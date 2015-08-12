MODULE Rose; (* Rational Oberon Socket Engine *)
IMPORT SYSTEM, Ignore, Net := WinNet, C := LibC, WinApi;

CONST
  ErrSocket * = 20;
  ErrHost   * = 21;
  ErrPort   * = 22;
  ErrBind   * = 23;
  ErrListen * = 24;

TYPE
  Adr* = ARRAY 255 + 1 + 5 + 1 OF CHAR; (* RFC 1034, RFC 1035 *)
  IPv4 = INTEGER;

  Socket = RECORD
    handle: Net.SOCKET;
    host- : ARRAY 255 + 1 OF CHAR; (* RFC 1034, RFC 1035 *)
    ip-   : ARRAY 16 OF CHAR; (* "XXX.XXX.XXX.XXX" *)
    ipv4  : IPv4; (* 32-bit IPv4 host address *)
    port- : INTEGER; (* 16-bit protocol port *)
  END;

  Listener* = RECORD (Socket)
    error-   : BOOLEAN; (** Was there an error during the work? *)
    errcode- : INTEGER; (** A code of the first occurred error. *)
  END;

VAR
  started: BOOLEAN;

PROCEDURE -print (i: INTEGER) 'printf("%d", i)';
PROCEDURE -prln 'printf("\n")';
PROCEDURE -prstr (s: ARRAY OF CHAR) 'printf("%s", s)';

(* Initialize/Cleanup the network API. Call it before using other functions. *)
PROCEDURE Init* (): BOOLEAN;
CONST
  WinSockVer = 0101H;
VAR
  wsaData: Net.WSADATA;
BEGIN
  IF ~ started THEN (* Start up the Windows networking: *)
    IF 0 # Net.WSAStartup(WinSockVer, wsaData) THEN RETURN FALSE END;
  END;
  started := TRUE; RETURN TRUE
END Init;

(* Shutdown and cleanup the network API. All sockets are closed.
   You may, of course, use Init to use the functionality again. *)
PROCEDURE Quit* ;
BEGIN
  IF started THEN (* Clean up Windows networking: *)
    started := FALSE;
    IF Net.WSACleanup() = Net.SOCKET_ERROR THEN
      IF Net.WSAGetLastError() = Net.WSAEINPROGRESS THEN
        Ignore.Int( Net.WSACancelBlockingCall() );
        Ignore.Int( Net.WSACleanup() );
      END;
    END;
  END;
END Quit;

PROCEDURE (VAR self: Socket) Close* ; (* Close a TCP network socket. *)
BEGIN
  IF self.handle # SYSTEM.VAL(Net.SOCKET, Net.INVALID_SOCKET) THEN
    Ignore.Int( Net.closesocket(self.handle) );
  END;
END Close;

(* Resolve IP or domain into 32-bit IPv4 host address or INADDR_NONE: *)
PROCEDURE ResolveHost (VAR self: Socket): BOOLEAN;
TYPE
  IPv4Ptr = POINTER [1] TO ARRAY [1] 1 OF IPv4;
VAR
  hp: Net.Ptrhostent; ipv4: IPv4Ptr;
BEGIN
  self.ipv4 := Net.inet_addr(SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(self.host)));
  IF self.ipv4 # Net.INADDR_NONE THEN RETURN TRUE END; (* IP *)
  IF self.host = "localhost" THEN
    hp := Net.gethostbyname(SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(self.host)));
    IF hp # NIL THEN (* domain *)
      SYSTEM.GET(hp^.h_addr_list, ipv4); self.ipv4 := ipv4^[0]; RETURN TRUE
    END;
  END;
  RETURN FALSE
END ResolveHost;

(* Resolve a host name and port to an IP address in network form: *)
PROCEDURE Resolve (VAR self: Socket; IN adr: ARRAY OF CHAR): BOOLEAN;
BEGIN
  IF C.sscanfi(
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(adr)),
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(":%d")), self.port) = 1
  THEN
    self.host := ""; self.ip := ""; self.ipv4 := Net.INADDR_ANY;
    RETURN TRUE (* INADDR_ANY *)
  ELSIF C.sscanfai(
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(adr)),
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR("%[^:]:%d")),
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(self.host)), self.port) = 2
  THEN
    IF ResolveHost(self) THEN RETURN TRUE (* IP or INADDR_NONE *) END;
  ELSIF C.sscanfi(
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(adr)),
    SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR("%d")), self.port) = 1
  THEN
    self.host := ""; self.ip := ""; self.ipv4 := Net.INADDR_ANY;
    RETURN TRUE (* INADDR_ANY *)
  ELSE (* port not specified: *)
    self.port := -1;
  END;
  self.host := ""; self.ip := ""; self.ipv4 := Net.INADDR_NONE;
  RETURN FALSE (* INADDR_NONE *)
END Resolve;

(* Listen to a local server TCP socket on the given port: *)
PROCEDURE (VAR self: Listener) Listen* (IN localAdr: ARRAY OF CHAR);
VAR
  sock_addr: Net.sockaddr_in; mode: Net.u_long;
