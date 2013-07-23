/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "GrScr.h"
#include "SdlLib.h"


export INTEGER GrPixel_ink;
static INTEGER GrPixel_pitch;
static void (*GrPixel_PutActualPixelNoLock)(INTEGER, INTEGER);
export void (*GrPixel_PutPixel)(INTEGER, INTEGER), (*GrPixel_PutPixelNoLock)(INTEGER, INTEGER);


static void GrPixel_PutActualPixel16Lock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel16NoLock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel24Lock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel24NoLock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel32Lock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel32NoLock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel8Lock (INTEGER x, INTEGER y);
static void GrPixel_PutActualPixel8NoLock (INTEGER x, INTEGER y);
static void GrPixel_PutVirtualPixelLock (INTEGER x, INTEGER y);
static void GrPixel_PutVirtualPixelNoLock (INTEGER x, INTEGER y);
export void GrPixel_SetInk (INTEGER color);


static void GrPixel_PutActualPixel8Lock (INTEGER x, INTEGER y)
{
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)x, __VAL(SYSTEM_BYTE, GrPixel_ink), SYSTEM_BYTE);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel8NoLock (INTEGER x, INTEGER y)
{
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)x, __VAL(SYSTEM_BYTE, GrPixel_ink), SYSTEM_BYTE);
	}
}

static void GrPixel_PutActualPixel16Lock (INTEGER x, INTEGER y)
{
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel16NoLock (INTEGER x, INTEGER y)
{
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
	}
}

static void GrPixel_PutActualPixel24Lock (INTEGER x, INTEGER y)
{
	LONGINT addr;
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			addr = ((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)(x * 3);
			__PUT(addr, __VAL(SHORTINT, GrPixel_ink), SHORTINT);
			__PUT(addr + 2, (SYSTEM_BYTE)__LSHR(GrPixel_ink, 16, INTEGER), SYSTEM_BYTE);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel24NoLock (INTEGER x, INTEGER y)
{
	LONGINT addr;
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		addr = ((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)(x * 3);
		__PUT(addr, __VAL(SHORTINT, GrPixel_ink), SHORTINT);
		__PUT(addr + 2, (SYSTEM_BYTE)__LSHR(GrPixel_ink, 16, INTEGER), SYSTEM_BYTE);
	}
}

static void GrPixel_PutActualPixel32Lock (INTEGER x, INTEGER y)
{
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 2), GrPixel_ink, INTEGER);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel32NoLock (INTEGER x, INTEGER y)
{
	if (!(((x < 0 || x > 767) || y < 0) || y > 575)) {
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 2), GrPixel_ink, INTEGER);
	}
}

static void GrPixel_PutVirtualPixelLock (INTEGER x, INTEGER y)
{
	INTEGER xActual, yActual, xTemp, xNext, yNext;
	xActual = __ASHR(x * 768, 8);
	yActual = __DIV(y * 576, 192);
	xNext = __ASHR((x + 1) * 768, 8);
	yNext = __DIV((y + 1) * 576, 192);
	if (SdlLib_LockSurface(GrScr_Screen)) {
		while (yActual != yNext) {
			xTemp = xActual;
			while (xTemp != xNext) {
				(*GrPixel_PutActualPixelNoLock)(xTemp, yActual);
				xTemp += 1;
			}
			yActual += 1;
		}
		SdlLib_UnlockSurface(GrScr_Screen);
	}
}

static void GrPixel_PutVirtualPixelNoLock (INTEGER x, INTEGER y)
{
	INTEGER xActual, yActual, xTemp, xNext, yNext;
	xActual = __ASHR(x * 768, 8);
	yActual = __DIV(y * 576, 192);
	xNext = __ASHR((x + 1) * 768, 8);
	yNext = __DIV((y + 1) * 576, 192);
	while (yActual != yNext) {
		xTemp = xActual;
		while (xTemp != xNext) {
			(*GrPixel_PutActualPixelNoLock)(xTemp, yActual);
			xTemp += 1;
		}
		yActual += 1;
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
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel8NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel8NoLock;
			if (GrScr_mustLock) {
				GrPixel_PutPixel = GrPixel_PutActualPixel8Lock;
			} else {
				GrPixel_PutPixel = GrPixel_PutActualPixel8NoLock;
			}
			break;
		case 0x02: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel16NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel16NoLock;
			if (GrScr_mustLock) {
				GrPixel_PutPixel = GrPixel_PutActualPixel16Lock;
			} else {
				GrPixel_PutPixel = GrPixel_PutActualPixel16NoLock;
			}
			break;
		case 0x03: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel24NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel24NoLock;
			if (GrScr_mustLock) {
				GrPixel_PutPixel = GrPixel_PutActualPixel24Lock;
			} else {
				GrPixel_PutPixel = GrPixel_PutActualPixel24NoLock;
			}
			break;
		case 0x04: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel32NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel32NoLock;
			if (GrScr_mustLock) {
				GrPixel_PutPixel = GrPixel_PutActualPixel32Lock;
			} else {
				GrPixel_PutPixel = GrPixel_PutActualPixel32NoLock;
			}
			break;
		default: 
			break;
	}
	GrPixel_PutPixelNoLock = GrPixel_PutVirtualPixelNoLock;
	if (GrScr_mustLock) {
		GrPixel_PutPixel = GrPixel_PutVirtualPixelLock;
	} else {
		GrPixel_PutPixel = GrPixel_PutVirtualPixelNoLock;
	}
	__ENDMOD;
}
