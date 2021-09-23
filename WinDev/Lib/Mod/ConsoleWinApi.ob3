MODULE ConsoleWinApi;
IMPORT SYSTEM, w := WinApi, Strings, Ignore;

TYPE
  REAL64 = SYSTEM.REAL64;

VAR
  hConOutput: w.HANDLE;

PROCEDURE SetColors* (colors: INT16);
BEGIN
  Ignore.Int( w.SetConsoleTextAttribute(hConOutput, colors) );
END SetColors;

PROCEDURE WriteCh* (ch: CHAR);
VAR
  maxLen: INT32;
BEGIN
  Ignore.Int( w.WriteFile(hConOutput, SYSTEM.ADR(ch), 1, @maxLen, @NIL) );
END WriteCh;

PROCEDURE WriteLn* ;
BEGIN
  WriteCh(0DX); WriteCh(0AX);
END WriteLn;

PROCEDURE WriteInt* (n: INT32);
VAR
  s: ARRAY 11 OF CHAR; i1, k: INT32;
BEGIN
  IF n = MIN(INT32) THEN s := "8463847412"; k := 10;
  ELSE
    i1 := ABS(n);
    s[0] := CHR(i1 MOD 10 + ORD("0")); i1 := i1 DIV 10; k := 1;
    WHILE i1 > 0 DO
      s[k] := CHR(i1 MOD 10 + ORD("0")); i1 := i1 DIV 10; INC(k);
    END;
  END;
  IF n < 0 THEN s[k] := "-"; INC(k) END;
  WHILE k > 0 DO DEC(k); WriteCh(s[k]) END;
END WriteInt;

PROCEDURE WriteLong* (n: INT64);
VAR
  s: ARRAY 20 OF CHAR; i1: INT64; k: INT32;
BEGIN
  IF n = MIN(INT64) THEN s := "8085774586302733229"; k := 19;
  ELSE
    i1 := ABS(n);
    s[0] := CHR(i1 MOD 10 + ORD("0")); i1 := i1 DIV 10; k := 1;
    WHILE i1 > 0 DO
      s[k] := CHR(SHORT(i1) MOD 10 + ORD("0")); i1 := i1 DIV 10; INC(k);
    END;
  END;
  IF n < 0 THEN s[k] := "-"; INC(k) END;
  WHILE k > 0 DO DEC(k); WriteCh(s[k]) END;
END WriteLong;

PROCEDURE WriteStr* (str: ARRAY OF CHAR);
VAR
  maxLen: INT32;
BEGIN
  Ignore.Int(
    w.WriteFile(hConOutput, SYSTEM.ADR(str), Strings.Length(str), @maxLen, @NIL)
  );
END WriteStr;

PROCEDURE Ten (n: INT32): REAL64;
  VAR t, p: REAL64;
BEGIN t := 1.0; p := 10.0;   (*compute 10^n *)
  WHILE n > 0 DO
    IF ODD(n) THEN t := p * t END;
    p := p*p; n := n DIV 2
  END;
  RETURN t
END Ten;

PROCEDURE IsNaN (x: REAL64): BOOLEAN;  (* by Robert D. Campbell *)
  CONST nanS = {19..30};  (* Detects non-signalling NaNs *)
BEGIN
  RETURN nanS - BITS(SHORT(ASH(SYSTEM.VAL(INT64, x), -32))) = {}
END IsNaN;

PROCEDURE Exponent (x: REAL64): INT32;
  CONST ExpoMax = 1023;
  VAR exp, offset: INT32;
BEGIN
  x := ABS(x);
  exp := SHORT(ASH(SYSTEM.VAL(INT64, x), -52));
  offset := ExpoMax;
  WHILE exp = 0 DO
    x := x + x; exp := SHORT(ASH(SYSTEM.VAL(INT64, x), -52)); INC(offset)
  END;
  RETURN exp - offset
END Exponent;

PROCEDURE WriteReal* (x: REAL64);
  VAR m: INT64; e, i: INT32; d: ARRAY 16 OF CHAR;
BEGIN
  e := SHORT(ASH(SYSTEM.VAL(INT64, x), -52)) MOD 800H;  (*binary exponent*)
  IF e = 0 THEN WriteCh("0")
  ELSIF IsNaN(x) THEN WriteStr("NaN")
  ELSE
    (* 2 < n < 9 digits to be written *)
    IF x < 0.0 THEN WriteCh("-"); x := -x END;
    e := Exponent(x) * 77 DIV 256 - 12;  (* decimal exponent *)
    IF e >= 0 THEN x := x / Ten(e);
    ELSIF e < -308 THEN x := x * Ten(-e-12) * 1.0D+12;
    ELSE x := Ten(-e) * x;
    END;
    m := ENTIER(x + 0.5); i := 0;
    IF m >= 10000000000000 THEN INC(e); m := m DIV 10 END;
    REPEAT d[i] := CHR(m MOD 10 + 30H); m := m DIV 10; INC(i) UNTIL m = 0;
    DEC(i); WriteCh(d[i]); WriteCh(".");
    WHILE i > 0 DO DEC(i); WriteCh(d[i]) END;
    INC(e, 12);
    IF e # 0 THEN WriteCh("E");
      IF e > 0 THEN WriteCh("+") END;
      WriteInt(e);
    END;
  END;
END WriteReal;

PROCEDURE WriteRealFix* (x: REAL64; n: INT32);
  VAR m: INT64;
BEGIN
  IF x = 0.0 THEN WriteCh("0")
  ELSE
    IF (n < 1) OR (n > 16) THEN n := 16 END;
    IF x < 0.0 THEN x := -x; WriteCh("-") END;
    m := ENTIER(x);
    WriteLong(m); WriteCh(".");
    x := Ten(n) * (x - m);
    m := ENTIER(x + 0.5);
    WHILE (m # 0) & (m MOD 10 = 0) DO m := m DIV 10 END;
    WriteLong(m);
  END;
END WriteRealFix;

BEGIN
  hConOutput := w.GetStdHandle(-11);
END ConsoleWinApi.
