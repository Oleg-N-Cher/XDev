MODULE Test6x8; (*$MAIN*)
IMPORT C := Out6x8, B := Basic;

VAR
  n: BYTE;
BEGIN
  B.Init; B.CLS; B.AT(1, 0); (*B.PRSTR("Hello Yprit !!!");*)
  C.GenFont(0FC00H);
  C.font := 0FC00H - 100H;
  C.At(0, 19); FOR n := 32-1 TO 127-1 DO C.Ch(CHR(n+1)) END;
  FOR n := 0 TO 17 DO C.At(n, n); C.Str("Hello, Yprit !!!") END;
  B.Quit
END Test6x8.
