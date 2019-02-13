/* Ofront+ 1.0 -sxt3 -48 */

#ifndef ConsoleWinAPI__h
#define ConsoleWinAPI__h

#include "SYSTEM.h"




import void ConsoleWinAPI_SetColors (SHORTINT colors);
import void ConsoleWinAPI_WriteCh (CHAR ch);
import void ConsoleWinAPI_WriteInt (INTEGER n);
import void ConsoleWinAPI_WriteLn (void);
import void ConsoleWinAPI_WriteLong (LONGINT n);
import void ConsoleWinAPI_WriteReal (REAL x);
import void ConsoleWinAPI_WriteRealFix (REAL x, INTEGER n);
import void ConsoleWinAPI_WriteStr (CHAR *str, INTEGER str__len);
import void *ConsoleWinAPI__init(void);


#endif
