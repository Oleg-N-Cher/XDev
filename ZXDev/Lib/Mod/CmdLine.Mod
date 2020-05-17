MODULE [noinit] CmdLine;

CONST
  ParamCount* = 0;

TYPE
  Char* = CHAR;
  String* = ARRAY 1 OF Char;

PROCEDURE GetParam* (n: BYTE; VAR param: ARRAY OF Char);
BEGIN
  param[0] := 0X;
END GetParam;

END CmdLine.
