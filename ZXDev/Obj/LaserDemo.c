/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Basic.h"
#include "Laser.h"




export void LaserDemo_Main (void);


void LaserDemo_Main (void)
{
	INTEGER n, s;
	Basic_Init();
	Laser_Init();
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


export void *LaserDemo__init(void)
{
	__DEFMOD;
	__IMPORT(Basic);
	__IMPORT(Laser);
	__REGMOD("LaserDemo", 0);
	__REGCMD("Main", LaserDemo_Main);
/* BEGIN */
	__ENDMOD;
}
