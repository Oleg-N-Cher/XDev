MODULE MoveWindow;
(* Simple moving window application by Alexander Iljin, June 08, 2006. *)
(* http://oberoncore.ru/wiki/blackbox/make_exe *)
 
IMPORT SYSTEM, W := WinAPI;

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
 
PROCEDURE MoveMainWindow;
CONST
  NumSteps = 50;
VAR
  i, res: INTEGER; rect: W.RECT;
  left, top, width, height: INTEGER; (* original window parameters *)
BEGIN
  (* remember original window position *)
  res := W.GetWindowRect(mainWnd, @rect);
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
      mainWnd, HWND_TOPMOST, rect.left,
      rect.top, width, height, W.SWP_SHOWWINDOW
    );
    INC(i);
  END;
  (* restore original window position *)
  res := W.SetWindowPos(
    mainWnd, HWND_TOPMOST,
    left, top, width, height, W.SWP_SHOWWINDOW
  );
END MoveMainWindow;
 
PROCEDURE [stdcall] WndHandler (
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
      dc := W.BeginPaint(wnd, @ps);
      res := W.SetBkMode(dc, W.TRANSPARENT);
      IF W.SelectObject(dc, defaultFont) # 0 THEN END;
      res := W.GetClientRect(wnd, @rect);
      defMessage := "Click me||Esc - exit";
      defMessage[8] := 0DX; defMessage[9] := 0AX;
      res := W.DrawText(
        dc, SYSTEM.ADR(defMessage),
        -1, @rect, W.DT_WORDBREAK + W.DT_CENTER
      );
      res := W.EndPaint(wnd, @ps);
  | W.WM_CHAR:
      IF wParam = W.VK_ESCAPE THEN
        W.PostQuitMessage(0);
      ELSE
        MoveMainWindow;
      END;
  | W.WM_LBUTTONDOWN:
      MoveMainWindow;
  ELSE
    RETURN W.DefWindowProc(wnd, msg, wParam, lParam)
  END;
  RETURN 0
END WndHandler;

PROCEDURE OpenWindow;
VAR
  class: W.WNDCLASS; res: INTEGER;
BEGIN
  defaultBrush := W.CreateSolidBrush(W.GetSysColor(W.COLOR_BTNFACE));
  defaultFont := W.CreateFont(
    -20, 0, 0, W.FW_REGULAR, 0, 0, 0, 0, W.DEFAULT_CHARSET,
    W.OUT_DEFAULT_PRECIS, W.CLIP_DEFAULT_PRECIS, W.DEFAULT_QUALITY,
    W.DEFAULT_PITCH, SYSTEM.ADR(defFontName)
  );
  class.hCursor := W.LoadCursor(0, W.IDC_ARROW);
  class.hIcon := W.LoadIcon(instance, iconId);
  class.lpszMenuName := 0;
  class.lpszClassName := SYSTEM.ADR("MoveWin");
  class.hbrBackground := defaultBrush;
  class.style := W.CS_VREDRAW + W.CS_HREDRAW;
  class.hInstance := instance;
  class.lpfnWndProc := WndHandler;
  class.cbClsExtra := 0;
  class.cbWndExtra := 0;
  res := W.RegisterClass(@class);
  mainWnd := W.CreateWindowEx(
    W.WS_EX_TOPMOST, SYSTEM.ADR("MoveWin"),
    SYSTEM.ADR("MoveWin"), W.WS_OVERLAPPEDWINDOW,
    SYSTEM.VAL(INTEGER, W.CW_USEDEFAULT), 0, 210, 100, 0, 0, instance, 0
  );
  res := W.ShowWindow(mainWnd, W.SW_SHOWDEFAULT);
  res := W.UpdateWindow(mainWnd);
END OpenWindow;
 
PROCEDURE MainLoop;
VAR
  msg: W.MSG; res: INTEGER;
BEGIN
  WHILE W.GetMessage(@msg, 0, 0, 0) # 0 DO
    res := W.TranslateMessage(@msg);
    res := W.DispatchMessage(@msg);
  END;
END MainLoop;
 
BEGIN (*$MAIN*)
  instance := W.GetModuleHandle(0);
  OpenWindow;
  MainLoop;
END MoveWindow.
