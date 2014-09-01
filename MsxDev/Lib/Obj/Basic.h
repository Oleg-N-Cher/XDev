/*  Ofront 1.2 -xtspkae */

#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"




import void Basic_ATR (INTEGER atr);
import void Basic_CLS (void);
import void Basic_COLOR (INTEGER fore, INTEGER back, INTEGER border);
import void Basic_LINE (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
import void Basic_LOCATE (INTEGER x, INTEGER y);
import INTEGER Basic_PEEK (LONGINT addr);
import INTEGER Basic_PEEKW (LONGINT addr);
import void Basic_POKE (LONGINT addr, INTEGER value);
import void Basic_POKEW (LONGINT addr, INTEGER value);
import void Basic_SCREEN (INTEGER mode);
import INTEGER Basic_VPEEK (LONGINT addr);
import void Basic_VPOKE (LONGINT addr, INTEGER value);
import void Basic_WIDTH (INTEGER width);
import void *Basic__init(void);


#endif
