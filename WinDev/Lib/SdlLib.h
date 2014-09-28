/*  Ofront 1.2 -xtspkae */

#ifndef SdlLib__h
#define SdlLib__h

#include "SYSTEM.h"
#include "SdlWin32.h"

typedef
	struct {
		LONGINT len[1];
		BYTE data[1];
	} *SdlLib_Pointer;

struct SdlLib__1 {
	INTEGER autoclose;
	SdlLib_Pointer fp;
};

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *SdlLib_PUInt8;

struct SdlLib__2 {
	SdlLib_PUInt8 base, here, stop;
};

struct SdlLib__3 {
	SdlLib_Pointer data1;
};

struct SdlLib__4 {
	struct SdlLib__1 stdio;
	struct SdlLib__2 mem;
	struct SdlLib__3 unknown;
};

typedef
	struct SdlLib_ActiveEvent {
		BYTE type;
		CHAR gain, state;
	} SdlLib_ActiveEvent;

typedef
	struct SdlLib_AudioCVTFilter *SdlLib_PAudioCVTFilter;

typedef
	SdlLib_PAudioCVTFilter SdlLib_AudioCVTFilterArray[10];

typedef
	struct SdlLib_AudioCVT {
		INTEGER needed;
		SHORTINT src_format, dst_format;
		LONGREAL rate_incr;
		SdlLib_PUInt8 buf;
		INTEGER len, len_cvt, len_mult;
		LONGREAL len_ratio;
		SdlLib_AudioCVTFilterArray filters;
		char _prvt0[4];
	} SdlLib_AudioCVT;

typedef
	SdlLib_AudioCVT *SdlLib_PAudioCVT;

typedef
	struct SdlLib_AudioCVTFilter {
		SdlLib_PAudioCVT cvt;
		SHORTINT format;
	} SdlLib_AudioCVTFilter;

typedef
	void (*SdlLib_AudioSpecCallback)(SdlLib_Pointer, CHAR*, INTEGER);

typedef
	struct SdlLib_AudioSpec {
		INTEGER freq;
		SHORTINT format;
		CHAR channels, silence;
		SHORTINT samples, padding;
		INTEGER size;
		SdlLib_AudioSpecCallback callback;
		SdlLib_Pointer userdata;
	} SdlLib_AudioSpec;

typedef
	struct SdlLib_BallDelta {
		INTEGER dx, dy;
	} SdlLib_BallDelta;

typedef
	struct SdlLib_Surface *SdlLib_PSurface;

typedef
	struct SdlLib_Rect *SdlLib_PRect;

typedef
	INTEGER (*SdlLib_Blit)(SdlLib_PSurface, SdlLib_PRect, SdlLib_PSurface, SdlLib_PRect);

typedef
	struct SdlLib_PixelFormat *SdlLib_PPixelFormat;

typedef
	struct SdlLib_BlitInfo {
		SdlLib_PUInt8 s_pixels;
		INTEGER s_width, s_height, s_skip;
		SdlLib_PUInt8 d_pixels;
		INTEGER d_width, d_height, d_skip;
		SdlLib_Pointer aux_data;
		SdlLib_PPixelFormat src;
		SdlLib_PUInt8 table;
		SdlLib_PPixelFormat dst;
	} SdlLib_BlitInfo;

typedef
	struct SdlLib_CDTrack {
		CHAR id, type;
		SHORTINT unused;
		INTEGER length, offset;
	} SdlLib_CDTrack;

typedef
	struct SdlLib_CD {
		char _prvt0[8];
		INTEGER numtracks, cur_track, cur_frame;
		SdlLib_CDTrack track[100];
	} SdlLib_CD;

typedef
	struct SdlLib_Color {
		CHAR r, g, b, unused;
	} SdlLib_Color;

typedef
	SdlLib_Color SdlLib_ColorArray[65001];

typedef
	struct SdlLib_Rect {
		SHORTINT x, y, w, h;
	} SdlLib_Rect;

typedef
	struct SdlLib_Cursor {
		SdlLib_Rect area;
		SHORTINT hot_x, hot_y;
		SdlLib_PUInt8 data, mask;
		SdlLib_PUInt8 save[2];
		SdlLib_Pointer wm_cursor;
	} SdlLib_Cursor;

