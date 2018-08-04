/* Ofront+ 1.0 -m3 -21 */
#include "SYSTEM.h"
#include "Basic.h"
#include "GRAPH0.h"
#include "Console.h"


static BYTE MiraTest_c;
static SHORTINT MiraTest_i, MiraTest__for__3;
static BYTE MiraTest__for__2, MiraTest__for__1;




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
	MiraTest__for__3 = 513;
	do {
		Basic_INK((BYTE)Basic_RND(0, 6));
		Basic_PLOT(Basic_RND(0, 255), Basic_RND(0, 175));
		MiraTest_i += 1;
	} while (--MiraTest__for__3);
	MiraTest_c = 1;
	MiraTest__for__2 = 23;
	do {
		GRAPH0_SETATTRS(16 - __DIV(MiraTest_c, 3), MiraTest_c - 3, __ASHL(__DIV(MiraTest_c, 3), 1, BYTE), 36);
		MiraTest_c += 1;
	} while (--MiraTest__for__2);
	MiraTest_c = 21;
	MiraTest__for__1 = 3;
	do {
		GRAPH0_SETATTRS(15, MiraTest_c, 2, 18);
		MiraTest_c += 1;
	} while (--MiraTest__for__1);
	Basic_PAUSE(0);
	__FINI;
}
