MODULE TestSaveRegs3; (*$MAIN*)
IMPORT b := Basic, d := Debug;
BEGIN
  b.Init; b.CLS; b.AT(1, 0);

  b.COLOR(b.Yellow); (*b.PRSTR("AT_FAST ");*)
  d.SaveRegsDef; b.AT(4, 9); d.CheckRegs;
(*
  Basic.BEEP(1000, 1); Basic.BEEP(1000, -1);
*)
  b.Quit
END TestSaveRegs3.
