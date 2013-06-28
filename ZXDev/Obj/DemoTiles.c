/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GrTiles.h"


static SHORTINT DemoTiles_i;
static INTEGER DemoTiles_square;
static SHORTINT DemoTiles__for__6, DemoTiles__for__5, DemoTiles__for__4, DemoTiles__for__3, DemoTiles__for__2, DemoTiles__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic);
	__IMPORT(GrTiles);
	__REGMAIN("DemoTiles", 0);
/* BEGIN */
	Basic_Init();
	Basic_BORDER(2);
	Basic_DEFDATAREL(DemoTiles_square, 9);
	Basic_DATA8(255, 129, 129, 129, 129, 129, 129, 255);
	Basic_DATA1(49);
	DemoTiles_i = 0;
	DemoTiles__for__6 = 23;
	DemoTiles__for__6 = (DemoTiles__for__6 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawTile(DemoTiles_i, DemoTiles_i, DemoTiles_square);
		DemoTiles_i += 1;
		DemoTiles__for__6 -= 1;
	} while (!(DemoTiles__for__6 == 0));
	DemoTiles_i = 24;
	DemoTiles__for__5 = 31;
	DemoTiles__for__5 = (DemoTiles__for__5 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawTile(DemoTiles_i, 23, DemoTiles_square);
		DemoTiles_i += 1;
		DemoTiles__for__5 -= 1;
	} while (!(DemoTiles__for__5 == 0));
	GrTiles_SetColors(7);
	DemoTiles_i = 8;
	DemoTiles__for__4 = 23;
	DemoTiles__for__4 = (DemoTiles__for__4 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile(DemoTiles_i, 1, DemoTiles_square);
		DemoTiles_i += 1;
		DemoTiles__for__4 -= 1;
	} while (!(DemoTiles__for__4 == 0));
	GrTiles_SetColors(13);
	DemoTiles_i = 10;
	DemoTiles__for__3 = 21;
	DemoTiles__for__3 = (DemoTiles__for__3 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile(DemoTiles_i, 3, DemoTiles_square);
		DemoTiles_i += 1;
		DemoTiles__for__3 -= 1;
	} while (!(DemoTiles__for__3 == 0));
	GrTiles_SetColors(56);
	DemoTiles_i = 12;
	DemoTiles__for__2 = 19;
	DemoTiles__for__2 = (DemoTiles__for__2 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile(DemoTiles_i, 5, DemoTiles_square);
		DemoTiles_i += 1;
		DemoTiles__for__2 -= 1;
	} while (!(DemoTiles__for__2 == 0));
	GrTiles_SetColors(28);
	DemoTiles_i = 14;
	DemoTiles__for__1 = 17;
	DemoTiles__for__1 = (DemoTiles__for__1 - DemoTiles_i) + 1;
	do {
		GrTiles_DrawMonoTile(DemoTiles_i, 7, DemoTiles_square);
		DemoTiles_i += 1;
		DemoTiles__for__1 -= 1;
	} while (!(DemoTiles__for__1 == 0));
	Basic_PAUSE(0);
	Basic_Quit();
	__FINI;
}
