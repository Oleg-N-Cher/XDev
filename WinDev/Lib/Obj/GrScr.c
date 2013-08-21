/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "SdlLib.h"


export SdlLib_PSurface GrScr_Screen;
export BOOLEAN GrScr_MustLock;
export INTEGER GrScr_ActualWidth, GrScr_ActualHeight, GrScr_VirtualWidth, GrScr_VirtualHeight, GrScr_ActualMaxX, GrScr_ActualMaxY;
export SHORTINT GrScr_DepthBits;
export struct {
	LONGINT len[1];
	CHAR data[1];
} *GrScr_AppTitle;


export void GrScr_Close (void);
static INTEGER GrScr_TimeLeft (void);
export void GrScr_Update (void);
static void GrScr_WaitAClick (void);


static INTEGER GrScr_TimeLeft (void)
{
	INTEGER nextTime, now;
	nextTime = 0;
	now = SdlLib_GetTicks();
	if (nextTime <= now) {
		nextTime = now + 60;
		return 0;
	}
	return nextTime - now;
}

static void GrScr_WaitAClick (void)
{
	SdlLib_Event event;
	BOOLEAN done;
	done = 0;
	while (!done) {
		SdlLib_Delay(10);
		for (;;) {
			if (SdlLib_WaitEvent(&event, SdlLib_Event__typ) == 0) {
				break;
			}
			switch (__VAL(CHAR, event.type)) {
				case 0x02: 
					done = 1;
					goto exit__0;
					break;
				case 0x0c: 
					done = 1;
					goto exit__0;
					break;
				case 0x05: case 0x06: 
					done = 1;
					goto exit__0;
					break;
				default: 
					goto exit__0;
					break;
			}
		}
		exit__0:;
		SdlLib_PumpEvents();
		SdlLib_Delay(GrScr_TimeLeft());
	}
}

void GrScr_Close (void)
{
	GrScr_WaitAClick();
	SdlLib_Quit();
}

void GrScr_Update (void)
{
	if (SdlLib_Flip(GrScr_Screen)) {
	}
}


export void *GrScr__init(void)
{
	__DEFMOD;
	__IMPORT(GrConfig__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrScr", 0);
	__REGCMD("Close", GrScr_Close);
	__REGCMD("Update", GrScr_Update);
/* BEGIN */
	if (SdlLib_Init(0x20) < 0) {
		__HALT(1);
	}
	if (GrConfig_AppTitle != NIL) {
		SdlLib_WM_SetCaption((SdlLib_PChar)((LONGINT)&GrScr_AppTitle), NIL);
	}
	GrScr_Screen = SdlLib_SetVideoMode(GrScr_ActualWidth, GrScr_ActualHeight, GrScr_DepthBits, 0x40000000);
	if (GrScr_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	GrScr_MustLock = SdlLib_MustLock(GrScr_Screen);
	__ENDMOD;
}
