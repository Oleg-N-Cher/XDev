/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "WinApi.h"

struct Sdl2Lib__8 {
	char _prvt0[1];
};

struct Sdl2Lib__1 {
	char _prvt0[1];
};

struct Sdl2Lib__2 {
	char _prvt0[1];
};

typedef
	struct Sdl2Lib_PixelFormat *Sdl2Lib_PPixelFormat;

typedef
	struct Sdl2Lib_Rect *Sdl2Lib_PRect;

typedef
	struct Sdl2Lib_Surface {
		INTEGER flags;
		Sdl2Lib_PPixelFormat format;
		INTEGER w, h, pitch;
		SYSTEM_PTR pixels, userdata;
		INTEGER locked;
		SYSTEM_PTR lock_data;
		Sdl2Lib_PRect clip_rect;
		SYSTEM_PTR map;
		INTEGER refcount;
	} Sdl2Lib_Surface;

typedef
	struct Sdl2Lib_Rect {
		INTEGER x, y, w, h;
	} Sdl2Lib_Rect;

typedef
	struct Sdl2Lib_DisplayMode {
		INTEGER format, w, h, refresh_rate;
		SYSTEM_PTR driverdata;
	} Sdl2Lib_DisplayMode;

typedef
	Sdl2Lib_Surface *Sdl2Lib_PSurface;

typedef
	struct Sdl2Lib_WindowShaper *Sdl2Lib_PWindowShaper;

typedef
	struct Sdl2Lib_WindowUserData *Sdl2Lib_PWindowUserData;

typedef
	struct Sdl2Lib__9 *Sdl2Lib_Window;

struct Sdl2Lib__9 {
	SYSTEM_PTR magic;
	INTEGER id;
	SYSTEM_PTR title;
	Sdl2Lib_Surface icon;
	INTEGER x, y, w, h, min_w, min_h, max_w, max_h, flags;
	Sdl2Lib_Rect windowed;
	Sdl2Lib_DisplayMode fullscreen_mode;
	REAL brightness;
	SYSTEM_PTR gamma, saved_gamma;
	Sdl2Lib_PSurface surface;
	INTEGER surface_valid;
	Sdl2Lib_PWindowShaper shaper;
	Sdl2Lib_PWindowUserData data;
	SYSTEM_PTR driverdata;
	Sdl2Lib_Window prev, next;
};

struct Sdl2Lib__7 {
	char _prvt0[1];
};

struct Sdl2Lib__3 {
	INTEGER autoclose;
	SYSTEM_PTR fp;
};

struct Sdl2Lib__4 {
	SYSTEM_PTR base, here, stop;
};

struct Sdl2Lib__5 {
	SYSTEM_PTR data1;
};

struct Sdl2Lib__6 {
	struct Sdl2Lib__3 stdio;
	struct Sdl2Lib__4 mem;
	struct Sdl2Lib__5 unknown;
};

typedef
	struct Sdl2Lib_RWops *Sdl2Lib_PRWops;

typedef
	INTEGER (*Sdl2Lib_Close)(Sdl2Lib_PRWops);

typedef
	struct Sdl2Lib_Color {
		CHAR r, g, b, a;
	} Sdl2Lib_Color;

typedef
	Sdl2Lib_Color Sdl2Lib_ColorArray[65001];

typedef
	struct Sdl2Lib__1 *Sdl2Lib_Cursor;

typedef
	struct Sdl2Lib_WindowEvent {
		INTEGER type, timestamp, windowID;
		CHAR event, padding1, padding2, padding3;
		INTEGER data1, data2;
	} Sdl2Lib_WindowEvent;

typedef
	struct Sdl2Lib_KeySym {
		INTEGER scancode, sym;
		SHORTINT modifier;
		INTEGER unicode;
	} Sdl2Lib_KeySym;

typedef
	struct Sdl2Lib_KeyboardEvent {
		INTEGER type, timestamp, windowID;
		CHAR state, repeat, padding2, padding3;
		Sdl2Lib_KeySym keysym;
	} Sdl2Lib_KeyboardEvent;

typedef
	struct Sdl2Lib_TextInputEvent {
		INTEGER type, timestamp, windowID;
		CHAR text[32];
	} Sdl2Lib_TextInputEvent;

typedef
	struct Sdl2Lib_MouseMotionEvent {
		INTEGER type, timestamp, windowID, which, state, x, y, xrel, yrel;
	} Sdl2Lib_MouseMotionEvent;

typedef
	struct Sdl2Lib_MouseButtonEvent {
		INTEGER type, timestamp, windowID, which;
		CHAR button, state, clicks;
		INTEGER x, y;
	} Sdl2Lib_MouseButtonEvent;

typedef
	struct Sdl2Lib_MouseWheelEvent {
		INTEGER type, timestamp, windowID, which, x, y;
	} Sdl2Lib_MouseWheelEvent;

typedef
	struct Sdl2Lib_UserEvent {
		INTEGER type, timestamp, windowID, code;
		SYSTEM_PTR data1, data2;
	} Sdl2Lib_UserEvent;

