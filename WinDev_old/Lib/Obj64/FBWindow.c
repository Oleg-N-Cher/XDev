/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "WinApi.h"




export SYSTEM_PTR FBWindow_OpenWindow (CHAR *name, LONGINT name__len, INTEGER x, INTEGER y, INTEGER width, INTEGER height);
export SYSTEM_PTR FBWindow_OpenWindowEx (CHAR *name, LONGINT name__len, INTEGER x, INTEGER y, INTEGER width, INTEGER height, SET style1, SET style2);


/*============================================================================*/

SYSTEM_PTR FBWindow_OpenWindowEx (CHAR *name, LONGINT name__len, INTEGER x, INTEGER y, INTEGER width, INTEGER height, SET style1, SET style2)
{
	WinApi_WNDCLASSEXA wc;
	INTEGER err;
	SYSTEM_PTR hwn = NIL;
	wc.cbSize = 80;
	wc.style = 0x03;
	wc.hInstance = WinApi_GetModuleHandle(NIL);
	wc.hbrBackground = (SYSTEM_PTR)16;
	wc.hIcon = WinApi_LoadIcon(NIL, (SYSTEM_PTR)32512);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = WinApi_LoadCursor(NIL, (SYSTEM_PTR)32512);
	if (WinApi_RegisterClassEx(&wc, WinApi_WNDCLASSEXA__typ) == 0) {
		err = WinApi_GetLastError();
		return NIL;
	}
	hwn = WinApi_CreateWindowEx(style2, NIL, (SYSTEM_PTR)((LONGINT)name), style1, x, y, width, height, NIL, NIL, NIL, NIL);
	return hwn;
}

/*----------------------------------------------------------------------------*/
SYSTEM_PTR FBWindow_OpenWindow (CHAR *name, LONGINT name__len, INTEGER x, INTEGER y, INTEGER width, INTEGER height)
{
	return FBWindow_OpenWindowEx((void*)name, name__len, x, y, width, height, 0x10cf0000, 0x0);
}

/*----------------------------------------------------------------------------*/

export void *FBWindow__init(void)
{
	__DEFMOD;
	__IMPORT(WinApi__init);
	__REGMOD("FBWindow", 0);
/* BEGIN */
	__ENDMOD;
}
