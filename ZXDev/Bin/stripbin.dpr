{$APPTYPE CONSOLE}
PROGRAM stripbin;

USES Windows, KOL;

{$R *.RES}
CONST
  PODRYAD = 3;
VAR
  bin: AnsiString;
  binLen, i, idx, ff: INTEGER; lastByte: CHAR;
BEGIN
  bin := StrLoadFromFile(ParamStr(1));
  binLen := LENGTH(bin);
  lastByte := bin[binLen]; IF NOT (lastByte IN [#$1A, #$FF]) THEN lastByte := #$FF;
  idx := binLen;
  ff := 0;
  FOR i := binLen DOWNTO 1 DO BEGIN
    idx := i;
    IF bin[i] = lastByte THEN
      INC(ff)
    ELSE
      ff := 0;
    IF ff = PODRYAD THEN BREAK
  END;
  FOR i := idx DOWNTO 1 DO BEGIN
    IF bin[i] <> lastByte THEN BEGIN idx := i; BREAK END
  END;
  WriteLn('New size is ', idx);
  WriteLn('You win ', binLen - idx, ' bytes');
  DELETE(bin, idx + 1, binLen);
  StrSaveToFile(ParamStr(1), bin)
END {stripbin}.
