/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GrFonts.h"
#include "NewSupercode.h"






/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(GrFonts__init);
	__IMPORT(NewSupercode__init);
	__REGMAIN("DemoRus", 0);
/* BEGIN */
	Basic_BORDER(5);
	Basic_PAPER(0);
	Basic_CLS();
	Basic_INK(2);
	Basic_FONT(GrFonts_ZxSpecRus8x8);
	NewSupercode_LITERY(4, 0, 3, 5, 7, (void*)&"priwet, mir!", (LONGINT)13);
	Basic_INK(6);
	Basic_FONT(15616);
	NewSupercode_LITERY(4, 65, 3, 5, 7, (void*)&"HELLO WORLD!", (LONGINT)13);
	Basic_INK(4);
	Basic_FONT(GrFonts_MsDosCga8x8);
	NewSupercode_LITERY(4, 130, 3, 5, 7, (void*)&"HELLO WORLD!", (LONGINT)13);
	Basic_PAUSE(0);
	__FINI;
}
