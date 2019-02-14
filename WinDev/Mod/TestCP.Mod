MODULE TestCP; (*$MAIN*)
IMPORT io := Console;

CONST
  a* = ENTIER(3.141);
  b* = ENTIER(-3.141);
  c* = ENTIER(3.941);
  d* = ENTIER(-3.941);
  e* = ENTIER(1.5);
  f* = ENTIER(-1.5);
s*= BITS(5);
VAR i: LONGINT; r: REAL;

BEGIN
  i := ENTIER(r);
  i := ENTIER(3.141);
  i := ENTIER(-3.141);
  i := ENTIER(3.941);
  i := ENTIER(-3.941);
  i := ENTIER(1.5);
  i := ENTIER(-1.5);
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
END TestCP.