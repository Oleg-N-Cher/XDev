/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Delphi.h"
#include "Ignore.h"
#include "WinApi.h"

typedef
	struct Clock_TIME {
		INTEGER hour, minute, second;
	} Clock_TIME;

typedef
	INTEGER Clock_arrPOINT[120];

typedef
	CHAR (*Clock_pszTooManyPtr)[512];


static BOOLEAN Clock_bFirst;
static INTEGER Clock_TimerID;
static BOOLEAN Clock_bIconic;
static SYSTEM_PTR Clock_Instance;
__CONSTARR Clock_arrPOINT CirTabConst =
	{0,-7999,836,-7956,1663,-7825,2472,-7608,3253,-7308,
	3999,-6928,4702,-6472,5353,-5945,5945,-5353,6472,-4702,
	6928,-4000,7308,-3253,7608,-2472,7825,-1663,7956,-836,
	8000,0,7956,836,7825,1663,7608,2472,7308,3253,
	6928,4000,6472,4702,5945,5353,5353,5945,4702,6472,
	3999,6928,3253,7308,2472,7608,1663,7825,836,7956,
	0,7999,-836,7956,-1663,7825,-2472,7608,-3253,7308,
	-4000,6928,-4702,6472,-5353,5945,-5945,5353,-6472,4702,
	-6928,3999,-7308,3253,-7608,2472,-7825,1663,-7956,836,
	-7999,0,-7956,-836,-7825,-1663,-7608,-2472,-7308,-3253,
	-6928,-4000,-6472,-4702,-5945,-5353,-5353,-5945,-4702,-6472,
	-3999,-6928,-3253,-7308,-2472,-7608,-1663,-7825,-836,-7956};
static Clock_TIME Clock_oTime;
static SYSTEM_PTR Clock_hbrForegnd, Clock_hbrBackgnd, Clock_hpenForegnd, Clock_hpenBackgnd;
static Clock_arrPOINT Clock_CirTab;
static CHAR Clock_szBuffer[31];
static WinApi_RECT Clock_ClockRect;
static INTEGER Clock_ClockRadius;
static WinApi_POINT Clock_ClockCenter;
static INTEGER Clock_HRes, Clock_VRes, Clock_AspectH, Clock_AspectV;
static SYSTEM_PTR Clock_Wnd;
static WinApi_MSG Clock_mess;
static SYSTEM_PTR Clock_Menu;
static Clock_TIME Clock_nTime;
static INTEGER Clock_sysWidth, Clock_sysHeight, Clock_width, Clock_height;
static Clock_pszTooManyPtr Clock_pszTooMany;

export LONGINT *Clock_TIME__typ;

static SYSTEM_PTR __CALL_1 Clock_AboutProc (SYSTEM_PTR hDlg, INTEGER message, SYSTEM_PTR wParam, SYSTEM_PTR lParam);
static void Clock_CircleClock (INTEGER maxWidth, INTEGER maxHeight);
static void Clock_ClockCreate (void);
static BOOLEAN Clock_ClockInit (void);
static void Clock_ClockPaint (SYSTEM_PTR dc, INTEGER paintType);
static void Clock_ClockSize (SYSTEM_PTR w, INTEGER newWidth, INTEGER newHeight, INTEGER sizeType);
static void Clock_ClockTimer (SYSTEM_PTR w);
static SYSTEM_PTR __CALL_1 Clock_ClockWndProc (SYSTEM_PTR wnd, INTEGER message, SYSTEM_PTR wParam, SYSTEM_PTR lParam);
static void Clock_CreateTools (void);
static void Clock_DeleteTools (void);
static void Clock_DrawFace (SYSTEM_PTR DC);
static void Clock_DrawFatHand (SYSTEM_PTR DC, INTEGER pos, SYSTEM_PTR Pen, INTEGER whichHand);
static void Clock_DrawHand (SYSTEM_PTR DC, INTEGER pos, SYSTEM_PTR Pen, INTEGER scale, INTEGER patMode);
static void Clock_GetTime (Clock_TIME *t, LONGINT *t__typ);
static INTEGER Clock_HorzEquiv (INTEGER l);
static INTEGER Clock_HourHandPos (Clock_TIME t);
static INTEGER Clock_VertEquiv (INTEGER l);


/*============================================================================*/

