MODULE [foreign] GrTiles; IMPORT SYSTEM, GrScr;

TYPE
  Colors* = SYSTEM.BYTE;
  Coords* = SYSTEM.BYTE;
  MonoTile8x8* = ARRAY 8 OF SYSTEM.BYTE;
  Tile8x8* = ARRAY 9 OF SYSTEM.BYTE;
  MonoTile16x16* = ARRAY 32 OF SYSTEM.BYTE;
  Tile16x16* = ARRAY 4*9 OF SYSTEM.BYTE;
  MonoTile* = MonoTile8x8;
  Tile* = Tile8x8;
  AnyTile* = POINTER TO ARRAY [notag] OF SYSTEM.BYTE;

PROCEDURE- DrawTile8x8* (x, y: Coords; tile: AnyTile);
PROCEDURE- DrawTile16x16* (x, y: Coords; tile: Tile16x16);

(** Draw a two-color tile with user-defined colors: *)
PROCEDURE- DrawMonoTile8x8* (
  x, y: Coords; tile: AnyTile; colors: Colors);
PROCEDURE- DrawMonoTile16x16* (
  x, y: Coords; tile: AnyTile; colors: Colors);

PROCEDURE- DrawTranspMonoTile8x8* (
  x, y: Coords; tile: AnyTile; colors: Colors);

(** Draw a tile with default size: *)
PROCEDURE- DrawTile* (x, y: Coords; tile: Tile);

PROCEDURE- DrawMonoTile* (
  x, y: Coords; tile: AnyTile; colors: Colors);

PROCEDURE- DrawTranspMonoTile* (
  x, y: Coords; tile: AnyTile; colors: Colors);

PROCEDURE- DrawNoAtrTile16x16* (x, y: Coords; tile: AnyTile);

PROCEDURE- GetTile8x8* (x, y: Coords; VAR tile: Tile8x8);

PROCEDURE- GetMonoTile8x8* (
  x, y: Coords; VAR tile: ARRAY [notag] OF SYSTEM.BYTE);

PROCEDURE- GetTile* (x, y: Coords; VAR tile: Tile);

PROCEDURE- GetMonoTile* (
  x, y: Coords; VAR tile: ARRAY [notag] OF SYSTEM.BYTE);

END GrTiles.
