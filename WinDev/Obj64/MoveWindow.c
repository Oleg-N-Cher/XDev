/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "WinApi.h"


static CHAR MoveWindow_defMessage[1024];
static SYSTEM_PTR MoveWindow_instance, MoveWindow_mainWnd, MoveWindow_defaultBrush, MoveWindow_defaultFont;


export void MoveWindow_Append (CHAR *to, LONGINT to__len, CHAR *this, LONGINT this__len);
static void MoveWindow_MainLoop (void);
static void MoveWindow_MoveMainWindow (void);
static void MoveWindow_OpenWindow (void);
static INTEGER MoveWindow_WndHandler (SYSTEM_PTR wnd, INTEGER msg, INTEGER wParam, INTEGER lParam);


/*============================================================================*/

void MoveWindow_Append (CHAR *to, LONGINT to__len, CHAR *this, LONGINT this__len)
{
	LONGINT i, j, l;
	i = 0;
	while (to[__X(i, to__len)] != 0x00) {
		i += 1;
	}
	l = to__len - 1;
	j = 0;
	while (i < l && this[__X(j, this__len)] != 0x00) {
		to[__X(i, to__len)] = this[__X(j, this__len)];
		i += 1;
		j += 1;
	}
	to[__X(i, to__len)] = 0x00;
}

/*----------------------------------------------------------------------------*/
static void MoveWindow_MoveMainWindow (void)
{
	INTEGER i, res;
	WinApi_RECT rect;
	INTEGER left, top, width, height;
	res = WinApi_GetWindowRect(MoveWindow_mainWnd, &rect, WinApi_RECT__typ);
	if (res == 0) {
		return;
	}
	left = rect.left;
	top = rect.top;
	width = rect.right - left;
	height = rect.bottom - top;
	i = 0;
	res = 1;
	while (i < 50 && res != 0) {
		rect.top += 10;
		rect.left += 10;
		res = WinApi_SetWindowPos(MoveWindow_mainWnd, (SYSTEM_PTR)-1, rect.left, rect.top, width, height, 0x40);
		i += 1;
	}
	res = WinApi_SetWindowPos(MoveWindow_mainWnd, (SYSTEM_PTR)-1, left, top, width, height, 0x40);
}

static INTEGER MoveWindow_WndHandler (SYSTEM_PTR wnd, INTEGER msg, INTEGER wParam, INTEGER lParam)
{
	INTEGER res;
	WinApi_PAINTSTRUCT ps;
	SYSTEM_PTR dc = NIL;
	WinApi_RECT rect;
	switch (msg) {
		case 2: 
			res = WinApi_DeleteObject(MoveWindow_defaultBrush);
			res = WinApi_DeleteObject(MoveWindow_defaultFont);
			WinApi_PostQuitMessage(0);
			break;
		case 15: 
			dc = WinApi_BeginPaint(wnd, &ps, WinApi_PAINTSTRUCT__typ);
			res = WinApi_SetBkMode(dc, 1);
			if (WinApi_SelectObject(dc, MoveWindow_defaultFont) != NIL) {
			}
			res = WinApi_GetClientRect(wnd, &rect, WinApi_RECT__typ);
			__MOVE("Click me", MoveWindow_defMessage, 9);
			MoveWindow_Append((void*)MoveWindow_defMessage, 1024, (void*)&"", (LONGINT)2);
			MoveWindow_Append((void*)MoveWindow_defMessage, 1024, (void*)&"
", (LONGINT)2);
			MoveWindow_Append((void*)MoveWindow_defMessage, 1024, (void*)&"Esc - exit", (LONGINT)11);
			res = WinApi_DrawText(dc, (SYSTEM_PTR)((LONGINT)MoveWindow_defMessage), -1, &rect, WinApi_RECT__typ, 0x11);
			res = WinApi_EndPaint(wnd, &ps, WinApi_PAINTSTRUCT__typ);
			break;
		case 258: 
			if (wParam == 27) {
				WinApi_PostQuitMessage(0);
			} else {
				MoveWindow_MoveMainWindow();
			}
			break;
		case 513: 
			MoveWindow_MoveMainWindow();
			break;
		default: 
			return WinApi_DefWindowProc(wnd, msg, wParam, lParam);
			break;
	}
	return 0;
}

static void MoveWindow_OpenWindow (void)
{
	WinApi_WNDCLASSA class;
	INTEGER res;
	MoveWindow_defaultBrush = WinApi_CreateSolidBrush(WinApi_GetSysColor(15));
	MoveWindow_defaultFont = WinApi_CreateFont(-20, 0, 0, 400, 0, 0, 0, 0, 1, 0, 0, 0, 0, (SYSTEM_PTR)((LONGINT)"Verdana"));
	class.hCursor = WinApi_LoadCursor(NIL, (SYSTEM_PTR)32512);
	class.hIcon = WinApi_LoadIcon(MoveWindow_instance, (SYSTEM_PTR)1);
	class.lpszMenuName = NIL;
	class.lpszClassName = (SYSTEM_PTR)((LONGINT)"MoveWin");
	class.hbrBackground = MoveWindow_defaultBrush;
	class.style = 0x03;
	class.hInstance = MoveWindow_instance;
	class.lpfnWndProc = MoveWindow_WndHandler;
	class.cbClsExtra = 0;
	class.cbWndExtra = 0;
	res = WinApi_RegisterClass(&class, WinApi_WNDCLASSA__typ);
	MoveWindow_mainWnd = WinApi_CreateWindowEx(0x08, (SYSTEM_PTR)((LONGINT)"MoveWin"), (SYSTEM_PTR)((LONGINT)"MoveWin"), 0xcf0000, 100, 100, 100, 100, NIL, NIL, MoveWindow_instance, NIL);
	res = WinApi_ShowWindow(MoveWindow_mainWnd, 10);
	res = WinApi_UpdateWindow(MoveWindow_mainWnd);
}

static void MoveWindow_MainLoop (void)
{
	WinApi_MSG msg;
	INTEGER res;
	while (WinApi_GetMessage(&msg, WinApi_MSG__typ, NIL, 0, 0) != 0) {
		res = WinApi_TranslateMessage(&msg, WinApi_MSG__typ);
		res = WinApi_DispatchMessage(&msg, WinApi_MSG__typ);
	}
	WinApi_ExitProcess(msg.wParam);
}

static void EnumPtrs(void (*P)(void*))
{
	P(MoveWindow_instance);
	P(MoveWindow_mainWnd);
	P(MoveWindow_defaultBrush);
	P(MoveWindow_defaultFont);
}


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(WinApi__init);
	__REGMAIN("MoveWindow", EnumPtrs);
/* BEGIN */
	MoveWindow_instance = WinApi_GetModuleHandle(NIL);
	MoveWindow_OpenWindow();
	MoveWindow_MainLoop();
	__FINI;
}
