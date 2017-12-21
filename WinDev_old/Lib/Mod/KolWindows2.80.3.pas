///////////////////////////////////////////////////////////////////////
//                         W  I  N  D  O  W  S
///////////////////////////////////////////////////////////////////////

{ -- Set of window-related utility functions. -- }
type
  PGUIThreadInfo = ^TGUIThreadInfo;
  tagGUITHREADINFO = {$ifndef wince}packed{$endif} record
    cbSize: DWORD;
    flags: DWORD;
    hwndActive: HWND;
    hwndFocus: HWND;
    hwndCapture: HWND;
    hwndMenuOwner: HWND;
    hwndMoveSize: HWND;
    hwndCaret: HWND;
    rcCaret: TRect;
  end;
  TGUIThreadInfo = tagGUITHREADINFO;

const
  GUI_CARETBLINKING  = $00000001;
  GUI_INMOVESIZE     = $00000002;
  GUI_INMENUMODE     = $00000004;
  GUI_SYSTEMMENUMODE = $00000008;
  GUI_POPUPMENUMODE  = $00000010;

type TGUIThreadInfo_Proc = function( ThreadID: THandle; var GTI: TGUIThreadInfo )
                          : Boolean; {$ifdef wince}cdecl{$else}stdcall{$endif};

var Proc_GetGUIThreadInfo: TGuiThreadInfo_Proc;

//[function GetWindowChild]
function GetWindowChild( Wnd: HWnd; Kind: TWindowChildKind ): HWnd;
var GTI: TGuiThreadInfo;
    ThreadID: THandle;
    Module: THandle;
begin
  if not Assigned( Proc_GetGUIThreadInfo ) then
  begin
    Module := GetModuleHandle( 'User32' );
    Proc_GetGUIThreadInfo := GetProcAddress( Module, 'GetGUIThreadInfoA' );
    if not Assigned( Proc_GetGUIThreadInfo ) then
      Proc_GetGUIThreadInfo := Pointer( -1 );
  end;
  Result := Wnd;
  if @Proc_GetGUIThreadInfo = Pointer( -1 ) then
    Exit;
  Result := 0;
  if Wnd = 0 then
    ThreadID := GetCurrentThreadID
  else
    ThreadID := GetWindowThreadProcessID( Wnd, nil );
  if ThreadID = 0 then Exit;
  GTI.cbSize := Sizeof( GTI );
  if Proc_GetGUIThreadInfo( ThreadId, GTI ) then
  begin
    case Kind of
    wcActive:  Result := GTI.hwndActive;
    wcFocus:   Result := GTI.hwndFocus;
    wcCapture: Result := GTI.hwndCapture;
    wcMenuOwner: Result := GTI.hwndMenuOwner;
    wcMoveSize:  Result := GTI.hwndMoveSize;
    wcCaret:     Result := GTI.hwndCaret;
    end;
  end;
end;

{$ifdef win32}
//[function GetFocusedChild]
function GetFocusedChild( Wnd: HWnd ): HWnd;
var Tr1, Tr2: THandle;
begin
  Result := 0;
  Tr1 := GetCurrentThreadId;
  Tr2 := GetWindowThreadProcessId( Wnd, nil );
  if Tr1 = Tr2 then
    Result := GetFocus
  else
  if AttachThreadInput( Tr2, Tr1, True ) then
  begin
    Result := GetFocus;
    AttachThreadInput( Tr2, Tr1, False );
  end;
end;

//[function WaitFocusedWndChild]
function WaitFocusedWndChild( Wnd: HWnd ): HWnd;
var T1, T2: Integer;
    W: HWnd;
begin
  Sleep( 50 );
  T1 := GetTickCount;
  while True do
  begin
    W := GetTopWindow( Wnd );
    if W = 0 then W := Wnd;
    W := GetFocusedChild( W );
    if W <> 0 then
    begin
      Wnd := W;
      break;
    end;
    T2 := GetTickCount;
    if Abs( T1 - T2 ) > 100 then break;
  end;
  Result := Wnd;
end;

//[function Stroke2Window]
function Stroke2Window( Wnd: HWnd; const S: String ): Boolean;
var P: PChar;
begin
  Result := False;
  //Wnd := GetTopWindow( Wnd );
  Wnd := WaitFocusedWndChild( Wnd );
  if Wnd = 0 then Exit;
  P := PChar( S );
  while P^ <> #0 do
  begin
    PostMessage( Wnd, WM_CHAR, Integer( P^ ), 1 );
    Inc( P );
  end;
  Result := True;
end;

