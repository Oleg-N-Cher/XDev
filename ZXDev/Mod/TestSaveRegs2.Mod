MODULE TestSaveRegs2; (*$MAIN*)
IMPORT b := Basic, d := Debug;
BEGIN
  b.Init; b.CLS; b.AT(1, 0);

  b.COLOR(b.Yellow); b.PRSTR("AT_ROM_fastcall ");
  d.SaveRegsDef; b.AT(1, 16); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("ATTR_fastcall ");
  d.SaveRegsDef; IF b.ATTR(1, 15) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BEEP_EI ");
  d.SaveRegsDef; b.BEEP(10, 1); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BORDER ");
  d.SaveRegsDef; b.BORDER(3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PLOT_fastcall ");
  d.SaveRegsDef; b.PLOT(255, 175); d.CheckRegs;

  b.Quit
END TestSaveRegs2.
