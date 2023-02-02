MODULE [foreign] Laser; (** non-portable *)
IMPORT SYSTEM;

(*-----------------------------------*)
(* LASER BASIC v3.17 for Ofront/SDCC *)
(* Adapted to Ofront by Oleg N. Cher *)
(*  VEDAsoft Oberon Club, 2012-2015  *)
(* Thanx to Raydac & Michailov (HVG) *)
(*-----------------------------------*)

TYPE
  ADR   = INTEGER;
  CHAR  = SHORTCHAR;

PROCEDURE- InitSprites   * (adr, size: ADR);
PROCEDURE- InitSpritesEx * (adr, size: ADR);
PROCEDURE- InitSpritesAr * (sprites: ARRAY OF CHAR);
PROCEDURE- InitScroll    * (scrollBuf: ADR);
PROCEDURE- CalcSpritesOffset *;

(* Procedures for screen windows processing *)
PROCEDURE- INVV * (col, row, len, hgt: UBYTE);
PROCEDURE- MIRV * (col, row, len, hgt: UBYTE);
PROCEDURE- MARV * (col, row, len, hgt: UBYTE);
PROCEDURE- SETV * (col, row, len, hgt: UBYTE);
PROCEDURE- CLSV * (col, row, len, hgt: UBYTE);
PROCEDURE- WL1V * (col, row, len, hgt: UBYTE);
PROCEDURE- WR1V * (col, row, len, hgt: UBYTE);
PROCEDURE- WL4V * (col, row, len, hgt: UBYTE);
PROCEDURE- WR4V * (col, row, len, hgt: UBYTE);
PROCEDURE- WL8V * (col, row, len, hgt: UBYTE);
PROCEDURE- WR8V * (col, row, len, hgt: UBYTE);
PROCEDURE- SL1V * (col, row, len, hgt: UBYTE);
PROCEDURE- SR1V * (col, row, len, hgt: UBYTE);
PROCEDURE- SL4V * (col, row, len, hgt: UBYTE);
PROCEDURE- SR4V * (col, row, len, hgt: UBYTE);
PROCEDURE- SL8V * (col, row, len, hgt: UBYTE);
PROCEDURE- SR8V * (col, row, len, hgt: UBYTE);
PROCEDURE- WCRV * (col, row, len, hgt, npx: UBYTE);
PROCEDURE- SCRV * (col, row, len, hgt, npx: UBYTE);
PROCEDURE- AWLV * (col, row, len, hgt: UBYTE);
PROCEDURE- ASLV * (col, row, len, hgt: UBYTE);
PROCEDURE- AWRV * (col, row, len, hgt: UBYTE);
PROCEDURE- ASRV * (col, row, len, hgt: UBYTE);
PROCEDURE- ATUV * (col, row, len, hgt: UBYTE);
PROCEDURE- ATDV * (col, row, len, hgt: UBYTE);

(* Procedures for sprites manipulations *)
PROCEDURE- CLSM * (spN: UBYTE);
PROCEDURE- INVM * (spN: UBYTE);
PROCEDURE- PTBL * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- PTOR * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- PTXR * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- PTND * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- WL1M * (spN: UBYTE);
PROCEDURE- WR1M * (spN: UBYTE);
PROCEDURE- WL4M * (spN: UBYTE);
PROCEDURE- WR4M * (spN: UBYTE);
PROCEDURE- WL8M * (spN: UBYTE);
PROCEDURE- WR8M * (spN: UBYTE);
PROCEDURE- SL1M * (spN: UBYTE);
PROCEDURE- SR1M * (spN: UBYTE);
PROCEDURE- SL4M * (spN: UBYTE);
PROCEDURE- SR4M * (spN: UBYTE);
PROCEDURE- SL8M * (spN: UBYTE);
PROCEDURE- SR8M * (spN: UBYTE);
PROCEDURE- WCRM * (spN, npx: UBYTE);
PROCEDURE- SCRM * (spN, npx: UBYTE);
PROCEDURE- ATOF * ;
PROCEDURE- ATON * ;
PROCEDURE- GTBL * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- GTOR * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- GTXR * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- GTND * (col, row: SHORTINT; spN: UBYTE);
PROCEDURE- PMBL * (col, row, spD, spS: UBYTE);
PROCEDURE- PMOR * (col, row, spD, spS: UBYTE);
PROCEDURE- PMXR * (col, row, spD, spS: UBYTE);
PROCEDURE- PMND * (col, row, spD, spS: UBYTE);
PROCEDURE- PMAT * (col, row, spD, spS: UBYTE);
PROCEDURE- GMBL * (col, row, spD, spS: UBYTE);
PROCEDURE- GMOR * (col, row, spD, spS: UBYTE);
PROCEDURE- GMXR * (col, row, spD, spS: UBYTE);
PROCEDURE- GMND * (col, row, spD, spS: UBYTE);
PROCEDURE- GMAT * (col, row, spD, spS: UBYTE);
PROCEDURE- PWBL * (col, row, spN, spCol, spRow, len, hgt: UBYTE);
PROCEDURE- PWOR * (col, row, spN, spCol, spRow, len, hgt: UBYTE);
PROCEDURE- PWXR * (col, row, spN, spCol, spRow, len, hgt: UBYTE);
PROCEDURE- PWND * (col, row, spN, spCol, spRow, len, hgt: UBYTE);
PROCEDURE- SPNM * (sp1, sp2: UBYTE);

END Laser.