/*  Ofront 1.2 -xtspkae */

#ifndef KolObj__h
#define KolObj__h

#include "SYSTEM.h"

typedef
	struct KolObj_TObj *KolObj_PObj;

typedef
	struct KolObj_TObj {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[8];
	} KolObj_TObj;

import void KolObj_TObj_Create (KolObj_TObj *obj, LONGINT *obj__typ);
import void KolObj_TObj_Destroy (KolObj_TObj *obj, LONGINT *obj__typ);
import void KolObj_TObj_Free (KolObj_TObj *obj, LONGINT *obj__typ);
#define __KolObj_TObj_Create(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_Create, 0, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))
#define __KolObj_TObj_Destroy(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_Destroy, 1, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))
#define __KolObj_TObj_Free(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_Free, 2, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))



import LONGINT *KolObj_TObj__typ;

import void *KolObj__init(void);


#endif
