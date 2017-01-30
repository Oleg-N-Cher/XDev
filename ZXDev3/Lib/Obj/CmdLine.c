/* Ofront+ 0.9 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR CmdLine_String[1];




export void CmdLine_GetParam (INTEGER n, CHAR *param, SHORTINT param__len);


/*============================================================================*/

void CmdLine_GetParam (INTEGER n, CHAR *param, SHORTINT param__len)
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
