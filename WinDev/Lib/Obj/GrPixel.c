/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrConfig.h"
#include "GrScr.h"
#include "SdlLib.h"


export INTEGER GrPixel_ink;
static INTEGER GrPixel_pitch;
static void (*GrPixel_PutActualPixelNoLock)(INTEGER, INTEGER);
export void (*GrPixel_Dot)(INTEGER, INTEGER), (*GrPixel_PutPixelNoLock)(INTEGER, INTEGER);


export void GrPixel_Circle (INTEGER cx, INTEGER cy, INTEGER radius);
static INTEGER GrPixel_GetSign (INTEGER x);
export void GrPixel_Ink (INTEGER color);
export void GrPixel_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
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


static void GrPixel_PutActualPixel8Lock (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)x, __VAL(SYSTEM_BYTE, GrPixel_ink), SYSTEM_BYTE);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel8NoLock (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)x, __VAL(SYSTEM_BYTE, GrPixel_ink), SYSTEM_BYTE);
	}
}

static void GrPixel_PutActualPixel16Lock (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel16NoLock (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
	}
}

static void GrPixel_PutActualPixel24Lock (INTEGER x, INTEGER y)
{
	LONGINT addr;
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
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
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		addr = ((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)(x * 3);
		__PUT(addr, __VAL(SHORTINT, GrPixel_ink), SHORTINT);
		__PUT(addr + 2, (SYSTEM_BYTE)__LSHR(GrPixel_ink, 16, INTEGER), SYSTEM_BYTE);
	}
}

static void GrPixel_PutActualPixel32Lock (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
		if (SdlLib_LockSurface(GrScr_Screen)) {
			__PUT(((LONGINT)GrScr_Screen->pixels + (LONGINT)(y * GrPixel_pitch)) + (LONGINT)__ASHL(x, 2), GrPixel_ink, INTEGER);
			SdlLib_UnlockSurface(GrScr_Screen);
		}
	}
}

static void GrPixel_PutActualPixel32NoLock (INTEGER x, INTEGER y)
{
	if (((x >= 0 && x <= 767) && y >= 0) && y <= 575) {
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

void GrPixel_Ink (INTEGER color)
{
	GrPixel_ink = color;
}

static INTEGER GrPixel_GetSign (INTEGER x)
{
	if (x >= 0) {
		return 1;
	}
	return -1;
}

void GrPixel_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2)
{
	INTEGER dx, dy, sdx, sdy, x, y, px, py;
	dx = x2 - x1;
	dy = y2 - y1;
	sdx = GrPixel_GetSign(dx);
	sdy = GrPixel_GetSign(dy);
	dx = sdx * dx + 1;
	dy = sdy * dy + 1;
	x = 0;
	y = 0;
	px = x1;
	py = y1;
	if (dx >= dy) {
		x = 0;
		while (x < dx) {
			(*GrPixel_Dot)(px, py);
			y += dy;
			if (y >= dx) {
				y -= dx;
				py += sdy;
			}
			px += sdx;
			x += 1;
		}
	} else {
		y = 0;
		while (y < dy) {
			(*GrPixel_Dot)(px, py);
			x += dx;
			if (x >= dy) {
				x -= dy;
				px += sdx;
			}
			py += sdy;
			y += 1;
		}
	}
}

static struct Circle__1 {
	INTEGER *cx, *cy;
	INTEGER *x, *y;
	struct Circle__1 *lnk;
} *Circle__1_s;

static void Cursors__2 (void);

static void Cursors__2 (void)
{
	(*GrPixel_Dot)(*Circle__1_s->cx + *Circle__1_s->x, *Circle__1_s->cy + *Circle__1_s->y);
	(*GrPixel_Dot)(*Circle__1_s->cx - *Circle__1_s->x, *Circle__1_s->cy + *Circle__1_s->y);
	(*GrPixel_Dot)(*Circle__1_s->cx + *Circle__1_s->x, *Circle__1_s->cy - *Circle__1_s->y);
	(*GrPixel_Dot)(*Circle__1_s->cx - *Circle__1_s->x, *Circle__1_s->cy - *Circle__1_s->y);
	(*GrPixel_Dot)(*Circle__1_s->cx + *Circle__1_s->y, *Circle__1_s->cy + *Circle__1_s->x);
	(*GrPixel_Dot)(*Circle__1_s->cx - *Circle__1_s->y, *Circle__1_s->cy + *Circle__1_s->x);
	(*GrPixel_Dot)(*Circle__1_s->cx + *Circle__1_s->y, *Circle__1_s->cy - *Circle__1_s->x);
	(*GrPixel_Dot)(*Circle__1_s->cx - *Circle__1_s->y, *Circle__1_s->cy - *Circle__1_s->x);
}

void GrPixel_Circle (INTEGER cx, INTEGER cy, INTEGER radius)
{
	INTEGER x, y, rr, xx, yy;
	struct Circle__1 _s;
	_s.cx = &cx;
	_s.cy = &cy;
	_s.x = &x;
	_s.y = &y;
	_s.lnk = Circle__1_s;
	Circle__1_s = &_s;
	x = radius;
	y = 0;
	rr = x * x;
	xx = rr - x;
	yy = 0;
	do {
		Cursors__2();
		yy += (y + y) + 1;
		y += 1;
		if (xx > rr - yy) {
			xx += (1 - x) - x;
			x -= 1;
			Cursors__2();
		}
	} while (!(x < y));
	Circle__1_s = _s.lnk;
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
				GrPixel_Dot = GrPixel_PutActualPixel8Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel8NoLock;
			}
			break;
		case 0x02: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel16NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel16NoLock;
			if (GrScr_mustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel16Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel16NoLock;
			}
			break;
		case 0x03: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel24NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel24NoLock;
			if (GrScr_mustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel24Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel24NoLock;
			}
			break;
		case 0x04: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel32NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel32NoLock;
			if (GrScr_mustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel32Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel32NoLock;
			}
			break;
		default: 
			break;
	}
	GrPixel_PutPixelNoLock = GrPixel_PutVirtualPixelNoLock;
	if (GrScr_mustLock) {
		GrPixel_Dot = GrPixel_PutVirtualPixelLock;
	} else {
		GrPixel_Dot = GrPixel_PutVirtualPixelNoLock;
	}
	__ENDMOD;
}
