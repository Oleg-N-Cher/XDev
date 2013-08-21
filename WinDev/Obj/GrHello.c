/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "GrColors.h"
#include "GrFonts.h"
#include "GrScr.h"







export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(GrColors__init);
	__IMPORT(GrFonts__init);
	__IMPORT(GrScr__init);
	__REGMAIN("GrHello", 0);
/* BEGIN */
	Console_Clear(GrColors_Orange);
	Console_SetColors(GrColors_LGreenOnYellow);
	Console_SetFont(GrFonts_ZxSpecRom8x8, 768);
	Console_At(3, 3);
	Console_WriteStr((CHAR*)"Hello World! ", (LONGINT)14);
	Console_SetColors(GrColors_GreenOnBlack);
	Console_SetFont(GrFonts_MsDosCga8x8, 2048);
	Console_At(6, 6);
	Console_WriteStr((CHAR*)"Hello World! ", (LONGINT)14);
	GrScr_Update();
	GrScr_Close();
	__FINI;
}