static void Clock_GetTime (Clock_TIME *t, LONGINT *t__typ)
{
	WinApi_SYSTEMTIME dt;
	WinApi_GetLocalTime(&dt, WinApi_SYSTEMTIME__typ);
	(*t).hour = dt.wHour;
	(*t).minute = dt.wMinute;
	(*t).second = dt.wSecond;
}

static INTEGER Clock_HourHandPos (Clock_TIME t)
{
	if (t.hour < 12) {
		return t.hour * 5 + __DIV(t.minute, 12);
	} else {
		return (t.hour - 12) * 5 + __DIV(t.minute, 12);
	}
	__RETCHK;
}

static INTEGER Clock_VertEquiv (INTEGER l)
{
	return __DIV(l * Clock_AspectV, Clock_AspectH);
}

static INTEGER Clock_HorzEquiv (INTEGER l)
{
	return __DIV(l * Clock_AspectH, Clock_AspectV);
}

static void Clock_CreateTools (void)
{
	Clock_hbrForegnd = WinApi_CreateSolidBrush(WinApi_GetSysColor(8));
	Clock_hbrBackgnd = WinApi_CreateSolidBrush(WinApi_GetSysColor(5));
	Clock_hpenForegnd = WinApi_CreatePen(0, 1, WinApi_GetSysColor(8));
	Clock_hpenBackgnd = WinApi_CreatePen(0, 1, WinApi_GetSysColor(5));
}

static void Clock_DeleteTools (void)
{
	Ignore_Int(WinApi_DeleteObject(Clock_hbrForegnd));
	Ignore_Int(WinApi_DeleteObject(Clock_hbrBackgnd));
	Ignore_Int(WinApi_DeleteObject(Clock_hpenForegnd));
	Ignore_Int(WinApi_DeleteObject(Clock_hpenBackgnd));
}

static void Clock_ClockCreate (void)
{
	INTEGER pos, vSize, hSize;
	SYSTEM_PTR dc = NIL;
	dc = WinApi_GetDC(NIL);
	Clock_VRes = WinApi_GetDeviceCaps(dc, 10);
	Clock_HRes = WinApi_GetDeviceCaps(dc, 8);
	vSize = WinApi_GetDeviceCaps(dc, 6);
	hSize = WinApi_GetDeviceCaps(dc, 4);
	Ignore_Int(WinApi_ReleaseDC(NIL, dc));
	Clock_AspectV = __DIV(Clock_VRes * 100, vSize);
	Clock_AspectH = __DIV(Clock_HRes * 100, hSize);
	Clock_CreateTools();
	if (Clock_bFirst != 0) {
		pos = 0;
		while (pos < 60) {
			Clock_CirTab[__X(__ASHL(pos, 1) + 1, 120)] = Clock_VertEquiv(Clock_CirTab[__X(__ASHL(pos, 1) + 1, 120)]);
			pos += 1;
		}
	}
	Clock_GetTime(&Clock_oTime, Clock_TIME__typ);
}

static void Clock_CircleClock (INTEGER maxWidth, INTEGER maxHeight)
{
	INTEGER clockHeight, clockWidth;
	if (maxWidth > Clock_HorzEquiv(maxHeight)) {
		clockWidth = Clock_HorzEquiv(maxHeight);
		Clock_ClockRect.left = Clock_ClockRect.left + __ASHR(maxWidth - clockWidth, 1);
		Clock_ClockRect.right = Clock_ClockRect.left + clockWidth;
	} else {
		clockHeight = Clock_VertEquiv(maxWidth);
		Clock_ClockRect.top = Clock_ClockRect.top + __ASHR(maxHeight - clockHeight, 1);
		Clock_ClockRect.bottom = Clock_ClockRect.top + clockHeight;
	}
}

static void Clock_ClockSize (SYSTEM_PTR w, INTEGER newWidth, INTEGER newHeight, INTEGER sizeType)
{
	Ignore_Int(WinApi_SetRect(&Clock_ClockRect, WinApi_RECT__typ, 0, 0, newWidth, newHeight));
	Clock_CircleClock(newWidth, newHeight);
	if (sizeType == 1) {
		Ignore_Int(WinApi_KillTimer(w, Clock_TimerID));
		Ignore_Int(WinApi_SetTimer(w, Clock_TimerID, 59000, (WinApi_TIMERPROC)0));
		Clock_bIconic = 1;
	} else if (Clock_bIconic != 0) {
		Ignore_Int(WinApi_KillTimer(w, Clock_TimerID));
		Ignore_Int(WinApi_SetTimer(w, Clock_TimerID, 450, (WinApi_TIMERPROC)0));
		Clock_bIconic = 0;
	}
}

