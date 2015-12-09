#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "ConsoleCfg.h"

/* StdIO */
import void Console_WriteBool_StdIO (BOOLEAN b);
import void Console_WriteCh_StdIO (CHAR ch);
import void Console_WriteInt_StdIO (LONGINT n);
import void Console_WriteReal_StdIO (REAL r);
import void Console_WriteLn_StdIO (void);
import void Console_WriteStr_StdIO (CHAR *str);
import void Console_WriteStrLn_StdIO (CHAR *str);
import void Console_WriteIntWidth_StdIO (INTEGER x, INTEGER n);
import void Console_WriteHex_StdIO (INTEGER val);

/* WinAPI */
import void Console_At_WinAPI (INTEGER x, INTEGER y);
import void Console_WriteBool_WinAPI (BOOLEAN b);
import void Console_WriteLn_WinAPI (void);
import void Console_WriteStr_WinAPI (CHAR *str);
import void Console_WriteStrLn_WinAPI (CHAR *str);
import void Console_SetColors_WinAPI (INTEGER colors);

/* StdIO */
#ifdef OUTPUT_STDIO
#  define Console_SetColors(colors)
#  define Console_WriteBool	Console_WriteBool_StdIO
#  define Console_WriteCh	Console_WriteCh_StdIO
#  define Console_WriteInt	Console_WriteInt_StdIO
#  define Console_WriteReal	Console_WriteReal_StdIO
#  define Console_WriteStr(str, str__len)	Console_WriteStr_StdIO(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_StdIO(str)
#  define Console_WriteLn	Console_WriteLn_StdIO
#  define Console_WriteIntWidth	Console_WriteIntWidth_StdIO
#  define Console_WriteHex	Console_WriteHex_StdIO
#  define Console__init()
#endif //OUTPUT_STDIO

/* ConIO */
/*
#ifdef OUTPUT_CONIO
#  define Console_SetColors(colors)
#  define Console_WriteStr(str, str__len)	_cputs(str)
#  define Console__init()
#endif //OUTPUT_CONIO
*/

/* WinAPI */
#ifdef OUTPUT_WINAPI
#  define Console_At	Console_At_WinAPI
#  define Console_WriteBool Console_WriteBool_WinAPI
#  define Console_WriteCh(ch)	printf("%c", ch)
#  define Console_WriteInt(i)	printf("%ld", i)
#  define Console_WriteLn Console_WriteLn_WinAPI
#  define Console_WriteStr(str, str__len)	Console_WriteStr_WinAPI(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_WinAPI(str)
#  define Console_SetColors	Console_SetColors_WinAPI
#  define Console__init()
#endif //OUTPUT_WINAPI

/* SDL */
#ifdef OUTPUT_SDL
#  include "GrApp.h"
#  include "GrConsole.h"

#  define Console_At		GrConsole_At
#  define Console_Clear		GrConsole_Clear
#  define Console_SetColors	GrConsole_SetColors
#  define Console_SetFont	GrConsole_SetFont
#  define Console_WriteCh	GrConsole_WriteCh
#  define Console_WriteInt	GrConsole_WriteInt
#  define Console_WriteStr	GrConsole_WriteStr
#  define Console_WriteStrLn	GrConsole_WriteStrLn
#  define Console_WriteLn	GrConsole_WriteLn
#  define Console__init	GrConsole__init


#  define Console_Black		GrApp_Black
#  define Console_Blue		GrApp_Blue
#  define Console_Green		GrApp_Green
#  define Console_Cyan		GrApp_Cyan
#  define Console_Red		GrApp_Red
#  define Console_Magenta	GrApp_Magenta
#  define Console_Olive		GrApp_Olive
#  define Console_White		GrApp_White
#  define Console_Gray		GrApp_Gray
#  define Console_LightBlue	GrApp_LightBlue
#  define Console_LightGreen	GrApp_LightGreen
#  define Console_LightCyan	GrApp_LightCyan
#  define Console_LightRed	GrApp_LightRed
#  define Console_LightMagenta	GrApp_LightMagenta
#  define Console_Yellow	GrApp_Yellow
#  define Console_LightWhite	GrApp_LightWhite
#  define Console_Orange	GrApp_Orange

#  define Console_BlackOnBlack		GrApp_BlackOnBlack
#  define Console_BlueOnBlack		GrApp_BlueOnBlack
#  define Console_GreenOnBlack		GrApp_GreenOnBlack
#  define Console_CyanOnBlack		GrApp_CyanOnBlack
#  define Console_RedOnBlack		GrApp_RedOnBlack
#  define Console_MagentaOnBlack	GrApp_MagentaOnBlack
#  define Console_OliveOnBlack		GrApp_OliveOnBlack
#  define Console_WhiteOnBlack		GrApp_WhiteOnBlack
#  define Console_GrayOnBlack		GrApp_GrayOnBlack
#  define Console_LBlueOnBlack		GrApp_LBlueOnBlack
#  define Console_LGreenOnBlack		GrApp_LGreenOnBlack
#  define Console_LCyanOnBlack		GrApp_LCyanOnBlack
#  define Console_LRedOnBlack		GrApp_LRedOnBlack
#  define Console_LMagentaOnBlack	GrApp_LMagentaOnBlack
#  define Console_YellowOnBlack		GrApp_YellowOnBlack
#  define Console_LWhiteOnBlack		GrApp_LWhiteOnBlack
#  define Console_OrangeOnBlack		GrApp_OrangeOnBlack
	
#  define Console_BlackOnBlue		GrApp_BlackOnBlue
#  define Console_BlueOnBlue		GrApp_BlueOnBlue
#  define Console_GreenOnBlue		GrApp_GreenOnBlue
#  define Console_CyanOnBlue		GrApp_CyanOnBlue
#  define Console_RedOnBlue		GrApp_RedOnBlue
#  define Console_MagentaOnBlue		GrApp_MagentaOnBlue
#  define Console_OliveOnBlue		GrApp_OliveOnBlue
#  define Console_WhiteOnBlue		GrApp_WhiteOnBlue
#  define Console_GrayOnBlue		GrApp_GrayOnBlue
#  define Console_LBlueOnBlue		GrApp_LBlueOnBlue
#  define Console_LGreenOnBlue		GrApp_LGreenOnBlue
#  define Console_LCyanOnBlue		GrApp_LCyanOnBlue
#  define Console_LRedOnBlue		GrApp_LRedOnBlue
#  define Console_LMagentaOnBlue	GrApp_LMagentaOnBlue
#  define Console_YellowOnBlue		GrApp_YellowOnBlue
#  define Console_LWhiteOnBlue		GrApp_LWhiteOnBlue
#  define Console_OrangeOnBlue		GrApp_OrangeOnBlue
	
