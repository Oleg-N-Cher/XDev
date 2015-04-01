MODULE MoveWindow;
(* Simple moving window application by Alexander Iljin, June 08, 2006. *)
(* http://oberoncore.ru/wiki/blackbox/make_exe *)
 
IMPORT SYSTEM, W := WinApi;

CONST
  defFontName = "Verdana";
  iconId = 1;
  HWND_TOPMOST = -1; (* this constant is not present in WinApi module *)

VAR
  defMessage: ARRAY 1024 OF CHAR;
  instance: W.HINSTANCE;
  mainWnd: W.HWND;
  defaultBrush: W.HBRUSH;
  defaultFont: W.HFONT;
 
PROCEDURE Append* (VAR to: ARRAY OF CHAR; IN this: ARRAY OF CHAR);
VAR
  i, j, l: LONGINT;
BEGIN
  i := 0; WHILE to[i] # 0X DO INC(i) END;
  l := LEN(to)-1; j := 0;
  WHILE (i < l) & (this[j] # 0X) DO
    to[i] := this[j]; INC(i); INC(j)
  END;
  to[i] := 0X
END Append;

PROCEDURE MoveMainWindow;
CONST
  NumSteps = 50;
VAR
  i, res: INTEGER; rect: W.RECT;
  left, top, width, height: INTEGER; (* original window parameters *)
BEGIN
  (* remember original window position *)
  res := W.GetWindowRect(mainWnd, rect);
  IF res = 0 THEN RETURN END;
 
  left := rect.left;
  top := rect.top;
  width := rect.right - left;
  height := rect.bottom - top;
  (* move window *)
  i := 0;
  res := 1;
  WHILE (i < NumSteps) & (res # 0) DO
    INC(rect.top, 10);
    INC(rect.left, 10);
    res := W.SetWindowPos(
      mainWnd, SYSTEM.VAL(W.HWND, HWND_TOPMOST), rect.left,
      rect.top, width, height, W.SWP_SHOWWINDOW
    );
    INC(i);
  END;
  (* restore original window position *)
  res := W.SetWindowPos(
    mainWnd, SYSTEM.VAL(W.HWND, HWND_TOPMOST),
    left, top, width, height, W.SWP_SHOWWINDOW
  );
END MoveMainWindow;
 
PROCEDURE [1] WndHandler (
  wnd: W.HWND; msg: INTEGER; wParam, lParam: W.HANDLE): W.HANDLE;
VAR
  res: INTEGER; ps: W.PAINTSTRUCT; dc: W.HDC; rect: W.RECT;
BEGIN
  CASE msg OF
  | W.WM_DESTROY:
      res := W.DeleteObject(defaultBrush);
      res := W.DeleteObject(defaultFont);
      W.PostQuitMessage(0);
  | W.WM_PAINT:
      dc := W.BeginPaint(wnd, ps);
      res := W.SetBkMode(dc, W.TRANSPARENT);
      IF W.SelectObject(dc, defaultFont) # NIL THEN END;
      res := W.GetClientRect(wnd, rect);
      defMessage := "Click me";
      Append(defMessage, 0DX); Append(defMessage, 0AX);
      Append(defMessage, "Esc - exit");
      res := W.DrawText(
        dc, SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(defMessage)),
        -1, rect, W.DT_WORDBREAK + W.DT_CENTER
      );
      res := W.EndPaint(wnd, ps);
  | W.WM_CHAR:
      IF SYSTEM.VAL(INTEGER, wParam) = W.VK_ESCAPE THEN
        W.PostQuitMessage(0);
      ELSE
        MoveMainWindow;
      END;
  | W.WM_LBUTTONDOWN:
      MoveMainWindow;
  ELSE
    RETURN W.DefWindowProc(wnd, msg, wParam, lParam)
  END;
  RETURN NIL
END WndHandler;

PROCEDURE OpenWindow;
VAR
  class: W.WNDCLASS; res: INTEGER;
BEGIN
  defaultBrush := W.CreateSolidBrush(W.GetSysColor(W.COLOR_BTNFACE));
  defaultFont := W.CreateFont(
    -20, 0, 0, W.FW_REGULAR, 0, 0, 0, 0, W.DEFAULT_CHARSET,
    W.OUT_DEFAULT_PRECIS, W.CLIP_DEFAULT_PRECIS, W.DEFAULT_QUALITY,
    W.DEFAULT_PITCH, SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(defFontName))
  );
  class.hCursor := W.LoadCursor(NIL, SYSTEM.VAL(W.HCURSOR, W.IDC_ARROW));
  class.hIcon := W.LoadIcon(instance, SYSTEM.VAL(W.HICON, iconId));
  class.lpszMenuName := NIL;
  class.lpszClassName := SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR("MoveWin"));
  class.hbrBackground := defaultBrush;
  class.style := W.CS_VREDRAW + W.CS_HREDRAW;
  class.hInstance := instance;
  class.lpfnWndProc := WndHandler;
  class.cbClsExtra := 0;
  class.cbWndExtra := 0;
  res := W.RegisterClass(class);
  mainWnd := W.CreateWindowEx(
    W.WS_EX_TOPMOST, SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR("MoveWin")),
    SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR("MoveWin")), W.WS_OVERLAPPEDWINDOW,
    100, 100, 100, 100, NIL, NIL, instance, NIL
  );
  res := W.ShowWindow(mainWnd, W.SW_SHOWDEFAULT);
  res := W.UpdateWindow(mainWnd);
END OpenWindow;
 
PROCEDURE MainLoop;
VAR
  msg: W.MSG; res: INTEGER;
BEGIN
  WHILE W.GetMessage(msg, NIL, 0, 0) # 0 DO
    res := W.TranslateMessage(msg);
    res := W.DispatchMessage(msg);
  END;
  W.ExitProcess(SYSTEM.VAL(INTEGER, msg.wParam))
END MainLoop;
 
BEGIN (*$MAIN*)
  instance := W.GetModuleHandle(NIL);
  OpenWindow;
  MainLoop;
END MoveWindow.
