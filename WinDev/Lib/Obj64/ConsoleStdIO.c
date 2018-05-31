/* Ofront+ 1.0 -sC -88 */
#include "SYSTEM.h"




export void ConsoleStdIO_WriteCh (CHAR ch);
export void ConsoleStdIO_WriteInt (INTEGER n);
export void ConsoleStdIO_WriteLn (void);
export void ConsoleStdIO_WriteStr (CHAR *str, INTEGER str__len);

#include <stdio.h>
#define ConsoleStdIO_printfc(ch)	printf("%c", ch)
#define ConsoleStdIO_printfi(n)	printf("%d", n);
#define ConsoleStdIO_printfli(l)	printf("%lld", l)
#define ConsoleStdIO_printfs(str, str__len)	printf("%s", str)

/*============================================================================*/

void ConsoleStdIO_WriteInt (INTEGER n)
{
	ConsoleStdIO_printfi(n);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteCh (CHAR ch)
{
	ConsoleStdIO_printfc(ch);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteLn (void)
{
	ConsoleStdIO_printfs((CHAR*)"\\n", 3);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteStr (CHAR *str, INTEGER str__len)
{
	ConsoleStdIO_printfs(str, str__len);
}

/*----------------------------------------------------------------------------*/

export void *ConsoleStdIO__init(void)
{
	__DEFMOD;
	__REGMOD("ConsoleStdIO", 0);
	__REGCMD("WriteLn", ConsoleStdIO_WriteLn);
/* BEGIN */
	__ENDMOD;
}
