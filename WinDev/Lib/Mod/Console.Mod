MODULE Console;	(** portable layer for LibC - output to standard out *)

IMPORT SYSTEM;

PROCEDURE -includestdio()	"#include <stdio.h>";

PROCEDURE -writeInt (n: LONGINT)	'printf("%ld", n)';
PROCEDURE -writeLInt (n: LONGINT)	'printf("%lld", n)';
PROCEDURE -writeStr (str: ARRAY [1] OF CHAR)	'printf("%s", str)';
PROCEDURE -writeStrLn (str: ARRAY [1] OF CHAR)	'printf("%s\n", str)';
PROCEDURE -writeCh (ch: CHAR)	'printf("%c", ch)';
PROCEDURE -writeLn	'printf("\n")'; (** Write from next line (CR). *)

PROCEDURE WriteInt* (n: LONGINT); (** Write signed long integer number into console. *)
BEGIN
  IF SIZE(LONGINT) = 4 THEN writeInt(n) END;
  IF SIZE(LONGINT) = 8 THEN writeLInt(n) END;
END WriteInt;

PROCEDURE WriteStr* (str: ARRAY [1] OF CHAR); (* Write ANSI string into console. *)
  (** UNSAFE! Make sure that value of array 'str' is null-terminated. *)
BEGIN writeStr(str) END WriteStr;

PROCEDURE WriteStrLn* (str: ARRAY [1] OF CHAR); (* Write ANSI string into console. *)
  (** UNSAFE! Make sure that value of array 'str' is null-terminated. *)
BEGIN writeStrLn(str) END WriteStrLn;

PROCEDURE WriteCh* (ch: CHAR); (** Write ANSI character. *)
BEGIN writeCh(ch) END WriteCh;

PROCEDURE WriteLn* ; (** Write from next line (CR). *)
BEGIN writeLn END WriteLn;

END Console.
