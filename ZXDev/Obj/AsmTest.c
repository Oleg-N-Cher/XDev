/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Asm.h"






/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Asm__init);
	__REGMAIN("AsmTest", 0);
/* BEGIN */
	Asm_Byte2(62, 1);
	Asm_Byte2(211, 254);
	Asm_Code((CHAR*)"DI", (LONGINT)3);
	__FINI;
}
