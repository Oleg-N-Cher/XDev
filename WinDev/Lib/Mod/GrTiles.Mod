MODULE GrTiles;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, GrScr, GrPixel, GrColors;

TYPE
  Color = GrScr.Color;
  Coords* = INTEGER;
  Tile = ARRAY[1] OF BYTE;
  Tile8x8* = ARRAY[1] 8 OF BYTE;
  TranspTile = ARRAY[1] OF BYTE;
  TranspTile8x8* = ARRAY[1] 8 * 2 OF BYTE;

VAR
  DrawMonoTile-: PROCEDURE (
    x, y: Coords; VAR tile: Tile; colors: GrColors.Colors);
  DrawTranspMonoTile-: PROCEDURE (
    x, y: Coords; VAR tile: TranspTile; colors: GrColors.Colors);

PROCEDURE DrawMonoTile8x8* (
  x, y: Coords; VAR tile: Tile; colors: GrColors.Colors);
VAR
  mask: CHAR; byte, bit: SHORTINT; inkTemp: Color;
BEGIN
  x := x * 8; y := y * 8;
  inkTemp := GrPixel.ink;
  IF GrScr.MustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
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
  IF GrScr.MustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
  GrPixel.Ink(inkTemp);
END DrawMonoTile8x8;

PROCEDURE DrawTranspMonoTile8x8* (
  x, y: Coords; VAR tile: TranspTile; colors: GrColors.Colors);
VAR
  mask, transp: CHAR; byte, bit: SHORTINT; inkTemp: Color;
BEGIN
  x := x * 8; y := y * 8;
  inkTemp := GrPixel.ink;
  IF GrScr.MustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
  FOR byte := 0 TO 7 DO
    mask := SYSTEM.VAL(CHAR, tile[byte]);
    transp := SYSTEM.VAL(CHAR, tile[byte + 8]);
    FOR bit := 0 TO 7 DO
      IF transp < 80X THEN
        IF mask >= 80X THEN
          GrPixel.Ink(colors.ink);
          GrPixel.PutPixelNoLock(x + bit, y);
        ELSE
          GrPixel.Ink(colors.paper);
          GrPixel.PutPixelNoLock(x + bit, y);
        END;
      END;
      mask := SYSTEM.LSH(mask, 1);
      transp := SYSTEM.LSH(transp, 1);
    END;
    INC(y);
  END;
  IF GrScr.MustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
  GrPixel.Ink(inkTemp);
END DrawTranspMonoTile8x8;

BEGIN
  DrawMonoTile := DrawMonoTile8x8;
  DrawTranspMonoTile := DrawTranspMonoTile8x8;
END GrTiles.