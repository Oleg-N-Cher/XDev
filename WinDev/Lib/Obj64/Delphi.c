/* Ofront+ 1.0 -sxtw3 -88 */
#include "SYSTEM.oh"




export INTEGER Delphi_HiWord (INTEGER i);
export INTEGER Delphi_LoWord (INTEGER i);


/*============================================================================*/

INTEGER Delphi_HiWord (INTEGER i)
{
  return __ASHR(i, 16, INTEGER);
}

/*----------------------------------------------------------------------------*/
INTEGER Delphi_LoWord (INTEGER i)
{
  return (INTEGER)((SET)i & 0xffff);
}

/*----------------------------------------------------------------------------*/

export void *Delphi__init (void)
{
  __DEFMOD;
  __REGMOD("Delphi", 0);
/* BEGIN */
  __ENDMOD;
}
