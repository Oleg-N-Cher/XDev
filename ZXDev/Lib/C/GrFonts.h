#ifndef GrFonts__h
#define GrFonts__h

#include "SYSTEM.h"

typedef
	INTEGER GrFonts_Font;

import BYTE GrFonts_ZxSpecRus8x8Font [768];
import BYTE GrFonts_MsDosCga8x8Font [768];


#define GrFonts_ZxSpecRom8x8 0x3D00
#define GrFonts_ZxSpecRus8x8 (int)GrFonts_ZxSpecRus8x8Font
#define GrFonts_MsDosCga8x8 (int)GrFonts_MsDosCga8x8Font


#define GrFonts__init()

#endif
