MODULE Files;	(** portable layer for LibC - file IO *)
(*******************************************************************************
*      Description: provides a simple buffered file input/output library.      *
********************************************************************************

  По замыслу при работе с файлами есть 3 уровня различной глубины:

  1. Все ошибки могут игнорироваться; ничего страшного не произойдёт,
     кроме того, что файл может не создаться и т.п. Можно проверять на
     ошибки состояние File.error один раз после всех файловых операций.
  2. Проверяем File.error после каждой файловой операции; так у нас
     есть точная указка где именно произошла (или не произошла) ошибка.
  3. Если недостаточно информации о возникшей ошибке, мы уточняем её,
     опросив переменную File.state и сравнив значение с кодом состояния.
*)

IMPORT SYSTEM;

(*CONST
  Successful* = 0;
  Failed* = 3;*)

TYPE
  PtrFILE = INTEGER; (* Internal system type - pointer to FILE. *)
  PtrSTR = ARRAY [1] OF CHAR;
  STRING = ARRAY [1] OF CHAR;

  File* = RECORD (** Binary file *)
    handle: PtrFILE;
    (*state- : INTEGER; (* successful, outofmemory, toomanyfilesopen, failed, connectionfailure. *) *)
    end-: BOOLEAN; (** Is end of file? *)
    error-: BOOLEAN; (** Is no file errors? *)
  END;
  FileToRead* = RECORD (File) (** Binary file to read only. *)
  END;
  FileToWrite* = RECORD (File) (** Binary file to write only. *)
  END;

PROCEDURE -includestdio()	"#include <stdio.h>";
PROCEDURE -includeunistd()	"#include <unistd.h>";

PROCEDURE -fopen (filename, mode: PtrSTR): PtrFILE "(int)fopen(filename, mode)";
PROCEDURE -fgetc (file: PtrFILE): INTEGER "fgetc((FILE*)file)";
PROCEDURE -fputc (c: INTEGER; file: PtrFILE): INTEGER "fputc(c, (FILE*)file)";
PROCEDURE -feof (file: PtrFILE): INTEGER "feof((FILE*)file)"; (* IF # 0 THEN EOF. *)
PROCEDURE -EOF(): INTEGER "EOF";
PROCEDURE -fclose (file: PtrFILE): INTEGER "fclose((FILE*)file)";
PROCEDURE -unlink (filename: PtrSTR): INTEGER "unlink(filename)"; (* IF = 0 THEN OK. *)

(*
   OpenToRead - attempts to open a file, fname, for reading and
                it returns this file.
                The success of this operation can be checked by
                calling IsNoError.
*)
PROCEDURE (VAR file: File) OpenToRead* (fname: STRING);
  (** UNSAFE! Make sure that value of array 'fname' is null-terminated. *)
BEGIN
  file.error := FALSE; (* Reset this flag once - at start of work with a file. *)
  (* file.state := Successful; *)
  file.handle := fopen(fname, "rb");
  IF file.handle = 0 THEN
    file.error := TRUE;
    file.end := TRUE; (* file.state := Failed *)
  ELSE
    file.end := feof(file.handle) # 0;
  END;
END OpenToRead;

(*
   OpenToWrite - attempts to open a file, fname, for write and
                 it returns this file.
                 The success of this operation can be checked by
                 calling IsNoError.
*)
PROCEDURE (VAR file: File) OpenToWrite* (fname: STRING);
  (** UNSAFE! Make sure that value of array 'fname' is null-terminated. *)
BEGIN
  file.error := FALSE; (* Reset this flag once - at start of work with a file. *)
  (* file.state := Successful; *)
  file.handle := fopen(fname, "wb");
  IF file.handle = 0 THEN file.error := TRUE; (* file.state := Failed *) END;
END OpenToWrite;

(*
   Close - close a file which has been previously opened using:
           OpenToRead, OpenToWrite, OpenForRandom.
           It is correct to close a file which has an error status.
*)
PROCEDURE (VAR file: File) Close* ;
BEGIN
  IF file.handle # 0 THEN (* This is file to close. *)
    IF fclose(file.handle) # 0 THEN (* File closing error. *)
      file.error := TRUE; (* Error while closing. *)
    END;
    file.handle := 0; (* file.state := Successful; *)
  ELSE (* File is already closed or not opened. *)
    file.error := TRUE;
  END;
END Close;

PROCEDURE (VAR fromfile: FileToRead) ReadByte* (): SYSTEM.BYTE;
VAR
  byte: INTEGER;
BEGIN
  IF fromfile.error THEN RETURN 0 END; (* To safe work after error. *)
  byte := fgetc(fromfile.handle);
  IF byte = EOF() THEN (* EOF or error: *)
    IF feof(fromfile.handle) # 0 THEN (* Is EOF? *)
      fromfile.end := TRUE; RETURN 0
    ELSE (* This is file error. *)
      fromfile.error := TRUE;
      (* fromfile.state := Failed; *)
      RETURN 0
    END;
  END;
  RETURN SHORT(byte);
END ReadByte;

PROCEDURE (VAR tofile: FileToWrite) WriteByte* (byte: SYSTEM.BYTE);
VAR
  exitcode: INTEGER;
BEGIN
  IF tofile.error THEN RETURN END; (* To safe work after error. *)
  exitcode := fputc(ORD(SYSTEM.VAL(CHAR, byte)), tofile.handle);
  IF exitcode = EOF() THEN
    IF feof(tofile.handle) # 0 THEN
      tofile.end := TRUE;
    ELSE
      (* tofile.state := Failed; *)
    END;
  END;
END WriteByte;

(*
   DeleteFile - returns TRUE if a file named, fname is successfully deleted.
*)
PROCEDURE DeleteFile* (fname: STRING): BOOLEAN;
  (** UNSAFE! Make sure that value of array 'fname' is null-terminated. *)
BEGIN
  RETURN unlink(fname) = 0
END DeleteFile;

(*
   ExistsFile - returns TRUE if a file named, fname exists for reading.
*)
PROCEDURE ExistsFile* (fname: STRING): BOOLEAN;
  (** UNSAFE! Make sure that value of array 'fname' is null-terminated. *)
VAR
  f: FileToRead;
BEGIN
  f.OpenToRead(fname); f.Close; RETURN ~f.error
END ExistsFile;

END Files.

(* TODO:
  implement ReadBytes, WriteBytes (fread/fwrite)
  implement Rename (rename или fopen/fread/fwrite/fclose/unlink)
*)
