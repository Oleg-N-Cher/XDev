/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "Math.h"


static INTEGER TestRnd_i, TestRnd__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(Math__init);
	__REGMAIN("TestRnd", 0);
/* BEGIN */
	TestRnd_i = 1;
	TestRnd__for__1 = 500;
	TestRnd__for__1 = (TestRnd__for__1 - TestRnd_i) + 1;
	do {
		Console_WriteInt(Math_RndRange(-3, 3));
		Console_WriteStr((CHAR*)"  ", (LONGINT)3);
		TestRnd_i += 1;
		TestRnd__for__1 -= 1;
	} while (!(TestRnd__for__1 == 0));
	__FINI;
}
