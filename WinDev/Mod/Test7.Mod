MODULE Test7;

CONST
  a* = FLOOR(3.141);
  b* = FLOOR(-3.141);
  c* = FLOOR(3.941);
  d* = FLOOR(-3.941);
  e* = FLOOR(1.5);
  f* = FLOOR(-1.5);
  l* = FLT(1234);

VAR i: INTEGER; r: REAL;

PROCEDURE Ten(x: INTEGER): INTEGER; END Ten;

PROCEDURE WriteReal* (r: SHORTREAL);
	VAR e, i, j, m: INTEGER; d: ARRAY 16 OF CHAR;
BEGIN i := 0; j := 0;
	e := ASR(SYSTEM.VAL(INTEGER, r)), 23) MOD 100H;	(*binary exponent*)
	IF e # 0 THEN
		IF r < 0.0 THEN d[j] := "-"; r := ABS(r); INC(j) END ;
		e := (e - 127) * 77 DIV 256 - 6;	(*decimal exponent*)
		IF e >= 0 THEN r := r / Ten(e) ELSE r := Ten(-e) * r END ;
		m := FLOOR(r + 0.5);
		IF m >= 10000000 THEN INC(e); m := m DIV 10 END ;
		REPEAT d[i] := CHR(m MOD 10 + 30H); m := m DIV 10; INC(i) UNTIL m = 0;
		d[i] := 0X; DEC(i); d[i] := "."; (* "." replaces 1st digit !! *)
		REPEAT d[j] := d[i]; DEC(i); INC(j) UNTIL i < 0 ; (*reverse*)
		d[j] := "E"; INC(e, 6); INC(j);
		IF e < 0 THEN d[j] :=	"-"; e := -e ELSE d[j] := "+" END ;
		d[j+1] := CHR(e DIV 10 + 30H); d[j+2] := CHR(e MOD 10 + 30H)
	END
END WriteReal;


BEGIN
  i := FLOOR(r);
  i := FLOOR(3.141);
  i := FLOOR(-3.141);
  i := FLOOR(3.941);
  i := FLOOR(-3.941);
  i := FLOOR(1.5);
  i := FLOOR(-1.5);
  r := FLT(9999999999999);
  r := FLT(i);
END Test7.