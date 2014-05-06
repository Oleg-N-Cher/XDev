MODULE Laser; (** non-portable *)
(*-----------------------------------*)
(* LASER BASIC v3.17 for Ofront/SDCC *)
(* Adapted to Ofront by Oleg N. Cher *)
(*  VEDAsoft Oberon Club, 2012-2013  *)
(* Thanx to Raydac & Michailov (HVG) *)
(*-----------------------------------*)

TYPE
  BYTE = INTEGER;
  CARDINAL = LONGINT;

PROCEDURE InitSprites* (sprAddr, sprSize: CARDINAL);
  BEGIN END InitSprites;
PROCEDURE InitScroll* (scrollBuf: CARDINAL);
  BEGIN END InitScroll;

(* Procedures for screen windows processing *)
PROCEDURE INVV* (col, row, len, hgt: BYTE); BEGIN END INVV;
PROCEDURE MIRV* (col, row, len, hgt: BYTE); BEGIN END MIRV;
PROCEDURE MARV* (col, row, len, hgt: BYTE); BEGIN END MARV;
PROCEDURE SETV* (col, row, len, hgt: BYTE); BEGIN END SETV;
PROCEDURE CLSV* (col, row, len, hgt: BYTE); BEGIN END CLSV;
PROCEDURE WL1V* (col, row, len, hgt: BYTE); BEGIN END WL1V;
PROCEDURE WR1V* (col, row, len, hgt: BYTE); BEGIN END WR1V;
PROCEDURE WL4V* (col, row, len, hgt: BYTE); BEGIN END WL4V;
PROCEDURE WR4V* (col, row, len, hgt: BYTE); BEGIN END WR4V;
PROCEDURE WL8V* (col, row, len, hgt: BYTE); BEGIN END WL8V;
PROCEDURE WR8V* (col, row, len, hgt: BYTE); BEGIN END WR8V;
PROCEDURE SL1V* (col, row, len, hgt: BYTE); BEGIN END SL1V;
PROCEDURE SR1V* (col, row, len, hgt: BYTE); BEGIN END SR1V;
PROCEDURE SL4V* (col, row, len, hgt: BYTE); BEGIN END SL4V;
PROCEDURE SR4V* (col, row, len, hgt: BYTE); BEGIN END SR4V;
PROCEDURE SL8V* (col, row, len, hgt: BYTE); BEGIN END SL8V;
PROCEDURE SR8V* (col, row, len, hgt: BYTE); BEGIN END SR8V;
PROCEDURE WCRV* (col, row, len, hgt, npx: BYTE); BEGIN END WCRV;
PROCEDURE SCRV* (col, row, len, hgt, npx: BYTE); BEGIN END SCRV;
PROCEDURE AWLV* (col, row, len, hgt: BYTE); BEGIN END AWLV;
PROCEDURE ASLV* (col, row, len, hgt: BYTE); BEGIN END ASLV;
PROCEDURE AWRV* (col, row, len, hgt: BYTE); BEGIN END AWRV;
PROCEDURE ASRV* (col, row, len, hgt: BYTE); BEGIN END ASRV;
PROCEDURE ATUV* (col, row, len, hgt: BYTE); BEGIN END ATUV;
PROCEDURE ATDV* (col, row, len, hgt: BYTE); BEGIN END ATDV;

(* Procedures for sprites manipulations *)
PROCEDURE CLSM* (spN: BYTE); BEGIN END CLSM;
PROCEDURE INVM* (spN: BYTE); BEGIN END INVM;
PROCEDURE PTBL* (col, row, spN: BYTE); BEGIN END PTBL;
PROCEDURE PTOR* (col, row, spN: BYTE); BEGIN END PTOR;
PROCEDURE PTXR* (col, row, spN: BYTE); BEGIN END PTXR;
PROCEDURE PTND* (col, row, spN: BYTE); BEGIN END PTND;
PROCEDURE WL1M* (spN: BYTE); BEGIN END WL1M;
PROCEDURE WR1M* (spN: BYTE); BEGIN END WR1M;
PROCEDURE WL4M* (spN: BYTE); BEGIN END WL4M;
PROCEDURE WR4M* (spN: BYTE); BEGIN END WR4M;
PROCEDURE WL8M* (spN: BYTE); BEGIN END WL8M;
PROCEDURE WR8M* (spN: BYTE); BEGIN END WR8M;
PROCEDURE SL1M* (spN: BYTE); BEGIN END SL1M;
PROCEDURE SR1M* (spN: BYTE); BEGIN END SR1M;
PROCEDURE SL4M* (spN: BYTE); BEGIN END SL4M;
PROCEDURE SR4M* (spN: BYTE); BEGIN END SR4M;
PROCEDURE SL8M* (spN: BYTE); BEGIN END SL8M;
PROCEDURE SR8M* (spN: BYTE); BEGIN END SR8M;
PROCEDURE WCRM* (spN, npx: BYTE); BEGIN END WCRM;
PROCEDURE SCRM* (spN, npx: BYTE); BEGIN END SCRM;
PROCEDURE ATOF* ; BEGIN END ATOF;
PROCEDURE ATON* ; BEGIN END ATON;
PROCEDURE GTBL* (col, row, spN: BYTE); BEGIN END GTBL;
PROCEDURE GTOR* (col, row, spN: BYTE); BEGIN END GTOR;
PROCEDURE GTXR* (col, row, spN: BYTE); BEGIN END GTXR;
PROCEDURE GTND* (col, row, spN: BYTE); BEGIN END GTND;
PROCEDURE PMBL* (col, row, spD, spS: BYTE); BEGIN END PMBL;
PROCEDURE PMOR* (col, row, spD, spS: BYTE); BEGIN END PMOR;
PROCEDURE PMXR* (col, row, spD, spS: BYTE); BEGIN END PMXR;
PROCEDURE PMND* (col, row, spD, spS: BYTE); BEGIN END PMND;
PROCEDURE PMAT* (col, row, spD, spS: BYTE); BEGIN END PMAT;
PROCEDURE GMBL* (col, row, spD, spS: BYTE); BEGIN END GMBL;
PROCEDURE GMOR* (col, row, spD, spS: BYTE); BEGIN END GMOR;
PROCEDURE GMXR* (col, row, spD, spS: BYTE); BEGIN END GMXR;
PROCEDURE GMND* (col, row, spD, spS: BYTE); BEGIN END GMND;
PROCEDURE GMAT* (col, row, spD, spS: BYTE); BEGIN END GMAT;
PROCEDURE PWBL* (col, row, spN, spCol, spRow, len, hgt: BYTE);
  BEGIN END PWBL;
PROCEDURE PWOR* (col, row, spN, spCol, spRow, len, hgt: BYTE);
  BEGIN END PWOR;
PROCEDURE PWXR* (col, row, spN, spCol, spRow, len, hgt: BYTE);
  BEGIN END PWXR;
PROCEDURE PWND* (col, row, spN, spCol, spRow, len, hgt: BYTE);
  BEGIN END PWND;

END Laser.