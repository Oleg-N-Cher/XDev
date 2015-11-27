/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Files.h"
#include "Strings.h"
#include "Console.h"


static CHAR TestUTF8_str[100];
static CHAR TestUTF8_utfstr[300];
static Files_FileToRead TestUTF8_stringfile;




/*============================================================================*/


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Files__init);
	__IMPORT(Strings__init);
	__IMPORT(Console__init);
	__REGMAIN("TestUTF8", 0);
/* BEGIN */
	__Files_File_OpenToRead((void*)&TestUTF8_stringfile, Files_FileToRead__typ, (CHAR*)"TestUTF8.txt", (LONGINT)13);
	__Files_FileToRead_ReadStr(&TestUTF8_stringfile, Files_FileToRead__typ, (void*)TestUTF8_str, 100);
	__Files_File_Close((void*)&TestUTF8_stringfile, Files_FileToRead__typ);
	if (Strings_CP1251ToUtf8((void*)TestUTF8_str, 100, (void*)TestUTF8_utfstr, 300)) {
		Console_WriteStr(TestUTF8_utfstr, 300);
	}
	__FINI;
}
