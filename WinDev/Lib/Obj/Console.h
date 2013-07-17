/*  Ofront 1.2 -xtspkae */

#ifndef Console__h
#define Console__h

#include "SYSTEM.h"




import void Console_At (INTEGER x, INTEGER y);
import void Console_SetColors (INTEGER n);
import void Console_WriteCh (CHAR ch);
import void Console_WriteHex (INTEGER x);
import void Console_WriteInt (LONGINT n);
import void Console_WriteIntWidth (INTEGER x, INTEGER n);
import void Console_WriteLn (void);
import void Console_WriteStr (CHAR *str, LONGINT str__len);
import void Console_WriteStrLn (CHAR *str, LONGINT str__len);
import void *Console__init(void);


#endif
