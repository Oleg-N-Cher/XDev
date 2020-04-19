MODULE BasicRegs3; (*$MAIN*)
IMPORT b := Basic, d := Debug;
BEGIN
  b.Init; b.CLS;

  b.COLOR(b.Yellow);  b.AT(0, 8); b.PRSTR("AT_FAST_fastcall");
  d.SaveRegsDef; b.AT(4, 10); d.CheckRegs;
(*
  Basic.BEEP(1000, 1); Basic.BEEP(1000, -1);
*)
  b.COLOR(b.Yellow); b.AT(1, 11); b.PRSTR("INVERSE_FAST");
  d.SaveRegsDef; b.INVERSE(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(2, 11); b.PRSTR("OVER_FAST");
  d.SaveRegsDef; b.OVER(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(3, 4); b.PRSTR("PRCHAR_FAST");
  d.SaveRegsDef; b.PRCHAR(90X); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(4, 4); b.PRSTR("PRDATA_FAST");
  d.SaveRegsDef; b.PRDATA; b.DATACH2(90X, 0X); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(5, 4); b.PRSTR("PRINT_FAST "); b.COLOR(b.Cyan);
  d.SaveRegsDef; b.PRINT(-12345); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(6, 12); b.PRSTR("PRLN_FAST");
  d.SaveRegsDef; b.PRLN; d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(7, 6);
  d.SaveRegsDef; b.PRSTR("PRSTR_FAST"); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(8, 4); b.PRSTR("PRWORD_FAST "); b.COLOR(b.Cyan);
  d.SaveRegsDef; b.PRWORD(12345); d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(9, 14); b.PRSTR("SGN");
  d.SaveRegsDef; IF b.SGN(-1) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(10, 12); b.PRSTR("SGNI");
  d.SaveRegsDef; IF b.SGNI(-1) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(11, 1); b.PRSTR("RND");
  d.SaveRegsDef; IF b.RND(1, 2) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.AT(12, 1); b.PRSTR("RNDW");
  d.SaveRegsDef; IF b.RNDW(1, 2) = 0 THEN END; d.CheckRegs;

  b.Quit
END BasicRegs3.
