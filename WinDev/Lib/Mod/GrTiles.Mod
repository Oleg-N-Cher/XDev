MODULE GrTiles;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, GrScr, GrPixel;

TYPE
  Color = GrScr.Color;
  Coords = INTEGER;
  Tile = ARRAY [1] OF SYSTEM.BYTE;
  Tile8x8* = ARRAY [1] 8 OF SYSTEM.BYTE;

VAR
  ink, paper: Color;

PROCEDURE DrawMonoTile8x8* (x, y: Coords; VAR tile: Tile);
VAR
  byte, bit: SHORTINT; inkTemp: Color;
BEGIN
  x := x * 8; y := y * 8;
  inkTemp := GrPixel.ink;
  IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
  FOR byte := 0 TO 7 DO
    FOR bit := 0 TO 7 DO
      IF bit IN SYSTEM.VAL(SET, tile[byte]) THEN
        GrPixel.SetInk(ink);
        GrPixel.PutPixelNoLock(x + bit, y + byte);
      ELSE
        GrPixel.SetInk(paper);
        GrPixel.PutPixelNoLock(x + bit, y + byte);
      END;
    END;
  END;
  IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
  GrPixel.SetInk(inkTemp);
END DrawMonoTile8x8;

PROCEDURE SetColors* (fore, back: Color);
BEGIN
  ink := fore; paper := back;
END SetColors;

END GrTiles.