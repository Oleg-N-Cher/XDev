/*  Ofront 1.2 -xtspkae */

#ifndef Files__h
#define Files__h

#include "SYSTEM.h"

typedef
	struct Files_File {
		INTEGER _prvt0;
		char _prvt1[8];
		BOOLEAN end, error;
	} Files_File;

import void Files_File_Close (Files_File *file, LONGINT *file__typ);
typedef
	CHAR *Files_STRING;

import void Files_File_OpenToRead (Files_File *file, LONGINT *file__typ, CHAR *fname, LONGINT fname__len);
import void Files_File_OpenToWrite (Files_File *file, LONGINT *file__typ, CHAR *fname, LONGINT fname__len);
#define __Files_File_Close(file, file__typ) __SEND(file__typ, Files_File_Close, 0, void(*)(Files_File*, LONGINT *), (file, file__typ))
#define __Files_File_OpenToRead(file, file__typ, fname, fname__len) __SEND(file__typ, Files_File_OpenToRead, 1, void(*)(Files_File*, LONGINT *, CHAR*, LONGINT ), (file, file__typ, fname, fname__len))
#define __Files_File_OpenToWrite(file, file__typ, fname, fname__len) __SEND(file__typ, Files_File_OpenToWrite, 2, void(*)(Files_File*, LONGINT *, CHAR*, LONGINT ), (file, file__typ, fname, fname__len))

typedef
	struct Files_FileToRead { /* Files_File */
		INTEGER _prvt0;
		char _prvt1[8];
		BOOLEAN end, error;
	} Files_FileToRead;

import BYTE Files_FileToRead_ReadByte (Files_FileToRead *fromfile, LONGINT *fromfile__typ);
import void Files_FileToRead_ReadStr (Files_FileToRead *fromfile, LONGINT *fromfile__typ, CHAR *str, LONGINT str__len);
#define __Files_FileToRead_ReadByte(fromfile, fromfile__typ) __SEND(fromfile__typ, Files_FileToRead_ReadByte, 3, BYTE(*)(Files_FileToRead*, LONGINT *), (fromfile, fromfile__typ))
#define __Files_FileToRead_ReadStr(fromfile, fromfile__typ, str, str__len) __SEND(fromfile__typ, Files_FileToRead_ReadStr, 4, void(*)(Files_FileToRead*, LONGINT *, CHAR*, LONGINT ), (fromfile, fromfile__typ, str, str__len))

typedef
	struct Files_FileToWrite { /* Files_File */
		INTEGER _prvt0;
		char _prvt1[8];
		BOOLEAN end, error;
	} Files_FileToWrite;

import void Files_FileToWrite_WriteByte (Files_FileToWrite *tofile, LONGINT *tofile__typ, BYTE byte);
import void Files_FileToWrite_WriteStr (Files_FileToWrite *tofile, LONGINT *tofile__typ, CHAR *str, LONGINT str__len);
#define __Files_FileToWrite_WriteByte(tofile, tofile__typ, byte) __SEND(tofile__typ, Files_FileToWrite_WriteByte, 3, void(*)(Files_FileToWrite*, LONGINT *, BYTE), (tofile, tofile__typ, byte))
#define __Files_FileToWrite_WriteStr(tofile, tofile__typ, str, str__len) __SEND(tofile__typ, Files_FileToWrite_WriteStr, 4, void(*)(Files_FileToWrite*, LONGINT *, CHAR*, LONGINT ), (tofile, tofile__typ, str, str__len))



import LONGINT *Files_File__typ;
import LONGINT *Files_FileToRead__typ;
import LONGINT *Files_FileToWrite__typ;

import BOOLEAN Files_DeleteFile (CHAR *fname, LONGINT fname__len);
import BOOLEAN Files_ExistsFile (CHAR *fname, LONGINT fname__len);
import void *Files__init(void);


#endif
