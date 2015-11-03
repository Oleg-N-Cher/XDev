/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Platform.h"


static SHORTINT Unsigned_byte, Unsigned__for__1;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Platform__init);
	__REGMAIN("Unsigned", 0);
/* BEGIN */
	Basic_PAPER(0);
	Basic_INK(1);
	Basic_BRIGHT(1);
	Unsigned_byte = Platform_Unsigned(150);
	do {
		Basic_PRWORD(Unsigned_byte);
		Basic_PRCHAR(' ');
		Unsigned_byte -= 1;
	} while (!(Unsigned_byte == 60));
	Basic_INK(5);
	Basic_BRIGHT(0);
	Unsigned__for__1 = Platform_Unsigned(150);
	Unsigned_byte = 60;
	while (Unsigned_byte <= Unsigned__for__1) {
		Basic_PRWORD(Unsigned_byte);
		Basic_PRCHAR(' ');
		Unsigned_byte += 1;
	}
	Basic_INK(4);
	Unsigned_byte = Platform_Unsigned(-1);
	Basic_PRWORD(Unsigned_byte);
	Basic_PRCHAR(' ');
	Basic_PRWORD(Platform_Unsigned(-1));
	__FINI;
}
