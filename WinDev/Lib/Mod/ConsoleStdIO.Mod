MODULE ConsoleStdIO;
IMPORT SYSTEM;

PROCEDURE -AAAincludestdio "#include <stdio.h>";
PROCEDURE -printfc (ch: SHORTCHAR) 'printf("%c", ch)';
PROCEDURE -printfi (n: INTEGER) 'printf("%d", n);';
PROCEDURE -printfli (l: LONGINT) 'printf("%lld", l)';
PROCEDURE -printfs (str: ARRAY OF SHORTCHAR) 'printf("%s", str)';
PROCEDURE -printfln 'printf("\n")';

PROCEDURE WriteInt* (n: INTEGER);
BEGIN
  printfi(n);
END WriteInt;

PROCEDURE WriteCh* (ch: SHORTCHAR);
BEGIN
  printfc(ch);
END WriteCh;

PROCEDURE WriteLn* ;
BEGIN
  printfln;
END WriteLn;

PROCEDURE WriteStr* (str: ARRAY OF SHORTCHAR);
BEGIN
  printfs(str);
END WriteStr;

END ConsoleStdIO.
