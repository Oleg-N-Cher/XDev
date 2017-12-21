/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrApp.h"
#include "GrFonts.h"
#include "GrPixel.h"
#include "GrTiles.h"
#include "SdlLib.h"

typedef
	struct {
		LONGINT len[1];
		BYTE data[1];
	} *GrConsole_FontPtr;


static INTEGER GrConsole_curX, GrConsole_curY;
static GrApp_Colors GrConsole_curColors;
static GrConsole_FontPtr GrConsole_curFont;


export void GrConsole_At (INTEGER x, INTEGER y);
export void GrConsole_Clear (INTEGER color);
export void GrConsole_SetColors (GrApp_Colors colors);
export void GrConsole_SetFont (BYTE *font, LONGINT font__len);
export void GrConsole_WriteCh (CHAR ch);
export void GrConsole_WriteInt (INTEGER x);
export void GrConsole_WriteLn (void);
export void GrConsole_WriteStr (CHAR *str, LONGINT str__len);
export void GrConsole_WriteStrLn (CHAR *str, LONGINT str__len);


/*============================================================================*/

void GrConsole_At (INTEGER x, INTEGER y)
{
	GrConsole_curX = x;
	GrConsole_curY = y;
}

/*----------------------------------------------------------------------------*/
void GrConsole_Clear (INTEGER color)
{
	INTEGER x, y, inkTemp;
	GrConsole_curX = 0;
	GrConsole_curY = 0;
	if (GrApp_MustLock && SdlLib_LockSurface(GrApp_Screen) == 0) {
		return;
	}
	inkTemp = GrPixel_ink;
	GrPixel_Ink(color);
	y = GrApp_Screen->h - 1;
	while (y >= 0) {
		x = GrApp_Screen->w - 1;
		while (x >= 0) {
			(*GrPixel_PutPixelNoLock)(x, y);
			x += -1;
		}
		y += -1;
	}
	if (GrApp_MustLock) {
		SdlLib_UnlockSurface(GrApp_Screen);
	}
	GrPixel_Ink(inkTemp);
}

/*----------------------------------------------------------------------------*/
void GrConsole_SetColors (GrApp_Colors colors)
{
	GrConsole_curColors = colors;
}

/*----------------------------------------------------------------------------*/
void GrConsole_SetFont (BYTE *font, LONGINT font__len)
{
	if ((INTEGER)font == (INTEGER)GrFonts_ZxSpecRom8x8) {
		GrConsole_curFont = (GrConsole_FontPtr)((INTEGER)font - 256);
	} else {
		GrConsole_curFont = (GrConsole_FontPtr)((INTEGER)font);
	}
}

/*----------------------------------------------------------------------------*/
typedef
	GrTiles_MonoTile8x8 *TilePtr__6;

void GrConsole_WriteCh (CHAR ch)
{
	TilePtr__6 tilePtr = NIL;
	tilePtr = (TilePtr__6)(__ASHL((INTEGER)ch, 3, INTEGER) + __VAL(INTEGER, GrConsole_curFont));
	GrTiles_DrawMonoTile8x8(GrConsole_curX, GrConsole_curY, (void*)*tilePtr, 8, GrConsole_curColors);
	GrConsole_curX += 1;
}

/*----------------------------------------------------------------------------*/
void GrConsole_WriteLn (void)
{
	GrConsole_curX = 0;
	GrConsole_curY += 1;
}

/*----------------------------------------------------------------------------*/
void GrConsole_WriteStr (CHAR *str, LONGINT str__len)
{
	INTEGER n;
	n = 0;
	while (n < (INTEGER)str__len && str[__X(n, str__len)] != 0x00) {
		GrConsole_WriteCh(str[__X(n, str__len)]);
		n += 1;
	}
}

/*----------------------------------------------------------------------------*/
void GrConsole_WriteStrLn (CHAR *str, LONGINT str__len)
{
	GrConsole_WriteStr((void*)str, str__len);
	GrConsole_WriteLn();
}

/*----------------------------------------------------------------------------*/
void GrConsole_WriteInt (INTEGER x)
{
	INTEGER i;
	CHAR buf[10];
	if (x < 0) {
		if (x == (-2147483647-1)) {
			GrConsole_WriteStr((void*)&"-2147483648", (LONGINT)12);
			return;
		}
		GrConsole_WriteCh('-');
		x = -x;
	}
	i = 0;
	do {
		buf[__X(i, 10)] = (CHAR)((INTEGER)__MOD(x, 10) + 48);
		x = __DIV(x, 10);
		i += 1;
	} while (!(x == 0));
	do {
		i -= 1;
		GrConsole_WriteCh(buf[__X(i, 10)]);
	} while (!(i == 0));
}

/*----------------------------------------------------------------------------*/

export void *GrConsole__init(void)
{
	__DEFMOD;
	__IMPORT(GrApp__init);
	__IMPORT(GrFonts__init);
	__IMPORT(GrPixel__init);
	__IMPORT(GrTiles__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrConsole", 0);
	__REGCMD("WriteLn", GrConsole_WriteLn);
/* BEGIN */
	GrConsole_curX = 0;
	GrConsole_curY = 0;
	GrConsole_curColors.paper = GrApp_Black;
	GrConsole_curColors.ink = GrApp_Gray;
	GrConsole_SetFont((void*)GrFonts_ZxSpecRom8x8, 768);
	__ENDMOD;
}
