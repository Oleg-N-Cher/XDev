/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Asm.h"
#include "Basic.h"
#include "Input.h"
#include "Sound.h"


static INTEGER TestSnd_fx1, TestSnd_fx2, TestSnd_fx3, TestSnd_fx4, TestSnd_fx5, TestSnd_fx6, TestSnd_fx7;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Asm__init);
	__IMPORT(Basic__init);
	__IMPORT(Input__init);
	__IMPORT(Sound__init);
	__REGMAIN("TestSnd", 0);
/* BEGIN */
	Basic_Init();
	Basic_DEFDATA(TestSnd_fx1, 3);
	Basic_DATA3(253, 1, 0);
	Basic_DEFDATA(TestSnd_fx2, 13);
	Basic_DATA2(241, 79);
	Basic_DATA2(241, 71);
	Basic_DATA2(241, 56);
	Basic_DATA2(241, 56);
	Basic_DATA2(241, 106);
	Basic_DATA3(241, 106, 0);
	Basic_DEFDATA(TestSnd_fx3, 29);
	Basic_DATA2(241, 47);
	Basic_DATA2(241, 42);
	Basic_DATA2(241, 40);
	Basic_DATA2(241, 35);
	Basic_DATA2(241, 31);
	Basic_DATA2(241, 28);
	Basic_DATA2(241, 26);
	Basic_DATA2(241, 24);
	Basic_DATA2(241, 21);
	Basic_DATA2(241, 20);
	Basic_DATA2(241, 18);
	Basic_DATA2(241, 16);
	Basic_DATA2(241, 14);
	Basic_DATA3(241, 13, 0);
	Basic_DEFDATA(TestSnd_fx4, 15);
	Basic_DATA2(248, 3);
	Basic_DATA2(248, 223);
	Basic_DATA2(249, 214);
	Basic_DATA2(250, 235);
	Basic_DATA2(251, 130);
	Basic_DATA2(252, 204);
	Basic_DATA3(254, 61, 0);
	Basic_DEFDATA(TestSnd_fx5, 15);
	Basic_DATA2(241, 212);
	Basic_DATA2(241, 189);
	Basic_DATA2(241, 168);
	Basic_DATA2(241, 159);
	Basic_DATA2(241, 141);
	Basic_DATA2(241, 112);
	Basic_DATA3(241, 141, 0);
	Basic_DEFDATA(TestSnd_fx6, 89);
	Basic_DATA2(164, 79);
	Basic_DATA2(179, 243);
	Basic_DATA2(195, 161);
	Basic_DATA2(211, 123);
	Basic_DATA2(211, 54);
	Basic_DATA2(210, 248);
	Basic_DATA2(210, 193);
	Basic_DATA2(210, 168);
	Basic_DATA2(210, 121);
	Basic_DATA2(210, 80);
	Basic_DATA2(210, 61);
	Basic_DATA2(210, 27);
	Basic_DATA2(209, 252);
	Basic_DATA2(209, 224);
	Basic_DATA2(209, 212);
	Basic_DATA2(209, 189);
	Basic_DATA2(209, 168);
	Basic_DATA2(209, 159);
	Basic_DATA2(209, 141);
	Basic_DATA2(209, 126);
	Basic_DATA2(209, 112);
	Basic_DATA2(209, 106);
	Basic_DATA2(209, 94);
	Basic_DATA2(209, 84);
	Basic_DATA2(209, 79);
	Basic_DATA2(209, 71);
	Basic_DATA2(209, 63);
	Basic_DATA2(209, 56);
	Basic_DATA2(209, 53);
	Basic_DATA1(208);
	Basic_DATA2(15, 240);
	Basic_DATA1(176);
	Basic_DATA2(2, 240);
	Basic_DATA1(176);
	Basic_DATA2(2, 240);
	Basic_DATA1(176);
	Basic_DATA3(8, 241, 56);
	Basic_DATA1(176);
	Basic_DATA3(8, 241, 63);
	Basic_DATA1(176);
	Basic_DATA3(8, 241, 71);
	Basic_DATA1(176);
	Basic_DATA3(8, 241, 56);
	Basic_DATA1(176);
	Basic_DATA3(13, 241, 63);
	Basic_DATA2(176, 0);
	Basic_DEFDATA(TestSnd_fx7, 31);
	Basic_DATA3(3, 250, 235);
	Basic_DATA1(176);
	Basic_DATA2(3, 240);
	Basic_DATA1(176);
	Basic_DATA3(3, 249, 214);
	Basic_DATA1(176);
	Basic_DATA3(3, 250, 235);
	Basic_DATA1(176);
	Basic_DATA3(3, 249, 87);
	Basic_DATA1(176);
	Basic_DATA3(3, 250, 235);
	Basic_DATA1(176);
	Basic_DATA3(3, 249, 87);
	Basic_DATA1(176);
	Basic_DATA4(4, 248, 223, 0);
	Basic_IM2PROC(Sound_RunMe50Hz);
	Sound_Play(TestSnd_fx7);
	for (;;) {
		switch (Input_Read()) {
			case '1': 
				Sound_Play(TestSnd_fx1);
				break;
			case '2': 
				Sound_Play(TestSnd_fx2);
				break;
			case '3': 
				Sound_Play(TestSnd_fx3);
				break;
			case '4': 
				Sound_Play(TestSnd_fx4);
				break;
			case '5': 
				Sound_Play(TestSnd_fx5);
				break;
			case '6': 
				Sound_Play(TestSnd_fx6);
				break;
			case '7': 
				Sound_Play(TestSnd_fx7);
				break;
			default: __CASECHK;
		}
	}
	__FINI;
}
