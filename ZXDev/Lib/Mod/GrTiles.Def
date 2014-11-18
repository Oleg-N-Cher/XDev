MODULE GrTiles;
IMPORT SYSTEM;

TYPE
  BYTE = INTEGER; ADDRESS = INTEGER;
  Colors* = SHORTINT;
  Coords* = SHORTINT;
  Tile* = ADDRESS;
  TranspTile* = ADDRESS;

PROCEDURE DrawTile8x8* (x, y: BYTE; tile: Tile); BEGIN END DrawTile8x8;
(** Draw a two-color tile with user-defined colors: *)
PROCEDURE DrawMonoTile8x8* (
  x, y: BYTE; tile: Tile; colors: Colors);
    BEGIN END DrawMonoTile8x8;

PROCEDURE DrawTranspMonoTile8x8* (
  x, y: Coords; VAR tile: TranspTile; colors: Colors);
    BEGIN END DrawTranspMonoTile8x8;

(** Draw a tile with default size: *)
PROCEDURE DrawTile* (x, y: BYTE; tile: Tile); BEGIN END DrawTile;
PROCEDURE DrawMonoTile* (x, y: BYTE; tile: Tile; colors: Colors);
  BEGIN END DrawMonoTile;
PROCEDURE DrawTranspMonoTile* (x, y: BYTE; tile: TranspTile; colors: Colors);
  BEGIN END DrawTranspMonoTile;

END GrTiles.