/*  Ofront 1.2 -xtspkae */

#ifndef GrTiles__h
#define GrTiles__h

#include "SYSTEM.h"


import void GrTiles_DrawTile8x8 (SHORTCARD x, SHORTCARD y, CARDINAL tile);
import void GrTiles_DrawMonoTile8x8 (SHORTCARD x, SHORTCARD y, CARDINAL tile, SHORTINT colors);
#define GrTiles__init()

#define GrTiles_DrawTile GrTiles_DrawTile8x8
#define GrTiles_DrawMonoTile GrTiles_DrawMonoTile8x8

#endif
