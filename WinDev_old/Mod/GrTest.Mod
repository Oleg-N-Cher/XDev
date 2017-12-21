MODULE GrTest; (*$MAIN*)

IMPORT GrApp, Sdl := SdlLib, P := GrPixel, Input;

VAR
  x, width, height: P.Coords;

BEGIN
  width := GrApp.VirtualWidth;
  height := GrApp.VirtualHeight;

  FOR x := 0 TO 150 BY 30 DO
    P.Ink(GrApp.LightGreen);
    P.Circle(width DIV 2, height DIV 2, x);
    P.Ink(GrApp.LightRed);
    P.Circle(width DIV 2, height DIV 2, x + 5);
    P.Ink(GrApp.LightBlue);
    P.Circle(width DIV 2, height DIV 2, x + 10);
    P.Ink(GrApp.Green);
    P.Circle(width DIV 2, height DIV 2, x + 15);
    P.Ink(GrApp.Red);
    P.Circle(width DIV 2, height DIV 2, x + 20);
    P.Ink(GrApp.Blue);
    P.Circle(width DIV 2, height DIV 2, x + 25);
  END;

  FOR x := 0 TO 255 DO
    P.Ink(GrApp.LightGreen); P.Dot(x, x);
    P.Ink(GrApp.LightRed);   P.Dot(x+10, x);
    P.Ink(GrApp.LightBlue);  P.Dot(x+20, x);
    P.Ink(GrApp.Green); P.Dot(x+50, x);
    P.Ink(GrApp.Red);   P.Dot(x+60, x);
    P.Ink(GrApp.Blue);  P.Dot(x+70, x);
  END;

  FOR x := 0 TO 255 DO
    P.Ink(GrApp.Yellow);       P.Line(x, x, x*2, x*3);
    P.Ink(GrApp.LightMagenta); P.Line(width-x, x, width-x*2, x*3);
    P.Ink(GrApp.LightCyan);    P.Line(x, height-x, x*2, height-x*3);
    P.Ink(GrApp.White);  P.Line(width-x, height-x, width-x*2, height-x*3);
    P.Ink(GrApp.Olive);  P.Line(x+width DIV 2, x, x*2, x*3);
    P.Ink(GrApp.Black);  P.Line(x-width DIV 2, x, x*2, x*3);
  END;
(*
  Console.WriteInt(ORD(
    SYSTEM.VAL(CHAR, GrScr.Screen.format.BytesPerPixel)));
  IF GrScr.MustLock THEN
    Console.WriteStr(" Must Lock");
  ELSE
    Console.WriteStr(" No need Lock");
  END;*)
  GrApp.Redraw; IF Input.Read() = " " THEN END;
  GrApp.Close;
END GrTest.
