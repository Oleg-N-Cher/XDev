#include "SYSTEM.oh"
#include "Platform.oh"

export SET Platform_BITS (SHORTINT i);
export void Platform_DISPOSE (SYSTEM_PTR *mem);
export SHORTINT Platform_ORD (SET s);

/*================================== Header ==================================*/
SET Platform_BITS (SHORTINT i)
{
  return __VAL(SET, i);
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT Platform_ORD (SET s)
{
  return __VAL(SHORTINT, s);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Platform_free(memblock)	free(memblock)

void Platform_DISPOSE (SYSTEM_PTR *mem)
{
  Platform_free(*mem);
  *mem = NIL;
}
