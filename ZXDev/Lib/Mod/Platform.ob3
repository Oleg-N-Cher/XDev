MODULE Platform; (** non-portable *)

(* Provided as incapsulated type implementation       *)
(*  for efficient work on different platforms where   *)
(*  unsigned, signed or fixed size types are perfect. *)
(* Copyright (C) 2012 Oleg N. Cher, VEDAsoft.         *)
(* http://zx.oberon2.ru *)

IMPORT SYSTEM;

PROCEDURE- LT* (x, y: INT16): BOOLEAN "((unsigned)x <  (unsigned)y)";
PROCEDURE- LE* (x, y: INT16): BOOLEAN "((unsigned)x <= (unsigned)y)";

PROCEDURE -UBYTE*(b: INT8): INT16 "((SHORTINT)(unsigned char)(b))";
PROCEDURE -USHORT*(s: INT16): INT32 "((INTEGER)(unsigned short)(s))";
PROCEDURE -UINT*(i: INT32): INT64 "((LONGINT)(unsigned int)(i))";

PROCEDURE -ToBYTE*(s: INT16): INT8 "((BYTE)(s))";
PROCEDURE -ToSHORT*(i: INT32): INT16 "((SHORTINT)(i))";
PROCEDURE -ToINT*(l: INT64): INT32 "((INTEGER)(l))";

PROCEDURE -free (memblock: SYSTEM.PTR)	"free(memblock)";

PROCEDURE DISPOSE* (VAR mem: SYSTEM.PTR);
BEGIN
  free(mem); mem := NIL;
END DISPOSE;

END Platform.
