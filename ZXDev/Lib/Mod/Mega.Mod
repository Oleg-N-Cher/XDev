MODULE Mega; (** non-portable *)
(* -------------------- *)
(* MEGA BASIC for ZXDev *)
(*   by Oleg N. Cher    *)
(*    VEDAsoft, 2013    *)
(* -------------------- *)

CONST
	Tone* = FALSE;
	Noise* = TRUE;

TYPE
	UBYTE = INTEGER;
	WORD = LONGINT;
	SoundType = BOOLEAN;

PROCEDURE INVERT* ; BEGIN END INVERT;

(* Procedures for sound: *)
PROCEDURE PLAY* (
	sound: SoundType; stepLen, startFreq: UBYTE; stepNum: WORD; incFreq: UBYTE);
BEGIN END PLAY;

END Mega.
