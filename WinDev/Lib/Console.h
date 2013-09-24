#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "ConsoleCfg.h"

/* StdIO */
import void Console_WriteCh_StdIO (CHAR ch);
import void Console_WriteInt_StdIO (LONGINT n);
import void Console_WriteLn_StdIO (void);
import void Console_WriteStr_StdIO (CHAR *str);
import void Console_WriteStrLn_StdIO (CHAR *str);
import void Console_WriteIntWidth_StdIO (INTEGER x, INTEGER n);
import void Console_WriteHex_StdIO (INTEGER val);

/* WinAPI */
import void Console_At_WinAPI (INTEGER x, INTEGER y);
import void Console_WriteLn_WinAPI (void);
import void Console_WriteStr_WinAPI (CHAR *str);
import void Console_WriteStrLn_WinAPI (CHAR *str);
import void Console_SetColors_WinAPI (INTEGER colors);

/* StdIO */
#ifdef OUTPUT_STDIO
#  define Console_SetColors(colors)
#  define Console_WriteCh	Console_WriteCh_StdIO
#  define Console_WriteInt	Console_WriteInt_StdIO
#  define Console_WriteStr(str, str__len)	Console_WriteStr_StdIO(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_StdIO(str)
#  define Console_WriteLn	Console_WriteLn_StdIO
#  define Console_WriteIntWidth	Console_WriteIntWidth_StdIO
#  define Console_WriteHex	Console_WriteHex_StdIO
#  define Console__init()
#endif OUTPUT_STDIO

/* ConIO */
/*
#ifdef OUTPUT_CONIO
#  define Console_SetColors(colors)
#  define Console_WriteStr(str, str__len)	_cputs(str)
#  define Console__init()
#endif OUTPUT_CONIO
*/

/* WinAPI */
#ifdef OUTPUT_WINAPI
#  define Console_At	Console_At_WinAPI
#  define Console_WriteCh(ch)	printf("%c", ch)
#  define Console_WriteInt(i)	printf("%ld", i)
#  define Console_WriteLn Console_WriteLn_WinAPI
#  define Console_WriteStr(str, str__len)	Console_WriteStr_WinAPI(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_WinAPI(str)
#  define Console_SetColors	Console_SetColors_WinAPI
#  define Console__init()
#endif OUTPUT_WINAPI

/* SDL */
#ifdef OUTPUT_SDL
#  include "GrConsole.h"
#  include "GrColors.h"

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


#  define Console_Black		GrColors_Black
#  define Console_Blue		GrColors_Blue
#  define Console_Green		GrColors_Green
#  define Console_Cyan		GrColors_Cyan
#  define Console_Red		GrColors_Red
#  define Console_Magenta	GrColors_Magenta
#  define Console_Olive		GrColors_Olive
#  define Console_White		GrColors_White
#  define Console_Gray		GrColors_Gray
#  define Console_LightBlue	GrColors_LightBlue
#  define Console_LightGreen	GrColors_LightGreen
#  define Console_LightCyan	GrColors_LightCyan
#  define Console_LightRed	GrColors_LightRed
#  define Console_LightMagenta	GrColors_LightMagenta
#  define Console_Yellow	GrColors_Yellow
#  define Console_LightWhite	GrColors_LightWhite
#  define Console_Orange	GrColors_Orange

