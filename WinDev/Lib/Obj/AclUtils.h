/*  Ofront 1.2 -xtspkae */

#ifndef AclUtils__h
#define AclUtils__h

#include "SYSTEM.h"
#include "WinApi.h"

typedef
	CHAR *AclUtils_String;


import INTEGER AclUtils_Win32Platform, AclUtils_Win32MajorVersion, AclUtils_Win32MinorVersion, AclUtils_Win32BuildNumber;
import CHAR AclUtils_Win32CSDVersion[128];


import INTEGER AclUtils_ColorToRGB (INTEGER color);
import void AclUtils_FileClose (SYSTEM_PTR handle);
import SYSTEM_PTR AclUtils_FileCreate (CHAR *fileName, LONGINT fileName__len);
import SYSTEM_PTR AclUtils_FileOpen (CHAR *fileName, LONGINT fileName__len, INTEGER mode);
import INTEGER AclUtils_FileRead (SYSTEM_PTR handle, BYTE *buffer, LONGINT buffer__len, INTEGER count);
import INTEGER AclUtils_FileWrite (SYSTEM_PTR handle, BYTE *buffer, LONGINT buffer__len, INTEGER Count);
import INTEGER AclUtils_HeightOf (WinApi_RECT r);
import INTEGER AclUtils_RGB (BYTE r, BYTE g, BYTE b);
import INTEGER AclUtils_WidthOf (WinApi_RECT r);
import void *AclUtils__init(void);


#endif
