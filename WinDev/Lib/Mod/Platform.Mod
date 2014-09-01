MODULE Platform;	(* non-portable *)

IMPORT SYSTEM;

TYPE
  Byte* = BYTE; (** Non-system end-user-level BYTE. *)
  OCTET* = BYTE; (** BYTE that is exactly 8 bit. *)
  STRING* = ARRAY[1] OF CHAR; (** Untagged ARRAY OF CHAR. *)

PROCEDURE -free (memblock: SYSTEM.PTR)	"free(memblock)";

PROCEDURE BITS* (i: INTEGER): SET; (** Convert INTEGER to SET. *)
BEGIN
  RETURN SYSTEM.VAL(SET, i)
END BITS;

PROCEDURE ORD* (s: SET): INTEGER; (** Convert SET to INTEGER. *)
BEGIN
  RETURN SYSTEM.VAL(INTEGER, s)
END ORD;

PROCEDURE Unsigned* (i: LONGINT): BYTE;
BEGIN
	RETURN SHORT(SHORT(i))
END Unsigned;

PROCEDURE DISPOSE* (VAR mem: SYSTEM.PTR);
BEGIN
  free(mem); mem := NIL;
END DISPOSE;

END Platform.
