/*  Ofront 1.2 -xtspkae */

#ifndef Types__h
#define Types__h

#include "SYSTEM.h"

typedef
	void (*Types_PROC)(void);

typedef
	CHAR Types_STRING[32767];

typedef
	Types_STRING *Types_STRPTR;




import void *Types__init(void);

#define Types__init()	/*-noinit*/

#endif
