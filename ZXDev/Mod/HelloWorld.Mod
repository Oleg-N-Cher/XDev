MODULE HelloWorld;

(* "HelloWorld" Demo for Sinclair ZX Spectrum, 48 Kb. *)
(* Copyright (C) 2012 Oleg N. Cher, VEDANTA software. *)

IMPORT B := Basic;

VAR
	x: INTEGER;
BEGIN (*$MAIN*)
	B.Init;
	B.BORDER(B.Green); B.PAPER(B.Black); B.CLS;
	FOR x := 0 TO 245 BY 2 DO
		B.INK(B.Yellow); B.PLOT(x, 127); B.DRAW(10, 10);
		B.INK(B.Magenta); B.PLOT(x, 37); B.DRAW(10, 10);
	END;
	B.AT(11, 1); B.PAPER(B.Blue); B.INK(B.Cyan);
	B.BRIGHT(B.On); B.FLASH(B.On);
	B.PRSTR(" HELLO WORLD of ZX Spectrum ! "); B.FLASH(B.Off);
	B.PAUSE(B.WaitAKey);
	B.Quit;
END HelloWorld.