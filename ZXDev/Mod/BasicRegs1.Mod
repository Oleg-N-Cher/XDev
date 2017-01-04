MODULE BasicRegs1; (*$MAIN*)
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
  d.SaveRegsDef; b.BORDER(b.Black); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BRIGHT ");
  d.SaveRegsDef; b.BRIGHT(1); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("CIRCLE ");
  d.SaveRegsDef; b.CIRCLE(250, 170, 3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("CIRCLEROM ");
  d.SaveRegsDef; b.CIRCLEROM(236, 170, 3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("CIRCLEW_DI ");
  d.SaveRegsDef; b.CIRCLEW(250, 170, 5); d.CheckRegs;

  (*b.COLOR(b.Yellow); b.PRSTR("CLS_ZX ");
  d.SaveRegsDef; b.CLS; d.CheckRegs;*)

  b.COLOR(b.Yellow); b.PRSTR("COLOR ");
  d.SaveRegsDef; b.COLOR(b.Yellow); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("DRAW_callee "); b.PLOT(0, 0);
  d.SaveRegsDef; b.DRAW(3, 3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("FLASH ");
  d.SaveRegsDef; b.FLASH(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("INK ");
  d.SaveRegsDef; b.INK(b.Yellow); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("INKEY ");
  d.SaveRegsDef; IF b.INKEY() = 0X THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("INVERSE_ROM ");
  d.SaveRegsDef; b.INVERSE(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("OVER_ROM ");
  d.SaveRegsDef; b.OVER(b.Off); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PAINT ");
  d.SaveRegsDef; b.PAINT(236, 186, b.Red); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PAPER ");
  d.SaveRegsDef; b.PAPER(b.Black); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PAUSE ");
  d.SaveRegsDef; b.PAUSE(1); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PLOT_callee ");
  d.SaveRegsDef; b.PLOT(255, 175); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("POINT_callee ");
  d.SaveRegsDef; IF b.POINT(0, 0) THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PORTIN ");
  d.SaveRegsDef; IF b.PORTIN(254) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("PORTOUT ");
  d.SaveRegsDef; b.PORTOUT(254, 0); d.CheckRegs;

  b.Quit
END BasicRegs1.
