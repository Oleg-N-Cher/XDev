///////////////////////////////////////////////////////////////////////
//                         W  I  N  D  O  W  S
///////////////////////////////////////////////////////////////////////

{ -- Set of window-related utility functions. -- }
type
  PGUIThreadInfo = ^TGUIThreadInfo;
  tagGUITHREADINFO = packed record
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

{function GetGUIThreadInfo (idThread: DWORD; var pgui: TGUIThreadinfo): BOOL; stdcall;
         external user32 name 'GetGUIThreadInfo';}

type TGUIThreadInfo_Proc = function( ThreadID: THandle; var GTI: TGUIThreadInfo )
                          : Boolean; stdcall;

var Proc_GetGUIThreadInfo: TGuiThreadInfo_Proc;

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
  if Integer( @Proc_GetGUIThreadInfo ) = -1 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>}
  Result := 0;
  if Wnd = 0 then
    ThreadID := GetCurrentThreadID
  else
    ThreadID := GetWindowThreadProcessID( Wnd, nil );
  if ThreadID = 0 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
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

function WaitFocusedWndChild( Wnd: HWnd ): HWnd;
var T1, T2: Integer;
    W: HWnd;
begin
  Sleep( TimeWaitFocus );
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
    Sleep(TimeWaitFocus);
    Applet.ProcessMessages;
  end;
  Result := Wnd;
end;

function ForceSetForegroundWindow: Integer;
var AllowSetforegroundWindow: function(proc_id: THandle): BOOL; stdcall;
    Lib: THandle;
begin
    Result := -1;
    Lib := LoadLibrary('user32.dll');
    if Lib = 0 then Exit;
    AllowSetforegroundWindow := GetProcAddress(Lib, 'AllowSetForegroundWindow');
    if not Assigned(AllowSetForegroundWindow) then Exit;
    if AllowSetforegroundWindow(GetCurrentProcessId) then
    begin
        SystemParametersInfo($2000 {SPI_GETFOREGROUNDLOCKTIMEOUT},
            0, @ Result, 0);
        SystemParametersInfo($2001 {SPI_SETFOREGROUNDLOCKTIMEOUT},
            0, nil, SPIF_UPDATEINIFILE or SPIF_SENDWININICHANGE);
    end;
end;

function Stroke2Window( Wnd: HWnd; const S: AnsiString ): Boolean;
var P: PAnsiChar;
begin
  Result := False;
  Wnd := WaitFocusedWndChild( Wnd );
  if Wnd = 0 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  P := PAnsiChar( S );
  while P^ <> #0 do
  begin
    PostMessage( Wnd, WM_CHAR, Integer( P^ ), 1 );
    Inc( P );
  end;
  Result := True;
end;

function Stroke2WindowEx( Wnd: HWnd; const S: AnsiString; Wait: Boolean ): Boolean;
var P: PAnsiChar;
    EndChar: AnsiChar;
    MsgDn, MsgUp, SCA: Integer;

    function Compare( Pattern: PAnsiChar ): Boolean;
    var Pos: PAnsiChar;
        C1, C2: AnsiChar;
    begin
      Pos := P;
      while Pattern^ <> #0 do
      begin
        C1 := Pattern^;
        C2 := Pos^;
        if  (C1 >= 'a') and (C1 <= 'z') then
            C1 := AnsiChar( Ord( C1 ) - $20 );
        if  (C2 >= 'a') and (C2 <= 'z') then
            C2 := AnsiChar( Ord( C2 ) - $20 );
        if C1 <> C2 then
        begin
          Result := False; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
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
        e: DWORD;
    begin
      if  (Keycode = VK_LBUTTON) or (KeyCode = VK_RBUTTON)  then
      begin
          if  KeyCode = VK_LBUTTON then
              e := MOUSEEVENTF_LEFTDOWN
          else
              e := MOUSEEVENTF_RIGHTDOWN;
          if Msg = MsgUp then
             e := e + 2;
          mouse_event( e, 0, 0, 0, 0 );
          exit;
      end;
      Wnd := WaitFocusedWndChild( Wnd );
      if Wnd = 0 then
      begin
         asm nop end;
         Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      end;
      lParam := 1;
      if longBool( SCA and 4 ) then
        lParam := $20000001;
      if Msg = MsgUp then
        lParam := lParam or Integer($D0000000);
      PostMessage( Wnd, Msg, KeyCode, lParam );
      if Wait then
      begin
        Applet.ProcessMessages;
        Sleep( 10 );
      end;
    end;

    function CompareSend( Pattern: PAnsiChar; Value2Send: Integer ): Boolean;
    begin
      if Compare( Pattern ) then
      begin
        if  Value2Send = 0 then
        begin
           Sleep(500);
           //Applet.ProcessMessages;
        end
          else
        begin
            Send( MsgDn, Value2Send );
            Send( MsgUp, Value2Send );
        end;
        Result := True;
      end
         else
        Result := False;
    end;

    function ParseKeys( EndChar: AnsiChar ): PAnsiChar;
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
                CompareSend( 'Up', $26 ) or
                CompareSend( 'Sleep', 0 ) or
                CompareSend( 'LClick', VK_LBUTTON ) or
                CompareSend( 'RClick', VK_RBUTTON )) then break;
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
          Stroke2Window( Wnd, AnsiString('') + P^ );
        repeat Inc( P ) until (P^ <> AnsiString(' '));
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

var W: HWnd;
    each_key: Boolean;

    procedure AdjustWnd;
    begin
        W := GetTopWindow( Wnd );
        if  W = 0 then
            W := Wnd;
        W := GetFocusedChild( W );
        if W = 0 then W := Wnd;
        Wnd := W;
    end;
begin
  each_key := FALSE;
  if  Wnd = 0 then
      each_key := TRUE
  else
      AdjustWnd;
  P := PAnsiChar( S );
  while P^ <> #0 do
  begin
    if  each_key then
    begin
        Wnd := GetForegroundWindow;
        AdjustWnd;
    end;
    if not (P^ in [ '[', '{' ]) then
    begin
      Stroke2Window( Wnd, AnsiString('') + P^ ); // TODO: adjust compile options?
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

{$IFDEF _D5orHIGHER}
function SendCommands2Wnd(WndHandle: Hwnd; const s: KOLString): Boolean;
var PiD: DWORD;
    inp: array of TInput;
    i, j, n, L: Integer;
begin
    Result := FALSE;
    GetWindowThreadProcessId( WndHandle, {$IFDEF _D6orHigher} PiD {$ELSE} Pointer(@PiD) {$ENDIF} );
    AttachThreadInput(GetCurrentProcessId, PiD, TRUE);
    TRY
        SetForegroundWindow( WndHandle );
        SetFocus( WndHandle );
        if  GetForegroundWindow <> WndHandle then Exit;
        if  s <> '' then
        begin
            SetLength( inp, Length(s) * 2 );
            j := 0;
            for i := 1 to Length(s) do
            begin
                inp[j].Itype := INPUT_KEYBOARD;
                inp[j].ki.wVk := 0;
                inp[j].ki.wScan := DWORD( s[i] );
                inp[j].ki.dwFlags := 4 { KEYEVENTF_UNICODE };
                inp[j].ki.time := 0;
                inp[j].ki.dwExtraInfo := 0;
                inc(j);
                inp[j].Itype := INPUT_KEYBOARD;
                inp[j].ki.wVk := 0;
                inp[j].ki.wScan := DWORD( s[i] );
                inp[j].ki.dwFlags := KEYEVENTF_KEYUP or 4 { KEYEVENTF_UNICODE };
                inp[j].ki.time := 0;
                inp[j].ki.dwExtraInfo := 0;
                inc(j);
            end;
            for i := 1 to 5 do
            begin
                SetForegroundWindow( WndHandle );
                SetFocus( WndHandle );
                sleep(300);
                L := Length(inp);
                n := SendInput( L, inp[0], SizeOf(TInput) );
                if  n >= Length(inp) then
                begin
                    Result := TRUE;
                    break;
                end;
                if  n > 0 then
                begin
                    move(inp[n], inp[0], Length(inp) - n);
                    SetLength(inp, Length(inp) - n);
                end;
            end;
        end;
    FINALLY
    AttachThreadInput(GetCurrentProcessId, PiD, FALSE);
    END;
end;
{$ENDIF}

type
  PHWnd = ^HWnd;

  TFindWndRec = packed Record
    ThreadID : DWord;
    WndFound : HWnd;
  end;
  PFindWndRec = ^TFindWndRec;

function EnumWindowsProc( Wnd : HWnd; Find : PFindWndRec ) : Boolean;
stdcall;
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

function FindWindowByThreadID( ThreadID : DWORD ) : HWnd;
var Find : TFindWndRec;
begin
  Find.ThreadID := ThreadID;
  Find.WndFound := 0;
  EnumWindows( @EnumWindowsProc, Integer( @Find ) );
  Result := Find.WndFound;
end;

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

function EnumMons(hMon: THandle; hdc: HDC; rc: PRect; L: PList ): BOOL;
         stdcall;
begin
    L.Add(Pointer(rc.Left));
    L.Add(Pointer(rc.Top));
    L.Add(Pointer(rc.Right));
    L.Add(Pointer(rc.Bottom));
    Result := TRUE;
end;

{$IFDEF _D4orHIGHER}
function ListMonitors: TRectsArray;
var EnumDisplayMonitors: function (hdc: HDC; lprcClip: PRect; lpfnEnum: Pointer;
         dwData: PList): LongBool; stdcall;
    Lib: THandle;
    L: PList;
    i, j: Integer;
begin
    Lib := LoadLibrary('user32.dll');
    EnumDisplayMonitors := GetProcAddress(Lib, 'EnumDisplayMonitors');
    if not Assigned(EnumDisplayMonitors) then
    begin
        SetLength(Result, 1);
        Result[0] := MakeRect(0, 0, ScreenWidth, ScreenHeight);
    end
      else
    begin
        L := NewList;
        EnumDisplayMonitors(0, nil, @EnumMons, L);
        SetLength(Result, L.Count div 4);
        j := 0;
        for i := 0 to High(Result) do
        begin
            Result[i] := {MakeRect(Integer(L.Items[j]), Integer(L.Items[j+1]),
                Integer(L.Items[j+2]), Integer(L.Items[j+3]));}
                PRect( @ L.FItems[j] )^;
            inc(j, 4);
        end;
        L.Free;
    end;
end;

function MonitorAt(X, Y: Integer): TRect;
var RR: TRectsArray;
    i: Integer;
begin
    RR := ListMonitors;
    for i := 0 to High(RR) do
        if PtInRect(RR[i], MakePoint(X, Y)) then
        begin
            Result := RR[i];
            Exit;
        end;
    Result := MakeRect(0, 0, ScreenWidth, ScreenHeight);
end;
{$ENDIF}

function GetDesktopRect : TRect;
var W1, W2 : HWnd;
begin
  if  WinVer >= wvVista then
  begin
      Result := GetWorkArea; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  end;
  Result := MakeRect( 0, 0, GetSystemMetrics( SM_CXSCREEN ), GetSystemMetrics( SM_CYSCREEN ) );
  W2 := findwindow('Progman',nil);
  W1 := findwindowex(W2,0,'SHELLDLL_DefView',nil);
  if  W1 = 0 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  GetWindowRect( W1, Result );
end;

function GetWorkArea: TRect;
begin
  SystemParametersInfo( SPI_GETWORKAREA, 0, @ Result, 0 );
end;

function ExecuteWait( const AppPath, CmdLine, DfltDirectory: KOLString;
         Show: DWORD; TimeOut: DWORD; ProcID: PDWORD ): Boolean;
var Flags: DWORD;
    Startup: TStartupInfo;
    ProcInf: TProcessInformation;
    DfltDir: PKOLChar;
    App: KOLString;
begin
  Result := FALSE;
  Flags := CREATE_NEW_CONSOLE;
  if Show = SW_HIDE then
    Flags := Flags or {$IFDEF F_P}$08000000{$ELSE}CREATE_NO_WINDOW{$ENDIF};
  ZeroMemory( @Startup, SizeOf( Startup ) );
  Startup.cb := Sizeof( Startup );
  Startup.wShowWindow := Show;
  Startup.dwFlags := STARTF_USESHOWWINDOW;
  if ProcID <> nil then
    ProcID^ := 0;
  DfltDir := nil;
  if DfltDirectory <> '' then
    DfltDir := PKOLChar( DfltDirectory );
  App := AppPath;
  //if (pos( KOLString(' '), App ) > 0) and (pos( KOLString('"'), App ) <= 0) then
  if (App <> '') and (App[1] <> '"') and (pos( KOLString(' '), App ) > 0) then
      App := '"' + App + '"';
  if (App <> '') and (CmdLine <> '') then
      App := App + ' ';
  if  CreateProcess( nil, PKOLChar( App + CmdLine ), nil,
      nil, FALSE, Flags, nil, DfltDir, Startup, ProcInf ) then
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
          Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
        if not SetStdHandle( STD_OUTPUT_HANDLE, ChildStdOutWr ) then
          Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
        if not DuplicateHandle( GetCurrentProcess, ChildStdOutRd,
           GetCurrentProcess, @ ChildStdOutRdDup, 0, FALSE,
           2 {DUPLICATE_SAME_ACCESS} ) then
          Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
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
          Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
        if not SetStdHandle( STD_INPUT_HANDLE, ChildStdInRd ) then
          Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
        if not DuplicateHandle( GetCurrentProcess, ChildStdInWr,
           GetCurrentProcess, @ ChildStdInWrDup, 0, FALSE,
           2 {DUPLICATE_SAME_ACCESS} ) then
          Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
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

var Cmd: KOLString;
begin
  Result := FALSE;
  Flags := 0;
  if Show = SW_HIDE then
    Flags := Flags or {$IFDEF F_P}$08000000{$ELSE}CREATE_NO_WINDOW{$ENDIF};
  ZeroMemory( @Startup, SizeOf( Startup ) );
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
    Close_Handles; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  end;
  if DfltDirectory <> '' then
    DfltDir := PKOLChar( DfltDirectory );
  Cmd := '"' + AppPath + '" ' + CmdLine;
  if  CreateProcess( nil, PKOLChar( Cmd ), nil, nil, TRUE, Flags, nil,
      DfltDir, Startup, ProcInf ) then
  begin
      if ProcID <> nil then
        ProcID^ := ProcInf.hProcess
      else
        CloseHandle( ProcInf.hProcess );
      CloseHandle( ProcInf.hThread );
      Restore_Saved_StdInOut;
      Result := TRUE;
  end else
  begin
    Restore_Saved_StdInOut;
    Close_Handles;
  end;
end;

function ExecuteConsoleAppIORedirect( const AppPath, CmdLine, DfltDirectory: KOLString;
         Show: DWORD; const InStr: KOLString; var OutStr: KOLString; WaitTimeout: DWORD ): Boolean;
var PipeIn, PipeOutRd, PipeOutWr: THandle;
    ProcID: DWORD;
    BytesCount: DWORD;
    Buffer: Array[ 0..4096 ] of KOLChar; // KOL_ANSI
    BufStr: KOLString;
    PPipeIn: PHandle;
begin
  Result := FALSE;
  PPipeIn := @ PipeIn;
  if InStr = '' then
    PPipeIn := nil;
  PipeOutRd := 0;
  PipeOutWr := 0;
  if not ExecuteIORedirect( AppPath, CmdLine, DfltDirectory, Show, @ ProcID,
                     PPipeIn, @ PipeOutWr, @ PipeOutRd ) then Exit; {>>>>>>>>>>}
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
function OpenProcessToken(ProcessHandle: THandle; DesiredAccess: DWORD;
  var TokenHandle: THandle): BOOL; stdcall;
  external advapi32 name 'OpenProcessToken';
{$ENDIF}

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
    if Machine <> '' then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
    Flags := EWX_SHUTDOWN;
    if Reboot then
      Flags := Flags or EWX_REBOOT;
    if Force then
      Flags := Flags or EWX_FORCE;
    Result := ExitWindowsEx( Flags, 0 ); Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  end;
  OpenProcessToken(GetCurrentProcess(),
                   TOKEN_ADJUST_PRIVILEGES or TOKEN_QUERY,
                   hToken);
  if not LookupPrivilegeValue(PKOLChar(Machine), 'SeShutdownPrivilege',
                              tkp.Privileges[0].Luid) then Exit; {>>>>>>>>>>>>>}
  tkp_prev:=tkp;
  tkp.PrivilegeCount:=1;
  tkp.Privileges[0].Attributes:=SE_PRIVILEGE_ENABLED;
  AdjustTokenPrivileges(hToken, FALSE, tkp, sizeof(tkp), tkp_prev,
dwRetLen);
  if  not LookupPrivilegeValue(PKOLChar(Machine),
                               'SeRemoteShutdownPrivilege',
                               tkp.Privileges[0].Luid) then Exit; {>>>>>>>>>>>>}
  tkp.PrivilegeCount:=1;
  tkp.Privileges[0].Attributes:=SE_PRIVILEGE_ENABLED;
  AdjustTokenPrivileges(hToken, FALSE, tkp, sizeof(tkp), tkp_prev, dwRetLen);
  Result := InitiateSystemShutdown(PKOLChar(Machine),nil, 0, Force, Reboot);
end;

function WindowsLogoff( Force : Boolean ) : Boolean;
var Flags: Integer;
begin
  Flags := 0;
  if Force then
    Flags := EWX_FORCE;
  Result := ExitWindowsEx( Flags, 0 );
end;

var SaveWinVer: Byte = $FF;

{$IFDEF ASM_VERSION}{$ELSE PAS_VERSION} // asm version by MTsv DN  (v 2.90)
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
      if (MajorVersion >= 6) then begin
        if (MinorVersion >= 1) then
          Result := wvSeven
        else
          Result := wvVista;
      end else begin
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
{$ENDIF PAS_VERSION}

function IsWinVer( Ver : TWindowsVersions ) : Boolean;
{* Returns True if Windows version is in given range of values. }
begin
  Result := WinVer in Ver;
end;

procedure TControl.SetAlphaBlend(const Value: Byte);
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
    : Boolean; stdcall;
var
  SetLayeredWindowAttributes: TSetLayeredWindowAttributes;
  User32: THandle;
  dw: DWORD;
begin
  if Value = fAlphaBlend then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  fAlphaBlend := Value;
  User32 := GetModuleHandle( 'User32' );
  SetLayeredWindowAttributes := GetProcAddress( User32,
                             'SetLayeredWindowAttributes' );
  if Assigned( SetLayeredWindowAttributes ) then
  begin
      dw := GetWindowLong( GetWindowHandle, GWL_EXSTYLE );
      if Value < 255 then
      begin
          SetWindowLong( fHandle, GWL_EXSTYLE, dw or WS_EX_LAYERED );
          SetLayeredWindowAttributes( fHandle, 0, Value {and $FF}, LWA_ALPHA);
      end else
          SetWindowLong( fHandle, GWL_EXSTYLE, dw and not WS_EX_LAYERED );
  end;
end;

{$ENDIF WIN_GDI}
function TControl.SetPosition( X, Y: Integer ): PControl;
begin
  Left := X;
  Top := Y;
  Result := @Self;
end;
{$IFDEF WIN_GDI}

function NewColorDialog( FullOpen: TColorCustomOption ): PColorDialog;
var I: Integer;
begin
  New( Result, Create );
  {$IFDEF DEBUG_OBJKIND}
  Result.fObjKind := 'TColorDialog';
  {$ENDIF}
  Result.ColorCustomOption := FullOpen;
  for I := 1 to 16 do
    Result.CustomColors[ I ] := clWhite;
end;

{ TColorDialog }

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
  Result := ChooseColor( CD );
  if Result then
    Color := CD.rgbResult;
end;

procedure TControl.SetMaxProgress(const Index, Value: Integer);
begin
  // ignore index, and set Value via PBM_SETRANGE32:     ()
  Perform( PBM_SETRANGE32, 0, Value );
end;

procedure TControl.SetDroppedWidth(const Value: Integer);
begin
  DF.fDroppedWidth := Value;
  Perform( CB_SETDROPPEDWIDTH, Value, 0 );
end;

function TControl.LVGetItemState(Idx: Integer): TListViewItemState;
type
  PListViewItemState = ^TListViewItemState;
var I: Byte;
begin
  I := Perform( LVM_GETITEMSTATE, Idx,
                LVIS_CUT or LVIS_DROPHILITED or LVIS_FOCUSED or LVIS_SELECTED );
  Result := PListViewItemState( @ I )^;
end;

procedure TControl.LVSetItemState(Idx: Integer; const Value: TListViewItemState);
var Data: TLVItem;
begin
  Data.stateMask := LVIS_FOCUSED or LVIS_SELECTED or LVIS_CUT or LVIS_DROPHILITED;
  Data.state     := PByte( @ Value )^;
  Perform( LVM_SETITEMSTATE, Idx, Integer( @Data ) );
end;

procedure TControl.LVSelectAll;
begin
  LVSetItemState( -1, [ lvisSelect ] );
end;

function TControl.LVItemInsert(Idx: Integer; const aText: KOLString): Integer;
var LVI: TLVItem;
begin
  LVI.mask := LVIF_TEXT or LVIF_DI_SETITEM;
  LVI.iItem := Idx;
  LVI.iSubItem := 0;
  LVI.pszText := PKOL_Char( aText );
  Result := Perform( LVM_INSERTITEM, 0, Integer( @LVI ) );
end;

function TControl.LVItemAdd(const aText: KOLString): Integer;
begin
  Result := LVItemInsert( Count, aText );
end;

function TControl.LVGetSttImgIdx(Idx: Integer): Integer;
begin
  Result := Perform( LVM_GETITEMSTATE, Idx, LVIS_STATEIMAGEMASK ) shr 12;
end;

procedure TControl.LVSetSttImgIdx(Idx: Integer; const Value: Integer);
var LVI: TLVItem;
begin
  LVI.stateMask := LVIS_STATEIMAGEMASK;
  LVI.state := Value shl 12;
  Perform( LVM_SETITEMSTATE, Idx, Integer( @LVI ) );
end;

function TControl.LVGetOvlImgIdx(Idx: Integer): Integer;
begin
  Result := Perform( LVM_GETITEMSTATE, Idx, LVIS_OVERLAYMASK ) shr 8;
end;

procedure TControl.LVSetOvlImgIdx(Idx: Integer; const Value: Integer);
var LVI: TLVItem;
begin
  LVI.stateMask := LVIS_OVERLAYMASK;
  LVI.state := Value shl 8;
  Perform( LVM_SETITEMSTATE, Idx, Integer( @LVI ) );
end;

function TControl.LVGetItemData(Idx: Integer): DWORD;
var LVI: TLVItem;
begin
  LVI.mask := LVIF_PARAM;
  LVI.iItem := Idx;
  LVI.iSubItem := 0;
  Perform( LVM_GETITEM, 0, Integer( @LVI ) );
  Result := LVI.lParam;
end;

procedure TControl.LVSetItemData(Idx: Integer; const Value: DWORD);
var LVI: TLVItem;
begin
  LVI.mask := LVIF_PARAM;
  LVI.iItem := Idx;
  LVI.iSubItem := 0;
  LVI.lParam := Value;
  Perform( LVM_SETITEM, 0, Integer( @LVI ) );
end;

function TControl.LVGetItemIndent(Idx: Integer): Integer;
var LI: TLVItem;
begin
  LI.mask := LVIF_INDENT;
  LI.iItem := Idx;
  LI.iSubItem := 0;
  Perform( LVM_GETITEM, 0, Integer( @LI ) );
  Result := LI.iIndent;
