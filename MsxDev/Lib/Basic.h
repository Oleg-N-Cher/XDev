#ifndef Basic__h
#define Basic__h

#include "BasicCfg.h"

import void Basic_ATR_BIOS (char color);
import void Basic_ATR_ISLT (char color);
#ifndef INTERSLOT_CALLS
#  define Basic_ATR Basic_ATR_BIOS
#else
#  define Basic_ATR Basic_ATR_ISLT
#endif
import void Basic_CLS (void);
import void Basic_COLOR (char fore, char back, char border);
import void Basic_LINE_BASIC (int x1, int y1, int x2, int y2);
import void Basic_LINE_EBIOS (int x1, int y1, int x2, int y2);
#define Basic_LINE Basic_LINE_EBIOS
import void Basic_LOCATE (char x, char y);
//import INTEGER Basic_PEEK (LONGINT addr);
//import INTEGER Basic_PEEKW (LONGINT addr);
//import void Basic_POKE (LONGINT addr, INTEGER value);
//import void Basic_POKEW (LONGINT addr, INTEGER value);

import void Basic_SCREEN_BIOS (char mode);
import void Basic_SCREEN_ISLT (char mode);
#ifndef INTERSLOT_CALLS
#  define Basic_SCREEN Basic_SCREEN_BIOS
#else
#  define Basic_SCREEN Basic_SCREEN_ISLT
#endif
import INTEGER Basic_VPEEK (unsigned int addr);
import void Basic_VPOKE (unsigned int addr, char value);
import void Basic_WIDTH_BIOS (char width);
import void Basic_WIDTH_ISLT (char width);
#ifndef INTERSLOT_CALLS
#  define Basic_WIDTH Basic_WIDTH_BIOS
#else
#  define Basic_WIDTH Basic_WIDTH_ISLT
#endif
#define Basic__init()


#endif
