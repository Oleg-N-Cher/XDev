/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Console.h"
#include "Mega.h"







export void *DemoInvert__init(void)
{
	__DEFMOD;
	__IMPORT(Console);
	__IMPORT(Mega);
	__REGMOD("DemoInvert", 0);
/* BEGIN */
	Mega_INVERT();
	Console_WriteStr((CHAR*)" To Be Inverted!", (LONGINT)17);
	Mega_INVERT();
	Console_WriteStr((CHAR*)" To Be Inverted!", (LONGINT)17);
	Mega_INVERT();
	__ENDMOD;
}
