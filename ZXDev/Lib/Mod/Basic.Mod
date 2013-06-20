MODULE Basic; (** non-portable *)
(*-----------------------------------*)
(* Sinclair ZX Spectrum BASIC        *)
(* for Ofront & SDCC by Oleg N. Cher *)
(*  VEDAsoft Oberon Club, 2012-2013  *)
(*-----------------------------------*)

CONST
	Black* = 0;
	Blue* = 1;
	Red* = 2;
	Magenta* = 3;
	Green* = 4;
	Cyan* = 5;
	Brown* = 6;
	LightGray* = 7;

	LightBlue* = Blue;
	LightRed* = Red;
	LightMagenta* = Magenta;
	LightGreen* = Green;
	LightCyan* = Cyan;
	Yellow* = Brown;
	White* = LightGray;

	On* = 1;
	Off* = 0;

	WaitAKey* = 0;

TYPE
	BYTE = INTEGER;
	CARDINAL = INTEGER;
	Color* = BYTE;
	Coords* = BYTE;
	TextCoords = BYTE;
	Mode = BYTE;
	ADDRESS = CARDINAL;

(* This procedures listed here for creating (by Ofront) symbol file .sym *)
PROCEDURE Init* ; BEGIN END Init;
PROCEDURE BORDER* (color: Color); BEGIN END BORDER;
PROCEDURE INK* (color: Color); BEGIN END INK;
PROCEDURE PAPER* (color: Color); BEGIN END PAPER;
PROCEDURE FLASH* (mode: Mode); BEGIN END FLASH;
PROCEDURE BRIGHT* (mode: Mode); BEGIN END BRIGHT;
PROCEDURE INVERSE* (mode: Mode); BEGIN END INVERSE;
PROCEDURE OVER* (mode: Mode); BEGIN END OVER;
PROCEDURE AT* (y, x: TextCoords); BEGIN END AT;
PROCEDURE CLS* ; BEGIN END CLS;
PROCEDURE PRSTR* (str: ARRAY OF CHAR); BEGIN END PRSTR;
PROCEDURE PRCHAR* (ch: CHAR); BEGIN END PRCHAR;
PROCEDURE PRLN* ; BEGIN END PRLN;
PROCEDURE PLOT* (x, y: Coords); BEGIN END PLOT;
PROCEDURE POINT* (x, y: Coords): BYTE; BEGIN RETURN 0 END POINT;
PROCEDURE ATTR* (y, x: TextCoords): BYTE; BEGIN RETURN 0 END ATTR;
PROCEDURE DRAW* (x, y: Coords); BEGIN END DRAW;
PROCEDURE CIRCLE* (cx, cy, radius: Coords); BEGIN END CIRCLE;
PROCEDURE PRINT* (i: INTEGER); BEGIN END PRINT;
PROCEDURE PRWORD* (i: CARDINAL); BEGIN END PRWORD;
PROCEDURE SlowCircle* (cx, cy, radius: Coords); BEGIN END SlowCircle;
PROCEDURE PEEK* (addr: ADDRESS): BYTE; BEGIN RETURN 0 END PEEK;
PROCEDURE POKE* (addr: ADDRESS; value: BYTE); BEGIN END POKE;
PROCEDURE PORTIN* (port: ADDRESS): BYTE; BEGIN RETURN 0 END PORTIN;
PROCEDURE PORTOUT* (port: ADDRESS; value: BYTE); BEGIN END PORTOUT;
PROCEDURE KeyPressed* (): BOOLEAN; BEGIN RETURN TRUE END KeyPressed;
PROCEDURE PAUSE* (ticks: CARDINAL); BEGIN END PAUSE;
PROCEDURE RANDOMIZE* (seed: CARDINAL); BEGIN END RANDOMIZE;
PROCEDURE RND* (min, max: CARDINAL): CARDINAL; BEGIN RETURN 0 END RND;
PROCEDURE SGN* (x: INTEGER): INTEGER; BEGIN RETURN 0 END SGN;
PROCEDURE BEEP* (ms: CARDINAL; freq: INTEGER); BEGIN END BEEP;
PROCEDURE FONT* (addr: ADDRESS); BEGIN END FONT;
PROCEDURE Quit* ; BEGIN END Quit;

END Basic.