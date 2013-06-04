#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "Cons_Cfg.h"

/* StdIO */
import void Console_WriteCh_StdIO (CHAR ch);
import void Console_WriteInt_StdIO (LONGINT n);
import void Console_WriteLn_StdIO (void);
import void Console_WriteStr_StdIO (CHAR *str);
import void Console_WriteStrLn_StdIO (CHAR *str);
/* DIRECT */
import void Console_At_DIRECT (INTEGER x, INTEGER y);
import void Console_WriteLn_DIRECT (void);
import void Console_WriteStr_DIRECT (CHAR *str);
import void Console_WriteStrLn_DIRECT (CHAR *str);
import void Console_SetColors_DIRECT (INTEGER colors);

#define Console()

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

/* DIRECT */
#ifdef OUTPUT_DIRECT

#  define Console_At	Console_At_DIRECT
#  define Console_WriteCh(ch)	printf("%c", ch)
#  define Console_WriteInt(i)	printf("%ld", i)
#  define Console_WriteLn Console_WriteLn_DIRECT
#  define Console_WriteStr(str, str__len)	Console_WriteStr_DIRECT(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_DIRECT(str)
#  define Console_SetColors	Console_SetColors_DIRECT

#endif OUTPUT_DIRECT


#define WriteStr	Console_WriteStr
#define SetColors	Console_SetColors

#endif __Console_h
