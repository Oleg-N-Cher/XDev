MODULE DemoTiles;
IMPORT Til := GrTiles, B := Basic;

VAR
  i: SHORTINT; square: Til.Tile;
BEGIN (*$MAIN*)
  B.Init; B.BORDER(B.Red);
  B.DEFDATAREL(square, 8 + 1);
  B.DATA8((*Pixels:*)0FFH, 81H, 81H, 81H, 81H, 81H, 81H, 0FFH);
  B.DATA1((*Attrib:*)31H);
  FOR i := 0 TO 23 DO Til.DrawTile(i, i, square) END;
  FOR i := 24 TO 31 DO Til.DrawTile(i, 23, square) END;
  Til.SetColors(Til.WhiteOnBlack);
  FOR i :=  8 TO 23 DO Til.DrawMonoTile(i, 1, square) END;
  Til.SetColors(Til.CyanOnBlue);
  FOR i := 10 TO 21 DO Til.DrawMonoTile(i, 3, square) END;
  Til.SetColors(Til.BlackOnWhite);
  FOR i := 12 TO 19 DO Til.DrawMonoTile(i, 5, square) END;
  Til.SetColors(Til.GreenOnMagenta);
  FOR i := 14 TO 17 DO Til.DrawMonoTile(i, 7, square) END;
  B.PAUSE(B.WaitAKey);
  B.Quit;
END DemoTiles.