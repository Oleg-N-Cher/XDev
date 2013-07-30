/*  Ofront 1.2 -xtspkae */

#ifndef GrTiles__h
#define GrTiles__h

#include "SYSTEM.h"


typedef
	SYSTEM_BYTE *GrTiles_Tile;

typedef
	SYSTEM_BYTE GrTiles_Tile8x8[8];


import void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len);
import void GrTiles_SetColors (INTEGER fore, INTEGER back);
import void *GrTiles__init(void);


#endif
