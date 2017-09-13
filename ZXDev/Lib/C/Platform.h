#ifndef Platform__h
#define Platform__h

#include "SYSTEM.h"


typedef
	BYTE Platform_ADDRESS[65536];

typedef
	CHAR *Platform_STRING;


import void Platform_DISPOSE (SYSTEM_PTR *mem);
#define Platform_Unsigned(i) ((unsigned)(i))

void __sdcc_heap_init (void);
#ifndef SYSTEM_Use_HEAP
#  define Platform__init()
#else
#  define Platform__init() __sdcc_heap_init()
#endif

#endif
