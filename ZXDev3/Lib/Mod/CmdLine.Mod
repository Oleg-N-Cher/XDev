MODULE CmdLine;
IMPORT SYSTEM;

CONST
  ParamCount* = 0;

TYPE
  Char* = CHAR;
  String* = ARRAY 1 OF Char;

PROCEDURE GetParam* (n: INTEGER; VAR param: ARRAY OF Char);
BEGIN
  param[0] := 0X;
END GetParam;

END CmdLine.
