/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Console_At (INTEGER x, INTEGER y);
export void Console_SetColors (INTEGER n);
export void Console_WriteCh (CHAR ch);
export void Console_WriteInt (LONGINT n);
export void Console_WriteLn (void);
export void Console_WriteStr (CHAR *str, LONGINT str__len);
export void Console_WriteStrLn (CHAR *str, LONGINT str__len);

#include <stdio.h>
#define Console_writeCh(ch)	printf("%c", ch)
#define Console_writeInt(n)	printf("%ld", n)
#define Console_writeLInt(n)	printf("%lld", n)
#define Console_writeLn()	printf("\n")
#define Console_writeStr(str, str__len)	printf("%s", str)
#define Console_writeStrLn(str, str__len)	printf("%s\n", str)

void Console_At (INTEGER x, INTEGER y)
{
}

void Console_WriteInt (LONGINT n)
{
	Console_writeInt(n);
}

void Console_WriteStr (CHAR *str, LONGINT str__len)
{
	Console_writeStr(str, str__len);
}

void Console_WriteStrLn (CHAR *str, LONGINT str__len)
{
	Console_writeStrLn(str, str__len);
}

void Console_WriteCh (CHAR ch)
{
	Console_writeCh(ch);
}

void Console_WriteLn (void)
{
	Console_writeLn();
}

void Console_SetColors (INTEGER n)
{
}


export void *Console__init(void)
{
	__DEFMOD;
	__REGMOD("Console", 0);
	__REGCMD("WriteLn", Console_WriteLn);
/* BEGIN */
	__ENDMOD;
}
