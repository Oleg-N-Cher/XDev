MODULE BigCircles; IMPORT B := Basic;

VAR r: SHORTINT;

BEGIN (*$MAIN*)
  B.Init;
  FOR r := 160 TO 1 BY -1 DO B.CIRCLEW(129, 90, r) END;
  B.Quit;
END BigCircles.
