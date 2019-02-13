MODULE TestReal; (*$MAIN*)
IMPORT b := Basic, io := Console;

BEGIN
	b.Init;
	io.WriteReal(3.14159265358979); io.WriteLn;
	io.WriteReal(31.4159265358979); io.WriteLn;
	io.WriteReal(314.159265358979); io.WriteLn;
	io.WriteReal(3141.59265358979); io.WriteLn;
	io.WriteReal(31415.9265358979); io.WriteLn;
	io.WriteReal(314159.265358979); io.WriteLn;
	io.WriteReal(3141592.65358979); io.WriteLn;
	io.WriteReal(31415926.5358979); io.WriteLn;
	io.WriteReal(314159265.358979); io.WriteLn;
	io.WriteReal(3141592653.58979); io.WriteLn;
	io.WriteReal(31415926535.8979); io.WriteLn;
	io.WriteReal(314159265358.979); io.WriteLn;
	io.WriteReal(3141592653589.79); io.WriteLn;
	io.WriteReal(31415926535897.9); io.WriteLn;
	io.WriteReal(314159265358979.0); io.WriteLn;
	io.WriteReal(MIN(SHORTREAL)); io.WriteLn;
	io.WriteReal(MAX(SHORTREAL)); io.WriteLn;
  io.WriteRealFix(3.14159265358979, 1); io.WriteLn;
  io.WriteRealFix(-3.14159265358979, 3); io.WriteLn;
  io.WriteRealFix(3.14159265358979, 5); io.WriteLn;
  io.WriteRealFix(-3.14159265358979, 9); io.WriteLn;
	b.Quit
END TestReal. 