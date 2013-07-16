/*  Ofront 1.2 -xtspkae */

#ifndef Platform__h
#define Platform__h

#include "SYSTEM.h"

typedef
	CHAR *Platform_STRING;




import SET Platform_BITS (INTEGER i);
import void Platform_DISPOSE (SYSTEM_PTR *mem);
import INTEGER Platform_ORD (SET s);
import SYSTEM_BYTE Platform_Unsigned (LONGCARD i);
import void *Platform__init(void);


#endif
