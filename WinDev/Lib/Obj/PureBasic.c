/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "WinApi.h"




static void PureBasic_OpenWindow (void);


/*============================================================================*/

static void PureBasic_OpenWindow (void)
{
	INTEGER v8;
	v8 = 0;
}


export void *PureBasic__init(void)
{
	__DEFMOD;
	__IMPORT(WinApi__init);
	__REGMOD("PureBasic", 0);
/* BEGIN */
	__ENDMOD;
}
