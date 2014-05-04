/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void GrPixel_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
export void GrPixel_PutPixel (INTEGER x, INTEGER y);


/*============================================================================*/

void GrPixel_PutPixel (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
void GrPixel_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2)
{
}

/*----------------------------------------------------------------------------*/

export void *GrPixel__init(void)
{
	__DEFMOD;
	__REGMOD("GrPixel", 0);
/* BEGIN */
	__ENDMOD;
}