#  define Console_BlackOnGreen		GrApp_BlackOnGreen
#  define Console_BlueOnGreen		GrApp_BlueOnGreen
#  define Console_GreenOnGreen		GrApp_GreenOnGreen
#  define Console_CyanOnGreen		GrApp_CyanOnGreen
#  define Console_RedOnGreen		GrApp_RedOnGreen
#  define Console_MagentaOnGreen	GrApp_MagentaOnGreen
#  define Console_OliveOnGreen		GrApp_OliveOnGreen
#  define Console_WhiteOnGreen		GrApp_WhiteOnGreen
#  define Console_GrayOnGreen		GrApp_GrayOnGreen
#  define Console_LBlueOnGreen		GrApp_LBlueOnGreen
#  define Console_LGreenOnGreen		GrApp_LGreenOnGreen
#  define Console_LCyanOnGreen		GrApp_LCyanOnGreen
#  define Console_LRedOnGreen		GrApp_LRedOnGreen
#  define Console_LMagentaOnGreen	GrApp_LMagentaOnGreen
#  define Console_YellowOnGreen		GrApp_YellowOnGreen
#  define Console_LWhiteOnGreen		GrApp_LWhiteOnGreen
#  define Console_OrangeOnGreen		GrApp_OrangeOnGreen

#  define Console_BlackOnCyan		GrApp_BlackOnCyan
#  define Console_BlueOnCyan		GrApp_BlueOnCyan
#  define Console_GreenOnCyan		GrApp_GreenOnCyan
#  define Console_CyanOnCyan		GrApp_CyanOnCyan
#  define Console_RedOnCyan		GrApp_RedOnCyan
#  define Console_MagentaOnCyan		GrApp_MagentaOnCyan
#  define Console_OliveOnCyan		GrApp_OliveOnCyan
#  define Console_WhiteOnCyan		GrApp_WhiteOnCyan
#  define Console_GrayOnCyan		GrApp_GrayOnCyan
#  define Console_LBlueOnCyan		GrApp_LBlueOnCyan
#  define Console_LGreenOnCyan		GrApp_LGreenOnCyan
#  define Console_LCyanOnCyan		GrApp_LCyanOnCyan
#  define Console_LRedOnCyan		GrApp_LRedOnCyan
#  define Console_LMagentaOnCyan	GrApp_LMagentaOnCyan
#  define Console_YellowOnCyan		GrApp_YellowOnCyan
#  define Console_LWhiteOnCyan		GrApp_LWhiteOnCyan
#  define Console_OrangeOnCyan		GrApp_OrangeOnCyan

#  define Console_BlackOnRed		GrApp_BlackOnRed
#  define Console_BlueOnRed		GrApp_BlueOnRed
#  define Console_GreenOnRed		GrApp_GreenOnRed
#  define Console_CyanOnRed		GrApp_CyanOnRed
#  define Console_RedOnRed		GrApp_RedOnRed
#  define Console_MagentaOnRed		GrApp_MagentaOnRed
#  define Console_OliveOnRed		GrApp_OliveOnRed
#  define Console_WhiteOnRed		GrApp_WhiteOnRed
#  define Console_GrayOnRed		GrApp_GrayOnRed
#  define Console_LBlueOnRed		GrApp_LBlueOnRed
#  define Console_LGreenOnRed		GrApp_LGreenOnRed
#  define Console_LCyanOnRed		GrApp_LCyanOnRed
#  define Console_LRedOnRed		GrApp_LRedOnRed
#  define Console_LMagentaOnRed		GrApp_LMagentaOnRed
#  define Console_YellowOnRed		GrApp_YellowOnRed
#  define Console_LWhiteOnRed		GrApp_LWhiteOnRed
#  define Console_OrangeOnRed		GrApp_OrangeOnRed

#  define Console_BlackOnMagenta	GrApp_BlackOnMagenta
#  define Console_BlueOnMagenta		GrApp_BlueOnMagenta
#  define Console_GreenOnMagenta	GrApp_GreenOnMagenta
#  define Console_CyanOnMagenta		GrApp_CyanOnMagenta
#  define Console_RedOnMagenta		GrApp_RedOnMagenta
#  define Console_MagentaOnMagenta	GrApp_MagentaOnMagenta
#  define Console_OliveOnMagenta	GrApp_OliveOnMagenta
#  define Console_WhiteOnMagenta	GrApp_WhiteOnMagenta
#  define Console_GrayOnMagenta		GrApp_GrayOnMagenta
#  define Console_LBlueOnMagenta	GrApp_LBlueOnMagenta
#  define Console_LGreenOnMagenta	GrApp_LGreenOnMagenta
#  define Console_LCyanOnMagenta	GrApp_LCyanOnMagenta
#  define Console_LRedOnMagenta		GrApp_LRedOnMagenta
#  define Console_LMagentaOnMagenta	GrApp_LMagentaOnMagenta
#  define Console_YellowOnMagenta	GrApp_YellowOnMagenta
#  define Console_LWhiteOnMagenta	GrApp_LWhiteOnMagenta
#  define Console_OrangeOnMagenta	GrApp_OrangeOnMagenta

#  define Console_BlackOnOlive		GrApp_BlackOnOlive
#  define Console_BlueOnOlive		GrApp_BlueOnOlive
#  define Console_GreenOnOlive		GrApp_GreenOnOlive
#  define Console_CyanOnOlive		GrApp_CyanOnOlive
#  define Console_RedOnOlive		GrApp_RedOnOlive
#  define Console_MagentaOnOlive	GrApp_MagentaOnOlive
#  define Console_OliveOnOlive		GrApp_OliveOnOlive
#  define Console_WhiteOnOlive		GrApp_WhiteOnOlive
#  define Console_GrayOnOlive		GrApp_GrayOnOlive
#  define Console_LBlueOnOlive		GrApp_LBlueOnOlive
#  define Console_LGreenOnOlive		GrApp_LGreenOnOlive
#  define Console_LCyanOnOlive		GrApp_LCyanOnOlive
#  define Console_LRedOnOlive		GrApp_LRedOnOlive
#  define Console_LMagentaOnOlive	GrApp_LMagentaOnOlive
#  define Console_YellowOnOlive		GrApp_YellowOnOlive
#  define Console_LWhiteOnOlive		GrApp_LWhiteOnOlive
#  define Console_OrangeOnOlive		GrApp_OrangeOnOlive

