MODULE Laser2Test;

(*  Laser Basic 2 Demo for Sinclair ZX Spectrum, 48 Kb.  *)
(* Copyright (C) 2016 Oleg N. Cher, VEDAsoft Oberon club *)

IMPORT L := Laser2, B := Basic;

TYPE
  Sprite1X1 = ARRAY 14 OF CHAR;

CONST
  BluePearl = Sprite1X1
    (1X, CHR(8 + 1 + 3), 0X, 1X, 1X,
     04FX,
     0E7X, 081X, 0B1X, 020X, 000X, 081X, 081X, 0E7X
    );

BEGIN (*$MAIN*)
  B.Init;
  L.InitSpritesAr(BluePearl);

  B.BORDER(B.Black); B.PAPER(B.Black); B.INK(B.Yellow); B.CLS;
  L.PTBL(5, 5, 1); L.PTBL(5, 6, 1); L.PTBL(6, 5, 1);
  L.ATOF;
  L.PTBL(15, 5, 1); L.PTBL(15, 6, 1); L.PTBL(16, 5, 1);
  L.ATON;
  L.PTBL(25, 5, 1); L.PTBL(25, 6, 1); L.PTBL(26, 5, 1);
  B.PAUSE(0);
  B.Quit;
END Laser2Test.