typedef
	struct SdlLib_KeySym {
		CHAR scancode;
		INTEGER sym;
		SET modifier;
		SHORTINT unicode;
	} SdlLib_KeySym;

typedef
	struct SdlLib_KeyboardEvent {
		BYTE type;
		CHAR which, state;
		SdlLib_KeySym keysym;
	} SdlLib_KeyboardEvent;

typedef
	struct SdlLib_MouseMotionEvent {
		BYTE type;
		CHAR which, state;
		SHORTINT x, y, xrel, yrel;
	} SdlLib_MouseMotionEvent;

typedef
	struct SdlLib_MouseButtonEvent {
		BYTE type;
		CHAR which, button, state;
		SHORTINT x, y;
	} SdlLib_MouseButtonEvent;

typedef
	struct SdlLib_JoyAxisEvent {
		BYTE type;
		CHAR which, axis;
		SHORTINT value;
	} SdlLib_JoyAxisEvent;

typedef
	struct SdlLib_JoyBallEvent {
		BYTE type;
		CHAR which, ball;
		SHORTINT xrel, yrel;
	} SdlLib_JoyBallEvent;

typedef
	struct SdlLib_JoyHatEvent {
		BYTE type;
		CHAR which, hat, value;
	} SdlLib_JoyHatEvent;

typedef
	struct SdlLib_JoyButtonEvent {
		BYTE type;
		CHAR which, button, state;
	} SdlLib_JoyButtonEvent;

typedef
	struct SdlLib_ResizeEvent {
		BYTE type;
		INTEGER w, h;
	} SdlLib_ResizeEvent;

typedef
	struct SdlLib_ExposeEvent {
		BYTE type;
	} SdlLib_ExposeEvent;

typedef
	struct SdlLib_QuitEvent {
		BYTE type;
	} SdlLib_QuitEvent;

typedef
	struct SdlLib_UserEvent {
		BYTE type;
		INTEGER code;
		SdlLib_Pointer data1, data2;
	} SdlLib_UserEvent;

typedef
	struct SdlLib_SysWMEvent {
		BYTE type;
		SdlWin32_PSysWMmsg msg;
	} SdlLib_SysWMEvent;

typedef
	struct SdlLib_Event {
		BYTE type;
		SdlLib_ActiveEvent active;
		SdlLib_KeyboardEvent key;
		SdlLib_MouseMotionEvent motion;
		SdlLib_MouseButtonEvent button;
		SdlLib_JoyAxisEvent jaxis;
		SdlLib_JoyBallEvent jball;
		SdlLib_JoyHatEvent jhat;
		SdlLib_JoyButtonEvent jbutton;
		SdlLib_ResizeEvent resize;
		SdlLib_ExposeEvent expose;
		SdlLib_QuitEvent quit;
		SdlLib_UserEvent user;
		SdlLib_SysWMEvent syswm;
	} SdlLib_Event;

typedef
	SdlLib_Event *SdlLib_PEvent;

typedef
	INTEGER (*SdlLib_EventFilter)(SdlLib_PEvent);

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *SdlLib_PChar;

typedef
	struct {
		LONGINT len[1];
		SHORTINT data[1];
	} *SdlLib_PUInt16;

typedef
	SdlLib_BallDelta *SdlLib_PBallDelta;

typedef
	struct SdlLib_JoystickHWdata *SdlLib_PJoystickHWdata;

typedef
	struct SdlLib_Joystick {
		CHAR index;
		SdlLib_PChar name;
		INTEGER naxes;
		SdlLib_PUInt16 axes;
		INTEGER nhats;
		SdlLib_PUInt8 hats;
		INTEGER nballs;
		SdlLib_PBallDelta balls;
		INTEGER nbuttons;
		SdlLib_PUInt8 buttons;
		SdlLib_PJoystickHWdata hwdata;
		INTEGER ref_count;
	} SdlLib_Joystick;

typedef
	struct SdlLib_TransAxis {
		INTEGER offset;
		REAL scale;
	} SdlLib_TransAxis;

typedef
	struct SdlLib_JoystickHWdata {
		INTEGER id;
		SdlLib_TransAxis transaxis[6];
	} SdlLib_JoystickHWdata;

typedef
	INTEGER (*SdlLib_NewTimerCallback)(INTEGER, SdlLib_Pointer);

typedef
	struct SdlLib_Overlay {
		INTEGER format, w, h, planes;
		SdlLib_PUInt16 pitches;
		SdlLib_Pointer pixels;
		INTEGER hw_overlay;
	} SdlLib_Overlay;

