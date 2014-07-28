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
PROCEDURE- _init* "/*-noinit*/";
(*
BEGIN
	NEW(PtrToEmptyKOLString, 1); PtrToEmptyKOLString^[0] := 0X;*)
END KolStrings.