#  define Console_BlackOnBlack		GrColors_BlackOnBlack
#  define Console_BlueOnBlack		GrColors_BlueOnBlack
#  define Console_GreenOnBlack		GrColors_GreenOnBlack
#  define Console_CyanOnBlack		GrColors_CyanOnBlack
#  define Console_RedOnBlack		GrColors_RedOnBlack
#  define Console_MagentaOnBlack	GrColors_MagentaOnBlack
#  define Console_OliveOnBlack		GrColors_OliveOnBlack
#  define Console_WhiteOnBlack		GrColors_WhiteOnBlack
#  define Console_GrayOnBlack		GrColors_GrayOnBlack
#  define Console_LBlueOnBlack		GrColors_LBlueOnBlack
#  define Console_LGreenOnBlack		GrColors_LGreenOnBlack
#  define Console_LCyanOnBlack		GrColors_LCyanOnBlack
#  define Console_LRedOnBlack		GrColors_LRedOnBlack
#  define Console_LMagentaOnBlack	GrColors_LMagentaOnBlack
#  define Console_YellowOnBlack		GrColors_YellowOnBlack
#  define Console_LWhiteOnBlack		GrColors_LWhiteOnBlack
	
#  define Console_BlackOnBlue		GrColors_BlackOnBlue
#  define Console_BlueOnBlue		GrColors_BlueOnBlue
#  define Console_GreenOnBlue		GrColors_GreenOnBlue
#  define Console_CyanOnBlue		GrColors_CyanOnBlue
#  define Console_RedOnBlue		GrColors_RedOnBlue
#  define Console_MagentaOnBlue		GrColors_MagentaOnBlue
#  define Console_OliveOnBlue		GrColors_OliveOnBlue
#  define Console_WhiteOnBlue		GrColors_WhiteOnBlue
#  define Console_GrayOnBlue		GrColors_GrayOnBlue
#  define Console_LBlueOnBlue		GrColors_LBlueOnBlue
#  define Console_LGreenOnBlue		GrColors_LGreenOnBlue
#  define Console_LCyanOnBlue		GrColors_LCyanOnBlue
#  define Console_LRedOnBlue		GrColors_LRedOnBlue
#  define Console_LMagentaOnBlue	GrColors_LMagentaOnBlue
#  define Console_YellowOnBlue		GrColors_YellowOnBlue
#  define Console_LWhiteOnBlue		GrColors_LWhiteOnBlue
	
#  define Console_BlackOnGreen		GrColors_BlackOnGreen
#  define Console_BlueOnGreen		GrColors_BlueOnGreen
#  define Console_GreenOnGreen		GrColors_GreenOnGreen
#  define Console_CyanOnGreen		GrColors_CyanOnGreen
#  define Console_RedOnGreen		GrColors_RedOnGreen
#  define Console_MagentaOnGreen	GrColors_MagentaOnGreen
#  define Console_OliveOnGreen		GrColors_OliveOnGreen
#  define Console_WhiteOnGreen		GrColors_WhiteOnGreen
#  define Console_GrayOnGreen		GrColors_GrayOnGreen
#  define Console_LBlueOnGreen		GrColors_LBlueOnGreen
#  define Console_LGreenOnGreen		GrColors_LGreenOnGreen
#  define Console_LCyanOnGreen		GrColors_LCyanOnGreen
#  define Console_LRedOnGreen		GrColors_LRedOnGreen
#  define Console_LMagentaOnGreen	GrColors_LMagentaOnGreen
#  define Console_YellowOnGreen		GrColors_YellowOnGreen
#  define Console_LWhiteOnGreen		GrColors_LWhiteOnGreen
	
#  define Console_BlackOnCyan		GrColors_BlackOnCyan
#  define Console_BlueOnCyan		GrColors_BlueOnCyan
#  define Console_GreenOnCyan		GrColors_GreenOnCyan
#  define Console_CyanOnCyan		GrColors_CyanOnCyan
#  define Console_RedOnCyan		GrColors_RedOnCyan
#  define Console_MagentaOnCyan		GrColors_MagentaOnCyan
#  define Console_OliveOnCyan		GrColors_OliveOnCyan
#  define Console_WhiteOnCyan		GrColors_WhiteOnCyan
#  define Console_GrayOnCyan		GrColors_GrayOnCyan
#  define Console_LBlueOnCyan		GrColors_LBlueOnCyan
#  define Console_LGreenOnCyan		GrColors_LGreenOnCyan
#  define Console_LCyanOnCyan		GrColors_LCyanOnCyan
#  define Console_LRedOnCyan		GrColors_LRedOnCyan
#  define Console_LMagentaOnCyan	GrColors_LMagentaOnCyan
#  define Console_YellowOnCyan		GrColors_YellowOnCyan
#  define Console_LWhiteOnCyan		GrColors_LWhiteOnCyan
	
