MODULE TestSave;
IMPORT b := Basic, f := Files, TRDOS;

BEGIN (*$MAIN*)
  b.Init;
  IF TRDOS.IsDisk() THEN
    IF f.LoadDisk("Castle  C", 4000H) THEN
      b.PRSTR("DISK O.K. Size = "); b.PRINT(f.filesize)
    ELSE
      b.PRSTR("No file")
    END
  ELSE
    CASE f.LoadTape("Castle", 4000H) OF
    | f.ErrTapeLoading, f.ErrLoadingHeader: b.PRSTR("Tape loading error")
    | f.ErrNameNotMatch: b.PRSTR("File name not match")
    | f.ErrBreakPressed: b.PRSTR("Break")
    ELSE
      b.PRSTR("TAPE O.K. Size = "); b.PRINT(f.filesize)
    END
  END;
  b.PAUSE(0);
  IF TRDOS.IsDisk() THEN
    f.SaveDisk("Castle2 C", 4000H, 6912)
  ELSE
    f.SaveTape("Castle2", 4000H, 6912)
  END;
  b.Quit
END TestSave.
