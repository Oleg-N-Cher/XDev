MODULE Console;  (** portable layer for LibC - output to standard out *)

IMPORT SYSTEM, GrApp(*Compatibility*);

CONST
  Light = 8;

TYPE
  Color = INTEGER;
  Coords* = INTEGER;
  Colors* = GrApp.Colors;

VAR
  Black-, Blue-, Green-, Cyan-, Red-, Magenta-, Olive-, White-,
  Gray-, LightBlue-, LightGreen-, LightCyan-, LightRed-,
  LightMagenta-, Yellow-, LightWhite-, Orange- : Color;

  BlackOnBlack-, BlueOnBlack-, GreenOnBlack-, CyanOnBlack-,
  RedOnBlack-, MagentaOnBlack-, OliveOnBlack-, WhiteOnBlack-,
  GrayOnBlack-, LBlueOnBlack-, LGreenOnBlack-, LCyanOnBlack-,
  LRedOnBlack-, LMagentaOnBlack-, YellowOnBlack-, LWhiteOnBlack-,
  OrangeOnBlack-,

  BlackOnBlue-, BlueOnBlue-, GreenOnBlue-, CyanOnBlue-,
  RedOnBlue-, MagentaOnBlue-, OliveOnBlue-, WhiteOnBlue-,
  GrayOnBlue-, LBlueOnBlue-, LGreenOnBlue-, LCyanOnBlue-,
  LRedOnBlue-, LMagentaOnBlue-, YellowOnBlue-, LWhiteOnBlue-,
  OrangeOnBlue-,

  BlackOnGreen-, BlueOnGreen-, GreenOnGreen-, CyanOnGreen-,
  RedOnGreen-, MagentaOnGreen-, OliveOnGreen-, WhiteOnGreen-,
  GrayOnGreen-, LBlueOnGreen-, LGreenOnGreen-, LCyanOnGreen-,
  LRedOnGreen-, LMagentaOnGreen-, YellowOnGreen-, LWhiteOnGreen-,
  OrangeOnGreen-,

  BlackOnCyan-, BlueOnCyan-, GreenOnCyan-, CyanOnCyan-,
  RedOnCyan-, MagentaOnCyan-, OliveOnCyan-, WhiteOnCyan-,
  GrayOnCyan-, LBlueOnCyan-, LGreenOnCyan-, LCyanOnCyan-,
  LRedOnCyan-, LMagentaOnCyan-, YellowOnCyan-, LWhiteOnCyan-,
  OrangeOnCyan-,

  BlackOnRed-, BlueOnRed-, GreenOnRed-, CyanOnRed-,
  RedOnRed-, MagentaOnRed-, OliveOnRed-, WhiteOnRed-,
  GrayOnRed-, LBlueOnRed-, LGreenOnRed-, LCyanOnRed-,
  LRedOnRed-, LMagentaOnRed-, YellowOnRed-, LWhiteOnRed-,
  OrangeOnRed-,

  BlackOnMagenta-, BlueOnMagenta-, GreenOnMagenta-, CyanOnMagenta-,
  RedOnMagenta-, MagentaOnMagenta-, OliveOnMagenta-, WhiteOnMagenta-,
  GrayOnMagenta-, LBlueOnMagenta-, LGreenOnMagenta-, LCyanOnMagenta-,
  LRedOnMagenta-, LMagentaOnMagenta-, YellowOnMagenta-, LWhiteOnMagenta-,
  OrangeOnMagenta-,

  BlackOnOlive-, BlueOnOlive-, GreenOnOlive-, CyanOnOlive-,
  RedOnOlive-, MagentaOnOlive-, OliveOnOlive-, WhiteOnOlive-,
  GrayOnOlive-, LBlueOnOlive-, LGreenOnOlive-, LCyanOnOlive-,
  LRedOnOlive-, LMagentaOnOlive-, YellowOnOlive-, LWhiteOnOlive-,
  OrangeOnOlive-,

  BlackOnWhite-, BlueOnWhite-, GreenOnWhite-, CyanOnWhite-,
  RedOnWhite-, MagentaOnWhite-, OliveOnWhite-, WhiteOnWhite-,
  GrayOnWhite-, LBlueOnWhite-, LGreenOnWhite-, LCyanOnWhite-,
  LRedOnWhite-, LMagentaOnWhite-, YellowOnWhite-, LWhiteOnWhite-,
  OrangeOnWhite-,

  BlackOnGray-, BlueOnGray-, GreenOnGray-, CyanOnGray-,
  RedOnGray-, MagentaOnGray-, OliveOnGray-, WhiteOnGray-,
  GrayOnGray-, LBlueOnGray-, LGreenOnGray-, LCyanOnGray-,
  LRedOnGray-, LMagentaOnGray-, YellowOnGray-, LWhiteOnGray-,
  OrangeOnGray-,

  BlackOnLBlue-, BlueOnLBlue-, GreenOnLBlue-, CyanOnLBlue-,
  RedOnLBlue-, MagentaOnLBlue-, OliveOnLBlue-, WhiteOnLBlue-,
  GrayOnLBlue-, LBlueOnLBlue-, LGreenOnLBlue-, LCyanOnLBlue-,
  LRedOnLBlue-, LMagentaOnLBlue-, YellowOnLBlue-, LWhiteOnLBlue-,
  OrangeOnLBlue-,

  BlackOnLGreen-, BlueOnLGreen-, GreenOnLGreen-, CyanOnLGreen-,
  RedOnLGreen-, MagentaOnLGreen-, OliveOnLGreen-, WhiteOnLGreen-,
  GrayOnLGreen-, LBlueOnLGreen-, LGreenOnLGreen-, LCyanOnLGreen-,
  LRedOnLGreen-, LMagentaOnLGreen-, YellowOnLGreen-, LWhiteOnLGreen-,
  OrangeOnLGreen-,

  BlackOnLCyan-, BlueOnLCyan-, GreenOnLCyan-, CyanOnLCyan-,
  RedOnLCyan-, MagentaOnLCyan-, OliveOnLCyan-, WhiteOnLCyan-,
  GrayOnLCyan-, LBlueOnLCyan-, LGreenOnLCyan-, LCyanOnLCyan-,
  LRedOnLCyan-, LMagentaOnLCyan-, YellowOnLCyan-, LWhiteOnLCyan-,
  OrangeOnLCyan-,

  BlackOnLRed-, BlueOnLRed-, GreenOnLRed-, CyanOnLRed-,
  RedOnLRed-, MagentaOnLRed-, OliveOnLRed-, WhiteOnLRed-,
  GrayOnLRed-, LBlueOnLRed-, LGreenOnLRed-, LCyanOnLRed-,
  LRedOnLRed-, LMagentaOnLRed-, YellowOnLRed-, LWhiteOnLRed-,
  OrangeOnLRed-,

  BlackOnLMagenta-, BlueOnLMagenta-, GreenOnLMagenta-, CyanOnLMagenta-,
  RedOnLMagenta-, MagentaOnLMagenta-, OliveOnLMagenta-, WhiteOnLMagenta-,
  GrayOnLMagenta-, LBlueOnLMagenta-, LGreenOnLMagenta-, LCyanOnLMagenta-,
  LRedOnLMagenta-, LMagentaOnLMagenta-, YellowOnLMagenta-, LWhiteOnLMagenta-,
  OrangeOnLMagenta-,

  BlackOnYellow-, BlueOnYellow-, GreenOnYellow-, CyanOnYellow-,
  RedOnYellow-, MagentaOnYellow-, OliveOnYellow-, WhiteOnYellow-,
  GrayOnYellow-, LBlueOnYellow-, LGreenOnYellow-, LCyanOnYellow-,
  LRedOnYellow-, LMagentaOnYellow-, YellowOnYellow-, LWhiteOnYellow-,
  OrangeOnYellow-,

  BlackOnLWhite-, BlueOnLWhite-, GreenOnLWhite-, CyanOnLWhite-,
  RedOnLWhite-, MagentaOnLWhite-, OliveOnLWhite-, WhiteOnLWhite-,
  GrayOnLWhite-, LBlueOnLWhite-, LGreenOnLWhite-, LCyanOnLWhite-,
  LRedOnLWhite-, LMagentaOnLWhite-, YellowOnLWhite-, LWhiteOnLWhite-,
  OrangeOnLWhite-,

  BlackOnOrange-, BlueOnOrange-, GreenOnOrange-, CyanOnOrange-,
  RedOnOrange-, MagentaOnOrange-, OliveOnOrange-, WhiteOnOrange-,
  GrayOnOrange-, LBlueOnOrange-, LGreenOnOrange-, LCyanOnOrange-,
  LRedOnOrange-, LMagentaOnOrange-, YellowOnOrange-, LWhiteOnOrange-

    : Colors;

