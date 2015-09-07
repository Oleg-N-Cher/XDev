(*$MAIN*) MODULE Fill; IMPORT b := Basic, Gfx;
BEGIN b.Init;
  b.INK(b.Black); b.PAPER(b.White); b.BORDER(b.White); b.CLS;
  b.PLOT(0, 0); b.DRAW(255, 0); b.PLOT(128, 0); b.DRAW(0, 175);
  b.CIRCLE(60, 88, 60); b.CIRCLE(194, 88, 60);
  Gfx.Fill(1, 1, b.Blue);
(*
    SO  PRINT   USR  L,1,1,1:   PRINT  US
R   L,255,1,2
    SO  PRUSE   100
    70  CLS   :   CIRCLE  128,88,87
    SO  PRINT   USR  L , 128 ,2,4
  100  PRUSE   O:   STOP
*)
b.Quit END Fill.
