MODULE ASCII; (*$MAIN*)
IMPORT Console;
VAR
	n: INTEGER;
BEGIN
	FOR n := 32 TO 127 DO Console.WriteCh(CHR(n)) END;
END ASCII.
