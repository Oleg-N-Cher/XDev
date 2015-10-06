/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"


static SHORTINT TestCircle_r;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("TestCircle", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	TestCircle_r = 1;
	while (TestCircle_r <= 87) {
		Basic_OVER(1);
		Basic_CIRCLE(128, 88, TestCircle_r);
		TestCircle_r += 3;
	}
	Basic_Quit();
	__FINI;
}
