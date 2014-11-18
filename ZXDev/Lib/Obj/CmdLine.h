/*  Ofront 1.2 -xtspkae */

#ifndef CmdLine__h
#define CmdLine__h

#include "SYSTEM.h"

typedef
	CHAR CmdLine_String[1];




import void CmdLine_GetParam (INTEGER n, CHAR *param, LONGINT param__len);
import void *CmdLine__init(void);

#define CmdLine__init()	/*-noinit*/

#endif
