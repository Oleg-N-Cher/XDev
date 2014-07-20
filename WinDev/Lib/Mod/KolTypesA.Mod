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

MODULE KolTypesA; (* nonportable (Win32) *)
IMPORT SYSTEM, WinApi;

	CONST (* For SystemString from BlackBox *)
		charCode* = -1; decimal* = 10; hexadecimal* = -2; roman*= -3;
		digitspace* = 08FX;
		showBase* = TRUE; hideBase* = FALSE;
		minLongIntRev = "8085774586302733229";	(* reversed string of -MIN(LONGINT) *)

TYPE
  SHORTCHAR = CHAR;
  BYTE* = SYSTEM.BYTE;
	AnsiString* = ARRAY OF SHORTCHAR;
	Double* = REAL; (* 64 bit *)
	DWORD* = INTEGER; (* 32 bit *)
	Integer* = INTEGER; (* 32 bit *)
	KOLChar* = SHORTCHAR;
	PByte* = SYSTEM.PTR;
	PKOLChar* = POINTER TO ARRAY[1] OF KOLChar;
	KOLString* = ARRAY OF KOLChar;
	PKOLString* = POINTER TO KOLString;
	TDateTime* = Double;
	THandle* = WinApi.HANDLE;
	(* Single = SHORTREAL 32 bit *)

	VAR eps, e: REAL; (* For SystemMath from BlackBox *)
		maxExp: INTEGER; (* For SystemString from BlackBox *)
		maxDig: INTEGER;
		factor: REAL;	(* 10^maxDig *)
		digits: ARRAY 17 OF CHAR;
		toUpper, toLower: ARRAY 256 OF CHAR;
