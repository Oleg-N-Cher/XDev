/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "SdlLib.h"


export SdlLib_PSurface GrScr_Screen;
export BOOLEAN GrScr_mustLock;
export INTEGER GrScr_Black, GrScr_Blue, GrScr_Green, GrScr_Cyan, GrScr_Red, GrScr_Magenta, GrScr_Olive, GrScr_White;
static INTEGER GrScr_Gray;
export INTEGER GrScr_LightBlue, GrScr_LightGreen, GrScr_LightCyan, GrScr_LightRed, GrScr_LightMagenta, GrScr_Yellow, GrScr_LightWhite, GrScr_Orange;


export void GrScr_Close (void);


void GrScr_Close (void)
{
	SdlLib_Quit();
}


export void *GrScr__init(void)
{
	__DEFMOD;
	__IMPORT(GrConfig__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrScr", 0);
	__REGCMD("Close", GrScr_Close);
/* BEGIN */
	if (SdlLib_Init(0x20) < 0) {
		__HALT(1);
	}
	SdlLib_WM_SetCaption((SdlLib_PChar)((LONGINT)"XDev/SDL graphic"), NIL);
	GrScr_Screen = SdlLib_SetVideoMode(768, 576, 0, 0x0);
	if (GrScr_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	GrScr_mustLock = SdlLib_MustLock(GrScr_Screen);
	GrScr_Black = SdlLib_MapRGB(GrScr_Screen->format, 0, 0, 0);
	GrScr_Blue = SdlLib_MapRGB(GrScr_Screen->format, 0, 0, 128);
	GrScr_Green = SdlLib_MapRGB(GrScr_Screen->format, 0, 128, 0);
	GrScr_Cyan = SdlLib_MapRGB(GrScr_Screen->format, 0, 128, 128);
	GrScr_Red = SdlLib_MapRGB(GrScr_Screen->format, 128, 0, 0);
	GrScr_Magenta = SdlLib_MapRGB(GrScr_Screen->format, 128, 0, 128);
	GrScr_Olive = SdlLib_MapRGB(GrScr_Screen->format, 128, 128, 0);
	GrScr_White = SdlLib_MapRGB(GrScr_Screen->format, 192, 192, 192);
	GrScr_Gray = SdlLib_MapRGB(GrScr_Screen->format, 128, 128, 128);
	GrScr_LightBlue = SdlLib_MapRGB(GrScr_Screen->format, 0, 0, 255);
	GrScr_LightGreen = SdlLib_MapRGB(GrScr_Screen->format, 0, 255, 0);
	GrScr_LightCyan = SdlLib_MapRGB(GrScr_Screen->format, 0, 255, 255);
	GrScr_LightRed = SdlLib_MapRGB(GrScr_Screen->format, 255, 0, 0);
	GrScr_LightMagenta = SdlLib_MapRGB(GrScr_Screen->format, 255, 0, 255);
	GrScr_Yellow = SdlLib_MapRGB(GrScr_Screen->format, 255, 255, 0);
	GrScr_LightWhite = SdlLib_MapRGB(GrScr_Screen->format, 255, 255, 255);
	GrScr_Orange = SdlLib_MapRGB(GrScr_Screen->format, 255, 128, 0);
	__ENDMOD;
}
