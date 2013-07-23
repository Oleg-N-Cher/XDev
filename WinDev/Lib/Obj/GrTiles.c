/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrPixel.h"
#include "GrScr.h"
#include "SdlLib.h"

typedef
	SYSTEM_BYTE *GrTiles_Tile;

typedef
	SYSTEM_BYTE GrTiles_Tile8x8[8];


static INTEGER GrTiles_ink, GrTiles_paper;


export void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len);
export void GrTiles_SetColors (INTEGER fore, INTEGER back);


void GrTiles_DrawMonoTile8x8 (INTEGER x, INTEGER y, SYSTEM_BYTE *tile, LONGINT tile__len)
{
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
		bit = 0;
		_for__2 = 7;
		_for__2 = (_for__2 - bit) + 1;
		do {
			if (__IN(bit, __VAL(SET, tile[__X(byte, tile__len)]))) {
				GrPixel_SetInk(GrTiles_ink);
				(*GrPixel_PutPixelNoLock)(x + (int)bit, y + (int)byte);
			} else {
				GrPixel_SetInk(GrTiles_paper);
				(*GrPixel_PutPixelNoLock)(x + (int)bit, y + (int)byte);
			}
			bit += 1;
			_for__2 -= 1;
		} while (!(_for__2 == 0));
		byte += 1;
		_for__3 -= 1;
	} while (!(_for__3 == 0));
	if (GrScr_mustLock) {
		SdlLib_UnlockSurface(GrScr_Screen);
	}
	GrPixel_SetInk(inkTemp);
}

void GrTiles_SetColors (INTEGER fore, INTEGER back)
{
	GrTiles_ink = fore;
	GrTiles_paper = back;
}


export void *GrTiles__init(void)
{
	__DEFMOD;
	__IMPORT(GrPixel__init);
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrTiles", 0);
/* BEGIN */
	__ENDMOD;
}
