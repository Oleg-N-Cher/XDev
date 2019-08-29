MODULE TestSave;
IMPORT b := Basic, m := Mem128;

BEGIN (*$MAIN*)
  b.Init;
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
  IF m.IsTRDOS() THEN
    m.SaveDisk("Castle2 C", 4000H, 6912)
  ELSE
    m.SaveTape("Castle2", 4000H, 6912)
  END;
  b.Quit
END TestSave.
