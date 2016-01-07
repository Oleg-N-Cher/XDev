/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"






/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("Fill", 0);
/* BEGIN */
	Basic_Init();
	Basic_POKE(23693, 56);
	Basic_BORDER(7);
	Basic_CLS();
	Basic_PLOT(0, 0);
	Basic_DRAW(255, 0);
	Basic_PLOT(128, 0);
	Basic_DRAW(0, 175);
	Basic_CIRCLEROM(60, 88, 60);
	Basic_CIRCLEROM(194, 88, 60);
	Basic_PAINT(1, 17, 1);
	Basic_PAINT(250, 17, 2);
	Basic_PAUSE(100);
	Basic_CLS();
	Basic_CIRCLEROM(128, 88, 87);
	Basic_PAINT(128, 18, 4);
	Basic_PAUSE(0);
	Basic_Quit();
	__FINI;
}
