(* How to work with unsigned numbers in ZXDev/Oberon *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE Unsigned; (*$MAIN*)
IMPORT SYSTEM, P := Platform, B := Basic;

TYPE
	BYTE = (* UNSIGNED*) SHORTINT;
VAR
	byte: BYTE; (* 0..255 *)

BEGIN
	B.PAPER(B.Black); B.INK(B.Blue); B.BRIGHT(B.On);
	byte := P.Unsigned(150);
	REPEAT
		B.PRWORD(byte); B.PRCHAR(" "); DEC(byte); (* Print numbers 150 to 61 *)
	UNTIL byte = 60;
	B.INK(B.Cyan); B.BRIGHT(B.Off);
	FOR byte := 60 TO P.Unsigned(150) DO
		B.PRWORD(byte); B.PRCHAR(" "); (* Print numbers 60 to 150 *)
	END;
	B.INK(B.Green);
	byte := P.Unsigned(-1);
	B.PRWORD(byte); B.PRCHAR(" "); (* Print Unsigned(-1) as byte *)
	B.PRWORD(P.Unsigned(-1)); (* Print Unsigned(-1) as word *)
END Unsigned.