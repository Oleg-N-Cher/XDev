MODULE GrTiles;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, GrScr, GrPixel, GrColors;

TYPE
  Color = GrScr.Color;
  Coords* = INTEGER;
  Tile = ARRAY [1] OF SYSTEM.BYTE;
  Tile8x8* = ARRAY [1] 8 OF SYSTEM.BYTE;

PROCEDURE DrawMonoTile8x8* (
  x, y: Coords; VAR tile: Tile; colors: GrColors.Colors);
VAR
  mask: CHAR; byte, bit: SHORTINT; inkTemp: Color;
BEGIN
  x := x * 8; y := y * 8;
  inkTemp := GrPixel.ink;
  IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
  FOR byte := 0 TO 7 DO
    mask := SYSTEM.VAL(CHAR, tile[byte]);
    FOR bit := 0 TO 7 DO
      IF mask >= 80X THEN
        GrPixel.Ink(colors.ink);
        GrPixel.PutPixelNoLock(x + bit, y);
      ELSE
        GrPixel.Ink(colors.paper);
        GrPixel.PutPixelNoLock(x + bit, y);
      END;
      mask := SYSTEM.LSH(mask, 1);
    END;
    INC(y);
  END;
  IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
  GrPixel.Ink(inkTemp);
END DrawMonoTile8x8;

END GrTiles.