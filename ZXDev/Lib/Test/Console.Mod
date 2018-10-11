MODULE ConsoleDemo; (*$MAIN*)
IMPORT IO := Console, P := Platform, Asm;

BEGIN
  IO.Clear(IO.Black);
  IO.SetColors(IO.GreenOnBlack);
  IO.WriteUInt(0); IO.WriteLn;
  IO.WriteUInt(10); IO.WriteLn;
  IO.WriteUInt(555); IO.WriteLn;
  IO.WriteUInt(9999); IO.WriteLn;
  IO.WriteUInt(32767); IO.WriteLn;
  IO.WriteUInt(P.ToSHORT(65535)); IO.WriteLn;

  IO.WriteInt(0); IO.WriteLn;
  IO.WriteInt(10); IO.WriteLn;
  IO.WriteInt(500); IO.WriteLn;
  IO.WriteInt(9000); IO.WriteLn;
  IO.WriteInt(30000); IO.WriteLn;
  IO.WriteInt(-10); IO.WriteLn;
  IO.WriteInt(-555); IO.WriteLn;
  IO.WriteInt(-9999); IO.WriteLn;
  IO.WriteInt(-32767); IO.WriteLn;
  IO.WriteInt(-32768); IO.WriteLn;

  Asm.Code("LD HL,#10072"); Asm.Code("EXX");

END ConsoleDemo.
