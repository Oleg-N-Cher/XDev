#ifndef GrApp__h
#define GrApp__h

#include "SYSTEM.h"
#include "SdlLib.h"


import SdlLib_PSurface GrApp_Screen;
import BOOLEAN GrApp_MustLock;
import INTEGER GrApp_ActualWidth, GrApp_ActualHeight, GrApp_VirtualWidth, GrApp_VirtualHeight, GrApp_ActualMaxX, GrApp_ActualMaxY;
import SHORTINT GrApp_DepthBits, GrApp_NormalColor;
import CHAR* GrApp_AppTitle;


#define GrApp_Black
#define GrApp_Blue
#define GrApp_Green
#define GrApp_Cyan
#define GrApp_Red
#define GrApp_Magenta
#define GrApp_Olive
#define GrApp_White
#define GrApp_LightBlue
#define GrApp_LightGreen
#define GrApp_LightCyan
#define GrApp_LightRed
#define GrApp_LightMagenta
#define GrApp_Yellow
#define GrApp_LightWhite
#define GrApp_Orange


import void GrApp_Close (void);
import void GrApp_Update (void);
#define GrApp__init()


#endif
