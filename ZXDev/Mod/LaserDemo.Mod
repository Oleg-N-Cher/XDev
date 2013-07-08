MODULE LaserDemo;

(* Laser Basic Demo for Sinclair ZX Spectrum, 48 Kb.  *)
(* Copyright (C) 2012 Oleg N. Cher, VEDANTA software. *)

IMPORT L := Laser, B := Basic, Rsrc := LaserSprite2B;

(* Пример взят из книги "Как написать игру для ZX Spectrum" *)

(*
10 BORDER 0: PAPER 0:INK 5
20 CLS: LET S=-2
30 FOR N=7 TO 10
40 .R0W=5:.C0L=S:.SPN=N
50 .PTBL
60 PAUSE 5
70 NEXT N
80 LET S=S+2
90 IF S<32 THEN GO TO 30
*)

PROCEDURE Main* ;
VAR
	n, s: SHORTINT;
BEGIN
	B.Init; L.InitSprites(Rsrc.SprStart, Rsrc.SprSize);
	B.BORDER(B.Black); B.PAPER(B.Black); B.CLS;
	FOR s := -2 TO 30 BY 2 DO
		FOR n := 7 TO 10 DO L.PTBL(s, 5, n); B.PAUSE(5) END;
	END;
	B.Quit;
END Main;

END LaserDemo.