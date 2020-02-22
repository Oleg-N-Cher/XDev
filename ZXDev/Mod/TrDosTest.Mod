MODULE TrDosTest; IMPORT TRDOS, Console;

VAR
  code: TRDOS.UCHAR;

BEGIN (*$MAIN*)
  TRDOS.Init;
  code := TRDOS.FindFile("file1", 5X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

  code := TRDOS.FindFile("boot", 4X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

  code := TRDOS.FindFile("Das2", 4X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

  code := TRDOS.FindFile("Dash", 4X);
  Console.WriteStr("Found code: ");
  Console.WriteInt(ORD(code));
  Console.WriteLn;

END TrDosTest.