/*  Ofront 1.2 -xtspkae */

#ifndef AclLib__h
#define AclLib__h

#include "SYSTEM.h"

typedef
	struct AclLib_TWinControl *AclLib_PWinControl;

typedef
	struct AclLib_TWinControl {
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TWinControl;

import void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_PWinControl AParent);
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
#define __AclLib_TWinControl_Create(w, w__typ, AParent) __SEND(w__typ, AclLib_TWinControl_Create, 0, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_PWinControl), (w, w__typ, AParent))
#define __AclLib_TWinControl_CreateWnd(w, w__typ) __SEND(w__typ, AclLib_TWinControl_CreateWnd, 3, void(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))
#define __AclLib_TWinControl_SetCaption(w, w__typ, value, value__len) __SEND(w__typ, AclLib_TWinControl_SetCaption, 14, void(*)(AclLib_TWinControl*, LONGINT *, CHAR*, LONGINT ), (w, w__typ, value, value__len))
#define __AclLib_TWinControl_SetColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetColor, 15, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetHeight(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetHeight, 17, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetLeft(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetLeft, 18, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTextColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTextColor, 19, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTop(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTop, 20, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetVisible(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetVisible, 21, void(*)(AclLib_TWinControl*, LONGINT *, BOOLEAN), (w, w__typ, value))
#define __AclLib_TWinControl_SetWidth(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetWidth, 22, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_ShowModal(w, w__typ) __SEND(w__typ, AclLib_TWinControl_ShowModal, 24, INTEGER(*)(AclLib_TWinControl*, LONGINT *), (w, w__typ))

typedef
	struct AclLib_TStdControl { /* AclLib_TWinControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TStdControl;

typedef
	struct AclLib_TButton { /* AclLib_TStdControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TButton;

typedef
	struct AclLib_TCheckBox { /* AclLib_TStdControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TCheckBox;

typedef
	struct AclLib_TCreateParams {
		INTEGER _prvt0;
		char _prvt1[388];
	} AclLib_TCreateParams;

typedef
	struct AclLib_TLabel { /* AclLib_TStdControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TLabel;

typedef
	struct AclLib_TListBox { /* AclLib_TStdControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TListBox;

typedef
	struct AclLib_TObject {
		char _prvt0[1];
	} AclLib_TObject;

typedef
	struct AclLib_TProgressBar { /* AclLib_TStdControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[12];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[6];
	} AclLib_TProgressBar;



import LONGINT *AclLib_TObject__typ;
import LONGINT *AclLib_TCreateParams__typ;
import LONGINT *AclLib_TWinControl__typ;
import LONGINT *AclLib_TStdControl__typ;
import LONGINT *AclLib_TLabel__typ;
import LONGINT *AclLib_TListBox__typ;
import LONGINT *AclLib_TButton__typ;
import LONGINT *AclLib_TCheckBox__typ;
import LONGINT *AclLib_TProgressBar__typ;

import void *AclLib__init(void);


#endif
