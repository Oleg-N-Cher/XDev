#include "SYSTEM.h"

typedef
	CHAR *Platform_STRING;

export void Platform_DISPOSE (SYSTEM_PTR *mem);

/*================================== Header ==================================*/

#define Platform_free(memblock)	free(memblock)
void Platform_DISPOSE (SYSTEM_PTR *mem)
{
  Platform_free(*mem);
  *mem = NIL;
}
