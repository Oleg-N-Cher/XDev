/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrColors.h"
#include "GrPixel.h"
#include "GrScr.h"
#include "SdlLib.h"

typedef
	BYTE *GrTiles_Tile;

typedef
	BYTE GrTiles_Tile8x8[8];

typedef
	BYTE *GrTiles_TranspTile;

typedef
	BYTE GrTiles_TranspTile8x8[16];


export void (*GrTiles_DrawMonoTile)(INTEGER, INTEGER, BYTE*, LONGINT , GrColors_Colors);
export void (*GrTiles_DrawTranspMonoTile)(INTEGER, INTEGER, BYTE*, LONGINT , GrColors_Colors);


export void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors);
export void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors);


/*============================================================================*/

void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors)
{
	CHAR mask;
	SHORTINT byte, bit;
	INTEGER inkTemp;
	SHORTINT _for__3, _for__2;
	x = __ASHL(x, 3);
	y = __ASHL(y, 3);
	inkTemp = GrPixel_ink;
	if (GrScr_MustLock && !SdlLib_LockSurface(GrScr_Screen)) {
		return;
	}
	byte = 0;
	_for__3 = 8;
	do {
		mask = __VAL(CHAR, tile[__X(byte, tile__len)]);
		bit = 0;
		_for__2 = 8;
		do {
			if (mask >= 0x80) {
				GrPixel_Ink(colors.ink);
				(*GrPixel_PutPixelNoLock)(x + (int)bit, y);
			} else {
				GrPixel_Ink(colors.paper);
				(*GrPixel_PutPixelNoLock)(x + (int)bit, y);
			}
			mask = __LSHL(mask, 1, CHAR);
			bit += 1;
		} while (--_for__2);
		y += 1;
		byte += 1;
	} while (--_for__3);
	if (GrScr_MustLock) {
		SdlLib_UnlockSurface(GrScr_Screen);
	}
	GrPixel_Ink(inkTemp);
}

/*----------------------------------------------------------------------------*/
void GrTiles_DrawTranspMonoTile8x8 (INTEGER x, INTEGER y, BYTE *tile, LONGINT tile__len, GrColors_Colors colors)
{
	CHAR mask, transp;
	SHORTINT byte, bit;
	INTEGER inkTemp;
	SHORTINT _for__6, _for__5;
	x = __ASHL(x, 3);
	y = __ASHL(y, 3);
	inkTemp = GrPixel_ink;
	if (GrScr_MustLock && !SdlLib_LockSurface(GrScr_Screen)) {
		return;
	}
	byte = 0;
	_for__6 = 8;
	do {
		mask = __VAL(CHAR, tile[__X(byte, tile__len)]);
		transp = __VAL(CHAR, tile[__X(byte + 8, tile__len)]);
		bit = 0;
		_for__5 = 8;
		do {
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
		} while (--_for__5);
		y += 1;
		byte += 1;
	} while (--_for__6);
	if (GrScr_MustLock) {
		SdlLib_UnlockSurface(GrScr_Screen);
	}
	GrPixel_Ink(inkTemp);
}

/*----------------------------------------------------------------------------*/

export void *GrTiles__init(void)
{
	__DEFMOD;
	__IMPORT(GrColors__init);
	__IMPORT(GrPixel__init);
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrTiles", 0);
/* BEGIN */
	GrTiles_DrawMonoTile = GrTiles_DrawMonoTile8x8;
	GrTiles_DrawTranspMonoTile = GrTiles_DrawTranspMonoTile8x8;
	__ENDMOD;
}
