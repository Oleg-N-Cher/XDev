MODULE TestCalc;
IMPORT b := Basic, c := CalcZX;

BEGIN (*$MAIN*)
  b.Init;
  c.PushWord(1000); (* 1000 *)
  c.PushByte(24);   (*   24 *)
  c.Begin;
  c.add;            (*    + *)
  c.pi_div_2;       (* PI/2 *)
  c.duplicate;      (*  DUP *)
  c.add;            (*    + *)
  c.add;            (*    + *)
  c.End;
  b.PRSTR("1000 + 24 + PI = ");
  c.Print_PopReal();
  b.Quit
END TestCalc.
