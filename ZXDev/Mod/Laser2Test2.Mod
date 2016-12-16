MODULE Laser2Test2;

(*  Laser Basic 2 Demo for Sinclair ZX Spectrum, 48 Kb.  *)
(* Copyright (C) 2016 Oleg N. Cher, VEDAsoft Oberon club *)

IMPORT gr := Laser2, B := Basic;

TYPE
  Sprite2X2 = ARRAY 5 + 4*8 + 4 OF CHAR;

CONST
  CopperFeet = Sprite2X2 (
    1X, CHR( 8*4 + 4 + 3 ), 0X, 2X, 2X,
    060X,080X,08AX,08AX,08AX,066X,000X,000X,
    006X,00FX,00FX,076X,0F0X,0FBX,0FBX,0FCX,
    039X,07FX,07FX,07FX,07FX,03EX,018X,000X,
    0FDX,0FBX,0F8X,0F6X,0E0X,000X,000X,000X,
    047X,042X,042X,042X
  );

BEGIN (*$MAIN*)
  B.Init;
  gr.SPRTa(CopperFeet);
  B.BORDER(B.Black); B.PAPER(B.Black); B.INK(B.Yellow); B.CLS;
  gr.PTBL(5, 5, 1); gr.PTNV(10, 5, 1);
  B.PAUSE(0); B.Quit;
END Laser2Test2.
