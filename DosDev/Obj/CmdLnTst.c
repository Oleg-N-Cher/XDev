/* Ofront+ 1.0 -mx3 -21 */
#include "SYSTEM.oh"
#include "CmdLine.oh"
#include "Console.oh"
#include "Strings.oh"


static SHORTINT CmdLnTst_i, CmdLnTst_n;
static CmdLine_String CmdLnTst_param;
static SHORTINT CmdLnTst__for__2, CmdLnTst__for__1;




/*============================================================================*/


int main(int argc, char **argv)
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
		CmdLnTst__for__2 = (__U_SHORTINT)(CmdLnTst__for__2 - CmdLnTst_n) + 1;
		do {
			CmdLine_GetParam(CmdLnTst_n, (void*)CmdLnTst_param, 128);
			Console_WriteInt(CmdLnTst_n);
			Console_WriteStr((CHAR*)":", 2);
			Console_WriteStrLn((void*)CmdLnTst_param, 128);
			CmdLnTst_i = 0;
			CmdLnTst__for__1 = (SHORTINT)Strings_Length((void*)CmdLnTst_param, 128) - 1;
			if (CmdLnTst_i <= CmdLnTst__for__1) {
				CmdLnTst__for__1 = (__U_SHORTINT)(CmdLnTst__for__1 - CmdLnTst_i) + 1;
				do {
					Console_WriteInt((SHORTINT)CmdLnTst_param[CmdLnTst_i]);
					Console_WriteStr((CHAR*)",", 2);
					CmdLnTst_i += 1;
				} while (--CmdLnTst__for__1);
			}
			Console_WriteLn();
			CmdLnTst_n += 1;
		} while (--CmdLnTst__for__2);
	}
	__FINI;
}
