/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "GrScr.h"
#include "SdlLib.h"







export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(GrScr__init);
	__IMPORT(SdlLib__init);
	__REGMAIN("GrTest", 0);
/* BEGIN */
	SdlLib_Delay(5000);
	GrScr_Close();
	__FINI;
}
