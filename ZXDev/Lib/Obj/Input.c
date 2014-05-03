/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export SHORTINT Input_Available (void);
export CHAR Input_Read (void);


/*============================================================================*/

SHORTINT Input_Available (void)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
CHAR Input_Read (void)
{
	return 0x00;
}

/*----------------------------------------------------------------------------*/

export void *Input__init(void)
{
	__DEFMOD;
	__REGMOD("Input", 0);
/* BEGIN */
	__ENDMOD;
}