typedef
	struct Sdl2Lib_QuitEvent {
		INTEGER type, timestamp;
	} Sdl2Lib_QuitEvent;

typedef
	struct Sdl2Lib_Event {
		INTEGER type;
		Sdl2Lib_WindowEvent window;
		Sdl2Lib_KeyboardEvent key;
		Sdl2Lib_TextInputEvent text;
		Sdl2Lib_MouseMotionEvent motion;
		Sdl2Lib_MouseButtonEvent button;
		Sdl2Lib_MouseWheelEvent wheel;
		Sdl2Lib_UserEvent user;
		Sdl2Lib_QuitEvent quit;
		BYTE _data[1000];
	} Sdl2Lib_Event;

typedef
	INTEGER (*Sdl2Lib_EventFilter)(SYSTEM_PTR, Sdl2Lib_Event*, LONGINT *);

typedef
	struct Sdl2Lib__2 *Sdl2Lib_GLContext;

typedef
	Sdl2Lib_Color *Sdl2Lib_PColor;

typedef
	Sdl2Lib_ColorArray *Sdl2Lib_PColorArray;

typedef
	Sdl2Lib_Event *Sdl2Lib_PEvent;

typedef
	Sdl2Lib_KeySym *Sdl2Lib_PKeySym;

typedef
	struct Sdl2Lib_Palette *Sdl2Lib_PPalette;

typedef
	struct Sdl2Lib_Point *Sdl2Lib_PPoint;

typedef
	struct Sdl2Lib_SDL_version *Sdl2Lib_PSDL_version;

typedef
	struct Sdl2Lib_WindowShapeMode *Sdl2Lib_PWindowShapeMode;

typedef
	struct Sdl2Lib_Palette {
		INTEGER ncolors;
		Sdl2Lib_PColorArray colors;
		INTEGER version, refcount;
	} Sdl2Lib_Palette;

typedef
	struct Sdl2Lib_PixelFormat {
		INTEGER format;
		Sdl2Lib_PPalette palette;
		CHAR BitsPerPixel, BytesPerPixel;
		CHAR padding[2];
		INTEGER Rmask, Gmask, Bmask, Amask;
	} Sdl2Lib_PixelFormat;

typedef
	struct Sdl2Lib_Point {
		INTEGER x, y;
	} Sdl2Lib_Point;

typedef
	INTEGER (*Sdl2Lib_Seek)(Sdl2Lib_PRWops, INTEGER, INTEGER);

typedef
	INTEGER (*Sdl2Lib_Read)(Sdl2Lib_PRWops, SYSTEM_PTR, INTEGER, INTEGER);

typedef
	INTEGER (*Sdl2Lib_Write)(Sdl2Lib_PRWops, SYSTEM_PTR, INTEGER, INTEGER);

typedef
	struct Sdl2Lib_RWops {
		Sdl2Lib_Seek seek;
		Sdl2Lib_Read read;
		Sdl2Lib_Write write;
		Sdl2Lib_Close close;
		INTEGER type;
		struct Sdl2Lib__6 hidden;
	} Sdl2Lib_RWops;

typedef
	struct Sdl2Lib__7 *Sdl2Lib_Renderer;

typedef
	struct Sdl2Lib_SDL_version {
		CHAR major, minor, patch;
	} Sdl2Lib_SDL_version;

typedef
	struct Sdl2Lib__8 *Sdl2Lib_Texture;

typedef
	INTEGER (*Sdl2Lib_TimerCallback)(INTEGER, SYSTEM_PTR);

typedef
	struct Sdl2Lib_WindowShapeParams {
		CHAR binarizationCutoff;
		Sdl2Lib_Color colorKey;
	} Sdl2Lib_WindowShapeParams;

typedef
	struct Sdl2Lib_WindowShapeMode {
		INTEGER mode;
		Sdl2Lib_WindowShapeParams parameters;
	} Sdl2Lib_WindowShapeMode;

typedef
	struct Sdl2Lib_WindowShaper {
		Sdl2Lib_Window window;
		INTEGER userx, usery;
		Sdl2Lib_WindowShapeMode mode;
		INTEGER hasshape;
		SYSTEM_PTR driverdata;
	} Sdl2Lib_WindowShaper;

typedef
	struct Sdl2Lib_WindowUserData {
		SYSTEM_PTR name, data;
		Sdl2Lib_PWindowUserData next;
	} Sdl2Lib_WindowUserData;



