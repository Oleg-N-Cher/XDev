/*  Ofront 1.2 -xtspkae */

#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"




import void Basic_AT (SHORTINT y, SHORTINT x);
import INTEGER Basic_ATTR (SHORTINT y, SHORTINT x);
import void Basic_BEEP (INTEGER ms, INTEGER freq);
import void Basic_BORDER (INTEGER color);
import void Basic_BRIGHT (SHORTINT mode);
import void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius);
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
import void Basic_DEFDATA (INTEGER title, INTEGER size);
import void Basic_DEFDATAREL (INTEGER title, INTEGER size);
import void Basic_DRAW (SHORTINT x, SHORTINT y);
import void Basic_FLASH (SHORTINT mode);
import void Basic_FONT (LONGINT addr);
import void Basic_INK (INTEGER color);
import void Basic_INVERSE (SHORTINT mode);
import void Basic_Init (void);
import BOOLEAN Basic_KeyPressed (void);
import void Basic_OVER (SHORTINT mode);
import void Basic_PAPER (INTEGER color);
import void Basic_PAUSE (INTEGER ticks);
import INTEGER Basic_PEEK (LONGINT addr);
import INTEGER Basic_PEEKW (LONGINT addr);
import void Basic_PLOT (SHORTINT x, SHORTINT y);
import INTEGER Basic_POINT (SHORTINT x, SHORTINT y);
import void Basic_POKE (LONGINT addr, INTEGER value);
import void Basic_POKEW (LONGINT addr, INTEGER value);
import INTEGER Basic_PORTIN (LONGINT port);
import void Basic_PORTOUT (LONGINT port, INTEGER value);
import void Basic_PRCHAR (CHAR ch);
import void Basic_PRDATA (void);
import void Basic_PRINT (INTEGER i);
import void Basic_PRLN (void);
import void Basic_PRSTR (CHAR *str, LONGINT str__len);
import void Basic_PRWORD (INTEGER i);
import void Basic_Quit (void);
import void Basic_RANDOMIZE (INTEGER seed);
import INTEGER Basic_READ (INTEGER addr);
import INTEGER Basic_RND (INTEGER min, INTEGER max);
import SHORTINT Basic_SGN (INTEGER x);
import void Basic_SlowCircle (SHORTINT cx, SHORTINT cy, SHORTINT radius);
import void *Basic__init(void);


#endif
