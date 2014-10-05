#include "SYSTEM.h"
#include "GrApp.h"
#include "SdlLib.h"

typedef
	struct GrColors_Colors {
		INTEGER paper, ink;
	} GrColors_Colors;


export INTEGER GrColors_Black, GrColors_Blue, GrColors_Green, GrColors_Cyan, GrColors_Red, GrColors_Magenta, GrColors_Olive, GrColors_White, GrColors_Gray, GrColors_LightBlue, GrColors_LightGreen, GrColors_LightCyan, GrColors_LightRed, GrColors_LightMagenta, GrColors_Yellow, GrColors_LightWhite, GrColors_Orange;
export GrColors_Colors GrColors_BlackOnBlack, GrColors_BlueOnBlack, GrColors_GreenOnBlack, GrColors_CyanOnBlack, GrColors_RedOnBlack, GrColors_MagentaOnBlack, GrColors_OliveOnBlack, GrColors_WhiteOnBlack, GrColors_GrayOnBlack, GrColors_LBlueOnBlack, GrColors_LGreenOnBlack, GrColors_LCyanOnBlack, GrColors_LRedOnBlack, GrColors_LMagentaOnBlack, GrColors_YellowOnBlack, GrColors_LWhiteOnBlack, GrColors_OrangeOnBlack, GrColors_BlackOnBlue, GrColors_BlueOnBlue, GrColors_GreenOnBlue, GrColors_CyanOnBlue, GrColors_RedOnBlue, GrColors_MagentaOnBlue, GrColors_OliveOnBlue, GrColors_WhiteOnBlue, GrColors_GrayOnBlue, GrColors_LBlueOnBlue, GrColors_LGreenOnBlue, GrColors_LCyanOnBlue, GrColors_LRedOnBlue, GrColors_LMagentaOnBlue, GrColors_YellowOnBlue, GrColors_LWhiteOnBlue, GrColors_OrangeOnBlue, GrColors_BlackOnGreen, GrColors_BlueOnGreen, GrColors_GreenOnGreen, GrColors_CyanOnGreen, GrColors_RedOnGreen, GrColors_MagentaOnGreen, GrColors_OliveOnGreen, GrColors_WhiteOnGreen, GrColors_GrayOnGreen, GrColors_LBlueOnGreen, GrColors_LGreenOnGreen, GrColors_LCyanOnGreen, GrColors_LRedOnGreen, GrColors_LMagentaOnGreen, GrColors_YellowOnGreen, GrColors_LWhiteOnGreen, GrColors_OrangeOnGreen, GrColors_BlackOnCyan, GrColors_BlueOnCyan, GrColors_GreenOnCyan, GrColors_CyanOnCyan, GrColors_RedOnCyan, GrColors_MagentaOnCyan, GrColors_OliveOnCyan, GrColors_WhiteOnCyan, GrColors_GrayOnCyan, GrColors_LBlueOnCyan, GrColors_LGreenOnCyan, GrColors_LCyanOnCyan, GrColors_LRedOnCyan, GrColors_LMagentaOnCyan, GrColors_YellowOnCyan, GrColors_LWhiteOnCyan, GrColors_OrangeOnCyan, GrColors_BlackOnRed, GrColors_BlueOnRed, GrColors_GreenOnRed, GrColors_CyanOnRed, GrColors_RedOnRed, GrColors_MagentaOnRed, GrColors_OliveOnRed, GrColors_WhiteOnRed, GrColors_GrayOnRed, GrColors_LBlueOnRed, GrColors_LGreenOnRed, GrColors_LCyanOnRed, GrColors_LRedOnRed, GrColors_LMagentaOnRed, GrColors_YellowOnRed, GrColors_LWhiteOnRed, GrColors_OrangeOnRed, GrColors_BlackOnMagenta, GrColors_BlueOnMagenta, GrColors_GreenOnMagenta, GrColors_CyanOnMagenta, GrColors_RedOnMagenta, GrColors_MagentaOnMagenta, GrColors_OliveOnMagenta, GrColors_WhiteOnMagenta, GrColors_GrayOnMagenta, GrColors_LBlueOnMagenta, GrColors_LGreenOnMagenta, GrColors_LCyanOnMagenta, GrColors_LRedOnMagenta, GrColors_LMagentaOnMagenta, GrColors_YellowOnMagenta, GrColors_LWhiteOnMagenta, GrColors_OrangeOnMagenta, GrColors_BlackOnOlive, GrColors_BlueOnOlive, GrColors_GreenOnOlive, GrColors_CyanOnOlive, GrColors_RedOnOlive, GrColors_MagentaOnOlive, GrColors_OliveOnOlive, GrColors_WhiteOnOlive, GrColors_GrayOnOlive, GrColors_LBlueOnOlive, GrColors_LGreenOnOlive, GrColors_LCyanOnOlive, GrColors_LRedOnOlive, GrColors_LMagentaOnOlive, GrColors_YellowOnOlive, GrColors_LWhiteOnOlive, GrColors_OrangeOnOlive, GrColors_BlackOnWhite, GrColors_BlueOnWhite, GrColors_GreenOnWhite, GrColors_CyanOnWhite, GrColors_RedOnWhite, GrColors_MagentaOnWhite, GrColors_OliveOnWhite, GrColors_WhiteOnWhite, GrColors_GrayOnWhite, GrColors_LBlueOnWhite, GrColors_LGreenOnWhite, GrColors_LCyanOnWhite, GrColors_LRedOnWhite, GrColors_LMagentaOnWhite, GrColors_YellowOnWhite, GrColors_LWhiteOnWhite, GrColors_OrangeOnWhite, GrColors_BlackOnGray, GrColors_BlueOnGray, GrColors_GreenOnGray, GrColors_CyanOnGray, GrColors_RedOnGray, GrColors_MagentaOnGray, GrColors_OliveOnGray, GrColors_WhiteOnGray, GrColors_GrayOnGray, GrColors_LBlueOnGray, GrColors_LGreenOnGray, GrColors_LCyanOnGray, GrColors_LRedOnGray, GrColors_LMagentaOnGray, GrColors_YellowOnGray, GrColors_LWhiteOnGray, GrColors_OrangeOnGray, GrColors_BlackOnLBlue, GrColors_BlueOnLBlue, GrColors_GreenOnLBlue, GrColors_CyanOnLBlue, GrColors_RedOnLBlue, GrColors_MagentaOnLBlue, GrColors_OliveOnLBlue, GrColors_WhiteOnLBlue, GrColors_GrayOnLBlue, GrColors_LBlueOnLBlue, GrColors_LGreenOnLBlue, GrColors_LCyanOnLBlue, GrColors_LRedOnLBlue, GrColors_LMagentaOnLBlue, GrColors_YellowOnLBlue, GrColors_LWhiteOnLBlue, GrColors_OrangeOnLBlue, GrColors_BlackOnLGreen, GrColors_BlueOnLGreen, GrColors_GreenOnLGreen, GrColors_CyanOnLGreen, GrColors_RedOnLGreen, GrColors_MagentaOnLGreen, GrColors_OliveOnLGreen, GrColors_WhiteOnLGreen, GrColors_GrayOnLGreen, GrColors_LBlueOnLGreen, GrColors_LGreenOnLGreen, GrColors_LCyanOnLGreen, GrColors_LRedOnLGreen, GrColors_LMagentaOnLGreen, GrColors_YellowOnLGreen, GrColors_LWhiteOnLGreen, GrColors_OrangeOnLGreen, GrColors_BlackOnLCyan, GrColors_BlueOnLCyan, GrColors_GreenOnLCyan, GrColors_CyanOnLCyan, GrColors_RedOnLCyan, GrColors_MagentaOnLCyan, GrColors_OliveOnLCyan, GrColors_WhiteOnLCyan, GrColors_GrayOnLCyan, GrColors_LBlueOnLCyan, GrColors_LGreenOnLCyan, GrColors_LCyanOnLCyan, GrColors_LRedOnLCyan, GrColors_LMagentaOnLCyan, GrColors_YellowOnLCyan, GrColors_LWhiteOnLCyan, GrColors_OrangeOnLCyan, GrColors_BlackOnLRed, GrColors_BlueOnLRed, GrColors_GreenOnLRed, GrColors_CyanOnLRed, GrColors_RedOnLRed, GrColors_MagentaOnLRed, GrColors_OliveOnLRed, GrColors_WhiteOnLRed, GrColors_GrayOnLRed, GrColors_LBlueOnLRed, GrColors_LGreenOnLRed, GrColors_LCyanOnLRed, GrColors_LRedOnLRed, GrColors_LMagentaOnLRed, GrColors_YellowOnLRed, GrColors_LWhiteOnLRed, GrColors_OrangeOnLRed, GrColors_BlackOnLMagenta, GrColors_BlueOnLMagenta, GrColors_GreenOnLMagenta, GrColors_CyanOnLMagenta, GrColors_RedOnLMagenta, GrColors_MagentaOnLMagenta, GrColors_OliveOnLMagenta, GrColors_WhiteOnLMagenta, GrColors_GrayOnLMagenta, GrColors_LBlueOnLMagenta, GrColors_LGreenOnLMagenta, GrColors_LCyanOnLMagenta, GrColors_LRedOnLMagenta, GrColors_LMagentaOnLMagenta, GrColors_YellowOnLMagenta, GrColors_LWhiteOnLMagenta, GrColors_OrangeOnLMagenta, GrColors_BlackOnYellow, GrColors_BlueOnYellow, GrColors_GreenOnYellow, GrColors_CyanOnYellow, GrColors_RedOnYellow, GrColors_MagentaOnYellow, GrColors_OliveOnYellow, GrColors_WhiteOnYellow, GrColors_GrayOnYellow, GrColors_LBlueOnYellow, GrColors_LGreenOnYellow, GrColors_LCyanOnYellow, GrColors_LRedOnYellow, GrColors_LMagentaOnYellow, GrColors_YellowOnYellow, GrColors_LWhiteOnYellow, GrColors_OrangeOnYellow, GrColors_BlackOnLWhite, GrColors_BlueOnLWhite, GrColors_GreenOnLWhite, GrColors_CyanOnLWhite, GrColors_RedOnLWhite, GrColors_MagentaOnLWhite, GrColors_OliveOnLWhite, GrColors_WhiteOnLWhite, GrColors_GrayOnLWhite, GrColors_LBlueOnLWhite, GrColors_LGreenOnLWhite, GrColors_LCyanOnLWhite, GrColors_LRedOnLWhite, GrColors_LMagentaOnLWhite, GrColors_YellowOnLWhite, GrColors_LWhiteOnLWhite, GrColors_OrangeOnLWhite, GrColors_BlackOnOrange, GrColors_BlueOnOrange, GrColors_GreenOnOrange, GrColors_CyanOnOrange, GrColors_RedOnOrange, GrColors_MagentaOnOrange, GrColors_OliveOnOrange, GrColors_WhiteOnOrange, GrColors_GrayOnOrange, GrColors_LBlueOnOrange, GrColors_LGreenOnOrange, GrColors_LCyanOnOrange, GrColors_LRedOnOrange, GrColors_LMagentaOnOrange, GrColors_YellowOnOrange, GrColors_LWhiteOnOrange;

