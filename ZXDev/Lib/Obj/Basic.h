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
import void Basic_DATA (INTEGER b);
import void Basic_DATA1 (INTEGER b);
import void Basic_DATA10 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10);
import void Basic_DATA11 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11);
import void Basic_DATA12 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12);
import void Basic_DATA13 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13);
import void Basic_DATA14 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14);
import void Basic_DATA15 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15);
import void Basic_DATA16 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15, INTEGER b16);
import void Basic_DATA2 (INTEGER b1, INTEGER b2);
import void Basic_DATA3 (INTEGER b1, INTEGER b2, INTEGER b3);
import void Basic_DATA4 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4);
import void Basic_DATA5 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5);
import void Basic_DATA6 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6);
import void Basic_DATA7 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7);
import void Basic_DATA8 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8);
import void Basic_DATA9 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9);
import void Basic_DEFDATAREL (INTEGER title, INTEGER size);
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
import INTEGER Basic_PEEKW (INTEGER addr);
import void Basic_PLOT (INTEGER x, INTEGER y);
import INTEGER Basic_POINT (INTEGER x, INTEGER y);
import void Basic_POKE (INTEGER addr, INTEGER value);
import void Basic_POKEW (INTEGER addr, INTEGER value);
import INTEGER Basic_PORTIN (INTEGER port);
import void Basic_PORTOUT (INTEGER port, INTEGER value);
import void Basic_PRCHAR (CHAR ch);
import void Basic_PRINT (INTEGER i);
import void Basic_PRLN (void);
import void Basic_PRSTR (CHAR *str, LONGINT str__len);
import void Basic_PRWORD (INTEGER i);
import void Basic_Quit (void);
import void Basic_RANDOMIZE (INTEGER seed);
import INTEGER Basic_READ (INTEGER addr);
import INTEGER Basic_RND (INTEGER min, INTEGER max);
import INTEGER Basic_SGN (INTEGER x);
import void Basic_SlowCircle (INTEGER cx, INTEGER cy, INTEGER radius);
import void *Basic__init(void);


#endif
