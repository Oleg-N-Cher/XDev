/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "TrDos.h"


static CHAR TrDosTest_code;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(TrDos__init);
	__REGMAIN("TrDosTest", 0);
/* BEGIN */
	TrDosTest_code = TrDos_FindFile((CHAR*)"file1", (LONGINT)6, 0x05);
	Console_WriteStr((CHAR*)"Found code: ", (LONGINT)13);
	Console_WriteInt((int)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((CHAR*)"boot", (LONGINT)5, 0x04);
	Console_WriteStr((CHAR*)"Found code: ", (LONGINT)13);
	Console_WriteInt((int)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((CHAR*)"Das2", (LONGINT)5, 0x04);
	Console_WriteStr((CHAR*)"Found code: ", (LONGINT)13);
	Console_WriteInt((int)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((CHAR*)"Dash", (LONGINT)5, 0x04);
	Console_WriteStr((CHAR*)"Found code: ", (LONGINT)13);
	Console_WriteInt((int)TrDosTest_code);
	Console_WriteLn();
	__FINI;
}
