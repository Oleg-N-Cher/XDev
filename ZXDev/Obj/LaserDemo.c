/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Laser.h"
#include "LaserSprite2B.h"




export void LaserDemo_Main (void);


/*============================================================================*/

void LaserDemo_Main (void)
{
	SHORTINT n, s;
	Basic_Init();
	Laser_InitSprites(LaserSprite2B_SprStart, 6271);
	Basic_BORDER(0);
	Basic_PAPER(0);
	Basic_CLS();
	s = -2;
	while (s <= 30) {
		n = 7;
		while (n <= 10) {
			Laser_PTBL(s, 5, n);
			Basic_PAUSE(5);
			n += 1;
		}
		s += 2;
	}
	Basic_Quit();
}

/*----------------------------------------------------------------------------*/

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Laser__init);
	__IMPORT(LaserSprite2B__init);
	__REGMAIN("LaserDemo", 0);
	__REGCMD("Main", LaserDemo_Main);
/* BEGIN */
	__FINI;
}
