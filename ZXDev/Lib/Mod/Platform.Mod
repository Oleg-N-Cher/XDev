MODULE Platform; (** non-portable *)

(* Provided as incapsulated type implementation       *)
(*  for efficient work on different platforms where   *)
(*  unsigned, signed or fixed size types are perfect. *)
(* Copyright (C) 2012 Oleg N. Cher, VEDAsoft.         *)
(* http://zx.oberon2.ru *)

IMPORT SYSTEM;

PROCEDURE -UBYTE*(b: BYTE): SHORTINT "((SHORTINT)(unsigned char)(b))";
PROCEDURE -USHORT*(s: SHORTINT): INTEGER "((INTEGER)(unsigned short)(s))";
PROCEDURE -UINT*(i: INTEGER): LONGINT "((LONGINT)(unsigned int)(i))";

PROCEDURE -ToBYTE*(s: SHORTINT): BYTE "((BYTE)(s))";
PROCEDURE -ToSHORT*(i: INTEGER): SHORTINT "((SHORTINT)(i))";
PROCEDURE -ToINT*(l: LONGINT): INTEGER "((INTEGER)(l))";

PROCEDURE -free (memblock: SYSTEM.PTR)	"free(memblock)";

PROCEDURE DISPOSE* (VAR mem: SYSTEM.PTR);
BEGIN
  free(mem); mem := NIL;
END DISPOSE;

END Platform.
