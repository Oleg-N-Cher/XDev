/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *Platform_STRING;




export SET Platform_BITS (INTEGER i);
export void Platform_DISPOSE (SYSTEM_PTR *mem);
export INTEGER Platform_ORD (SET s);
export SYSTEM_BYTE Platform_Unsigned (LONGCARD i);

#define Platform_free(memblock)	free(memblock)

SET Platform_BITS (INTEGER i)
{
	return __VAL(SET, i);
}

INTEGER Platform_ORD (SET s)
{
	return __VAL(INTEGER, s);
}

SYSTEM_BYTE Platform_Unsigned (LONGCARD i)
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
