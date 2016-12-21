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
	Basic_PRSTR((CHAR*)"AT_FAST_fastcall ", 18);
	Debug_SaveRegsDef();
	Basic_AT(4, 9);
	Debug_CheckRegs();
	Basic_Quit();
	__FINI;
}
