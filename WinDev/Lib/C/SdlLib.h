/*  Ofront 1.2 -xtspkae */

#ifndef SdlLib__h
#define SdlLib__h

#include "SYSTEM.h"
#include "SdlWin32.h"

struct SdlLib__1 {
	INTEGER autoclose;
	SYSTEM_PTR fp;
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
	SYSTEM_PTR data1;
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
	void (*SdlLib_AudioSpecCallback)(SYSTEM_PTR, CHAR*, INTEGER);

typedef
	struct SdlLib_AudioSpec {
		INTEGER freq;
		SHORTINT format;
		CHAR channels, silence;
		SHORTINT samples, padding;
		INTEGER size;
		SdlLib_AudioSpecCallback callback;
		SYSTEM_PTR userdata;
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
		SYSTEM_PTR aux_data;
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
		SYSTEM_PTR wm_cursor;
	} SdlLib_Cursor;

typedef
	struct SdlLib_Event {
		CHAR type;
		char _prvt0[32];
	} SdlLib_Event;

typedef
	SdlLib_Event *SdlLib_PEvent;

typedef
	INTEGER (*SdlLib_EventFilter)(SdlLib_PEvent);

typedef
	struct SdlLib_ExposeEvent {
		BYTE type;
	} SdlLib_ExposeEvent;

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
	struct SdlLib_JoyButtonEvent {
		BYTE type;
		CHAR which, button, state;
	} SdlLib_JoyButtonEvent;

typedef
	struct SdlLib_JoyHatEvent {
		BYTE type;
		CHAR which, hat, value;
	} SdlLib_JoyHatEvent;

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
		SYSTEM_PTR name;
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
	struct SdlLib_MouseButtonEvent {
		BYTE type;
		CHAR which, button, state;
		SHORTINT x, y;
	} SdlLib_MouseButtonEvent;

typedef
	struct SdlLib_MouseMotionEvent {
		BYTE type;
		CHAR which, state;
		SHORTINT x, y, xrel, yrel;
	} SdlLib_MouseMotionEvent;

typedef
	INTEGER (*SdlLib_NewTimerCallback)(INTEGER, SYSTEM_PTR);

typedef
	struct SdlLib_Overlay {
		INTEGER format, w, h, planes;
		SdlLib_PUInt16 pitches;
		SYSTEM_PTR pixels;
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
	struct SdlLib_QuitEvent *SdlLib_PQuitEvent;

typedef
	struct SdlLib_RWops *SdlLib_PRWops;

typedef
	struct SdlLib_SysWMEvent *SdlLib_PSysWMEvent;

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
	struct SdlLib_UserEvent *SdlLib_PUserEvent;

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
	struct SdlLib_QuitEvent {
		BYTE type;
	} SdlLib_QuitEvent;

typedef
	struct SdlLib_RWops {
		INTEGER (*seek)(SdlLib_PRWops, INTEGER, INTEGER);
		INTEGER (*read)(SdlLib_PRWops, SYSTEM_PTR, INTEGER, INTEGER);
		INTEGER (*write)(SdlLib_PRWops, SYSTEM_PTR, INTEGER, INTEGER);
		INTEGER (*close)(SdlLib_PRWops);
		INTEGER type;
		struct SdlLib__4 hidden;
	} SdlLib_RWops;

typedef
	struct SdlLib_ResizeEvent {
		BYTE type;
		INTEGER w, h;
	} SdlLib_ResizeEvent;

typedef
	struct SdlLib_Surface {
		SET flags;
		SdlLib_PPixelFormat format;
		INTEGER w, h;
		SHORTINT pitch;
		SYSTEM_PTR pixels;
		INTEGER offset;
		SYSTEM_PTR hwdata;
		SdlLib_Rect clip_rect;
		char _prvt0[4];
		INTEGER locked;
		SYSTEM_PTR map;
		INTEGER format_version, refcount;
	} SdlLib_Surface;

typedef
	struct SdlLib_SysWMEvent {
		BYTE type;
		SdlWin32_PSysWMmsg msg;
	} SdlLib_SysWMEvent;

typedef
	INTEGER (*SdlLib_TimerCallback)(INTEGER);

typedef
	struct SdlLib_TimerID {
		INTEGER interval;
		SdlLib_NewTimerCallback callback;
		SYSTEM_PTR param;
		INTEGER last_alarm;
		SdlLib_PTimerID next;
	} SdlLib_TimerID;

typedef
	struct SdlLib_UserEvent {
		BYTE type;
		INTEGER code;
		SYSTEM_PTR data1, data2;
	} SdlLib_UserEvent;

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
#define SdlLib_AudioDriverName(nameBuf, nameBuf__len, maxLen)	SDL_AudioDriverName(nameBuf, maxLen)
#define SdlLib_AudioInit(driverName, driverName__len)	SDL_AudioInit(driverName)
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
#define SdlLib_GL_GetProcAddress(procName, procName__len)	SDL_GL_GetProcAddress(procName)
#define SdlLib_GL_LoadLibrary(fileName, fileName__len)	SDL_GL_LoadLibrary(fileName)
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
#define SdlLib_LoadFunction(handle, name, name__len)	SDL_LoadFunction(handle, name)
#define SdlLib_LoadObject(soFile, soFile__len)	SDL_LoadObject(soFile)
#define SdlLib_LoadWAV_RW(src, freeSrc, spec, audioBuf, audioLen)	SDL_LoadWAV_RW(src, freeSrc, spec, audioBuf, audioLen)
#define SdlLib_LockAudio()	SDL_LockAudio()
#define SdlLib_LockSurface(surface)	SDL_LockSurface(surface)
#define SdlLib_LockYUVOverlay(overlay)	SDL_LockYUVOverlay(overlay)
#define SdlLib_LowerBlit(src, srcRect, dst, dstRect)	SDL_LowerBlit(src, srcRect, dst, dstRect)
#define SdlLib_MapRGB(format, r, g, b)	SDL_MapRGB(format, r, g, b)
#define SdlLib_MapRGBA(format, r, g, b, a)	SDL_MapRGBA(format, r, g, b, a)
#define SdlLib_MixAudio(dst, src, len, volume)	SDL_MixAudio(dst, src, len, volume)
#define SdlLib_MustLock(surface)	(surface->offset || ((surface->flags & (0x00000001|0x00000004|0x00004000)) != 0))
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
#define SdlLib_RWFromFile(fileName, fileName__len, mode, mode__len)	SDL_RWFromFile(fileName, mode)
#define SdlLib_RWFromMem(mem, size)	SDL_RWFromMem(mem, size)
#define SdlLib_RegisterApp(name, name__len, style, hInst)	SDL_RegisterApp(name, style, hInst)
#define SdlLib_RemoveTimer(t)	SDL_RemoveTimer(t)
#define SdlLib_SDL_AddTimer(interval, callback, param)	SDL_AddTimer(interval, callback, param)
__EXTERN SdlLib_PTimerID SDL_AddTimer(INTEGER interval, SdlLib_NewTimerCallback callback, SYSTEM_PTR param);
#define SdlLib_SDL_AllocRW()	SDL_AllocRW()
__EXTERN SdlLib_PRWops SDL_AllocRW(void);
#define SdlLib_SDL_AudioDriverName(nameBuf, nameBuf__len, maxLen)	SDL_AudioDriverName(nameBuf, maxLen)
__EXTERN SYSTEM_PTR SDL_AudioDriverName(CHAR *nameBuf, INTEGER maxLen);
#define SdlLib_SDL_AudioInit(driverName, driverName__len)	SDL_AudioInit(driverName)
__EXTERN INTEGER SDL_AudioInit(CHAR *driverName);
#define SdlLib_SDL_AudioQuit()	SDL_AudioQuit()
__EXTERN void SDL_AudioQuit(void);
#define SdlLib_SDL_BuildAudioCVT(cvt, srcFormat, srcChannels, srcRate, dstFormat, dstChannels, dstRate)	SDL_BuildAudioCVT(cvt, srcFormat, srcChannels, srcRate, dstFormat, dstChannels, dstRate)
__EXTERN INTEGER SDL_BuildAudioCVT(SdlLib_PAudioCVT cvt, SHORTINT srcFormat, CHAR srcChannels, INTEGER srcRate, SHORTINT dstFormat, CHAR dstChannels, INTEGER dstRate);
#define SdlLib_SDL_CDClose(cdRom)	SDL_CDClose(cdRom)
__EXTERN void SDL_CDClose(SdlLib_PCD cdRom);
#define SdlLib_SDL_CDEject(cdRom)	SDL_CDEject(cdRom)
__EXTERN INTEGER SDL_CDEject(SdlLib_PCD cdRom);
#define SdlLib_SDL_CDName(drive)	SDL_CDName(drive)
__EXTERN SYSTEM_PTR SDL_CDName(INTEGER drive);
#define SdlLib_SDL_CDNumDrives()	SDL_CDNumDrives()
__EXTERN INTEGER SDL_CDNumDrives(void);
#define SdlLib_SDL_CDOpen(drive)	SDL_CDOpen(drive)
__EXTERN SdlLib_PCD SDL_CDOpen(INTEGER drive);
#define SdlLib_SDL_CDPause(cdRom)	SDL_CDPause(cdRom)
__EXTERN INTEGER SDL_CDPause(SdlLib_PCD cdRom);
#define SdlLib_SDL_CDPlay(cdRom, start, length)	SDL_CDPlay(cdRom, start, length)
__EXTERN INTEGER SDL_CDPlay(SdlLib_PCD cdRom, INTEGER start, INTEGER length);
#define SdlLib_SDL_CDPlayTracks(cdRom, startTrack, startFrame, nTracks, nFrames)	SDL_CDPlayTracks(cdRom, startTrack, startFrame, nTracks, nFrames)
__EXTERN INTEGER SDL_CDPlayTracks(SdlLib_PCD cdRom, INTEGER startTrack, INTEGER startFrame, INTEGER nTracks, INTEGER nFrames);
#define SdlLib_SDL_CDResume(cdRom)	SDL_CDResume(cdRom)
__EXTERN INTEGER SDL_CDResume(SdlLib_PCD cdRom);
#define SdlLib_SDL_CDStatus(cdRom)	SDL_CDStatus(cdRom)
__EXTERN INTEGER SDL_CDStatus(SdlLib_PCD cdRom);
#define SdlLib_SDL_CDStop(cdRom)	SDL_CDStop(cdRom)
__EXTERN INTEGER SDL_CDStop(SdlLib_PCD cdRom);
#define SdlLib_SDL_ClearError()	SDL_ClearError()
__EXTERN void SDL_ClearError(void);
#define SdlLib_SDL_CloseAudio()	SDL_CloseAudio()
__EXTERN void SDL_CloseAudio(void);
#define SdlLib_SDL_ConvertAudio(cvt)	SDL_ConvertAudio(cvt)
__EXTERN INTEGER SDL_ConvertAudio(SdlLib_PAudioCVT cvt);
#define SdlLib_SDL_ConvertSurface(src, fmt, flags)	SDL_ConvertSurface(src, fmt, flags)
__EXTERN SdlLib_PSurface SDL_ConvertSurface(SdlLib_PSurface src, SdlLib_PPixelFormat fmt, SET flags);
#define SdlLib_SDL_CreateCursor(data, mask, w, h, hotX, hotY)	SDL_CreateCursor(data, mask, w, h, hotX, hotY)
__EXTERN SdlLib_PCursor SDL_CreateCursor(SdlLib_PUInt8 data, SdlLib_PUInt8 mask, INTEGER w, INTEGER h, INTEGER hotX, INTEGER hotY);
#define SdlLib_SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurface(flags, width, height, depth, rMask, gMask, bMask, aMask)
__EXTERN SdlLib_PSurface SDL_CreateRGBSurface(SET flags, INTEGER width, INTEGER height, INTEGER depth, INTEGER rMask, INTEGER gMask, INTEGER bMask, INTEGER aMask);
#define SdlLib_SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rMask, gMask, bMask, aMask)	SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, rMask, gMask, bMask, aMask)
__EXTERN SdlLib_PSurface SDL_CreateRGBSurfaceFrom(SYSTEM_PTR pixels, INTEGER width, INTEGER height, INTEGER depth, INTEGER pitch, INTEGER rMask, INTEGER gMask, INTEGER bMask, INTEGER aMask);
#define SdlLib_SDL_CreateYUVOverlay(width, height, format, display)	SDL_CreateYUVOverlay(width, height, format, display)
__EXTERN SdlLib_POverlay SDL_CreateYUVOverlay(INTEGER width, INTEGER height, INTEGER format, SdlLib_PSurface display);
#define SdlLib_SDL_Delay(msec)	SDL_Delay(msec)
__EXTERN void SDL_Delay(INTEGER msec);
#define SdlLib_SDL_DisplayFormat(surface)	SDL_DisplayFormat(surface)
__EXTERN SdlLib_PSurface SDL_DisplayFormat(SdlLib_PSurface surface);
#define SdlLib_SDL_DisplayFormatAlpha(surface)	SDL_DisplayFormatAlpha(surface)
__EXTERN SdlLib_PSurface SDL_DisplayFormatAlpha(SdlLib_PSurface surface);
#define SdlLib_SDL_DisplayYUVOverlay(overlay, dstRect)	SDL_DisplayYUVOverlay(overlay, dstRect)
__EXTERN INTEGER SDL_DisplayYUVOverlay(SdlLib_POverlay overlay, SdlLib_PRect dstRect);
#define SdlLib_SDL_EnableKeyRepeat(delay, interval)	SDL_EnableKeyRepeat(delay, interval)
__EXTERN INTEGER SDL_EnableKeyRepeat(INTEGER delay, INTEGER interval);
#define SdlLib_SDL_EnableUNICODE(enable)	SDL_EnableUNICODE(enable)
__EXTERN INTEGER SDL_EnableUNICODE(INTEGER enable);
#define SdlLib_SDL_EventState(type, state)	SDL_EventState(type, state)
__EXTERN CHAR SDL_EventState(CHAR type, INTEGER state);
#define SdlLib_SDL_FillRect(dst, dstRect, color)	SDL_FillRect(dst, dstRect, color)
__EXTERN INTEGER SDL_FillRect(SdlLib_PSurface dst, SdlLib_PRect dstRect, INTEGER color);
#define SdlLib_SDL_Flip(screen)	SDL_Flip(screen)
__EXTERN INTEGER SDL_Flip(SdlLib_PSurface screen);
#define SdlLib_SDL_FreeCursor(cursor)	SDL_FreeCursor(cursor)
__EXTERN void SDL_FreeCursor(SdlLib_PCursor cursor);
#define SdlLib_SDL_FreeRW(area)	SDL_FreeRW(area)
__EXTERN void SDL_FreeRW(SdlLib_PRWops area);
#define SdlLib_SDL_FreeSurface(surface)	SDL_FreeSurface(surface)
__EXTERN void SDL_FreeSurface(SdlLib_PSurface surface);
#define SdlLib_SDL_FreeWAV(audioBuf)	SDL_FreeWAV(audioBuf)
__EXTERN void SDL_FreeWAV(SdlLib_PUInt8 audioBuf);
#define SdlLib_SDL_FreeYUVOverlay(overlay)	SDL_FreeYUVOverlay(overlay)
__EXTERN void SDL_FreeYUVOverlay(SdlLib_POverlay overlay);
#define SdlLib_SDL_GL_GetAttribute(attr, value)	SDL_GL_GetAttribute(attr, value)
__EXTERN INTEGER SDL_GL_GetAttribute(INTEGER attr, INTEGER *value);
#define SdlLib_SDL_GL_GetProcAddress(procName, procName__len)	SDL_GL_GetProcAddress(procName)
__EXTERN SYSTEM_PTR SDL_GL_GetProcAddress(CHAR *procName);
#define SdlLib_SDL_GL_LoadLibrary(fileName, fileName__len)	SDL_GL_LoadLibrary(fileName)
__EXTERN INTEGER SDL_GL_LoadLibrary(CHAR *fileName);
#define SdlLib_SDL_GL_Lock()	SDL_GL_Lock()
__EXTERN void SDL_GL_Lock(void);
#define SdlLib_SDL_GL_SetAttribute(attr, value)	SDL_GL_SetAttribute(attr, value)
__EXTERN INTEGER SDL_GL_SetAttribute(INTEGER attr, INTEGER value);
#define SdlLib_SDL_GL_SwapBuffers()	SDL_GL_SwapBuffers()
__EXTERN void SDL_GL_SwapBuffers(void);
#define SdlLib_SDL_GL_Unlock()	SDL_GL_Unlock()
__EXTERN void SDL_GL_Unlock(void);
#define SdlLib_SDL_GL_UpdateRects(numRects, rects)	SDL_GL_UpdateRects(numRects, rects)
__EXTERN void SDL_GL_UpdateRects(INTEGER numRects, SdlLib_PRect rects);
#define SdlLib_SDL_GetAppState()	SDL_GetAppState()
__EXTERN CHAR SDL_GetAppState(void);
#define SdlLib_SDL_GetAudioStatus()	SDL_GetAudioStatus()
__EXTERN INTEGER SDL_GetAudioStatus(void);
#define SdlLib_SDL_GetClipRect(surface, rect, rect__typ)	SDL_GetClipRect(surface, rect)
__EXTERN void SDL_GetClipRect(SdlLib_PSurface surface, SdlLib_Rect *rect);
#define SdlLib_SDL_GetCursor()	SDL_GetCursor()
__EXTERN SdlLib_PCursor SDL_GetCursor(void);
#define SdlLib_SDL_GetError()	SDL_GetError()
__EXTERN SYSTEM_PTR SDL_GetError(void);
#define SdlLib_SDL_GetEventFilter()	SDL_GetEventFilter()
__EXTERN SdlLib_EventFilter SDL_GetEventFilter(void);
#define SdlLib_SDL_GetGammaRamp(redTable, greenTable, blueTable)	SDL_GetGammaRamp(redTable, greenTable, blueTable)
__EXTERN INTEGER SDL_GetGammaRamp(SdlLib_PUInt16 redTable, SdlLib_PUInt16 greenTable, SdlLib_PUInt16 blueTable);
#define SdlLib_SDL_GetKeyName(key)	SDL_GetKeyName(key)
__EXTERN SYSTEM_PTR SDL_GetKeyName(INTEGER key);
#define SdlLib_SDL_GetKeyRepeat(delay, interval)	SDL_GetKeyRepeat(delay, interval)
__EXTERN void SDL_GetKeyRepeat(INTEGER *delay, INTEGER *interval);
#define SdlLib_SDL_GetKeyState(numKeys)	SDL_GetKeyState(numKeys)
__EXTERN SdlLib_PUInt8 SDL_GetKeyState(INTEGER *numKeys);
#define SdlLib_SDL_GetModState()	SDL_GetModState()
__EXTERN SET SDL_GetModState(void);
#define SdlLib_SDL_GetMouseState(x, y)	SDL_GetMouseState(x, y)
__EXTERN CHAR SDL_GetMouseState(INTEGER *x, INTEGER *y);
#define SdlLib_SDL_GetRGB(pixel, fmt, r, g, b)	SDL_GetRGB(pixel, fmt, r, g, b)
__EXTERN void SDL_GetRGB(INTEGER pixel, SdlLib_PPixelFormat fmt, CHAR *r, CHAR *g, CHAR *b);
#define SdlLib_SDL_GetRGBA(pixel, fmt, r, g, b, a)	SDL_GetRGBA(pixel, fmt, r, g, b, a)
__EXTERN void SDL_GetRGBA(INTEGER pixel, SdlLib_PPixelFormat fmt, CHAR *r, CHAR *g, CHAR *b, CHAR *a);
#define SdlLib_SDL_GetRelativeMouseState(x, y)	SDL_GetRelativeMouseState(x, y)
__EXTERN CHAR SDL_GetRelativeMouseState(INTEGER *x, INTEGER *y);
#define SdlLib_SDL_GetTicks()	SDL_GetTicks()
__EXTERN INTEGER SDL_GetTicks(void);
#define SdlLib_SDL_GetVideoInfo()	SDL_GetVideoInfo()
__EXTERN SdlLib_PVideoInfo SDL_GetVideoInfo(void);
#define SdlLib_SDL_GetVideoSurface()	SDL_GetVideoSurface()
__EXTERN SdlLib_PSurface SDL_GetVideoSurface(void);
#define SdlLib_SDL_GetWMInfo(info)	SDL_GetWMInfo(info)
__EXTERN INTEGER SDL_GetWMInfo(SdlWin32_PSysWMinfo info);
#define SdlLib_SDL_Init(flags)	SDL_Init(flags)
__EXTERN INTEGER SDL_Init(SET flags);
#define SdlLib_SDL_InitSubSystem(flags)	SDL_InitSubSystem(flags)
__EXTERN INTEGER SDL_InitSubSystem(SET flags);
#define SdlLib_SDL_JoystickClose(joystick)	SDL_JoystickClose(joystick)
__EXTERN void SDL_JoystickClose(SdlLib_PJoystick joystick);
#define SdlLib_SDL_JoystickEventState(state)	SDL_JoystickEventState(state)
__EXTERN INTEGER SDL_JoystickEventState(INTEGER state);
#define SdlLib_SDL_JoystickGetAxis(joystick, axis)	SDL_JoystickGetAxis(joystick, axis)
__EXTERN SHORTINT SDL_JoystickGetAxis(SdlLib_PJoystick joystick, INTEGER axis);
#define SdlLib_SDL_JoystickGetBall(joystick, ball, dx, dy)	SDL_JoystickGetBall(joystick, ball, dx, dy)
__EXTERN INTEGER SDL_JoystickGetBall(SdlLib_PJoystick joystick, INTEGER ball, INTEGER *dx, INTEGER *dy);
#define SdlLib_SDL_JoystickGetButton(joystick, Button)	SDL_JoystickGetButton(joystick, Button)
__EXTERN CHAR SDL_JoystickGetButton(SdlLib_PJoystick joystick, INTEGER Button);
#define SdlLib_SDL_JoystickGetHat(joystick, hat)	SDL_JoystickGetHat(joystick, hat)
__EXTERN CHAR SDL_JoystickGetHat(SdlLib_PJoystick joystick, INTEGER hat);
#define SdlLib_SDL_JoystickIndex(joystick)	SDL_JoystickIndex(joystick)
__EXTERN INTEGER SDL_JoystickIndex(SdlLib_PJoystick joystick);
#define SdlLib_SDL_JoystickName(index)	SDL_JoystickName(index)
__EXTERN SYSTEM_PTR SDL_JoystickName(INTEGER index);
#define SdlLib_SDL_JoystickNumAxes(joystick)	SDL_JoystickNumAxes(joystick)
__EXTERN INTEGER SDL_JoystickNumAxes(SdlLib_PJoystick joystick);
#define SdlLib_SDL_JoystickNumBalls(joystick)	SDL_JoystickNumBalls(joystick)
__EXTERN INTEGER SDL_JoystickNumBalls(SdlLib_PJoystick joystick);
#define SdlLib_SDL_JoystickNumButtons(joystick)	SDL_JoystickNumButtons(joystick)
__EXTERN INTEGER SDL_JoystickNumButtons(SdlLib_PJoystick joystick);
#define SdlLib_SDL_JoystickNumHats(joystick)	SDL_JoystickNumHats(joystick)
__EXTERN INTEGER SDL_JoystickNumHats(SdlLib_PJoystick joystick);
#define SdlLib_SDL_JoystickOpen(index)	SDL_JoystickOpen(index)
__EXTERN SdlLib_PJoystick SDL_JoystickOpen(INTEGER index);
#define SdlLib_SDL_JoystickOpened(index)	SDL_JoystickOpened(index)
__EXTERN INTEGER SDL_JoystickOpened(INTEGER index);
#define SdlLib_SDL_JoystickUpdate()	SDL_JoystickUpdate()
__EXTERN void SDL_JoystickUpdate(void);
#define SdlLib_SDL_Linked_Version()	SDL_Linked_Version()
__EXTERN SdlLib_PVersion SDL_Linked_Version(void);
#define SdlLib_SDL_ListModes(format, flags)	SDL_ListModes(format, flags)
__EXTERN SdlLib_PPRect SDL_ListModes(SdlLib_PPixelFormat format, SET flags);
#define SdlLib_SDL_LoadBMP_RW(src, freeSrc)	SDL_LoadBMP_RW(src, freeSrc)
__EXTERN SdlLib_PSurface SDL_LoadBMP_RW(SdlLib_PRWops src, INTEGER freeSrc);
#define SdlLib_SDL_LoadFunction(handle, name, name__len)	SDL_LoadFunction(handle, name)
__EXTERN SYSTEM_PTR SDL_LoadFunction(SYSTEM_PTR handle, CHAR *name);
#define SdlLib_SDL_LoadObject(soFile, soFile__len)	SDL_LoadObject(soFile)
__EXTERN SYSTEM_PTR SDL_LoadObject(CHAR *soFile);
#define SdlLib_SDL_LoadWAV_RW(src, freeSrc, spec, audioBuf, audioLen)	SDL_LoadWAV_RW(src, freeSrc, spec, audioBuf, audioLen)
__EXTERN SdlLib_PAudioSpec SDL_LoadWAV_RW(SdlLib_PRWops src, INTEGER freeSrc, SdlLib_PAudioSpec spec, CHAR *audioBuf, INTEGER *audioLen);
#define SdlLib_SDL_LockAudio()	SDL_LockAudio()
__EXTERN void SDL_LockAudio(void);
#define SdlLib_SDL_LockSurface(surface)	SDL_LockSurface(surface)
__EXTERN INTEGER SDL_LockSurface(SdlLib_PSurface surface);
#define SdlLib_SDL_LockYUVOverlay(overlay)	SDL_LockYUVOverlay(overlay)
__EXTERN INTEGER SDL_LockYUVOverlay(SdlLib_POverlay overlay);
#define SdlLib_SDL_LowerBlit(src, srcRect, dst, dstRect)	SDL_LowerBlit(src, srcRect, dst, dstRect)
__EXTERN INTEGER SDL_LowerBlit(SdlLib_PSurface src, SdlLib_PRect srcRect, SdlLib_PSurface dst, SdlLib_PRect dstRect);
#define SdlLib_SDL_MapRGB(format, r, g, b)	SDL_MapRGB(format, r, g, b)
__EXTERN INTEGER SDL_MapRGB(SdlLib_PPixelFormat format, CHAR r, CHAR g, CHAR b);
#define SdlLib_SDL_MapRGBA(format, r, g, b, a)	SDL_MapRGBA(format, r, g, b, a)
__EXTERN INTEGER SDL_MapRGBA(SdlLib_PPixelFormat format, CHAR r, CHAR g, CHAR b, CHAR a);
#define SdlLib_SDL_MixAudio(dst, src, len, volume)	SDL_MixAudio(dst, src, len, volume)
__EXTERN void SDL_MixAudio(SdlLib_PUInt8 dst, SdlLib_PUInt8 src, INTEGER len, INTEGER volume);
#define SdlLib_SDL_NumJoysticks()	SDL_NumJoysticks()
__EXTERN INTEGER SDL_NumJoysticks(void);
#define SdlLib_SDL_OpenAudio(desired, obtained)	SDL_OpenAudio(desired, obtained)
__EXTERN INTEGER SDL_OpenAudio(SdlLib_PAudioSpec desired, SdlLib_PAudioSpec obtained);
#define SdlLib_SDL_OutOfMemory()	SDL_OutOfMemory()
__EXTERN void SDL_OutOfMemory(void);
#define SdlLib_SDL_PauseAudio(pauseOn)	SDL_PauseAudio(pauseOn)
__EXTERN void SDL_PauseAudio(INTEGER pauseOn);
#define SdlLib_SDL_PeepEvents(events, events__typ, numEvents, action, mask)	SDL_PeepEvents(events, numEvents, action, mask)
__EXTERN INTEGER SDL_PeepEvents(SdlLib_Event *events, INTEGER numEvents, INTEGER action, INTEGER mask);
#define SdlLib_SDL_PollEvent(event, event__typ)	SDL_PollEvent(event)
__EXTERN INTEGER SDL_PollEvent(SdlLib_Event *event);
#define SdlLib_SDL_PumpEvents()	SDL_PumpEvents()
__EXTERN void SDL_PumpEvents(void);
#define SdlLib_SDL_PushEvent(event, event__typ)	SDL_PushEvent(event)
__EXTERN INTEGER SDL_PushEvent(SdlLib_Event *event);
#define SdlLib_SDL_Quit()	SDL_Quit()
__EXTERN void SDL_Quit(void);
#define SdlLib_SDL_QuitSubSystem(flags)	SDL_QuitSubSystem(flags)
__EXTERN void SDL_QuitSubSystem(SET flags);
#define SdlLib_SDL_RWFromConstMem(mem, size)	SDL_RWFromConstMem(mem, size)
__EXTERN SdlLib_PRWops SDL_RWFromConstMem(SYSTEM_PTR mem, INTEGER size);
#define SdlLib_SDL_RWFromFP(fp, autoClose)	SDL_RWFromFP(fp, autoClose)
__EXTERN SdlLib_PRWops SDL_RWFromFP(SYSTEM_PTR fp, INTEGER autoClose);
#define SdlLib_SDL_RWFromFile(fileName, fileName__len, mode, mode__len)	SDL_RWFromFile(fileName, mode)
__EXTERN SdlLib_PRWops SDL_RWFromFile(CHAR *fileName, CHAR *mode);
#define SdlLib_SDL_RWFromMem(mem, size)	SDL_RWFromMem(mem, size)
__EXTERN SdlLib_PRWops SDL_RWFromMem(SYSTEM_PTR mem, INTEGER size);
#define SdlLib_SDL_RegisterApp(name, name__len, style, hInst)	SDL_RegisterApp(name, style, hInst)
__EXTERN INTEGER SDL_RegisterApp(CHAR *name, INTEGER style, SYSTEM_PTR hInst);
#define SdlLib_SDL_RemoveTimer(t)	SDL_RemoveTimer(t)
__EXTERN INTEGER SDL_RemoveTimer(SdlLib_PTimerID t);
#define SdlLib_SDL_SaveBMP_RW(surface, dst, freeDst)	SDL_SaveBMP_RW(surface, dst, freeDst)
__EXTERN INTEGER SDL_SaveBMP_RW(SdlLib_PSurface surface, SdlLib_PRWops dst, INTEGER freeDst);
#define SdlLib_SDL_SetAlpha(surface, flag, alpha)	SDL_SetAlpha(surface, flag, alpha)
__EXTERN INTEGER SDL_SetAlpha(SdlLib_PSurface surface, SET flag, CHAR alpha);
#define SdlLib_SDL_SetClipRect(surface, rect, rect__typ)	SDL_SetClipRect(surface, rect)
__EXTERN INTEGER SDL_SetClipRect(SdlLib_PSurface surface, SdlLib_Rect *rect);
#define SdlLib_SDL_SetColorKey(surface, flag, key)	SDL_SetColorKey(surface, flag, key)
__EXTERN INTEGER SDL_SetColorKey(SdlLib_PSurface surface, SET flag, INTEGER key);
#define SdlLib_SDL_SetColors(surface, colors, firstColor, nColors)	SDL_SetColors(surface, colors, firstColor, nColors)
__EXTERN INTEGER SDL_SetColors(SdlLib_PSurface surface, SdlLib_PColor colors, INTEGER firstColor, INTEGER nColors);
#define SdlLib_SDL_SetCursor(cursor)	SDL_SetCursor(cursor)
__EXTERN void SDL_SetCursor(SdlLib_PCursor cursor);
#define SdlLib_SDL_SetError(fmt, fmt__len)	SDL_SetError(fmt)
__EXTERN void SDL_SetError(CHAR *fmt);
#define SdlLib_SDL_SetEventFilter(filter)	SDL_SetEventFilter(filter)
__EXTERN void SDL_SetEventFilter(SdlLib_EventFilter filter);
#define SdlLib_SDL_SetGamma(redGamma, greenGamma, blueGamma)	SDL_SetGamma(redGamma, greenGamma, blueGamma)
__EXTERN INTEGER SDL_SetGamma(REAL redGamma, REAL greenGamma, REAL blueGamma);
#define SdlLib_SDL_SetGammaRamp(redTable, greenTable, blueTable)	SDL_SetGammaRamp(redTable, greenTable, blueTable)
__EXTERN INTEGER SDL_SetGammaRamp(SdlLib_PUInt16 redTable, SdlLib_PUInt16 greenTable, SdlLib_PUInt16 blueTable);
#define SdlLib_SDL_SetModState(modState)	SDL_SetModState(modState)
__EXTERN void SDL_SetModState(SET modState);
#define SdlLib_SDL_SetPalette(surface, flags, colors, firstColor, nColors)	SDL_SetPalette(surface, flags, colors, firstColor, nColors)
__EXTERN INTEGER SDL_SetPalette(SdlLib_PSurface surface, SET flags, SdlLib_PColor colors, INTEGER firstColor, INTEGER nColors);
#define SdlLib_SDL_SetTimer(interval, callback)	SDL_SetTimer(interval, callback)
__EXTERN INTEGER SDL_SetTimer(INTEGER interval, SdlLib_TimerCallback callback);
#define SdlLib_SDL_SetVideoMode(width, height, bpp, flags)	SDL_SetVideoMode(width, height, bpp, flags)
__EXTERN SdlLib_PSurface SDL_SetVideoMode(INTEGER width, INTEGER height, INTEGER bpp, SET flags);
#define SdlLib_SDL_ShowCursor(toggle)	SDL_ShowCursor(toggle)
__EXTERN INTEGER SDL_ShowCursor(INTEGER toggle);
#define SdlLib_SDL_SoftStretch(src, srcRect, dst, dstRect)	SDL_SoftStretch(src, srcRect, dst, dstRect)
__EXTERN INTEGER SDL_SoftStretch(SdlLib_PSurface src, SdlLib_PRect srcRect, SdlLib_PSurface dst, SdlLib_PRect dstRect);
#define SdlLib_SDL_TableSize(table, table__len)	SDL_TableSize(table)
__EXTERN INTEGER SDL_TableSize(CHAR *table);
#define SdlLib_SDL_UnloadObject(handle)	SDL_UnloadObject(handle)
__EXTERN void SDL_UnloadObject(SYSTEM_PTR handle);
#define SdlLib_SDL_UnlockAudio()	SDL_UnlockAudio()
__EXTERN void SDL_UnlockAudio(void);
#define SdlLib_SDL_UnlockSurface(surface)	SDL_UnlockSurface(surface)
__EXTERN void SDL_UnlockSurface(SdlLib_PSurface surface);
#define SdlLib_SDL_UnlockYUVOverlay(overlay)	SDL_UnlockYUVOverlay(overlay)
__EXTERN void SDL_UnlockYUVOverlay(SdlLib_POverlay overlay);
#define SdlLib_SDL_UpdateRect(screen, x, y, w, h)	SDL_UpdateRect(screen, x, y, w, h)
__EXTERN void SDL_UpdateRect(SdlLib_PSurface screen, INTEGER x, INTEGER y, INTEGER w, INTEGER h);
#define SdlLib_SDL_UpdateRects(screen, numRects, rects)	SDL_UpdateRects(screen, numRects, rects)
__EXTERN void SDL_UpdateRects(SdlLib_PSurface screen, INTEGER numRects, SdlLib_PRect rects);
#define SdlLib_SDL_UpperBlit(src, srcRect, dst, dstRect)	SDL_UpperBlit(src, srcRect, dst, dstRect)
__EXTERN INTEGER SDL_UpperBlit(SdlLib_PSurface src, SdlLib_PRect srcRect, SdlLib_PSurface dst, SdlLib_PRect dstRect);
#define SdlLib_SDL_VideoDriverName(nameBuf, nameBuf__len, maxLen)	SDL_VideoDriverName(nameBuf, maxLen)
__EXTERN SYSTEM_PTR SDL_VideoDriverName(CHAR *nameBuf, INTEGER maxLen);
#define SdlLib_SDL_VideoInit(driverName, driverName__len, flags)	SDL_VideoInit(driverName, flags)
__EXTERN INTEGER SDL_VideoInit(CHAR *driverName, SET flags);
#define SdlLib_SDL_VideoModeOK(width, height, bpp, flags)	SDL_VideoModeOK(width, height, bpp, flags)
__EXTERN INTEGER SDL_VideoModeOK(INTEGER width, INTEGER height, INTEGER bpp, SET flags);
#define SdlLib_SDL_VideoQuit()	SDL_VideoQuit()
__EXTERN void SDL_VideoQuit(void);
#define SdlLib_SDL_WM_GetCaption(title, title__len, icon, icon__len)	SDL_WM_GetCaption(title, icon)
__EXTERN void SDL_WM_GetCaption(CHAR *title, CHAR *icon);
#define SdlLib_SDL_WM_GrabInput(mode)	SDL_WM_GrabInput(mode)
__EXTERN INTEGER SDL_WM_GrabInput(INTEGER mode);
#define SdlLib_SDL_WM_IconifyWindow()	SDL_WM_IconifyWindow()
__EXTERN INTEGER SDL_WM_IconifyWindow(void);
#define SdlLib_SDL_WM_SetCaption(title, title__len, icon, icon__len)	SDL_WM_SetCaption(title, icon)
__EXTERN void SDL_WM_SetCaption(CHAR *title, CHAR *icon);
#define SdlLib_SDL_WM_SetIcon(icon, mask)	SDL_WM_SetIcon(icon, mask)
__EXTERN void SDL_WM_SetIcon(SdlLib_PSurface icon, CHAR mask);
#define SdlLib_SDL_WM_ToggleFullScreen(surface)	SDL_WM_ToggleFullScreen(surface)
__EXTERN INTEGER SDL_WM_ToggleFullScreen(SdlLib_PSurface surface);
#define SdlLib_SDL_WaitEvent(event, event__typ)	SDL_WaitEvent(event)
__EXTERN INTEGER SDL_WaitEvent(SdlLib_Event *event);
#define SdlLib_SDL_WarpMouse(x, y)	SDL_WarpMouse(x, y)
__EXTERN void SDL_WarpMouse(SHORTINT x, SHORTINT y);
#define SdlLib_SDL_WasInit(flags)	SDL_WasInit(flags)
__EXTERN SET SDL_WasInit(SET flags);
#define SdlLib_SaveBMP_RW(surface, dst, freeDst)	SDL_SaveBMP_RW(surface, dst, freeDst)
#define SdlLib_SetAlpha(surface, flag, alpha)	SDL_SetAlpha(surface, flag, alpha)
#define SdlLib_SetClipRect(surface, rect, rect__typ)	SDL_SetClipRect(surface, rect)
#define SdlLib_SetColorKey(surface, flag, key)	SDL_SetColorKey(surface, flag, key)
#define SdlLib_SetColors(surface, colors, firstColor, nColors)	SDL_SetColors(surface, colors, firstColor, nColors)
#define SdlLib_SetCursor(cursor)	SDL_SetCursor(cursor)
#define SdlLib_SetError(fmt, fmt__len)	SDL_SetError(fmt)
#define SdlLib_SetEventFilter(filter)	SDL_SetEventFilter(filter)
#define SdlLib_SetGamma(redGamma, greenGamma, blueGamma)	SDL_SetGamma(redGamma, greenGamma, blueGamma)
#define SdlLib_SetGammaRamp(redTable, greenTable, blueTable)	SDL_SetGammaRamp(redTable, greenTable, blueTable)
#define SdlLib_SetModState(modState)	SDL_SetModState(modState)
#define SdlLib_SetPalette(surface, flags, colors, firstColor, nColors)	SDL_SetPalette(surface, flags, colors, firstColor, nColors)
#define SdlLib_SetTimer(interval, callback)	SDL_SetTimer(interval, callback)
#define SdlLib_SetVideoMode(width, height, bpp, flags)	SDL_SetVideoMode(width, height, bpp, flags)
#define SdlLib_ShowCursor(toggle)	SDL_ShowCursor(toggle)
#define SdlLib_SoftStretch(src, srcRect, dst, dstRect)	SDL_SoftStretch(src, srcRect, dst, dstRect)
#define SdlLib_TableSize(table, table__len)	SDL_TableSize(table)
#define SdlLib_UnloadObject(handle)	SDL_UnloadObject(handle)
#define SdlLib_UnlockAudio()	SDL_UnlockAudio()
#define SdlLib_UnlockSurface(surface)	SDL_UnlockSurface(surface)
#define SdlLib_UnlockYUVOverlay(overlay)	SDL_UnlockYUVOverlay(overlay)
#define SdlLib_UpdateRect(screen, x, y, w, h)	SDL_UpdateRect(screen, x, y, w, h)
#define SdlLib_UpdateRects(screen, numRects, rects)	SDL_UpdateRects(screen, numRects, rects)
#define SdlLib_UpperBlit(src, srcRect, dst, dstRect)	SDL_UpperBlit(src, srcRect, dst, dstRect)
#define SdlLib_VideoDriverName(nameBuf, nameBuf__len, maxLen)	SDL_VideoDriverName(nameBuf, maxLen)
#define SdlLib_VideoInit(driverName, driverName__len, flags)	SDL_VideoInit(driverName, flags)
#define SdlLib_VideoModeOK(width, height, bpp, flags)	SDL_VideoModeOK(width, height, bpp, flags)
#define SdlLib_VideoQuit()	SDL_VideoQuit()
#define SdlLib_WM_GetCaption(title, title__len, icon, icon__len)	SDL_WM_GetCaption(title, icon)
#define SdlLib_WM_GrabInput(mode)	SDL_WM_GrabInput(mode)
#define SdlLib_WM_IconifyWindow()	SDL_WM_IconifyWindow()
#define SdlLib_WM_SetCaption(title, title__len, icon, icon__len)	SDL_WM_SetCaption(title, icon)
#define SdlLib_WM_SetIcon(icon, mask)	SDL_WM_SetIcon(icon, mask)
#define SdlLib_WM_ToggleFullScreen(surface)	SDL_WM_ToggleFullScreen(surface)
#define SdlLib_WaitEvent(event, event__typ)	SDL_WaitEvent(event)
#define SdlLib_WarpMouse(x, y)	SDL_WarpMouse(x, y)
#define SdlLib_WasInit(flags)	SDL_WasInit(flags)
#define SdlLib__init()	/*-noinit*/

#endif