export LONGINT *Sdl2Lib_SDL_version__typ;
export LONGINT *Sdl2Lib_Rect__typ;
export LONGINT *Sdl2Lib_Point__typ;
export LONGINT *Sdl2Lib__8__typ;
export LONGINT *Sdl2Lib_DisplayMode__typ;
export LONGINT *Sdl2Lib_Color__typ;
export LONGINT *Sdl2Lib__1__typ;
export LONGINT *Sdl2Lib_Palette__typ;
export LONGINT *Sdl2Lib_PixelFormat__typ;
export LONGINT *Sdl2Lib__2__typ;
export LONGINT *Sdl2Lib_Surface__typ;
export LONGINT *Sdl2Lib__9__typ;
export LONGINT *Sdl2Lib_WindowShapeParams__typ;
export LONGINT *Sdl2Lib_WindowShapeMode__typ;
export LONGINT *Sdl2Lib_WindowShaper__typ;
export LONGINT *Sdl2Lib_WindowUserData__typ;
export LONGINT *Sdl2Lib__7__typ;
export LONGINT *Sdl2Lib_KeySym__typ;
export LONGINT *Sdl2Lib_KeyboardEvent__typ;
export LONGINT *Sdl2Lib_TextInputEvent__typ;
export LONGINT *Sdl2Lib_MouseMotionEvent__typ;
export LONGINT *Sdl2Lib_MouseButtonEvent__typ;
export LONGINT *Sdl2Lib_MouseWheelEvent__typ;
export LONGINT *Sdl2Lib_QuitEvent__typ;
export LONGINT *Sdl2Lib_WindowEvent__typ;
export LONGINT *Sdl2Lib_UserEvent__typ;
export LONGINT *Sdl2Lib_Event__typ;
export LONGINT *Sdl2Lib__3__typ;
export LONGINT *Sdl2Lib__4__typ;
export LONGINT *Sdl2Lib__5__typ;
export LONGINT *Sdl2Lib__6__typ;
export LONGINT *Sdl2Lib_RWops__typ;


