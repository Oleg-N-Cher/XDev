/* Ofront+ 1.0 -s3 -21 */
#include "SYSTEM.h"

typedef
	CHAR CmdLine_String[1];




export void CmdLine_GetParam (SHORTINT n, CHAR *param, SHORTINT param__len);

#define CmdLine__init()	/*-noinit*/

/*============================================================================*/

void CmdLine_GetParam (SHORTINT n, CHAR *param, SHORTINT param__len)
{
	param[0] = 0x00;
}

