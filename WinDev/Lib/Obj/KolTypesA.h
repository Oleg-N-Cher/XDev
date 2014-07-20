/*  Ofront 1.2 -xtspkae */

#ifndef KolTypesA__h
#define KolTypesA__h

#include "SYSTEM.h"

typedef
	CHAR *KolTypesA_AnsiString;

typedef
	CHAR *KolTypesA_KOLString;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *KolTypesA_PKOLChar;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *KolTypesA_PKOLString;




import void *KolTypesA__init(void);

#define KolTypesA__init()	/*-noinit*/

#endif