#define Sdl2Lib_AddEventWatch(filter, userData)	SDL_AddEventWatch(filter, userData)
#define Sdl2Lib_AddTimer(interval, callback, param)	SDL_AddTimer(interval, callback, param)
#define Sdl2Lib_BlitSurface(src, srcrect, dst, dstrect)	SDL_UpperBlit(src, srcrect, dst, dstrect)
#define Sdl2Lib_ConvertSurfaceFormat(surface, pixel_format, flags)	SDL_ConvertSurfaceFormat(surface, pixel_format, flags)
#define Sdl2Lib_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)
#define Sdl2Lib_CreateRenderer(window, index, flags)	SDL_CreateRenderer(window, index, flags)
#define Sdl2Lib_CreateSystemCursor(id)	SDL_CreateSystemCursor(id)
#define Sdl2Lib_CreateTextureFromSurface(renderer, surface)	SDL_CreateTextureFromSurface(renderer, surface)
#define Sdl2Lib_CreateWindow(title, x, y, w, h, flags)	SDL_CreateWindow(title, x, y, w, h, flags)
#define Sdl2Lib_DelEventWatch(filter, userData)	SDL_DelEventWatch(filter, userData)
#define Sdl2Lib_Delay(ms)	SDL_Delay(ms)
#define Sdl2Lib_DestroyRenderer(renderer)	SDL_DestroyRenderer(renderer)
#define Sdl2Lib_DestroyWindow(window)	SDL_DestroyWindow(window)
#define Sdl2Lib_EventState(type, state)	SDL_EventState(type, state)
#define Sdl2Lib_FreeSurface(surface)	SDL_FreeSurface(surface)
#define Sdl2Lib_GL_BindTexture(texture, texw, texh)	SDL_GL_BindTexture(texture, texw, texh)
#define Sdl2Lib_GL_CreateContext(window)	SDL_GL_CreateContext(window)
#define Sdl2Lib_GL_DeleteContext(c)	SDL_GL_DeleteContext(c)
#define Sdl2Lib_GL_GetCurrentContext()	SDL_GL_GetCurrentContext()
#define Sdl2Lib_GL_MakeCurrent(window, c)	SDL_GL_MakeCurrent(window, c)
#define Sdl2Lib_GL_SwapWindow(window)	SDL_GL_SwapWindow(window)
#define Sdl2Lib_GetError()	SDL_GetError()
#define Sdl2Lib_GetKeyBoardState(numkeys)	SDL_GetKeyboardState(numkeys)
#define Sdl2Lib_GetModState()	SDL_GetModState()
#define Sdl2Lib_GetMouseFocus()	SDL_GetMouseFocus()
#define Sdl2Lib_GetMouseState(x, y)	SDL_GetMouseState(x, y)
#define Sdl2Lib_GetPerformanceCounter()	SDL_GetPerformanceCounter()
#define Sdl2Lib_GetPerformanceFrequency()	SDL_GetPerformanceFrequency()
#define Sdl2Lib_GetSurfaceAlphaMod(surface, alpha)	SDL_GetSurfaceAlphaMod(surface, alpha)
#define Sdl2Lib_GetSurfaceBlendMode(surface, blend)	SDL_GetSurfaceBlendMode(surface, blend)
#define Sdl2Lib_GetTicks()	SDL_GetTicks()
#define Sdl2Lib_GetWindowPosition(window, x, y)	SDL_GetWindowPosition(window, x, y)
#define Sdl2Lib_GetWindowSize(window, w, h)	SDL_GetWindowSize(window, w, h)
#define Sdl2Lib_HasEvent(type)	SDL_HasEvent(type)
#define Sdl2Lib_HasEvents(minType, maxType)	SDL_HasEvents(minType, maxType)
#define Sdl2Lib_Init(flags)	SDL_Init(flags)
#define Sdl2Lib_MasksToPixelFormatEnum(bpp, rMask, gMask, bMask, aMask)	SDL_MasksToPixelFormatEnum(bpp, rMask, gMask, bMask, aMask)
#define Sdl2Lib_PollEvent(event, event__typ)	SDL_PollEvent(event)
#define Sdl2Lib_PumpEvents()	SDL_PumpEvents()
#define Sdl2Lib_PushEvent(event)	SDL_PushEvent(event)
#define Sdl2Lib_Quit()	SDL_Quit()
#define Sdl2Lib_RaiseWindow(window)	SDL_RaiseWindow(window)
#define Sdl2Lib_RegisterEvents(num)	SDL_RegisterEvents(num)
#define Sdl2Lib_RemoveTimer(t)	SDL_RemoveTimer(t)
#define Sdl2Lib_RenderClear(renderer)	SDL_RenderClear(renderer)
#define Sdl2Lib_RenderCopy(renderer, texture, src, dst)	SDL_RenderCopy(renderer, texture, src, dst)
#define Sdl2Lib_RenderDrawLine(renderer, x1, y1, x2, y2)	SDL_RenderDrawLine(renderer, x1, y1, x2, y2)
#define Sdl2Lib_RenderDrawLines(renderer, points, count)	SDL_RenderDrawLines(renderer, points, count)
#define Sdl2Lib_RenderDrawPoint(renderer, x, y)	SDL_RenderDrawPoint(renderer, x, y)
#define Sdl2Lib_RenderDrawPoints(renderer, points, count)	SDL_RenderDrawPoints(renderer, points, count)
#define Sdl2Lib_RenderDrawRect(renderer, rect)	SDL_RenderDrawRect(renderer, rect)
#define Sdl2Lib_RenderDrawRects(renderer, rect, count)	SDL_RenderDrawRects(renderer, rect, count)
#define Sdl2Lib_RenderFillRect(renderer, rect)	SDL_RenderFillRect(renderer, rect)
#define Sdl2Lib_RenderFillRects(renderer, rect, count)	SDL_RenderFillRects(renderer, rect, count)
#define Sdl2Lib_RenderPresent(renderer)	SDL_RenderPresent(renderer)
#define Sdl2Lib_SDL_AddEventWatch(filter, userData)	SDL_AddEventWatch(filter, userData)
__EXTERN void SDL_AddEventWatch(Sdl2Lib_EventFilter filter, SYSTEM_PTR userData);
#define Sdl2Lib_SDL_AddTimer(interval, callback, param)	SDL_AddTimer(interval, callback, param)
__EXTERN INTEGER SDL_AddTimer(INTEGER interval, Sdl2Lib_TimerCallback callback, SYSTEM_PTR param);
#define Sdl2Lib_SDL_ConvertSurfaceFormat(surface, pixel_format, flags)	SDL_ConvertSurfaceFormat(surface, pixel_format, flags)
__EXTERN Sdl2Lib_PSurface SDL_ConvertSurfaceFormat(Sdl2Lib_PSurface surface, INTEGER pixel_format, INTEGER flags);
#define Sdl2Lib_SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)
__EXTERN Sdl2Lib_PSurface SDL_CreateRGBSurface(INTEGER flags, INTEGER width, INTEGER height, INTEGER depth, INTEGER rMask, INTEGER gMask, INTEGER bMask, INTEGER aMask);
#define Sdl2Lib_SDL_CreateRenderer(window, index, flags)	SDL_CreateRenderer(window, index, flags)
__EXTERN Sdl2Lib_Renderer SDL_CreateRenderer(Sdl2Lib_Window window, INTEGER index, INTEGER flags);
#define Sdl2Lib_SDL_CreateSystemCursor(id)	SDL_CreateSystemCursor(id)
__EXTERN Sdl2Lib_Cursor SDL_CreateSystemCursor(INTEGER id);
#define Sdl2Lib_SDL_CreateTextureFromSurface(renderer, surface)	SDL_CreateTextureFromSurface(renderer, surface)
__EXTERN Sdl2Lib_Texture SDL_CreateTextureFromSurface(Sdl2Lib_Renderer renderer, Sdl2Lib_PSurface surface);
#define Sdl2Lib_SDL_CreateWindow(title, x, y, w, h, flags)	SDL_CreateWindow(title, x, y, w, h, flags)
__EXTERN Sdl2Lib_Window SDL_CreateWindow(SYSTEM_PTR title, INTEGER x, INTEGER y, INTEGER w, INTEGER h, INTEGER flags);
#define Sdl2Lib_SDL_DelEventWatch(filter, userData)	SDL_DelEventWatch(filter, userData)
__EXTERN void SDL_DelEventWatch(Sdl2Lib_EventFilter filter, SYSTEM_PTR userData);
#define Sdl2Lib_SDL_Delay(ms)	SDL_Delay(ms)
__EXTERN void SDL_Delay(INTEGER ms);
#define Sdl2Lib_SDL_DestroyRenderer(renderer)	SDL_DestroyRenderer(renderer)
__EXTERN void SDL_DestroyRenderer(Sdl2Lib_Renderer renderer);
#define Sdl2Lib_SDL_DestroyWindow(window)	SDL_DestroyWindow(window)
__EXTERN void SDL_DestroyWindow(Sdl2Lib_Window window);
#define Sdl2Lib_SDL_EventState(type, state)	SDL_EventState(type, state)
__EXTERN CHAR SDL_EventState(INTEGER type, INTEGER state);
#define Sdl2Lib_SDL_FreeSurface(surface)	SDL_FreeSurface(surface)
__EXTERN void SDL_FreeSurface(Sdl2Lib_PSurface surface);
#define Sdl2Lib_SDL_GL_BindTexture(texture, texw, texh)	SDL_GL_BindTexture(texture, texw, texh)
__EXTERN INTEGER SDL_GL_BindTexture(Sdl2Lib_Texture texture, REAL *texw, REAL *texh);
#define Sdl2Lib_SDL_GL_CreateContext(window)	SDL_GL_CreateContext(window)
__EXTERN Sdl2Lib_GLContext SDL_GL_CreateContext(Sdl2Lib_Window window);
#define Sdl2Lib_SDL_GL_DeleteContext(c)	SDL_GL_DeleteContext(c)
__EXTERN void SDL_GL_DeleteContext(Sdl2Lib_GLContext c);
#define Sdl2Lib_SDL_GL_GetCurrentContext()	SDL_GL_GetCurrentContext()
__EXTERN Sdl2Lib_GLContext SDL_GL_GetCurrentContext(void);
#define Sdl2Lib_SDL_GL_MakeCurrent(window, c)	SDL_GL_MakeCurrent(window, c)
__EXTERN void SDL_GL_MakeCurrent(Sdl2Lib_Window window, Sdl2Lib_GLContext c);
#define Sdl2Lib_SDL_GL_SwapWindow(window)	SDL_GL_SwapWindow(window)
__EXTERN void SDL_GL_SwapWindow(Sdl2Lib_Window window);
#define Sdl2Lib_SDL_GetError()	SDL_GetError()
__EXTERN SYSTEM_PTR SDL_GetError(void);
#define Sdl2Lib_SDL_GetKeyboardState(numkeys)	SDL_GetKeyboardState(numkeys)
__EXTERN SYSTEM_PTR SDL_GetKeyboardState(INTEGER *numkeys);
#define Sdl2Lib_SDL_GetModState()	SDL_GetModState()
__EXTERN INTEGER SDL_GetModState(void);
#define Sdl2Lib_SDL_GetMouseFocus()	SDL_GetMouseFocus()
__EXTERN Sdl2Lib_Window SDL_GetMouseFocus(void);
#define Sdl2Lib_SDL_GetMouseState(x, y)	SDL_GetMouseState(x, y)
__EXTERN INTEGER SDL_GetMouseState(INTEGER *x, INTEGER *y);
#define Sdl2Lib_SDL_GetPerformanceCounter()	SDL_GetPerformanceCounter()
__EXTERN LONGINT SDL_GetPerformanceCounter(void);
#define Sdl2Lib_SDL_GetPerformanceFrequency()	SDL_GetPerformanceFrequency()
__EXTERN LONGINT SDL_GetPerformanceFrequency(void);
#define Sdl2Lib_SDL_GetSurfaceAlphaMod(surface, alpha)	SDL_GetSurfaceAlphaMod(surface, alpha)
__EXTERN void SDL_GetSurfaceAlphaMod(Sdl2Lib_PSurface surface, CHAR *alpha);
#define Sdl2Lib_SDL_GetSurfaceBlendMode(surface, blend)	SDL_GetSurfaceBlendMode(surface, blend)
__EXTERN void SDL_GetSurfaceBlendMode(Sdl2Lib_PSurface surface, INTEGER *blend);
#define Sdl2Lib_SDL_GetTicks()	SDL_GetTicks()
__EXTERN INTEGER SDL_GetTicks(void);
#define Sdl2Lib_SDL_GetWindowPosition(window, x, y)	SDL_GetWindowPosition(window, x, y)
__EXTERN void SDL_GetWindowPosition(Sdl2Lib_Window window, INTEGER *x, INTEGER *y);
#define Sdl2Lib_SDL_GetWindowSize(window, w, h)	SDL_GetWindowSize(window, w, h)
__EXTERN void SDL_GetWindowSize(Sdl2Lib_Window window, INTEGER *w, INTEGER *h);
#define Sdl2Lib_SDL_HasEvent(type)	SDL_HasEvent(type)
__EXTERN INTEGER SDL_HasEvent(INTEGER type);
#define Sdl2Lib_SDL_HasEvents(minType, maxType)	SDL_HasEvents(minType, maxType)
__EXTERN INTEGER SDL_HasEvents(INTEGER minType, INTEGER maxType);
#define Sdl2Lib_SDL_Init(flags)	SDL_Init(flags)
__EXTERN INTEGER SDL_Init(SET flags);
#define Sdl2Lib_SDL_MasksToPixelFormatEnum(bpp, rMask, gMask, bMask, aMask)	SDL_MasksToPixelFormatEnum(bpp, rMask, gMask, bMask, aMask)
__EXTERN INTEGER SDL_MasksToPixelFormatEnum(INTEGER bpp, INTEGER rMask, INTEGER gMask, INTEGER bMask, INTEGER aMask);
#define Sdl2Lib_SDL_PollEvent(event, event__typ)	SDL_PollEvent(event)
__EXTERN INTEGER SDL_PollEvent(Sdl2Lib_Event *event);
#define Sdl2Lib_SDL_PumpEvents()	SDL_PumpEvents()
__EXTERN void SDL_PumpEvents(void);
#define Sdl2Lib_SDL_PushEvent(event)	SDL_PushEvent(event)
__EXTERN INTEGER SDL_PushEvent(Sdl2Lib_PEvent event);
#define Sdl2Lib_SDL_Quit()	SDL_Quit()
__EXTERN void SDL_Quit(void);
#define Sdl2Lib_SDL_RaiseWindow(window)	SDL_RaiseWindow(window)
__EXTERN void SDL_RaiseWindow(Sdl2Lib_Window window);
#define Sdl2Lib_SDL_RegisterEvents(num)	SDL_RegisterEvents(num)
__EXTERN INTEGER SDL_RegisterEvents(INTEGER num);
#define Sdl2Lib_SDL_RemoveTimer(t)	SDL_RemoveTimer(t)
__EXTERN INTEGER SDL_RemoveTimer(INTEGER t);
#define Sdl2Lib_SDL_RenderClear(renderer)	SDL_RenderClear(renderer)
__EXTERN INTEGER SDL_RenderClear(Sdl2Lib_Renderer renderer);
#define Sdl2Lib_SDL_RenderCopy(renderer, texture, src, dst)	SDL_RenderCopy(renderer, texture, src, dst)
__EXTERN INTEGER SDL_RenderCopy(Sdl2Lib_Renderer renderer, Sdl2Lib_Texture texture, Sdl2Lib_PRect src, Sdl2Lib_PRect dst);
#define Sdl2Lib_SDL_RenderDrawLine(renderer, x1, y1, x2, y2)	SDL_RenderDrawLine(renderer, x1, y1, x2, y2)
__EXTERN INTEGER SDL_RenderDrawLine(Sdl2Lib_Renderer renderer, INTEGER x1, INTEGER y1, INTEGER x2, INTEGER y2);
#define Sdl2Lib_SDL_RenderDrawLines(renderer, points, count)	SDL_RenderDrawLines(renderer, points, count)
__EXTERN INTEGER SDL_RenderDrawLines(Sdl2Lib_Renderer renderer, Sdl2Lib_PPoint points, INTEGER count);
#define Sdl2Lib_SDL_RenderDrawPoint(renderer, x, y)	SDL_RenderDrawPoint(renderer, x, y)
__EXTERN INTEGER SDL_RenderDrawPoint(Sdl2Lib_Renderer renderer, INTEGER x, INTEGER y);
#define Sdl2Lib_SDL_RenderDrawPoints(renderer, points, count)	SDL_RenderDrawPoints(renderer, points, count)
__EXTERN INTEGER SDL_RenderDrawPoints(Sdl2Lib_Renderer renderer, Sdl2Lib_PPoint points, INTEGER count);
#define Sdl2Lib_SDL_RenderDrawRect(renderer, rect)	SDL_RenderDrawRect(renderer, rect)
__EXTERN INTEGER SDL_RenderDrawRect(Sdl2Lib_Renderer renderer, Sdl2Lib_PRect rect);
#define Sdl2Lib_SDL_RenderDrawRects(renderer, rect, count)	SDL_RenderDrawRects(renderer, rect, count)
__EXTERN INTEGER SDL_RenderDrawRects(Sdl2Lib_Renderer renderer, Sdl2Lib_PRect rect, INTEGER count);
#define Sdl2Lib_SDL_RenderFillRect(renderer, rect)	SDL_RenderFillRect(renderer, rect)
__EXTERN INTEGER SDL_RenderFillRect(Sdl2Lib_Renderer renderer, Sdl2Lib_PRect rect);
#define Sdl2Lib_SDL_RenderFillRects(renderer, rect, count)	SDL_RenderFillRects(renderer, rect, count)
__EXTERN INTEGER SDL_RenderFillRects(Sdl2Lib_Renderer renderer, Sdl2Lib_PRect rect, INTEGER count);
#define Sdl2Lib_SDL_RenderPresent(renderer)	SDL_RenderPresent(renderer)
__EXTERN INTEGER SDL_RenderPresent(Sdl2Lib_Renderer renderer);
#define Sdl2Lib_SDL_SetCursor(cursor)	SDL_SetCursor(cursor)
__EXTERN void SDL_SetCursor(Sdl2Lib_Cursor cursor);
#define Sdl2Lib_SDL_SetRenderDrawColor(renderer, r, g, b, a)	SDL_SetRenderDrawColor(renderer, r, g, b, a)
__EXTERN INTEGER SDL_SetRenderDrawColor(Sdl2Lib_Renderer renderer, CHAR r, CHAR g, CHAR b, CHAR a);
#define Sdl2Lib_SDL_SetSurfaceAlphaMod(surface, alpha)	SDL_SetSurfaceAlphaMod(surface, alpha)
__EXTERN void SDL_SetSurfaceAlphaMod(Sdl2Lib_PSurface surface, CHAR alpha);
#define Sdl2Lib_SDL_SetSurfaceBlendMode(surface, blend)	SDL_SetSurfaceBlendMode(surface, blend)
__EXTERN void SDL_SetSurfaceBlendMode(Sdl2Lib_PSurface surface, INTEGER blend);
#define Sdl2Lib_SDL_UnlockSurface(surface)	SDL_UnlockSurface(surface)
__EXTERN void SDL_UnlockSurface(Sdl2Lib_PSurface surface);
#define Sdl2Lib_SDL_UpperBlit(src, srcrect, dst, dstrect)	SDL_UpperBlit(src, srcrect, dst, dstrect)
__EXTERN INTEGER SDL_UpperBlit(Sdl2Lib_PSurface src, Sdl2Lib_PRect srcrect, Sdl2Lib_PSurface *dst, Sdl2Lib_PRect dstrect);
#define Sdl2Lib_SDL_WaitEvent(event, event__typ)	SDL_WaitEvent(event)
__EXTERN INTEGER SDL_WaitEvent(Sdl2Lib_Event *event);
#define Sdl2Lib_SDL_WaitEventTimeout(event, event__typ, timeout)	SDL_WaitEventTimeout(event, timeout)
__EXTERN INTEGER SDL_WaitEventTimeout(Sdl2Lib_Event *event, INTEGER timeout);
#define Sdl2Lib_SetCursor(cursor)	SDL_SetCursor(cursor)
#define Sdl2Lib_SetRenderDrawColor(renderer, r, g, b, a)	SDL_SetRenderDrawColor(renderer, r, g, b, a)
#define Sdl2Lib_SetSurfaceAlphaMod(surface, alpha)	SDL_SetSurfaceAlphaMod(surface, alpha)
#define Sdl2Lib_SetSurfaceBlendMode(surface, blend)	SDL_SetSurfaceBlendMode(surface, blend)
#define Sdl2Lib_UnlockSurface(surface)	SDL_UnlockSurface(surface)
#define Sdl2Lib_WaitEvent(event, event__typ)	SDL_WaitEvent(event)
#define Sdl2Lib_WaitEventTimeout(event, event__typ, timeout)	SDL_WaitEventTimeout(event, timeout)
#define Sdl2Lib__init()	/*-noinit*/

