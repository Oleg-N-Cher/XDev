MODULE TestReal; (*$MAIN*)
IMPORT b := Basic, io := Console;

BEGIN
  b.Init;
  io.WriteReal(3.14159265358979); io.WriteCh(6X);
  io.WriteReal(31.4159265358979); io.WriteLn;
  io.WriteReal(314.159265358979); io.WriteCh(6X);
  io.WriteReal(3141.59265358979); io.WriteLn;
  io.WriteReal(31415.9265358979); io.WriteCh(6X);
  io.WriteReal(314159.265358979); io.WriteLn;
  io.WriteReal(3141592.65358979); io.WriteCh(6X);
  io.WriteReal(31415926.5358979); io.WriteLn;
  io.WriteReal(314159265.358979); io.WriteCh(6X);
  io.WriteReal(3141592653.58979); io.WriteLn;
  io.WriteReal(31415926535.8979); io.WriteCh(6X);
  io.WriteReal(314159265358.979); io.WriteLn;
  io.WriteReal(3141592653589.79); io.WriteCh(6X);
  io.WriteReal(31415926535897.9); io.WriteLn;
  io.WriteReal(314159265358979.0); io.WriteLn; io.WriteLn;
  io.WriteReal(MIN(SHORTREAL)); io.WriteCh(6X);
  io.WriteReal(MAX(SHORTREAL)); io.WriteLn; io.WriteLn;
  io.WriteReal(3.14159265358979E-37 / 10); io.WriteCh(6X);
  io.WriteReal(3.14159265358979E-37); io.WriteLn;
  io.WriteReal(314.159265358979E-38); io.WriteCh(6X);
  io.WriteReal(3141.59265358979E-38); io.WriteLn;
  io.WriteReal(31415.9265358979E-38); io.WriteCh(6X);
  io.WriteReal(314159.265358979E-38); io.WriteLn;
  io.WriteReal(3141592.65358979E-38); io.WriteCh(6X);
  io.WriteReal(31415926.5358979E-38); io.WriteLn;
  io.WriteReal(314159265.358979E-38); io.WriteCh(6X);
  io.WriteReal(3141592653.58979E-38); io.WriteLn;
  io.WriteReal(31415926535.8979E-38); io.WriteCh(6X);
  io.WriteReal(314159265358.979E-38); io.WriteLn;
  io.WriteReal(3141592653589.79E-38); io.WriteCh(6X);
  io.WriteReal(31415926535897.9E-38); io.WriteLn;
  io.WriteReal(314159265358979.0E-38); io.WriteLn; io.WriteLn;
  io.WriteRealFix(3.14159265358979, 1); io.WriteCh(6X);
  io.WriteRealFix(-3.14159265358979, 3); io.WriteLn;
  io.WriteRealFix(3.14159265358979, 5); io.WriteCh(6X);
  io.WriteRealFix(-3.14159265358979, 9); io.WriteLn;
  b.Quit
END TestReal.