BEGIN
  (* Open the socket: *)
  self.handle := Net.socket(Net.AF_INET, Net.SOCK_STREAM, 0);
  IF self.handle # SYSTEM.VAL(Net.SOCKET, Net.INVALID_SOCKET) THEN

    (* Resolve host and port: *)
    Ignore.Ptr(
      C.memset(
        SYSTEM.VAL(C.PtrVoid, SYSTEM.ADR(sock_addr)), 0,
        SYSTEM.VAL(C.size_t, SIZE(Net.sockaddr_in))
      )
    );
    sock_addr.sin_family := Net.AF_INET;

    (* Resolve address to host(ipv4): port *)
    IF Resolve(self, localAdr) THEN
      sock_addr.sin_addr.S_un.S_addr := self.ipv4;
      Ignore.Ptr(
        C.strncpy(
          SYSTEM.VAL(C.PtrSTR, SYSTEM.ADR(self.ip)),
          SYSTEM.VAL(C.PtrSTR, Net.inet_ntoa(sock_addr.sin_addr)),
          SYSTEM.VAL(C.size_t, LEN(self.ip))
        )
      );
      IF (self.port >= 0) & (self.port <= 0FFFFH) THEN
        sock_addr.sin_port := Net.htons(SHORT(self.port));

        (* Bind the socket for listening: *)
        IF Net.bind(self.handle, SYSTEM.VAL(Net.sockaddr, sock_addr),
          SIZE(Net.sockaddr_in)) # Net.SOCKET_ERROR
        THEN
          IF Net.listen(self.handle, 5) # Net.SOCKET_ERROR THEN
            mode := 1; (* O_NONBLOCK *)
            Ignore.Int(
              Net.ioctlsocket(self.handle, Net.FIONBIO(), mode)
            );
            self.error := FALSE; RETURN
          ELSE self.errcode := ErrListen;
          END;
        ELSE self.errcode := ErrBind;
        END;
      ELSE self.errcode := ErrPort;
      END;
    ELSE self.errcode := ErrHost;
    END;
    self.Close;
  ELSE self.errcode := ErrSocket;
  END;
  self.error := TRUE;
END Listen;

PROCEDURE MainLoop* ;
VAR
  msg: WinApi.MSG;
BEGIN
  WHILE WinApi.GetMessage(msg, NIL, 0, 0) # 0 DO
    Ignore.Int( WinApi.TranslateMessage(msg) );
    Ignore.Int( WinApi.DispatchMessage(msg) );
  END;
END MainLoop;

BEGIN
  started := FALSE;
END Rose.

(*
  Самоучитель игры на WINSOCK
  http://citforum.ru/book/cook/winsock.shtml

  Отличия сетевых вызовов Windows и Linux
  http://habrahabr.ru/post/105918/

  Программирование сокетов в Linux
  http://rsdn.ru/article/unix/sockets.xml

  Использование сокетов в Delphi
  http://www.delphikingdom.com/asp/viewitem.asp?catalogid=1021
  http://www.delphikingdom.com/asp/viewitem.asp?catalogid=1060
*)

(*

DnsQuery, DnsQueryExA: dnsapi.dll
  https://msdn.microsoft.com/ru-ru/library/windows/desktop/ms682016%28v=vs.85%29.aspx

gethostbyname(), gethostbyname_r()
  http://unix.derkeiler.com/Newsgroups/comp.unix.programmer/2007-02/msg00007.html

WSAAsyncGetHostByName
  http://forum.sources.ru/index.php?showtopic=272612&st=0&#entry2269771

*)

(* ToDo:

1. Реализовать поддержку номера порта 0, таким образом заставляя ядро выделить эфемерный порт. Вызываем getsockname, чтобы узнать номер этого порта. Это нужно в ряде случаев когда требуется выделить произвольный свободный порт.

2. select не предназначен для обработки большого числа соединий, для этого в Windows есть IOCP, в Linux - epoll, в FreeBSD - kqueue. И да, лучший метод, специфичный для конкретной платформы - используется тем же Boost.ASIO.

Во-первых select() или poll() при большой нагрузке начинают тормозить. Для решения этой проблемы в линухе 2.6 добавили epoll(7), в BSD есть всякие kqueue, etc.

Во-вторых кол-во файловых дескрипторов на процесс обычно ограничено 1024, и изменить (увеличить) это может только root. Впрочем это обычно не большая проблема, т.к. сервера которым нужно обрабатывать больше тысячи клиентов обычно запускаются на своём дедике.

Вот классическая ссылка по теме: http://www.kegel.com/c10k.html

http://nginx.org/ru/docs/events.html

Это что касается сервера. Для клиента есть ещё такие грабли как DNS - чтобы качать сотнями/тысячами потоков с разных серверов (есть и такие задачки :-)) нужно уметь быстро и асинхронно ресолвить их IPшники.

*)
