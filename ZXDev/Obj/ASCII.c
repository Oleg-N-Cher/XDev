/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Console.h"


static INTEGER ASCII_n;





export void *ASCII__init(void)
{
	__DEFMOD;
	__IMPORT(Console);
	__REGMOD("ASCII", 0);
/* BEGIN */
	ASCII_n = 32;
	while (ASCII_n <= 127) {
		Console_WriteCh((CHAR)ASCII_n);
		ASCII_n += 1;
	}
	__ENDMOD;
}
