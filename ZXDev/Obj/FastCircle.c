/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"


static INTEGER FastCircle_r;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("FastCircle", 0);
/* BEGIN */
	Basic_Init();
	FastCircle_r = 160;
	while (FastCircle_r >= 1) {
		Basic_CIRCLE(129, 90, FastCircle_r);
		FastCircle_r += -1;
	}
	Basic_Quit();
	__FINI;
}
