/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "CmdLine.h"
#include "Console.h"
#include "Strings.h"


static INTEGER CmdLnTst_i, CmdLnTst_n;
static CmdLine_String CmdLnTst_param;
static INTEGER CmdLnTst__for__2, CmdLnTst__for__1;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(CmdLine__init);
	__IMPORT(Console__init);
	__IMPORT(Strings__init);
	__REGMAIN("CmdLnTst", 0);
/* BEGIN */
	Console_WriteInt(CmdLine_paramCount);
	Console_WriteLn();
	CmdLnTst_n = 1;
	CmdLnTst__for__2 = CmdLine_paramCount;
	if (CmdLnTst_n <= CmdLnTst__for__2) {
		CmdLnTst__for__2 = (CmdLnTst__for__2 - CmdLnTst_n) + 1;
		do {
			CmdLine_GetParam(CmdLnTst_n, (void*)CmdLnTst_param, 128);
			Console_WriteInt(CmdLnTst_n);
			Console_WriteStr((CHAR*)":", (LONGINT)2);
			Console_WriteStrLn(CmdLnTst_param, 128);
			CmdLnTst_i = 0;
			CmdLnTst__for__1 = (int)Strings_Length((void*)CmdLnTst_param, 128) - 1;
			if (CmdLnTst_i <= CmdLnTst__for__1) {
				CmdLnTst__for__1 = (CmdLnTst__for__1 - CmdLnTst_i) + 1;
				do {
					Console_WriteInt((int)CmdLnTst_param[__X(CmdLnTst_i, 128)]);
					Console_WriteStr((CHAR*)",", (LONGINT)2);
					CmdLnTst_i += 1;
					CmdLnTst__for__1 -= 1;
				} while (!(CmdLnTst__for__1 == 0));
			}
			Console_WriteLn();
			CmdLnTst_n += 1;
			CmdLnTst__for__2 -= 1;
		} while (!(CmdLnTst__for__2 == 0));
	}
	__FINI;
}
