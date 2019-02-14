MODULE TestLen; (*$MAIN*)

TYPE
  Arr = ARRAY 3,3 OF INTEGER;

VAR
  a:Arr;
  i:INTEGER;

BEGIN
  i:=LEN(a,1);
END TestLen.