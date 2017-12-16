/* Ofront+ 1.0 -sC -48 */
#include "SYSTEM.h"




export void ConsoleStdIO_WriteCh (CHAR ch);

#include <stdio.h>
#define ConsoleStdIO_printfc(ch)	printf("%c", ch)

/*============================================================================*/

void ConsoleStdIO_WriteCh (CHAR ch)
{
	ConsoleStdIO_printfc(ch);
}

/*----------------------------------------------------------------------------*/

export void *ConsoleStdIO__init(void)
{
	__DEFMOD;
	__REGMOD("ConsoleStdIO", 0);
/* BEGIN */
	__ENDMOD;
}
