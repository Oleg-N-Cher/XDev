/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Asm.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Asm__init);
	__REGMAIN("BrightLetters", 0);
/* BEGIN */
	Basic_Init();
	Basic_INK(0);
	Basic_PAPER(0);
	Basic_BORDER(0);
	Basic_CLS();
	Basic_AT(0, 0);
	Basic_PRSTR((CHAR*)" FLASH (C) AZH soft 1996", 25);
	Basic_Quit();
	Asm_Code((CHAR*)"     LD   A, #6      ", 22);
	Asm_Code((CHAR*)"     LD   HL, #22528 ", 22);
	Asm_Code((CHAR*)"                     ", 22);
	Asm_Code((CHAR*)"     LD   B, #32     ", 22);
	Asm_Code((CHAR*)"L1$: PUSH AF         ", 22);
	Asm_Code((CHAR*)"L2$: INC  (HL)       ", 22);
	Asm_Code((CHAR*)"     DEC  A          ", 22);
	Asm_Code((CHAR*)"     HALT            ", 22);
	Asm_Code((CHAR*)"     JR   NZ, L2$    ", 22);
	Asm_Code((CHAR*)"     POP  AF         ", 22);
	Asm_Code((CHAR*)"     INC  HL         ", 22);
	Asm_Code((CHAR*)"     DJNZ L1$        ", 22);
	__FINI;
}