#  define Console_BlackOnRed		GrColors_BlackOnRed
#  define Console_BlueOnRed		GrColors_BlueOnRed
#  define Console_GreenOnRed		GrColors_GreenOnRed
#  define Console_CyanOnRed		GrColors_CyanOnRed
#  define Console_RedOnRed		GrColors_RedOnRed
#  define Console_MagentaOnRed		GrColors_MagentaOnRed
#  define Console_OliveOnRed		GrColors_OliveOnRed
#  define Console_WhiteOnRed		GrColors_WhiteOnRed
#  define Console_GrayOnRed		GrColors_GrayOnRed
#  define Console_LBlueOnRed		GrColors_LBlueOnRed
#  define Console_LGreenOnRed		GrColors_LGreenOnRed
#  define Console_LCyanOnRed		GrColors_LCyanOnRed
#  define Console_LRedOnRed		GrColors_LRedOnRed
#  define Console_LMagentaOnRed		GrColors_LMagentaOnRed
#  define Console_YellowOnRed		GrColors_YellowOnRed
#  define Console_LWhiteOnRed		GrColors_LWhiteOnRed
	
#  define Console_BlackOnMagenta	GrColors_BlackOnMagenta
#  define Console_BlueOnMagenta		GrColors_BlueOnMagenta
#  define Console_GreenOnMagenta	GrColors_GreenOnMagenta
#  define Console_CyanOnMagenta		GrColors_CyanOnMagenta
#  define Console_RedOnMagenta		GrColors_RedOnMagenta
#  define Console_MagentaOnMagenta	GrColors_MagentaOnMagenta
#  define Console_OliveOnMagenta	GrColors_OliveOnMagenta
#  define Console_WhiteOnMagenta	GrColors_WhiteOnMagenta
#  define Console_GrayOnMagenta		GrColors_GrayOnMagenta
#  define Console_LBlueOnMagenta	GrColors_LBlueOnMagenta
#  define Console_LGreenOnMagenta	GrColors_LGreenOnMagenta
#  define Console_LCyanOnMagenta	GrColors_LCyanOnMagenta
#  define Console_LRedOnMagenta		GrColors_LRedOnMagenta
#  define Console_LMagentaOnMagenta	GrColors_LMagentaOnMagenta
#  define Console_YellowOnMagenta	GrColors_YellowOnMagenta
#  define Console_LWhiteOnMagenta	GrColors_LWhiteOnMagenta
	
#  define Console_BlackOnOlive		GrColors_BlackOnOlive
#  define Console_BlueOnOlive		GrColors_BlueOnOlive
#  define Console_GreenOnOlive		GrColors_GreenOnOlive
#  define Console_CyanOnOlive		GrColors_CyanOnOlive
#  define Console_RedOnOlive		GrColors_RedOnOlive
#  define Console_MagentaOnOlive	GrColors_MagentaOnOlive
#  define Console_OliveOnOlive		GrColors_OliveOnOlive
#  define Console_WhiteOnOlive		GrColors_WhiteOnOlive
#  define Console_GrayOnOlive		GrColors_GrayOnOlive
#  define Console_LBlueOnOlive		GrColors_LBlueOnOlive
#  define Console_LGreenOnOlive		GrColors_LGreenOnOlive
#  define Console_LCyanOnOlive		GrColors_LCyanOnOlive
#  define Console_LRedOnOlive		GrColors_LRedOnOlive
#  define Console_LMagentaOnOlive	GrColors_LMagentaOnOlive
#  define Console_YellowOnOlive		GrColors_YellowOnOlive
#  define Console_LWhiteOnOlive		GrColors_LWhiteOnOlive
	
