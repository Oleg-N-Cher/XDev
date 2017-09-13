/* Ofront+ 0.9 -sm */
#include "SYSTEM.h"
#include "Console.h"
#include "TrDos.h"


static CHAR TrDosTest_code;




/*============================================================================*/


int main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(TrDos__init);
	__REGMAIN("TrDosTest", 0);
/* BEGIN */
	TrDosTest_code = TrDos_FindFile((CHAR*)"file1", 6, 0x05);
	Console_WriteStr((CHAR*)"Found code: ", 13);
	Console_WriteInt((INTEGER)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((CHAR*)"boot", 5, 0x04);
	Console_WriteStr((CHAR*)"Found code: ", 13);
	Console_WriteInt((INTEGER)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((CHAR*)"Das2", 5, 0x04);
	Console_WriteStr((CHAR*)"Found code: ", 13);
	Console_WriteInt((INTEGER)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((CHAR*)"Dash", 5, 0x04);
	Console_WriteStr((CHAR*)"Found code: ", 13);
	Console_WriteInt((INTEGER)TrDosTest_code);
	Console_WriteLn();
	__FINI;
}