#  define Console_BlackOnWhite		GrApp_BlackOnWhite
#  define Console_BlueOnWhite		GrApp_BlueOnWhite
#  define Console_GreenOnWhite		GrApp_GreenOnWhite
#  define Console_CyanOnWhite		GrApp_CyanOnWhite
#  define Console_RedOnWhite		GrApp_RedOnWhite
#  define Console_MagentaOnWhite	GrApp_MagentaOnWhite
#  define Console_OliveOnWhite		GrApp_OliveOnWhite
#  define Console_WhiteOnWhite		GrApp_WhiteOnWhite
#  define Console_GrayOnWhite		GrApp_GrayOnWhite
#  define Console_LBlueOnWhite		GrApp_LBlueOnWhite
#  define Console_LGreenOnWhite		GrApp_LGreenOnWhite
#  define Console_LCyanOnWhite		GrApp_LCyanOnWhite
#  define Console_LRedOnWhite		GrApp_LRedOnWhite
#  define Console_LMagentaOnWhite	GrApp_LMagentaOnWhite
#  define Console_YellowOnWhite		GrApp_YellowOnWhite
#  define Console_LWhiteOnWhite		GrApp_LWhiteOnWhite
#  define Console_OrangeOnWhite		GrApp_OrangeOnWhite

#  define Console_BlackOnGray		GrApp_BlackOnGray
#  define Console_BlueOnGray		GrApp_BlueOnGray
#  define Console_GreenOnGray		GrApp_GreenOnGray
#  define Console_CyanOnGray		GrApp_CyanOnGray
#  define Console_RedOnGray		GrApp_RedOnGray
#  define Console_MagentaOnGray		GrApp_MagentaOnGray
#  define Console_OliveOnGray		GrApp_OliveOnGray
#  define Console_WhiteOnGray		GrApp_WhiteOnGray
#  define Console_GrayOnGray		GrApp_GrayOnGray
#  define Console_LBlueOnGray		GrApp_LBlueOnGray
#  define Console_LGreenOnGray		GrApp_LGreenOnGray
#  define Console_LCyanOnGray		GrApp_LCyanOnGray
#  define Console_LRedOnGray		GrApp_LRedOnGray
#  define Console_LMagentaOnGray	GrApp_LMagentaOnGray
#  define Console_YellowOnGray		GrApp_YellowOnGray
#  define Console_LWhiteOnGray		GrApp_LWhiteOnGray
#  define Console_OrangeOnGray		GrApp_OrangeOnGray

#  define Console_BlackOnLBlue		GrApp_BlackOnLBlue
#  define Console_BlueOnLBlue		GrApp_BlueOnLBlue
#  define Console_GreenOnLBlue		GrApp_GreenOnLBlue
#  define Console_CyanOnLBlue		GrApp_CyanOnLBlue
#  define Console_RedOnLBlue		GrApp_RedOnLBlue
#  define Console_MagentaOnLBlue	GrApp_MagentaOnLBlue
#  define Console_OliveOnLBlue		GrApp_OliveOnLBlue
#  define Console_WhiteOnLBlue		GrApp_WhiteOnLBlue
#  define Console_GrayOnLBlue		GrApp_GrayOnLBlue
#  define Console_LBlueOnLBlue		GrApp_LBlueOnLBlue
#  define Console_LGreenOnLBlue		GrApp_LGreenOnLBlue
#  define Console_LCyanOnLBlue		GrApp_LCyanOnLBlue
#  define Console_LRedOnLBlue		GrApp_LRedOnLBlue
#  define Console_LMagentaOnLBlue	GrApp_LMagentaOnLBlue
#  define Console_YellowOnLBlue		GrApp_YellowOnLBlue
#  define Console_LWhiteOnLBlue		GrApp_LWhiteOnLBlue
#  define Console_OrangeOnLBlue		GrApp_OrangeOnLBlue

#  define Console_BlackOnLGreen		GrApp_BlackOnLGreen
#  define Console_BlueOnLGreen		GrApp_BlueOnLGreen
#  define Console_GreenOnLGreen		GrApp_GreenOnLGreen
#  define Console_CyanOnLGreen		GrApp_CyanOnLGreen
#  define Console_RedOnLGreen		GrApp_RedOnLGreen
#  define Console_MagentaOnLGreen	GrApp_MagentaOnLGreen
#  define Console_OliveOnLGreen		GrApp_OliveOnLGreen
#  define Console_WhiteOnLGreen		GrApp_WhiteOnLGreen
#  define Console_GrayOnLGreen		GrApp_GrayOnLGreen
#  define Console_LBlueOnLGreen		GrApp_LBlueOnLGreen
#  define Console_LGreenOnLGreen	GrApp_LGreenOnLGreen
#  define Console_LCyanOnLGreen		GrApp_LCyanOnLGreen
#  define Console_LRedOnLGreen		GrApp_LRedOnLGreen
#  define Console_LMagentaOnLGreen	GrApp_LMagentaOnLGreen
#  define Console_YellowOnLGreen	GrApp_YellowOnLGreen
#  define Console_LWhiteOnLGreen	GrApp_LWhiteOnLGreen
#  define Console_OrangeOnLGreen	GrApp_OrangeOnLGreen

#  define Console_BlackOnLCyan		GrApp_BlackOnLCyan
#  define Console_BlueOnLCyan		GrApp_BlueOnLCyan
#  define Console_GreenOnLCyan		GrApp_GreenOnLCyan
#  define Console_CyanOnLCyan		GrApp_CyanOnLCyan
#  define Console_RedOnLCyan		GrApp_RedOnLCyan
#  define Console_MagentaOnLCyan	GrApp_MagentaOnLCyan
#  define Console_OliveOnLCyan		GrApp_OliveOnLCyan
#  define Console_WhiteOnLCyan		GrApp_WhiteOnLCyan
#  define Console_GrayOnLCyan		GrApp_GrayOnLCyan
#  define Console_LBlueOnLCyan		GrApp_LBlueOnLCyan
#  define Console_LGreenOnLCyan		GrApp_LGreenOnLCyan
#  define Console_LCyanOnLCyan		GrApp_LCyanOnLCyan
#  define Console_LRedOnLCyan		GrApp_LRedOnLCyan
#  define Console_LMagentaOnLCyan	GrApp_LMagentaOnLCyan
#  define Console_YellowOnLCyan		GrApp_YellowOnLCyan
#  define Console_LWhiteOnLCyan		GrApp_LWhiteOnLCyan
#  define Console_OrangeOnLCyan		GrApp_OrangeOnLCyan

