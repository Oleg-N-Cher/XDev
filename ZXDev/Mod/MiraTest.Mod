MODULE MiraTest; (*$MAIN*)
IMPORT IO := Console, B := Basic, GRAPH0;

VAR
  c: IO.Coords; i: INTEGER;
BEGIN
  GRAPH0.CLS2; GRAPH0.GCLS;
  FOR i := 0 TO 512 DO
    B.INK(SHORT(B.RND(0, 6))); B.PLOT(B.RND(0, 255), B.RND(0, 175));
  END;
  FOR c := 1 TO 23 DO
    GRAPH0.SETATTRS(16 - c DIV 3, c - 3, (c DIV 3)*2, IO.GreenOnGreen);
  END;
  FOR c := 21 TO 23 DO
    GRAPH0.SETATTRS(15, c, 2, IO.RedOnRed);
  END;
  B.PAUSE(0);
END MiraTest.