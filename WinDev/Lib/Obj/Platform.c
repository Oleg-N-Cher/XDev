/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *Platform_STRING;




export SET Platform_BITS (INTEGER i);
export void Platform_DISPOSE (SYSTEM_PTR mem);
export INTEGER Platform_ORD (SET s);

#define Platform_free(memblock)	free(memblock)

SET Platform_BITS (INTEGER i)
{
	return __VAL(SET, i);
}

INTEGER Platform_ORD (SET s)
{
	return __VAL(INTEGER, s);
}

void Platform_DISPOSE (SYSTEM_PTR mem)
{
	Platform_free(mem);
}


export void *Platform__init(void)
{
	__DEFMOD;
	__REGMOD("Platform", 0);
/* BEGIN */
	__ENDMOD;
}