(*
PROCEDURE ^ Int2Str* (value: Integer): PKOLString;
(* Obvious. *)
PROCEDURE ^ Str2Int* (IN value: KOLString): Integer;
(* Converts string to integer. First character, which can not be
	 recognized as a part of number, regards as a separator. Even
	 empty string or string without number silently converted to 0. *)

(*//[String<->Double DECLARATIONS]*)
PROCEDURE ^ Str2Double* (IN s: KOLString): Double;
(* *)
PROCEDURE ^ Double2Str* (d: Double): PKOLString;
(* *)
*)
(* Temporarily used SystemMath from BlackBox
	 Copyright (c) Oberon microsystems *)
(*MODULE Math;*)
(**
	project	= "BlackBox"
	organization	= "www.oberon.ch"
	contributors	= "Oberon microsystems"
	version	= "System/Rsrc/About"
	copyright	= "System/Rsrc/About"
	license	= "Docu/BB-License"
	changes	= ""
	issues	= ""

**)

	(* code procedures for 80387 math coprocessor *)
(*
	PROCEDURE [code] FLD (x: REAL);
	PROCEDURE [code] TOP (): REAL;
	PROCEDURE [code] FSW (): INTEGER 0DFH, 0E0H;
	PROCEDURE [code] FSWs (): SET 0DFH, 0E0H;
	PROCEDURE [code] ST0 (): REAL 0D9H, 0C0H;
	PROCEDURE [code] ST1 (): REAL 0D9H, 0C1H;

	PROCEDURE [code] FXCH 0D9H, 0C9H;
	PROCEDURE [code] FLDst0 0D9H, 0C0H;	(* doublicate st[0] *)
	PROCEDURE [code] FSTPst0 0DDH, 0D8H;	(* remove st[0] *)
	PROCEDURE [code] FSTPst1 0DDH, 0D9H;	(* remove st[1] *)
	PROCEDURE [code] FSTPDe 0DBH, 05DH, 0F4H;	(* FSTPD -12[FP] *)	(* COMPILER DEPENDENT *)
	PROCEDURE [code] WAIT 09BH;
	PROCEDURE [code] FNOP 0D9H, 0D0H;

	PROCEDURE [code] FLD0 0D9H, 0EEH;
	PROCEDURE [code] FLD1 0D9H, 0E8H;
	PROCEDURE [code] FLDPI 0D9H, 0EBH;
	PROCEDURE [code] FLDLN2 0D9H, 0EDH;
	PROCEDURE [code] FLDLG2 0D9H, 0ECH;
	PROCEDURE [code] FLDL2E 0D9H, 0EAH;

	PROCEDURE [code] FADD 0DEH, 0C1H;
	PROCEDURE [code] FADDst0 0D8H, 0C0H;
	PROCEDURE [code] FSUB 0DEH, 0E9H;
	PROCEDURE [code] FSUBn 0DCH, 0E9H;	(* no pop *)
	PROCEDURE [code] FSUBR 0DEH, 0E1H;
	PROCEDURE [code] FSUBst1 0D8H, 0E1H;
	PROCEDURE [code] FMUL 0DEH, 0C9H;
	PROCEDURE [code] FMULst0 0D8H, 0C8H;
	PROCEDURE [code] FMULst1st0 0DCH, 0C9H;
	PROCEDURE [code] FDIV 0DEH, 0F9H;
	PROCEDURE [code] FDIVR 0DEH, 0F1H;
	PROCEDURE [code] FDIVRst1 0D8H, 0F9H;
	PROCEDURE [code] FCHS 0D9H, 0E0H;

	PROCEDURE [code] FCOM 0D8H, 0D1H;
	PROCEDURE [code] FSWax 0DFH, 0E0H;
	PROCEDURE [code] SAHF 09EH;
	PROCEDURE [code] JBE4 076H, 004H;
	PROCEDURE [code] JAE4 073H, 004H;

	PROCEDURE [code] FRNDINT 0D9H, 0FCH;
	PROCEDURE [code] FSCALE 0D9H, 0FDH;	(* st[0] * 2^FLOOR(st[1]) *)
	PROCEDURE [code] FXTRACT 0D9H, 0F4H;	(* exp -> st[1]; mant -> st[0] *)
	PROCEDURE [code] FXAM 0D9H, 0E5H;

	PROCEDURE [code] FSQRT 0D9H, 0FAH;	(* st[0] >= 0 *)
	PROCEDURE [code] FSIN 0D9H, 0FEH;	(* |st[0]| < 2^63 *)
	PROCEDURE [code] FCOS 0D9H, 0FFH;	(* |st[0]| < 2^63 *)
	PROCEDURE [code] FTAN 0D9H, 0F2H;	(* |st[0]| < 2^63 *)
	PROCEDURE [code] FATAN 0D9H, 0F3H;	(* atan2(st[1], st[0]) *)
	PROCEDURE [code] FYL2X 0D9H, 0F1H;	(* st[1] * log2(st[0]), st[0] > 0 *)
	PROCEDURE [code] FYL2XP1 0D9H, 0F9H;	(* st[1] * log2(1 + st[0]), |st[0]| < 1-sqrt(2)/2 *)
	PROCEDURE [code] F2XM1 0D9H, 0F0H;	(* 2^st[0] - 1, |st[0]| <= 1 *)

	(** REAL precision **)

	PROCEDURE Eps* (): REAL;
	BEGIN
		RETURN eps
	END Eps;

	PROCEDURE Log* (x: REAL): REAL;
	BEGIN
		(* 20, argument of Log must not be negative *)
		(* log(2) * ld(x) *)
		FLDLG2; FLD(x); FYL2X; WAIT; RETURN TOP()
	END Log;

	PROCEDURE IntPower* (x: REAL; n: INTEGER): REAL;
	BEGIN 
		FLD1; FLD(x);
		IF n = MIN(INTEGER) THEN RETURN IntPower(x, n + 1) / x END;
		IF n <= 0 THEN FDIVRst1; (* 1 / x *) n := -n END;
		WHILE n > 0 DO
			IF ODD(n) THEN FMULst1st0; (* y := y * x *) DEC(n)
			ELSE FMULst0; (* x := x * x *) n := n DIV 2
			END
		END;
		FSTPst0; RETURN TOP()
	END IntPower;

	PROCEDURE Mantissa* (x: REAL): REAL;
	BEGIN
		FLD(x); FXAM; WAIT;
		CASE FSW() DIV 256 MOD 8 OF
		| 4, 6: FXTRACT; FSTPst1; RETURN TOP()
		| 0, 2: FSTPst0; RETURN 0.0	(* zero *)
		| 5: FSTPst0; RETURN 1.0	(* inf *)
		| 7: FSTPst0; RETURN -1.0	(* -inf *)
		| 1: FSTPst0; RETURN 1.5	(* nan *)
		| 3: FSTPst0; RETURN -1.5	(* -nan *)
		END
	END Mantissa;

	PROCEDURE Exponent* (x: REAL): INTEGER;	(* COMPILER DEPENDENT *)
		VAR e: INTEGER;	(* e is set by FSTPDe! *)
	BEGIN
		FLD(x); FXAM; WAIT;
		CASE FSW() DIV 256 MOD 8 OF
		| 4, 6: FXTRACT; FSTPst0; FSTPDe; WAIT; RETURN e
		| 0, 2: FSTPst0; RETURN 0	(* zero *)
		| 1, 3, 5, 7: FSTPst0; RETURN MAX(INTEGER)	(* inf or nan*)
		END
	END Exponent;

(*END *)

(* Temporarily used SystemStrings from BlackBox
	 Copyright (c) Oberon microsystems *)
(*MODULE Strings;*)
(**
	project	= "BlackBox"
	organization	= "www.oberon.ch"
	contributors	= "Oberon microsystems"
	version	= "System/Rsrc/About"
	copyright	= "System/Rsrc/About"
	license	= "Docu/BB-License"
	changes	= ""
	issues	= ""

**)

	(* integer conversions *)
*)
	PROCEDURE IntToString (x: LONGINT; VAR s: ARRAY OF SHORTCHAR);
		CONST minLongIntRev = "8085774586302733229";	(* reversed string of -MIN(LONGINT) *)
		VAR j, k: INTEGER; ch: SHORTCHAR; a: ARRAY 32 OF SHORTCHAR;
	BEGIN
		IF x # MIN(LONGINT) THEN
			IF x < 0 THEN s[0] := "-"; k := 1; x := -x ELSE k := 0 END;
			j := 0; REPEAT a[j] := CHR(x MOD 10 + ORD("0")); x := x DIV 10; INC(j) UNTIL x = 0
		ELSE
			a := minLongIntRev; s[0] := "-"; k := 1;
			j := 0; WHILE a[j] # 0X DO INC(j) END
		END;
		ASSERT(k + j < LEN(s), 23);
		REPEAT DEC(j); ch := a[j]; s[k] := ch; INC(k) UNTIL j = 0;
		s[k] := 0X
	END IntToString;

	PROCEDURE StringToInt (IN s: ARRAY OF SHORTCHAR; VAR x: INTEGER; VAR res: INTEGER);
		CONST hexLimit = MAX(INTEGER) DIV 8 + 1;
		VAR i, j, k, digits: INTEGER; ch, top: SHORTCHAR; neg: BOOLEAN; base: INTEGER;
	BEGIN
		res := 0; i := 0; ch := s[0];
		WHILE (ch # 0X) & (ch <= " ") OR (ch = 8BX) OR (ch = 8FX) OR (ch = 0A0X) DO	(* ignore leading blanks *)
			INC(i); ch := s[i]
		END;
		j := i; top := "0";
		WHILE (ch # 0X) & (ch # "H") & (ch # "X") & (ch # "%") DO 
			IF ch > top THEN top := ch END;
			INC(j); ch := s[j]
		END;
		IF (ch = "H") OR (ch = "X") THEN
			x := 0; ch := s[i];
			IF ("0" <= ch) & (ch <= "9") OR ("A" <= ch) & (ch <= "F") THEN
				WHILE ch = "0" DO INC(i); ch := s[i] END;
				digits := 0;
				WHILE (res = 0) & (("0" <= ch) & (ch <= "9") OR ("A" <= ch) & (ch <= "F")) DO
					IF ch < "A" THEN k := ORD(ch) - ORD("0")
					ELSE k := ORD(ch) - ORD("A") + 10
					END;
					IF digits < 8 THEN
						x := x MOD hexLimit;
						IF x >= hexLimit DIV 2 THEN x := x - hexLimit END;
						x := x * 16 + k; INC(i); ch := s[i]
					ELSE res := 1
					END;
					INC(digits)
				END;
				IF res = 0 THEN
					IF (ch # "H") & (ch # "X") OR (s[i+1] # 0X) THEN res := 2 END
				END
			ELSE res := 2
			END
		ELSE
			IF ch = "%" THEN
				INC(j); ch := s[j]; base := 0;
				IF ("0" <= ch) & (ch <= "9") THEN
					k := ORD(ch) - ORD("0");
					REPEAT
						base := base * 10 + k;
						INC(j); ch := s[j]; k := ORD(ch) - ORD("0")
					UNTIL (ch < "0") OR (ch > "9") OR (base > (MAX(INTEGER) - k) DIV 10);
					IF ("0" <= ch) & (ch <= "9") THEN base := 0 END
				END
			ELSE
				base := 10
			END;
			
			IF (base < 2) OR (base > 16) THEN
				res := 2
			ELSIF (base <= 10) & (ORD(top) < base + ORD("0"))
			OR (base > 10) & (ORD(top) < base - 10 + ORD("A")) THEN
				x := 0; ch := s[i]; neg := FALSE;
				IF ch = "-" THEN INC(i); ch := s[i]; neg := TRUE ELSIF ch = "+" THEN INC(i); ch := s[i] END;
				WHILE (ch # 0X) & (ch <= " ") DO INC(i); ch := s[i] END; 
				IF ("0" <= ch) & (ch <= "9") OR ("A" <= ch) & (ch <= "F") THEN
					IF ch <= "9" THEN k := ORD(ch) - ORD("0") ELSE k := ORD(ch) - ORD("A") + 10 END;
					WHILE (("0" <= ch) & (ch <= "9") OR ("A" <= ch) & (ch <= "F")) & (res = 0) DO
						IF x >= (MIN(INTEGER) + (base - 1) + k) DIV base THEN
							x := x * base - k; INC(i); ch := s[i];
							IF ch <= "9" THEN k := ORD(ch) - ORD("0") ELSE k := ORD(ch) - ORD("A") + 10 END
						ELSE res := 1
						END
					END
				ELSE res := 2
				END;
				IF res = 0 THEN
					IF ~neg THEN
						IF x > MIN(INTEGER) THEN x := -x ELSE res := 1 END
					END;
					IF (ch # 0X) & (ch # "%") THEN res := 2 END
				END
			ELSE
				res := 2
			END
		END
	END StringToInt;
(*
	(* real conversions *)

	PROCEDURE RealToStringForm (x: REAL; precision, minW, expW: INTEGER; fillCh: SHORTCHAR;
														OUT s: ARRAY OF SHORTCHAR);
		VAR exp, len, i, j, n, k, p: INTEGER; m: ARRAY 80 OF SHORTCHAR; neg: BOOLEAN;
		maxDig, maxExp: INTEGER; factor: REAL;	(* 10^maxDig *)
	BEGIN
		maxDig := SHORT(ENTIER(-Log(Eps())));
		maxExp := SHORT(ENTIER(Log(MAX(REAL)))) + 1;
		factor := IntPower(10, maxDig);

		ASSERT((precision > 0) (*& (precision <= 18)*), 20);
		ASSERT((minW >= 0) & (minW < LEN(s)), 21);
		ASSERT((expW > -LEN(s)) & (expW <= 3), 22);
		exp := Exponent(x);
		IF exp = MAX(INTEGER) THEN
			IF fillCh = "0" THEN fillCh := digitspace END;
			x := Mantissa(x);
			IF x = -1 THEN m := "-inf"; n := 4
			ELSIF x = 1 THEN m := "inf"; n := 3
			ELSE m := "nan"; n := 3
			END;
			i := 0; j := 0;
			WHILE minW > n DO s[i] := fillCh; INC(i); DEC(minW) END;
			WHILE (j <= n) & (i < LEN(s)) DO s[i] := m[j]; INC(i); INC(j) END
		ELSE
			neg := FALSE; len := 1; m := "00";
			IF x < 0 THEN x := -x; neg := TRUE; DEC(minW) END;
			IF x # 0 THEN
				exp := (exp - 8) * 30103 DIV 100000;	(* * log(2) *)
				IF exp > 0 THEN
					n := SHORT(ENTIER(x / IntPower(10, exp)));
					x := x / IntPower(10, exp) - n
				ELSIF exp > -maxExp THEN
					n := SHORT(ENTIER(x * IntPower(10, -exp)));
					x := x * IntPower(10, -exp) - n
				ELSE
					n := SHORT(ENTIER(x * IntPower(10, -exp - 2 * maxDig) * factor * factor));
					x := x * IntPower(10, -exp - 2 * maxDig) * factor * factor - n
				END;
				(* x0 = (n + x) * 10^exp, 200 < n < 5000 *)
				p := precision - 4;
				IF n < 1000 THEN INC(p) END;
				IF (expW < 0) & (p > exp - expW) THEN p := exp - expW END;
				IF p >= 0 THEN
					x := x + 0.5 / IntPower(10, p);	(* rounding correction *)
					IF x >= 1 THEN INC(n); x := x - 1 END
				ELSIF p = -1 THEN INC(n, 5)
				ELSIF p = -2 THEN INC(n, 50)
				ELSIF p = -3 THEN INC(n, 500)
				END;
				i := 0; k := 1000; INC(exp, 3);
				IF n < 1000 THEN k := 100; DEC(exp) END;
				WHILE (i < precision) & ((k > 0) OR (x # 0)) DO
					IF k > 0 THEN p := n DIV k; n := n MOD k; k := k DIV 10
					ELSE x := x * 10; p := SHORT(ENTIER(x)); x := x - p
					END;
					m[i] := SHORT(CHR(p + ORD("0"))); INC(i);
					IF p # 0 THEN len := i END
				END
			END;
			(* x0 = m[0].m[1]...m[len-1] * 10^exp *)
			i := 0;
			IF (expW < 0) OR (expW = 0) & (exp >= -3) & (exp <= len + 1) THEN
				n := exp + 1; k := len - n;
				IF n < 1 THEN n := 1 END;
				IF expW < 0 THEN k := -expW ELSIF k < 1 THEN k := 1 END;
				j := minW - n - k - 1; p := -exp;
				IF neg & (p >= MAX(0, n) + MAX(0, k)) THEN neg := FALSE; INC(j) END
			ELSE
				IF ABS(exp) >= 100 THEN expW := 3
				ELSIF (expW < 2) & (ABS(exp) >= 10) THEN expW := 2
				ELSIF expW < 1 THEN expW := 1
				END;
				IF len < 2 THEN len := 2 END;
				j := minW - len - 3 - expW; k := len;
				IF j > 0 THEN
					k := k + j; j := 0;
					IF k > precision THEN j := k - precision; k := precision END
				END;
				n := 1; DEC(k); p := 0
			END;
			IF neg & (fillCh = "0") THEN s[i] := "-"; INC(i); neg := FALSE END;
			WHILE j > 0 DO s[i] := fillCh; INC(i); DEC(j) END;
			IF neg & (i < LEN(s)) THEN s[i] := "-"; INC(i) END;
			j := 0;
			WHILE (n > 0) & (i < LEN(s)) DO
				IF (p <= 0) & (j < len) THEN s[i] := m[j]; INC(j) ELSE s[i] := "0" END;
				INC(i); DEC(n); DEC(p)
			END;
			IF i < LEN(s) THEN s[i] := "."; INC(i) END;
			WHILE (k > 0) & (i < LEN(s)) DO
				IF (p <= 0) & (j < len) THEN s[i] := m[j]; INC(j) ELSE s[i] := "0" END;
				INC(i); DEC(k); DEC(p)
			END;
			IF expW > 0 THEN
				IF i < LEN(s) THEN s[i] := "E"; INC(i) END;
				IF i < LEN(s) THEN
					IF exp < 0 THEN s[i] := "-"; exp := -exp ELSE s[i] := "+" END;
					INC(i)
				END;
				IF (expW = 3) & (i < LEN(s)) THEN s[i] := SHORT(CHR(exp DIV 100 + ORD("0"))); INC(i) END;
				IF (expW >= 2) & (i < LEN(s)) THEN s[i] := SHORT(CHR(exp DIV 10 MOD 10 + ORD("0"))); INC(i) END;
				IF i < LEN(s) THEN s[i] := SHORT(CHR(exp MOD 10 + ORD("0"))); INC(i) END
			END
		END;
		IF i < LEN(s) THEN s[i] := 0X ELSE HALT(23) END
	END RealToStringForm;

	PROCEDURE RealToString (x: REAL; OUT s: ARRAY OF SHORTCHAR);
	BEGIN
		RealToStringForm(x, 16, 0, 0, digitspace, s)
	END RealToString;

	PROCEDURE StringToReal (IN s: ARRAY OF SHORTCHAR; OUT x: REAL; OUT res: INTEGER);
		VAR first, last, point, e, n, i, exp: INTEGER; y: REAL; ch: SHORTCHAR; neg, negExp, dig: BOOLEAN;
	BEGIN
		maxDig := SHORT(ENTIER(-Log(Eps())));
		maxExp := SHORT(ENTIER(Log(MAX(REAL)))) + 1;
		factor := IntPower(10, maxDig);

		res := 0; i := 0; ch := s[0]; dig := FALSE;
		WHILE (ch # 0X) & (ch <= " ") OR (ch = 8BX) OR (ch = 8FX) OR (ch = 0A0X) DO INC(i); ch := s[i] END;
		IF ch = "+" THEN
			neg := FALSE; INC(i); ch := s[i]
		ELSIF ch = "-" THEN
			neg := TRUE; INC(i); ch := s[i]
		ELSE
			neg := FALSE
		END;
		WHILE ch = "0" DO INC(i); ch := s[i]; dig := TRUE END;
		first := i; e := 0;
		WHILE ("0" <= ch) & (ch <= "9") DO INC(i); ch := s[i]; INC(e); dig := TRUE END;
		point := i;
		IF ch = "." THEN
			INC(i); ch := s[i];
			IF e = 0 THEN
				WHILE ch = "0" DO INC(i); ch := s[i]; DEC(e); dig := TRUE END;
				first := i
			END;
			WHILE ("0" <= ch) & (ch <= "9") DO INC(i); ch := s[i]; dig := TRUE END
		END;
		last := i - 1; exp := 0;
		IF (ch = "E") OR (ch = "D") THEN
			INC(i); ch := s[i]; negExp := FALSE;
			IF ch = "-" THEN negExp := TRUE; INC(i); ch := s[i]
			ELSIF ch = "+" THEN INC(i); ch := s[i]
			END;
			WHILE ("0" <= ch) & (ch <= "9") & (exp < 1000) DO
				exp := exp * 10 + (ORD(ch) - ORD("0"));
				INC(i); ch := s[i]
			END;
			IF negExp THEN exp := -exp END
		END;
		exp := exp + e; x := 0; y := 0; n := 0; 
		WHILE (n < maxDig) & (first <= last) DO
			IF first # point THEN x := x * 10 + (ORD(s[first]) - ORD("0")); INC(n) END;
			INC(first)
		END;
		WHILE last >= first DO
			IF last # point THEN y := (y + (ORD(s[last]) - ORD("0"))) / 10 END;
			DEC(last)
		END;
		IF ~dig OR (ch # 0X) THEN res := 2	(* syntax error *)
		ELSIF exp < -maxExp - maxDig THEN
			x := 0.0
		ELSIF exp < -maxExp + maxDig THEN
			x := (x + y) / IntPower(10, n - exp - 2 * maxDig) / factor / factor
		ELSIF exp < n THEN
			x := (x + y) / IntPower(10, n - exp)
		ELSIF exp < maxExp THEN
			x := (x + y) * IntPower(10, exp - n)
		ELSIF exp = maxExp THEN
			x := (x + y) * (IntPower(10, exp - n) / 16);
			IF x <= MAX(REAL) / 16 THEN x := x * 16
			ELSE res := 1	(* overflow *)
			END
		ELSE res := 1	(* overflow *)
		END;
		IF neg THEN x := -x END
	END StringToReal;

	(* ----------------------------- string manipulation routines --------------------------- *)

	PROCEDURE Init;
		VAR i: INTEGER;
	BEGIN
		FOR i := 0 TO 255 DO toUpper[i] :=	CHR(i); toLower[i] := CHR(i) END;
		FOR i := ORD("A") TO ORD("Z") DO toLower[i] := CHR(i + 32); toUpper[i + 32] := CHR(i) END;
		FOR i := ORD("À") TO ORD ("Ö") DO toLower[i] := CHR(i + 32); toUpper[i + 32] := CHR(i) END;
		FOR i := ORD("Ø") TO ORD ("Þ") DO toLower[i] := CHR(i + 32); toUpper[i + 32] := CHR(i) END;
		digits := "0123456789ABCDEF"; 
		maxExp := SHORT(ENTIER(Log(MAX(REAL)))) + 1;
		maxDig := SHORT(ENTIER(-Log(Eps())));
		factor := IntPower(10, maxDig)
	END Init;
(*END Strings.*)
*)
(*
(*//[FUNCTION Bool2Int]*)
PROCEDURE Bool2Int (value: BOOLEAN): Integer;
BEGIN
	RETURN SYSTEM.VAL(BYTE, value)
END Bool2Int;

(*//[FUNCTION Int2Bool]*)
PROCEDURE Int2Bool (value: Integer): BOOLEAN;
BEGIN
	RETURN (value # 0)
END Int2Bool;
*)
(*
(*//[FUNCTION Int2Str]*)
(*-$IFDEF ASM_VERSION*)
(*-$ELSE ASM_VERSION} //Pascal *)
PROCEDURE Int2Str* (value: Integer): PKOLString;
(* Temporarily used SystemStrings.IntToString from BlackBox
	 Copyright (c) Oberon microsystems *)
VAR strPtr: POINTER TO KOLString;
BEGIN NEW(strPtr, 16); IntToString(value, strPtr^); RETURN strPtr
(*
var Buf : Array[ 0..15 ] of AnsiChar;
		Dst : PAnsiChar;
		Minus : Boolean;
		D: DWORD;
begin
	Dst := @Buf[ 15 ];
	Dst^ := #0;
	Minus := False;
	if Value < 0 then
	begin
		Value := -Value;
		Minus := True;
	end;
	D := Value;
	repeat
		Dec( Dst );
		Dst^ := AnsiChar( (D mod 10) + Byte( '0' ) );
		D := D div 10;
	until D = 0;
	if Minus then
	begin
		Dec( Dst );
		Dst^ := '-';
	end;
	Result := Dst;
end;
{$ENDIF ASM_VERSION}
*)
END Int2Str;

(*//[END Int2Str]*)

(*//[FUNCTION S2Int]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function S2Int( S: PAnsiChar ): Integer;
var M : Integer;
begin
	 Result := 0;
	 if S = '' then Exit;
	 M := 1;
	 if S^ = '-' then
	 begin
			M := -1;
			Inc( S );
	 end
		 else
	 if S^ = '+' then
		 Inc( S );
	 while S^ in [ '0'..'9' ] do
	 begin
			Result := Result * 10 + Integer( S^ ) - Integer( '0' );
			Inc( S );
	 end;
	 if M < 0 then
			Result := -Result;
end;
{$ENDIF ASM_VERSION}
//[END S2Int]*)

(*//[FUNCTION Str2Int]*)
(*-$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal *)
PROCEDURE Str2Int* (IN value: KOLString): Integer;
(* Temporarily used SystemStrings.StringToInt from BlackBox
	 Copyright (c) Oberon microsystems *)
VAR result, err: INTEGER;
BEGIN StringToInt(value, result, err);
CASE err OF
	1 (*for overflow*), 2 (*for syntax error*) : result := 0 ELSE END;
RETURN result
(*
function Str2Int(const Value : AnsiString) : Integer;
begin
	Result := S2Int( PAnsiChar( Value ) );
end;*)
(*-$ENDIF ASM_VERSION*)
(*//[END Str2Int]*)
END Str2Int;

(*//[FUNCTION Str2Double]*)
PROCEDURE Str2Double* (IN s: KOLString): Double;
	VAR result: Double; err: INTEGER;
(* Temporarily used SystemStrings.StringToReal from BlackBox
	 Copyright (c) Oberon microsystems *)
BEGIN StringToReal(s, result, err);
CASE err OF
	1 (*for overflow*), 2 (*for syntax error*) : result := 0.0 ELSE END;
RETURN result
END Str2Double;
(*
function Str2Double( const S: AnsiString ): Double;
var I: Integer;
		M, Pt: Boolean;
		D: Double;
		Ex: Integer;
begin
	Result := 0.0;
	if S = '' then Exit;
	M := FALSE;
	I := 1;
	if S[ 1 ] = '-' then
	begin
		M := TRUE;
		Inc( I );
	end;
	Pt := FALSE;
	D := 1.0;
	while I <= Length( S ) do
	begin
		case S[ I ] of
		'.': if not Pt then Pt := TRUE else break;
		'0'..'9': if not Pt then
								 Result := Result * 10.0 + Integer( S[ I ] ) - Integer( '0' )
							else
							begin
								D := D * 0.1;
								Result := Result + (Integer( S[ I ] ) - Integer( '0' )) * D;
							end;
		'e', 'E': begin
								Ex := Str2Int( CopyEnd( S, I + 1 ) );
								Result := Result * IntPower( 10.0, Ex );
								break;
							end;
		end;
		Inc( I );
	end;
	if M then
		Result := -Result;
end;
*)

(*//[function Double2Str]*)
PROCEDURE Double2Str* (d: Double): POINTER TO KOLString;
VAR result: POINTER TO KOLString;
(*begin
	Result := Extended2Str( D );*)
(* Temporarily used SystemStrings.RealToStringsForm from BlackBox
	 Copyright (c) Oberon microsystems *)
BEGIN NEW(result, 25); RealToString(d, result^);
RETURN result
END Double2Str;

BEGIN
	eps := 1.0E+0; e := 2.0E+0;
	WHILE e > 1.0E+0 DO eps := eps/2.0E+0; e := 1.0E+0 + eps END; eps := 2.0E+0 * eps;
	Init*)
PROCEDURE- _init* "/*-noinit*/";

END KolTypesA.