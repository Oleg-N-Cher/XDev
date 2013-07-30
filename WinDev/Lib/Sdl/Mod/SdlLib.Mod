MODULE SdlLib; (** non-portable *)

IMPORT SYSTEM;

CONST
  (* These are the currently supported flags for the SDL_surface *)
  (* Available for SDL_CreateRGBSurface() or SDL_SetVideoMode() *)
  SWSURFACE* = {}; (* Surface is in system memory *)
  HWSURFACE* = {0}; (* Surface is in video memory *)
  ASYNCBLIT* = {2}; (* Use asynchronous blits if possible *)
  (* Available for SDL_SetVideoMode() *)
  ANYFORMAT* = {28}; (* Allow any video depth/pixel-format *)
  HWPALETTE* = {29}; (* Surface has exclusive palette *)
  DOUBLEBUF* = {30}; (* Set up double-buffered video mode *)
  FULLSCREEN* = {31}; (* Surface is a full screen display *)
  OPENGL* = {1}; (* Create an OpenGL rendering context *)
  OPENGLBLIT* = {1}; (* Create an OpenGL rendering context *)
  RESIZABLE* = {4}; (* This video mode may be resized *)
  NOFRAME* = {5}; (* No window caption or edge frame *)
  (* Used internally (read-only) *)
  HWACCEL* = {8}; (* Blit uses hardware acceleration *)
  SRCCOLORKEY* = {12}; (* Blit uses a source color key *)
  RLEACCELOK* = {13}; (* Private flag *)
  RLEACCEL* = {14}; (* Colorkey blit is RLE accelerated *)
  SRCALPHA* = {16}; (* Blit uses source alpha blending *)
  SRCCLIPPING* = {20}; (* Blit uses source clipping *)
  PREALLOC* = {24}; (* Surface uses preallocated memory *)

  (* SDL.h constants *)
  INIT_TIMER* = {0};
  INIT_AUDIO* = {4};
  INIT_VIDEO* = {5};
  INIT_CDROM* = {8};
  INIT_JOYSTICK* = {9};
  INIT_NOPARACHUTE* = {20}; (* Don't catch fatal signals *)
  INIT_EVENTTHREAD* = {24}; (* Not supported on all OS's *)
  INIT_EVERYTHING* = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	(* SDL_events.h constants *)
	NOEVENT* = 0X; (* Unused (do not remove) *)
	ACTIVEEVENT* = 1X; (* Application loses/gains visibility *)
	KEYDOWN* = 2X; (* Keys pressed *)
	KEYUP* = 3X; (* Keys released *)
	MOUSEMOTION* = 4X; (* Mouse moved *)
	MOUSEBUTTONDOWN* = 5X; (* Mouse button pressed *)
	MOUSEBUTTONUP* = 6X; (* Mouse button released *)
	JOYAXISMOTION* = 7X; (* Joystick axis motion *)
	JOYBALLMOTION* = 8X; (* Joystick trackball motion *)
	JOYHATMOTION* = 9X; (* Joystick hat position change *)
	JOYBUTTONDOWN* = CHR(10); (* Joystick button pressed *)
	JOYBUTTONUP* = CHR(11); (* Joystick button released *)
	QUIT* = CHR(12); (* User-requested quit (Changed due to procedure conflict) *)
	QUITEV* = CHR(12);
	SYSWMEVENT* = CHR(13); (* System specific event *)
	EVENT_RESERVEDA* = CHR(14); (* Reserved for future use.. *)
	EVENT_RESERVED* = CHR(15); (* Reserved for future use.. *)
	VIDEORESIZE* = CHR(16); (* User resized video mode *)
	VIDEOEXPOSE* = CHR(17); (* Screen needs to be redrawn *)
	EVENT_RESERVED2* = CHR(18); (* Reserved for future use.. *)
	EVENT_RESERVED3* = CHR(19); (* Reserved for future use.. *)
	EVENT_RESERVED4* = CHR(20); (* Reserved for future use.. *)
	EVENT_RESERVED5* = CHR(21); (* Reserved for future use.. *)
	EVENT_RESERVED6* = CHR(22); (* Reserved for future use.. *)
	EVENT_RESERVED7* = CHR(23); (* Reserved for future use.. *)
	(* Events Sdl.USEREVENT through Sdl.MAXEVENTS-1 are for your use *)
	USEREVENT* = CHR(24);

TYPE
  (* Delphi types *)
  Byte*     = SYSTEM.BYTE;
  Cardinal* = INTEGER;
  Char*     = CHAR;
  Integer*  = INTEGER;
  PChar*    = POINTER [1] TO ARRAY [1] OF Char;
  Pointer*  = POINTER [1] TO ARRAY [1] OF Byte;
  SInt8*    = SYSTEM.BYTE;
  SInt16*   = SHORTINT;
  SInt32*   = Integer;
  UInt8*    = SYSTEM.BYTE;
  UInt16*   = SHORTINT;
  UInt32*   = INTEGER;

  (* SDL_video.h types *)
  (* Useful data types *)
  PRect* = POINTER [1] TO Rect;
  Rect* = RECORD [1]
    x*, y*: SInt16;
    w*, h*: UInt16;
  END;
  PPRect* = POINTER [1] TO ARRAY [1] OF PRect;

  PColor* = POINTER [1] TO Color;
  Color* = RECORD [1]
    r*: UInt8;
    g*: UInt8;
    b*: UInt8;
    unused*: UInt8;
  END;

  PColorArray* = POINTER [1] TO ColorArray;
  ColorArray* = ARRAY [1] 65000+1 OF Color;

  PPalette* = POINTER [1] TO Palette;
  Palette* = RECORD [1]
    ncolors*: Integer;
    colors*: PColorArray;
  END;

  (* Everything in the pixel format structure is read-only *)
  PPixelFormat* = POINTER [1] TO PixelFormat;
  PixelFormat* = RECORD [1]
    palette-: PPalette;
    BitsPerPixel-: Byte;
    BytesPerPixel-: Byte;
    Rloss-: UInt8;
    Gloss-: UInt8;
    Bloss-: UInt8;
    Aloss-: UInt8;
    Rshift-: UInt8;
    Gshift-: UInt8;
    Bshift-: UInt8;
    Ashift-: UInt8;
    Rmask-: UInt32;
    Gmask-: UInt32;
    Bmask-: UInt32;
    Amask-: UInt32;
    colorkey-: UInt32; (* RGB color key information *)
    alpha-: UInt8; (* Alpha value information (per-surface alpha) *)
  END;

  (* typedef for private surface blitting functions *)
  PSurface* = POINTER [1] TO Surface;

  Surface* = RECORD [1]
    flags-: SET; (* Read-only *)
    format-: PPixelFormat; (* Read-only *)
    w-, h-: Integer; (* Read-only *)
    pitch-: UInt16; (* Read-only *)
    pixels*: Pointer; (* Read-write *)
    offset-: Integer; (* Private *)
    hwdata-: Pointer; (* TPrivate_hwdata; Hardware-specific surface info *)

    (* clipping information: *)
    clip_rect-: Rect; (* Read-only *)
    unused1: UInt32; (* for binary compatibility *)
    (* Allow recursive locks *)
    locked-: UInt32; (* Private *)
    (* info for fast blit mapping to other surfaces *)
    map-: Pointer; (* Sdl.PBlitMap; Private *)
    (* format version, bumped at every change to invalidate blit maps *)
    format_version-: Cardinal; (* Private *)
    refcount-: Integer;
  END;

  (* General event structure *)
  PEvent* = POINTER [1] TO Event;
  Event* = RECORD [1]
    type-: SInt8;
    dummy: ARRAY [1] 32 OF CHAR; (* BB shows: SIZE(Sdl.Event) = 20 *)
  END;

PROCEDURE -includesdl()  "#include <SDL.h>";

PROCEDURE -sdlDelay (msec: Integer)  "SDL_Delay(msec)";
PROCEDURE -sdlInit (flags: SET): Integer  "SDL_Init(flags)";
PROCEDURE -sdlQuit  "SDL_Quit()";
PROCEDURE -sdlWM_SetCaption (title, icon: PChar)
  "SDL_WM_SetCaption((char*)title, (char*)icon)";
PROCEDURE -sdlSetVideoMode (width, height, bpp: Integer; flags: SET):
  PSurface  "((SdlLib_PSurface)SDL_SetVideoMode(width, height, bpp, flags))";
PROCEDURE -sdlLockSurface (surface: PSurface): Integer
  "SDL_LockSurface((SDL_Surface*)surface)";
PROCEDURE -sdlUnlockSurface (surface: PSurface)
  "SDL_UnlockSurface((SDL_Surface*)surface)";
PROCEDURE -sdlMustLock (surface: PSurface): Integer
  "SDL_MUSTLOCK(surface)";
PROCEDURE -sdlUpdateRect (screen: PSurface; x, y: SInt32; w, h: UInt32)
  "SDL_UpdateRect((SDL_Surface*)screen, x, y, w, h)";
PROCEDURE -sdlMapRGB* (format: PPixelFormat; r, g, b: UInt8): UInt32
  "SDL_MapRGB((SDL_PixelFormat*)format, r, g, b)";
PROCEDURE -sdlFlip (screen: PSurface): Integer
  "SDL_Flip((SDL_Surface*)screen)";
PROCEDURE -sdlWaitEvent (VAR event: Event): Integer
  "SDL_WaitEvent((SDL_Event*)event)";
PROCEDURE -sdlPumpEvents "SDL_PumpEvents()";
PROCEDURE -sdlGetTicks (): UInt32 "SDL_GetTicks()";

PROCEDURE Init* (flags: SET): Integer; BEGIN
  RETURN sdlInit(flags) END Init;

PROCEDURE Quit* ; BEGIN sdlQuit END Quit;

PROCEDURE WM_SetCaption* (title, icon: PChar); BEGIN
  sdlWM_SetCaption(title, icon); END WM_SetCaption;

PROCEDURE SetVideoMode* (width, height, bpp: Integer; flags: SET): PSurface;
  BEGIN RETURN sdlSetVideoMode(width, height, bpp, flags) END SetVideoMode;

(* SDL_LockSurface() sets up a surface for directly accessing the pixels.
   Between calls to SDL_LockSurface()/SDL_UnlockSurface(), you can write
   to and read from 'surface->pixels', using the pixel format stored in
   'surface->format'.  Once you are done accessing the surface, you should
   use SDL_UnlockSurface() to release it.

   Not all surfaces require locking.  If SDL_MUSTLOCK(surface) evaluates
   to 0, then you can read and write to the surface at any time, and the
   pixel format of the surface will not change.  In particular, if the
   SDL_HWSURFACE flag is not given when calling SDL_SetVideoMode(), you
   will not need to lock the display surface before accessing it.

   No operating system or library calls should be made between lock/unlock
   pairs, as critical system locks may be held during this time.

   SDL_LockSurface() returns 0, or -1 if the surface couldn't be locked. *)

PROCEDURE LockSurface* (surface: PSurface): BOOLEAN;
  BEGIN RETURN sdlLockSurface(surface) = 0 END LockSurface;

PROCEDURE UnlockSurface* (surface: PSurface);
  BEGIN sdlUnlockSurface(surface) END UnlockSurface;

PROCEDURE MustLock* (surface: PSurface): BOOLEAN;
  BEGIN RETURN sdlMustLock(surface) # 0 END MustLock;

PROCEDURE UpdateRect* (screen: PSurface; x, y: SInt32; w, h: UInt32);
  BEGIN sdlUpdateRect(screen, x, y, w, h) END UpdateRect;

PROCEDURE MapRGB* (format: PPixelFormat; r, g, b: UInt8): UInt32;
  BEGIN RETURN sdlMapRGB(format, r, g, b) END MapRGB;

(* On hardware that supports double-buffering, this procedure sets up a flip
   and returns.  The hardware will wait for vertical retrace, and then swap
   video buffers before the next video surface blit or lock will return.
   On hardware that doesn not support double-buffering, this is equivalent
   to calling SDL_UpdateRect(screen, 0, 0, 0, 0);
   The SDL_DOUBLEBUF flag must have been passed to SDL_SetVideoMode() when
   setting the video mode for this procedure to perform hardware flipping.
   This procedure returns 0 if successful, or -1 if there was an error. *)
  
PROCEDURE Flip* (screen: PSurface): BOOLEAN;
  BEGIN RETURN sdlFlip(screen) = 0 END Flip;

(*------------------------------------------------------------------------*)
(*                            Time handling                               *)
(*------------------------------------------------------------------------*)

(* Wait a specified number of milliseconds before returning *)
PROCEDURE Delay* (msec: Integer); BEGIN sdlDelay(msec) END Delay;

(* Get the number of milliseconds since the SDL library initialization. *)
(* Note that this value wraps if the program runs for more than ~49 days. *)
PROCEDURE GetTicks* (): UInt32; BEGIN RETURN sdlGetTicks() END GetTicks;

(* Waits indefinitely for the next available event, returning 1, or 0 if
   there was an error while waiting for events.	If 'event' is not NULL,
   the next event is removed from the queue and stored in that area. *)

(*------------------------------------------------------------------------*)
(*														 Event handling 														*)
(*------------------------------------------------------------------------*)

(* Pumps the event loop, gathering events from the input devices.
	 This procedure updates the event queue and internal input device state.
	 This should only be run in the thread that sets the video mode. *)

PROCEDURE PumpEvents* ; BEGIN sdlPumpEvents END PumpEvents;

PROCEDURE WaitEvent* (VAR event: Event): Integer;
  BEGIN RETURN sdlWaitEvent(event) END WaitEvent;

END SdlLib.