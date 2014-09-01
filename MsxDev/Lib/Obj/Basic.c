/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Basic_ATR (INTEGER atr);
export void Basic_CLS (void);
export void Basic_COLOR (INTEGER fore, INTEGER back, INTEGER border);
export void Basic_LINE (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
export void Basic_LOCATE (INTEGER x, INTEGER y);
export INTEGER Basic_PEEK (LONGINT addr);
export INTEGER Basic_PEEKW (LONGINT addr);
export void Basic_POKE (LONGINT addr, INTEGER value);
export void Basic_POKEW (LONGINT addr, INTEGER value);
export void Basic_SCREEN (INTEGER mode);
export INTEGER Basic_VPEEK (LONGINT addr);
export void Basic_VPOKE (LONGINT addr, INTEGER value);
export void Basic_WIDTH (INTEGER width);


/*============================================================================*/

void Basic_ATR (INTEGER atr)
{
}

/*----------------------------------------------------------------------------*/
void Basic_CLS (void)
{
}

/*----------------------------------------------------------------------------*/
void Basic_COLOR (INTEGER fore, INTEGER back, INTEGER border)
{
}

/*----------------------------------------------------------------------------*/
void Basic_LINE (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2)
{
}

/*----------------------------------------------------------------------------*/
void Basic_LOCATE (INTEGER x, INTEGER y)
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
void Basic_SCREEN (INTEGER mode)
{
}

/*----------------------------------------------------------------------------*/
INTEGER Basic_VPEEK (LONGINT addr)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Basic_VPOKE (LONGINT addr, INTEGER value)
{
}

/*----------------------------------------------------------------------------*/
void Basic_WIDTH (INTEGER width)
{
}

/*----------------------------------------------------------------------------*/

export void *Basic__init(void)
{
	__DEFMOD;
	__REGMOD("Basic", 0);
	__REGCMD("CLS", Basic_CLS);
/* BEGIN */
	__ENDMOD;
}
