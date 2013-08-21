MODULE DemoTiles;
IMPORT SYSTEM, GrScr, Sdl := SdlLib, T := GrTiles, C := GrColors;

VAR
  i: T.Coords; square: T.Tile8x8;
BEGIN (*$MAIN*)
  square[0]:=0FFH;
  square[1]:=81H;
  square[2]:=81H;
  square[3]:=81H;
  square[4]:=81H;
  square[5]:=81H;
  square[6]:=81H;
  square[7]:=0FFH;

  FOR i :=  0 TO 23 DO T.DrawMonoTile8x8(i, i, square, C.BlueOnOlive) END;
  FOR i := 24 TO 31 DO T.DrawMonoTile8x8(i, 23, square, C.BlueOnOlive) END;
  FOR i :=  8 TO 23 DO T.DrawMonoTile8x8(i, 1, square, C.WhiteOnBlack) END;
  FOR i := 10 TO 21 DO T.DrawMonoTile8x8(i, 3, square, C.CyanOnBlue) END;
  FOR i := 12 TO 19 DO T.DrawMonoTile8x8(i, 5, square, C.BlackOnWhite) END;
  FOR i := 14 TO 17 DO T.DrawMonoTile8x8(i,7,square,C.GreenOnMagenta) END;
  GrScr.Update;
  GrScr.Close;
END DemoTiles.