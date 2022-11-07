/* Ofront+ 1.0 -sxtw3 -48 */
#include "SYSTEM.oh"




export void Strings_Find (CHAR *s, INTEGER s__len, CHAR *pat, INTEGER pat__len, INTEGER start, INTEGER *pos);
export INTEGER Strings_Length (CHAR *str, INTEGER str__len);


/*============================================================================*/

INTEGER Strings_Length (CHAR *str, INTEGER str__len)
{
  INTEGER len;
  len = 0;
  while (len < str__len && str[len] != 0x00) {
    len += 1;
  }
  return len;
}

/*----------------------------------------------------------------------------*/
void Strings_Find (CHAR *s, INTEGER s__len, CHAR *pat, INTEGER pat__len, INTEGER start, INTEGER *pos)
{
  INTEGER j;
  __ASSERT(start >= 0, 20, (CHAR*)"Strings", -307);
  if (start == 0 || start <= __STRLEN(s, s__len, (CHAR*)"Strings", -581) - __STRLEN(pat, pat__len, (CHAR*)"Strings", -581)) {
    *pos = start;
    while (s[*pos] != 0x00) {
      j = 0;
      while (s[*pos + j] == pat[j] && pat[j] != 0x00) {
        j += 1;
      }
      if (pat[j] == 0x00) {
        return;
      }
      *pos += 1;
    }
  }
  *pos = -1;
}

/*----------------------------------------------------------------------------*/

export void *Strings__init (void)
{
  __DEFMOD;
  __REGMOD("Strings", 0);
/* BEGIN */
  __ENDMOD;
}
