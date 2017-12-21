MODULE KolSocket;

IMPORT
  SYSTEM, WinApi, WinNet, Ignore,
  KolObj;(*KOL, Windows, Messages, Winsock;*)

CONST(*
  WM_SOCKET                 = WM_USER + $7000;
  WM_SOCKETERROR            = WM_USER + $7001;
  WM_SOCKETCLOSE            = WM_USER + $7002;
  WM_SOCKETREAD             = WM_USER + $7003;
  WM_SOCKETCONNECT          = WM_USER + $7004;
  WM_SOCKETACCEPT           = WM_USER + $7005;
  WM_SOCKETWRITE            = WM_USER + $7006;
  WM_SOCKETOOB              = WM_USER + $7007;
  WM_SOCKETLISTEN           = WM_USER + $7008;
  WM_SOCKETLOOKUP           = WM_USER + $7009;

  EVENTS_DOLISTEN           = FD_CLOSE OR FD_ACCEPT;
  EVENTS_DOCONNECT          = FD_CONNECT OR FD_CLOSE OR FD_READ;
  EVENTS_SETSOCKETHANDLE    = FD_READ OR FD_CLOSE OR FD_CONNECT;

  MaxWord                   = 65535;
  MinWord                   = 0;
*)
  c_FIRST*                   = 1;
(*
  INVALID_SOCKET            = winsock.INVALID_SOCKET;

*)TYPE(*

  TWndMethod = procedure(VAR Message: TMessage) of object;

  PhWnd =^ThWnd;
  ThWnd = object( TObj )
  protected
    m_hWnd: hWnd;
    destructor Destroy; virtual;
  public
    property Handle: hWnd read m_hWnd;
  END;
*)
  PAsyncSocket* = POINTER TO TAsyncSocket;
  TKOLSocket*   = PAsyncSocket;