#  define Console_BlackOnLRed		GrApp_BlackOnLRed
#  define Console_BlueOnLRed		GrApp_BlueOnLRed
#  define Console_GreenOnLRed		GrApp_GreenOnLRed
#  define Console_CyanOnLRed		GrApp_CyanOnLRed
#  define Console_RedOnLRed		GrApp_RedOnLRed
#  define Console_MagentaOnLRed		GrApp_MagentaOnLRed
#  define Console_OliveOnLRed		GrApp_OliveOnLRed
#  define Console_WhiteOnLRed		GrApp_WhiteOnLRed
#  define Console_GrayOnLRed		GrApp_GrayOnLRed
#  define Console_LBlueOnLRed		GrApp_LBlueOnLRed
#  define Console_LGreenOnLRed		GrApp_LGreenOnLRed
#  define Console_LCyanOnLRed		GrApp_LCyanOnLRed
#  define Console_LRedOnLRed		GrApp_LRedOnLRed
#  define Console_LMagentaOnLRed	GrApp_LMagentaOnLRed
#  define Console_YellowOnLRed		GrApp_YellowOnLRed
#  define Console_LWhiteOnLRed		GrApp_LWhiteOnLRed
#  define Console_OrangeOnLRed		GrApp_OrangeOnLRed

#  define Console_BlackOnLMagenta	GrApp_BlackOnLMagenta
#  define Console_BlueOnLMagenta	GrApp_BlueOnLMagenta
#  define Console_GreenOnLMagenta	GrApp_GreenOnLMagenta
#  define Console_CyanOnLMagenta	GrApp_CyanOnLMagenta
#  define Console_RedOnLMagenta		GrApp_RedOnLMagenta
#  define Console_MagentaOnLMagenta	GrApp_MagentaOnLMagenta
#  define Console_OliveOnLMagenta	GrApp_OliveOnLMagenta
#  define Console_WhiteOnLMagenta	GrApp_WhiteOnLMagenta
#  define Console_GrayOnLMagenta	GrApp_GrayOnLMagenta
#  define Console_LBlueOnLMagenta	GrApp_LBlueOnLMagenta
#  define Console_LGreenOnLMagenta	GrApp_LGreenOnLMagenta
#  define Console_LCyanOnLMagenta	GrApp_LCyanOnLMagenta
#  define Console_LRedOnLMagenta	GrApp_LRedOnLMagenta
#  define Console_LMagentaOnLMagenta	GrApp_LMagentaOnLMagenta
#  define Console_YellowOnLMagenta	GrApp_YellowOnLMagenta
#  define Console_LWhiteOnLMagenta	GrApp_LWhiteOnLMagenta
#  define Console_OrangeOnLMagenta	GrApp_OrangeOnLMagenta

#  define Console_BlackOnYellow		GrApp_BlackOnYellow
#  define Console_BlueOnYellow		GrApp_BlueOnYellow
#  define Console_GreenOnYellow		GrApp_GreenOnYellow
#  define Console_CyanOnYellow		GrApp_CyanOnYellow
#  define Console_RedOnYellow		GrApp_RedOnYellow
#  define Console_MagentaOnYellow	GrApp_MagentaOnYellow
#  define Console_OliveOnYellow		GrApp_OliveOnYellow
#  define Console_WhiteOnYellow		GrApp_WhiteOnYellow
#  define Console_GrayOnYellow		GrApp_GrayOnYellow
#  define Console_LBlueOnYellow		GrApp_LBlueOnYellow
#  define Console_LGreenOnYellow	GrApp_LGreenOnYellow
#  define Console_LCyanOnYellow		GrApp_LCyanOnYellow
#  define Console_LRedOnYellow		GrApp_LRedOnYellow
#  define Console_LMagentaOnYellow	GrApp_LMagentaOnYellow
#  define Console_YellowOnYellow	GrApp_YellowOnYellow
#  define Console_LWhiteOnYellow	GrApp_LWhiteOnYellow
#  define Console_OrangeOnYellow	GrApp_OrangeOnYellow

#  define Console_BlackOnLWhite		GrApp_BlackOnLWhite
#  define Console_BlueOnLWhite		GrApp_BlueOnLWhite
#  define Console_GreenOnLWhite		GrApp_GreenOnLWhite
#  define Console_CyanOnLWhite		GrApp_CyanOnLWhite
#  define Console_RedOnLWhite		GrApp_RedOnLWhite
#  define Console_MagentaOnLWhite	GrApp_MagentaOnLWhite
#  define Console_OliveOnLWhite		GrApp_OliveOnLWhite
#  define Console_WhiteOnLWhite		GrApp_WhiteOnLWhite
#  define Console_GrayOnLWhite		GrApp_GrayOnLWhite
#  define Console_LBlueOnLWhite		GrApp_LBlueOnLWhite
#  define Console_LGreenOnLWhite	GrApp_LGreenOnLWhite
#  define Console_LCyanOnLWhite		GrApp_LCyanOnLWhite
#  define Console_LRedOnLWhite		GrApp_LRedOnLWhite
#  define Console_LMagentaOnLWhite	GrApp_LMagentaOnLWhite
#  define Console_YellowOnLWhite	GrApp_YellowOnLWhite
#  define Console_LWhiteOnLWhite	GrApp_LWhiteOnLWhite
#  define Console_OrangeOnLWhite	GrApp_OrangeOnLWhite

