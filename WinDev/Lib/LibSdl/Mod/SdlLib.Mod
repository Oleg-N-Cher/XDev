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

  (* The keyboard syms have been cleverly chosen to map to ASCII *)
  K_UNKNOWN* = 0;
  K_FIRST* = 0;
  K_BACKSPACE* = 8;
  K_TAB* = 9;
  K_CLEAR* = 12;
  K_RETURN* = 13;
  K_PAUSE* = 19;
  K_ESCAPE* = 27;
  K_SPACE* = 32;
  K_EXCLAIM* = 33;
  K_QUOTEDBL* = 34;
  K_HASH* = 35;
  K_DOLLAR* = 36;
  K_AMPERSAND* = 38;
  K_QUOTE* = 39;
  K_LEFTPAREN* = 40;
  K_RIGHTPAREN* = 41;
  K_ASTERISK* = 42;
  K_PLUS* = 43;
  K_COMMA* = 44;
  K_MINUS* = 45;
  K_PERIOD* = 46;
  K_SLASH* = 47;
  K_0* = 48;
  K_1* = 49;
  K_2* = 50;
  K_3* = 51;
  K_4* = 52;
  K_5* = 53;
  K_6* = 54;
  K_7* = 55;
  K_8* = 56;
  K_9* = 57;
  K_COLON* = 58;
  K_SEMICOLON* = 59;
  K_LESS* = 60;
  K_EQUALS* = 61;
  K_GREATER* = 62;
  K_QUESTION* = 63;
  K_AT* = 64;

  (* Skip uppercase letters *)

  K_LEFTBRACKET* = 91;
  K_BACKSLASH* = 92;
  K_RIGHTBRACKET* = 93;
  K_CARET* = 94;
  K_UNDERSCORE* = 95;
  K_BACKQUOTE* = 96;
  K_a* = 97;
  K_b* = 98;
  K_c* = 99;
  K_d* = 100;
  K_e* = 101;
  K_f* = 102;
  K_g* = 103;
  K_h* = 104;
  K_i* = 105;
  K_j* = 106;
  K_k* = 107;
  K_l* = 108;
  K_m* = 109;
  K_n* = 110;
  K_o* = 111;
  K_p* = 112;
  K_q* = 113;
  K_r* = 114;
  K_s* = 115;
  K_t* = 116;
  K_u* = 117;
  K_v* = 118;
  K_w* = 119;
  K_x* = 120;
  K_y* = 121;
  K_z* = 122;
  K_DELETE* = 127;
  (* End of ASCII mapped keysyms *)

  (* International keyboard syms *)
  K_WORLD_0* = 160; (* 0xA0 *)
  K_WORLD_1* = 161;
  K_WORLD_2* = 162;
  K_WORLD_3* = 163;
  K_WORLD_4* = 164;
  K_WORLD_5* = 165;
  K_WORLD_6* = 166;
  K_WORLD_7* = 167;
  K_WORLD_8* = 168;
  K_WORLD_9* = 169;
  K_WORLD_10* = 170;
  K_WORLD_11* = 171;
  K_WORLD_12* = 172;
  K_WORLD_13* = 173;
  K_WORLD_14* = 174;
  K_WORLD_15* = 175;
  K_WORLD_16* = 176;
  K_WORLD_17* = 177;
  K_WORLD_18* = 178;
  K_WORLD_19* = 179;
  K_WORLD_20* = 180;
  K_WORLD_21* = 181;
  K_WORLD_22* = 182;
  K_WORLD_23* = 183;
  K_WORLD_24* = 184;
  K_WORLD_25* = 185;
  K_WORLD_26* = 186;
  K_WORLD_27* = 187;
  K_WORLD_28* = 188;
  K_WORLD_29* = 189;
  K_WORLD_30* = 190;
  K_WORLD_31* = 191;
  K_WORLD_32* = 192;
  K_WORLD_33* = 193;
  K_WORLD_34* = 194;
  K_WORLD_35* = 195;
  K_WORLD_36* = 196;
  K_WORLD_37* = 197;
  K_WORLD_38* = 198;
  K_WORLD_39* = 199;
  K_WORLD_40* = 200;
  K_WORLD_41* = 201;
  K_WORLD_42* = 202;
  K_WORLD_43* = 203;
  K_WORLD_44* = 204;
  K_WORLD_45* = 205;
  K_WORLD_46* = 206;
  K_WORLD_47* = 207;
  K_WORLD_48* = 208;
  K_WORLD_49* = 209;
  K_WORLD_50* = 210;
  K_WORLD_51* = 211;
  K_WORLD_52* = 212;
  K_WORLD_53* = 213;
  K_WORLD_54* = 214;
  K_WORLD_55* = 215;
  K_WORLD_56* = 216;
  K_WORLD_57* = 217;
  K_WORLD_58* = 218;
  K_WORLD_59* = 219;
  K_WORLD_60* = 220;
  K_WORLD_61* = 221;
  K_WORLD_62* = 222;
  K_WORLD_63* = 223;
  K_WORLD_64* = 224;
  K_WORLD_65* = 225;
  K_WORLD_66* = 226;
  K_WORLD_67* = 227;
  K_WORLD_68* = 228;
  K_WORLD_69* = 229;
  K_WORLD_70* = 230;
  K_WORLD_71* = 231;
  K_WORLD_72* = 232;
  K_WORLD_73* = 233;
  K_WORLD_74* = 234;
  K_WORLD_75* = 235;
  K_WORLD_76* = 236;
  K_WORLD_77* = 237;
  K_WORLD_78* = 238;
  K_WORLD_79* = 239;
  K_WORLD_80* = 240;
  K_WORLD_81* = 241;
  K_WORLD_82* = 242;
  K_WORLD_83* = 243;
  K_WORLD_84* = 244;
  K_WORLD_85* = 245;
  K_WORLD_86* = 246;
  K_WORLD_87* = 247;
  K_WORLD_88* = 248;
  K_WORLD_89* = 249;
  K_WORLD_90* = 250;
  K_WORLD_91* = 251;
  K_WORLD_92* = 252;
  K_WORLD_93* = 253;
  K_WORLD_94* = 254;
  K_WORLD_95* = 255; (* 0xFF *)

  (* Numeric keypad *)
  K_KP0* = 256;
  K_KP1* = 257;
  K_KP2* = 258;
  K_KP3* = 259;
  K_KP4* = 260;
  K_KP5* = 261;
  K_KP6* = 262;
  K_KP7* = 263;
  K_KP8* = 264;
  K_KP9* = 265;
  K_KP_PERIOD* = 266;
  K_KP_DIVIDE* = 267;
  K_KP_MULTIPLY* = 268;
  K_KP_MINUS* = 269;
  K_KP_PLUS* = 270;
  K_KP_ENTER* = 271;
  K_KP_EQUALS* = 272;

  (* Arrows + Home/End pad *)
  K_UP* = 273;
  K_DOWN* = 274;
  K_RIGHT* = 275;
  K_LEFT* = 276;
  K_INSERT* = 277;
  K_HOME* = 278;
  K_END* = 279;
  K_PAGEUP* = 280;
  K_PAGEDOWN* = 281;

  (* Function keys *)
  K_F1* = 282;
  K_F2* = 283;
  K_F3* = 284;
  K_F4* = 285;
  K_F5* = 286;
  K_F6* = 287;
  K_F7* = 288;
  K_F8* = 289;
  K_F9* = 290;
  K_F10* = 291;
  K_F11* = 292;
  K_F12* = 293;
  K_F13* = 294;
  K_F14* = 295;
  K_F15* = 296;

  (* Key state modifier keys *)
  K_NUMLOCK* = 300;
  K_CAPSLOCK* = 301;
  K_SCROLLOCK* = 302;
  K_RSHIFT* = 303;
  K_LSHIFT* = 304;
  K_RCTRL* = 305;
  K_LCTRL* = 306;
  K_RALT* = 307;
  K_LALT* = 308;
  K_RMETA* = 309;
  K_LMETA* = 310;
  K_LSUPER* = 311; (* Left "Windows" key *)
  K_RSUPER* = 312; (* Right "Windows" key *)
  K_MODE* = 313; (* "Alt Gr" key *)
  K_COMPOSE* = 314; (* Multi-key compose key *)

  (* Miscellaneous procedure keys *)
  K_HELP* = 315;
  K_PRINT* = 316;
  K_SYSREQ* = 317;
  K_BREAK* = 318;
  K_MENU* = 319;
  K_POWER* = 320; (* Power Macintosh power key *)
  K_EURO* = 321; (* Some european keyboards *)

  (* Enumeration of valid key mods (possibly OR'd together) *)
	KMOD_NONE* = {};
	KMOD_LSHIFT* = {0};
	KMOD_RSHIFT* = {1};
	KMOD_LCTRL* = {6};
	KMOD_RCTRL* = {7};
	KMOD_LALT* = {8};
	KMOD_RALT* = {9};
	KMOD_LMETA* = {10};
	KMOD_RMETA* = {11};
	KMOD_NUM* = {12};
	KMOD_CAPS* = {13};
	KMOD_MODE* = {14};
	KMOD_RESERVED* = {15};

  KMOD_CTRL* = (KMOD_LCTRL + KMOD_RCTRL);
  KMOD_SHIFT* = (KMOD_LSHIFT + KMOD_RSHIFT);
  KMOD_ALT* = (KMOD_LALT + KMOD_RALT);
  KMOD_META* = (KMOD_LMETA + KMOD_RMETA);

TYPE
  (* Delphi types *)
  Byte*     = SYSTEM.BYTE;
  Cardinal* = INTEGER;
  Char*     = CHAR;
  Integer*  = INTEGER;
  LongWord* = Cardinal;
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

  (* SDL_keyboard.h types *)
  Key = LongWord;
  Mod = SET;

  KeySym* = RECORD [1]
    scancode-: UInt8; (* hardware specific scancode *)
    sym-: Key; (* SDL virtual keysym *)
    modifier-: Mod; (* current key modifiers *)
    unicode-: UInt16; (* translated character *)
  END;

  (* General event structure *)
  PEvent* = POINTER [1] TO Event;
  Event* = RECORD [1]
    type-: SInt8;
    dummy: ARRAY [1] 32 OF CHAR; (* BB shows: SIZE(Sdl.Event) = 20 *)
  END;

  (* Keyboard event structure *)
  KeyboardEvent* = RECORD [1]
    type-: SInt8;  (* SDL_KEYDOWN or SDL_KEYUP *)
    which-: UInt8; (* The keyboard device index *)
    state-: UInt8; (* SDL_PRESSED or SDL_RELEASED *)
    keysym-: KeySym;
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
PROCEDURE -sdlPollEvent (VAR event: Event): Integer
  "SDL_PollEvent((SDL_Event*)event)";
PROCEDURE -sdlWaitEvent (VAR event: Event): Integer
  "SDL_WaitEvent((SDL_Event*)event)";
PROCEDURE -sdlPumpEvents "SDL_PumpEvents()";
PROCEDURE -sdlGetTicks (): UInt32 "SDL_GetTicks()";
PROCEDURE -sdlEnableUNICODE (enable: Integer): Integer
  "SDL_EnableUNICODE(enable)";
PROCEDURE -sdlEnableKeyRepeat (delay, interval: Integer): Integer
  "SDL_EnableKeyRepeat(delay, interval)";

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
   there was an error while waiting for events.  If 'event' is not NULL,
   the next event is removed from the queue and stored in that area. *)

(*------------------------------------------------------------------------*)
(*                             Event handling                             *)
(*------------------------------------------------------------------------*)

(* Pumps the event loop, gathering events from the input devices.
   This procedure updates the event queue and internal input device state.
   This should only be run in the thread that sets the video mode. *)

PROCEDURE PumpEvents* ; BEGIN sdlPumpEvents END PumpEvents;

(* Polls for currently pending events, and returns 1 if there are any pending
   events, or 0 if there are none available.  If 'event' is not NULL, the next
   event is removed from the queue and stored in that area. *)

PROCEDURE PollEvent* (VAR event: Event): Integer;
  BEGIN RETURN sdlPollEvent(event) END PollEvent;

(* Waits indefinitely for the next available event, returning 1, or 0 if there
   was an error while waiting for events.  If 'event' is not NULL, the next
   event is removed from the queue and stored in that area. *)

PROCEDURE WaitEvent* (VAR event: Event): Integer;
  BEGIN RETURN sdlWaitEvent(event) END WaitEvent;

(*----------------------------------------------------------------------------*)
(*                              Keyboard routines                             *)
(*----------------------------------------------------------------------------*)

(* Enable/Disable UNICODE translation of keyboard input.
   This translation has some overhead, so translation defaults off.
   If 'enable' is î , translation is enabled.
   If 'enable' is 0, translation is disabled.
   If 'enable' is -1, the translation state is not changed.
   It returns the previous state of keyboard translation. *)
PROCEDURE EnableUNICODE* (enable: Integer): Integer;
  BEGIN RETURN sdlEnableUNICODE(enable) END EnableUNICODE;

(* If 'delay' is set to 0, keyboard repeat is disabled. *)
PROCEDURE EnableKeyRepeat* (delay, interval: Integer): Integer;
  BEGIN RETURN sdlEnableKeyRepeat(delay, interval) END EnableKeyRepeat;

END SdlLib.