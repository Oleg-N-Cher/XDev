/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "GrColors.h"
#include "GrScr.h"
#include "SdlLib.h"
#include "GrTiles.h"


static INTEGER DemoTiles_i;
static GrTiles_Tile8x8 DemoTiles_square;
static INTEGER DemoTiles__for__6, DemoTiles__for__5, DemoTiles__for__4, DemoTiles__for__3, DemoTiles__for__2, DemoTiles__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrColors__init);
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__IMPORT(GrTiles__init);
	__REGMAIN("DemoTiles", 0);
/* BEGIN */
	DemoTiles_square[0] = 255;
	DemoTiles_square[1] = 129;
	DemoTiles_square[2] = 129;
	DemoTiles_square[3] = 129;
	DemoTiles_square[4] = 129;
	DemoTiles_square[5] = 129;
	DemoTiles_square[6] = 129;
	DemoTiles_square[7] = 255;
	DemoTiles_i = 0;
	DemoTiles__for__6 = 23;
	DemoTiles__for__6 = (DemoTiles__for__6 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile8x8(DemoTiles_i, DemoTiles_i, (void*)DemoTiles_square, 8, GrColors_BlueOnOlive);
		DemoTiles_i += 1;
		DemoTiles__for__6 -= 1;
	} while (!(DemoTiles__for__6 == 0));
	DemoTiles_i = 24;
	DemoTiles__for__5 = 31;
	DemoTiles__for__5 = (DemoTiles__for__5 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile8x8(DemoTiles_i, 23, (void*)DemoTiles_square, 8, GrColors_BlueOnOlive);
		DemoTiles_i += 1;
		DemoTiles__for__5 -= 1;
	} while (!(DemoTiles__for__5 == 0));
	DemoTiles_i = 8;
	DemoTiles__for__4 = 23;
	DemoTiles__for__4 = (DemoTiles__for__4 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile8x8(DemoTiles_i, 1, (void*)DemoTiles_square, 8, GrColors_WhiteOnBlack);
		DemoTiles_i += 1;
		DemoTiles__for__4 -= 1;
	} while (!(DemoTiles__for__4 == 0));
	DemoTiles_i = 10;
	DemoTiles__for__3 = 21;
	DemoTiles__for__3 = (DemoTiles__for__3 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile8x8(DemoTiles_i, 3, (void*)DemoTiles_square, 8, GrColors_CyanOnBlue);
		DemoTiles_i += 1;
		DemoTiles__for__3 -= 1;
	} while (!(DemoTiles__for__3 == 0));
	DemoTiles_i = 12;
	DemoTiles__for__2 = 19;
	DemoTiles__for__2 = (DemoTiles__for__2 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile8x8(DemoTiles_i, 5, (void*)DemoTiles_square, 8, GrColors_BlackOnWhite);
		DemoTiles_i += 1;
		DemoTiles__for__2 -= 1;
	} while (!(DemoTiles__for__2 == 0));
	DemoTiles_i = 14;
	DemoTiles__for__1 = 17;
	DemoTiles__for__1 = (DemoTiles__for__1 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile8x8(DemoTiles_i, 7, (void*)DemoTiles_square, 8, GrColors_GreenOnMagenta);
		DemoTiles_i += 1;
		DemoTiles__for__1 -= 1;
	} while (!(DemoTiles__for__1 == 0));
	GrScr_Update();
	GrScr_Close();
	__FINI;
}
