MODULE FastCircle; IMPORT B := Basic;

VAR r: INTEGER;

BEGIN (*$MAIN*)
  B.Init;
  FOR r := 160 TO 1 BY -1 DO B.CIRCLE(129, 90, r) END;
  B.Quit;
END FastCircle.
