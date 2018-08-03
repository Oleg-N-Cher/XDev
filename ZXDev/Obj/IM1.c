/* Ofront+ 1.0 -m3 -21 */
#include "SYSTEM.h"
#include "Basic.h"






/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__REGMAIN("IM1", 0);
/* BEGIN */
	Basic_Init();
	Basic_POKE(23560, 0);
	Basic_AT(0, 0);
	Basic_PRSTR((void*)&"Press SPACE to exit", 20);
	do {
		Basic_AT(4, 4);
		Basic_PRINT(Basic_PEEK(23560));
		Basic_PRSTR((void*)&"   ", 4);
		Basic_AT(8, 8);
		Basic_PRINT(Basic_PEEK(23672));
		Basic_PRSTR((void*)&"   ", 4);
	} while (!(Basic_PEEK(23560) == 32));
	Basic_Quit();
	__FINI;
}
