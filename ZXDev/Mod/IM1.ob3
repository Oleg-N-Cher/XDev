MODULE IM1;
IMPORT B := Basic, SysVar;
BEGIN (*$MAIN*)
  B.Init;
  SysVar.LAST_K := 0; B.AT(0, 0); B.PRSTR("Press SPACE to exit");
  REPEAT
    B.AT(4, 4); B.PRINT(SysVar.LAST_K); B.PRSTR("   ");
    B.AT(8, 8); B.PRINT(SysVar.FRAMES[0]); B.PRSTR("   ");
  UNTIL SysVar.LAST_K = 20H;
  B.Quit;
END IM1.