//[function Stroke2WindowEx]
function Stroke2WindowEx( Wnd: HWnd; const S: String; Wait: Boolean ): Boolean;
var P: PChar;
    EndChar: Char;
    MsgDn, MsgUp, SCA: Integer;

    function Compare( Pattern: PChar ): Boolean;
    var Pos: PChar;
        C1, C2: Char;
    begin
      Pos := P;
      while Pattern^ <> #0 do
      begin
        C1 := Pattern^;
        C2 := Pos^;
        if C1 in [ 'a'..'z' ] then
          C1 := Char( Ord( C1 ) - $20 );
        if C2 in [ 'a'..'z' ] then
          C2 := Char( Ord( C2 ) - $20 );
        if C1 <> C2 then
        begin
          Result := False;
          Exit;
        end;
        Inc( Pos );
        Inc( Pattern );
      end;
      while Pos^ = ' ' do Inc( Pos );
      P := Pos;
      Result := True;
    end;

    procedure Send( Msg, KeyCode: Integer );
    var lParam: Integer;
    begin
      Wnd := WaitFocusedWndChild( Wnd );
      if Wnd = 0 then Exit;
      lParam := 1;
      if longBool( SCA and 4 ) then
        lParam := $20000001;
      if Msg = MsgUp then
        lParam := lParam or Integer($D0000000);
      PostMessage( Wnd, Msg, KeyCode, lParam );
      Applet.ProcessMessages;
      if Wait then
        Sleep( 50 );
    end;

    function CompareSend( Pattern: PChar; Value2Send: Integer ): Boolean;
    begin
      if Compare( Pattern ) then
      begin
        Send( MsgDn, Value2Send );
        Send( MsgUp, Value2Send );
        Result := True;
      end
         else
        Result := False;
    end;

    function ParseKeys( EndChar: Char ): PChar;
    var FN: Integer;
    begin
      SCA := 0;
      while not (P^ in [ #0, EndChar ]) do
      begin
        if Compare( 'Shift' ) then SCA := SCA or 1
        else
        if Compare( 'Ctrl' ) then SCA := SCA or 2
        else
        if Compare( 'Alt' ) then SCA := SCA or 4
        else
          break;
      end;
      MsgDn := WM_KEYDOWN;
      MsgUp := WM_KEYUP;
      if LongBool( SCA and 4 ) then
      begin
        MsgDn := WM_SYSKEYDOWN;
        MsgUp := WM_SYSKEYUP;
        keybd_event( VK_MENU, 0, 0, 0 );
        Send( WM_SYSKEYDOWN, VK_MENU );
      end;
      if LongBool( SCA and 2 ) then
      begin
        keybd_event( VK_CONTROL, 0, 0, 0 );
        Send( WM_KEYDOWN, VK_CONTROL );
      end;
      if Longbool( SCA and 1 ) then
      begin
        keybd_event( VK_SHIFT, 0, 0, 0 );
        Send( WM_KEYDOWN, VK_SHIFT );
      end;
      while not (P^ in [ #0, EndChar ]) do
      begin
        if (P^ = 'F') and (P[ 1 ] in [ '1'..'9' ]) then
        begin
          Inc( P );
          FN := Ord( P^ ) - Ord( '0' );
          if (FN = 1) and (P[ 1 ] in [ '0'..'2' ]) then
          begin
            Inc( P );
            FN := 10 + Ord( P^ ) - Ord( '0' );
          end;
          repeat Inc( P ) until P^ <> ' ';
          FN := FN + $6F;
          Send( MsgDn, FN );
          Send( MsgUp, FN );
        end
           else
        if Compare( 'Numpad' ) then
        begin
          if P^ in [ '0'..'9' ] then
          begin
            FN := Ord( P^ ) - Ord( '0' ) + $60;
            repeat Inc( P^ ) until P^ <> ' ';
            Send( MsgDn, FN );
            Send( MsgUp, FN );
          end;
        end
           else
        if not (CompareSend( 'Add', $6B ) or
                CompareSend( 'Gray+', $6B ) or
                CompareSend( 'Apps', $5D ) or
                CompareSend( 'BackSpace', $08 ) or
                CompareSend( 'BkSp', $08 ) or
                CompareSend( 'BS', $08 ) or
                CompareSend( 'Break', $13 ) or
                CompareSend( 'CapsLock', $14 ) or
                CompareSend( 'Clear', $0C ) or
                CompareSend( 'Decimal', $6E ) or
                CompareSend( 'Del', $2E ) or
                CompareSend( 'Delete', $2E ) or
                CompareSend( 'Divide', $6F ) or
                CompareSend( 'Gray/', $6F ) or
                CompareSend( 'Down', $28 ) or
                CompareSend( 'End', $23 ) or
                CompareSend( 'Enter', $0D ) or
                CompareSend( 'Return', $0D ) or
                CompareSend( 'CR', $0D ) or
                CompareSend( 'Esc', $1B ) or
                CompareSend( 'Escape', $1B ) or
                CompareSend( 'Help', $2F ) or
                CompareSend( 'Home', $24 ) or
                CompareSend( 'Ins', $2D ) or
                CompareSend( 'Insert', $2D ) or
                CompareSend( 'Left', $25 ) or
                CompareSend( 'LWin', $5B ) or
                CompareSend( 'Multiply', $6A ) or
                CompareSend( 'Gray*', $6A ) or
                CompareSend( 'NumLock', $90 ) or
                CompareSend( 'PgDn', $22 ) or
                CompareSend( 'PgUp', $21 ) or
                CompareSend( 'PrintScrn', $2C ) or
                CompareSend( 'Right', $27 ) or
                CompareSend( 'RWin', $5C ) or
                CompareSend( 'Separator', $6C ) or
                CompareSend( 'ScrollLock', $91 ) or
                CompareSend( 'Subtract', $6D ) or
                CompareSend( 'Tab', $09 ) or
                CompareSend( 'Gray-', $6D ) or
                CompareSend( 'Up', $26 )) then break;
      end;
      while not (P^ in [ #0, EndChar ]) do
      begin
        if P^ in [ 'A'..'Z', '0'..'9' ] then
        begin
          Send( MsgDn, Integer( P^ ) );
          Send( MsgUp, Integer( P^ ) );
        end
        else
        if P^ in [ #1..#255 ] then
          Stroke2Window( Wnd, '' + P^ );
        repeat Inc( P ) until (P^ <> ' ');
      end;
      if P^ = EndChar then
        Inc( P );
      if Longbool( SCA and 1 ) then
      begin
        Send( WM_KEYUP, VK_SHIFT );
        keybd_event( VK_SHIFT, 0, KEYEVENTF_KEYUP, 0 );
      end;
      if LongBool( SCA and 2 ) then
      begin
        Send( WM_KEYUP, VK_CONTROL );
        keybd_event( VK_CONTROL, 0, KEYEVENTF_KEYUP, 0 );
      end;
      if LongBool( SCA and 4 ) then
      begin
        Send( WM_SYSKEYUP, VK_MENU );
        keybd_event( VK_MENU, 0, KEYEVENTF_KEYUP, 0 );
      end;
      Result := P;
    end;

begin
  Result := False;
  Wnd := GetTopWindow( Wnd );
  Wnd := GetFocusedChild( Wnd );
  if Wnd = 0 then Exit;
  P := PChar( S );
  while P^ <> #0 do
  begin
    if not (P^ in [ '[', '{' ]) then
    begin
      Stroke2Window( Wnd, '' + P^ );
      Inc( P );
    end
      else
    begin
      if P^ = '[' then
        EndChar := ']'
      else
        EndChar := '}';
      Inc( P );
      P := ParseKeys( EndChar );
    end;
  end;
  Result := True;
end;
{$endif win32}

type
  PHWnd = ^HWnd;

  TFindWndRec = {$ifndef wince}packed{$endif} Record
    ThreadID : DWord;
    WndFound : HWnd;
  end;
  PFindWndRec = ^TFindWndRec;

//[function EnumWindowsProc]
function EnumWindowsProc( Wnd : HWnd; Find : PFindWndRec ) : Boolean;
{$ifdef wince}cdecl{$else}stdcall{$endif};
var Id : DWord;
begin
  Result := True;
  Id := GetWindowThreadProcessId( Wnd, @Id );
  if Id = Find.ThreadID then
  begin
    Find.WndFound := Wnd;
    Result := False;
  end;
end;

//[function FindWindowByThreadID]
function FindWindowByThreadID( ThreadID : DWORD ) : HWnd;
var Find : TFindWndRec;
begin
  Find.ThreadID := ThreadID;
  Find.WndFound := 0;
  EnumWindows( @EnumWindowsProc, Integer( @Find ) );
  Result := Find.WndFound;
end;

//[function DesktopPixelFormat]
function DesktopPixelFormat: TPixelFormat;
var DC: HDC;
    Nbits_per_pixel, Nplanes: Integer;
begin
  DC := GetDC( 0 );
  Nbits_per_pixel := GetDeviceCaps( DC, BITSPIXEL );
  Nplanes := GetDeviceCaps( DC, PLANES );
  ReleaseDC( 0, DC );
  CASE Nplanes * Nbits_per_pixel OF
  1: Result := pf1bit;
  4: Result := pf4bit;
  8: Result := pf8bit;
  16: Result := pf16bit;
  24, 32: Result := pf32bit;
  else Result := pfDevice;
  END;
end;

//[function GetDesktopRect]
function GetDesktopRect : TRect;
{$ifdef win32}
var W1, W2 : HWnd;
{$endif win32}
begin
  Result := MakeRect( 0, 0, GetSystemMetrics( SM_CXSCREEN ), GetSystemMetrics( SM_CYSCREEN ) );
{$ifdef win32}
  W2 := findwindow(nil,'Program Manager');
  W1 := findwindowex(W2,0,'SHELLDLL_DefView',nil);
  if W1 = 0 then Exit;
  GetWindowRect( W1, Result );
{$endif win32}
end;

//[function GetWorkArea]
function GetWorkArea: TRect;
begin
  SystemParametersInfo( SPI_GETWORKAREA, 0, @ Result, 0 );
end;

//[function ExecuteWait]
function ExecuteWait( const AppPath, CmdLine, DfltDirectory: KOLString;
         Show: DWORD; TimeOut: DWORD; ProcID: PDWORD ): Boolean;
var Flags: DWORD;
    Startup: TStartupInfo;
    ProcInf: TProcessInformation;
    DfltDir, pAppPath: PKOLChar;
    Cmd: KOLString;
begin
  Result := FALSE;
{$ifdef wince}
  Flags := 0;
{$else}
  Flags := CREATE_NEW_CONSOLE;
  if Show = SW_HIDE then
    Flags := Flags or {$IFDEF F_P}$08000000{$ELSE}CREATE_NO_WINDOW{$ENDIF};
{$endif wince}
  FillChar( Startup, SizeOf( Startup ), #0 );
  Startup.cb := Sizeof( Startup );
  Startup.wShowWindow := Show;
  Startup.dwFlags := STARTF_USESHOWWINDOW;
  if ProcID <> nil then
    ProcID^ := 0;
  DfltDir := nil;
  if DfltDirectory <> '' then
    DfltDir := PKOLChar( DfltDirectory );
  if AppPath <> '' then
    pAppPath:=PKOLChar(AppPath)
  else
    pAppPath:=nil;
  Cmd:=CmdLine; // CmdLine parameter must not be const
  if CreateProcess( pAppPath, PKOLChar(Cmd), nil,
     nil, FALSE, Flags, nil, DfltDir, Startup,
     ProcInf ) then
  begin
    if WaitForSingleObject( ProcInf.hProcess, TimeOut ) = WAIT_OBJECT_0 then
    begin
      CloseHandle( ProcInf.hProcess );
      Result := TRUE;
    end
      else
    begin
      if ProcID <> nil then
        ProcID^ := ProcInf.hProcess;
    end;
    CloseHandle( ProcInf.hThread );
  end;
end;

{$ifdef win32}
//[function ExecuteIORedirect]
function ExecuteIORedirect( const AppPath, CmdLine, DfltDirectory: KOLString;
         Show: DWORD; ProcID: PDWORD; InPipe, OutPipeWr, OutPipeRd: PHandle ): Boolean;
var Flags: DWORD;
    Startup: TStartupInfo;
    ProcInf: TProcessInformation;
    DfltDir: PKOLChar;
    SecurityAttributes: TSecurityAttributes;
    SaveStdOut, SaveStdIn: THandle;
    ChildStdOutRd, ChildStdOutWr: THandle;
    ChildStdInRd, ChildStdInWr: THandle;
    ChildStdOutRdDup: THandle;
    ChildStdInWrDup: THandle;

    procedure Do_CloseHandle( var Handle: THandle );
    begin
      if Handle <> 0 then
      begin
        CloseHandle( Handle );
        Handle := 0;
      end;
    end;

    procedure Close_Handles;
    begin
      Do_CloseHandle( ChildStdOutRd );
      Do_CloseHandle( ChildStdOutWr );
      Do_CloseHandle( ChildStdInRd );
      Do_CloseHandle( ChildStdInWr );
    end;

    function RedirectInputOutput: Boolean;
    begin
      Result := FALSE;
      if (OutPipeRd <> nil) or (OutPipeWr <> nil) then
      begin
        // redirect output
        SaveStdOut := GetStdHandle(STD_OUTPUT_HANDLE);
        if not CreatePipe( ChildStdOutRd, ChildStdOutWr, @ SecurityAttributes, 0 ) then
          Exit;
        if not SetStdHandle( STD_OUTPUT_HANDLE, ChildStdOutWr ) then
          Exit;
        if not DuplicateHandle( GetCurrentProcess, ChildStdOutRd,
           GetCurrentProcess, @ ChildStdOutRdDup, 0, FALSE,
           2 {DUPLICATE_SAME_ACCESS} ) then
          Exit;
        Do_CloseHandle( ChildStdOutRd );
        if OutPipeRd <> nil then
          OutPipeRd^ := ChildStdOutRdDup;
        if OutPipeWr <> nil then
          OutPipeWr^ := ChildStdOutWr;
      end;
      if InPipe <> nil then
      begin
        // redirect input
        SaveStdIn := GetStdHandle(STD_INPUT_HANDLE);
        if not CreatePipe( ChildStdInRd, ChildStdInWr, @ SecurityAttributes, 0 ) then
          Exit;
        if not SetStdHandle( STD_INPUT_HANDLE, ChildStdInRd ) then
          Exit;
        if not DuplicateHandle( GetCurrentProcess, ChildStdInWr,
           GetCurrentProcess, @ ChildStdInWrDup, 0, FALSE,
           2 {DUPLICATE_SAME_ACCESS} ) then
          Exit;
        Do_CloseHandle( ChildStdInWr );
        if InPipe <> nil then
          InPipe^ := ChildStdInWrDup;
        Do_CloseHandle( ChildStdInRd );
      end;
      Result := TRUE;
    end;

    procedure Restore_Saved_StdInOut;
    begin
      SetStdHandle( STD_OUTPUT_HANDLE, SaveStdOut );
      SetStdHandle( STD_INPUT_HANDLE, SaveStdIn );
    end;

begin
  Result := FALSE;
  Flags := 0;
  if Show = SW_HIDE then
    Flags := Flags or {$IFDEF F_P}$08000000{$ELSE}CREATE_NO_WINDOW{$ENDIF};
  FillChar( Startup, SizeOf( Startup ), #0 );
  Startup.cb := Sizeof( Startup );
  if ProcID <> nil then
    ProcID^ := 0;
  DfltDir := nil;
  SecurityAttributes.nLength := Sizeof( SecurityAttributes );
  SecurityAttributes.lpSecurityDescriptor := nil;
  SecurityAttributes.bInheritHandle := TRUE;
  SaveStdOut := 0;
  SaveStdIn := 0;
  ChildStdOutRd := 0;
  ChildStdOutWr := 0;
  ChildStdInRd := 0;
  ChildStdInWr := 0;
  if not RedirectInputOutput then
  begin
    Close_Handles;
    Exit;
  end;;
  if DfltDirectory <> '' then
    DfltDir := PKOLChar( DfltDirectory );
  if CreateProcess( nil, PKOLChar( '"' + AppPath + '" ' + CmdLine ),
     nil, nil, TRUE, Flags, nil, DfltDir, Startup,
     ProcInf ) then
  begin
    if ProcID <> nil then
      ProcID^ := ProcInf.hProcess
    else
      CloseHandle( ProcInf.hProcess );
    CloseHandle( ProcInf.hThread );
    Restore_Saved_StdInOut;
    Result := TRUE;
  end
    else
  begin
    Restore_Saved_StdInOut;
    Close_Handles;
    Exit;
  end;
end;

//[function ExecuteConsoleAppIORedirect]
function ExecuteConsoleAppIORedirect( const AppPath, CmdLine, DfltDirectory: String;
         Show: DWORD; const InStr: String; var OutStr: String; WaitTimeout: DWORD ): Boolean;
var PipeIn, PipeOutRd, PipeOutWr: THandle;
    ProcID: DWORD;
    BytesCount: DWORD;
    Buffer: array[ 0..4096 ] of Char;
    BufStr: String;
    PPipeIn: PHandle;
begin
  Result := FALSE;
  PPipeIn := @ PipeIn;
  if InStr = '' then
    PPipeIn := nil;
  PipeOutRd := 0;
  PipeOutWr := 0;
  if not ExecuteIORedirect( AppPath, CmdLine, DfltDirectory, Show, @ ProcID,
                     PPipeIn, @ PipeOutWr, @ PipeOutRd ) then Exit;
  if PPipeIn <> nil then
  begin
    if InStr <> '' then
      WriteFile( PipeIn, InStr[ 1 ], Length( InStr ), BytesCount, nil );
    CloseHandle( PipeIn );
  end;
  OutStr := '';
  if WaitForSingleObject( ProcID, WaitTimeOut ) = WAIT_OBJECT_0 then
  begin
    CloseHandle( ProcID );
    CloseHandle( PipeOutWr );
    while ReadFile( PipeOutRd, Buffer, Sizeof( Buffer ), BytesCount, nil ) do
    begin
      SetLength( BufStr, BytesCount );
      Move( Buffer[ 0 ], BufStr[ 1 ], BytesCount );
      OutStr := OutStr + BufStr;
    end;
  end
    else
    CloseHandle( PipeOutWr );
  CloseHandle( PipeOutRd );
  Result := TRUE;
end;

{$IFDEF _D2}
//[API OpenProcessToken]
function OpenProcessToken(ProcessHandle: THandle; DesiredAccess: DWORD;
  var TokenHandle: THandle): BOOL; {$ifdef wince}cdecl{$else}stdcall{$endif};
  external advapi32 name 'OpenProcessToken';
{$ENDIF}

//[function WindowsShutdown]
function WindowsShutdown( const Machine : KOLString; Force, Reboot : Boolean ) : Boolean;
var
  hToken: THandle;
  tkp, tkp_prev: TTokenPrivileges;
  dwRetLen :DWORD;
  Flags: Integer;
begin
  Result := False;
  if Integer( GetVersion ) < 0 then // Windows95/98/Me
  begin
    if Machine <> '' then Exit;
    Flags := EWX_SHUTDOWN;
    if Reboot then
      Flags := Flags or EWX_REBOOT;
    if Force then
      Flags := Flags or EWX_FORCE;
    Result := ExitWindowsEx( Flags, 0 );
    Exit;
  end;

  OpenProcessToken(GetCurrentProcess(),
                   TOKEN_ADJUST_PRIVILEGES or TOKEN_QUERY,
                   hToken);

  if not LookupPrivilegeValue(PKOLChar(Machine), 'SeShutdownPrivilege',
                              tkp.Privileges[0].Luid) then Exit;
  tkp_prev:=tkp;
  tkp.PrivilegeCount:=1;
  tkp.Privileges[0].Attributes:=SE_PRIVILEGE_ENABLED;
  AdjustTokenPrivileges(hToken, FALSE, tkp, sizeof(tkp), tkp_prev,
dwRetLen);

  if not LookupPrivilegeValue(PKOLChar(Machine),
                              'SeRemoteShutdownPrivilege',
                              tkp.Privileges[0].Luid)
     then
         Exit;

  tkp.PrivilegeCount:=1;
  tkp.Privileges[0].Attributes:=SE_PRIVILEGE_ENABLED;
  AdjustTokenPrivileges(hToken, FALSE, tkp, sizeof(tkp), tkp_prev,
dwRetLen);

  Result := InitiateSystemShutdown(PKOLChar(Machine),nil, 0, Force, Reboot);
end;

var SaveWinVer: Byte = $FF;

//[function WinVer]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION}
function WinVer : TWindowsVersion;
var MajorVersion, MinorVersion: Byte;
    dwVersion: Integer;
begin
  if SaveWinVer <> $FF then Result := TWindowsVersion( SaveWinVer )
  else
  begin
    dwVersion := GetVersion;
    MajorVersion := LoByte( dwVersion );
    MinorVersion := HiByte( LoWord( dwVersion ) );
    if dwVersion >= 0 then
    begin
      Result := wvNT;
      if MajorVersion >= 6 then
        Result := wvVista
      else begin
             if MajorVersion >= 5 then
                if MinorVersion >= 1 then
                begin
                     Result := wvXP;
                     if MinorVersion >= 2 then
                       Result := wvServer2003;
                end
                else Result := wvY2K;
           end;
    end
      else
    begin
      Result := wv95;
      if (MajorVersion > 4) or
         (MajorVersion = 4) and (MinorVersion >= 10)  then
      begin
        Result := wv98;
        if (MajorVersion = 4) and (MinorVersion >= $5A) then
          Result := wvME;
      end
        else
      if MajorVersion <= 3 then
        Result := wv31;
    end;
    SaveWinVer := Ord( Result );
  end;
end;
{$ENDIF ASM_VERSION}
{$else}
function WinVer : TWindowsVersion;
begin
  Result:=wvCE;
end;
{$endif win32}

//[function IsWinVer]
function IsWinVer( Ver : TWindowsVersions ) : Boolean;
{* Returns True if Windows version is in given range of values. }
begin
  Result := WinVer in Ver;
end;

//[procedure TControl.SetAlphaBlend]
procedure TControl.SetAlphaBlend(const Value: Integer);
const
  LWA_COLORKEY=$00000001;
  LWA_ALPHA=$00000002;
  ULW_COLORKEY=$00000001;
  ULW_ALPHA=$00000002;
  ULW_OPAQUE=$00000004;
  WS_EX_LAYERED=$00080000;
type
  TSetLayeredWindowAttributes=
    function( hwnd: Integer; crKey: TColor; bAlpha: Byte; dwFlags: DWORD )
    : Boolean; {$ifdef wince}cdecl{$else}stdcall{$endif};
var
  SetLayeredWindowAttributes: TSetLayeredWindowAttributes;
  User32: THandle;
  dw: DWORD;
begin
  if Value = fAlphaBlend then Exit;
  fAlphaBlend := Value;
  User32 := GetModuleHandle( 'User32' );
  SetLayeredWindowAttributes := GetProcAddress( User32,
                             'SetLayeredWindowAttributes' );
  if Assigned( SetLayeredWindowAttributes ) then
  begin
    dw := GetWindowLong( GetWindowHandle, GWL_EXSTYLE );
    if Byte( Value ) < 255 then
    begin
      SetWindowLong( fHandle, GWL_EXSTYLE, dw or WS_EX_LAYERED );
      SetLayeredWindowAttributes( fHandle, 0, Value and $FF, LWA_ALPHA);
    end
       else
      SetWindowLong( fHandle, GWL_EXSTYLE, dw and not WS_EX_LAYERED );
  end;
end;

{$ENDIF WIN_GDI}
//[function TControl.SetPosition]
function TControl.SetPosition( X, Y: Integer ): PControl;
begin
  Left := X;
  Top := Y;
  Result := @Self;
end;
{$IFDEF WIN_GDI}

//[function NewColorDialog]
function NewColorDialog( FullOpen: TColorCustomOption ): PColorDialog;
var I: Integer;
begin
  {-}
  New( Result, Create );
  {+}{++}(*Result := PColorDialog.Create;*){--}
  Result.ColorCustomOption := FullOpen;
  for I := 1 to 16 do
    Result.CustomColors[ I ] := clWhite;
end;
//[END NewColorDialog]

{ TColorDialog }

//[function TColorDialog.Execute]
function TColorDialog.Execute: Boolean;
var CD: TChooseColor;
begin
  CD.lStructSize := Sizeof( CD );
  CD.hWndOwner := OwnerWindow;
  //CD.hInstance := 0;
  CD.rgbResult := Color2RGB( Color );
  CD.lpCustColors := @CustomColors[ 1 ];
  CD.Flags := CC_RGBINIT;
  case ColorCustomOption of
  ccoFullOpen: CD.Flags := CD.Flags or CC_FULLOPEN;
  ccoPreventFullOpen: CD.Flags := CD.Flags or CC_PREVENTFULLOPEN;
  end;
  Result := ChooseColor( {$ifdef wince}@{$endif}CD );
  if Result then
    Color := CD.rgbResult;
end;

//[procedure TControl.SetMaxProgress]
procedure TControl.SetMaxProgress(const Index, Value: Integer);
begin
  // ignore index, and set Value via PBM_SETRANGE32:     ()
  Perform( PBM_SETRANGE32, 0, Value );
end;

//[procedure TControl.SetDroppedWidth]
procedure TControl.SetDroppedWidth(const Value: Integer);
begin
  FDroppedWidth := Value;
  Perform( CB_SETDROPPEDWIDTH, Value, 0 );
end;

//[function TControl.LVGetItemState]
function TControl.LVGetItemState(Idx: Integer): TListViewItemState;
type
  PListViewItemState = ^TListViewItemState;
var I: integer;
begin
  I := Perform( LVM_GETITEMSTATE, Idx,
                LVIS_CUT or LVIS_DROPHILITED or LVIS_FOCUSED or LVIS_SELECTED );
  Result := PListViewItemState( @ I )^;
end;

//[procedure TControl.LVSetItemState]
procedure TControl.LVSetItemState(Idx: Integer; const Value: TListViewItemState);
var Data: TLVItem;
begin
  Data.stateMask := LVIS_FOCUSED or LVIS_SELECTED or LVIS_CUT or LVIS_DROPHILITED;
  Data.state     := PByte( @ Value )^;
  Perform( LVM_SETITEMSTATE, Idx, Integer( @Data ) );
end;

//[procedure TControl.LVSelectAll]
procedure TControl.LVSelectAll;
begin
  LVSetItemState( -1, [ lvisSelect ] );
end;

//[function TControl.LVItemInsert]
function TControl.LVItemInsert(Idx: Integer; const aText: KOLString): Integer;
var LVI: TLVItem;
begin
  LVI.mask := LVIF_TEXT;
  LVI.iItem := Idx;
  LVI.iSubItem := 0;
  LVI.pszText := PKOL_Char( aText );
  Result := Perform( LVM_INSERTITEM, 0, Integer( @LVI ) );
end;

//[function TControl.LVItemAdd]
function TControl.LVItemAdd(const aText: KOLString): Integer;
begin
  Result := LVItemInsert( Count, aText );
end;

//[function TControl.LVGetSttImgIdx]
function TControl.LVGetSttImgIdx(Idx: Integer): Integer;
begin
  Result := Perform( LVM_GETITEMSTATE, Idx, LVIS_STATEIMAGEMASK ) shr 12;
end;

//[procedure TControl.LVSetSttImgIdx]
procedure TControl.LVSetSttImgIdx(Idx: Integer; const Value: Integer);
var LVI: TLVItem;
begin
  LVI.stateMask := LVIS_STATEIMAGEMASK;
  LVI.state := Value shl 12;
  Perform( LVM_SETITEMSTATE, Idx, Integer( @LVI ) );
end;

//[function TControl.LVGetOvlImgIdx]
function TControl.LVGetOvlImgIdx(Idx: Integer): Integer;
begin
  Result := Perform( LVM_GETITEMSTATE, Idx, LVIS_OVERLAYMASK ) shr 8;
end;

//[procedure TControl.LVSetOvlImgIdx]
procedure TControl.LVSetOvlImgIdx(Idx: Integer; const Value: Integer);
var LVI: TLVItem;
begin
  LVI.stateMask := LVIS_OVERLAYMASK;
  LVI.state := Value shl 8;
  Perform( LVM_SETITEMSTATE, Idx, Integer( @LVI ) );
end;

//[function TControl.LVGetItemData]
function TControl.LVGetItemData(Idx: Integer): DWORD;
var LVI: TLVItem;
begin
  LVI.mask := LVIF_PARAM;
  LVI.iItem := Idx;
  LVI.iSubItem := 0;
  Perform( LVM_GETITEM, 0, Integer( @LVI ) );
  Result := LVI.lParam;
end;

//[procedure TControl.LVSetItemData]
procedure TControl.LVSetItemData(Idx: Integer; const Value: DWORD);
var LVI: TLVItem;
begin
  LVI.mask := LVIF_PARAM;
  LVI.iItem := Idx;
  LVI.iSubItem := 0;
  LVI.lParam := Value;
  Perform( LVM_SETITEM, 0, Integer( @LVI ) );
end;

//[function TControl.LVGetItemIndent]
function TControl.LVGetItemIndent(Idx: Integer): Integer;
var LI: TLVItem;
begin
  LI.mask := LVIF_INDENT;
  LI.iItem := Idx;
  LI.iSubItem := 0;
  Perform( LVM_GETITEM, 0, Integer( @LI ) );
  Result := LI.iIndent;
end;

//[procedure TControl.LVSetItemIndent]
procedure TControl.LVSetItemIndent(Idx: Integer; const Value: Integer);
var LI: TLVItem;
begin
  LI.mask := LVIF_INDENT;
  LI.iItem := Idx;
  LI.iSubItem := 0;
  LI.iIndent := Value;
  Perform( LVM_SETITEM, 0, Integer( @LI ) );
end;

type
  TNMLISTVIEW = {$ifndef wince}packed{$endif} Record
    hdr: TNMHDR;
    iItem: Integer;
    iSubItem: Integer;
    uNewState: Integer;
    uOldState: Integer;
    uChanged: Integer;
    ptAction: Integer;
    lParam: DWORD;
  end;
  PNMLISTVIEW = ^TNMLISTVIEW;

//[function WndProc_LVDeleteItem]
function WndProc_LVDeleteItem( Sender: PControl; var Msg: TMsg; var Rslt: Integer )
                          : Boolean;
var Hdr: PNMHDR;
    LV: PNMListView;
begin
  Result := FALSE;
  if Msg.message = WM_NOTIFY then
  begin
    Hdr := Pointer(Msg.lParam);
    if Hdr.hwndFrom = Sender.Handle then
    begin
      LV := Pointer( Hdr );
      if LongInt(Hdr.code) = LVN_DELETEITEM then
      begin
        if Assigned( Sender.OnDeleteLVItem ) then
          Sender.OnDeleteLVItem( Sender, LV.iItem );
        Result := TRUE;
      end
        else
      if LongInt(Hdr.code) = LVN_DELETEALLITEMS then
      begin
        if Assigned( Sender.OnDeleteAllLVItems ) then
        begin
          Sender.OnDeleteAllLVItems( Sender );
          Rslt := 0;
          if Assigned( Sender.OnDeleteLVItem ) then
            Rslt := 1;
        end;
        Result := TRUE;
      end;
    end;
  end;
end;

//[procedure TControl.SetOnDeleteAllLVItems]
procedure TControl.SetOnDeleteAllLVItems(const Value: TOnEvent);
begin
  fOnDeleteAllLVItems := Value;
  AttachProc( @WndProc_LVDeleteItem );
end;

//[procedure TControl.SetOnDeleteLVItem]
procedure TControl.SetOnDeleteLVItem(const Value: TOnDeleteLVItem);
begin
  fOnDeleteLVItem := Value;
  AttachProc( @WndProc_LVDeleteItem );
end;

//[function WndProc_LVData]
function WndProc_LVData( Sender: PControl; var Msg: TMsg; var Rslt: Integer )
                          : Boolean;
var Hdr: PNMHDR;
    DI: PLVDispInfo;
    Store: Boolean;
    Txt: KOL_String;
    LV: PControl;
begin
  Result := FALSE;
  if Msg.message = WM_NOTIFY then
  begin
    Hdr := Pointer(Msg.lParam);
    if Hdr.hwndFrom = Sender.Handle then
    begin
      if (LongInt(Hdr.code) = LVN_GETDISPINFO)
         {$IFDEF UNICODE_CTRLS}
         or (LongInt(Hdr.code) = LVN_GETDISPINFOW)
         {$ENDIF UNICODE_CTRLS}
      then
      begin
        DI := Pointer( Hdr );
        LV := Sender;
        if LV <> nil then
        begin
          DI.item.iImage := -1;
          DI.item.state := 0;
          Store := FALSE;
          if Assigned( LV.OnLVData ) and (DI.item.iItem >= 0) then
          begin
            LV.OnLVData( LV, DI.item.iItem, DI.item.iSubItem, Txt,
                             DI.item.iImage, DWORD( DI.item.state ), Store );
            if LongBool(DI.item.mask and LVIF_TEXT) then begin
              LV.fCaption := Txt;
              DI.item.pszText := PKOL_Char( PKOLChar( LV.fCaption ) );
            end;
            DI.item.stateMask := 0;
            if DI.item.state and LVIS_STATEIMAGEMASK <> 0 then
              DI.item.stateMask := LVIS_STATEIMAGEMASK;
            if DI.item.state and LVIS_OVERLAYMASK <> 0 then
              DI.item.stateMask := DI.item.stateMask or LVIS_OVERLAYMASK;
            if DI.item.state and $7F <> 0 then
              DI.item.stateMask := DI.item.stateMask or $7F;
            if Store then
              DI.item.mask := DI.item.mask or LVIF_DI_SETITEM;
          end;
          Result := TRUE;
        end;
      end;
    end;
  end;
end;

//[procedure TControl.SetOnLVData]
procedure TControl.SetOnLVData(const Value: TOnLVData);
begin
  fOnLVData := Value;
  AttachProc( @WndProc_LVData );
  Perform( LVM_SETCALLBACKMASK, LVIS_OVERLAYMASK or LVIS_STATEIMAGEMASK, 0 );
end;

{$IFDEF ENABLE_DEPRECATED}
{$DEFINE implementation} {$I KOL_deprecated.inc} {$UNDEF implementation}
{$ENDIF DISABLE_DEPRECATED}

//[function WndProc_LVCustomDraw]
function WndProc_LVCustomDraw( Sender: PControl; var Msg: TMsg;
                               var Rslt: Integer ): Boolean;
var NMCustDraw: PNMLVCustomDraw;
    NMHdr: PNMHdr;
    ItemIdx, SubItemIdx: Integer;
    S: TListViewItemState;
    ItemState: TDrawState;
begin
  Result := FALSE;
  if Msg.message = WM_NOTIFY then
  begin
    NMHdr := Pointer( Msg.lParam );
    if (LongInt(NMHdr.code) = NM_CUSTOMDRAW) and Assigned( Sender.fOnLVCustomDraw ) then
    begin
      NMCustDraw := Pointer( Msg.lParam );
      ItemIdx := -1;
      SubItemIdx := -1;
      if LongBool( NMCustDraw.nmcd.dwDrawStage and CDDS_ITEM ) then
        ItemIdx := NMCustDraw.nmcd.dwItemSpec;
      if LongBool( NMCustDraw.nmcd.dwDrawStage and CDDS_SUBITEM ) then
        SubItemIdx := NMCustDraw.iSubItem;
      ItemState := [ ];
      if ItemIdx >= 0 then
      begin
        S := Sender.LVItemState[ ItemIdx ];
        if lvisFocus in S then
          ItemState := ItemState + [ odsFocused ];
        if lvisSelect in S then
          ItemState := ItemState + [ odsSelected ];
        if lvisBlend in S then
          ItemState := ItemState + [ odsGrayed ];
        if lvisHighlight in S then
          ItemState := ItemState + [ odsMarked ];
      end;

      Sender.Canvas;

      Rslt := Sender.FOnLVCustomDraw( Sender, {Sender.fPaintDC} NMCustDraw.nmcd.hdc,
           NMCustDraw.nmcd.dwDrawStage, ItemIdx, SubItemIdx, NMCustDraw.nmcd.rc,
           ItemState, TColor( NMCustDraw.clrText ), TColor( NMCustDraw.clrTextBk ) );

      Result := TRUE;
    end;
  end;
end;

//[procedure TControl.SetOnLVCustomDraw]
procedure TControl.SetOnLVCustomDraw(const Value: TOnLVCustomDraw);
begin
  fOnLVCustomDraw := Value;
  AttachProc( @WndProc_LVCustomDraw );
end;

//[function CompareLVItems]
function CompareLVItems( Idx1, Idx2: Integer; ListView: PControl ): Integer; {$ifdef wince}cdecl{$else}stdcall{$endif};
begin
  if Assigned( ListView.fOnCompareLVItems ) then
    Result := ListView.fOnCompareLVItems( ListView, Idx1, Idx2 )
  else
    Result := 0;
end;

//[procedure TControl.LVSort]
procedure TControl.LVSort;
begin
{$ifdef wince}
  MsgOk('TControl.LVSort must be fixed!');
  Halt(6); // FIXME
{$else}
  Perform( LVM_SORTITEMSEX, Integer(@Self), Integer(@CompareLVItems) );
{$endif wince}
end;

//[function CompareLVItemsData]
function CompareLVItemsData( D1, D2: DWORD; ListView: PControl ): Integer; {$ifdef wince}cdecl{$else}stdcall{$endif};
begin
  if Assigned( ListView.fOnCompareLVItems ) then
    Result := ListView.fOnCompareLVItems( ListView, D1, D2 )
  else
    Result := 0;
end;

//[procedure TControl.LVSortData]
procedure TControl.LVSortData;
begin
  Perform( LVM_SORTITEMS, Integer( @Self ), Integer( @CompareLVItemsData ) );
end;

//[function WndProc_LVColumnClick]
function WndProc_LVColumnClick( Sender: PControl; var Msg: TMsg; var Rslt: Integer )
                          : Boolean;
var Hdr: PNMHDR;
    LV: PNMListView;
begin
  Result := FALSE;
  if Msg.message = WM_NOTIFY then
  begin
    Hdr := Pointer(Msg.lParam);
    if Hdr.hwndFrom = Sender.Handle then
    begin
      LV := Pointer( Hdr );
      if LongInt(Hdr.code) = LVN_COLUMNCLICK then
      begin
        if Assigned( Sender.OnColumnClick ) then
          Sender.OnColumnClick( Sender, LV.iSubItem );
        Result := TRUE;
      end;
    end;
  end;
end;

//[procedure TControl.SetOnColumnClick]
procedure TControl.SetOnColumnClick(const Value: TOnLVColumnClick);
begin
  fOnColumnClick := Value;
  AttachProc( @WndProc_LVColumnClick );
end;

//[function WndProc_LVStateChange]
function WndProc_LVStateChange( Sender: PControl; var Msg: TMsg; var R: Integer ): Boolean;
var NMOD: PNMLVODStateChange;
    NMLV: PNMLISTVIEW;
begin
  if Msg.message = WM_NOTIFY then
  begin
    NMOD := Pointer( Msg.lParam );
    NMLV := Pointer( Msg.lParam );
    if LongInt(NMOD.hdr.code) = LVN_ODSTATECHANGED then
    begin
      if Assigned( Sender.OnLVStateChange ) then
        Sender.OnLVStateChange( Sender, NMOD.iFrom, NMOD.iTo,
                                NMOD.uOldState, NMOD.uNewState );
    end
      else
    if LongInt(NMLV.hdr.code) = LVN_ITEMCHANGED then
    begin
      if Assigned( Sender.OnLVStateChange ) then
        Sender.OnLVStateChange( Sender, NMLV.iItem, NMLV.iItem,
                                NMLV.uOldState, NMLV.uNewState );
    end;
  end;
  Result := FALSE;
end;

//[procedure TControl.SetOnLVStateChange]
procedure TControl.SetOnLVStateChange(const Value: TOnLVStateChange);
begin
  FOnLVStateChange := Value;
  AttachProc( WndProc_LVStateChange );
end;

//[function CompareLVColumns]
function CompareLVColumns( Idx1, Idx2: Integer; Sender: PControl ): Integer; {$ifdef wince}cdecl{$else}stdcall{$endif};
var S1, S2: String;
begin
  //--- changed by Mike Gerasimov:
  S1 := Sender.LVItems[ Idx1, Sender.fColumn ];
  S2 := Sender.LVItems[ Idx2, Sender.fColumn ];
  If lvoSortAscending in Sender.fLVOptions Then
   Result := AnsiCompareStrNoCase( S1, S2 )
  Else
   If lvoSortDescending in Sender.fLVOptions Then
    Result := AnsiCompareStrNoCase( S2, S1 )
   Else
    Result:=0;
end;

//[procedure TControl.LVSortColumn]
procedure TControl.LVSortColumn(Idx: Integer);
begin
  fColumn := Idx;
{$ifdef wince}
  MsgOk('TControl.LVSortColumn must be fixed!');
  Halt(6); // FIXME
{$else}
  Perform( LVM_SORTITEMSEX, Integer(@Self), Integer(@CompareLVColumns) );
{$endif wince}
end;

//[function TControl.LVIndexOf]
function TControl.LVIndexOf(const S: KOLString): Integer;
begin
  Result := LVSearchFor( S, -1, FALSE );
end;

//[function TControl.LVSearchFor]
function TControl.LVSearchFor(const S: KOLString; StartAfter: Integer;
  Partial: Boolean): Integer;
var f: TLVFindInfo;
begin
    f.lParam := 0;
    f.flags  := LVFI_STRING;
    if Partial then
      f.flags := LVFI_STRING or LVFI_PARTIAL;
    f.psz    := @s[1];
    result := Perform(LVM_FINDITEM,StartAfter,integer(@f));
end;

function WndProcLVMeasureItem( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var
  pMI: PMeasureItemStruct;
  P: PControl;
  H: Integer;
  wId: DWORD;
  i: Integer;
begin
  Result := FALSE;
  if Msg.message = WM_MEASUREITEM then begin
    pMI := Pointer(Msg.lParam);
    with pMI^ do begin
      for i:=0 to Sender.ChildCount-1 do begin
        P := Sender.Children[i];
        if P <> nil then begin
          wId := GetWindowLong(P.Handle,GWL_ID);
          if CtlID = wId then begin
            H := P.fLVItemHeight;
            if H > 0 then begin
              itemHeight := H;
              Rslt:=1;
              Result := TRUE;
            end;
            break;
          end;
        end;
      end;
    end;
  end;
end;

function TControl.SetLVItemHeight(Value: Integer): PControl;
begin
  Set_LVItemHeight( Value );
  Result := @ Self;
end;

procedure TControl.Set_LVItemHeight(Value: Integer);
begin
  if fLVItemHeight <> Value then begin
    if fLVItemHeight = 0 then
      Parent.AttachProc(WndProcLVMeasureItem);
    fLVItemHeight := Value;
  end;
end;

//[function TControl.IndexOf]
function TControl.IndexOf(const S: KOLString): Integer;
begin
  Result := SearchFor( S, -1, FALSE );
end;

//[function TControl.SearchFor]
function TControl.SearchFor(const S: KOLString; StartAfter: Integer;
  Partial: Boolean): Integer;
var Cmd: Integer;
    I: Integer;
begin
  Cmd := fCommandActions.aFindItem;
  if Partial then
    Cmd := fCommandActions.aFindPartial;
  if Cmd <> 0 then
    Result := Perform( Cmd, StartAfter, Integer( PKOLChar( S ) ) )
  else
  begin
    Result := -1;
    for I := StartAfter+1 to Count-1 do
    begin
      if Partial and ( Copy( Items[ I ], 1, Length( S ) ) = S ) or
         ( Items[ I ] = S ) then
      begin
        Result := I;
        break;
      end;
    end;
  end;
end;

//[function TControl.DefaultBtnProc]
function TControl.DefaultBtnProc(var Msg: TMsg;
  var Rslt: Integer): Boolean;
var Btn: PControl;
    F: PControl;
begin
  if Assigned( fOldOnMessage ) then
  begin
    Result := fOldOnMessage( Msg, Rslt );
    if Result then Exit;
  end;
  Result := FALSE;
  if AppletTerminated then Exit;
  F := Applet;
  if not F.fIsForm then
  begin
    F := F.fCurrentControl;
    if F = nil then Exit;
  end;
  Btn := nil;
  if ((Msg.message = WM_KEYDOWN) or (Msg.message = WM_KEYUP)) and
     ((Msg.wParam = VK_RETURN) or (Msg.wParam = VK_ESCAPE)) then
  begin
    if (Msg.wParam = VK_RETURN) and
       (F.fDefaultBtnCtl <> nil) and
       F.fDefaultBtnCtl.ToBeVisible and
       F.fDefaultBtnCtl.Enabled and
       ((F.fCurrentControl=nil) or (not F.fCurrentControl.fCancelBtn and
                                    not F.fCurrentControl.fIgnoreDefault)
                                or (F.fCurrentControl = F.fDefaultBtnCtl)
       ) then
       Btn := F.fDefaultBtnCtl
      else
    if (Msg.wParam = VK_ESCAPE) and
       (F.fCancelBtnCtl <> nil) and
       F.fCancelBtnCtl.ToBeVisible and
       F.fCancelBtnCtl.Enabled then
       Btn := F.fCancelBtnCtl
      else
    if (Msg.wParam = VK_RETURN) and
       (F.fAllBtnReturnClick or fAllBtnReturnClick) and
       (F.ActiveControl <> nil) and
       (F.ActiveControl.ToBeVisible) and
       (F.ActiveControl.IsButton) and
       (F.ActiveControl.Count = 0) then
       Btn := F.ActiveControl;
    if Btn <> nil then
    begin
      if Msg.message = WM_KEYDOWN then
      begin
        {$IFDEF CLICK_DEFAULT_CANCEL_BTN_DIRECTLY}
        //Btn.Click;
        if Assigned( Btn.OnClick ) then
          Btn.OnClick( Btn );
        {$ELSE}
        Btn.Focused := TRUE;
        {$ENDIF}
      end;
      {$IFDEF CLICK_DEFAULT_CANCEL_BTN_DIRECTLY}
      {$ELSE}
      Btn.Perform( Msg.message, DWORD( ' ' ), Msg.lParam );
      {$ENDIF}
      Msg.wParam := 0;
      Result := TRUE;
      Rslt := 0;
      Exit;
    end
  end;
  Result := FALSE;
end;

//[procedure TControl.SetDefaultBtn]
procedure TControl.SetDefaultBtn(const Index: Integer;
  const Value: Boolean);
var F, C: PControl;
begin
  if Index = 13 then
  begin
    fDefaultBtn := Value;
    {$IFDEF DEFAULT_CANCEL_BTN_EXCLUSIVE}
    fCancelBtn := FALSE;
    {$ENDIF}
  end
    else
  if Index = 27 then
  begin
    fCancelBtn := Value;
    {$IFDEF DEFAULT_CANCEL_BTN_EXCLUSIVE}
    fDefaultBtn := FALSE;
    {$ENDIF}
  end;
  if Applet = nil then Exit;
  F := ParentForm;
  if F <> nil then
  begin
    if Value then
    begin
      if @ Applet.fOnMessage <> @ TControl.DefaultBtnProc  then
        Applet.fOldOnMessage := Applet.fOnMessage; // fixed by YS
      Applet.fOnMessage := Applet.DefaultBtnProc;
    end
      else
    begin
      Applet.fOnMessage := Applet.fOldOnMessage;
      Applet.fOldOnMessage := nil;
    end;
    C := nil;
    if Value then C := @ Self;
    if Index = 13 then
    begin
      F.fDefaultBtnCtl := C;
{$ifndef wince}
      {$IFDEF NO_DEFAULT_BUTTON_BOLD}
      {$ELSE}
      if Value then
        Style := Style or BS_DEFPUSHBUTTON
      else
        Style := Style and not BS_DEFPUSHBUTTON;
      {$ENDIF}
{$endif wince}
    end
    else
    if Index = 27 then
      F.fCancelBtnCtl := C;
  end;
end;

{$IFDEF F_P}
//[function TControl.GetDefaultBtn]
function TControl.GetDefaultBtn(const Index: Integer): Boolean;
begin
  CASE Index OF
  13: Result := fDefaultBtn;
  27: Result := fCancelBtn;
  END;
end;
{$ENDIF F_P}

//[function TControl.AllBtnReturnClick]
function TControl.AllBtnReturnClick: PControl;
{$IFDEF ALL_BUTTONS_RESPOND_TO_ENTER}
begin
  // nothing: already implemented in WndProcBtnReturnClick
  Result := @ Self;
end;
{$ELSE}
var F: PControl;
begin
  SetDefaultBtn( 0, TRUE );
  F := ParentForm;
  if F <> nil then
    F.fAllBtnReturnClick := TRUE;
  Result := @ Self;
end;
{$ENDIF}

//[function WndProc_CNDrawItem]
function WndProc_CNDrawItem( Sender: PControl; var Msg: TMsg; var Rslt: Integer )
                          : Boolean;
type PDrawAction = ^TDrawAction;
     PDrawState = ^TDrawState;
var DI: PDrawItemStruct;
begin
  Result := FALSE;
  if Msg.message = CN_DRAWITEM then
  begin
    DI := Pointer( Msg.lParam );
    if Assigned( Sender.OnDrawItem ) then
    begin
      if Sender.OnDrawItem( Sender, DI.hDC, DI.rcItem, DI.itemID,
                         PDrawAction( @ DI.itemAction )^,
                         PDrawState( @ DI.itemState )^ )
        then Rslt := 1
        else Rslt := 0;
      Result := TRUE;
    end
      else Rslt := 0;
  end;
end;

//[procedure TControl.SetOnDrawItem]
procedure TControl.SetOnDrawItem(const Value: TOnDrawItem);
begin
  fOnDrawItem := Value;
  if Parent <> nil then
    Parent.AttachProc( @WndProc_DrawItem );
  AttachProc( @WndProc_CNDrawItem );
end;

//[function WndProc_MeasureItem]
function WndProc_MeasureItem( Sender: PControl; var Msg: TMsg; var Rslt: Integer )
                          : Boolean;
var MI: PMeasureItemStruct;
    Control: PControl;
    I: Integer;
begin
  Result := FALSE;
  if Msg.message = WM_MEASUREITEM then
  begin
    MI := Pointer( Msg.lParam );
    for I := 0 to Sender.ChildCount - 1 do
    begin
      Control := Sender.Children[ I ];
      if Control.Menu = MI.CtlID then
      begin
        if Assigned( Control.OnMeasureItem ) then
        begin
          MI.itemHeight := Control.OnMeasureItem( Control, MI.itemID );
          if MI.itemHeight > 0 then
          begin
            Rslt := 1;
            Result := TRUE;
          end;
        end;
        break;
      end;
    end;
  end;
end;

//[procedure TControl.SetOnMeasureItem]
procedure TControl.SetOnMeasureItem(const Value: TOnMeasureItem);
begin
  fOnMeasureItem := Value;
  if Parent <> nil then
    Parent.AttachProc( @WndProc_MeasureItem );
end;

//[function TControl.GetItemData]
function TControl.GetItemData(Idx: Integer): DWORD;
begin
  Result := 0;
  if fCommandActions.aGetItemData <> 0 then
    Result := Perform( fCommandActions.aGetItemData, Idx, 0 );
end;

//[procedure TControl.SetItemData]
procedure TControl.SetItemData(Idx: Integer; const Value: DWORD);
begin
  if fCommandActions.aSetItemData <> 0 then
    Perform( fCommandActions.aSetItemData, Idx, Value );
end;

//[function TControl.GetLVCurItem]
function TControl.GetLVCurItem: Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, -1, LVNI_SELECTED );
end;

//[procedure TControl.SetLVCurItem]
procedure TControl.SetLVCurItem(const Value: Integer);
begin
  if (lvoMultiselect in LVOptions) or (Value <> LVCurItem ) then
    LVItemState[ -1 ] := [ ];
  if Value >= 0 then
    LVItemState[ Value ] := [ lvisSelect, lvisFocus ];
end;

//[function TControl.LVNextItem]
function TControl.LVNextItem(IdxPrev: Integer; Attrs: DWORD): Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, IdxPrev, Attrs );
end;

//[function TControl.LVNextSelected]
function TControl.LVNextSelected(IdxPrev: Integer): Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, IdxPrev, LVNI_SELECTED );
end;

//[function TControl.GetLVFocusItem]
function TControl.GetLVFocusItem: Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, -1, LVNI_FOCUSED );
end;

//[procedure TControl.Close]
procedure TControl.Close;
begin
  PostMessage( Handle, WM_CLOSE, 0, 0 );
end;

//[function WndProcMinimize]
function WndProcMinimize( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var Wnd: PControl;
begin
  Result := FALSE;
  if (Msg.message = WM_SYSCOMMAND) and ((Msg.wParam and $FFF0) = SC_MINIMIZE)then
  begin
    if Applet <> nil then
    begin
      Wnd := Applet.FMinimizeWnd;
      if Wnd <> nil then
        SetWindowPos( Applet.Handle, 0, Wnd.Left, Wnd.Top, Wnd.Width, 0,
                      SWP_NOZORDER or SWP_NOREDRAW);
    end;
  end;
end;

function WndProcRestore( Self_: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
begin
  Result := FALSE;
  CASE Msg.message OF
     WM_SHOWWINDOW:
               begin
                  case Msg.lParam of
                    SW_PARENTCLOSING:
                       begin
{$ifdef win32}
                          if IsIconic( Self_.fHandle ) then
                             Self_.fShowAction := SW_SHOWMINNOACTIVE
                          else
                          if IsZoomed( Self_.fHandle ) then
                             Self_.fShowAction := SW_SHOWMAXIMIZED
                          else
                             Self_.fShowAction := SW_SHOWNOACTIVATE;
{$endif win32}
                       end;
                    SW_PARENTOPENING:
                       begin
                          if Self_.fShowAction <> 0 then
                          begin
                             ShowWindow( Self_.fHandle, Self_.fShowAction );
                             Self_.fShowAction := 0;
                          end;
                          Rslt := 0;
                       end;
                  end;
               end;
  END;
end;

//[procedure TControl.MinimizeNormalAnimated]
procedure TControl.MinimizeNormalAnimated;
var App: PControl;
begin
  App := Applet;
  if App = nil then
    App := @Self;
  App.FMinimizeWnd := @Self;
  App.AttachProc( @WndProcMinimize );
  AttachProc( @WndProcRestore );
end;

//[procedure TCotrol.RestoreNormalMaximized]
procedure TControl.RestoreNormalMaximized;
begin
  AttachProc( @WndProcRestore );
end;

{$ifndef wince}
//[function WndProcDropFiles]
function WndProcDropFiles( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var hDrop: THandle;
    Pt: TPoint;
    FList: KOLString;
    I, N: Integer;
    Buf: array[ 0..MAX_PATH ] of KOLChar;
begin
  if Msg.message = WM_DROPFILES then
  if Assigned( Sender.FOnDropFiles ) then
  begin
    hDrop := Msg.wParam;
    DragQueryPoint( hDrop, Pt );
    N := DragQueryFile( hDrop, $FFFFffff, nil, 0 );
    FList := '';
    for I := 0 to N-1 do
    begin
      if FList <> '' then
        FList := FList + #13;
      DragQueryFile( hDrop, I, Buf, Sizeof( Buf ) );
      FList := FList + Buf;
    end;
    DragFinish( hDrop );
    Sender.FOnDropFiles( Sender, FList, Pt );
    Rslt := 0;
    Result := TRUE;
    Exit;
  end;
  Result := FALSE;
end;
{$endif wince}
//[procedure TControl.SetOnDropFiles]
procedure TControl.SetOnDropFiles(const Value: TOnDropFiles);
begin
  FOnDropFiles := Value;
{$ifndef wince}
  AttachProc( @WndProcDropFiles );
  DragAcceptFiles( GetWindowHandle, Assigned( Value ) );
{$endif wince}
end;

//[function WndProcShowHide]
function WndProcShowHide( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var IsVisible: Boolean;
begin
  if Msg.message = WM_SHOWWINDOW then
  if Msg.hwnd = Sender.Handle then
  begin
    IsVisible := IsWindowVisible( Sender.Handle );
    if LongBool( Msg.wParam ) then
    begin
      Sender.fVisible := TRUE;
      if not IsVisible then
      if Assigned( Sender.FOnShow ) then
        Sender.FOnShow( Sender );
    end
      else
    begin
      Sender.fVisible := FALSE;
      if IsVisible then
      if Assigned( Sender.FOnHide ) then
        Sender.FOnHide( Sender );
    end;
  end;
  Result := FALSE;
end;

//[procedure TControl.SetOnHide]
procedure TControl.SetOnHide(const Value: TOnEvent);
begin
  FOnHide := Value;
  AttachProc( WndProcShowHide );
end;

//[procedure TControl.SetOnShow]
procedure TControl.SetOnShow(const Value: TOnEvent);
begin
  FOnShow := Value;
  AttachProc( WndProcShowHide );
end;

//[function TControl.BringToFront]
function TControl.BringToFront: PControl;
begin
  SetWindowPos( GetWindowHandle, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE or
                SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_SHOWWINDOW );
  Result := @Self;
end;

//[function TControl.SendToBack]
function TControl.SendToBack: PControl;
begin
  SetWindowPos( GetWindowHandle, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE or
                SWP_NOACTIVATE or SWP_NOOWNERZORDER );
  Result := @Self;
end;

//[procedure TControl.DragStart]
procedure TControl.DragStart;
begin
  PostMessage( GetWindowHandle, WM_SYSCOMMAND, $F012, 0 );
end;

//[function WndProcDragWindow]
function WndProcDragWindow( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var P: TPoint;
begin
  if Msg.message = WM_MOUSEMOVE then
  begin
    if Sender.FDragging then
    begin
      GetCursorPos( P );
      P.x := P.x - Sender.fMouseStartPos.x + Sender.fDragStartPos.x;
      P.y := P.y - Sender.fMouseStartPos.y + Sender.fDragStartPos.y;
      Sender.Position := P;
    end;
  end;
  Result := FALSE;
end;

//[procedure TControl.DragStartEx]
procedure TControl.DragStartEx;
var StartBounds: TRect;
begin
  {$IFNDEF SMALLEST_CODE}
  if fDragging then Exit;
  {$ENDIF}
  GetCursorPos( fMouseStartPos );
  StartBounds := BoundsRect;
  fDragStartPos.x := StartBounds.Left;
  fDragStartPos.y := StartBounds.Top;
  SetCapture( GetWindowHandle );
  fDragging := TRUE;
  AttachProc( WndProcDragWindow );
end;

//[procedure TControl.DragStopEx]
procedure TControl.DragStopEx;
begin
  if FDragging then
  begin
    ReleaseCapture;
    FDragging := FALSE;
  end;
end;

//[function CallDragCallBack]
function CallDragCallBack( Sender: PControl; var Stop: Boolean ): Boolean;
var P: TPoint;
    Shape, ShapeWas: Integer;
begin
  Sender.AttachProc( WndProcSetCursor );
  GetCursorPos( P );
  Shape := LoadCursor( 0, IDC_HAND );
  ShapeWas := Shape;
  Result := Sender.fDragCallback( Sender, P.x, P.y, Shape, Stop );
  if not Stop then
  begin
    if not Result then
      if Shape = ShapeWas then
        Shape := LoadCursor( 0, IDC_NO );
    ScreenCursor := Shape;
  end
    else
  begin
    ScreenCursor := 0;
    Shape := Sender.fCursor;
  end;
  Windows.SetCursor( Shape );
end;

//[function WndProcDrag]
function WndProcDrag( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var Stop: Boolean;
begin
  if Sender.fDragging then
  begin
    Stop := FALSE;
    case Msg.message of
    WM_MOUSEMOVE:
      CallDragCallBack( Sender, Stop );
    WM_LBUTTONUP, WM_RBUTTONUP:
      begin
        Stop := TRUE;
        CallDragCallBack( Sender, Stop );
      end;
    else
      begin
        Result := FALSE;
        Exit;
      end;
    end;
    if Stop then
    begin
      ReleaseCapture;
      Sender.fDragging := FALSE;
    end
      else
    begin
      Result := TRUE;
      exit;
    end;
  end;
  Result := FALSE;
end;

//[procedure TControl.DragItem]
procedure TControl.DragItem(OnDrag: TOnDrag);
begin
  fDragCallback := OnDrag;
  fDragging := TRUE;
  SetCapture( GetWindowHandle );
  AttachProc( WndProcDrag );
end;

{-}
{$IFDEF USE_CONSTRUCTORS} //****************************************************//
                                                                                //
//[constructor TControl.CreateWindowed]
constructor TControl.CreateWindowed(AParent: PControl; AClassName: PKOLChar;       //
  ACtl3D: Boolean);                                                             //
begin                                                                           //
  CreateParented( AParent );                                                    //
  fOnDynHandlers := WndProcDummy;                                               //
  fWndProcKeybd := WndProcDummy;                                                //
  fWndProcResizeFlicks := WndProcDummy;                                         //
  fCommandActions.aClear := ClearText;                                          //
  //fWindowed := True; // is set in TControl.Init
  fControlClassName := AClassName;                                              //
                                                                                //
  fControlClick := DummyObjProc;                                                //
                                                                                //
  fColor := clBtnFace;                                                          //
  fTextColor := clWindowText;                                                   //
  fMargin := 2;                                                                 //
  fCtl3D := True;                                                               //
  fCtl3Dchild := True;                                                          //
  if AParent <> nil then                                                        //
  begin                                                                         //
     fWndProcResizeFlicks := AParent.fWndProcResizeFlicks;                      //
     fGotoControl := AParent.fGotoControl;                                      //
     fDoubleBuffered := AParent.fDoubleBuffered;                                //
     fTransparent := AParent.fTransparent;                                      //
     fCtl3Dchild := AParent.fCtl3Dchild;                                        //
     if AParent.fCtl3Dchild then                                                //
       fCtl3D := ACtl3D                                                         //
     else                                                                       //
       fCtl3D := False;                                                         //
     fMargin := AParent.fMargin;                                                //
     with fBoundsRect do                                                        //
     begin                                                                      //
       Left := AParent.fMargin + AParent.fClientLeft;                           //
       Top  := AParent.fMargin + AParent.fClientTop;                            //
       Right := Left + 64;                                                      //
       Bottom := Top + 64;                                                      //
     end;                                                                       //
     fTextColor := AParent.fTextColor;                                          //
     fFont := fFont.Assign( AParent.fFont );                                    //
     if fFont <> nil then                                                       //
     begin                                                                      //
       fFont.fOnChange := FontChanged;                                          //
       FontChanged( fFont );                                                    //
     end;                                                                       //
     fColor := AParent.fColor;                                                  //
     fBrush := fBrush.Assign( AParent.fBrush );                                 //
     if fBrush <> nil then                                                      //
     begin                                                                      //
       fBrush.fOnChange := BrushChanged;                                        //
       BrushChanged( fBrush );                                                  //
     end;                                                                       //
  end;                                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateApplet]
constructor TControl.CreateApplet(const ACaption: String);                      //
begin                                                                           //
  AppButtonUsed := True;                                                        //
  CreateWindowed( nil, 'App', TRUE );                                           //
  FIsApplet := TRUE;                                                            //
  fStyle := WS_VISIBLE or WS_SYSMENU or WS_POPUP or WS_MINIMIZEBOX              //
    or WS_CAPTION;                                                              //
  fExStyle := WS_EX_APPWINDOW;                                                  //
  FCreateWndExt := CreateAppButton;                                             //
  AttachProc( WndProcApp );                                                     //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateForm]
constructor TControl.CreateForm(AParent: PControl; const ACaption: String);     //
begin                                                                           //
  CreateWindowed( AParent, 'Form', TRUE );                                      //
  AttachProc( WndProcForm );                                                    //
  AttachProc( WndProcDoEraseBkgnd );                                            //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateControl]
constructor TControl.CreateControl(AParent: PControl; AClassName: PChar;        //
  AStyle: DWORD; ACtl3D: Boolean; Actions: PCommandActions);                    //
var Form: PControl;                                                             //
begin                                                                           //
  CreateWindowed( AParent, AClassName, ACtl3D );                                //
  if Actions <> nil then                                                        //
    fCommandActions := Actions^;                                                //
  fIsControl := True;                                                           //
  fStyle := AStyle or WS_CLIPSIBLINGS or WS_CLIPCHILDREN;                       //
  fVisible := (Style and WS_VISIBLE) <> 0;                                      //
  fTabstop := (Style and WS_TABSTOP) <> 0;                                      //
  if (AParent <> nil) then                                                      //
  begin                                                                         //
    Inc( AParent.ParentForm.fTabOrder );                                        //
    fTabOrder := AParent.ParentForm.fTabOrder;                                  //
  end;                                                                          //
  fLookTabKeys := [ tkTab, tkLeftRight, tkUpDown, tkPageUpPageDn ];             //
  if fCtl3D then                                                                //
  begin                                                                         //
    fStyle := fStyle and not WS_BORDER;                                         //
    fExStyle := fExStyle or WS_EX_CLIENTEDGE;                                   //
  end;                                                                          //
  if (Style and WS_TABSTOP) <> 0 then                                           //
  begin                                                                         //
    Form := ParentForm;                                                         //
    if Form <> nil then                                                         //
    if Form.FCurrentControl = nil then                                          //
       Form.FCurrentControl := @Self;                                           //
  end;                                                                          //
  //fCreateParamsExt := CreateParams2;                                          //
  fMenu := CtlIdCount;                                                          //
  Inc( CtlIdCount );                                                            //
  AttachProc( WndProcCtrl );                                                    //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateButton]
constructor TControl.CreateButton(AParent: PControl;                            //
  const ACaption: String);                                                      //
begin                                                                           //
  CreateControl( AParent, 'BUTTON',                                             //
            WS_VISIBLE or WS_CHILD or                                           //
            BS_PUSHLIKE or WS_TABSTOP, False, @ButtonActions );                 //
  with fBoundsRect do                                                           //
    Bottom := Top + 22;                                                         //
  fTextAlign := taCenter;                                                       //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateBitBtn]
constructor TControl.CreateBitBtn(AParent: PControl;                            //
  const ACaption: String; AOptions: TBitBtnOptions; ALayout: TGlyphLayout;      //
  AGlyphBitmap: HBitmap; AGlyphCount: Integer);                                 //
var                                                                             //
    B: TBitmapInfo;                                                             //
    W, H: Integer;                                                              //
begin                                                                           //
  CreateControl( AParent, 'BUTTON', WS_VISIBLE or WS_CHILD or                   //
            WS_TABSTOP or BS_OWNERDRAW, False, @ButtonActions );                //
  fBitBtnOptions := AOptions;                                                   //
  fGlyphLayout := ALayout;                                                      //
  fGlyphBitmap := AGlyphBitmap;                                                 //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Bottom := Top + 22;                                                         //
    W := 0; H := 0;                                                             //
    if AGlyphBitmap <> 0 then                                                   //
    begin                                                                       //
      if bboImageList in AOptions then                                          //
        ImageList_GetIconSize( AGlyphBitmap, W, H )                             //
      else                                                                      //
        begin                                                                   //
          if GetObject( AGlyphBitmap, Sizeof(B), @B ) > 0 then                  //
          begin                                                                 //
            W := B.bmiHeader.biWidth;                                           //
            H := B.bmiHeader.biHeight;                                          //
            if AGlyphCount = 0 then                                             //
              AGlyphCount := W div H;                                           //
            if AGlyphCount > 1 then                                             //
              W := W div AGlyphCount;                                           //
          end;                                                                  //
        end;                                                                    //
      if W > 0 then                                                             //
        if ACaption = '' then                                                   //
          Right := Left + W                                                     //
        else                                                                    //
          Right := Right + W;                                                   //
      if H > 0 then                                                             //
        Bottom := Top + H;                                                      //
      if not ( bboNoBorder in AOptions ) then                                   //
      begin                                                                     //
        if W > 0 then                                                           //
          Inc( Right, 2 );                                                      //
        if H > 0 then                                                           //
          Inc( Bottom, 2 );                                                     //
      end;                                                                      //
    end;                                                                        //
    fGlyphWidth := W;                                                           //
    fGlyphHeight := H;                                                          //
  end;                                                                          //
  fGlyphCount := AGlyphCount;                                                   //
  if AParent <> nil then                                                        //
    AParent.AttachProc( WndProc_DrawItem );                                     //
  AttachProc( WndProcBitBtn );                                                  //
  fTextAlign := taCenter;                                                       //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateLabel]
constructor TControl.CreateLabel(AParent: PControl;                             //
  const ACaption: String);                                                      //
begin                                                                           //
  CreateControl( AParent, 'STATIC', WS_VISIBLE or WS_CHILD or                   //
                         SS_LEFTNOWORDWRAP or SS_NOPREFIX or SS_NOTIFY,         //
                         False, @LabelActions );                                //
  fIsStaticControl := 1;                                                     //
  fSizeRedraw := True;                                                          //
  fBoundsRect.Bottom := fBoundsRect.Top + 22;                                   //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateWordWrapLabel]
constructor TControl.CreateWordWrapLabel(AParent: PControl;                     //
  const ACaption: String);                                                      //
begin                                                                           //
  CreateLabel( AParent, ACaption );                                             //
  fBoundsRect.Bottom := fBoundsRect.Top + 44;                                   //
  fStyle := fStyle and not SS_LEFTNOWORDWRAP;                                   //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateLabelEffect]
constructor TControl.CreateLabelEffect(AParent: PControl; ACaption: String;     //
  AShadowDeep: Integer);                                                        //
begin                                                                           //
  CreateLabel( AParent, ACaption );                                             //
  fIsStaticControl := 0;                                                        //
  AttachProc( WndProcLabelEffect );                                             //
  fTextAlign := taCenter;                                                       //
  fTextColor := clBtnShadow;                                                    //
  fShadowDeep := AShadowDeep;                                                   //
  fIgnoreWndCaption := True;                                                    //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Bottom := Top + 40;                                                         //
  end;                                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreatePaintBox]
constructor TControl.CreatePaintBox(AParent: PControl);                         //
begin                                                                           //
  CreateLabel( AParent, '' );                                                   //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 40;                                                         //
    Bottom := Top + 40;                                                         //
  end;                                                                          //
end;                                                                            //
                                                                                //
{$IFDEF ASM_VERSION}                                                            //
//[constructor TControl.CreateGradientPanel]
constructor TControl.CreateGradientPanel(AParent: PControl; AColor1,            //
  AColor2: TColor);                                                             //
asm     //cmd    //opd                                                          //
        XOR      EDX, EDX                                                       //
        PUSH     EDX                                                            //
        CALL     CreateLabel                                                    //
        MOV      ECX, AColor1                                                   //
        MOV      [EAX].fColor1, ECX                                             //
        MOV      ECX, AColor2                                                   //
        MOV      [EAX].fColor2, ECX                                             //
        MOV      EDX, [EAX].fBoundsRect.Left                                    //
        ADD      EDX, 40                                                        //
        MOV      [EAX].fBoundsRect.Right, EDX                                   //
        MOV      EDX, [EAX].fBoundsRect.Top                                     //
        ADD      EDX, 40                                                        //
        MOV      [EAX].fBoundsRect.Bottom, EDX                                  //
        PUSH     EAX                                                            //
        MOV      EDX, offset[ WndProcGradient ]                                 //
        CALL     AttachProc                                                     //
        POP      EAX                                                            //
end;                                                                            //
{$ELSE ASM_VERSION} //Pascal                                                                //
constructor TControl.CreateGradientPanel(AParent: PControl; AColor1,            //
  AColor2: TColor);                                                             //
begin                                                                           //
  CreateLabel( AParent, '' );                                                   //
  AttachProc( WndProcGradient );                                                //
  fColor2 := AColor2;                                                           //
  fColor1 := AColor1;                                                           //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 40;                                                         //
    Bottom := Top + 40;                                                         //
  end;                                                                          //
end;                                                                            //
{$ENDIF ASM_VERSION}                                                                        //
                                                                                //
//[constructor TControl.CreateGradientPanelEx]
constructor TControl.CreateGradientPanelEx(AParent: PControl; AColor1,          //
  AColor2: TColor; AStyle: TGradientStyle; ALayout: TGradientLayout);           //
begin                                                                           //
  CreateLabel( AParent, '' );                                                   //
  AttachProc( WndProcGradientEx );                                              //
  fColor2 := AColor2;                                                           //
  fColor1 := AColor1;                                                           //
  fGradientStyle := AStyle;                                                     //
  fGradientLayout := ALayout;                                                   //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 40;                                                         //
    Bottom := Top + 40;                                                         //
  end;                                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateGroupbox]
constructor TControl.CreateGroupbox(AParent: PControl;                          //
  const ACaption: String);                                                      //
begin                                                                           //
  CreateButton( AParent, ACaption );                                            //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 100;                                                        //
    Bottom := Top + 100;                                                        //
  end;                                                                          //
  fStyle := WS_VISIBLE or WS_CHILD or BS_GROUPBOX or WS_TABSTOP;                //
  fClientTop := 22;                                                             //
  fClientLeft := 2;                                                             //
  fClientBottom := 2;                                                           //
  fClientRight := 2;                                                            //
  fTabstop := False;                                                            //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateCheckbox]
constructor TControl.CreateCheckbox(AParent: PControl;                          //
  const ACaption: String);                                                      //
begin                                                                           //
  CreateButton( AParent, ACaption );                                            //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 72;                                                         //
  end;                                                                          //
  fStyle := WS_VISIBLE or WS_CHILD or                                           //
            BS_AUTOCHECKBOX or WS_TABSTOP;                                      //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateRadiobox]
constructor TControl.CreateRadiobox(AParent: PControl;                          //
  const ACaption: String);                                                      //
begin                                                                           //
  CreateCheckbox( AParent, ACaption );                                          //
  fStyle := WS_VISIBLE or WS_CHILD or                                           //
            BS_RADIOBUTTON or WS_TABSTOP or WS_GROUP;                           //
  fControlClick := ClickRadio;                                                  //
  if AParent <> nil then                                                        //
  begin                                                                         //
    AParent.fRadioLast := fMenu;                                                //
    if AParent.fRadio1st = 0 then                                               //
    begin                                                                       //
       AParent.fRadio1st := fMenu;                                              //
       SetRadioChecked;                                                         //
    end;                                                                        //
  end;                                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateEditbox]
constructor TControl.CreateEditbox(AParent: PControl;                           //
  AOptions: TEditOptions);                                                      //
var Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, EditFlags );                                   //
  if not(eoMultiline in AOptions) then                                          //
     Flags := Flags and not(WS_HSCROLL or WS_VSCROLL);                          //
  CreateControl( AParent, 'EDIT', WS_VISIBLE or WS_CHILD or WS_TABSTOP          //
                         or WS_BORDER or Flags, True, @EditActions );           //
//YS  fCursor := LoadCursor( 0, IDC_IBEAM );                                      // //YS
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 100;                                                        //
    Bottom := Top + 22;                                                         //
    if eoMultiline in AOptions then                                             //
    begin                                                                       //
       Right := Right + 100;                                                    //
       Bottom := Top + 200;                                                     //
    end;                                                                        //
  end;                                                                          //
  fColor := clWindow;                                                           //
  fLookTabKeys := [ tkTab, tkUpDown, tkPageUpPageDn ];                          //
  if eoMultiline in AOptions then                                               //
     fLookTabKeys := [ tkTab ];                                                 //
  if eoWantTab in AOptions then                                                 //
     fLookTabKeys := fLookTabKeys - [ tkTab ];                                  //
end;                                                                            //
                                                                                //
//[constructor TControl.CreatePanel]
constructor TControl.CreatePanel(AParent: PControl; AStyle: TEdgeStyle);        //
const Edgestyles: array[ TEdgeStyle ] of DWORD = ( WS_DLGFRAME, SS_SUNKEN, 0 ); //
begin                                                                           //
  CreateControl( AParent, 'STATIC', WS_VISIBLE or WS_CHILD or                   //
                         SS_LEFTNOWORDWRAP or SS_NOPREFIX or SS_NOTIFY, False,  //
                         @LabelActions );                                       //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 100;                                                        //
    Bottom := Top + 100;                                                        //
  end;                                                                          //
  Style := Style or Edgestyles[ AStyle ];                                       //
  ExStyle := ExStyle or WS_EX_CONTROLPARENT;                                    //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateSplitter]
constructor TControl.CreateSplitter(AParent: PControl; AMinSizePrev,            //
  AMinSizeNext: Integer; EdgeStyle: TEdgeStyle);                                //
var PrevCtrl: PControl;                                                         //
    Sz0: Integer;                                                               //
begin                                                                           //
  CreatePanel( AParent, EdgeStyle );                                            //
  fSplitMinSize1 := AMinSizePrev;                                               //
  fSplitMinSize2 := AMinSizeNext;                                               //
  Sz0 := 4;                                                                     //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + Sz0;                                                        //
    Bottom := Top + Sz0;                                                        //
  end;                                                                          //
  if AParent <> nil then                                                        //
  begin                                                                         //
    if AParent.fChildren.fCount > 1 then                                        //
    begin                                                                       //
      PrevCtrl := AParent.fChildren.fItems[ AParent.fChildren.fCount - 2 ];     //
      case PrevCtrl.FAlign of                                                   //
      caLeft, caRight:                                                          //
        begin                                                                   //
          fCursor := LoadCursor( 0, IDC_SIZEWE );                               //
        end;                                                                    //
      caTop, caBottom:                                                          //
        begin                                                                   //
          fCursor := LoadCursor( 0, IDC_SIZENS );                               //
        end;                                                                    //
      end;                                                                      //
      Align := PrevCtrl.FAlign;                                                 //
    end;                                                                        //
  end;                                                                          //
  AttachProc( WndProcSplitter );                                                //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateListbox]
constructor TControl.CreateListbox(AParent: PControl;                           //
  AOptions: TListOptions);                                                      //
var Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, ListFlags );                                   //
  CreateControl( AParent, 'LISTBOX', WS_VISIBLE or WS_CHILD or WS_TABSTOP       //
                 or WS_BORDER or WS_VSCROLL                                     //
                 or LBS_NOTIFY or Flags, True, @ListActions );                  //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Right + 100;                                                       //
    Bottom := Top + 200;                                                        //
  end;                                                                          //
  fColor := clWindow;                                                           //
  fLookTabKeys := [ tkTab, tkLeftRight ];                                       //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateCombobox]
constructor TControl.CreateCombobox(AParent: PControl;                          //
  AOptions: TComboOptions);                                                     //
var Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, ComboFlags );                                  //
  CreateControl( AParent, 'COMBOBOX',                                           //
                 WS_VISIBLE or WS_CHILD or WS_VSCROLL or                        //
                 CBS_DROPDOWN or CBS_HASSTRINGS or WS_TABSTOP or Flags,         //
                 True, @ComboActions );                                         //
  fCreateWndExt := CreateComboboxWnd;                                           //
  fDropDownProc := ComboboxDropDown;                                            //
  fClsStyle := fClsStyle or CS_DBLCLKS;                                         //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 100;                                                        //
    Bottom := Top + 22;                                                         //
  end;                                                                          //
  fColor := clWindow;                                                           //
  fLookTabKeys := [ tkTab ];                                                    //
  if coReadOnly in AOptions then                                                //
    fLookTabKeys := [ tkTab, tkLeftRight ];                                     //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateCommonControl]
constructor TControl.CreateCommonControl(AParent: PControl;                     //
  AClassName: PChar; AStyle: DWORD; ACtl3D: Boolean;                            //
  Actions: PCommandActions);                                                    //
begin                                                                           //
  {*************} DoInitCommonControls( ICC_WIN95_CLASSES );                      //
  CreateControl( AParent, AClassName, AStyle, ACtl3D, Actions );                //
  fIsCommonControl := True;                                                     //
  if AParent <> nil then                                                        //
  begin                                                                         //
    AttachProc( WndProcParentResize );                                          //
    AParent.AttachProc( WndProcResize );                                        //
    AttachProc( WndProcCommonNotify );                                          //
    AParent.AttachProc( WndProcNotify );                                        //
  end;                                                                          //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateRichEdit1]
constructor TControl.CreateRichEdit1(AParent: PControl;                         //
  AOptions: TEditOptions);                                                      //
var Flags, I: Integer;                                                          //
begin                                                                           //
  if FRichEditModule = 0 then                                                   //
  begin                                                                         //
    for I := 0 to High( RichEditLibnames ) do                                                          //
    begin                                                                       //
      FRichEditModule := LoadLibrary( RichEditLibnames[ I ] );                  //
      if FRichEditModule > HINSTANCE_ERROR then break;                          //
      RichEditClass := RichEditClasses[ I ];                                              //
    end;                                                                        //
    if FRichEditModule <= HINSTANCE_ERROR then                                  //
      FRichEditModule := 0;                                                     //
  end;                                                                          //
  Flags := MakeFlags( @AOptions, RichEditFlags );                               //
  CreateCommonControl( AParent, RichEditClass, WS_VISIBLE or WS_CHILD           //
                       or WS_TABSTOP or WS_BORDER or ES_MULTILINE or Flags,     //
                       True, @RichEditActions );                                //
                                                                                //
  AttachProc( WndProcRichEditNotify );                                          //
  fDoubleBuffered := False;                                                     //
  fCannotDoubleBuf := True;                                                     //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Right + 100;                                                       //
    Bottom := Top + 200;                                                        //
  end;                                                                          //
  fColor := clWindow;                                                           //
  fLookTabKeys := [ tkTab ];                                                    //
  if eoWantTab in AOptions then                                                 //
     fLookTabKeys := [ ];                                                       //
  Perform( EM_SETEVENTMASK, 0,                                                  //
    ENM_CHANGE or ENM_SELCHANGE or ENM_REQUESTRESIZE or                         //
    ENM_PROTECTED or $04000000 {ENM_LINK} );                                    //
  Perform( EM_SETBKGNDCOLOR, 0, Color2RGB(fColor));                             //
end;                                                                            //
                                                                                //
                                                                                //
//[constructor TControl.CreateRichEdit]
constructor TControl.CreateRichEdit(AParent: PControl;                          //
  AOptions: TEditOptions);                                                      //
var OldRichEditClass, OldRichEditLib: PChar;                                    //
begin                                                                           //
  if OleInit then                                                               //
  begin                                                                         //
    OldRichEditClass := RichEditClass;                                          //
    OldRichEditLib := RichEditLib;                                              //
    CreateRichEdit1( AParent, AOptions );                                       //
    fCharFmtDeltaSz := 24;                                                      //
    fParaFmtDeltaSz := sizeof( TParaFormat2 ) - sizeof( RichEdit.TParaFormat ); //
    RichEditClass := OldRichEditClass;                                          //
    RichEditLib := OldRichEditLib;                                              //
  end                                                                           //
     else                                                                       //
    CreateRichEdit1( AParent, AOptions );                                       //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateProgressbar]
constructor TControl.CreateProgressbar(AParent: PControl);                      //
const ProgressBarFlags: array[ TProgressbarOption ] of Integer =                //
      (PBS_VERTICAL, PBS_SMOOTH );                                              //
begin                                                                           //
  CreateCommonControl( AParent, PROGRESS_CLASS,                                 //
            WS_CHILD or WS_VISIBLE, True, nil );                                //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 300;                                                        //
    Bottom := Top + 20;                                                         //
  end;                                                                          //
  fMenu := 0;                                                                   //
  fTextColor := clHighlight;                                                    //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateProgressbarEx]
constructor TControl.CreateProgressbarEx(AParent: PControl;                     //
  AOptions: TProgressbarOptions);                                               //
const ProgressBarFlags: array[ TProgressbarOption ] of Integer =                //
      (PBS_VERTICAL, PBS_SMOOTH );                                              //
begin                                                                           //
  CreateProgressbar( AParent );                                                 //
  fStyle := fStyle or DWORD( MakeFlags( @AOptions, ProgressBarFlags ) );        //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateListView]
constructor TControl.CreateListView(AParent: PControl;                          //
  AStyle: TListViewStyle; AOptions: TListViewOptions; AImageListSmall,          //
  AImageListNormal, AImageListState: PImageList);                               //
begin                                                                           //
  CreateCommonControl( AParent, WC_LISTVIEW, ListViewStyles[ AStyle ] or        //
                 LVS_SHAREIMAGELISTS or WS_CHILD or WS_VISIBLE or WS_TABSTOP,   //
                 True, @ListViewActions );                                      //
  fLVOptions := AOptions;                                                       //
  fLVStyle := AStyle;                                                           //
  fCreateWndExt := ApplyImageLists2ListView;                                    //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 200;                                                        //
    Bottom := Top + 150;                                                        //
  end;                                                                          //
  ImageListSmall := AImageListSmall;                                            //
  ImageListNormal := AImageListNormal;                                          //
  ImageListState := AImageListState;                                            //
  fLVTextBkColor := clWindow;                                                   //
  fLookTabKeys := [ tkTab ];                                                    //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateTreeView]
constructor TControl.CreateTreeView(AParent: PControl;                          //
  AOptions: TTreeViewOptions; AImgListNormal, AImgListState: PImageList);       //
var Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, TreeViewFlags );                               //
  CreateCommonControl( AParent, WC_TREEVIEW, Flags or WS_VISIBLE or             //
            WS_CHILD or WS_TABSTOP, True, @TreeViewActions );                   //
  fCreateWndExt := ApplyImageLists2Control;                                     //
  fColor := clWindow;                                                           //
  AttachProc( WndProcTreeView );                                                //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 150;                                                        //
    Bottom := Top + 200;                                                        //
  end;                                                                          //
  ImageListNormal := AImgListNormal;                                            //
  ImageListState := AImgListState;                                              //
  fLookTabKeys := [ tkTab ];                                                    //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateTabControl]
constructor TControl.CreateTabControl(AParent: PControl; ATabs: array of String;//
         AOptions: TTabControlOptions;                                          //
         AImgList: PImageList; AImgList1stIdx: Integer);                        //
var I, II : Integer;                                                            //
    Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, TabControlFlags );                             //
  if tcoFocusTabs in AOptions then                                              //
    Flags := Flags or (WS_TABSTOP or TCS_FOCUSONBUTTONDOWN);                    //
  CreateCommonControl( AParent, WC_TABCONTROL,                                  //
            Flags or (WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or         //
            WS_VISIBLE), True, @TabControlActions );                            //
  if not( tcoBorder in AOptions ) then                                           //
    fExStyle := fExStyle and not WS_EX_CLIENTEDGE;                              //
  AttachProc( WndProcTabControl );                                              //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 100;                                                        //
    Bottom := Top + 100;                                                        //
  end;                                                                          //
  if AImgList <> nil then                                                       //
    Perform( TCM_SETIMAGELIST, 0, AImgList.Handle );                            //
  II := AImgList1stIdx;                                                         //
  for I := 0 to High( ATabs ) do                                                //
  begin                                                                         //
    TC_Insert( I, ATabs[ I ], II );                                             //
    Inc( II );                                                                  //
  end;                                                                          //
  fLookTabKeys := [ tkTab ];                                                    //
end;                                                                            //
                                                                                //
//[constructor TControl.CreateToolbar]
constructor TControl.CreateToolbar(AParent: PControl;                           //
  AAlign: TControlAlign; AOptions: TToolbarOptions; ABitmap: HBitmap;           //
  AButtons: array of PChar; ABtnImgIdxArray: array of Integer);                 //
var Flags: DWORD;                                                               //
begin                                                                           //
  if not( tboTextBottom in AOptions ) then                                      //
    AOptions := AOptions + [ tboTextRight ];                                    //
  if tboTextRight in AOptions then                                              //
    AOptions := AOptions - [ tboTextBottom ];                                   //
  Flags := MakeFlags( @AOptions, ToolbarOptions );                              //
  CreateCommonControl( AParent, TOOLBARCLASSNAME, ToolbarAligns[ Align ] or     //
                       WS_CHILD or WS_VISIBLE {or WS_TABSTOP}                   //
                       or TBSTYLE_TOOLTIPS or Flags,                            //
                       (not (Align in [caNone])) and                            //
                        not (tboNoDivider in AOptions),  nil );                 //
  fCommandActions.aClear := ClearToolbar;                                       //
  fCommandActions.aGetCount := TB_BUTTONCOUNT;                                  //
  with fBoundsRect do                                                           //
  begin                                                                         //
    if AAlign in [ caNone ] then                                                //
    begin                                                                       //
      Bottom := Top + 26;                                                       //
      Right := Left + 1000;                                                     //
    end                                                                         //
       else                                                                     //
    begin                                                                       //
      Left := 0; Right := 0;                                                    //
      Top := 0; Bottom := 0;                                                    //
    end;                                                                        //
  end;                                                                          //
  Perform(TB_SETEXTENDEDSTYLE, 0, Perform(TB_GETEXTENDEDSTYLE, 0, 0) or         //
      TBSTYLE_EX_DRAWDDARROWS);                                                 //
                                                                                //
  AttachProc( WndProcToolbarCtrl );                                             //
  Perform( TB_BUTTONSTRUCTSIZE, Sizeof( TTBButton ), 0 );                       //
  Perform( TB_SETINDENT, fMargin, 0 );                                          //
  with fBoundsRect do                                                           //
  begin                                                                         //
    if AAlign in [ caLeft, caRight ] then                                       //
      Right := Left + 24                                                        //
    else if not (AAlign in [caNone]) then                                       //
      Bottom := Top + 22;                                                       //
  end;                                                                          //
  if ABitmap <> 0 then                                                          //
    TBAddBitmap( ABitmap );                                                     //
  TBAddButtons( AButtons, ABtnImgIdxArray );                                    //
  Perform( WM_SIZE, 0, 0 );                                                     //
end;                                                                            //
                                                                                //
//[constructor TImageList.CreateImageList]
constructor TImageList.CreateImageList(POwner: Pointer);                        //
var AOwner: PControl;                                                           //
begin                                                                           //
  {*************} DoInitCommonControls( ICC_WIN95_CLASSES );                    //
  Create;                                                                       //
  FAllocBy := 1;                                                                //
  FMasked := True;                                                              //
  if POwner = nil then exit;                                                    //
  FBkColor := TColor( CLR_NONE );
  //ImageList_SetBkColor( FHandle, CLR_NONE );
                                                                                //
  AOwner := POwner;                                                             //
  FControl := AOwner;                                                           //
  fNext := PImageList( AOwner.fImageList );                                     //
  if AOwner.fImageList <> nil then                                              //
     PImageList( AOwner.fImageList ).fPrev := @Self;                            //
  AOwner.fImageList := @Self;                                                   //
end;                                                                            //
                                                                                //
//[constructor TThread.ThreadCreate]
constructor TThread.ThreadCreate;                                               //
begin                                                                           //
  IsMultiThread := True;                                                        //
  Create;                                                                       //
  FSuspended := True;                                                           //
  FHandle := CreateThread( nil, // no security                                  //
                          0,   // the same stack size                           //
                          @ThreadFunc, // thread entry point                    //
                          @Self,      // parameter to pass to ThreadFunc        //
                          CREATE_SUSPENDED,   // always SUSPENDED               //
                          FThreadID ); // receive thread ID                     //
end;                                                                            //
                                                                                //
//[constructor TThread.ThreadCreateEx]
constructor TThread.ThreadCreateEx( const Proc: TOnThreadExecute );             //
begin                                                                           //
  ThreadCreate;                                                                 //
  OnExecute := Proc;                                                            //
  Resume;                                                                       //
end;                                                                            //
                                                                                //
{$ENDIF USE_CONSTRUCTORS} //****************************************************//
{+}

//[procedure InvalidateExW]
procedure InvalidateExW( Wnd: HWnd );
begin
  InvalidateRect( Wnd, nil, TRUE );
  Wnd := GetWindow( Wnd, GW_CHILD );
  while Wnd <> 0 do
  begin
    InvalidateExW( Wnd );
    Wnd := GetWindow( Wnd, GW_HWNDNEXT );
  end;
end;

//[procedure TControl.InvalidateEx]
procedure TControl.InvalidateEx;
begin
  if fHandle = 0 then Exit;
  InvalidateExW( fHandle );
end;

//[procedure InvalidateNCW]
procedure InvalidateNCW( Wnd: HWnd; Recursive: Boolean );
begin
  SendMessage( Wnd, WM_NCPAINT, 1, 0 );
  if not Recursive then Exit;
  Wnd := GetWindow( Wnd, GW_CHILD );
  while Wnd <> 0 do
  begin
    InvalidateNCW( Wnd, Recursive );
    Wnd := GetWindow( Wnd, GW_HWNDNEXT );
  end;
end;

//[procedure TControl.InvalidateNC]
procedure TControl.InvalidateNC(Recursive: Boolean);
begin
  if fHandle = 0 then Exit;
  InvalidateNCW( fHandle, Recursive );
end;

//[procedure TControl.SetClientMargin]
procedure TControl.SetClientMargin(const Index, Value: Integer);
begin
  case Index of
  1: fClientTop := Value;
  2: fClientBottom := Value;
  3: fClientLeft := Value;
  4: fClientRight := Value;
  end;
  {$IFNDEF OLD_ALIGN}include(fAligning,oaFromSelf);{$ENDIF}//???
  Global_Align( @Self );
end;

{$IFDEF F_P}
//[function TControl.GetClientMargin]
function TControl.GetClientMargin(const Index: Integer): Integer;
begin
  CASE Index OF
  1: Result := fClientTop;
  2: Result := fClientBottom;
  3: Result := fClientLeft;
  4: Result := fClientRight;
  END;
end;
{$ENDIF F_P}

{------------------------------------------------------------------------------}

{                        G R A P H   C O N T R O L S                           }

{------------------------------------------------------------------------------}
type TGrayTextData = {$ifndef wince}packed{$endif} record
       Ctl: PControl;
       W, H: Integer;
       Flags: DWORD;
     end;
     PGrayTextData = ^TGrayTextData;

function DrawTextGrayed( DC: HDC; lData, wData, cX, cY: Integer ): BOOL; {$ifdef wince}cdecl{$else}stdcall{$endif};
var GDT: PGrayTextData;
    R: TRect;
begin
  GDT := Pointer( lData );
  R := MakeRect( 0, 0, cX, cY );
  DrawFormattedText( GDT.Ctl, DC, R, GDT.Flags or $80000000 );
  Result := TRUE;
end;

procedure DrawFormattedText( Ctl: PControl; DC: HDC; var R: TRect; Flags: DWORD {EditCtl: Boolean} );
var Fmt: DWORD;
    OldFont: Integer;
    OldBrush: Integer;
    OldBk: Integer;
    ParentHavingFont: PControl;
{$ifdef win32}
    GTD: TGrayTextData;
{$endif win32}
    dX, dY: Integer;
    R1: TRect;
begin
  Fmt := DT_EXPANDTABS or Flags and $7FFFFFFF;
  if Ctl.WordWrap then
    Fmt := Fmt or DT_WORDBREAK;
  if Flags and DT_EDITCONTROL <> 0 then
    Inc( R.Left, 4 );

  ParentHavingFont := Ctl;
  while (ParentHavingFont <> nil) and not Assigned( ParentHavingFont.FFont )
        and not ParentHavingFont.IsForm do
    ParentHavingFont := ParentHavingFont.Parent;
  OldFont := 0;
  if Assigned( ParentHavingFont ) then
  begin
    OldFont := SelectObject( DC, ParentHavingFont.Font.Handle );
    SetTextColor( DC, ParentHavingFont.Font.FColorRGB );
  end;

  R1 := R;
  Windows.{$IFDEF UNICODE_CTRLS}DrawTextW{$ELSE}DrawTextA{$ENDIF}( DC, PKOLChar( Ctl.Caption ), Length( Ctl.Caption ), R,
    Fmt or DT_CALCRECT );
  CASE Ctl.fTextAlign OF
  taCenter:
    dX := (R1.Right - R1.Left - (R.Right - R.Left)) div 2;
  taRight:
    dX := R1.Right - R.Right;
  else
    dX := 0;
  END;
  CASE Ctl.fVerticalAlign OF
  vaCenter:
    dY := (R1.Bottom - R1.Top - (R.Bottom - R.Top)) div 2;
  vaBottom:
    dY := R1.Bottom - R.Bottom;
  else
    dY := 0;
  END;
  OffsetRect( R, dX, dY );

  if Ctl.fEnabled or (Flags and $80000000 <> 0) then
  begin
    OldBk := SetBkMode( DC, TRANSPARENT );
    OldBrush := SelectObject( DC, GetStockObject( NULL_BRUSH ) );
    Windows.{$IFDEF UNICODE_CTRLS}DrawTextW{$ELSE}DrawTextA{$ENDIF}( DC, PKOLChar( Ctl.Caption ), Length( Ctl.Caption ), R, Fmt );
    SelectObject( DC, OldBrush );
    SetBkMode( DC, OldBk );
  end
    else
  begin
{$ifdef wince}
    MsgOk('DrawFormattedText must be fixed!');
    Halt(4); // FIXME
{$else}
    GTD.Ctl := Ctl;
    GTD.W := R.Right - R.Left;
    GTD.H := R.Bottom - R.Top;
    GTD.Flags := Flags;
    Windows.DrawState( DC, GetStockObject( NULL_BRUSH ), @ DrawTextGrayed,
      Integer( @ GTD ), Length( Ctl.fCaption ), R.Left, R.Top, R.Right - R.Left, R.Bottom - R.Top,
      DST_COMPLEX or DSS_DISABLED );
{$endif wince}
  end;
  if Assigned( ParentHavingFont ) then
    SelectObject( DC, OldFont );
end;

{$IFDEF USE_GRAPHCTLS}
{$IFDEF GRAPHCTL_XPSTYLES}
type TOpenThemeDataProc = function( Wnd: HWnd; pszClassList: PWideChar ): THandle;
                          {$ifdef wince}cdecl{$else}stdcall{$endif};
     TDrawThemeBackground = function( Theme: THandle; DC: HDC; iPartId: Integer;
                          iStateId: Integer; Rect, ClipRect: PRect ): Integer;
                          {$ifdef wince}cdecl{$else}stdcall{$endif};
     TGetThemeBackgroundContentRect = function( Theme: THandle; DC: HDC;
                          iPartId, iStateId: Integer; Rect, ContentRect: PRect ):
                          Integer; {$ifdef wince}cdecl{$else}stdcall{$endif};
     TDrawThemeText = function( Theme: THandle; DC: HDC; iPartId, iStateId: Integer;
                          pszText: PWideChar; iCharCount: Integer;
                          dwTextFlags, dwTextFlags2: DWORD; Rect: PRect ): Integer;
                          {$ifdef wince}cdecl{$else}stdcall{$endif};
     TCloseThemeData = function( Theme: THandle ): Integer; {$ifdef wince}cdecl{$else}stdcall{$endif};
var fOpenThemeDataProc: TOpenThemeDataProc;
    fDrawthemeBackground: TDrawThemeBackground;
    fGetThemeBackgroundcontentRect: TGetThemeBackgroundContentRect;
    fDrawThemeText: TDrawThemeText;
    fCloseThemeData: TCloseThemeData;
    uxtheme_lib: THandle;
function OpenThemeDataProc: TOpenThemeDataProc;
begin
  Result := nil;
  if Integer(uxtheme_lib) = -1 then Exit;
  if uxtheme_lib = 0 then
    uxtheme_lib := LoadLibrary( 'uxtheme' );
  if uxtheme_lib = 0 then
  begin
    uxtheme_lib := DWORD( -1 );
    Exit;
  end;
  fOpenThemeDataProc := GetProcAddress( uxtheme_lib, 'OpenThemeData' );
  fDrawthemeBackground := GetProcAddress( uxtheme_lib, 'DrawThemeBackground' );
  fGetThemeBackgroundcontentRect := GetProcAddress( uxtheme_lib, 'GetThemeBackgroundContentRect' );
  fDrawThemeText := GetProcAddress( uxtheme_lib, 'DrawThemeText' );
  fCloseThemeData := GetProcAddress( uxtheme_lib, 'CloseThemeData' );
  if not Assigned( fOpenThemeDataProc ) or
     not Assigned( fDrawThemeBackground ) or
     not Assigned( fGetThemeBackgroundcontentRect ) or
     not Assigned( fDrawThemeText ) or
     not Assigned( fCloseThemeData ) then
  begin
    FreeLibrary( uxtheme_lib );
    uxtheme_lib := DWORD( -1 );
    fOpenThemeDataProc := nil;
    fDrawThemeBackground := nil;
    fGetThemeBackgroundcontentRect := nil;
    fDrawThemeText := nil;
    fCloseThemeData := nil;
  end;
  Result := fOpenThemeDataProc;
end;

procedure DrawFormattedTextXP( Theme: THandle; Ctl: PControl; DC: HDC;
  var R: TRect; CtlType, CtlStates, Flags1, Flags2: Integer );
var OldFont: Integer;
    OldBrush: Integer;
    ParentHavingFont: PControl;
begin
  ParentHavingFont := Ctl;
  while (ParentHavingFont <> nil) and not Assigned( ParentHavingFont.FFont )
        and not ParentHavingFont.IsForm do
    ParentHavingFont := ParentHavingFont.Parent;
  OldFont := 0;
  if Assigned( ParentHavingFont ) then
    OldFont := SelectObject( DC, ParentHavingFont.Font.Handle );
  OldBrush := SelectObject( DC, GetStockObject( NULL_BRUSH ) );
  fDrawThemeText( Theme, DC, CtlType, CtlStates, @ WideString( Ctl.fCaption )[ 1 ],
                  Length( Ctl.fCaption ), Flags1, Flags2, @ R );
  SelectObject( DC, OldBrush );
  if Assigned( ParentHavingFont ) then
    SelectObject( DC, OldFont );
end;
{$ENDIF}

procedure PaintGraphicChildren( Self_, Sender: PControl; DC: HDC );
var i, sav: Integer;
    C: PControl;
    R: TRect;
    rgn: HRgn;
begin
  for i := Self_.ChildCount-1 downto 0 do
  begin
    C := Self_.Children[ i ];
    if not C.Visible then continue;
    R := C.BoundsRect;
    if (C.Handle = 0) and not C.fWindowed and
       Assigned( C.fPaintProc ) then
    begin
      sav := SaveDC( DC );
      rgn := CreateRectRgnIndirect( R );
      ExtSelectClipRgn( DC, rgn, RGN_AND );
      SelectClipRgn( DC, rgn );
      DeleteObject( rgn );
      Free_And_Nil( C.fCanvas );

      C.fCanvas := Self_.Canvas;
      Self_.Canvas.Brush.Assign( Self_.Brush );
      Self_.Canvas.Font.Assign( Self_.Font ); // не присваивается?
      Self_.fCanvas.DeselectHandles;          // не помогает???

      if Assigned( C.OnPrepaint ) then
        C.OnPrePaint( C, DC );

      if Assigned( C.OnPaint ) then
        C.OnPaint( C, DC )
      else
        C.fPaintProc( DC );

      if Assigned( C.OnPostPaint ) then
        C.OnPostPaint( C, DC );

      C.fCanvas := nil; 

      Self_.Canvas.Brush.Assign( Self_.Brush );
      Self_.Canvas.Font.Assign( Self_.Font );

      RestoreDC( DC, sav );
      ExcludeClipRect( DC, R.Left, R.Top, R.Right, R.Bottom );
    end;
  end;
  if Self_.fIsGroupBox then
  begin
    Self_.fErasingBkgnd := TRUE;
    R := Self_.BoundsRect;
    OffsetRect( R, -R.Left, -R.Top );
    Self_.Canvas.FillRect( R );
    Self_.GroupBoxPaint( DC );
    Self_.fErasingBkgnd := FALSE;
  end
    else
  if Assigned( Self_.fOnPaint2 ) then
    Self_.fOnPaint2( Self_, DC )
  else
    Self_.Canvas.FillRect( Self_.ClientRect );
end;

function WndProc_ParentOfGraphicCtl( Self_: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var WasOnPaint: TOnPaint;
    i: Integer;
    C: PControl;
    Pt: TPoint;
    PF: PControl;
    save_Paint2: TOnPaint;
begin
  Result := FALSE;

  if (Msg.message = WM_PAINT) {or (Msg.message = WM_PRINT)} then
  begin
    //if not Result then
    begin
      WasOnPaint := Self_.fOnPaint;
      Self_.fOnPaint2 := Self_.fOnPaint;
      Self_.fPaintMsg := Msg;
      TMethod( Self_.fOnPaint ) := MakeMethod( Self_, @ PaintGraphicChildren );

      save_Paint2 := Self_.fOnPaint2;
      if not Assigned( Self_.fOnPaint2 ) then
        Self_.fOnPaint2 := TOnPaint( MakeMethod( nil, @ DummyPaintClear ) );

      i := Self_.fDynHandlers.fCount;
      Self_.fDynHandlers.fCount := Self_.fDynHandlers.IndexOf( @ WndProc_ParentOfGraphicCtl );
      Result := EnumDynHandlers( Self_, Msg, Rslt );
      Self_.fDynHandlers.fCount := i;

      //Self_.fOnPaint2 := save_Paint2;

      if not Result then
        {Result :=} WndProcPaint( Self_, Msg, Rslt );
      Self_.fOnPaint := WasOnPaint;
    end;
    Result := TRUE;
  end
    else
  if (Msg.message >= WM_MOUSEFIRST) and (Msg.message <= WM_MOUSELAST) then
  begin
    Pt.X := SmallInt( LoWord( Msg.lParam ) );
    Pt.Y := SmallInt( HiWord( Msg.lParam ) );
    for i := 0 to Self_.ChildCount-1 do
    begin
      if (i = 0) and (Self_.fPushedBtn <> nil) then
        C := Self_.fPushedBtn
      else
        C := Self_.Children[ i ];
      if (C = Self_.fPushedBtn) OR
         C.fVisible and C.fEnabled and PtInRect( C.BoundsRect, Pt ) then
      begin
        if not C.fWindowed and
           (C.fCursor <> 0) and (C.fCursor <> Self_.fCursor) and
           (ScreenCursor = 0) then
        begin
          if Self_.fSaveCursor = 0 then
          begin
            Self_.fSaveCursor := Self_.fCursor;
            if Self_.fCursor = 0 then
              Self_.fSaveCursor := LoadCursor( 0, IDC_ARROW );
          end;
          Self_.Cursor := C.fCursor;
          Windows.SetCursor( C.fCursor );
        end;
        {$IFDEF GRAPHCTL_HOTTRACK}
        if not C.fWindowed and (Applet.fHotCtl <> C) then
        begin
          if Applet.fHotCtl <> nil then
          begin
            Applet.fHotCtl.fHot := FALSE;
            if not Applet.fHotCtl.fWindowed then
            begin
              Applet.fHotCtl.Invalidate;
              if Assigned( Applet.fHotCtl.OnMouseLeave ) then
                Applet.fHotCtl.OnMouseLeave( Applet.fHotCtl );
            end;
            Applet.fHotCtl.RefDec;
          end;
          C.RefInc;
          Applet.fHotCtl := C;
          C.fHot := TRUE;
          C.Invalidate;
          Self_.fMouseLeaveProc := Self_.MouseLeaveFromParentOfGraphCtl;
          ProvideMouseEnterLeave( Self_ );
          if Assigned( C.OnMouseEnter ) then
            C.OnMouseEnter( C );
        end;
        {$ENDIF GRAPHCTL_HOTTRACK}
        if C.fWindowed then
        begin
          Msg.hwnd := C.fHandle;
          Pt := Self_.Client2Screen( Pt );
          Pt := C.Screen2Client( Pt );
          Msg.lParam := Pt.Y shl 16 or (Pt.X and $FFFF);
        end;
        Rslt := C.WndProc( Msg );
        if not C.fWindowed then
          if Assigned( C.fGraphCtlMouseEvent ) then
            C.fGraphCtlMouseEvent( Msg )
          else
          if (Msg.message = WM_LBUTTONDOWN) or
             (Msg.message = WM_RBUTTONDOWN) or
             (Msg.message = WM_MBUTTONDOWN) then
             C.DoClick;
        Result := TRUE;
        Exit;
      end;
    end;
    {$IFDEF GRAPHCTL_HOTTRACK}
    Self_.MouseLeaveFromParentOfGraphCtl( Self_ );
    {$ENDIF GRAPHCTL_HOTTRACK}
    if Self_.fIsGroupBox and (
         (Msg.message = WM_LBUTTONDOWN) or
         (Msg.message = WM_LBUTTONDBLCLK) or
         (Msg.message = WM_LBUTTONUP)
       ) then
    begin
      Self_.Invalidate;
    end;
    if Self_.fSaveCursor <> 0 then
    begin
      Self_.Cursor := Self_.fSaveCursor;
      Self_.fSaveCursor := 0;
      if ScreenCursor = 0 then
        Windows.SetCursor( Self_.fCursor );
    end;
  end
    else
  if (Msg.message >= WM_KEYFIRST) and (Msg.message <= WM_KEYLAST) then
  begin
    if Self_.IsControl then
      PF := Self_.ParentForm
    else
      PF := Self_;
    if (PF.fCurrentControl <> nil) and not PF.fCurrentControl.fWindowed then
    begin
      if Assigned( PF.fCurrentControl.fKeyboardProcess ) and
         PF.fCurrentControl.fKeyboardProcess( Msg, Rslt ) then
      else
         Rslt := PF.fCurrentControl.WndProc( Msg );
      Result := TRUE;
    end
      else
    begin
      if Self_.fIsGroupBox and (Msg.wParam = WORD( ' ' )) and
         (
           (Msg.message = WM_KEYDOWN) or
           (Msg.message = WM_SYSKEYDOWN) or
           (Msg.message = WM_KEYUP) or
           (Msg.message = WM_SYSKEYUP) or
           (Msg.message = WM_CHAR) or
           (Msg.message = WM_SYSCHAR)
         ) then
      begin
        Self_.Invalidate;
      end;
    end;
  end
    else
  if Msg.message = CM_QUIT then
  begin
    C := Pointer( Msg.wParam );
    C.Free;
  end
    else
  if Msg.message = CM_FOCUSGRAPHCTL then
  begin
    C := Pointer( Msg.wParam );
    PF := C.ParentForm;
    if (PF.fCurrentControl <> nil) and (PF.fCurrentControl <> C) then
    begin
      PF.fCurrentControl.fFocused := FALSE;
      PF.fCurrentControl.Invalidate;
    end;
    PF.fCurrentControl := C;
    C.Parent.fCurrentControl := C;
    C.Parent.fFocusHandle := C.Parent.fHandle;
    C.fFocused := TRUE;
    if Assigned( C.fOnEnter ) then
      C.fOnEnter( C );
    C.Invalidate;
    C.fLeave := C.LeaveGraphButton;
    C.RefDec;
  end;
end;

function WndProc_FormHavingGraphCtl( Self_: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var Msg2: TMsg;
begin
  Result := FALSE;
  if Msg.message = WM_ACTIVATE then
  begin
    if Self_.fCurrentControl <> nil then
      Self_.fCurrentControl.Invalidate;
  end
    else
  if (Msg.message >= WM_KEYFIRST) and (Msg.message <= WM_KEYLAST) then
  begin
    if (Self_.fCurrentControl <> nil) and not Self_.fCurrentControl.fWindowed then
    begin
      if (Msg.message = WM_KEYDOWN) and ((Msg.wParam = 32) or (Msg.wParam = 13)) then
      begin
        if not PeekMessage( Msg2, Msg.hwnd, WM_CHAR, WM_CHAR, pm_noRemove ) or
           (Msg2.wParam <> Msg.wParam) then
           Msg.message := WM_CHAR;
      end
        else
      if (Msg.message = WM_SYSKEYDOWN) and ((Msg.wParam = 32) or (Msg.wParam = 13)) then
      begin
        if not PeekMessage( Msg2, Msg.hwnd, WM_SYSCHAR, WM_SYSCHAR, pm_noRemove ) or
           (Msg2.wParam <> Msg.wParam) then
           Msg.message := WM_SYSCHAR;
      end;
      if Assigned( Self_.fCurrentControl.fKeyboardProcess ) and
         Self_.fCurrentControl.fKeyboardProcess( Msg, Rslt ) then
      else
         Rslt := Self_.fCurrentControl.WndProc( Msg );
      Result := TRUE;
    end;
  end;
end;

{$IFDEF GRAPHCTL_HOTTRACK}
procedure TControl.MouseLeaveFromParentOfGraphCtl(Sender: PObj);
var C: PControl;
    Pt: TPoint;
begin
  if AppletTerminated then Exit;
  GetCursorPos( Pt );
  Pt := Screen2Client( Pt );
  if (Applet.fHotCtl <> nil) and (fChildren.IndexOf( Applet.fHotCtl ) >= 0) then
  begin
    C := Applet.fHotCtl;
    if PtInRect( C.BoundsRect, Pt ) then Exit;
    Applet.fHotCtl := nil;
    C.fHot := FALSE;
    if not C.fWindowed then
      C.Invalidate;
    if Assigned( C.OnMouseLeave ) then
      C.OnMouseLeave( C );
    C.RefDec;
  end;
end;
{$ENDIF GRAPHCTL_HOTTRACK}

procedure NotifyGraphCtlAboutNewParent(Prnt, Chld: PControl);
begin
  if (Chld <> nil) and (Prnt <> nil) then
  begin
    Prnt.AttachProc( WndProc_ParentOfGraphicCtl );
    {if not Prnt.IsProcAttached( WndProc_ParentOfGraphicCtl ) then
    begin
      Prnt.fDynHandlers.Insert( 0, nil );
      Prnt.fDynHandlers.Insert( 0, @ WndProc_ParentOfGraphicCtl );
    end;}
  end;
end;

function _NewGraphCtl( AParent: PControl; ATabStop: Boolean ): PControl;
begin
  {-}
  new( Result, Create );
  {+}{++}(*Result := PControl.CreateParented( AParent );*){--}
  Result.fDoInvalidate := Result.InvalidateNonWindowed;
  Result.fWindowed := FALSE;
  Result.fVisible := TRUE;
  Result.fCreateVisible := TRUE;
  Result.fIsControl := TRUE;
  Result.fMenu := CtlIdCount;
  Inc( CtlIdCount );
  Result.fBitBtnOptions := [ bboFixed ]; // to return Checked = fChecked w/o window handle
  Result.fIgnoreWndCaption := TRUE;
  Result.fNotifyChild := @ NotifyGraphCtlAboutNewParent;
  Result.fSizeRedraw := TRUE;
  Result.fTabstop := ATabStop;
  if ATabStop then
    Result.fLookTabKeys := [ tkTab, tkLeftRight, tkUpDown, tkPageUpPageDn ];
  if AParent <> nil then
  begin
    Result.Parent := AParent;
    Result.Border := AParent.Border;
    //if not AParent.IsProcAttached( WndProc_ParentOfGraphicCtl ) then
    begin
      AParent.AttachProc( WndProc_ParentOfGraphicCtl );
      //AParent.fDynHandlers.Insert( 0, nil );
      //AParent.fDynHandlers.Insert( 0, @ WndProc_ParentOfGraphicCtl );
    end;
    if ATabStop then
    begin
      Inc( AParent.ParentForm.fTabOrder );
      Result.fTabOrder := AParent.ParentForm.fTabOrder;
    end;
    if AParent.IsControl then
      AParent.ParentForm.AttachProc( WndProc_FormHavingGraphCtl );
    if AParent.fIsGroupBox then
    begin
      AParent.Style := AParent.Style and
        not BS_GROUPBOX; // otherwise the groupbox is flickering A LOT!
      AParent.Parent.AttachProc( WndProc_ParentOfGraphicCtl );
    end;

     Result.fFont := Result.fFont.Assign( AParent.fFont );
     if Result.fFont <> nil then
     begin
       Result.fFont.fParentGDITool := AParent.fFont;
       Result.fFont.fOnChange := Result.FontChanged;
       Result.FontChanged( Result.fFont );
     end;
  end;
  Result.fBoundsRect.Right := Result.fBoundsRect.Left + 64;
  Result.fBoundsRect.Bottom := Result.fBoundsRect.Top + 22;

  {$IFDEF GRAPHCTL_XPSTYLES}
  if WinVer < wvXP then
    DoNotDrawGraphCtlsUsingXPStyles := TRUE;
  {$ENDIF}
end;

function NewGraphLabel( AParent: PControl; const ACaption: String ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewLabel( AParent, ACaption );
  {$ELSE}
  Result := _NewGraphCtl( AParent, FALSE );
  Result.fCommandActions := LabelActions;
  Result.fPaintProc := Result.GraphicLabelPaint;
  Result.Caption := ACaption;
  {$ENDIF}
end;

function NewWordWrapGraphLabel( AParent: PControl; const ACaption: KOLString ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewWordWrapLabel( AParent, ACaption );
  {$ELSE}
  Result := NewGraphLabel( AParent, ACaption );
  Result.fWordWrap := TRUE;
  {$ENDIF}
end;

function NewGraphPaintBox( AParent: PControl ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewPaintbox( AParent );
  {$ELSE}
  Result := NewGraphLabel( AParent, '' );
  {$ENDIF}
end;

procedure ClickGraphCheck(Sender: PObj);
var Ctl: PControl;
begin
  Ctl := Pointer( Sender );
  if not Ctl.Enabled then Exit;
  Ctl.Focused := TRUE;
  if Assigned( Ctl.OnEnter ) then
    Ctl.OnEnter( Ctl );
  Ctl.fChecked := not Ctl.fChecked;
  Ctl.Invalidate;
  if Assigned( Ctl.OnClick ) then
    Ctl.OnClick( Ctl );
end;

function NewGraphCheckBox( AParent: PControl; const ACaption: KOLString ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewCheckbox( AParent, ACaption );
  {$ELSE}
  Result := NewGraphButton( AParent, ACaption );
  Result.TextAlign := taLeft;
  Result.fCommandActions.aAutoSzX := GetSystemMetrics( SM_CXMENUCHECK ) + 4;
  Result.fPaintProc := Result.GraphicCheckBoxPaint;
  Result.fGraphCtlMouseEvent := Result.GraphicCheckBoxMouse;
  Result.fControlClick := @ ClickGraphCheck;
  {$ENDIF}
end;

procedure ClickGraphRadio(Sender: PObj);
var Ctl, C: PControl;
    i: Integer;
begin
  Ctl := Pointer( Sender );
  if not Ctl.Enabled then Exit;
  Ctl.Focused := TRUE;
  Ctl.Checked := TRUE;
  if Ctl.Parent <> nil then
  for i := 0 to Ctl.Parent.ChildCount-1 do
  begin
    C := Ctl.Parent.Children[ i ];
    if (C <> Ctl) and (@ C.fControlClick = @ ClickGraphRadio) then
      C.Checked := FALSE;
  end;
end;

function NewGraphRadioBox( AParent: PControl; const ACaption: KOLString ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewRadiobox( AParent, ACaption );
  if (@ ClickGraphRadio) <> nil then;
  {$ELSE}
  Result := NewGraphButton( AParent, ACaption );
  Result.TextAlign := taLeft;
  Result.fCommandActions.aAutoSzX := GetSystemMetrics( SM_CXMENUCHECK ) + 4;
  Result.fPaintProc := Result.GraphicRadioBoxPaint;
  Result.fControlClick := @ ClickGraphRadio;
  if AParent <> nil then
  begin
    AParent.fRadioLast := Result.fMenu;
    if AParent.fRadio1st = 0 then
    begin
       AParent.fRadio1st := Result.fMenu;
       Result.SetRadioChecked;
    end;
  end;
  {$ENDIF}
end;

function NewGraphButton( AParent: PControl; const ACaption: KOLString ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewButton( AParent, ACaption );
  {$ELSE}
  Result := _NewGraphCtl( AParent, TRUE );
  Result.fCommandActions := ButtonActions;
  Result.fPaintProc := Result.GraphicButtonPaint;
  Result.Caption := ACaption;
  Result.TextAlign := taCenter;
  Result.VerticalAlign := vaCenter;
  Result.fGraphCtlMouseEvent := Result.GraphicButtonMouse;
  Result.fSetFocus := Result.GraphButtonSetFocus;
  Result.fKeyboardProcess := Result.GraphButtonKeyboardProcess;
  {$ENDIF}
end;

function NewGraphEditbox( AParent: PControl; Options: TEditOptions ): PControl;
begin
  {$IFDEF INPACKAGE}
  Result := NewEditbox( AParent, Options );
  {$ELSE}
  Result := _NewGraphCtl( AParent, TRUE );
  Result.fCommandActions := EditActions;
  Result.fPaintProc := Result.GraphicEditPaint;
  Result.fEditOptions := Options;
  Result.VerticalAlign := vaCenter;
  Result.fColor := clWindow;
  Result.fGraphCtlMouseEvent := Result.GraphicEditMouse;
  Result.fSetFocus := Result.GraphEditBoxSetFocus;
  Result.fLookTabKeys := [ tkTab, tkUpDown, tkPageUpPageDn ];
  Result.fLeave := Result.LeaveGraphEdit;
  {$ENDIF}
end;

{ TGraphicControl }

function TControl.DoGraphCtlPrepaint: TRect;
begin
  Result := ClientRect;
  if not Assigned( OnPrepaint ) and not Transparent then
  begin
    if Assigned( fBrush ) then
      Canvas.Brush.Assign( fBrush )
    else
      Canvas.Brush.Color := Color;
    Canvas.FillRect( Result );
  end;
end;

procedure TControl.GraphicLabelPaint(DC: HDC);
var R: TRect;
begin
  R := DoGraphCtlPrepaint;
  if Text <> '' then
    DrawFormattedText( @ Self, DC, R, 0 );
  //SaveImg( Canvas, R, 'bm09.bmp' );
  //sv1 := FALSE;
end;

procedure TControl.GraphicCheckBoxPaint(DC: HDC);
var R, R1: TRect;
    Flag: DWORD;
    W, H: Integer;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Theme: THandle;
    {$ENDIF}
begin
  R := DoGraphCtlPrepaint;
  {
  R := ClientRect;
  if not Assigned( OnPrepaint ) and not Transparent then
  begin
    if Assigned( fBrush ) then
      Canvas.Brush.Assign( fBrush )
    else
      Canvas.Brush.Color := Color;
    Canvas.FillRect( R );
  end;
  }

  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
    Theme := fOpenThemeDataProc( 0, 'Button' );
  if Theme <> 0 then
  begin

    W := GetSystemMetrics( SM_CXMENUCHECK );
    H := GetSystemMetrics( SM_CYMENUCHECK );

    R1 := R;
    R1.Right := R1.Left + W;
    if fWordWrap then
      R1.Top := R1.Top + Border
    else
      R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
    R1.Bottom := R1.Top + H;

    Flag := 1; {CBS_UNCHECKEDNORMAL}
    if not Enabled then
      Flag := 4 {CBS_UNCHECKEDDISABLED}
    else
    if fHot then
      Flag := 2; {CBS_UNCHECKEDHOT}
    if fChecked then
      Inc( Flag, 4 );
    fDrawThemeBackground( Theme, DC, 3 {BP_CHECKBOX}, Flag, @R1, @R  );

    R.Left := R1.Left + W + Border;

    if fCaption <> '' then
    begin
      DrawFormattedText( @ Self, DC, R, DT_CALCRECT );
      if fWordWrap then
      begin
        DrawFormattedText( @ Self, DC, R, 0 );
        GraphCtlDrawFocusRect( DC, R );
      end
        else
      begin
        GraphCtlDrawFocusRect( DC, R );
        DrawFormattedTextXP( Theme, @ Self, DC, R, 3 {BP_CHECKBOX}, Flag, 0, 0 );
      end;
    end;

    fCloseThemeData( Theme );
  end
    else
  {$ENDIF}
  begin

    W := GetSystemMetrics( SM_CXMENUCHECK );
    H := GetSystemMetrics( SM_CYMENUCHECK );

    R1 := R;
    R1.Right := R1.Left + W;
    if fWordWrap then
      R1.Top := R1.Top + Border
    else
      R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
    R1.Bottom := R1.Top + H;
    //if not Transparent then
    begin
      Flag := 0;
      if fChecked then
        Flag := DFCS_CHECKED;
      DrawFrameControl( DC, R1, DFC_BUTTON, DFCS_BUTTONCHECK or
                        $800 {DFCS_TRANSPARENT} or Flag );
    end;

    R.Left := R1.Left + W + Border;
    DrawFormattedText( @ Self, DC, R, 0 );
    GraphCtlDrawFocusRect( DC, R );
  end;
end;

procedure TControl.GraphicCheckBoxMouse(var Msg: TMsg);
begin
  if (Msg.message = WM_LBUTTONDOWN) or (Msg.message = WM_LBUTTONDBLCLK) then
    ClickGraphCheck( @ Self );
end;

procedure TControl.GraphicRadioBoxPaint(DC: HDC);
var R, R1: TRect;
    Flag: DWORD;
    W, H: Integer;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Theme: THandle;
    {$ENDIF}
begin
  R := DoGraphCtlPrepaint;
  {R := ClientRect;
  if not Assigned( OnPrepaint ) and not Transparent then
    Canvas.FillRect( R );}
  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
    Theme := fOpenThemeDataProc( 0, 'Button' );
  if Theme <> 0 then
  begin

    W := GetSystemMetrics( SM_CXMENUCHECK );
    H := GetSystemMetrics( SM_CYMENUCHECK );

    R1 := R;
    R1.Right := R1.Left + W;
    if fWordWrap then
      R1.Top := R1.Top + Border
    else
      R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
    R1.Bottom := R1.Top + H;

    Flag := 1; {CBS_UNCHECKEDNORMAL}
    if not Enabled then
      Flag := 4 {CBS_UNCHECKEDDISABLED}
    else
    if fHot then
      Flag := 2; {CBS_UNCHECKEDHOT}
    if fChecked then
      Inc( Flag, 4 );
    fDrawThemeBackground( Theme, DC, 2 {BP_RADIOBOX}, Flag, @R1, @R  );

    R.Left := R1.Left + W + Border;

    if fCaption <> '' then
    begin
      DrawFormattedText( @ Self, DC, R, DT_CALCRECT );
      if fWordWrap then
      begin
        DrawFormattedText( @ Self, DC, R, 0 );
        GraphCtlDrawFocusRect( DC, R );
      end
      else
      begin
        GraphCtlDrawFocusRect( DC, R );
        DrawFormattedTextXP( Theme, @ Self, DC, R, 2 {BP_RADIOBOX}, Flag, 0, 0 );
      end;
    end;
    fCloseThemeData( Theme );
  end
    else
  {$ENDIF}
  begin
    W := GetSystemMetrics( SM_CXMENUCHECK );
    H := GetSystemMetrics( SM_CYMENUCHECK );
    R1 := R;
    R1.Right := R1.Left + W;
    if fWordWrap then
      R1.Top := R1.Top + Border
    else
      R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
    R1.Bottom := R1.Top + H;
    //if not Transparent then
    begin
      Flag := 0;
      if fChecked then
        Flag := DFCS_CHECKED;
      DrawFrameControl( DC, R1, DFC_BUTTON, DFCS_BUTTONRADIO
                        or $800 {DFCS_TRANSPARENT} {or DFCS_ADJUSTRECT} or Flag );
    end;
    R.Left := R1.Right + 2;
    DrawFormattedText( @ Self, DC, R, 0 );
    GraphCtlDrawFocusRect( DC, R );
  end;
end;

procedure TControl.GraphicButtonPaint(DC: HDC);
var R: TRect;
    Flag: DWORD;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Flag1: DWORD;
    Theme: THandle;
    {$ENDIF}
    II: TIconInfo;
    BI: TagBitmap;
    Y: Integer;
    R1: TRect;
begin
  R := DoGraphCtlPrepaint;
  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
    Theme := fOpenThemeDataProc( 0, 'Button' );
  if Theme <> 0 then
  begin
    Flag := 1; {PBS_UNCHECKEDNORMAL}
    if not Enabled then
      Flag := 4 {PBS_UNCHECKEDDISABLED}
    else
    if fPushed then
      Flag := 3 {PBS_UNCHECKEDPRESSED}
    else
    if fHot then
      Flag := 2; {PBS_UNCHECKEDHOT}
    if fChecked then
      Inc( Flag, 4 );

    fDrawThemeBackground( Theme, DC, 1 {BP_PUSHBUTTON}, Flag, @R, @R  );

    fGetThemeBackgroundContentRect( Theme, DC, 1 {BS_PUSHBUTTON}, Flag, @R, @R1 );
    GraphCtlDrawFocusRect( DC, R1 );

    if (fButtonIcon <> 0) and GetIconInfo( fButtonIcon, II ) then
    begin
      if GetObject( II.hbmColor, Sizeof( BI ), @ BI ) <> 0 then
      begin
        CASE fVerticalAlign OF
        vaTop:
          Y := R.Top + Border;
        vaBottom:
          Y := R.Bottom - Border - BI.bmHeight;
        else //vaCenter:
          Y := R.Top + (R.Bottom - R.Top - BI.bmHeight) div 2;
        END;
        DrawIcon( DC, R.Left + Border, Y, fButtonIcon );
        Inc( R1.Left, BI.bmWidth + Border * 2 );
      end;
      DeleteObject( II.hbmColor );
      if II.hbmMask <> 0 then
        DeleteObject( II.hbmMask );
    end;

    if fCaption <> '' then
    begin
      Flag1 := DT_SINGLELINE;
      if WordWrap then
        Flag1 := DT_WORDBREAK;
      DrawFormattedText( @ Self, DC, R1, DT_CALCRECT );
      DrawFormattedTextXP( Theme, @ Self, DC, R1, 1 {BP_PUSHBUTTON}, Flag,
        Flag1, 0 );
    end;
    fCloseThemeData( Theme );
  end
    else
  {$ENDIF}
  begin
    Flag := 0;
    if fChecked then
      Flag := DFCS_CHECKED
    else
    if fPushed then
      Flag := DFCS_PUSHED;
    if fFlat then
      Flag := Flag or DFCS_FLAT;
    DrawFrameControl( DC, R, DFC_BUTTON, DFCS_BUTTONPUSH or
                      $800 {DFCS_TRANSPARENT} or DFCS_ADJUSTRECT or Flag );
    //{$IFNDEF GRAPHCTL_XPSTYLES}
    R1 := R;
    //{$ENDIF}

    if (fButtonIcon <> 0) and GetIconInfo( fButtonIcon, II ) then
    begin
      if GetObject( II.hbmColor, Sizeof( BI ), @ BI ) <> 0 then
      begin
        CASE fVerticalAlign OF
        vaTop:
          Y := R.Top + Border;
        vaBottom:
          Y := R.Bottom - Border - BI.bmHeight;
        else //vaCenter:
          Y := R.Top + (R.Bottom - R.Top - BI.bmHeight) div 2;
        END;
        DrawIcon( DC, R.Left + Border, Y, fButtonIcon );
        Inc( R1.Left, BI.bmWidth + Border * 2 );
      end;
      DeleteObject( II.hbmColor );
      if II.hbmMask <> 0 then
        DeleteObject( II.hbmMask );
    end;

    DrawFormattedText( @ Self, DC, R1, 0 );
    GraphCtlDrawFocusRect( DC, R );
  end;
end;

procedure TControl.GraphicButtonMouse(var Msg: TMsg);
var Pt: TPoint;
begin
  CASE Msg.message OF
  WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
    begin
      GraphButtonSetFocus;
      RefInc;
      SetCapture( Parent.Handle );
      Parent.fPushedBtn := @ Self;
      fPushed := TRUE;
      Invalidate;
    end;
  WM_LBUTTONUP:
    begin
      ReleaseCapture;
      Invalidate;
      if fPushed then
      begin
        Pt.X := SmallInt( LoWord( Msg.lParam ) );
        Pt.Y := SmallInt( HiWord( Msg.lParam ) );
        if PtInRect( ClientRect, Pt ) then
          DoClick;
        fPushed := FALSE;
        Parent.fPushedBtn := nil;
        RefDec;
      end;
    end;
  END;
end;

procedure TControl.GraphButtonSetFocus;
var PF: PControl;
    CC: PControl;
    W: HWnd;
begin
  if not fTabStop then Exit;
  PF := ParentForm;
  if (PF.fCurrentControl <> nil) and (PF.fCurrentControl <> @ Self) and
     (PF.fCurrentControl <> Parent) then
  begin
    CC := PF.fCurrentControl;
    CC.RefInc;
    Parent.Focused := TRUE;
    if Assigned( CC.fLeave ) then
      CC.fLeave( PF.fCurrentControl )
    else
      Windows.SetFocus( 0 );
    CC.RefDec;
  end
    else
  begin
    W := GetFocus;
    if (W <> Parent.fHandle) and (W <> 0) then
    begin
      Windows.SetFocus( 0 );
      Parent.Focused := TRUE;
    end;
  end;
  if Parent.fHandle <> 0 then
  begin
    fFocused := TRUE;
    Parent.Postmsg( CM_FOCUSGRAPHCTL, Integer( @ Self ), 0 );
    RefInc;
  end;
  if Assigned( fOnEnter ) then
    fOnEnter( @ Self );
end;

procedure TControl.LeaveGraphButton( Sender: PObj );
begin
  fFocused := FALSE;
  if Parent.fCurrentControl = @ Self then
    Parent.fCurrentControl := nil;
  if ParentForm.fCurrentControl = @ Self then
    ParentForm.fCurrentControl := nil;
  Invalidate;
  if Assigned( fOnLeave ) then
    fOnLeave( @ Self );
end;

function TControl.GraphButtonKeyboardProcess(var Msg: TMsg;
  var Rslt: Integer): Boolean;
var SpacePressed: Boolean;
begin
  Result := FALSE;
  SpacePressed := Msg.wParam = Word( ' ' );
  {$IFDEF ALL_BUTTONS_RESPOND_TO_ENTER}
  SpacePressed := SpacePressed or (Msg.wParam = 13);
  {$ENDIF}
  if not SpacePressed then Exit;
  if (Msg.message = WM_KEYDOWN) or (Msg.message = WM_SYSKEYDOWN) then
  begin
    Parent.fPushedBtn := @ Self;
    fPushed := TRUE;
    Invalidate;
    Result := TRUE; /////
  end
    else
  if (Msg.message = WM_KEYUP) or (Msg.message = WM_SYSKEYUP) then
  begin
    fPushed := FALSE;
    Parent.fPushedBtn := nil;
    Invalidate;
    Result := TRUE; /////
  end
    else
  if (Msg.message = WM_CHAR) or (Msg.message = WM_SYSCHAR) then
  begin
    DoClick;
    Result := TRUE;
  end;
end;

procedure TControl.GraphicEditPaint(DC: HDC);
var R: TRect;
    {$IFDEF GRAPHCTL_XPSTYLES}
    R1: TRect;
    Flag, Flag1: DWORD;
    Theme: THandle;
    {$ENDIF}
begin
  R := ClientRect;
  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
    Theme := fOpenThemeDataProc( 0, 'Edit' );
  if Theme <> 0 then
  begin
    Flag := 1; {ETS_NORMAL}
    if not Enabled then
      Flag := 4 {ETS_DISABLED}
    else
    if eoReadonly in fEditOptions then
      Flag := 6 {ETS_READONLY}
    else
    if fFocused then
      Flag := 5 {ETS_FOCUSED}
    else
    if fHot then
      Flag := 2; {ETS_HOT}

    fDrawThemeBackground( Theme, DC, 1 {EP_EDITTEXT}, Flag, @R, @R  );

    Inc( R.Left, 2 );
    Dec( R.Right, 2 );
    fGetThemeBackgroundContentRect( Theme, DC, 1 {EP_EDITTEXT}, Flag, @R, @R1 );

    if fCaption <> '' then
    begin
      Flag1 := DT_SINGLELINE;
      if eoMultiline in fEditOptions then
        Flag1 := DT_WORDBREAK;
      CASE fTextAlign OF
      taCenter: Flag1 := Flag1 or DT_CENTER;
      taRight:  Flag1 := Flag1 or DT_RIGHT;
      //else    Flag1 := Flag1 or DT_LEFT;
      END;
      CASE fVerticalAlign OF
      vaCenter: Flag1 := Flag1 or DT_VCENTER;
      vaBottom: Flag1 := Flag1 or DT_BOTTOM;
      //else    Flag1 := Flag1 or DT_TOP;
      END;
      DrawFormattedTextXP( Theme, @ Self, DC, R1, 1 {EP_EDITTEXT}, Flag,
        Flag1, 0 );
    end;
    fCloseThemeData( Theme );
  end
    else
  {$ENDIF}
  begin
    if not Assigned( OnPrepaint ) and not Transparent then
    begin
      Canvas.Brush.Color := fColor;
      Canvas.FillRect( R );
    end;

    DrawEdge( DC, R, BDR_SUNKENINNER or BDR_SUNKENOUTER, BF_ADJUST or BF_RECT  );

    DrawFormattedText( @ Self, DC, R, DT_EDITCONTROL );
  end;
end;

procedure TControl.GraphicEditMouse(var Msg: TMsg);
var E: PControl;
    Pt: TPoint;
begin
  CASE Msg.message OF
  WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
    if not ( eoReadOnly in fEditOptions ) then
    begin
      E := EditGraphEdit;
      Pt.X := Smallint( LoWord( Msg.lParam ) ) - Left;
      Pt.Y := Smallint( HiWord( Msg.lParam ) ) - Top;
      PostMessage( E.Handle, Msg.message, Msg.wParam,
        Pt.Y shl 16 or Pt.X and $FFFF );
    end;
  END;
end;

function TControl.EditGraphEdit: PControl;
var E: PControl;
begin
  E := NewEditBox( Parent, fEditOptions )
       .SetPosition( Left, Top )
       .SetSize( Width, Height )
       .SetAlign( Align );
  E.fTabOrder := fTabOrder;
  E.Text := Text;
  E.OnChange := ChangeGraphEdit;
  E.Color := Color;
  E.fCursor := fCursor;
  E.CreateWindow;
  E.OnLeave := LeaveGraphEdit;
  E.fLeave := LeaveGraphEdit;
  E.Focused := TRUE;
  E.OnChar := OnChar;
  E.OnKeyDown := OnKeyDown;
  E.OnKeyUp := OnKeyUp;
  E.OnDestroy := DestroyGraphEdit;
  //E.Font.Assign( Font );
  Result := E;
  Visible := FALSE;
  fEditCtl := E;
  if Assigned( fOnEnter ) then
    fOnEnter( @ Self );
end;

procedure TControl.LeaveGraphEdit(Sender: PObj);
begin
  if PControl( Sender ).fWindowed and Assigned( fEditCtl ) then
  begin
    Text := PControl( Sender ).Text;
    fEditCtl := nil;
    Visible := TRUE;
    ParentForm.fCurrentControl := @ Self;
    Parent.fCurrentControl := @ Self;
    Parent.Postmsg( CM_QUIT, DWORD( Sender ), 0 );
  end
    else
  if Assigned( fEditCtl ) then
  begin
    fEditCtl.fLeave( fEditCtl );
  end;
end;

procedure TControl.ChangeGraphEdit(Sender: PObj);
begin
  Text := PControl( Sender ).Text;
end;

procedure TControl.GraphEditboxSetFocus;
begin
  EditGraphEdit;
end;

procedure TControl.DestroyGraphEdit(Sender: PObj);
begin
  fEditCtl := nil;
end;

procedure TControl.GraphCtlDrawFocusRect(DC: HDC; const R: TRect);
var rgn: HRgn;
begin
  if fFocused and (GetActiveWindow = ParentForm.Handle) then
  begin
    BeginPath( DC );
    Canvas.FrameRect( R );
    EndPath( DC );
    Canvas.FrameRect( R );
    DrawFocusRect( DC, R );
    rgn := PathToRegion( DC );
    ExtSelectClipRgn( DC, rgn, RGN_DIFF );
    DeleteObject( rgn );
  end;
end;

procedure TControl.GroupBoxPaint(DC: HDC);
var bk_erased: Boolean;

  procedure DoEraseBkgnd;
  var R: TRect;
  begin
    bk_erased := TRUE;
    if Assigned( OnEraseBkgnd ) then
      OnEraseBkgnd( @ Self, DC )
    else
    begin
      R := BoundsRect;
      OffsetRect( R, -R.Left, -R.Top );
      SetBkMode( DC, OPAQUE );
      SetBkColor( DC, Color2RGB( fColor ) );
      SetBrushOrgEx( DC, 0, 0, nil );
      Windows.FillRect( DC, R, Global_GetCtlBrushHandle( @ Self ) );
    end;
  end;

var R, R1, R0: TRect;
    rgn, rgn2, rgntxt, rgnsav, rgnsavall: HRgn;
    i: Integer;
    C: PControl;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Theme: THandle;
    Flag: DWORD;
    {$ENDIF}
begin
  if not fErasingBkgnd then
    Exit;
  R := ClientRect;
  Dec( R.Top, 14 { Self_.fClientTop div 2 } );
  Dec( R.Left, fClientLeft );
  Inc( R.Right, fClientRight );
  Inc( R.Bottom, fClientBottom );

  rgnsavall := CreateRectRgn( 0, 0, 0, 0 );
  GetClipRgn( DC, rgnsavall );

  TRY

  for i := 0 to ChildCount-1 do
  begin
    C := Children[ i ];
    if not C.fWindowed and C.fVisible then
    begin
      rgn := CreateRectRgnIndirect( C.BoundsRect );
      ExtSelectClipRgn( DC, rgn, RGN_DIFF );
      DeleteObject( rgn );
    end;
  end;

  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
    Theme := fOpenThemeDataProc( 0, 'Button' );
  if Theme <> 0 then
  begin
    DoEraseBkgnd;

    Flag := 1; {GBS_NORMAL}
    if not Enabled then
      Flag := 2; {GBS_DISABLED}
    R1 := R;

    rgnsav := 0;
    if fCaption <> '' then
    begin
      R1.Top := 0;
      Inc( R1.Left, 8 );
      Dec( R1.Right, 8 );
      BeginPath( DC );
      DrawFormattedTextXP( Theme, @ Self, DC, R1, 4 {BP_GROUPBOX}, Flag, 0, 0 );
      EndPath( DC );
      rgntxt := PathToRegion( DC );
      if rgntxt = 0 then
      begin
        R1.Right := R1.Left + Canvas.TextWidth( fCaption );
        R1.Bottom := R1.Top + Canvas.TextHeight( fCaption );
        rgntxt := CreateRectRgnIndirect( R1 );
      end;
      DrawFormattedTextXP( Theme, @ Self, DC, R1, 4 {BP_GROUPBOX}, Flag, 0, 0 );
      GetRgnBox( rgntxt, R0 );
      Dec( R0.Left, 3 );
      Inc( R0.Right, 3 );
      DeleteObject( rgntxt );
      rgn := CreateRectRgnIndirect( R0 );
    end
      else
    begin
      rgn := 0;
    end;
    if rgn <> 0 then
    begin
      rgnsav := CreateRectRgn( 0, 0, 0, 0 );
      GetClipRgn( DC, rgnsav );
      ExtSelectClipRgn( DC, rgn, RGN_DIFF );
      DeleteObject( rgn );
    end;
    fDrawThemeBackground( Theme, DC, 4 {BP_GROUPBOX}, Flag, @R, @R  );
    if rgnsav <> 0 then
    begin
      SelectClipRgn( DC, rgnsav );
      DeleteObject( rgnsav );
    end;

    fCloseThemeData( Theme );
  end
    else
  {$ENDIF}
  begin
    bk_erased := FALSE;

    R1 := R;
    R1.Top := 0;
    R1.Bottom := ClientRect.Top;
    Inc( R1.Left, 16 );
    Dec( R1.Right, 16 );
    fVerticalAlign := vaCenter;
    BeginPath( DC );
    Canvas.TextOut( R1.Left, R1.Top, fCaption );
    EndPath( DC );
    Canvas.TextOut( R1.Left, R1.Top, fCaption );
    rgntxt := PathToRegion( DC );
    if rgntxt = 0 then // такое - в случае шрифта по умолчаниі!
    begin
      R1.Right := R1.Left + Canvas.TextWidth( fCaption );
      R1.Bottom := R1.Top + Canvas.TextHeight( fCaption );
      rgntxt := CreateRectRgnIndirect( R1 );
    end;

    GetRgnBox( rgntxt, R0 );
    rgn2 := CreateRectRgnIndirect( R0 );

    rgnsav := CreateRectRgn( 0, 0, 0, 0 );
    GetClipRgn( DC, rgnsav );
    ExtSelectClipRgn( DC, rgn2, RGN_DIFF );
    DeleteObject( rgn2 );

    BeginPath( DC );
    DrawEdge( DC, R, BDR_RAISEDINNER or BDR_SUNKENOUTER, BF_RECT );
    EndPath( DC );
    rgn := PathToRegion( DC );
    if rgn = 0 then DoEraseBkgnd;
    DrawEdge( DC, R, BDR_RAISEDINNER or BDR_SUNKENOUTER, BF_RECT );

    SelectClipRgn( DC, rgnsav );
    DeleteObject( rgnsav );

    if rgn <> 0 then
    begin
      ExtSelectClipRgn( DC, rgn, RGN_DIFF );
      DeleteObject( rgn );
    end;
    ExtSelectClipRgn( DC, rgntxt, RGN_DIFF );
    DeleteObject( rgntxt );

    if not bk_erased then DoEraseBkgnd;
  end;

  FINALLY
    SelectClipRgn( DC, rgnsavall );
    DeleteObject( rgnsavall );
  END;
end;
{$ENDIF USE_GRAPHCTLS}

function TControl.MakeWordWrap: PControl;
begin
  fWordWrap := TRUE;
  Style := (fStyle and not SS_LEFTNOWORDWRAP) or BS_MULTILINE;
  Result := @ Self;
end;

function ParentAnchorChildren( Sender: PControl; var Msg: TMsg;
  var Rslt: Integer ): Boolean;
var NewW, NewH: Integer;
    dW, dH: Integer;
    i: Integer;
    C: PControl;
    {$IFNDEF ANCHORS_WM_SIZE}
    CR: TRect;
    {$ENDIF}
begin
  Result := FALSE;
  if (Msg.message = {$IFDEF ANCHORS_WM_SIZE} WM_SIZE {$ELSE} WM_WINDOWPOSCHANGED {$ENDIF} )
     {$ifndef wince} and not IsIconic(Sender.Handle) {$endif} then
  begin
    {$IFDEF ANCHORS_WM_SIZE}
    NewW := LoWord( Msg.lParam ) - Sender.fClientLeft - Sender.fClientRight;
    NewH := HiWord( Msg.lParam ) - Sender.fClientTop - Sender.fClientBottom;
    {$ELSE}
    CR := Sender.ClientRect;
    NewW := CR.Right;
    NewH := CR.Bottom;
    {$ENDIF}
    dW := NewW - Sender.fOldWidth;
    dH := NewH - Sender.fOldHeight;
    for i := 0 to Sender.ChildCount - 1 do
    begin
      C := Sender.Children[ i ];

      if dW <> 0 then
      begin
        if C.AnchorRight and C.AnchorLeft then
          C.Width := C.Width + dW
        else if C.AnchorRight then
          C.Left := C.Left + dW;
      end;
      if dH <> 0 then
      begin
        if C.AnchorBottom and C.AnchorTop then
          C.Height := C.Height + dH
        else if C.AnchorBottom then
          C.Top := C.Top + dH;
      end;

    end;
    Sender.fOldWidth := NewW;
    Sender.fOldHeight := NewH;
  end;
end;

function TControl.Anchor(aLeft, aTop, aRight, aBottom: Boolean): PControl;
begin
  if (not aLeft) and aRight then
    SetAnchorLeft( FALSE )
  else
    SetAnchorLeft( aLeft );

  if (not aTop) and aBottom then
    SetAnchorTop( FALSE )
  else
    SetAnchorTop( aTop );

  SetAnchorRight( aRight );
  SetAnchorBottom( aBottom );

  Result := @ Self;
end;

procedure TControl.SetAnchorLeft(const Value: Boolean);
begin
  fAnchorLeft := Value;
  if Parent <> nil then
  begin
    fParent.AttachProc( ParentAnchorChildren );
    Parent.fOldWidth := Parent.ClientWidth;
  end;
end;

procedure TControl.SetAnchorTop(const Value: Boolean);
begin
  fAnchorTop := Value;
  if Parent <> nil then
  begin
    fParent.AttachProc( ParentAnchorChildren );
    fParent.fOldHeight := Parent.ClientHeight;
  end;
end;

procedure TControl.SetAnchorBottom(Value: Boolean);
begin
  fAnchorBottom := Value;
  if Parent <> nil then
  begin
    fParent.AttachProc( ParentAnchorChildren );
    fParent.fOldHeight := Parent.ClientHeight;
  end;
end;

procedure TControl.SetAnchorRight(Value: Boolean);
begin
  fAnchorRight := Value;
  if Parent <> nil then
  begin
    Parent.AttachProc( ParentAnchorChildren );
    Parent.fOldWidth := Parent.ClientWidth;
  end;
end;

function TControl.GetLBTopIndex: Integer;
begin
  Result := Perform(LB_GETTOPINDEX,0,0);
end;

function TControl.LBItemAtPos(X, Y: Integer): Integer;
var
  R: TRect;
  P: TPoint;
  i: Integer;
begin
  P := MakePoint(X,Y);
    for i := LBTopIndex to Count -1 do begin
      Perform(LB_GETITEMRECT, i , Integer(@R));
      if PointInRect(P,R) then begin
        Result := i;
        Exit;
      end;
    end;
  Result := -1;
end;

procedure TControl.SetLBTopIndex(const Value: Integer);
begin
  Perform(LB_SETTOPINDEX,Value,0);
end;

//--------

procedure ScrollToChild(C, SB: PControl);

  function DoScroll(msg, bar, d1, d2, client: integer): boolean;
  var
    i: integer;
  begin
    i:=GetScrollPos(SB.Handle, bar);
    if d1 < SB.Border then
      Dec(i, SB.Border - d1)
    else
      if d2 > client - SB.Border then
        Inc(i, d2 - client + SB.Border)
      else begin
        Result:=False;
        exit;
      end;
    SetScrollPos(SB.Handle, bar, i, True);
    Result:=True;
  end;

var
  R: TRect;
begin
  if C = nil then exit;
  R:=C.BoundsRect;
  R.TopLeft:=SB.Screen2Client(C.Parent.Client2Screen(R.TopLeft));
  R.BottomRight:=SB.Screen2Client(C.Parent.Client2Screen(R.BottomRight));
  if DoScroll(WM_VSCROLL, SB_VERT, R.Top, R.Bottom, SB.ClientHeight) or
     DoScroll(WM_HSCROLL, SB_HORZ, R.Left, R.Right, SB.ClientWidth)
  then
    ScrollChildren(SB);
end;

function WndProcScrollable( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;

  procedure ProcessScroll;
  begin
    NotifyScrollBox(Sender, nil);
    ScrollToChild(Sender.ParentForm.ActiveControl, Sender);
  end;

begin
  Result:=False;
  case Msg.message of
    WM_SIZE:
      PostMessage(Sender.fHandle, CM_SHOW, 0, 0);
    WM_SHOWWINDOW:
      if WordBool(Msg.wParam) then
        PostMessage(Sender.fHandle, CM_SHOW, 0, 0);
    CM_SHOW:
      begin
        ProcessScroll;
        Result:=True;
      end;
  end;
end;

function WndProcScrollToChild( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var
  P: PControl;
begin
  Result:=False;
  if Msg.message = WM_SETFOCUS then begin
    P:=Sender.Parent;
    while (P <> nil) and not Assigned(P.fScrollChildren) do
      P:=P.Parent;
    if P <> nil then
      ScrollToChild(Sender, P);
  end;
end;

procedure NotifyScroller( Self_, Child: PControl );
begin
  if Assigned(Child) then begin
    Child.AttachProc(@WndProcScrollToChild);
    if not Assigned(Child.fNotifyChild) then
      Child.fNotifyChild:=@NotifyScroller;
  end;
end;

procedure TControl.MakeScrollable;

  procedure AttachProcToChildren(P: PControl);
  var
    i: integer;
    C: PControl;
  begin
    for i:=0 to P.ChildCount - 1 do begin
      C:=P.Children[i];
      NotifyScroller(P, C);
      AttachProcToChildren(C);
    end;
  end;
  
begin
  if not IsProcAttached( WndProcScrollBox ) then begin
    fDynHandlers.Insert(0, nil);
    fDynHandlers.Insert(0, @WndProcScrollBox);
  end;
  AttachProc( WndProcScrollable );
  fScrollChildren := ScrollChildren;
  FScrollLineDist[ 0 ] := 16;
  FScrollLineDist[ 1 ] := 16;
  fNotifyChild:=@NotifyScroller;
  AttachProcToChildren(@Self);
end;
{$ENDIF WIN_GDI}

procedure TControl.DisableAlign;
begin
  Include(fAligning, oaAligning);
end;

procedure TControl.EnableAlign;
begin
  fAligning:=[];
  Global_Align(@Self);
end;

{$IFNDEF PAS_VERSION}
//  {$DEFINE ASM_VERSION}
//  {$DEFINE ASM_UNICODE}
{$I KOL_ASM.inc} {$ENDIF ASM_VERSION}
{$IFDEF LIN}
  {$DEFINE implementation} {$I KOL_Linux.inc} {$UNDEF implementation}
{$ENDIF LIN}

{ -- }
{$IFDEF USE_CUSTOMEXTENSIONS}
  {$I CUSTOM_CODE_EXTENSION.inc} // See comments in TControl
{$ENDIF USE_CUSTOMEXTENSIONS}

//[initialization]

{$IFNDEF NOT_UNLOAD_RICHEDITLIB}
{$IFDEF UNLOAD_RICHEDITLIB}
  {$DEFINE INIT_FINIT}
{$ENDIF}
{$ENDIF}

{$IFDEF USE_NAMES}
  {$DEFINE INIT_FINIT}
{$ENDIF}

{$IFDEF GRAPHCTL_XPSTYLES}
  {$DEFINE INIT_FINIT}
{$ENDIF}

{$IFDEF KOL_MMX}
  {$DEFINE INIT_FINIT}
{$ENDIF}

{$IFDEF INIT_FINIT}

initialization
{$IFDEF GRAPHCTL_XPSTYLES}
 CheckThemes;
 if AppTheming then
  InitThemes;
{$ENDIF}

//[finalization]
finalization
{$IFDEF GRAPHCTL_XPSTYLES}
 if AppTheming then
  DeinitThemes;
{$ENDIF}

{$IFNDEF NOT_UNLOAD_RICHEDITLIB}
{$IFDEF UNLOAD_RICHEDITLIB}
  if FRichEditModule <> 0 then
    FreeLibrary( FRichEditModule );
{$ENDIF UNLOAD_RICHEDITLIB}
{$ENDIF}
{$ENDIF INIT_FINIT}

//[END OF KOL.pas]
end.
