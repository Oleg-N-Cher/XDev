(* Cross-platform "HelloWorld" Demo for ZX Spectrum 48K *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE XDevHello; (*$MAIN*)
IMPORT C := Console;

BEGIN
	C.SetColors(C.LCyanOnBlue); C.Clear(C.Black);
	C.WriteStr("Hello Cross-platform World");
END XDevHello.
