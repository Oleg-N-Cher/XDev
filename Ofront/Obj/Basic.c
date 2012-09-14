/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Basic_AT (INTEGER y, INTEGER x);
export INTEGER Basic_ATTR (INTEGER y, INTEGER x);
export void Basic_BEEP (INTEGER ms, INTEGER freq);
export void Basic_BORDER (INTEGER color);
export void Basic_BRIGHT (INTEGER mode);
export void Basic_CIRCLE (INTEGER cx, INTEGER cy, INTEGER radius);
export void Basic_CLS (void);
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
export void Basic_PLOT (INTEGER x, INTEGER y);
export INTEGER Basic_POINT (INTEGER x, INTEGER y);
export void Basic_POKE (INTEGER addr, INTEGER value);
export INTEGER Basic_PORTIN (INTEGER port);
export void Basic_PORTOUT (INTEGER port, INTEGER value);
export void Basic_PRCARD (INTEGER i);
export void Basic_PRCHAR (CHAR ch);
export void Basic_PRINT (INTEGER i);
export void Basic_PRSTR (CHAR *str, LONGINT str__len);
export void Basic_Quit (void);
export void Basic_RANDOMIZE (INTEGER seed);
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

void Basic_PRCARD (INTEGER i)
{
}

void Basic_SlowCircle (INTEGER cx, INTEGER cy, INTEGER radius)
{
}

INTEGER Basic_PEEK (INTEGER addr)
{
	return 0;
}

void Basic_POKE (INTEGER addr, INTEGER value)
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

void Basic_Quit (void)
{
}


export void *Basic__init(void)
{
	__DEFMOD;
	__REGMOD("Basic", 0);
	__REGCMD("CLS", Basic_CLS);
	__REGCMD("Init", Basic_Init);
	__REGCMD("Quit", Basic_Quit);
/* BEGIN */
	__ENDMOD;
}
