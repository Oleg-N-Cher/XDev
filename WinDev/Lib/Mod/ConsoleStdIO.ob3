MODULE ConsoleStdIO;
IMPORT SYSTEM;

PROCEDURE -AAAincludestdio "#include <stdio.h>";
PROCEDURE -printfc (ch: CHAR) 'printf("%c", ch)';
PROCEDURE -printfi (n: INTEGER) 'printf("%d", n);';
PROCEDURE -printfli (l: INT64) 'printf("%lld", l)';
PROCEDURE -printfr (r: SYSTEM.REAL64) 'printf("%.7g", r)';
PROCEDURE -printfs (str: ARRAY OF CHAR) 'printf("%s", str)';
PROCEDURE -printfln 'printf("\n")';

PROCEDURE WriteCh* (ch: CHAR);
BEGIN
  printfc(ch);
END WriteCh;

PROCEDURE WriteInt* (n: INTEGER);
BEGIN
  printfi(n);
END WriteInt;

PROCEDURE WriteLong* (n: INT64);
BEGIN
  printfli(n);
END WriteLong;

PROCEDURE WriteLn* ;
BEGIN
  printfln;
END WriteLn;

PROCEDURE WriteStr* (str: ARRAY OF CHAR);
BEGIN
  printfs(str);
END WriteStr;

PROCEDURE Ten (n: INTEGER): REAL;
  VAR t, p: REAL;
BEGIN t := 1.0; p := 10.0;   (*compute 10^n *)
  WHILE n > 0 DO
    IF ODD(n) THEN t := p * t END;
    p := p*p; n := n DIV 2
  END;
  RETURN t
END Ten;

PROCEDURE WriteReal* (x: REAL);
BEGIN
  printfr(x);
END WriteReal;

PROCEDURE WriteRealFix* (x: REAL; n: INTEGER);
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

END ConsoleStdIO.
