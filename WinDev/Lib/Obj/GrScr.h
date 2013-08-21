/*  Ofront 1.2 -xtspkae */

#ifndef GrScr__h
#define GrScr__h

#include "SYSTEM.h"
#include "SdlLib.h"


import SdlLib_PSurface GrScr_Screen;
import BOOLEAN GrScr_MustLock;
import INTEGER GrScr_ActualWidth, GrScr_ActualHeight, GrScr_VirtualWidth, GrScr_VirtualHeight, GrScr_ActualMaxX, GrScr_ActualMaxY;
import SHORTINT GrScr_DepthBits;
import struct {
	LONGINT len[1];
	CHAR data[1];
} *GrScr_AppTitle;


import void GrScr_Close (void);
import void GrScr_Update (void);
import void *GrScr__init(void);


#endif
