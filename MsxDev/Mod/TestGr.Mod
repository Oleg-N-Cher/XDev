MODULE TestGr;
IMPORT G := GRAPHIC, Basic;
VAR
  n: SHORTINT;
BEGIN (*$MAIN*)
  G.Screen(7); G.Color(15,1,1);
  FOR n := 32 TO 126 DO
    Basic.ATR(n MOD 16); Basic.LINE(n, 5, n, 150) END;
  Basic.ATR(15);
  G.Pset(1,2,0,5,0);
END TestGr.
