/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	SYSTEM_BYTE Platform_ADDRESS[65536];

typedef
	CHAR *Platform_STRING;




export Platform_SHORTCARD Platform_Unsigned (LONGCARD i);


Platform_SHORTCARD Platform_Unsigned (LONGCARD i)
{
	return (int)i;
}


export void *Platform__init(void)
{
	__DEFMOD;
	__REGMOD("Platform", 0);
/* BEGIN */
	__ENDMOD;
}
