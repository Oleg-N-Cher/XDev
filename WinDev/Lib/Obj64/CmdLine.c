/* Ofront+ 1.0 -sxtw3 -88 */
#include "SYSTEM.oh"
#include "Ignore.oh"

typedef
  CHAR (*CmdLine_ArgPtr)[1024];

typedef
  CmdLine_ArgPtr (*CmdLine_ArgVec)[1024];

typedef
  CHAR CmdLine_String[1024];


export INTEGER CmdLine_ParamCount;
static CmdLine_ArgVec CmdLine_argv;
static LONGINT CmdLine_dummy;


export void CmdLine_GetParam (INTEGER n, CHAR *val, INTEGER val__len);
export void CmdLine_GetParamInt (INTEGER n, INTEGER *val);
export INTEGER __getmainargs (INTEGER *argc, CmdLine_ArgVec *argv, LONGINT *env, INTEGER wildcard, LONGINT *startupinfo);


/*============================================================================*/

void CmdLine_GetParam (INTEGER n, CHAR *val, INTEGER val__len)
{
  if (n <= CmdLine_ParamCount) {
    __COPY(*(*CmdLine_argv)[n], val, __MIN(val__len, 1024));
  }
}

/*----------------------------------------------------------------------------*/
void CmdLine_GetParamInt (INTEGER n, INTEGER *val)
{
  CHAR s[64];
  INTEGER k, d, i;
  s[0] = 0x00;
  CmdLine_GetParam(n, (void*)s, 64);
  i = 0;
  if (s[0] == '-') {
    i = 1;
  }
  k = 0;
  d = (SHORTINT)s[i] - 48;
  while (d >= 0 && d <= 9) {
    k = k * 10 + d;
    i += 1;
    d = (SHORTINT)s[i] - 48;
  }
  if (s[0] == '-') {
    d = -d;
    i -= 1;
  }
  if (i > 0) {
    *val = k;
  }
}

/*----------------------------------------------------------------------------*/

export void *CmdLine__init (void)
{
  __DEFMOD;
  __IMPORT(Ignore__init);
  __REGMOD("CmdLine", 0);
/* BEGIN */
  Ignore_Int(__getmainargs(&CmdLine_ParamCount, &CmdLine_argv, &CmdLine_dummy, 0, &CmdLine_dummy));
  CmdLine_ParamCount -= 1;
  __ENDMOD;
}
