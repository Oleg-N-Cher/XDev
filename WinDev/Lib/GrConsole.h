/*  Ofront 1.2 -xtspkae */

#ifndef GrConsole__h
#define GrConsole__h

#include "SYSTEM.h"




import void GrConsole_SetFont (SYSTEM_BYTE *font, LONGINT font__len);
import void GrConsole_WriteCh (CHAR ch);
import void GrConsole_WriteStr (CHAR *str, LONGINT str__len);
import void *GrConsole__init(void);


#endif