PROCEDURE -includestdio()  "#include <stdio.h>";

PROCEDURE -writeInt (n: LONGINT)  'printf("%ld", n)';
PROCEDURE -writeLInt (n: LONGINT)  'printf("%lld", n)';
PROCEDURE -writeReal (r: REAL)  'printf("%f", r)';
PROCEDURE -writeStr (str: ARRAY [1] OF CHAR)  'printf("%s", str)';
PROCEDURE -writeStrLn (str: ARRAY [1] OF CHAR)  'printf("%s\n", str)';
PROCEDURE -writeCh (ch: CHAR)  'printf("%c", ch)';
PROCEDURE -writeLn  'printf("\n")'; (** Write from next line (CR). *)

PROCEDURE At* (x, y: INTEGER);
BEGIN
END At;

PROCEDURE Clear* (colors: Color);
BEGIN
END Clear;

PROCEDURE SetColors* (n: Colors);
BEGIN
END SetColors;

PROCEDURE SetFont* (font: ARRAY [1] OF BYTE);
BEGIN
END SetFont;

PROCEDURE WriteInt* (n: LONGINT); (** Write signed long integer number into console. *)
BEGIN
  IF SIZE(LONGINT) = 4 THEN writeInt(n) END;
  IF SIZE(LONGINT) = 8 THEN writeLInt(n) END;
