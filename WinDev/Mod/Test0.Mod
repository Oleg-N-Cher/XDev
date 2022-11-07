MODULE Test0;

CONST
  longhex = 0FFFFFFFFFFFFFFFFH;
  longhex2 = 0FFFFFFFFFFFFFFFFL;
  c0* = (-32) * 8;
  d0* = (5 + 5) DIV0 2;
	Min* = MIN(LONGINT) DIV (1);

VAR
  x, a, b: INTEGER;

BEGIN
  x := a DIV0 b;
  x := a REM0 b;
END Test0.