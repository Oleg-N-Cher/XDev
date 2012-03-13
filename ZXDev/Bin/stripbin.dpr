{$APPTYPE CONSOLE}
PROGRAM stripbin;

USES Windows, KOL;

{$R *.RES}
CONST
  PODRYAD = 16;
VAR
  bin: AnsiString;
  binLen, i, idx, ff: INTEGER;
BEGIN
  bin := StrLoadFromFile(ParamStr(1));
  binLen := LENGTH(bin);
  idx := binLen;
  ff := 0;
  FOR i := binLen DOWNTO 1 DO BEGIN
    idx := i;
    IF ORD(bin[i]) = 255 THEN
      INC(ff)
    ELSE
      ff := 0;
    IF ff = PODRYAD THEN BREAK
  END;
  FOR i := idx DOWNTO 1 DO BEGIN
    IF ORD(bin[i]) <> 255 THEN BEGIN idx := i; BREAK END
  END;
  WriteLn('New size is ', idx);
  WriteLn('You win ', binLen - idx, ' bytes');
  DELETE(bin, idx + 1, binLen);
  StrSaveToFile(ParamStr(1), bin)
END.
