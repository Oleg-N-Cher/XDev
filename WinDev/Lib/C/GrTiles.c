#include "SYSTEM.h"
#include "GrApp.h"
#include "GrPixel.h"
#include "SdlLib.h"

typedef
	BYTE *GrTiles_Tile;

typedef
	BYTE *GrTiles_MonoTile;

typedef
	BYTE GrTiles_MonoTile8x8[8];

typedef
	struct GrTiles_Tile8x8 {
		GrTiles_MonoTile8x8 mono;
		GrApp_Colors colors;
	} GrTiles_Tile8x8;

typedef
	BYTE *GrTiles_TranspMonoTile;

typedef
	BYTE GrTiles_TranspMonoTile8x8[16];


export void (*GrTiles_DrawMonoTile)(INTEGER, INTEGER, BYTE*, LONGINT , GrApp_Colors);
export void (*GrTiles_DrawTranspMonoTile)(INTEGER, INTEGER, BYTE*, LONGINT , GrApp_Colors);


export void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrApp_Colors colors);
export void GrTiles_DrawTile8x8 (INTEGER x, INTEGER y, GrTiles_Tile8x8 *tile, LONGINT *tile__typ);
export void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrApp_Colors colors);
export void GrTiles_SetTileAsMonoTile8x8 (SdlLib_PSurface *tile, GrTiles_MonoTile8x8 monoTile, GrApp_Colors colors);


/*================================== Header ==================================*/

void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrApp_Colors colors)
{
	CHAR mask;
	SHORTINT byte, bit;
	INTEGER inkTemp;
	x = __ASHL(x, 3);
	y = __ASHL(y, 3);
	inkTemp = GrPixel_ink;
	if (GrApp_MustLock && SdlLib_LockSurface(GrApp_Screen) == 0) {
		return;
	}
	byte = 0;
	while (byte <= 7) {
		mask = __VAL(CHAR, tile[__X(byte, tile__len)]);
		bit = 0;
		while (bit <= 7) {
			if (mask >= 0x80) {
				GrPixel_Ink(colors.ink);
				(*GrPixel_PutPixelNoLock)(x + (int)bit, y);
			} else {
				GrPixel_Ink(colors.paper);
				(*GrPixel_PutPixelNoLock)(x + (int)bit, y);
			}
			mask = __LSHL(mask, 1, CHAR);
			bit += 1;
		}
		y += 1;
		byte += 1;
	}
	if (GrApp_MustLock) {
		SdlLib_UnlockSurface(GrApp_Screen);
	}
	GrPixel_Ink(inkTemp);
}

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrApp_Colors colors)
{
	CHAR mask, transp;
	SHORTINT byte, bit;
	INTEGER inkTemp;
	x = __ASHL(x, 3);
	y = __ASHL(y, 3);
	inkTemp = GrPixel_ink;
	if (GrApp_MustLock && SdlLib_LockSurface(GrApp_Screen) == 0) {
		return;
	}
	byte = 0;
	while (byte <= 7) {
		mask = __VAL(CHAR, tile[__X(byte, tile__len)]);
		transp = __VAL(CHAR, tile[__X(byte + 8, tile__len)]);
		bit = 0;
		while (bit <= 7) {
			if (transp < 0x80) {
				if (mask >= 0x80) {
					GrPixel_Ink(colors.ink);
					(*GrPixel_PutPixelNoLock)(x + (int)bit, y);
				} else {
					GrPixel_Ink(colors.paper);
					(*GrPixel_PutPixelNoLock)(x + (int)bit, y);
				}
			}
			mask = __LSHL(mask, 1, CHAR);
			transp = __LSHL(transp, 1, CHAR);
			bit += 1;
		}
		y += 1;
		byte += 1;
	}
	if (GrApp_MustLock) {
		SdlLib_UnlockSurface(GrApp_Screen);
	}
	GrPixel_Ink(inkTemp);
}

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_SetTileAsMonoTile8x8 (SdlLib_PSurface *tile, GrTiles_MonoTile8x8 monoTile, GrApp_Colors colors)
{
	*tile = SdlLib_CreateRGBSurface(0x20000000, 8, 8, __VAL(INTEGER, GrApp_Screen->format->BitsPerPixel), 0, 0, 0, 0);
}

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_DrawTile8x8 (INTEGER x, INTEGER y, GrTiles_Tile8x8 *tile, LONGINT *tile__typ)
{
	GrTiles_DrawMonoTile8x8(x, y, (void*)(*tile).mono, 8, (*tile).colors);
}

/*--------------------------------- Cut here ---------------------------------*/

export void GrTiles__init (void)
{
	__DEFMOD;
	__IMPORT(GrPixel__init);
	__IMPORT(GrApp__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrTiles", 0);
/* BEGIN */
	__ENDMOD;
}
