/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	BYTE *GrFonts_Font;


export BYTE GrFonts_ZxSpecRom8x8[768], GrFonts_ZxSpecRus8x8[768];
export BYTE GrFonts_MsDosCga8x8[2048];




/*============================================================================*/


export void *GrFonts__init(void)
{
	__DEFMOD;
	__REGMOD("GrFonts", 0);
/* BEGIN */
	__ENDMOD;
}
