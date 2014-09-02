/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "AclUtils.h"
#include "WinApi.h"

typedef
	CHAR AclLib_PChar[256];

typedef
	struct AclLib_TWinControl *AclLib_PWinControl;

typedef
	CHAR AclLib_ShortString[256];

typedef
	struct AclLib_TWinControl {
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style;
		INTEGER FExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl FParent;
		BOOLEAN FAutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN FEnabled, FIsModal, FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TWinControl;

export void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_PWinControl AParent);
static INTEGER AclLib_TWinControl_GetClientHeight (AclLib_TWinControl *w, LONGINT *w__typ);
static void AclLib_TWinControl_GetClientRect (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_RECT *rect, LONGINT *rect__typ);
static INTEGER AclLib_TWinControl_GetClientWidth (AclLib_TWinControl *w, LONGINT *w__typ);
static void AclLib_TWinControl_SetBounds (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_RECT *r, LONGINT *r__typ);
export void AclLib_TWinControl_SetCaption (AclLib_TWinControl *w, LONGINT *w__typ, CHAR *value, LONGINT value__len);
export void AclLib_TWinControl_SetColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetHeight (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetLeft (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetTextColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetTop (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetWidth (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
#define __AclLib_TWinControl_Create(w, w__typ, AParent) __SEND(w__typ, AclLib_TWinControl_Create, 0, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_PWinControl), (w, w__typ, AParent))
#define __AclLib_TWinControl_GetClientHeight(w, w__typ) __SEND(w__typ, AclLib_TWinControl_GetClientHeight, 1, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_GetClientRect(w, w__typ, rect, rect__typ) __SEND(w__typ, AclLib_TWinControl_GetClientRect, 2, void(*)(AclLib_TWinControl*, LONGINT *, WinApi_RECT*, LONGINT *), (w, w__typ, rect, rect__typ))
#define __AclLib_TWinControl_GetClientWidth(w, w__typ) __SEND(w__typ, AclLib_TWinControl_GetClientWidth, 3, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_SetBounds(w, w__typ, r, r__typ) __SEND(w__typ, AclLib_TWinControl_SetBounds, 4, void(*)(AclLib_TWinControl*, LONGINT *, WinApi_RECT*, LONGINT *), (w, w__typ, r, r__typ))
#define __AclLib_TWinControl_SetCaption(w, w__typ, value, value__len) __SEND(w__typ, AclLib_TWinControl_SetCaption, 5, void(*)(AclLib_TWinControl*, LONGINT *, CHAR*, LONGINT ), (w, w__typ, value, value__len))
#define __AclLib_TWinControl_SetColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetColor, 6, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetHeight(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetHeight, 7, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetLeft(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetLeft, 8, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTextColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTextColor, 9, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTop(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTop, 10, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetWidth(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetWidth, 11, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))



export LONGINT *AclLib_TWinControl__typ;



/*============================================================================*/

void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_PWinControl AParent)
{
	(*w).FHandle = NIL;
	(*w).FParentHandle = NIL;
	(*w).FTextBuf[0] = 0x00;
	(*w).FTextLen = 0;
	__MOVE("TACLFORM", (*w).FClassName, 9);
	(*w).Style = 0xc10000;
	(*w).FExStyle = 0;
	(*w).FCtl3D = 0;
	(*w).FParent = AParent;
	(*w).FDefWndProc = 0;
	(*w).Left = (-2147483647-1);
	(*w).Top = (-2147483647-1);
	(*w).Width = (-2147483647-1);
	(*w).Height = (-2147483647-1);
	(*w).Color = 12632256;
	(*w).FBkMode = 0;
	(*w).Brush = NIL;
}

/*----------------------------------------------------------------------------*/
static void AclLib_TWinControl_SetBounds (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_RECT *r, LONGINT *r__typ)
{
	SET flags;
	flags = 0x04;
	if ((*w).Visible) {
		flags = (flags | 0x20) | 0x40;
	}
	if ((*w).FHandle != NIL) {
		Ignore_Int(WinApi_SetWindowPos((*w).FHandle, NIL, (*r).left, (*r).top, (*r).right - (*r).left, (*r).bottom - (*r).top, flags));
	}
	(*w).Left = (*r).left;
	(*w).Top = (*r).top;
	(*w).Width = (*r).right - (*r).left;
	(*w).Height = (*r).bottom - (*r).top;
}

void AclLib_TWinControl_SetLeft (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	WinApi_RECT r;
	if ((*w).Left != value) {
		(*w).Left = value;
		r.left = (*w).Left;
		r.right = r.left + (*w).Width;
		r.top = (*w).Top;
		r.bottom = r.top + (*w).Height;
		__AclLib_TWinControl_SetBounds(&*w, w__typ, &r, WinApi_RECT__typ);
	}
}

/*----------------------------------------------------------------------------*/
void AclLib_TWinControl_SetTop (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	WinApi_RECT r;
	if ((*w).Top != value) {
		(*w).Top = value;
		r.left = (*w).Left;
		r.right = r.left + (*w).Width;
		r.top = (*w).Top;
		r.bottom = r.top + (*w).Height;
		__AclLib_TWinControl_SetBounds(&*w, w__typ, &r, WinApi_RECT__typ);
	}
}

/*----------------------------------------------------------------------------*/
void AclLib_TWinControl_SetWidth (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	WinApi_RECT r;
	if ((*w).Width != value) {
		(*w).Width = value;
		r.left = (*w).Left;
		r.right = r.left + (*w).Width;
		r.top = (*w).Top;
		r.bottom = r.top + (*w).Height;
		__AclLib_TWinControl_SetBounds(&*w, w__typ, &r, WinApi_RECT__typ);
	}
}

/*----------------------------------------------------------------------------*/
void AclLib_TWinControl_SetHeight (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	WinApi_RECT r;
	if ((*w).Height != value) {
		(*w).Height = value;
		r.left = (*w).Left;
		r.right = r.left + (*w).Width;
		r.top = (*w).Top;
		r.bottom = r.top + (*w).Height;
		__AclLib_TWinControl_SetBounds(&*w, w__typ, &r, WinApi_RECT__typ);
	}
}

/*----------------------------------------------------------------------------*/
void AclLib_TWinControl_SetCaption (AclLib_TWinControl *w, LONGINT *w__typ, CHAR *value, LONGINT value__len)
{
	__COPY(value, (*w).FTextBuf, 256);
	if ((*w).FHandle != NIL) {
		Ignore_Ptr(WinApi_SendMessage((*w).FHandle, 12, NIL, (SYSTEM_PTR)((LONGINT)(*w).FTextBuf)));
	}
}

/*----------------------------------------------------------------------------*/
static void AclLib_TWinControl_GetClientRect (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_RECT *rect, LONGINT *rect__typ)
{
	Ignore_Int(WinApi_GetClientRect((*w).FHandle, &*rect, rect__typ));
}

static INTEGER AclLib_TWinControl_GetClientWidth (AclLib_TWinControl *w, LONGINT *w__typ)
{
	WinApi_RECT r;
	Ignore_Int(WinApi_GetClientRect((*w).FHandle, &r, WinApi_RECT__typ));
	return r.right - r.left;
}

static INTEGER AclLib_TWinControl_GetClientHeight (AclLib_TWinControl *w, LONGINT *w__typ)
{
	WinApi_RECT r;
	Ignore_Int(WinApi_GetClientRect((*w).FHandle, &r, WinApi_RECT__typ));
	return r.bottom - r.top;
}

void AclLib_TWinControl_SetColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	SYSTEM_PTR tb = NIL, ob = NIL;
	if ((*w).FHandle != NIL) {
		tb = WinApi_CreateSolidBrush(value);
		ob = WinApi_SelectObject((*w).FDC, tb);
		Ignore_Int(WinApi_DeleteObject(ob));
		(*w).Brush = tb;
	} else {
		if ((*w).Brush != NIL) {
			Ignore_Int(WinApi_DeleteObject((*w).Brush));
		}
		(*w).Brush = WinApi_CreateSolidBrush(value);
	}
	(*w).Color = value;
}

/*----------------------------------------------------------------------------*/
void AclLib_TWinControl_SetTextColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	Ignore_Int(WinApi_SetTextColor((*w).FDC, value));
	(*w).TextColor = value;
}

/*----------------------------------------------------------------------------*/
__TDESC(AclLib_TWinControl__desc, 13, 6) = {__TDFLDS("TWinControl", 856), {0, 4, 788, 792, 836, 844, -56}};

export void *AclLib__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(AclUtils__init);
	__IMPORT(WinApi__init);
	__REGMOD("AclLib", 0);
	__INITYP(AclLib_TWinControl, AclLib_TWinControl, 0);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_Create, 0);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_GetClientHeight, 1);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_GetClientRect, 2);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_GetClientWidth, 3);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetBounds, 4);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetCaption, 5);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetColor, 6);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetHeight, 7);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetLeft, 8);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetTextColor, 9);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetTop, 10);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetWidth, 11);
/* BEGIN */
	__ENDMOD;
}
