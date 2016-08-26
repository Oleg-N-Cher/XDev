/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "GrPixel.h"
#include "Math.h"


static INTEGER Spiral11_i, Spiral11_x, Spiral11_y;
static REAL Spiral11_yr1, Spiral11_yr2;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrPixel__init);
	__IMPORT(Math__init);
	__REGMAIN("Spiral11", 0);
/* BEGIN */
	Spiral11_yr1 = (REAL)80 * Math_Sin(0.5235833525657654);
	Spiral11_yr2 = (REAL)80 * Math_Cos(0.5235833525657654);
	Spiral11_i = 0;
	while (Spiral11_i <= 720) {
		GrPixel_PutPixel(128 + (INTEGER)__ENTIER(((REAL)80 * Math_Cos((3.141499996185303 * Spiral11_i) / (REAL)(REAL)18)) * Math_Sin((3.141499996185303 * Spiral11_i) / (REAL)(REAL)720)), 88 + (INTEGER)__ENTIER((Spiral11_yr1 * Math_Sin((3.141499996185303 * Spiral11_i) / (REAL)(REAL)18)) * Math_Sin((3.141499996185303 * Spiral11_i) / (REAL)(REAL)720) - Spiral11_yr2 * Math_Cos((3.141499996185303 * Spiral11_i) / (REAL)(REAL)720)));
		Spiral11_i += 1;
	}
	__FINI;
}
