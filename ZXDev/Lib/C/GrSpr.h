#ifndef __GrSpr
#define __GrSpr

#include "libspr/spr0.h"

#define GrSpr_DrawSprite(x, y, spr) spr0_out0_attr((Sprite0*)spr, x, y)
#define GrSpr_DrawSpriteNoAttr(x, y, spr) spr0_out0((Sprite0*)spr, x, y)
#define GrSpr__init()

#endif
