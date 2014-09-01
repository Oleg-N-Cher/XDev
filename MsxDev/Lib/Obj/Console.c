/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Console_At (SHORTINT x, SHORTINT y);
export void Console_Clear (void);
export void Console_WriteCh (CHAR ch);


/*============================================================================*/

void Console_At (SHORTINT x, SHORTINT y)
{
}

/*----------------------------------------------------------------------------*/
void Console_Clear (void)
{
}

/*----------------------------------------------------------------------------*/
void Console_WriteCh (CHAR ch)
{
}

/*----------------------------------------------------------------------------*/

export void *Console__init(void)
{
	__DEFMOD;
	__REGMOD("Console", 0);
	__REGCMD("Clear", Console_Clear);
/* BEGIN */
	__ENDMOD;
}
