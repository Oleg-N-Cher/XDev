/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Basic.h"







export void *TinyHello__init(void)
{
	__DEFMOD;
	__IMPORT(Basic);
	__REGMOD("TinyHello", 0);
/* BEGIN */
	Basic_PRSTR((CHAR*)"Hello World", (LONGINT)12);
	__ENDMOD;
}
