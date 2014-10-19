#include "SYSTEM.h"
#include "SdlLib.h"


export SdlLib_PSurface GrApp_Screen;
export BOOLEAN GrApp_MustLock;
export INTEGER GrApp_ActualWidth, GrApp_ActualHeight, GrApp_VirtualWidth, GrApp_VirtualHeight, GrApp_ActualMaxX, GrApp_ActualMaxY;
export SHORTINT GrApp_DepthBits, GrApp_NormalColor;
export CHAR* GrApp_AppTitle;


export INTEGER GrApp_Black, GrApp_Blue, GrApp_Green, GrApp_Cyan, GrApp_Red,
  GrApp_Magenta, GrApp_Olive, GrApp_White, GrApp_Gray, GrApp_LightBlue,
  GrApp_LightGreen, GrApp_LightCyan, GrApp_LightRed, GrApp_LightMagenta,
  GrApp_Yellow, GrApp_LightWhite, GrApp_Orange;

export void GrApp_Close (void);
export void GrApp_Update (void);


void GrApp_Close (void)
{
	SdlLib_Quit();
}

void GrApp_Update (void)
{
	SdlLib_Flip(GrApp_Screen);
}

void GrApp_InitColors (void)
{
	GrApp_Black = SdlLib_MapRGB(GrApp_Screen->format, 0, 0, 0);
	GrApp_Blue = SdlLib_MapRGB(GrApp_Screen->format, 0, 0, GrApp_NormalColor);
	GrApp_Green = SdlLib_MapRGB(GrApp_Screen->format, 0, GrApp_NormalColor, 0);
	GrApp_Cyan = SdlLib_MapRGB(GrApp_Screen->format, 0, GrApp_NormalColor, GrApp_NormalColor);
	GrApp_Red = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, 0, 0);
	GrApp_Magenta = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, 0, GrApp_NormalColor);
	GrApp_Olive = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, GrApp_NormalColor, 0);
	GrApp_White = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, GrApp_NormalColor, GrApp_NormalColor);
	GrApp_Gray = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor/2, GrApp_NormalColor/2, GrApp_NormalColor/2);
	GrApp_LightBlue = SdlLib_MapRGB(GrApp_Screen->format, 0, 0, 255);
	GrApp_LightGreen = SdlLib_MapRGB(GrApp_Screen->format, 0, 255, 0);
	GrApp_LightCyan = SdlLib_MapRGB(GrApp_Screen->format, 0, 255, 255);
	GrApp_LightRed = SdlLib_MapRGB(GrApp_Screen->format, 255, 0, 0);
	GrApp_LightMagenta = SdlLib_MapRGB(GrApp_Screen->format, 255, 0, 255);
	GrApp_Yellow = SdlLib_MapRGB(GrApp_Screen->format, 255, 255, 0);
	GrApp_LightWhite = SdlLib_MapRGB(GrApp_Screen->format, 255, 255, 255);
	GrApp_Orange = SdlLib_MapRGB(GrApp_Screen->format, 255, GrApp_NormalColor, 0);
} //GrApp_InitColors

export void GrApp_Init (void)
{
	__DEFMOD;
	__IMPORT(SdlLib__init);
	__REGMOD("GrApp", 0);
	__REGCMD("Close", GrApp_Close);
	__REGCMD("Update", GrApp_Update);
/* BEGIN */
	if (SdlLib_Init(0x20) < 0) {
		__HALT(1);
	}
	SdlLib_WM_SetCaption((SdlLib_PChar)GrApp_AppTitle, NIL);
	GrApp_Screen = SdlLib_SetVideoMode(GrApp_ActualWidth, GrApp_ActualHeight, GrApp_DepthBits, 0x40000000);
	if (GrApp_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	GrApp_MustLock = SdlLib_MustLock(GrApp_Screen);
	GrApp_ActualMaxX = GrApp_ActualWidth - 1;
	GrApp_ActualMaxY = GrApp_ActualHeight - 1;
	GrApp_InitColors();
	__ENDMOD;
}
