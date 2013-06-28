/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Basic_AT (INTEGER y, INTEGER x);
export INTEGER Basic_ATTR (INTEGER y, INTEGER x);
export void Basic_BEEP (INTEGER ms, INTEGER freq);
export void Basic_BORDER (INTEGER color);
export void Basic_BRIGHT (INTEGER mode);
export void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius);
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
export void Basic_DEFDATAREL (INTEGER title, INTEGER size);
export void Basic_DRAW (INTEGER x, INTEGER y);
export void Basic_FLASH (INTEGER mode);
export void Basic_FONT (INTEGER addr);
export void Basic_INK (INTEGER color);
export void Basic_INVERSE (INTEGER mode);
export void Basic_Init (void);
export BOOLEAN Basic_KeyPressed (void);
export void Basic_OVER (INTEGER mode);
export void Basic_PAPER (INTEGER color);
export void Basic_PAUSE (INTEGER ticks);
export INTEGER Basic_PEEK (INTEGER addr);
export INTEGER Basic_PEEKW (INTEGER addr);
export void Basic_PLOT (INTEGER x, INTEGER y);
export INTEGER Basic_POINT (INTEGER x, INTEGER y);
export void Basic_POKE (INTEGER addr, INTEGER value);
export void Basic_POKEW (INTEGER addr, INTEGER value);
export INTEGER Basic_PORTIN (INTEGER port);
export void Basic_PORTOUT (INTEGER port, INTEGER value);
export void Basic_PRCHAR (CHAR ch);
export void Basic_PRINT (INTEGER i);
export void Basic_PRLN (void);
export void Basic_PRSTR (CHAR *str, LONGINT str__len);
export void Basic_PRWORD (INTEGER i);
export void Basic_Quit (void);
export void Basic_RANDOMIZE (INTEGER seed);
export INTEGER Basic_READ (INTEGER addr);
export INTEGER Basic_RND (INTEGER min, INTEGER max);
export INTEGER Basic_SGN (INTEGER x);
export void Basic_SlowCircle (INTEGER cx, INTEGER cy, INTEGER radius);


void Basic_Init (void)
{
}

void Basic_BORDER (INTEGER color)
{
}

void Basic_INK (INTEGER color)
{
}

void Basic_PAPER (INTEGER color)
{
}

void Basic_FLASH (INTEGER mode)
{
}

void Basic_BRIGHT (INTEGER mode)
{
}

void Basic_INVERSE (INTEGER mode)
{
}

void Basic_OVER (INTEGER mode)
{
}

void Basic_AT (INTEGER y, INTEGER x)
{
}

void Basic_CLS (void)
{
}

void Basic_PRSTR (CHAR *str, LONGINT str__len)
{
	__DUP(str, str__len, CHAR);
	__DEL(str);
}

void Basic_PRCHAR (CHAR ch)
{
}

void Basic_PRLN (void)
{
}

void Basic_PLOT (INTEGER x, INTEGER y)
{
}

INTEGER Basic_POINT (INTEGER x, INTEGER y)
{
	return 0;
}

INTEGER Basic_ATTR (INTEGER y, INTEGER x)
{
	return 0;
}

void Basic_DRAW (INTEGER x, INTEGER y)
{
}

void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius)
{
}

void Basic_PRINT (INTEGER i)
{
}

void Basic_PRWORD (INTEGER i)
{
}

void Basic_SlowCircle (INTEGER cx, INTEGER cy, INTEGER radius)
{
}

INTEGER Basic_PEEK (INTEGER addr)
{
	return 0;
}

INTEGER Basic_PEEKW (INTEGER addr)
{
	return 0;
}

void Basic_POKE (INTEGER addr, INTEGER value)
{
}

void Basic_POKEW (INTEGER addr, INTEGER value)
{
}

INTEGER Basic_PORTIN (INTEGER port)
{
	return 0;
}

void Basic_PORTOUT (INTEGER port, INTEGER value)
{
}

BOOLEAN Basic_KeyPressed (void)
{
	return 1;
}

void Basic_PAUSE (INTEGER ticks)
{
}

void Basic_RANDOMIZE (INTEGER seed)
{
}

INTEGER Basic_RND (INTEGER min, INTEGER max)
{
	return 0;
}

INTEGER Basic_SGN (INTEGER x)
{
	return 0;
}

void Basic_BEEP (INTEGER ms, INTEGER freq)
{
}

void Basic_FONT (INTEGER addr)
{
}

void Basic_DEFDATAREL (INTEGER title, INTEGER size)
{
}

INTEGER Basic_READ (INTEGER addr)
{
	return 0;
}

void Basic_DATA (INTEGER b)
{
}

void Basic_DATA1 (INTEGER b)
{
}

void Basic_DATA2 (INTEGER b1, INTEGER b2)
{
}

void Basic_DATA3 (INTEGER b1, INTEGER b2, INTEGER b3)
{
}

void Basic_DATA4 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4)
{
}

void Basic_DATA5 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5)
{
}

void Basic_DATA6 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6)
{
}

void Basic_DATA7 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7)
{
}

void Basic_DATA8 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8)
{
}

void Basic_DATA9 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9)
{
}

void Basic_DATA10 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10)
{
}

void Basic_DATA11 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11)
{
}

void Basic_DATA12 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12)
{
}

void Basic_DATA13 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13)
{
}

void Basic_DATA14 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14)
{
}

void Basic_DATA15 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15)
{
}

void Basic_DATA16 (INTEGER b1, INTEGER b2, INTEGER b3, INTEGER b4, INTEGER b5, INTEGER b6, INTEGER b7, INTEGER b8, INTEGER b9, INTEGER b10, INTEGER b11, INTEGER b12, INTEGER b13, INTEGER b14, INTEGER b15, INTEGER b16)
{
}

void Basic_Quit (void)
{
}


export void *Basic__init(void)
{
	__DEFMOD;
	__REGMOD("Basic", 0);
	__REGCMD("CLS", Basic_CLS);
	__REGCMD("Init", Basic_Init);
	__REGCMD("PRLN", Basic_PRLN);
	__REGCMD("Quit", Basic_Quit);
/* BEGIN */
	__ENDMOD;
}
