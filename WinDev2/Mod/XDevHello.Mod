(* Cross-platform "HelloWorld" Demo for MS Windows x86 & x64 *)

MODULE XDevHello; (*$MAIN*)
IMPORT C := Console;

BEGIN
  C.SetColors(C.LCyanOnBlue);
  C.WriteStr("Hello Cross-platform World");
  C.SetColors(C.WhiteOnBlack);
END XDevHello.
