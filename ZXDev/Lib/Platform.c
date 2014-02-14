/*  Ofront 1.2 -xtspkae */
#include <malloc.h>
#include "SYSTEM.h"
#include "Platform.h"

export SET Platform_BITS (INTEGER i);
export void Platform_DISPOSE (SYSTEM_PTR *mem);
export INTEGER Platform_ORD (SET s);

/*================================== Header ==================================*/
SET Platform_BITS (INTEGER i)
{
  return __VAL(SET, i);
}

/*--------------------------------- Cut here ---------------------------------*/
INTEGER Platform_ORD (SET s)
{
  return __VAL(INTEGER, s);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Platform_free(memblock)	free(memblock)

void Platform_DISPOSE (SYSTEM_PTR *mem)
{
  Platform_free(*mem);
  *mem = NIL;
}
