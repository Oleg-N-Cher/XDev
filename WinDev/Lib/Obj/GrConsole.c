/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrColors.h"
#include "GrFonts.h"
#include "GrPixel.h"
#include "GrScr.h"
#include "GrTiles.h"
#include "SdlLib.h"

typedef
	struct {
		LONGINT len[1];
		SYSTEM_BYTE data[1];
	} *GrConsole_FontPtr;

typedef
	GrTiles_Tile8x8 *GrConsole_TilePtr;


static INTEGER GrConsole_x, GrConsole_y;
static GrColors_Colors GrConsole_curColors;
static GrConsole_FontPtr GrConsole_curFont;


export void GrConsole_Clear (INTEGER color);
export void GrConsole_SetColors (GrColors_Colors colors);
export void GrConsole_SetFont (SYSTEM_BYTE *font, LONGINT font__len);
export void GrConsole_WriteCh (CHAR ch);
export void GrConsole_WriteStr (CHAR *str, LONGINT str__len);


void GrConsole_Clear (INTEGER color)
{
	INTEGER x, y, inkTemp;
	inkTemp = GrPixel_ink;
	GrPixel_Ink(color);
	if (GrScr_mustLock && !SdlLib_LockSurface(GrScr_Screen)) {
		return;
	}
	y = GrScr_Screen->h - 1;
	if (y >= 0) {
		y -= -1;
		do {
			y += -1;
			x = GrScr_Screen->w - 1;
			if (x >= 0) {
				x -= -1;
				do {
					x += -1;
					(*GrPixel_PutPixelNoLock)(x, y);
				} while (!(x == 0));
			}
		} while (!(y == 0));
	}
	if (GrScr_mustLock) {
		SdlLib_UnlockSurface(GrScr_Screen);
	}
	GrPixel_Ink(inkTemp);
}

void GrConsole_SetColors (GrColors_Colors colors)
{
	GrConsole_curColors = colors;
}

void GrConsole_SetFont (SYSTEM_BYTE *font, LONGINT font__len)
{
	if ((LONGINT)font == (LONGINT)GrFonts_ZxSpecROM8x8) {
		GrConsole_curFont = (GrConsole_FontPtr)((LONGINT)font - 256);
	} else {
		GrConsole_curFont = (GrConsole_FontPtr)((LONGINT)font);
	}
}

void GrConsole_WriteCh (CHAR ch)
{
	GrConsole_TilePtr tilePtr = NIL;
	tilePtr = (GrConsole_TilePtr)((LONGINT)__ASHL((int)ch, 3) + (LONGINT)GrConsole_curFont);
	GrTiles_DrawMonoTile8x8(GrConsole_x, GrConsole_y, (void*)*tilePtr, 8, GrConsole_curColors);
	GrConsole_x += 1;
}

void GrConsole_WriteStr (CHAR *str, LONGINT str__len)
{
	LONGINT n;
	n = 0;
	while (n < str__len && str[__X(n, str__len)] != 0x00) {
		GrConsole_WriteCh(str[__X(n, str__len)]);
		n += 1;
	}
}


export void *GrConsole__init(void)
{
	__DEFMOD;
	__IMPORT(GrColors__init);
	__IMPORT(GrFonts__init);
	__IMPORT(GrPixel__init);
	__IMPORT(GrScr__init);
	__IMPORT(GrTiles__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrConsole", 0);
/* BEGIN */
	GrConsole_x = 0;
	GrConsole_y = 0;
	GrConsole_curColors.paper = GrColors_Black;
	GrConsole_curColors.ink = GrColors_Gray;
	GrConsole_SetFont((void*)GrFonts_ZxSpecROM8x8, 768);
	__ENDMOD;
}
