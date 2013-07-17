/*  Ofront 1.2 -xtspkae */

#ifndef Strings__h
#define Strings__h

#include "SYSTEM.h"




import void Strings_IntToStr (LONGINT n, CHAR *str, LONGINT str__len);
import void Strings_IntToStrForm (LONGINT x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len);
import LONGINT Strings_Length (CHAR *str, LONGINT str__len);
import void *Strings__init(void);


#endif
