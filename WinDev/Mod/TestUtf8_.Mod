MODULE TestUtf8; (*$MAIN*)
IMPORT io:=Console, Strings, Files;

VAR
  str: ARRAY 100 OF CHAR;
  utfstr: ARRAY 3 OF CHAR;
  stringfile: Files.FileToRead; 

BEGIN
  stringfile.OpenToRead("TestUtf8.txt");
  stringfile.ReadStr(str);
  stringfile.Close;
  IF Strings.Win1251ToUtf8(str, utfstr) THEN
    io.WriteStr("Ok ");
  ELSE
    io.WriteStr("Err ");
  END;
  io.WriteStr(utfstr);
END TestUtf8.
