MODULE TestSaveRegs1; (*$MAIN*)
IMPORT b := Basic, d := Debug;
BEGIN
  b.Init; b.CLS; b.AT(0, 0);

  b.COLOR(b.Yellow); b.PRSTR("AT_ROM_callee ");
  d.SaveRegsDef; b.AT(0, 14); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("ATTR_callee ");
  d.SaveRegsDef; IF b.ATTR(1, 15) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BEEP_DI ");
  d.SaveRegsDef; b.BEEP(10, 1); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BORDER_fastcall ");
  d.SaveRegsDef; b.BORDER(3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BRIGHT ");
  d.SaveRegsDef; b.BRIGHT(1); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PLOT_callee ");
  d.SaveRegsDef; b.PLOT(255, 175); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PORTIN ");
  d.SaveRegsDef; IF b.PORTIN(254) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PORTOUT ");
  d.SaveRegsDef; b.PORTOUT(254, 0); d.CheckRegs;

  b.Quit
END TestSaveRegs1.
