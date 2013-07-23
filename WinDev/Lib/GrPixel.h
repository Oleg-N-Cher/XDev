/*  Ofront 1.2 -xtspkae */

#ifndef GrPixel__h
#define GrPixel__h

#include "SYSTEM.h"


import INTEGER GrPixel_ink;
import void (*GrPixel_PutPixel)(INTEGER, INTEGER), (*GrPixel_PutPixelNoLock)(INTEGER, INTEGER);


import void GrPixel_SetInk (INTEGER color);
import void *GrPixel__init(void);


#endif
