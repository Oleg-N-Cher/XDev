/*  Ofront 1.2 -xtspkae */

#ifndef CmdLine__h
#define CmdLine__h

#include "SYSTEM.h"

typedef
	CHAR CmdLine_String[1024];


import INTEGER CmdLine_ParamCount;


import void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len);
#ifndef DJGPP 
#  define CmdLine__init() CmdLine_ParamCount = SYSTEM_argc - 1;
#else
#  define CmdLine__init() {int tmp; \
     __getmainargs(&SYSTEM_argc, &SYSTEM_argv, &tmp, 0, &tmp); CmdLine_ParamCount = SYSTEM_argc - 1;}
#endif


#endif
