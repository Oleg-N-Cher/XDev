/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"


static SHORTINT ASCII_n, ASCII__for__1;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__REGMAIN("ASCII", 0);
/* BEGIN */
	ASCII_n = 32;
	ASCII__for__1 = 127;
	ASCII__for__1 = (ASCII__for__1 - ASCII_n) + 1;
	do {
		Console_WriteCh((CHAR)ASCII_n);
		ASCII_n += 1;
		ASCII__for__1 -= 1;
	} while (!(ASCII__for__1 == 0));
	__FINI;
}
