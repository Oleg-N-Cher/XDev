/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GRAPHIC.h"


static SHORTINT TestGr_n;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(GRAPHIC__init);
	__REGMAIN("TestGr", 0);
/* BEGIN */
	GRAPHIC_Screen(7);
	GRAPHIC_Color(15, 1, 1);
	TestGr_n = 32;
	while (TestGr_n <= 126) {
		Basic_ATR(__MASK(TestGr_n, -16));
		Basic_LINE(TestGr_n, 5, TestGr_n, 150);
		TestGr_n += 1;
	}
	Basic_ATR(15);
	GRAPHIC_Pset(1, 2, 0, 5, 0);
	__FINI;
}
