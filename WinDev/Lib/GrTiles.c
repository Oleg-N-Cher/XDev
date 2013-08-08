/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrColors.h"
#include "GrPixel.h"
#include "GrScr.h"
#include "SdlLib.h"

typedef
	SYSTEM_BYTE *GrTiles_Tile;

typedef
	SYSTEM_BYTE GrTiles_Tile8x8[8];


export void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len, GrColors_Colors colors);


void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len, GrColors_Colors colors)
{
	CHAR mask;
	SHORTINT byte, bit;
	INTEGER inkTemp;
	SHORTINT _for__3, _for__2;
	x = __ASHL(x, 3);
	y = __ASHL(y, 3);
	inkTemp = GrPixel_ink;
	if (GrScr_mustLock && !SdlLib_LockSurface(GrScr_Screen)) {
		return;
	}
	byte = 0;
	_for__3 = 7;
	_for__3 = (_for__3 - byte) + 1;
	do {
		mask = __VAL(CHAR, tile[__X(byte, tile__len)]);
		bit = 0;
		_for__2 = 7;
		_for__2 = (_for__2 - bit) + 1;
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
			_for__2 -= 1;
		} while (!(_for__2 == 0));
		y += 1;
		byte += 1;
		_for__3 -= 1;
	} while (!(_for__3 == 0));
	if (GrScr_mustLock) {
		SdlLib_UnlockSurface(GrScr_Screen);
	}
	GrPixel_Ink(inkTemp);
}

export void GrTiles__init (void)
{
	__DEFMOD;
	__IMPORT(GrPixel__init);
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrTiles", 0);
/* BEGIN */
	__ENDMOD;
}
