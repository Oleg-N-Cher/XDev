MODULE TrDosTest; IMPORT TrDos, Console;

VAR
  code: TrDos.UCHAR;

BEGIN (*$MAIN*)
  code := TrDos.FindFile("file1", 5X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

  code := TrDos.FindFile("boot", 4X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

  code := TrDos.FindFile("Das2", 4X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

  code := TrDos.FindFile("Dash", 4X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

END TrDosTest.