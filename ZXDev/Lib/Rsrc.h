#ifndef Rsrc__h
#define Rsrc__h

#include "SYSTEM.h"

import const unsigned char Sprites [6271];
#define sprAddr (_Sprites)
#define sprEnd (sprAddr + 6271 - 1)

import const unsigned char Font [768];
#define fontAddr ((SYSTEM_ADDRESS)Font)

#define scrollBuf (0xFE00)

#endif
