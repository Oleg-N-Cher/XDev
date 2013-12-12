/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "SdlLib.h"


export SdlLib_PSurface GrScr_Screen;
export BOOLEAN GrScr_MustLock;
export INTEGER GrScr_ActualWidth, GrScr_ActualHeight, GrScr_VirtualWidth, GrScr_VirtualHeight, GrScr_ActualMaxX, GrScr_ActualMaxY;
export SHORTINT GrScr_DepthBits, GrScr_NormalColor;
export CHAR* GrScr_AppTitle;


export void GrScr_Close (void);
export void GrScr_Update (void);


void GrScr_Close (void)
{
	SdlLib_Quit();
}

void GrScr_Update (void)
{
	SdlLib_Flip(GrScr_Screen);
}

export void GrScr_Init (void)
{
	__DEFMOD;
	__IMPORT(SdlLib__init);
	__REGMOD("GrScr", 0);
	__REGCMD("Close", GrScr_Close);
	__REGCMD("Update", GrScr_Update);
/* BEGIN */
	if (SdlLib_Init(0x20) < 0) {
		__HALT(1);
	}
	SdlLib_WM_SetCaption((SdlLib_PChar)GrScr_AppTitle, NIL);
	GrScr_Screen = SdlLib_SetVideoMode(GrScr_ActualWidth, GrScr_ActualHeight, GrScr_DepthBits, 0x40000000);
	if (GrScr_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	GrScr_MustLock = SdlLib_MustLock(GrScr_Screen);
	GrScr_ActualMaxX = GrScr_ActualWidth - 1;
	GrScr_ActualMaxY = GrScr_ActualHeight - 1;
	__ENDMOD;
}
