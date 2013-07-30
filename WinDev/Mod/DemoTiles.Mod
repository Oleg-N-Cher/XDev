MODULE DemoTiles;
IMPORT SYSTEM, GrScr, Sdl := SdlLib, Til := GrTiles, Colors := GrColors;

VAR
  i: SHORTINT; square: Til.Tile8x8;
BEGIN (*$MAIN*)
  square[0]:=0FFH;
  square[1]:=81H;
  square[2]:=81H;
  square[3]:=81H;
  square[4]:=81H;
  square[5]:=81H;
  square[6]:=81H;
  square[7]:=0FFH;

  Til.SetColors(Colors.Blue, Colors.Olive);
  FOR i := 0 TO 23 DO Til.DrawMonoTile8x8(i, i, square) END;
  FOR i := 24 TO 31 DO Til.DrawMonoTile8x8(i, 23, square) END;
  Til.SetColors(Colors.White, Colors.Black);
  FOR i :=  8 TO 23 DO Til.DrawMonoTile8x8(i, 1, square) END;
  Til.SetColors(Colors.Cyan, Colors.Blue);
  FOR i := 10 TO 21 DO Til.DrawMonoTile8x8(i, 3, square) END;
  Til.SetColors(Colors.Black, Colors.White);
  FOR i := 12 TO 19 DO Til.DrawMonoTile8x8(i, 5, square) END;
  Til.SetColors(Colors.Green, Colors.Magenta);
  FOR i := 14 TO 17 DO Til.DrawMonoTile8x8(i, 7, square) END;
  GrScr.Update;
  GrScr.Close;
END DemoTiles.