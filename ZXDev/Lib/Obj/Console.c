/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrFonts.h"




export void Console_At (INTEGER x, INTEGER y);
export void Console_Clear (INTEGER attr);
export void Console_SetColors (INTEGER attr);
export void Console_SetFont (SYSTEM_BYTE *font, LONGINT font__len);
export void Console_WriteCh (CHAR ch);
export void Console_WriteInt (LONGINT i);
export void Console_WriteLn (void);
export void Console_WriteStr (CHAR *str, LONGINT str__len);
export void Console_WriteStrLn (CHAR *str, LONGINT str__len);


void Console_At (INTEGER x, INTEGER y)
{
}

void Console_Clear (INTEGER attr)
{
}

void Console_SetColors (INTEGER attr)
{
}

void Console_SetFont (SYSTEM_BYTE *font, LONGINT font__len)
{
}

void Console_WriteCh (CHAR ch)
{
}

void Console_WriteInt (LONGINT i)
{
}

void Console_WriteLn (void)
{
}

void Console_WriteStr (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}

void Console_WriteStrLn (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}


export void *Console__init(void)
{
	__DEFMOD;
	__IMPORT(GrFonts__init);
	__REGMOD("Console", 0);
	__REGCMD("WriteLn", Console_WriteLn);
/* BEGIN */
	__ENDMOD;
}
