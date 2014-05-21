/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Basic.h"


export INTEGER GrFonts_MsDosCga8x8, GrFonts_ZxSpecRus8x8;




/*============================================================================*/


export void *GrFonts__init(void)
{
	__DEFMOD;
	__IMPORT(Basic__init);
	__REGMOD("GrFonts", 0);
/* BEGIN */
	__ENDMOD;
}
