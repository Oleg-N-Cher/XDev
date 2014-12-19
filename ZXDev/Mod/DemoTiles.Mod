MODULE DemoTiles;
IMPORT G := GrApp, T := GrTiles, B := Basic;

VAR
  i: SHORTINT; square: T.Tile;
BEGIN (*$MAIN*)
  B.Init; B.PAPER(B.Black); B.CLS; B.BORDER(B.Red);
  B.DEFDATA(square, 8 + 1);
  (*Pixels:*) B.DATA8(0FFH, 81H, 81H, 81H, 81H, 81H, 81H, 0FFH);
  (*Attrib:*) B.DATA1(G.BlueOnOlive);
  FOR i := 0 TO 23 DO T.DrawTile(i, i, square) END;
  FOR i := 24 TO 31 DO T.DrawTile(i, 23, square) END;
  FOR i :=  8 TO 23 DO T.DrawMonoTile(i, 1, square, G.WhiteOnBlack) END;
  FOR i := 10 TO 21 DO T.DrawMonoTile(i, 3, square, G.CyanOnBlue) END;
  FOR i := 12 TO 19 DO T.DrawMonoTile(i, 5, square, G.BlackOnWhite) END;
  FOR i := 14 TO 17 DO T.DrawMonoTile(i, 7, square, G.GreenOnMagenta) END;
  B.PAUSE(B.WaitAKey);
  B.Quit;
END DemoTiles.