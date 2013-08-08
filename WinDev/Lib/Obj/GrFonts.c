/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	SYSTEM_BYTE *GrFonts_Font;


export SYSTEM_BYTE GrFonts_ZxSpecROM8x8[768];
export SYSTEM_BYTE GrFonts_MsDosCGA8x8[2048];





export void *GrFonts__init(void)
{
	__DEFMOD;
	__REGMOD("GrFonts", 0);
/* BEGIN */
	__ENDMOD;
}
