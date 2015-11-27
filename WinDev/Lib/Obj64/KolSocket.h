/*  Ofront 1.2 -xtspkae */

#ifndef KolSocket__h
#define KolSocket__h

#include "SYSTEM.h"
#include "KolObj.h"

typedef
	struct KolSocket_TAsyncSocket *KolSocket_PAsyncSocket;

typedef
	struct KolSocket_TAsyncSocket { /* KolObj_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[8];
	} KolSocket_TAsyncSocket;



import LONGINT *KolSocket_TAsyncSocket__typ;

import KolSocket_PAsyncSocket KolSocket_NewAsyncSocket (void);
import void *KolSocket__init(void);


#endif
