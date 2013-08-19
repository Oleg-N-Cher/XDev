/*  Ofront 1.2 -xtspkae */

#ifndef GrConsole__h
#define GrConsole__h

#include "SYSTEM.h"
#include "GrColors.h"
#include "GrConfig.h"


import void GrConsole_At (INTEGER x, INTEGER y);
import void GrConsole_Clear (INTEGER color);
import void GrConsole_SetColors (GrColors_Colors colors);
import void GrConsole_SetFont (SYSTEM_BYTE *font, LONGINT font__len);
import void GrConsole_WriteCh (CHAR ch);
import void GrConsole_WriteStr (CHAR *str, LONGINT str__len);
import void GrConsole__init (void);


#endif