#  define Console_BlackOnOrange		GrApp_BlackOnOrange
#  define Console_BlueOnOrange		GrApp_BlueOnOrange
#  define Console_GreenOnOrange		GrApp_GreenOnOrange
#  define Console_CyanOnOrange		GrApp_CyanOnOrange
#  define Console_RedOnOrange		GrApp_RedOnOrange
#  define Console_MagentaOnOrange	GrApp_MagentaOnOrange
#  define Console_OliveOnOrange		GrApp_OliveOnOrange
#  define Console_WhiteOnOrange		GrApp_WhiteOnOrange
#  define Console_GrayOnOrange		GrApp_GrayOnOrange
#  define Console_LBlueOnOrange		GrApp_LBlueOnOrange
#  define Console_LGreenOnOrange	GrApp_LGreenOnOrange
#  define Console_LCyanOnOrange		GrApp_LCyanOnOrange
#  define Console_LRedOnOrange		GrApp_LRedOnOrange
#  define Console_LMagentaOnOrange	GrApp_LMagentaOnOrange
#  define Console_YellowOnOrange	GrApp_YellowOnOrange
#  define Console_LWhiteOnOrange	GrApp_LWhiteOnOrange
#  define Console_OrangeOnOrange	GrApp_OrangeOnOrange

#else

#  define Console_Black		0
#  define Console_Blue		1
#  define Console_Green		2
#  define Console_Cyan		(Console_Green + Console_Blue)
#  define Console_Red		4
#  define Console_Magenta		(Console_Red + Console_Blue)
#  define Console_Olive		(Console_Red + Console_Green)
#  define Console_White		(Console_Red + Console_Green + Console_Blue)
#  define Console_Light		8
#  define Console_Gray		(Console_Light + Console_Black)
#  define Console_LightBlue	(Console_Light + Console_Blue)
#  define Console_LightGreen	(Console_Light + Console_Green)
#  define Console_LightCyan	(Console_Light + Console_Cyan)
#  define Console_LightRed	(Console_Light + Console_Red)
#  define Console_LightMagenta	(Console_Light + Console_Magenta)
#  define Console_Yellow	(Console_Light + Console_Olive)
#  define Console_LightWhite	(Console_Light + Console_White)
#  define Console_Orange	Console_LightRed

#  define Console_BlackOnBlack		((Console_Black << 4) + Console_Black)
#  define Console_BlueOnBlack		((Console_Black << 4) + Console_Blue)
#  define Console_GreenOnBlack		((Console_Black << 4) + Console_Green)
#  define Console_CyanOnBlack		((Console_Black << 4) + Console_Cyan)
#  define Console_RedOnBlack		((Console_Black << 4) + Console_Red)
#  define Console_MagentaOnBlack		((Console_Black << 4) + Console_Magenta)
#  define Console_OliveOnBlack		((Console_Black << 4) + Console_Olive)
#  define Console_WhiteOnBlack		((Console_Black << 4) + Console_White)
#  define Console_GrayOnBlack		((Console_Black << 4) + Console_Gray)
#  define Console_LBlueOnBlack		((Console_Black << 4) + Console_LightBlue)
#  define Console_LGreenOnBlack		((Console_Black << 4) + Console_LightGreen)
#  define Console_LCyanOnBlack		((Console_Black << 4) + Console_LightCyan)
#  define Console_LRedOnBlack		((Console_Black << 4) + Console_LightRed)
#  define Console_LMagentaOnBlack		((Console_Black << 4) + Console_LightMagenta)
#  define Console_YellowOnBlack		((Console_Black << 4) + Console_Yellow)
#  define Console_LWhiteOnBlack		((Console_Black << 4) + Console_LightWhite)

#  define Console_BlackOnBlue		((Console_Blue << 4) + Console_Black)
#  define Console_BlueOnBlue		((Console_Blue << 4) + Console_Blue)
#  define Console_GreenOnBlue		((Console_Blue << 4) + Console_Green)
#  define Console_CyanOnBlue		((Console_Blue << 4) + Console_Cyan)
#  define Console_RedOnBlue		((Console_Blue << 4) + Console_Red)
#  define Console_MagentaOnBlue		((Console_Blue << 4) + Console_Magenta)
#  define Console_OliveOnBlue		((Console_Blue << 4) + Console_Olive)
#  define Console_WhiteOnBlue		((Console_Blue << 4) + Console_White)
#  define Console_GrayOnBlue		((Console_Blue << 4) + Console_Gray)
#  define Console_LBlueOnBlue		((Console_Blue << 4) + Console_LightBlue)
#  define Console_LGreenOnBlue		((Console_Blue << 4) + Console_LightGreen)
#  define Console_LCyanOnBlue		((Console_Blue << 4) + Console_LightCyan)
#  define Console_LRedOnBlue		((Console_Blue << 4) + Console_LightRed)
#  define Console_LMagentaOnBlue		((Console_Blue << 4) + Console_LightMagenta)
#  define Console_YellowOnBlue		((Console_Blue << 4) + Console_Yellow)
#  define Console_LWhiteOnBlue		((Console_Blue << 4) + Console_LightWhite)

#  define Console_BlackOnGreen		((Console_Green << 4) + Console_Black)
#  define Console_BlueOnGreen		((Console_Green << 4) + Console_Blue)
#  define Console_GreenOnGreen		((Console_Green << 4) + Console_Green)
#  define Console_CyanOnGreen		((Console_Green << 4) + Console_Cyan)
#  define Console_RedOnGreen		((Console_Green << 4) + Console_Red)
#  define Console_MagentaOnGreen		((Console_Green << 4) + Console_Magenta)
#  define Console_OliveOnGreen		((Console_Green << 4) + Console_Olive)
#  define Console_WhiteOnGreen		((Console_Green << 4) + Console_White)
#  define Console_GrayOnGreen		((Console_Green << 4) + Console_Gray)
#  define Console_LBlueOnGreen		((Console_Green << 4) + Console_LightBlue)
#  define Console_LGreenOnGreen		((Console_Green << 4) + Console_LightGreen)
#  define Console_LCyanOnGreen		((Console_Green << 4) + Console_LightCyan)
#  define Console_LRedOnGreen		((Console_Green << 4) + Console_LightRed)
#  define Console_LMagentaOnGreen		((Console_Green << 4) + Console_LightMagenta)
#  define Console_YellowOnGreen		((Console_Green << 4) + Console_Yellow)
#  define Console_LWhiteOnGreen		((Console_Green << 4) + Console_LightWhite)

