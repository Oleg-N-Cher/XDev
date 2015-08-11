/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Sdl2Lib.h"


static Sdl2Lib_Window TestSdl2_Screen;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Sdl2Lib__init);
	__REGMAIN("TestSdl2", 0);
/* BEGIN */
	if (Sdl2Lib_Init(0x20) < 0) {
		__HALT(1);
	}
	TestSdl2_Screen = Sdl2Lib_CreateWindow(NIL, 320, 240, 320, 240, 0);
	if (TestSdl2_Screen == NIL) {
		Sdl2Lib_Quit();
		__HALT(1);
	}
	Sdl2Lib_Delay(5000);
	Sdl2Lib_DestroyWindow(TestSdl2_Screen);
	Sdl2Lib_Quit();
	__FINI;
}
