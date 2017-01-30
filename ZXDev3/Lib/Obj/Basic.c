/* Ofront+ 0.9 -xtspkae */
#include "SYSTEM.h"




export SHORTINT Basic_ABS (SHORTINT x);
export INTEGER Basic_ABSI (INTEGER x);
export void Basic_AT (SHORTINT y, SHORTINT x);
export INTEGER Basic_ATTR (SHORTINT y, SHORTINT x);
export void Basic_BEEP (INTEGER ms, SHORTINT freq);
export void Basic_BORDER (SHORTINT color);
export void Basic_BRIGHT (SHORTINT mode);
export void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius);
export void Basic_CIRCLEROM (INTEGER cx, INTEGER cy, INTEGER radius);
export void Basic_CIRCLEW (INTEGER cx, INTEGER cy, INTEGER radius);
export void Basic_CLS (void);
export void Basic_COLOR (INTEGER attr);
export void Basic_DATA (INTEGER b);
export void Basic_DATA1 (INTEGER b);
export void Basic_DATA10 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10);
export void Basic_DATA11 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11);
export void Basic_DATA12 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12);
export void Basic_DATA13 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13);
export void Basic_DATA14 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14);
export void Basic_DATA15 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15);
export void Basic_DATA16 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15, INTEGER b16);
export void Basic_DATA2 (INTEGER b1, INTEGER b2);
export void Basic_DATA3 (INTEGER b1, INTEGER b2, INTEGER b3);
export void Basic_DATA4 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4);
export void Basic_DATA5 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5);
export void Basic_DATA6 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6);
export void Basic_DATA7 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7);
export void Basic_DATA8 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8);
export void Basic_DATA9 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9);
export void Basic_DATACH (CHAR b);
export void Basic_DATACH1 (CHAR b);
export void Basic_DATACH10 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10);
export void Basic_DATACH11 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11);
export void Basic_DATACH12 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12);
export void Basic_DATACH13 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13);
export void Basic_DATACH14 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14);
export void Basic_DATACH15 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14, CHAR b15);
export void Basic_DATACH16 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14, CHAR b15, CHAR b16);
export void Basic_DATACH2 (CHAR b1, CHAR b2);
export void Basic_DATACH3 (CHAR b1, CHAR b2, CHAR b3);
export void Basic_DATACH4 (CHAR b1, CHAR b2, CHAR b3, CHAR b4);
export void Basic_DATACH5 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5);
export void Basic_DATACH6 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6);
export void Basic_DATACH7 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7);
export void Basic_DATACH8 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8);
export void Basic_DATACH9 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9);
export void Basic_DATASTR (CHAR *str, SHORTINT str__len);
export void Basic_DATASTRZ (CHAR *str, SHORTINT str__len);
export void Basic_DATAW (INTEGER w);
export void Basic_DATAW1 (INTEGER w);
export void Basic_DATAW10 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10);
export void Basic_DATAW11 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11);
export void Basic_DATAW12 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12);
export void Basic_DATAW13 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13);
export void Basic_DATAW14 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14);
export void Basic_DATAW15 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14, INTEGER w15);
export void Basic_DATAW16 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14, INTEGER w15, INTEGER w16);
export void Basic_DATAW2 (INTEGER w1, INTEGER w2);
export void Basic_DATAW3 (INTEGER w1, INTEGER w2, INTEGER w3);
export void Basic_DATAW4 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4);
export void Basic_DATAW5 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5);
export void Basic_DATAW6 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6);
export void Basic_DATAW7 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7);
export void Basic_DATAW8 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8);
export void Basic_DATAW9 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9);
export void Basic_DEFDATA (INTEGER var, INTEGER size);
export void Basic_DEFDATAREL (INTEGER var, INTEGER size);
export void Basic_DRAW (INTEGER x, INTEGER y);
export void Basic_FLASH (SHORTINT mode);
export void Basic_FONT (LONGINT adr);
export void Basic_IM2PROC (void (*proc)(void));
export void Basic_INK (SHORTINT color);
export CHAR Basic_INKEY (void);
export void Basic_INVERSE (SHORTINT mode);
export void Basic_Init (void);
export void Basic_OVER (SHORTINT mode);
export void Basic_PAINT (INTEGER x, INTEGER y, SHORTINT ink);
export void Basic_PAPER (SHORTINT color);
export void Basic_PAUSE (INTEGER ticks);
export INTEGER Basic_PEEK (LONGINT adr);
export INTEGER Basic_PEEKW (LONGINT adr);
export void Basic_PLOT (INTEGER x, INTEGER y);
export BOOLEAN Basic_POINT (SHORTINT x, SHORTINT y);
export void Basic_POKE (LONGINT adr, INTEGER value);
export void Basic_POKEW (LONGINT adr, INTEGER value);
export INTEGER Basic_PORTIN (LONGINT port);
export void Basic_PORTOUT (LONGINT port, INTEGER value);
export void Basic_PRCHAR (CHAR ch);
export void Basic_PRDATA (void);
export BOOLEAN Basic_PRESSED (void);
export void Basic_PRINT (INTEGER n);
export void Basic_PRLN (void);
export void Basic_PRSTR (CHAR *str, SHORTINT str__len);
export void Basic_PRUDG (CHAR udg);
export void Basic_PRWORD (LONGINT n);
export void Basic_Quit (void);
export void Basic_RANDOMIZE (INTEGER seed);
export INTEGER Basic_READ (LONGINT adr);
export INTEGER Basic_RND (INTEGER min, INTEGER max);
export INTEGER Basic_RNDW (INTEGER min, INTEGER max);
export SHORTINT Basic_SGN (SHORTINT x);
export SHORTINT Basic_SGNI (INTEGER x);
export void Basic_UDG (LONGINT adr);
export void Basic_USR0 (void);


