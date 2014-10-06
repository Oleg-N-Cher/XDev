#ifndef GrTiles__h
#define GrTiles__h

#include "SYSTEM.h"
#include "GrColors.h"


typedef
	BYTE *GrTiles_Tile;

typedef
	BYTE *GrTiles_MonoTile;

typedef
	BYTE GrTiles_MonoTile8x8[8];

typedef
	struct GrTiles_Tile8x8 {
		GrTiles_MonoTile8x8 mono;
		GrColors_Colors colors;
	} GrTiles_Tile8x8;

typedef
	BYTE *GrTiles_TranspMonoTile;

typedef
	BYTE GrTiles_TranspMonoTile8x8[16];


import void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
import void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
import void GrTiles__init (void);


#define GrTiles_DrawMonoTile	GrTiles_DrawMonoTile8x8
#define GrTiles_DrawTranspMonoTile	GrTiles_DrawTranspMonoTile8x8
#define GrTiles_DrawTile	GrTiles_DrawTile8x8

#define GrTiles_Tile8x8__typ	NIL


#endif
