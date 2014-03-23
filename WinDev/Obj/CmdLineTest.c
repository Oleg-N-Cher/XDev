/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "CmdLine.h"
#include "Console.h"
#include "Strings.h"


static INTEGER CmdLineTest_i, CmdLineTest_n;
static CmdLine_String CmdLineTest_param;
static INTEGER CmdLineTest__for__2, CmdLineTest__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(CmdLine__init);
	__IMPORT(Console__init);
	__IMPORT(Strings__init);
	__REGMAIN("CmdLineTest", 0);
/* BEGIN */
	CmdLineTest_n = 1;
	CmdLineTest__for__2 = CmdLine_ParamCount;
	if (CmdLineTest_n <= CmdLineTest__for__2) {
		CmdLineTest__for__2 = (CmdLineTest__for__2 - CmdLineTest_n) + 1;
		do {
			CmdLine_GetParam(CmdLineTest_n, (void*)CmdLineTest_param, 1024);
			Console_WriteInt(CmdLineTest_n);
			Console_WriteStr((CHAR*)":", (LONGINT)2);
			Console_WriteStrLn(CmdLineTest_param, 1024);
			CmdLineTest_i = 0;
			CmdLineTest__for__1 = (int)Strings_Length((void*)CmdLineTest_param, 1024) - 1;
			if (CmdLineTest_i <= CmdLineTest__for__1) {
				CmdLineTest__for__1 = (CmdLineTest__for__1 - CmdLineTest_i) + 1;
				do {
					Console_WriteInt((int)CmdLineTest_param[__X(CmdLineTest_i, 1024)]);
					Console_WriteStr((CHAR*)",", (LONGINT)2);
					CmdLineTest_i += 1;
					CmdLineTest__for__1 -= 1;
				} while (!(CmdLineTest__for__1 == 0));
			}
			Console_WriteLn();
			CmdLineTest_n += 1;
			CmdLineTest__for__2 -= 1;
		} while (!(CmdLineTest__for__2 == 0));
	}
	__FINI;
}
