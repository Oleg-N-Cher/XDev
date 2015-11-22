/*  Ofront 1.2 -xtspkae */

#ifndef Strings__h
#define Strings__h

#include "SYSTEM.h"




import BOOLEAN Strings_CP1251ToUtf8 (CHAR *s, LONGINT s__len, CHAR *res, LONGINT res__len);
import INTEGER Strings_Find (CHAR *str, LONGINT str__len, CHAR *pattern, LONGINT pattern__len, INTEGER start);
import void Strings_IntToStr (INTEGER n, CHAR *str, LONGINT str__len);
import void Strings_IntToStrForm (INTEGER x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len);
import void Strings_LIntToStr (LONGINT n, CHAR *str, LONGINT str__len);
import void Strings_LIntToStrForm (LONGINT x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len);
import INTEGER Strings_Length (CHAR *str, LONGINT str__len);
import void *Strings__init(void);

#define Strings__init()	/*-noinit*/

#endif
