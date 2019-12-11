MODULE TestInput; (*$MAIN*)
IMPORT io := Console;

VAR
  name: ARRAY 32 OF CHAR;
BEGIN
  io.SetColors(io.LCyanOnBlue); io.Clear(io.Black);
  io.WriteStr("Enter your name:"); io.WriteLn; io.WriteLn;
  io.ReadStr(@name, 31); io.WriteLn; io.WriteLn;
  io.WriteStr("Hello, "); io.WriteStr(name);
END TestInput. 