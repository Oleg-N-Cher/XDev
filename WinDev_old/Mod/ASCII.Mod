MODULE ASCII;
IMPORT Console;
VAR
	n: INTEGER;
BEGIN (*$MAIN*)
	FOR n := 32 TO 127 DO Console.WriteCh(CHR(n)) END;
END ASCII.
