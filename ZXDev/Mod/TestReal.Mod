MODULE TestReal; (*$MAIN*)
IMPORT b := Basic, io := Console;

BEGIN
	b.Init;
	io.WriteRealFix(3.14159265358979, 1); io.WriteLn;
	io.WriteRealFix(-3.14159265358979, 3); io.WriteLn;
	io.WriteRealFix(3.14159265358979, 5); io.WriteLn;
	io.WriteRealFix(-3.14159265358979, 9); io.WriteLn;
	io.WriteReal(3.14159265358979); io.WriteLn;

	io.WriteInt(5); io.WriteLn;
	io.WriteInt(91); io.WriteLn;
	io.WriteInt(241); io.WriteLn;
	io.WriteInt(3415); io.WriteLn;
	io.WriteInt(44159); io.WriteLn;
	io.WriteInt(541592); io.WriteLn;
	io.WriteInt(6415926); io.WriteLn;
	io.WriteInt(74159265); io.WriteLn;
	io.WriteInt(841592653); io.WriteLn;
	io.WriteInt(1415926535); io.WriteLn;
	b.Quit
END TestReal. 