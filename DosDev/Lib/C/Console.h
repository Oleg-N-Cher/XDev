#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "Cons_Cfg.h"

/* StdIO */
import void Console_At_StdIO (INTEGER x, INTEGER y);
import void Console_SetColors_StdIO (SYSTEM_BYTE colors);
import void Console_WriteCh_StdIO (CHAR ch);
import void Console_WriteInt_StdIO (LONGINT n);
import void Console_WriteLn_StdIO (void);
import void Console_WriteStr_StdIO (CHAR *str);
import void Console_WriteStrLn_StdIO (CHAR *str);

/* ConIO */
import void Console_At_ConIO (INTEGER x, INTEGER y);
import void Console_SetColors_ConIO (SYSTEM_BYTE colors);
import void Console_WriteCh_ConIO (CHAR ch);
import void Console_WriteInt_ConIO (LONGINT n);
import void Console_WriteLn_ConIO (void);
import void Console_WriteStr_ConIO (CHAR *str);
import void Console_WriteStrLn_ConIO (CHAR *str);

/* DIRECT */
import void Console_At_DIRECT (INTEGER x, INTEGER y);
import void Console_Clear_DIRECT (SYSTEM_BYTE colors);
import void Console_WriteLn_DIRECT (void);
import void Console_WriteStr_DIRECT (CHAR *str);
import void Console_WriteStrLn_DIRECT (CHAR *str);
import void Console_SetColors_DIRECT (SYSTEM_BYTE colors);

#define Console__init()

/* StdIO */
#ifdef OUTPUT_STDIO
#  define Console_At(x, y)	Console_At_StdIO(x + 1, y + 1)
#  define Console_SetColors	Console_SetColors_StdIO
#  define Console_WriteCh	Console_WriteCh_StdIO
#  define Console_WriteInt	Console_WriteInt_StdIO
#  define Console_WriteStr(str, str__len)	Console_WriteStr_StdIO(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_StdIO(str)
#  define Console_WriteLn	Console_WriteLn_StdIO
#endif OUTPUT_STDIO

/* ConIO */
#ifdef OUTPUT_CONIO
#  define Console_At(x, y)	Console_At_ConIO(x + 1, y + 1)
#  define Console_SetColors	Console_SetColors_ConIO
#  define Console_WriteCh	Console_WriteCh_ConIO
#  define Console_WriteInt	Console_WriteInt_ConIO
#  define Console_WriteStr(str, str__len) Console_WriteStr_ConIO(str)
#  define Console_WriteStrLn(str, str__len)	Console_WriteStrLn_ConIO(str)
#  define Console_WriteLn	Console_WriteLn_ConIO
#endif OUTPUT_CONIO

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

