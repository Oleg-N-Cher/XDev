/* Ofront+ 0.9 -sm */
#include "SYSTEM.h"
#include "Basic.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("TinyHello", 0);
/* BEGIN */
	Basic_Init();
	Basic_PRSTR((CHAR*)"Hello World", 12);
	__FINI;
}