static void Clock_DrawFace (SYSTEM_PTR DC)
{
	INTEGER pos, dotHeight, dotWidth;
	WinApi_POINT dotCenter;
	WinApi_RECT rc;
	dotWidth = __DIV(25 * (Clock_ClockRect.right - Clock_ClockRect.left), Clock_HRes);
	dotHeight = Clock_VertEquiv(dotWidth);
	if (dotHeight < 1) {
		dotHeight = 1;
	}
	if (dotWidth < 2) {
		dotWidth = 2;
	}
	dotCenter.x = __ASHR(dotWidth, 1);
	dotCenter.y = __ASHR(dotHeight, 1);
	Ignore_Int(WinApi_InflateRect(&Clock_ClockRect, WinApi_RECT__typ, -dotCenter.y, -dotCenter.x));
	Clock_ClockRadius = __ASHR(Clock_ClockRect.right - Clock_ClockRect.left, 1);
	Clock_ClockCenter.x = Clock_ClockRect.left + Clock_ClockRadius;
	Clock_ClockCenter.y = Clock_ClockRect.top + __ASHR(Clock_ClockRect.bottom - Clock_ClockRect.top, 1);
	Ignore_Int(WinApi_InflateRect(&Clock_ClockRect, WinApi_RECT__typ, dotCenter.y, dotCenter.x));
	pos = 0;
	while (pos <= 59) {
		rc.top = __DIV(Clock_CirTab[__X(__ASHL(pos, 1) + 1, 120)] * Clock_ClockRadius, 8000) + Clock_ClockCenter.y;
		rc.left = __DIV(Clock_CirTab[__X(__ASHL(pos, 1), 120)] * Clock_ClockRadius, 8000) + Clock_ClockCenter.x;
		if ((int)__MOD(pos, 5) != 0) {
			if (dotWidth > 2 && dotHeight > 1) {
				rc.right = rc.left + 1;
				rc.bottom = rc.top + 1;
				Ignore_Int(WinApi_FillRect(DC, &rc, WinApi_RECT__typ, Clock_hbrForegnd));
			}
		} else {
			rc.right = rc.left + dotWidth;
			rc.bottom = rc.top + dotHeight;
			Ignore_Int(WinApi_OffsetRect(&rc, WinApi_RECT__typ, -dotCenter.x, -dotCenter.y));
			Ignore_Int(WinApi_FillRect(DC, &rc, WinApi_RECT__typ, Clock_hbrForegnd));
		}
		pos += 1;
	}
}

static void Clock_DrawHand (SYSTEM_PTR DC, INTEGER pos, SYSTEM_PTR Pen, INTEGER scale, INTEGER patMode)
{
	INTEGER radius, xr, yr;
	radius = __DIV(Clock_ClockRadius * scale, 100);
	Ignore_Int(WinApi_SetROP2(DC, patMode));
	Ignore_Ptr(WinApi_SelectObject(DC, Pen));
	xr = __DIV(Clock_CirTab[__X(__ASHL(pos, 1), 120)] * radius, 8000);
	yr = __DIV(Clock_CirTab[__X(__ASHL(pos, 1) + 1, 120)] * radius, 8000);
	Ignore_Int(WinApi_MoveToEx(DC, Clock_ClockCenter.x, Clock_ClockCenter.y, NIL, NIL));
	Ignore_Int(WinApi_LineTo(DC, Clock_ClockCenter.x + xr, Clock_ClockCenter.y + yr));
}

