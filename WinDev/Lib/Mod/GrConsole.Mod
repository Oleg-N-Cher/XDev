MODULE GrConsole;
IMPORT SYSTEM, Sdl := SdlLib,
  GrScr, GrFonts, GrPixel, GrTiles, Colors := GrColors;

CONST
  CharSizeInBytes = 8;
  TileSizeInBytes = 8;
TYPE
  FontPtr = POINTER [1] TO GrFonts.Font;
  TilePtr = POINTER [1] TO GrTiles.Tile8x8;
  ADDRESS = LONGINT;
VAR
  x, y: GrTiles.Coords; curColors: Colors.Colors; curFont: FontPtr;

PROCEDURE Clear* (color: Colors.Color);
VAR
  x, y: GrPixel.Coords; inkTemp: Colors.Color;
BEGIN
  inkTemp := GrPixel.ink; GrPixel.Ink(color);
  IF GrScr.mustLock & ~Sdl.LockSurface(GrScr.Screen) THEN RETURN END;
  FOR y := GrScr.Screen.h - 1 TO 0 BY -1 DO
    FOR x := GrScr.Screen.w - 1 TO 0 BY -1 DO
      GrPixel.PutPixelNoLock(x, y);
    END;
  END;
  IF GrScr.mustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
  GrPixel.Ink(inkTemp);
END Clear;

PROCEDURE SetColors* (colors: Colors.Colors);
BEGIN
  curColors := colors;
END SetColors;

PROCEDURE SetFont* (VAR font: GrFonts.Font);
BEGIN
  IF SYSTEM.ADR(font) = SYSTEM.ADR(GrFonts.ZxSpecROM8x8) THEN
    curFont := SYSTEM.VAL(FontPtr, SYSTEM.ADR(font) - 32*CharSizeInBytes);
  ELSE
    curFont := SYSTEM.VAL(FontPtr, SYSTEM.ADR(font));
  END;
END SetFont;

PROCEDURE WriteCh* (ch: CHAR);
VAR
  tilePtr: TilePtr;
BEGIN
  tilePtr := SYSTEM.VAL(TilePtr,
    TileSizeInBytes * ORD(ch) + SYSTEM.VAL(ADDRESS, curFont));
  GrTiles.DrawMonoTile8x8(x, y, tilePtr^, curColors);
  INC(x);
END WriteCh;

PROCEDURE WriteStr* ((*IN*) str: ARRAY [1] OF CHAR);
VAR
  n: LONGINT;
BEGIN
  n := 0;
  WHILE (n < LEN(str)) & (str[n] # 0X) DO WriteCh(str[n]); INC(n) END;
END WriteStr;

BEGIN
  x := 0; y := 0;
  curColors.paper := Colors.Black; curColors.ink := Colors.Gray;
  SetFont(GrFonts.ZxSpecROM8x8);
END GrConsole.