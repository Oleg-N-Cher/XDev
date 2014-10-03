/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR (*CmdLine_ArgPtr)[1024];

typedef
	CmdLine_ArgPtr (*CmdLine_ArgVec)[1024];

export void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len);

extern INTEGER CmdLine_ParamCount;
/*================================== Header ==================================*/
export INTEGER CmdLine_ParamCount;

/*--------------------------------- Cut here ---------------------------------*/
#define CmdLine_argc()	SYSTEM_argc
#define CmdLine_argv()	(long)SYSTEM_argv

void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len)
{
	CmdLine_ArgVec av = NIL;
	if (n <= CmdLine_ParamCount) {
		av = (CmdLine_ArgVec)CmdLine_argv();
		__COPY(*(*av)[__X(n, 1024)], param, param__len);
	} else {
		__COPY("", param, param__len);
	}
}

