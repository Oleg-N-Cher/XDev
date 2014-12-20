/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"
#include "Control.h"
#include "Laser.h"


static SET TestCtrl_pressed;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Control__init);
	__IMPORT(Laser__init);
	__REGMAIN("TestCtrl", 0);
/* BEGIN */
	Basic_CLS();
	for (;;) {
		TestCtrl_pressed = Control_Get();
		if (__IN(1, TestCtrl_pressed)) {
			Basic_PAPER(4);
		} else {
			Basic_PAPER(0);
		}
		Laser_SETV(0, 8, 10, 8);
		if (__IN(0, TestCtrl_pressed)) {
			Basic_PAPER(6);
		} else {
			Basic_PAPER(0);
		}
		Laser_SETV(22, 8, 10, 8);
		if (__IN(3, TestCtrl_pressed)) {
			Basic_PAPER(5);
		} else {
			Basic_PAPER(0);
		}
		Laser_SETV(10, 0, 12, 8);
		if (__IN(2, TestCtrl_pressed)) {
			Basic_PAPER(3);
		} else {
			Basic_PAPER(0);
		}
		Laser_SETV(10, 16, 12, 8);
		if (__IN(4, TestCtrl_pressed)) {
			Basic_BORDER(2);
		} else {
			Basic_BORDER(0);
		}
	}
	__FINI;
}
