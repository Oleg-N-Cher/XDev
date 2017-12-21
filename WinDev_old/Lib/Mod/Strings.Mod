MODULE Strings;

IMPORT SYSTEM;

CONST
  CharCode* = -1; Decimal* = 10; Hexadecimal* = -2; Roman*= -3;

TYPE
  PtrSTR = ARRAY OF CHAR;

PROCEDURE -includestdio()	"#include <stdio.h>";
(*PROCEDURE -includestring()	"#include <string.h>";*)

PROCEDURE -sprintf (str: PtrSTR; n: LONGINT)	'sprintf(str, "%ld", n)'; 
PROCEDURE -sprintfL (str: PtrSTR; n: LONGINT)	'sprintf(str, "%lld", n)';
(*PROCEDURE -Length* (str: PtrSTR): STRLEN	"strlen(str)";*)

PROCEDURE Length* (IN str: ARRAY OF CHAR): INTEGER;
VAR
  len: INTEGER;
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

PROCEDURE HexToInt* (IN hex: ARRAY OF CHAR): INTEGER;
VAR
  res, n: INTEGER; ch: CHAR;
BEGIN
  res := 0; n := 0;
  REPEAT
    ch := hex[n];
    IF (ch >= "0") & (ch <= "9") THEN
      res := res * 16 + ORD(ch) - ORD("0");
    ELSIF (ch >= "A") & (ch <= "F") THEN
      res := res * 16 + ORD(ch) - ORD("A") + 10;
    ELSIF (ch >= "a") & (ch <= "f") THEN
      res := res * 16 + ORD(ch) - ORD("a") + 10;
    ELSIF (ch = 0X) & (n # 0) THEN RETURN res
    ELSE
      RETURN -1
    END;
  INC(n) UNTIL n = LEN(hex);
  RETURN res
END HexToInt;

PROCEDURE HexToLInt* (IN hex: ARRAY OF CHAR): LONGINT;
VAR
  res: LONGINT; n: INTEGER; ch: CHAR;
BEGIN
  res := 0; n := 0;
  REPEAT
    ch := hex[n];
    IF (ch >= "0") & (ch <= "9") THEN
      res := res * 16 + ORD(ch) - ORD("0");
    ELSIF (ch >= "A") & (ch <= "F") THEN
      res := res * 16 + ORD(ch) - ORD("A") + 10;
    ELSIF (ch >= "a") & (ch <= "f") THEN
      res := res * 16 + ORD(ch) - ORD("a") + 10;
    ELSIF (ch = 0X) & (n # 0) THEN RETURN res
    ELSE
      RETURN -1
    END;
  INC(n) UNTIL n # LEN(hex);
  RETURN res
END HexToLInt;

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
TYPE
  Digits = ARRAY 16 OF CHAR;
CONST
  digits = Digits
    ("0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F");
VAR
  base, i, j, k, si: INTEGER; mSign: BOOLEAN;
  a: ARRAY 128 OF CHAR; c1, c5, c10: CHAR;
BEGIN
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
TYPE
  Digits = ARRAY 16 OF CHAR;
CONST
  digits = Digits
    ("0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F");
VAR
  base, i, j, k, si: INTEGER; mSign: BOOLEAN;
  a: ARRAY 128 OF CHAR; c1, c5, c10: CHAR;
BEGIN
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

PROCEDURE Win1251ToUtf8* (
  IN s: ARRAY OF CHAR; VAR res: ARRAY OF CHAR): BOOLEAN;
(*
  http://freepascal.ru/forum/viewtopic.php?f=5&t=2389&start=15
  Don't use CP1251ToUtf8(str, str) - it does not work!
*)
VAR
  i, j, n, len: INTEGER; ch: CHAR; utf8: ARRAY 3 OF CHAR;
BEGIN
  i := 0; j := 0;
  REPEAT
    len := 1; ch := s[i];
    IF (ch >= 1X) & (ch <= 7FX) THEN
      utf8[0] := s[i]; DEC(len); (* One-byte and Russian characters *)
    ELSIF (ch >= 0C0X) & (ch <= 0EFX) THEN
      utf8[0] := 0D0X; utf8[1] := CHR(ORD(ch) - 48);  (* "À".."ï" *)
    ELSIF (ch >= 0F0X) & (ch <= 0FFX) THEN
      utf8[0] := 0D1X; utf8[1] := CHR(ORD(ch) - 112); (* "ð".."ÿ" *)
    ELSE
      CASE ch OF
      |  80X: utf8[0] := 0D0X; utf8[1] :=  82X;                  (* "€" *)
      |  81X: utf8[0] := 0D0X; utf8[1] :=  83X;                  (* "" *)
      |  82X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  9AX; (* "‚" *)
              INC(len);
      |  83X: utf8[0] := 0D1X; utf8[1] :=  93X;                  (* "ƒ" *)
      |  84X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  9EX; (* "„" *)
              INC(len);
      |  85X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0A6X; (* "…" *)
              INC(len);
      |  86X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0A0X; (* "†" *)
              INC(len);
      |  87X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0A1X; (* "‡" *)
              INC(len);
      |  88X: utf8[0] := 0E2X; utf8[1] :=  82X; utf8[2] := 0ACX; (* "ˆ" *)
              INC(len);
      |  89X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0B0X; (* "‰" *)
              INC(len);
      |  8AX: utf8[0] := 0D0X; utf8[1] :=  89X;                  (* "Š" *)
      |  8BX: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0B9X; (* "‹" *)
              INC(len);
      |  8CX: utf8[0] := 0D0X; utf8[1] :=  8AX;                  (* "Œ" *)
      |  8DX: utf8[0] := 0D0X; utf8[1] :=  8CX;                  (* "" *)
      |  8EX: utf8[0] := 0D0X; utf8[1] :=  8BX;                  (* "Ž" *)
      |  8FX: utf8[0] := 0D0X; utf8[1] :=  8FX;                  (* "" *)
      |  90X: utf8[0] := 0D1X; utf8[1] :=  92X;                  (* "" *)
      |  91X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  98X; (* "‘" *)
              INC(len);
      |  92X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  99X; (* "’" *)
              INC(len);
      |  93X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  9CX; (* "“" *)
              INC(len);
      |  94X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  9DX; (* "”" *)
              INC(len);
      |  95X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0A2X; (* "•" *)
              INC(len);
      |  96X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  93X; (* "–" *)
              INC(len);
      |  97X: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] :=  94X; (* "—" *)
              INC(len);
      |  98X: utf8[0] := 0C2X; utf8[1] :=  98X;                  (* ? *)
      |  99X: utf8[0] := 0E2X; utf8[1] :=  84X; utf8[2] := 0A2X; (* "™" *)
              INC(len);
      |  9AX: utf8[0] := 0D1X; utf8[1] :=  99X;                  (* "š" *)
      |  9BX: utf8[0] := 0E2X; utf8[1] :=  80X; utf8[2] := 0BAX; (* "›" *)
              INC(len);
      |  9CX: utf8[0] := 0D1X; utf8[1] :=  9AX;                  (* "œ" *)
      |  9DX: utf8[0] := 0D1X; utf8[1] :=  9CX;                  (* "" *)
      |  9EX: utf8[0] := 0D1X; utf8[1] :=  9BX;                  (* "ž" *)
      |  9FX: utf8[0] := 0D1X; utf8[1] :=  9FX;                  (* "Ÿ" *)
      | 0A0X: utf8[0] := 0C2X; utf8[1] := 0A0X;                  (* " " *)
      | 0A1X: utf8[0] := 0D0X; utf8[1] :=  8EX;                  (* "¡" *)
      | 0A2X: utf8[0] := 0D1X; utf8[1] :=  9EX;                  (* "¢" *)
      | 0A3X: utf8[0] := 0D0X; utf8[1] :=  88X;                  (* "£" *)
      | 0A4X: utf8[0] := 0C2X; utf8[1] := 0A4X;                  (* "¤" *)
      | 0A5X: utf8[0] := 0D2X; utf8[1] :=  90X;                  (* "¥" *)
      | 0A6X: utf8[0] := 0C2X; utf8[1] := 0A6X;                  (* "¦" *)
      | 0A7X: utf8[0] := 0C2X; utf8[1] := 0A7X;                  (* "§" *)
      | 0A8X: utf8[0] := 0D0X; utf8[1] :=  81X;                  (* "¨" *)
      | 0A9X: utf8[0] := 0C2X; utf8[1] := 0A9X;                  (* "©" *)
      | 0AAX: utf8[0] := 0D0X; utf8[1] :=  84X;                  (* "ª" *)
      | 0ABX: utf8[0] := 0C2X; utf8[1] := 0ABX;                  (* "«" *)
      | 0ACX: utf8[0] := 0C2X; utf8[1] := 0ACX;                  (* "¬" *)
      | 0ADX: utf8[0] := 0C2X; utf8[1] := 0ADX;                  (* ­? *)
      | 0AEX: utf8[0] := 0C2X; utf8[1] := 0AEX;                  (* "®" *)
      | 0AFX: utf8[0] := 0D0X; utf8[1] :=  87X;                  (* "¯" *)
      | 0B0X: utf8[0] := 0C2X; utf8[1] := 0B0X;                  (* "°" *)
      | 0B1X: utf8[0] := 0C2X; utf8[1] := 0B1X;                  (* "±" *)
      | 0B2X: utf8[0] := 0D0X; utf8[1] :=  86X;                  (* "²" *)
      | 0B3X: utf8[0] := 0D1X; utf8[1] :=  96X;                  (* "³" *)
      | 0B4X: utf8[0] := 0D2X; utf8[1] :=  91X;                  (* "´" *)
      | 0B5X: utf8[0] := 0C2X; utf8[1] := 0B5X;                  (* "µ" *)
      | 0B6X: utf8[0] := 0C2X; utf8[1] := 0B6X;                  (* "¶" *)
      | 0B7X: utf8[0] := 0C2X; utf8[1] := 0B7X;                  (* "•" *)
      | 0B8X: utf8[0] := 0D1X; utf8[1] :=  91X;                  (* "¸" *)
      | 0B9X: utf8[0] := 0E2X; utf8[1] :=  84X; utf8[2] :=  96X; (* "¹" *)
              INC(len);
      | 0BAX: utf8[0] := 0D1X; utf8[1] :=  94X;                  (* "º" *)
      | 0BBX: utf8[0] := 0C2X; utf8[1] := 0BBX;                  (* "»" *)
      | 0BCX: utf8[0] := 0D1X; utf8[1] :=  98X;                  (* "¼" *)
      | 0BDX: utf8[0] := 0D0X; utf8[1] :=  85X;                  (* "½" *)
      | 0BEX: utf8[0] := 0D1X; utf8[1] :=  95X;                  (* "¾" *)
      | 0BFX: utf8[0] := 0D1X; utf8[1] :=  97X;                  (* "¿" *)
      | 0X: res[j] := 0X; RETURN i # 0
      ELSE res[j] := 0X; RETURN FALSE
      END; (* CASE *)
    END; (* IF *)
    IF j + len + 1 >= LEN(res) THEN res[j] := 0X; RETURN FALSE END;
    FOR n := 0 TO len DO res[j] := utf8[n]; INC(j) END;
    INC(i);
  UNTIL i = LEN(s);
  res[j] := 0X; RETURN TRUE
END Win1251ToUtf8;

PROCEDURE Utf8ToWin1251* (
  IN s: ARRAY OF CHAR; VAR res: ARRAY OF CHAR): BOOLEAN;
(*
  http://freepascal.ru/forum/viewtopic.php?f=5&t=2389&start=45
*)
VAR
  i, j: INTEGER; ch: CHAR;
BEGIN
  i := 0; j := 0;
  REPEAT
    IF j+1 >= LEN(res) THEN res[j] := 0X; RETURN FALSE END;
    ch := s[i];
    IF (ch >= 1X) & (ch <= 7FX) THEN (* One byte and latin characters *)
    ELSE
      CASE ch OF
      | 0C2X: INC(i); ch := s[i];
      | 0D0X: INC(i); ch := s[i];
        IF (ch >= 90X) & (ch <= 0BFX) THEN
          ch := CHR(ORD(ch) + 48); (* "À".."ï" *)
        ELSE
          CASE ch OF
          | 81X: ch := 0A8X; (* "¨" *) 
          | 82X: ch :=  80X; (* "€" *)
          | 83X: ch :=  81X; (* "" *)
          | 84X: ch := 0AAX; (* "ª" *)
          | 85X: ch := 0BDX; (* "½" *)
          | 86X: ch := 0B2X; (* "²" *)
          | 87X: ch := 0AFX; (* "¯" *)
          | 88X: ch := 0A3X; (* "£" *)
          | 89X: ch :=  8AX; (* "Š" *)
          | 8AX: ch :=  8CX; (* "Œ" *)
          | 8BX: ch :=  8EX; (* "Ž" *)
          | 8CX: ch :=  8DX; (* "" *)
          | 8EX: ch := 0A1X; (* "¡" *)
          | 8FX: ch :=  8FX; (* "" *)
          ELSE
            res[j] := 0X; RETURN FALSE
          END;
        END;
      | 0D1X: INC(i); ch := s[i];
        IF (ch >= 80X) & (ch <= 8FX) THEN
          ch := CHR(ORD(ch) + 112); (* "ð".."ÿ" *)
        ELSE
          CASE ch OF
          | 91X: ch := 0B8X; (* "¸" *)
          | 92X: ch :=  90X; (* "" *)
          | 93X: ch :=  83X; (* "ƒ" *)
          | 94X: ch := 0BAX; (* "º" *)
          | 95X: ch := 0BEX; (* "¾" *)
          | 96X: ch := 0B3X; (* "³" *)
          | 97X: ch := 0BFX; (* "¿" *)
          | 98X: ch := 0BCX; (* "¼" *)
          | 99X: ch :=  9AX; (* "š" *)
          | 9AX: ch :=  9CX; (* "œ" *)
          | 9BX: ch :=  9EX; (* "ž" *)
          | 9CX: ch :=  9DX; (* "" *)
          | 9EX: ch := 0A2X; (* "¢" *)
          | 9FX: ch :=  9FX; (* "Ÿ" *)
          ELSE
            res[j] := 0X; RETURN FALSE
          END;
        END;
      | 0D2X: INC(i);
          CASE s[i] OF
          | 90X: ch := 0A5X; (* "¥" *)
          | 91X: ch := 0B4X; (* "´" *)
          ELSE
            res[j] := 0X; RETURN FALSE
          END;
      | 0E2X: INC(i);
        CASE s[i] OF
        | 80X: INC(i);
          CASE s[i] OF
          |  93X: ch := 96X; (* "–" *)
          |  94X: ch := 97X; (* "—" *)
          |  98X: ch := 91X; (* "‘" *)
          |  99X: ch := 92X; (* "’" *)
          |  9AX: ch := 82X; (* "‚" *)
          |  9CX: ch := 93X; (* "“" *)
          |  9DX: ch := 94X; (* "”" *)
          |  9EX: ch := 84X; (* "„" *)
          | 0A0X: ch := 86X; (* "†" *)
          | 0A1X: ch := 87X; (* "‡" *)
          | 0A2X: ch := 95X; (* "•" *)
          | 0A6X: ch := 85X; (* "…" *)
          | 0B0X: ch := 89X; (* "‰" *)
          | 0B9X: ch := 8BX; (* "‹" *)
          | 0BAX: ch := 9BX; (* "›" *)
          ELSE
            res[j] := 0X; RETURN FALSE
          END;
        | 82X: INC(i); ch := 88X; (* 0ACX ? *)
        | 84X: INC(i);
          CASE s[i] OF
          |  96X: ch := 0B9X; (* "¹" *)
          | 0A2X: ch :=  99X; (* "™" *)
          ELSE
            res[j] := 0X; RETURN FALSE
          END;
        ELSE
          res[j] := 0X; RETURN FALSE
        END;
      | 0X: res[j] := 0X; RETURN i # 0
      ELSE
        res[j] := 0X; RETURN FALSE
      END; (* CASE *)
    END; (* IF *)
    res[j] := ch; INC(j); INC(i);
  UNTIL i = LEN(s);
  res[j] := 0X; RETURN TRUE
END Utf8ToWin1251;

PROCEDURE- _init* "/*-noinit*/";

END Strings.
