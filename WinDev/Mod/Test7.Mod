MODULE Test7; IMPORT SYSTEM;

VAR var* : INTEGER;

CONST
	o0* = LSL(SYSTEM.VAL(SYSTEM.INT32, 2H), 31);
  p0* = LSL(SYSTEM.VAL(SYSTEM.INT64, 2H), 31);
  a* = FLOOR(3.141);
  c* = FLOOR(3.941);
  d* = FLOOR(-3.941);
  e* = FLOOR(1.5);
  f* = FLOOR(-1.5);
  dd* = ASR(MIN(INTEGER), 31);
  rr* = LSL(1, 31);
a1* = ROR(-2147483647, 1);
a2* = ROR(00000001H, 1);
a3* = ROR(00000000H, 1);
a4* = ROR(MIN(INTEGER), 1);
  p00* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 0);
  p01* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 1);
  p02* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 2);
  p03* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 3);
  p04* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 4);
  p05* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 5);
  p06* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 6);
  p07* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 7);
  p08* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 8);
  p09* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 9);
  p10* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 10);
  p11* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 11);
  p12* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 12);
  p13* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 13);
  p14* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 14);
  p15* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 15);
  p16* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 16);
  p17* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 17);
  p18* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 18);
  p19* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 19);
  p20* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 20);
  p21* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 21);
  p22* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 22);
  p23* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 23);
  p24* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 24);
  p25* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 25);
  p26* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 26);
  p27* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 27);
  p28* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 28);
  p29* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 29);
  p30* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 30);
  p31* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 31);
  p001* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 2);
  p32* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 32);
  p33* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 33);
  p34* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 34);
  p60* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 60);
  p61* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 61);
  p62* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 62);
  p63* = ROR(SYSTEM.VAL(SYSTEM.INT64, 1), 63);

VAR b: SYSTEM.INT8; s: SYSTEM.INT16; i, x: INTEGER; l: SYSTEM.INT64; r: REAL;

PROCEDURE Ten(x: INTEGER): INTEGER; END Ten;

PROCEDURE WriteReal* (r: REAL);
	VAR e, i, j, m: INTEGER; d: ARRAY 16 OF CHAR;
BEGIN i := 0; j := 0;
	e := ASR(SYSTEM.VAL(INTEGER, r), 23) MOD 100H;	(*binary exponent*)
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

PROCEDURE Ret(): INTEGER
RETURN 1+2 END Ret;

PROCEDURE Ret0(): INTEGER;
BEGIN REPEAT UNTIL FALSE
RETURN 1 END Ret0;

PROCEDURE Ret1(): INTEGER;
BEGIN
  IF 1=1 THEN END
RETURN 1 END Ret1;

PROCEDURE Ret2;
  (*RETURN*)
END Ret2;

BEGIN
  i := ASR(b, x); i := ASR(s, x); i := ASR(i, x); l := ASR(l, x);
  i := LSL(b, x); i := LSL(s, x); i := LSL(i, x); l := LSL(l, x);
  i := ROR(b, x); i := ROR(s, x); i := ROR(i, x); l := ROR(l, x);
  i := FLOOR(3.141);
  i := FLOOR(-3.141);
  i := FLOOR(3.941);
  i := FLOOR(-3.941);
  i := FLOOR(1.5);
  i := FLOOR(-1.5);
  r := FLT(999999999);
  r := FLT(i);
	ASSERT(FALSE, 123)
END Test7.