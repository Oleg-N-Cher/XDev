MODULE TestInpBuf; (*$MAIN*)
IMPORT B := Basic, Input, Timer;

VAR
  key: Input.Key; av: INT8;

BEGIN
  B.Init; B.CLS; B.IM2PROC(Input.RunMe50Hz);
  B.PRSTR("PRESS KEYS SO MANY AS POSSIBLE!"); B.PRLN;
  Timer.Delay(500); (* 1/50 сек. тиков, а не мс *)
  B.AT(0, 0); B.PRINT(Input.Available()); B.PRLN;
  WHILE Input.Available() > 0 DO B.PRCHAR(Input.Read()) END;
  B.PRLN;
  REPEAT
    av := Input.Available();
    B.AT(0, 0); B.PRINT(av); B.PRSTR("    ");
  UNTIL av = 8;
  B.AT(10, 10);
  WHILE Input.Available() > 0 DO B.PRCHAR(Input.Read()) END;
  LOOP END;
END TestInpBuf. 