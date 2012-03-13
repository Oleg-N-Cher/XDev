#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"
#include "Settings.h"

import void Basic_Init (void);
import void BORDER (SHORTINT color);
import void INK (SHORTINT color);
import void PAPER (SHORTINT color);
import void FLASH (SHORTINT mode);
import void BRIGHT (SHORTINT mode);
import void INVERSE (SHORTINT mode);
import void OVER (SHORTINT mode);
import void AT (SHORTINT y, SHORTINT x);
import void CLS (void);
import void PRSTR (CHAR *str);
import void PRCHAR (CHAR ch);
import void PLOT (SHORTINT x, SHORTINT y);
import SYSTEM_BYTE POINT (SHORTINT x, SHORTINT y);
import SYSTEM_BYTE ATTR (SHORTINT y, SHORTINT x);
import void DRAW (SHORTINT x, SHORTINT y);
import void CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius);
import void PRINT (INTEGER i);
import void PRWORD (CARDINAL n);
import void SlowCircle (SHORTINT cx, SHORTINT cy, SHORTINT radius);
import SYSTEM_BYTE PEEK (SYSTEM_ADDRESS addr);
import void POKE (SYSTEM_ADDRESS addr, SYSTEM_BYTE value);
import SYSTEM_BYTE IN (SYSTEM_ADDRESS port);
import void OUT (SYSTEM_ADDRESS port, SYSTEM_BYTE value);
import BOOLEAN KeyPressed (void);
import void PAUSE (CARDINAL ticks);
import void RANDOMIZE (CARDINAL seed);
#ifndef Basic_RND_SHORTCARD
  import CARDINAL RND (CARDINAL min, CARDINAL max);
#else
  import SHORTCARD RND (SHORTCARD min, SHORTCARD max);
#endif
import SHORTINT SGN (SHORTINT x);
import void BEEP (CARDINAL ms, SHORTINT freq);
import void FONT (SYSTEM_ADDRESS addr);
import void Reset (void);
import void Basic_Quit (void);

#define Black 0
#define Blue 1
#define Red 2
#define Magenta 3
#define Green 4
#define Cyan 5
#define Brown 6
#define LightGray 7

#define LightBlue 1
#define LightRed 2
#define LightMagenta 3
#define LightGreen 4
#define LightCyan 5
#define Yellow 6
#define White 7

#define On 1
#define Off 0

#define Basic_BORDER BORDER
#define Basic_INK INK
#define Basic_PAPER PAPER
#define Basic_FLASH FLASH
#define Basic_BRIGHT BRIGHT
#define Basic_INVERSE INVERSE
#define Basic_OVER OVER
#define Basic_AT AT
#define Basic_CLS CLS
#define Basic_PRSTR(str,len) PRSTR(str)
#define Basic_PRCHAR PRCHAR
#define Basic_PLOT PLOT
#define Basic_POINT POINT
#define Basic_ATTR ATTR
#define Basic_DRAW DRAW
#define Basic_CIRCLE CIRCLE
#define Basic_PRINT PRINT
#define Basic_PRWORD PRWORD
#define Basic_SlowCircle SlowCircle
#define Basic_PEEK PEEK
#define Basic_POKE POKE
#define Basic_PORTIN PORTIN
#define Basic_PORTOUT PORTOUT
#define Basic_KeyPressed KeyPressed
#define Basic_PAUSE PAUSE
#define Basic_RANDOMIZE RANDOMIZE
#define Basic_RND RND
#define Basic_SGN SGN
#define Basic_BEEP BEEP
#define Basic_FONT FONT
#define Basic_Reset Reset

#endif
