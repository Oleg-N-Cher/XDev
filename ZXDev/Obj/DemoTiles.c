/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GrApp.h"
#include "GrTiles.h"


static SHORTINT DemoTiles_i;
static INTEGER DemoTiles_square;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(GrApp__init);
	__IMPORT(GrTiles__init);
	__REGMAIN("DemoTiles", 0);
/* BEGIN */
	Basic_Init();
	Basic_BORDER(2);
	Basic_DEFDATA(DemoTiles_square, 9);
	Basic_DATA8(255, 129, 129, 129, 129, 129, 129, 255);
	Basic_DATA1(49);
	DemoTiles_i = 0;
	while (DemoTiles_i <= 23) {
		GrTiles_DrawTile(DemoTiles_i, DemoTiles_i, DemoTiles_square);
		DemoTiles_i += 1;
	}
	DemoTiles_i = 24;
	while (DemoTiles_i <= 31) {
		GrTiles_DrawTile(DemoTiles_i, 23, DemoTiles_square);
		DemoTiles_i += 1;
	}
	DemoTiles_i = 8;
	while (DemoTiles_i <= 23) {
		GrTiles_DrawMonoTile(DemoTiles_i, 1, DemoTiles_square, 7);
		DemoTiles_i += 1;
	}
	DemoTiles_i = 10;
	while (DemoTiles_i <= 21) {
		GrTiles_DrawMonoTile(DemoTiles_i, 3, DemoTiles_square, 13);
		DemoTiles_i += 1;
	}
	DemoTiles_i = 12;
	while (DemoTiles_i <= 19) {
		GrTiles_DrawMonoTile(DemoTiles_i, 5, DemoTiles_square, 56);
		DemoTiles_i += 1;
	}
	DemoTiles_i = 14;
	while (DemoTiles_i <= 17) {
		GrTiles_DrawMonoTile(DemoTiles_i, 7, DemoTiles_square, 28);
		DemoTiles_i += 1;
	}
	Basic_PAUSE(0);
	Basic_Quit();
	__FINI;
}
