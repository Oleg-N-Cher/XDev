MODULE Triangle; (*$MAIN*)
IMPORT b := Basic;
VAR
  i: BYTE;
BEGIN
  b.Init;
  b.PLOT(100, 80); b.DRAWARC(30, 50, 172);
  b.PLOT(100, 80); b.DRAWARC(30, 50, -172);
  b.OVER(1); FOR i := 0 TO 100 DO b.PLOT(0, 0); b.DRAW(i, 100) END;
  b.Quit
END Triangle.
