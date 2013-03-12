TYPE
	Color = Integer;

	FillPatternType = ARRAY [1..8] OF Byte;
	
	FillSettingsType = RECORD
		Pattern : FillPatternType;
		Color   : Color
	END;

	LineSettingsType = RECORD
		LineStyle : Integer;
		Pattern   : Integer;
		Thickness : Integer;
	END;

CONST
	GDA  = 0;
	GDA1 = 1;

	Text		= 0;
	NoGraphAndText	= 1;
	GraphAndText	= 2;	
	Graph 		= 3;

	Black = 0;
	White = 1;
	Inv   = 2;

 	GetMaxX = 639;
 	GetMaxY = 263;

	NormalPut  = 0;
	XorPut	   = 1;
	OrPut	   = 2;
	AndPut	   = 3;
	NotPut	   = 4;
	
	SolidLn	   = 0;
	DottedLn   = 1;
	CenterLn   = 2;
	DashedLn   = 3;
	UserBitLn  = 4;
	
	NormWidth  = 1;
	ThickWidth = 3;

	TopOn	= True;
	TopOff	= False;
	
	EmptyFill	= 0;
	SolidFill	= 1;
	LineFill	= 2;
	LtSlashFill	= 3;
	SlashFill	= 4;
	BkSlashFill	= 5;
	LtBkSlashFill	= 6;
	HatchFill	= 7;
	XHatchFill	= 8;
	InterleaveFill	= 9;
	WideDotFill	= 10;
	CloseDotFill 	= 11;

PROCEDURE PutPixel (X,Y : Integer; C : Color);
	EXTERNAL 'PAS:GRAPH';

PROCEDURE InitGraph (VAR Typ, Mode : Integer);
	EXTERNAL PutPixel [4];

PROCEDURE SetGraphMode (Mode : 0..3);
	EXTERNAL PutPixel [8];

FUNCTION GetPixel (x, y : Integer) : Color;
	EXTERNAL PutPixel [12];

PROCEDURE SetColor (Col : Color);
	EXTERNAL PutPixel [16];

FUNCTION GetColor : Color;
	EXTERNAL PutPixel [20];

PROCEDURE Bar (x1, y1, x2, y2 : Integer);
	EXTERNAL PutPixel [24];

PROCEDURE Bar3d (x1, y1, x2, y2, Depth : Integer; Top : Boolean);
	EXTERNAL PutPixel [72];

PROCEDURE Rectangle (x1, y1, x2, y2 : Integer);
	EXTERNAL PutPixel [28];

FUNCTION GetX : Integer;
	EXTERNAL PutPixel [32];

FUNCTION GetY : Integer;
	EXTERNAL PutPixel [36];

PROCEDURE MoveTo (x, y : Integer);
	EXTERNAL PutPixel [40];

PROCEDURE MoveRel (dx, dy : Integer);
	EXTERNAL PutPixel [44];

PROCEDURE LineRel (dx, dy : Integer);
	EXTERNAL PutPixel [48];

PROCEDURE LineTo (x, y : Integer);
	EXTERNAL PutPixel [52];

PROCEDURE Line (x1, y1, x2, y2 : Integer);
	EXTERNAL PutPixel [56];

PROCEDURE GetImage (x1, y1, x2, y2 : Integer; VAR Image);
	EXTERNAL PutPixel [60];
	
PROCEDURE PutImage (x, y : Integer; VAR Image; Code : Integer);
	EXTERNAL PutPixel [64];
	
FUNCTION ImageSize (x1, y1, x2, y2 : Integer) : Integer;
	EXTERNAL PutPixel [68];

PROCEDURE SetLineStyle (Style, Patt, Thickness : Integer);
	EXTERNAL PutPixel [76];

PROCEDURE GetLineSettings (VAR LineInfo : LineSettingsType);
	EXTERNAL PutPixel [80];

PROCEDURE SetFillStyle (Style : Integer; Col : Color);
	EXTERNAL PutPixel [84];
	
PROCEDURE SetFillPattern (Pattern : FillPatternType; Col : Color);
	EXTERNAL PutPixel [88];

PROCEDURE GetFillSettings (VAR FillInfo : FillSettingsType);
	EXTERNAL PutPixel [92];

PROCEDURE PrintScreen (Invers : Boolean);
	EXTERNAL PutPixel [96];
	
PROCEDURE FloodFill (x, y : Integer; Col : Color);
	EXTERNAL PutPixel [100];

PROCEDURE OutText (s : STRING);
	EXTERNAL PutPixel [104];

PROCEDURE OutTextXY (x, y : Integer; s : STRING);
	EXTERNAL PutPixel [108];
	
PROCEDURE SetTextStyle (Font, Dir, Size : Integer);
	EXTERNAL PutPixel [112];

PROCEDURE SetBkColor (Col : Color);
	EXTERNAL PutPixel [116];

FUNCTION GetBkColor : Color;
	EXTERNAL PutPixel [120];

PROCEDURE ClearDevice;
	EXTERNAL PutPixel [124];

PROCEDURE Ellips (Col : Color; x, y, dx, dy : Integer);
	EXTERNAL PutPixel [128];

PROCEDURE SetBkFillStyle (Style : Integer; Col : Color);
	EXTERNAL PutPixel [132];
	
PROCEDURE SetBkFillPattern (Pattern : FillPatternType; Col : Color);
	EXTERNAL PutPixel [136];