(*
  TWMSocket = record
    Msg: Word;
    case Integer of
    0: (
      SocketWParam: Word;
      SocketDataSize: LongInt;
      SocketNumber: Longint;
      SocketAddress: PAsyncSocket);
    1: (
      WParamLo: Byte;
      WParamHi: Byte;
      SocketEvent: Word;
      SocketError: Word;
      ResultLo: Word;
      ResultHi: Word);
    2: (
      WParam: Word;
      TaskHandle: Word;
      WordHolder: Word;
      pHostStruct: Pointer);
  END;

  TBArray = array[0..65534] of byte;

  TBufRecord = record
     i: integer;
     p:^TBArray;
  END;

  TSocketMessageEvent = procedure (SocketMessage: TWMSocket) of object;
*)
  TAsyncSocket* = RECORD (KolObj.TObj)(*
    m_SockAddr:         TSockAddr;
    m_Handle:           TSocket;
    m_hWnd:             PhWnd;
    fConnected:         boolean;
    fDNSResult:         string;
    fDNSHandle:         integer;
    FDnsBuffer:         array [0..MAXGETHOSTSTRUCT] of char;
    FList:              PList;
    FOnError:           TSocketMessageEvent;
    FOnLookup:          TSocketMessageEvent;
    FOnAccept:          TSocketMessageEvent;
    FOnClose:           TSocketMessageEvent;
    FOnConnect:         TSocketMessageEvent;
    FOnRead:            TSocketMessageEvent;
    FOnWrite:           TSocketMessageEvent;
    FOnListen:          TSocketMessageEvent;
    FOnOOB:             TSocketMessageEvent;

  protected
    destructor Destroy; virtual;

  private
    PROCEDURE GetCount: LongInt;
    PROCEDURE GetPortNumber: LongInt;
    PROCEDURE GetIPAddress: String;
    PROCEDURE ErrorTest(Evaluation: LongInt): LongInt;

    procedure AllocateSocket;
    procedure KillWinsockBug;
    procedure SetPortNumber(NewPortNumber: LongInt);
    procedure SetIPAddress(NewIPAddress: String);
    procedure SetSocketHandle(NewSocketHandle: TSocket);
    PROCEDURE  GetConnected: boolean;

    // Message Handlers

    procedure HWndProcedure(VAR Message: TMessage);

    procedure Message_Error(VAR Message: TWMSocket);
    procedure Message_Lookup(VAR Message: TWMSocket);
    procedure Message_Close(VAR Message: TWMSocket);
    procedure Message_Accept(VAR Message: TWMSocket);
    procedure Message_Read(VAR Message: TWMSocket);
    procedure Message_Connect(VAR Message: TWMSocket);
    procedure Message_Write(VAR Message: TWMSocket);
    procedure Message_OOB(VAR Message: TWMSocket);
    procedure Message_Listen(VAR Message: TWMSocket);
    procedure DoReceive(Buffer: Pointer; VAR ReceiveLen: LongInt);
    procedure DoFinal(Abort: boolean);

  public
    procedure ProcessMessages;
    PROCEDURE  DoGetHostByAddr(IPAddr: PChar): String;
    PROCEDURE  DoGetHostByName(Name: PChar): String;

    procedure DoLookup(host: string);
    procedure DoClose;
    procedure DoSend(Buffer: Pointer; VAR SendLen: LongInt);
    procedure DoListen;
    procedure DoConnect;
    procedure DoAccept(VAR AcceptSocket: PAsyncSocket);

    procedure SendString(fString: String);

    PROCEDURE  ReadData(b: pointer; c: integer): integer;
    PROCEDURE  ReadLine(c: char): string; overload;
    PROCEDURE  ReadLine(c: char; t: integer): string; overload;
    PROCEDURE  ErrToStr(Err: LongInt): String;
    PROCEDURE  LocalIP: String;
    PROCEDURE  LocalPort: integer;

    property  SocketHandle: TSocket read m_Handle write SetSocketHandle;
    property  IPAddress: String read GetIPAddress write SetIPAddress;
    property  PortNumber: LongInt read GetPortNumber write SetPortNumber;
    property  Count: LongInt read GetCount;
    property  Connected: boolean read GetConnected;
    property  DNSResult: string read fDNSResult write fDNSResult;

    property  OnError: TSocketMessageEvent read FOnError write FOnError;
    property  OnLookup: TSocketMessageEvent read FOnLookup write FOnLookup;
    property  OnAccept: TSocketMessageEvent read FOnAccept write FOnAccept;
    property  OnClose: TSocketMessageEvent read FOnClose write FOnClose;
    property  OnConnect: TSocketMessageEvent read FOnConnect write FOnConnect;
    property  OnRead: TSocketMessageEvent read FOnRead write FOnRead;
    property  OnWrite: TSocketMessageEvent read FOnWrite write FOnWrite;
    property  OnOOB: TSocketMessageEvent read FOnOOB write FOnOOB;
    property  OnListen: TSocketMessageEvent read FOnListen write FOnListen;
  *)END;
VAR
  InstanceCount: INTEGER (*= 0*);
(*
  PROCEDURE NewThWnd(WndMethod: TWndMethod): PhWnd;*)
  PROCEDURE ^ NewAsyncSocket* (): PAsyncSocket;

(*
implementation

uses objects;

PROCEDURE NewThWnd;
BEGIN
  New(Result, Create);
  Result.m_hWnd := AllocateHWnd(WndMethod);
END;  // constructor ThWnd.Create(WndMethod: TWndMethod)

destructor ThWnd.Destroy;
BEGIN
  DeallocateHWnd(m_hWnd);
  inherited;
END;
*)
PROCEDURE NewAsyncSocket* (): PAsyncSocket;
VAR
  TempWSAData: WinNet.WSADATA; Result: PAsyncSocket;