#  define Console_BlackOnWhite		GrColors_BlackOnWhite
#  define Console_BlueOnWhite		GrColors_BlueOnWhite
#  define Console_GreenOnWhite		GrColors_GreenOnWhite
#  define Console_CyanOnWhite		GrColors_CyanOnWhite
#  define Console_RedOnWhite		GrColors_RedOnWhite
#  define Console_MagentaOnWhite	GrColors_MagentaOnWhite
#  define Console_OliveOnWhite		GrColors_OliveOnWhite
#  define Console_WhiteOnWhite		GrColors_WhiteOnWhite
#  define Console_GrayOnWhite		GrColors_GrayOnWhite
#  define Console_LBlueOnWhite		GrColors_LBlueOnWhite
#  define Console_LGreenOnWhite		GrColors_LGreenOnWhite
#  define Console_LCyanOnWhite		GrColors_LCyanOnWhite
#  define Console_LRedOnWhite		GrColors_LRedOnWhite
#  define Console_LMagentaOnWhite	GrColors_LMagentaOnWhite
#  define Console_YellowOnWhite		GrColors_YellowOnWhite
#  define Console_LWhiteOnWhite		GrColors_LWhiteOnWhite
	
#  define Console_BlackOnGray		GrColors_BlackOnGray
#  define Console_BlueOnGray		GrColors_BlueOnGray
#  define Console_GreenOnGray		GrColors_GreenOnGray
#  define Console_CyanOnGray		GrColors_CyanOnGray
#  define Console_RedOnGray		GrColors_RedOnGray
#  define Console_MagentaOnGray		GrColors_MagentaOnGray
#  define Console_OliveOnGray		GrColors_OliveOnGray
#  define Console_WhiteOnGray		GrColors_WhiteOnGray
#  define Console_GrayOnGray		GrColors_GrayOnGray
#  define Console_LBlueOnGray		GrColors_LBlueOnGray
#  define Console_LGreenOnGray		GrColors_LGreenOnGray
#  define Console_LCyanOnGray		GrColors_LCyanOnGray
#  define Console_LRedOnGray		GrColors_LRedOnGray
#  define Console_LMagentaOnGray	GrColors_LMagentaOnGray
#  define Console_YellowOnGray		GrColors_YellowOnGray
#  define Console_LWhiteOnGray		GrColors_LWhiteOnGray
	
#  define Console_BlackOnLBlue		GrColors_BlackOnLBlue
#  define Console_BlueOnLBlue		GrColors_BlueOnLBlue
#  define Console_GreenOnLBlue		GrColors_GreenOnLBlue
#  define Console_CyanOnLBlue		GrColors_CyanOnLBlue
#  define Console_RedOnLBlue		GrColors_RedOnLBlue
#  define Console_MagentaOnLBlue	GrColors_MagentaOnLBlue
#  define Console_OliveOnLBlue		GrColors_OliveOnLBlue
#  define Console_WhiteOnLBlue		GrColors_WhiteOnLBlue
#  define Console_GrayOnLBlue		GrColors_GrayOnLBlue
#  define Console_LBlueOnLBlue		GrColors_LBlueOnLBlue
#  define Console_LGreenOnLBlue		GrColors_LGreenOnLBlue
#  define Console_LCyanOnLBlue		GrColors_LCyanOnLBlue
#  define Console_LRedOnLBlue		GrColors_LRedOnLBlue
#  define Console_LMagentaOnLBlue	GrColors_LMagentaOnLBlue
#  define Console_YellowOnLBlue		GrColors_YellowOnLBlue
#  define Console_LWhiteOnLBlue		GrColors_LWhiteOnLBlue
	
