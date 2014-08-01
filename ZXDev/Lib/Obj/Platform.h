/*  Ofront 1.2 -xtspkae */

#ifndef Platform__h
#define Platform__h

#include "SYSTEM.h"

typedef
	SHORTCARD Platform_SHORTCARD;

typedef
	Platform_SHORTCARD Platform_ADDRESS[65536];

typedef
	CHAR *Platform_STRING;




import void Platform_DISPOSE (SYSTEM_PTR *mem);
import Platform_SHORTCARD Platform_Unsigned (LONGCARD i);
import void *Platform__init(void);


#endif
