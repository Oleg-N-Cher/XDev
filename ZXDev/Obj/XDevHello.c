/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Console.h"







export void *XDevHello__init(void)
{
	__DEFMOD;
	__IMPORT(Console);
	__REGMOD("XDevHello", 0);
/* BEGIN */
	Console_SetColors(77);
	Console_WriteStr((CHAR*)"Hello Cross-platform World", (LONGINT)27);
	__ENDMOD;
}