END WriteInt;

PROCEDURE WriteReal* (r: REAL);
BEGIN
  writeReal(r);
END WriteReal;

PROCEDURE WriteStr* (str: ARRAY [1] OF CHAR); (* Write ANSI string into console. *)
  (** UNSAFE! Make sure that value of array 'str' is null-terminated. *)
BEGIN writeStr(str) END WriteStr;

PROCEDURE WriteStrLn* (str: ARRAY [1] OF CHAR); (* Write ANSI string into console. *)
  (** UNSAFE! Make sure that value of array 'str' is null-terminated. *)
BEGIN writeStrLn(str) END WriteStrLn;

PROCEDURE WriteBool* (b: BOOLEAN);
BEGIN
  IF b THEN WriteStr("TRUE") ELSE WriteStr("FALSE") END;
END WriteBool;

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
PROCEDURE WriteHex* (val: INTEGER);
VAR
  i, y: INTEGER; a: ARRAY 10 OF CHAR;
BEGIN
  i := 0;
  REPEAT
    y := val MOD 10H;
    IF y < 10 THEN a[i] := CHR(y + 30H) ELSE a[i] := CHR(y + 37H) END;
    val := val DIV 10H; INC(i);
  UNTIL val = 0;
  REPEAT DEC(i); writeCh(a[i]) UNTIL i = 0;
END WriteHex;