typedef
	SdlLib_AudioCVTFilterArray *SdlLib_PAudioCVTFilterArray;

typedef
	SdlLib_AudioSpec *SdlLib_PAudioSpec;

typedef
	SdlLib_BlitInfo *SdlLib_PBlitInfo;

typedef
	struct {
		LONGINT len[1];
		BYTE data[1];
	} *SdlLib_PByte;

typedef
	SdlLib_CD *SdlLib_PCD;

typedef
	SdlLib_CDTrack *SdlLib_PCDTrack;

typedef
	SdlLib_Color *SdlLib_PColor;

typedef
	SdlLib_ColorArray *SdlLib_PColorArray;

typedef
	SdlLib_Cursor *SdlLib_PCursor;

typedef
	SdlLib_ExposeEvent *SdlLib_PExposeEvent;

typedef
	struct {
		LONGINT len[1];
		INTEGER data[1];
	} *SdlLib_PInteger;

typedef
	SdlLib_Joystick *SdlLib_PJoystick;

typedef
	SdlLib_KeySym *SdlLib_PKeySym;

typedef
	struct {
		LONGINT len[1];
		INTEGER data[1];
	} *SdlLib_PLongWord;

typedef
	SdlLib_Overlay *SdlLib_POverlay;

typedef
	struct {
		LONGINT len[1];
		SdlLib_PRect data[1];
	} *SdlLib_PPRect;

typedef
	struct SdlLib_Palette *SdlLib_PPalette;

typedef
	SdlLib_QuitEvent *SdlLib_PQuitEvent;

typedef
	struct SdlLib_RWops *SdlLib_PRWops;

typedef
	SdlLib_SysWMEvent *SdlLib_PSysWMEvent;

typedef
	struct SdlLib_TimerID *SdlLib_PTimerID;

typedef
	SdlLib_TransAxis *SdlLib_PTransAxis;

typedef
	struct {
		LONGINT len[1];
		INTEGER data[1];
	} *SdlLib_PUInt32;

typedef
	SdlLib_UserEvent *SdlLib_PUserEvent;

typedef
	SdlWin32_Version *SdlLib_PVersion;

typedef
	struct SdlLib_VideoInfo *SdlLib_PVideoInfo;

typedef
	struct {
		LONGINT len[1];
		SHORTINT data[1];
	} *SdlLib_PWord;

typedef
	struct SdlLib_Palette {
		INTEGER ncolors;
		SdlLib_PColorArray colors;
	} SdlLib_Palette;

typedef
	struct SdlLib_PixelFormat {
		SdlLib_PPalette palette;
		BYTE BitsPerPixel, BytesPerPixel;
		CHAR Rloss, Gloss, Bloss, Aloss, Rshift, Gshift, Bshift, Ashift;
		INTEGER Rmask, Gmask, Bmask, Amask, colorkey;
		CHAR alpha;
	} SdlLib_PixelFormat;

typedef
	struct SdlLib_RWops {
		INTEGER (*seek)(SdlLib_PRWops, INTEGER, INTEGER);
		INTEGER (*read)(SdlLib_PRWops, SdlLib_Pointer, INTEGER, INTEGER);
		INTEGER (*write)(SdlLib_PRWops, SdlLib_Pointer, INTEGER, INTEGER);
		INTEGER (*close)(SdlLib_PRWops);
		INTEGER type;
		struct SdlLib__4 hidden;
	} SdlLib_RWops;

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

typedef
	INTEGER (*SdlLib_TimerCallback)(INTEGER);

typedef
	struct SdlLib_TimerID {
		INTEGER interval;
		SdlLib_NewTimerCallback callback;
		SdlLib_Pointer param;
		INTEGER last_alarm;
		SdlLib_PTimerID next;
	} SdlLib_TimerID;

typedef
	struct SdlLib_VideoInfo {
		CHAR hw_available, blit_hw, UnusedBits3;
		INTEGER video_mem;
		SdlLib_PPixelFormat vfmt;
		INTEGER current_w, current_h;
	} SdlLib_VideoInfo;



