MODULE Triangle; (*$MAIN*)
IMPORT b := Basic;
VAR
  i: SHORTINT;
BEGIN
  b.Init;
  b.OVER(1); FOR i := 0 TO 100 DO b.PLOT(0, 0); b.DRAW(i, 100) END;
  b.Quit
END Triangle.
