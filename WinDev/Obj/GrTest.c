/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "GrColors.h"
#include "Console.h"
#include "GrScr.h"
#include "GrPixel.h"
#include "SdlLib.h"


static INTEGER GrTest_x, GrTest_width, GrTest_height, GrTest__for__3, GrTest__for__2, GrTest__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrColors__init);
	__IMPORT(Console__init);
	__IMPORT(GrScr__init);
	__IMPORT(GrPixel__init);
	__IMPORT(SdlLib__init);
	__REGMAIN("GrTest", 0);
/* BEGIN */
	GrTest_width = GrScr_VirtualWidth;
	GrTest_height = GrScr_VirtualHeight;
	GrTest_x = 0;
	GrTest__for__3 = 150;
	GrTest__for__3 = __DIV(GrTest__for__3 - GrTest_x, 30) + 1;
	do {
		GrPixel_Ink(GrColors_LightGreen);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x);
		GrPixel_Ink(GrColors_LightRed);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 5);
		GrPixel_Ink(GrColors_LightBlue);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 10);
		GrPixel_Ink(GrColors_Green);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 15);
		GrPixel_Ink(GrColors_Red);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 20);
		GrPixel_Ink(GrColors_Blue);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 25);
		GrTest_x += 30;
		GrTest__for__3 -= 1;
	} while (!(GrTest__for__3 == 0));
	GrTest_x = 0;
	GrTest__for__2 = 255;
	GrTest__for__2 = (GrTest__for__2 - GrTest_x) + 1;
	do {
		GrPixel_Ink(GrColors_LightGreen);
		(*GrPixel_Dot)(GrTest_x, GrTest_x);
		GrPixel_Ink(GrColors_LightRed);
		(*GrPixel_Dot)(GrTest_x + 10, GrTest_x);
		GrPixel_Ink(GrColors_LightBlue);
		(*GrPixel_Dot)(GrTest_x + 20, GrTest_x);
		GrPixel_Ink(GrColors_Green);
		(*GrPixel_Dot)(GrTest_x + 50, GrTest_x);
		GrPixel_Ink(GrColors_Red);
		(*GrPixel_Dot)(GrTest_x + 60, GrTest_x);
		GrPixel_Ink(GrColors_Blue);
		(*GrPixel_Dot)(GrTest_x + 70, GrTest_x);
		GrTest_x += 1;
		GrTest__for__2 -= 1;
	} while (!(GrTest__for__2 == 0));
	GrTest_x = 0;
	GrTest__for__1 = 255;
	GrTest__for__1 = (GrTest__for__1 - GrTest_x) + 1;
	do {
		GrPixel_Ink(GrColors_Yellow);
		GrPixel_Line(GrTest_x, GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_Ink(GrColors_LightMagenta);
		GrPixel_Line(GrTest_width - GrTest_x, GrTest_x, GrTest_width - __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_Ink(GrColors_LightCyan);
		GrPixel_Line(GrTest_x, GrTest_height - GrTest_x, __ASHL(GrTest_x, 1), GrTest_height - GrTest_x * 3);
		GrPixel_Ink(GrColors_White);
		GrPixel_Line(GrTest_width - GrTest_x, GrTest_height - GrTest_x, GrTest_width - __ASHL(GrTest_x, 1), GrTest_height - GrTest_x * 3);
		GrPixel_Ink(GrColors_Olive);
		GrPixel_Line(GrTest_x + __ASHR(GrTest_width, 1), GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_Ink(GrColors_Black);
		GrPixel_Line(GrTest_x - __ASHR(GrTest_width, 1), GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrTest_x += 1;
		GrTest__for__1 -= 1;
	} while (!(GrTest__for__1 == 0));
	Console_WriteInt((int)(__VAL(CHAR, GrScr_Screen->format->BytesPerPixel)));
	if (GrScr_MustLock) {
		Console_WriteStr((CHAR*)" Must Lock", (LONGINT)11);
	} else {
		Console_WriteStr((CHAR*)" No need Lock", (LONGINT)14);
	}
	GrScr_Update();
	GrScr_Close();
	__FINI;
}
