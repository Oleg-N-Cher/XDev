/*  Ofront 1.2 -xtspkae */

#ifndef Tst__h
#define Tst__h

#include "SYSTEM.h"




import void Tst_Bool (CHAR *msg, LONGINT msg__len, BOOLEAN b);
import void Tst_Int (CHAR *msg, LONGINT msg__len, LONGINT i);
import void Tst_IntBox (LONGINT i);
import void Tst_Ptr (CHAR *msg, LONGINT msg__len, SYSTEM_PTR ptr);
import void Tst_Str (CHAR *msg, LONGINT msg__len);
import void Tst_WriteInt (LONGINT x);
import void Tst_WriteLn (void);
import void Tst_WriteStr (CHAR *str, LONGINT str__len);
import void *Tst__init(void);


#endif
