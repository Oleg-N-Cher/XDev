/* Ofront+ 1.0 -m3 -21 */
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
	Basic_PRSTR((void*)&"Hello World", 12);
	__FINI;
}
