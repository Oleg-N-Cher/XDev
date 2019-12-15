MODULE TestOut6x8; (*$MAIN*)
IMPORT SYSTEM, C := Out6x8, B := Basic;

VAR
  n: BYTE; font: ARRAY 96 (*chars*) * 8 (* bytes *) OF BYTE;
BEGIN
  B.Init; B.CLS;
  C.GenFont(SYSTEM.ADR(font));
  C.font := SYSTEM.ADR(font) - 100H;
  C.At(0, 19); FOR n := 32-1 TO 127-1 DO C.Ch(CHR(n+1)) END;
  FOR n := 0 TO 17 DO C.At(n, n); C.Str("Hello, Yprit !!!") END;
  B.Quit
END TestOut6x8.
