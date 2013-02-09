/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Platform.h"

typedef
	CHAR *Platform_STRING;

export SET Platform_BITS (INTEGER i);
export INTEGER Platform_ORD (SET s);
//export void *Platform__init (void);

/*================================== Header ==================================*/
SET Platform_BITS (INTEGER i)
{
	return __VAL(SET, i);
}

/*--------------------------------- Cut here ---------------------------------*/
INTEGER Platform_ORD (SET s)
{
	return __VAL(INTEGER, s);
}

//export void *Platform__init(void)
//{
//	__DEFMOD;
//	__REGMOD("Platform", 0);
///* BEGIN */
//	__ENDMOD;
//}
