/*  Ofront 1.2 -xtspkae */
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
		INTEGER unused1, locked;
		SdlLib_Pointer map;
		INTEGER format_version, refcount;
	} SdlLib_Surface;



export LONGINT *SdlLib_Rect__typ;
export LONGINT *SdlLib_Color__typ;
export LONGINT *SdlLib_Palette__typ;
export LONGINT *SdlLib_PixelFormat__typ;
export LONGINT *SdlLib_Surface__typ;

export void SdlLib_Delay (INTEGER msec);
export INTEGER SdlLib_Flip (SdlLib_PSurface screen);
export INTEGER SdlLib_Init (SET flags);
export BOOLEAN SdlLib_LockSurface (SdlLib_PSurface surface);
export INTEGER SdlLib_MapRGB (SdlLib_PPixelFormat format, SYSTEM_BYTE r, SYSTEM_BYTE g, SYSTEM_BYTE b);
export BOOLEAN SdlLib_MustLock (SdlLib_PSurface surface);
export void SdlLib_Quit (void);
export SdlLib_PSurface SdlLib_SetVideoMode (INTEGER width, INTEGER height, INTEGER bpp, SET flags);
export void SdlLib_UnlockSurface (SdlLib_PSurface surface);
export void SdlLib_UpdateRect (SdlLib_PSurface screen, INTEGER x, INTEGER y, INTEGER w, INTEGER h);
export void SdlLib_WM_SetCaption (SdlLib_PChar title, SdlLib_PChar icon);

#include <SDL.h>
#define SdlLib_sdlDelay(msec)	SDL_Delay(msec)
#define SdlLib_sdlFlip(screen)	SDL_Flip((SDL_Surface*)screen)
#define SdlLib_sdlInit(flags)	SDL_Init(flags)
#define SdlLib_sdlLockSurface(surface)	SDL_LockSurface((SDL_Surface*)surface)
#define SdlLib_sdlMapRGB(format, r, g, b)	SDL_MapRGB((SDL_PixelFormat*)format, r, g, b)
#define SdlLib_sdlMustLock(surface)	SDL_MUSTLOCK(surface)
#define SdlLib_sdlQuit()	SDL_Quit()
#define SdlLib_sdlSetVideoMode(width, height, bpp, flags)	((SdlLib_PSurface)SDL_SetVideoMode(width, height, bpp, flags))
#define SdlLib_sdlUnlockSurface(surface)	SDL_UnlockSurface((SDL_Surface*)surface)
#define SdlLib_sdlUpdateRect(screen, x, y, w, h)	SDL_UpdateRect((SDL_Surface*)screen, x, y, w, h)
#define SdlLib_sdlWM_SetCaption(title, icon)	SDL_WM_SetCaption((char*)title, (char*)icon)

INTEGER SdlLib_Init (SET flags)
{
	return SdlLib_sdlInit(flags);
}

void SdlLib_Quit (void)
{
	SdlLib_sdlQuit();
}

void SdlLib_WM_SetCaption (SdlLib_PChar title, SdlLib_PChar icon)
{
	SdlLib_sdlWM_SetCaption(title, icon);
}

SdlLib_PSurface SdlLib_SetVideoMode (INTEGER width, INTEGER height, INTEGER bpp, SET flags)
{
	return SdlLib_sdlSetVideoMode(width, height, bpp, flags);
}

BOOLEAN SdlLib_LockSurface (SdlLib_PSurface surface)
{
	return SdlLib_sdlLockSurface(surface) == 0;
}

void SdlLib_UnlockSurface (SdlLib_PSurface surface)
{
	SdlLib_sdlUnlockSurface(surface);
}

BOOLEAN SdlLib_MustLock (SdlLib_PSurface surface)
{
	return SdlLib_sdlMustLock(surface) != 0;
}

void SdlLib_UpdateRect (SdlLib_PSurface screen, INTEGER x, INTEGER y, INTEGER w, INTEGER h)
{
	SdlLib_sdlUpdateRect(screen, x, y, w, h);
}

INTEGER SdlLib_MapRGB (SdlLib_PPixelFormat format, SYSTEM_BYTE r, SYSTEM_BYTE g, SYSTEM_BYTE b)
{
	return SdlLib_sdlMapRGB(format, r, g, b);
}

INTEGER SdlLib_Flip (SdlLib_PSurface screen)
{
	return SdlLib_sdlFlip(screen);
}

void SdlLib_Delay (INTEGER msec)
{
	SdlLib_sdlDelay(msec);
}

__TDESC(SdlLib_Rect__desc, 1, 0) = {__TDFLDS("Rect", 8), {-4}};
__TDESC(SdlLib_Color__desc, 1, 0) = {__TDFLDS("Color", 4), {-4}};
__TDESC(SdlLib_Palette__desc, 1, 0) = {__TDFLDS("Palette", 8), {-4}};
__TDESC(SdlLib_PixelFormat__desc, 1, 0) = {__TDFLDS("PixelFormat", 40), {-4}};
__TDESC(SdlLib_Surface__desc, 1, 0) = {__TDFLDS("Surface", 60), {-4}};

export void *SdlLib__init(void)
{
	__DEFMOD;
	__REGMOD("SdlLib", 0);
	__REGCMD("Quit", SdlLib_Quit);
	__INITYP(SdlLib_Rect, SdlLib_Rect, 0);
	__INITYP(SdlLib_Color, SdlLib_Color, 0);
	__INITYP(SdlLib_Palette, SdlLib_Palette, 0);
	__INITYP(SdlLib_PixelFormat, SdlLib_PixelFormat, 0);
	__INITYP(SdlLib_Surface, SdlLib_Surface, 0);
/* BEGIN */
	__ENDMOD;
}
