/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Best40.h"


static SHORTINT Best40Test_i;
static INTEGER Best40Test_udg;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Best40__init);
	__REGMAIN("Best40Test", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Best40Test_i = 16;
	while (Best40Test_i >= 1) {
		Best40_ASRL_LF(32);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	}
	Best40Test_i = 16;
	while (Best40Test_i >= 1) {
		Best40_ASRL_UP(49);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	}
	Best40Test_i = 6;
	while (Best40Test_i >= 1) {
		Best40_ASRL_RG(41);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	}
	Best40Test_i = 5;
	while (Best40Test_i >= 1) {
		Best40_ASRL_DN(23);
		Basic_PAUSE(5);
		Best40Test_i += -1;
	}
	Best40Test_i = 49;
	while (Best40Test_i <= 113) {
		Best40_AREPLC(Best40Test_i, Best40Test_i + 1);
		Basic_PAUSE(5);
		Best40Test_i += 1;
	}
	Best40_ACHANGE(247, 1);
	Best40Test_i = 127;
	while (Best40Test_i >= 1) {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1, SHORTINT), Best40Test_i, (CHAR*)"065088060", 10);
		Best40Test_i += -2;
	}
	Best40Test_i = 127;
	while (Best40Test_i >= 1) {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1, SHORTINT), Best40Test_i + 10, (CHAR*)"065088060", 10);
		Best40Test_i += -2;
	}
	Best40Test_i = 16;
	while (Best40Test_i >= 1) {
		Best40_SSRL_LF();
		Best40_SSRL_UP();
		Best40_SSRL_RG();
		Best40_SSRL_DN();
		Best40Test_i += -1;
	}
	Best40Test_i = 99;
	while (Best40Test_i >= 1) {
		Best40_PFIGURE(__ASHL(Best40Test_i, 1, SHORTINT), Best40Test_i + 26, (CHAR*)"06050808060", 12);
		Best40Test_i += -2;
	}
	Best40_ASRL_RG(39);
	Best40_ASRL_DN(41);
	Best40Test_i = 10;
	while (Best40Test_i >= 1) {
		Best40_SCR_INV();
		Best40Test_i += -1;
	}
	Best40_PAINT(0, 0);
	Best40Test_i = 64;
	while (Best40Test_i >= 1) {
		Best40_PSRL_LF();
		Best40Test_i += -1;
	}
	Best40Test_i = 32;
	while (Best40Test_i >= 1) {
		Best40_PSRL_RG();
		Best40Test_i += -1;
	}
	Best40Test_i = 16;
	while (Best40Test_i >= 1) {
		Best40_PSRL_DN();
		Best40Test_i += -1;
	}
	Best40Test_i = 16;
	while (Best40Test_i >= 1) {
		Best40_PSRL_UP();
		Best40Test_i += -1;
	}
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
	while (Best40Test_i <= 56) {
		Best40_SINV_LR(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40Test_i += 8;
	}
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
	while (Best40Test_i <= 56) {
		Best40_SINV_UD(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40Test_i += 8;
	}
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
	while (Best40Test_i <= 56) {
		Best40_SINV_LR(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40Test_i += 8;
	}
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
	while (Best40Test_i <= 56) {
		Best40_SINV_UD(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40_SROTATE(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40Test_i += 8;
	}
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
	while (Best40Test_i <= 56) {
		Best40_SROTATE(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40_SROTATE(Best40Test_udg + (INTEGER)Best40Test_i);
		Best40Test_i += 8;
	}
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
	Best40_SCREEN_APART(16);
	Basic_Quit();
	__FINI;
}
