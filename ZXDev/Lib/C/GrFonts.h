#ifndef GrFonts__h
#define GrFonts__h

typedef
	int GrFonts_Font;

extern signed char GrFonts_ZxSpecRus8x8Font [768];
extern signed char GrFonts_MsDosCga8x8Font [768];


#define GrFonts_ZxSpecRom8x8 0x3D00
#define GrFonts_ZxSpecRus8x8 (int)GrFonts_ZxSpecRus8x8Font
#define GrFonts_MsDosCga8x8 (int)GrFonts_MsDosCga8x8Font


#define GrFonts__init()

#endif
