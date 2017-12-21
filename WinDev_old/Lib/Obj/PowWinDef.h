/*  Ofront 1.2 -xtspkae */

#ifndef PowWinDef__h
#define PowWinDef__h

#include "SYSTEM.h"

typedef
	INTEGER (*PowWinDef_FARPROC)(void);

typedef
	struct PowWinDef_RECT *PowWinDef_LPRECT;

typedef
	struct PowWinDef_RECTL *PowWinDef_LPCRECTL;

typedef
	struct PowWinDef_POINT *PowWinDef_LPPOINT;

typedef
	struct PowWinDef_POINTS *PowWinDef_LPPOINTS;

typedef
	struct PowWinDef_RECTL *PowWinDef_LPRECTL;

typedef
	struct PowWinDef_SIZE *PowWinDef_LPSIZE;

typedef
	struct PowWinDef_SIZEL *PowWinDef_LPSIZEL;

typedef
	INTEGER (*PowWinDef_NEARPROC)(void);

typedef
	struct PowWinDef_POINT *PowWinDef_NPPOINT;

typedef
	struct PowWinDef_RECT *PowWinDef_NPRECT;

typedef
	struct PowWinDef_POINT {
		INTEGER x, y;
	} PowWinDef_POINT;

typedef
	struct PowWinDef_POINTL {
		INTEGER x, y;
	} PowWinDef_POINTL;

typedef
	struct PowWinDef_POINTS {
		SHORTINT x, y;
	} PowWinDef_POINTS;

typedef
	PowWinDef_POINT *PowWinDef_PPOINT;

typedef
	PowWinDef_POINTL *PowWinDef_PPOINTL;

typedef
	PowWinDef_POINTS *PowWinDef_PPOINTS;

typedef
	struct PowWinDef_RECT *PowWinDef_PRECT;

typedef
	struct PowWinDef_RECTL *PowWinDef_PRECTL;

typedef
	INTEGER (*PowWinDef_PROC)(void);

typedef
	struct PowWinDef_SIZE *PowWinDef_PSIZE;

typedef
	struct PowWinDef_SIZEL *PowWinDef_PSIZEL;

typedef
	struct PowWinDef_RECT {
		INTEGER left, top, right, bottom;
	} PowWinDef_RECT;

typedef
	struct PowWinDef_RECTL {
		INTEGER left, top, right, bottom;
	} PowWinDef_RECTL;

typedef
	struct PowWinDef_SIZE {
		INTEGER cx, cy;
	} PowWinDef_SIZE;

typedef
	struct PowWinDef_SIZEL {
		INTEGER cx, cy;
	} PowWinDef_SIZEL;



import LONGINT *PowWinDef_RECT__typ;
import LONGINT *PowWinDef_RECTL__typ;
import LONGINT *PowWinDef_POINT__typ;
import LONGINT *PowWinDef_POINTL__typ;
import LONGINT *PowWinDef_SIZE__typ;
import LONGINT *PowWinDef_SIZEL__typ;
import LONGINT *PowWinDef_POINTS__typ;

import void *PowWinDef__init(void);

#define PowWinDef__init()	/*-noinit*/

#endif
