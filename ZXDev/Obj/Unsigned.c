/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Basic.h"
#include "Platform.h"


static SHORTCARD Unsigned_byte, Unsigned__for__1;





export void *Unsigned__init(void)
{
	__DEFMOD;
	__IMPORT(Basic);
	__IMPORT(Platform);
	__REGMOD("Unsigned", 0);
/* BEGIN */
	Basic_PAPER(0);
	Basic_INK(1);
	Basic_BRIGHT(1);
	Unsigned_byte = Platform_Unsigned(150);
	do {
		Basic_PRWORD(Unsigned_byte);
		Basic_PRCHAR(' ');
		Unsigned_byte -= 1;
	} while (!((int)Unsigned_byte == 60));
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
	__ENDMOD;
}
