/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolStrings.h"
#include "KolTypes.h"
#include "WinApi.h"


export SYSTEM_PTR KolFiles_hInstance;


export BOOLEAN KolFiles_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len);
export BOOLEAN KolFiles_ExtractFilePath (CHAR *path, LONGINT path__len, CHAR *res, LONGINT res__len);
export BOOLEAN KolFiles_FileClose (SYSTEM_PTR handle);
export SYSTEM_PTR KolFiles_FileCreate (CHAR *fileName, LONGINT fileName__len, SET openFlags);
export BOOLEAN KolFiles_SameFile (CHAR *fileName1, LONGINT fileName1__len, CHAR *fileName2, LONGINT fileName2__len);

#define KolFiles__init()	/*-noinit*/

/*============================================================================*/

SYSTEM_PTR KolFiles_FileCreate (CHAR *fileName, LONGINT fileName__len, SET openFlags)
{
	SET attr;
	attr = __LSHR(openFlags, 16, SET) & 0x1fff;
	if (attr == 0x0) {
		attr = 0x80;
	}
	return WinApi_CreateFile((SYSTEM_PTR)((INTEGER)fileName), openFlags & 0xf0000000, openFlags & 0x0f, NIL, NIL, (INTEGER)(__LSHR(openFlags, 8, SET) & 0x0f), attr, NIL);
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolFiles_FileClose (SYSTEM_PTR handle)
{
	return WinApi_CloseHandle(handle) != 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolFiles_ExtractFilePath (CHAR *path, LONGINT path__len, CHAR *res, LONGINT res__len)
{
	INTEGER p;
	p = KolStrings_DelimiterLast(path, path__len, (void*)&":\\/", (LONGINT)4);
	if (path[__X(p, path__len)] != 0x00) {
		return KolStrings_SubStr((void*)path, path__len, 0, p + 1, (void*)res, res__len);
	}
	res[0] = 0x00;
	return 1;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolFiles_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len)
{
	INTEGER p;
	p = KolStrings_DelimiterLast(path, path__len, (void*)&":\\/", (LONGINT)4);
	if (path[__X(p, path__len)] != 0x00) {
		return KolStrings_SubStr((void*)path, path__len, p + 1, (INTEGER)path__len, (void*)name, name__len);
	}
	return KolStrings_SubStr((void*)path, path__len, 0, p, (void*)name, name__len);
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolFiles_SameFile (CHAR *fileName1, LONGINT fileName1__len, CHAR *fileName2, LONGINT fileName2__len)
{
	WinApi_BY_HANDLE_FILE_INFORMATION fileInfo1, fileInfo2;
	SYSTEM_PTR handle1 = NIL, handle2 = NIL;
	BOOLEAN same;
	INTEGER res;
	same = 0;
	handle1 = WinApi_CreateFileA((SYSTEM_PTR)((INTEGER)fileName1), 0x80000000, 0x01, NIL, NIL, 3, 0x0, NIL);
	if (handle1 != (SYSTEM_PTR)-1) {
		handle2 = WinApi_CreateFileA((SYSTEM_PTR)((INTEGER)fileName2), 0x80000000, 0x01, NIL, NIL, 3, 0x0, NIL);
		if (handle2 != (SYSTEM_PTR)-1) {
			same = (((WinApi_GetFileInformationByHandle(handle1, &fileInfo1, WinApi_BY_HANDLE_FILE_INFORMATION__typ) != 0 && WinApi_GetFileInformationByHandle(handle2, &fileInfo2, WinApi_BY_HANDLE_FILE_INFORMATION__typ) != 0) && fileInfo1.nFileIndexLow == fileInfo2.nFileIndexLow) && fileInfo1.nFileIndexHigh == fileInfo2.nFileIndexHigh) && fileInfo1.dwVolumeSerialNumber == fileInfo2.dwVolumeSerialNumber;
			res = WinApi_CloseHandle(handle2);
		}
		res = WinApi_CloseHandle(handle1);
	}
	return same;
}

/*----------------------------------------------------------------------------*/
static void EnumPtrs(void (*P)(void*))
{
	P(KolFiles_hInstance);
}


export void *KolFiles__init(void)
{
	__DEFMOD;
	__IMPORT(KolStrings__init);
	__IMPORT(KolTypes__init);
	__IMPORT(WinApi__init);
	__REGMOD("KolFiles", EnumPtrs);
/* BEGIN */
	__ENDMOD;
}
