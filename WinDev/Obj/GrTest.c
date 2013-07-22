/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "GrScr.h"
#include "GrPixel.h"
#include "SdlLib.h"


static INTEGER GrTest_x, GrTest__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(GrScr__init);
	__IMPORT(GrPixel__init);
	__IMPORT(SdlLib__init);
	__REGMAIN("GrTest", 0);
/* BEGIN */
	GrTest_x = 1;
	GrTest__for__1 = 255;
	GrTest__for__1 = (GrTest__for__1 - GrTest_x) + 1;
	do {
		GrPixel_SetInk(GrScr_LightGreen);
		(*GrPixel_PutPixel)(GrTest_x, GrTest_x);
		GrPixel_SetInk(GrScr_LightRed);
		(*GrPixel_PutPixel)(GrTest_x + 10, GrTest_x);
		GrPixel_SetInk(GrScr_LightBlue);
		(*GrPixel_PutPixel)(GrTest_x + 20, GrTest_x);
		GrPixel_SetInk(GrScr_Green);
		(*GrPixel_PutPixel)(GrTest_x + 50, GrTest_x);
		GrPixel_SetInk(GrScr_Red);
		(*GrPixel_PutPixel)(GrTest_x + 60, GrTest_x);
		GrPixel_SetInk(GrScr_Blue);
		(*GrPixel_PutPixel)(GrTest_x + 70, GrTest_x);
		GrTest_x += 1;
		GrTest__for__1 -= 1;
	} while (!(GrTest__for__1 == 0));
	Console_WriteInt((int)(__VAL(CHAR, GrScr_Screen->format->BytesPerPixel)));
	SdlLib_Delay(5000);
	GrScr_Close();
	__FINI;
}
