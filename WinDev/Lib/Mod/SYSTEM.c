#include "SYSTEM.h"

/*============================================================================*/
INTEGER SYSTEM_DIV(INTEGER x, INTEGER y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(-12);
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_DIVL(LONGINT x, LONGINT y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(-12);
}

/*----------------------------------------------------------------------------*/
INTEGER SYSTEM_MOD(INTEGER x, INTEGER y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(-12);
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_MODL(LONGINT x, LONGINT y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(-12);
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
