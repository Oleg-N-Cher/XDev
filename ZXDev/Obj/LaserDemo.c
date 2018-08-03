/* Ofront+ 1.0 -m3 -21 */
#include "SYSTEM.h"
#include "Basic.h"
#include "Laser.h"


static SHORTINT LaserDemo_chudik;
static BYTE LaserDemo_n, LaserDemo_s, LaserDemo__for__2, LaserDemo__for__1;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Laser__init);
	__REGMAIN("LaserDemo", 0);
/* BEGIN */
	Basic_Init();
	Basic_DEFDATA(LaserDemo_chudik, 741);
	Basic_DATA5(7, 183, 0, 5, 4);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 48, 48, 0, 0, 0, 72, 72);
	Basic_DATA8(0, 0, 0, 72, 72, 0, 0, 0);
	Basic_DATA8(48, 48, 0, 0, 0, 16, 32, 0);
	Basic_DATA8(0, 0, 16, 64, 0, 0, 0, 16);
	Basic_DATA8(128, 0, 0, 0, 9, 0, 0, 0);
	Basic_DATA8(0, 7, 128, 0, 0, 0, 12, 124);
	Basic_DATA8(0, 0, 0, 25, 126, 0, 0, 0);
	Basic_DATA8(28, 254, 0, 0, 0, 31, 240, 0);
	Basic_DATA8(0, 0, 31, 128, 0, 0, 0, 15);
	Basic_DATA8(0, 0, 0, 0, 2, 0, 0, 0);
	Basic_DATA8(0, 31, 128, 0, 0, 0, 63, 192);
	Basic_DATA8(0, 0, 0, 127, 192, 0, 0, 0);
	Basic_DATA8(127, 0, 0, 0, 0, 126, 0, 0);
	Basic_DATA8(0, 0, 96, 0, 0, 0, 0, 240);
	Basic_DATA8(224, 0, 0, 0, 127, 128, 0, 0);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA4(70, 70, 70, 70);
	Basic_DATA5(8, 183, 0, 5, 4);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(24, 0, 0, 0, 0, 36, 6, 0);
	Basic_DATA8(0, 0, 36, 9, 0, 0, 0, 24);
	Basic_DATA8(9, 0, 0, 0, 4, 6, 0, 0);
	Basic_DATA8(0, 2, 8, 0, 0, 0, 3, 224);
	Basic_DATA8(0, 0, 0, 7, 24, 0, 0, 0);
	Basic_DATA8(14, 94, 0, 0, 0, 15, 63, 0);
	Basic_DATA8(0, 0, 15, 255, 128, 0, 0, 15);
	Basic_DATA8(231, 128, 0, 0, 7, 195, 0, 0);
	Basic_DATA8(0, 1, 128, 0, 0, 0, 15, 240);
	Basic_DATA8(0, 0, 0, 31, 252, 0, 0, 0);
	Basic_DATA8(31, 254, 0, 0, 0, 7, 252, 0);
	Basic_DATA8(0, 0, 7, 56, 0, 0, 0, 30);
	Basic_DATA8(0, 0, 0, 0, 24, 0, 0, 0);
	Basic_DATA8(0, 63, 128, 0, 0, 0, 0, 96);
	Basic_DATA8(0, 0, 0, 0, 48, 0, 0, 0);
	Basic_DATA8(0, 24, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA4(70, 70, 70, 70);
	Basic_DATA5(9, 183, 0, 5, 4);
	Basic_DATA8(0, 3, 0, 48, 0, 0, 4, 225);
	Basic_DATA8(200, 0, 0, 4, 146, 72, 0, 0);
	Basic_DATA8(3, 10, 48, 0, 0, 0, 62, 0);
	Basic_DATA8(0, 0, 0, 113, 240, 0, 0, 0);
	Basic_DATA8(229, 248, 0, 0, 0, 243, 248, 0);
	Basic_DATA8(0, 0, 255, 224, 0, 0, 0, 254);
	Basic_DATA8(0, 0, 0, 0, 124, 0, 0, 0);
	Basic_DATA8(0, 24, 0, 0, 0, 0, 255, 0);
	Basic_DATA8(0, 0, 1, 255, 192, 0, 0, 1);
	Basic_DATA8(255, 224, 0, 0, 0, 127, 192, 0);
	Basic_DATA8(0, 0, 97, 128, 0, 0, 1, 192);
	Basic_DATA8(0, 0, 0, 1, 128, 0, 0, 0);
	Basic_DATA8(3, 255, 128, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA4(70, 70, 70, 70);
	Basic_DATA5(10, 183, 0, 5, 4);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 6, 128);
	Basic_DATA8(0, 0, 0, 9, 64, 0, 0, 0);
	Basic_DATA8(9, 64, 0, 0, 0, 6, 128, 0);
	Basic_DATA8(0, 0, 2, 0, 0, 0, 0, 2);
	Basic_DATA8(0, 0, 0, 0, 2, 6, 0, 0);
	Basic_DATA8(0, 1, 31, 0, 0, 0, 7, 255);
	Basic_DATA8(0, 0, 0, 14, 62, 0, 0, 0);
	Basic_DATA8(28, 188, 0, 0, 0, 30, 112, 0);
	Basic_DATA8(0, 0, 31, 192, 0, 0, 0, 31);
	Basic_DATA8(192, 0, 0, 0, 15, 128, 0, 0);
	Basic_DATA8(0, 3, 0, 0, 0, 0, 15, 192);
	Basic_DATA8(0, 0, 0, 31, 224, 0, 0, 0);
	Basic_DATA8(31, 224, 0, 0, 0, 7, 224, 0);
	Basic_DATA8(0, 0, 14, 196, 0, 0, 0, 28);
	Basic_DATA8(24, 0, 0, 0, 28, 96, 0, 0);
	Basic_DATA8(0, 15, 128, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(0, 0, 0, 0, 0, 0, 0, 0);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA8(70, 70, 70, 70, 70, 70, 70, 70);
	Basic_DATA4(70, 70, 70, 70);
	Basic_DATA1(0);
	Laser_InitSpritesEx(LaserDemo_chudik, 740);
	Basic_BORDER(0);
	Basic_PAPER(0);
	Basic_CLS();
	LaserDemo_s = -2;
	LaserDemo__for__2 = 17;
	do {
		LaserDemo_n = 7;
		LaserDemo__for__1 = 4;
		do {
			Laser_PTBL(LaserDemo_s, 5, LaserDemo_n);
			Basic_PAUSE(5);
			LaserDemo_n += 1;
		} while (--LaserDemo__for__1);
		LaserDemo_s += 2;
	} while (--LaserDemo__for__2);
	Basic_Quit();
	__FINI;
}
