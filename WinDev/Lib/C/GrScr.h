/*  Ofront 1.2 -xtspkae */

#ifndef GrScr__h
#define GrScr__h

#include "SYSTEM.h"
#include "SdlLib.h"


import SdlLib_PSurface GrScr_Screen;
import BOOLEAN GrScr_MustLock;
import INTEGER GrScr_ActualWidth, GrScr_ActualHeight, GrScr_VirtualWidth, GrScr_VirtualHeight, GrScr_ActualMaxX, GrScr_ActualMaxY;
import SHORTINT GrScr_DepthBits, GrScr_NormalColor;
import CHAR* GrScr_AppTitle;


#define GrScr_Black
#define GrScr_Blue
#define GrScr_Green
#define GrScr_Cyan
#define GrScr_Red
#define GrScr_Magenta
#define GrScr_Olive
#define GrScr_White
#define GrScr_LightBlue
#define GrScr_LightGreen
#define GrScr_LightCyan
#define GrScr_LightRed
#define GrScr_LightMagenta
#define GrScr_Yellow
#define GrScr_LightWhite
#define GrScr_Orange


import void GrScr_Close (void);
import void GrScr_Update (void);
#define GrScr__init()


#endif
