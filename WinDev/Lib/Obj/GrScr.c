/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "SdlLib.h"


static SdlLib_PSurface GrScr_Screen;


export void GrScr_Close (void);


void GrScr_Close (void)
{
	SdlLib_Quit();
}


export void *GrScr__init(void)
{
	__DEFMOD;
	__IMPORT(GrConfig__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrScr", 0);
	__REGCMD("Close", GrScr_Close);
/* BEGIN */
	if (SdlLib_Init(0x20) < 0) {
		__HALT(1);
	}
	SdlLib_WM_SetCaption((SdlLib_PChar)((LONGINT)"XDev/SDL graphic"), NIL);
	GrScr_Screen = SdlLib_SetVideoMode(768, 576, 0, 0x0);
	if (GrScr_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	__ENDMOD;
}
