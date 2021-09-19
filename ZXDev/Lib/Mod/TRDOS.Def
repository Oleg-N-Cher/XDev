MODULE [foreign] TRDOS; IMPORT SYSTEM;

(* * * * * * * * * * * * * * * * * * * * * * * *)
(* Обертка к функциям TR-DOS для SDCC          *)
(* Бесплатно для некоммерческого использования *)
(* SDCC interface for TR-DOS functions         *)
(* Absolutely free for noncommercial use       *)
(* (c) 2013 Amxgris/Red Triangle/Mother Russia *)
(* * * * * * * * * * * * * * * * * * * * * * * *)

(*
// эти дефины на всякий случай, - в либу "забиты" сами значения
#define trdosFileOperationSign 0x5CF9
#define trdosFileLoadVerifySign 0x5d10
#define trdosFileName 0x5cdd
#define trdosCheckSymbolsNum 0x5d06
#define trdosDeletedFilesNum 0x5d07
#define trdosErrorCode 0x5d0f
#define trdosFoundFileNum 0x5d1e
*)

(* описываем дескриптор файла TR-DOS: *)

TYPE
  UCHAR* = CHAR; UCHARPTR* = POINTER [1] TO ARRAY [1] OF UCHAR;
  UINT*  = INT16;
  FDSP*  = RECORD [1]
    trFName*    : ARRAY 9 OF UCHAR; (* имя и тип файла *)
    trFStart*   : UCHARPTR; (* см. описание TR-DOS *)
    trFByteLen* : UINT;
    trFSectLen* : UCHAR;
    trFSector*  : UCHAR;
    trFTrack*   : UCHAR;
  END;

(* Прототипы функций: *)
PROCEDURE- IsDisk* (): BOOLEAN;

(* функция #01 TR-DOS: *)
(*          drive name ('a','b','c','d'), не чувствительна к регистру *)
PROCEDURE- DriveSel* (driveLetter: UCHAR);

(* функция #00 TR-DOS: *)
PROCEDURE- Init*;

(* функция #18 TR-DOS: *)
PROCEDURE- DiskTune*;

(* функция #05 TR-DOS: *)
(*           destptr,     track pos,    sector pos,    len in sectors *)
PROCEDURE- ReadSectors* (
  destPtr: UCHARPTR; trackPos, sectorPos, LenInSectors: UCHAR);

(* функция #08 TR-DOS: *)
(*             destptr,          file number *)
PROCEDURE- ReadFileDSP* (destPtr: UCHARPTR; fileNumber: UCHAR);

(* функция #06 TR-DOS: *)
(*           srctptr,     track pos,    sector pos,    len in sectors *)
PROCEDURE- WriteSectors* (
  srctPtr: UCHARPTR; trackPos, sectorPos, LenInSectors: UCHAR);

(* функция #09 TR-DOS: *)
(*              srctptr,       file number *)
PROCEDURE- WriteFileDSP* (srctPtr: UCHARPTR; fileNumber: UCHAR);

(* функция #0A TR-DOS: *)
(*              name ptr  name len *)
PROCEDURE- FindFile* (name: ARRAY OF UCHAR; nameLen: UCHAR): UCHAR;

(* функция #0B TR-DOS: *)
(*          name ptr  data ptr     file data len *)
PROCEDURE- WriteFile* (
  name: ARRAY OF UCHAR; dataPtr: UCHARPTR; dataLen: UINT);

(* функция #12 TR-DOS: *)
(*          FDSP ptr *)
PROCEDURE- EraseFile* (name: ARRAY OF UCHAR);

(* функция #0E TR-DOS, (23801) = 0: *)

(*          name ptr  dest ptr    file data len *)
PROCEDURE- LoadFile* (
  name: ARRAY OF UCHAR; destPtr: UCHARPTR; fileDataLen: UINT);

END TRDOS.
