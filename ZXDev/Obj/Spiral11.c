/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GrPixel.h"
#include "Math.h"


static INTEGER Spiral11_i, Spiral11_x, Spiral11_y;
static REAL Spiral11_yr1, Spiral11_yr2;
static REAL Spiral11_Sina[361], Spiral11_Cosa[361];


static void Spiral11_PrepareTables (void);


/*============================================================================*/

static void Spiral11_PrepareTables (void)
{
	SHORTINT i, q;
	Spiral11_Sina[0] = Math_Sin((REAL)0);
	Spiral11_Cosa[0] = Math_Cos((REAL)0);
	GrPixel_PutPixel(37, 0);
	GrPixel_PutPixel(37, 1);
	GrPixel_PutPixel(37, 2);
	GrPixel_PutPixel(0, 0);
	i = 1;
	while (i <= 36) {
		Spiral11_yr1 = (i * 3.141599893569946) / (REAL)(REAL)18;
		Spiral11_Sina[__X(i * 10, 361)] = Math_Sin(Spiral11_yr1);
		Spiral11_Cosa[__X(i * 10, 361)] = Math_Cos(Spiral11_yr1);
		Spiral11_yr1 = (Spiral11_Sina[__X(i * 10, 361)] - Spiral11_Sina[__X((i - 1) * 10, 361)]) / (REAL)(REAL)10;
		Spiral11_yr2 = (Spiral11_Cosa[__X(i * 10, 361)] - Spiral11_Cosa[__X((i - 1) * 10, 361)]) / (REAL)(REAL)10;
		q = 1;
		while (q <= 9) {
			Spiral11_Sina[__X((i - 1) * 10 + q, 361)] = Spiral11_Sina[__X((i - 1) * 10, 361)] + Spiral11_yr1 * q;
			Spiral11_Cosa[__X((i - 1) * 10 + q, 361)] = Spiral11_Cosa[__X((i - 1) * 10, 361)] + Spiral11_yr2 * q;
			q += 1;
		}
		GrPixel_PutPixel(i, 0);
		i += 1;
	}
}


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(GrPixel__init);
	__IMPORT(Math__init);
	__REGMAIN("Spiral11", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Spiral11_PrepareTables();
	Basic_CLS();
	Spiral11_yr1 = (REAL)80 * Spiral11_Sina[30];
	Spiral11_yr2 = (REAL)80 * Spiral11_Cosa[30];
	Spiral11_i = 720;
	do {
		GrPixel_PutPixel(128 + (INTEGER)__ENTIER(((REAL)80 * Spiral11_Cosa[__X((INTEGER)__MOD(Spiral11_i * 10, 360), 361)]) * Spiral11_Sina[__X(__DIV(Spiral11_i * 5, 20), 361)]), 88 + (INTEGER)__ENTIER((Spiral11_yr1 * Spiral11_Sina[__X((INTEGER)__MOD(Spiral11_i * 10, 360), 361)]) * Spiral11_Sina[__X(__DIV(Spiral11_i * 5, 20), 361)] - Spiral11_yr2 * Spiral11_Cosa[__X(__DIV(Spiral11_i * 5, 20), 361)]));
		Spiral11_i -= 1;
	} while (!(Spiral11_i < 0));
	Basic_PAUSE(0);
	Basic_Quit();
	__FINI;
}
