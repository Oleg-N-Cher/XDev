/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Basic.h"




export void HelloWorld_Main (void);


void HelloWorld_Main (void)
{
	INTEGER x;
	Basic_Init();
	Basic_BORDER(4);
	Basic_PAPER(0);
	Basic_CLS();
	x = 0;
	while (x <= 245) {
		Basic_INK(6);
		Basic_PLOT(x, 127);
		Basic_DRAW(10, 10);
		Basic_INK(3);
		Basic_PLOT(x, 37);
		Basic_DRAW(10, 10);
		x += 2;
	}
	Basic_AT(11, 1);
	Basic_PAPER(1);
	Basic_INK(5);
	Basic_BRIGHT(1);
	Basic_FLASH(1);
	Basic_PRSTR((CHAR*)" HELLO WORLD of ZX Spectrum ! ", (LONGINT)31);
	Basic_PAUSE(0);
	Basic_Quit();
}


export void *HelloWorld__init(void)
{
	__DEFMOD;
	__IMPORT(Basic);
	__REGMOD("HelloWorld", 0);
	__REGCMD("Main", HelloWorld_Main);
/* BEGIN */
	__ENDMOD;
}
