MODULE ConsoleStdIO;
IMPORT SYSTEM;

PROCEDURE -AAAincludestdio "#include <stdio.h>";
PROCEDURE -printfc (ch: CHAR) 'printf("%c", ch)';

PROCEDURE WriteCh* (ch: CHAR);
BEGIN
  printfc(ch);
END WriteCh;

END ConsoleStdIO.
