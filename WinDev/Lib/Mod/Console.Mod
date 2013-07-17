MODULE Console;  (** portable layer for LibC - output to standard out *)

IMPORT SYSTEM;

CONST
  Black     = 0;
  Blue      = 1;
  Green     = 2;
  Cyan      = Green + Blue;
  Red       = 4;
  Magenta   = Red + Blue;
  Olive     = Red + Green;
  White     = Red + Green + Blue;
  Light     = 8;
  Gray         = Light + Black;
  LightBlue    = Light + Blue;
  LightGreen   = Light + Green;
  LightCyan    = Light + Cyan;
  LightRed     = Light + Red;
  LightMagenta = Light + Magenta;
  Yellow       = Light + Olive;
  LightWhite   = Light + White;

  BlackOnBlack*    = ASH(Black, 4) + Black;
  BlueOnBlack*     = ASH(Black, 4) + Blue;
  GreenOnBlack*    = ASH(Black, 4) + Green;
  CyanOnBlack*     = ASH(Black, 4) + Cyan;
  RedOnBlack*      = ASH(Black, 4) + Red;
  MagentaOnBlack*  = ASH(Black, 4) + Magenta;
  OliveOnBlack*    = ASH(Black, 4) + Olive;
  WhiteOnBlack*    = ASH(Black, 4) + White;
  GrayOnBlack*     = ASH(Black, 4) + Gray;
  LBlueOnBlack*    = ASH(Black, 4) + LightBlue;
  LGreenOnBlack*   = ASH(Black, 4) + LightGreen;
  LCyanOnBlack*    = ASH(Black, 4) + LightCyan;
  LRedOnBlack*     = ASH(Black, 4) + LightRed;
  LMagentaOnBlack* = ASH(Black, 4) + LightMagenta;
  YellowOnBlack*   = ASH(Black, 4) + Yellow;
  LWhiteOnBlack*   = ASH(Black, 4) + LightWhite;

  BlackOnBlue*    = ASH(Blue, 4) + Black;
  BlueOnBlue*     = ASH(Blue, 4) + Blue;
  GreenOnBlue*    = ASH(Blue, 4) + Green;
  CyanOnBlue*     = ASH(Blue, 4) + Cyan;
  RedOnBlue*      = ASH(Blue, 4) + Red;
  MagentaOnBlue*  = ASH(Blue, 4) + Magenta;
  OliveOnBlue*    = ASH(Blue, 4) + Olive;
  WhiteOnBlue*    = ASH(Blue, 4) + White;
  GrayOnBlue*     = ASH(Blue, 4) + Gray;
  LBlueOnBlue*    = ASH(Blue, 4) + LightBlue;
  LGreenOnBlue*   = ASH(Blue, 4) + LightGreen;
  LCyanOnBlue*    = ASH(Blue, 4) + LightCyan;
  LRedOnBlue*     = ASH(Blue, 4) + LightRed;
  LMagentaOnBlue* = ASH(Blue, 4) + LightMagenta;
  YellowOnBlue*   = ASH(Blue, 4) + Yellow;
  LWhiteOnBlue*   = ASH(Blue, 4) + LightWhite;

  BlackOnGreen*    = ASH(Green, 4) + Black;
  BlueOnGreen*     = ASH(Green, 4) + Blue;
  GreenOnGreen*    = ASH(Green, 4) + Green;
  CyanOnGreen*     = ASH(Green, 4) + Cyan;
  RedOnGreen*      = ASH(Green, 4) + Red;
  MagentaOnGreen*  = ASH(Green, 4) + Magenta;
  OliveOnGreen*    = ASH(Green, 4) + Olive;
  WhiteOnGreen*    = ASH(Green, 4) + White;
  GrayOnGreen*     = ASH(Green, 4) + Gray;
  LBlueOnGreen*    = ASH(Green, 4) + LightBlue;
  LGreenOnGreen*   = ASH(Green, 4) + LightGreen;
  LCyanOnGreen*    = ASH(Green, 4) + LightCyan;
  LRedOnGreen*     = ASH(Green, 4) + LightRed;
  LMagentaOnGreen* = ASH(Green, 4) + LightMagenta;
  YellowOnGreen*   = ASH(Green, 4) + Yellow;
  LWhiteOnGreen*   = ASH(Green, 4) + LightWhite;

  BlackOnCyan*    = ASH(Cyan, 4) + Black;
  BlueOnCyan*     = ASH(Cyan, 4) + Blue;
  GreenOnCyan*    = ASH(Cyan, 4) + Green;
  CyanOnCyan*     = ASH(Cyan, 4) + Cyan;
  RedOnCyan*      = ASH(Cyan, 4) + Red;
  MagentaOnCyan*  = ASH(Cyan, 4) + Magenta;
  OliveOnCyan*    = ASH(Cyan, 4) + Olive;
  WhiteOnCyan*    = ASH(Cyan, 4) + White;
  GrayOnCyan*     = ASH(Cyan, 4) + Gray;
  LBlueOnCyan*    = ASH(Cyan, 4) + LightBlue;
  LGreenOnCyan*   = ASH(Cyan, 4) + LightGreen;
  LCyanOnCyan*    = ASH(Cyan, 4) + LightCyan;
  LRedOnCyan*     = ASH(Cyan, 4) + LightRed;
  LMagentaOnCyan* = ASH(Cyan, 4) + LightMagenta;
  YellowOnCyan*   = ASH(Cyan, 4) + Yellow;
  LWhiteOnCyan*   = ASH(Cyan, 4) + LightWhite;

  BlackOnRed*    = ASH(Red, 4) + Black;
  BlueOnRed*     = ASH(Red, 4) + Blue;
  GreenOnRed*    = ASH(Red, 4) + Green;
  CyanOnRed*     = ASH(Red, 4) + Cyan;
  RedOnRed*      = ASH(Red, 4) + Red;
  MagentaOnRed*  = ASH(Red, 4) + Magenta;
  OliveOnRed*    = ASH(Red, 4) + Olive;
  WhiteOnRed*    = ASH(Red, 4) + White;
  GrayOnRed*     = ASH(Red, 4) + Gray;
  LBlueOnRed*    = ASH(Red, 4) + LightBlue;
  LGreenOnRed*   = ASH(Red, 4) + LightGreen;
  LCyanOnRed*    = ASH(Red, 4) + LightCyan;
  LRedOnRed*     = ASH(Red, 4) + LightRed;
  LMagentaOnRed* = ASH(Red, 4) + LightMagenta;
  YellowOnRed*   = ASH(Red, 4) + Yellow;
  LWhiteOnRed*   = ASH(Red, 4) + LightWhite;

  BlackOnMagenta*    = ASH(Magenta, 4) + Black;
  BlueOnMagenta*     = ASH(Magenta, 4) + Blue;
  GreenOnMagenta*    = ASH(Magenta, 4) + Green;
  CyanOnMagenta*     = ASH(Magenta, 4) + Cyan;
  RedOnMagenta*      = ASH(Magenta, 4) + Red;
  MagentaOnMagenta*  = ASH(Magenta, 4) + Magenta;
  OliveOnMagenta*    = ASH(Magenta, 4) + Olive;
  WhiteOnMagenta*    = ASH(Magenta, 4) + White;
  GrayOnMagenta*     = ASH(Magenta, 4) + Gray;
  LBlueOnMagenta*    = ASH(Magenta, 4) + LightBlue;
  LGreenOnMagenta*   = ASH(Magenta, 4) + LightGreen;
  LCyanOnMagenta*    = ASH(Magenta, 4) + LightCyan;
  LRedOnMagenta*     = ASH(Magenta, 4) + LightRed;
  LMagentaOnMagenta* = ASH(Magenta, 4) + LightMagenta;
  YellowOnMagenta*   = ASH(Magenta, 4) + Yellow;
  LWhiteOnMagenta*   = ASH(Magenta, 4) + LightWhite;

  BlackOnOlive*    = ASH(Olive, 4) + Black;
  BlueOnOlive*     = ASH(Olive, 4) + Blue;
  GreenOnOlive*    = ASH(Olive, 4) + Green;
  CyanOnOlive*     = ASH(Olive, 4) + Cyan;
  RedOnOlive*      = ASH(Olive, 4) + Red;
  MagentaOnOlive*  = ASH(Olive, 4) + Magenta;
  OliveOnOlive*    = ASH(Olive, 4) + Olive;
  WhiteOnOlive*    = ASH(Olive, 4) + White;
  GrayOnOlive*     = ASH(Olive, 4) + Gray;
  LBlueOnOlive*    = ASH(Olive, 4) + LightBlue;
  LGreenOnOlive*   = ASH(Olive, 4) + LightGreen;
  LCyanOnOlive*    = ASH(Olive, 4) + LightCyan;
  LRedOnOlive*     = ASH(Olive, 4) + LightRed;
  LMagentaOnOlive* = ASH(Olive, 4) + LightMagenta;
  YellowOnOlive*   = ASH(Olive, 4) + Yellow;
  LWhiteOnOlive*   = ASH(Olive, 4) + LightWhite;

  BlackOnWhite*    = ASH(White, 4) + Black;
  BlueOnWhite*     = ASH(White, 4) + Blue;
  GreenOnWhite*    = ASH(White, 4) + Green;
  CyanOnWhite*     = ASH(White, 4) + Cyan;
  RedOnWhite*      = ASH(White, 4) + Red;
  MagentaOnWhite*  = ASH(White, 4) + Magenta;
  OliveOnWhite*    = ASH(White, 4) + Olive;
  WhiteOnWhite*    = ASH(White, 4) + White;
  GrayOnWhite*     = ASH(White, 4) + Gray;
  LBlueOnWhite*    = ASH(White, 4) + LightBlue;
  LGreenOnWhite*   = ASH(White, 4) + LightGreen;
  LCyanOnWhite*    = ASH(White, 4) + LightCyan;
  LRedOnWhite*     = ASH(White, 4) + LightRed;
  LMagentaOnWhite* = ASH(White, 4) + LightMagenta;
  YellowOnWhite*   = ASH(White, 4) + Yellow;
  LWhiteOnWhite*   = ASH(White, 4) + LightWhite;

  BlackOnGray*    = ASH(Gray, 4) + Black;
  BlueOnGray*     = ASH(Gray, 4) + Blue;
  GreenOnGray*    = ASH(Gray, 4) + Green;
  CyanOnGray*     = ASH(Gray, 4) + Cyan;
  RedOnGray*      = ASH(Gray, 4) + Red;
  MagentaOnGray*  = ASH(Gray, 4) + Magenta;
  OliveOnGray*    = ASH(Gray, 4) + Olive;
  WhiteOnGray*    = ASH(Gray, 4) + White;
  GrayOnGray*     = ASH(Gray, 4) + Gray;
  LBlueOnGray*    = ASH(Gray, 4) + LightBlue;
  LGreenOnGray*   = ASH(Gray, 4) + LightGreen;
  LCyanOnGray*    = ASH(Gray, 4) + LightCyan;
  LRedOnGray*     = ASH(Gray, 4) + LightRed;
  LMagentaOnGray* = ASH(Gray, 4) + LightMagenta;
  YellowOnGray*   = ASH(Gray, 4) + Yellow;
  LWhiteOnGray*   = ASH(Gray, 4) + LightWhite;

  BlackOnLBlue*    = ASH(LightBlue, 4) + Black;
  BlueOnLBlue*     = ASH(LightBlue, 4) + Blue;
  GreenOnLBlue*    = ASH(LightBlue, 4) + Green;
  CyanOnLBlue*     = ASH(LightBlue, 4) + Cyan;
  RedOnLBlue*      = ASH(LightBlue, 4) + Red;
  MagentaOnLBlue*  = ASH(LightBlue, 4) + Magenta;
  OliveOnLBlue*    = ASH(LightBlue, 4) + Olive;
  WhiteOnLBlue*    = ASH(LightBlue, 4) + White;
  GrayOnLBlue*     = ASH(LightBlue, 4) + Gray;
  LBlueOnLBlue*    = ASH(LightBlue, 4) + LightBlue;
  LGreenOnLBlue*   = ASH(LightBlue, 4) + LightGreen;
  LCyanOnLBlue*    = ASH(LightBlue, 4) + LightCyan;
  LRedOnLBlue*     = ASH(LightBlue, 4) + LightRed;
  LMagentaOnLBlue* = ASH(LightBlue, 4) + LightMagenta;
  YellowOnLBlue*   = ASH(LightBlue, 4) + Yellow;
  LWhiteOnLBlue*   = ASH(LightBlue, 4) + LightWhite;

  BlackOnLGreen*    = ASH(LightGreen, 4) + Black;
  BlueOnLGreen*     = ASH(LightGreen, 4) + Blue;
  GreenOnLGreen*    = ASH(LightGreen, 4) + Green;
  CyanOnLGreen*     = ASH(LightGreen, 4) + Cyan;
  RedOnLGreen*      = ASH(LightGreen, 4) + Red;
  MagentaOnLGreen*  = ASH(LightGreen, 4) + Magenta;
  OliveOnLGreen*    = ASH(LightGreen, 4) + Olive;
  WhiteOnLGreen*    = ASH(LightGreen, 4) + White;
  GrayOnLGreen*     = ASH(LightGreen, 4) + Gray;
  LBlueOnLGreen*    = ASH(LightGreen, 4) + LightBlue;
  LGreenOnLGreen*   = ASH(LightGreen, 4) + LightGreen;
  LCyanOnLGreen*    = ASH(LightGreen, 4) + LightCyan;
  LRedOnLGreen*     = ASH(LightGreen, 4) + LightRed;
  LMagentaOnLGreen* = ASH(LightGreen, 4) + LightMagenta;
  YellowOnLGreen*   = ASH(LightGreen, 4) + Yellow;
  LWhiteOnLGreen*   = ASH(LightGreen, 4) + LightWhite;

  BlackOnLCyan*    = ASH(LightCyan, 4) + Black;
  BlueOnLCyan*     = ASH(LightCyan, 4) + Blue;
  GreenOnLCyan*    = ASH(LightCyan, 4) + Green;
  CyanOnLCyan*     = ASH(LightCyan, 4) + Cyan;
  RedOnLCyan*      = ASH(LightCyan, 4) + Red;
  MagentaOnLCyan*  = ASH(LightCyan, 4) + Magenta;
  OliveOnLCyan*    = ASH(LightCyan, 4) + Olive;
  WhiteOnLCyan*    = ASH(LightCyan, 4) + White;
  GrayOnLCyan*     = ASH(LightCyan, 4) + Gray;
  LBlueOnLCyan*    = ASH(LightCyan, 4) + LightBlue;
  LGreenOnLCyan*   = ASH(LightCyan, 4) + LightGreen;
  LCyanOnLCyan*    = ASH(LightCyan, 4) + LightCyan;
  LRedOnLCyan*     = ASH(LightCyan, 4) + LightRed;
  LMagentaOnLCyan* = ASH(LightCyan, 4) + LightMagenta;
  YellowOnLCyan*   = ASH(LightCyan, 4) + Yellow;
  LWhiteOnLCyan*   = ASH(LightCyan, 4) + LightWhite;

  BlackOnLRed*    = ASH(LightRed, 4) + Black;
  BlueOnLRed*     = ASH(LightRed, 4) + Blue;
  GreenOnLRed*    = ASH(LightRed, 4) + Green;
  CyanOnLRed*     = ASH(LightRed, 4) + Cyan;
  RedOnLRed*      = ASH(LightRed, 4) + Red;
  MagentaOnLRed*  = ASH(LightRed, 4) + Magenta;
  OliveOnLRed*    = ASH(LightRed, 4) + Olive;
  WhiteOnLRed*    = ASH(LightRed, 4) + White;
  GrayOnLRed*     = ASH(LightRed, 4) + Gray;
  LBlueOnLRed*    = ASH(LightRed, 4) + LightBlue;
  LGreenOnLRed*   = ASH(LightRed, 4) + LightGreen;
  LCyanOnLRed*    = ASH(LightRed, 4) + LightCyan;
  LRedOnLRed*     = ASH(LightRed, 4) + LightRed;
  LMagentaOnLRed* = ASH(LightRed, 4) + LightMagenta;
  YellowOnLRed*   = ASH(LightRed, 4) + Yellow;
  LWhiteOnLRed*   = ASH(LightRed, 4) + LightWhite;

  BlackOnLMagenta*    = ASH(LightMagenta, 4) + Black;
  BlueOnLMagenta*     = ASH(LightMagenta, 4) + Blue;
  GreenOnLMagenta*    = ASH(LightMagenta, 4) + Green;
  CyanOnLMagenta*     = ASH(LightMagenta, 4) + Cyan;
  RedOnLMagenta*      = ASH(LightMagenta, 4) + Red;
  MagentaOnLMagenta*  = ASH(LightMagenta, 4) + Magenta;
  OliveOnLMagenta*    = ASH(LightMagenta, 4) + Olive;
  WhiteOnLMagenta*    = ASH(LightMagenta, 4) + White;
  GrayOnLMagenta*     = ASH(LightMagenta, 4) + Gray;
  LBlueOnLMagenta*    = ASH(LightMagenta, 4) + LightBlue;
  LGreenOnLMagenta*   = ASH(LightMagenta, 4) + LightGreen;
  LCyanOnLMagenta*    = ASH(LightMagenta, 4) + LightCyan;
  LRedOnLMagenta*     = ASH(LightMagenta, 4) + LightRed;
  LMagentaOnLMagenta* = ASH(LightMagenta, 4) + LightMagenta;
  YellowOnLMagenta*   = ASH(LightMagenta, 4) + Yellow;
  LWhiteOnLMagenta*   = ASH(LightMagenta, 4) + LightWhite;

  BlackOnYellow*    = ASH(Yellow, 4) + Black;
  BlueOnYellow*     = ASH(Yellow, 4) + Blue;
  GreenOnYellow*    = ASH(Yellow, 4) + Green;
  CyanOnYellow*     = ASH(Yellow, 4) + Cyan;
  RedOnYellow*      = ASH(Yellow, 4) + Red;
  MagentaOnYellow*  = ASH(Yellow, 4) + Magenta;
  OliveOnYellow*    = ASH(Yellow, 4) + Olive;
  WhiteOnYellow*    = ASH(Yellow, 4) + White;
  GrayOnYellow*     = ASH(Yellow, 4) + Gray;
  LBlueOnYellow*    = ASH(Yellow, 4) + LightBlue;
  LGreenOnYellow*   = ASH(Yellow, 4) + LightGreen;
  LCyanOnYellow*    = ASH(Yellow, 4) + LightCyan;
  LRedOnYellow*     = ASH(Yellow, 4) + LightRed;
  LMagentaOnYellow* = ASH(Yellow, 4) + LightMagenta;
  YellowOnYellow*   = ASH(Yellow, 4) + Yellow;
  LWhiteOnYellow*   = ASH(Yellow, 4) + LightWhite;

  BlackOnLWhite*    = ASH(LightWhite, 4) + Black;
  BlueOnLWhite*     = ASH(LightWhite, 4) + Blue;
  GreenOnLWhite*    = ASH(LightWhite, 4) + Green;
  CyanOnLWhite*     = ASH(LightWhite, 4) + Cyan;
  RedOnLWhite*      = ASH(LightWhite, 4) + Red;
  MagentaOnLWhite*  = ASH(LightWhite, 4) + Magenta;
  OliveOnLWhite*    = ASH(LightWhite, 4) + Olive;
  WhiteOnLWhite*    = ASH(LightWhite, 4) + White;
  GrayOnLWhite*     = ASH(LightWhite, 4) + Gray;
  LBlueOnLWhite*    = ASH(LightWhite, 4) + LightBlue;
  LGreenOnLWhite*   = ASH(LightWhite, 4) + LightGreen;
  LCyanOnLWhite*    = ASH(LightWhite, 4) + LightCyan;
  LRedOnLWhite*     = ASH(LightWhite, 4) + LightRed;
  LMagentaOnLWhite* = ASH(LightWhite, 4) + LightMagenta;
  YellowOnLWhite*   = ASH(LightWhite, 4) + Yellow;
  LWhiteOnLWhite*   = ASH(LightWhite, 4) + LightWhite;

