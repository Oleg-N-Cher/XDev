MODULE Platform;	(* non-portable *)

IMPORT SYSTEM;

TYPE
  Byte* = BYTE; (** Non-system end-user-level BYTE. *)
  OCTET* = BYTE; (** BYTE that is exactly 8 bit. *)
  STRING* = ARRAY[1] OF CHAR; (** Untagged ARRAY OF CHAR. *)

PROCEDURE -free (memblock: SYSTEM.PTR)	"free(memblock)";

PROCEDURE Unsigned* (i: LONGINT): BYTE;
BEGIN
	RETURN SHORT(SHORT(i))
END Unsigned;

PROCEDURE DISPOSE* (VAR mem: SYSTEM.PTR);
BEGIN
  free(mem); mem := NIL;
END DISPOSE;

END Platform.
