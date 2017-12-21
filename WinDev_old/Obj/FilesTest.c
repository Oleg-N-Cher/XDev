/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Files.h"


static Files_FileToWrite FilesTest_file;





export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Files__init);
	__REGMAIN("FilesTest", 0);
/* BEGIN */
	__Files_File_OpenToWrite((void*)&FilesTest_file, Files_FileToWrite__typ, (CHAR*)"Privet.txt", (LONGINT)11);
	__Files_FileToWrite_WriteStr(&FilesTest_file, Files_FileToWrite__typ, (CHAR*)"Privet Yulia!", (LONGINT)14);
	__Files_File_Close((void*)&FilesTest_file, Files_FileToWrite__typ);
	__FINI;
}
