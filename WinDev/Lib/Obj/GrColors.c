/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrScr.h"
#include "SdlLib.h"


export INTEGER GrColors_Black, GrColors_Blue, GrColors_Green, GrColors_Cyan, GrColors_Red, GrColors_Magenta, GrColors_Olive, GrColors_White;
static INTEGER GrColors_Gray;
export INTEGER GrColors_LightBlue, GrColors_LightGreen, GrColors_LightCyan, GrColors_LightRed, GrColors_LightMagenta, GrColors_Yellow, GrColors_LightWhite, GrColors_Orange;





export void *GrColors__init(void)
{
	__DEFMOD;
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrColors", 0);
/* BEGIN */
	GrColors_Black = SdlLib_MapRGB(GrScr_Screen->format, 0, 0, 0);
	GrColors_Blue = SdlLib_MapRGB(GrScr_Screen->format, 0, 0, 128);
	GrColors_Green = SdlLib_MapRGB(GrScr_Screen->format, 0, 128, 0);
	GrColors_Cyan = SdlLib_MapRGB(GrScr_Screen->format, 0, 128, 128);
	GrColors_Red = SdlLib_MapRGB(GrScr_Screen->format, 128, 0, 0);
	GrColors_Magenta = SdlLib_MapRGB(GrScr_Screen->format, 128, 0, 128);
	GrColors_Olive = SdlLib_MapRGB(GrScr_Screen->format, 128, 128, 0);
	GrColors_White = SdlLib_MapRGB(GrScr_Screen->format, 192, 192, 192);
	GrColors_Gray = SdlLib_MapRGB(GrScr_Screen->format, 128, 128, 128);
	GrColors_LightBlue = SdlLib_MapRGB(GrScr_Screen->format, 0, 0, 255);
	GrColors_LightGreen = SdlLib_MapRGB(GrScr_Screen->format, 0, 255, 0);
	GrColors_LightCyan = SdlLib_MapRGB(GrScr_Screen->format, 0, 255, 255);
	GrColors_LightRed = SdlLib_MapRGB(GrScr_Screen->format, 255, 0, 0);
	GrColors_LightMagenta = SdlLib_MapRGB(GrScr_Screen->format, 255, 0, 255);
	GrColors_Yellow = SdlLib_MapRGB(GrScr_Screen->format, 255, 255, 0);
	GrColors_LightWhite = SdlLib_MapRGB(GrScr_Screen->format, 255, 255, 255);
	GrColors_Orange = SdlLib_MapRGB(GrScr_Screen->format, 255, 128, 0);
	__ENDMOD;
}
