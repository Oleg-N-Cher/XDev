MODULE GrScr; IMPORT SYSTEM;

PROCEDURE- ScrToAtr*; (** Screen address (DE) => attrib address (DE) *)
PROCEDURE- SetScr* (hiadr: SYSTEM.BYTE); (** Set screen address *)
PROCEDURE- XYtoScr*; (** Char/tile address (DE) => screen address (DE) *)

END GrScr.
