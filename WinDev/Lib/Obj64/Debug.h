/*  Ofront 1.2 -xtspkae */

#ifndef Debug__h
#define Debug__h

#include "SYSTEM.h"




import void Debug_Bool (CHAR *msg, LONGINT msg__len, BOOLEAN b);
import void Debug_Int (CHAR *msg, LONGINT msg__len, LONGINT i);
import void Debug_IntBox (LONGINT i);
import void Debug_Ptr (CHAR *msg, LONGINT msg__len, SYSTEM_PTR ptr);
import void Debug_Str (CHAR *msg, LONGINT msg__len);
import void Debug_WriteInt (LONGINT x);
import void Debug_WriteLn (void);
import void Debug_WriteStr (CHAR *str, LONGINT str__len);
import void *Debug__init(void);


#endif
