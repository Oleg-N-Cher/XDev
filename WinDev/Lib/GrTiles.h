/*  Ofront 1.2 -xtspkae */

#ifndef GrTiles__h
#define GrTiles__h

#include "SYSTEM.h"
#include "GrColors.h"
#include "GrConfig.h"


typedef
	BYTE *GrTiles_Tile;

typedef
	BYTE GrTiles_Tile8x8[8];

typedef
	BYTE *GrTiles_TranspTile;

typedef
	BYTE GrTiles_TranspTile8x8[16];


import void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
import void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
import void GrTiles__init (void);


#define GrTiles_DrawMonoTile	GrTiles_DrawMonoTile8x8
#define GrTiles_DrawTranspMonoTile	GrTiles_DrawTranspMonoTile8x8


#endif
