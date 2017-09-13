/* Ofront+ 0.9 -sm */
#include "SYSTEM.h"
#include "Basic.h"
#include "GRAPH0.h"
#include "Console.h"


static SHORTINT MiraTest_c;
static INTEGER MiraTest_i;




/*============================================================================*/


int main(int argc, char **argv)
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
	while (MiraTest_i <= 512) {
		Basic_INK((SHORTINT)Basic_RND(0, 6));
		Basic_PLOT(Basic_RND(0, 255), Basic_RND(0, 175));
		MiraTest_i += 1;
	}
	MiraTest_c = 1;
	while (MiraTest_c <= 23) {
		GRAPH0_SETATTRS(16 - __DIV(MiraTest_c, 3), MiraTest_c - 3, __ASHL(__DIV(MiraTest_c, 3), 1, SHORTINT), 36);
		MiraTest_c += 1;
	}
	MiraTest_c = 21;
	while (MiraTest_c <= 23) {
		GRAPH0_SETATTRS(15, MiraTest_c, 2, 18);
		MiraTest_c += 1;
	}
	Basic_PAUSE(0);
	__FINI;
}
