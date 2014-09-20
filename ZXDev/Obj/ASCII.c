/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"


static SHORTINT ASCII_n;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__REGMAIN("ASCII", 0);
/* BEGIN */
	ASCII_n = 31;
	while (ASCII_n <= 126) {
		Console_WriteCh((CHAR)(ASCII_n + 1));
		ASCII_n += 1;
	}
	__FINI;
}
