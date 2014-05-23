/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void GrSpr_DrawSprite (SHORTINT x, SHORTINT y, INTEGER spr);
export void GrSpr_DrawSpriteNoAttr (SHORTINT x, SHORTINT y, INTEGER spr);


/*============================================================================*/

void GrSpr_DrawSprite (SHORTINT x, SHORTINT y, INTEGER spr)
{
}

/*----------------------------------------------------------------------------*/
void GrSpr_DrawSpriteNoAttr (SHORTINT x, SHORTINT y, INTEGER spr)
{
}

/*----------------------------------------------------------------------------*/

export void *GrSpr__init(void)
{
	__DEFMOD;
	__REGMOD("GrSpr", 0);
/* BEGIN */
	__ENDMOD;
}