import LONGINT *SdlLib__1__typ;
import LONGINT *SdlLib__2__typ;
import LONGINT *SdlLib__3__typ;
import LONGINT *SdlLib__4__typ;
import LONGINT *SdlLib_RWops__typ;
import LONGINT *SdlLib_TimerID__typ;
import LONGINT *SdlLib_AudioSpec__typ;
import LONGINT *SdlLib_AudioCVTFilter__typ;
import LONGINT *SdlLib_AudioCVT__typ;
import LONGINT *SdlLib_CDTrack__typ;
import LONGINT *SdlLib_CD__typ;
import LONGINT *SdlLib_TransAxis__typ;
import LONGINT *SdlLib_JoystickHWdata__typ;
import LONGINT *SdlLib_BallDelta__typ;
import LONGINT *SdlLib_Joystick__typ;
import LONGINT *SdlLib_KeySym__typ;
import LONGINT *SdlLib_ActiveEvent__typ;
import LONGINT *SdlLib_KeyboardEvent__typ;
import LONGINT *SdlLib_MouseMotionEvent__typ;
import LONGINT *SdlLib_MouseButtonEvent__typ;
import LONGINT *SdlLib_JoyAxisEvent__typ;
import LONGINT *SdlLib_JoyBallEvent__typ;
import LONGINT *SdlLib_JoyHatEvent__typ;
import LONGINT *SdlLib_JoyButtonEvent__typ;
import LONGINT *SdlLib_ResizeEvent__typ;
import LONGINT *SdlLib_QuitEvent__typ;
import LONGINT *SdlLib_UserEvent__typ;
import LONGINT *SdlLib_ExposeEvent__typ;
import LONGINT *SdlLib_SysWMEvent__typ;
import LONGINT *SdlLib_Event__typ;
import LONGINT *SdlLib_Rect__typ;
import LONGINT *SdlLib_Color__typ;
import LONGINT *SdlLib_Palette__typ;
import LONGINT *SdlLib_PixelFormat__typ;
import LONGINT *SdlLib_BlitInfo__typ;
import LONGINT *SdlLib_Surface__typ;
import LONGINT *SdlLib_VideoInfo__typ;
import LONGINT *SdlLib_Overlay__typ;
import LONGINT *SdlLib_Cursor__typ;

import void *SdlLib__init(void);

