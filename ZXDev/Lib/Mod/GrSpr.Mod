MODULE GrSpr;

TYPE
  Coords* = SHORTINT;
  Sprite* = INTEGER;

PROCEDURE DrawSprite* (x, y: Coords; spr: Sprite); END DrawSprite;
PROCEDURE DrawSpriteNoAttr* (x, y: Coords; spr: Sprite); END DrawSpriteNoAttr;

END GrSpr.