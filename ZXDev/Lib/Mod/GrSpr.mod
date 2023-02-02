MODULE GrSpr; IMPORT SYSTEM;

TYPE
  Coords* = SYSTEM.BYTE;
  Sprite* = ADRINT;

PROCEDURE DrawSprite* (x, y: Coords; spr: Sprite); END DrawSprite;
PROCEDURE DrawSpriteNoAttr* (x, y: Coords; spr: Sprite); END DrawSpriteNoAttr;

END GrSpr.