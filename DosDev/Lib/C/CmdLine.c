#include "SYSTEM.oh"
#include "CmdLine.oh"

typedef
	CHAR (*CmdLine_ArgPtr)[128];

typedef
	CmdLine_ArgPtr (*CmdLine_ArgVec)[128];

/*typedef
	CHAR CmdLine_String[128];*/

export void CmdLine_GetParam (SHORTINT n, CHAR *param, SHORTINT param__len);

/*================================== Header ==================================*/
export SHORTINT CmdLine_paramCount;

/*--------------------------------- Cut here ---------------------------------*/
#define CmdLine_argc()	SYSTEM_argc
#define CmdLine_argv()	(long)SYSTEM_argv

void CmdLine_GetParam (SHORTINT n, CHAR *param, SHORTINT param__len)
{
	CmdLine_ArgVec av = NIL;
	if (n <= CmdLine_paramCount) {
		av = (CmdLine_ArgVec)CmdLine_argv();
		__COPY(*(*av)[n], param, param__len);
	} else {
		__COPY("", param, param__len);
	}
}

