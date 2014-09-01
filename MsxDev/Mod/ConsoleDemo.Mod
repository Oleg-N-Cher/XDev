MODULE ConsoleDemo; (*$MAIN*)
IMPORT B := Basic, G := GRAPHIC;

VAR
  n: SHORTINT;
BEGIN
  G.Screen(0); G.Color(1, 15, 15);
  FOR n := 0 TO 7 BY 2 DO
    B.VPOKE(2048+32*8+n, 170);
    B.VPOKE(2048+32*8+n+1, 85);
  END;
END ConsoleDemo.
