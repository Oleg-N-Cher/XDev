/*  Ofront 1.2 -xtspkae */

#ifndef KolTypes__h
#define KolTypes__h

#include "SYSTEM.h"

typedef
	SYSTEM_PTR (*KolTypes_ANYPTR)[1];

typedef
	CHAR *KolTypes_AnsiString;

typedef
	CHAR *KolTypes_KOLString;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *KolTypes_PKOLChar;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *KolTypes_PKOLString;




import void KolTypes_IntToString (LONGINT x, CHAR *s, LONGINT s__len);
import void KolTypes_StringToInt (CHAR *s, LONGINT s__len, INTEGER *x, INTEGER *res);
import void *KolTypes__init(void);

#define KolTypes__init()	/*-noinit*/

#endif
