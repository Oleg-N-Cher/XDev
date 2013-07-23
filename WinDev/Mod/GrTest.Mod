MODULE GrTest; (*$MAIN*)

IMPORT GrScr, P := GrPixel, Sdl := SdlLib, Console, SYSTEM;

VAR
  x: P.Coords;
BEGIN
  FOR x := 0 TO 2550 DO
    P.SetInk(GrScr.LightGreen); P.PutPixel(x, x);
    P.SetInk(GrScr.LightRed);   P.PutPixel(x+10, x);
    P.SetInk(GrScr.LightBlue);  P.PutPixel(x+20, x);
    P.SetInk(GrScr.Green); P.PutPixel(x+50, x);
    P.SetInk(GrScr.Red);   P.PutPixel(x+60, x);
    P.SetInk(GrScr.Blue);  P.PutPixel(x+70, x);
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
