#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "ConsoleCfg.h"

import void Console_WriteHex (INTEGER x);
import void Console_WriteIntWidth (INTEGER x, INTEGER n);

/* StdIO */
import void Console_WriteCh_StdIO (CHAR ch);
import void Console_WriteInt_StdIO (LONGINT n);
import void Console_WriteLn_StdIO (void);
import void Console_WriteStr_StdIO (CHAR *str);
import void Console_WriteStrLn_StdIO (CHAR *str);

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
#  define Console_Clear	GrConsole_Clear
#  define Console_SetColors	GrConsole_SetColors
#  define Console_SetFont	GrConsole_SetFont
#  define Console_WriteCh	GrConsole_WriteCh
#  define Console_WriteInt	GrConsole_WriteInt
#  define Console_WriteStr	GrConsole_WriteStr
#  define Console_WriteStrLn	GrConsole_WriteStrLn
#  define Console_WriteLn	GrConsole_WriteLn
#  define Console__init	GrConsole__init
#endif OUTPUT_SDL


#define WriteStr	Console_WriteStr
#define SetColors	Console_SetColors

#endif __Console_h
