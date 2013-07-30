/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "SdlLib.h"


export SdlLib_PSurface GrScr_Screen;
export BOOLEAN GrScr_mustLock;
export INTEGER GrScr_Black, GrScr_Blue, GrScr_Green, GrScr_Cyan, GrScr_Red, GrScr_Magenta, GrScr_Olive, GrScr_White;
static INTEGER GrScr_Gray;
export INTEGER GrScr_LightBlue, GrScr_LightGreen, GrScr_LightCyan, GrScr_LightRed, GrScr_LightMagenta, GrScr_Yellow, GrScr_LightWhite, GrScr_Orange;


export void GrScr_Close (void);
export void GrScr_Update (void);


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
	SdlLib_Flip(GrScr_Screen);
}

export void GrScr__init (void)
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
	SdlLib_WM_SetCaption(AppTitle, NIL);
	GrScr_Screen = SdlLib_SetVideoMode(ActualWidth, ActualHeight, DepthBits, 0x40000000);
	if (GrScr_Screen == NIL) {
		SdlLib_Quit();
		__HALT(1);
	}
	GrScr_mustLock = SdlLib_MustLock(GrScr_Screen);
	__ENDMOD;
}
