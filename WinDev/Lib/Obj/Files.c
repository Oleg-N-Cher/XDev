/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	struct Files_File {
		INTEGER handle;
		BOOLEAN end, error;
	} Files_File;

export void Files_File_Close (Files_File *file, LONGINT *file__typ);
typedef
	CHAR *Files_STRING;

export void Files_File_OpenToRead (Files_File *file, LONGINT *file__typ, CHAR *fname, LONGINT fname__len);
export void Files_File_OpenToWrite (Files_File *file, LONGINT *file__typ, CHAR *fname, LONGINT fname__len);
#define __Files_File_Close(file, file__typ) __SEND(file__typ, Files_File_Close, 0, void(*)(Files_File*, LONGINT *), (file, file__typ))
#define __Files_File_OpenToRead(file, file__typ, fname, fname__len) __SEND(file__typ, Files_File_OpenToRead, 1, void(*)(Files_File*, LONGINT *, CHAR*, LONGINT ), (file, file__typ, fname, fname__len))
#define __Files_File_OpenToWrite(file, file__typ, fname, fname__len) __SEND(file__typ, Files_File_OpenToWrite, 2, void(*)(Files_File*, LONGINT *, CHAR*, LONGINT ), (file, file__typ, fname, fname__len))

typedef
	struct Files_FileToRead { /* Files_File */
		INTEGER handle;
		BOOLEAN end, error;
	} Files_FileToRead;

export SYSTEM_BYTE Files_FileToRead_ReadByte (Files_FileToRead *fromfile, LONGINT *fromfile__typ);
#define __Files_FileToRead_ReadByte(fromfile, fromfile__typ) __SEND(fromfile__typ, Files_FileToRead_ReadByte, 3, SYSTEM_BYTE(*)(Files_FileToRead*, LONGINT *), (fromfile, fromfile__typ))

typedef
	struct Files_FileToWrite { /* Files_File */
		INTEGER handle;
		BOOLEAN end, error;
	} Files_FileToWrite;

export void Files_FileToWrite_WriteByte (Files_FileToWrite *tofile, LONGINT *tofile__typ, SYSTEM_BYTE byte);
#define __Files_FileToWrite_WriteByte(tofile, tofile__typ, byte) __SEND(tofile__typ, Files_FileToWrite_WriteByte, 3, void(*)(Files_FileToWrite*, LONGINT *, SYSTEM_BYTE), (tofile, tofile__typ, byte))

typedef
	CHAR *Files_PtrSTR;



export LONGINT *Files_File__typ;
export LONGINT *Files_FileToRead__typ;
export LONGINT *Files_FileToWrite__typ;

export BOOLEAN Files_DeleteFile (CHAR *fname, LONGINT fname__len);
export BOOLEAN Files_ExistsFile (CHAR *fname, LONGINT fname__len);

#define Files_EOF()	EOF
#define Files_fclose(file)	fclose((FILE*)file)
#define Files_feof(file)	feof((FILE*)file)
#define Files_fgetc(file)	fgetc((FILE*)file)
#define Files_fopen(filename, filename__len, mode, mode__len)	(int)fopen(filename, mode)
#define Files_fputc(c, file)	fputc(c, (FILE*)file)
#include <stdio.h>
#include <unistd.h>
#define Files_unlink(filename, filename__len)	unlink(filename)

void Files_File_OpenToRead (Files_File *file, LONGINT *file__typ, CHAR *fname, LONGINT fname__len)
{
	(*file).error = 0;
	(*file).handle = Files_fopen(fname, fname__len, (CHAR*)"rb", (LONGINT)3);
	if ((*file).handle == 0) {
		(*file).error = 1;
		(*file).end = 1;
	} else {
		(*file).end = Files_feof((*file).handle) != 0;
	}
}

void Files_File_OpenToWrite (Files_File *file, LONGINT *file__typ, CHAR *fname, LONGINT fname__len)
{
	(*file).error = 0;
	(*file).handle = Files_fopen(fname, fname__len, (CHAR*)"wb", (LONGINT)3);
	if ((*file).handle == 0) {
		(*file).error = 1;
	}
}

void Files_File_Close (Files_File *file, LONGINT *file__typ)
{
	if ((*file).handle != 0) {
		if (Files_fclose((*file).handle) != 0) {
			(*file).error = 1;
		}
		(*file).handle = 0;
	} else {
		(*file).error = 1;
	}
}

SYSTEM_BYTE Files_FileToRead_ReadByte (Files_FileToRead *fromfile, LONGINT *fromfile__typ)
{
	INTEGER byte;
	if ((*fromfile).error) {
		return 0;
	}
	byte = Files_fgetc((*fromfile).handle);
	if (byte == Files_EOF()) {
		if (Files_feof((*fromfile).handle) != 0) {
			(*fromfile).end = 1;
			return 0;
		} else {
			(*fromfile).error = 1;
			return 0;
		}
	}
	return (int)byte;
}

void Files_FileToWrite_WriteByte (Files_FileToWrite *tofile, LONGINT *tofile__typ, SYSTEM_BYTE byte)
{
	INTEGER exitcode;
	if ((*tofile).error) {
		return;
	}
	exitcode = Files_fputc((int)(__VAL(CHAR, byte)), (*tofile).handle);
	if (exitcode == Files_EOF()) {
		if (Files_feof((*tofile).handle) != 0) {
			(*tofile).end = 1;
		}
	}
}

BOOLEAN Files_DeleteFile (CHAR *fname, LONGINT fname__len)
{
	return Files_unlink(fname, fname__len) == 0;
}

BOOLEAN Files_ExistsFile (CHAR *fname, LONGINT fname__len)
{
	Files_FileToRead f;
	__Files_File_OpenToRead((void*)&f, Files_FileToRead__typ, fname, fname__len);
	__Files_File_Close((void*)&f, Files_FileToRead__typ);
	return !f.error;
}

__TDESC(Files_File, 4, 0) = {__TDFLDS("File", 8), {-4}};
__TDESC(Files_FileToRead, 5, 0) = {__TDFLDS("FileToRead", 8), {-4}};
__TDESC(Files_FileToWrite, 5, 0) = {__TDFLDS("FileToWrite", 8), {-4}};

export void *Files__init(void)
{
	__DEFMOD;
	__REGMOD("Files", 0);
	__INITYP(Files_File, Files_File, 0);
	__INITBP(Files_File, Files_File_Close, 0);
	__INITBP(Files_File, Files_File_OpenToRead, 1);
	__INITBP(Files_File, Files_File_OpenToWrite, 2);
	__INITYP(Files_FileToRead, Files_File, 1);
	__INITBP(Files_FileToRead, Files_FileToRead_ReadByte, 3);
	__INITYP(Files_FileToWrite, Files_File, 1);
	__INITBP(Files_FileToWrite, Files_FileToWrite_WriteByte, 3);
/* BEGIN */
	__ENDMOD;
}
