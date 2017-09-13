/* Ofront+ 0.9 -sm */
#include "SYSTEM.h"
#include "Basic.h"
#include "Input.h"


static CHAR TestInput_key;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Input__init);
	__REGMAIN("TestInput", 0);
/* BEGIN */
	Basic_Init();
	do {
		TestInput_key = Input_Read();
		Basic_PRCHAR(TestInput_key);
	} while (!(TestInput_key == '0'));
	Basic_Quit();
	__FINI;
}
