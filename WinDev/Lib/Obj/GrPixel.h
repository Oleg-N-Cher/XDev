/*  Ofront 1.2 -xtspkae */

#ifndef GrPixel__h
#define GrPixel__h

#include "SYSTEM.h"


import INTEGER GrPixel_ink;
import void (*GrPixel_Dot)(INTEGER, INTEGER), (*GrPixel_PutPixelNoLock)(INTEGER, INTEGER);


import void GrPixel_Circle (INTEGER cx, INTEGER cy, INTEGER radius);
import void GrPixel_Ink (INTEGER color);
import void GrPixel_Line (INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
import void *GrPixel__init(void);


#endif
