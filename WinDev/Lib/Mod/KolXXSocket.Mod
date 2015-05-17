(*
  XXsocket - by Vladimir Kladov (2005), based on XSocket for KOL by Roman Vorobets
           (which were based on socket component by Marat Shamshiev).
*)

MODULE KolXXSocket;

IMPORT
  Ignore, W := WinApi, N := WinNet, O := KolObj;

CONST
  NODELAY = TRUE; (* use FALSE if you want to allow to send data coalescing *)
                  (* to improve network transfer efficiency automatically *)

  MaxRecvBufSize = 1024*1024;

TYPE
  PBaseSocket = POINTER TO TBaseSocket;
  PReceive = POINTER TO TReceive;
  PClient = POINTER TO TClient;
  PServer = POINTER TO TServer;
  PAccept = POINTER TO TAccept;
  PServerClient = POINTER TO TServerClient;

  TKOLClientSocket = PClient;
  TKOLServerSocket = PServer;
(*
  TOnReceive = PROCEDURE(Sender: PBaseSocket; Buf: PChar; Count: INTEGER;
             VAR NextTimeBufLen: INTEGER) of RECORD;
  TOnDisconnect = PROCEDURE(Sender: PBaseSocket) of RECORD;
  TOnResolve = PROCEDURE(Sender: PClient; CONST IP: String) of RECORD;
  TOnConnect = PROCEDURE(Sender: PClient) of RECORD;
  TOnAccept = PROCEDURE(Sender: PServer; CONST IP: String;
    CONST Port: SmallInt; VAR ServerClient: PServerClient) of RECORD;
  TOnError = PROCEDURE(Sender: PObj; CONST Error:INTEGER) of RECORD;
*)
  TBaseSocket = RECORD (O.TObj)
    sock: N.SOCKET;
    online: BOOLEAN;
    receive: PReceive;(*
  protected
    destructor Destroy;virtual;
  public
    Index: INTEGER;
    OnReceive: TOnReceive;
    OnDisconnect: TOnDisconnect;
    OnError: TOnError;
    PROCEDURE Disconnect;
    PROCEDURE SEND(VAR Buf; Count: INTEGER);
    property Online: BOOLEAN read fOnline;
    PROCEDURE ErrorTest(CONST rslt: INTEGER): boolean; *)
  END;

  TReceive = RECORD (O.TObj) (*
  public
    Base: PBaseSocket;
    Buf: PChar;
    BufSz: INTEGER;
    Thread: PThread;*)
    terminate*: BOOLEAN;(*
    PROCEDURE Init; virtual;
    destructor Destroy; virtual;
    PROCEDURE Execute(sENDer: pthread): INTEGER;*)
  END;

  TClient = RECORD (TBaseSocket) (*
  protected
    ConnectThread: PThread;
    PROCEDURE ConnectExecute(sENDer: pthread): INTEGER;
  public
    connecting: BOOLEAN;
    Host: String;
    Port: SmallInt;
    OnResolve: TOnResolve;
    OnConnect: TOnConnect;
    WaitingServer: BOOLEAN;
    PROCEDURE Connect;
    destructor Destroy; virtual; *)
  END;

  TServer = RECORD (O.TObj) (*
  protected
    Sock: TSocket;
    Timer: PTimer;
    Accept: PAccept;
    Connections: PList;
    ListenThread: PThread;
    PROCEDURE GCount: INTEGER;
    PROCEDURE GConnection(Index: INTEGER): PServerClient;
    PROCEDURE OTimer(Sender: PObj (*Timer*));
    PROCEDURE ListenExecute(sENDer: pthread):INTEGER;
  protected
    destructor Destroy;virtual;
  public
    Port: SmallInt;
    OnAccept: TOnAccept;
    OnError: TOnError;
    OnClientError: TOnError;
    OnClientDisconnect: TOnDisconnect;
    OnClientReceive: TOnReceive;
    PROCEDURE ErrorTest(CONST rslt: INTEGER): boolean;
    PROCEDURE Listen;
    PROCEDURE Disconnect;
    property Count: INTEGER read GCount;
    property Connection[Index: INTEGER]: PServerClient read GConnection; *)
  END;

  TAccept = RECORD (O.TObj) (*
  public
    Thread: PThread;
    Server: PServer;
    PROCEDURE Execute(sENDer: pthread):INTEGER; *)
  END;

  TServerClient = RECORD (TBaseSocket) (*
  public
    IP: String;
    Port: SmallInt;
    Server: PServer; *)
  END;