BEGIN
  Black     := 0;
  Blue      := 1;
  Green     := 2;
  Cyan      := Green + Blue;
  Red       := 4;
  Magenta   := Red + Blue;
  Olive     := Red + Green;
  White     := Red + Green + Blue;
  Gray         := Light + Black;
  LightBlue    := Light + Blue;
  LightGreen   := Light + Green;
  LightCyan    := Light + Cyan;
  LightRed     := Light + Red;
  LightMagenta := Light + Magenta;
  Yellow       := Light + Olive;
  LightWhite   := Light + White;

  BlackOnBlack.paper    := Black; BlackOnBlack.ink    := Black;
  BlueOnBlack.paper     := Black; BlueOnBlack.ink     := Blue;
  GreenOnBlack.paper    := Black; GreenOnBlack.ink    := Green;
  CyanOnBlack.paper     := Black; CyanOnBlack.ink     := Cyan;
  RedOnBlack.paper      := Black; RedOnBlack.ink      := Red;
  MagentaOnBlack.paper  := Black; MagentaOnBlack.ink  := Magenta;
  OliveOnBlack.paper    := Black; OliveOnBlack.ink    := Olive;
  WhiteOnBlack.paper    := Black; WhiteOnBlack.ink    := White;
  GrayOnBlack.paper     := Black; GrayOnBlack.ink     := Gray;
  LBlueOnBlack.paper    := Black; LBlueOnBlack.ink    := LightBlue;
  LGreenOnBlack.paper   := Black; LGreenOnBlack.ink   := LightGreen;
  LCyanOnBlack.paper    := Black; LCyanOnBlack.ink    := LightCyan;
  LRedOnBlack.paper     := Black; LRedOnBlack.ink     := LightRed;
  LMagentaOnBlack.paper := Black; LMagentaOnBlack.ink := LightMagenta;
  YellowOnBlack.paper   := Black; YellowOnBlack.ink   := Yellow;
  LWhiteOnBlack.paper   := Black; LWhiteOnBlack.ink   := LightWhite;
  OrangeOnBlack.paper   := Black; OrangeOnBlack.ink   := Orange;

  BlackOnBlue.paper    := Blue; BlackOnBlue.ink    := Black;
  BlueOnBlue.paper     := Blue; BlueOnBlue.ink     := Blue;
  GreenOnBlue.paper    := Blue; GreenOnBlue.ink    := Green;
  CyanOnBlue.paper     := Blue; CyanOnBlue.ink     := Cyan;
  RedOnBlue.paper      := Blue; RedOnBlue.ink      := Red;
  MagentaOnBlue.paper  := Blue; MagentaOnBlue.ink  := Magenta;
  OliveOnBlue.paper    := Blue; OliveOnBlue.ink    := Olive;
  WhiteOnBlue.paper    := Blue; WhiteOnBlue.ink    := White;
  GrayOnBlue.paper     := Blue; GrayOnBlue.ink     := Gray;
  LBlueOnBlue.paper    := Blue; LBlueOnBlue.ink    := LightBlue;
  LGreenOnBlue.paper   := Blue; LGreenOnBlue.ink   := LightGreen;
  LCyanOnBlue.paper    := Blue; LCyanOnBlue.ink    := LightCyan;
  LRedOnBlue.paper     := Blue; LRedOnBlue.ink     := LightRed;
  LMagentaOnBlue.paper := Blue; LMagentaOnBlue.ink := LightMagenta;
  YellowOnBlue.paper   := Blue; YellowOnBlue.ink   := Yellow;
  LWhiteOnBlue.paper   := Blue; LWhiteOnBlue.ink   := LightWhite;
  OrangeOnBlue.paper   := Blue; OrangeOnBlue.ink   := Orange;

  BlackOnGreen.paper    := Green; BlackOnGreen.ink    := Black;
  BlueOnGreen.paper     := Green; BlueOnGreen.ink     := Blue;
  GreenOnGreen.paper    := Green; GreenOnGreen.ink    := Green;
  CyanOnGreen.paper     := Green; CyanOnGreen.ink     := Cyan;
  RedOnGreen.paper      := Green; RedOnGreen.ink      := Red;
  MagentaOnGreen.paper  := Green; MagentaOnGreen.ink  := Magenta;
  OliveOnGreen.paper    := Green; OliveOnGreen.ink    := Olive;
  WhiteOnGreen.paper    := Green; WhiteOnGreen.ink    := White;
  GrayOnGreen.paper     := Green; GrayOnGreen.ink     := Gray;
  LBlueOnGreen.paper    := Green; LBlueOnGreen.ink    := LightBlue;
  LGreenOnGreen.paper   := Green; LGreenOnGreen.ink   := LightGreen;
  LCyanOnGreen.paper    := Green; LCyanOnGreen.ink    := LightCyan;
  LRedOnGreen.paper     := Green; LRedOnGreen.ink     := LightRed;
  LMagentaOnGreen.paper := Green; LMagentaOnGreen.ink := LightMagenta;
  YellowOnGreen.paper   := Green; YellowOnGreen.ink   := Yellow;
  LWhiteOnGreen.paper   := Green; LWhiteOnGreen.ink   := LightWhite;
  OrangeOnGreen.paper   := Green; OrangeOnGreen.ink   := Orange;

  BlackOnCyan.paper    := Cyan; BlackOnCyan.ink    := Black;
  BlueOnCyan.paper     := Cyan; BlueOnCyan.ink     := Blue;
  GreenOnCyan.paper    := Cyan; GreenOnCyan.ink    := Green;
  CyanOnCyan.paper     := Cyan; CyanOnCyan.ink     := Cyan;
  RedOnCyan.paper      := Cyan; RedOnCyan.ink      := Red;
  MagentaOnCyan.paper  := Cyan; MagentaOnCyan.ink  := Magenta;
  OliveOnCyan.paper    := Cyan; OliveOnCyan.ink    := Olive;
  WhiteOnCyan.paper    := Cyan; WhiteOnCyan.ink    := White;
  GrayOnCyan.paper     := Cyan; GrayOnCyan.ink     := Gray;
  LBlueOnCyan.paper    := Cyan; LBlueOnCyan.ink    := LightBlue;
  LGreenOnCyan.paper   := Cyan; LGreenOnCyan.ink   := LightGreen;
  LCyanOnCyan.paper    := Cyan; LCyanOnCyan.ink    := LightCyan;
  LRedOnCyan.paper     := Cyan; LRedOnCyan.ink     := LightRed;
  LMagentaOnCyan.paper := Cyan; LMagentaOnCyan.ink := LightMagenta;
  YellowOnCyan.paper   := Cyan; YellowOnCyan.ink   := Yellow;
  LWhiteOnCyan.paper   := Cyan; LWhiteOnCyan.ink   := LightWhite;
  OrangeOnCyan.paper   := Cyan; OrangeOnCyan.ink   := Orange;

  BlackOnRed.paper    := Red; BlackOnRed.ink    := Black;
  BlueOnRed.paper     := Red; BlueOnRed.ink     := Blue;
  GreenOnRed.paper    := Red; GreenOnRed.ink    := Green;
  CyanOnRed.paper     := Red; CyanOnRed.ink     := Cyan;
  RedOnRed.paper      := Red; RedOnRed.ink      := Red;
  MagentaOnRed.paper  := Red; MagentaOnRed.ink  := Magenta;
  OliveOnRed.paper    := Red; OliveOnRed.ink    := Olive;
  WhiteOnRed.paper    := Red; WhiteOnRed.ink    := White;
  GrayOnRed.paper     := Red; GrayOnRed.ink     := Gray;
  LBlueOnRed.paper    := Red; LBlueOnRed.ink    := LightBlue;
  LGreenOnRed.paper   := Red; LGreenOnRed.ink   := LightGreen;
  LCyanOnRed.paper    := Red; LCyanOnRed.ink    := LightCyan;
  LRedOnRed.paper     := Red; LRedOnRed.ink     := LightRed;
  LMagentaOnRed.paper := Red; LMagentaOnRed.ink := LightMagenta;
  YellowOnRed.paper   := Red; YellowOnRed.ink   := Yellow;
  LWhiteOnRed.paper   := Red; LWhiteOnRed.ink   := LightWhite;
  OrangeOnRed.paper   := Red; OrangeOnRed.ink   := Orange;

  BlackOnMagenta.paper    := Magenta; BlackOnMagenta.ink    := Black;
  BlueOnMagenta.paper     := Magenta; BlueOnMagenta.ink     := Blue;
  GreenOnMagenta.paper    := Magenta; GreenOnMagenta.ink    := Green;
  CyanOnMagenta.paper     := Magenta; CyanOnMagenta.ink     := Cyan;
  RedOnMagenta.paper      := Magenta; RedOnMagenta.ink      := Red;
  MagentaOnMagenta.paper  := Magenta; MagentaOnMagenta.ink  := Magenta;
  OliveOnMagenta.paper    := Magenta; OliveOnMagenta.ink    := Olive;
  WhiteOnMagenta.paper    := Magenta; WhiteOnMagenta.ink    := White;
  GrayOnMagenta.paper     := Magenta; GrayOnMagenta.ink     := Gray;
  LBlueOnMagenta.paper    := Magenta; LBlueOnMagenta.ink    := LightBlue;
  LGreenOnMagenta.paper   := Magenta; LGreenOnMagenta.ink   := LightGreen;
  LCyanOnMagenta.paper    := Magenta; LCyanOnMagenta.ink    := LightCyan;
  LRedOnMagenta.paper     := Magenta; LRedOnMagenta.ink     := LightRed;
  LMagentaOnMagenta.paper := Magenta; LMagentaOnMagenta.ink := LightMagenta;
  YellowOnMagenta.paper   := Magenta; YellowOnMagenta.ink   := Yellow;
  LWhiteOnMagenta.paper   := Magenta; LWhiteOnMagenta.ink   := LightWhite;
  OrangeOnMagenta.paper   := Magenta; OrangeOnMagenta.ink   := Orange;

  BlackOnOlive.paper    := Olive; BlackOnOlive.ink    := Black;
  BlueOnOlive.paper     := Olive; BlueOnOlive.ink     := Blue;
  GreenOnOlive.paper    := Olive; GreenOnOlive.ink    := Green;
  CyanOnOlive.paper     := Olive; CyanOnOlive.ink     := Cyan;
  RedOnOlive.paper      := Olive; RedOnOlive.ink      := Red;
  MagentaOnOlive.paper  := Olive; MagentaOnOlive.ink  := Magenta;
  OliveOnOlive.paper    := Olive; OliveOnOlive.ink    := Olive;
  WhiteOnOlive.paper    := Olive; WhiteOnOlive.ink    := White;
  GrayOnOlive.paper     := Olive; GrayOnOlive.ink     := Gray;
  LBlueOnOlive.paper    := Olive; LBlueOnOlive.ink    := LightBlue;
  LGreenOnOlive.paper   := Olive; LGreenOnOlive.ink   := LightGreen;
  LCyanOnOlive.paper    := Olive; LCyanOnOlive.ink    := LightCyan;
  LRedOnOlive.paper     := Olive; LRedOnOlive.ink     := LightRed;
  LMagentaOnOlive.paper := Olive; LMagentaOnOlive.ink := LightMagenta;
  YellowOnOlive.paper   := Olive; YellowOnOlive.ink   := Yellow;
  LWhiteOnOlive.paper   := Olive; LWhiteOnOlive.ink   := LightWhite;
  OrangeOnOlive.paper   := Olive; OrangeOnOlive.ink   := Orange;

  BlackOnWhite.paper    := White; BlackOnWhite.ink    := Black;
  BlueOnWhite.paper     := White; BlueOnWhite.ink     := Blue;
  GreenOnWhite.paper    := White; GreenOnWhite.ink    := Green;
  CyanOnWhite.paper     := White; CyanOnWhite.ink     := Cyan;
  RedOnWhite.paper      := White; RedOnWhite.ink      := Red;
  MagentaOnWhite.paper  := White; MagentaOnWhite.ink  := Magenta;
  OliveOnWhite.paper    := White; OliveOnWhite.ink    := Olive;
  WhiteOnWhite.paper    := White; WhiteOnWhite.ink    := White;
  GrayOnWhite.paper     := White; GrayOnWhite.ink     := Gray;
  LBlueOnWhite.paper    := White; LBlueOnWhite.ink    := LightBlue;
  LGreenOnWhite.paper   := White; LGreenOnWhite.ink   := LightGreen;
  LCyanOnWhite.paper    := White; LCyanOnWhite.ink    := LightCyan;
  LRedOnWhite.paper     := White; LRedOnWhite.ink     := LightRed;
  LMagentaOnWhite.paper := White; LMagentaOnWhite.ink := LightMagenta;
  YellowOnWhite.paper   := White; YellowOnWhite.ink   := Yellow;
  LWhiteOnWhite.paper   := White; LWhiteOnWhite.ink   := LightWhite;
  OrangeOnWhite.paper   := White; OrangeOnWhite.ink   := Orange;

  BlackOnGray.paper    := Gray; BlackOnGray.ink    := Black;
  BlueOnGray.paper     := Gray; BlueOnGray.ink     := Blue;
  GreenOnGray.paper    := Gray; GreenOnGray.ink    := Green;
  CyanOnGray.paper     := Gray; CyanOnGray.ink     := Cyan;
  RedOnGray.paper      := Gray; RedOnGray.ink      := Red;
  MagentaOnGray.paper  := Gray; MagentaOnGray.ink  := Magenta;
  OliveOnGray.paper    := Gray; OliveOnGray.ink    := Olive;
  WhiteOnGray.paper    := Gray; WhiteOnGray.ink    := White;
  GrayOnGray.paper     := Gray; GrayOnGray.ink     := Gray;
  LBlueOnGray.paper    := Gray; LBlueOnGray.ink    := LightBlue;
  LGreenOnGray.paper   := Gray; LGreenOnGray.ink   := LightGreen;
  LCyanOnGray.paper    := Gray; LCyanOnGray.ink    := LightCyan;
  LRedOnGray.paper     := Gray; LRedOnGray.ink     := LightRed;
  LMagentaOnGray.paper := Gray; LMagentaOnGray.ink := LightMagenta;
  YellowOnGray.paper   := Gray; YellowOnGray.ink   := Yellow;
  LWhiteOnGray.paper   := Gray; LWhiteOnGray.ink   := LightWhite;
  OrangeOnGray.paper   := Gray; OrangeOnGray.ink   := Orange;

  BlackOnLBlue.paper    := LightBlue; BlackOnLBlue.ink    := Black;
  BlueOnLBlue.paper     := LightBlue; BlueOnLBlue.ink     := Blue;
  GreenOnLBlue.paper    := LightBlue; GreenOnLBlue.ink    := Green;
  CyanOnLBlue.paper     := LightBlue; CyanOnLBlue.ink     := Cyan;
  RedOnLBlue.paper      := LightBlue; RedOnLBlue.ink      := Red;
  MagentaOnLBlue.paper  := LightBlue; MagentaOnLBlue.ink  := Magenta;
  OliveOnLBlue.paper    := LightBlue; OliveOnLBlue.ink    := Olive;
  WhiteOnLBlue.paper    := LightBlue; WhiteOnLBlue.ink    := White;
  GrayOnLBlue.paper     := LightBlue; GrayOnLBlue.ink     := Gray;
  LBlueOnLBlue.paper    := LightBlue; LBlueOnLBlue.ink    := LightBlue;
  LGreenOnLBlue.paper   := LightBlue; LGreenOnLBlue.ink   := LightGreen;
  LCyanOnLBlue.paper    := LightBlue; LCyanOnLBlue.ink    := LightCyan;
  LRedOnLBlue.paper     := LightBlue; LRedOnLBlue.ink     := LightRed;
  LMagentaOnLBlue.paper := LightBlue; LMagentaOnLBlue.ink := LightMagenta;
  YellowOnLBlue.paper   := LightBlue; YellowOnLBlue.ink   := Yellow;
  LWhiteOnLBlue.paper   := LightBlue; LWhiteOnLBlue.ink   := LightWhite;
  OrangeOnLBlue.paper   := LightBlue; OrangeOnLBlue.ink   := Orange;

  BlackOnLGreen.paper    := LightGreen; BlackOnLGreen.ink    := Black;
  BlueOnLGreen.paper     := LightGreen; BlueOnLGreen.ink     := Blue;
  GreenOnLGreen.paper    := LightGreen; GreenOnLGreen.ink    := Green;
  CyanOnLGreen.paper     := LightGreen; CyanOnLGreen.ink     := Cyan;
  RedOnLGreen.paper      := LightGreen; RedOnLGreen.ink      := Red;
  MagentaOnLGreen.paper  := LightGreen; MagentaOnLGreen.ink  := Magenta;
  OliveOnLGreen.paper    := LightGreen; OliveOnLGreen.ink    := Olive;
  WhiteOnLGreen.paper    := LightGreen; WhiteOnLGreen.ink    := White;
  GrayOnLGreen.paper     := LightGreen; GrayOnLGreen.ink     := Gray;
  LBlueOnLGreen.paper    := LightGreen; LBlueOnLGreen.ink    := LightBlue;
  LGreenOnLGreen.paper   := LightGreen; LGreenOnLGreen.ink   := LightGreen;
  LCyanOnLGreen.paper    := LightGreen; LCyanOnLGreen.ink    := LightCyan;
  LRedOnLGreen.paper     := LightGreen; LRedOnLGreen.ink     := LightRed;
  LMagentaOnLGreen.paper := LightGreen; LMagentaOnLGreen.ink := LightMagenta;
  YellowOnLGreen.paper   := LightGreen; YellowOnLGreen.ink   := Yellow;
  LWhiteOnLGreen.paper   := LightGreen; LWhiteOnLGreen.ink   := LightWhite;
  OrangeOnLGreen.paper   := LightGreen; OrangeOnLGreen.ink   := Orange;

  BlackOnLCyan.paper    := LightCyan; BlackOnLCyan.ink    := Black;
  BlueOnLCyan.paper     := LightCyan; BlueOnLCyan.ink     := Blue;
  GreenOnLCyan.paper    := LightCyan; GreenOnLCyan.ink    := Green;
  CyanOnLCyan.paper     := LightCyan; CyanOnLCyan.ink     := Cyan;
  RedOnLCyan.paper      := LightCyan; RedOnLCyan.ink      := Red;
  MagentaOnLCyan.paper  := LightCyan; MagentaOnLCyan.ink  := Magenta;
  OliveOnLCyan.paper    := LightCyan; OliveOnLCyan.ink    := Olive;
  WhiteOnLCyan.paper    := LightCyan; WhiteOnLCyan.ink    := White;
  GrayOnLCyan.paper     := LightCyan; GrayOnLCyan.ink     := Gray;
  LBlueOnLCyan.paper    := LightCyan; LBlueOnLCyan.ink    := LightBlue;
  LGreenOnLCyan.paper   := LightCyan; LGreenOnLCyan.ink   := LightGreen;
  LCyanOnLCyan.paper    := LightCyan; LCyanOnLCyan.ink    := LightCyan;
  LRedOnLCyan.paper     := LightCyan; LRedOnLCyan.ink     := LightRed;
  LMagentaOnLCyan.paper := LightCyan; LMagentaOnLCyan.ink := LightMagenta;
  YellowOnLCyan.paper   := LightCyan; YellowOnLCyan.ink   := Yellow;
  LWhiteOnLCyan.paper   := LightCyan; LWhiteOnLCyan.ink   := LightWhite;
  OrangeOnLCyan.paper   := LightCyan; OrangeOnLCyan.ink   := Orange;

  BlackOnLRed.paper    := LightRed; BlackOnLRed.ink    := Black;
  BlueOnLRed.paper     := LightRed; BlueOnLRed.ink     := Blue;
  GreenOnLRed.paper    := LightRed; GreenOnLRed.ink    := Green;
  CyanOnLRed.paper     := LightRed; CyanOnLRed.ink     := Cyan;
  RedOnLRed.paper      := LightRed; RedOnLRed.ink      := Red;
  MagentaOnLRed.paper  := LightRed; MagentaOnLRed.ink  := Magenta;
  OliveOnLRed.paper    := LightRed; OliveOnLRed.ink    := Olive;
  WhiteOnLRed.paper    := LightRed; WhiteOnLRed.ink    := White;
  GrayOnLRed.paper     := LightRed; GrayOnLRed.ink     := Gray;
  LBlueOnLRed.paper    := LightRed; LBlueOnLRed.ink    := LightBlue;
  LGreenOnLRed.paper   := LightRed; LGreenOnLRed.ink   := LightGreen;
  LCyanOnLRed.paper    := LightRed; LCyanOnLRed.ink    := LightCyan;
  LRedOnLRed.paper     := LightRed; LRedOnLRed.ink     := LightRed;
  LMagentaOnLRed.paper := LightRed; LMagentaOnLRed.ink := LightMagenta;
  YellowOnLRed.paper   := LightRed; YellowOnLRed.ink   := Yellow;
  LWhiteOnLRed.paper   := LightRed; LWhiteOnLRed.ink   := LightWhite;
  OrangeOnLRed.paper   := LightRed; OrangeOnLRed.ink   := Orange;

  BlackOnLMagenta.paper   := LightMagenta; BlackOnLMagenta.ink   := Black;
  BlueOnLMagenta.paper    := LightMagenta; BlueOnLMagenta.ink    := Blue;
  GreenOnLMagenta.paper   := LightMagenta; GreenOnLMagenta.ink   := Green;
  CyanOnLMagenta.paper    := LightMagenta; CyanOnLMagenta.ink    := Cyan;
  RedOnLMagenta.paper     := LightMagenta; RedOnLMagenta.ink     := Red;
  MagentaOnLMagenta.paper := LightMagenta; MagentaOnLMagenta.ink := Magenta;
  OliveOnLMagenta.paper   := LightMagenta; OliveOnLMagenta.ink   := Olive;
  WhiteOnLMagenta.paper   := LightMagenta; WhiteOnLMagenta.ink   := White;
  GrayOnLMagenta.paper    := LightMagenta; GrayOnLMagenta.ink    := Gray;
  LBlueOnLMagenta.paper   := LightMagenta; LBlueOnLMagenta.ink := LightBlue;
  LGreenOnLMagenta.paper  := LightMagenta; LGreenOnLMagenta.ink:= LightGreen;
  LCyanOnLMagenta.paper   := LightMagenta; LCyanOnLMagenta.ink := LightCyan;
  LRedOnLMagenta.paper    := LightMagenta; LRedOnLMagenta.ink  := LightRed;
  LMagentaOnLMagenta.paper:= LightMagenta;
                                        LMagentaOnLMagenta.ink:=LightMagenta;
  YellowOnLMagenta.paper  := LightMagenta; YellowOnLMagenta.ink:= Yellow;
  LWhiteOnLMagenta.paper  := LightMagenta; LWhiteOnLMagenta.ink:= LightWhite;
  OrangeOnLMagenta.paper  := LightMagenta; OrangeOnLMagenta.ink:= Orange;

  BlackOnYellow.paper    := Yellow; BlackOnYellow.ink    := Black;
  BlueOnYellow.paper     := Yellow; BlueOnYellow.ink     := Blue;
  GreenOnYellow.paper    := Yellow; GreenOnYellow.ink    := Green;
  CyanOnYellow.paper     := Yellow; CyanOnYellow.ink     := Cyan;
  RedOnYellow.paper      := Yellow; RedOnYellow.ink      := Red;
  MagentaOnYellow.paper  := Yellow; MagentaOnYellow.ink  := Magenta;
  OliveOnYellow.paper    := Yellow; OliveOnYellow.ink    := Olive;
  WhiteOnYellow.paper    := Yellow; WhiteOnYellow.ink    := White;
  GrayOnYellow.paper     := Yellow; GrayOnYellow.ink     := Gray;
  LBlueOnYellow.paper    := Yellow; LBlueOnYellow.ink    := LightBlue;
  LGreenOnYellow.paper   := Yellow; LGreenOnYellow.ink   := LightGreen;
  LCyanOnYellow.paper    := Yellow; LCyanOnYellow.ink    := LightCyan;
  LRedOnYellow.paper     := Yellow; LRedOnYellow.ink     := LightRed;
  LMagentaOnYellow.paper := Yellow; LMagentaOnYellow.ink := LightMagenta;
  YellowOnYellow.paper   := Yellow; YellowOnYellow.ink   := Yellow;
  LWhiteOnYellow.paper   := Yellow; LWhiteOnYellow.ink   := LightWhite;
  OrangeOnYellow.paper   := Yellow; OrangeOnYellow.ink   := Orange;

  BlackOnLWhite.paper    := LightWhite; BlackOnLWhite.ink    := Black;
  BlueOnLWhite.paper     := LightWhite; BlueOnLWhite.ink     := Blue;
  GreenOnLWhite.paper    := LightWhite; GreenOnLWhite.ink    := Green;
  CyanOnLWhite.paper     := LightWhite; CyanOnLWhite.ink     := Cyan;
  RedOnLWhite.paper      := LightWhite; RedOnLWhite.ink      := Red;
  MagentaOnLWhite.paper  := LightWhite; MagentaOnLWhite.ink  := Magenta;
  OliveOnLWhite.paper    := LightWhite; OliveOnLWhite.ink    := Olive;
  WhiteOnLWhite.paper    := LightWhite; WhiteOnLWhite.ink    := White;
  GrayOnLWhite.paper     := LightWhite; GrayOnLWhite.ink     := Gray;
  LBlueOnLWhite.paper    := LightWhite; LBlueOnLWhite.ink    := LightBlue;
  LGreenOnLWhite.paper   := LightWhite; LGreenOnLWhite.ink   := LightGreen;
  LCyanOnLWhite.paper    := LightWhite; LCyanOnLWhite.ink    := LightCyan;
  LRedOnLWhite.paper     := LightWhite; LRedOnLWhite.ink     := LightRed;
  LMagentaOnLWhite.paper := LightWhite; LMagentaOnLWhite.ink := LightMagenta;
  YellowOnLWhite.paper   := LightWhite; YellowOnLWhite.ink   := Yellow;
  LWhiteOnLWhite.paper   := LightWhite; LWhiteOnLWhite.ink   := LightWhite;
  OrangeOnLWhite.paper   := LightWhite; OrangeOnLWhite.ink   := Orange;
END Console.
