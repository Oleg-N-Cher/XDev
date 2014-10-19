/*  Ofront 1.2 -xtspkae */

#ifndef GrConsole__h
#define GrConsole__h

#include "SYSTEM.h"
#include "GrApp.h"




import void GrConsole_At (INTEGER x, INTEGER y);
import void GrConsole_Clear (INTEGER color);
import void GrConsole_SetColors (GrApp_Colors colors);
import void GrConsole_SetFont (BYTE *font, LONGINT font__len);
import void GrConsole_WriteCh (CHAR ch);
import void GrConsole_WriteInt (INTEGER x);
import void GrConsole_WriteLn (void);
import void GrConsole_WriteStr (CHAR *str, LONGINT str__len);
import void GrConsole_WriteStrLn (CHAR *str, LONGINT str__len);
import void *GrConsole__init(void);


#endif
