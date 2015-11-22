MODULE TestUTF8; (*$MAIN*)
IMPORT io:=Console, Strings, Files;

VAR
  str: ARRAY 100 OF CHAR;
  utfstr: ARRAY 300 OF CHAR;
  stringfile: Files.FileToRead; 

BEGIN
  stringfile.OpenToRead("TestUTF8.txt");
  stringfile.ReadStr(str);
  stringfile.Close;
  IF Strings.CP1251ToUtf8(str, utfstr) THEN io.WriteStr(utfstr) END;
END TestUTF8.
