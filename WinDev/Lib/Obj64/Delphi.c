/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export INTEGER Delphi_HiWord (INTEGER i);
export INTEGER Delphi_LoWord (INTEGER i);

#define Delphi__init()	/*-noinit*/

/*============================================================================*/

INTEGER Delphi_HiWord (INTEGER i)
{
	return __ASHR(i, 16);
}

/*----------------------------------------------------------------------------*/
INTEGER Delphi_LoWord (INTEGER i)
{
	return (int)((SET)i & 0xffff);
}

/*----------------------------------------------------------------------------*/

export void *Delphi__init(void)
{
	__DEFMOD;
	__REGMOD("Delphi", 0);
/* BEGIN */
	__ENDMOD;
}
