MODULE ConsoleStdIO;
IMPORT SYSTEM;

PROCEDURE -AAAincludestdio "#include <stdio.h>";
PROCEDURE -printfc (ch: CHAR) 'printf("%c", ch)';
PROCEDURE -printfi (n: INTEGER) 'printf("%d", n);';
PROCEDURE -printfli (l: LONGINT) 'printf("%lld", l)';
PROCEDURE -printfs (str: ARRAY OF CHAR) 'printf("%s", str)';

PROCEDURE WriteInt* (n: INTEGER);
BEGIN
  printfi(n);
END WriteInt;

PROCEDURE WriteCh* (ch: CHAR);
BEGIN
  printfc(ch);
END WriteCh;

PROCEDURE WriteStr* (IN str: ARRAY OF CHAR);
BEGIN
  printfs(str);
END WriteStr;

END ConsoleStdIO.