/*============================================================================*/

void Basic_Init (void)
{
}

/*----------------------------------------------------------------------------*/
SHORTINT Basic_ABS (SHORTINT x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_ABSI (INTEGER x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_AT (SHORTINT y, SHORTINT x)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_ATTR (SHORTINT y, SHORTINT x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_BEEP (INTEGER ms, SHORTINT freq)
{
}

/*----------------------------------------------------------------------------*/
void Basic_BORDER (SHORTINT color)
{
}

/*----------------------------------------------------------------------------*/
void Basic_BRIGHT (SHORTINT mode)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CIRCLEW (INTEGER cx, INTEGER cy, INTEGER radius)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CIRCLEROM (INTEGER cx, INTEGER cy, INTEGER radius)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CLS (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_COLOR (INTEGER attr)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA (INTEGER b)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA1 (INTEGER b)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA2 (INTEGER b1, INTEGER b2)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA3 (INTEGER b1, INTEGER b2, INTEGER b3)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA4 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA5 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA6 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA7 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA8 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA9 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA10 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA11 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA12 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA13 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA14 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA15 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATA16 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15, INTEGER b16)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH (CHAR b)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH1 (CHAR b)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH2 (CHAR b1, CHAR b2)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH3 (CHAR b1, CHAR b2, CHAR b3)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH4 (CHAR b1, CHAR b2, CHAR b3, CHAR b4)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH5 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH6 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH7 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH8 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH9 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH10 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH11 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH12 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH13 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH14 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH15 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14, CHAR b15)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH16 (CHAR b1, CHAR b2, CHAR b3, CHAR b4, CHAR b5, CHAR b6, CHAR b7, CHAR b8, CHAR b9, CHAR b10, CHAR b11, CHAR b12, CHAR b13, CHAR b14, CHAR b15, CHAR b16)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATASTR (CHAR *str, SHORTINT str__len)
{
	__DUP(str, str__len);
	__DEL(str);
}

/*----------------------------------------------------------------------------*/
void Basic_DATASTRZ (CHAR *str, SHORTINT str__len)
{
	__DUP(str, str__len);
	__DEL(str);
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW (INTEGER w)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW1 (INTEGER w)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW2 (INTEGER w1, INTEGER w2)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW3 (INTEGER w1, INTEGER w2, INTEGER w3)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW4 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW5 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW6 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW7 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW8 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW9 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW10 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW11 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW12 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW13 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW14 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW15 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14, INTEGER w15)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATAW16 (INTEGER w1, INTEGER w2, INTEGER w3, INTEGER w4, INTEGER w5, INTEGER w6, INTEGER w7, INTEGER w8, INTEGER w9, INTEGER w10, INTEGER w11, INTEGER w12, INTEGER w13, INTEGER w14, INTEGER w15, INTEGER w16)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DEFDATA (INTEGER var, INTEGER size)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DEFDATAREL (INTEGER var, INTEGER size)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DRAW (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
void Basic_FLASH (SHORTINT mode)
{
}

/*----------------------------------------------------------------------------*/
void Basic_FONT (LONGINT adr)
{
}

/*----------------------------------------------------------------------------*/
void Basic_IM2PROC (void (*proc)(void))
{
}

/*----------------------------------------------------------------------------*/
void Basic_INK (SHORTINT color)
{
}

/*----------------------------------------------------------------------------*/
CHAR Basic_INKEY (void)
{
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
void Basic_INVERSE (SHORTINT mode)
{
}

/*----------------------------------------------------------------------------*/
void Basic_OVER (SHORTINT mode)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PAINT (INTEGER x, INTEGER y, SHORTINT ink)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PAPER (SHORTINT color)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PAUSE (INTEGER ticks)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_PEEK (LONGINT adr)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_PEEKW (LONGINT adr)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_PLOT (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
BOOLEAN Basic_POINT (SHORTINT x, SHORTINT y)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_POKE (LONGINT adr, INTEGER value)
{
}

/*----------------------------------------------------------------------------*/
void Basic_POKEW (LONGINT adr, INTEGER value)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_PORTIN (LONGINT port)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_PORTOUT (LONGINT port, INTEGER value)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRCHAR (CHAR ch)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRDATA (void)
{
}

/*----------------------------------------------------------------------------*/
BOOLEAN Basic_PRESSED (void)
{
	return 1;
}

/*----------------------------------------------------------------------------*/
void Basic_PRINT (INTEGER n)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRLN (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRSTR (CHAR *str, SHORTINT str__len)
{
	__DUP(str, str__len);
	__DEL(str);
}

/*----------------------------------------------------------------------------*/
void Basic_PRUDG (CHAR udg)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRWORD (LONGINT n)
{
}

/*----------------------------------------------------------------------------*/
void Basic_RANDOMIZE (INTEGER seed)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_READ (LONGINT adr)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_RND (INTEGER min, INTEGER max)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_RNDW (INTEGER min, INTEGER max)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
SHORTINT Basic_SGN (SHORTINT x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
SHORTINT Basic_SGNI (INTEGER x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_UDG (LONGINT adr)
{
}

/*----------------------------------------------------------------------------*/
void Basic_USR0 (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_Quit (void)
{
}

/*----------------------------------------------------------------------------*/

export void *Basic__init(void)
{
	__DEFMOD;
	__REGMOD("Basic", 0);
	__REGCMD("CLS", Basic_CLS);
	__REGCMD("Init", Basic_Init);
	__REGCMD("PRDATA", Basic_PRDATA);
	__REGCMD("PRLN", Basic_PRLN);
	__REGCMD("Quit", Basic_Quit);
	__REGCMD("USR0", Basic_USR0);
/* BEGIN */
	__ENDMOD;
}
