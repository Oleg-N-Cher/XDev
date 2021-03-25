MODULE Cursor; IMPORT SYSTEM; (** non-portable *)

CONST
  Right* = 0; Left* = 1; Down* = 2; Up* = 3; Fire* = 4;

VAR Std-: ARRAY 39 OF CHAR; (** Standard cursor shape *)

(** #0: INIT CURSOR (set cursor shape). *)
PROCEDURE- Init* (shape: POINTER TO ARRAY [notag] OF CHAR);

(** #1: DRAW CURSOR (also saves background). *)
PROCEDURE- Draw* (x (*{0..255}*), y (*{0..191}*): INT16);

(** #2: HIDE CURSOR (restore background). *)
PROCEDURE- Hide*;

(** #3: GET CONTROL BYTE for current keys. *)
PROCEDURE- GetControl* (): SET;

END Cursor.
