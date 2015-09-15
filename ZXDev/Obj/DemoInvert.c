/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "MegaBasic.h"






/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(MegaBasic__init);
	__REGMAIN("DemoInvert", 0);
/* BEGIN */
	Console_Clear(0);
	MegaBasic_INVERT();
	Console_WriteStr((CHAR*)" To Be Inverted!", (LONGINT)17);
	MegaBasic_INVERT();
	Console_WriteStr((CHAR*)" To Be Inverted!", (LONGINT)17);
	MegaBasic_INVERT();
	__FINI;
}