static void Clock_DrawFatHand (SYSTEM_PTR DC, INTEGER pos, SYSTEM_PTR Pen, INTEGER whichHand)
{
	WinApi_POINT ptTip, ptTail, ptSide;
	INTEGER index, scale, toPaint;
	Ignore_Int(WinApi_SetROP2(DC, 13));
	Ignore_Ptr(WinApi_SelectObject(DC, Pen));
	if (whichHand == 1) {
		toPaint = 7;
	} else {
		toPaint = 5;
	}
	scale = __DIV(Clock_ClockRadius * toPaint, 100);
	index = (int)__MOD(pos + 15, 60);
	ptSide.y = __DIV(Clock_CirTab[__X(__ASHL(index, 1) + 1, 120)] * scale, 8000);
	ptSide.x = __DIV(Clock_CirTab[__X(__ASHL(index, 1), 120)] * scale, 8000);
	if (whichHand == 1) {
		toPaint = 65;
	} else {
		toPaint = 80;
	}
	scale = __DIV(Clock_ClockRadius * toPaint, 100);
	ptTip.y = __DIV(Clock_CirTab[__X(__ASHL(pos, 1) + 1, 120)] * scale, 8000);
	ptTip.x = __DIV(Clock_CirTab[__X(__ASHL(pos, 1), 120)] * scale, 8000);
	if (whichHand == 1) {
		toPaint = 15;
	} else {
		toPaint = 20;
	}
	scale = __DIV(Clock_ClockRadius * toPaint, 100);
	index = (int)__MOD(pos + 30, 60);
	ptTail.y = __DIV(Clock_CirTab[__X(__ASHL(index, 1) + 1, 120)] * scale, 8000);
	ptTail.x = __DIV(Clock_CirTab[__X(__ASHL(index, 1), 120)] * scale, 8000);
	Ignore_Int(WinApi_MoveToEx(DC, Clock_ClockCenter.x + ptSide.x, Clock_ClockCenter.y + ptSide.y, NIL, NIL));
	Ignore_Int(WinApi_LineTo(DC, Clock_ClockCenter.x + ptTip.x, Clock_ClockCenter.y + ptTip.y));
	Ignore_Int(WinApi_MoveToEx(DC, Clock_ClockCenter.x - ptSide.x, Clock_ClockCenter.y - ptSide.y, NIL, NIL));
	Ignore_Int(WinApi_LineTo(DC, Clock_ClockCenter.x + ptTip.x, Clock_ClockCenter.y + ptTip.y));
	Ignore_Int(WinApi_MoveToEx(DC, Clock_ClockCenter.x + ptSide.x, Clock_ClockCenter.y + ptSide.y, NIL, NIL));
	Ignore_Int(WinApi_LineTo(DC, Clock_ClockCenter.x + ptTail.x, Clock_ClockCenter.y + ptTail.y));
	Ignore_Int(WinApi_MoveToEx(DC, Clock_ClockCenter.x - ptSide.x, Clock_ClockCenter.y - ptSide.y, NIL, NIL));
	Ignore_Int(WinApi_LineTo(DC, Clock_ClockCenter.x + ptTail.x, Clock_ClockCenter.y + ptTail.y));
}

static void Clock_ClockPaint (SYSTEM_PTR dc, INTEGER paintType)
{
	Clock_TIME nTime;
	Ignore_Int(WinApi_SetBkMode(dc, 1));
	if (paintType == 0) {
		Ignore_Int(WinApi_FillRect(dc, &Clock_ClockRect, WinApi_RECT__typ, Clock_hbrBackgnd));
		Clock_DrawFace(dc);
		Clock_DrawFatHand(dc, Clock_HourHandPos(Clock_oTime), Clock_hpenForegnd, 1);
		Clock_DrawFatHand(dc, Clock_oTime.minute, Clock_hpenForegnd, 0);
		if (Clock_bIconic == 0) {
			Clock_DrawHand(dc, Clock_oTime.second, Clock_hpenBackgnd, 80, 6);
		}
	} else if (paintType == 1) {
		Clock_GetTime(&nTime, Clock_TIME__typ);
		if (Clock_bIconic == 0 && nTime.second != Clock_oTime.second) {
			Clock_DrawHand(dc, Clock_oTime.second, Clock_hpenBackgnd, 80, 6);
		}
		if (nTime.minute != Clock_oTime.minute || nTime.hour != Clock_oTime.hour) {
			if (Clock_bIconic != 0) {
				Clock_DrawHand(dc, Clock_oTime.minute, Clock_hpenBackgnd, 80, 13);
				Clock_DrawHand(dc, Clock_HourHandPos(Clock_oTime), Clock_hpenBackgnd, 65, 13);
				Clock_DrawHand(dc, nTime.minute, Clock_hpenForegnd, 80, 13);
				Clock_DrawHand(dc, Clock_HourHandPos(nTime), Clock_hpenForegnd, 65, 13);
			} else {
				Clock_DrawFatHand(dc, Clock_oTime.minute, Clock_hpenBackgnd, 0);
				Clock_DrawFatHand(dc, Clock_HourHandPos(Clock_oTime), Clock_hpenBackgnd, 1);
				Clock_DrawFatHand(dc, nTime.minute, Clock_hpenForegnd, 0);
				Clock_DrawFatHand(dc, Clock_HourHandPos(nTime), Clock_hpenForegnd, 1);
			}
		}
		if (Clock_bIconic == 0 && nTime.second != Clock_oTime.second) {
			Clock_DrawHand(dc, nTime.second, Clock_hpenBackgnd, 80, 6);
		}
		Clock_oTime.minute = nTime.minute;
		Clock_oTime.hour = nTime.hour;
		Clock_oTime.second = nTime.second;
	}
}

