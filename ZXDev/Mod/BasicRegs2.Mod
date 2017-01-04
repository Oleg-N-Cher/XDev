MODULE BasicRegs2; (*$MAIN*)
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

  b.COLOR(b.Yellow); b.PRSTR("CIRCLEW_EI ");
  d.SaveRegsDef; b.CIRCLEW(250, 170, 5); d.CheckRegs;

  (*b.COLOR(b.Yellow); b.PRSTR("CLS_FULLSCREEN ");
  d.SaveRegsDef; b.CLS; d.CheckRegs;*)

  b.COLOR(b.Yellow); b.PRSTR("DRAW_fastcall "); b.PLOT(0, 0);
  d.SaveRegsDef; b.DRAW(3, 3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PLOT_fastcall ");
  d.SaveRegsDef; b.PLOT(255, 175); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("POINT_fastcall ");
  d.SaveRegsDef; IF b.POINT(0, 0) THEN END; d.CheckRegs;

  b.Quit
END BasicRegs2.
