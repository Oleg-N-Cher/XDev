/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolStrings.h"
#include "KolTypes.h"
#include "WinApi.h"


export SYSTEM_PTR KolFiles_hInstance;


export BOOLEAN KolFiles_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len);
export BOOLEAN KolFiles_FileClose (SYSTEM_PTR handle);
export SYSTEM_PTR KolFiles_FileCreate (CHAR *fileName, LONGINT fileName__len, SET openFlags);

#define KolFiles__init()	/*-noinit*/

/*============================================================================*/

SYSTEM_PTR KolFiles_FileCreate (CHAR *fileName, LONGINT fileName__len, SET openFlags)
{
	SET attr;
	attr = __LSHR(openFlags, 16, SET) & 0x1fff;
	if (attr == 0x0) {
		attr = 0x80;
	}
	return WinApi_CreateFile((SYSTEM_PTR)((LONGINT)fileName), openFlags & 0xf0000000, openFlags & 0x0f, NIL, NIL, (int)(__LSHR(openFlags, 8, SET) & 0x0f), attr, NIL);
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolFiles_FileClose (SYSTEM_PTR handle)
{
	return WinApi_CloseHandle(handle) != 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolFiles_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len)
{
	INTEGER p;
	p = KolStrings_DelimiterLast(path, path__len, (void*)&":\\/", (LONGINT)4);
	if (path[__X(p, path__len)] != 0x00) {
		return KolStrings_SubStr((void*)path, path__len, p + 1, (int)path__len, (void*)name, name__len);
	}
	return KolStrings_SubStr((void*)path, path__len, 0, p - 1, (void*)name, name__len);
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
