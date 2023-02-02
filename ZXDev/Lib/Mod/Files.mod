MODULE [noinit] Files; IMPORT SYSTEM; (** non-portable *)
(*---------------------------------------*)
(* Load/Save files on tape & TR-DOS disk *)
(*      VEDAsoft Oberon Club, 2019       *)
(*---------------------------------------*)

CONST (* LoadTape error codes *)
  OK               * = 0;
  ErrTapeLoading   * = 1;
  ErrLoadingHeader * = 2;
  ErrNameNotMatch  * = 3;
  ErrBreakPressed  * = 4;

VAR
  filesize-: INT16; (* File size after LoadTape/LoadDisk successful *)

PROCEDURE- LoadDisk* (name_ext: POINTER TO ARRAY [notag] OF CHAR;
  adr: INT32): BOOLEAN;
PROCEDURE- LoadTape* (name: POINTER TO ARRAY [notag] OF CHAR;
  adr: INT32): INT8;
PROCEDURE- SaveDisk* (name_ext: POINTER TO ARRAY [notag] OF CHAR;
  adr, size: INT32);
PROCEDURE- SaveTape* (name: POINTER TO ARRAY [notag] OF CHAR;
  adr, size: INT32);

END Files.
