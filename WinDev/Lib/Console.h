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
/* WinAPI */
import void Console_At_WinAPI (INTEGER x, INTEGER y);
import void Console_WriteLn_WinAPI (void);
import void Console_WriteStr_WinAPI (CHAR *str);
import void Console_SetColors_WinAPI (INTEGER colors);

#define Console__init()

/* StdIO */
#ifdef OUTPUT_STDIO

#  include <stdio.h>

#  define Console_SetColors(colors)
#  define Console_WriteCh	Console_WriteCh_StdIO
#  define Console_WriteInt	Console_WriteInt_StdIO
#  define Console_WriteStr(str, str__len)	Console_WriteStr_StdIO(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_StdIO(str)
#  define Console_WriteLn	Console_WriteLn_StdIO

#endif OUTPUT_STDIO

/* ConIO */
/*
#ifdef OUTPUT_CONIO

#  include <conio.h>

#  define Console_SetColors(colors)
#  define Console_WriteStr(str, str__len)	_cputs(str)

#endif OUTPUT_CONIO
*/

/* WinAPI */
#ifdef OUTPUT_WINAPI

#  define Console_At	Console_At_WinAPI
#  define Console_WriteCh(ch)	printf("%c", ch)
#  define Console_WriteInt(i)	printf("%ld", i)
#  define Console_WriteLn Console_WriteLn_WinAPI
#  define Console_WriteStr(str, str__len)	Console_WriteStr_WinAPI(str)
#  define Console_SetColors	Console_SetColors_WinAPI

#endif OUTPUT_WINAPI


#define WriteStr	Console_WriteStr
#define SetColors	Console_SetColors

#endif __Console_h
