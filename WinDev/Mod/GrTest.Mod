MODULE GrTest; (*$MAIN*)

IMPORT GrScr, Sdl := SdlLib, Console, SYSTEM,
  Cfg := GrConfig, Colors := GrColors, P := GrPixel;

CONST
  Width = Cfg.VirtualWidth;
  Height = Cfg.VirtualHeight;
VAR
  x: P.Coords;

BEGIN
  FOR x := 0 TO 150 BY 30 DO
    P.Ink(Colors.LightGreen);
    P.Circle(Width DIV 2, Height DIV 2, x);
    P.Ink(Colors.LightRed);
    P.Circle(Width DIV 2, Height DIV 2, x + 5);
    P.Ink(Colors.LightBlue);
    P.Circle(Width DIV 2, Height DIV 2, x + 10);
    P.Ink(Colors.Green);
    P.Circle(Width DIV 2, Height DIV 2, x + 15);
    P.Ink(Colors.Red);
    P.Circle(Width DIV 2, Height DIV 2, x + 20);
    P.Ink(Colors.Blue);
    P.Circle(Width DIV 2, Height DIV 2, x + 25);
  END;

  FOR x := 0 TO 255 DO
    P.Ink(Colors.LightGreen); P.Dot(x, x);
    P.Ink(Colors.LightRed);   P.Dot(x+10, x);
    P.Ink(Colors.LightBlue);  P.Dot(x+20, x);
    P.Ink(Colors.Green); P.Dot(x+50, x);
    P.Ink(Colors.Red);   P.Dot(x+60, x);
    P.Ink(Colors.Blue);  P.Dot(x+70, x);
  END;

  FOR x := 0 TO 255 DO
    P.Ink(Colors.Yellow);       P.Line(x, x, x*2, x*3);
    P.Ink(Colors.LightMagenta); P.Line(Width-x, x, Width-x*2, x*3);
    P.Ink(Colors.LightCyan);    P.Line(x, Height-x, x*2, Height-x*3);
    P.Ink(Colors.White);  P.Line(Width-x, Height-x, Width-x*2, Height-x*3);
    P.Ink(Colors.Olive);  P.Line(x+Width DIV 2, x, x*2, x*3);
    P.Ink(Colors.Black);  P.Line(x-Width DIV 2, x, x*2, x*3);
  END;

  Console.WriteInt(ORD(
    SYSTEM.VAL(CHAR, GrScr.Screen.format.BytesPerPixel)));
  IF GrScr.mustLock THEN
    Console.WriteStr(" Must Lock");
  ELSE
    Console.WriteStr(" No need Lock");
  END;
  GrScr.Update;
  GrScr.Close;
END GrTest.
