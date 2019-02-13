#ifndef Console__h
#define Console__h

#include "ConsoleCfg.h"
#include "SYSTEM.h"


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

#ifdef OUTPUT_StdIO
   extern void ConsoleStdIO_WriteCh (char ch);
   extern void ConsoleStdIO_WriteLn (void);
   extern void ConsoleStdIO_WriteLong (LONGINT n);
   extern void ConsoleStdIO_WriteInt (int n);
   extern void ConsoleStdIO_WriteReal (double x);
   extern void ConsoleStdIO_WriteRealFix (double x, int n);
   extern void ConsoleStdIO_WriteStr (char *str, int str__len);
   
#  define Console_SetColors(colors)
#  define Console_WriteCh ConsoleStdIO_WriteCh
#  define Console_WriteInt ConsoleStdIO_WriteInt
#  define Console_WriteLn ConsoleStdIO_WriteLn
#  define Console_WriteLong ConsoleStdIO_WriteLong
#  define Console_WriteReal ConsoleStdIO_WriteReal
#  define Console_WriteRealFix ConsoleStdIO_WriteRealFix
#  define Console_WriteShort ConsoleStdIO_WriteInt
#  define Console_WriteStr ConsoleStdIO_WriteStr

#  define Console__init()
#endif

#ifdef OUTPUT_WinAPI
   extern void ConsoleWinAPI_SetColors (short int colors);
   extern void ConsoleWinAPI_WriteCh (char ch);
   extern void ConsoleWinAPI_WriteInt (int n);
   extern void ConsoleWinAPI_WriteLn (void);
   extern void ConsoleWinAPI_WriteLong (LONGINT n);
   extern void ConsoleWinAPI_WriteReal (double x);
   extern void ConsoleWinAPI_WriteRealFix (double x, int n);
   extern void ConsoleWinAPI_WriteStr (char *str, int str__len);
   extern void *ConsoleWinAPI__init (void);
   
#  define Console_SetColors ConsoleWinAPI_SetColors
#  define Console_WriteCh ConsoleWinAPI_WriteCh
#  define Console_WriteInt ConsoleWinAPI_WriteInt
#  define Console_WriteLn ConsoleWinAPI_WriteLn
#  define Console_WriteLong ConsoleWinAPI_WriteLong
#  define Console_WriteReal ConsoleWinAPI_WriteReal
#  define Console_WriteRealFix ConsoleWinAPI_WriteRealFix
#  define Console_WriteShort ConsoleWinAPI_WriteInt
#  define Console_WriteStr ConsoleWinAPI_WriteStr

#  define Console__init ConsoleWinAPI__init
#endif


#endif //__Console_h
