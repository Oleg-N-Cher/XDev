MODULE GrConsole;
IMPORT SYSTEM, Sdl := SdlLib,
  GrScr, GrFonts, GrPixel, GrTiles, Colors := GrColors;

CONST
  CharSizeInBytes = 8;
  TileSizeInBytes = 8;
TYPE
  FontPtr = POINTER [1] TO GrFonts.Font;
  TilePtr = POINTER [1] TO GrTiles.MonoTile8x8;
  ADDRESS = LONGINT;
VAR
  curX, curY: GrTiles.Coords; curColors: Colors.Colors; curFont: FontPtr;

PROCEDURE At* (x, y: GrTiles.Coords);
BEGIN
  curX := x; curY := y;
END At;

PROCEDURE Clear* (color: Colors.Color);
VAR
  x, y: GrPixel.Coords; inkTemp: Colors.Color;
BEGIN
  curX := 0; curY := 0;
  IF GrScr.MustLock & (Sdl.LockSurface(GrScr.Screen) = 0) THEN RETURN END;
  inkTemp := GrPixel.ink; GrPixel.Ink(color);
  FOR y := GrScr.Screen.h - 1 TO 0 BY -1 DO
    FOR x := GrScr.Screen.w - 1 TO 0 BY -1 DO
      GrPixel.PutPixelNoLock(x, y);
    END;
  END;
  IF GrScr.MustLock THEN Sdl.UnlockSurface(GrScr.Screen) END;
  GrPixel.Ink(inkTemp);
END Clear;

PROCEDURE SetColors* (colors: Colors.Colors);
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
VAR
  tilePtr: TilePtr;
BEGIN
  tilePtr := SYSTEM.VAL(TilePtr,
    TileSizeInBytes * ORD(ch) + SYSTEM.VAL(ADDRESS, curFont));
  GrTiles.DrawMonoTile8x8(curX, curY, tilePtr^, curColors);
  INC(curX);
END WriteCh;

PROCEDURE WriteLn* ;
BEGIN
  curX := 0; INC(curY);
END WriteLn;

PROCEDURE WriteStr* ((*IN*) str: ARRAY [1] OF CHAR);
VAR
  n: LONGINT;
BEGIN
  n := 0;
  WHILE (n < LEN(str)) & (str[n] # 0X) DO WriteCh(str[n]); INC(n) END;
END WriteStr;

PROCEDURE WriteStrLn* ((*IN*) str: ARRAY [1] OF CHAR);
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
  curColors.paper := Colors.Black; curColors.ink := Colors.Gray;
  SetFont(GrFonts.ZxSpecRom8x8);
END GrConsole.