/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	SYSTEM_BYTE Platform_ADDRESS[65536];

typedef
	CHAR *Platform_STRING;




export void Platform_DISPOSE (SYSTEM_PTR *mem);
export Platform_SHORTCARD Platform_Unsigned (LONGCARD i);

#define Platform_free(memblock)	free(memblock)

Platform_SHORTCARD Platform_Unsigned (LONGCARD i)
{
	return (int)i;
}

void Platform_DISPOSE (SYSTEM_PTR *mem)
{
	Platform_free(*mem);
	*mem = NIL;
}


export void *Platform__init(void)
{
	__DEFMOD;
	__REGMOD("Platform", 0);
/* BEGIN */
	__ENDMOD;
}