end;

procedure TControl.LVSetItemIndent(Idx: Integer; const Value: Integer);
var LI: TLVItem;
begin
  LI.mask := LVIF_INDENT or LVIF_DI_SETITEM;
  LI.iItem := Idx;
  LI.iSubItem := 0;
  LI.iIndent := Value;
  Perform( LVM_SETITEM, 0, Integer( @LI ) );
end;

type
  TNMLISTVIEW = packed Record
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
      if Hdr.code = LVN_DELETEITEM then
      begin
        {$IFDEF NIL_EVENTS}
        if  Assigned( Sender.EV.fOnDeleteLVItem ) then
        {$ENDIF}
            Sender.EV.fOnDeleteLVItem( Sender, LV.iItem );
        Result := TRUE;
      end
        else
      if Hdr.code = LVN_DELETEALLITEMS then
      begin
          if Assigned( Sender.DF.fOnDeleteAllLVItems ) then
          begin
              Sender.DF.fOnDeleteAllLVItems( Sender );
              Rslt := 0;
              if  Assigned( Sender.EV.fOnDeleteLVItem ) then
                  Rslt := 1;
          end;
          Result := TRUE;
      end;
    end;
  end;
end;

procedure TControl.SetOnDeleteAllLVItems(const Value: TOnEvent);
begin
  DF.fOnDeleteAllLVItems := Value;
  AttachProc( @WndProc_LVDeleteItem );
end;

procedure TControl.SetOnDeleteLVItem(const Value: TOnDeleteLVItem);
begin
    {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
    .fOnDeleteLVItem := Value;
    AttachProc( @WndProc_LVDeleteItem );
end;

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
      if (Hdr.code = LVN_GETDISPINFO)
         {$IFDEF UNICODE_CTRLS}
         or (Hdr.code = LVN_GETDISPINFOW)
         {$ENDIF UNICODE_CTRLS}
      then
      begin
        DI := Pointer( Hdr );
        LV := Sender;
        if LV <> nil then
        begin
          Txt := '';
          DI.item.iImage := -1;
          DI.item.state := 0;
          if  {$IFDEF NIL_EVENTS} Assigned( LV.EV.fOnLVData ) and {$ENDIF}
              (DI.item.iItem >= 0) then
          begin
              Store := FALSE;
              LV.EV.fOnLVData( LV, DI.item.iItem, DI.item.iSubItem, Txt,
                               DI.item.iImage, DWORD( DI.item.state ), Store );
              LV.fCaption := Txt;
              DI.item.pszText := PKOL_Char( PKOLChar( LV.fCaption ) );
              if  Store then
                  DI.item.mask := DI.item.mask or LVIF_DI_SETITEM;
            end;
            Result := TRUE;
        end;
      end;
    end;
  end;
end;

procedure TControl.SetOnLVData(const Value: TOnLVData);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .fOnLVData := Value;
  AttachProc( @WndProc_LVData );
  Perform( LVM_SETCALLBACKMASK, LVIS_OVERLAYMASK or LVIS_STATEIMAGEMASK, 0 );
end;

{$IFDEF ENABLE_DEPRECATED}
{$DEFINE implementation} {$I KOL_deprecated.inc} {$UNDEF implementation}
{$ENDIF DISABLE_DEPRECATED}

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
    if (NMHdr.code = NM_CUSTOMDRAW)
    {$IFDEF NIL_EVENTS} and Assigned( Sender.EV.fOnLVCustomDraw ) {$ENDIF}
    then
    begin
      NMCustDraw := Pointer( Msg.lParam );
      ItemIdx := -1;
      SubItemIdx := -1;
      if  LongBool( NMCustDraw.nmcd.dwDrawStage and CDDS_ITEM ) then
          ItemIdx := NMCustDraw.nmcd.dwItemSpec;
      if  LongBool( NMCustDraw.nmcd.dwDrawStage and CDDS_SUBITEM ) then
          SubItemIdx := NMCustDraw.iSubItem;
      ItemState := [ ];
      if  ItemIdx >= 0 then
      begin
          S := Sender.LVItemState[ ItemIdx ];
          if  lvisFocus in S then
              include( ItemState, odsFocused );
          if  lvisSelect in S then
              include( ItemState, odsSelected );
          if  lvisBlend in S then
              include( ItemState, odsGrayed );
          if  lvisHighlight in S then
              include( ItemState, odsMarked );
      end;
      Rslt := Sender.EV.FOnLVCustomDraw( Sender, {Sender.fPaintDC} NMCustDraw.nmcd.hdc,
           NMCustDraw.nmcd.dwDrawStage, ItemIdx, SubItemIdx, NMCustDraw.nmcd.rc,
           ItemState, TColor( NMCustDraw.clrText ), TColor( NMCustDraw.clrTextBk ) );

      Result := TRUE;
    end;
  end;
end;

procedure TControl.SetOnLVCustomDraw(const Value: TOnLVCustomDraw);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .fOnLVCustomDraw := Value;
  AttachProc( @WndProc_LVCustomDraw );
end;

function WndProc_LVSubitemDraw( Sender: PControl; var Msg: TMsg;
                               var Rslt: Integer ): Boolean;
var NMCustDraw: PNMLVCustomDraw;
    NMHdr: PNMHdr;
    ItemIdx, SubItemIdx: Integer;
    S: TListViewItemState;
    ItemState: TDrawState;
    was_clrText, was_clrTextBk: DWORD;
    R: TRect;
begin
  Result := FALSE;
  if Msg.message = WM_NOTIFY then
  begin
    NMHdr := Pointer( Msg.lParam );
    if (NMHdr.code = NM_CUSTOMDRAW)
    {$IFDEF NIL_EVENTS} and Assigned( Sender.EV.fOnLVCustomDraw ) {$ENDIF}
    then
    begin
      NMCustDraw := Pointer( Msg.lParam );
      CASE NMCustDraw.nmcd.dwDrawStage OF
      CDDS_PREPAINT:
          begin
              Rslt := CDRF_NOTIFYITEMDRAW;
              Result := TRUE;
              Exit;
          end;
      CDDS_ITEMPREPAINT:
          begin
              Rslt := CDRF_NOTIFYITEMDRAW or CDRF_DODEFAULT;
          end;
      END;
      ItemIdx := NMCustDraw.nmcd.dwItemSpec;
      ItemState := [ ];
      if  ItemIdx >= 0 then
      begin
          S := Sender.LVItemState[ ItemIdx ];
          if  lvisFocus in S then
              include( ItemState, odsFocused );
          if  lvisSelect in S then
              include( ItemState, odsSelected );
          if  lvisBlend in S then
              include( ItemState, odsGrayed );
          if  lvisHighlight in S then
              include( ItemState, odsMarked );
      end;
      was_clrText := NMCustDraw.clrText;
      was_clrTextBk := NMCustDraw.clrTextBk;
      for SubItemIdx := 0 to Sender.LVColCount-1 do
      begin
          R := Sender.LVSubItemRect( ItemIdx, SubItemIdx );
          if   0 = Sender.EV.FOnLVCustomDraw( Sender, NMCustDraw.nmcd.hdc, 0,
               ItemIdx, SubItemIdx, R,
               ItemState, TColor( NMCustDraw.clrText ), TColor( NMCustDraw.clrTextBk ) )
             then
          begin
              Rslt := CDRF_DODEFAULT; {вернули FALSE - не хотят рисовать, тогда по умолчанию}
              break;
          end
             else
          if  (was_clrText <> NMCustDraw.clrText) or
              (was_clrTextBk <> NMCustDraw.clrTextBk) then
          begin
              Rslt := CDRF_NEWFONT; {поменяли цвет текста или фона - рисование по умолчанию, но с новыми цветами}
              break;
          end;
      end;
      Result := TRUE;
    end;
  end;
end;

procedure TControl.SetOnLVSubitemDraw(const Value: TOnLVSubitemDraw);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .fOnLVCustomDraw := TOnLVCustomDraw( Value );
  AttachProc( @WndProc_LVSubitemDraw );
end;

function CompareLVItems( Idx1, Idx2: Integer; ListView: PControl ): Integer; stdcall;
begin
  {$IFDEF NIL_EVENTS}
  if  Assigned( ListView.EV.fOnCompareLVItems ) then
  {$ENDIF}
      Result := ListView.EV.fOnCompareLVItems( ListView, Idx1, Idx2 )
  {$IFDEF NIL_EVENTS}
  else
      Result := 0
  {$ENDIF} ;
end;

procedure TControl.LVSort;
begin
  Perform( LVM_SORTITEMSEX, Integer(@Self), Integer(@CompareLVItems) );
end;

function CompareLVItemsData( D1, D2: DWORD; ListView: PControl ): Integer; stdcall;
begin
  {$IFDEF NIL_EVENTS}
  if  Assigned( ListView.EV.fOnCompareLVItems ) then
  {$ENDIF}
      Result := ListView.EV.fOnCompareLVItems( ListView, D1, D2 )
  {$IFDEF NIL_EVENTS}
  else
      Result := 0
  {$ENDIF} ;
end;

procedure TControl.LVSortData;
begin
  Perform( LVM_SORTITEMS, Integer( @Self ), Integer( @CompareLVItemsData ) );
end;

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
      if Hdr.code = LVN_COLUMNCLICK then
      begin
        {$IFDEF NIL_EVENTS}
        if  Assigned( Sender.EV.fOnColumnClick ) then
        {$ENDIF}
            Sender.EV.fOnColumnClick( Sender, LV.iSubItem );
        Result := TRUE;
      end;
    end;
  end;
end;

procedure TControl.SetOnColumnClick(const Value: TOnLVColumnClick);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .fOnColumnClick := Value;
  AttachProc( @WndProc_LVColumnClick );
end;

function WndProc_LVStateChange( Sender: PControl; var Msg: TMsg; var R: Integer ): Boolean;
var NMOD: PNMLVODStateChange;
    NMLV: PNMLISTVIEW;
begin
  if Msg.message = WM_NOTIFY then
  begin
    NMOD := Pointer( Msg.lParam );
    NMLV := Pointer( Msg.lParam );
    if NMOD.hdr.code = LVN_ODSTATECHANGED then
    begin
      {$IFDEF NIL_EVENTS}
      if  Assigned( Sender.EV.fOnLVStateChange ) then
      {$ENDIF}
          Sender.EV.fOnLVStateChange( Sender, NMOD.iFrom, NMOD.iTo,
                                      NMOD.uOldState, NMOD.uNewState );
    end
      else
    if NMLV.hdr.code = LVN_ITEMCHANGED then
    begin
      {$IFDEF NIL_EVENTS}
      if  Assigned( Sender.EV.fOnLVStateChange ) then
      {$ENDIF}
          Sender.EV.fOnLVStateChange( Sender, NMLV.iItem, NMLV.iItem,
                                      NMLV.uOldState, NMLV.uNewState );
    end;
  end;
  Result := FALSE;
end;

procedure TControl.SetOnLVStateChange(const Value: TOnLVStateChange);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .FOnLVStateChange := Value;
  AttachProc( WndProc_LVStateChange );
end;

function CompareLVColumns( Idx1, Idx2: Integer; Sender: PControl ): Integer; stdcall;
var S1, S2: KOLString;
begin
  //--- changed by Mike Gerasimov:
  S1 := Sender.LVItems[ Idx1, Sender.DF.fColumn ];
  S2 := Sender.LVItems[ Idx2, Sender.DF.fColumn ];
  If  lvoSortAscending in Sender.DF.fLVOptions Then
      Result := AnsiCompareStrNoCase( S1, S2 )
  Else
      If  lvoSortDescending in Sender.DF.fLVOptions Then
          Result := AnsiCompareStrNoCase( S2, S1 )
      Else
          Result:=0;
end;

procedure TControl.LVSortColumn(Idx: Integer);
begin
  DF.fColumn := Idx;
  Perform( LVM_SORTITEMSEX, Integer(@Self), Integer(@CompareLVColumns) );
end;

function TControl.LVIndexOf(const S: KOLString): Integer;
begin
  Result := LVSearchFor( S, -1, FALSE );
end;

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
            H := P.Perform(WM_MEASUREITEM,0,0);
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

function WndProcLVMeasureItem2( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
begin
  Result := FALSE;
  if (Msg.message = WM_MEASUREITEM) and (Msg.wParam = 0) then begin
    Rslt := Sender.DF.fLVItemHeight;
    Result := TRUE;
  end;

end;

function TControl.SetLVItemHeight(Value: Integer): PControl;
begin
  Set_LVItemHeight( Value );
  Result := @ Self;
end;

procedure TControl.Set_LVItemHeight(Value: Integer);
begin
  if  DF.fLVItemHeight <> Value then
  begin
      if  DF.fLVItemHeight = 0 then
      begin
          Parent.AttachProc(WndProcLVMeasureItem);
          AttachProc(WndProcLVMeasureItem2);
      end;
      DF.fLVItemHeight := Value;
  end;
end;

function TControl.IndexOf(const S: KOLString): Integer;
begin
  Result := SearchFor( S, -1, FALSE );
end;

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

{$UNDEF ASM_LOCAL}
{$IFDEF ASM_VERSION}
        {$IFDEF USE_FLAGS}
        {$IFDEF EVENTS_DYNAMIC}
        //{$IFNDEF NIL_EVENTS}
        {$IFNDEF CLICK_DEFAULT_CANCEL_BTN_DIRECTLY}
                                                   {$DEFINE ASM_LOCAL}
        {$ENDIF CLICK_DEFAULT_CANCEL_BTN_DIRECTLY}
        //{$ENDIF NIL_EVENTS}
        {$ENDIF EVENTS_DYNAMIC}
        {$ENDIF USE_FLAGS}
{$ENDIF PAS_VERSION}

{$IFDEF ASM_LOCAL}
function TControl.DefaultBtnProc(var Msg: TMsg; var Rslt: Integer): Boolean;
asm
         PUSH  EBX
         PUSH  ESI
         PUSH  EDI
         PUSH  ECX  // save @Rslt
         PUSH  EDX  // save Msg
         MOV   EBX, EDX // EBX = @ Msg
         XCHG  ESI, EAX // ESI = @ Self
         MOV   EAX, [ESI].TControl.EV
         MOV   EDI, [EAX].TEvents.fOldOnMessage.TMethod.Code
         MOV   EAX, [EAX].TEvents.fOldOnMessage.TMethod.Data
         {$IFDEF NIL_EVENTS}
         TEST  EDI, EDI
         JZ    @@cont
         {$ELSE}
         {$ENDIF}
         CALL  EDI
         TEST  AL, AL
         JNZ   @@exit1
@@cont:
         CMP   [AppletTerminated], AL
         JNZ   @@exit
         MOV   AX, word ptr [EBX].TMsg.message
         //SUB   AX, WM_KEYDOWN
         DEC   AH
         CMP   AX, WM_CHAR - WM_KEYDOWN
         JA    @@exit
         XCHG  EAX, EBX
         MOV   EBX, [EAX].TMsg.message
         SHL   EBX, 16
         MOV   BL, byte ptr [EAX].TMsg.wParam
         CMP   BL, 13
         JE    @@ok1327
         CMP   BL, 27
         JNE   @@exit
@@ok1327:
         MOV   EDI, [Applet]
         TEST  [EDI].TControl.fFlagsG3, 1 shl G3_IsForm
         JNZ   @@1
         MOV   EDI, [EDI].DF.fCurrentControl
@@1:
         TEST  EDI, EDI
         JZ    @@exit

         PUSH  EBP
         XOR   EBP, EBP // Btn := nil;

         MOV   BH, 13
         MOV   EDX, offset[DFLT_BTN]
@@findButton:
         MOV   EAX, EDI
         CALL  TControl.Get_Prop_Int
         TEST  EAX, EAX
         JZ    @@notFromProp
         CMP   BL, BH
         JNZ   @@notFromProp
         MOV   EBP, EAX
         CALL  TControl.GetToBeVisible
         TEST  AL, AL
         JZ    @@notFromProp
         MOV   EAX, EBP
         CALL  TControl.GetEnabled
         TEST  AL, AL
         JZ    @@notFromProp
         CMP   BL, 13
         JNZ   @@yesFound
         MOV   ECX, [EDI].TControl.DF.fCurrentControl
         JECXZ @@yesFound
         TEST  word ptr [ECX].TControl.fFlagsG5, (1 shl G6_CancelBtn) shl 8 or(1 shl G5_IgnoreDefault)
         JZ    @@yesFound
         CMP   EBP, ECX
         JZ    @@yesFound
@@notFromProp:
         XOR   EBP, EBP
         CMP   BL, 13
         JNZ   @@notFound
         MOV   AL, [EDI].TControl.DF.fAllBtnReturnClick
         OR    AL, [ESI].TControl.DF.fAllBtnReturnClick
         JZ    @@notFound
         MOV   ECX, [EDI].DF.fCurrentControl
         JECXZ @@notFound
         MOV   AL, [ECX].TControl.fFlagsG5
         AND   AL, (1 shl G5_IsButton) or (1 shl G5_IsGroupbox)
         CMP   AL, (1 shl G5_IsButton)
         JNZ   @@notFound
         MOV   EBP, EAX
         CALL  TControl.GetToBeVisible
         TEST  AL, AL
         JNZ   @@yesFound
@@notFound:
         XOR   EBP, EBP
@@yesFound:
         CMP   BH, 13
         MOV   BH, 27
         MOV   EDX, offset[CNCL_BTN]
         JNZ   @@check_Found
         TEST  EBP, EBP
         JZ    @@findButton
@@check_Found:
         MOV   ECX, EBP
         POP   EBP
         JECXZ @@exit

         MOV   ESI, ECX
         XCHG  EAX, ECX

         SHR   EBX, 16
         CMP   BX, WM_KEYDOWN
         JNZ   @@doclick

         MOV   DL, 1
         CALL  TControl.SetFocused

@@doclick:
         POP   EDI
         POP   EBX

         PUSH  [EDI].TMsg.lParam
         PUSH  32
         PUSH  [EDI].TMsg.message
         PUSH  ESI
         CALL  TControl.Perform

         XOR   EAX, EAX
         AND   [EDI].TMsg.wParam, EAX
         AND   [EBX], EAX
         INC   EAX
         PUSH  EAX
         PUSH  EAX
         JMP   @@exit1

@@exit:  XOR   EAX, EAX
@@exit1:
         POP   EDX
         POP   ECX
         POP   EDI
         POP   ESI
         POP   EBX
end;
{$ELSE PAS_VERSION}
function TControl.DefaultBtnProc(var Msg: TMsg;
  var Rslt: Integer): Boolean;
var Btn: PControl;
    F: PControl;

    procedure FindBtn( key: Word; s: PKOLChar; for_dflt: Boolean );
    var Ctl: PControl;
    begin
      Ctl := Pointer( F.PropInt[ s ] );
      if  (Msg.wParam = key) and
          (Ctl <> nil) and
          Ctl.ToBeVisible and
          Ctl.Enabled and
          ( not for_dflt or
            for_dflt and
          ( (F.DF.fCurrentControl=nil) or
            ({$IFDEF USE_FLAGS} not(G6_CancelBtn in F.DF.fCurrentControl.fFlagsG6)
            {$ELSE} not F.DF.fCurrentControl.fCancelBtn {$ENDIF} and
            {$IFDEF USE_FLAGS} not(G5_IgnoreDefault in F.DF.fCurrentControl.fFlagsG5)
            {$ELSE} not F.DF.fCurrentControl.fIgnoreDefault {$ENDIF})
            or (F.DF.fCurrentControl = Ctl)
          ) ) then
          Btn := Ctl
      else
      if  for_dflt
      AND (Msg.wParam = VK_RETURN) and
          (F.DF.fAllBtnReturnClick or DF.fAllBtnReturnClick)
      and (F.ActiveControl <> nil) and
          (F.ActiveControl.ToBeVisible) and
          {$IFDEF USE_FLAGS} (G5_IsButton in F.ActiveControl.fFlagsG5)
                             and not(G5_IsGroupbox in F.ActiveControl.fFlagsG5)
          {$ELSE} (F.ActiveControl.IsButton and not F.ActiveControl.fIsGroupbox) {$ENDIF}
      {and (F.ActiveControl.Count = 0)} then
          Btn := F.ActiveControl;
    end;
begin
  {$IFDEF NIL_EVENTS}
  if  Assigned( EV.fOldOnMessage ) then
  {$ENDIF}
  begin
      Result := EV.fOldOnMessage( Msg, Rslt );
      if Result then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  end;
  Result := FALSE;
  if AppletTerminated then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  F := Applet;
  if  {$IFDEF USE_FLAGS} not(G3_IsForm in F.fFlagsG3)
      {$ELSE} not F.fIsForm {$ENDIF} then
      F := F.DF.fCurrentControl;
  if  F = nil then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  Btn := nil;
  if  //((Msg.message = WM_KEYDOWN) or (Msg.message = WM_KEYUP) or (Msg.message = WM_CHAR)) and
      ((Msg.message >= WM_KEYDOWN) and (Msg.message <= WM_CHAR)) and
      ((Msg.wParam = VK_RETURN) or (Msg.wParam = VK_ESCAPE)) then
  begin
      FindBtn( VK_RETURN, @DFLT_BTN, TRUE );
      FindBtn( VK_ESCAPE, @CNCL_BTN, FALSE );
      if Btn <> nil then
      begin
        if Msg.message = WM_KEYDOWN then
        begin
          {$IFDEF CLICK_DEFAULT_CANCEL_BTN_DIRECTLY}
          {$IFDEF NIL_EVENTS}
          if  Assigned( Btn.EV.fOnClick ) then
          {$ENDIF}
              Btn.EV.fOnClick( Btn );
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
        Rslt := 0; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      end
  end;
  Result := FALSE;
end;
{$ENDIF PAS_VERSION}

{$UNDEF ASM_LOCAL}
{$IFDEF ASM_VERSION}
        {$IFDEF USE_FLAGS}
        {$IFNDEF DEFAULT_CANCEL_BTN_EXCLUSIVE}
        {$IFDEF EVENTS_DYNAMIC}
                {$DEFINE ASM_LOCAL}
        {$ENDIF EVENTS_DYNAMIC}
        {$ENDIF  DEFAULT_CANCEL_BTN_EXCLUSIVE}
        {$ENDIF USE_FLAGS}
{$ENDIF PAS_VERSION}

{$IFDEF ASM_LOCAL}
procedure TControl.SetDefaultBtn(const Index: Integer;
  const Value: Boolean);
asm
        PUSH  EBX
        PUSH  EDI
        PUSH  ESI
        MOV   BL, DL // index
        MOV   BH, CL // value
        MOV   ESI, EAX // @Self
        ADD   ECX, ECX // DL = 2
        CMP   BL, 13
        JZ    @@1
        CMP   BL, 27
        JNZ   @@2
        ADD   ECX, ECX // DL := Index = 13 ? 2 : 4
@@1:    CMP   BH, 0
        JNZ   @@set_flag
        NOT   CL
        AND   [ESI].fFlagsG6, CL
        MOV   CL, 0
@@set_flag:
        OR    [ESI].fFlagsG6, CL
@@2:
        CMP   [Applet], 0
        JZ    @@exit
        CALL  TControl.ParentForm
        TEST  EAX, EAX
        JZ    @@exit

        XCHG  EDI, EAX // EDI = ParentForm
        MOV   AL, BH
        SHR   EAX, 1
        SBB   ECX, ECX
        AND   ECX, ESI // ECX = Value ? @ Self : 0
        MOV   EDX, offset[DFLT_BTN]
        CMP   BL, 13
        JZ    @@3
        MOV   EDX, offset[CNCL_BTN]
@@3:
        XCHG  EAX, EDI
        CALL  TControl.Set_Prop_Int

        {$IFnDEF NO_DEFAULT_BUTTON_BOLD}
        XCHG  EAX, ESI //---- больше @Self не нужен
        MOV   EDX, [EAX].TControl.fStyle
        AND   DL, not BS_DEFPUSHBUTTON //---- BS_DEFPUSHBUTTON = 1, BH = Value = 1 : 0
        OR    DL, BH
        CALL  TControl.SetStyle
        {$ENDIF}

        TEST  BH, BH
        MOV   ESI, [Applet] // ESI = Applet
        MOV   EBX, [ESI].TControl.EV
        JZ    @@notValue

        MOV   EDX, [EBX].TEvents.fOnMessage.TMethod.Code
        CMP   EDX, offset[TControl.DefaultBtnProc]
        JZ    @@setDefaultBtnProc

        MOV   [EBX].TEvents.fOldOnMessage.TMethod.Code, EDX
        MOV   EDX, [EBX].TEvents.fOnMessage.TMethod.Data
        MOV   [EBX].TEvents.fOldOnMessage.TMethod.Data, EDX

@@setDefaultBtnProc:
        MOV   [EBX].TEvents.fOnMessage.TMethod.Code, offset[TControl.DefaultBtnProc]
        MOV   [EBX].TEvents.fOnMessage.TMethod.Data, ESI
        JMP   @@exit

@@notValue:
        LEA   ESI, [EBX].TEvents.fOldOnMessage
        LEA   EDI, [EBX].TEvents.fOnMessage
        MOVSD
        MOVSD
        MOV   [EBX].TEvents.fOldOnMessage.TMethod.Code, offset[DummyProc123_0]

@@exit: POP   ESI
        POP   EDI
        POP   EBX
end;
{$ELSE  notASM_VERSION}
procedure TControl.SetDefaultBtn(const Index: Integer;
  const Value: Boolean);
var F, C: PControl;
begin
  if Index = 13 then
  begin
      {$IFDEF USE_FLAGS} if Value
              then include( fFlagsG6, G6_DefaultBtn )
              else exclude( fFlagsG6, G6_DefaultBtn );
      {$ELSE} fDefaultBtn := Value; {$ENDIF}
      {$IFDEF DEFAULT_CANCEL_BTN_EXCLUSIVE}
          {$IFDEF USE_FLAGS} Exclude( fFlagsG6, G6_CancelBtn );
          {$ELSE} fCancelBtn := FALSE; {$ENDIF}
      {$ENDIF}
  end else
  if  Index = 27 then // this check is necessary still could be Index = 0 to reset both !
  begin
      {$IFDEF USE_FLAGS} if Value
              then include( fFlagsG6, G6_CancelBtn )
              else exclude( fFlagsG6, G6_CancelBtn );
      {$ELSE} fCancelBtn := Value; {$ENDIF}

      {$IFDEF DEFAULT_CANCEL_BTN_EXCLUSIVE}
          {$IFDEF USE_FLAGS} Exclude( fFlagsG6, G6_DefaultBtn );
          {$ELSE} fDefaultBtn := FALSE; {$ENDIF}
      {$ENDIF}
  end;
  if Applet = nil then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  F := ParentForm;
  if F <> nil then
  begin
      C := nil;
      if  Value then C := @ Self;
      if  Index = 13 then
      begin
          F.PropInt[ @DFLT_BTN ] := Integer( C );
          {$IFDEF NO_DEFAULT_BUTTON_BOLD}
          {$ELSE}
          if  Value then
              Style := fStyle.Value or BS_DEFPUSHBUTTON
          else
              Style := fStyle.Value and not BS_DEFPUSHBUTTON;
          {$ENDIF}
      end
      else if Index = 27 then
          F.PropInt[ @CNCL_BTN ] := Integer( C );

      if  Value then
      begin
          if  @ Applet.EV.fOnMessage <> @ TControl.DefaultBtnProc  then
              Applet.EV.fOldOnMessage := Applet.EV.fOnMessage; // fixed by YS
          Applet.EV.fOnMessage := Applet.DefaultBtnProc;
      end else
      begin
          Applet.EV.fOnMessage := Applet.EV.fOldOnMessage;
          Applet.EV.fOldOnMessage :=
              {$IFDEF SAFEST_CODE} TOnMessage( MakeMethod( nil, @ DummyProc123_0 ) )
              {$ELSE}              nil {$ENDIF};
      end;
  end;
end;
{$ENDIF PAS_VERSION}

function TControl.GetDefaultBtn(const Index: Integer): Boolean;
begin
  CASE Index OF
  13 : Result := {$IFDEF USE_FLAGS} G6_DefaultBtn in fFlagsG6
                 {$ELSE} fDefaultBtn {$ENDIF};
  else Result := {$IFDEF USE_FLAGS} G6_CancelBtn in fFlagsG6
                 {$ELSE} fCancelBtn {$ENDIF};
  END;
end;

function TControl.AllBtnReturnClick: PControl;
{$IFDEF ALL_BUTTONS_RESPOND_TO_ENTER}
begin
  // nothing: already implemented in WndProcBtnReturnClick
  Result := @ Self;
end;
{$ELSE}
var F: PControl;
begin
  {$IFDEF SAFE_CODE}
  if  {$IFDEF USE_FLAGS} [G3_IsForm, G3_IsApplet] * fFlagsG3 <> []
      {$ELSE} fIsForm or fIsApplet {$ENDIF} then
  {$ENDIF}
  begin
      SetDefaultBtn( 0, TRUE );
      F := ParentForm;
      if  F <> nil then
          F.DF.fAllBtnReturnClick := TRUE;
  end;
  Result := @ Self;
end;
{$ENDIF}

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
    {$IFDEF NIL_EVENTS}
    if  Assigned( Sender.EV.fOnDrawItem ) then
    {$ENDIF}
    begin
        if Sender.EV.fOnDrawItem( Sender, DI.hDC, DI.rcItem, DI.itemID,
                           PDrawAction( @ DI.itemAction )^,
                           PDrawState( @ DI.itemState )^ )
        then Rslt := 1
        else Rslt := 0;
        Result := TRUE;
    end
    {$IFDEF NIL_EVENTS}
    else Rslt := 0
    {$ENDIF}
    ;
  end;
end;

procedure TControl.SetOnDrawItem(const Value: TOnDrawItem);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .fOnDrawItem := Value;
  if  Parent <> nil then
      Parent.AttachProc( @WndProc_DrawItem );
  AttachProc( @WndProc_CNDrawItem );
end;

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
        {$IFDEF NIL_EVENTS}
        if  Assigned( Control.EV.fOnMeasureItem ) then
        {$ENDIF}
        begin
            MI.itemHeight := Control.EV.fOnMeasureItem( Control, MI.itemID );
            if  MI.itemHeight > 0 then
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

procedure TControl.SetOnMeasureItem(const Value: TOnMeasureItem);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .fOnMeasureItem := Value;
  if Parent <> nil then
    Parent.AttachProc( @WndProc_MeasureItem );
end;

function TControl.GetItemData(Idx: Integer): DWORD;
begin
  Result := 0;
  if fCommandActions.aGetItemData <> 0 then
    Result := Perform( fCommandActions.aGetItemData, Idx, 0 );
end;

procedure TControl.SetItemData(Idx: Integer; const Value: DWORD);
begin
  if fCommandActions.aSetItemData <> 0 then
    Perform( fCommandActions.aSetItemData, Idx, Value );
end;

function TControl.GetLVCurItem: Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, -1, LVNI_SELECTED );
end;

procedure TControl.SetLVCurItem(const Value: Integer);
begin
  if (lvoMultiselect in LVOptions) or (Value <> LVCurItem ) then
    LVItemState[ -1 ] := [ ];
  if Value >= 0 then
    LVItemState[ Value ] := [ lvisSelect, lvisFocus ];
end;

function TControl.LVNextItem(IdxPrev: Integer; Attrs: DWORD): Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, IdxPrev, Attrs );
end;

