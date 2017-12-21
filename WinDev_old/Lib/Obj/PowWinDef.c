/*  Ofront 1.2 -xtspkae */
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



export LONGINT *PowWinDef_RECT__typ;
export LONGINT *PowWinDef_RECTL__typ;
export LONGINT *PowWinDef_POINT__typ;
export LONGINT *PowWinDef_POINTL__typ;
export LONGINT *PowWinDef_SIZE__typ;
export LONGINT *PowWinDef_SIZEL__typ;
export LONGINT *PowWinDef_POINTS__typ;


#define PowWinDef__init()	/*-noinit*/

/*============================================================================*/

__TDESC(PowWinDef_RECT__desc, 1, 0) = {__TDFLDS("RECT", 16), {-8}};
__TDESC(PowWinDef_RECTL__desc, 1, 0) = {__TDFLDS("RECTL", 16), {-8}};
__TDESC(PowWinDef_POINT__desc, 1, 0) = {__TDFLDS("POINT", 8), {-8}};
__TDESC(PowWinDef_POINTL__desc, 1, 0) = {__TDFLDS("POINTL", 8), {-8}};
__TDESC(PowWinDef_SIZE__desc, 1, 0) = {__TDFLDS("SIZE", 8), {-8}};
__TDESC(PowWinDef_SIZEL__desc, 1, 0) = {__TDFLDS("SIZEL", 8), {-8}};
__TDESC(PowWinDef_POINTS__desc, 1, 0) = {__TDFLDS("POINTS", 4), {-8}};

export void *PowWinDef__init(void)
{
	__DEFMOD;
	__REGMOD("PowWinDef", 0);
	__INITYP(PowWinDef_RECT, PowWinDef_RECT, 0);
	__INITYP(PowWinDef_RECTL, PowWinDef_RECTL, 0);
	__INITYP(PowWinDef_POINT, PowWinDef_POINT, 0);
	__INITYP(PowWinDef_POINTL, PowWinDef_POINTL, 0);
	__INITYP(PowWinDef_SIZE, PowWinDef_SIZE, 0);
	__INITYP(PowWinDef_SIZEL, PowWinDef_SIZEL, 0);
	__INITYP(PowWinDef_POINTS, PowWinDef_POINTS, 0);
/* BEGIN */
	__ENDMOD;
}
