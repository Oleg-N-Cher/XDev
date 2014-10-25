/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Asm.h"
#include "Basic.h"
#include "PT3x0A.h"


static INTEGER TestPT3_ace;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Asm__init);
	__IMPORT(Basic__init);
	__IMPORT(PT3x0A__init);
	__REGMAIN("TestPT3", 0);
/* BEGIN */
	Basic_Init();
	if (__MASK(PT3x0A_TabAdr(), -256) != 0) {
		Basic_PRSTR((CHAR*)"Start address of module must be aligned to ", (LONGINT)44);
		Basic_PRINT(__MASK(PT3x0A_TabAdr(), -256));
		Basic_PRSTR((CHAR*)" bytes", (LONGINT)7);
		Basic_PAUSE(0);
	}
	Basic_DEFDATA(TestPT3_ace, 2137);
	Basic_DATA12(80, 114, 111, 84, 114, 97, 99, 107, 101, 114, 32, 51);
	Basic_DATA12(46, 54, 32, 99, 111, 109, 112, 105, 108, 97, 116, 105);
	Basic_DATA12(111, 110, 32, 111, 102, 32, 97, 99, 101, 32, 32, 32);
	Basic_DATA12(32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32);
	Basic_DATA12(32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32);
	Basic_DATA12(32, 32, 32, 98, 121, 32, 83, 99, 108, 32, 40, 102);
	Basic_DATA12(111, 114, 32, 51, 98, 105, 116, 33, 41, 32, 32, 32);
	Basic_DATA12(32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32);
	Basic_DATA12(32, 32, 32, 2, 6, 27, 26, 229, 0, 0, 0, 0);
	Basic_DATA12(0, 0, 0, 0, 0, 54, 8, 0, 0, 0, 0, 0);
	Basic_DATA12(0, 76, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA12(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA12(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA12(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA12(0, 82, 8, 0, 0, 0, 0, 85, 8, 0, 0, 0);
	Basic_DATA12(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA12(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 6);
	Basic_DATA12(3, 3, 33, 33, 12, 15, 18, 18, 21, 24, 27, 3);
	Basic_DATA12(3, 33, 33, 12, 15, 18, 18, 21, 24, 27, 30, 36);
	Basic_DATA12(255, 51, 1, 166, 1, 9, 2, 172, 2, 166, 1, 30);
	Basic_DATA12(3, 13, 2, 166, 1, 127, 2, 13, 2, 166, 1, 9);
	Basic_DATA12(2, 172, 2, 166, 1, 51, 4, 172, 2, 201, 4, 51);
	Basic_DATA12(4, 44, 5, 75, 5, 51, 4, 2, 6, 75, 5, 51);
	Basic_DATA12(4, 175, 6, 156, 7, 51, 4, 175, 6, 191, 7, 51);
	Basic_DATA12(4, 231, 7, 251, 7, 30, 8, 172, 2, 166, 1, 163);
	Basic_DATA12(3, 50, 8, 50, 8, 50, 8, 243, 8, 206, 9, 177);
	Basic_DATA12(2, 133, 6, 9, 135, 4, 9, 136, 6, 9, 138, 4);
	Basic_DATA12(9, 140, 6, 201, 9, 138, 4, 9, 140, 6, 200, 9);
	Basic_DATA12(138, 4, 9, 140, 6, 199, 9, 138, 4, 9, 140, 6);
	Basic_DATA12(198, 9, 138, 4, 9, 140, 6, 197, 9, 138, 4, 9);
	Basic_DATA12(140, 6, 196, 9, 138, 4, 207, 9, 133, 6, 9, 135);
	Basic_DATA12(4, 9, 136, 6, 9, 138, 4, 9, 140, 6, 201, 9);
	Basic_DATA12(138, 4, 9, 140, 6, 200, 9, 138, 4, 9, 140, 6);
	Basic_DATA12(199, 9, 138, 4, 9, 140, 6, 198, 9, 138, 4, 9);
	Basic_DATA12(140, 6, 197, 9, 138, 4, 9, 140, 6, 196, 9, 138);
	Basic_DATA12(4, 0, 240, 16, 207, 177, 5, 121, 202, 177, 1, 208);
	Basic_DATA12(207, 177, 5, 121, 202, 177, 1, 208, 207, 177, 3, 121);
	Basic_DATA12(202, 177, 1, 208, 207, 177, 5, 119, 202, 177, 1, 208);
	Basic_DATA12(207, 177, 5, 119, 202, 177, 1, 208, 207, 177, 3, 119);
	Basic_DATA12(202, 177, 1, 208, 207, 177, 5, 114, 202, 177, 1, 208);
	Basic_DATA12(207, 177, 5, 114, 202, 177, 1, 208, 207, 177, 3, 114);
	Basic_DATA12(202, 177, 1, 208, 207, 177, 5, 116, 202, 177, 1, 208);
	Basic_DATA12(207, 177, 5, 116, 202, 177, 1, 208, 207, 177, 3, 116);
	Basic_DATA12(202, 177, 1, 208, 0, 177, 64, 208, 0, 243, 8, 206);
	Basic_DATA12(9, 177, 2, 133, 6, 9, 135, 4, 9, 136, 6, 9);
	Basic_DATA12(138, 4, 9, 140, 6, 201, 9, 138, 4, 9, 140, 6);
	Basic_DATA12(200, 9, 138, 4, 207, 9, 133, 6, 9, 135, 4, 9);
	Basic_DATA12(136, 6, 9, 138, 4, 9, 140, 6, 201, 9, 138, 4);
	Basic_DATA12(9, 140, 6, 200, 9, 138, 4, 207, 9, 133, 6, 9);
	Basic_DATA12(135, 4, 9, 136, 6, 9, 138, 4, 9, 140, 6, 201);
	Basic_DATA12(9, 138, 4, 9, 140, 6, 200, 9, 138, 4, 207, 9);
	Basic_DATA12(140, 6, 9, 138, 4, 9, 135, 6, 9, 131, 4, 9);
	Basic_DATA12(136, 6, 201, 9, 136, 4, 207, 9, 143, 6, 201, 9);
	Basic_DATA12(143, 4, 0, 177, 56, 208, 240, 16, 205, 177, 1, 109);
	Basic_DATA12(1, 208, 1, 6, 0, 1, 208, 1, 6, 0, 1, 208);
	Basic_DATA12(1, 7, 0, 1, 208, 1, 7, 0, 1, 208, 1, 7);
	Basic_DATA12(0, 1, 208, 1, 6, 0, 1, 208, 1, 8, 0, 0);
	Basic_DATA12(243, 8, 206, 9, 177, 2, 140, 6, 9, 138, 4, 9);
	Basic_DATA12(136, 6, 9, 135, 4, 9, 133, 6, 201, 9, 135, 4);
	Basic_DATA12(9, 133, 6, 200, 9, 135, 4, 207, 9, 133, 6, 9);
	Basic_DATA12(135, 4, 9, 136, 6, 9, 138, 4, 9, 140, 6, 201);
	Basic_DATA12(9, 138, 4, 9, 140, 6, 200, 9, 138, 4, 207, 9);
	Basic_DATA12(140, 6, 9, 138, 4, 9, 136, 6, 9, 135, 4, 9);
	Basic_DATA12(133, 6, 201, 9, 135, 4, 9, 133, 6, 200, 9, 135);
	Basic_DATA12(4, 207, 9, 140, 6, 9, 138, 4, 9, 135, 6, 9);
	Basic_DATA12(131, 4, 9, 136, 6, 201, 9, 136, 4, 207, 9, 143);
	Basic_DATA12(6, 201, 9, 143, 4, 0, 240, 8, 207, 177, 1, 97);
	Basic_DATA12(202, 208, 207, 97, 202, 208, 207, 109, 202, 208, 207, 177);
	Basic_DATA12(3, 109, 202, 177, 1, 208, 207, 97, 202, 208, 207, 109);
	Basic_DATA12(202, 208, 207, 109, 202, 208, 207, 95, 202, 208, 207, 95);
	Basic_DATA12(202, 208, 207, 107, 202, 208, 207, 177, 3, 107, 202, 177);
	Basic_DATA12(1, 208, 207, 95, 202, 208, 207, 107, 202, 208, 207, 107);
	Basic_DATA12(202, 208, 207, 90, 202, 208, 207, 90, 202, 208, 207, 102);
	Basic_DATA12(202, 208, 207, 177, 3, 102, 202, 177, 1, 208, 207, 90);
	Basic_DATA12(202, 208, 207, 102, 202, 208, 207, 102, 202, 208, 207, 92);
	Basic_DATA12(202, 208, 207, 92, 202, 208, 207, 104, 202, 208, 207, 177);
	Basic_DATA12(3, 104, 202, 177, 1, 208, 207, 92, 202, 208, 207, 104);
	Basic_DATA12(202, 208, 207, 104, 202, 208, 0, 240, 8, 207, 177, 1);
	Basic_DATA12(97, 202, 208, 67, 207, 145, 202, 208, 64, 207, 109, 202);
	Basic_DATA12(208, 207, 177, 2, 109, 67, 145, 64, 177, 1, 97, 202);
	Basic_DATA12(208, 207, 109, 202, 208, 207, 109, 202, 208, 207, 95, 202);
	Basic_DATA12(208, 67, 207, 177, 2, 145, 64, 177, 1, 107, 202, 208);
	Basic_DATA12(207, 177, 2, 107, 67, 145, 64, 177, 1, 95, 202, 208);
	Basic_DATA12(207, 107, 202, 208, 207, 107, 202, 208, 207, 90, 202, 208);
	Basic_DATA12(67, 207, 177, 2, 145, 64, 177, 1, 102, 202, 208, 207);
	Basic_DATA12(177, 2, 102, 67, 145, 64, 177, 1, 90, 202, 208, 207);
	Basic_DATA12(102, 202, 208, 207, 102, 202, 208, 207, 92, 202, 208, 67);
	Basic_DATA12(207, 177, 2, 143, 64, 177, 1, 104, 202, 208, 207, 177);
	Basic_DATA12(2, 104, 67, 143, 64, 177, 1, 92, 202, 208, 207, 104);
	Basic_DATA12(202, 208, 207, 104, 202, 208, 0, 240, 8, 207, 177, 1);
	Basic_DATA12(97, 202, 208, 67, 207, 145, 202, 208, 64, 207, 109, 202);
	Basic_DATA12(208, 207, 177, 2, 109, 67, 145, 64, 177, 1, 97, 202);
	Basic_DATA12(208, 67, 207, 177, 2, 148, 64, 177, 1, 109, 202, 208);
	Basic_DATA12(207, 95, 202, 208, 67, 207, 145, 202, 208, 64, 207, 107);
	Basic_DATA12(202, 208, 207, 177, 2, 107, 67, 145, 64, 177, 1, 95);
	Basic_DATA12(202, 208, 207, 107, 202, 208, 207, 107, 202, 208, 207, 90);
	Basic_DATA12(202, 208, 67, 207, 177, 2, 145, 64, 177, 1, 102, 202);
	Basic_DATA12(208, 207, 177, 2, 102, 67, 145, 64, 177, 1, 90, 202);
	Basic_DATA12(208, 67, 207, 177, 2, 148, 64, 177, 1, 102, 202, 208);
	Basic_DATA12(207, 92, 202, 208, 67, 207, 177, 2, 143, 64, 177, 1);
	Basic_DATA12(104, 202, 208, 207, 177, 2, 104, 67, 143, 64, 177, 1);
	Basic_DATA12(92, 202, 208, 207, 177, 2, 152, 177, 1, 104, 202, 208);
	Basic_DATA12(0, 240, 16, 207, 177, 5, 121, 202, 177, 1, 208, 207);
	Basic_DATA12(177, 5, 121, 202, 177, 1, 208, 207, 177, 3, 121, 202);
	Basic_DATA12(177, 1, 208, 207, 177, 5, 124, 202, 177, 1, 208, 207);
	Basic_DATA12(177, 5, 124, 202, 177, 1, 208, 207, 177, 3, 124, 202);
	Basic_DATA12(177, 1, 208, 207, 177, 5, 126, 202, 177, 1, 208, 207);
	Basic_DATA12(177, 5, 126, 202, 177, 1, 208, 207, 177, 3, 126, 202);
	Basic_DATA12(177, 1, 208, 207, 177, 5, 128, 202, 177, 1, 208, 207);
	Basic_DATA12(177, 5, 128, 202, 177, 1, 208, 207, 177, 3, 128, 202);
	Basic_DATA12(177, 1, 208, 0, 243, 8, 207, 177, 4, 145, 150, 152);
	Basic_DATA12(202, 152, 207, 152, 150, 145, 202, 145, 207, 145, 148, 152);
	Basic_DATA12(202, 152, 207, 155, 152, 148, 177, 2, 147, 148, 0, 240);
	Basic_DATA12(16, 207, 9, 177, 2, 121, 6, 9, 208, 4, 9, 177);
	Basic_DATA12(1, 208, 6, 202, 208, 207, 9, 177, 2, 121, 4, 9);
	Basic_DATA12(208, 6, 9, 177, 1, 208, 4, 202, 208, 207, 9, 177);
	Basic_DATA12(2, 121, 6, 9, 177, 1, 208, 4, 202, 208, 207, 9);
	Basic_DATA12(177, 2, 124, 6, 9, 208, 4, 9, 177, 1, 208, 6);
	Basic_DATA12(202, 208, 207, 9, 177, 2, 124, 4, 9, 208, 6, 9);
	Basic_DATA12(177, 1, 208, 4, 202, 208, 207, 9, 177, 2, 124, 6);
	Basic_DATA12(9, 177, 1, 208, 4, 202, 208, 207, 9, 177, 2, 126);
	Basic_DATA12(6, 9, 208, 4, 9, 177, 1, 208, 6, 202, 208, 207);
	Basic_DATA12(9, 177, 2, 126, 4, 9, 208, 6, 9, 177, 1, 208);
	Basic_DATA12(4, 202, 208, 207, 9, 177, 2, 126, 6, 9, 177, 1);
	Basic_DATA12(208, 4, 202, 208, 207, 9, 177, 2, 128, 6, 9, 208);
	Basic_DATA12(4, 9, 177, 1, 208, 6, 202, 208, 207, 9, 177, 2);
	Basic_DATA12(128, 4, 9, 208, 6, 9, 177, 1, 208, 4, 202, 208);
	Basic_DATA12(207, 9, 177, 2, 128, 6, 9, 177, 1, 208, 4, 202);
	Basic_DATA12(208, 0, 243, 8, 207, 177, 2, 145, 64, 177, 1, 109);
	Basic_DATA12(202, 208, 67, 207, 177, 2, 150, 64, 177, 1, 109, 202);
	Basic_DATA12(208, 67, 207, 177, 2, 152, 64, 177, 1, 121, 202, 208);
	Basic_DATA12(67, 177, 2, 152, 64, 207, 177, 1, 116, 202, 208, 67);
	Basic_DATA12(207, 177, 2, 152, 64, 177, 1, 109, 202, 208, 67, 207);
	Basic_DATA12(177, 2, 150, 64, 177, 1, 109, 202, 208, 67, 207, 177);
	Basic_DATA12(2, 145, 64, 177, 1, 121, 202, 208, 67, 177, 2, 145);
	Basic_DATA12(64, 207, 177, 1, 116, 202, 208, 67, 207, 177, 2, 145);
	Basic_DATA12(64, 177, 1, 109, 202, 208, 67, 207, 177, 2, 148, 64);
	Basic_DATA12(177, 1, 109, 202, 208, 67, 207, 177, 2, 152, 64, 177);
	Basic_DATA12(1, 121, 202, 208, 67, 177, 2, 152, 64, 207, 177, 1);
	Basic_DATA12(116, 202, 208, 67, 207, 177, 2, 155, 64, 177, 1, 109);
	Basic_DATA12(202, 208, 67, 207, 177, 2, 152, 64, 177, 1, 109, 202);
	Basic_DATA12(208, 67, 207, 177, 2, 148, 64, 177, 1, 121, 202, 208);
	Basic_DATA12(67, 207, 177, 2, 147, 148, 0, 243, 8, 207, 9, 177);
	Basic_DATA12(2, 145, 6, 64, 9, 177, 1, 109, 4, 202, 208, 67);
	Basic_DATA12(207, 9, 177, 2, 150, 6, 64, 9, 177, 1, 109, 4);
	Basic_DATA12(202, 208, 67, 207, 9, 177, 2, 152, 6, 64, 9, 177);
	Basic_DATA12(1, 121, 4, 202, 208, 67, 9, 177, 2, 152, 6, 64);
	Basic_DATA12(207, 9, 177, 1, 116, 4, 202, 208, 67, 207, 9, 177);
	Basic_DATA12(2, 152, 6, 64, 9, 177, 1, 109, 4, 202, 208, 67);
	Basic_DATA12(207, 9, 177, 2, 150, 6, 64, 9, 177, 1, 109, 4);
	Basic_DATA12(202, 208, 67, 207, 9, 177, 2, 145, 6, 64, 9, 177);
	Basic_DATA12(1, 121, 4, 202, 208, 67, 9, 177, 2, 145, 6, 64);
	Basic_DATA12(207, 9, 177, 1, 116, 4, 202, 208, 67, 207, 9, 177);
	Basic_DATA12(2, 145, 6, 64, 9, 177, 1, 109, 4, 202, 208, 67);
	Basic_DATA12(207, 9, 177, 2, 148, 6, 64, 9, 177, 1, 109, 4);
	Basic_DATA12(202, 208, 67, 207, 9, 177, 2, 152, 6, 64, 9, 177);
	Basic_DATA12(1, 121, 4, 202, 208, 67, 9, 177, 2, 152, 6, 64);
	Basic_DATA12(207, 9, 177, 1, 116, 4, 202, 208, 67, 207, 9, 177);
	Basic_DATA12(2, 155, 6, 64, 9, 177, 1, 109, 4, 202, 208, 67);
	Basic_DATA12(207, 9, 177, 2, 152, 6, 64, 9, 177, 1, 109, 4);
	Basic_DATA12(202, 208, 67, 207, 9, 177, 2, 148, 6, 64, 9, 177);
	Basic_DATA12(1, 121, 4, 202, 208, 67, 207, 9, 177, 2, 147, 6);
	Basic_DATA12(9, 148, 4, 0, 240, 8, 207, 177, 4, 109, 121, 177);
	Basic_DATA12(8, 119, 177, 4, 109, 121, 177, 8, 119, 177, 4, 109);
	Basic_DATA12(121, 177, 8, 119, 177, 4, 109, 121, 177, 6, 119, 177);
	Basic_DATA12(2, 116, 0, 240, 8, 207, 177, 4, 109, 121, 177, 8);
	Basic_DATA12(119, 177, 4, 109, 121, 177, 8, 119, 177, 4, 109, 121);
	Basic_DATA12(177, 8, 119, 67, 206, 177, 2, 140, 138, 135, 131, 136);
	Basic_DATA12(202, 136, 207, 143, 202, 143, 0, 243, 8, 207, 177, 2);
	Basic_DATA12(140, 201, 140, 199, 140, 197, 140, 195, 140, 194, 140, 193);
	Basic_DATA12(140, 192, 0, 240, 16, 203, 9, 177, 2, 121, 6, 201);
	Basic_DATA12(9, 121, 4, 199, 9, 121, 6, 197, 9, 121, 4, 195);
	Basic_DATA12(9, 121, 6, 193, 9, 121, 4, 9, 192, 6, 9, 208);
	Basic_DATA12(4, 0, 240, 8, 207, 177, 2, 97, 201, 97, 199, 97);
	Basic_DATA12(197, 97, 195, 97, 194, 97, 193, 97, 192, 0, 177, 4);
	Basic_DATA12(208, 0, 3, 5, 1, 143, 0, 0, 1, 143, 0, 0);
	Basic_DATA12(1, 143, 0, 0, 1, 141, 0, 0, 129, 141, 0, 0);
	Basic_DATA12(0, 1, 0, 141, 0, 0, 0, 1, 0, 1, 2, 12);
	Basic_DATA1(0);
	PT3x0A_Install(TestPT3_ace);
	Asm_Code((CHAR*)"play_l$: LD   IY,#0x5C3A", (LONGINT)25);
	Asm_Code((CHAR*)"         EI             ", (LONGINT)25);
	Asm_Code((CHAR*)"         HALT           ", (LONGINT)25);
	PT3x0A_Play();
	Asm_Code((CHAR*)"         LD   A,#0x7F   ", (LONGINT)25);
	Asm_Code((CHAR*)"         IN   A,(-2)    ", (LONGINT)25);
	Asm_Code((CHAR*)"         RRA            ", (LONGINT)25);
	Asm_Code((CHAR*)"         JR   C,play_l$ ", (LONGINT)25);
	PT3x0A_Stop();
	Basic_Quit();
	__FINI;
}