static void Clock_ClockTimer (SYSTEM_PTR w)
{
	Clock_TIME nTime;
	SYSTEM_PTR dc = NIL;
	Clock_GetTime(&nTime, Clock_TIME__typ);
	if ((nTime.second != Clock_oTime.second || nTime.minute != Clock_oTime.minute) || nTime.hour != Clock_oTime.hour) {
		dc = WinApi_GetDC(w);
		Clock_ClockPaint(dc, 1);
		Ignore_Int(WinApi_ReleaseDC(w, dc));
	}
}

static SYSTEM_PTR __CALL_1 Clock_AboutProc (SYSTEM_PTR hDlg, INTEGER message, SYSTEM_PTR wParam, SYSTEM_PTR lParam)
{
	switch (message) {
		case 272: 
			break;
		case 273: 
			Ignore_Int(WinApi_EndDialog(hDlg, 1));
			break;
		default: 
			return (SYSTEM_PTR)0;
			break;
	}
	return (SYSTEM_PTR)1;
}

static SYSTEM_PTR __CALL_1 Clock_ClockWndProc (SYSTEM_PTR wnd, INTEGER message, SYSTEM_PTR wParam, SYSTEM_PTR lParam)
{
	WinApi_PAINTSTRUCT ps;
	WinApi_RECT rc;
	switch (message) {
		case 274: 
			if (wParam == (SYSTEM_PTR)1001) {
				Ignore_Int(WinApi_DialogBoxParam(Clock_Instance, (SYSTEM_PTR)((LONGINT)"#1"), wnd, Clock_AboutProc, NIL));
			} else {
				return WinApi_DefWindowProc(wnd, message, wParam, lParam);
			}
			break;
		case 5: 
			Clock_ClockSize(wnd, Delphi_LoWord(__VAL(INTEGER, lParam)), Delphi_HiWord(__VAL(INTEGER, lParam)), __VAL(INTEGER, wParam));
			Ignore_Int(WinApi_UpdateWindow(wnd));
			break;
		case 2: 
			Ignore_Int(WinApi_KillTimer(wnd, Clock_TimerID));
			Clock_DeleteTools();
			WinApi_PostQuitMessage(0);
			break;
		case 15: 
			Ignore_Int(WinApi_InvalidateRect(wnd, NIL, NIL, (INTEGER)1));
			Ignore_Ptr(WinApi_BeginPaint(wnd, &ps, WinApi_PAINTSTRUCT__typ));
			Clock_ClockPaint(ps.hdc, 0);
			Ignore_Int(WinApi_EndPaint(wnd, &ps, WinApi_PAINTSTRUCT__typ));
			break;
		case 30: case 275: 
			Clock_ClockTimer(wnd);
			break;
		case 21: 
			Clock_DeleteTools();
			Clock_CreateTools();
			break;
		case 20: 
			Ignore_Int(WinApi_GetClientRect(wnd, &rc, WinApi_RECT__typ));
			Ignore_Int(WinApi_FillRect((SYSTEM_PTR)wParam, &rc, WinApi_RECT__typ, Clock_hbrBackgnd));
			break;
		default: 
			return WinApi_DefWindowProc(wnd, message, wParam, lParam);
			break;
	}
	return NIL;
}

static BOOLEAN Clock_ClockInit (void)
{
	WinApi_WNDCLASSA clockClass;
	clockClass.lpszClassName = (SYSTEM_PTR)((LONGINT)Clock_szBuffer);
	clockClass.hbrBackground = NIL;
	clockClass.style = 0x1003;
	clockClass.hInstance = Clock_Instance;
	clockClass.lpfnWndProc = Clock_ClockWndProc;
	clockClass.hCursor = WinApi_LoadCursor(Clock_Instance, (SYSTEM_PTR)32512);
	clockClass.hIcon = WinApi_LoadIcon(Clock_Instance, (SYSTEM_PTR)100);
	clockClass.cbClsExtra = 0;
	clockClass.cbWndExtra = 0;
	clockClass.lpszMenuName = NIL;
	if (WinApi_RegisterClass(&clockClass, WinApi_WNDCLASSA__typ) == 0) {
		return 0;
	}
	__MOVE(CirTabConst, Clock_CirTab, 480);
	return 1;
}

