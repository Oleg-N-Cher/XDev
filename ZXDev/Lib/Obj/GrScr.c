/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void GrScr_Close (void);
export void GrScr_Update (void);


/*============================================================================*/

void GrScr_Update (void)
{
}

/*----------------------------------------------------------------------------*/
void GrScr_Close (void)
{
}

/*----------------------------------------------------------------------------*/

export void *GrScr__init(void)
{
	__DEFMOD;
	__REGMOD("GrScr", 0);
	__REGCMD("Close", GrScr_Close);
	__REGCMD("Update", GrScr_Update);
/* BEGIN */
	__ENDMOD;
}
