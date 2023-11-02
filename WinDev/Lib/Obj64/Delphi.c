/* Ofront+ 1.0 -sxtw3 -88 */
#include "SYSTEM.oh"




export BOOLEAN Delphi_CompareMem (LONGINT p1, LONGINT p2, INTEGER length);
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
BOOLEAN Delphi_CompareMem (LONGINT p1, LONGINT p2, INTEGER length)
{
  BYTE byte1, byte2;
  LONGINT word1, word2;
  if (__MASK(p1, -8) == 0 && __MASK(p2, -8) == 0) {
    while (length >= 8) {
      __GET(p1, word1, LONGINT);
      __GET(p2, word2, LONGINT);
      if (word1 != word2) {
        return 0;
      }
      p1 += 8;
      p2 += 8;
      length -= 8;
    }
  }
  while (length > 0) {
    __GET(p1, byte1, BYTE);
    __GET(p2, byte2, BYTE);
    if (byte1 != byte2) {
      return 0;
    }
    p1 += 1;
    p2 += 1;
    length -= 1;
  }
  return 1;
}

/*----------------------------------------------------------------------------*/
