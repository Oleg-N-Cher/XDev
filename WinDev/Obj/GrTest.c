/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "Console.h"
#include "GrScr.h"
#include "GrPixel.h"
#include "SdlLib.h"


static INTEGER GrTest_x, GrTest__for__3, GrTest__for__2, GrTest__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrConfig__init);
	__IMPORT(Console__init);
	__IMPORT(GrScr__init);
	__IMPORT(GrPixel__init);
	__IMPORT(SdlLib__init);
	__REGMAIN("GrTest", 0);
/* BEGIN */
	GrTest_x = 0;
	GrTest__for__3 = 150;
	GrTest__for__3 = __DIV(GrTest__for__3 - GrTest_x, 30) + 1;
	do {
		GrPixel_SetInk(GrScr_LightGreen);
		GrPixel_Circle(128, 96, GrTest_x);
		GrPixel_SetInk(GrScr_LightRed);
		GrPixel_Circle(128, 96, GrTest_x + 5);
		GrPixel_SetInk(GrScr_LightBlue);
		GrPixel_Circle(128, 96, GrTest_x + 10);
		GrPixel_SetInk(GrScr_Green);
		GrPixel_Circle(128, 96, GrTest_x + 15);
		GrPixel_SetInk(GrScr_Red);
		GrPixel_Circle(128, 96, GrTest_x + 20);
		GrPixel_SetInk(GrScr_Blue);
		GrPixel_Circle(128, 96, GrTest_x + 25);
		GrTest_x += 30;
		GrTest__for__3 -= 1;
	} while (!(GrTest__for__3 == 0));
	GrTest_x = 0;
	GrTest__for__2 = 255;
	GrTest__for__2 = (GrTest__for__2 - GrTest_x) + 1;
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
		GrTest__for__2 -= 1;
	} while (!(GrTest__for__2 == 0));
	GrTest_x = 0;
	GrTest__for__1 = 255;
	GrTest__for__1 = (GrTest__for__1 - GrTest_x) + 1;
	do {
		GrPixel_SetInk(GrScr_Yellow);
		GrPixel_Line(GrTest_x, GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_SetInk(GrScr_LightMagenta);
		GrPixel_Line(256 - GrTest_x, GrTest_x, 256 - __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_SetInk(GrScr_LightCyan);
		GrPixel_Line(GrTest_x, 192 - GrTest_x, __ASHL(GrTest_x, 1), 192 - GrTest_x * 3);
		GrPixel_SetInk(GrScr_White);
		GrPixel_Line(256 - GrTest_x, 192 - GrTest_x, 256 - __ASHL(GrTest_x, 1), 192 - GrTest_x * 3);
		GrPixel_SetInk(GrScr_Olive);
		GrPixel_Line(GrTest_x + 128, GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_SetInk(GrScr_Black);
		GrPixel_Line(GrTest_x - 128, GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrTest_x += 1;
		GrTest__for__1 -= 1;
	} while (!(GrTest__for__1 == 0));
	Console_WriteInt((int)(__VAL(CHAR, GrScr_Screen->format->BytesPerPixel)));
	if (GrScr_mustLock) {
		Console_WriteStr((CHAR*)" Must Lock", (LONGINT)11);
	} else {
		Console_WriteStr((CHAR*)" No need Lock", (LONGINT)14);
	}
	GrScr_Update();
	SdlLib_Delay(5000);
	GrScr_Close();
	__FINI;
}
