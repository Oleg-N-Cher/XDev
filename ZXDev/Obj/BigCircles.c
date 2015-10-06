/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"


static INTEGER BigCircles_r;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("BigCircles", 0);
/* BEGIN */
	Basic_Init();
	BigCircles_r = 160;
	while (BigCircles_r >= 1) {
		Basic_CIRCLEW(129, 90, BigCircles_r);
		BigCircles_r += -1;
	}
	Basic_Quit();
	__FINI;
}
