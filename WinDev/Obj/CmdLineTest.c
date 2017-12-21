/* Ofront+ 1.0 -smC -48 */
#include "SYSTEM.h"
#include "CmdLine.h"
#include "Console.h"
#include "Strings.h"


static INTEGER CmdLineTest_i, CmdLineTest_n;
static CmdLine_String CmdLineTest_param;
static INTEGER CmdLineTest__for__2, CmdLineTest__for__1;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(CmdLine__init);
	__IMPORT(Console__init);
	__IMPORT(Strings__init);
	__REGMAIN("CmdLineTest", 0);
/* BEGIN */
	CmdLineTest__for__2 = CmdLine_ParamCount;
	CmdLineTest_n = 1;
	while (CmdLineTest_n <= CmdLineTest__for__2) {
		CmdLine_GetParam(CmdLineTest_n, (void*)CmdLineTest_param, 1024);
		Console_WriteInt(CmdLineTest_n);
		Console_WriteStr((CHAR*)":", 2);
		Console_WriteStrLn(CmdLineTest_param, 1024);
		CmdLineTest__for__1 = (SHORTINT)Strings_Length((void*)CmdLineTest_param, 1024) - 1;
		CmdLineTest_i = 0;
		while (CmdLineTest_i <= CmdLineTest__for__1) {
			Console_WriteInt((SHORTINT)CmdLineTest_param[__X(CmdLineTest_i, 1024)]);
			Console_WriteStr((CHAR*)",", 2);
			CmdLineTest_i += 1;
		}
		Console_WriteLn();
		CmdLineTest_n += 1;
	}
	__FINI;
}
