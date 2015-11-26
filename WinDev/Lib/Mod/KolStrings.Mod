(*//[START OF KOL.pas]*)
(****************************************************************

				KKKKK		KKKKK		OOOOOOOOO		LLLLL
				KKKKK		KKKKK	OOOOOOOOOOOOO	LLLLL
				KKKKK		KKKKK	OOOOO	 OOOOO	LLLLL
				KKKKK	KKKKK		OOOOO	 OOOOO	LLLLL
				KKKKKKKKKK			OOOOO	 OOOOO	LLLLL
				KKKKK	KKKKK		OOOOO	 OOOOO	LLLLL
				KKKKK		KKKKK	OOOOO	 OOOOO	LLLLL
				KKKKK		KKKKK	OOOOOOOOOOOOO	LLLLLLLLLLLLL
				KKKKK		KKKKK		OOOOOOOOO		LLLLLLLLLLLLL

	Key Objects Library (C) 2000 by Kladov Vladimir.

//[VERSION]
****************************************************************
* VERSION 2.94++
****************************************************************
//[END OF VERSION]

	K.O.L. - is a set of objects to create small programs
	with the Delphi, but without the VCL. KOL allows to
	create executables of size about 10 times smaller then
	those created with the VCL. But this does not mean that
	KOL is less power then the VCL - perhaps just the opposite...

	KOL is provided free with the source code.
	Copyright (C) Vladimir Kladov, 2000-2003.

	For code provided by other	developers (even if later
	changed by me) authors are noted in the source.

	mailto: bonanzas@online.sinor.ru
	Web-Page: http://bonanzas.rinet.ru

	See also Mirror Classes Kit (M.C.K.) which allows
	to create KOL programs visually.

****************************************************************)

MODULE KolStrings;
IMPORT SYSTEM, Typ := KolTypes;

TYPE
	Integer = Typ.Integer;
	KOLString = Typ.KOLString;
	PKOLString = Typ.PKOLString;(*
VAR
	PtrToEmptyKOLString-: PKOLString;*)

PROCEDURE Length* (IN str: KOLString): Integer;
	(* Returns the length of a null-terminated string in chars *)
VAR
	len, maxLen: Integer;
BEGIN
	maxLen := SHORT(LEN(str)); len := 0;
	WHILE (len < maxLen) & (str[len] # 0X) DO INC(len) END;
	RETURN len;
END Length;
(*
PROCEDURE Assign* (VAR str: PKOLString; IN value: KOLString);
	(* Assign the contents of 'value' to 'str'. *)
VAR
	valueLen: Integer;
BEGIN
	valueLen := Length(value) + 1;
	(* ?????? ????? ^^^ Length, ? ?? LEN ? *)
	(* LEN ???????, ?? ???? value - ???????? ?????? ? ?????? ???????? ???????,*)
	(* ?? Length ?????? ????? ??????, ? LEN - ?????? ??????. ??????? ???????: *)
	(* ????????? ????? ? ?????????????? ???????????? ???????? ???????? ?????? *)
	(* (????????? ??????? KOL ????? ??????? ???????? ?????? ? ??????? ??????) *)
	IF ((str # NIL) & (LEN(str^) < valueLen)) OR (str = NIL) THEN 
		NEW(str, valueLen)
	END;
	COPY(value, str^);
END Assign;
*)

PROCEDURE StrRScan* (IN str: KOLString; ch: CHAR): INTEGER;
VAR
 count, index: INTEGER;
BEGIN
  count := Length(str);
  IF ch = 0X THEN RETURN count END;
  FOR index := count-1 TO 0 BY -1 DO
    IF ch = str[index] THEN RETURN index END;
  END;
  RETURN -1
END StrRScan;

PROCEDURE DelimiterLast* (IN str, delimiters: KOLString): INTEGER;
VAR
  delimiterN, f, result: INTEGER;
BEGIN
  delimiterN := 0; result := Length(str);
  WHILE delimiters[delimiterN] # 0X DO
    f := StrRScan(str, delimiters[delimiterN]);
    IF f # -1 THEN
      IF (str[result] = 0X) OR (f > result) THEN result := f END;
    END;
    INC(delimiterN);
  END;
  RETURN result
END DelimiterLast;

PROCEDURE SubStr* (
  IN s: ARRAY OF CHAR; pos, len: INTEGER; VAR res: ARRAY OF CHAR): BOOLEAN;
VAR
  i, j, max: INTEGER;
BEGIN
	ASSERT(len >= 0, 20); ASSERT(pos >= 0, 21);
	i := 0; j := 0; max := SHORT(LEN(res)) - 1;
	WHILE (i < pos) & (s[i] # 0X) DO INC(i) END;
	WHILE (j < len) & (j < max) & (s[i] # 0X) DO
	  res[j] := s[i]; INC(j); INC(i);
	END;
	res[j] := 0X;
  IF s[i] = 0X THEN len := j-1 END;
	RETURN len < max
END SubStr;

PROCEDURE- _init* "/*-noinit*/";
(*
BEGIN
	NEW(PtrToEmptyKOLString, 1); PtrToEmptyKOLString^[0] := 0X;*)
END KolStrings.