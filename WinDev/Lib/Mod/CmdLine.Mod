MODULE CmdLine;	(** portable layer for LibC - command line parameters handling *)

IMPORT SYSTEM;

TYPE
  Char* = CHAR;
  String* = ARRAY 1024 OF Char;
  ArgPtr = POINTER [1] TO ARRAY [1] 1024 OF Char;
  ArgVec = POINTER [1] TO ARRAY [1] 1024 OF ArgPtr;

VAR
  paramCount-: INTEGER; (* argc - 1 *)

PROCEDURE -argc(): INTEGER "SYSTEM_argc";
PROCEDURE -argv(): LONGINT "(long)SYSTEM_argv";

PROCEDURE GetParam* (n: INTEGER; VAR param: ARRAY OF Char);
(**
  Under Windows all wide characters are replaced by "?".
  Under Linux all non-ASCII characters provided in UTF-8.
*)
VAR
  av: ArgVec;
BEGIN
  IF n <= paramCount THEN
    av := SYSTEM.VAL(ArgVec, argv()); COPY(av[n]^, param);
  ELSE
    COPY("", param);
  END;
END GetParam;

BEGIN
  paramCount := argc() - 1;
END CmdLine.
