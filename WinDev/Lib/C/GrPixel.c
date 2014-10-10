#include "SYSTEM.h"
#include "GrConfig.h"
#include "GrApp.h"
#include "SdlLib.h"

import INTEGER GrPixel_ink;
import void (*GrPixel_Dot)(INTEGER, INTEGER);
import void (*GrPixel_PutPixelNoLock)(INTEGER, INTEGER);
import void (*GrPixel_PutActualPixelNoLock)(INTEGER, INTEGER);
import INTEGER GrPixel_pitch;

export void GrPixel_Circle (INTEGER cx, INTEGER cy, INTEGER radius);
export void GrPixel_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
export void GrPixel_Ink (INTEGER color);

void GrPixel_PutActualPixel16Lock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel16NoLock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel24Lock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel24NoLock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel32Lock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel32NoLock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel8Lock (INTEGER x, INTEGER y);
void GrPixel_PutActualPixel8NoLock (INTEGER x, INTEGER y);
void GrPixel_PutVirtualPixelLock (INTEGER x, INTEGER y);
void GrPixel_PutVirtualPixelNoLock (INTEGER x, INTEGER y);
INTEGER GrPixel_GetSign (INTEGER x);

/*================================== Header ==================================*/
export INTEGER GrPixel_ink;
/*--------------------------------- Cut here ---------------------------------*/
INTEGER GrPixel_pitch;
/*--------------------------------- Cut here ---------------------------------*/
void (*GrPixel_PutActualPixelNoLock)(INTEGER, INTEGER);
/*--------------------------------- Cut here ---------------------------------*/
export void (*GrPixel_Dot)(INTEGER, INTEGER), (*GrPixel_PutPixelNoLock)(INTEGER, INTEGER);

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel8Lock (INTEGER x, INTEGER y)
{
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		if (SdlLib_LockSurface(GrApp_Screen)) {
			__PUT((GrApp_Screen->pixels + (y * GrPixel_pitch)) + x, __VAL(BYTE, GrPixel_ink), BYTE);
			SdlLib_UnlockSurface(GrApp_Screen);
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel8NoLock (INTEGER x, INTEGER y)
{
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		__PUT((GrApp_Screen->pixels + (y * GrPixel_pitch)) + x, __VAL(BYTE, GrPixel_ink), BYTE);
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel16Lock (INTEGER x, INTEGER y)
{
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		if (SdlLib_LockSurface(GrApp_Screen)) {
			__PUT((GrApp_Screen->pixels + (y * GrPixel_pitch)) + __ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
			SdlLib_UnlockSurface(GrApp_Screen);
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel16NoLock (INTEGER x, INTEGER y)
{
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		__PUT((GrApp_Screen->pixels + (y * GrPixel_pitch)) + __ASHL(x, 1), __VAL(SHORTINT, GrPixel_ink), SHORTINT);
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel24Lock (INTEGER x, INTEGER y)
{
	SYSTEM_ADDRESS addr;
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		if (SdlLib_LockSurface(GrApp_Screen)) {
			addr = ((SYSTEM_ADDRESS)GrApp_Screen->pixels + (SYSTEM_ADDRESS)(y * GrPixel_pitch)) + (SYSTEM_ADDRESS)(x * 3);
			__PUT(addr, __VAL(SHORTINT, GrPixel_ink), SHORTINT);
			__PUT(addr + 2, (BYTE)__LSHR(GrPixel_ink, 16, INTEGER), BYTE);
			SdlLib_UnlockSurface(GrApp_Screen);
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel24NoLock (INTEGER x, INTEGER y)
{
	SYSTEM_ADDRESS addr;
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		addr = ((SYSTEM_ADDRESS)GrApp_Screen->pixels + (SYSTEM_ADDRESS)(y * GrPixel_pitch)) + (SYSTEM_ADDRESS)(x * 3);
		__PUT(addr, __VAL(SHORTINT, GrPixel_ink), SHORTINT);
		__PUT(addr + 2, (BYTE)__LSHR(GrPixel_ink, 16, INTEGER), BYTE);
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel32Lock (INTEGER x, INTEGER y)
{
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		if (SdlLib_LockSurface(GrApp_Screen)) {
			__PUT(((SYSTEM_ADDRESS)GrApp_Screen->pixels + (SYSTEM_ADDRESS)(y * GrPixel_pitch)) + (SYSTEM_ADDRESS)__ASHL(x, 2), GrPixel_ink, INTEGER);
			SdlLib_UnlockSurface(GrApp_Screen);
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutActualPixel32NoLock (INTEGER x, INTEGER y)
{
	if ((!ChkOutOfScreen) || (x>=0 && x<=GrApp_ActualMaxX && y>=0 && y<=GrApp_ActualMaxY)) {
		__PUT(((SYSTEM_ADDRESS)GrApp_Screen->pixels + (SYSTEM_ADDRESS)(y * GrPixel_pitch)) + (SYSTEM_ADDRESS)__ASHL(x, 2), GrPixel_ink, INTEGER);
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutVirtualPixelLock (INTEGER x, INTEGER y)
{
	INTEGER xActual, yActual, xTemp, xNext, yNext;
	xActual = x * GrApp_ActualWidth / GrApp_VirtualWidth;
	yActual = y * GrApp_ActualHeight / GrApp_VirtualHeight;
	xNext = (x + 1) * GrApp_ActualWidth / GrApp_VirtualWidth;
	yNext = (y + 1) * GrApp_ActualHeight / GrApp_VirtualHeight;
	if (SdlLib_LockSurface(GrApp_Screen)) {
		while (yActual != yNext) {
			xTemp = xActual;
			while (xTemp != xNext) {
				(*GrPixel_PutActualPixelNoLock)(xTemp, yActual);
				xTemp += 1;
			}
			yActual += 1;
		}
		SdlLib_UnlockSurface(GrApp_Screen);
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutVirtualPixelNoLock (INTEGER x, INTEGER y)
{
	INTEGER xActual, yActual, xTemp, xNext, yNext;
	xActual = x * GrApp_ActualWidth / GrApp_VirtualWidth;
	yActual = y * GrApp_ActualHeight / GrApp_VirtualHeight;
	xNext = (x + 1) * GrApp_ActualWidth / GrApp_VirtualWidth;
	yNext = (y + 1) * GrApp_ActualHeight / GrApp_VirtualHeight;
	while (yActual != yNext) {
		xTemp = xActual;
		while (xTemp != xNext) {
			(*GrPixel_PutActualPixelNoLock)(xTemp, yActual);
			xTemp += 1;
		}
		yActual += 1;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_Ink (INTEGER color)
{
	GrPixel_ink = color;
}

/*--------------------------------- Cut here ---------------------------------*/
INTEGER GrPixel_GetSign (INTEGER x)
{
	if (x >= 0) {
		return 1;
	}
	return -1;
}

/*--------------------------------- Cut here ---------------------------------*/
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

/*--------------------------------- Cut here ---------------------------------*/
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

/*--------------------------------- Cut here ---------------------------------*/

export void GrPixel__init (void)
{
	__DEFMOD;
	__IMPORT(GrApp__init);
	__IMPORT(SdlLib__init);
	__REGMOD("GrPixel", 0);
/* BEGIN */
	GrPixel_pitch = GrApp_Screen->pitch;
	switch (__VAL(CHAR, GrApp_Screen->format->BytesPerPixel)) {
		case 0x01: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel8NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel8NoLock;
			if (GrApp_MustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel8Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel8NoLock;
			}
			break;
		case 0x02: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel16NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel16NoLock;
			if (GrApp_MustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel16Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel16NoLock;
			}
			break;
		case 0x03: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel24NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel24NoLock;
			if (GrApp_MustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel24Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel24NoLock;
			}
			break;
		case 0x04: 
			GrPixel_PutActualPixelNoLock = GrPixel_PutActualPixel32NoLock;
			GrPixel_PutPixelNoLock = GrPixel_PutActualPixel32NoLock;
			if (GrApp_MustLock) {
				GrPixel_Dot = GrPixel_PutActualPixel32Lock;
			} else {
				GrPixel_Dot = GrPixel_PutActualPixel32NoLock;
			}
			break;
		default:
			break;
	}
  if ((GrApp_ActualWidth != GrApp_VirtualWidth) || (GrApp_ActualHeight != GrApp_VirtualHeight)) {
		GrPixel_PutPixelNoLock = GrPixel_PutVirtualPixelNoLock;
		if (GrApp_MustLock) {
			GrPixel_Dot = GrPixel_PutVirtualPixelLock;
		} else {
			GrPixel_Dot = GrPixel_PutVirtualPixelNoLock;
		}
  }
	__ENDMOD;
}
