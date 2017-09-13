/* Ofront+ 0.9 -sm */
#include "SYSTEM.h"
#include "Graph.h"
#include "Math.h"


static INTEGER Flower_KD, Flower_MD, Flower_x0, Flower_y0;


static void Flower_Flower (INTEGER x, INTEGER y, INTEGER radius, INTEGER n, REAL a1, REAL a3, REAL a5);


/*============================================================================*/

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
		Graph_Line(x, y, x + (INTEGER)__ENTIER(r * cosRd), y + (INTEGER)__ENTIER(r * sinRd));
		Graph_PutPixel(x + (INTEGER)__ENTIER((r + (REAL)4) * cosRd), y + (INTEGER)__ENTIER((r + (REAL)4) * sinRd));
		dg = dg - 0.5;
	} while (!(dg == (REAL)0));
	q = radius / (REAL)(REAL)10;
	do {
		n = 345;
		Graph_SetColor(4);
		do {
			Graph_PutPixel(x + (INTEGER)__ENTIER(q * Math_Cos(n * 0.01745327934622765)), y + (INTEGER)__ENTIER(q * Math_Sin(n * 0.01745327934622765)));
			n = n - 15;
		} while (!(n < 0));
		q = q - radius / (REAL)(REAL)50;
	} while (!(q < (REAL)0));
}


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Graph__init);
	__IMPORT(Math__init);
	__REGMAIN("Flower", 0);
/* BEGIN */
	Flower_KD = 1;
	Flower_MD = 1;
	Graph_InitGraph(&Flower_KD, &Flower_MD, (CHAR*)"", 1);
	Graph_SetBkColor(4);
	Graph_SetColor(2);
	Graph_ClearDevice();
	Flower_x0 = __ASHR(Graph_GetMaxX() + 1, 1, INTEGER);
	Flower_y0 = __ASHR(Graph_GetMaxY() + 1, 1, INTEGER);
	Flower_Flower(Flower_x0, Flower_y0, __ASHR(Flower_y0, 1, INTEGER) * 3, 5, (REAL)1, 0.25, 0.1000000014901161);
	Graph_CloseGraph();
	__FINI;
}
