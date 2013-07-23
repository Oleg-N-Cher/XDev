/*  Ofront 1.2 -xtspkae */

#ifndef SdlLib__h
#define SdlLib__h

#include "SYSTEM.h"

typedef
	struct SdlLib_Color {
		SYSTEM_BYTE r, g, b, unused;
	} SdlLib_Color;

typedef
	SdlLib_Color SdlLib_ColorArray[65001];

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *SdlLib_PChar;

typedef
	SdlLib_Color *SdlLib_PColor;

typedef
	SdlLib_ColorArray *SdlLib_PColorArray;

typedef
	struct SdlLib_Rect *SdlLib_PRect;

typedef
	struct {
		LONGINT len[1];
		SdlLib_PRect data[1];
	} *SdlLib_PPRect;

typedef
	struct SdlLib_Palette *SdlLib_PPalette;

typedef
	struct SdlLib_PixelFormat *SdlLib_PPixelFormat;

typedef
	struct SdlLib_Surface *SdlLib_PSurface;

typedef
	struct SdlLib_Palette {
		INTEGER ncolors;
		SdlLib_PColorArray colors;
	} SdlLib_Palette;

typedef
	struct SdlLib_PixelFormat {
		SdlLib_PPalette palette;
		SYSTEM_BYTE BitsPerPixel, BytesPerPixel, Rloss, Gloss, Bloss, Aloss, Rshift, Gshift, Bshift, Ashift;
		INTEGER Rmask, Gmask, Bmask, Amask, colorkey;
		SYSTEM_BYTE alpha;
	} SdlLib_PixelFormat;

typedef
	struct {
		LONGINT len[1];
		SYSTEM_BYTE data[1];
	} *SdlLib_Pointer;

typedef
	struct SdlLib_Rect {
		SHORTINT x, y, w, h;
	} SdlLib_Rect;

typedef
	struct SdlLib_Surface {
		SET flags;
		SdlLib_PPixelFormat format;
		INTEGER w, h;
		SHORTINT pitch;
		SdlLib_Pointer pixels;
		INTEGER offset;
		SdlLib_Pointer hwdata;
		SdlLib_Rect clip_rect;
		char _prvt0[4];
		INTEGER locked;
		SdlLib_Pointer map;
		INTEGER format_version, refcount;
	} SdlLib_Surface;



import LONGINT *SdlLib_Rect__typ;
import LONGINT *SdlLib_Color__typ;
import LONGINT *SdlLib_Palette__typ;
import LONGINT *SdlLib_PixelFormat__typ;
import LONGINT *SdlLib_Surface__typ;

import void SdlLib_Delay (INTEGER msec);
import BOOLEAN SdlLib_Flip (SdlLib_PSurface screen);
import INTEGER SdlLib_Init (SET flags);
import BOOLEAN SdlLib_LockSurface (SdlLib_PSurface surface);
import INTEGER SdlLib_MapRGB (SdlLib_PPixelFormat format, SYSTEM_BYTE r, SYSTEM_BYTE g, SYSTEM_BYTE b);
import BOOLEAN SdlLib_MustLock (SdlLib_PSurface surface);
import void SdlLib_Quit (void);
import SdlLib_PSurface SdlLib_SetVideoMode (INTEGER width, INTEGER height, INTEGER bpp, SET flags);
import void SdlLib_UnlockSurface (SdlLib_PSurface surface);
import void SdlLib_UpdateRect (SdlLib_PSurface screen, INTEGER x, INTEGER y, INTEGER w, INTEGER h);
import void SdlLib_WM_SetCaption (SdlLib_PChar title, SdlLib_PChar icon);
import void *SdlLib__init(void);

#define SdlLib_sdlMapRGB(format, r, g, b)	SDL_MapRGB((SDL_PixelFormat*)format, r, g, b)

#endif
