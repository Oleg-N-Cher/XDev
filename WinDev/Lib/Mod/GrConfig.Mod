MODULE GrConfig;
IMPORT SYSTEM;

CONST
  AutoDetect = 0; (* It's treated as the current display bits per pixel. *)
  ChkOutOfScreen* = TRUE;

TYPE
  PChar = POINTER [1] TO ARRAY OF CHAR;

VAR
  AppTitle-: PChar;
  VirtualWidth-, VirtualHeight-, (* Virtual Width, Height in pixels. *)
  VirtualMaxX-,  VirtualMaxY-,
  ActualWidth-,  ActualHeight-,  (* Actual Width, Height in pixels. *)
  ActualMaxX-,   ActualMaxY-
    : INTEGER;
  DepthBits- : SHORTINT; (* Depth in bits per pixel (8, 16, or 32). *)

BEGIN
  VirtualWidth  := 256; (* Virtual Width, Height in pixels. *)
  VirtualHeight := 192;
  VirtualMaxX   := VirtualWidth  - 1;
  VirtualMaxY   := VirtualHeight - 1;
  ActualWidth   := VirtualWidth  * 3; (* Actual Width, Height in pixels. *)
  ActualHeight  := VirtualHeight * 3;
  ActualMaxX    := ActualWidth   - 1;
  ActualMaxY    := ActualHeight  - 1;
  DepthBits     := AutoDetect; (* Depth in bits per pixel (8, 16, or 32). *)

  AppTitle := SYSTEM.VAL(PChar, SYSTEM.ADR("XDev/SDL graphic"));

END GrConfig.
