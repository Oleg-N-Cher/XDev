/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR CmdLine_String[1];




export void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len);

#define CmdLine__init()	/*-noinit*/

/*============================================================================*/

void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len)
{
	param[0] = 0x00;
}

/*----------------------------------------------------------------------------*/

export void *CmdLine__init(void)
{
	__DEFMOD;
	__REGMOD("CmdLine", 0);
/* BEGIN */
	__ENDMOD;
}
