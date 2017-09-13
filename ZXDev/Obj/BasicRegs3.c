/* Ofront+ 0.9 -sm */
#include "SYSTEM.h"
#include "Basic.h"
#include "Debug.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Debug__init);
	__REGMAIN("BasicRegs3", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Basic_COLOR(6);
	Basic_AT(0, 8);
	Basic_PRSTR((CHAR*)"AT_FAST_fastcall", 17);
	Debug_SaveRegsDef();
	Basic_AT(4, 10);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(1, 11);
	Basic_PRSTR((CHAR*)"INVERSE_FAST", 13);
	Debug_SaveRegsDef();
	Basic_INVERSE(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(2, 11);
	Basic_PRSTR((CHAR*)"OVER_FAST", 10);
	Debug_SaveRegsDef();
	Basic_OVER(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(3, 4);
	Basic_PRSTR((CHAR*)"PRCHAR_FAST", 12);
	Debug_SaveRegsDef();
	Basic_PRCHAR(0x90);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(4, 4);
	Basic_PRSTR((CHAR*)"PRDATA_FAST", 12);
	Debug_SaveRegsDef();
	Basic_PRDATA();
	Basic_DATACH2(0x90, 0x00);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(5, 4);
	Basic_PRSTR((CHAR*)"PRINT_FAST ", 12);
	Basic_COLOR(5);
	Debug_SaveRegsDef();
	Basic_PRINT(-12345);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(6, 12);
	Basic_PRSTR((CHAR*)"PRLN_FAST", 10);
	Debug_SaveRegsDef();
	Basic_PRLN();
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(7, 6);
	Debug_SaveRegsDef();
	Basic_PRSTR((CHAR*)"PRSTR_FAST", 11);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(8, 4);
	Basic_PRSTR((CHAR*)"PRWORD_FAST ", 13);
	Basic_COLOR(5);
	Debug_SaveRegsDef();
	Basic_PRWORD(12345);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(9, 14);
	Basic_PRSTR((CHAR*)"SGN", 4);
	Debug_SaveRegsDef();
	if (Basic_SGN(-1) == 0) {
	}
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_AT(10, 12);
	Basic_PRSTR((CHAR*)"SGNI", 5);
	Debug_SaveRegsDef();
	if (Basic_SGNI(-1) == 0) {
	}
	Debug_CheckRegs();
	Basic_Quit();
	__FINI;
}
