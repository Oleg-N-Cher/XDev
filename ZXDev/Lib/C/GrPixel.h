#ifndef GrPixel__h
#define GrPixel__h

#include "XDevCfg.h"
#include "GrApp.h"


extern void GrPixel_PutPixel_ROM (unsigned char x, unsigned char y);
extern void GrPixel_PutPixel_TBL (unsigned char x, unsigned char y);
extern void GrPixel_Line (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);

#ifdef GrPixel_PixelTable
#  define GrPixel_PutPixel GrPixel_PutPixel_TBL
   void GrPixel__init (void);
#else
#  define GrPixel__init()  GrApp__init()
#  define GrPixel_PutPixel GrPixel_PutPixel_ROM
#endif


#endif