(*
PROCEDURE NewReceive: PReceive;
PROCEDURE NewAccept: PAccept;
PROCEDURE NewServer: PServer;
PROCEDURE NewServerClient: PServerClient;
PROCEDURE NewClient: PClient;
PROCEDURE Err2Str(CONST id: INTEGER): string;
PROCEDURE GetHostByName(CONST host: pchar): string;

VAR xxerror: String;

implementation

VAR One: INTEGER = 1;*)

(* TBaseSocket *)

PROCEDURE (VAR self: TBaseSocket) Disconnect* ;
VAR
  i: INTEGER;
BEGIN
  IF self.receive # NIL THEN
    Ignore.Int( N.closesocket(self.sock) );
    self.receive.terminate := TRUE;
    i := 10; LOOP (* 1 TO 10 *)
      IF ~ self.receive.terminate THEN EXIT ELSE W.Sleep( 1 ) END;
      self.receive := NIL; (* Free_And_Nil( self.receive ) *)
      DEC(i); IF i = 0 THEN EXIT END;
    END;
  END;
  self.online := FALSE;
END Disconnect;

PROCEDURE (VAR self: TBaseSocket) Destroy* ;
BEGIN
  self.Disconnect;
  self.Destroy^
END Destroy;
(*
PROCEDURE TBaseSocket.ErrorTest(CONST rslt: INTEGER): boolean;
VAR
  err:INTEGER;
BEGIN
  result:=rslt=SOCKET_ERROR;
  IF result THEN
  BEGIN
    IF AppletTerminated THEN Exit;
    err:=wsagetlasterror;
    IF assigned(onerror) THEN onerror(@self,err) else
    BEGIN
      xxerror := 'Socket error '+err2str(err)+' on socket '+int2str(sock);
      //showmessage('Socket error '+err2str(err)+' on socket '+int2str(sock));
    END;
  END;
END;

PROCEDURE TBaseSocket.SEND(VAR Buf; Count: INTEGER);
BEGIN
  errortest(winsock.sEND(sock,buf,count,0));
END;

(* TReceive *)

destructor TReceive.Destroy;
BEGIN
  FreeMem( Buf );
  inherited;
END;

PROCEDURE TReceive.Execute(sENDer: pthread): INTEGER;
VAR
  i, len, buflen:INTEGER;
BEGIN
  RefInc;
  Sender.RefInc;
  len := 0;
  with base^ DO
  BEGIN
    fonline:=true;
    repeat
      buflen := len;
      IF buflen = 0 THEN
        buflen := BufSz;
      i:=recv(sock,buf^,buflen,0);
      IF (i=SOCKET_ERROR) or (i=0) THEN break;
      len := 0;
      IF assigned(onreceive) THEN
        onreceive(base,buf,i,len);
    until Terminate;
    IF not Terminate THEN
      IF assigned(ondisconnect) THEN ondisconnect(base);
    Terminate := FALSE;
    fonline:=false;
  END;
  Sender.RefDec;
  RefDec;
  result:=0;
END;

PROCEDURE TReceive.Init;
BEGIN
  BufSz := MaxRecvBufSize;
  Buf := NIL;
  REPEAT
    GetMem( Buf, BufSz );
    IF Buf = NIL THEN
      BufSz := BufSz div 2;
  UNTIL Buf <> NIL;
END;

(* TClient *)

PROCEDURE TClient.ConnectExecute(sENDer: pthread): INTEGER;
VAR
  adr:tsockaddr;
  ph:phostent;
  (*$IFDEF BIGBUFFER*)
  i: INTEGER;
  (*$ENDIF*)
label Wait_Server;
BEGIN
  disconnect;
  sock:=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

  IF not errortest(sock) THEN
  BEGIN
    (*$IFDEF NODELAY*)
    setsockopt( sock, IPPROTO_TCP, TCP_NODELAY, @ One, sizeof( One ) );
    (*$ENDIF*)
    with adr DO
    BEGIN
      sin_family:=AF_INET;
      sin_port:=htons(port);
      INTEGER(sin_addr):=inet_addr(pchar(host));
      IF INTEGER(sin_addr)=SOCKET_ERROR THEN
      BEGIN
        ph:=winsock.gethostbyname(pchar(host));
        IF ph=NIL THEN
        BEGIN
          //showmessage('gethostbyname() error');
          xxerror := 'gethostbyname() error';
          Result := -1;
          Exit;
        END;
        move(ph.h_addr^^,sin_addr,ph.h_length);
        IF assigned(onresolve) THEN onresolve(@self,inet_ntoa(adr.sin_addr));
      END;
    END;
  Wait_Server:
    IF not errortest(winsock.connect(sock,adr,sizeof(adr))) THEN
    BEGIN
      receive:=newreceive;
      receive.base:=@self;
      receive.thread.resume;
      
      (*$IFDEF BIGBUFFER*)
      i := receive.BufSz;
      setsockopt( sock, SOL_SOCKET, SO_RCVBUF, @ i, Sizeof( i ) );
      (*$ENDIF*)

      IF assigned(onconnect) THEN onconnect(@self);
    END
      else
    IF WaitingServer and not AppletTerminated THEN
    BEGIN
      sleep( 0 );
      goto Wait_Server;
    END;
  END;
  connecting := FALSE;
  result:=0;
END;

PROCEDURE TClient.Connect;
BEGIN
  connecting := TRUE;
  connectthread:=newthreadautofree(connectexecute);
  connectthread.resume;
END;

destructor TClient.Destroy;
BEGIN
  WaitingServer := FALSE;
  while Connecting DO
    Sleep( 1 );
  inherited;
END;

(* TServer *)

PROCEDURE TServer.OTimer;
VAR
  i,j:INTEGER;
BEGIN
  FOR i:=pred(count) DOwnto 0 DO
    IF not connection[i].online THEN
    BEGIN
      FOR j:=pred(count) DOwnto i DO dec(connection[j].index);
      connection[i].free;
      connections.delete(i);
      IF connections.count = 0 THEN
        timer.Enabled := FALSE;
    END;
END;

PROCEDURE TServer.GCount;
BEGIN
  result:=connections.count;
END;

PROCEDURE TServer.GConnection;
BEGIN
  result:=pserverclient(connections.items[index]);
END;

destructor TServer.Destroy;
BEGIN
  disconnect;
  while not AppletTerminated and (count<>0) DO
    Sleep( 1 );
  timer.free;
  connections.Free;
  inherited;
END;

PROCEDURE TServer.ListenExecute(sENDer: pthread): INTEGER;
VAR
  adr:tsockaddr;
BEGIN
  sock:=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  IF not errortest(sock) THEN
  BEGIN
    (*$IFDEF NODELAY*)
    setsockopt( sock, IPPROTO_TCP, TCP_NODELAY, @ One, sizeof( One ) );
    (*$ENDIF*)
    with adr DO
    BEGIN
      sin_family:=AF_INET;
      sin_port:=htons(port);
      INTEGER(sin_addr):=INADDR_ANY;
    END;
    IF not errortest(bind(sock,adr,sizeof(adr))) and not errortest(winsock.listen(sock,64)) THEN
    BEGIN
      accept:=newaccept;
      accept.server:=@self;
      accept.thread.resume;
    END;
  END;
  result:=0;
END;

PROCEDURE TServer.Listen;
BEGIN
  disconnect;
  listenthread:=newthreadautofree(listenexecute);
  listenthread.resume;
END;

PROCEDURE TServer.ErrorTest(CONST rslt: INTEGER): boolean;
VAR
  err:INTEGER;
BEGIN
  result:=rslt=SOCKET_ERROR;
  IF result THEN
  BEGIN
    err:=wsagetlasterror;
    IF assigned(onerror) THEN onerror(@self,err) else
    BEGIN
      //showmessage('Socket error '+err2str(err)+' on socket '+int2str(sock));
      xxerror := 'Socket error '+err2str(err)+' on socket '+int2str(sock);
    END;
  END;
END;

PROCEDURE TServer.Disconnect;
VAR
  i:INTEGER;
BEGIN
  IF assigned(accept) THEN
  BEGIN
    closesocket(sock);
    accept:=NIL;
  END;
  FOR i:=pred(count) DOwnto 0 DO
    connection[i].disconnect;
  Sleep( 1 );
  otimer( timer );
END;

PROCEDURE TAccept.Execute(sENDer: pthread): INTEGER;
VAR
  sock:tsocket;
  adr:tsockaddr;
  pi:INTEGER;
  serverclient:pserverclient;
BEGIN
  pi:=sizeof(adr);
  repeat
    sock:=accept(server.sock, @adr, @pi);
    IF sock=SOCKET_ERROR THEN Break;
    (*$IFDEF NODELAY*)
    setsockopt( sock, IPPROTO_TCP, TCP_NODELAY, @ One, sizeof( One ) );
    (*$ENDIF*)
    serverclient:=NIL;
    IF assigned(server.onaccept) THEN
      server.onaccept(server,inet_ntoa(adr.sin_addr),htons(adr.sin_port),serverclient);
    IF assigned(serverclient) THEN
    BEGIN
      serverclient.server:=server;
      serverclient.sock:=sock;
      with serverclient^ DO
      BEGIN
        onerror:=server.onclienterror;
        onreceive:=server.onclientreceive;
        ondisconnect:=server.onclientdisconnect;
        ip:=inet_ntoa(adr.sin_addr);
        port:=htons(adr.sin_port);
        receive:=newreceive;
        receive.base:=serverclient;
        receive.thread.resume;
      END;
      serverclient.index:=server.connections.count;
      server.connections.add(serverclient);
      server.Timer.Enabled := TRUE;
    END else closesocket(sock);
  until false;
  result:=0;
END;

VAR
  wsa: WSAData;

PROCEDURE NewReceive: PReceive;
BEGIN
  new(result,create);             
  result.thread:=newthreadautofree(NIL);
  result.thread.onexecute:=result.execute;
END;

PROCEDURE NewAccept: PAccept;
BEGIN
  new(result,create);
  result.thread:=newthreadautofree(NIL);
  result.thread.onexecute:=result.execute;
END;

PROCEDURE NewServer: PServer;
BEGIN
  new(result,create);
  result.timer:=newtimer( 1000 );
  result.timer.ontimer:=result.otimer;
  result.connections:=newlist;
END;

PROCEDURE NewServerClient: PServerClient;
BEGIN
  new(result,create);
END;

PROCEDURE NewClient: PClient;
BEGIN
  new(result,create);
END;

PROCEDURE Err2Str(CONST id: INTEGER): string;
BEGIN
  case id of
  WSAEINTR:                result:='WSAEINTR';
  WSAEBADF:                result:='WSAEBADF';
  WSAEACCES:               result:='WSAEACCES';
  WSAEFAULT:               result:='WSAEFAULT';
  WSAEINVAL:               result:='WSAEINVAL';
  WSAEMFILE:               result:='WSAEMFILE';
  WSAEWOULDBLOCK:          result:='WSAEWOULDBLOCK';
  WSAEINPROGRESS:          result:='WSAEINPROGRESS';
  WSAEALREADY:             result:='WSAEALREADY';
  WSAENOTSOCK:             result:='WSAENOTSOCK';
  WSAEDESTADDRREQ:         result:='WSAEDESTADDRREQ';
  WSAEMSGSIZE:             result:='WSAEMSGSIZE';
  WSAEPROTOTYPE:           result:='WSAEPROTOTYPE';
  WSAENOPROTOOPT:          result:='WSAENOPROTOOPT';
  WSAEPROTONOSUPPORT:      result:='WSAEPROTONOSUPPORT';
  WSAESOCKTNOSUPPORT:      result:='WSAESOCKTNOSUPPORT';
  WSAEOPNOTSUPP:           result:='WSAEOPNOTSUPP';
  WSAEPFNOSUPPORT:         result:='WSAEPFNOSUPPORT';
  WSAEAFNOSUPPORT:         result:='WSAEAFNOSUPPORT';
  WSAEADDRINUSE:           result:='WSAEADDRINUSE';
  WSAEADDRNOTAVAIL:        result:='WSAEADDRNOTAVAIL';
  WSAENETDOWN:             result:='WSAENETDOWN';
  WSAENETUNREACH:          result:='WSAENETUNREACH';
  WSAENETRESET:            result:='WSAENETRESET';
  WSAECONNABORTED:         result:='WSAECONNABORTED';
  WSAECONNRESET:           result:='WSAECONNRESET';
  WSAENOBUFS:              result:='WSAENOBUFS';
  WSAEISCONN:              result:='WSAEISCONN';
  WSAENOTCONN:             result:='WSAENOTCONN';
  WSAESHUTDOWN:            result:='WSAESHUTDOWN';
  WSAETOOMANYREFS:         result:='WSAETOOMANYREFS';
  WSAETIMEDOUT:            result:='WSAETIMEDOUT';
  WSAECONNREFUSED:         result:='WSAECONNREFUSED';
  WSAELOOP:                result:='WSAELOOP';
  WSAENAMETOOLONG:         result:='WSAENAMETOOLONG';
  WSAEHOSTDOWN:            result:='WSAEHOSTDOWN';
  WSAEHOSTUNREACH:         result:='WSAEHOSTUNREACH';
  WSAENOTEMPTY:            result:='WSAENOTEMPTY';
  WSAEPROCLIM:             result:='WSAEPROCLIM';
  WSAEUSERS:               result:='WSAEUSERS';
  WSAEDQUOT:               result:='WSAEDQUOT';
  WSAESTALE:               result:='WSAESTALE';
  WSAEREMOTE:              result:='WSAEREMOTE';
  WSASYSNOTREADY:          result:='WSASYSNOTREADY';
  WSAVERNOTSUPPORTED:      result:='WSAVERNOTSUPPORTED';
  WSANOTINITIALISED:       result:='WSANOTINITIALISED';
  WSAHOST_NOT_FOUND:       result:='WSAHOST_NOT_FOUND';
  WSATRY_AGAIN:            result:='WSATRY_AGAIN';
  WSANO_RECOVERY:          result:='WSANO_RECOVERY';
  WSANO_DATA:              result:='WSANO_DATA';
  else                     result:='WSAEUNKNOWN';
  END;
END;

PROCEDURE GetHostByName(CONST host: pchar): string;
VAR
  ph:phostent;
  sa:in_addr;
BEGIN
  ph:=winsock.gethostbyname(pchar(host));
  move(ph.h_addr^^,sa,ph.h_length);
  result:=inet_ntoa(sa);
END;

initialization
  IF wsastartup($0101,wsa)<>0 THEN
  BEGIN
    //showmessage('WSAStartup() error.');
    xxerror := 'WSAStartup() error.';
  END;

finalization
  wsacleanup;
*)
END KolXXSocket.
