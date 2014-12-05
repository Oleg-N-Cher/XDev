/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Asm.h"




export void AsmTest_Border (SHORTINT color);


/*============================================================================*/

void AsmTest_Border (SHORTINT color)
{
	Asm_Code((CHAR*)"POP  DE    ", (LONGINT)12);
	Asm_Code((CHAR*)"POP  HL    ", (LONGINT)12);
	Asm_Code((CHAR*)"PUSH HL    ", (LONGINT)12);
	Asm_Code((CHAR*)"PUSH DE    ", (LONGINT)12);
	Asm_Code((CHAR*)"LD   A,L   ", (LONGINT)12);
	Asm_Code((CHAR*)"JP   0x229B", (LONGINT)12);
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
