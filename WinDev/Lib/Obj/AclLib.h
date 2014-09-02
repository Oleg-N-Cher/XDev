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
		char _prvt1[4];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style;
		char _prvt3[8];
		INTEGER Left, Top, Width, Height;
		char _prvt4[15];
		BOOLEAN Visible;
		char _prvt5[4];
	} AclLib_TWinControl;

import void AclLib_TWinControl_Create (AclLib_TWinControl *w, LONGINT *w__typ, AclLib_PWinControl AParent);
import void AclLib_TWinControl_SetCaption (AclLib_TWinControl *w, LONGINT *w__typ, CHAR *value, LONGINT value__len);
import void AclLib_TWinControl_SetColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetHeight (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetLeft (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetTextColor (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetTop (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
import void AclLib_TWinControl_SetWidth (AclLib_TWinControl *w, LONGINT *w__typ, INTEGER value);
#define __AclLib_TWinControl_Create(w, w__typ, AParent) __SEND(w__typ, AclLib_TWinControl_Create, 0, void(*)(AclLib_TWinControl*, LONGINT *, AclLib_PWinControl), (w, w__typ, AParent))
#define __AclLib_TWinControl_SetCaption(w, w__typ, value, value__len) __SEND(w__typ, AclLib_TWinControl_SetCaption, 5, void(*)(AclLib_TWinControl*, LONGINT *, CHAR*, LONGINT ), (w, w__typ, value, value__len))
#define __AclLib_TWinControl_SetColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetColor, 6, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetHeight(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetHeight, 7, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetLeft(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetLeft, 8, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTextColor(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTextColor, 9, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetTop(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetTop, 10, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))
#define __AclLib_TWinControl_SetWidth(w, w__typ, value) __SEND(w__typ, AclLib_TWinControl_SetWidth, 11, void(*)(AclLib_TWinControl*, LONGINT *, INTEGER), (w, w__typ, value))



import LONGINT *AclLib_TWinControl__typ;

import void *AclLib__init(void);


#endif
