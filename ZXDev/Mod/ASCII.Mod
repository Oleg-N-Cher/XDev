MODULE ASCII; (** portable *)
IMPORT Console;
VAR
  n: SHORTINT;
BEGIN (*$MAIN*)
  FOR n := 32 TO 127 DO Console.WriteCh(CHR(n)) END;
END ASCII.
