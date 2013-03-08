/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Console.h"

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

/*================================== Header ==================================*/
void Console_WriteInt (LONGINT n)
{
	Console_writeInt(n);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr (CHAR *str, LONGINT str__len)
{
	Console_writeStr(str, str__len);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStrLn (CHAR *str, LONGINT str__len)
{
	Console_writeStrLn(str, str__len);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteCh (CHAR ch)
{
	Console_writeCh(ch);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn (void)
{
	Console_writeLn();
}

//export void *Console__init(void)
//{
//	__DEFMOD;
//	__REGMOD("Console", 0);
//	__REGCMD("WriteLn", Console_WriteLn);
///* BEGIN */
//	__ENDMOD;
//}
