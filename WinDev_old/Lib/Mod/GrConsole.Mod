MODULE GrConsole;
IMPORT SYSTEM, Sdl := SdlLib, GrApp, GrFonts, GrPixel, GrTiles;

CONST
  CharSizeInBytes = 8;
  TileSizeInBytes = 8;

TYPE
  FontPtr = POINTER[1] TO GrFonts.Font;

VAR
  curX, curY: GrTiles.Coords; curColors: GrApp.Colors; curFont: FontPtr;

PROCEDURE At* (x, y: GrTiles.Coords);
BEGIN
  curX := x; curY := y;
END At;

PROCEDURE Clear* (color: GrApp.Color);
VAR
  x, y: GrPixel.Coords; inkTemp: GrApp.Color;
BEGIN
  curX := 0; curY := 0;
  IF GrApp.MustLock & (Sdl.LockSurface(GrApp.Screen) = 0) THEN RETURN END;
  inkTemp := GrPixel.ink; GrPixel.Ink(color);
  FOR y := GrApp.Screen.h - 1 TO 0 BY -1 DO
    FOR x := GrApp.Screen.w - 1 TO 0 BY -1 DO
      GrPixel.PutPixelNoLock(x, y);
    END;
  END;
  IF GrApp.MustLock THEN Sdl.UnlockSurface(GrApp.Screen) END;
  GrPixel.Ink(inkTemp);
END Clear;

PROCEDURE SetColors* (colors: GrApp.Colors);
BEGIN
  curColors := colors;
END SetColors;

PROCEDURE SetFont* (VAR font: GrFonts.Font);
BEGIN
  IF SYSTEM.ADR(font) = SYSTEM.ADR(GrFonts.ZxSpecRom8x8) THEN
    curFont := SYSTEM.VAL(FontPtr, SYSTEM.ADR(font) - 32*CharSizeInBytes);
  ELSE
    curFont := SYSTEM.VAL(FontPtr, SYSTEM.ADR(font));
  END;
END SetFont;

PROCEDURE WriteCh* (ch: CHAR);
TYPE
  TilePtr = POINTER[1] TO GrTiles.MonoTile8x8;
VAR
  tilePtr: TilePtr;
BEGIN
  IF SIZE(TilePtr) = 4 THEN
    tilePtr := SYSTEM.VAL(TilePtr,
      TileSizeInBytes * ORD(ch) + SYSTEM.VAL(INTEGER, curFont));
  ELSE
    tilePtr := SYSTEM.VAL(TilePtr,
      TileSizeInBytes * ORD(ch) + SYSTEM.VAL(LONGINT, curFont));
  END;
  GrTiles.DrawMonoTile8x8(curX, curY, tilePtr^, curColors);
  INC(curX);
END WriteCh;

PROCEDURE WriteLn* ;
BEGIN
  curX := 0; INC(curY);
END WriteLn;

PROCEDURE WriteStr* (IN str: ARRAY OF CHAR);
VAR
  n: INTEGER;
BEGIN
  n := 0;
  WHILE (n < SHORT(LEN(str))) & (str[n] # 0X) DO WriteCh(str[n]); INC(n) END;
END WriteStr;

PROCEDURE WriteStrLn* (IN str: ARRAY OF CHAR);
BEGIN
  WriteStr(str); WriteLn;
END WriteStrLn;

PROCEDURE WriteInt* (x: INTEGER); (* Write integer x to Console. *)
VAR
  i: INTEGER; buf: ARRAY 10 OF CHAR;
BEGIN
  IF x < 0 THEN
    IF x = MIN(INTEGER) THEN WriteStr("-2147483648"); RETURN END;
    WriteCh("-"); x := -x;
  END;
  i := 0;
  REPEAT
    buf[i] := CHR(x MOD 10 + ORD("0")); x := x DIV 10; INC(i);
  UNTIL x = 0;
  REPEAT DEC(i); WriteCh(buf[i]) UNTIL i = 0;
END WriteInt;

BEGIN
  curX := 0; curY := 0;
  curColors.paper := GrApp.Black; curColors.ink := GrApp.Gray;
  SetFont(GrFonts.ZxSpecRom8x8);
END GrConsole.