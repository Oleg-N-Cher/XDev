MODULE TestSaveRegs1; (*$MAIN*)
IMPORT b := Basic, d := Debug;
BEGIN
  b.Init; b.CLS; b.AT(0, 0);

  b.COLOR(b.Yellow); b.PRSTR("AT_ROM_stdcall ");
  d.SaveRegsDef; b.AT(0, 15); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("ATTR ");
  d.SaveRegsDef; IF b.ATTR(1, 15) = 0 THEN END; d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BEEP_DI ");
  d.SaveRegsDef; b.BEEP(10, 1); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BORDER_z88dk_fast ");
  d.SaveRegsDef; b.BORDER(3); d.CheckRegs;

  b.COLOR(b.Yellow); b.PRSTR("BRIGHT ");
  d.SaveRegsDef; b.BRIGHT(1); d.CheckRegs;

  b.Quit
END TestSaveRegs1.
