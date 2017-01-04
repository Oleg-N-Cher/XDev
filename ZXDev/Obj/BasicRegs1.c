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
	__REGMAIN("BasicRegs1", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"ABS ", 5);
	Debug_SaveRegsDef();
	if (Basic_ABS(-1) == 0) {
	}
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"ABSI ", 6);
	Debug_SaveRegsDef();
	if (Basic_ABSI(-1) == 0) {
	}
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"AT_ROM_callee ", 15);
	Debug_SaveRegsDef();
	Basic_AT(2, 14);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"ATTR_callee ", 13);
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
	Basic_PRSTR((CHAR*)"BORDER_fastcall ", 17);
	Debug_SaveRegsDef();
	Basic_BORDER(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"BRIGHT ", 8);
	Debug_SaveRegsDef();
	Basic_BRIGHT(1);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"CIRCLE ", 8);
	Debug_SaveRegsDef();
	Basic_CIRCLE(250, 170, 3);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"CIRCLEROM ", 11);
	Debug_SaveRegsDef();
	Basic_CIRCLEROM(236, 170, 3);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"CIRCLEW_DI ", 12);
	Debug_SaveRegsDef();
	Basic_CIRCLEW(250, 170, 5);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"COLOR ", 7);
	Debug_SaveRegsDef();
	Basic_COLOR(6);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"DRAW_callee ", 13);
	Basic_PLOT(0, 0);
	Debug_SaveRegsDef();
	Basic_DRAW(3, 3);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"FLASH ", 7);
	Debug_SaveRegsDef();
	Basic_FLASH(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"INK ", 5);
	Debug_SaveRegsDef();
	Basic_INK(6);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"INKEY ", 7);
	Debug_SaveRegsDef();
	if (Basic_INKEY() == 0x00) {
	}
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"INVERSE_ROM ", 13);
	Debug_SaveRegsDef();
	Basic_INVERSE(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"OVER_ROM ", 10);
	Debug_SaveRegsDef();
	Basic_OVER(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"PAINT ", 7);
	Debug_SaveRegsDef();
	Basic_PAINT(236, 186, 2);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"PAPER ", 7);
	Debug_SaveRegsDef();
	Basic_PAPER(0);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"PAUSE_DI ", 10);
	Debug_SaveRegsDef();
	Basic_PAUSE(1);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"PLOT_callee ", 13);
	Debug_SaveRegsDef();
	Basic_PLOT(255, 175);
	Debug_CheckRegs();
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"POINT_callee ", 14);
	Debug_SaveRegsDef();
	if (Basic_POINT(0, 0)) {
	}
	Debug_CheckRegs();
	Basic_Quit();
	__FINI;
}
