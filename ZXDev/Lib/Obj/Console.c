/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Console_SetColors (INTEGER attr);
export void Console_WriteCh (CHAR ch);
export void Console_WriteStr (CHAR *str, LONGINT str__len);


void Console_SetColors (INTEGER attr)
{
}

void Console_WriteCh (CHAR ch)
{
}

void Console_WriteStr (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}


export void *Console__init(void)
{
	__DEFMOD;
	__REGMOD("Console", 0);
/* BEGIN */
	__ENDMOD;
}
