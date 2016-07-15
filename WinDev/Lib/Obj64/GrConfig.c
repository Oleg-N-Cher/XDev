/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *GrConfig_PChar;


export GrConfig_PChar GrConfig_AppTitle;
export INTEGER GrConfig_VirtualWidth, GrConfig_VirtualHeight, GrConfig_VirtualMaxX, GrConfig_VirtualMaxY, GrConfig_ActualWidth, GrConfig_ActualHeight, GrConfig_ActualMaxX, GrConfig_ActualMaxY;
export SHORTINT GrConfig_DepthBits;




/*============================================================================*/


export void *GrConfig__init(void)
{
	__DEFMOD;
	__REGMOD("GrConfig", 0);
/* BEGIN */
	GrConfig_VirtualWidth = 256;
	GrConfig_VirtualHeight = 192;
	GrConfig_VirtualMaxX = GrConfig_VirtualWidth - 1;
	GrConfig_VirtualMaxY = GrConfig_VirtualHeight - 1;
	GrConfig_ActualWidth = GrConfig_VirtualWidth * 3;
	GrConfig_ActualHeight = GrConfig_VirtualHeight * 3;
	GrConfig_ActualMaxX = GrConfig_ActualWidth - 1;
	GrConfig_ActualMaxY = GrConfig_ActualHeight - 1;
	GrConfig_DepthBits = 0;
	GrConfig_AppTitle = (GrConfig_PChar)((LONGINT)"XDev/SDL graphic");
	__ENDMOD;
}
