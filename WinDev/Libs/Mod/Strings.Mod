MODULE Strings;	(** portable layer for LibC - strings *)

IMPORT SYSTEM;

TYPE
  PtrSTR = ARRAY [1] OF CHAR;

PROCEDURE -includestdio()	"#include <stdio.h>";
(*PROCEDURE -includestring()	"#include <string.h>";*)

PROCEDURE -sprintf (str: PtrSTR; n: LONGINT)	'sprintf(str, "%ld", n)'; 
PROCEDURE -sprintfL (str: PtrSTR; n: LONGINT)	'sprintf(str, "%lld", n)';
(*PROCEDURE -Length* (str: PtrSTR): LONGINT	"strlen(str)";*)

PROCEDURE IntToStr* (n: LONGINT; VAR str: ARRAY [1] OF CHAR);
  (** UNSAFE! Make sure that size of array 'str' is enough. *)
BEGIN
  IF SIZE(LONGINT) = 4 THEN sprintf(str, n) END;
  IF SIZE(LONGINT) = 8 THEN sprintfL(str, n) END;
END IntToStr;

PROCEDURE Length* (VAR str: ARRAY OF CHAR): LONGINT;
VAR
  len, maxLen: LONGINT;
BEGIN
  maxLen := LEN(str); len := 0;
  WHILE (len < maxLen) & (str[len] # 0X) DO INC(len) END;
  RETURN len
END Length;

END Strings.
