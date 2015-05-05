MODULE Strings;

IMPORT SYSTEM;

CONST
  CharCode* = -1; Decimal* = 10; Hexadecimal* = -2; Roman*= -3;

TYPE
  STRLEN = INTEGER;
  PtrSTR = ARRAY OF CHAR;

PROCEDURE -includestdio()	"#include <stdio.h>";
(*PROCEDURE -includestring()	"#include <string.h>";*)

PROCEDURE -sprintf (str: PtrSTR; n: LONGINT)	'sprintf(str, "%ld", n)'; 
PROCEDURE -sprintfL (str: PtrSTR; n: LONGINT)	'sprintf(str, "%lld", n)';
(*PROCEDURE -Length* (str: PtrSTR): STRLEN	"strlen(str)";*)

PROCEDURE Length* (IN str: ARRAY OF CHAR): STRLEN;
VAR
  len: STRLEN;
BEGIN
  len := 0;
  WHILE (len < SHORT(LEN(str))) & (str[len] # 0X) DO INC(len) END;
  RETURN len
END Length;

(** This function returns the position of the <pattern> in the string <str>.
    If <pattern> does not occur in <str> -1 is returned. If the <pattern>
    occurs several times the position of the first occurrence is returned. *)
PROCEDURE Find* (IN str, pattern: ARRAY OF CHAR; start: INTEGER): INTEGER;
VAR
  j, pos: INTEGER;
BEGIN
  IF start < 0 THEN start := 0 END;
  IF (start = 0) OR (start <= Length(str) - Length(pattern)) THEN
    (* start = 0 is optimization: need not call Len *)
    pos := start;
    WHILE str[pos] # 0X DO j := 0;
      WHILE (str[pos+j] = pattern[j]) & (pattern[j] # 0X) DO INC(j) END;
      IF pattern[j] = 0X THEN RETURN pos END;
      INC(pos);
    END;
  END;
  RETURN -1 (* pattern not found *)
END Find;

PROCEDURE IntToStr* (n: INTEGER; VAR str: ARRAY OF CHAR);
  (** UNSAFE! Make sure that size of array 'str' is enough. *)
BEGIN
  IF SIZE(INTEGER) = 4 THEN sprintf(str, n) END;
  IF SIZE(INTEGER) = 8 THEN sprintfL(str, n) END;
END IntToStr;

PROCEDURE LIntToStr* (n: LONGINT; VAR str: ARRAY OF CHAR);
  (** UNSAFE! Make sure that size of array 'str' is enough. *)
BEGIN
  IF SIZE(LONGINT) = 4 THEN sprintf(str, n) END;
  IF SIZE(LONGINT) = 8 THEN sprintfL(str, n) END;
END LIntToStr;

PROCEDURE IntToStrForm* (
  x: INTEGER; form, minWidth: INTEGER; fillCh: CHAR;
  showBase: BOOLEAN; VAR(*OUT*) s: ARRAY OF CHAR);
VAR
  base, i, j, k, si: INTEGER; mSign: BOOLEAN;
  a: ARRAY 128 OF CHAR; c1, c5, c10: CHAR; digits: ARRAY 17 OF CHAR;
BEGIN
  digits := "0123456789ABCDEF";
  ASSERT((form = CharCode) OR (form = Hexadecimal) OR
    (form = Roman) OR ((form >= 2) & (form <= 16)), 20);
  ASSERT(minWidth >= 0, 22);
  IF form = CharCode THEN base := 16
  ELSIF form = Hexadecimal THEN base := 16
  ELSE base := form
  END;
  
  IF form = Roman THEN
    ASSERT((x > 0) & (x < 3999), 21); 
    base := 1000; i := 0; mSign := FALSE;
    WHILE (base > 0) & (x > 0) DO
      IF base = 1 THEN c1 := "I"; c5 := "V"; c10 := "X"
      ELSIF base = 10 THEN c1 := "X"; c5 := "L"; c10 := "C"
      ELSIF base = 100 THEN c1 := "C"; c5 := "D"; c10 := "M"
      ELSE c1 := "M"
      END;
      k := SHORT(x DIV base); x := x MOD base;
      IF k IN {4, 9} THEN a[i] := c1; INC(i) END;
      IF k IN {4 .. 8} THEN a[i] := c5; INC(i) END;
      IF k = 9 THEN a[i] := c10; INC(i)
      ELSIF k IN {1 .. 3, 6 .. 8} THEN
        j := k MOD 5;
        REPEAT a[i] := c1; INC(i); DEC(j) UNTIL j = 0
      END;
      base := base DIV 10
    END
  ELSIF (form = Hexadecimal) OR (form = CharCode) THEN
    i := 0; mSign := FALSE;
    IF showBase THEN DEC(minWidth) END;
    REPEAT
      a[i] := digits[x MOD base]; x := x DIV base; INC(i)
    UNTIL (x = 0) OR (x = -1) OR (i = LEN(a));
    IF x = -1 THEN fillCh := "F" END
  ELSE
    IF x < 0 THEN
      i := 0; mSign := TRUE; DEC(minWidth);
      REPEAT
        IF x MOD base = 0 THEN
          a[i] := digits[0]; x := x DIV base
        ELSE
          a[i] := digits[base - x MOD base]; x := x DIV base + 1
        END;
        INC(i)
      UNTIL (x = 0) OR (i = LEN(a))
    ELSE
      i := 0; mSign := FALSE;
      REPEAT
        a[i] := digits[x MOD base]; x := x DIV base; INC(i)
      UNTIL (x = 0) OR (i = LEN(a))
    END;
    IF showBase THEN DEC(minWidth);
      IF base < 10 THEN DEC(minWidth) ELSE DEC(minWidth,2) END
    END
  END;
  si := 0;
  IF mSign & (fillCh = "0") & (si < LEN(s)) THEN s[si] := "-"; INC(si); mSign := FALSE END;
  WHILE minWidth > i DO
    IF si < LEN(s) THEN s[si] := fillCh; INC(si) END;
    DEC(minWidth)
  END;
  IF mSign & (si < LEN(s)) THEN s[si] := "-"; INC(si) END;
  IF form = Roman THEN
    j := 0;
    WHILE j < i DO 
      IF si < LEN(s) THEN s[si] := a[j]; INC(si) END; 
      INC(j)
    END
  ELSE
    REPEAT DEC(i);
      IF si < LEN(s) THEN s[si] := a[i]; INC(si) END
    UNTIL i = 0
  END;
  IF showBase & (form # Roman) THEN
    IF (form = CharCode) & (si < LEN(s)) THEN s[si] := "X"; INC(si)
    ELSIF (form = Hexadecimal) & (si < LEN(s)) THEN s[si] := "H"; INC(si)
    ELSIF (form < 10) & (si < LEN(s)-1) THEN s[si] := "%"; s[si+1] := digits[base]; INC(si, 2)
    ELSIF (si < LEN(s) - 2) THEN
      s[si] := "%"; s[si+1] := digits[base DIV 10]; s[si+2] := digits[base MOD 10]; INC(si, 3)
    END
  END;
  IF si < LEN(s) THEN s[si] := 0X ELSE HALT(23) END
END IntToStrForm;

PROCEDURE LIntToStrForm* (
  x: LONGINT; form, minWidth: INTEGER; fillCh: CHAR;
  showBase: BOOLEAN; VAR(*OUT*) s: ARRAY OF CHAR);
VAR
  base, i, j, k, si: INTEGER; mSign: BOOLEAN;
  a: ARRAY 128 OF CHAR; c1, c5, c10: CHAR; digits: ARRAY 17 OF CHAR;
BEGIN
  digits := "0123456789ABCDEF";
  ASSERT((form = CharCode) OR (form = Hexadecimal) OR
    (form = Roman) OR ((form >= 2) & (form <= 16)), 20);
  ASSERT(minWidth >= 0, 22);
  IF form = CharCode THEN base := 16
  ELSIF form = Hexadecimal THEN base := 16
  ELSE base := form
  END;
  
  IF form = Roman THEN
    ASSERT((x > 0) & (x < 3999), 21); 
    base := 1000; i := 0; mSign := FALSE;
    WHILE (base > 0) & (x > 0) DO
      IF base = 1 THEN c1 := "I"; c5 := "V"; c10 := "X"
      ELSIF base = 10 THEN c1 := "X"; c5 := "L"; c10 := "C"
      ELSIF base = 100 THEN c1 := "C"; c5 := "D"; c10 := "M"
      ELSE c1 := "M"
      END;
      k := SHORT(x DIV base); x := x MOD base;
      IF k IN {4, 9} THEN a[i] := c1; INC(i) END;
      IF k IN {4 .. 8} THEN a[i] := c5; INC(i) END;
      IF k = 9 THEN a[i] := c10; INC(i)
      ELSIF k IN {1 .. 3, 6 .. 8} THEN
        j := k MOD 5;
        REPEAT a[i] := c1; INC(i); DEC(j) UNTIL j = 0
      END;
      base := base DIV 10
    END
  ELSIF (form = Hexadecimal) OR (form = CharCode) THEN
    i := 0; mSign := FALSE;
    IF showBase THEN DEC(minWidth) END;
    REPEAT
      a[i] := digits[x MOD base]; x := x DIV base; INC(i)
    UNTIL (x = 0) OR (x = -1) OR (i = LEN(a));
    IF x = -1 THEN fillCh := "F" END
  ELSE
    IF x < 0 THEN
      i := 0; mSign := TRUE; DEC(minWidth);
      REPEAT
        IF x MOD base = 0 THEN
          a[i] := digits[0]; x := x DIV base
        ELSE
          a[i] := digits[base - x MOD base]; x := x DIV base + 1
        END;
        INC(i)
      UNTIL (x = 0) OR (i = LEN(a))
    ELSE
      i := 0; mSign := FALSE;
      REPEAT
        a[i] := digits[x MOD base]; x := x DIV base; INC(i)
      UNTIL (x = 0) OR (i = LEN(a))
    END;
    IF showBase THEN DEC(minWidth);
      IF base < 10 THEN DEC(minWidth) ELSE DEC(minWidth,2) END
    END
  END;
  si := 0;
  IF mSign & (fillCh = "0") & (si < LEN(s)) THEN s[si] := "-"; INC(si); mSign := FALSE END;
  WHILE minWidth > i DO
    IF si < LEN(s) THEN s[si] := fillCh; INC(si) END;
    DEC(minWidth)
  END;
  IF mSign & (si < LEN(s)) THEN s[si] := "-"; INC(si) END;
  IF form = Roman THEN
    j := 0;
    WHILE j < i DO 
      IF si < LEN(s) THEN s[si] := a[j]; INC(si) END; 
      INC(j)
    END
  ELSE
    REPEAT DEC(i);
      IF si < LEN(s) THEN s[si] := a[i]; INC(si) END
    UNTIL i = 0
  END;
  IF showBase & (form # Roman) THEN
    IF (form = CharCode) & (si < LEN(s)) THEN s[si] := "X"; INC(si)
    ELSIF (form = Hexadecimal) & (si < LEN(s)) THEN s[si] := "H"; INC(si)
    ELSIF (form < 10) & (si < LEN(s)-1) THEN s[si] := "%"; s[si+1] := digits[base]; INC(si, 2)
    ELSIF (si < LEN(s) - 2) THEN
      s[si] := "%"; s[si+1] := digits[base DIV 10]; s[si+2] := digits[base MOD 10]; INC(si, 3)
    END
  END;
  IF si < LEN(s) THEN s[si] := 0X ELSE HALT(23) END
END LIntToStrForm;

PROCEDURE- _init* "/*-noinit*/";

END Strings.
