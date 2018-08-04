/* Ofront+ 1.0 -m3 -21 */
#include "SYSTEM.h"
#include "Basic.h"
#include "Input.h"
#include "Timer.h"


static CHAR TestInpBuf_key;
static BYTE TestInpBuf_av;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Basic__init);
	__IMPORT(Input__init);
	__IMPORT(Timer__init);
	__REGMAIN("TestInpBuf", 0);
/* BEGIN */
	Basic_Init();
	Basic_CLS();
	Basic_IM2PROC(Input_RunMe50Hz);
	Basic_PRSTR((void*)&"PRESS KEYS SO MANY AS POSSIBLE!", 32);
	Basic_PRLN();
	Timer_Delay(500);
	Basic_AT(0, 0);
	Basic_PRINT(Input_Available());
	Basic_PRLN();
	while (Input_Available() > 0) {
		Basic_PRCHAR(Input_Read());
	}
	Basic_PRLN();
	do {
		TestInpBuf_av = Input_Available();
		Basic_AT(0, 0);
		Basic_PRINT(TestInpBuf_av);
		Basic_PRSTR((void*)&"    ", 5);
	} while (!(TestInpBuf_av == 8));
	Basic_AT(10, 10);
	while (Input_Available() > 0) {
		Basic_PRCHAR(Input_Read());
	}
	for (;;) {
	}
	__FINI;
}
