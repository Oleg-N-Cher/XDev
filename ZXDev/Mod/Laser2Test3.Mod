MODULE Laser2Test3;

(*  Laser Basic 2 Test for Sinclair ZX Spectrum, 48 Kb.  *)
(* Copyright (C) 2016 Oleg N. Cher, VEDAsoft Oberon club *)
(*      http://zxpress.su/book_articles.php?id=1026      *)

IMPORT gr := Laser2, b := Basic;

VAR
  m, n, col, row, len, hgt: SHORTINT;

BEGIN (*$MAIN*)
  b.Init;
  b.INK(5); b.PAPER(0); b.BORDER(0); b.CLS;
  FOR n := 7 TO 1 BY -1 DO
    m := 7 - n;
    row := 5 + n; col := 2 + 2*n;
    hgt := 2 + 2*m; len := 1 + 4*m;
    b.POKE(23693, 8*n + 64);
    gr.CLSV(col, row, len, hgt); gr.SETV(col, row, len, hgt);
    b.PAUSE(5);
  END;
  b.Quit;
END Laser2Test3.
