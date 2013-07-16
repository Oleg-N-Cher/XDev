MODULE FilesTest;

IMPORT Files;

VAR
  file: Files.FileToWrite;

BEGIN (*$MAIN*)
  file.OpenToWrite("Privet.txt");
  file.WriteStr("Privet Yulia!");
  file.Close;
END FilesTest.