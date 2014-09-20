MODULE ASCII; (** portable *)
IMPORT Console;
VAR
  n: SHORTINT;
BEGIN (*$MAIN*)
  FOR n := 32-1 TO 127-1 DO Console.WriteCh(CHR(n+1)) END;
END ASCII.
