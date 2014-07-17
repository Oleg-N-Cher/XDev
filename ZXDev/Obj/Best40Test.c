/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Best40.h"


static SHORTINT Best40Test_i;
static INTEGER Best40Test_udg;
static SHORTINT Best40Test__for__9, Best40Test__for__8, Best40Test__for__7, Best40Test__for__6, Best40Test__for__5, Best40Test__for__4, Best40Test__for__3, Best40Test__for__2, Best40Test__for__1;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Best40__init);
	__REGMAIN("Best40Test", 0);
/* BEGIN */
	Basic_Init();
	Best40Test_i = 16;
	do {
		Best40_ASRL_LF(32);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 16;
	do {
		Best40_ASRL_UP(49);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 6;
	do {
		Best40_ASRL_RG(41);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 5;
	do {
		Best40_ASRL_DN(23);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 49;
	Best40Test__for__9 = 113;
	Best40Test__for__9 = (Best40Test__for__9 - Best40Test_i) + 1;
	do {
		Best40_AREPLC(Best40Test_i, Best40Test_i + 1);
		Basic_PAUSE(5);
		Best40Test_i += 1;
		Best40Test__for__9 -= 1;
	} while (!(Best40Test__for__9 == 0));
	Best40_ACHANGE(247, 1);
	Best40Test_i = 127;
	Best40Test__for__8 = 1;
	Best40Test__for__8 = __ASHR(Best40Test_i - Best40Test__for__8, 1) + 1;
	do {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1), Best40Test_i, (CHAR*)"065088060", (LONGINT)10);
		Best40Test_i += -2;
		Best40Test__for__8 -= 1;
	} while (!(Best40Test__for__8 == 0));
	Best40Test_i = 127;
	Best40Test__for__7 = 1;
	Best40Test__for__7 = __ASHR(Best40Test_i - Best40Test__for__7, 1) + 1;
	do {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1), Best40Test_i + 10, (CHAR*)"065088060", (LONGINT)10);
		Best40Test_i += -2;
		Best40Test__for__7 -= 1;
	} while (!(Best40Test__for__7 == 0));
	Best40Test_i = 16;
	do {
		Best40_SSRL_LF();
		Best40_SSRL_UP();
		Best40_SSRL_RG();
		Best40_SSRL_DN();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 99;
	Best40Test__for__6 = 1;
	Best40Test__for__6 = __ASHR(Best40Test_i - Best40Test__for__6, 1) + 1;
	do {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1), Best40Test_i + 26, (CHAR*)"06050808060", (LONGINT)12);
		Best40Test_i += -2;
		Best40Test__for__6 -= 1;
	} while (!(Best40Test__for__6 == 0));
	Best40_ASRL_RG(39);
	Best40_ASRL_DN(41);
	Best40Test_i = 10;
	do {
		Best40_SCR_INV();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40_PAINT(0, 0);
	Best40Test_i = 64;
	do {
		Best40_PSRL_LF();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 32;
	do {
		Best40_PSRL_RG();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 16;
	do {
		Best40_PSRL_DN();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40Test_i = 16;
	do {
		Best40_PSRL_UP();
		Best40Test_i += -1;
	} while (!(Best40Test_i == 0));
	Best40_SCR_INV();
	Best40_SCR_INV();
	Best40_SCR_MRG(0);
	Basic_DEFDATA(Best40Test_udg, 64);
	Basic_DATA8(30, 54, 102, 102, 126, 102, 102, 0);
	Basic_DATA8(124, 96, 96, 124, 102, 102, 124, 0);
	Basic_DATA8(124, 102, 102, 124, 102, 102, 124, 0);
	Basic_DATA8(126, 96, 96, 96, 96, 96, 96, 0);
	Basic_DATA8(56, 108, 108, 108, 108, 108, 254, 198);
	Basic_DATA8(126, 96, 96, 124, 96, 96, 126, 0);
	Basic_DATA8(219, 219, 126, 60, 126, 219, 219, 0);
	Basic_DATA8(60, 102, 6, 28, 6, 102, 60, 0);
	Basic_UDG(Best40Test_udg);
	Basic_PRUDG('A');
	Basic_PRUDG('B');
	Basic_PRUDG('C');
	Basic_PRUDG('D');
	Basic_PRUDG('E');
	Basic_PRUDG('F');
	Basic_PRUDG('G');
	Basic_PRUDG('H');
	Basic_PRLN();
	Best40Test_i = 0;
	Best40Test__for__5 = 56;
	Best40Test__for__5 = __ASHR(Best40Test__for__5 - Best40Test_i, 3) + 1;
	do {
		Best40_SINV_LR(Best40Test_udg + (int)Best40Test_i);
		Best40Test_i += 8;
		Best40Test__for__5 -= 1;
	} while (!(Best40Test__for__5 == 0));
	Basic_PRUDG('A');
	Basic_PRUDG('B');
	Basic_PRUDG('C');
	Basic_PRUDG('D');
	Basic_PRUDG('E');
	Basic_PRUDG('F');
	Basic_PRUDG('G');
	Basic_PRUDG('H');
	Basic_PRLN();
	Best40Test_i = 0;
	Best40Test__for__4 = 56;
	Best40Test__for__4 = __ASHR(Best40Test__for__4 - Best40Test_i, 3) + 1;
	do {
		Best40_SINV_UD(Best40Test_udg + (int)Best40Test_i);
		Best40Test_i += 8;
		Best40Test__for__4 -= 1;
	} while (!(Best40Test__for__4 == 0));
	Basic_PRUDG('A');
	Basic_PRUDG('B');
	Basic_PRUDG('C');
	Basic_PRUDG('D');
	Basic_PRUDG('E');
	Basic_PRUDG('F');
	Basic_PRUDG('G');
	Basic_PRUDG('H');
	Basic_PRLN();
	Best40Test_i = 0;
	Best40Test__for__3 = 56;
	Best40Test__for__3 = __ASHR(Best40Test__for__3 - Best40Test_i, 3) + 1;
	do {
		Best40_SINV_LR(Best40Test_udg + (int)Best40Test_i);
		Best40Test_i += 8;
		Best40Test__for__3 -= 1;
	} while (!(Best40Test__for__3 == 0));
	Basic_PRUDG('A');
	Basic_PRUDG('B');
	Basic_PRUDG('C');
	Basic_PRUDG('D');
	Basic_PRUDG('E');
	Basic_PRUDG('F');
	Basic_PRUDG('G');
	Basic_PRUDG('H');
	Basic_PRLN();
	Best40Test_i = 0;
	Best40Test__for__2 = 56;
	Best40Test__for__2 = __ASHR(Best40Test__for__2 - Best40Test_i, 3) + 1;
	do {
		Best40_SINV_UD(Best40Test_udg + (int)Best40Test_i);
		Best40_SROTATE(Best40Test_udg + (int)Best40Test_i);
		Best40Test_i += 8;
		Best40Test__for__2 -= 1;
	} while (!(Best40Test__for__2 == 0));
	Basic_PRUDG('A');
	Basic_PRUDG('B');
	Basic_PRUDG('C');
	Basic_PRUDG('D');
	Basic_PRUDG('E');
	Basic_PRUDG('F');
	Basic_PRUDG('G');
	Basic_PRUDG('H');
	Basic_PRLN();
	Best40Test_i = 0;
	Best40Test__for__1 = 56;
	Best40Test__for__1 = __ASHR(Best40Test__for__1 - Best40Test_i, 3) + 1;
	do {
		Best40_SROTATE(Best40Test_udg + (int)Best40Test_i);
		Best40_SROTATE(Best40Test_udg + (int)Best40Test_i);
		Best40Test_i += 8;
		Best40Test__for__1 -= 1;
	} while (!(Best40Test__for__1 == 0));
	Basic_PRUDG('A');
	Basic_PRUDG('B');
	Basic_PRUDG('C');
	Basic_PRUDG('D');
	Basic_PRUDG('E');
	Basic_PRUDG('F');
	Basic_PRUDG('G');
	Basic_PRUDG('H');
	Basic_PRLN();
	Best40_PSCALER(0, 0, 63, 47, 3, 3, 32, 48);
	Basic_BORDER(6);
	Basic_PAUSE(0);
	Basic_Quit();
	__FINI;
}
