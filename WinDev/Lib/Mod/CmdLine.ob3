MODULE CmdLine;  (** Command line parameter handling *)

IMPORT SYSTEM, Ignore;

TYPE
  Char* = CHAR;
  String* = ARRAY 1024 OF Char;
  ArgPtr* = POINTER [notag] TO ARRAY 1024 OF CHAR;
  ArgVec* = POINTER [notag] TO ARRAY 1024 OF ArgPtr;

VAR
  ParamCount-: INTEGER; (* argc - 1 *)
  argv: ArgVec; dummy: ADRINT;

(**
  Under Windows all wide characters are replaced by "?".
  Under Linux all non-ASCII characters provided in UTF-8.
*)
PROCEDURE GetParam* (n: INTEGER; VAR val: ARRAY OF CHAR);
BEGIN
  IF n <= ParamCount THEN SYSTEM.COPY(argv[n]^, val) END
END GetParam;

PROCEDURE GetParamInt* (n: INTEGER; VAR val: INTEGER);
  VAR s: ARRAY 64 OF CHAR; k, d, i: INTEGER;
BEGIN
  s := ""; GetParam(n, @s); i := 0;
  IF s[0] = "-" THEN i := 1 END ;
  k := 0; d := ORD(s[i]) - ORD("0");
  WHILE (d >= 0 ) & (d <= 9) DO k := k*10 + d; INC(i); d := ORD(s[i]) - ORD("0") END ;
  IF s[0] = "-" THEN d := -d; DEC(i) END ;
  IF i > 0 THEN val := k END
END GetParamInt; 

PROCEDURE __getmainargs* ["__getmainargs"] (VAR argc: INT32; VAR argv: ArgVec;
  VAR env: ADRINT; wildcard: INT32; VAR startupinfo: ADRINT): INT32;

BEGIN
  Ignore.Int(__getmainargs(@ParamCount, @argv, @dummy, 0, @dummy));
  DEC(ParamCount);
END CmdLine.
