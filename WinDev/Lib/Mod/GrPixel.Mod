MODULE GrPixel;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, GrScr, Cfg := GrConfig;

TYPE
  Color* = GrScr.Color;
  Coords* = INTEGER;
VAR
  ink: Color;
  pitch: INTEGER;
  PutPixel- : PROCEDURE (x, y: Coords);

PROCEDURE PutPixel8 (x, y: Coords); (* Assuming 8-bpp mode. *)
BEGIN
  IF (x >= 0) & (x <= Cfg.ActualMaxX)
    & (y >= 0) & (y <= Cfg.ActualMaxY) THEN
      IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
      SYSTEM.PUT(
        SYSTEM.VAL(LONGINT, GrScr.Screen.pixels) + y*pitch + x,
        SYSTEM.VAL(SYSTEM.BYTE, ink));
      IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
      Sdl.UpdateRect(GrScr.Screen, x, y, 1, 1);
  END;
END PutPixel8;

PROCEDURE PutPixel16 (x, y: Coords); (* Probably 15-bpp or 16-bpp. *)
BEGIN
  IF (x >= 0) & (x <= Cfg.ActualMaxX)
    & (y >= 0) & (y <= Cfg.ActualMaxY) THEN
      IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
      SYSTEM.PUT(
        SYSTEM.VAL(LONGINT, GrScr.Screen.pixels) + y*pitch + x*2,
        SYSTEM.VAL(SHORTINT, ink));
      IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
      Sdl.UpdateRect(GrScr.Screen, x, y, 1, 1);
  END;
END PutPixel16;

(* Slow 24-bpp mode, usually not used: *)
PROCEDURE PutPixel24 (x, y: Coords);
VAR
  addr: LONGINT;
BEGIN
  IF (x >= 0) & (x <= Cfg.ActualMaxX)
    & (y >= 0) & (y <= Cfg.ActualMaxY) THEN
      IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
      addr := SYSTEM.VAL(LONGINT, GrScr.Screen.pixels) + y*pitch + x*3;
      SYSTEM.PUT(addr,   SYSTEM.VAL(SHORTINT, ink));
      SYSTEM.PUT(addr+2, SYSTEM.VAL(SYSTEM.BYTE, SYSTEM.LSH(ink, -16)));
      IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
      Sdl.UpdateRect(GrScr.Screen, x, y, 1, 1);
  END;
END PutPixel24;

PROCEDURE PutPixel32 (x, y: Coords); (* 32-bpp mode. *)
BEGIN
  IF (x >= 0) & (x <= Cfg.ActualMaxX)
    & (y >= 0) & (y <= Cfg.ActualMaxY) THEN
      IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
      SYSTEM.PUT(
        SYSTEM.VAL(LONGINT, GrScr.Screen.pixels) + y*pitch + x*4, ink);
      IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
      Sdl.UpdateRect(GrScr.Screen, x, y, 1, 1);
  END;
END PutPixel32;

PROCEDURE SetInk* (color: Color);
BEGIN
  ink := color;
END SetInk;

BEGIN
  pitch := GrScr.Screen.pitch;
  CASE SYSTEM.VAL(CHAR, GrScr.Screen.format.BytesPerPixel) OF
  | 1X: (* Assuming 8-bpp *)
    PutPixel := PutPixel8;
  | 2X: (* Probably 15-bpp or 16-bpp *)
    PutPixel := PutPixel16;
  | 3X: (* Slow 24-bpp mode, usually not used *)
    PutPixel := PutPixel24;
  | 4X: (* Probably 32-bpp *)
    PutPixel := PutPixel32;
  ELSE END;
END GrPixel.