PROCEDURE -includestdio()  "#include <stdio.h>";

PROCEDURE -writeInt (n: LONGINT)  'printf("%ld", n)';
PROCEDURE -writeLInt (n: LONGINT)  'printf("%lld", n)';
PROCEDURE -writeStr (str: ARRAY [1] OF CHAR)  'printf("%s", str)';
PROCEDURE -writeStrLn (str: ARRAY [1] OF CHAR)  'printf("%s\n", str)';
PROCEDURE -writeCh (ch: CHAR)  'printf("%c", ch)';
PROCEDURE -writeLn  'printf("\n")'; (** Write from next line (CR). *)

PROCEDURE At* (x, y: INTEGER);
BEGIN
END At;

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

(** Write signed integer x to console.
    Spaces are padded to the left until the number field
    is at least n characters long. *)
PROCEDURE WriteIntWidth* (x, n: INTEGER);
VAR
  i, x0: INTEGER; a: ARRAY 10 OF CHAR;
BEGIN
  IF x < 0 THEN
    IF x = MIN(INTEGER) THEN writeStr("-2147483648"); RETURN END;
    DEC(n); x0 := -x;
  ELSE
    x0 := x;
  END;
  i := 0;
  REPEAT
    a[i] := CHR(x0 MOD 10 + ORD("0")); x0 := x0 DIV 10; INC(i);
  UNTIL x0 = 0;
  WHILE n > i DO writeCh(" "); DEC(n) END;
  IF x < 0 THEN writeCh("-") END;
  REPEAT DEC(i); writeCh(a[i]) UNTIL i = 0;
END WriteIntWidth;

(** Write a hexadecimal representation of x to console. *)
PROCEDURE WriteHex* (x: INTEGER);
VAR
  i, y: INTEGER; a: ARRAY 10 OF CHAR;
BEGIN
  i := 0;
  REPEAT
    y := x MOD 10H;
    IF y < 10 THEN a[i] := CHR(y + 30H) ELSE a[i] := CHR(y + 37H) END;
    x := x DIV 10H; INC(i);
  UNTIL i = 8;
  REPEAT DEC(i); writeCh(a[i]) UNTIL i = 0;
END WriteHex;

PROCEDURE SetColors* (n: INTEGER);
BEGIN
END SetColors;

END Console.
