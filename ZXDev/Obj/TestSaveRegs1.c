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
	__REGMAIN("TestSaveRegs1", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Basic_AT(0, 0);
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"AT_ROM_stdcall ", 16);
	Debug_SaveRegsDef();
	Basic_AT(0, 15);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"ATTR ", 6);
	Debug_SaveRegsDef();
	if (Basic_ATTR(1, 15) == 0) {
	}
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"BEEP_DI ", 9);
	Debug_SaveRegsDef();
	Basic_BEEP(10, 1);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"BORDER_z88dk_fast ", 19);
	Debug_SaveRegsDef();
	Basic_BORDER(3);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"BRIGHT ", 8);
	Debug_SaveRegsDef();
	Basic_BRIGHT(1);
	Debug_CheckRegs();
	Basic_Quit();
	__FINI;
}
