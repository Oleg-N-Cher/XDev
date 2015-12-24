/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "GrPixel.h"
#include "GrApp.h"
#include "GrConsole.h"
#include "Input.h"
#include "Math.h"


static INTEGER Flower_KD, Flower_MD, Flower_x0, Flower_y0;


static void Flower_Flower (INTEGER x, INTEGER y, INTEGER radius, INTEGER n, REAL a1, REAL a3, REAL a5);
static INTEGER Flower_Round (REAL x);


/*============================================================================*/

static INTEGER Flower_Round (REAL x)
{
	return (int)__ENTIER(x + 0.5);
}

static void Flower_Flower (INTEGER x, INTEGER y, INTEGER radius, INTEGER n, REAL a1, REAL a3, REAL a5)
{
	REAL b1, b3, b5, q, r, dg, rd, cosRd, sinRd;
	q = (a1 + a3) + a5;
	b1 = (radius * a1) / q;
	b3 = (radius * a3) / q;
	b5 = (radius * a5) / q;
	dg = (REAL)360;
	do {
		rd = dg * 0.01745327934622765;
		q = n * rd;
		r = __ABSFD((b1 * Math_Sin(q * 0.5) + b3 * Math_Sin(q * 1.5)) + b5 * Math_Sin(q * 2.5));
		cosRd = Math_Cos(rd);
		sinRd = Math_Sin(rd);
		GrPixel_Line(x, y, x + Flower_Round(r * cosRd), y + Flower_Round(r * sinRd));
		(*GrPixel_Dot)(x + Flower_Round((r + (REAL)4) * cosRd), y + Flower_Round((r + (REAL)4) * sinRd));
		dg = dg - 0.5;
	} while (!(dg == (REAL)0));
	q = radius / (REAL)(REAL)10;
	do {
		n = 345;
		GrPixel_Ink(GrApp_Green);
		do {
			(*GrPixel_Dot)(x + Flower_Round(q * Math_Cos(n * 0.01745327934622765)), y + Flower_Round(q * Math_Sin(n * 0.01745327934622765)));
			n = n - 15;
		} while (!(n < 0));
		q = q - radius / (REAL)(REAL)50;
	} while (!(q < (REAL)0));
}


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrPixel__init);
	__IMPORT(GrApp__init);
	__IMPORT(GrConsole__init);
	__IMPORT(Input__init);
	__IMPORT(Math__init);
	__REGMAIN("Flower", 0);
/* BEGIN */
	GrConsole_Clear(GrApp_Green);
	GrPixel_Ink(GrApp_Red);
	Flower_x0 = __ASHR(GrApp_ActualMaxX + 1, 1);
	Flower_y0 = __ASHR(GrApp_ActualMaxY + 1, 1);
	Flower_Flower(Flower_x0, Flower_y0, __ASHR(Flower_y0, 1) * 3, 5, (REAL)1, 0.25, 0.1000000014901161);
	GrApp_Redraw();
	if (Input_Read() == ' ') {
	}
	GrApp_Close();
	__FINI;
}
