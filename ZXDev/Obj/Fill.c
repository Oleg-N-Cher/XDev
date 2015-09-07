/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Gfx.h"
#include "Basic.h"






/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Gfx__init);
	__IMPORT(Basic__init);
	__REGMAIN("Fill", 0);
/* BEGIN */
	Basic_Init();
	Basic_INK(0);
	Basic_PAPER(7);
	Basic_BORDER(7);
	Basic_CLS();
	Basic_PLOT(0, 0);
	Basic_DRAW(255, 0);
	Basic_PLOT(128, 0);
	Basic_DRAW(0, 175);
	Basic_CIRCLE(60, 88, 60);
	Basic_CIRCLE(194, 88, 60);
	Gfx_Fill(1, 1, 1);
	Basic_Quit();
	__FINI;
}
