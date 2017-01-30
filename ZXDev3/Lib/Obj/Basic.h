/* Ofront+ 0.9 -xtspkae */

#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"




import SHORTINT Basic_ABS (SHORTINT x);
import INTEGER Basic_ABSI (INTEGER x);
import void Basic_AT (SHORTINT y, SHORTINT x);
import INTEGER Basic_ATTR (SHORTINT y, SHORTINT x);
import void Basic_BEEP (INTEGER ms, SHORTINT freq);
import void Basic_BORDER (SHORTINT color);
import void Basic_BRIGHT (SHORTINT mode);
import void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius);
import void Basic_CIRCLEROM (INTEGER cx, INTEGER cy, INTEGER radius);
import void Basic_CIRCLEW (INTEGER cx, INTEGER cy, INTEGER radius);
import void Basic_CLS (void);
import void Basic_COLOR (INTEGER attr);
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
import void Basic_DATACH (CHAR b);
import void Basic_DATACH1 (CHAR b);
import void Basic_DATACH10 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10);
import void Basic_DATACH11 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11);
import void Basic_DATACH12 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12);
import void Basic_DATACH13 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13);
import void Basic_DATACH14 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14);
import void Basic_DATACH15 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14, CHAR b15);
import void Basic_DATACH16 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14, CHAR b15, CHAR b16);
import void Basic_DATACH2 (CHAR b1, CHAR b2);
import void Basic_DATACH3 (CHAR b1, CHAR b2, CHAR b3);
import void Basic_DATACH4 (CHAR b1, CHAR b2, CHAR b3, CHAR b4);
import void Basic_DATACH5 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5);
import void Basic_DATACH6 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6);
import void Basic_DATACH7 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7);
import void Basic_DATACH8 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8);
import void Basic_DATACH9 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9);
import void Basic_DATASTR (CHAR *str, SHORTINT str__len);
import void Basic_DATASTRZ (CHAR *str, SHORTINT str__len);
import void Basic_DATAW (INTEGER w);
import void Basic_DATAW1 (INTEGER w);
import void Basic_DATAW10 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10);
import void Basic_DATAW11 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11);
import void Basic_DATAW12 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12);
import void Basic_DATAW13 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13);
import void Basic_DATAW14 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14);
import void Basic_DATAW15 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14, INTEGER w15);
import void Basic_DATAW16 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14, INTEGER w15, INTEGER w16);
import void Basic_DATAW2 (INTEGER w1, INTEGER w2);
import void Basic_DATAW3 (INTEGER w1, INTEGER w2, INTEGER w3);
import void Basic_DATAW4 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4);
import void Basic_DATAW5 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5);
import void Basic_DATAW6 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6);
import void Basic_DATAW7 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7);
import void Basic_DATAW8 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8);
import void Basic_DATAW9 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9);
import void Basic_DEFDATA (INTEGER var, INTEGER size);
import void Basic_DEFDATAREL (INTEGER var, INTEGER size);
import void Basic_DRAW (INTEGER x, INTEGER y);
import void Basic_FLASH (SHORTINT mode);
import void Basic_FONT (LONGINT adr);
import void Basic_IM2PROC (void (*proc)(void));
import void Basic_INK (SHORTINT color);
import CHAR Basic_INKEY (void);
import void Basic_INVERSE (SHORTINT mode);
import void Basic_Init (void);
import void Basic_OVER (SHORTINT mode);
import void Basic_PAINT (INTEGER x, INTEGER y, SHORTINT ink);
import void Basic_PAPER (SHORTINT color);
import void Basic_PAUSE (INTEGER ticks);
import INTEGER Basic_PEEK (LONGINT adr);
import INTEGER Basic_PEEKW (LONGINT adr);
import void Basic_PLOT (INTEGER x, INTEGER y);
import BOOLEAN Basic_POINT (SHORTINT x, SHORTINT y);
import void Basic_POKE (LONGINT adr, INTEGER value);
import void Basic_POKEW (LONGINT adr, INTEGER value);
import INTEGER Basic_PORTIN (LONGINT port);
import void Basic_PORTOUT (LONGINT port, INTEGER value);
import void Basic_PRCHAR (CHAR ch);
import void Basic_PRDATA (void);
import BOOLEAN Basic_PRESSED (void);
import void Basic_PRINT (INTEGER n);
import void Basic_PRLN (void);
import void Basic_PRSTR (CHAR *str, SHORTINT str__len);
import void Basic_PRUDG (CHAR udg);
import void Basic_PRWORD (LONGINT n);
import void Basic_Quit (void);
import void Basic_RANDOMIZE (INTEGER seed);
import INTEGER Basic_READ (LONGINT adr);
import INTEGER Basic_RND (INTEGER min, INTEGER max);
import INTEGER Basic_RNDW (INTEGER min, INTEGER max);
import SHORTINT Basic_SGN (SHORTINT x);
import SHORTINT Basic_SGNI (INTEGER x);
import void Basic_UDG (LONGINT adr);
import void Basic_USR0 (void);
import void *Basic__init(void);


#endif
