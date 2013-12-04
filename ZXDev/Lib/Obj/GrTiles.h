/*  Ofront 1.2 -xtspkae */

#ifndef GrTiles__h
#define GrTiles__h

#include "SYSTEM.h"




import void GrTiles_DrawMonoTile (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors);
import void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors);
import void GrTiles_DrawTile (INTEGER x, INTEGER y, INTEGER tile);
import void GrTiles_DrawTile8x8 (INTEGER x, INTEGER y, INTEGER tile);
import void GrTiles_DrawTranspMonoTile (INTEGER x, INTEGER y, INTEGER tile, SHORTINT colors);
import void GrTiles_DrawTranspMonoTile8x8 (SHORTINT x, SHORTINT y, INTEGER *tile, SHORTINT colors);
import void GrTiles_SetColors (INTEGER attr);
import void *GrTiles__init(void);


#endif
