/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Debug.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Debug__init);
	__REGMAIN("TestSaveRegs3", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Basic_AT(1, 0);
	Basic_COLOR(6);
	Basic_AT(0, 7);
	Basic_PRSTR((CHAR*)"AT_FAST_fastcall ", 18);
	Debug_SaveRegsDef();
	Basic_AT(4, 9);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(1, 10);
	Basic_PRSTR((CHAR*)"INVERSE_FAST ", 14);
	Debug_SaveRegsDef();
	Basic_INVERSE(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(2, 10);
	Basic_PRSTR((CHAR*)"OVER_FAST ", 11);
	Debug_SaveRegsDef();
	Basic_OVER(0);
	Debug_CheckRegs();
	Basic_Quit();
	__FINI;
}
