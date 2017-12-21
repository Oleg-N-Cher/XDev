/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Files.h"
#include "Strings.h"
#include "Console.h"


static CHAR TestUtf8_str[2];
static CHAR TestUtf8_utfstr[2];
static Files_FileToRead TestUtf8_stringfile;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Files__init);
	__IMPORT(Strings__init);
	__IMPORT(Console__init);
	__REGMAIN("TestUtf8", 0);
/* BEGIN */
	TestUtf8_str[0] = 'A';
	TestUtf8_str[1] = 'B';
	if (Strings_Utf8ToWin1251((void*)TestUtf8_str, 2, (void*)TestUtf8_utfstr, 2)) {
		Console_WriteStr((CHAR*)"Ok ", (LONGINT)4);
	} else {
		Console_WriteStr((CHAR*)"Err ", (LONGINT)5);
	}
	Console_WriteStr(TestUtf8_utfstr, 2);
	__FINI;
}
