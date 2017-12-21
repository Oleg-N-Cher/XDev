/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Input.h"
#include "GrApp.h"
#include "Sound.h"


static SdlMixer_PMix_Chunk TestSnd_EduinDied;




/*============================================================================*/

static void EnumPtrs(void (*P)(void*))
{
	P(TestSnd_EduinDied);
}


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Input__init);
	__IMPORT(GrApp__init);
	__IMPORT(Sound__init);
	__REGMAIN("TestSnd", EnumPtrs);
/* BEGIN */
	Sound_Load(&TestSnd_EduinDied, (void*)&"fx7.wav", (LONGINT)8);
	for (;;) {
		Sound_Play(TestSnd_EduinDied);
		if (Input_Read() == ' ') {
			break;
		}
	}
	Sound_Free(&TestSnd_EduinDied);
	Sound_Quit();
	__FINI;
}