#  define Console_BlackOnLGreen		GrColors_BlackOnLGreen
#  define Console_BlueOnLGreen		GrColors_BlueOnLGreen
#  define Console_GreenOnLGreen		GrColors_GreenOnLGreen
#  define Console_CyanOnLGreen		GrColors_CyanOnLGreen
#  define Console_RedOnLGreen		GrColors_RedOnLGreen
#  define Console_MagentaOnLGreen	GrColors_MagentaOnLGreen
#  define Console_OliveOnLGreen		GrColors_OliveOnLGreen
#  define Console_WhiteOnLGreen		GrColors_WhiteOnLGreen
#  define Console_GrayOnLGreen		GrColors_GrayOnLGreen
#  define Console_LBlueOnLGreen		GrColors_LBlueOnLGreen
#  define Console_LGreenOnLGreen	GrColors_LGreenOnLGreen
#  define Console_LCyanOnLGreen		GrColors_LCyanOnLGreen
#  define Console_LRedOnLGreen		GrColors_LRedOnLGreen
#  define Console_LMagentaOnLGreen	GrColors_LMagentaOnLGreen
#  define Console_YellowOnLGreen	GrColors_YellowOnLGreen
#  define Console_LWhiteOnLGreen	GrColors_LWhiteOnLGreen
	
#  define Console_BlackOnLCyan		GrColors_BlackOnLCyan
#  define Console_BlueOnLCyan		GrColors_BlueOnLCyan
#  define Console_GreenOnLCyan		GrColors_GreenOnLCyan
#  define Console_CyanOnLCyan		GrColors_CyanOnLCyan
#  define Console_RedOnLCyan		GrColors_RedOnLCyan
#  define Console_MagentaOnLCyan	GrColors_MagentaOnLCyan
#  define Console_OliveOnLCyan		GrColors_OliveOnLCyan
#  define Console_WhiteOnLCyan		GrColors_WhiteOnLCyan
#  define Console_GrayOnLCyan		GrColors_GrayOnLCyan
#  define Console_LBlueOnLCyan		GrColors_LBlueOnLCyan
#  define Console_LGreenOnLCyan		GrColors_LGreenOnLCyan
#  define Console_LCyanOnLCyan		GrColors_LCyanOnLCyan
#  define Console_LRedOnLCyan		GrColors_LRedOnLCyan
#  define Console_LMagentaOnLCyan	GrColors_LMagentaOnLCyan
#  define Console_YellowOnLCyan		GrColors_YellowOnLCyan
#  define Console_LWhiteOnLCyan		GrColors_LWhiteOnLCyan
	
#  define Console_BlackOnLRed		GrColors_BlackOnLRed
#  define Console_BlueOnLRed		GrColors_BlueOnLRed
#  define Console_GreenOnLRed		GrColors_GreenOnLRed
#  define Console_CyanOnLRed		GrColors_CyanOnLRed
#  define Console_RedOnLRed		GrColors_RedOnLRed
#  define Console_MagentaOnLRed		GrColors_MagentaOnLRed
#  define Console_OliveOnLRed		GrColors_OliveOnLRed
#  define Console_WhiteOnLRed		GrColors_WhiteOnLRed
#  define Console_GrayOnLRed		GrColors_GrayOnLRed
#  define Console_LBlueOnLRed		GrColors_LBlueOnLRed
#  define Console_LGreenOnLRed		GrColors_LGreenOnLRed
#  define Console_LCyanOnLRed		GrColors_LCyanOnLRed
#  define Console_LRedOnLRed		GrColors_LRedOnLRed
#  define Console_LMagentaOnLRed	GrColors_LMagentaOnLRed
#  define Console_YellowOnLRed		GrColors_YellowOnLRed
#  define Console_LWhiteOnLRed		GrColors_LWhiteOnLRed
	