function TControl.LVNextSelected(IdxPrev: Integer): Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, IdxPrev, LVNI_SELECTED );
end;

function TControl.GetLVFocusItem: Integer;
begin
  Result := Perform( LVM_GETNEXTITEM, -1, LVNI_FOCUSED );
end;

procedure TControl.Close;
begin
  PostMessage( Handle, WM_CLOSE, 0, 0 );
end;

function WndProcMinimize( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var Wnd: PControl;
begin
  Result := FALSE;
  if  (Msg.message = WM_SYSCOMMAND) and ((Msg.wParam and $FFF0) = SC_MINIMIZE)then
  begin
      if Applet <> nil then
      begin
        Wnd := Pointer( Applet.PropInt[ @MIN_WND ] ); // fMinimizeWnd;
        if  Wnd <> nil then
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
                          if IsIconic( Self_.fHandle ) then
                             Self_.DF.fShowAction := SW_SHOWMINNOACTIVE
                          else
                          if IsZoomed( Self_.fHandle ) then
                             Self_.DF.fShowAction := SW_SHOWMAXIMIZED
                          else
                             Self_.DF.fShowAction := SW_SHOWNOACTIVATE;
                       end;
                    SW_PARENTOPENING:
                       begin
                          if Self_.DF.fShowAction <> 0 then
                          begin
                             ShowWindow( Self_.fHandle, Self_.DF.fShowAction );
                             Self_.DF.fShowAction := 0;
                          end;
                          Rslt := 0;
                       end;
                  end;
               end;
  END;
end;

procedure TControl.MinimizeNormalAnimated;
var App: PControl;
begin
  App := Applet;
  if  App = nil then
      App := @Self;
  App.PropInt[ @MIN_WND ] // fMinimizeWnd
               := Integer( @Self );
  App.AttachProc( @WndProcMinimize );
  AttachProc( @WndProcRestore );
end;

procedure TControl.RestoreNormalMaximized;
begin
  AttachProc( @WndProcRestore );
end;

function WndProcDropFiles( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var hDrop: THandle;
    Pt: TPoint;
    FList: KOLString;
    I, N: Integer;
    Buf: array[ 0..MAX_PATH ] of KOLChar;
begin
  if  Msg.message = WM_DROPFILES then
  if  TMethod(Sender.EV.fOnDropFiles).Code <> nil then
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
        FList := FList + KOLString(Buf);
      end;
      DragFinish( hDrop );
      Sender.EV.FOnDropFiles( Sender, FList, Pt );
      Rslt := 0;
      Result := TRUE; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  end;
  Result := FALSE;
end;

procedure TControl.SetOnDropFiles(const Value: TOnDropFiles);
begin
    {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
    .FOnDropFiles := Value;
    AttachProc( @WndProcDropFiles );
    DragAcceptFiles( GetWindowHandle, Assigned( Value ) );
end;

function WndProcShowHide( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var IsVisible: Boolean;
begin
  if Msg.message = WM_SHOWWINDOW then
  if Msg.hwnd = Sender.Handle then
  begin
    IsVisible := IsWindowVisible( Sender.Handle );
    if LongBool( Msg.wParam ) then
    begin
      {$IFDEF USE_FLAGS} include( Sender.fStyle.f3_Style, F3_Visible );
      {$ELSE}            Sender.fVisible := TRUE; {$ENDIF}
      if  not IsVisible then
      {$IFDEF NIL_EVENTS}
      if  Assigned( Sender.EV.FOnShow ) then
      {$ENDIF}
          Sender.EV.FOnShow( Sender );
    end else
    begin
      {$IFDEF USE_FLAGS} exclude( Sender.fStyle.f3_Style, F3_Visible );
      {$ELSE}            Sender.fVisible := FALSE; {$ENDIF}
      if  IsVisible then
      {$IFDEF NIL_EVENTS}
      if  Assigned( Sender.EV.FOnHide ) then
      {$ENDIF}
          Sender.EV.FOnHide( Sender );
    end;
  end;
  Sender.UpdateWndStyles;
  Result := FALSE;
end;

procedure TControl.SetOnHide(const Value: TOnEvent);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .FOnHide := Value;
  AttachProc( WndProcShowHide );
end;

procedure TControl.SetOnShow(const Value: TOnEvent);
begin
  {$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
  .FOnShow := Value;
  AttachProc( WndProcShowHide );
end;

function TControl.BringToFront: PControl;
begin
  SetWindowPos( GetWindowHandle, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE or
                SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_SHOWWINDOW );
  Result := @Self;
end;

function TControl.SendToBack: PControl;
begin
  SetWindowPos( GetWindowHandle, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE or
                SWP_NOACTIVATE or SWP_NOOWNERZORDER );
  Result := @Self;
end;

procedure TControl.DragStart;
begin
  PostMessage( GetWindowHandle, WM_SYSCOMMAND, $F012, 0 );
end;

function WndProcDragWindow( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var P: TPoint;
    Delta: DWORD;
    dX, dY: Integer;
begin
  if  Msg.message = WM_MOUSEMOVE then
  begin
      if  {$IFDEF USE_FLAGS} G6_Dragging in Sender.fFlagsG6
          {$ELSE} Sender.FDragging {$ENDIF} then
      begin
          GetCursorPos( P );
          Delta := Sender.PropInt[ @DRAG_XY ];
          dX := SmallInt( LoWord( Delta ) );
          dY := SmallInt( HiWord( Delta ) );
          P.x := P.x + dX; // - Sender.fMouseStartPos.x + Sender.fDragStartPos.x;
          P.y := P.y + dY; // - Sender.fMouseStartPos.y + Sender.fDragStartPos.y;
          Sender.Position := P;
      end;
  end;
  Result := FALSE;
end;

procedure TControl.DragStartEx;
var StartBounds: TRect;
    MSP: TPoint;
    dX, dY: Integer;
    Delta: Integer;
begin
  {$IFNDEF SMALLEST_CODE}
  if  {$IFDEF USE_FLAGS} G6_Dragging in fFlagsG6
      {$ELSE} fDragging {$ENDIF} then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  {$ENDIF}
  GetCursorPos( MSP );
  StartBounds := BoundsRect;
  dX := StartBounds.Left - MSP.X;
  dY := StartBounds.Top  - MSP.Y;
  Delta := (dX and $FFFF) or (dY shl 16);
  PropInt[ @DRAG_XY ] := Delta;
  SetCapture( GetWindowHandle );
  {$IFDEF USE_FLAGS} include( fFlagsG6, G6_Dragging );
  {$ELSE} fDragging := TRUE; {$ENDIF}
  AttachProc( WndProcDragWindow );
end;

procedure TControl.DragStopEx;
begin
  if  {$IFDEF USE_FLAGS} G6_Dragging in fFlagsG6
      {$ELSE} FDragging {$ENDIF} then
  begin
      ReleaseCapture;
      {$IFDEF USE_FLAGS} exclude( fFlagsG6, G6_Dragging );
      {$ELSE} FDragging := FALSE; {$ENDIF}
  end;
end;

function CallDragCallBack( Sender: PControl; var Stop: Boolean ): Boolean;
var P: TPoint;
    Shape, ShapeWas: Integer;
begin
  Sender.AttachProc( WndProcSetCursor );
  GetCursorPos( P );
  Shape := LoadCursor( 0, PKOLChar(IDC_HAND) );
  ShapeWas := Shape;
  Result := Sender.EV.fDragCallback( Sender, P.x, P.y, Shape, Stop );
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

function WndProcDrag( Sender: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var Stop: Boolean;
begin
  if  {$IFDEF USE_FLAGS} G6_Dragging in Sender.fFlagsG6
      {$ELSE} Sender.fDragging {$ENDIF} then
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
      else Result := FALSE; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      end;
      if Stop then
      begin
        ReleaseCapture;
        {$IFDEF USE_FLAGS} exclude( Sender.fFlagsG6, G6_Dragging );
        {$ELSE} Sender.fDragging := FALSE; {$ENDIF}
      end else
      begin
        Result := TRUE; exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      end;
  end;
  Result := FALSE;
end;

procedure TControl.DragItem(OnDrag: TOnDrag);
begin
  EV.fDragCallback := OnDrag;
  {$IFDEF USE_FLAGS} include( fFlagsG6, G6_Dragging );
  {$ELSE} fDragging := TRUE; {$ENDIF}
  SetCapture( GetWindowHandle );
  AttachProc( WndProcDrag );
end;

{$IFDEF USE_CONSTRUCTORS} //****************************************************//
                                                                                //
constructor TControl.CreateWindowed(AParent: PControl; AClassName: PKOLChar;       //
  ACtl3D: Boolean);                                                             //
begin                                                                           //
  CreateParented( AParent );                                                    //
  fOnDynHandlers := WndProcDummy;                                               //
  fWndProcKeybd := WndProcDummy;                                                //
  //{-2.95}//fWndProcResizeFlicks := WndProcDummy;                                         //
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
     //{-2.95}//fWndProcResizeFlicks := AParent.fWndProcResizeFlicks;                      //
     fGotoControl := AParent.fGotoControl;                                      //
     {$IFDEF USE_FLAGS}
             exc fFlagsG2 := fFlagsG2 - [G2_DoubleBuffered, G2_Transparent] +
             (AParent.fFlagsG2 * [G2_DoubleBuffered, G2_Transparent]);
     {$ELSE} fDoubleBuffered := AParent.fDoubleBuffered;
             fTransparent := AParent.fTransparent;                                      //
     {$ENDIF}
     fCtl3Dchild := AParent.fCtl3Dchild;                                        //
     if   AParent.fCtl3Dchild then                                                //
          fCtl3D := ACtl3D                                                         //
     else fCtl3D := False;                                                         //
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
       fFont.fOnGTChange := FontChanged;                                          //
       FontChanged( fFont );                                                    //
     end;                                                                       //
     fColor := AParent.fColor;                                                  //
     fBrush := fBrush.Assign( AParent.fBrush );                                 //
     if fBrush <> nil then                                                      //
     begin                                                                      //
       fBrush.fOnGTChange := BrushChanged;                                        //
       BrushChanged( fBrush );                                                  //
     end;                                                                       //
  end;                                                                          //
end;                                                                            //
                                                                                //
constructor TControl.CreateApplet(const ACaption: AnsiString);                      //
begin                                                                           //
  AppButtonUsed := True;                                                        //
  CreateWindowed( nil, 'App', TRUE );                                           //
  {$IFDEF USE_FLAGS} include( fFlagsG3, G3_IsApplet );
  {$ELSE}            FIsApplet := TRUE; {$ENDIF}
  fStyle := WS_VISIBLE or WS_SYSMENU or WS_POPUP or WS_MINIMIZEBOX              //
    or WS_CAPTION;                                                              //
  fExStyle := WS_EX_APPWINDOW;                                                  //
  FCreateWndExt := CreateAppButton;                                             //
  AttachProc( WndProcApp );                                                     //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
constructor TControl.CreateForm(AParent: PControl; const ACaption: AnsiString);     //
begin                                                                           //
  CreateWindowed( AParent, 'Form', TRUE );                                      //
  AttachProc( WndProcForm );                                                    //
  AttachProc( WndProcDoEraseBkgnd );                                            //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
constructor TControl.CreateControl(AParent: PControl; AClassName: PAnsiChar;        //
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
constructor TControl.CreateButton(AParent: PControl;                            //
  const ACaption: AnsiString);                                                      //
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
constructor TControl.CreateBitBtn(AParent: PControl;                            //
  const ACaption: AnsiString; AOptions: TBitBtnOptions; ALayout: TGlyphLayout;      //
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
      if  W > 0 then                                                             //
          if   ACaption = '' then                                                   //
               Right := Left + W                                                     //
          else Right := Right + W;                                                   //
      if  H > 0 then                                                             //
          Bottom := Top + H;                                                      //
      if  not ( bboNoBorder in AOptions ) then                                   //
      begin                                                                     //
          if W > 0 then Inc( Right, 2 );                                                      //
          if H > 0 then Inc( Bottom, 2 );                                                     //
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
constructor TControl.CreateLabel(AParent: PControl;                             //
  const ACaption: AnsiString);                                                      //
begin                                                                           //
  CreateControl( AParent, 'STATIC', WS_VISIBLE or WS_CHILD or                   //
                         SS_LEFTNOWORDWRAP or SS_NOPREFIX or SS_NOTIFY,         //
                         False, @LabelActions );
  aAutoSzX := 1;
  aAutoSzY := 1;
  {$IFDEF USE_FLAGS} fFlagsG1 := fFlagsG1 + [G1_SizeRedraw, G1_IsStaticControl];
  {$ELSE} fSizeRedraw := True;
          fIsStaticControl := 1;                                                     //
  {$ENDIF}                                         //
  fBoundsRect.Bottom := fBoundsRect.Top + 22;                                   //
  Caption := ACaption;                                                          //
end;                                                                            //
                                                                                //
constructor TControl.CreateWordWrapLabel(AParent: PControl;                     //
  const ACaption: AnsiString);                                                      //
begin                                                                           //
  CreateLabel( AParent, ACaption );                                             //
  fBoundsRect.Bottom := fBoundsRect.Top + 44;                                   //
  fStyle := fStyle and not SS_LEFTNOWORDWRAP;                                   //
end;                                                                            //
                                                                                //
constructor TControl.CreateLabelEffect(AParent: PControl; ACaption: AnsiString;     //
  AShadowDeep: Integer);                                                        //
begin                                                                           //
  CreateLabel( AParent, ACaption );                                             //
  {$IFDEF USE_FLAGS} exclude( fFlagsG1, G1_IsStaticControl );
  {$ELSE} fIsStaticControl := 0; {$ENDIF}
  AttachProc( WndProcLabelEffect );                                             //
  fTextAlign := taCenter;                                                       //
  fTextColor := clBtnShadow;                                                    //
  fShadowDeep := AShadowDeep;                                                   //
  {$IFDEF USE_FLAGS} include( fFlagsG1, G1_IgnoreWndCaption );
  {$ELSE} fIgnoreWndCaption := True; {$ENDIF}                                   //
  with fBoundsRect do                                                           //
  begin                                                                         //
    Bottom := Top + 40;                                                         //
  end;                                                                          //
end;                                                                            //
                                                                                //
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
{$IFDEF ASM_VERSION}{$ELSE PAS_VERSION} //Pascal                                                                //
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
{$ENDIF PAS_VERSION}                                                                        //
                                                                                //
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
constructor TControl.CreateGroupbox(AParent: PControl;                          //
  const ACaption: AnsiString);                                                      //
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
constructor TControl.CreateCheckbox(AParent: PControl;                          //
  const ACaption: AnsiString);                                                      //
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
constructor TControl.CreateRadiobox(AParent: PControl;                          //
  const ACaption: AnsiString);                                                      //
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
constructor TControl.CreateEditbox(AParent: PControl;                           //
  AOptions: TEditOptions);                                                      //
var Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, EditFlags );                                   //
  if not(eoMultiline in AOptions) then                                          //
     Flags := Flags and not(WS_HSCROLL or WS_VSCROLL);                          //
  CreateControl( AParent, 'EDIT', WS_VISIBLE or WS_CHILD or WS_TABSTOP          //
                         or WS_BORDER or Flags, True, @EditActions );           //
  aAutoSzY := 6;
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
  if  eoMultiline in AOptions then                                               //
      fLookTabKeys := [ tkTab ];                                                 //
  if  eoWantTab in AOptions then                                                 //
      exclude( fLookTabKeys, tkTab );                                  
end;                                                                            //
                                                                                //
constructor TControl.CreatePanel(AParent: PControl; AStyle: TEdgeStyle);        //
begin                                                                           //
  CreateControl( AParent, 'STATIC', WS_VISIBLE or WS_CHILD or                   //
                         SS_LEFTNOWORDWRAP or SS_NOPREFIX or SS_NOTIFY, False,  //
                         @LabelActions );
  aAutoSzX := 1;
  aAutoSzY := 1;
  with fBoundsRect do                                                           //
  begin                                                                         //
    Right := Left + 100;                                                        //
    Bottom := Top + 100;                                                        //
  end;                                                                          //
  Style := Style or Edgestyles[ AStyle ];                                       //
  ExStyle := ExStyle or WS_EX_CONTROLPARENT;                                    //
end;                                                                            //
                                                                                //
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
      PrevCtrl := AParent.fChildren.{$IFDEF TLIST_FAST} Items {$ELSE} fItems {$ENDIF}[ AParent.fChildren.fCount - 2 ];     //
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
constructor TControl.CreateCombobox(AParent: PControl;                          //
  AOptions: TComboOptions);                                                     //
var Flags: Integer;                                                             //
begin                                                                           //
  Flags := MakeFlags( @AOptions, ComboFlags );                                  //
  CreateControl( AParent, 'COMBOBOX',                                           //
                 WS_VISIBLE or WS_CHILD or WS_VSCROLL or                        //
                 CBS_DROPDOWN or CBS_HASSTRINGS or WS_TABSTOP or Flags,         //
                 True, @ComboActions );                                         //
  aAutoSzY := 6;
  fCreateWndExt := CreateComboboxWnd;                                           //
  //fDropDownProc := ComboboxDropDown;                                            //
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
constructor TControl.CreateCommonControl(AParent: PControl;                     //
  AClassName: PAnsiChar; AStyle: DWORD; ACtl3D: Boolean;                            //
  Actions: PCommandActions);                                                    //
begin                                                                           //
  {*************} DoInitCommonControls( ICC_WIN95_CLASSES );                      //
  CreateControl( AParent, AClassName, AStyle, ACtl3D, Actions );                //
  {$IFDEF USE_FLAGS} include( fFlagsG2, G2_IsCommonCtl );
  {$ELSE} fIsCommonControl := True; {$ENDIF}
  if AParent <> nil then                                                        //
  begin                                                                         //
    AttachProc( WndProcParentResize );                                          //
    AParent.AttachProc( WndProcResize );                                        //
    AttachProc( WndProcCommonNotify );                                          //
    AParent.AttachProc( WndProcNotify );                                        //
  end;                                                                          //
end;                                                                            //
                                                                                //
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
  {$IFDEF USE_FLAGS} exclude( fFlagsG2, G2_DoubleBuffered );
  {$ELSE} fDoubleBuffered := False; {$ENDIF}
  {$IFDEF USE_FLAGS} include( fFlagsG1, G1_CanNotDoublebuf );
  {$ELSE} fCannotDoubleBuf := True; {$ENDIF}                                    //
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
constructor TControl.CreateRichEdit(AParent: PControl;                          //
  AOptions: TEditOptions);                                                      //
var OldRichEditClass, OldRichEditLib: PAnsiChar;                                    //
begin                                                                           //
  if  OleInit then                                                               //
  begin                                                                         //
      OldRichEditClass := RichEditClass;                                          //
      OldRichEditLib := RichEditLib;                                              //
      CreateRichEdit1( AParent, AOptions );                                       //
      fCharFmtDeltaSz := 24;                                                      //
      fParaFmtDeltaSz := sizeof( TParaFormat2 ) - sizeof( RichEdit.TParaFormat ); //
      RichEditClass := OldRichEditClass;                                          //
      RichEditLib := OldRichEditLib;                                              //
  end else                                                                       //
      CreateRichEdit1( AParent, AOptions );                                       //
end;                                                                            //
                                                                                //
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
constructor TControl.CreateProgressbarEx(AParent: PControl;                     //
  AOptions: TProgressbarOptions);                                               //
const ProgressBarFlags: array[ TProgressbarOption ] of Integer =                //
      (PBS_VERTICAL, PBS_SMOOTH );                                              //
begin                                                                           //
  CreateProgressbar( AParent );                                                 //
  fStyle := fStyle or DWORD( MakeFlags( @AOptions, ProgressBarFlags ) );        //
end;                                                                            //
                                                                                //
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
end; ///////////////////////////////////////////////////////////////////////////                                                                            
constructor TControl.CreateTabControl(AParent: PControl; ATabs: array of String;//
         AOptions: TTabControlOptions;                                          //
         AImgList: PImageList; AImgList1stIdx: Integer);                        //
var I, II : Integer;                                                            //
    Flags: Integer;                                                             //
begin Flags := MakeFlags( @AOptions, TabControlFlags );                             //
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
end; ///////////////////////////////////////////////////////////////////////////
constructor TControl.CreateToolbar(AParent: PControl;                           //
  AAlign: TControlAlign; AOptions: TToolbarOptions; ABitmap: HBitmap;           //
  AButtons: array of PAnsiChar; ABtnImgIdxArray: array of Integer);             //
var Flags: DWORD;                                                               //
begin                                                                           //
  if  not( tboTextBottom in AOptions ) then                                      //
      include( AOptions, tboTextRight );
  if  tboTextRight in AOptions then                                              //
      exclude( AOptions, tboTextBottom );
  Flags := MakeFlags( @AOptions, ToolbarOptions );                              //
  CreateCommonControl( AParent, TOOLBARCLASSNAME, ToolbarAligns[ Align ] or     //
                       WS_CHILD or WS_VISIBLE {or WS_TABSTOP}                   //
                       or TBSTYLE_TOOLTIPS or Flags,                            //
                       (not (Align in [caNone])) and                            //
                        not (tboNoDivider in AOptions),  nil );                 //
  fCommandActions.aClear := ClearToolbar;                                       //
  fCommandActions.aGetCount := TB_BUTTONCOUNT;                                  //
  with fBoundsRect do                                                           //
  begin if AAlign in [ caNone ] then                                                //
        begin Bottom := Top + 26;                                                       //
              Right := Left + 1000;                                                     //
        end else                                                                     //
        begin Left := 0; Right := 0;                                                    //
              Top := 0; Bottom := 0;                                                    //
        end;                                                                        //
  end;                                                                          //
  Perform(TB_SETEXTENDEDSTYLE, 0, Perform(TB_GETEXTENDEDSTYLE, 0, 0) or         //
      TBSTYLE_EX_DRAWDDARROWS);                                                 //
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
end; ///////////////////////////////////////////////////////////////////////////                                                                            
constructor TImageList.CreateImageList(POwner: Pointer);                        //
var AOwner: PControl;                                                           //
begin {*************} DoInitCommonControls( ICC_WIN95_CLASSES );                    //
      Create;                                                                       //
      FAllocBy := 1;                                                                //
      FMasked := True;                                                              //
      if POwner = nil then exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      FBkColor := TColor( CLR_NONE );
      AOwner := POwner;                                                             //
      FControl := AOwner;                                                           //
      fNext := PImageList( AOwner.fImageList );                                     //
      if AOwner.fImageList <> nil then                                              //
         PImageList( AOwner.fImageList ).fPrev := @Self;                            //
      AOwner.fImageList := @Self;                                                   //
end;////////////////////////////////////////////////////////////////////////////
constructor TThread.ThreadCreate;                                               //
begin IsMultiThread := True;                                                        //
      Create;                                                                       //
      FSuspended := True;                                                           //
      FHandle := CreateThread( nil, // no security                                  //
                              0,   // the same stack size                           //
                              @ThreadFunc, // thread entry point                    //
                              @Self,      // parameter to pass to ThreadFunc        //
                              CREATE_SUSPENDED,   // always SUSPENDED               //
                              FThreadID ); // receive thread ID                     //
end;////////////////////////////////////////////////////////////////////////////
constructor TThread.ThreadCreateEx( const Proc: TOnThreadExecute );             //
begin                                                                           //
  ThreadCreate;                                                                 //
  OnExecute := Proc;                                                            //
  Resume;                                                                       //
end;                                                                            //
{$ENDIF USE_CONSTRUCTORS} //****************************************************//
procedure InvalidateExW( Wnd: HWnd );
begin InvalidateRect( Wnd, nil, TRUE );
      Wnd := GetWindow( Wnd, GW_CHILD );
      while Wnd <> 0 do
      begin
        InvalidateExW( Wnd );
        Wnd := GetWindow( Wnd, GW_HWNDNEXT );
      end;
end; ///////////////////////////////////////////////////////////////////////////
procedure TControl.InvalidateEx;
begin if fHandle = 0 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      InvalidateExW( fHandle );
end; ///////////////////////////////////////////////////////////////////////////
procedure InvalidateNCW( Wnd: HWnd; Recursive: Boolean );
begin SendMessage( Wnd, WM_NCPAINT, 1, 0 );
      if not Recursive then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      Wnd := GetWindow( Wnd, GW_CHILD );
      while Wnd <> 0 do
      begin
        InvalidateNCW( Wnd, Recursive );
        Wnd := GetWindow( Wnd, GW_HWNDNEXT );
      end;
end; ///////////////////////////////////////////////////////////////////////////
procedure TControl.InvalidateNC(Recursive: Boolean);
begin
  if fHandle = 0 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  InvalidateNCW( fHandle, Recursive );
end; ///////////////////////////////////////////////////////////////////////////
procedure TControl.SetClientMargin(const Index: Integer; Value: ShortInt);
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
type TGrayTextData = packed record
       Ctl: PControl;
       W, H: Integer;
       Flags: DWORD;
     end;
     PGrayTextData = ^TGrayTextData; ///////////////////////////////////////////
function DrawTextGrayed( DC: HDC; lData, wData, cX, cY: Integer ): BOOL; stdcall;
var GDT: PGrayTextData;
    R: TRect;
begin
  GDT := Pointer( lData );
  R := MakeRect( 0, 0, cX, cY );
  DrawFormattedText( GDT.Ctl, DC, R, GDT.Flags or $80000000 );
  Result := TRUE;
end; ///////////////////////////////////////////////////////////////////////////
procedure DrawFormattedText( Ctl: PControl; DC: HDC; var R: TRect; Flags: DWORD {EditCtl: Boolean} );
var Fmt: DWORD;
    OldFont: Integer;
    OldBrush: Integer;
    OldBk: Integer;
    ParentHavingFont: PControl;
    GTD: TGrayTextData;
    dX, dY: Integer;
    R1: TRect;
begin Fmt := DT_EXPANDTABS or Flags and $7FFFFFFF;
  if  Ctl.WordWrap then
      Fmt := Fmt or DT_WORDBREAK;
  if  Flags and DT_EDITCONTROL <> 0 then
      Inc( R.Left, 4 );
  ParentHavingFont := Ctl;
  while (ParentHavingFont <> nil) and ( ParentHavingFont.FFont = nil )
        and {$IFDEF USE_FLAGS} not(G3_IsForm in ParentHavingFont.fFlagsG3)
            {$ELSE} not ParentHavingFont.IsForm {$ENDIF} do
      ParentHavingFont := ParentHavingFont.Parent;
  OldFont := 0;
  if  ( ParentHavingFont <> nil ) then
  begin OldFont := SelectObject( DC, ParentHavingFont.Font.Handle );
        SetTextColor( DC, ParentHavingFont.Font.FColorRGB );
  end;
  R1 := R;
  {$IFDEF UNICODE_CTRLS}Windows.DrawTextW
  {$ELSE}               Windows.DrawTextA
  {$ENDIF}( DC, PKOLChar( Ctl.Caption ), Length( Ctl.Caption ), R,
    Fmt or DT_CALCRECT ); // TODO: fixme (Length('kanji') != WStrLen('kanji'))
  CASE Ctl.fTextAlign OF
  taCenter: dX := (R1.Right - R1.Left - (R.Right - R.Left)) div 2;
  taRight:  dX := R1.Right - R.Right;
  else      dX := 0;
  END;
  CASE Ctl.fVerticalAlign OF
  vaCenter: dY := (R1.Bottom - R1.Top - (R.Bottom - R.Top)) div 2;
  vaBottom: dY := R1.Bottom - R.Bottom;
  else      dY := 0;
  END;
  OffsetRect( R, dX, dY );
  if  {$IFDEF USE_FLAGS} not(F3_Disabled in Ctl.fStyle.f3_Style)
      {$ELSE}            Ctl.fEnabled {$ENDIF}
  or (Flags and $80000000 <> 0) then
  begin OldBk := SetBkMode( DC, TRANSPARENT );
        OldBrush := SelectObject( DC, GetStockObject( NULL_BRUSH ) );
        {$IFDEF UNICODE_CTRLS}Windows.DrawTextW
        {$ELSE}               Windows.DrawTextA
        {$ENDIF}( DC, PKOLChar( Ctl.Caption ), Length( Ctl.Caption ), R, Fmt );
        SelectObject( DC, OldBrush );
        SetBkMode( DC, OldBk );
  end else
  begin GTD.Ctl := Ctl;
        GTD.W := R.Right - R.Left;
        GTD.H := R.Bottom - R.Top;
        GTD.Flags := Flags;
        Windows.DrawState( DC, GetStockObject( NULL_BRUSH ), @ DrawTextGrayed,
          Integer( @ GTD ), Length( Ctl.fCaption ), R.Left, R.Top, R.Right - R.Left, R.Bottom - R.Top,
          DST_COMPLEX or DSS_DISABLED );
  end;
  if  ( ParentHavingFont <> nil ) then
      SelectObject( DC, OldFont );
end;

{$IFDEF USE_GRAPHCTLS}
{$IFDEF GRAPHCTL_XPSTYLES}
type TOpenThemeDataProc = function( Wnd: HWnd; pszClassList: PWideChar ): THandle;
                          stdcall;
     TDrawThemeBackground = function( Theme: THandle; DC: HDC; iPartId: Integer;
                          iStateId: Integer; Rect, ClipRect: PRect ): Integer;
                          stdcall;
     TGetThemeBackgroundContentRect = function( Theme: THandle; DC: HDC;
                          iPartId, iStateId: Integer; Rect, ContentRect: PRect ):
                          Integer; stdcall;
     TDrawThemeText = function( Theme: THandle; DC: HDC; iPartId, iStateId: Integer;
                          pszText: PWideChar; iCharCount: Integer;
                          dwTextFlags, dwTextFlags2: DWORD; Rect: PRect ): Integer;
                          stdcall;
     TCloseThemeData = function( Theme: THandle ): Integer; stdcall;
var fOpenThemeDataProc: TOpenThemeDataProc;
    fDrawthemeBackground: TDrawThemeBackground;
    fGetThemeBackgroundcontentRect: TGetThemeBackgroundContentRect;
    fDrawThemeText: TDrawThemeText;
    fCloseThemeData: TCloseThemeData;
    uxtheme_lib: THandle;
function OpenThemeDataProc: TOpenThemeDataProc;
begin Result := nil;
      if Integer(uxtheme_lib) = -1 then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      if uxtheme_lib = 0 then
         uxtheme_lib := LoadLibrary( 'uxtheme' );
      if uxtheme_lib = 0 then
      begin uxtheme_lib := DWORD( -1 ); Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
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
begin ParentHavingFont := Ctl;
  while (ParentHavingFont <> nil) and ( ParentHavingFont.FFont = nil )
        and {$IFDEF USE_FLAGS} not(G3_IsForm in ParentHavingFont.fFlagsG3)
            {$ELSE} not ParentHavingFont.IsForm {$ENDIF} do
    ParentHavingFont := ParentHavingFont.Parent;
  OldFont := 0;
  if  ( ParentHavingFont <> nil ) then
      OldFont := SelectObject( DC, ParentHavingFont.Font.Handle );
  OldBrush := SelectObject( DC, GetStockObject( NULL_BRUSH ) );
  fDrawThemeText( Theme, DC, CtlType, CtlStates, @ KOLWideString( Ctl.fCaption )[ 1 ],
                  Length( Ctl.fCaption ), Flags1, Flags2, @ R );
  SelectObject( DC, OldBrush );
  if  ( ParentHavingFont <> nil ) then SelectObject( DC, OldFont );
end;
{$ENDIF}

procedure PaintGraphicChildren( Self_, _Sender: PControl; DC: HDC );
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
    if  (C.Handle = 0)
    and {$IFDEF USE_FLAGS} (G6_GraphicCtl in C.fFlagsG6)
        {$ELSE} not C.fWindowed {$ENDIF}
    {$IFDEF SAFE_CODE} and Assigned( C.EV.fPaintProc ) {$ENDIF} then
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
      {$IFDEF NIL_EVENTS}
      if  Assigned( C.EV.fOnPrepaint ) then
      {$ENDIF}
          C.EV.fOnPrePaint( C, DC );
      C.EV.fPaintProc( DC );
      if  Assigned( C.EV.fOnPaint ) then
          C.EV.fOnPaint( C, DC );
      {$IFDEF NIL_EVENTS}
      if  Assigned( C.EV.fOnPostPaint ) then
      {$ENDIF}
          C.EV.fOnPostPaint( C, DC );
      C.fCanvas := nil;
      Self_.Canvas.Brush.Assign( Self_.Brush );
      Self_.Canvas.Font.Assign( Self_.Font );
      RestoreDC( DC, sav );
      ExcludeClipRect( DC, R.Left, R.Top, R.Right, R.Bottom );
    end;
  end;
  if  {$IFDEF USE_FLAGS} G5_IsGroupbox in Self_.fFlagsG5
      {$ELSE} Self_.fIsGroupBox {$ENDIF} then
  begin
      Self_.DF.fErasingBkgnd := TRUE;
      R := Self_.BoundsRect;
      OffsetRect( R, -R.Left, -R.Top );
      Self_.Canvas.FillRect( R );
      Self_.GroupBoxPaint( DC );
      Self_.DF.fErasingBkgnd := FALSE;
  end else
  if   Assigned( Self_.EV.fOnPaint2 ) then
       Self_.EV.fOnPaint2( Self_, DC )
  else Self_.Canvas.FillRect( Self_.ClientRect );
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
  begin WasOnPaint := Self_.EV.fOnPaint;
      Self_.{$IFDEF EVENTS_DYNAMIC} ProvideUniqueEvents {$ELSE} EV {$ENDIF}
      .fOnPaint2 := Self_.EV.fOnPaint;
      //Self_.fPaintMsg := Msg;
      {$IFDEF MAKE_METHOD}
      TMethod( Self_.EV.fOnPaint ) := MakeMethod( Self_, @ PaintGraphicChildren );
      {$ELSE}
      TMethod( Self_.EV.fOnPaint ).Code := @ PaintGraphicChildren;
      TMethod( Self_.EV.fOnPaint ).Data := Self_;
      {$ENDIF}
      save_Paint2 := Self_.EV.fOnPaint2;
      if  not Assigned( Self_.EV.fOnPaint2 ) then
      begin
          {$IFDEF MAKE_METHOD}
          Self_.EV.fOnPaint2 := TOnPaint( MakeMethod( nil, @ DummyPaintClear ) );
          {$ELSE}
          TMethod( Self_.EV.fOnPaint2 ).Code := @ DummyPaintClear;
          //TMethod( Self_.EV.fOnPaint2 ).Data := nil;
          {$ENDIF}
      end;
      i := Self_.fDynHandlers.fCount;
      Self_.fDynHandlers.fCount := Self_.fDynHandlers.IndexOf( @ WndProc_ParentOfGraphicCtl );
      Result := EnumDynHandlers( Self_, Msg, Rslt );
      Self_.fDynHandlers.fCount := i;
      if not Result then
        {Result :=} WndProcPaint( Self_, Msg, Rslt );
      Self_.EV.fOnPaint := WasOnPaint;
      Result := TRUE;
  end else
  if (Msg.message >= WM_MOUSEFIRST) and (Msg.message <= WM_MOUSELAST) then
  begin
    Pt.X := SmallInt( LoWord( Msg.lParam ) );
    Pt.Y := SmallInt( HiWord( Msg.lParam ) );
    for i := 0 to Self_.ChildCount-1 do
    begin
      if   (i = 0) and (Self_.fPushedBtn <> nil) then
           C := Self_.fPushedBtn
      else C := Self_.Children[ i ];
      if  (C = Self_.fPushedBtn) OR
          {$IFDEF USE_FLAGS}
                  (F3_Visible in C.fStyle.f3_Style)
          and not (F3_Disabled in C.fStyle.f3_Style)
          {$ELSE} C.fVisible and C.fEnabled {$ENDIF}
      and PtInRect( C.BoundsRect, Pt ) then
      begin
        if  {$IFDEF USE_FLAGS} (G6_GraphicCtl in C.fFlagsG6)
            {$ELSE} not C.fWindowed {$ENDIF}
        and (C.fCursor <> 0) and (C.fCursor <> Self_.fCursor) and
            (ScreenCursor = 0) then
        begin if Self_.fSaveCursor = 0 then
              begin Self_.fSaveCursor := Self_.fCursor;
                    if  Self_.fCursor = 0 then
                        Self_.fSaveCursor := LoadCursor( 0, IDC_ARROW );
              end;
              Self_.Cursor := C.fCursor;
              Windows.SetCursor( C.fCursor );
        end;
        {$IFDEF GRAPHCTL_HOTTRACK}
        if  {$IFDEF USE_FLAGS} (G6_GraphicCtl in C.fFlagsG6)
            {$ELSE} not C.fWindowed {$ENDIF}
        and (Applet.DF.fHotCtl <> C) then
        begin
          if Applet.DF.fHotCtl <> nil then
          begin
              {$IFDEF USE_FLAGS}
                      exclude( Applet.DF.fHotCtl.fFlagsG4, G4_Hot );
              {$ELSE} Applet.DF.fHotCtl.fHot := FALSE; {$ENDIF}
              if  {$IFDEF USE_FLAGS} (G6_GraphicCtl in Applet.DF.fHotCtl.fFlagsG6)
                  {$ELSE} not Applet.DF.fHotCtl.fWindowed {$ENDIF} then
              begin
                  Applet.DF.fHotCtl.Invalidate;
                  {$IFDEF NIL_EVENTS}
                  if  Assigned( Applet.DF.fHotCtl.EV.fOnMouseLeave ) then
                  {$ENDIF}
                      Applet.DF.fHotCtl.EV.fOnMouseLeave( Applet.DF.fHotCtl );
              end;
              Applet.DF.fHotCtl.RefDec;
          end;
          C.RefInc;
          Applet.DF.fHotCtl := C;
          {$IFDEF USE_FLAGS} include( C.fFlagsG4, G4_Hot );
          {$ELSE} C.fHot := TRUE; {$ENDIF}
          C.Invalidate;
          Self_.EV.fMouseLeaveProc := Self_.MouseLeaveFromParentOfGraphCtl;
          ProvideMouseEnterLeave( Self_ );
          {$IFDEF NIL_EVENTS}
          if  Assigned( C.EV.fOnMouseEnter ) then
          {$ENDIF}
              C.EV.fOnMouseEnter( C );
        end;
        {$ENDIF GRAPHCTL_HOTTRACK}
        if  {$IFDEF USE_FLAGS} not(G6_GraphicCtl in C.fFlagsG6)
            {$ELSE} C.fWindowed {$ENDIF} then
        begin
            Msg.hwnd := C.fHandle;
            Pt := Self_.Client2Screen( Pt );
            Pt := C.Screen2Client( Pt );
            Msg.lParam := Pt.Y shl 16 or (Pt.X and $FFFF);
        end;
        Rslt := C.WndProc( Msg );
        if  {$IFDEF USE_FLAGS} (G6_GraphicCtl in C.fFlagsG6)
            {$ELSE} not C.fWindowed {$ENDIF} then
            {$IFDEF NIL_EVENTS}
            if  Assigned( C.EV.fGraphCtlMouseEvent ) then
            {$ENDIF}
                C.EV.fGraphCtlMouseEvent( Msg )
          else if (Msg.message = WM_LBUTTONDOWN) or
                  (Msg.message = WM_RBUTTONDOWN) or
                  (Msg.message = WM_MBUTTONDOWN) then C.DoClick;
        Result := TRUE; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      end;
    end;
    {$IFDEF GRAPHCTL_HOTTRACK}
    Self_.MouseLeaveFromParentOfGraphCtl( Self_ );
    {$ENDIF GRAPHCTL_HOTTRACK}
    if  {$IFDEF USE_FLAGS} (G5_IsGroupbox in Self_.fFlagsG5)
        {$ELSE} Self_.fIsGroupBox {$ENDIF}
    and (
         (Msg.message = WM_LBUTTONDOWN) or
         (Msg.message = WM_LBUTTONDBLCLK) or
         (Msg.message = WM_LBUTTONUP)
        ) then
    begin
      Self_.Invalidate;
    end;
    if Self_.fSaveCursor <> 0 then
    begin Self_.Cursor := Self_.fSaveCursor;
          Self_.fSaveCursor := 0;
          if  ScreenCursor = 0 then Windows.SetCursor( Self_.fCursor );
    end;
  end else
  if (Msg.message >= WM_KEYFIRST) and (Msg.message <= WM_KEYLAST) then
  begin
    if   Self_.IsControl then
         PF := Self_.ParentForm
    else PF := Self_;
    if  (PF.DF.fCurrentControl <> nil)
    and {$IFDEF USE_FLAGS} (G6_GraphicCtl in PF.DF.fCurrentControl.fFlagsG6)
        {$ELSE} not PF.DF.fCurrentControl.fWindowed {$ENDIF} then
    begin if   Assigned( PF.DF.fCurrentControl.fKeyboardProcess ) and
               PF.DF.fCurrentControl.fKeyboardProcess( Msg, Rslt ) then
          else Rslt := PF.DF.fCurrentControl.WndProc( Msg );
          Result := TRUE;
    end else
    begin
      if  {$IFDEF USE_FLAGS} (G5_IsGroupbox in Self_.fFlagsG5)
          {$ELSE} Self_.fIsGroupBox {$ENDIF}
      and (Msg.wParam = WORD( ' ' )) and
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
  end else
  if Msg.message = CM_QUIT then
  begin
    C := Pointer( Msg.wParam );
    C.Free;
  end else
  if Msg.message = CM_FOCUSGRAPHCTL then
  begin
    C := Pointer( Msg.wParam );
    PF := C.ParentForm;
    if (PF.DF.fCurrentControl <> nil) and (PF.DF.fCurrentControl <> C) then
    begin
        {$IFDEF USE_FLAGS}
                exclude( PF.DF.fCurrentControl.fFlagsG6, G6_Focused );
        {$ELSE} PF.DF.fCurrentControl.fFocused := FALSE; {$ENDIF}
        PF.DF.fCurrentControl.Invalidate;
    end;
    PF.DF.fCurrentControl := C;
    C.Parent.DF.fCurrentControl := C;
    //C.Parent.fFocusHandle := C.Parent.fHandle;
    {$IFDEF USE_FLAGS} include( C.fFlagsG6, G6_Focused );
    {$ELSE} C.fFocused := TRUE; {$ENDIF}
    if  Assigned( C.EV.fOnEnter ) then
        C.EV.fOnEnter( C );
    C.Invalidate;
    C.EV.fLeave := C.LeaveGraphButton;
    C.RefDec;
  end;
end;////////////////////////////////////////////////////////////////////////////
function WndProc_FormHavingGraphCtl( Self_: PControl; var Msg: TMsg; var Rslt: Integer ): Boolean;
var Msg2: TMsg;
begin Result := FALSE;
  if Msg.message = WM_ACTIVATE then
      begin if  Self_.DF.fCurrentControl <> nil then
      Self_.DF.fCurrentControl.Invalidate;
      end else
  if (Msg.message >= WM_KEYFIRST) and (Msg.message <= WM_KEYLAST) then
  begin if  (Self_.DF.fCurrentControl <> nil)
        and {$IFDEF USE_FLAGS} (G6_GraphicCtl in Self_.DF.fCurrentControl.fFlagsG6)
        {$ELSE} not Self_.DF.fCurrentControl.fWindowed {$ENDIF} then
        begin if (Msg.message = WM_KEYDOWN) and ((Msg.wParam = 32) or (Msg.wParam = 13)) then
              begin if  not PeekMessage( Msg2, Msg.hwnd, WM_CHAR, WM_CHAR, pm_noRemove )
                        or (Msg2.wParam <> Msg.wParam) then
                        Msg.message := WM_CHAR;
              end else
              if  (Msg.message = WM_SYSKEYDOWN) and ((Msg.wParam = 32) or (Msg.wParam = 13)) then
              begin if not PeekMessage( Msg2, Msg.hwnd, WM_SYSCHAR, WM_SYSCHAR, pm_noRemove ) or
                       (Msg2.wParam <> Msg.wParam) then
                       Msg.message := WM_SYSCHAR;
              end;
              if   Assigned( Self_.DF.fCurrentControl.fKeyboardProcess ) and
                   Self_.DF.fCurrentControl.fKeyboardProcess( Msg, Rslt ) then
              else Rslt := Self_.DF.fCurrentControl.WndProc( Msg );
              Result := TRUE;
        end;
  end;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF GRAPHCTL_HOTTRACK}
procedure TControl.MouseLeaveFromParentOfGraphCtl(Sender: PObj);
var C: PControl;
    Pt: TPoint;
begin
  if AppletTerminated then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
  GetCursorPos( Pt );
  Pt := Screen2Client( Pt );
  if  (Applet.DF.fHotCtl <> nil) and (fChildren.IndexOf( Applet.DF.fHotCtl ) >= 0) then
  begin
      C := Applet.DF.fHotCtl;
      if PtInRect( C.BoundsRect, Pt ) then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      Applet.DF.fHotCtl := nil;
      {$IFDEF USE_FLAGS} exclude( C.fFlagsG4, G4_Hot );
      {$ELSE} C.fHot := FALSE; {$ENDIF}
      if  {$IFDEF USE_FLAGS} (G6_GraphicCtl in C.fFlagsG6)
          {$ELSE} not C.fWindowed {$ENDIF} then
          C.Invalidate;
      if  Assigned( C.OnMouseLeave ) then
          C.OnMouseLeave( C );
      C.RefDec;
  end;
end;
{$ENDIF GRAPHCTL_HOTTRACK}

procedure NotifyGraphCtlAboutNewParent(Prnt, Chld: PControl);
begin
  if  (Chld <> nil) and (Prnt <> nil) then
      Prnt.AttachProc( WndProc_ParentOfGraphicCtl );
end;

function _NewGraphCtl( AParent: PControl; ATabStop: Boolean;
         ACommandActions: TCommandActionsParam ): PControl;
var IdxActions: Integer;
begin new( Result, Create );
      {$IFDEF DEBUG_OBJKIND} Result.fObjKind := 'TControl:GraphicControl';
      {$ENDIF}
      {$IFDEF COMMANDACTIONS_OBJ}
          IdxActions := Integer( ACommandActions );
          if  IdxActions >= 120 then
              IdxActions := PByte( ACommandActions )^;
          if  AllActions_Objs[IdxActions] <> nil then
              begin Result.fCommandActions := AllActions_Objs[IdxActions];
              Result.fCommandActions.RefInc;
              end else
              begin new( Result.fCommandActions, Create );
              {$IFDEF DEBUG_OBJKIND}
              Result.fCommandActions.fObjKind := 'TCommandActionsObj';
              {$ENDIF}
              AllActions_Objs[IdxActions] := Result.fCommandActions;
              {$IFDEF SAFE_CODE}
              if  ACommandActions <> nil then
              {$ENDIF}
                  Move( ACommandActions^, Result.fCommandActions.aClear, Sizeof( TCommandActions ) );
          end;
          Result.Add2AutoFree( Result.fCommandActions );
          {$ELSE} {$IFDEF SAFE_CODE}
          if  ACommandActions <> nil then
          {$ENDIF}
              Result.fCommandActions := ACommandActions^;
      {$ENDIF}
      Result.PP.fDoInvalidate := InvalidateNonWindowed;
      {$IFDEF USE_FLAGS} include( Result.fFlagsG6, G6_GraphicCtl );
      {$ELSE} Result.fWindowed := FALSE; {$ENDIF}
      {$IFDEF USE_FLAGS}
              include( Result.fFlagsG3, G3_IsControl );
              include( Result.fFlagsG4, G4_CreateVisible );
              if  ATabStop then
                  include( Result.fStyle.f2_Style, F2_TabStop );
      {$ELSE} Result.fCreateVisible := TRUE;
              Result.fVisible := TRUE;
              Result.fIsControl := TRUE;
              Result.fTabstop := ATabStop;
      {$ENDIF}
      Result.fMenu := CtlIdCount;
      Inc( CtlIdCount );
      Result.DF.fBitBtnOptions := [ bboFixed ]; // to return Checked = fChecked w/o window handle
      {$IFDEF USE_FLAGS}
              Result.fFlagsG1 := Result.fFlagsG1 + [ G1_IgnoreWndCaption, G1_SizeRedraw ];
      {$ELSE} Result.fIgnoreWndCaption := TRUE;
              Result.fSizeRedraw := TRUE;
      {$ENDIF}
      Result.PP.fNotifyChild := @ NotifyGraphCtlAboutNewParent;
      if  ATabStop then
          Result.fLookTabKeys := [ tkTab, tkLeftRight, tkUpDown, tkPageUpPageDn ];
      if  AParent <> nil then
          begin Result.Parent := AParent;
          Result.Border := AParent.Border;
          AParent.AttachProc( WndProc_ParentOfGraphicCtl );
          if ATabStop then
          begin Inc( AParent.ParentForm.fTabOrder );
                Result.fTabOrder := AParent.ParentForm.fTabOrder;
          end;
          if  {$IFDEF USE_FLAGS} G3_IsControl in AParent.fFlagsG3
              {$ELSE} AParent.fIsControl {$ENDIF} then
              AParent.ParentForm.AttachProc( WndProc_FormHavingGraphCtl );
          if  {$IFDEF USE_FLAGS} G5_IsGroupbox in APArent.fFlagsG5
              {$ELSE} AParent.fIsGroupBox {$ENDIF} then
          begin AParent.Style := AParent.Style and
                    not BS_GROUPBOX; // otherwise the groupbox is flickering A LOT!
                AParent.Parent.AttachProc( WndProc_ParentOfGraphicCtl );
          end;

           Result.fFont := Result.fFont.Assign( AParent.fFont );
           if Result.fFont <> nil then
                begin  Result.fFont.fParentGDITool := AParent.fFont;
             Result.fFont.fOnGTChange := Result.FontChanged;
             Result.FontChanged( Result.fFont );
           end;
      end;
      Result.fBoundsRect.Right := Result.fBoundsRect.Left + 64;
      Result.fBoundsRect.Bottom := Result.fBoundsRect.Top + 22;
      Result.EV.fOnPaint := nil;

      {$IFDEF GRAPHCTL_XPSTYLES}
      if WinVer < wvXP then
        DoNotDrawGraphCtlsUsingXPStyles := TRUE;
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
function NewGraphLabel( AParent: PControl; const ACaption: AnsiString ): PControl;
begin {$IFDEF INPACKAGE} Result := NewLabel( AParent, ACaption );
      {$ELSE} Result := _NewGraphCtl( AParent, FALSE,
              {$IFDEF PACK_COMMANDACTIONS} LabelActions_Packed
              {$ELSE} @LabelActions {$ENDIF} );
              Result.aAutoSzX := 1;
              Result.aAutoSzY := 1;
              Result.EV.fPaintProc := Result.GraphicLabelPaint;
              Result.Caption := ACaption;
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
function NewWordWrapGraphLabel( AParent: PControl; const ACaption: KOLString ): PControl;
begin {$IFDEF INPACKAGE} Result := NewWordWrapLabel( AParent, ACaption );
      {$ELSE} Result := NewGraphLabel( AParent, ACaption );
              {$IFDEF USE_FLAGS} include( Result.fFlagsG1, G1_WordWrap );
              {$ELSE} Result.fWordWrap := TRUE; {$ENDIF}
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
function NewGraphPaintBox( AParent: PControl ): PControl;
begin {$IFDEF INPACKAGE} Result := NewPaintbox( AParent );
      {$ELSE}            Result := NewGraphLabel( AParent, '' ); {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
procedure ClickGraphCheck(Sender: PObj);
var Ctl: PControl;
begin Ctl := Pointer( Sender );
      if  not Ctl.Enabled then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      Ctl.Focused := TRUE;
      if  Assigned( Ctl.OnEnter ) then
          Ctl.OnEnter( Ctl );
      {$IFDEF USE_FLAGS}
              if   G4_Checked in Ctl.fFlagsG4 then
                   exclude( Ctl.fFlagsG4, G4_Checked )
              else include( Ctl.fFlagsG4, G4_Checked );
      {$ELSE} Ctl.fChecked := not Ctl.fChecked; {$ENDIF}
      Ctl.Invalidate;
      if  Assigned( Ctl.OnClick ) then
          Ctl.OnClick( Ctl );
end;////////////////////////////////////////////////////////////////////////////
function NewGraphCheckBox( AParent: PControl; const ACaption: KOLString ): PControl;
begin {$IFDEF INPACKAGE} Result := NewCheckbox( AParent, ACaption );
      {$ELSE} Result := NewGraphButton( AParent, ACaption );
      Result.TextAlign := taLeft;
      Result.aAutoSzX := GetSystemMetrics( SM_CXMENUCHECK ) + 4;
      Result.EV.fPaintProc := Result.GraphicCheckBoxPaint;
      Result.EV.fGraphCtlMouseEvent := Result.GraphicCheckBoxMouse;
      Result.PP.fControlClick := @ ClickGraphCheck;
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
procedure ClickGraphRadio(Sender: PObj);
var Ctl, C: PControl;
    i: Integer;
begin Ctl := Pointer( Sender );
      if not Ctl.Enabled then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      Ctl.Focused := TRUE;
      Ctl.Checked := TRUE;
      if Ctl.Parent <> nil then
      for i := 0 to Ctl.Parent.ChildCount-1 do
          begin C := Ctl.Parent.Children[ i ];
        if (C <> Ctl) and (@ C.PP.fControlClick = @ ClickGraphRadio) then
          C.Checked := FALSE;
      end;
end;////////////////////////////////////////////////////////////////////////////
function NewGraphRadioBox( AParent: PControl; const ACaption: KOLString ): PControl;
begin {$IFDEF INPACKAGE}  Result := NewRadiobox( AParent, ACaption );
      if (@ ClickGraphRadio) <> nil then;
      {$ELSE} Result := NewGraphButton( AParent, ACaption );
      Result.TextAlign := taLeft;
      Result.aAutoSzX := GetSystemMetrics( SM_CXMENUCHECK ) + 4;
      Result.EV.fPaintProc := Result.GraphicRadioBoxPaint;
      Result.PP.fControlClick := @ ClickGraphRadio;
      {$IFDEF USE_FLAGS}
      if  not(G1_HasRadio in AParent.fFlagsG1) then
      begin
          include( AParent.fFlagsG1, G1_HasRadio );
          Result.SetRadioChecked;
      end;
      {$ELSE}
      AParent.PropInt[ @RADIO_LAST ] := Result.fMenu;
      if AParent.PropInt[ @RADIO_1ST ] = 0 then
      begin
         AParent.PropInt[ @RADIO_1ST ] := Result.fMenu;
         Result.SetRadioChecked;
      end;
      {$ENDIF}
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
procedure GraphButtonSetFocus(Ctl: PControl);
var PF, CC: PControl;
    W: HWnd;
begin if  {$IFDEF USE_FLAGS} not(F2_Tabstop in Ctl.fStyle.f2_Style)
      {$ELSE} not Ctl.fTabStop {$ENDIF} then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      PF := Ctl.ParentForm;
      if  (PF.DF.fCurrentControl <> nil) and (PF.DF.fCurrentControl <> Ctl) and
          (PF.DF.fCurrentControl <> Ctl.fParent) then
          begin CC := PF.DF.fCurrentControl;
          CC.RefInc;
          Ctl.fParent.Focused := TRUE;
          if  Assigned( CC.EV.fLeave ) then
              CC.EV.fLeave( PF.DF.fCurrentControl )
          else
              Windows.SetFocus( 0 );
          CC.RefDec;
      end else
          begin W := GetFocus;
          if  (W <> Ctl.Parent.fHandle) and (W <> 0) then
                begin Windows.SetFocus( 0 );
              Ctl.fParent.Focused := TRUE;
          end;
      end;
      if  Ctl.fParent.fHandle <> 0 then
          begin {$IFDEF USE_FLAGS} include( Ctl.fFlagsG6, G6_Focused );
          {$ELSE} Ctl.fFocused := TRUE; {$ENDIF}
          Ctl.fParent.Postmsg( CM_FOCUSGRAPHCTL, Integer( Ctl ), 0 );
          Ctl.RefInc;
      end;
      if  Assigned( Ctl.EV.fOnEnter ) then
          Ctl.EV.fOnEnter( Ctl );
end;////////////////////////////////////////////////////////////////////////////
function NewGraphButton( AParent: PControl; const ACaption: KOLString ): PControl;
begin {$IFDEF INPACKAGE}
      Result := NewButton( AParent, ACaption );
      {$ELSE}
      Result := _NewGraphCtl( AParent, TRUE,
             {$IFDEF PACK_COMMANDACTIONS} ButtonActions_Packed
             {$ELSE} @ButtonActions {$ENDIF} );
      Result.EV.fPaintProc := Result.GraphicButtonPaint;
      Result.Caption := ACaption;
      Result.TextAlign := taCenter;
      Result.VerticalAlign := vaCenter;
      Result.EV.fGraphCtlMouseEvent := Result.GraphicButtonMouse;
      Result.fSetFocus := @GraphButtonSetFocus;
      Result.fKeyboardProcess := Result.GraphButtonKeyboardProcess;
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
function EditGraphEdit(Ctl: PControl): PControl;
var E: PControl;
begin E := NewEditBox( Ctl.fParent, Ctl.DF.fEditOptions );
      E.SetBoundsRect( Ctl.BoundsRect );
      E.SetAlign( Ctl.Align );
      E.fTabOrder := Ctl.fTabOrder;
      E.Text := Ctl.Text;
      E.OnChange := Ctl.ChangeGraphEdit;
      E.Color := Ctl.Color;
      E.fCursor := Ctl.fCursor;
      E.CreateWindow;
      E.OnLeave := Ctl.LeaveGraphEdit;
      E.EV.fLeave := Ctl.LeaveGraphEdit;
      E.Focused := TRUE;
      E.OnChar := Ctl.OnChar;
      E.OnKeyDown := Ctl.OnKeyDown;
      E.OnKeyUp := Ctl.OnKeyUp;
      E.OnDestroy := Ctl.DestroyGraphEdit;
      //E.Font.Assign( Font );
      Result := E;
      Ctl.Visible := FALSE;
      Ctl.DF.fEditCtl := E;
      {$IFDEF NIL_EVENTS}
      if  Assigned( Ctl.EV.fOnEnter ) then
      {$ENDIF}
          Ctl.EV.fOnEnter( Ctl );
end;////////////////////////////////////////////////////////////////////////////
function NewGraphEditbox( AParent: PControl; Options: TEditOptions ): PControl;
begin {$IFDEF INPACKAGE}
  Result := NewEditbox( AParent, Options );
  {$ELSE}
  Result := _NewGraphCtl( AParent, TRUE,
         {$IFDEF PACK_COMMANDACTIONS} EditActions_Packed
         {$ELSE} @EditActions {$ENDIF} );
  Result.aAutoSzY := 1;
  Result.EV.fPaintProc := Result.GraphicEditPaint;
  Result.DF.fEditOptions := Options;
  Result.VerticalAlign := vaCenter;
  Result.fColor := clWindow;
  Result.EV.fGraphCtlMouseEvent := Result.GraphicEditMouse;
  Result.fSetFocus := @EditGraphEdit;
  Result.fLookTabKeys := [ tkTab, tkUpDown, tkPageUpPageDn ];
  Result.EV.fLeave := Result.LeaveGraphEdit;
  {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
{ TGraphicControl }

function TControl.DoGraphCtlPrepaint: TRect;
begin
  Result := ClientRect;
  if not Assigned( TMethod( EV.fOnPrepaint ).Data ) and not Transparent then
  begin if  fBrush <> nil then
            Canvas.Brush.Assign( fBrush )
        else Canvas.Brush.Color := Color;
        Canvas.FillRect( Result );
  end;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicLabelPaint(DC: HDC);
var R: TRect;
begin R := DoGraphCtlPrepaint;
      if  Text <> '' then DrawFormattedText( @ Self, DC, R, 0 );
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicCheckBoxPaint(DC: HDC);
var R, R1: TRect;
    Flag: DWORD;
    W, H: Integer;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Theme: THandle;
    {$ENDIF}
begin R := DoGraphCtlPrepaint;
  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if  Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
      Theme := fOpenThemeDataProc( 0, 'Button' );
  if  Theme <> 0 then begin
      W := GetSystemMetrics( SM_CXMENUCHECK );
      H := GetSystemMetrics( SM_CYMENUCHECK );
      R1 := R;
      R1.Right := R1.Left + W;
      if   {$IFDEF USE_FLAGS} G1_WordWrap in fFlagsG1
           {$ELSE} fWordWrap {$ENDIF} then
           R1.Top := R1.Top + Border
      else R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
      R1.Bottom := R1.Top + H;
      Flag := 1; {CBS_UNCHECKEDNORMAL}
      if  not Enabled then
          Flag := 4 {CBS_UNCHECKEDDISABLED}
      else if  {$IFDEF USE_FLAGS} G4_Hot in fFlagsG4
          {$ELSE} fHot {$ENDIF} then
          Flag := 2; {CBS_UNCHECKEDHOT}
      if  {$IFDEF USE_FLAGS} G4_Checked in fFlagsG4
          {$ELSE} fChecked {$ENDIF} then
          Inc( Flag, 4 );
      fDrawThemeBackground( Theme, DC, 3 {BP_CHECKBOX}, Flag, @R1, @R  );
      R.Left := R1.Left + W + Border;
      if fCaption <> '' then begin
          DrawFormattedText( @ Self, DC, R, DT_CALCRECT );
          if  {$IFDEF USE_FLAGS} G1_WordWrap in fFlagsG1
              {$ELSE} fWordWrap {$ENDIF} then begin
              DrawFormattedText( @ Self, DC, R, 0 );
              GraphCtlDrawFocusRect( DC, R );
          end else begin
              GraphCtlDrawFocusRect( DC, R );
              DrawFormattedTextXP( Theme, @ Self, DC, R, 3 {BP_CHECKBOX}, Flag, 0, 0 );
          end;
      end;
      fCloseThemeData( Theme );
  end else
  {$ENDIF}
  begin W := GetSystemMetrics( SM_CXMENUCHECK );
        H := GetSystemMetrics( SM_CYMENUCHECK );
        R1 := R;
        R1.Right := R1.Left + W;
        if   {$IFDEF USE_FLAGS} G1_WordWrap in fFlagsG1
             {$ELSE} fWordWrap {$ENDIF} then
             R1.Top := R1.Top + Border
        else R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
        R1.Bottom := R1.Top + H;
        Flag := 0;
        if  {$IFDEF USE_FLAGS} G4_Checked in fFlagsG4
            {$ELSE} fChecked {$ENDIF} then
            Flag := DFCS_CHECKED;
        DrawFrameControl( DC, R1, DFC_BUTTON, DFCS_BUTTONCHECK or
                          $800 {DFCS_TRANSPARENT} or Flag );
        R.Left := R1.Left + W + Border;
        DrawFormattedText( @ Self, DC, R, 0 );
        GraphCtlDrawFocusRect( DC, R );
  end;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicCheckBoxMouse(var Msg: TMsg);
begin if (Msg.message = WM_LBUTTONDOWN) or (Msg.message = WM_LBUTTONDBLCLK) then
         ClickGraphCheck( @ Self );
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicRadioBoxPaint(DC: HDC);
var R, R1: TRect;
    Flag: DWORD;
    W, H: Integer;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Theme: THandle;
    {$ENDIF}
begin R := DoGraphCtlPrepaint;
  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if  Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
      Theme := fOpenThemeDataProc( 0, 'Button' );
  if  Theme <> 0 then begin
      W := GetSystemMetrics( SM_CXMENUCHECK );
      H := GetSystemMetrics( SM_CYMENUCHECK );
      R1 := R;
      R1.Right := R1.Left + W;
      if   {$IFDEF USE_FLAGS} G1_WordWrap in fFlagsG1
           {$ELSE} fWordWrap {$ENDIF} then
           R1.Top := R1.Top + Border
      else R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
      R1.Bottom := R1.Top + H;
      Flag := 1; {CBS_UNCHECKEDNORMAL}
      if  not Enabled then
          Flag := 4 {CBS_UNCHECKEDDISABLED}
      else if  {$IFDEF USE_FLAGS} G4_Hot in fFlagsG4
               {$ELSE} fHot {$ENDIF} then
          Flag := 2; {CBS_UNCHECKEDHOT}
      if  {$IFDEF USE_FLAGS} G4_Checked in fFlagsG4
          {$ELSE} fChecked {$ENDIF} then
          Inc( Flag, 4 );
      fDrawThemeBackground( Theme, DC, 2 {BP_RADIOBOX}, Flag, @R1, @R  );
      R.Left := R1.Left + W + Border;
      if  fCaption <> '' then begin
          DrawFormattedText( @ Self, DC, R, DT_CALCRECT );
          if  {$IFDEF USE_FLAGS} G1_WordWrap in fFlagsG1
              {$ELSE} fWordWrap {$ENDIF} then begin
              DrawFormattedText( @ Self, DC, R, 0 );
              GraphCtlDrawFocusRect( DC, R );
          end else begin
              GraphCtlDrawFocusRect( DC, R );
              DrawFormattedTextXP( Theme, @ Self, DC, R, 2 {BP_RADIOBOX}, Flag, 0, 0 );
          end;
      end;
      fCloseThemeData( Theme );
  end else
  {$ENDIF}
  begin W := GetSystemMetrics( SM_CXMENUCHECK );
        H := GetSystemMetrics( SM_CYMENUCHECK );
        R1 := R;
        R1.Right := R1.Left + W;
        if   {$IFDEF USE_FLAGS} G1_WordWrap in fFlagsG1
             {$ELSE} fWordWrap {$ENDIF} then
             R1.Top := R1.Top + Border
        else R1.Top := R1.Top + (R1.Bottom - R1.Top - H) div 2;
        R1.Bottom := R1.Top + H;
        Flag := 0;
        if  {$IFDEF USE_FLAGS} G4_Checked in fFlagsG4
            {$ELSE} fChecked {$ENDIF} then
            Flag := DFCS_CHECKED;
        DrawFrameControl( DC, R1, DFC_BUTTON, DFCS_BUTTONRADIO
                          or $800 {DFCS_TRANSPARENT} {or DFCS_ADJUSTRECT} or Flag );
        R.Left := R1.Right + 2;
        DrawFormattedText( @ Self, DC, R, 0 );
        GraphCtlDrawFocusRect( DC, R );
  end;
end;////////////////////////////////////////////////////////////////////////////
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
begin R := DoGraphCtlPrepaint;
  {$IFDEF GRAPHCTL_XPSTYLES}
  OpenThemeDataProc;
  Theme := 0;
  if  Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
      Theme := fOpenThemeDataProc( 0, 'Button' );
  if  Theme <> 0 then begin
      Flag := 1; {PBS_UNCHECKEDNORMAL}
      if  not Enabled then
          Flag := 4 {PBS_UNCHECKEDDISABLED}
      else
      if  {$IFDEF USE_FLAGS} G4_Pushed in fFlagsG4
          {$ELSE} fPushed {$ENDIF} then
          Flag := 3 {PBS_UNCHECKEDPRESSED}
      else
      if  {$IFDEF USE_FLAGS} G4_Hot in fFlagsG4
          {$ELSE} fHot {$ENDIF} then
          Flag := 2; {PBS_UNCHECKEDHOT}
      if  {$IFDEF USE_FLAGS} G4_Checked in fFlagsG4
          {$ELSE} fChecked {$ENDIF} then
          Inc( Flag, 4 );
      fDrawThemeBackground( Theme, DC, 1 {BP_PUSHBUTTON}, Flag, @R, @R  );
      fGetThemeBackgroundContentRect( Theme, DC, 1 {BS_PUSHBUTTON}, Flag, @R, @R1 );
      GraphCtlDrawFocusRect( DC, R1 );
      if (DF.fButtonIcon <> 0) and GetIconInfo( DF.fButtonIcon, II ) then begin
          if GetObject( II.hbmColor, Sizeof( BI ), @ BI ) <> 0 then begin
              CASE fVerticalAlign OF
              vaTop:    Y := R.Top + Border;
              vaBottom: Y := R.Bottom - Border - BI.bmHeight;
              else {vaCenter:}Y := R.Top + (R.Bottom - R.Top - BI.bmHeight) div 2;
              END;
              DrawIcon( DC, R.Left + Border, Y, DF.fButtonIcon );
              Inc( R1.Left, BI.bmWidth + Border * 2 );
          end;
          DeleteObject( II.hbmColor );
          if II.hbmMask <> 0 then
            DeleteObject( II.hbmMask );
      end;
      if  fCaption <> '' then begin
          Flag1 := DT_SINGLELINE;
          if  WordWrap then Flag1 := DT_WORDBREAK;
          DrawFormattedText( @ Self, DC, R1, DT_CALCRECT );
          DrawFormattedTextXP( Theme, @ Self, DC, R1, 1 {BP_PUSHBUTTON}, Flag,
            Flag1, 0 );
      end;
      fCloseThemeData( Theme );
  end else
  {$ENDIF}
  begin
    Flag := 0;
    if  {$IFDEF USE_FLAGS} G4_Checked in fFlagsG4
        {$ELSE} fChecked {$ENDIF} then Flag := DFCS_CHECKED
    else if  {$IFDEF USE_FLAGS} G4_Pushed in fFlagsG4
             {$ELSE} fPushed {$ENDIF} then
             Flag := DFCS_PUSHED;
    if  {$IFDEF USE_FLAGS} G3_Flat in fFlagsG3
        {$ELSE} fFlat {$ENDIF} then
        Flag := Flag or DFCS_FLAT;
    DrawFrameControl( DC, R, DFC_BUTTON, DFCS_BUTTONPUSH or
                      $800 {DFCS_TRANSPARENT} or DFCS_ADJUSTRECT or Flag );
    R1 := R;
    if (DF.fButtonIcon <> 0) and GetIconInfo( DF.fButtonIcon, II ) then begin
        if  GetObject( II.hbmColor, Sizeof( BI ), @ BI ) <> 0 then begin
            CASE fVerticalAlign OF
            vaTop:    Y := R.Top + Border;
            vaBottom: Y := R.Bottom - Border - BI.bmHeight;
            else {vaCenter:}Y := R.Top + (R.Bottom - R.Top - BI.bmHeight) div 2;
            END;
            DrawIcon( DC, R.Left + Border, Y, DF.fButtonIcon );
            Inc( R1.Left, BI.bmWidth + Border * 2 );
        end;
        DeleteObject( II.hbmColor );
        if  II.hbmMask <> 0 then DeleteObject( II.hbmMask );
    end;
    DrawFormattedText( @ Self, DC, R1, 0 );
    GraphCtlDrawFocusRect( DC, R );
  end;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicButtonMouse(var Msg: TMsg);
var Pt: TPoint;
begin CASE Msg.message OF
      WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
        begin GraphButtonSetFocus(@Self);
              RefInc;
              SetCapture( Parent.Handle );
              Parent.fPushedBtn := @ Self;
              {$IFDEF USE_FLAGS} include( fFlagsG4, G4_Pushed );
              {$ELSE} fPushed := TRUE; {$ENDIF}
              Invalidate;
        end;
      WM_LBUTTONUP:
        begin
          ReleaseCapture;
          Invalidate;
          if  {$IFDEF USE_FLAGS} G4_Pushed in fFlagsG4
              {$ELSE} fPushed {$ENDIF} then begin
              Pt.X := SmallInt( LoWord( Msg.lParam ) );
              Pt.Y := SmallInt( HiWord( Msg.lParam ) );
              if  PtInRect( ClientRect, Pt ) then DoClick;
              {$IFDEF USE_FLAGS} exclude( fFlagsG4, G4_Pushed );
              {$ELSE} fPushed := FALSE; {$ENDIF}
              Parent.fPushedBtn := nil;
              RefDec;
          end;
        end;
      END;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.LeaveGraphButton( Sender: PObj );
begin {$IFDEF USE_FLAGS} exclude( fFlagsG6, G6_Focused );
      {$ELSE} fFocused := FALSE; {$ENDIF}
      if  Parent.DF.fCurrentControl = @ Self then
          Parent.DF.fCurrentControl := nil;
      if  ParentForm.DF.fCurrentControl = @ Self then
          ParentForm.DF.fCurrentControl := nil;
      Invalidate;
      {$IFDEF NIL_EVENTS}
      if  Assigned( EV.fOnLeave ) then
      {$ENDIF}
          EV.fOnLeave( @ Self );
end;////////////////////////////////////////////////////////////////////////////
function TControl.GraphButtonKeyboardProcess(var Msg: TMsg;
  var Rslt: Integer): Boolean;
var SpacePressed: Boolean;
begin Result := FALSE;
      SpacePressed := Msg.wParam = Word( ' ' );
      {$IFDEF ALL_BUTTONS_RESPOND_TO_ENTER}
      SpacePressed := SpacePressed or (Msg.wParam = 13);
      {$ENDIF}
      if not SpacePressed then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      if  (Msg.message = WM_KEYDOWN) or (Msg.message = WM_SYSKEYDOWN) then
      begin
          Parent.fPushedBtn := @ Self;
          {$IFDEF USE_FLAGS} include( fFlagsG4, G4_Pushed );
          {$ELSE} fPushed := TRUE; {$ENDIF}
          Invalidate;
          Result := TRUE; /////
      end else
      if  (Msg.message = WM_KEYUP) or (Msg.message = WM_SYSKEYUP) then
      begin
          {$IFDEF USE_FLAGS} exclude( fFlagsG4, G4_Pushed );
          {$ELSE} fPushed := FALSE; {$ENDIF}
          Parent.fPushedBtn := nil;
          Invalidate;
          Result := TRUE; /////
      end else
      if (Msg.message = WM_CHAR) or (Msg.message = WM_SYSCHAR) then
      begin
          DoClick;
          Result := TRUE;
      end;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicEditPaint(DC: HDC);
var R: TRect;
    {$IFDEF GRAPHCTL_XPSTYLES}
    R1: TRect;
    Flag, Flag1: DWORD;
    Theme: THandle;
    {$ENDIF}
begin R := ClientRect;
      {$IFDEF GRAPHCTL_XPSTYLES}
      OpenThemeDataProc;
      Theme := 0;
      if  Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
          Theme := fOpenThemeDataProc( 0, 'Edit' );
      if  Theme <> 0 then
      begin
          Flag := 1; {ETS_NORMAL}
          if   not Enabled then
               Flag := 4 {ETS_DISABLED}
          else if  eoReadonly in DF.fEditOptions then
               Flag := 6 {ETS_READONLY}
          else if  {$IFDEF USE_FLAGS} G6_Focused in fFlagsG6
                   {$ELSE} fFocused {$ENDIF} then
               Flag := 5 {ETS_FOCUSED}
          else if  {$IFDEF USE_FLAGS} G4_Hot in fFlagsG4
                   {$ELSE} fHot {$ENDIF} then
               Flag := 2; {ETS_HOT}
          fDrawThemeBackground( Theme, DC, 1 {EP_EDITTEXT}, Flag, @R, @R  );
          Inc( R.Left, 2 );
          Dec( R.Right, 2 );
          fGetThemeBackgroundContentRect( Theme, DC, 1 {EP_EDITTEXT}, Flag, @R, @R1 );
          if fCaption <> '' then
          begin
              Flag1 := DT_SINGLELINE;
              if  eoMultiline in DF.fEditOptions then
                  Flag1 := DT_WORDBREAK;
              CASE fTextAlign OF
              taCenter: Flag1 := Flag1 or DT_CENTER;
              taRight:  Flag1 := Flag1 or DT_RIGHT;
              END;
              CASE fVerticalAlign OF
              vaCenter: Flag1 := Flag1 or DT_VCENTER;
              vaBottom: Flag1 := Flag1 or DT_BOTTOM;
              END;
              DrawFormattedTextXP( Theme, @ Self, DC, R1, 1 {EP_EDITTEXT}, Flag,
                Flag1, 0 );
          end;
          fCloseThemeData( Theme );
      end else
      {$ENDIF}
      begin
        if  not Assigned( EV.fOnPrepaint ) and not Transparent then begin
            Canvas.Brush.Color := fColor;
            Canvas.FillRect( R );
        end;
        DrawEdge( DC, R, BDR_SUNKENINNER or BDR_SUNKENOUTER, BF_ADJUST or BF_RECT  );
        DrawFormattedText( @ Self, DC, R, DT_EDITCONTROL );
      end;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphicEditMouse(var Msg: TMsg);
var E: PControl;
    Pt: TPoint;
begin CASE Msg.message OF
      WM_LBUTTONDOWN, WM_LBUTTONDBLCLK:
        if  not ( eoReadOnly in DF.fEditOptions ) then begin
            E := EditGraphEdit(@Self);
            Pt.X := Smallint( LoWord( Msg.lParam ) ) - Left;
            Pt.Y := Smallint( HiWord( Msg.lParam ) ) - Top;
            PostMessage( E.Handle, Msg.message, Msg.wParam,
                Pt.Y shl 16 or Pt.X and $FFFF );
        end;
      END;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.LeaveGraphEdit(Sender: PObj);
begin if  {$IFDEF USE_FLAGS} not(G6_GraphicCtl in PControl(Sender).fFlagsG6)
          {$ELSE} PControl( Sender ).fWindowed {$ENDIF}
      and ( DF.fEditCtl <> nil ) then begin
          Text := PControl( Sender ).Text;
          DF.fEditCtl := nil;
          Visible := TRUE;
          ParentForm.DF.fCurrentControl := @ Self;
          Parent.DF.fCurrentControl := @ Self;
          Parent.Postmsg( CM_QUIT, DWORD( Sender ), 0 );
      end else
      if  Assigned( DF.fEditCtl ) then
          DF.fEditCtl.EV.fLeave( DF.fEditCtl );
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.ChangeGraphEdit(Sender: PObj);
begin Text := PControl( Sender ).Text;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.DestroyGraphEdit(Sender: PObj);
begin
  DF.fEditCtl := nil;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GraphCtlDrawFocusRect(DC: HDC; const R: TRect);
var rgn: HRgn;
begin if  {$IFDEF USE_FLAGS} (G6_Focused in fFlagsG6)
          {$ELSE} fFocused {$ENDIF}
      and (GetActiveWindow = ParentForm.Handle) then begin
          BeginPath( DC );
          Canvas.FrameRect( R );
          EndPath( DC );
          Canvas.FrameRect( R );
          DrawFocusRect( DC, R );
          rgn := PathToRegion( DC );
          ExtSelectClipRgn( DC, rgn, RGN_DIFF );
          DeleteObject( rgn );
      end;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.GroupBoxPaint(DC: HDC);
var bk_erased: Boolean;
    procedure DoEraseBkgnd;
    var R: TRect;
    begin
        bk_erased := TRUE;
        If  Assigned( EV.fOnEraseBkgnd ) then
            EV.fOnEraseBkgnd( @ Self, DC )
        else begin
            R := BoundsRect;
            OffsetRect( R, -R.Left, -R.Top );
            SetBkMode( DC, OPAQUE );
            SetBkColor( DC, Color2RGB( fColor ) );
            SetBrushOrgEx( DC, 0, 0, nil );
            Windows.FillRect( DC, R, Global_GetCtlBrushHandle( @ Self ) );
        End;
    end;
var R, R1, R0: TRect;
    rgn, rgn2, rgntxt, rgnsav, rgnsavall: HRgn;
    i: Integer;
    C: PControl;
    {$IFDEF GRAPHCTL_XPSTYLES}
    Theme: THandle;
    Flag: DWORD;
    {$ENDIF}
begin if not DF.fErasingBkgnd then Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
      R := ClientRect;
      Dec( R.Top, 14 { Self_.fClientTop div 2 } );
      Dec( R.Left, fClientLeft );
      Inc( R.Right, fClientRight );
      Inc( R.Bottom, fClientBottom );
      rgnsavall := CreateRectRgn( 0, 0, 0, 0 );
      GetClipRgn( DC, rgnsavall );
      TRY
          For i := 0 to ChildCount-1 do begin
              C := Children[ i ];
              If  {$IFDEF USE_FLAGS} (G6_GraphicCtl in C.fFlagsG6)
                  {$ELSE} not C.fWindowed {$ENDIF}
              and {$IFDEF USE_FLAGS} (F3_Visible in C.fStyle.f3_Style)
                  {$ELSE} C.fVisible {$ENDIF} then begin
                  rgn := CreateRectRgnIndirect( C.BoundsRect );
                  ExtSelectClipRgn( DC, rgn, RGN_DIFF );
                  DeleteObject( rgn );
              End;
          End;
          {$IFDEF GRAPHCTL_XPSTYLES}
          OpenThemeDataProc;
          Theme := 0;
          if  Assigned( fOpenThemeDataProc ) and not DoNotDrawGraphCtlsUsingXPStyles then
              Theme := fOpenThemeDataProc( 0, 'Button' );
          If  Theme <> 0 then begin
              DoEraseBkgnd;
              Flag := 1; {GBS_NORMAL}
              if not Enabled then Flag := 2; {GBS_DISABLED}
              R1 := R;
              rgnsav := 0;
              if  fCaption <> '' then
              begin
                  R1.Top := 0;
                  Inc( R1.Left, 8 );
                  Dec( R1.Right, 8 );
                  BeginPath( DC );
                  DrawFormattedTextXP( Theme, @ Self, DC, R1, 4 {BP_GROUPBOX}, Flag, 0, 0 );
                  EndPath( DC );
                  rgntxt := PathToRegion( DC );
                  if  rgntxt = 0 then begin
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
              end else rgn := 0;
              if rgn <> 0 then
              begin
                rgnsav := CreateRectRgn( 0, 0, 0, 0 );
                GetClipRgn( DC, rgnsav );
                ExtSelectClipRgn( DC, rgn, RGN_DIFF );
                DeleteObject( rgn );
              end;
              fDrawThemeBackground( Theme, DC, 4 {BP_GROUPBOX}, Flag, @R, @R  );
              if rgnsav <> 0 then begin
                  SelectClipRgn( DC, rgnsav );
                  DeleteObject( rgnsav );
              end;
              fCloseThemeData( Theme );
          end else
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
              if rgntxt = 0 then // такое - в случае шрифта по умолчанию!
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
          End;
      FINALLY
          SelectClipRgn( DC, rgnsavall );
          DeleteObject( rgnsavall );
      END;
end;
{$ENDIF USE_GRAPHCTLS}//--------------------------------------------------------

{$IFDEF ASM_VERSION}{$ELSE PASCAL}
function TControl.MakeWordWrap: PControl;
begin {$IFDEF USE_FLAGS} include( fFlagsG1, G1_WordWrap );
      {$ELSE}            fWordWrap := TRUE; {$ENDIF}
      if  IsButton then
          Style := fStyle.Value or BS_MULTILINE
      else
          Style := fStyle.Value and not SS_LEFTNOWORDWRAP;
      Result := @ Self;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
function ParentAnchorChildren( Sender: PControl; var Msg: TMsg;
  var Rslt: Integer ): Boolean;
var NewW, NewH: Integer;
    dW, dH: Integer;
    i: Integer;
    C: PControl;
    {$IFNDEF ANCHORS_WM_SIZE}
    CR: TRect;
    {$ENDIF}
begin Result := FALSE;
      If  (Msg.message = {$IFDEF ANCHORS_WM_SIZE} WM_SIZE {$ELSE} WM_WINDOWPOSCHANGED {$ENDIF} )
          and not IsIconic(Sender.Handle) then begin
          {$IFDEF ANCHORS_WM_SIZE}
          NewW := LoWord( Msg.lParam );
          NewH := HiWord( Msg.lParam );
          {$ELSE}
          CR := Sender.ClientRect;
          NewW := CR.Right;
          NewH := CR.Bottom;
          {$ENDIF}
          dW := NewW - Sender.fOldWidth;
          dH := NewH - Sender.fOldHeight;
          For i := 0 to Sender.ChildCount - 1 do begin
              C := Sender.Children[ i ];
              If  dW <> 0 then begin
                  if C.AnchorRight and C.AnchorLeft then
                    C.Width := C.Width + dW
                  else if C.AnchorRight then
                    C.Left := C.Left + dW;
              End;
              If  dH <> 0 then begin
                  if C.AnchorBottom and C.AnchorTop then
                    C.Height := C.Height + dH
                  else if C.AnchorBottom then
                    C.Top := C.Top + dH;
              End;
          End;
          Sender.fOldWidth := NewW;
          Sender.fOldHeight := NewH;
      End;
end;////////////////////////////////////////////////////////////////////////////
function TControl.Anchor(aLeft, aTop, aRight, aBottom: Boolean): PControl;
begin if   (not aLeft) and aRight then
           AnchorLeft := FALSE
      else AnchorLeft := aLeft;
      if   (not aTop) and aBottom then
           AnchorTop := FALSE
      else AnchorTop := aTop;
      AnchorRight := aRight;
      AnchorBottom := aBottom;
      Result := @ Self;
end;
function TControl.GetLBTopIndex: Integer;
begin Result := Perform(LB_GETTOPINDEX,0,0);
end;////////////////////////////////////////////////////////////////////////////
function TControl.LBItemAtPos(X, Y: Integer): Integer;
var R: TRect;
    P: TPoint;
    i: Integer;
begin P := MakePoint(X,Y);
      For i := LBTopIndex to Count -1 do begin
          Perform(LB_GETITEMRECT, i , Integer(@R));
          if  PointInRect(P,R) then begin
              Result := i; Exit; {>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>}
          end;
      End;
      Result := -1;
end;////////////////////////////////////////////////////////////////////////////
procedure TControl.SetLBTopIndex(const Value: Integer);
begin Perform(LB_SETTOPINDEX,Value,0); end;/////////////////////////////////////
{$ENDIF WIN_GDI}//--------------------------------------------------------------
{$IFDEF ASM_VERSION}{$ELSE  PAS_VERSION}
function TControl.FormGetIntParam: Integer;
var C: Byte;
    Sign, Cont: Boolean;
begin Result := 0;
      While TRUE do begin
          C := Byte( DF.FormParams^ );
          inc( DF.FormParams );
          Cont := C and 1 <> 0;
          C := C shr 1;
          If  Cont then
              Result := (Result shl 7) or C
          else begin
              Sign := C and 1 <> 0;
              C := C shr 1;
              Result := (Result shl 6) or C;
              if  Sign then
                  Result := -Result;
              break;
          End;
      End;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function TControl.FormGetColorParam: Integer;
begin Result := FormGetIntParam;
      Result := (Result shr 1) or (Result shl 31);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure TControl.FormGetStrParam;
var i: Integer;
begin i := FormGetIntParam;
      SetString( FormString, DF.FormParams, i );
      inc( DF.FormParams, i );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure TControl.FormCreateParameters(
    alphabet: PFormInitFuncArray;
    params: PAnsiChar );
begin DF.FormCurrentParent := @Self;
      DF.FormLastCreatedChild := @Self;
      DF.FormParams := params;
      DF.FormAlphabet := alphabet;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure TControl.FormExecuteCommands(AForm: PControl; ControlPtrOffsets: PSmallIntArray);
var N: Integer;
    Ctrl: PPcontrol;
begin while {FormParams <> ''} TRUE do begin
          N := FormGetIntParam;
          if  N = 0 then
              break;
          if  N < 0 then
          begin
              N := -N;
              Ctrl := PPControl( Pointer( Integer(AForm)
                                 + (ControlPtrOffsets[0] shl 2) ) );
              ControlPtrOffsets := Pointer( Integer( ControlPtrOffsets ) + 2 );
              Ctrl^ := DF.FormAlphabet[N-1]( @Self );
              DF.FormLastCreatedChild := Ctrl^;
          end else begin
              Ctrl := @ DF.FormLastCreatedChild;
              PFormInitFuncArray1( DF.FormAlphabet )[N-1]( Ctrl^, 1 );
          end;
      end;
      FormString := '';
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}
procedure FormPrepareStrParamCreateCtrl;
asm PUSH EAX
    CALL TControl.FormGetStrParam
    POP  ECX
    MOV  EAX, [ECX].TControl.DF.FormCurrentParent
    MOV  EDX, [ECX].TControl.FormString
end;////////////////////////////////////////////////////////////////////////////
procedure FormPrepareIntParamCreateCtrl;
asm PUSH EAX
    CALL TControl.FormGetIntParam
    XCHG EDX, EAX
    POP  ECX
    MOV  EAX, [ECX].TControl.DF.FormCurrentParent
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewLabel( Form: PControl ): PControl;
begin Form.FormGetStrParam;
      Result := NewLabel( Form.DF.FormCurrentParent, Form.FormString );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewWordWrapLabel( Form: PControl ): PControl;
begin Form.FormGetStrParam;
      Result := NewWordWrapLabel( Form.DF.FormCurrentParent, Form.FormString );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewLabelEffect( Form: PControl ): PControl;
var Shd: Integer;
begin Form.FormGetStrParam;
      Shd := Form.FormGetIntParam;
      Result := NewLabelEffect( Form.DF.FormCurrentParent, Form.FormString, Shd );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewButton( Form: PControl ): PControl;
begin Form.FormGetStrParam;
      Result := NewButton( Form.DF.FormCurrentParent, Form.FormString );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
function FormNewBitBtn( Form: PControl ): PControl;
type PBitBtnOptions = ^TBitBtnOptions;
var Cap: KOLString;
    i, j, k, bmp: Integer;
begin Form.FormGetStrParam;
      Cap := Form.FormString;
      i := Form.FormGetIntParam;
      j := Form.FormGetIntParam;
      Form.FormGetStrParam;
      k := Form.FormGetIntParam;
      bmp := 0;
      if  Form.FormString <> '' then
          bmp := LoadBmp( hInstance, PKOLChar( KOLString( Form.FormString ) ), Form );
    Result := NewBitBtn( Form.DF.FormCurrentParent, Cap,
                         PBitBtnOptions( @i )^,
                         TGlyphLayout( j ),
                         bmp, k );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewPanel( Form: PControl ): PControl;
begin Result := NewPanel( Form.DF.FormCurrentParent,
                          TEdgeStyle( Form.FormGetIntParam ) );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
function FormNewGradientPanel( Form: PControl ): PControl;
var C1, C2: TColor;
begin C1 := Form.FormGetColorParam;
      C2 := Form.FormGetColorParam;
      Result := NewGradientPanel( Form.DF.FormCurrentParent, C1, C2 );
end;////////////////////////////////////////////////////////////////////////////
function FormNewGradientPanelEx( Form: PControl ): PControl;
var C1, C2: TColor;
    Style, Layout: Integer;
begin C1 := Form.FormGetColorParam;
      C2 := Form.FormGetColorParam;
      Style := Form.FormGetIntParam;
      Layout := Form.FormGetIntParam;
      Result := NewGradientPanelEx( Form.DF.FormCurrentParent, C1, C2,
          TGradientStyle( Style ), TGradientLayout( Layout ) );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
function FormNewGroupbox( Form: PControl ): PControl;
begin Form.FormGetStrParam;
      Result := NewGroupbox( Form.DF.FormCurrentParent,
                             Form.FormString );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
function FormNewPaintbox( Form: PControl ): PControl;
begin Result := NewPaintbox( Form.DF.FormCurrentParent ); end;//////////////////
function FormNewImageShow( Form: PControl ): PControl;
begin Result := NewImageShow( Form.DF.FormCurrentParent, nil, 0 ); end;/////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewEditBox( Form: PControl ): PControl;
type PEditOptions = ^TEditOptions;
var  i: Integer;
begin i := Form.FormGetIntParam;
      Result := NewEditbox( Form.DF.FormCurrentParent, PEditOptions( @ i )^ );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF USE_RICHEDIT}///////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewRichEdit( Form: PControl ): PControl;
type PEditOptions = ^TEditOptions;
var  i: Integer;
begin i := Form.FormGetIntParam;
      Result := NewRichEdit( Form.DF.FormCurrentParent,
                             PEditOptions( @ i )^ );
end;
{$ENDIF PAS_VERSION}
{$ENDIF USE_RICHEDIT}///////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewComboBox( Form: PControl ): PControl;
type PComboOptions = ^TComboOptions;
var  i: Integer;
begin i := Form.FormGetIntParam;
      Result := NewCombobox( Form.DF.FormCurrentParent, PComboOptions( @ i )^ );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewCheckbox( Form: PControl ): PControl;
begin Form.FormGetStrParam;
      Result := NewCheckbox( Form.DF.FormCurrentParent, Form.FormString );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewRadiobox( Form: PControl ): PControl;
begin Form.FormGetStrParam;
      Result := NewRadiobox( Form.DF.FormCurrentParent, Form.FormString );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
function FormNewSplitter( Form: PControl ): PControl;
var p, n: Integer;
begin p := Form.FormGetIntParam;
      n := Form.FormGetIntParam;
      Result := NewSplitter( Form.DF.FormCurrentParent, p, n );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}
function FormNewListbox( Form: PControl ): PControl;
type PListOptions = ^TListOptions;
var  i: Integer;
begin i := Form.FormGetIntParam;
      Result := NewListbox( Form.DF.FormCurrentParent, PListOptions( @ i )^ );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
function FormNewListView( Form: PControl ): PControl;
type PListViewOptions = ^TListViewOptions;
var lvs: TListViewStyle;
    i: Integer;
begin lvs := TListViewStyle( Form.FormGetIntParam );
      i := Form.FormGetIntParam;
      Result := NewListView( Form.DF.FormCurrentParent,
                             lvs, PListViewOptions( @i )^,
                             nil, nil, nil );
end;////////////////////////////////////////////////////////////////////////////
function FormNewTreeView( Form: PControl ): PControl;
type PTreeViewOptions = ^TTreeViewOptions;
var i: Integer;
begin i := Form.FormGetIntParam;
      Result := NewTreeView( Form.DF.FormCurrentParent,
                             PTreeViewOptions( @i )^,
                             nil, nil );
end;////////////////////////////////////////////////////////////////////////////
function FormNewScrollbox( Form: PControl ): PControl;
type PScrollerBars = ^TScrollerBars;
var es: TEdgeStyle;
    b: Integer;
begin es := TEdgeStyle( Form.FormGetIntParam );
      b := Form.FormGetIntParam;
      Result := NewScrollbox( Form.DF.FormCurrentParent, es, PScrollerBars( @ b )^ );
end;////////////////////////////////////////////////////////////////////////////
function FormNewScrollboxEx( Form: PControl ): PControl;
begin Result := NewScrollboxEx( Form.DF.FormCurrentParent,
                                TEdgeStyle( Form.FormGetIntParam ) );
end;////////////////////////////////////////////////////////////////////////////
function FormNewScrollBar( Form: PControl ): PControl;
begin Result := NewScrollbar( Form.DF.FormCurrentParent,
                              TScrollerBar( Form.FormGetIntParam ) );
end;////////////////////////////////////////////////////////////////////////////
function FormNewProgressBar( Form: PControl ): PControl;
begin Result := NewProgressBar( Form.DF.FormCurrentParent ); end;///////////////
function FormNewProgressBarEx( Form: PControl ): PControl;
type PProgressbarOptions = ^TProgressbarOptions;
begin Result := NewProgressBarEx( Form.DF.FormCurrentParent,
                                  PProgressbarOptions(Form.FormGetIntParam)^ );
end;////////////////////////////////////////////////////////////////////////////
function FormNewDateTimePicker( Form: PControl ): PControl;
type PDateTimePickerOptions = ^TDateTimePickerOptions;
var o: Integer;
begin o := Form.FormGetIntParam;
      Result := NewDateTimePicker( Form.DF.FormCurrentParent,
                                   PDateTimePickerOptions( @ o )^ );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF _D4orHigher}
function FormNewTabControl( Form: PControl ): PControl;
type PTabControlOptions = ^TTabControlOptions;
var N, i, o: Integer;
    Tabs1: array of KOLString;
    Tabs2: array of PKOLChar;
begin N := Form.FormGetIntParam;
      SetLength( Tabs1, N );
      SetLength( Tabs2, N );
      for i := 0 to N-1 do
      begin
          Form.FormGetStrParam;
          Tabs1[i] := Form.FormString;
          Tabs2[i] := PKOLChar( Tabs1[i] );
      end;
      o := Form.FormGetIntParam;
      i := Form.FormGetIntParam;
      Result := NewTabControl( Form.DF.FormCurrentParent,
                               Tabs2,
                               PTabControlOptions(@ o)^,
                               nil, i );
      SetLength( Tabs1, 0 );
      SetLength( Tabs2, 0 );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ENDIF PAS_VERSION}////////////////////////////////////////
function ParentForm_PCharParam(Control: PControl): PKOLChar;
var Form: PControl;
begin Form := Control.FormParentForm;
      Form.FormGetStrParam;
      Result := PKOLChar( KOLString( Form.FormString ) );
end;////////////////////////////////////////////////////////////////////////////
function ParentForm_IntParamPas(Form: PControl): Integer;
begin Result := Form.FormParentForm.FormGetIntParam; end;///////////////////////////
function ParentForm_ColorParamPas(Form: PControl): Integer;
begin Result := Form.FormParentForm.FormGetColorParam; end;/////////////////////////
{$IFDEF ASM_VERSION} // only to call from asm -- returns EAX=Parent Form, EDX=ECX=PChar param
{$ENDIF ASM_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure FormSetSize( Form: PControl );
var W, H: Integer;
begin W := ParentForm_IntParamPas( Form );
      H := ParentForm_IntParamPas( Form );
      Form.SetSize( W, H );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
procedure FormSetHeight( Form: PControl );
begin Form.Height := ParentForm_IntParamPas(Form); end;/////////////////////////
procedure FormSetWidth( Form: PControl );
begin Form.Width := ParentForm_IntParamPas(Form); end;//////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure FormSetPosition( Form: PControl );
var X, Y: Integer;
begin X := ParentForm_IntParamPas(Form);
      Y := ParentForm_IntParamPas(Form);
      Form.SetPosition( X, Y );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure FormSetClientSize( Form: PControl );
var W, H: Integer;
begin W := ParentForm_IntParamPas(Form);
      H := ParentForm_IntParamPas(Form);
      Form.SetClientSize( W, H );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure FormSetAlign( Form: PControl );
begin Form.SetAlign( TControlAlign( ParentForm_IntParamPas(Form) ) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF USE_NAMES}
procedure FormSetName( Form: PControl );
var C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      Form.FormGetStrParam;
      C.SetName( Form, Form.FormString );
end;
{$ENDIF USE_NAMES}//////////////////////////////////////////////////////////////
procedure FormSetTag( Form: PControl );
var tag: DWORD;
begin
    tag := ParentForm_IntParamPas(Form);
    Form.Tag := tag;
end;
{$IFDEF UNICODE_CTRLS}
procedure FormSetUnicode( Form: PControl );
begin Form.SetUnicode( TRUE ); end;
{$ENDIF UNICODE_CTRLS}//////////////////////////////////////////////////////////
procedure FormAssignHelpContext( Form: PControl );
begin Form.AssignHelpContext( ParentForm_IntParamPas( Form ) ); end;////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetCanResizeFalse( Form: PControl );
begin Form.CanResize := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormInitMenu( Form: PControl );
begin Form.Perform( WM_INITMENU, 0, 0 ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSizeGripFalse( Form: PControl );
begin Form.SizeGrip := FALSE; end; /////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetExStyle( Form: PControl );
begin Form.ExStyle := Form.ExStyle or DWORD( ParentForm_IntParamPas(Form) ); end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetVisibleFalse( Form: PControl );
begin Form.Visible := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetEnabledFalse( Form: PControl );
begin Form.Enabled := FALSE; end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormResetStyles( Form: PControl );
begin Form.Style := Form.Style and not ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetStyle( Form: PControl );
begin Form.Style := Form.Style or DWORD( ParentForm_IntParamPas(Form)); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE  PASCAL}
procedure FormSetAlphaBlend( Form: PControl );
begin Form.AlphaBlend := ParentForm_IntParamPas( Form ); end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetHasBorderFalse( Form: PControl );
begin Form.HasBorder := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetHasCaptionFalse( Form: PControl );
begin Form.HasCaption := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormResetCtl3D( Form: PControl );
begin Form.Ctl3D := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormIconLoad_hInstance( Form: PControl );
begin Form.IconLoad( hInstance,
                     MAKEINTRESOURCE( ParentForm_IntParamPas(Form) ) );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormIconLoadCursor_0( Form: PControl );
begin Form.IconLoadCursor( 0, MakeIntResource( ParentForm_IntParamPas(Form) ) );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetIconNeg1( Form: PControl );
begin Form.Icon := THandle( -1 ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormIconLoad_hInstance_str( Form: PControl );
begin Form.FormGetStrParam;
      Form.IconLoad( hInstance, PKOLChar( KOLString( Form.FormString ) ) );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetWindowState( Form: PControl );
begin Form.WindowState := TWindowState( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormCursorLoad_0( Form: PControl );
begin Form.CursorLoad( 0, MAKEINTRESOURCE( ParentForm_IntParamPas(Form) ) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormCursorLoad_hInstance( Form: PControl );
var C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      Form.FormGetStrParam;
      C.CursorLoad( 0, PKOLChar( KOLString( Form.FormString ) ) );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetColor( Form: PControl );
begin Form.Color := ParentForm_ColorParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetBrushStyle( Form: PControl );
begin Form.Brush.BrushStyle := TBrushStyle( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetBrushBitmap( Form: PControl );
var C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      {$IFDEF UNICODE_CTRLS}
      Form.FormGetStrParam;
      {$ENDIF}
      C.Brush.BrushBitmap :=
          LoadBmp( hInstance,
          {$IFDEF UNICODE_CTRLS} PKOLChar( KOLString( Form.FormString ) )
          {$ELSE}                ParentForm_PCharParam(Form)
          {$ENDIF}               , Form );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontColor( Form: PControl );
begin Form.Font.Color := ParentForm_ColorParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontStyles( Form: PControl );
type PFontStyle = ^TFontStyle;
var fs: Byte;
begin fs := ParentForm_IntParamPas(Form);
      Form.Font.FontStyle := PFontStyle( @ fs )^;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontHeight( Form: PControl );
begin Form.Font.FontHeight := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontWidth( Form: PControl );
begin Form.Font.FontWidth := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure ParentForm_StrParam( Form: PControl );
begin Form := Form.FormParentForm;
      Form.FormGetStrParam;
end;////////////////////////////////////////////////////////////////////////////
procedure FormSetFontName( Form: PControl );
begin ParentForm_StrParam(Form);
      Form.Font.FontName := Form.FormParentForm.FormString;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontOrientation( Form: PControl );
begin Form.Font.FontOrientation := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontCharset( Form: PControl );
begin Form.Font.FontCharset := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetFontPitch( Form: PControl );
begin Form.Font.FontPitch := TFontPitch( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetBorder( Form: PControl );
begin Form.Border := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMarginTop( Form: PControl );
begin Form.MarginTop := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMarginBottom( Form: PControl );
begin Form.MarginBottom := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMarginLeft( Form: PControl );
begin Form.MarginLeft := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMarginRight( Form: PControl );
begin Form.MarginRight := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetSimpleStatusText( Form: PControl );
begin Form.SimpleStatusText := ParentForm_PCharParam(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetStatusText( Form: PControl );
var I: Integer;
begin I := ParentForm_IntParamPas(Form);
      Form.StatusText[I] := ParentForm_PCharParam(Form);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormRemoveCloseIcon( Form: PControl );
begin DeleteMenu( GetSystemMenu( Form.GetWindowHandle, False ),
                  SC_CLOSE, MF_BYCOMMAND );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetEraseBkgndTrue( Form: PControl );
begin Form.EraseBackground := TRUE; end;
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMinWidth( Form: PControl );
begin Form.MinWidth := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMaxWidth( Form: PControl );
begin Form.MaxWidth := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMinHeight( Form: PControl );
begin Form.MinHeight := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMaxHeight( Form: PControl );
begin Form.MaxHeight := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF noASM_VERSION}
procedure FormSetRepeatInterval( Form: PControl );
asm CALL ParentForm_IntParamAsm
    MOV  [EAX].TControl.fRepeatInterval, EDX
end;
{$ELSE PAS_VERSION}
procedure FormSetRepeatInterval( Form: PControl );
begin Form.RepeatInterval := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetKeyPreviewTrue( Form: PControl );
begin {$IFDEF KEY_PREVIEW}
          Form.KeyPreview := TRUE;
      {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetTextShiftX( Form: PControl );
begin Form.TextShiftX := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetTextShiftY( Form: PControl );
begin Form.TextShiftY := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetColor2( Form: PControl );
begin Form.Color2 := ParentForm_ColorParamPas( Form ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetTextAlign( Form: PControl );
begin Form.TextAlign := TTextAlign( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetTextVAlign( Form: PControl );
begin Form.VerticalAlign := TVerticalAlign( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetTabStopFalse( Form: PControl );
begin Form.TabStop := FALSE; end;
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetIgnoreDefault( Form: PControl );
begin Form.IgnoreDefault := Boolean( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetHintText( Form: PControl );
begin {$IFDEF USE_MHTOOLTIP}
      ParentForm_StrParam(Form);
      Form.Hint.Text := Form.FormParentForm.FormString;
      {$ENDIF USE_MHTOOLTIP}
end;////////////////////////////////////////////////////////////////////////////
procedure FormSetAnchor( Form: PControl );
var i: Integer;
begin i := ParentForm_IntParamPas(Form);
      Form.AnchorLeft   := I and 1 <> 0;
      Form.AnchorTop    := I and 2 <> 0;
      Form.AnchorRight  := I and 4 <> 0;
      Form.AnchorBottom := I and 8 <> 0;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetCaption( Form: PControl );
var   Ctl: PControl;
begin Ctl := Form;
      Form := Form.FormParentForm;
      Form.FormGetStrParam;
      Ctl.Caption := Form.FormString;
end;
{$ENDIF PAS_VERSION}
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetGradienStyle( Form: PControl );
begin Form.GradientStyle := TGradientStyle( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormOverrideScrollbars( Form: PControl );
begin OverrideScrollbars( Form ); end;
{$IFDEF USE_RICHEDIT}
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_AutoFontFalse( Form: PControl );
begin Form.RE_AutoFont := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_AutoFontSizeAdjustFalse( Form: PControl );
begin Form.RE_AutoFontSizeAdjust := FALSE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_DualFontTrue( Form: PControl );
begin Form.RE_DualFont := TRUE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_UIFontsTrue( Form: PControl );
begin Form.RE_UIFonts := TRUE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_IMECancelCompleteTrue( Form: PControl );
begin Form.RE_IMECancelComplete := TRUE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_IMEAlwaysSendNotifyTrue( Form: PControl );
begin Form.RE_IMEAlwaysSendNotify := TRUE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMaxTextSize( Form: PControl );
begin Form.MaxTextSize := DWORD( ParentForm_IntParamPas(Form) ); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_AutoKeyboardTrue( Form: PControl );
begin Form.RE_AutoKeyboard := TRUE; end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetRE_DisableOverwriteChangeTrue( Form: PControl );
begin Form.RE_DisableOverwriteChange := TRUE;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetRE_Zoom( Form: PControl );
var   zoom: TSmallPoint;
begin zoom.X := ParentForm_IntParamPas(Form);
      zoom.Y := ParentForm_IntParamPas(Form);
      Form.RE_Zoom := zoom;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$ENDIF USE_RICHEDIT}
procedure FormSetListItems( Form: PControl );
var N, i: Integer;
begin N := ParentForm_IntParamPas(Form);
      for i := 0 to N-1 do BEGIN
          ParentForm_StrParam(Form);
          Form.Items[i] := Form.FormParentForm.FormString;
      END;
end;
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetCount( Form: PControl );
begin Form.Count := ParentForm_IntParamPas(Form);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetDroppedWidth( Form: PControl );
begin Form.DroppedWidth := ParentForm_IntParamPas(Form);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetButtonIcon( Form: PControl );
begin
    Form.SetButtonIcon( LoadImage( hInstance,
         ParentForm_PCharParam(Form),
         IMAGE_ICON, 0, 0, $8000 {LR_SHARED} ) );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetButtonImage( Form: PControl );
var   w, h: Integer;
begin w := ParentForm_IntParamPas(Form);
      h := ParentForm_IntParamPas(Form);
      Form.SetButtonIcon( LoadImage( hInstance,
          ParentForm_PCharParam(Form),
          IMAGE_ICON, w, h, $8000 {LR_SHARED} ) );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetButtonBitmap( Form: PControl );
begin Form.SetButtonBitmap( LoadBitmap( hInstance,
           ParentForm_PCharParam(Form) ) );
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetDefaultBtn( Form: PControl );
var i: Integer;
begin i := ParentForm_IntParamPas(Form);
      Form.SetDefaultBtn( i, TRUE );
end;
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetMaxProgress( Form: PControl );
begin Form.MaxProgress := ParentForm_IntParamPas(Form);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetProgress( Form: PControl );
begin Form.Progress := ParentForm_IntParamPas(Form);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormLVColumsAdd( Form: PControl );
var   N, i, w: Integer;
begin N := ParentForm_IntParamPas(Form);
      for i := 0 to N-1 do BEGIN
          w := ParentForm_IntParamPas(Form);
          ParentForm_StrParam(Form);
          Form.LVColAdd( Form.FormParentForm.FormString, taLeft, w );
      END;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetLVColOrder( Form: PControl );
var   N, i: Integer;
begin N := ParentForm_IntParamPas(Form);
      i := ParentForm_IntParamPas(Form);
      Form.LVColOrder[N] := i;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetLVColImage( Form: PControl );
var   N, i: Integer;
begin N := ParentForm_IntParamPas(Form);
      i := ParentForm_IntParamPas(Form);
      Form.LVColImage[N] := i;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetTVIndent( Form: PControl );
begin Form.TVIndent := ParentForm_IntParamPas(Form);
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetTBBtnImgWidth( Form: PControl );
begin Form.TBBtnImgWidth := ParentForm_IntParamPas( Form );
end;////////////////////////////////////////////////////////////////////////////
procedure FormTBAddBitmap( Form: PControl );
var   map: array[ 0..1 ] of TColor;
      b: Integer;
      C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      b := Form.FormGetIntParam;
      if  b >= 0 then
      begin
          Form.FormGetStrParam;
          if  b <> 0 then
          begin
              map[0] := Form.FormGetColorParam;
              map[1] := Color2RGB( clBtnFace );
              b := LoadMappedBitmapEx( Form, hInstance, PKOLChar( KOLString( Form.FormString )), map );
          end else
              b := LoadBmp( hInstance, PKOLChar(KOLString(Form.FormString)), Form );
      end;
      C.TBAddBitmap( b );
end;////////////////////////////////////////////////////////////////////////////
procedure FormSetTBButtonSize( Form: PControl );
begin Form.Perform( TB_SETBUTTONSIZE, 0,
                    ParentForm_IntParamPas(Form) or $10000 {or (HiWord(HW) shl 16)} );
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF _D4orHigher}
procedure FormTBSetTooltips( Form: PControl );
var   A1: array of KOLString;
      A2: array of PKOLChar;
      N, i: Integer;
      C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      N := Form.FormGetIntParam;
      SetLength( A1, N );
      SetLength( A2, N );
      for i := 0 to N-1 do
      begin
          Form.FormGetStrParam;
          A1[i] := Form.FormString;
          A2[i] := PKOLChar( A1[i] );
      end;
      C.TBSetTooltips( 0, A2 );
      SetLength( A1, 0 );
      SetLength( A2, 0 );
end;
{$ENDIF _D4orHigher}////////////////////////////////////////////////////////////
procedure FormSetTBButtonsMinWidth( Form: PControl );
begin Form.TBButtonsMinWidth := ParentForm_IntParamPas(Form);
end;////////////////////////////////////////////////////////////////////////////
procedure FormSetTBButtonsMaxWidth( Form: PControl );
begin Form.TBButtonsMaxWidth := ParentForm_IntParamPas(Form);
end;////////////////////////////////////////////////////////////////////////////
procedure FormHideToolbarButton( Form: PControl );
var i: Integer;
begin i := ParentForm_IntParamPas(Form);
      {$IFDEF USE_GRUSH}
              ShowHideToolbarButton( Form, i, FALSE );
      {$ELSE} Form.TBButtonVisible[ i ] := FALSE; {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
procedure FormDisableToolbarButton( Form: PControl );
var   i: Integer;
begin i := ParentForm_IntParamPas(Form);
      {$IFDEF USE_GRUSH}
              EnableToolbarButton( Form, i, FALSE );
      {$ELSE} Form.TBButtonEnabled[ i ] := FALSE; {$ENDIF}
end;////////////////////////////////////////////////////////////////////////////
procedure FormFixFlatXPToolbar( Form: PControl );
begin Form.OnTBCustomDraw := nil;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetDateTimeFormat( Form: PControl );
begin ParentForm_StrParam(Form);
      Form.DateTimeFormat := Form.FormParentForm.FormString;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetDateTimeColor( Form: PControl );
var   i: Integer;
      C: TColor;
begin C := ParentForm_ColorParamPas( Form );
      i := ParentForm_IntParamPas( Form );
      Form.DateTimePickerColors[TDateTimePickerColor(i)] := C;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetCurrentTab( Form: PControl );
var i: Integer;
begin i := ParentForm_IntParamPas(Form);
      Form.CurIndex := i;
      Form.Pages[i].BringToFront;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetCurIdx( Form: PControl );
begin Form.CurIndex := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetSBMin( Form: PControl );
begin Form.SBMin := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetSBMax( Form: PControl );
begin Form.SBMax := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetSBPosition( Form: PControl );
begin Form.SBPosition := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetSBPageSize( Form: PControl );
begin Form.SBPageSize := ParentForm_IntParamPas(Form); end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormLastCreatedChildAsNewCurrentParent( Form: PControl );
var   C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      Form.DF.FormCurrentParent := C;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetUpperParent( Form: PControl );
begin Form := Form.FormParentForm;
      Form.DF.FormCurrentParent := Form.DF.FormCurrentParent.Parent;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}
procedure FormSetTabpageAsParent( Form: PControl );
var   i: Integer;
      C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      i := Form.FormGetIntParam;
      Form.DF.FormCurrentParent := C.Pages[i];
      Form.DF.FormLastCreatedChild := Form.DF.FormCurrentParent;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE PASCAL}//////////////////////////////////////////////
procedure FormSetCurCtl( Form: PControl );
var   i: Integer;
      C: PControl;
begin Form := Form.FormParentForm;
      i := Form.FormGetIntParam;
      C := PPControl(Integer( Form.DF.FormAddress ) + i * 4)^;
      if  C = nil then C := Form;
      Form.DF.FormLastCreatedChild := C;
end;
{$ENDIF PAS_VERSION}////////////////////////////////////////////////////////////
procedure FormSetParent( Form: PControl );
var   C: PControl;
begin C := Form;
      Form := Form.FormParentForm;
      Form.DF.FormCurrentParent := C;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}/////////////////////////////////////////////////////
procedure FormSetEvent( Form: PControl );
type  TSetEventProc = procedure( TargetCtl: PControl; const event: TOnEvent );
var   C: PControl;
      idx_handler, idx_setter: Integer;
      handler, setter: Pointer;
      event: TOnEvent;
      set_proc: TSetEventProc;
begin C := Form;
      Form := Form.FormParentForm;
      idx_handler := Form.FormGetIntParam;
      idx_setter := Form.FormGetIntParam;
      handler := @Form.DF.FormAlphabet[idx_handler];
      setter := @Form.DF.FormAlphabet[idx_setter];
      set_proc := TSetEventProc( setter );
      Pointer( TMethod( event ).Code ) := handler;
      TMethod( event ).Data := Form.DF.FormObj;
      set_proc( PControl( C ), event );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
{$IFDEF ASM_VERSION}{$ELSE}/////////////////////////////////////////////////////
procedure FormSetIndexedEvent( Form: PControl );
type  TSetIndexedEventProc = procedure( TargetCtl: PControl; Index: Integer;
                                        const event: TOnEvent );
var   C: PControl;
      idx_handler, idx_setter, idx: Integer;
      handler, setter: Pointer;
      event: TOnEvent;
      set_proc: TSetIndexedEventProc;
begin C := Form;
      Form := Form.FormParentForm;
      idx_handler := Form.FormGetIntParam;
      idx := Form.FormGetIntParam;
      idx_setter := Form.FormGetIntParam;
      handler := @Form.DF.FormAlphabet[idx_handler];
      setter := @Form.DF.FormAlphabet[idx_setter];
      set_proc := TSetIndexedEventProc( setter );
      Pointer( TMethod( event ).Code ) := handler;
      TMethod( event ).Data := Form.DF.FormObj;
      set_proc( PControl( C ), idx, event );
end;
{$ENDIF}////////////////////////////////////////////////////////////////////////
procedure DummyOverrideScrollbars(Sender: PControl);
begin
end;

{$IFnDEF PAS_VERSION}
    {$I KOL_ASM.inc} //<<<<<<<<<<<<<<<<<<<<<<< KOL_ASM.inc
    {$IFnDEF UNICODE_CTRLS}
        {$I KOL_ASM_NOUNICODE.inc} //<<<<<<<<< KOL_ASM_NOUNICODE.inc
    {$ENDIF noUNICODE}
{$ENDIF PAS_VERSION}
{$IFDEF LIN}
  {$DEFINE implementation} {$I KOL_Linux.inc} {$UNDEF implementation}
{$ENDIF LIN}

{$IFDEF USE_CUSTOMEXTENSIONS}
  {$I CUSTOM_CODE_EXTENSION.inc} // See comments in TControl
{$ENDIF USE_CUSTOMEXTENSIONS}

{$IFDEF EVENTS_DYNAMIC}//-------------------------------------------------------
{$IFDEF ASM_VERSION}
function TControl.ProvideUniqueEvents: PEvents;
const Size_TEvents = Sizeof(TEvents);
asm      PUSH  ESI
         XCHG  ESI, EAX
         MOV   EAX, [ESI].TControl.EV
         CMP   EAX, offset[EmptyEvents]
         JNZ   @@ready

         MOV   EAX, Size_TEvents
         CALL  System.@GetMem
         MOV   [ESI].TControl.EV, EAX 
         PUSH  EAX
         XCHG  EDX, EAX
         MOV   EAX, offset[EmptyEvents]
         MOV   ECX, Size_TEvents
         CALL  Move
         PUSH  ESI
         PUSH  offset[FreeEV]
         XCHG  EAX, ESI
         CALL  TControl.Add2AutoFreeEx
         POP   EAX
@@ready:
         POP   ESI
end;
{$ELSE}
function TControl.ProvideUniqueEvents: PEvents;
begin if  EV = @EmptyEvents then
      begin
          GetMem( EV, Sizeof(TEvents) );
          Move( EmptyEvents, EV^, Sizeof(TEvents) );
          Add2AutoFreeEx( FreeEV );
      end;
      Result := EV;
end; {$ENDIF PAS_VERSION}///////////////////////////////////////////////////////

procedure TControl.FreeEV;
begin FreeMem( EV );
      EV := @EmptyEvents;
end;////////////////////////////////////////////////////////////////////////////
function TControl.Get_OnHelp: TOnHelp;
begin Result := EV.fOnHelp; end;
procedure TControl.Set_OnHelp(const Value: TOnHelp);
begin ProvideUniqueEvents.fOnHelp := Value; end;
function TControl.Get_OnBitBtnDraw: TOnBitBtnDraw;
begin Result := EV.FOnBitBtnDraw; end;
procedure TControl.Set_OnBitBtnDraw(const Value: TOnBitBtnDraw);
begin ProvideUniqueEvents.FOnBitBtnDraw := Value; end;
function TControl.Get_OnMeasureItem: TOnMeasureItem;
begin Result := EV.fOnMeasureItem; end;
function TControl.Get_OnShow: TOnEvent;
begin Result := EV.fOnShow; end;
function TControl.Get_OnHide: TOnEvent;
begin Result := EV.fOnHide; end;
function TControl.Get_OnClose: TOnEventAccept;
begin Result := EV.fOnClose; end;
function TControl.Get_OnQueryEndSession: TOnEventAccept;
begin Result := EV.fOnQueryEndSession; end;
function TControl.Get_OnPaint: TOnPaint;
begin Result := EV.fOnPaint; end;
function TControl.Get_OnPrePaint: TOnPaint;
begin Result := EV.fOnPrepaint; end;
procedure TControl.Set_OnPrePaint(const Value: TOnPaint);
begin ProvideUniqueEvents.fOnPrepaint := Value; end;
function TControl.Get_OnPostPaint: TOnPaint;
begin Result := EV.fOnPostPaint; end;
procedure TControl.Set_OnPostPaint(const Value: TOnPaint);
begin ProvideUniqueEvents.fOnPostPaint := Value; end;
function TControl.Get_OnEraseBkgnd: TOnPaint;
begin Result := EV.fOnEraseBkgnd; end;
procedure TControl.Set_OnEraseBkgnd(const Value: TOnPaint);
begin ProvideUniqueEvents.fOnEraseBkgnd := Value;
      AttachProc( WndProcEraseBkgnd );
end;////////////////////////////////////////////////////////////////////////////
function TControl.Get_OnClick: TOnEvent;
begin Result := EV.fOnClick; end;
function TControl.Get_OnResize: TOnEvent;
begin Result := EV.fOnResize; end;
function TControl.Get_OnMove: TOnEvent;
begin Result := EV.fOnMove; end;
function TControl.Get_OnMoving: TOnEventMoving;
begin Result := EV.fOnMoving; end;
function TControl.Get_OnSplit: TOnSplit;
begin Result := EV.FOnSplit; end;
procedure TControl.Set_OnSplit(const Value: TOnSplit);
begin ProvideUniqueEvents.FOnSplit := Value; end;
function TControl.Get_OnKeyDown: TOnKey;
begin Result := EV.fOnKeyDown; end;
function TControl.Get_OnKeyUp: TOnKey;
begin Result := EV.fOnKeyUp; end;
function TControl.Get_OnChar: TOnChar;
begin Result := EV.fOnChar; end;
function TControl.Get_OnDeadChar: TOnChar;
begin Result := EV.fOnDeadChar; end;
function TControl.Get_OnMouseUp: TOnMouse;
begin Result := EV.fOnMouseUp; end;
function TControl.Get_OnMouseDown: TOnMouse;
begin Result := EV.fOnMouseDown; end;
function TControl.Get_OnMouseMove: TOnMouse;
begin Result := EV.fOnMouseMove; end;
function TControl.Get_OnMouseDblClk: TOnMouse;
begin Result := EV.fOnMouseDblClk; end;
function TControl.Get_OnMouseWheel: TOnMouse;
begin Result := EV.fOnMouseWheel; end;
function TControl.Get_OnMouseEnter: TOnEvent;
begin Result := EV.fOnMouseEnter; end;
function TControl.Get_OnMouseLeave: TOnEvent;
begin Result := EV.fOnMouseLeave; end;
function TControl.Get_OnTestMouseOver: TOnTestMouseOver;
begin Result := EV.fOnTestMouseOver; end;
function TControl.Get_OnEndEditLVItem: TOnEditLVItem;
begin Result := EV.fOnEndEditLVItem; end;
function TControl.Get_OnDeleteLVItem: TOnDeleteLVItem;
begin Result := EV.fOnDeleteLVItem; end;
function TControl.Get_OnLVData: TOnLVData;
begin Result := EV.fOnLVData; end;
function TControl.Get_OnCompareLVItems: TOnCompareLVItems;
begin Result := EV.fOnCompareLVItems; end;
procedure TControl.Set_OnCompareLVItems(const Value: TOnCompareLVItems);
begin ProvideUniqueEvents.fOnCompareLVItems := Value; end;
function TControl.Get_OnColumnClick: TOnLVColumnClick;
begin Result := EV.fOnColumnClick; end;
function TControl.Get_OnLVStateChange: TOnLVStateChange;
begin Result := EV.FOnLVStateChange; end;
function TControl.Get_OnDrawItem: TOnDrawItem;
begin Result := EV.fOnDrawItem; end;
function TControl.Get_OnLVCustomDraw: TOnLVCustomDraw;
begin Result := EV.fOnLVCustomDraw; end;
function TControl.Get_OnLVSubitemDraw: TOnLVSubitemDraw;
begin Result := TOnLVSubitemDraw( EV.fOnLVCustomDraw ); end;
function TControl.Get_OnTVBeginDrag: TOnTVBeginDrag;
begin Result := EV.FOnTVBeginDrag; end;
procedure TControl.Set_OnTVBeginDrag(const Value: TOnTVBeginDrag);
begin ProvideUniqueEvents.FOnTVBeginDrag := Value; end;
function TControl.Get_OnTVBeginEdit: TOnTVBeginEdit;
begin Result := EV.FOnTVBeginEdit; end;
procedure TControl.Set_OnTVBeginEdit(const Value: TOnTVBeginEdit);
begin ProvideUniqueEvents.FOnTVBeginEdit := Value; end;
function TControl.Get_OnTVEndEdit: TOnTVEndEdit;
begin Result := EV.FOnTVEndEdit; end;
procedure TControl.Set_OnTVEndEdit(const Value: TOnTVEndEdit);
begin ProvideUniqueEvents.fOnTVEndEdit := Value; end;
function TControl.Get_OnTVExpanding: TOnTVExpanding;
begin Result := EV.FOnTVExpanding; end;
procedure TControl.Set_OnTVExpanding(const Value: TOnTVExpanding);
begin ProvideUniqueEvents.FOnTVExpanding := Value; end;
function TControl.Get_OnTVExpanded: TOnTVExpanded;
begin Result := EV.FOnTVExpanded; end;
procedure TControl.Set_OnTVExpanded(const Value: TOnTVExpanded);
begin ProvideUniqueEvents.FOnTVExpanded := Value; end;
function TControl.Get_OnTVDelete: TOnTVDelete;
begin Result := EV.FOnTVDelete; end;
function TControl.Get_OnTVSelChanging: TOnTVSelChanging;
begin Result := EV.fOnTVSelChanging; end;
procedure TControl.Set_OnTVSelChanging(const Value: TOnTVSelChanging);
begin ProvideUniqueEvents.FOnTVSelChanging := Value; end;
function TControl.Get_OnDTPUserString: TDTParseInputEvent;
begin Result := EV.FOnDTPUserString; end;
procedure TControl.Set_OnDTPUserString(const Value: TDTParseInputEvent);
begin ProvideUniqueEvents.FOnDTPUserString := Value; end;
function TControl.Get_OnSBBeforeScroll: TOnSBBeforeScroll;
begin Result := EV.FOnSBBeforeScroll; end;
procedure TControl.Set_OnSBBeforeScroll(const Value: TOnSBBeforeScroll);
begin ProvideUniqueEvents.fOnSBBeforeScroll := Value; end;
function TControl.Get_OnSBScroll: TOnSBScroll;
begin Result := EV.FOnSBScroll; end;
procedure TControl.Set_OnSBScroll(const Value: TOnSBScroll);
begin ProvideUniqueEvents.FOnSBScroll := Value; end;
function TControl.Get_OnScroll: TOnScroll;
begin Result := EV.fOnScroll; end;
function TControl.Get_OnMessage: TOnMessage;
begin Result := EV.fOnMessage; end;
procedure TControl.Set_OnMessage(const Value: TOnMessage);
begin ProvideUniqueEvents.fOnMessage := Value; end;
function TControl.Get_TOnEvent(const Index: Integer): TOnEvent;
begin Result := TOnEvent( EV.MethodEvents[Index] ); end;
procedure TControl.Set_TOnEvent(const Index: Integer; const Value: TOnEvent);
begin ProvideUniqueEvents.MethodEvents[Index] := TMethod( Value ); end;
function TControl.Get_OnDropFiles: TOnDropFiles;
begin Result := EV.fOnDropFiles; end;
{$ENDIF EVENTS_DYNAMIC}//-------------------------------------------------------
{$IFnDEF NOT_USE_RICHEDIT}
procedure TControl.FreeCharFormatRec;
begin {$IFnDEF STATIC_RICHEDIT_DATA} FreeMem( DF.fRECharFormatRec ); {$ENDIF} end;
{$ENDIF}
function TControl.GetAnchor(const Index: Integer): Boolean;
begin Result := fAnchors and Index <> 0; end;
procedure TControl.SetAnchor(const Index: Integer; const Value: Boolean);
begin if   Value then
           fAnchors := fAnchors or Index
      else fAnchors := fAnchors and not Index;
      if  Parent <> nil then
      begin
          fParent.AttachProc( ParentAnchorChildren );
          Parent.fOldWidth := Parent.ClientWidth;
          Parent.fOldHeight := Parent.ClientHeight;
      end;
end;////////////////////////////////////////////////////////////////////////////
function TControl.Get_StatusWnd: HWND;
begin Result := 0;
      if  fStatusCtl <> nil then
          Result := fStatusCtl.GetWindowHandle;
end;////////////////////////////////////////////////////////////////////////////
function TControl.Get_Prop_Int(PropName: PKOLChar): Integer;
begin Result := GetProp( GetWindowHandle, PropName ); end;
procedure TControl.Set_Prop_Int(PropName: PKOLChar; const Value: Integer);
begin SetProp( GetWindowHandle, PropName, Value ); end;
function TControl.GetHelpContext: Integer;
begin Result := 0;
      if  fHandle <> 0 then
          Result := GetWindowContextHelpId( fHandle );
end;////////////////////////////////////////////////////////////////////////////
function TControl.Get_Ctl3D: Boolean;
begin Result := fCtl3D_child and 2 <> 0; end;
procedure TControl.ResetEvent(idx: Integer);
begin TMethod( EV.MethodEvents[idx] ).Code := DummyProcTable[ InitEventsTable[ idx ] and $F ];
      TMethod( EV.MethodEvents[idx] ).Data := nil;
end;////////////////////////////////////////////////////////////////////////////
{$IFDEF COMMANDACTIONS_OBJ}
{ TCommandActionsObj }
{$IFDEF ASM_VERSION}////////////////////////////////////////////////////////////
destructor TCommandActionsObj.Destroy;
asm MOV  EDX, [EAX].fIndexInActions
    MOV  dword ptr [EDX*4+AllActions_Objs], 0
    CALL TObj.Destroy
end; {$ELSE}////////////////////////////////////////////////////////////////////
destructor TCommandActionsObj.Destroy;
begin AllActions_Objs[fIndexInActions] := nil;
      inherited;
end; {$ENDIF}///////////////////////////////////////////////////////////////////
{$ENDIF}
{$IFDEF GRAPHCTL_XPSTYLES}{$DEFINE INIT_FINIT}{$ENDIF}
{$IFDEF USE_NAMES}{$DEFINE INIT_FINIT}{$ENDIF}
{$IFNDEF NOT_UNLOAD_RICHEDITLIB}{$IFDEF UNLOAD_RICHEDITLIB}
         {$DEFINE INIT_FINIT}
{$ENDIF}{$ENDIF}
{$IFDEF INIT_FINIT}//-----------------------------------------------------------
//******************************************************************************
initialization //...............................................................
{$IFDEF GRAPHCTL_XPSTYLES}
 CheckThemes;
 if  AppTheming then
     InitThemes;
{$ENDIF}
finalization //.................................................................
{$IFDEF GRAPHCTL_XPSTYLES}
 if  AppTheming then
     DeinitThemes;
{$ENDIF}
{$IFNDEF NOT_UNLOAD_RICHEDITLIB}
{$IFDEF UNLOAD_RICHEDITLIB}
  if  FRichEditModule <> 0 then
      FreeLibrary( FRichEditModule );
{$ENDIF UNLOAD_RICHEDITLIB}
{$ENDIF}
{$ENDIF INIT_FINIT}//-----------------------------------------------------------

end.
