/*  Ofront 1.2 -xtspkae */

#ifndef KolXXSocket__h
#define KolXXSocket__h

#include "SYSTEM.h"

typedef
	CHAR *KolXXSocket_AnsiString;

typedef
	struct KolXXSocket_TObj *KolXXSocket_PObj;

typedef
	struct KolXXSocket_TObj {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[8];
	} KolXXSocket_TObj;

import void KolXXSocket_TObj_Create (KolXXSocket_TObj *obj, LONGINT *obj__typ);
import void KolXXSocket_TObj_Destroy (KolXXSocket_TObj *obj, LONGINT *obj__typ);
import void KolXXSocket_TObj_Free (KolXXSocket_TObj *obj, LONGINT *obj__typ);
#define __KolXXSocket_TObj_Create(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_Create, 0, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))
#define __KolXXSocket_TObj_Destroy(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_Destroy, 1, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))
#define __KolXXSocket_TObj_Free(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_Free, 2, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))



import LONGINT *KolXXSocket_TObj__typ;

import void KolXXSocket_Free_And_Nil (KolXXSocket_PObj *obj);
import void *KolXXSocket__init(void);


#endif
