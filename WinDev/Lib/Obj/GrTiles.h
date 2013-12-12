/*  Ofront 1.2 -xtspkae */

#ifndef GrTiles__h
#define GrTiles__h

#include "SYSTEM.h"
#include "GrColors.h"

typedef
	SYSTEM_BYTE *GrTiles_Tile;

typedef
	SYSTEM_BYTE GrTiles_Tile8x8[8];

typedef
	SYSTEM_BYTE *GrTiles_TranspTile;

typedef
	SYSTEM_BYTE GrTiles_TranspTile8x8[16];


import void (*GrTiles_DrawMonoTile)(INTEGER, INTEGER, SYSTEM_BYTE*, LONGINT , GrColors_Colors);
import void (*GrTiles_DrawTranspMonoTile)(INTEGER, INTEGER, SYSTEM_BYTE*, LONGINT , GrColors_Colors);


import void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
import void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
import void *GrTiles__init(void);


#endif