export LONGINT *GrColors_Colors__typ;

__TDESC(GrColors_Colors__desc, 1, 0) = {__TDFLDS("Colors", 8), {-4}};

export void GrColors__init (void)
{
	__DEFMOD;
	//__IMPORT(GrApp__init);
	//__IMPORT(SdlLib__init);
	__REGMOD("GrColors", 0);
	__INITYP(GrColors_Colors, GrColors_Colors, 0);
/* BEGIN */
	GrColors_Black = SdlLib_MapRGB(GrApp_Screen->format, 0, 0, 0);
	GrColors_Blue = SdlLib_MapRGB(GrApp_Screen->format, 0, 0, GrApp_NormalColor);
	GrColors_Green = SdlLib_MapRGB(GrApp_Screen->format, 0, GrApp_NormalColor, 0);
	GrColors_Cyan = SdlLib_MapRGB(GrApp_Screen->format, 0, GrApp_NormalColor, GrApp_NormalColor);
	GrColors_Red = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, 0, 0);
	GrColors_Magenta = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, 0, GrApp_NormalColor);
	GrColors_Olive = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, GrApp_NormalColor, 0);
	GrColors_White = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor, GrApp_NormalColor, GrApp_NormalColor);
	GrColors_Gray = SdlLib_MapRGB(GrApp_Screen->format, GrApp_NormalColor/2, GrApp_NormalColor/2, GrApp_NormalColor/2);
	GrColors_LightBlue = SdlLib_MapRGB(GrApp_Screen->format, 0, 0, 255);
	GrColors_LightGreen = SdlLib_MapRGB(GrApp_Screen->format, 0, 255, 0);
	GrColors_LightCyan = SdlLib_MapRGB(GrApp_Screen->format, 0, 255, 255);
	GrColors_LightRed = SdlLib_MapRGB(GrApp_Screen->format, 255, 0, 0);
	GrColors_LightMagenta = SdlLib_MapRGB(GrApp_Screen->format, 255, 0, 255);
	GrColors_Yellow = SdlLib_MapRGB(GrApp_Screen->format, 255, 255, 0);
	GrColors_LightWhite = SdlLib_MapRGB(GrApp_Screen->format, 255, 255, 255);
	GrColors_Orange = SdlLib_MapRGB(GrApp_Screen->format, 255, GrApp_NormalColor, 0);
	GrColors_BlackOnBlack.paper = GrColors_Black;
	GrColors_BlackOnBlack.ink = GrColors_Black;
	GrColors_BlueOnBlack.paper = GrColors_Black;
	GrColors_BlueOnBlack.ink = GrColors_Blue;
	GrColors_GreenOnBlack.paper = GrColors_Black;
	GrColors_GreenOnBlack.ink = GrColors_Green;
	GrColors_CyanOnBlack.paper = GrColors_Black;
	GrColors_CyanOnBlack.ink = GrColors_Cyan;
	GrColors_RedOnBlack.paper = GrColors_Black;
	GrColors_RedOnBlack.ink = GrColors_Red;
	GrColors_MagentaOnBlack.paper = GrColors_Black;
	GrColors_MagentaOnBlack.ink = GrColors_Magenta;
	GrColors_OliveOnBlack.paper = GrColors_Black;
	GrColors_OliveOnBlack.ink = GrColors_Olive;
	GrColors_WhiteOnBlack.paper = GrColors_Black;
	GrColors_WhiteOnBlack.ink = GrColors_White;
	GrColors_GrayOnBlack.paper = GrColors_Black;
	GrColors_GrayOnBlack.ink = GrColors_Gray;
	GrColors_LBlueOnBlack.paper = GrColors_Black;
	GrColors_LBlueOnBlack.ink = GrColors_LightBlue;
	GrColors_LGreenOnBlack.paper = GrColors_Black;
	GrColors_LGreenOnBlack.ink = GrColors_LightGreen;
	GrColors_LCyanOnBlack.paper = GrColors_Black;
	GrColors_LCyanOnBlack.ink = GrColors_LightCyan;
	GrColors_LRedOnBlack.paper = GrColors_Black;
	GrColors_LRedOnBlack.ink = GrColors_LightRed;
	GrColors_LMagentaOnBlack.paper = GrColors_Black;
	GrColors_LMagentaOnBlack.ink = GrColors_LightMagenta;
	GrColors_YellowOnBlack.paper = GrColors_Black;
	GrColors_YellowOnBlack.ink = GrColors_Yellow;
	GrColors_LWhiteOnBlack.paper = GrColors_Black;
	GrColors_LWhiteOnBlack.ink = GrColors_LightWhite;
	GrColors_OrangeOnBlack.paper = GrColors_Black;
	GrColors_OrangeOnBlack.ink = GrColors_Orange;
	GrColors_BlackOnBlue.paper = GrColors_Blue;
	GrColors_BlackOnBlue.ink = GrColors_Black;
	GrColors_BlueOnBlue.paper = GrColors_Blue;
	GrColors_BlueOnBlue.ink = GrColors_Blue;
	GrColors_GreenOnBlue.paper = GrColors_Blue;
	GrColors_GreenOnBlue.ink = GrColors_Green;
	GrColors_CyanOnBlue.paper = GrColors_Blue;
	GrColors_CyanOnBlue.ink = GrColors_Cyan;
	GrColors_RedOnBlue.paper = GrColors_Blue;
	GrColors_RedOnBlue.ink = GrColors_Red;
	GrColors_MagentaOnBlue.paper = GrColors_Blue;
	GrColors_MagentaOnBlue.ink = GrColors_Magenta;
	GrColors_OliveOnBlue.paper = GrColors_Blue;
	GrColors_OliveOnBlue.ink = GrColors_Olive;
	GrColors_WhiteOnBlue.paper = GrColors_Blue;
	GrColors_WhiteOnBlue.ink = GrColors_White;
	GrColors_GrayOnBlue.paper = GrColors_Blue;
	GrColors_GrayOnBlue.ink = GrColors_Gray;
	GrColors_LBlueOnBlue.paper = GrColors_Blue;
	GrColors_LBlueOnBlue.ink = GrColors_LightBlue;
	GrColors_LGreenOnBlue.paper = GrColors_Blue;
	GrColors_LGreenOnBlue.ink = GrColors_LightGreen;
	GrColors_LCyanOnBlue.paper = GrColors_Blue;
	GrColors_LCyanOnBlue.ink = GrColors_LightCyan;
	GrColors_LRedOnBlue.paper = GrColors_Blue;
	GrColors_LRedOnBlue.ink = GrColors_LightRed;
	GrColors_LMagentaOnBlue.paper = GrColors_Blue;
	GrColors_LMagentaOnBlue.ink = GrColors_LightMagenta;
	GrColors_YellowOnBlue.paper = GrColors_Blue;
	GrColors_YellowOnBlue.ink = GrColors_Yellow;
	GrColors_LWhiteOnBlue.paper = GrColors_Blue;
	GrColors_LWhiteOnBlue.ink = GrColors_LightWhite;
	GrColors_OrangeOnBlue.paper = GrColors_Blue;
	GrColors_OrangeOnBlue.ink = GrColors_Orange;
	GrColors_BlackOnGreen.paper = GrColors_Green;
	GrColors_BlackOnGreen.ink = GrColors_Black;
	GrColors_BlueOnGreen.paper = GrColors_Green;
	GrColors_BlueOnGreen.ink = GrColors_Blue;
	GrColors_GreenOnGreen.paper = GrColors_Green;
	GrColors_GreenOnGreen.ink = GrColors_Green;
	GrColors_CyanOnGreen.paper = GrColors_Green;
	GrColors_CyanOnGreen.ink = GrColors_Cyan;
	GrColors_RedOnGreen.paper = GrColors_Green;
	GrColors_RedOnGreen.ink = GrColors_Red;
	GrColors_MagentaOnGreen.paper = GrColors_Green;
	GrColors_MagentaOnGreen.ink = GrColors_Magenta;
	GrColors_OliveOnGreen.paper = GrColors_Green;
	GrColors_OliveOnGreen.ink = GrColors_Olive;
	GrColors_WhiteOnGreen.paper = GrColors_Green;
	GrColors_WhiteOnGreen.ink = GrColors_White;
	GrColors_GrayOnGreen.paper = GrColors_Green;
	GrColors_GrayOnGreen.ink = GrColors_Gray;
	GrColors_LBlueOnGreen.paper = GrColors_Green;
	GrColors_LBlueOnGreen.ink = GrColors_LightBlue;
	GrColors_LGreenOnGreen.paper = GrColors_Green;
	GrColors_LGreenOnGreen.ink = GrColors_LightGreen;
	GrColors_LCyanOnGreen.paper = GrColors_Green;
	GrColors_LCyanOnGreen.ink = GrColors_LightCyan;
	GrColors_LRedOnGreen.paper = GrColors_Green;
	GrColors_LRedOnGreen.ink = GrColors_LightRed;
	GrColors_LMagentaOnGreen.paper = GrColors_Green;
	GrColors_LMagentaOnGreen.ink = GrColors_LightMagenta;
	GrColors_YellowOnGreen.paper = GrColors_Green;
	GrColors_YellowOnGreen.ink = GrColors_Yellow;
	GrColors_LWhiteOnGreen.paper = GrColors_Green;
	GrColors_LWhiteOnGreen.ink = GrColors_LightWhite;
	GrColors_OrangeOnGreen.paper = GrColors_Green;
	GrColors_OrangeOnGreen.ink = GrColors_Orange;
	GrColors_BlackOnCyan.paper = GrColors_Cyan;
	GrColors_BlackOnCyan.ink = GrColors_Black;
	GrColors_BlueOnCyan.paper = GrColors_Cyan;
	GrColors_BlueOnCyan.ink = GrColors_Blue;
	GrColors_GreenOnCyan.paper = GrColors_Cyan;
	GrColors_GreenOnCyan.ink = GrColors_Green;
	GrColors_CyanOnCyan.paper = GrColors_Cyan;
	GrColors_CyanOnCyan.ink = GrColors_Cyan;
	GrColors_RedOnCyan.paper = GrColors_Cyan;
	GrColors_RedOnCyan.ink = GrColors_Red;
	GrColors_MagentaOnCyan.paper = GrColors_Cyan;
	GrColors_MagentaOnCyan.ink = GrColors_Magenta;
	GrColors_OliveOnCyan.paper = GrColors_Cyan;
	GrColors_OliveOnCyan.ink = GrColors_Olive;
	GrColors_WhiteOnCyan.paper = GrColors_Cyan;
	GrColors_WhiteOnCyan.ink = GrColors_White;
	GrColors_GrayOnCyan.paper = GrColors_Cyan;
	GrColors_GrayOnCyan.ink = GrColors_Gray;
	GrColors_LBlueOnCyan.paper = GrColors_Cyan;
	GrColors_LBlueOnCyan.ink = GrColors_LightBlue;
	GrColors_LGreenOnCyan.paper = GrColors_Cyan;
	GrColors_LGreenOnCyan.ink = GrColors_LightGreen;
	GrColors_LCyanOnCyan.paper = GrColors_Cyan;
	GrColors_LCyanOnCyan.ink = GrColors_LightCyan;
	GrColors_LRedOnCyan.paper = GrColors_Cyan;
	GrColors_LRedOnCyan.ink = GrColors_LightRed;
	GrColors_LMagentaOnCyan.paper = GrColors_Cyan;
	GrColors_LMagentaOnCyan.ink = GrColors_LightMagenta;
	GrColors_YellowOnCyan.paper = GrColors_Cyan;
	GrColors_YellowOnCyan.ink = GrColors_Yellow;
	GrColors_LWhiteOnCyan.paper = GrColors_Cyan;
	GrColors_LWhiteOnCyan.ink = GrColors_LightWhite;
	GrColors_OrangeOnCyan.paper = GrColors_Cyan;
	GrColors_OrangeOnCyan.ink = GrColors_Orange;
	GrColors_BlackOnRed.paper = GrColors_Red;
	GrColors_BlackOnRed.ink = GrColors_Black;
	GrColors_BlueOnRed.paper = GrColors_Red;
	GrColors_BlueOnRed.ink = GrColors_Blue;
	GrColors_GreenOnRed.paper = GrColors_Red;
	GrColors_GreenOnRed.ink = GrColors_Green;
	GrColors_CyanOnRed.paper = GrColors_Red;
	GrColors_CyanOnRed.ink = GrColors_Cyan;
	GrColors_RedOnRed.paper = GrColors_Red;
	GrColors_RedOnRed.ink = GrColors_Red;
	GrColors_MagentaOnRed.paper = GrColors_Red;
	GrColors_MagentaOnRed.ink = GrColors_Magenta;
	GrColors_OliveOnRed.paper = GrColors_Red;
	GrColors_OliveOnRed.ink = GrColors_Olive;
	GrColors_WhiteOnRed.paper = GrColors_Red;
	GrColors_WhiteOnRed.ink = GrColors_White;
	GrColors_GrayOnRed.paper = GrColors_Red;
	GrColors_GrayOnRed.ink = GrColors_Gray;
	GrColors_LBlueOnRed.paper = GrColors_Red;
	GrColors_LBlueOnRed.ink = GrColors_LightBlue;
	GrColors_LGreenOnRed.paper = GrColors_Red;
	GrColors_LGreenOnRed.ink = GrColors_LightGreen;
	GrColors_LCyanOnRed.paper = GrColors_Red;
	GrColors_LCyanOnRed.ink = GrColors_LightCyan;
	GrColors_LRedOnRed.paper = GrColors_Red;
	GrColors_LRedOnRed.ink = GrColors_LightRed;
	GrColors_LMagentaOnRed.paper = GrColors_Red;
	GrColors_LMagentaOnRed.ink = GrColors_LightMagenta;
	GrColors_YellowOnRed.paper = GrColors_Red;
	GrColors_YellowOnRed.ink = GrColors_Yellow;
	GrColors_LWhiteOnRed.paper = GrColors_Red;
	GrColors_LWhiteOnRed.ink = GrColors_LightWhite;
	GrColors_OrangeOnRed.paper = GrColors_Red;
	GrColors_OrangeOnRed.ink = GrColors_Orange;
	GrColors_BlackOnMagenta.paper = GrColors_Magenta;
	GrColors_BlackOnMagenta.ink = GrColors_Black;
	GrColors_BlueOnMagenta.paper = GrColors_Magenta;
	GrColors_BlueOnMagenta.ink = GrColors_Blue;
	GrColors_GreenOnMagenta.paper = GrColors_Magenta;
	GrColors_GreenOnMagenta.ink = GrColors_Green;
	GrColors_CyanOnMagenta.paper = GrColors_Magenta;
	GrColors_CyanOnMagenta.ink = GrColors_Cyan;
	GrColors_RedOnMagenta.paper = GrColors_Magenta;
	GrColors_RedOnMagenta.ink = GrColors_Red;
	GrColors_MagentaOnMagenta.paper = GrColors_Magenta;
	GrColors_MagentaOnMagenta.ink = GrColors_Magenta;
	GrColors_OliveOnMagenta.paper = GrColors_Magenta;
	GrColors_OliveOnMagenta.ink = GrColors_Olive;
	GrColors_WhiteOnMagenta.paper = GrColors_Magenta;
	GrColors_WhiteOnMagenta.ink = GrColors_White;
	GrColors_GrayOnMagenta.paper = GrColors_Magenta;
	GrColors_GrayOnMagenta.ink = GrColors_Gray;
	GrColors_LBlueOnMagenta.paper = GrColors_Magenta;
	GrColors_LBlueOnMagenta.ink = GrColors_LightBlue;
	GrColors_LGreenOnMagenta.paper = GrColors_Magenta;
	GrColors_LGreenOnMagenta.ink = GrColors_LightGreen;
	GrColors_LCyanOnMagenta.paper = GrColors_Magenta;
	GrColors_LCyanOnMagenta.ink = GrColors_LightCyan;
	GrColors_LRedOnMagenta.paper = GrColors_Magenta;
	GrColors_LRedOnMagenta.ink = GrColors_LightRed;
	GrColors_LMagentaOnMagenta.paper = GrColors_Magenta;
	GrColors_LMagentaOnMagenta.ink = GrColors_LightMagenta;
	GrColors_YellowOnMagenta.paper = GrColors_Magenta;
	GrColors_YellowOnMagenta.ink = GrColors_Yellow;
	GrColors_LWhiteOnMagenta.paper = GrColors_Magenta;
	GrColors_LWhiteOnMagenta.ink = GrColors_LightWhite;
	GrColors_OrangeOnMagenta.paper = GrColors_Magenta;
	GrColors_OrangeOnMagenta.ink = GrColors_Orange;
	GrColors_BlackOnOlive.paper = GrColors_Olive;
	GrColors_BlackOnOlive.ink = GrColors_Black;
	GrColors_BlueOnOlive.paper = GrColors_Olive;
	GrColors_BlueOnOlive.ink = GrColors_Blue;
	GrColors_GreenOnOlive.paper = GrColors_Olive;
	GrColors_GreenOnOlive.ink = GrColors_Green;
	GrColors_CyanOnOlive.paper = GrColors_Olive;
	GrColors_CyanOnOlive.ink = GrColors_Cyan;
	GrColors_RedOnOlive.paper = GrColors_Olive;
	GrColors_RedOnOlive.ink = GrColors_Red;
	GrColors_MagentaOnOlive.paper = GrColors_Olive;
	GrColors_MagentaOnOlive.ink = GrColors_Magenta;
	GrColors_OliveOnOlive.paper = GrColors_Olive;
	GrColors_OliveOnOlive.ink = GrColors_Olive;
	GrColors_WhiteOnOlive.paper = GrColors_Olive;
	GrColors_WhiteOnOlive.ink = GrColors_White;
	GrColors_GrayOnOlive.paper = GrColors_Olive;
	GrColors_GrayOnOlive.ink = GrColors_Gray;
	GrColors_LBlueOnOlive.paper = GrColors_Olive;
	GrColors_LBlueOnOlive.ink = GrColors_LightBlue;
	GrColors_LGreenOnOlive.paper = GrColors_Olive;
	GrColors_LGreenOnOlive.ink = GrColors_LightGreen;
	GrColors_LCyanOnOlive.paper = GrColors_Olive;
	GrColors_LCyanOnOlive.ink = GrColors_LightCyan;
	GrColors_LRedOnOlive.paper = GrColors_Olive;
	GrColors_LRedOnOlive.ink = GrColors_LightRed;
	GrColors_LMagentaOnOlive.paper = GrColors_Olive;
	GrColors_LMagentaOnOlive.ink = GrColors_LightMagenta;
	GrColors_YellowOnOlive.paper = GrColors_Olive;
	GrColors_YellowOnOlive.ink = GrColors_Yellow;
	GrColors_LWhiteOnOlive.paper = GrColors_Olive;
	GrColors_LWhiteOnOlive.ink = GrColors_LightWhite;
	GrColors_OrangeOnOlive.paper = GrColors_Olive;
	GrColors_OrangeOnOlive.ink = GrColors_Orange;
	GrColors_BlackOnWhite.paper = GrColors_White;
	GrColors_BlackOnWhite.ink = GrColors_Black;
	GrColors_BlueOnWhite.paper = GrColors_White;
	GrColors_BlueOnWhite.ink = GrColors_Blue;
	GrColors_GreenOnWhite.paper = GrColors_White;
	GrColors_GreenOnWhite.ink = GrColors_Green;
	GrColors_CyanOnWhite.paper = GrColors_White;
	GrColors_CyanOnWhite.ink = GrColors_Cyan;
	GrColors_RedOnWhite.paper = GrColors_White;
	GrColors_RedOnWhite.ink = GrColors_Red;
	GrColors_MagentaOnWhite.paper = GrColors_White;
	GrColors_MagentaOnWhite.ink = GrColors_Magenta;
	GrColors_OliveOnWhite.paper = GrColors_White;
	GrColors_OliveOnWhite.ink = GrColors_Olive;
	GrColors_WhiteOnWhite.paper = GrColors_White;
	GrColors_WhiteOnWhite.ink = GrColors_White;
	GrColors_GrayOnWhite.paper = GrColors_White;
	GrColors_GrayOnWhite.ink = GrColors_Gray;
	GrColors_LBlueOnWhite.paper = GrColors_White;
	GrColors_LBlueOnWhite.ink = GrColors_LightBlue;
	GrColors_LGreenOnWhite.paper = GrColors_White;
	GrColors_LGreenOnWhite.ink = GrColors_LightGreen;
	GrColors_LCyanOnWhite.paper = GrColors_White;
	GrColors_LCyanOnWhite.ink = GrColors_LightCyan;
	GrColors_LRedOnWhite.paper = GrColors_White;
	GrColors_LRedOnWhite.ink = GrColors_LightRed;
	GrColors_LMagentaOnWhite.paper = GrColors_White;
	GrColors_LMagentaOnWhite.ink = GrColors_LightMagenta;
	GrColors_YellowOnWhite.paper = GrColors_White;
	GrColors_YellowOnWhite.ink = GrColors_Yellow;
	GrColors_LWhiteOnWhite.paper = GrColors_White;
	GrColors_LWhiteOnWhite.ink = GrColors_LightWhite;
	GrColors_OrangeOnWhite.paper = GrColors_White;
	GrColors_OrangeOnWhite.ink = GrColors_Orange;
	GrColors_BlackOnGray.paper = GrColors_Gray;
	GrColors_BlackOnGray.ink = GrColors_Black;
	GrColors_BlueOnGray.paper = GrColors_Gray;
	GrColors_BlueOnGray.ink = GrColors_Blue;
	GrColors_GreenOnGray.paper = GrColors_Gray;
	GrColors_GreenOnGray.ink = GrColors_Green;
	GrColors_CyanOnGray.paper = GrColors_Gray;
	GrColors_CyanOnGray.ink = GrColors_Cyan;
	GrColors_RedOnGray.paper = GrColors_Gray;
	GrColors_RedOnGray.ink = GrColors_Red;
	GrColors_MagentaOnGray.paper = GrColors_Gray;
	GrColors_MagentaOnGray.ink = GrColors_Magenta;
	GrColors_OliveOnGray.paper = GrColors_Gray;
	GrColors_OliveOnGray.ink = GrColors_Olive;
	GrColors_WhiteOnGray.paper = GrColors_Gray;
	GrColors_WhiteOnGray.ink = GrColors_White;
	GrColors_GrayOnGray.paper = GrColors_Gray;
	GrColors_GrayOnGray.ink = GrColors_Gray;
	GrColors_LBlueOnGray.paper = GrColors_Gray;
	GrColors_LBlueOnGray.ink = GrColors_LightBlue;
	GrColors_LGreenOnGray.paper = GrColors_Gray;
	GrColors_LGreenOnGray.ink = GrColors_LightGreen;
	GrColors_LCyanOnGray.paper = GrColors_Gray;
	GrColors_LCyanOnGray.ink = GrColors_LightCyan;
	GrColors_LRedOnGray.paper = GrColors_Gray;
	GrColors_LRedOnGray.ink = GrColors_LightRed;
	GrColors_LMagentaOnGray.paper = GrColors_Gray;
	GrColors_LMagentaOnGray.ink = GrColors_LightMagenta;
	GrColors_YellowOnGray.paper = GrColors_Gray;
	GrColors_YellowOnGray.ink = GrColors_Yellow;
	GrColors_LWhiteOnGray.paper = GrColors_Gray;
	GrColors_LWhiteOnGray.ink = GrColors_LightWhite;
	GrColors_OrangeOnGray.paper = GrColors_Gray;
	GrColors_OrangeOnGray.ink = GrColors_Orange;
	GrColors_BlackOnLBlue.paper = GrColors_LightBlue;
	GrColors_BlackOnLBlue.ink = GrColors_Black;
	GrColors_BlueOnLBlue.paper = GrColors_LightBlue;
	GrColors_BlueOnLBlue.ink = GrColors_Blue;
	GrColors_GreenOnLBlue.paper = GrColors_LightBlue;
	GrColors_GreenOnLBlue.ink = GrColors_Green;
	GrColors_CyanOnLBlue.paper = GrColors_LightBlue;
	GrColors_CyanOnLBlue.ink = GrColors_Cyan;
	GrColors_RedOnLBlue.paper = GrColors_LightBlue;
	GrColors_RedOnLBlue.ink = GrColors_Red;
	GrColors_MagentaOnLBlue.paper = GrColors_LightBlue;
	GrColors_MagentaOnLBlue.ink = GrColors_Magenta;
	GrColors_OliveOnLBlue.paper = GrColors_LightBlue;
	GrColors_OliveOnLBlue.ink = GrColors_Olive;
	GrColors_WhiteOnLBlue.paper = GrColors_LightBlue;
	GrColors_WhiteOnLBlue.ink = GrColors_White;
	GrColors_GrayOnLBlue.paper = GrColors_LightBlue;
	GrColors_GrayOnLBlue.ink = GrColors_Gray;
	GrColors_LBlueOnLBlue.paper = GrColors_LightBlue;
	GrColors_LBlueOnLBlue.ink = GrColors_LightBlue;
	GrColors_LGreenOnLBlue.paper = GrColors_LightBlue;
	GrColors_LGreenOnLBlue.ink = GrColors_LightGreen;
	GrColors_LCyanOnLBlue.paper = GrColors_LightBlue;
	GrColors_LCyanOnLBlue.ink = GrColors_LightCyan;
	GrColors_LRedOnLBlue.paper = GrColors_LightBlue;
	GrColors_LRedOnLBlue.ink = GrColors_LightRed;
	GrColors_LMagentaOnLBlue.paper = GrColors_LightBlue;
	GrColors_LMagentaOnLBlue.ink = GrColors_LightMagenta;
	GrColors_YellowOnLBlue.paper = GrColors_LightBlue;
	GrColors_YellowOnLBlue.ink = GrColors_Yellow;
	GrColors_LWhiteOnLBlue.paper = GrColors_LightBlue;
	GrColors_LWhiteOnLBlue.ink = GrColors_LightWhite;
	GrColors_OrangeOnLBlue.paper = GrColors_LightBlue;
	GrColors_OrangeOnLBlue.ink = GrColors_Orange;
	GrColors_BlackOnLGreen.paper = GrColors_LightGreen;
	GrColors_BlackOnLGreen.ink = GrColors_Black;
	GrColors_BlueOnLGreen.paper = GrColors_LightGreen;
	GrColors_BlueOnLGreen.ink = GrColors_Blue;
	GrColors_GreenOnLGreen.paper = GrColors_LightGreen;
	GrColors_GreenOnLGreen.ink = GrColors_Green;
	GrColors_CyanOnLGreen.paper = GrColors_LightGreen;
	GrColors_CyanOnLGreen.ink = GrColors_Cyan;
	GrColors_RedOnLGreen.paper = GrColors_LightGreen;
	GrColors_RedOnLGreen.ink = GrColors_Red;
	GrColors_MagentaOnLGreen.paper = GrColors_LightGreen;
	GrColors_MagentaOnLGreen.ink = GrColors_Magenta;
	GrColors_OliveOnLGreen.paper = GrColors_LightGreen;
	GrColors_OliveOnLGreen.ink = GrColors_Olive;
	GrColors_WhiteOnLGreen.paper = GrColors_LightGreen;
	GrColors_WhiteOnLGreen.ink = GrColors_White;
	GrColors_GrayOnLGreen.paper = GrColors_LightGreen;
	GrColors_GrayOnLGreen.ink = GrColors_Gray;
	GrColors_LBlueOnLGreen.paper = GrColors_LightGreen;
	GrColors_LBlueOnLGreen.ink = GrColors_LightBlue;
	GrColors_LGreenOnLGreen.paper = GrColors_LightGreen;
	GrColors_LGreenOnLGreen.ink = GrColors_LightGreen;
	GrColors_LCyanOnLGreen.paper = GrColors_LightGreen;
	GrColors_LCyanOnLGreen.ink = GrColors_LightCyan;
	GrColors_LRedOnLGreen.paper = GrColors_LightGreen;
	GrColors_LRedOnLGreen.ink = GrColors_LightRed;
	GrColors_LMagentaOnLGreen.paper = GrColors_LightGreen;
	GrColors_LMagentaOnLGreen.ink = GrColors_LightMagenta;
	GrColors_YellowOnLGreen.paper = GrColors_LightGreen;
	GrColors_YellowOnLGreen.ink = GrColors_Yellow;
	GrColors_LWhiteOnLGreen.paper = GrColors_LightGreen;
	GrColors_LWhiteOnLGreen.ink = GrColors_LightWhite;
	GrColors_OrangeOnLGreen.paper = GrColors_LightGreen;
	GrColors_OrangeOnLGreen.ink = GrColors_Orange;
	GrColors_BlackOnLCyan.paper = GrColors_LightCyan;
	GrColors_BlackOnLCyan.ink = GrColors_Black;
	GrColors_BlueOnLCyan.paper = GrColors_LightCyan;
	GrColors_BlueOnLCyan.ink = GrColors_Blue;
	GrColors_GreenOnLCyan.paper = GrColors_LightCyan;
	GrColors_GreenOnLCyan.ink = GrColors_Green;
	GrColors_CyanOnLCyan.paper = GrColors_LightCyan;
	GrColors_CyanOnLCyan.ink = GrColors_Cyan;
	GrColors_RedOnLCyan.paper = GrColors_LightCyan;
	GrColors_RedOnLCyan.ink = GrColors_Red;
	GrColors_MagentaOnLCyan.paper = GrColors_LightCyan;
	GrColors_MagentaOnLCyan.ink = GrColors_Magenta;
	GrColors_OliveOnLCyan.paper = GrColors_LightCyan;
	GrColors_OliveOnLCyan.ink = GrColors_Olive;
	GrColors_WhiteOnLCyan.paper = GrColors_LightCyan;
	GrColors_WhiteOnLCyan.ink = GrColors_White;
	GrColors_GrayOnLCyan.paper = GrColors_LightCyan;
	GrColors_GrayOnLCyan.ink = GrColors_Gray;
	GrColors_LBlueOnLCyan.paper = GrColors_LightCyan;
	GrColors_LBlueOnLCyan.ink = GrColors_LightBlue;
	GrColors_LGreenOnLCyan.paper = GrColors_LightCyan;
	GrColors_LGreenOnLCyan.ink = GrColors_LightGreen;
	GrColors_LCyanOnLCyan.paper = GrColors_LightCyan;
	GrColors_LCyanOnLCyan.ink = GrColors_LightCyan;
	GrColors_LRedOnLCyan.paper = GrColors_LightCyan;
	GrColors_LRedOnLCyan.ink = GrColors_LightRed;
	GrColors_LMagentaOnLCyan.paper = GrColors_LightCyan;
	GrColors_LMagentaOnLCyan.ink = GrColors_LightMagenta;
	GrColors_YellowOnLCyan.paper = GrColors_LightCyan;
	GrColors_YellowOnLCyan.ink = GrColors_Yellow;
	GrColors_LWhiteOnLCyan.paper = GrColors_LightCyan;
	GrColors_LWhiteOnLCyan.ink = GrColors_LightWhite;
	GrColors_OrangeOnLCyan.paper = GrColors_LightCyan;
	GrColors_OrangeOnLCyan.ink = GrColors_Orange;
	GrColors_BlackOnLRed.paper = GrColors_LightRed;
	GrColors_BlackOnLRed.ink = GrColors_Black;
	GrColors_BlueOnLRed.paper = GrColors_LightRed;
	GrColors_BlueOnLRed.ink = GrColors_Blue;
	GrColors_GreenOnLRed.paper = GrColors_LightRed;
	GrColors_GreenOnLRed.ink = GrColors_Green;
	GrColors_CyanOnLRed.paper = GrColors_LightRed;
	GrColors_CyanOnLRed.ink = GrColors_Cyan;
	GrColors_RedOnLRed.paper = GrColors_LightRed;
	GrColors_RedOnLRed.ink = GrColors_Red;
	GrColors_MagentaOnLRed.paper = GrColors_LightRed;
	GrColors_MagentaOnLRed.ink = GrColors_Magenta;
	GrColors_OliveOnLRed.paper = GrColors_LightRed;
	GrColors_OliveOnLRed.ink = GrColors_Olive;
	GrColors_WhiteOnLRed.paper = GrColors_LightRed;
	GrColors_WhiteOnLRed.ink = GrColors_White;
	GrColors_GrayOnLRed.paper = GrColors_LightRed;
	GrColors_GrayOnLRed.ink = GrColors_Gray;
	GrColors_LBlueOnLRed.paper = GrColors_LightRed;
	GrColors_LBlueOnLRed.ink = GrColors_LightBlue;
	GrColors_LGreenOnLRed.paper = GrColors_LightRed;
	GrColors_LGreenOnLRed.ink = GrColors_LightGreen;
	GrColors_LCyanOnLRed.paper = GrColors_LightRed;
	GrColors_LCyanOnLRed.ink = GrColors_LightCyan;
	GrColors_LRedOnLRed.paper = GrColors_LightRed;
	GrColors_LRedOnLRed.ink = GrColors_LightRed;
	GrColors_LMagentaOnLRed.paper = GrColors_LightRed;
	GrColors_LMagentaOnLRed.ink = GrColors_LightMagenta;
	GrColors_YellowOnLRed.paper = GrColors_LightRed;
	GrColors_YellowOnLRed.ink = GrColors_Yellow;
	GrColors_LWhiteOnLRed.paper = GrColors_LightRed;
	GrColors_LWhiteOnLRed.ink = GrColors_LightWhite;
	GrColors_OrangeOnLRed.paper = GrColors_LightRed;
	GrColors_OrangeOnLRed.ink = GrColors_Orange;
	GrColors_BlackOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_BlackOnLMagenta.ink = GrColors_Black;
	GrColors_BlueOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_BlueOnLMagenta.ink = GrColors_Blue;
	GrColors_GreenOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_GreenOnLMagenta.ink = GrColors_Green;
	GrColors_CyanOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_CyanOnLMagenta.ink = GrColors_Cyan;
	GrColors_RedOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_RedOnLMagenta.ink = GrColors_Red;
	GrColors_MagentaOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_MagentaOnLMagenta.ink = GrColors_Magenta;
	GrColors_OliveOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_OliveOnLMagenta.ink = GrColors_Olive;
	GrColors_WhiteOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_WhiteOnLMagenta.ink = GrColors_White;
	GrColors_GrayOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_GrayOnLMagenta.ink = GrColors_Gray;
	GrColors_LBlueOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_LBlueOnLMagenta.ink = GrColors_LightBlue;
	GrColors_LGreenOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_LGreenOnLMagenta.ink = GrColors_LightGreen;
	GrColors_LCyanOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_LCyanOnLMagenta.ink = GrColors_LightCyan;
	GrColors_LRedOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_LRedOnLMagenta.ink = GrColors_LightRed;
	GrColors_LMagentaOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_LMagentaOnLMagenta.ink = GrColors_LightMagenta;
	GrColors_YellowOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_YellowOnLMagenta.ink = GrColors_Yellow;
	GrColors_LWhiteOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_LWhiteOnLMagenta.ink = GrColors_LightWhite;
	GrColors_OrangeOnLMagenta.paper = GrColors_LightMagenta;
	GrColors_OrangeOnLMagenta.ink = GrColors_Orange;
	GrColors_BlackOnYellow.paper = GrColors_Yellow;
	GrColors_BlackOnYellow.ink = GrColors_Black;
	GrColors_BlueOnYellow.paper = GrColors_Yellow;
	GrColors_BlueOnYellow.ink = GrColors_Blue;
	GrColors_GreenOnYellow.paper = GrColors_Yellow;
	GrColors_GreenOnYellow.ink = GrColors_Green;
	GrColors_CyanOnYellow.paper = GrColors_Yellow;
	GrColors_CyanOnYellow.ink = GrColors_Cyan;
	GrColors_RedOnYellow.paper = GrColors_Yellow;
	GrColors_RedOnYellow.ink = GrColors_Red;
	GrColors_MagentaOnYellow.paper = GrColors_Yellow;
	GrColors_MagentaOnYellow.ink = GrColors_Magenta;
	GrColors_OliveOnYellow.paper = GrColors_Yellow;
	GrColors_OliveOnYellow.ink = GrColors_Olive;
	GrColors_WhiteOnYellow.paper = GrColors_Yellow;
	GrColors_WhiteOnYellow.ink = GrColors_White;
	GrColors_GrayOnYellow.paper = GrColors_Yellow;
	GrColors_GrayOnYellow.ink = GrColors_Gray;
	GrColors_LBlueOnYellow.paper = GrColors_Yellow;
	GrColors_LBlueOnYellow.ink = GrColors_LightBlue;
	GrColors_LGreenOnYellow.paper = GrColors_Yellow;
	GrColors_LGreenOnYellow.ink = GrColors_LightGreen;
	GrColors_LCyanOnYellow.paper = GrColors_Yellow;
	GrColors_LCyanOnYellow.ink = GrColors_LightCyan;
	GrColors_LRedOnYellow.paper = GrColors_Yellow;
	GrColors_LRedOnYellow.ink = GrColors_LightRed;
	GrColors_LMagentaOnYellow.paper = GrColors_Yellow;
	GrColors_LMagentaOnYellow.ink = GrColors_LightMagenta;
	GrColors_YellowOnYellow.paper = GrColors_Yellow;
	GrColors_YellowOnYellow.ink = GrColors_Yellow;
	GrColors_LWhiteOnYellow.paper = GrColors_Yellow;
	GrColors_LWhiteOnYellow.ink = GrColors_LightWhite;
	GrColors_OrangeOnYellow.paper = GrColors_Yellow;
	GrColors_OrangeOnYellow.ink = GrColors_Orange;
	GrColors_BlackOnLWhite.paper = GrColors_LightWhite;
	GrColors_BlackOnLWhite.ink = GrColors_Black;
	GrColors_BlueOnLWhite.paper = GrColors_LightWhite;
	GrColors_BlueOnLWhite.ink = GrColors_Blue;
	GrColors_GreenOnLWhite.paper = GrColors_LightWhite;
	GrColors_GreenOnLWhite.ink = GrColors_Green;
	GrColors_CyanOnLWhite.paper = GrColors_LightWhite;
	GrColors_CyanOnLWhite.ink = GrColors_Cyan;
	GrColors_RedOnLWhite.paper = GrColors_LightWhite;
	GrColors_RedOnLWhite.ink = GrColors_Red;
	GrColors_MagentaOnLWhite.paper = GrColors_LightWhite;
	GrColors_MagentaOnLWhite.ink = GrColors_Magenta;
	GrColors_OliveOnLWhite.paper = GrColors_LightWhite;
	GrColors_OliveOnLWhite.ink = GrColors_Olive;
	GrColors_WhiteOnLWhite.paper = GrColors_LightWhite;
	GrColors_WhiteOnLWhite.ink = GrColors_White;
	GrColors_GrayOnLWhite.paper = GrColors_LightWhite;
	GrColors_GrayOnLWhite.ink = GrColors_Gray;
	GrColors_LBlueOnLWhite.paper = GrColors_LightWhite;
	GrColors_LBlueOnLWhite.ink = GrColors_LightBlue;
	GrColors_LGreenOnLWhite.paper = GrColors_LightWhite;
	GrColors_LGreenOnLWhite.ink = GrColors_LightGreen;
	GrColors_LCyanOnLWhite.paper = GrColors_LightWhite;
	GrColors_LCyanOnLWhite.ink = GrColors_LightCyan;
	GrColors_LRedOnLWhite.paper = GrColors_LightWhite;
	GrColors_LRedOnLWhite.ink = GrColors_LightRed;
	GrColors_LMagentaOnLWhite.paper = GrColors_LightWhite;
	GrColors_LMagentaOnLWhite.ink = GrColors_LightMagenta;
	GrColors_YellowOnLWhite.paper = GrColors_LightWhite;
	GrColors_YellowOnLWhite.ink = GrColors_Yellow;
	GrColors_LWhiteOnLWhite.paper = GrColors_LightWhite;
	GrColors_LWhiteOnLWhite.ink = GrColors_LightWhite;
	GrColors_OrangeOnLWhite.paper = GrColors_LightWhite;
	GrColors_OrangeOnLWhite.ink = GrColors_Orange;
	__ENDMOD;
}
