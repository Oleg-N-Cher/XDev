MODULE TestCP;
IMPORT io := Console, S := SYSTEM;

CONST
	max* = MAX(500, 0);
	min* = MIN(500, 0);
	dd* = ASH(500, 0);
  dd1* = ASH(MIN(INTEGER), -31);
  dd2* = ASH(1, 30);
  dd1l* = ASH(MIN(LONGINT), -63);
  (*dd2l* = ASH(LONG(LONG(LONG(1))), 62);*)

VAR b: BYTE; s: SHORTINT; i,n: INTEGER; l: LONGINT; r: REAL;

PROCEDURE Ret(): INTEGER;
BEGIN
  IF 0 = 0 THEN RETURN 1+1 END
END Ret;

BEGIN
(*
  io.WriteRealFix(-3.141592653589793238,  1);io.WriteLn;
  io.WriteRealFix(-31.41592653589793238,  2);io.WriteLn;
  io.WriteRealFix(-314.1592653589793238,  3);io.WriteLn;
  io.WriteRealFix(-3141.592653589793238,  4);io.WriteLn;
  io.WriteRealFix(-31415.92653589793238,  5);io.WriteLn;
  io.WriteRealFix(-314159.2653589793238,  6);io.WriteLn;
  io.WriteRealFix(-3141592.653589793238,  7);io.WriteLn;
  io.WriteRealFix(-31415926.53589793238,  8);io.WriteLn;
  io.WriteRealFix(-314159265.3589793238,  9);io.WriteLn;
  io.WriteRealFix(-3141592653.589793238, 10);io.WriteLn;
  io.WriteRealFix(-31415926535.89793238, 11);io.WriteLn;
  io.WriteRealFix(-314159265358.9793238, 12);io.WriteLn;
  io.WriteRealFix(-3141592653589.793238, 13);io.WriteLn;
  io.WriteRealFix(-31415926535897.93238, 14);io.WriteLn;
  io.WriteRealFix(-314159265358979.3238, 15);io.WriteLn;
  io.WriteRealFix(-3141592653589793.238, 16);io.WriteLn;
  io.WriteRealFix(-31415926535897932.38, 17);io.WriteLn;
  io.WriteRealFix(-314159265358979323.8, 18);io.WriteLn;
  io.WriteRealFix(-3141592653589793238.0, 19);io.WriteLn;

  io.WriteRealFix(-3.141592653589793238, 11);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 12);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 13);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 14);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 15);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 16);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 17);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 18);io.WriteLn;
  io.WriteRealFix(-3.141592653589793238, 19);io.WriteLn;
*)
(*
  io.WriteReal(3.1D-233); io.WriteLn;
  io.WriteReal(3.1D+237); io.WriteLn;
  io.WriteReal(3.14159265358979D-1); io.WriteLn;
  io.WriteReal(-3141592653589793238.0); io.WriteLn;
  io.WriteReal(3.0D-307 / 10); io.WriteLn;
*)
(*
  io.WriteReal(3.14159265358979D-307 / 10); io.WriteLn;
  io.WriteReal(31.4159265358979D-308); io.WriteLn;
  io.WriteReal(314.159265358979D-308); io.WriteLn;
  io.WriteReal(3141.59265358979D-308); io.WriteLn;
  io.WriteReal(31415.9265358979D-308); io.WriteLn;
  io.WriteReal(314159.265358979D-308); io.WriteLn;
  io.WriteReal(3141592.65358979D-308); io.WriteLn;
  io.WriteReal(31415926.5358979D-308); io.WriteLn;
  io.WriteReal(314159265.358979D-308); io.WriteLn;
  io.WriteReal(3141592653.58979D-308); io.WriteLn;
  io.WriteReal(31415926535.8979D-308); io.WriteLn;
  io.WriteReal(314159265358.979D-308); io.WriteLn;
  io.WriteReal(3141592653589.79D-308); io.WriteLn;
  io.WriteReal(31415926535897.9D-308); io.WriteLn;
  io.WriteReal(314159265358979.0D-308); io.WriteLn;
*)
	i:=ASH(b, n); i:=ASH(s, n); i:=ASH(i, n); l:=ASH(l, n);
	i:=S.LSH(b, n); i:=S.LSH(s, n); i:=S.LSH(i, n); l:=S.LSH(l, n);
	i:=S.ROT(b, n); i:=S.ROT(s, n); i:=S.ROT(i, n); l:=S.ROT(l, n);
	i := MIN(b, s);
	n := MAX(b, s);
	IF s = 1 THEN END;
END TestCP.