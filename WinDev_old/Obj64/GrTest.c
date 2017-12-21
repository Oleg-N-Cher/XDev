/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "GrApp.h"
#include "Input.h"
#include "GrPixel.h"
#include "SdlLib.h"


static INTEGER GrTest_x, GrTest_width, GrTest_height;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrApp__init);
	__IMPORT(Input__init);
	__IMPORT(GrPixel__init);
	__IMPORT(SdlLib__init);
	__REGMAIN("GrTest", 0);
/* BEGIN */
	GrTest_width = GrApp_VirtualWidth;
	GrTest_height = GrApp_VirtualHeight;
	GrTest_x = 0;
	while (GrTest_x <= 150) {
		GrPixel_Ink(GrApp_LightGreen);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x);
		GrPixel_Ink(GrApp_LightRed);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 5);
		GrPixel_Ink(GrApp_LightBlue);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 10);
		GrPixel_Ink(GrApp_Green);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 15);
		GrPixel_Ink(GrApp_Red);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 20);
		GrPixel_Ink(GrApp_Blue);
		GrPixel_Circle(__ASHR(GrTest_width, 1), __ASHR(GrTest_height, 1), GrTest_x + 25);
		GrTest_x += 30;
	}
	GrTest_x = 0;
	while (GrTest_x <= 255) {
		GrPixel_Ink(GrApp_LightGreen);
		(*GrPixel_Dot)(GrTest_x, GrTest_x);
		GrPixel_Ink(GrApp_LightRed);
		(*GrPixel_Dot)(GrTest_x + 10, GrTest_x);
		GrPixel_Ink(GrApp_LightBlue);
		(*GrPixel_Dot)(GrTest_x + 20, GrTest_x);
		GrPixel_Ink(GrApp_Green);
		(*GrPixel_Dot)(GrTest_x + 50, GrTest_x);
		GrPixel_Ink(GrApp_Red);
		(*GrPixel_Dot)(GrTest_x + 60, GrTest_x);
		GrPixel_Ink(GrApp_Blue);
		(*GrPixel_Dot)(GrTest_x + 70, GrTest_x);
		GrTest_x += 1;
	}
	GrTest_x = 0;
	while (GrTest_x <= 255) {
		GrPixel_Ink(GrApp_Yellow);
		GrPixel_Line(GrTest_x, GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_Ink(GrApp_LightMagenta);
		GrPixel_Line(GrTest_width - GrTest_x, GrTest_x, GrTest_width - __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_Ink(GrApp_LightCyan);
		GrPixel_Line(GrTest_x, GrTest_height - GrTest_x, __ASHL(GrTest_x, 1), GrTest_height - GrTest_x * 3);
		GrPixel_Ink(GrApp_White);
		GrPixel_Line(GrTest_width - GrTest_x, GrTest_height - GrTest_x, GrTest_width - __ASHL(GrTest_x, 1), GrTest_height - GrTest_x * 3);
		GrPixel_Ink(GrApp_Olive);
		GrPixel_Line(GrTest_x + __ASHR(GrTest_width, 1), GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrPixel_Ink(GrApp_Black);
		GrPixel_Line(GrTest_x - __ASHR(GrTest_width, 1), GrTest_x, __ASHL(GrTest_x, 1), GrTest_x * 3);
		GrTest_x += 1;
	}
	GrApp_Redraw();
	if (Input_Read() == ' ') {
	}
	GrApp_Close();
	__FINI;
}
