(* How to work with unsigned numbers in ZXDev/Oberon *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE Unsigned; (*$MAIN*)
IMPORT SYSTEM, P := Platform, B := Basic;

VAR
	byte: (* UNSIGNED*) SHORTINT; (* 0..255 *)

BEGIN
	B.Init;
	B.PAPER(B.Black); B.INK(B.Cyan); B.BORDER(B.Black); B.CLS;
	byte := P.Unsigned(150);
	REPEAT (* Print numbers 150 to 61 *)
		B.PRWORD(ORD(CHR(byte))); B.PRCHAR(" "); DEC(byte);
	UNTIL byte = 60;
	B.INK(B.Green);
	byte := P.Unsigned(-1);
	B.PRWORD(ORD(CHR(byte))); B.PRCHAR(" "); (* Print Unsigned(-1) as byte *)
	B.PRWORD(P.Unsigned(-1)); (* Print Unsigned(-1) as word *)
	B.Quit
END Unsigned.