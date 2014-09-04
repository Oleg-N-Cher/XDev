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
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TWinControl;

export void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_PWinControl AParent);
typedef
	struct AclLib_TCreateParams {
		AclLib_PChar Caption;
		INTEGER Style, ExStyle, X, Y, Width, Height;
		SYSTEM_PTR WndParent, Param;
		WinApi_WNDCLASSA WindowClass;
		CHAR WinClassName[64];
	} AclLib_TCreateParams;

static void AclLib_TWinControl_CreateParams (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_TCreateParams *Params, LONGINT *Params__typ);
static void AclLib_TWinControl_CreateWindowHandle (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_TCreateParams *Params, LONGINT *Params__typ);
export void AclLib_TWinControl_CreateWnd (AclLib_TWinControl *w, LONGINT *w__typ);
static void AclLib_TWinControl_EndModal (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
static INTEGER AclLib_TWinControl_GetClientHeight (AclLib_TWinControl *w, LONGINT *w__typ);
static void AclLib_TWinControl_GetClientRect (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_RECT *rect, LONGINT *rect__typ);
static INTEGER AclLib_TWinControl_GetClientWidth (AclLib_TWinControl *w, LONGINT *w__typ);
static void AclLib_TWinControl_Hide (AclLib_TWinControl *w, LONGINT *w__typ);
static void AclLib_TWinControl_Invalidate (AclLib_TWinControl *w, LONGINT *w__typ);
static BOOLEAN AclLib_TWinControl_IsParentHandle (AclLib_TWinControl *w, LONGINT *w__typ, SYSTEM_PTR AHandle);
static void AclLib_TWinControl_ProcessMessages (AclLib_TWinControl *w, LONGINT *w__typ);
static BOOLEAN AclLib_TWinControl_ProcessMsg (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_MSG *Msg, LONGINT *Msg__typ);
static void AclLib_TWinControl_SetBounds (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_RECT *r, LONGINT *r__typ);
export void AclLib_TWinControl_SetCaption (AclLib_TWinControl *w, LONGINT *w__typ, CHAR *value, LONGINT value__len);
export void AclLib_TWinControl_SetColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
static void AclLib_TWinControl_SetFocus (AclLib_TWinControl *w, LONGINT *w__typ);
export void AclLib_TWinControl_SetHeight (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetLeft (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetTextColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetTop (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
export void AclLib_TWinControl_SetVisible (AclLib_TWinControl *w, LONGINT *w__typ, BOOLEAN value);
export void AclLib_TWinControl_SetWidth (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
static void AclLib_TWinControl_Show (AclLib_TWinControl *w, LONGINT *w__typ);
export INTEGER AclLib_TWinControl_ShowModal (AclLib_TWinControl *w, LONGINT *w__typ);
#define __AclLib_TWinControl_Create(w, w__typ, AParent) __SEND(w__typ, AclLib_TWinControl_Create, 0, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_PWinControl), (w, w__typ, AParent))
#define __AclLib_TWinControl_CreateParams(w, w__typ, Params, Params__typ) __SEND(w__typ, AclLib_TWinControl_CreateParams, 1, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_TCreateParams*, LONGINT *), (w, w__typ, Params, Params__typ))
#define __AclLib_TWinControl_CreateWindowHandle(w, w__typ, Params, Params__typ) __SEND(w__typ, AclLib_TWinControl_CreateWindowHandle, 2, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_TCreateParams*, LONGINT *), (w, w__typ, Params, Params__typ))
#define __AclLib_TWinControl_CreateWnd(w, w__typ) __SEND(w__typ, AclLib_TWinControl_CreateWnd, 3, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_EndModal(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_EndModal, 4, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_GetClientHeight(w, w__typ) __SEND(w__typ, AclLib_TWinControl_GetClientHeight, 5, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_GetClientRect(w, w__typ, rect, rect__typ) __SEND(w__typ, AclLib_TWinControl_GetClientRect, 6, void(*)(AclLib_TWinControl*, LONGINT *, WinApi_RECT*, LONGINT *), (w, w__typ, rect, rect__typ))
#define __AclLib_TWinControl_GetClientWidth(w, w__typ) __SEND(w__typ, AclLib_TWinControl_GetClientWidth, 7, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_Hide(w, w__typ) __SEND(w__typ, AclLib_TWinControl_Hide, 8, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_Invalidate(w, w__typ) __SEND(w__typ, AclLib_TWinControl_Invalidate, 9, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_IsParentHandle(w, w__typ, AHandle) __SEND(w__typ, AclLib_TWinControl_IsParentHandle, 10, BOOLEAN(*)(AclLib_TWinControl*, LONGINT *, SYSTEM_PTR), (w, w__typ, AHandle))
#define __AclLib_TWinControl_ProcessMessages(w, w__typ) __SEND(w__typ, AclLib_TWinControl_ProcessMessages, 11, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_ProcessMsg(w, w__typ, Msg, Msg__typ) __SEND(w__typ, AclLib_TWinControl_ProcessMsg, 12, BOOLEAN(*)(AclLib_TWinControl*, LONGINT *, WinApi_MSG*, LONGINT *), (w, w__typ, Msg, Msg__typ))
#define __AclLib_TWinControl_SetBounds(w, w__typ, r, r__typ) __SEND(w__typ, AclLib_TWinControl_SetBounds, 13, void(*)(AclLib_TWinControl*, LONGINT *, WinApi_RECT*, LONGINT *), (w, w__typ, r, r__typ))
#define __AclLib_TWinControl_SetCaption(w, w__typ, value, value__len) __SEND(w__typ, AclLib_TWinControl_SetCaption, 14, void(*)(AclLib_TWinControl*, LONGINT *, CHAR*, LONGINT ), (w, w__typ, value, value__len))
#define __AclLib_TWinControl_SetColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetColor, 15, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetFocus(w, w__typ) __SEND(w__typ, AclLib_TWinControl_SetFocus, 16, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_SetHeight(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetHeight, 17, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetLeft(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetLeft, 18, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTextColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTextColor, 19, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTop(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTop, 20, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetVisible(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetVisible, 21, void(*)(AclLib_TWinControl*, LONGINT *, BOOLEAN), (w, w__typ, value))
#define __AclLib_TWinControl_SetWidth(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetWidth, 22, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_Show(w, w__typ) __SEND(w__typ, AclLib_TWinControl_Show, 23, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_ShowModal(w, w__typ) __SEND(w__typ, AclLib_TWinControl_ShowModal, 24, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))

typedef
	struct AclLib_TStdControl { /* AclLib_TWinControl */
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TStdControl;

typedef
	struct AclLib_TButton { /* AclLib_TStdControl */
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TButton;

typedef
	struct AclLib_TCheckBox { /* AclLib_TStdControl */
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TCheckBox;

typedef
	struct AclLib_TLabel { /* AclLib_TStdControl */
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TLabel;

typedef
	struct AclLib_TListBox { /* AclLib_TStdControl */
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TListBox;

typedef
	struct AclLib_TObject {
		char _prvt0[1];
	} AclLib_TObject;

typedef
	struct AclLib_TProgressBar { /* AclLib_TStdControl */
		SYSTEM_PTR FHandle, FParentHandle;
		AclLib_PChar FClassName;
		INTEGER FDefWndProc, FHelpContext;
		AclLib_ShortString FHelpFile, FTextBuf;
		INTEGER FTextLen;
		SYSTEM_PTR Brush, FCursorHandle;
		SHORTINT FCursor;
		SYSTEM_PTR FDC;
		INTEGER Color, TextColor;
		BYTE FBkMode;
		SET Style, ExStyle;
		BOOLEAN FCtl3D;
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		AclLib_PWinControl FActiveControl;
		BOOLEAN Enabled, IsModal;
		INTEGER FModalResult;
		BOOLEAN FTabStop, Visible;
		INTEGER FHTest;
	} AclLib_TProgressBar;


static INTEGER AclLib_ScreenLogPixels;
static SYSTEM_PTR AclLib_HInstance;
static AclLib_TWinControl AclLib_MainWindow;
static INTEGER AclLib_CmdShow;

export LONGINT *AclLib_TObject__typ;
export LONGINT *AclLib_TCreateParams__typ;
export LONGINT *AclLib_TWinControl__typ;
export LONGINT *AclLib_TStdControl__typ;
export LONGINT *AclLib_TLabel__typ;
export LONGINT *AclLib_TListBox__typ;
export LONGINT *AclLib_TButton__typ;
export LONGINT *AclLib_TCheckBox__typ;
export LONGINT *AclLib_TProgressBar__typ;

static INTEGER AclLib_GetCmdShow (void);
static void AclLib_InitScreenLogPixels (void);


/*============================================================================*/

static INTEGER AclLib_GetCmdShow (void)
{
	WinApi_STARTUPINFOA SI;
	INTEGER result;
	result = 10;
	WinApi_GetStartupInfo(&SI, WinApi_STARTUPINFOA__typ);
	if (__IN(0, SI.dwFlags)) {
		result = SI.wShowWindow;
	}
	return result;
}

static void AclLib_InitScreenLogPixels (void)
{
	SYSTEM_PTR DC = NIL;
	DC = WinApi_GetDC(NIL);
	AclLib_ScreenLogPixels = WinApi_GetDeviceCaps(DC, 90);
	Ignore_Int(WinApi_ReleaseDC(NIL, DC));
}

void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_PWinControl AParent)
{
	(*w).FHandle = NIL;
	(*w).FParentHandle = NIL;
	(*w).FTextBuf[0] = 0x00;
	(*w).FTextLen = 0;
	__MOVE("TACLFORM", (*w).FClassName, 9);
	(*w).Style = 0xc10000;
	(*w).ExStyle = 0x0;
	(*w).FCtl3D = 0;
	(*w).Parent = AParent;
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

void AclLib_TWinControl_SetVisible (AclLib_TWinControl *w, LONGINT *w__typ, BOOLEAN value)
{
	(*w).Visible = value;
	if ((*w).FHandle != NIL) {
		if ((*w).Visible) {
			__AclLib_TWinControl_Show(&*w, w__typ);
		} else {
			__AclLib_TWinControl_Hide(&*w, w__typ);
		}
	}
}

/*----------------------------------------------------------------------------*/
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
static void AclLib_TWinControl_CreateParams (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_TCreateParams *Params, LONGINT *Params__typ)
{
}

void AclLib_TWinControl_CreateWnd (AclLib_TWinControl *w, LONGINT *w__typ)
{
	AclLib_TCreateParams Params;
	WinApi_WNDCLASSA TempClass;
	BOOLEAN ClassRegistered;
	__AclLib_TWinControl_CreateParams(&*w, w__typ, &Params, AclLib_TCreateParams__typ);
	ClassRegistered = 0 != WinApi_GetClassInfo(AclLib_HInstance, (SYSTEM_PTR)((LONGINT)Params.WinClassName), &TempClass, WinApi_WNDCLASSA__typ);
	if (!ClassRegistered) {
		Params.WindowClass.hInstance = AclLib_HInstance;
		if (WinApi_RegisterClass(&Params.WindowClass, WinApi_WNDCLASSA__typ) == 0) {
			Ignore_Int(WinApi_MessageBox(NIL, (SYSTEM_PTR)((LONGINT)"WinRegister failed"), NIL, 0x0));
			__HALT(0);
		}
	}
}

/*----------------------------------------------------------------------------*/
static void AclLib_TWinControl_CreateWindowHandle (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_TCreateParams *Params, LONGINT *Params__typ)
{
	(*w).FHandle = WinApi_CreateWindowEx((*w).ExStyle, (SYSTEM_PTR)((LONGINT)(*Params).WinClassName), (SYSTEM_PTR)((LONGINT)&(*w).FTextBuf[0]), (*w).Style, (*w).Left, (*w).Top, (*w).Width, (*w).Height, (*Params).WndParent, NIL, AclLib_HInstance, NIL);
	if ((*w).FHandle == NIL) {
		Ignore_Int(WinApi_MessageBox(NIL, (SYSTEM_PTR)((LONGINT)"WinCreate failed"), NIL, 0x0));
		__HALT(0);
	}
	Ignore_Int(WinApi_SetProp((*w).FHandle, (SYSTEM_PTR)((LONGINT)"__SELF__"), __VAL(SYSTEM_PTR, *w)));
	Ignore_Int(WinApi_EnableWindow((*w).FHandle, __VAL(INTEGER, (*w).Enabled)));
	if ((*w).Parent == NIL && __VAL(AclLib_PWinControl, AclLib_MainWindow) == NIL) {
		AclLib_MainWindow = *w;
	}
	if ((*w).Visible) {
		__AclLib_TWinControl_Show(&*w, w__typ);
	}
}

static void AclLib_TWinControl_Show (AclLib_TWinControl *w, LONGINT *w__typ)
{
	Ignore_Int(WinApi_ShowWindow((*w).FHandle, 5));
	Ignore_Int(WinApi_UpdateWindow((*w).FHandle));
}

static void AclLib_TWinControl_Hide (AclLib_TWinControl *w, LONGINT *w__typ)
{
	Ignore_Int(WinApi_ShowWindow((*w).FHandle, 0));
}

static BOOLEAN AclLib_TWinControl_IsParentHandle (AclLib_TWinControl *w, LONGINT *w__typ, SYSTEM_PTR AHandle)
{
	__RETCHK;
}

static BOOLEAN AclLib_TWinControl_ProcessMsg (AclLib_TWinControl *w, LONGINT *w__typ, WinApi_MSG *Msg, LONGINT *Msg__typ)
{
	BOOLEAN result;
	result = 0;
	if (0 != WinApi_PeekMessage(&*Msg, Msg__typ, NIL, 0, 0, 1)) {
		result = 1;
		if ((*Msg).message != 18) {
			Ignore_Int(WinApi_TranslateMessage(&*Msg, Msg__typ));
			Ignore_Int(WinApi_DispatchMessage(&*Msg, Msg__typ));
		}
	}
	return result;
}

static void AclLib_TWinControl_ProcessMessages (AclLib_TWinControl *w, LONGINT *w__typ)
{
	WinApi_MSG Msg;
	while (__AclLib_TWinControl_ProcessMsg(&*w, w__typ, &Msg, WinApi_MSG__typ)) {
	}
}

INTEGER AclLib_TWinControl_ShowModal (AclLib_TWinControl *w, LONGINT *w__typ)
{
	WinApi_MSG AMessage;
	INTEGER result;
	(*w).IsModal = 1;
	(*w).FModalResult = 0;
	while ((*w).FModalResult == 0) {
		Ignore_Int(WinApi_GetMessage(&AMessage, WinApi_MSG__typ, NIL, 0, 0));
		Ignore_Int(WinApi_TranslateMessage(&AMessage, WinApi_MSG__typ));
		if ((((*w).Parent == NIL || AMessage.message == 15) || AMessage.message == 18) || !__AclLib_TWinControl_IsParentHandle(&*w, w__typ, AMessage.hwnd)) {
			Ignore_Int(WinApi_DispatchMessage(&AMessage, WinApi_MSG__typ));
		}
	}
	if ((*w).FModalResult == 0) {
		result = __VAL(INTEGER, AMessage.wParam);
	} else {
		result = (*w).FModalResult;
	}
	(*w).FModalResult = 0;
	(*w).IsModal = 0;
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
static void AclLib_TWinControl_EndModal (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value)
{
	if ((*w).IsModal) {
		(*w).FModalResult = value;
	}
}

static void AclLib_TWinControl_Invalidate (AclLib_TWinControl *w, LONGINT *w__typ)
{
	if ((*w).Parent == NIL) {
		Ignore_Int(WinApi_ShowWindow((*w).FHandle, AclLib_CmdShow));
	}
	Ignore_Int(WinApi_InvalidateRect((*w).FHandle, NIL, NIL, 1));
	Ignore_Int(WinApi_UpdateWindow((*w).FHandle));
}

static void AclLib_TWinControl_SetFocus (AclLib_TWinControl *w, LONGINT *w__typ)
{
	Ignore_Ptr(WinApi_SetFocus((*w).FHandle));
}

static void EnumPtrs(void (*P)(void*))
{
	P(AclLib_HInstance);
	__ENUMR(&AclLib_MainWindow, AclLib_TWinControl__typ, 872, 1, P);
}

__TDESC(AclLib_TObject__desc, 1, 0) = {__TDFLDS("TObject", 1), {-8}};
__TDESC(AclLib_TCreateParams__desc, 1, 2) = {__TDFLDS("TCreateParams", 392), {280, 284, -24}};
__TDESC(AclLib_TWinControl__desc, 26, 7) = {__TDFLDS("TWinControl", 872), {0, 4, 788, 792, 800, 844, 852, -64}};
__TDESC(AclLib_TStdControl__desc, 26, 7) = {__TDFLDS("TStdControl", 872), {0, 4, 788, 792, 800, 844, 852, -64}};
__TDESC(AclLib_TLabel__desc, 26, 7) = {__TDFLDS("TLabel", 872), {0, 4, 788, 792, 800, 844, 852, -64}};
__TDESC(AclLib_TListBox__desc, 26, 7) = {__TDFLDS("TListBox", 872), {0, 4, 788, 792, 800, 844, 852, -64}};
__TDESC(AclLib_TButton__desc, 26, 7) = {__TDFLDS("TButton", 872), {0, 4, 788, 792, 800, 844, 852, -64}};
__TDESC(AclLib_TCheckBox__desc, 26, 7) = {__TDFLDS("TCheckBox", 872), {0, 4, 788, 792, 800, 844, 852, -64}};
__TDESC(AclLib_TProgressBar__desc, 26, 7) = {__TDFLDS("TProgressBar", 872), {0, 4, 788, 792, 800, 844, 852, -64}};

export void *AclLib__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(AclUtils__init);
	__IMPORT(WinApi__init);
	__REGMOD("AclLib", EnumPtrs);
	__INITYP(AclLib_TObject, AclLib_TObject, 0);
	__INITYP(AclLib_TCreateParams, AclLib_TCreateParams, 0);
	__INITYP(AclLib_TWinControl, AclLib_TWinControl, 0);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_Create, 0);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_CreateParams, 1);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_CreateWindowHandle, 2);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_CreateWnd, 3);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_EndModal, 4);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_GetClientHeight, 5);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_GetClientRect, 6);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_GetClientWidth, 7);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_Hide, 8);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_Invalidate, 9);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_IsParentHandle, 10);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_ProcessMessages, 11);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_ProcessMsg, 12);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetBounds, 13);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetCaption, 14);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetColor, 15);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetFocus, 16);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetHeight, 17);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetLeft, 18);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetTextColor, 19);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetTop, 20);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetVisible, 21);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_SetWidth, 22);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_Show, 23);
	__INITBP(AclLib_TWinControl, AclLib_TWinControl_ShowModal, 24);
	__INITYP(AclLib_TStdControl, AclLib_TWinControl, 1);
	__INITYP(AclLib_TLabel, AclLib_TStdControl, 2);
	__INITYP(AclLib_TListBox, AclLib_TStdControl, 2);
	__INITYP(AclLib_TButton, AclLib_TStdControl, 2);
	__INITYP(AclLib_TCheckBox, AclLib_TStdControl, 2);
	__INITYP(AclLib_TProgressBar, AclLib_TStdControl, 2);
/* BEGIN */
	AclLib_HInstance = WinApi_GetModuleHandle(NIL);
	AclLib_CmdShow = AclLib_GetCmdShow();
	__ENDMOD;
}
