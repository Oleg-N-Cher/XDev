#include "SYSTEM.h"
#include "SdlLib.h"


export SdlLib_PSurface GrApp_Screen;
export BOOLEAN GrApp_MustLock;
export INTEGER GrApp_ActualWidth, GrApp_ActualHeight, GrApp_VirtualWidth, GrApp_VirtualHeight, GrApp_ActualMaxX, GrApp_ActualMaxY;
export SHORTINT GrApp_DepthBits, GrApp_NormalColor;
export CHAR* GrApp_AppTitle;


export void GrApp_Close (void);
export void GrApp_Update (void);


void GrApp_Close (void)
{
	SdlLib_Quit();
}

void GrApp_Update (void)
{
	SdlLib_Flip(GrApp_Screen);
}

export void GrApp_Init (void)
{
	__DEFMOD;
	__IMPORT(SdlLib__init);
	__REGMOD("GrApp", 0);
	__REGCMD("Close", GrApp_Close);
	__REGCMD("Update", GrApp_Update);
/* BEGIN */
	if (SdlLib_Init(0x20) < 0) {
		__HALT(1);
	}
	SdlLib_WM_SetCaption((SdlLib_PChar)GrApp_AppTitle, NIL);
	GrApp_Screen = SdlLib_SetVideoMode(GrApp_ActualWidth, GrApp_ActualHeight, GrApp_DepthBits, 0x40000000);
	if (GrApp_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	GrApp_MustLock = SdlLib_MustLock(GrApp_Screen);
	GrApp_ActualMaxX = GrApp_ActualWidth - 1;
	GrApp_ActualMaxY = GrApp_ActualHeight - 1;
	__ENDMOD;
}
