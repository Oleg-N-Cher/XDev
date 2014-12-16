/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"


static SHORTINT FastCircle_r;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("FastCircle", 0);
/* BEGIN */
	Basic_Init();
	FastCircle_r = 0;
	while (FastCircle_r <= 72) {
		Basic_CIRCLE(121, 85, FastCircle_r);
		FastCircle_r += 8;
	}
	Basic_Quit();
	__FINI;
}
