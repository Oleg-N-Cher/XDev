/*  Ofront 1.2 -xtspkae */

#ifndef AclLib__h
#define AclLib__h

#include "SYSTEM.h"
#include "WinApi.h"

typedef
	WinApi_LOGFONTA *AclLib_TFontList;

typedef
	struct {
		LONGINT len[1];
		WinApi_LOGFONTA data[1];
	} *AclLib_PFontList;

typedef
	struct AclLib_TWinControl *AclLib_PWinControl;

typedef
	CHAR *AclLib_String;

typedef
	struct AclLib_TWinControl {
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TWinControl;

import void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_TWinControl *aParent, LONGINT *aParent__typ);
import void AclLib_TWinControl_CreateWnd (AclLib_TWinControl *w, LONGINT *w__typ);
import void AclLib_TWinControl_SetCaption (AclLib_TWinControl *w, LONGINT *w__typ, CHAR *value, LONGINT value__len);
import void AclLib_TWinControl_SetColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetHeight (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetLeft (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetTextColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetTop (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetVisible (AclLib_TWinControl *w, LONGINT *w__typ, BOOLEAN value);
import void AclLib_TWinControl_SetWidth (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import INTEGER AclLib_TWinControl_ShowModal (AclLib_TWinControl *w, LONGINT *w__typ);
#define __AclLib_TWinControl_Create(w, w__typ, aParent, aParent__typ) __SEND(w__typ, AclLib_TWinControl_Create, 0, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_TWinControl*, LONGINT *), (w, w__typ, aParent, aParent__typ))
#define __AclLib_TWinControl_CreateWnd(w, w__typ) __SEND(w__typ, AclLib_TWinControl_CreateWnd, 3, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_SetCaption(w, w__typ, value, value__len) __SEND(w__typ, AclLib_TWinControl_SetCaption, 14, void(*)(AclLib_TWinControl*, LONGINT *, CHAR*, LONGINT ), (w, w__typ, value, value__len))
#define __AclLib_TWinControl_SetColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetColor, 15, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetHeight(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetHeight, 19, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetLeft(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetLeft, 20, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTextColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTextColor, 21, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTop(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTop, 22, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetVisible(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetVisible, 23, void(*)(AclLib_TWinControl*, LONGINT *, BOOLEAN), (w, w__typ, value))
#define __AclLib_TWinControl_SetWidth(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetWidth, 24, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_ShowModal(w, w__typ) __SEND(w__typ, AclLib_TWinControl_ShowModal, 26, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))

typedef
	struct AclLib_TStdControl { /* AclLib_TWinControl */
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TStdControl;

typedef
	struct AclLib_TButton { /* AclLib_TStdControl */
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TButton;

typedef
	struct AclLib_TCheckBox { /* AclLib_TStdControl */
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TCheckBox;

typedef
	struct AclLib_TCreateParams {
		LONGINT _prvt0;
		char _prvt1[424];
	} AclLib_TCreateParams;

typedef
	struct AclLib_TFont {
		SYSTEM_PTR Handle;
		char _prvt0[116];
		INTEGER Color;
		char _prvt1[4];
	} AclLib_TFont;

typedef
	CHAR *AclLib_TFontName;

typedef
	struct AclLib_TFonts {
		LONGINT _prvt0;
		INTEGER Count;
		char _prvt1[13];
		CHAR CharSet;
	} AclLib_TFonts;

import void AclLib_TFonts_Create (AclLib_TFonts *f, LONGINT *f__typ);
import void AclLib_TFonts_Destroy (AclLib_TFonts *f, LONGINT *f__typ);
import void AclLib_TFonts_FindFont (AclLib_TFonts *f, LONGINT *f__typ, CHAR *aName, LONGINT aName__len, BYTE aPitch, WinApi_LOGFONTA *result, LONGINT *result__typ);
import void AclLib_TFonts_GetFont (AclLib_TFonts *f, LONGINT *f__typ, INTEGER i, WinApi_LOGFONTA *result, LONGINT *result__typ);
import INTEGER AclLib_TFonts_IndexOf (AclLib_TFonts *f, LONGINT *f__typ, BYTE APitch, CHAR *AName, LONGINT AName__len);
import BOOLEAN AclLib_TFonts_IsDefaultPitch (AclLib_TFonts *f, LONGINT *f__typ, WinApi_LOGFONTA *AFont, LONGINT *AFont__typ);
import BOOLEAN AclLib_TFonts_IsFixedPitch (AclLib_TFonts *f, LONGINT *f__typ, WinApi_LOGFONTA *AFont, LONGINT *AFont__typ);
import BOOLEAN AclLib_TFonts_IsVariablePitch (AclLib_TFonts *f, LONGINT *f__typ, WinApi_LOGFONTA *AFont, LONGINT *AFont__typ);
import void AclLib_TFonts_SetCharSet (AclLib_TFonts *f, LONGINT *f__typ, CHAR value);
#define __AclLib_TFonts_Create(f, f__typ) __SEND(f__typ, AclLib_TFonts_Create, 0, void(*)(AclLib_TFonts*, LONGINT *), (f, f__typ))
#define __AclLib_TFonts_Destroy(f, f__typ) __SEND(f__typ, AclLib_TFonts_Destroy, 1, void(*)(AclLib_TFonts*, LONGINT *), (f, f__typ))
#define __AclLib_TFonts_FindFont(f, f__typ, aName, aName__len, aPitch, result, result__typ) __SEND(f__typ, AclLib_TFonts_FindFont, 3, void(*)(AclLib_TFonts*, LONGINT *, CHAR*, LONGINT , BYTE, WinApi_LOGFONTA*, LONGINT *), (f, f__typ, aName, aName__len, aPitch, result, result__typ))
#define __AclLib_TFonts_GetFont(f, f__typ, i, result, result__typ) __SEND(f__typ, AclLib_TFonts_GetFont, 4, void(*)(AclLib_TFonts*, LONGINT *, INTEGER, WinApi_LOGFONTA*, LONGINT *), (f, f__typ, i, result, result__typ))
#define __AclLib_TFonts_IndexOf(f, f__typ, APitch, AName, AName__len) __SEND(f__typ, AclLib_TFonts_IndexOf, 5, INTEGER(*)(AclLib_TFonts*, LONGINT *, BYTE, CHAR*, LONGINT ), (f, f__typ, APitch, AName, AName__len))
#define __AclLib_TFonts_IsDefaultPitch(f, f__typ, AFont, AFont__typ) __SEND(f__typ, AclLib_TFonts_IsDefaultPitch, 6, BOOLEAN(*)(AclLib_TFonts*, LONGINT *, WinApi_LOGFONTA*, LONGINT *), (f, f__typ, AFont, AFont__typ))
#define __AclLib_TFonts_IsFixedPitch(f, f__typ, AFont, AFont__typ) __SEND(f__typ, AclLib_TFonts_IsFixedPitch, 7, BOOLEAN(*)(AclLib_TFonts*, LONGINT *, WinApi_LOGFONTA*, LONGINT *), (f, f__typ, AFont, AFont__typ))
#define __AclLib_TFonts_IsVariablePitch(f, f__typ, AFont, AFont__typ) __SEND(f__typ, AclLib_TFonts_IsVariablePitch, 9, BOOLEAN(*)(AclLib_TFonts*, LONGINT *, WinApi_LOGFONTA*, LONGINT *), (f, f__typ, AFont, AFont__typ))
#define __AclLib_TFonts_SetCharSet(f, f__typ, value) __SEND(f__typ, AclLib_TFonts_SetCharSet, 10, void(*)(AclLib_TFonts*, LONGINT *, CHAR), (f, f__typ, value))

typedef
	struct AclLib_TLabel { /* AclLib_TStdControl */
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TLabel;

typedef
	struct AclLib_TListBox { /* AclLib_TStdControl */
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TListBox;

typedef
	struct AclLib_TObject {
		char _prvt0[1];
	} AclLib_TObject;

typedef
	struct AclLib_TProgressBar { /* AclLib_TStdControl */
		char _prvt0[800];
		SYSTEM_PTR Brush;
		char _prvt1[8];
		SHORTINT Cursor;
		char _prvt2[148];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[15];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[6];
	} AclLib_TProgressBar;



import LONGINT *AclLib_TObject__typ;
import LONGINT *AclLib_TCreateParams__typ;
import LONGINT *AclLib_TFont__typ;
import LONGINT *AclLib_TFonts__typ;
import LONGINT *AclLib_TWinControl__typ;
import LONGINT *AclLib_TStdControl__typ;
import LONGINT *AclLib_TLabel__typ;
import LONGINT *AclLib_TListBox__typ;
import LONGINT *AclLib_TButton__typ;
import LONGINT *AclLib_TCheckBox__typ;
import LONGINT *AclLib_TProgressBar__typ;

import void *AclLib__init(void);


#endif
