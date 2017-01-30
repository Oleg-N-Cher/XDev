/* Ofront+ 0.9 -xtspkaem */
#include "SYSTEM.h"
#include "Basic.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("Hello", 0);
/* BEGIN */
	Basic_PRSTR((CHAR*)"Hello World", 12);
	__FINI;
}
