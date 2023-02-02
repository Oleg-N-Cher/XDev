MODULE Graph; (* non-portable *)
IMPORT Platform;

CONST
	Detect*  = 0;
	ZX*      = 1;

	ZXMono*  = 1;
	ZXColor* = 1;

	Bright        = 40H;
	Black*        = 0;
	Blue*         = 1;
	Red*          = 2;
	Magenta*      = Red + Blue;
	Green*        = 4;
	Cyan*         = Green + Blue;
	Brown*        = Red + Green;
	LightGray*    = Red + Green + Blue;
	DarkGray*     = LightGray;
	LightBlue*    = Bright + Blue;
	LightRed*     = Bright + Red;
	LightMagenta* = Bright + Magenta;
	LightGreen*   = Bright + Green;
	LightCyan*    = Bright + Cyan;
	Yellow*       = Bright + Brown;
	White*        = Bright + LightGray;

TYPE
	Integer = INT16;
	String = ARRAY OF CHAR;
	Word = INT32;

PROCEDURE ClearDevice*; END ClearDevice;
PROCEDURE CloseGraph* ; END CloseGraph;
PROCEDURE InitGraph* (VAR GraphDriver,GraphMode: Integer; PathToDriver: String); END InitGraph;
PROCEDURE GetMaxX* (): Integer; BEGIN RETURN 255 END GetMaxX;
PROCEDURE GetMaxY* (): Integer; BEGIN RETURN 191 END GetMaxY;
PROCEDURE SetBkColor* (Color: Word); END SetBkColor;
PROCEDURE SetColor* (Color: Word); END SetColor;
PROCEDURE PutPixel* (x, y: Integer); END PutPixel;

  PROCEDURE GetSign (x: Integer): Integer;
  (* Argument sign. Result:
       -1 for negatives,
        1 for positives and zero *)
  BEGIN
    IF x >= 0 THEN RETURN 1 ELSE RETURN -1 END
  END GetSign;

PROCEDURE Line* (x1, y1, x2, y2: Integer);
VAR
  dx, dy, sdx, sdy, x, y, px, py: Integer;

BEGIN
  dx := x2 - x1;  dy := y2 - y1;
  sdx := GetSign(dx); sdy := GetSign(dy);
  dx := sdx * dx + 1; dy := sdy * dy + 1;
  x := 0; y := 0;
  px := x1; py := y1;
  IF dx >= dy THEN
    WHILE x < dx DO
      PutPixel(px, py);
      INC(y, dy);
      IF y >= dx THEN
        DEC(y, dx); INC(py, sdy)
      END;
      INC(px, sdx); INC(x)
    END
  ELSE
    WHILE y < dy DO
      PutPixel(px, py);
      INC(x, dx);
      IF x >= dy THEN
        DEC(x, dy); INC(px, sdx)
      END;
      INC(py, sdy); INC(y)
    END
  END
END Line;

END Graph.
