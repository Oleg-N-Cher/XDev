#ifndef __GrConfig__h
#define __GrConfig__h


/* Virtual Width, Height in pixels: */
#define VirtualWidth	128
#define VirtualHeight	96

/* Actual Width, Height in pixels: */
#define ActualWidth	256
#define ActualHeight	192
#define MaxActualX	(ActualWidth - 1)
#define MaxActualY	(ActualHeight - 1)

/* Depth in bits per pixel (8, 16, or 32): */
#define AutoDetect	0
#define DepthBits	AutoDetect

#define AppTitle "XDev/SDL graphic"

#define ChkOutOfScreen	1


#define GrConfig__init()

#endif __GrConfig__h
