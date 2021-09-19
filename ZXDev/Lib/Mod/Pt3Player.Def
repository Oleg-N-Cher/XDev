MODULE [noinit] Pt3Player; IMPORT SYSTEM;

TYPE Module* = POINTER TO ARRAY [notag] OF CHAR;

VAR mode*: SET; (*
  set bit0 to 1, if you want to play without looping
	bit7 is set each time, when loop point is passed
*)

PROCEDURE- Init* (module: Module); (** Init player *)
PROCEDURE- Mute*; (** Mute *)
PROCEDURE- Play*; (** Play one quark (20 millisec) *)
  (* Must be called every 20ms for playing *)

END Pt3Player.
