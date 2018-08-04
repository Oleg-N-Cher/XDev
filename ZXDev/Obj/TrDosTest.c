/* Ofront+ 1.0 -m3 -21 */
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
	TrDosTest_code = TrDos_FindFile((void*)&"file1", 6, 0x05);
	Console_WriteStr((void*)&"Found code: ", 13);
	Console_WriteInt((SHORTINT)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((void*)&"boot", 5, 0x04);
	Console_WriteStr((void*)&"Found code: ", 13);
	Console_WriteInt((SHORTINT)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((void*)&"Das2", 5, 0x04);
	Console_WriteStr((void*)&"Found code: ", 13);
	Console_WriteInt((SHORTINT)TrDosTest_code);
	Console_WriteLn();
	TrDosTest_code = TrDos_FindFile((void*)&"Dash", 5, 0x04);
	Console_WriteStr((void*)&"Found code: ", 13);
	Console_WriteInt((SHORTINT)TrDosTest_code);
	Console_WriteLn();
	__FINI;
}
