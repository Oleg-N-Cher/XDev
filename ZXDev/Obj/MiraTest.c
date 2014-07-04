/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GRAPH0.h"
#include "Console.h"


static SHORTINT MiraTest_c;
static INTEGER MiraTest_i, MiraTest__for__3;
static SHORTINT MiraTest__for__2, MiraTest__for__1;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(GRAPH0__init);
	__IMPORT(Console__init);
	__REGMAIN("MiraTest", 0);
/* BEGIN */
	GRAPH0_CLS2();
	GRAPH0_GCLS();
	MiraTest_i = 0;
	MiraTest__for__3 = 512;
	MiraTest__for__3 = (MiraTest__for__3 - MiraTest_i) + 1;
	do {
		Basic_INK(Basic_RND(0, 6));
		Basic_PLOT(Basic_RND(0, 255), Basic_RND(0, 175));
		MiraTest_i += 1;
		MiraTest__for__3 -= 1;
	} while (!(MiraTest__for__3 == 0));
	MiraTest_c = 1;
	MiraTest__for__2 = 23;
	MiraTest__for__2 = (MiraTest__for__2 - MiraTest_c) + 1;
	do {
		GRAPH0_SETATTRS(16 - __DIV(MiraTest_c, 3), MiraTest_c - 3, __ASHL(__DIV(MiraTest_c, 3), 1), 36);
		MiraTest_c += 1;
		MiraTest__for__2 -= 1;
	} while (!(MiraTest__for__2 == 0));
	MiraTest_c = 21;
	MiraTest__for__1 = 23;
	MiraTest__for__1 = (MiraTest__for__1 - MiraTest_c) + 1;
	do {
		GRAPH0_SETATTRS(15, MiraTest_c, 2, 18);
		MiraTest_c += 1;
		MiraTest__for__1 -= 1;
	} while (!(MiraTest__for__1 == 0));
	Basic_PAUSE(0);
	__FINI;
}
