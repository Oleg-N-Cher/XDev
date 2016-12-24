/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Graph.h"
#include "GrPixel.h"

typedef
	INTEGER Spiral11f3_TSinAr[46];


__CONSTARR Spiral11f3_TSinAr SinStart =
	{0,9,18,27,36,44,53,62,71,79,
	88,96,104,112,120,128,136,143,150,158,
	165,171,178,184,190,196,202,207,212,217,
	222,226,230,234,237,241,243,246,248,250,
	252,254,255,255,256,256};
static INTEGER Spiral11f3_KD, Spiral11f3_MD, Spiral11f3_i, Spiral11f3_q, Spiral11f3_r1, Spiral11f3_r2;
static INTEGER Spiral11f3_Sina[361], Spiral11f3_Cosa[361];


static void Spiral11f3_PrepareTables (void);


/*============================================================================*/

static void Spiral11f3_PrepareTables (void)
{
	INTEGER i, x, y;
	i = 45;
	x = 0;
	y = 0;
	Spiral11f3_Sina[__X(y, 361)] = SinStart[__X(x, 46)];
	Spiral11f3_q = SinStart[__X(x, 46)];
	do {
		x = x + 1;
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361)] = __ASHR(SinStart[__X(x, 46)] + Spiral11f3_q, 1, INTEGER);
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361)] = SinStart[__X(x, 46)];
		Spiral11f3_q = SinStart[__X(x, 46)];
		i = i - 1;
	} while (!(i == 0));
	i = 90;
	x = 90;
	do {
		x = x - 1;
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361)] = Spiral11f3_Sina[__X(x, 361)];
		i = i - 1;
	} while (!(i == 0));
	i = 180;
	x = 0;
	do {
		x = x + 1;
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361)] = -Spiral11f3_Sina[__X(x, 361)];
		i = i - 1;
	} while (!(i == 0));
	i = 0;
	while (i <= 360) {
		Spiral11f3_Cosa[__X(i, 361)] = Spiral11f3_Sina[__X((INTEGER)__MOD(i + 90, 360), 361)];
		i += 1;
	}
}


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Graph__init);
	__IMPORT(GrPixel__init);
	__REGMAIN("Spiral11f3", 0);
/* BEGIN */
	Spiral11f3_KD = 1;
	Spiral11f3_MD = 1;
	Graph_InitGraph(&Spiral11f3_KD, &Spiral11f3_MD, (CHAR*)"", 1);
	Spiral11f3_PrepareTables();
	Spiral11f3_r1 = __ASHR(80 * Spiral11f3_Sina[30], 8, INTEGER);
	Spiral11f3_r2 = __ASHR(80 * Spiral11f3_Cosa[30], 8, INTEGER);
	Spiral11f3_i = 720;
	do {
		GrPixel_PutPixel(128 + __ASHR(__ASHR(80 * Spiral11f3_Cosa[__X((INTEGER)__MOD(Spiral11f3_i * 10, 360), 361)], 8, INTEGER) * Spiral11f3_Sina[__X(__DIV(Spiral11f3_i * 5, 20), 361)], 8, INTEGER), (88 + __ASHR(__ASHR(Spiral11f3_r1 * Spiral11f3_Sina[__X((INTEGER)__MOD(Spiral11f3_i * 10, 360), 361)], 8, INTEGER) * Spiral11f3_Sina[__X(__DIV(Spiral11f3_i * 5, 20), 361)], 8, INTEGER)) - __ASHR(Spiral11f3_r2 * Spiral11f3_Cosa[__X(__DIV(Spiral11f3_i * 5, 20), 361)], 8, INTEGER));
		Spiral11f3_i -= 1;
	} while (!(Spiral11f3_i < 0));
	Graph_CloseGraph();
	__FINI;
}