#  define Console_BlackOnCyan		((Console_Cyan << 4) + Console_Black)
#  define Console_BlueOnCyan		((Console_Cyan << 4) + Console_Blue)
#  define Console_GreenOnCyan		((Console_Cyan << 4) + Console_Green)
#  define Console_CyanOnCyan		((Console_Cyan << 4) + Console_Cyan)
#  define Console_RedOnCyan		((Console_Cyan << 4) + Console_Red)
#  define Console_MagentaOnCyan		((Console_Cyan << 4) + Console_Magenta)
#  define Console_OliveOnCyan		((Console_Cyan << 4) + Console_Olive)
#  define Console_WhiteOnCyan		((Console_Cyan << 4) + Console_White)
#  define Console_GrayOnCyan		((Console_Cyan << 4) + Console_Gray)
#  define Console_LBlueOnCyan		((Console_Cyan << 4) + Console_LightBlue)
#  define Console_LGreenOnCyan		((Console_Cyan << 4) + Console_LightGreen)
#  define Console_LCyanOnCyan		((Console_Cyan << 4) + Console_LightCyan)
#  define Console_LRedOnCyan		((Console_Cyan << 4) + Console_LightRed)
#  define Console_LMagentaOnCyan		((Console_Cyan << 4) + Console_LightMagenta)
#  define Console_YellowOnCyan		((Console_Cyan << 4) + Console_Yellow)
#  define Console_LWhiteOnCyan		((Console_Cyan << 4) + Console_LightWhite)

#  define Console_BlackOnRed		((Console_Red << 4) + Console_Black)
#  define Console_BlueOnRed		((Console_Red << 4) + Console_Blue)
#  define Console_GreenOnRed		((Console_Red << 4) + Console_Green)
#  define Console_CyanOnRed		((Console_Red << 4) + Console_Cyan)
#  define Console_RedOnRed		((Console_Red << 4) + Console_Red)
#  define Console_MagentaOnRed		((Console_Red << 4) + Console_Magenta)
#  define Console_OliveOnRed		((Console_Red << 4) + Console_Olive)
#  define Console_WhiteOnRed		((Console_Red << 4) + Console_White)
#  define Console_GrayOnRed		((Console_Red << 4) + Console_Gray)
#  define Console_LBlueOnRed		((Console_Red << 4) + Console_LightBlue)
#  define Console_LGreenOnRed		((Console_Red << 4) + Console_LightGreen)
#  define Console_LCyanOnRed		((Console_Red << 4) + Console_LightCyan)
#  define Console_LRedOnRed		((Console_Red << 4) + Console_LightRed)
#  define Console_LMagentaOnRed		((Console_Red << 4) + Console_LightMagenta)
#  define Console_YellowOnRed		((Console_Red << 4) + Console_Yellow)
#  define Console_LWhiteOnRed		((Console_Red << 4) + Console_LightWhite)

#  define Console_BlackOnMagenta		((Console_Magenta << 4) + Console_Black)
#  define Console_BlueOnMagenta		((Console_Magenta << 4) + Console_Blue)
#  define Console_GreenOnMagenta		((Console_Magenta << 4) + Console_Green)
#  define Console_CyanOnMagenta		((Console_Magenta << 4) + Console_Cyan)
#  define Console_RedOnMagenta		((Console_Magenta << 4) + Console_Red)
#  define Console_MagentaOnMagenta	((Console_Magenta << 4) + Console_Magenta)
#  define Console_OliveOnMagenta		((Console_Magenta << 4) + Console_Olive)
#  define Console_WhiteOnMagenta		((Console_Magenta << 4) + Console_White)
#  define Console_GrayOnMagenta		((Console_Magenta << 4) + Console_Gray)
#  define Console_LBlueOnMagenta		((Console_Magenta << 4) + Console_LightBlue)
#  define Console_LGreenOnMagenta		((Console_Magenta << 4) + Console_LightGreen)
#  define Console_LCyanOnMagenta		((Console_Magenta << 4) + Console_LightCyan)
#  define Console_LRedOnMagenta		((Console_Magenta << 4) + Console_LightRed)
#  define Console_LMagentaOnMagenta	((Console_Magenta << 4) + Console_LightMagenta)
#  define Console_YellowOnMagenta		((Console_Magenta << 4) + Console_Yellow)
#  define Console_LWhiteOnMagenta		((Console_Magenta << 4) + Console_LightWhite)

#  define Console_BlackOnOlive		((Console_Olive << 4) + Console_Black)
#  define Console_BlueOnOlive		((Console_Olive << 4) + Console_Blue)
#  define Console_GreenOnOlive		((Console_Olive << 4) + Console_Green)
#  define Console_CyanOnOlive		((Console_Olive << 4) + Console_Cyan)
#  define Console_RedOnOlive		((Console_Olive << 4) + Console_Red)
#  define Console_MagentaOnOlive		((Console_Olive << 4) + Console_Magenta)
#  define Console_OliveOnOlive		((Console_Olive << 4) + Console_Olive)
#  define Console_WhiteOnOlive		((Console_Olive << 4) + Console_White)
#  define Console_GrayOnOlive		((Console_Olive << 4) + Console_Gray)
#  define Console_LBlueOnOlive		((Console_Olive << 4) + Console_LightBlue)
#  define Console_LGreenOnOlive		((Console_Olive << 4) + Console_LightGreen)
#  define Console_LCyanOnOlive		((Console_Olive << 4) + Console_LightCyan)
#  define Console_LRedOnOlive		((Console_Olive << 4) + Console_LightRed)
#  define Console_LMagentaOnOlive		((Console_Olive << 4) + Console_LightMagenta)
#  define Console_YellowOnOlive		((Console_Olive << 4) + Console_Yellow)
#  define Console_LWhiteOnOlive		((Console_Olive << 4) + Console_LightWhite)

#  define Console_BlackOnWhite		((Console_White << 4) + Console_Black)
#  define Console_BlueOnWhite		((Console_White << 4) + Console_Blue)
#  define Console_GreenOnWhite		((Console_White << 4) + Console_Green)
#  define Console_CyanOnWhite		((Console_White << 4) + Console_Cyan)
#  define Console_RedOnWhite		((Console_White << 4) + Console_Red)
#  define Console_MagentaOnWhite		((Console_White << 4) + Console_Magenta)
#  define Console_OliveOnWhite		((Console_White << 4) + Console_Olive)
#  define Console_WhiteOnWhite		((Console_White << 4) + Console_White)
#  define Console_GrayOnWhite		((Console_White << 4) + Console_Gray)
#  define Console_LBlueOnWhite		((Console_White << 4) + Console_LightBlue)
#  define Console_LGreenOnWhite		((Console_White << 4) + Console_LightGreen)
#  define Console_LCyanOnWhite		((Console_White << 4) + Console_LightCyan)
#  define Console_LRedOnWhite		((Console_White << 4) + Console_LightRed)
#  define Console_LMagentaOnWhite		((Console_White << 4) + Console_LightMagenta)
#  define Console_YellowOnWhite		((Console_White << 4) + Console_Yellow)
#  define Console_LWhiteOnWhite		((Console_White << 4) + Console_LightWhite)

