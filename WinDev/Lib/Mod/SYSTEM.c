#include "SYSTEM.h"

/*============================================================================*/
LONGINT SYSTEM_DIV(LONGINT x, LONGINT y)
{
  if (x == 0) return 0;
  if (x >= 0)
    if (y >= 0) {return x/y;}
    else        {return -((x-y-1)/(-y));}
  else
    if (y >= 0) {return -((y-x-1)/y);}
    else        {return (-x)/(-y);}
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_MOD(LONGINT x, LONGINT y)
{
  if (x == 0) return 0;
  if (x >= 0)
    if (y >= 0) {return x % y;}
    else        {return (y+1) + ((x-1) % (-y));}
  else
    if (y >= 0) {return (y-1) - ((-x-1) % y);}
    else        {return -((-x) % (-y));}
}

/*----------------------------------------------------------------------------*/
INTEGER SYSTEM_ENTIER(REAL x)
{
  INTEGER i;
  i = (INTEGER)x;
  if (i > x) i--;
  return i;
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_ENTIERL(REAL x)
{
  LONGINT i;
  i = (LONGINT)x;
  if (i > x) i--;
  return i;
}

/*----------------------------------------------------------------------------*/
#ifndef _WIN32
#  include <stdlib.h>
   void SYSTEM_ExitOS (int code) { exit(code); }
#else
#  include "_windows.h"
   void SYSTEM_ExitOS (int code) { ExitProcess((UINT)(code)); }
#endif

