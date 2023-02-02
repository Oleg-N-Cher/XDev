MODULE BrightLetters; (*$MAIN*)
IMPORT b := Basic, c := Asm;

BEGIN
  b.Init;
  b.INK(0); b.PAPER(0); b.BORDER(0); b.CLS;
  b.AT(0, 0); b.PRSTR(" FLASH (C) AZH soft 1996");
  b.Quit;
  c.Code("     LD   A, #6      "); (* Конечный INC *)
  c.Code("     LD   HL, #22528 "); (* Адрес в файле атрибутов *)
  c.Code("                     "); (* для нулевой строки экрана *)
  c.Code("     LD   B, #32     "); (* 32 символа в строке *)
  c.Code("L1$: PUSH AF         ");
  c.Code("L2$: INC  (HL)       ");
  c.Code("     DEC  A          ");
  c.Code("     HALT            ");
  c.Code("     JR   NZ, L2$    ");
  c.Code("     POP  AF         ");
  c.Code("     INC  HL         ");
  c.Code("     DJNZ L1$        ");
END BrightLetters.
