/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Basic.h"
#include "Laser.h"
#include "LaserSprite2B.h"




export void LaserDemo_Main (void);


void LaserDemo_Main (void)
{
	SHORTINT n, s, _for__3, _for__2;
	Basic_Init();
	Laser_InitSprites(LaserSprite2B_SprStart, 6271);
	Basic_BORDER(0);
	Basic_PAPER(0);
	Basic_CLS();
	s = -2;
	_for__3 = 30;
	_for__3 = __ASHR(_for__3 - s, 1) + 1;
	do {
		n = 7;
		_for__2 = 10;
		_for__2 = (_for__2 - n) + 1;
		do {
			Laser_PTBL(s, 5, n);
			Basic_PAUSE(5);
			n += 1;
			_for__2 -= 1;
		} while (!(_for__2 == 0));
		s += 2;
		_for__3 -= 1;
	} while (!(_for__3 == 0));
	Basic_Quit();
}


export void *LaserDemo__init(void)
{
	__DEFMOD;
	__IMPORT(Basic);
	__IMPORT(Laser);
	__IMPORT(LaserSprite2B);
	__REGMOD("LaserDemo", 0);
	__REGCMD("Main", LaserDemo_Main);
/* BEGIN */
	__ENDMOD;
}
