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
	ASCII_n = 32;
	do {
		Console_WriteCh((CHAR)ASCII_n);
	} while (++ASCII_n >= 0);
	__FINI;
}
