/* Ofront+ 1.0 -sx3 -21 */
#include "SYSTEM.h"

typedef
	CHAR CmdLine_String[1];




export void CmdLine_GetParam (BYTE n, CHAR *param, SHORTINT param__len);

#define CmdLine__init()	/*-noinit*/

/*============================================================================*/

void CmdLine_GetParam (BYTE n, CHAR *param, SHORTINT param__len)
{
	param[0] = 0x00;
}

/*----------------------------------------------------------------------------*/

export void *CmdLine__init (void)
{
	__DEFMOD;
	__REGMOD("CmdLine", 0);
/* BEGIN */
	__ENDMOD;
}