#define SdlLib_AddTimer(interval, callback, param)	SDL_AddTimer(interval, callback, param)
#define SdlLib_AllocRW()	SDL_AllocRW()
#define SdlLib_AllocSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)
#define SdlLib_AudioDriverName(nameBuf, maxLen)	SDL_AudioDriverName(nameBuf, maxLen)
#define SdlLib_AudioInit(driverName)	SDL_AudioInit(driverName)
#define SdlLib_AudioQuit()	SDL_AudioQuit()
#define SdlLib_BlitSurface(src, srcRect, dst, dstRect)	SDL_UpperBlit(src, srcRect, dst, dstRect)
#define SdlLib_BuildAudioCVT(cvt, srcFormat, srcChannels, srcRate, dstFormat, dstChannels, dstRate)	SDL_BuildAudioCVT(cvt, srcFormat, srcChannels, srcRate, dstFormat, dstChannels, dstRate)
#define SdlLib_CDClose(cdRom)	SDL_CDClose(cdRom)
#define SdlLib_CDEject(cdRom)	SDL_CDEject(cdRom)
#define SdlLib_CDName(drive)	SDL_CDName(drive)
#define SdlLib_CDNumDrives()	SDL_CDNumDrives()
#define SdlLib_CDOpen(drive)	SDL_CDOpen(drive)
#define SdlLib_CDPause(cdRom)	SDL_CDPause(cdRom)
#define SdlLib_CDPlay(cdRom, start, length)	SDL_CDPlay(cdRom, start, length)
#define SdlLib_CDPlayTracks(cdRom, startTrack, startFrame, nTracks, nFrames)	SDL_CDPlayTracks(cdRom, startTrack, startFrame, nTracks, nFrames)
#define SdlLib_CDResume(cdRom)	SDL_CDResume(cdRom)
#define SdlLib_CDStatus(cdRom)	SDL_CDStatus(cdRom)
#define SdlLib_CDStop(cdRom)	SDL_CDStop(cdRom)
#define SdlLib_ClearError()	SDL_ClearError()
#define SdlLib_CloseAudio()	SDL_CloseAudio()
#define SdlLib_ConvertAudio(cvt)	SDL_ConvertAudio(cvt)
#define SdlLib_ConvertSurface(src, fmt, flags)	SDL_ConvertSurface(src, fmt, flags)
#define SdlLib_CreateCursor(data, mask, w, h, hotX, hotY)	SDL_CreateCursor(data, mask, w, h, hotX, hotY)
#define SdlLib_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)
#define SdlLib_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rMask, gMask, bMask, aMask)
#define SdlLib_CreateYUVOverlay(width, height, format, display)	SDL_CreateYUVOverlay(width, height, format, display)
#define SdlLib_Delay(msec)	SDL_Delay(msec)
#define SdlLib_DisplayFormat(surface)	SDL_DisplayFormat(surface)
#define SdlLib_DisplayFormatAlpha(surface)	SDL_DisplayFormatAlpha(surface)
#define SdlLib_DisplayYUVOverlay(overlay, dstRect)	SDL_DisplayYUVOverlay(overlay, dstRect)
#define SdlLib_EnableKeyRepeat(delay, interval)	SDL_EnableKeyRepeat(delay, interval)
#define SdlLib_EnableUNICODE(enable)	SDL_EnableUNICODE(enable)
#define SdlLib_EventState(type, state)	SDL_EventState(type, state)
#define SdlLib_FillRect(dst, dstRect, color)	SDL_FillRect(dst, dstRect, color)
#define SdlLib_Flip(screen)	SDL_Flip(screen)
#define SdlLib_FreeCursor(cursor)	SDL_FreeCursor(cursor)
#define SdlLib_FreeRW(area)	SDL_FreeRW(area)
#define SdlLib_FreeSurface(surface)	SDL_FreeSurface(surface)
#define SdlLib_FreeWAV(audioBuf)	SDL_FreeWAV(audioBuf)
#define SdlLib_FreeYUVOverlay(overlay)	SDL_FreeYUVOverlay(overlay)
#define SdlLib_GL_GetAttribute(attr, value)	SDL_GL_GetAttribute(attr, value)
#define SdlLib_GL_GetProcAddress(procName)	SDL_GL_GetProcAddress(procName)
#define SdlLib_GL_LoadLibrary(fileName)	SDL_GL_LoadLibrary(fileName)
#define SdlLib_GL_Lock()	SDL_GL_Lock()
#define SdlLib_GL_SetAttribute(attr, value)	SDL_GL_SetAttribute(attr, value)
#define SdlLib_GL_SwapBuffers()	SDL_GL_SwapBuffers()
#define SdlLib_GL_Unlock()	SDL_GL_Unlock()
#define SdlLib_GL_UpdateRects(numRects, rects)	SDL_GL_UpdateRects(numRects, rects)
#define SdlLib_GetAppState()	SDL_GetAppState()
#define SdlLib_GetAudioStatus()	SDL_GetAudioStatus()
#define SdlLib_GetClipRect(surface, rect, rect__typ)	SDL_GetClipRect(surface, rect)
#define SdlLib_GetCursor()	SDL_GetCursor()
#define SdlLib_GetError()	SDL_GetError()
#define SdlLib_GetEventFilter()	SDL_GetEventFilter()
#define SdlLib_GetGammaRamp(redTable, greenTable, blueTable)	SDL_GetGammaRamp(redTable, greenTable, blueTable)
#define SdlLib_GetKeyName(key)	SDL_GetKeyName(key)
#define SdlLib_GetKeyRepeat(delay, interval)	SDL_GetKeyRepeat(delay, interval)
#define SdlLib_GetKeyState(numKeys)	SDL_GetKeyState(numKeys)
#define SdlLib_GetModState()	SDL_GetModState()
#define SdlLib_GetMouseState(x, y)	SDL_GetMouseState(x, y)
#define SdlLib_GetRGB(pixel, fmt, r, g, b)	SDL_GetRGB(pixel, fmt, r, g, b)
#define SdlLib_GetRGBA(pixel, fmt, r, g, b, a)	SDL_GetRGBA(pixel, fmt, r, g, b, a)
#define SdlLib_GetRelativeMouseState(x, y)	SDL_GetRelativeMouseState(x, y)
#define SdlLib_GetTicks()	SDL_GetTicks()
#define SdlLib_GetVideoInfo()	SDL_GetVideoInfo()
#define SdlLib_GetVideoSurface()	SDL_GetVideoSurface()
#define SdlLib_GetWMInfo(info)	SDL_GetWMInfo(info)
#define SdlLib_Init(flags)	SDL_Init(flags)
#define SdlLib_InitSubSystem(flags)	SDL_InitSubSystem(flags)
#define SdlLib_JoystickClose(joystick)	SDL_JoystickClose(joystick)
#define SdlLib_JoystickEventState(state)	SDL_JoystickEventState(state)
#define SdlLib_JoystickGetAxis(joystick, axis)	SDL_JoystickGetAxis(joystick, axis)
#define SdlLib_JoystickGetBall(joystick, ball, dx, dy)	SDL_JoystickGetBall(joystick, ball, dx, dy)
#define SdlLib_JoystickGetButton(joystick, Button)	SDL_JoystickGetButton(joystick, Button)
#define SdlLib_JoystickGetHat(joystick, hat)	SDL_JoystickGetHat(joystick, hat)
#define SdlLib_JoystickIndex(joystick)	SDL_JoystickIndex(joystick)
#define SdlLib_JoystickName(index)	SDL_JoystickName(index)
#define SdlLib_JoystickNumAxes(joystick)	SDL_JoystickNumAxes(joystick)
#define SdlLib_JoystickNumBalls(joystick)	SDL_JoystickNumBalls(joystick)
#define SdlLib_JoystickNumButtons(joystick)	SDL_JoystickNumButtons(joystick)
#define SdlLib_JoystickNumHats(joystick)	SDL_JoystickNumHats(joystick)
#define SdlLib_JoystickOpen(index)	SDL_JoystickOpen(index)
#define SdlLib_JoystickOpened(index)	SDL_JoystickOpened(index)
#define SdlLib_JoystickUpdate()	SDL_JoystickUpdate()
#define SdlLib_Linked_Version()	SDL_Linked_Version()
#define SdlLib_ListModes(format, flags)	SDL_ListModes(format, flags)
#define SdlLib_LoadBMP_RW(src, freeSrc)	SDL_LoadBMP_RW(src, freeSrc)
#define SdlLib_LoadFunction(handle, name)	SDL_LoadFunction(handle, name)
#define SdlLib_LoadObject(soFile)	SDL_LoadObject(soFile)
#define SdlLib_LoadWAV_RW(src, freeSrc, spec, audioBuf, audioLen)	SDL_LoadWAV_RW(src, freeSrc, spec, audioBuf, audioLen)
#define SdlLib_LockAudio()	SDL_LockAudio()
#define SdlLib_LockSurface(surface)	SDL_LockSurface(surface)
#define SdlLib_LockYUVOverlay(overlay)	SDL_LockYUVOverlay(overlay)
#define SdlLib_LowerBlit(src, srcRect, dst, dstRect)	SDL_LowerBlit(src, srcRect, dst, dstRect)
#define SdlLib_MapRGB(format, r, g, b)	SDL_MapRGB(format, r, g, b)
#define SdlLib_MapRGBA(format, r, g, b, a)	SDL_MapRGBA(format, r, g, b, a)
#define SdlLib_MixAudio(dst, src, len, volume)	SDL_MixAudio(dst, src, len, volume)
#define SdlLib_NumJoysticks()	SDL_NumJoysticks()
#define SdlLib_OpenAudio(desired, obtained)	SDL_OpenAudio(desired, obtained)
#define SdlLib_OutOfMemory()	SDL_OutOfMemory()
#define SdlLib_PauseAudio(pauseOn)	SDL_PauseAudio(pauseOn)
#define SdlLib_PeepEvents(events, events__typ, numEvents, action, mask)	SDL_PeepEvents(events, numEvents, action, mask)
#define SdlLib_PollEvent(event, event__typ)	SDL_PollEvent(event)
#define SdlLib_PumpEvents()	SDL_PumpEvents()
#define SdlLib_PushEvent(event, event__typ)	SDL_PushEvent(event)
#define SdlLib_Quit()	SDL_Quit()
#define SdlLib_QuitSubSystem(flags)	SDL_QuitSubSystem(flags)
#define SdlLib_RWFromConstMem(mem, size)	SDL_RWFromConstMem(mem, size)
#define SdlLib_RWFromFP(fp, autoClose)	SDL_RWFromFP(fp, autoClose)
#define SdlLib_RWFromFile(fileName, mode)	SDL_RWFromFile(fileName, mode)
#define SdlLib_RWFromMem(mem, size)	SDL_RWFromMem(mem, size)
#define SdlLib_RegisterApp(name, style, hInst)	SDL_RegisterApp(name, style, hInst)
#define SdlLib_RemoveTimer(t)	SDL_RemoveTimer(t)
#define SdlLib_SaveBMP_RW(surface, dst, freeDst)	SDL_SaveBMP_RW(surface, dst, freeDst)
#define SdlLib_SetAlpha(surface, flag, alpha)	SDL_SetAlpha(surface, flag, alpha)
#define SdlLib_SetClipRect(surface, rect, rect__typ)	SDL_SetClipRect(surface, rect)
#define SdlLib_SetColorKey(surface, flag, key)	SDL_SetColorKey(surface, flag, key)
#define SdlLib_SetColors(surface, colors, firstColor, nColors)	SDL_SetColors(surface, colors, firstColor, nColors)
#define SdlLib_SetCursor(cursor)	SDL_SetCursor(cursor)
#define SdlLib_SetError(fmt)	SDL_SetError(fmt)
#define SdlLib_SetEventFilter(filter)	SDL_SetEventFilter(filter)
#define SdlLib_SetGamma(redGamma, greenGamma, blueGamma)	SDL_SetGamma(redGamma, greenGamma, blueGamma)
#define SdlLib_SetGammaRamp(redTable, greenTable, blueTable)	SDL_SetGammaRamp(redTable, greenTable, blueTable)
#define SdlLib_SetModState(modState)	SDL_SetModState(modState)
#define SdlLib_SetPalette(surface, flags, colors, firstColor, nColors)	SDL_SetPalette(surface, flags, colors, firstColor, nColors)
#define SdlLib_SetTimer(interval, callback)	SDL_SetTimer(interval, callback)
#define SdlLib_SetVideoMode(width, height, bpp, flags)	SDL_SetVideoMode(width, height, bpp, flags)
#define SdlLib_ShowCursor(toggle)	SDL_ShowCursor(toggle)
#define SdlLib_SoftStretch(src, srcRect, dst, dstRect)	SDL_SoftStretch(src, srcRect, dst, dstRect)
#define SdlLib_TableSize(table)	SDL_TableSize(table)
#define SdlLib_UnloadObject(handle)	SDL_UnloadObject(handle)
#define SdlLib_UnlockAudio()	SDL_UnlockAudio()
#define SdlLib_UnlockSurface(surface)	SDL_UnlockSurface(surface)
#define SdlLib_UnlockYUVOverlay(overlay)	SDL_UnlockYUVOverlay(overlay)
#define SdlLib_UpdateRect(screen, x, y, w, h)	SDL_UpdateRect(screen, x, y, w, h)
#define SdlLib_UpdateRects(screen, numRects, rects)	SDL_UpdateRects(screen, numRects, rects)
#define SdlLib_UpperBlit(src, srcRect, dst, dstRect)	SDL_UpperBlit(src, srcRect, dst, dstRect)
#define SdlLib_VideoDriverName(nameBuf, maxLen)	SDL_VideoDriverName(nameBuf, maxLen)
#define SdlLib_VideoInit(driverName, flags)	SDL_VideoInit(driverName, flags)
#define SdlLib_VideoModeOK(width, height, bpp, flags)	SDL_VideoModeOK(width, height, bpp, flags)
#define SdlLib_VideoQuit()	SDL_VideoQuit()
#define SdlLib_WM_GetCaption(title, icon)	SDL_WM_GetCaption(title, icon)
#define SdlLib_WM_GrabInput(mode)	SDL_WM_GrabInput(mode)
#define SdlLib_WM_IconifyWindow()	SDL_WM_IconifyWindow()
#define SdlLib_WM_SetCaption(title, icon)	SDL_WM_SetCaption(title, icon)
#define SdlLib_WM_SetIcon(icon, mask)	SDL_WM_SetIcon(icon, mask)
#define SdlLib_WM_ToggleFullScreen(surface)	SDL_WM_ToggleFullScreen(surface)
#define SdlLib_WaitEvent(event, event__typ)	SDL_WaitEvent(event)
#define SdlLib_WarpMouse(x, y)	SDL_WarpMouse(x, y)
#define SdlLib_WasInit(flags)	SDL_WasInit(flags)

#endif
