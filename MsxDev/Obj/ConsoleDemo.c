/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "GRAPHIC.h"


static SHORTINT ConsoleDemo_n;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(GRAPHIC__init);
	__REGMAIN("ConsoleDemo", 0);
/* BEGIN */
	GRAPHIC_Screen(0);
	GRAPHIC_Color(1, 15, 15);
	ConsoleDemo_n = 0;
	while (ConsoleDemo_n <= 7) {
		Basic_VPOKE(2304 + (int)ConsoleDemo_n, 170);
		Basic_VPOKE((2304 + (int)ConsoleDemo_n) + 1, 85);
		ConsoleDemo_n += 2;
	}
	__FINI;
}
