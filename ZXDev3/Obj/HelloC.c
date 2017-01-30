/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("HelloC", 0);
/* BEGIN */
	Basic_BORDER(3);
	Basic_COLOR(4);
	Basic_PRSTR((CHAR*)"Hello ", 7);
	Basic_COLOR(5);
	Basic_PRSTR((CHAR*)"Hello ", 7);
	Basic_COLOR(6);
	Basic_PRSTR((CHAR*)"Hello ", 7);
	__FINI;
}
