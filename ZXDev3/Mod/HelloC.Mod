(* Tiny "HelloWorld" Demo for ZX Spectrum 48K *)
(* Copyright (C) 2017 Oleg N. Cher, VEDAsoft. *)

(*$MAIN*) MODULE HelloC; IMPORT Basic;
BEGIN
  Basic.BORDER(3);
  Basic.COLOR(4); Basic.PRSTR("Hello ");
  Basic.COLOR(5); Basic.PRSTR("Hello ");
  Basic.COLOR(6); Basic.PRSTR("Hello ");
END HelloC.