#  define Console_BlackOnGray		((Console_Gray << 4) + Console_Black)
#  define Console_BlueOnGray		((Console_Gray << 4) + Console_Blue)
#  define Console_GreenOnGray		((Console_Gray << 4) + Console_Green)
#  define Console_CyanOnGray		((Console_Gray << 4) + Console_Cyan)
#  define Console_RedOnGray		((Console_Gray << 4) + Console_Red)
#  define Console_MagentaOnGray		((Console_Gray << 4) + Console_Magenta)
#  define Console_OliveOnGray		((Console_Gray << 4) + Console_Olive)
#  define Console_WhiteOnGray		((Console_Gray << 4) + Console_White)
#  define Console_GrayOnGray		((Console_Gray << 4) + Console_Gray)
#  define Console_LBlueOnGray		((Console_Gray << 4) + Console_LightBlue)
#  define Console_LGreenOnGray		((Console_Gray << 4) + Console_LightGreen)
#  define Console_LCyanOnGray		((Console_Gray << 4) + Console_LightCyan)
#  define Console_LRedOnGray		((Console_Gray << 4) + Console_LightRed)
#  define Console_LMagentaOnGray		((Console_Gray << 4) + Console_LightMagenta)
#  define Console_YellowOnGray		((Console_Gray << 4) + Console_Yellow)
#  define Console_LWhiteOnGray		((Console_Gray << 4) + Console_LightWhite)

#  define Console_BlackOnLBlue		((Console_LightBlue << 4) + Console_Black)
#  define Console_BlueOnLBlue		((Console_LightBlue << 4) + Console_Blue)
#  define Console_GreenOnLBlue		((Console_LightBlue << 4) + Console_Green)
#  define Console_CyanOnLBlue		((Console_LightBlue << 4) + Console_Cyan)
#  define Console_RedOnLBlue		((Console_LightBlue << 4) + Console_Red)
#  define Console_MagentaOnLBlue		((Console_LightBlue << 4) + Console_Magenta)
#  define Console_OliveOnLBlue		((Console_LightBlue << 4) + Console_Olive)
#  define Console_WhiteOnLBlue		((Console_LightBlue << 4) + Console_White)
#  define Console_GrayOnLBlue		((Console_LightBlue << 4) + Console_Gray)
#  define Console_LBlueOnLBlue		((Console_LightBlue << 4) + Console_LightBlue)
#  define Console_LGreenOnLBlue		((Console_LightBlue << 4) + Console_LightGreen)
#  define Console_LCyanOnLBlue		((Console_LightBlue << 4) + Console_LightCyan)
#  define Console_LRedOnLBlue		((Console_LightBlue << 4) + Console_LightRed)
#  define Console_LMagentaOnLBlue		((Console_LightBlue << 4) + Console_LightMagenta)
#  define Console_YellowOnLBlue		((Console_LightBlue << 4) + Console_Yellow)
#  define Console_LWhiteOnLBlue		((Console_LightBlue << 4) + Console_LightWhite)

#  define Console_BlackOnLGreen		((Console_LightGreen << 4) + Console_Black)
#  define Console_BlueOnLGreen		((Console_LightGreen << 4) + Console_Blue)
#  define Console_GreenOnLGreen		((Console_LightGreen << 4) + Console_Green)
#  define Console_CyanOnLGreen		((Console_LightGreen << 4) + Console_Cyan)
#  define Console_RedOnLGreen		((Console_LightGreen << 4) + Console_Red)
#  define Console_MagentaOnLGreen		((Console_LightGreen << 4) + Console_Magenta)
#  define Console_OliveOnLGreen		((Console_LightGreen << 4) + Console_Olive)
#  define Console_WhiteOnLGreen		((Console_LightGreen << 4) + Console_White)
#  define Console_GrayOnLGreen		((Console_LightGreen << 4) + Console_Gray)
#  define Console_LBlueOnLGreen		((Console_LightGreen << 4) + Console_LightBlue)
#  define Console_LGreenOnLGreen		((Console_LightGreen << 4) + Console_LightGreen)
#  define Console_LCyanOnLGreen		((Console_LightGreen << 4) + Console_LightCyan)
#  define Console_LRedOnLGreen		((Console_LightGreen << 4) + Console_LightRed)
#  define Console_LMagentaOnLGreen	((Console_LightGreen << 4) + Console_LightMagenta)
#  define Console_YellowOnLGreen		((Console_LightGreen << 4) + Console_Yellow)
#  define Console_LWhiteOnLGreen		((Console_LightGreen << 4) + Console_LightWhite)

#  define Console_BlackOnLCyan		((Console_LightCyan << 4) + Console_Black)
#  define Console_BlueOnLCyan		((Console_LightCyan << 4) + Console_Blue)
#  define Console_GreenOnLCyan		((Console_LightCyan << 4) + Console_Green)
#  define Console_CyanOnLCyan		((Console_LightCyan << 4) + Console_Cyan)
#  define Console_RedOnLCyan		((Console_LightCyan << 4) + Console_Red)
#  define Console_MagentaOnLCyan		((Console_LightCyan << 4) + Console_Magenta)
#  define Console_OliveOnLCyan		((Console_LightCyan << 4) + Console_Olive)
#  define Console_WhiteOnLCyan		((Console_LightCyan << 4) + Console_White)
#  define Console_GrayOnLCyan		((Console_LightCyan << 4) + Console_Gray)
#  define Console_LBlueOnLCyan		((Console_LightCyan << 4) + Console_LightBlue)
#  define Console_LGreenOnLCyan		((Console_LightCyan << 4) + Console_LightGreen)
#  define Console_LCyanOnLCyan		((Console_LightCyan << 4) + Console_LightCyan)
#  define Console_LRedOnLCyan		((Console_LightCyan << 4) + Console_LightRed)
#  define Console_LMagentaOnLCyan		((Console_LightCyan << 4) + Console_LightMagenta)
#  define Console_YellowOnLCyan		((Console_LightCyan << 4) + Console_Yellow)
#  define Console_LWhiteOnLCyan		((Console_LightCyan << 4) + Console_LightWhite)