BEGIN
  InstanceCount := InstanceCount + 1;
  NEW(Result); Result^.Create;
  IF (InstanceCount = c_FIRST) THEN Ignore.Int (
    (*Result^.ErrorTest( *)WinNet.WSAStartup(101H, TempWSAData));
  END;(*
  Result.KillWinsockBug;
  Result.m_Handle := INVALID_SOCKET;
  Result.m_SockAddr.sin_family := AF_INET;
  Result.m_SockAddr.sin_addr.s_addr := INet_Addr('0.0.0.0');
  Result.PortNumber := 0;
  Result.FList := NewList;
  Result.m_hWnd := NewThWnd(Result.HWndProcedure);
*)END NewAsyncSocket; (* CONSTRUCTOR TAsyncSocket.Create *)

(*PROCEDURE TAsyncSocket.GetCount;
VAR i: integer;
    t:^TBufRecord;
BEGIN
   result := 0;
   for i := 0 to FList.Count - 1 do BEGIN
      t := FList.Items[i];
      result := result + t^.i;
   END;
END;

PROCEDURE TAsyncSocket.ReadData;
VAR n,
    r: integer;
    t:^TBufRecord;
    u:^TBufRecord;
    a:^TBArray;
BEGIN
   IF FList.count = 0 THEN BEGIN
      result := 0;
      exit;
   END;
   n := 0;
   a := b;
   while (n < c) and (n < count) do BEGIN
      r := c - n;
      t := FList.Items[0];
      IF r > t^.i THEN r := t^.i;
      move(t^.p^, a^[n], r);
      n := n + r;
      IF r = t^.i THEN BEGIN
         FreeMem(t^.p, t^.i);
         FreeMem(t, SizeOf(TBufRecord));
         FList.Delete(0);
      end else BEGIN
         GetMem(u, SizeOf(TBufRecord));
         u^.i := t^.i - r;
         GetMem(u^.p, u^.i);
         move(t^.p^[r], u^.p^, u^.i);
         FreeMem(t^.p, t^.i);
         FreeMem(t, SizeOf(TBufRecord));
         FList.Items[0] := u;
      END;
   END;
   result := n;
END;

PROCEDURE TAsyncSocket.ReadLine(c: char): string;
VAR i,
    n,
    j: integer;
    t:^TBufRecord;
    s: string;
BEGIN
   result := '';
   n := 0;
   IF count = 0 THEN exit;
   for i := 0 to FList.Count - 1 do BEGIN
      t := FList.Items[i];
      for j := 0 to t^.i - 1 do BEGIN
         inc(n);
         IF chr(t^.p^[j]) = c THEN BEGIN
            setlength(s, n - 1);
            ReadData(@s[1], n - 1);
            ReadData(@n   ,     1);
            result := s;
            exit;
         END;
      END;
   END;
   setlength(s, n);
   ReadData(@s[1], n);
   Result := s;
END;

PROCEDURE TAsyncSocket.ReadLine(c: char; t: integer): string;
VAR tt: longint;
   Msg: tagMSG;
BEGIN
   result := '';
   tt := gettickcount;
   while (result = '') and (longint(gettickcount) < tt + t * 1000) do BEGIN
      IF PeekMessage(Msg, m_hWnd.m_hWnd, 0, 0, PM_REMOVE) THEN BEGIN
         DispatchMessage(Msg);
      END;
      result := ReadLine(c);
      IF m_Handle = INVALID_SOCKET THEN exit;
   END;
END;

PROCEDURE TAsyncSocket.GetIPAddress: String;
BEGIN
  Result := INet_NToA(m_SockAddr.sin_addr);
END;  // PROCEDURE TAsyncSocket.GetIPAddress: String

PROCEDURE TAsyncSocket.GetPortNumber: LongInt;
BEGIN
  Result := NToHS(m_SockAddr.sin_port);
END;  // PROCEDURE TAsyncSocket.GetPortNumber: Word

procedure TAsyncSocket.AllocateSocket;
BEGIN
  IF (m_Handle = INVALID_SOCKET) THEN
    BEGIN
    m_Handle := ErrorTest(socket(AF_INET, SOCK_STREAM, 0));
    END;  // IF (m_Handle = INVALID_SOCKET) THEN
END;  // procedure TAsyncSocket.AllocateSocket

procedure TAsyncSocket.SetSocketHandle(NewSocketHandle: TSocket);
BEGIN
  DoFinal(True);
  m_Handle := NewSocketHandle;
  ErrorTest(WSAAsyncSelect(m_Handle, m_hWnd.Handle, WM_SOCKET, EVENTS_SETSOCKETHANDLE));
END;  // procedure TAsyncSocket.SetSocketHandle(NewSocketHandle: TSocket)

PROCEDURE TAsyncSocket.GetConnected;
BEGIN
   result := m_Handle <> INVALID_SOCKET;
END;

PROCEDURE TAsyncSocket.ErrorTest(Evaluation: LongInt): LongInt;
VAR
  TempMessage: TWMSocket;
BEGIN
  IF ((Evaluation = SOCKET_ERROR) OR (Evaluation = INVALID_SOCKET)) THEN
    BEGIN
    TempMessage.Msg := WM_SOCKETERROR;
    TempMessage.SocketError := WSAGetLastError;
    TempMessage.SocketNumber := m_Handle;
    TempMessage.SocketAddress := @self;
    Message_Error(TempMessage);
    Result := Evaluation;
    end  // IF ((Evaluation = SOCKET_ERROR) OR (Evaluation = INVALID_SOCKET)) THEN
  else
    Result := Evaluation;
END;  // PROCEDURE ErrorTest(Evaluation: LongInt): LongInt;
*)
PROCEDURE KillWinsockBug;
VAR
  Addr: INTEGER;
BEGIN
  Addr := 0;
  (* For an unknown reason, if a call is made to GetHostByName and it should *)
  (* fail, the following call to GetHostByAddr will not fail, but return '>' *)
  (* in the place of the host name.  This clears the problem up. *)
  Ignore.Ptr(
    WinNet.gethostbyname(SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("")))
  );
  Ignore.Ptr(
    WinNet.gethostbyaddr(SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR(Addr)),
      SIZE(INTEGER), WinNet.PF_INET)
  );
  Ignore.Ptr(
    WinNet.gethostbyname(SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("")))
  );