/*============================================================================*/

__TDESC(Sdl2Lib_SDL_version__desc, 1, 0) = {__TDFLDS("SDL_version", 3), {-8}};
__TDESC(Sdl2Lib_Rect__desc, 1, 0) = {__TDFLDS("Rect", 16), {-8}};
__TDESC(Sdl2Lib_Point__desc, 1, 0) = {__TDFLDS("Point", 8), {-8}};
__TDESC(Sdl2Lib__8__desc, 1, 0) = {__TDFLDS("", 1), {-8}};
__TDESC(Sdl2Lib_DisplayMode__desc, 1, 0) = {__TDFLDS("DisplayMode", 24), {-8}};
__TDESC(Sdl2Lib_Color__desc, 1, 0) = {__TDFLDS("Color", 4), {-8}};
__TDESC(Sdl2Lib__1__desc, 1, 0) = {__TDFLDS("", 1), {-8}};
__TDESC(Sdl2Lib_Palette__desc, 1, 0) = {__TDFLDS("Palette", 24), {-8}};
__TDESC(Sdl2Lib_PixelFormat__desc, 1, 0) = {__TDFLDS("PixelFormat", 40), {-8}};
__TDESC(Sdl2Lib__2__desc, 1, 0) = {__TDFLDS("", 1), {-8}};
__TDESC(Sdl2Lib_Surface__desc, 1, 0) = {__TDFLDS("Surface", 88), {-8}};
__TDESC(Sdl2Lib__9__desc, 1, 0) = {__TDFLDS("", 272), {-8}};
__TDESC(Sdl2Lib_WindowShapeParams__desc, 1, 0) = {__TDFLDS("WindowShapeParams", 5), {-8}};
__TDESC(Sdl2Lib_WindowShapeMode__desc, 1, 0) = {__TDFLDS("WindowShapeMode", 12), {-8}};
__TDESC(Sdl2Lib_WindowShaper__desc, 1, 0) = {__TDFLDS("WindowShaper", 40), {-8}};
__TDESC(Sdl2Lib_WindowUserData__desc, 1, 0) = {__TDFLDS("WindowUserData", 24), {-8}};
__TDESC(Sdl2Lib__7__desc, 1, 0) = {__TDFLDS("", 1), {-8}};
__TDESC(Sdl2Lib_KeySym__desc, 1, 0) = {__TDFLDS("KeySym", 16), {-8}};
__TDESC(Sdl2Lib_KeyboardEvent__desc, 1, 0) = {__TDFLDS("KeyboardEvent", 32), {-8}};
__TDESC(Sdl2Lib_TextInputEvent__desc, 1, 0) = {__TDFLDS("TextInputEvent", 44), {-8}};
__TDESC(Sdl2Lib_MouseMotionEvent__desc, 1, 0) = {__TDFLDS("MouseMotionEvent", 36), {-8}};
__TDESC(Sdl2Lib_MouseButtonEvent__desc, 1, 0) = {__TDFLDS("MouseButtonEvent", 28), {-8}};
__TDESC(Sdl2Lib_MouseWheelEvent__desc, 1, 0) = {__TDFLDS("MouseWheelEvent", 24), {-8}};
__TDESC(Sdl2Lib_QuitEvent__desc, 1, 0) = {__TDFLDS("QuitEvent", 8), {-8}};
__TDESC(Sdl2Lib_WindowEvent__desc, 1, 0) = {__TDFLDS("WindowEvent", 24), {-8}};
__TDESC(Sdl2Lib_UserEvent__desc, 1, 0) = {__TDFLDS("UserEvent", 32), {-8}};
__TDESC(Sdl2Lib_Event__desc, 1, 0) = {__TDFLDS("Event", 1232), {-8}};
__TDESC(Sdl2Lib__3__desc, 1, 0) = {__TDFLDS("", 16), {-8}};
__TDESC(Sdl2Lib__4__desc, 1, 0) = {__TDFLDS("", 24), {-8}};
__TDESC(Sdl2Lib__5__desc, 1, 0) = {__TDFLDS("", 8), {-8}};
__TDESC(Sdl2Lib__6__desc, 1, 0) = {__TDFLDS("", 48), {-8}};
__TDESC(Sdl2Lib_RWops__desc, 1, 0) = {__TDFLDS("RWops", 88), {-8}};

