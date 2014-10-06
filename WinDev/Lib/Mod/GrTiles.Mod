MODULE GrTiles;	(** Ver. for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, GrApp, GrPixel, Gr := GrColors;

TYPE
  Color = GrApp.Color;
  Coords* = INTEGER;
  Tile* = Sdl.PSurface;
  MonoTile = ARRAY[1] OF BYTE;
  MonoTile8x8* = ARRAY[1] 8 OF BYTE;
  TranspMonoTile = ARRAY[1] OF BYTE;
  TranspMonoTile8x8* = ARRAY[1] 8 * 2 OF BYTE;
  Tile8x8* = RECORD
    mono*: MonoTile8x8;
    colors*: Gr.Colors;
  END;

VAR
  DrawMonoTile-: PROCEDURE (
    x, y: Coords; VAR tile: MonoTile; colors: Gr.Colors);
  DrawTranspMonoTile-: PROCEDURE (
    x, y: Coords; VAR tile: TranspMonoTile; colors: Gr.Colors);

PROCEDURE DrawMonoTile8x8* (
  x, y: Coords; VAR tile: MonoTile; colors: Gr.Colors);
VAR
  mask: CHAR; byte, bit: SHORTINT; inkTemp: Color;
BEGIN
  x := x * 8; y := y * 8;
  inkTemp := GrPixel.ink;
  IF GrApp.MustLock & (Sdl.LockSurface(GrApp.Screen) = 0) THEN RETURN END;
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
  IF GrApp.MustLock THEN Sdl.UnlockSurface(GrApp.Screen) END;
  GrPixel.Ink(inkTemp);
END DrawMonoTile8x8;

PROCEDURE DrawTranspMonoTile8x8* (
  x, y: Coords; VAR tile: TranspMonoTile; colors: Gr.Colors);
VAR
  mask, transp: CHAR; byte, bit: SHORTINT; inkTemp: Color;
BEGIN
  x := x * 8; y := y * 8;
  inkTemp := GrPixel.ink;
  IF GrApp.MustLock & (Sdl.LockSurface(GrApp.Screen) = 0) THEN RETURN END;
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
  IF GrApp.MustLock THEN Sdl.UnlockSurface(GrApp.Screen) END;
  GrPixel.Ink(inkTemp);
END DrawTranspMonoTile8x8;

PROCEDURE SetTileAsMonoTile8x8* (
  VAR tile: Tile; VAR monoTile: MonoTile8x8; colors: Gr.Colors);
BEGIN
  tile := Sdl.CreateRGBSurface(
    Sdl.HWPALETTE, 8, 8,
    SYSTEM.VAL(Sdl.Integer, GrApp.Screen^.format^.BitsPerPixel),
    0, 0, 0, 0);
  (*...*)
END SetTileAsMonoTile8x8;

PROCEDURE DrawTile8x8* (x, y: Coords; VAR tile: Tile8x8);
BEGIN
  DrawMonoTile8x8(x, y, tile.mono, tile.colors);
END DrawTile8x8;

PROCEDURE DrawTile* (x, y: Coords; VAR tile: Tile8x8);
END DrawTile;

BEGIN
  DrawMonoTile := DrawMonoTile8x8;
  DrawTranspMonoTile := DrawTranspMonoTile8x8;
END GrTiles.