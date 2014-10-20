/*  Ofront 1.2 -xtspkae */

#ifndef KolRegistry__h
#define KolRegistry__h

#include "SYSTEM.h"




import void KolRegistry_Close (SYSTEM_PTR key);
import BOOLEAN KolRegistry_Delete (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import BOOLEAN KolRegistry_Exists (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import INTEGER KolRegistry_GetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len);
import BOOLEAN KolRegistry_GetStrNoGC (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *result, LONGINT result__len);
import BOOLEAN KolRegistry_KeySetStr (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, CHAR *value, LONGINT value__len);
import SYSTEM_PTR KolRegistry_OpenCreate (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import SYSTEM_PTR KolRegistry_OpenRead (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import SYSTEM_PTR KolRegistry_OpenWrite (SYSTEM_PTR key, CHAR *subKey, LONGINT subKey__len);
import BOOLEAN KolRegistry_SetDw (SYSTEM_PTR key, CHAR *valueName, LONGINT valueName__len, INTEGER value);
import void *KolRegistry__init(void);

#define KolRegistry__init()	/*-noinit*/

#endif
