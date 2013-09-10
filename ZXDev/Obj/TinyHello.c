/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"







export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("TinyHello", 0);
/* BEGIN */
	Basic_PRSTR((CHAR*)"Hello World", (LONGINT)12);
	__FINI;
}
