MODULE TestMem128;
IMPORT b := Basic, m := Mem128;

BEGIN (*$MAIN*)
  b.Init;
(*
  m.Page(0); b.POKE(65535, 10);
  m.Page(1); b.POKE(65535, 100);
  m.Page(2); b.POKE(65535, 200);
  m.Page(0); b.PRSTR("[0] = "); b.PRINT(b.PEEK(65535)); b.PRLN;
  m.Page(1); b.PRSTR("[1] = "); b.PRINT(b.PEEK(65535)); b.PRLN;
  m.Page(2); b.PRSTR("[2] = "); b.PRINT(b.PEEK(65535)); b.PRLN;
*)
  IF m.IsTRDOS() THEN
    IF m.LoadDisk("Castle  C", 4000H) THEN
      b.PRSTR("DISK O.K. Size = "); b.PRINT(m.filesize)
    ELSE
      b.PRSTR("No file")
    END
  ELSE
    CASE m.LoadTape("Castle", 4000H) OF
    | m.ErrTapeLoading, m.ErrLoadingHeader: b.PRSTR("Tape loading error")
    | m.ErrNameNotMatch: b.PRSTR("File name not match")
    | m.ErrBreakPressed: b.PRSTR("Break")
    ELSE
      b.PRSTR("TAPE O.K. Size = "); b.PRINT(m.filesize)
    END
  END;
  b.PAUSE(0);
  b.Quit
END TestMem128.
