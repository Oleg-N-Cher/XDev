/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "Mega.h"






/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Mega__init);
	__REGMAIN("DemoInvert", 0);
/* BEGIN */
	Console_Clear(0);
	Mega_INVERT();
	Console_WriteStr((CHAR*)" To Be Inverted!", (LONGINT)17);
	Mega_INVERT();
	Console_WriteStr((CHAR*)" To Be Inverted!", (LONGINT)17);
	Mega_INVERT();
	__FINI;
}