static void EnumPtrs(void (*P)(void*))
{
	P(Clock_Instance);
	P(Clock_hbrForegnd);
	P(Clock_hbrBackgnd);
	P(Clock_hpenForegnd);
	P(Clock_hpenBackgnd);
	P(Clock_Wnd);
	P(Clock_Menu);
	P(Clock_pszTooMany);
}

__TDESC(Clock_TIME__desc, 1, 0) = {__TDFLDS("TIME", 12), {-8}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Delphi__init);
	__IMPORT(Ignore__init);
	__IMPORT(WinApi__init);
	__REGMAIN("Clock", EnumPtrs);
	__INITYP(Clock_TIME, Clock_TIME, 0);
/* BEGIN */
	Clock_bFirst = 1;
	Clock_TimerID = 1;
	Clock_bIconic = 0;
	Clock_Instance = WinApi_Instance();
	Ignore_Int(WinApi_LoadString(WinApi_Instance(), 2, (SYSTEM_PTR)((LONGINT)Clock_szBuffer), 30));
	if (WinApi_PrevInstance() == NIL) {
		if (!Clock_ClockInit()) {
			__HALT(1);
		}
	} else {
		Clock_bFirst = 0;
	}
	Clock_ClockCreate();
	Clock_sysWidth = __ASHL(WinApi_GetSystemMetrics(32), 1);
	Clock_sysHeight = WinApi_GetSystemMetrics(4) + __ASHL(WinApi_GetSystemMetrics(33), 1);
	Clock_width = __DIV(Clock_HRes, 3) + Clock_sysWidth;
	Clock_height = Clock_VertEquiv(Clock_width) + Clock_sysHeight;
	Clock_Wnd = WinApi_CreateWindowEx(0x0, (SYSTEM_PTR)((LONGINT)Clock_szBuffer), (SYSTEM_PTR)((LONGINT)Clock_szBuffer), 0xcf0000, (-2147483647-1), 0, Clock_width, Clock_height, NIL, NIL, WinApi_Instance(), NIL);
	Clock_GetTime(&Clock_nTime, Clock_TIME__typ);
	Clock_GetTime(&Clock_oTime, Clock_TIME__typ);
	while ((Clock_nTime.second == Clock_oTime.second && Clock_nTime.minute == Clock_oTime.minute) && Clock_nTime.hour == Clock_oTime.hour) {
		Clock_GetTime(&Clock_oTime, Clock_TIME__typ);
	}
	if (WinApi_SetTimer(Clock_Wnd, Clock_TimerID, 450, (WinApi_TIMERPROC)0) == 0) {
		Clock_pszTooMany = (Clock_pszTooManyPtr)WinApi_GlobalLock(WinApi_GlobalAlloc(0x40, 40));
		Ignore_Int(WinApi_LoadString(WinApi_Instance(), 4, (void*)Clock_pszTooMany, 40));
		Ignore_Int(WinApi_MessageBox(NIL, (SYSTEM_PTR)((LONGINT)&Clock_pszTooMany), (SYSTEM_PTR)((LONGINT)Clock_szBuffer), 0x1010));
		Clock_DeleteTools();
		__HALT(1);
	}
	Ignore_Int(WinApi_LoadString(WinApi_Instance(), 1, (SYSTEM_PTR)((LONGINT)Clock_szBuffer), 30));
	Clock_Menu = WinApi_GetSystemMenu(Clock_Wnd, 0);
	Ignore_Int(WinApi_ChangeMenu(Clock_Menu, 0, (SYSTEM_PTR)((LONGINT)Clock_szBuffer), 1001, 0x0100));
	Ignore_Int(WinApi_ShowWindow(Clock_Wnd, WinApi_CmdShow()));
	while (WinApi_GetMessage(&Clock_mess, WinApi_MSG__typ, NIL, 0, 0) != 0) {
		Ignore_Int(WinApi_TranslateMessage(&Clock_mess, WinApi_MSG__typ));
		Ignore_Int(WinApi_DispatchMessage(&Clock_mess, WinApi_MSG__typ));
	}
	__FINI;
}
