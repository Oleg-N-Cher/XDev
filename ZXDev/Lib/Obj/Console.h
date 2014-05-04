/*  Ofront 1.2 -xtspkae */

#ifndef Console__h
#define Console__h

#include "SYSTEM.h"




import void Console_At (INTEGER x, INTEGER y);
import void Console_Clear (INTEGER attr);
import INTEGER Console_ReadInt (void);
import INTEGER Console_ReadIntRange (INTEGER min, INTEGER max);
import void Console_SetColors (INTEGER attr);
import void Console_SetFont (INTEGER font);
import void Console_WriteCh (CHAR ch);
import void Console_WriteInt (LONGINT i);
import void Console_WriteLn (void);
import void Console_WriteStr (CHAR *str, LONGINT str__len);
import void Console_WriteStrLn (CHAR *str, LONGINT str__len);
import void *Console__init(void);


#endif
