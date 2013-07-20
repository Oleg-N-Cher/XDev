(* Cross-platform "HelloWorld" Demo for ZX Spectrum 48K *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE TestRnd; (*$MAIN*)
IMPORT C := Console, Math;

VAR
  i: INTEGER;
BEGIN
  FOR i := 1 TO 500 DO
    C.WriteInt(Math.RndRange(-3, 3)); C.WriteStr("  ");
  END;
END TestRnd.