#  define Console_BlackOnLMagenta	GrColors_BlackOnLMagenta
#  define Console_BlueOnLMagenta	GrColors_BlueOnLMagenta
#  define Console_GreenOnLMagenta	GrColors_GreenOnLMagenta
#  define Console_CyanOnLMagenta	GrColors_CyanOnLMagenta
#  define Console_RedOnLMagenta		GrColors_RedOnLMagenta
#  define Console_MagentaOnLMagenta	GrColors_MagentaOnLMagenta
#  define Console_OliveOnLMagenta	GrColors_OliveOnLMagenta
#  define Console_WhiteOnLMagenta	GrColors_WhiteOnLMagenta
#  define Console_GrayOnLMagenta	GrColors_GrayOnLMagenta
#  define Console_LBlueOnLMagenta	GrColors_LBlueOnLMagenta
#  define Console_LGreenOnLMagenta	GrColors_LGreenOnLMagenta
#  define Console_LCyanOnLMagenta	GrColors_LCyanOnLMagenta
#  define Console_LRedOnLMagenta	GrColors_LRedOnLMagenta
#  define Console_LMagentaOnLMagenta	GrColors_LMagentaOnLMagenta
#  define Console_YellowOnLMagenta	GrColors_YellowOnLMagenta
#  define Console_LWhiteOnLMagenta	GrColors_LWhiteOnLMagenta
	
#  define Console_BlackOnYellow		GrColors_BlackOnYellow
#  define Console_BlueOnYellow		GrColors_BlueOnYellow
#  define Console_GreenOnYellow		GrColors_GreenOnYellow
#  define Console_CyanOnYellow		GrColors_CyanOnYellow
#  define Console_RedOnYellow		GrColors_RedOnYellow
#  define Console_MagentaOnYellow	GrColors_MagentaOnYellow
#  define Console_OliveOnYellow		GrColors_OliveOnYellow
#  define Console_WhiteOnYellow		GrColors_WhiteOnYellow
#  define Console_GrayOnYellow		GrColors_GrayOnYellow
#  define Console_LBlueOnYellow		GrColors_LBlueOnYellow
#  define Console_LGreenOnYellow	GrColors_LGreenOnYellow
#  define Console_LCyanOnYellow		GrColors_LCyanOnYellow
#  define Console_LRedOnYellow		GrColors_LRedOnYellow
#  define Console_LMagentaOnYellow	GrColors_LMagentaOnYellow
#  define Console_YellowOnYellow	GrColors_YellowOnYellow
#  define Console_LWhiteOnYellow	GrColors_LWhiteOnYellow
	
#  define Console_BlackOnLWhite		GrColors_BlackOnLWhite
#  define Console_BlueOnLWhite		GrColors_BlueOnLWhite
#  define Console_GreenOnLWhite		GrColors_GreenOnLWhite
#  define Console_CyanOnLWhite		GrColors_CyanOnLWhite
#  define Console_RedOnLWhite		GrColors_RedOnLWhite
#  define Console_MagentaOnLWhite	GrColors_MagentaOnLWhite
#  define Console_OliveOnLWhite		GrColors_OliveOnLWhite
#  define Console_WhiteOnLWhite		GrColors_WhiteOnLWhite
#  define Console_GrayOnLWhite		GrColors_GrayOnLWhite
#  define Console_LBlueOnLWhite		GrColors_LBlueOnLWhite
#  define Console_LGreenOnLWhite	GrColors_LGreenOnLWhite
#  define Console_LCyanOnLWhite		GrColors_LCyanOnLWhite
#  define Console_LRedOnLWhite		GrColors_LRedOnLWhite
#  define Console_LMagentaOnLWhite	GrColors_LMagentaOnLWhite
#  define Console_YellowOnLWhite	GrColors_YellowOnLWhite
#  define Console_LWhiteOnLWhite	GrColors_LWhiteOnLWhite

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
#  define Console_Yellow		(Console_Light + Console_Olive)
#  define Console_LightWhite	(Console_Light + Console_White)

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

#endif OUTPUT_SDL


#define WriteStr	Console_WriteStr
#define SetColors	Console_SetColors


#endif __Console_h