#  define Console_BlackOnLRed		((Console_LightRed << 4) + Console_Black)
#  define Console_BlueOnLRed		((Console_LightRed << 4) + Console_Blue)
#  define Console_GreenOnLRed		((Console_LightRed << 4) + Console_Green)
#  define Console_CyanOnLRed		((Console_LightRed << 4) + Console_Cyan)
#  define Console_RedOnLRed		((Console_LightRed << 4) + Console_Red)
#  define Console_MagentaOnLRed		((Console_LightRed << 4) + Console_Magenta)
#  define Console_OliveOnLRed		((Console_LightRed << 4) + Console_Olive)
#  define Console_WhiteOnLRed		((Console_LightRed << 4) + Console_White)
#  define Console_GrayOnLRed		((Console_LightRed << 4) + Console_Gray)
#  define Console_LBlueOnLRed		((Console_LightRed << 4) + Console_LightBlue)
#  define Console_LGreenOnLRed		((Console_LightRed << 4) + Console_LightGreen)
#  define Console_LCyanOnLRed		((Console_LightRed << 4) + Console_LightCyan)
#  define Console_LRedOnLRed		((Console_LightRed << 4) + Console_LightRed)
#  define Console_LMagentaOnLRed		((Console_LightRed << 4) + Console_LightMagenta)
#  define Console_YellowOnLRed		((Console_LightRed << 4) + Console_Yellow)
#  define Console_LWhiteOnLRed		((Console_LightRed << 4) + Console_LightWhite)

#  define Console_BlackOnLMagenta		((Console_LightMagenta << 4) + Console_Black)
#  define Console_BlueOnLMagenta		((Console_LightMagenta << 4) + Console_Blue)
#  define Console_GreenOnLMagenta		((Console_LightMagenta << 4) + Console_Green)
#  define Console_CyanOnLMagenta		((Console_LightMagenta << 4) + Console_Cyan)
#  define Console_RedOnLMagenta		((Console_LightMagenta << 4) + Console_Red)
#  define Console_MagentaOnLMagenta	((Console_LightMagenta << 4) + Console_Magenta)
#  define Console_OliveOnLMagenta		((Console_LightMagenta << 4) + Console_Olive)
#  define Console_WhiteOnLMagenta		((Console_LightMagenta << 4) + Console_White)
#  define Console_GrayOnLMagenta		((Console_LightMagenta << 4) + Console_Gray)
#  define Console_LBlueOnLMagenta		((Console_LightMagenta << 4) + Console_LightBlue)
#  define Console_LGreenOnLMagenta	((Console_LightMagenta << 4) + Console_LightGreen)
#  define Console_LCyanOnLMagenta		((Console_LightMagenta << 4) + Console_LightCyan)
#  define Console_LRedOnLMagenta		((Console_LightMagenta << 4) + Console_LightRed)
#  define Console_LMagentaOnLMagenta	((Console_LightMagenta << 4) + Console_LightMagenta)
#  define Console_YellowOnLMagenta	((Console_LightMagenta << 4) + Console_Yellow)
#  define Console_LWhiteOnLMagenta	((Console_LightMagenta << 4) + Console_LightWhite)

#  define Console_BlackOnYellow		((Console_Yellow << 4) + Console_Black)
#  define Console_BlueOnYellow		((Console_Yellow << 4) + Console_Blue)
#  define Console_GreenOnYellow		((Console_Yellow << 4) + Console_Green)
#  define Console_CyanOnYellow		((Console_Yellow << 4) + Console_Cyan)
#  define Console_RedOnYellow		((Console_Yellow << 4) + Console_Red)
#  define Console_MagentaOnYellow		((Console_Yellow << 4) + Console_Magenta)
#  define Console_OliveOnYellow		((Console_Yellow << 4) + Console_Olive)
#  define Console_WhiteOnYellow		((Console_Yellow << 4) + Console_White)
#  define Console_GrayOnYellow		((Console_Yellow << 4) + Console_Gray)
#  define Console_LBlueOnYellow		((Console_Yellow << 4) + Console_LightBlue)
#  define Console_LGreenOnYellow		((Console_Yellow << 4) + Console_LightGreen)
#  define Console_LCyanOnYellow		((Console_Yellow << 4) + Console_LightCyan)
#  define Console_LRedOnYellow		((Console_Yellow << 4) + Console_LightRed)
#  define Console_LMagentaOnYellow	((Console_Yellow << 4) + Console_LightMagenta)
#  define Console_YellowOnYellow		((Console_Yellow << 4) + Console_Yellow)
#  define Console_LWhiteOnYellow		((Console_Yellow << 4) + Console_LightWhite)

#  define Console_BlackOnLWhite		((Console_LightWhite << 4) + Console_Black)
#  define Console_BlueOnLWhite		((Console_LightWhite << 4) + Console_Blue)
#  define Console_GreenOnLWhite		((Console_LightWhite << 4) + Console_Green)
#  define Console_CyanOnLWhite		((Console_LightWhite << 4) + Console_Cyan)
#  define Console_RedOnLWhite		((Console_LightWhite << 4) + Console_Red)
#  define Console_MagentaOnLWhite		((Console_LightWhite << 4) + Console_Magenta)
#  define Console_OliveOnLWhite		((Console_LightWhite << 4) + Console_Olive)
#  define Console_WhiteOnLWhite		((Console_LightWhite << 4) + Console_White)
#  define Console_GrayOnLWhite		((Console_LightWhite << 4) + Console_Gray)
#  define Console_LBlueOnLWhite		((Console_LightWhite << 4) + Console_LightBlue)
#  define Console_LGreenOnLWhite		((Console_LightWhite << 4) + Console_LightGreen)
#  define Console_LCyanOnLWhite		((Console_LightWhite << 4) + Console_LightCyan)
#  define Console_LRedOnLWhite		((Console_LightWhite << 4) + Console_LightRed)
#  define Console_LMagentaOnLWhite	((Console_LightWhite << 4) + Console_LightMagenta)
#  define Console_YellowOnLWhite		((Console_LightWhite << 4) + Console_Yellow)
#  define Console_LWhiteOnLWhite		((LightWhite << 4) + Console_LightWhite)

#endif //OUTPUT_SDL


#define WriteStr	Console_WriteStr
#define SetColors	Console_SetColors


#endif //__Console_h
