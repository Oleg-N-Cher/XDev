/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "CmdLine.h"

typedef
	CHAR (*CmdLine_ArgPtr)[128];

typedef
	CmdLine_ArgPtr (*CmdLine_ArgVec)[128];

/*typedef
	CHAR CmdLine_String[128];*/

export void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len);

/*================================== Header ==================================*/
export INTEGER CmdLine_paramCount;

/*--------------------------------- Cut here ---------------------------------*/
#define CmdLine_argc()	SYSTEM_argc
#define CmdLine_argv()	(long)SYSTEM_argv

void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len)
{
	CmdLine_ArgVec av = NIL;
	if (n <= CmdLine_paramCount) {
		av = (CmdLine_ArgVec)CmdLine_argv();
		__COPY(*(*av)[__X(n, 128)], param, param__len);
	} else {
		__COPY("", param, param__len);
	}
}

