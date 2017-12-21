/*  Ofront 1.2 -xtspkae */

#ifndef KolStrings__h
#define KolStrings__h

#include "SYSTEM.h"




import INTEGER KolStrings_DelimiterLast (CHAR *str, LONGINT str__len, CHAR *delimiters, LONGINT delimiters__len);
import INTEGER KolStrings_Length (CHAR *str, LONGINT str__len);
import INTEGER KolStrings_StrRScan (CHAR *str, LONGINT str__len, CHAR ch);
import BOOLEAN KolStrings_SubStr (CHAR *s, LONGINT s__len, INTEGER pos, INTEGER len, CHAR *res, LONGINT res__len);
import void *KolStrings__init(void);

#define KolStrings__init()	/*-noinit*/

#endif
