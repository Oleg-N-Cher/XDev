/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void GrTiles_DrawMonoTile (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors);
export void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors);
export void GrTiles_DrawTile (INTEGER x, INTEGER y, INTEGER tile);
export void GrTiles_DrawTile8x8 (INTEGER x, INTEGER y, INTEGER tile);
export void GrTiles_DrawTranspMonoTile (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors);
export void GrTiles_DrawTranspMonoTile8x8 (SHORTINT x, SHORTINT y, INTEGER *tile, SHORTINT colors);


/*============================================================================*/

void GrTiles_DrawTile8x8 (INTEGER x, INTEGER y, INTEGER tile)
{
}

/*----------------------------------------------------------------------------*/
void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors)
{
}

/*----------------------------------------------------------------------------*/
void GrTiles_DrawTranspMonoTile8x8 (SHORTINT x, SHORTINT y, INTEGER *tile, SHORTINT colors)
{
}

/*----------------------------------------------------------------------------*/
void GrTiles_DrawTile (INTEGER x, INTEGER y, INTEGER tile)
{
}

/*----------------------------------------------------------------------------*/
void GrTiles_DrawMonoTile (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors)
{
}

/*----------------------------------------------------------------------------*/
void GrTiles_DrawTranspMonoTile (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors)
{
}

/*----------------------------------------------------------------------------*/

export void *GrTiles__init(void)
{
	__DEFMOD;
	__REGMOD("GrTiles", 0);
/* BEGIN */
	__ENDMOD;
}
