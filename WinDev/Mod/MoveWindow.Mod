MODULE MoveWindow; (*$MAIN*)
(* Simple moving window application by Alexander Iljin, June 08, 2006. *)
(* http://oberoncore.ru/wiki/blackbox/make_exe *)
 
   IMPORT SYSTEM, WinApi;
 
   CONST
      defFontName = "Verdana";
      iconId = 1;
      HWND_TOPMOST = -1; (* this constant is not present in WinApi module *)

   VAR
      defMessage: ARRAY 1024 OF CHAR;
      instance: WinApi.HINSTANCE;
      mainWnd: WinApi.HWND;
      defaultBrush: WinApi.HBRUSH;
      defaultFont: WinApi.HFONT;
 
  PROCEDURE Append* (VAR to: ARRAY OF CHAR; IN this: ARRAY OF CHAR);
    VAR i, j, l: LONGINT;
  BEGIN
    i := 0; WHILE to[i] # 0X DO INC(i) END;
    l := LEN(to)-1; j := 0;
    WHILE (i < l) & (this[j] # 0X) DO
      to[i] := this[j]; INC(i); INC(j)
    END;
    to[i] := 0X
  END Append;

   PROCEDURE MoveMainWindow;
      CONST numSteps = 50;
      VAR
         i, res: INTEGER; rect: WinApi.RECT;
         left, top, width, height: INTEGER; (* original window parameters *)
   BEGIN
      (* remember original window position *)
      res := WinApi.GetWindowRect(mainWnd, rect);
      IF res = 0 THEN RETURN END;
 
      left := rect.left;
      top := rect.top;
      width := rect.right - left;
      height := rect.bottom - top;
      (* move window *)
      i := 0;
      res := 1;
      WHILE (i < numSteps) & (res # 0) DO
         INC(rect.top, 10);
         INC(rect.left, 10);
         res := WinApi.SetWindowPos(
            mainWnd, SYSTEM.VAL(WinApi.HWND, HWND_TOPMOST), rect.left, rect.top, width, height, WinApi.SWP_SHOWWINDOW
         );
         INC(i);
      END;
      (* restore original window position *)
      res := WinApi.SetWindowPos(
         mainWnd, SYSTEM.VAL(WinApi.HWND, HWND_TOPMOST), left, top, width, height, WinApi.SWP_SHOWWINDOW
      );
   END MoveMainWindow;
 
 
   PROCEDURE WndHandler (wnd: WinApi.HWND; msg, wParam, lParam: INTEGER): INTEGER;
      VAR
         res: INTEGER; ps: WinApi.PAINTSTRUCT; dc: WinApi.HDC; rect: WinApi.RECT;
   BEGIN
      CASE msg OF
      | WinApi.WM_DESTROY:
         res := WinApi.DeleteObject(defaultBrush);
         res := WinApi.DeleteObject(defaultFont);
         WinApi.PostQuitMessage(0)
      | WinApi.WM_PAINT:
         dc := WinApi.BeginPaint(wnd, ps);
         res := WinApi.SetBkMode(dc, WinApi.TRANSPARENT);
         IF WinApi.SelectObject(dc, defaultFont) # NIL THEN END;;
         res := WinApi.GetClientRect(wnd, rect);
         defMessage := "Click me";
         Append(defMessage, 0DX); Append(defMessage, 0AX);
         Append(defMessage, "Esc - exit");
         res := WinApi.DrawText(
            dc, SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR(defMessage)), -1, rect, WinApi.DT_WORDBREAK + WinApi.DT_CENTER
         );
         res := WinApi.EndPaint(wnd, ps)
      | WinApi.WM_CHAR:
         IF wParam = WinApi.VK_ESCAPE THEN
            WinApi.PostQuitMessage(0)
         ELSE
            MoveMainWindow
         END
      | WinApi.WM_LBUTTONDOWN:
         MoveMainWindow
      ELSE
         RETURN WinApi.DefWindowProc(wnd, msg, wParam, lParam)
      END;
      RETURN 0
   END WndHandler;
 
 
   PROCEDURE OpenWindow;
      VAR
         class: WinApi.WNDCLASS; res: INTEGER;
   BEGIN
      defaultBrush := WinApi.CreateSolidBrush(WinApi.GetSysColor(WinApi.COLOR_BTNFACE));
      defaultFont := WinApi.CreateFont(
         -20, 0, 0, WinApi.FW_REGULAR, 0, 0, 0, 0, WinApi.DEFAULT_CHARSET,
         WinApi.OUT_DEFAULT_PRECIS, WinApi.CLIP_DEFAULT_PRECIS, WinApi.DEFAULT_QUALITY,
         WinApi.DEFAULT_PITCH, SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR(defFontName))
      );
      class.hCursor := WinApi.LoadCursor(NIL, SYSTEM.VAL(WinApi.HCURSOR, WinApi.IDC_ARROW));
      class.hIcon := WinApi.LoadIcon(instance, SYSTEM.VAL(WinApi.HICON, iconId));
      class.lpszMenuName := NIL;
      class.lpszClassName := SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("MoveWin"));
      class.hbrBackground := defaultBrush;
      class.style := WinApi.CS_VREDRAW + WinApi.CS_HREDRAW;
      class.hInstance := instance;
      class.lpfnWndProc := WndHandler;
      class.cbClsExtra := 0;
      class.cbWndExtra := 0;
      res := WinApi.RegisterClass(class);
      mainWnd := WinApi.CreateWindowEx(
         WinApi.WS_EX_TOPMOST, SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("MoveWin")), SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("MoveWin")), WinApi.WS_OVERLAPPEDWINDOW,
         100, 100, 100, 100, NIL, NIL, instance, NIL
      );
      res := WinApi.ShowWindow(mainWnd, WinApi.SW_SHOWDEFAULT);
      res := WinApi.UpdateWindow(mainWnd);
   END OpenWindow;
 
 
   PROCEDURE MainLoop;
      VAR
         msg: WinApi.MSG; res: INTEGER;
   BEGIN
      WHILE WinApi.GetMessage(msg, NIL, 0, 0) # 0 DO
         res := WinApi.TranslateMessage(msg);
         res := WinApi.DispatchMessage(msg);
      END;
      WinApi.ExitProcess(msg.wParam)
   END MainLoop;
 
 
BEGIN
   instance := WinApi.GetModuleHandle(NIL);
   OpenWindow;
   MainLoop
END MoveWindow.