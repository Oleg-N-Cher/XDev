/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "GrScr.h"
#include "SdlLib.h"


static INTEGER GrPixel_ink, GrPixel_pitch;
export void (*GrPixel_PutPixel)(INTEGER, INTEGER);


static void GrPixel_PutPixel16 (INTEGER x, INTEGER y);
static void GrPixel_PutPixel24 (INTEGER x, INTEGER y);
static void GrPixel_PutPixel32 (INTEGER x, INTEGER y);
static void GrPixel_PutPixel8 (INTEGER x, INTEGER y);
export void GrPixel_SetInk (INTEGER color);


static void GrPixel_PutPixel8 (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (GrScr_mustLock && !SdlLib_LockSurface(GrScr_Screen)) {
			return;
		}
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)x, __VAL(SYSTEM_BYTE, GrPixel_ink), SYSTEM_BYTE);
		if (GrScr_mustLock) {
			SdlLib_UnlockSurface(GrScr_Screen);
		}
		SdlLib_UpdateRect(GrScr_Screen, x, y, 1, 1);
	}
}

static void GrPixel_PutPixel16 (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (GrScr_mustLock && !SdlLib_LockSurface(GrScr_Screen)) {
			return;
		}
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
		if (GrScr_mustLock) {
			SdlLib_UnlockSurface(GrScr_Screen);
		}
		SdlLib_UpdateRect(GrScr_Screen, x, y, 1, 1);
	}
}

static void GrPixel_PutPixel24 (INTEGER x, INTEGER y)
{
	LONGINT addr;
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (GrScr_mustLock && !SdlLib_LockSurface(GrScr_Screen)) {
			return;
		}
		addr = ((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)(x * 3);
		__PUT(addr, __VAL(SHORTINT, GrPixel_ink), SHORTINT);
		__PUT(addr + 2, (SYSTEM_BYTE)__LSHR(GrPixel_ink, 16, INTEGER), SYSTEM_BYTE);
		if (GrScr_mustLock) {
			SdlLib_UnlockSurface(GrScr_Screen);
		}
		SdlLib_UpdateRect(GrScr_Screen, x, y, 1, 1);
	}
}

static void GrPixel_PutPixel32 (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (GrScr_mustLock && !SdlLib_LockSurface(GrScr_Screen)) {
			return;
		}
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 2), GrPixel_ink, INTEGER);
		if (GrScr_mustLock) {
			SdlLib_UnlockSurface(GrScr_Screen);
		}
		SdlLib_UpdateRect(GrScr_Screen, x, y, 1, 1);
	}
}

void GrPixel_SetInk (INTEGER color)
{
	GrPixel_ink = color;
}


export void *GrPixel__init(void)
{
	__DEFMOD;
	__IMPORT(GrConfig__init);
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrPixel", 0);
/* BEGIN */
	GrPixel_pitch = GrScr_Screen->pitch;
	switch (__VAL(CHAR, GrScr_Screen->format->BytesPerPixel)) {
		case 0x01: 
			GrPixel_PutPixel = GrPixel_PutPixel8;
			break;
		case 0x02: 
			GrPixel_PutPixel = GrPixel_PutPixel16;
			break;
		case 0x03: 
			GrPixel_PutPixel = GrPixel_PutPixel24;
			break;
		case 0x04: 
			GrPixel_PutPixel = GrPixel_PutPixel32;
			break;
		default: 
			break;
	}
	__ENDMOD;
}
