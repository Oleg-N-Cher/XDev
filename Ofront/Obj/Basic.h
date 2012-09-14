/*  Ofront 1.2 -xtspkae */

#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"




import void Basic_AT (INTEGER y, INTEGER x);
import INTEGER Basic_ATTR (INTEGER y, INTEGER x);
import void Basic_BEEP (INTEGER ms, INTEGER freq);
import void Basic_BORDER (INTEGER color);
import void Basic_BRIGHT (INTEGER mode);
import void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius);
import void Basic_CLS (void);
import void Basic_DRAW (INTEGER x, INTEGER y);
import void Basic_FLASH (INTEGER mode);
import void Basic_FONT (INTEGER addr);
import void Basic_INK (INTEGER color);
import void Basic_INVERSE (INTEGER mode);
import void Basic_Init (void);
import BOOLEAN Basic_KeyPressed (void);
import void Basic_OVER (INTEGER mode);
import void Basic_PAPER (INTEGER color);
import void Basic_PAUSE (INTEGER ticks);
import INTEGER Basic_PEEK (INTEGER addr);
import void Basic_PLOT (INTEGER x, INTEGER y);
import INTEGER Basic_POINT (INTEGER x, INTEGER y);
import void Basic_POKE (INTEGER addr, INTEGER value);
import INTEGER Basic_PORTIN (INTEGER port);
import void Basic_PORTOUT (INTEGER port, INTEGER value);
import void Basic_PRCARD (INTEGER i);
import void Basic_PRCHAR (CHAR ch);
import void Basic_PRINT (INTEGER i);
import void Basic_PRSTR (CHAR *str, LONGINT str__len);
import void Basic_Quit (void);
import void Basic_RANDOMIZE (INTEGER seed);
import INTEGER Basic_RND (INTEGER min, INTEGER max);
import INTEGER Basic_SGN (INTEGER x);
import void Basic_SlowCircle (INTEGER cx, INTEGER cy, INTEGER radius);
import void *Basic__init(void);


#endif
