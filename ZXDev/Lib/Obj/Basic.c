/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Basic_AT (INTEGER y, INTEGER x);
export INTEGER Basic_ATTR (SHORTINT y, SHORTINT x);
export void Basic_BEEP (INTEGER ms, INTEGER freq);
export void Basic_BORDER (INTEGER color);
export void Basic_BRIGHT (SHORTINT mode);
export void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius);
export void Basic_CLS (void);
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
export void Basic_DATACH (INTEGER b);
export void Basic_DATACH1 (INTEGER b);
export void Basic_DATACH10 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10);
export void Basic_DATACH11 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11);
export void Basic_DATACH12 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12);
export void Basic_DATACH13 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13);
export void Basic_DATACH14 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14);
export void Basic_DATACH15 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15);
export void Basic_DATACH16 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15, INTEGER b16);
export void Basic_DATACH2 (INTEGER b1, INTEGER b2);
export void Basic_DATACH3 (INTEGER b1, INTEGER b2, INTEGER b3);
export void Basic_DATACH4 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4);
export void Basic_DATACH5 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5);
export void Basic_DATACH6 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6);
export void Basic_DATACH7 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7);
export void Basic_DATACH8 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8);
export void Basic_DATACH9 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9);
export void Basic_DATASTR (CHAR *str, LONGINT str__len);
export void Basic_DATASTRZ (CHAR *str, LONGINT str__len);
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
export void Basic_DEFDATA (INTEGER title, INTEGER size);
export void Basic_DEFDATAREL (INTEGER title, INTEGER size);
export void Basic_DRAW (INTEGER x, INTEGER y);
export void Basic_FLASH (SHORTINT mode);
export void Basic_FONT (LONGINT addr);
export void Basic_INK (INTEGER color);
export CHAR Basic_INKEY (void);
export void Basic_INVERSE (SHORTINT mode);
export void Basic_Init (void);
export BOOLEAN Basic_KeyPressed (void);
export void Basic_OVER (SHORTINT mode);
export void Basic_PAPER (INTEGER color);
export void Basic_PAUSE (INTEGER ticks);
export INTEGER Basic_PEEK (LONGINT addr);
export INTEGER Basic_PEEKW (LONGINT addr);
export void Basic_PLOT (INTEGER x, INTEGER y);
export INTEGER Basic_POINT (SHORTINT x, SHORTINT y);
export void Basic_POKE (LONGINT addr, INTEGER value);
export void Basic_POKEW (LONGINT addr, INTEGER value);
export INTEGER Basic_PORTIN (LONGINT port);
export void Basic_PORTOUT (LONGINT port, INTEGER value);
export void Basic_PRCHAR (CHAR ch);
export void Basic_PRDATA (void);
export void Basic_PRINT (INTEGER i);
export void Basic_PRLN (void);
export void Basic_PRSTR (CHAR *str, LONGINT str__len);
export void Basic_PRUDG (CHAR ch);
export void Basic_PRWORD (INTEGER i);
export void Basic_Quit (void);
export void Basic_RANDOMIZE (INTEGER seed);
export INTEGER Basic_READ (INTEGER addr);
export INTEGER Basic_RND (INTEGER min, INTEGER max);
export SHORTINT Basic_SGN (INTEGER x);
export void Basic_SlowCircle (SHORTINT cx, SHORTINT cy, SHORTINT radius);
export void Basic_UDG (LONGINT addr);


/*============================================================================*/

void Basic_Init (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_BORDER (INTEGER color)
{
}

/*----------------------------------------------------------------------------*/
void Basic_INK (INTEGER color)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PAPER (INTEGER color)
{
}

/*----------------------------------------------------------------------------*/
void Basic_FLASH (SHORTINT mode)
{
}

/*----------------------------------------------------------------------------*/
void Basic_BRIGHT (SHORTINT mode)
{
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
void Basic_AT (INTEGER y, INTEGER x)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CLS (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRSTR (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}

/*----------------------------------------------------------------------------*/
void Basic_PRCHAR (CHAR ch)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRUDG (CHAR ch)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRDATA (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRLN (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PLOT (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_POINT (SHORTINT x, SHORTINT y)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_ATTR (SHORTINT y, SHORTINT x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_DRAW (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRINT (INTEGER i)
{
}

/*----------------------------------------------------------------------------*/
void Basic_PRWORD (INTEGER i)
{
}

/*----------------------------------------------------------------------------*/
void Basic_SlowCircle (SHORTINT cx, SHORTINT cy, SHORTINT radius)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_PEEK (LONGINT addr)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_PEEKW (LONGINT addr)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_POKE (LONGINT addr, INTEGER value)
{
}

/*----------------------------------------------------------------------------*/
void Basic_POKEW (LONGINT addr, INTEGER value)
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
BOOLEAN Basic_KeyPressed (void)
{
	return 1;
}

/*----------------------------------------------------------------------------*/
void Basic_PAUSE (INTEGER ticks)
{
}

/*----------------------------------------------------------------------------*/
void Basic_RANDOMIZE (INTEGER seed)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_RND (INTEGER min, INTEGER max)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
SHORTINT Basic_SGN (INTEGER x)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_BEEP (INTEGER ms, INTEGER freq)
{
}

/*----------------------------------------------------------------------------*/
void Basic_FONT (LONGINT addr)
{
}

/*----------------------------------------------------------------------------*/
void Basic_UDG (LONGINT addr)
{
}

/*----------------------------------------------------------------------------*/
CHAR Basic_INKEY (void)
{
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
void Basic_DEFDATA (INTEGER title, INTEGER size)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DEFDATAREL (INTEGER title, INTEGER size)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_READ (INTEGER addr)
{
	return 0;
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
void Basic_DATACH (INTEGER b)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH1 (INTEGER b)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH2 (INTEGER b1, INTEGER b2)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH3 (INTEGER b1, INTEGER b2, INTEGER b3)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH4 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH5 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH6 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH7 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH8 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH9 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH10 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH11 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH12 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH13 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH14 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH15 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATACH16 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15, INTEGER b16)
{
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
void Basic_DATASTR (CHAR *str, LONGINT str__len)
{
}

/*----------------------------------------------------------------------------*/
void Basic_DATASTRZ (CHAR *str, LONGINT str__len)
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
/* BEGIN */
	__ENDMOD;
}
