MODULE [foreign] Laser2; (** non-portable *)
IMPORT SYSTEM;

(***************************)
(* LASER 2  Graphic Engine *)
(*  Coded by Oleg N. Cher  *)
(*   zx.oberon2.ru/forum   *)
(***************************)

TYPE
  ADR     = INTEGER;
  BUFFER  = ARRAY OF SHORTCHAR;
  SPRITES = ARRAY OF SHORTCHAR;

(** New procedures: *)

PROCEDURE- SCRL  * (adr: ADR); (** Set WU1V's scroll buffer *)
PROCEDURE- SCRLv * (adr: ADR); (** in variable *)
PROCEDURE- SCRLa * (buf: BUFFER); (** in array *)
PROCEDURE- SPRT  * (adr: ADR); (** Set address of sprites *)
PROCEDURE- SPRTv * (adr: ADR); (** in variable *)
PROCEDURE- SPRTa * (sprites: SPRITES); (** in array *)
PROCEDURE- SCRN  * (adr: ADR); (** Set address of screen *)

(** Synonyms for the new procedures: *)

PROCEDURE- InitScroll   * (adr: ADR); (** WU1V's scroll buf *)
PROCEDURE- InitScrollV  * (adr: ADR); (** in variable *)
PROCEDURE- InitScrollA  * (buf: BUFFER); (** in array *)
PROCEDURE- InitSprites  * (adr: ADR); (** Set sprites adr *)
PROCEDURE- InitSpritesV * (adr: ADR); (** in variable *)
PROCEDURE- InitSpritesA * (sprites: SPRITES); (** in array *)
PROCEDURE- SetScreen    * (adr: ADR); (** Set screen adr *)

(** Sprite engine (in OUT_OF_SCREEN the coords can be outside the screen): *)

PROCEDURE- ATOF * ;
PROCEDURE- ATON * ;
PROCEDURE- GTBL * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- GTND * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- GTNV * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- GTOR * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- GTXR * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- INVM * (spn: UBYTE);
PROCEDURE- PTBL * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- PTND * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- PTNV * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- PTOR * (col, row: SHORTINT; spn: UBYTE);
PROCEDURE- PTXR * (col, row: SHORTINT; spn: UBYTE);

(** Screen windows processing (coordinates CANNOT be outside the screen): *)

PROCEDURE- CLSV * (col, row, len, hgt: UBYTE);
PROCEDURE- INVV * (col, row, len, hgt: UBYTE);
PROCEDURE- MIRV * (col, row, len, hgt: UBYTE);
PROCEDURE- SDNV * (col, row, len, hgt, npx: UBYTE);
PROCEDURE- SUPV * (col, row, len, hgt, npx: UBYTE);
PROCEDURE- SL1V * (col, row, len, hgt: UBYTE);
PROCEDURE- SL4V * (col, row, len, hgt: UBYTE);
PROCEDURE- SL8V * (col, row, len, hgt: UBYTE);
PROCEDURE- SR1V * (col, row, len, hgt: UBYTE);
PROCEDURE- SR4V * (col, row, len, hgt: UBYTE);
PROCEDURE- SR8V * (col, row, len, hgt: UBYTE);
PROCEDURE- WL1V * (col, row, len, hgt: UBYTE);
PROCEDURE- WL4V * (col, row, len, hgt: UBYTE);
PROCEDURE- WL8V * (col, row, len, hgt: UBYTE);
PROCEDURE- WR1V * (col, row, len, hgt: UBYTE);
PROCEDURE- WR4V * (col, row, len, hgt: UBYTE);
PROCEDURE- WR8V * (col, row, len, hgt: UBYTE);
PROCEDURE- WU1V * (col, row, len, hgt: UBYTE);

(** Attribute windows processing (coordinates CANNOT be outside the screen): *)

PROCEDURE- AWLV * (col, row, len, hgt: UBYTE);
PROCEDURE- AWRV * (col, row, len, hgt: UBYTE);
PROCEDURE- ATUV * (col, row, len, hgt: UBYTE);
PROCEDURE- ATDV * (col, row, len, hgt: UBYTE);
PROCEDURE- ASUV * (col, row, len, hgt: UBYTE);
PROCEDURE- ASDV * (col, row, len, hgt: UBYTE);
PROCEDURE- MARV * (col, row, len, hgt: UBYTE);
PROCEDURE- SETV * (col, row, len, hgt: UBYTE);
PROCEDURE- BR0V * (col, row, len, hgt: UBYTE);
PROCEDURE- BR1V * (col, row, len, hgt: UBYTE);

END Laser2.
