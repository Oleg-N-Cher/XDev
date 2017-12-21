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
  PtrFILE = LONGINT; (* Internal system type - pointer to FILE. *)
  PtrSTR = ARRAY [1] OF CHAR;
  STRING = ARRAY [1] OF CHAR;

  File* = RECORD (** Binary file *)
    handle: PtrFILE;
    (*state- : INTEGER; (* successful, outofmemory, toomanyfilesopen, failed, connectionfailure. *) *)
    prevbyte: INTEGER; (* Used as byte cache for correct work of feof(). *)
    end-: BOOLEAN; (** Is end of file? *)
    error-: BOOLEAN; (** Is no file errors? *)
  END;
  FileToRead* = RECORD (File) (** Binary file to read only. *)
  END;
  FileToWrite* = RECORD (File) (** Binary file to write only. *)
  END;

PROCEDURE -includestdio()	"#include <stdio.h>";
PROCEDURE -includeunistd()	"#include <unistd.h>";

PROCEDURE -fopen (filename, mode: PtrSTR): PtrFILE
  "(SYSTEM_PTR)fopen((char*)filename, (char*)mode)";
PROCEDURE -fgetc (file: PtrFILE): INTEGER
  "fgetc((FILE*)file)";
PROCEDURE -fgets (str: PtrSTR; n: INTEGER; file: PtrFILE): INTEGER
  "fgets((CHAR*)str, n, (FILE*)file)";
PROCEDURE -fputc (c: INTEGER; file: PtrFILE): INTEGER
  "fputc(c, (FILE*)file)";
(*
   Checks whether the end-of-File indicator associated with stream is set, returning a value different from zero if it is.
   This indicator is generally set by a previous operation on the stream that attempted to read at or past the end-of-file.
   Notice that stream's internal position indicator may point to the end-of-file for the next operation, but still, the end-of-file indicator may not be set until an operation attempts to read at that point.

http://www.cplusplus.com/reference/clibrary/cstdio/feof/
*)
PROCEDURE -feof (file: PtrFILE): INTEGER "feof((FILE*)file)"; (* IF # 0 THEN EOF. *)
PROCEDURE -ferror (file: PtrFILE): INTEGER "ferror((FILE*)file)";
PROCEDURE -EOF(): INTEGER "EOF";
PROCEDURE -NULL(): PtrFILE "((SYSTEM_PTR)NULL)";

PROCEDURE -fclose (file: PtrFILE): INTEGER "fclose((FILE*)file)";
PROCEDURE -unlink (filename: PtrSTR): INTEGER "unlink(filename)"; (* IF = 0 THEN OK. *)
PROCEDURE -rename (oldname, newname: PtrSTR): INTEGER "rename(oldname, newname)";

PROCEDURE ^ (VAR file: File) Close* ;

(*
   OpenToRead - attempts to open a file, fname, for reading and
                it returns this file.
                The success of this operation can be checked by
                calling file.error.
*)
PROCEDURE (VAR file: File) OpenToRead* (fname: STRING);
  (** UNSAFE! Make sure that value of array 'fname' is null-terminated. *)
BEGIN
  file.handle := fopen(fname, "rb");
  IF file.handle # NULL() THEN
    file.prevbyte := fgetc(file.handle);
    IF file.prevbyte # EOF() THEN
      file.end := FALSE;
      file.error := FALSE; (* Reset this flag ONCE. *)
      (* file.state := Successful; *)
    ELSE
      file.end := feof(file.handle) # 0;
      file.error := ferror(file.handle) # 0;
      IF file.error THEN file.Close END;
    END;
  ELSE
    file.end := TRUE;
    file.error := TRUE; (* file.state := Failed; *)
  END;
END OpenToRead;

(*
   OpenToWrite - attempts to open a file, fname, for write and
                 it returns this file.
                 The success of this operation can be checked by
                 calling file.error.
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

PROCEDURE (VAR fromfile: FileToRead) ReadByte* (): BYTE;
VAR
  result: INTEGER;
BEGIN
  IF fromfile.end OR fromfile.error THEN
    RETURN SHORT(EOF()) (* To safe work after error. *)
  END;
  result := fromfile.prevbyte;
  fromfile.prevbyte := fgetc(fromfile.handle);
  IF fromfile.prevbyte = EOF() THEN (* EOF or error: *)
    fromfile.end := feof(fromfile.handle) # 0;
    fromfile.error := ferror(fromfile.handle) # 0;
    (* fromfile.state := Failed; *)
  END;
  RETURN SHORT(result)
END ReadByte;

PROCEDURE (VAR fromfile: FileToRead) ReadStr* (VAR str: ARRAY OF CHAR);
VAR
  n: INTEGER; ch: CHAR;
BEGIN
  ASSERT(LEN(str) > 1, 1); n := 0;
  LOOP
    IF (n >= LEN(str) - 1) OR fromfile.end OR fromfile.error THEN EXIT END;
    ch := SYSTEM.VAL(CHAR, fromfile.ReadByte());
    IF ch = 0DX THEN
      IF SYSTEM.VAL(CHAR, fromfile.prevbyte) = 0AX THEN
        ch := SYSTEM.VAL(CHAR, fromfile.ReadByte());
      END;
      EXIT
    END;
    IF ch = 0AX THEN EXIT END;
    str[n] := ch; INC(n);
  END;
  str[n] := 0X;
END ReadStr;

PROCEDURE (VAR tofile: FileToWrite) WriteByte* (byte: BYTE);
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

PROCEDURE (VAR tofile: FileToWrite) WriteStr* (str: STRING);
VAR
  n: LONGINT;
BEGIN
  n := 0;
  WHILE (n < LEN(str)) & (str[n] # 0X) DO
    tofile.WriteByte(str[n]);
    IF tofile.error THEN RETURN END; (* To safe work after error. *)
    INC(n);
  END;
END WriteStr;

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

PROCEDURE RenameFile* (IN oldname, newname: ARRAY OF CHAR): BOOLEAN;
  (** UNSAFE! Make sure that value of array 'fname' is null-terminated. *)
BEGIN
  RETURN rename(oldname, newname) = 0
END RenameFile;

END Files.

(* TODO:
  implement ReadBytes, WriteBytes (fread/fwrite)
  implement Rename (rename или fopen/fread/fwrite/fclose/unlink)
*)
