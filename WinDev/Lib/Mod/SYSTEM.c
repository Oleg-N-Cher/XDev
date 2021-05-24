#include "SYSTEM.oh"

/*============================================================================*/
LONGINT SYSTEM_INF = 0x7FF0000000000000L;
INTEGER SYSTEM_INFS = 0x7F800000;

/*----------------------------------------------------------------------------*/
INTEGER SYSTEM_DIV (INTEGER x, INTEGER y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(-12, "SYSTEM.c", 14);
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_DIVL (LONGINT x, LONGINT y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(-12, "SYSTEM.c", 28);
}

/*----------------------------------------------------------------------------*/
INTEGER SYSTEM_MOD (INTEGER x, INTEGER y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(-12, "SYSTEM.c", 42);
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_MODL (LONGINT x, LONGINT y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(-12, "SYSTEM.c", 56);
}

/*----------------------------------------------------------------------------*/
INTEGER SYSTEM_ENTIER (REAL x)
{
  INTEGER i;
  i = (INTEGER)x;
  if (i > x) i--;
  return i;
}

/*----------------------------------------------------------------------------*/
LONGINT SYSTEM_ENTIERL (REAL x)
{
  LONGINT i;
  i = (LONGINT)x;
  if (i > x) i--;
  return i;
}

/*----------------------------------------------------------------------------*/
void SYSTEM_PACK (SHORTREAL *x, INTEGER n) // x * 2 ** n
{
  INTEGER i = 1;
  if (n > 0) {
    while (i <=  n) { *x *= (SHORTREAL)2; i += 1; }
  } else if (n < 0) {
    while (i <= -n) { *x /= (SHORTREAL)2; i += 1; }
  }
}

/*----------------------------------------------------------------------------*/
void SYSTEM_UNPK (SHORTREAL *x, INTEGER *n)
  // real mantissa m of 'x' and an integer n such that 'x' = m * 2 ** n
{
  BOOLEAN neg = (*x < (SHORTREAL)0);
  *n = 0;
  if (neg) *x = -*x;
  if (*x >= (SHORTREAL)1) {
      do { *n += 1; *x /= (SHORTREAL)2; } while (*x >= (SHORTREAL)1);
  } else if (*x < 0.1 && *x != (SHORTREAL)0) {
      do { *n -= 1; *x *= (SHORTREAL)2; } while (*x < 0.1);
  }
  if (neg) *x = -*x;
  *x += *x; (*n)--;
}

/*----------------------------------------------------------------------------*/
#ifndef _WIN32
#  include <stdlib.h>
   void SYSTEM_ExitOS (int code) { exit(code); }
#else
#  include "_windows.h"
   void SYSTEM_ExitOS (int code) { ExitProcess((UINT)(code)); }
#endif
