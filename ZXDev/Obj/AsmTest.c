/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Asm.h"




export void AsmTest_Border (SHORTINT color);


/*============================================================================*/

void AsmTest_Border (SHORTINT color)
{
	Asm_Code((CHAR*)"LD   A,4(IX)", (LONGINT)13);
	Asm_Code((CHAR*)"CALL 0x229B ", (LONGINT)13);
}

/*----------------------------------------------------------------------------*/

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Asm__init);
	__REGMAIN("AsmTest", 0);
/* BEGIN */
	AsmTest_Border(2);
	__FINI;
}
