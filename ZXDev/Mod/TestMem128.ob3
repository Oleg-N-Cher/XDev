MODULE TestMem128;
IMPORT b := Basic, m := Mem128;

BEGIN (*$MAIN*)
  b.Init;
  m.Page(0); b.POKE(65535, 10);
  m.Page(1); b.POKE(65535, 100);
  m.Page(2); b.POKE(65535, 200);
  m.Page(0); b.PRSTR("[0] = "); b.PRINT(b.PEEK(65535)); b.PRLN;
  m.Page(1); b.PRSTR("[1] = "); b.PRINT(b.PEEK(65535)); b.PRLN;
  m.Page(2); b.PRSTR("[2] = "); b.PRINT(b.PEEK(65535)); b.PRLN;
  b.Quit
END TestMem128.
