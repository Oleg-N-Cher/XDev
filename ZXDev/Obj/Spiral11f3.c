/* Ofront+ 1.0 -m3 -21 */
#include "SYSTEM.h"
#include "Basic.h"
#include "Graph.h"
#include "GrPixel.h"

typedef
	SHORTINT Spiral11f3_TSinAr[46];


__CONSTARR Spiral11f3_TSinAr SinStart =
	{0,9,18,27,36,44,53,62,71,79,
	88,96,104,112,120,128,136,143,150,158,
	165,171,178,184,190,196,202,207,212,217,
	222,226,230,234,237,241,243,246,248,250,
	252,254,255,255,256,256};
static SHORTINT Spiral11f3_KD, Spiral11f3_MD, Spiral11f3_i, Spiral11f3_q, Spiral11f3_r1, Spiral11f3_r2;
static SHORTINT Spiral11f3_Sina[361], Spiral11f3_Cosa[361];


static void Spiral11f3_PrepareTables (void);


/*============================================================================*/

static void Spiral11f3_PrepareTables (void)
{
	SHORTINT i, x, y, _for__2;
	i = 45;
	x = 0;
	y = 0;
	Spiral11f3_Sina[__X(y, 361, "Spiral11f3", -1252)] = SinStart[__X(x, 46, "Spiral11f3", -1252)];
	Spiral11f3_q = SinStart[__X(x, 46, "Spiral11f3", -1272)];
	do {
		x = x + 1;
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361, "Spiral11f3", -1353)] = __ASHR(SinStart[__X(x, 46, "Spiral11f3", -1353)] + Spiral11f3_q, 1, SHORTINT);
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361, "Spiral11f3", -1397)] = SinStart[__X(x, 46, "Spiral11f3", -1397)];
		Spiral11f3_q = SinStart[__X(x, 46, "Spiral11f3", -1419)];
		i = i - 1;
	} while (!(i == 0));
	i = 90;
	x = 90;
	do {
		x = x - 1;
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361, "Spiral11f3", -1563)] = Spiral11f3_Sina[__X(x, 361, "Spiral11f3", -1563)];
		i = i - 1;
	} while (!(i == 0));
	i = 180;
	x = 0;
	do {
		x = x + 1;
		y = y + 1;
		Spiral11f3_Sina[__X(y, 361, "Spiral11f3", -1708)] = -Spiral11f3_Sina[__X(x, 361, "Spiral11f3", -1708)];
		i = i - 1;
	} while (!(i == 0));
	i = 0;
	_for__2 = 361;
	do {
		Spiral11f3_Cosa[__X(i, 361, "Spiral11f3", -1828)] = Spiral11f3_Sina[__X((INTEGER)__MOD(i + 90, 360), 361, "Spiral11f3", -1828)];
		i += 1;
	} while (--_for__2);
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
	Graph_InitGraph(&Spiral11f3_KD, &Spiral11f3_MD, (void*)&"", 1);
	Spiral11f3_PrepareTables();
	Spiral11f3_r1 = __ASHR(80 * Spiral11f3_Sina[30], 8, SHORTINT);
	Spiral11f3_r2 = __ASHR(80 * Spiral11f3_Cosa[30], 8, SHORTINT);
	Spiral11f3_i = 720;
	do {
		GrPixel_PutPixel(128 + __ASHR(__ASHR(80 * Spiral11f3_Cosa[__X((INTEGER)__MOD(Spiral11f3_i * 10, 360), 361, "Spiral11f3", -2790)], 8, SHORTINT) * Spiral11f3_Sina[__X(__DIV(Spiral11f3_i * 5, 20), 361, "Spiral11f3", -2790)], 8, SHORTINT), (88 + __ASHR(__ASHR(Spiral11f3_r1 * Spiral11f3_Sina[__X((INTEGER)__MOD(Spiral11f3_i * 10, 360), 361, "Spiral11f3", -2790)], 8, SHORTINT) * Spiral11f3_Sina[__X(__DIV(Spiral11f3_i * 5, 20), 361, "Spiral11f3", -2790)], 8, SHORTINT)) - __ASHR(Spiral11f3_r2 * Spiral11f3_Cosa[__X(__DIV(Spiral11f3_i * 5, 20), 361, "Spiral11f3", -2790)], 8, SHORTINT));
		Spiral11f3_i -= 1;
	} while (!(Spiral11f3_i < 0));
	Graph_CloseGraph();
	__FINI;
}
