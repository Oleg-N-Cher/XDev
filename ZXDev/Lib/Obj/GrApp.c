/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void GrApp_Close (void);
export void GrApp_Update (void);


/*============================================================================*/

void GrApp_Update (void)
{
}

/*----------------------------------------------------------------------------*/
void GrApp_Close (void)
{
}

/*----------------------------------------------------------------------------*/

export void *GrApp__init(void)
{
	__DEFMOD;
	__REGMOD("GrApp", 0);
	__REGCMD("Close", GrApp_Close);
	__REGCMD("Update", GrApp_Update);
/* BEGIN */
	__ENDMOD;
}