export void *Sdl2Lib__init(void)
{
	__DEFMOD;
	__IMPORT(WinApi__init);
	__REGMOD("Sdl2Lib", 0);
	__INITYP(Sdl2Lib_SDL_version, Sdl2Lib_SDL_version, 0);
	__INITYP(Sdl2Lib_Rect, Sdl2Lib_Rect, 0);
	__INITYP(Sdl2Lib_Point, Sdl2Lib_Point, 0);
	__INITYP(Sdl2Lib__8, Sdl2Lib__8, 0);
	__INITYP(Sdl2Lib_DisplayMode, Sdl2Lib_DisplayMode, 0);
	__INITYP(Sdl2Lib_Color, Sdl2Lib_Color, 0);
	__INITYP(Sdl2Lib__1, Sdl2Lib__1, 0);
	__INITYP(Sdl2Lib_Palette, Sdl2Lib_Palette, 0);
	__INITYP(Sdl2Lib_PixelFormat, Sdl2Lib_PixelFormat, 0);
	__INITYP(Sdl2Lib__2, Sdl2Lib__2, 0);
	__INITYP(Sdl2Lib_Surface, Sdl2Lib_Surface, 0);
	__INITYP(Sdl2Lib__9, Sdl2Lib__9, 0);
	__INITYP(Sdl2Lib_WindowShapeParams, Sdl2Lib_WindowShapeParams, 0);
	__INITYP(Sdl2Lib_WindowShapeMode, Sdl2Lib_WindowShapeMode, 0);
	__INITYP(Sdl2Lib_WindowShaper, Sdl2Lib_WindowShaper, 0);
	__INITYP(Sdl2Lib_WindowUserData, Sdl2Lib_WindowUserData, 0);
	__INITYP(Sdl2Lib__7, Sdl2Lib__7, 0);
	__INITYP(Sdl2Lib_KeySym, Sdl2Lib_KeySym, 0);
	__INITYP(Sdl2Lib_KeyboardEvent, Sdl2Lib_KeyboardEvent, 0);
	__INITYP(Sdl2Lib_TextInputEvent, Sdl2Lib_TextInputEvent, 0);
	__INITYP(Sdl2Lib_MouseMotionEvent, Sdl2Lib_MouseMotionEvent, 0);
	__INITYP(Sdl2Lib_MouseButtonEvent, Sdl2Lib_MouseButtonEvent, 0);
	__INITYP(Sdl2Lib_MouseWheelEvent, Sdl2Lib_MouseWheelEvent, 0);
	__INITYP(Sdl2Lib_QuitEvent, Sdl2Lib_QuitEvent, 0);
	__INITYP(Sdl2Lib_WindowEvent, Sdl2Lib_WindowEvent, 0);
	__INITYP(Sdl2Lib_UserEvent, Sdl2Lib_UserEvent, 0);
	__INITYP(Sdl2Lib_Event, Sdl2Lib_Event, 0);
	__INITYP(Sdl2Lib__3, Sdl2Lib__3, 0);
	__INITYP(Sdl2Lib__4, Sdl2Lib__4, 0);
	__INITYP(Sdl2Lib__5, Sdl2Lib__5, 0);
	__INITYP(Sdl2Lib__6, Sdl2Lib__6, 0);
	__INITYP(Sdl2Lib_RWops, Sdl2Lib_RWops, 0);
/* BEGIN */
	__ENDMOD;
}
