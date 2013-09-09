/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Best40.h"


static SHORTINT Best40Test_i, Best40Test__for__3, Best40Test__for__2, Best40Test__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Best40__init);
	__REGMAIN("Best40Test", 0);
/* BEGIN */
	Best40_attrib = 32;
	Best40Test_i = 16;
	do {
		Best40_ASRL_LF();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40_attrib = 49;
	Best40Test_i = 16;
	do {
		Best40_ASRL_UP();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40_attrib = 41;
	Best40Test_i = 6;
	do {
		Best40_ASRL_RG();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40_attrib = 23;
	Best40_ASRL_DN();
	Best40_ASRL_DN();
	Best40Test_i = 127;
	Best40Test__for__3 = 1;
	Best40Test__for__3 = __ASHR(Best40Test_i - Best40Test__for__3, 1) + 1;
	do {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1), Best40Test_i, (CHAR*)"065088060", (LONGINT)10);
		Best40Test_i += -2;
		Best40Test__for__3 -= 1;
	} while (!(Best40Test__for__3 == 0));
	Best40Test_i = 127;
	Best40Test__for__2 = 1;
	Best40Test__for__2 = __ASHR(Best40Test_i - Best40Test__for__2, 1) + 1;
	do {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1), Best40Test_i + 10, (CHAR*)"065088060", (LONGINT)10);
		Best40Test_i += -2;
		Best40Test__for__2 -= 1;
	} while (!(Best40Test__for__2 == 0));
	Best40Test_i = 16;
	do {
		Best40_SSRL_LF();
		Best40_SSRL_UP();
		Best40_SSRL_RG();
		Best40_SSRL_DN();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 99;
	Best40Test__for__1 = 1;
	Best40Test__for__1 = __ASHR(Best40Test_i - Best40Test__for__1, 1) + 1;
	do {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1), Best40Test_i + 26, (CHAR*)"06050808060", (LONGINT)12);
		Best40Test_i += -2;
		Best40Test__for__1 -= 1;
	} while (!(Best40Test__for__1 == 0));
	Best40_attrib = 39;
	Best40_ASRL_RG();
	Best40_attrib = 41;
	Best40_ASRL_DN();
	Best40Test_i = 10;
	do {
		Best40_SCR_INV();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40_PAINT(0, 0);
	__FINI;
}
