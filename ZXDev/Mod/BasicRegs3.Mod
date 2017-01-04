MODULE BasicRegs3; (*$MAIN*)
IMPORT b := Basic, d := Debug;
BEGIN
  b.Init; b.CLS; b.AT(1, 0);

  b.COLOR(b.Yellow);  b.AT(0, 7); b.PRSTR("AT_FAST_fastcall");
  d.SaveRegsDef; b.AT(4, 9); d.CheckRegs;
(*
  Basic.BEEP(1000, 1); Basic.BEEP(1000, -1);
*)
  b.COLOR(b.Yellow); b.AT(1, 10); b.PRSTR("INVERSE_FAST");
  d.SaveRegsDef; b.INVERSE(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(2, 10); b.PRSTR("OVER_FAST");
  d.SaveRegsDef; b.OVER(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(3, 3); b.PRSTR("PRCHAR_FAST");
  d.SaveRegsDef; b.PRCHAR(90X); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(4, 3); b.PRSTR("  PRDATA_FAST");
  d.SaveRegsDef; b.PRDATA; b.DATACH2(90X, 0X); d.CheckRegs;

  b.Quit
END BasicRegs3.
