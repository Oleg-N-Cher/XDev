MODULE TestRND; (*$MAIN*)
IMPORT b := Basic, SYSTEM;
VAR n: BYTE; rnd: SHORTINT;

PROCEDURE- _Basic_S_RND (): INT16;
PROCEDURE- UDIV (a, b: INT16): INT16 "((unsigned int)a)/((unsigned int)b)";

BEGIN
  b.Init;
  b.RANDOMIZE(1);
  FOR n := 1 TO 25 DO
    (*rnd := _Basic_S_RND();
    b.PRWORD(UDIV(rnd, 65535 DIV 10)); b.PRCHAR(" ");
    b.PRWORD(rnd); b.PRLN;*)
    b.PRWORD(b.RND(0, 9)); b.PRLN;
  END;
  b.Quit
END TestRND.