END KillWinsockBug;
(*
PROCEDURE TAsyncSocket.SetIPAddress(NewIPAddress: String);
VAR
   pTempHostEnt: PHostEnt;
BEGIN
  m_SockAddr.sin_addr.s_addr := INet_Addr(PChar(NewIPAddress));
  IF (m_SockAddr.sin_addr.s_addr = u_long(INADDR_NONE))  THEN
     BEGIN
     pTempHostEnt := GetHostByName(PChar(NewIPAddress));
     IF (pTempHostEnt <> Nil) THEN
        m_SockAddr.sin_addr.s_addr := PInAddr(pTempHostEnt^.h_addr_list^)^.s_addr;
     END;
END;  // procedure TAsyncSocket.SetIPAddress(NewIPAddress: String)

procedure TAsyncSocket.SetPortNumber(NewPortNumber: LongInt);
BEGIN
  IF ((NewPortNumber > 0) AND (NewPortNumber <= MaxWord)) THEN
    m_SockAddr.sin_port := HToNS(NewPortNumber);
END;  // procedure TAsyncSocket.SetPortNumber(NewPortNumber: Word)

procedure TAsyncSocket.DoReceive(Buffer: Pointer; VAR ReceiveLen: LongInt);
BEGIN
  ReceiveLen := recv(m_Handle, Buffer^, ReceiveLen, 0);
  ErrorTest(ReceiveLen);
END;  // TAsyncSocket.DoReceive(Buffer: Pointer; BufferLen: LongInt)

procedure TAsyncSocket.DoSend(Buffer: Pointer; VAR SendLen: LongInt);
BEGIN
  SendLen := send(m_Handle, Buffer^, SendLen, 0);
  ErrorTest(SendLen);
END;  // procedure TAsyncSocket.DoSend(Buffer: Pointer; BufferLen: LongInt)

procedure TAsyncSocket.DoLookup;
VAR
   IPAddr  : TInAddr;
BEGIN
   IF Host = '' THEN BEGIN
      Exit;
   END;

   { Cancel any pending lookup }
   IF FDnsHandle <> 0 THEN
      WSACancelAsyncRequest(FDnsHandle);

    FDnsResult := '';

    IPAddr.S_addr := Inet_addr(PChar(Host));
    IF IPAddr.S_addr <> u_long(INADDR_NONE) THEN BEGIN
        FDnsResult := inet_ntoa(IPAddr);
{        TriggerDnsLookupDone(0);}
        Exit;
    END;

    FDnsHandle := WSAAsyncGetHostByName(m_hWnd.Handle,
                                        WM_SOCKETLOOKUP,
                                        @Host[1],
                                        @FDnsBuffer,
                                        SizeOf(FDnsBuffer));
    IF FDnsHandle = 0 THEN BEGIN
       ErrorTest(WSAGetLastError);
       Exit;
    END;
END;

procedure TAsyncSocket.DoClose;
BEGIN
   DoFinal(True);
END;

procedure TAsyncSocket.DoFinal;
VAR
  TempMessage: TWMSocket;
BEGIN
  IF (m_Handle <> INVALID_SOCKET) THEN BEGIN
    IF not Abort THEN BEGIN
       ProcessMessages;
    END;
    TempMessage.Msg := WM_SOCKETCLOSE;
    TempMessage.SocketNumber := m_Handle;
    TempMessage.SocketAddress := @self;
    Message_Close(TempMessage);
    ErrorTest(closesocket(m_Handle));
    m_Handle := INVALID_SOCKET;
    END;
END;

procedure TAsyncSocket.DoAccept(VAR AcceptSocket: PAsyncSocket);
VAR
  TempSize: Integer;
  TempSock: TSocket;
  TempAddr: TSockAddrIn;
BEGIN
  TempSize := SizeOf(TSockAddr);
  TempSock := accept(m_Handle, @TempAddr, @TempSize);
  AcceptSocket.m_SockAddr := TempAddr;
  IF (ErrorTest(TempSock) <> INVALID_SOCKET) THEN
    AcceptSocket.SocketHandle := TempSock;
END;  // procedure TAsyncSocket.DoAccept(VAR AcceptSocket: TAsyncSocket)

procedure TAsyncSocket.DoListen;
VAR
  TempMessage: TWMSocket;
BEGIN
  DoClose;
  AllocateSocket;
  IF
    (ErrorTest(WSAAsyncSelect(m_Handle, m_hWnd.Handle, WM_SOCKET, EVENTS_DOLISTEN))
      <> SOCKET_ERROR) AND
    (ErrorTest(bind(m_Handle, m_SockAddr, SizeOf(TSockAddr))) <> SOCKET_ERROR) AND
    (ErrorTest(listen(m_Handle, 5)) <> SOCKET_ERROR) THEN
    BEGIN
    TempMessage.Msg := WM_SOCKETLISTEN;
    TempMessage.SocketNumber := m_Handle;
    TempMessage.SocketAddress := @self;
    Message_Listen(TempMessage);
    end
  else
    DoClose;
END;  // procedure TAsyncSocket.DoListen

procedure TAsyncSocket.DoConnect;
VAR
  TempResult: LongInt;
BEGIN
  DoClose;
  AllocateSocket;
  ErrorTest(WSAAsyncSelect(m_Handle, m_hWnd.Handle, WM_SOCKET, EVENTS_DOCONNECT));
  TempResult := connect(m_Handle, m_SockAddr, SizeOf(TSockAddr));
  IF ((TempResult = SOCKET_ERROR) AND (WSAGetLastError <> WSAEWOULDBLOCK)) THEN
    ErrorTest(SOCKET_ERROR);
END;  // procedure TAsyncSocket.DoConnect

procedure TAsyncSocket.SendString;
VAR
  L: LongInt;
BEGIN
  L := Length(fString);
  DoSend(PChar(fString), L);
END;

PROCEDURE TAsyncSocket.DoGetHostByName(Name: PChar): String;
VAR
   pTempHostEnt: PHostEnt;
BEGIN
  pTempHostEnt := GetHostByName(Name);
  IF (pTempHostEnt <> Nil) THEN
    Result := inet_ntoa(pInAddr(pTempHostEnt^.h_addr_list^)^)
  else
    Result := '';
END;

procedure TAsyncSocket.ProcessMessages;
VAR Msg: TMsg;
BEGIN
   while PeekMessage(Msg, m_hWnd.m_hWnd, WM_SOCKET, WM_SOCKETLOOKUP, PM_REMOVE) do BEGIN
      DispatchMessage(Msg);
   END;
END;

PROCEDURE TAsyncSocket.DoGetHostByAddr(IPAddr: PChar): String;
VAR
   pTempHostEnt: PHostEnt;
   TempAddr: LongInt;
BEGIN
  TempAddr := INet_Addr(IPAddr);
  pTempHostEnt := GetHostByAddr(@TempAddr, SizeOf(TempAddr), PF_INET);
  IF (pTempHostEnt <> Nil) THEN
    Result := pTempHostEnt^.h_name
  else
    Result := '';
END;

procedure TAsyncSocket.HWndProcedure(VAR Message: TMessage);
VAR
  TempMessage: TWMSocket;
BEGIN
  case Message.Msg of
    WM_SOCKETLOOKUP:
      BEGIN
         TempMessage.Msg := WM_SOCKETLOOKUP;
         TempMessage.SocketNumber := m_Handle;
         TempMessage.SocketAddress := @self;
         Message_Lookup(TempMessage);
      END;
    WM_SOCKET:
      BEGIN
      IF (Message.LParamHi > WSABASEERR) THEN
        BEGIN
        WSASetLastError(Message.LParamHi);
        ErrorTest(SOCKET_ERROR);
        end  // IF (Message.LParamHi > WSABASEERR) THEN
      else
        BEGIN
        case Message.LParamLo of
          FD_READ:
            BEGIN
            TempMessage.SocketDataSize := 0;
            ErrorTest(IOCtlSocket(m_Handle, FIONREAD, TempMessage.SocketDataSize));
            TempMessage.Msg := WM_SOCKETREAD;
            TempMessage.SocketNumber := m_Handle;
            TempMessage.SocketAddress := @self;
            Message_Read(TempMessage);
            END;  // FD_READ
          FD_CLOSE:
            BEGIN
            DoFinal(False);
            END; // FD_CLOSE
          FD_CONNECT:
            BEGIN
            TempMessage.Msg := WM_SOCKETCONNECT;
            TempMessage.SocketNumber := m_Handle;
            TempMessage.SocketAddress := @self;
            Message_Connect(TempMessage);
            END;  // FD_CONNECT
          FD_ACCEPT:
            BEGIN
            TempMessage.Msg := WM_SOCKETACCEPT;
            TempMessage.SocketNumber := m_Handle;
            TempMessage.SocketAddress := @self;
            Message_Accept(TempMessage);
            END;  // FD_ACCEPT
          FD_WRITE:
            BEGIN
            TempMessage.Msg := WM_SOCKETWRITE;
            TempMessage.SocketNumber := m_Handle;
            TempMessage.SocketAddress := @self;
            Message_Write(TempMessage);
            END;  // FD_WRITE
          FD_OOB:
            BEGIN
            TempMessage.Msg := WM_SOCKETOOB;
            TempMessage.SocketNumber := m_Handle;
            TempMessage.SocketAddress := @self;
            Message_OOB(TempMessage);
            END;  // FD_OOB
          END;  // case Message.LParamLo of
        end  // else (IF (Message.LParamHi > WSABASEERR) THEN)
      END;  // WM_SOCKET:
      else
      Message.Result := DefWindowProc(m_hWnd.m_hWnd, Message.Msg, Message.WParam, Message.LParam);
    END;  // case Message.Msg of
END;  // procedure TAsyncSocket.HWndProcedure(VAR Message: TMessage)

procedure TAsyncSocket.Message_Error(VAR Message: TWMSocket);
BEGIN
  IF Assigned(FOnError) THEN FOnError(Message)
  else
  MessageBox(HWND_DESKTOP, PChar(ErrToStr(Message.SocketError) + ' on socket ' +
    Int2Str(Message.SocketNumber)), 'Message_Error', MB_OK);
END;  // procedure TAsyncSocket.Message_Error(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Lookup(VAR Message: TWMSocket);
VAR p: PHostEnt;
BEGIN
  p := @fDNSBuffer;
  fDNSResult := p.h_name;
  IF Assigned(FOnLookup) THEN FOnLookup(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETLOOKUP on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Lookup', MB_OK);
END;  // procedure TAsyncSocket.Message_LookUp(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Close(VAR Message: TWMSocket);
BEGIN
  fConnected := False;
  IF Assigned(FOnClose) THEN FOnClose(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETCLOSE on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Close', MB_OK);
END;  // procedure TAsyncSocket.Message_Close(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Accept(VAR Message: TWMSocket);
BEGIN
  fConnected := True;
  IF Assigned(FOnAccept) THEN FOnAccept(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETACCEPT on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Accept', MB_OK);
END;  // procedure TAsyncSocket.Message_Accept(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Read(VAR Message: TWMSocket);
VAR t:^TBufRecord;
BEGIN
  IF Message.SocketDataSize > 0 THEN BEGIN
     fConnected := True;
     GetMem(t, sizeof(TBufRecord));
     t^.i := Message.SocketDataSize;
     GetMem(t^.p, t^.i);
     DoReceive(t^.p, t^.i);
     FList.Add(t);
  END;
  IF Assigned(FOnRead) THEN FOnRead(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETREAD on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Read', MB_OK);
END;  // procedure TAsyncSocket.Message_Read(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Connect(VAR Message: TWMSocket);
BEGIN
  fConnected := True;
  IF Assigned(FOnConnect) THEN FOnConnect(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETCONNECT on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Connect', MB_OK);
END;  // procedure TAsyncSocket.Message_Connect(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Write(VAR Message: TWMSocket);
BEGIN
  fConnected := True;
  IF Assigned(FOnWrite) THEN FOnWrite(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETWRITE on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Write', MB_OK);
END;  // procedure TAsyncSocket.Message_Write(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_OOB(VAR Message: TWMSocket);
BEGIN
  IF Assigned(FOnOOB) THEN FOnOOB(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETOOB on socket ' + Int2Str(Message.SocketNumber)),
    'Message_OOB', MB_OK);
END;  // procedure TAsyncSocket.Message_OOB(VAR Message: TWMSocket)

procedure TAsyncSocket.Message_Listen(VAR Message: TWMSocket);
BEGIN
  IF Assigned(FOnListen) THEN FOnListen(Message)
  else
  MessageBox(HWND_DESKTOP, PChar('WM_SOCKETLISTEN on socket ' + Int2Str(Message.SocketNumber)),
    'Message_Listen', MB_OK);
END;  // procedure TAsyncSocket.Message_Listen(VAR Message: TWMSocket)

destructor TAsyncSocket.Destroy;
VAR t:^TBufRecord;
    i: integer;
BEGIN
  DoClose;
  IF (InstanceCount = c_FIRST) THEN
    ErrorTest(WSACleanup);
  m_hWnd.Free;
  for i := 0 to FList.Count - 1 do BEGIN
     t := FList.Items[i];
     FreeMem(t^.p, t^.i);
     FreeMem(t, SizeOf(TBufRecord));
  END;
  FList.Free;
  InstanceCount := InstanceCount - 1;
  inherited;
END;

PROCEDURE TAsyncSocket.ErrToStr(Err: LongInt): String;
BEGIN
  case Err of
    WSAEINTR:
      Result := 'WSAEINTR';
    WSAEBADF:
      Result := 'WSAEBADF';
    WSAEACCES:
      Result := 'WSAEACCES';
    WSAEFAULT:
      Result := 'WSAEFAULT';
    WSAEINVAL:
      Result := 'WSAEINVAL';
    WSAEMFILE:
      Result := 'WSAEMFILE';
    WSAEWOULDBLOCK:
      Result := 'WSAEWOULDBLOCK';
    WSAEINPROGRESS:
      Result := 'WSAEINPROGRESS';
    WSAEALREADY:
      Result := 'WSAEALREADY';
    WSAENOTSOCK:
      Result := 'WSAENOTSOCK';
    WSAEDESTADDRREQ:
      Result := 'WSAEDESTADDRREQ';
    WSAEMSGSIZE:
      Result := 'WSAEMSGSIZE';
    WSAEPROTOTYPE:
      Result := 'WSAEPROTOTYPE';
    WSAENOPROTOOPT:
      Result := 'WSAENOPROTOOPT';
    WSAEPROTONOSUPPORT:
      Result := 'WSAEPROTONOSUPPORT';
    WSAESOCKTNOSUPPORT:
      Result := 'WSAESOCKTNOSUPPORT';
    WSAEOPNOTSUPP:
      Result := 'WSAEOPNOTSUPP';
    WSAEPFNOSUPPORT:
      Result := 'WSAEPFNOSUPPORT';
    WSAEAFNOSUPPORT:
      Result := 'WSAEAFNOSUPPORT';
    WSAEADDRINUSE:
      Result := 'WSAEADDRINUSE';
    WSAEADDRNOTAVAIL:
      Result := 'WSAEADDRNOTAVAIL';
    WSAENETDOWN:
      Result := 'WSAENETDOWN';
    WSAENETUNREACH:
      Result := 'WSAENETUNREACH';
    WSAENETRESET:
      Result := 'WSAENETRESET';
    WSAECONNABORTED:
      Result := 'WSAECONNABORTED';
    WSAECONNRESET:
      Result := 'WSAECONNRESET';
    WSAENOBUFS:
      Result := 'WSAENOBUFS';
    WSAEISCONN:
      Result := 'WSAEISCONN';
    WSAENOTCONN:
      Result := 'WSAENOTCONN';
    WSAESHUTDOWN:
      Result := 'WSAESHUTDOWN';
    WSAETOOMANYREFS:
      Result := 'WSAETOOMANYREFS';
    WSAETIMEDOUT:
      Result := 'WSAETIMEDOUT';
    WSAECONNREFUSED:
      Result := 'WSAECONNREFUSED';
    WSAELOOP:
      Result := 'WSAELOOP';
    WSAENAMETOOLONG:
      Result := 'WSAENAMETOOLONG';
    WSAEHOSTDOWN:
      Result := 'WSAEHOSTDOWN';
    WSAEHOSTUNREACH:
      Result := 'WSAEHOSTUNREACH';
    WSAENOTEMPTY:
      Result := 'WSAENOTEMPTY';
    WSAEPROCLIM:
      Result := 'WSAEPROCLIM';
    WSAEUSERS:
      Result := 'WSAEUSERS';
    WSAEDQUOT:
      Result := 'WSAEDQUOT';
    WSAESTALE:
      Result := 'WSAESTALE';
    WSAEREMOTE:
      Result := 'WSAEREMOTE';
    WSASYSNOTREADY:
      Result := 'WSASYSNOTREADY';
    WSAVERNOTSUPPORTED:
      Result := 'WSAVERNOTSUPPORTED';
    WSANOTINITIALISED:
      Result := 'WSANOTINITIALISED';
    WSAHOST_NOT_FOUND:
      Result := 'WSAHOST_NOT_FOUND';
    WSATRY_AGAIN:
      Result := 'WSATRY_AGAIN';
    WSANO_RECOVERY:
      Result := 'WSANO_RECOVERY';
    WSANO_DATA:
      Result := 'WSANO_DATA';
    else Result := 'UNDEFINED WINSOCK ERROR';
    END;  // case Err of
END;  // PROCEDURE TAsyncSocket.ErrToStr(Err: LongInt): String

PROCEDURE TAsyncSocket.LocalIP;
VAR Name: TSockAddrIn;
     len: integer;
BEGIN
   GetSockName(m_Handle, Name, len);
   Result := int2str(ord(Name.sin_addr.S_un_b.s_b1)) + '.' +
             int2str(ord(Name.sin_addr.S_un_b.s_b2)) + '.' +
             int2str(ord(Name.sin_addr.S_un_b.s_b3)) + '.' +
             int2str(ord(Name.sin_addr.S_un_b.s_b4));
END;

PROCEDURE TAsyncSocket.LocalPort;
VAR Name: TSockAddrIn;
     len: integer;
BEGIN
   GetSockName(m_Handle, Name, len);
   Result  := NToHS(Name.sin_port);
END;
*)
BEGIN
  InstanceCount := 0;
END KolSocket.
