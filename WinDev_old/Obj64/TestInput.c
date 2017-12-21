/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "GrColors.h"
#include "GrFonts.h"
#include "GrScr.h"
#include "Input.h"


static CHAR TestInput_key;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(GrColors__init);
	__IMPORT(GrFonts__init);
	__IMPORT(GrScr__init);
	__IMPORT(Input__init);
	__REGMAIN("TestInput", 0);
/* BEGIN */
	Console_Clear(GrColors_Orange);
	Console_SetColors(GrColors_LGreenOnGreen);
	Console_SetFont(GrFonts_ZxSpecRom8x8, 768);
	Console_At(0, 0);
	Console_WriteStr((CHAR*)" Please type your name: ", (LONGINT)25);
	Console_SetColors(GrColors_BlackOnLRed);
	Console_SetFont(GrFonts_MsDosCga8x8, 2048);
	Console_At(0, 2);
	for (;;) {
		GrScr_Update();
		TestInput_key = Input_Read();
		Console_WriteCh(TestInput_key);
		Console_WriteInt((int)TestInput_key);
	}
	__FINI;
}
