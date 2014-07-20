/*  Ofront 1.2 -xtspkae */

#ifndef KolRegKeyA__h
#define KolRegKeyA__h

#include "SYSTEM.h"




import void KolRegKeyA_Close (SYSTEM_PTR key);
import BOOLEAN KolRegKeyA_Exists (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import INTEGER KolRegKeyA_GetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len);
import BOOLEAN KolRegKeyA_GetStrNoGC (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *result, LONGINT result__len);
import BOOLEAN KolRegKeyA_KeySetStr (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *value, LONGINT value__len);
import SYSTEM_PTR KolRegKeyA_OpenCreate (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import SYSTEM_PTR KolRegKeyA_OpenRead (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import SYSTEM_PTR KolRegKeyA_OpenWrite (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import BOOLEAN KolRegKeyA_SetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, INTEGER value);
import void *KolRegKeyA__init(void);

#define KolRegKeyA__init()	/*-noinit*/

#endif
