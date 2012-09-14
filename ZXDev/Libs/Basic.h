#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"
#include "Settings.h"

import void Basic_Init (void);
import void Basic_BORDER (SHORTINT color);
import void Basic_INK (SHORTINT color);
import void Basic_PAPER (SHORTINT color);
import void Basic_FLASH (SHORTINT mode);
import void Basic_BRIGHT (SHORTINT mode);
import void Basic_INVERSE (SHORTINT mode);
import void Basic_OVER (SHORTINT mode);
import void Basic_AT (SHORTINT y, SHORTINT x);
import void Basic_CLS (void);
import void Basic_PRSTR_C (CHAR *str);
#define Basic_PRSTR(str,len) Basic_PRSTR_C(str)
import void Basic_PRCHAR (CHAR ch);
import void Basic_PLOT (SHORTINT x, SHORTINT y);
import SYSTEM_BYTE Basic_POINT (SHORTINT x, SHORTINT y);
import SYSTEM_BYTE Basic_ATTR (SHORTINT y, SHORTINT x);
import void Basic_DRAW (SHORTINT x, SHORTINT y);
import void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius);
import void Basic_PRINT (INTEGER i);
import void Basic_PRWORD (CARDINAL n);
import void Basic_SlowCircle (SHORTINT cx, SHORTINT cy, SHORTINT radius);
/*import SYSTEM_BYTE Basic_PEEK (SYSTEM_ADDRESS addr);
import void Basic_POKE (SYSTEM_ADDRESS addr, SYSTEM_BYTE value);*/
#define Basic_POKE(addr,val)  (*(unsigned char*) (addr) = (val))
#define Basic_POKEW(addr,val) (*(unsigned*) (addr) = (val))
#define Basic_PEEK(addr)      (*(unsigned char*) (addr))
#define Basic_PEEKW(addr)     (*(unsigned*) (addr))
import SYSTEM_BYTE Basic_PORTIN (SYSTEM_ADDRESS port);
import void Basic_PORTOUT (SYSTEM_ADDRESS port, SYSTEM_BYTE value);
import BOOLEAN Basic_KeyPressed (void);
import void Basic_PAUSE (CARDINAL ticks);
import void Basic_RANDOMIZE (CARDINAL seed);
#ifndef Basic_RND_SHORTCARD
  import CARDINAL Basic_RND (CARDINAL min, CARDINAL max);
#else
  import SHORTCARD Basic_RND (SHORTCARD min, SHORTCARD max);
#endif
import SHORTINT Basic_SGN (SHORTINT x);
import void Basic_BEEP (CARDINAL ms, SHORTINT freq);
import void Basic_FONT (SYSTEM_ADDRESS addr);
import void Basic_Reset (void);
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

#define BORDER Basic_BORDER
#define INK Basic_INK
#define PAPER Basic_PAPER
#define FLASH Basic_FLASH
#define BRIGHT Basic_BRIGHT
#define INVERSE Basic_INVERSE
#define OVER Basic_OVER
#define AT Basic_AT
#define CLS Basic_CLS
#define PRSTR Basic_PRSTR
#define PRCHAR Basic_PRCHAR
#define PLOT Basic_PLOT
#define POINT Basic_POINT
#define ATTR Basic_ATTR
#define DRAW Basic_DRAW
#define CIRCLE Basic_CIRCLE
#define PRINT Basic_PRINT
#define PRWORD Basic_PRWORD
#define SlowCircle Basic_SlowCircle
/*#define PEEK Basic_PEEK
#define POKE Basic_POKE*/
#define POKE(addr,val)  (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val) (*(unsigned*) (addr) = (val))
#define PEEK(addr)      (*(unsigned char*) (addr))
#define PEEKW(addr)     (*(unsigned*) (addr))
#define PORTIN Basic_PORTIN
#define PORTOUT Basic_PORTOUT
#define KeyPressed Basic_KeyPressed
#define PAUSE Basic_PAUSE
#define RANDOMIZE Basic_RANDOMIZE
#define RND Basic_RND
#define SGN Basic_SGN
#define BEEP Basic_BEEP
#define FONT Basic_FONT
#define Reset Basic_Reset

#endif
