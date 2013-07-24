MODULE GrTest; (*$MAIN*)

IMPORT GrScr, P := GrPixel, Sdl := SdlLib, Console, SYSTEM, Cfg := GrConfig;

CONST
  Width = Cfg.VirtualWidth;
  Height = Cfg.VirtualHeight;
VAR
  x: P.Coords;

BEGIN
  FOR x := 0 TO 150 BY 30 DO
    P.SetInk(GrScr.LightGreen);
    P.Circle(Width DIV 2, Height DIV 2, x);
    P.SetInk(GrScr.LightRed);
    P.Circle(Width DIV 2, Height DIV 2, x + 5);
    P.SetInk(GrScr.LightBlue);
    P.Circle(Width DIV 2, Height DIV 2, x + 10);
    P.SetInk(GrScr.Green);
    P.Circle(Width DIV 2, Height DIV 2, x + 15);
    P.SetInk(GrScr.Red);
    P.Circle(Width DIV 2, Height DIV 2, x + 20);
    P.SetInk(GrScr.Blue);
    P.Circle(Width DIV 2, Height DIV 2, x + 25);
  END;

  FOR x := 0 TO 255 DO
    P.SetInk(GrScr.LightGreen); P.PutPixel(x, x);
    P.SetInk(GrScr.LightRed);   P.PutPixel(x+10, x);
    P.SetInk(GrScr.LightBlue);  P.PutPixel(x+20, x);
    P.SetInk(GrScr.Green); P.PutPixel(x+50, x);
    P.SetInk(GrScr.Red);   P.PutPixel(x+60, x);
    P.SetInk(GrScr.Blue);  P.PutPixel(x+70, x);
  END;

  FOR x := 0 TO 255 DO
    P.SetInk(GrScr.Yellow);       P.Line(x, x, x*2, x*3);
    P.SetInk(GrScr.LightMagenta); P.Line(Width-x, x, Width-x*2, x*3);
    P.SetInk(GrScr.LightCyan);    P.Line(x, Height-x, x*2, Height-x*3);
    P.SetInk(GrScr.White);  P.Line(Width-x, Height-x, Width-x*2, Height-x*3);
    P.SetInk(GrScr.Olive);  P.Line(x+Width DIV 2, x, x*2, x*3);
    P.SetInk(GrScr.Black);  P.Line(x-Width DIV 2, x, x*2, x*3);
  END;

  Console.WriteInt(ORD(
    SYSTEM.VAL(CHAR, GrScr.Screen.format.BytesPerPixel)));
  IF GrScr.mustLock THEN
    Console.WriteStr(" Must Lock");
  ELSE
    Console.WriteStr(" No need Lock");
  END;
  GrScr.Update;
  Sdl.Delay(5000);
  GrScr.Close;
END GrTest.
