/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "GrApp.h"


export INTEGER XYplane_X, XYplane_Y, XYplane_W, XYplane_H;


export void XYplane_Clear (void);
static void XYplane_Dot (INTEGER x, INTEGER y, INTEGER mode);
static BOOLEAN XYplane_IsDot (INTEGER x, INTEGER y);
static CHAR XYplane_Key (void);
export void XYplane_Open (void);


/*============================================================================*/

void XYplane_Open (void)
{
}

/*----------------------------------------------------------------------------*/
void XYplane_Clear (void)
{
}

/*----------------------------------------------------------------------------*/
static void XYplane_Dot (INTEGER x, INTEGER y, INTEGER mode)
{
}

static BOOLEAN XYplane_IsDot (INTEGER x, INTEGER y)
{
	__RETCHK;
}

static CHAR XYplane_Key (void)
{
	__RETCHK;
}


export void *XYplane__init(void)
{
	__DEFMOD;
	__IMPORT(GrApp__init);
	__REGMOD("XYplane", 0);
	__REGCMD("Clear", XYplane_Clear);
	__REGCMD("Open", XYplane_Open);
/* BEGIN */
	__ENDMOD;
}
