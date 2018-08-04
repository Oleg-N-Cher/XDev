MODULE ConsoleWinAPI;
IMPORT SYSTEM, w := WinAPI, Strings, Ignore;

VAR
  hConOutput: w.HANDLE;

PROCEDURE SetColors* (colors: SHORTINT);
BEGIN
  Ignore.Int( w.SetConsoleTextAttribute(hConOutput, colors) );
END SetColors;

PROCEDURE WriteCh* (ch: CHAR);
VAR
  maxLen: INTEGER;
BEGIN
  Ignore.Int( w.WriteFile(hConOutput, SYSTEM.ADR(ch), 1, maxLen, NIL) );
END WriteCh;

PROCEDURE WriteLn* ;
BEGIN
  WriteCh(0DX); WriteCh(0AX);
END WriteLn;

PROCEDURE WriteInt* (n: INTEGER);
VAR
  s: ARRAY 11 OF CHAR; i1, k: INTEGER;
BEGIN
  IF n = SYSTEM.LSH(SYSTEM.VAL(INTEGER, 1), SIZE(INTEGER)*8 - 1) THEN
    s := "8463847412"; k := 10;
  ELSE
    i1 := ABS(n);
    s[0] := CHR(i1 MOD 10 + ORD("0")); i1 := i1 DIV 10; k := 1;
    WHILE i1 > 0 DO s[k] := CHR(i1 MOD 10 + ORD("0")); i1 := i1 DIV 10; INC(k) END
  END;
  IF n < 0 THEN s[k] := "-"; INC(k) END;
  WHILE k > 0 DO DEC(k); WriteCh(s[k]) END;
END WriteInt;

PROCEDURE WriteStr* (str: ARRAY OF CHAR);
VAR
  maxLen: INTEGER;
BEGIN
  Ignore.Int(
    w.WriteFile(hConOutput, SYSTEM.ADR(str), Strings.Length(str), maxLen, NIL)
  );
END WriteStr;

BEGIN
  hConOutput := w.GetStdHandle(-11);
END ConsoleWinAPI.
