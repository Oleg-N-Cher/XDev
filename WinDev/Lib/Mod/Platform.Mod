MODULE Platform;	(* non-portable *)

IMPORT SYSTEM;

TYPE
  BYTE* = SYSTEM.BYTE; (** Non-system end-user-level BYTE. *)
  STRING* = ARRAY [1] OF CHAR; (** Untagged ARRAY OF CHAR. *)

PROCEDURE BITS* (i: INTEGER): SET; (** Convert INTEGER to SET. *)
BEGIN
  RETURN SYSTEM.VAL(SET, i)
END BITS;

PROCEDURE ORD* (s: SET): INTEGER; (** Convert SET to INTEGER. *)
BEGIN
  RETURN SYSTEM.VAL(INTEGER, s)
END ORD;

END Platform.
