/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "WinApi.h"

typedef
	CHAR *AclUtils_String;


export INTEGER AclUtils_Win32Platform, AclUtils_Win32MajorVersion, AclUtils_Win32MinorVersion, AclUtils_Win32BuildNumber;
export CHAR AclUtils_Win32CSDVersion[128];


export INTEGER AclUtils_AnsiCompareText (CHAR *S1, LONGINT S1__len, CHAR *S2, LONGINT S2__len);
export INTEGER AclUtils_ColorToRGB (INTEGER color);
export void AclUtils_FileClose (SYSTEM_PTR handle);
export SYSTEM_PTR AclUtils_FileCreate (CHAR *fileName, LONGINT fileName__len);
export SYSTEM_PTR AclUtils_FileOpen (CHAR *fileName, LONGINT fileName__len, INTEGER mode);
export INTEGER AclUtils_FileRead (SYSTEM_PTR handle, BYTE *buffer, LONGINT buffer__len, INTEGER count);
export INTEGER AclUtils_FileWrite (SYSTEM_PTR handle, BYTE *buffer, LONGINT buffer__len, INTEGER Count);
export void AclUtils_FillChar (SYSTEM_PTR adr, INTEGER count, BYTE fill);
export INTEGER AclUtils_HeightOf (WinApi_RECT r);
export INTEGER AclUtils_Length (CHAR *str, LONGINT str__len);
export INTEGER AclUtils_MakeLong (INTEGER A, INTEGER B);
export INTEGER AclUtils_RGB (BYTE r, BYTE g, BYTE b);
export INTEGER AclUtils_WidthOf (WinApi_RECT r);


/*============================================================================*/

void AclUtils_FillChar (SYSTEM_PTR adr, INTEGER count, BYTE fill)
{
	while (count > 0) {
		__PUT(adr, fill, BYTE);
		adr = (SYSTEM_PTR)((LONGINT)adr + 1);
		count -= 1;
	}
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_WidthOf (WinApi_RECT r)
{
	return r.right - r.left;
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_HeightOf (WinApi_RECT r)
{
	return r.bottom - r.top;
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_ColorToRGB (INTEGER color)
{
	if (color < 0) {
		return WinApi_GetSysColor((int)((SET)(color) & 0xff));
	}
	return color;
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_RGB (BYTE r, BYTE g, BYTE b)
{
	return (__VAL(INTEGER, r) + __ASHL(__VAL(INTEGER, g), 8)) + __ASHL(__VAL(INTEGER, b), 16);
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_MakeLong (INTEGER A, INTEGER B)
{
	return A + __ASHL(B, 12);
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_Length (CHAR *str, LONGINT str__len)
{
	INTEGER len;
	len = 0;
	while (len < (int)str__len && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_AnsiCompareText (CHAR *S1, LONGINT S1__len, CHAR *S2, LONGINT S2__len)
{
	return WinApi_CompareString(1024, 0x01, (SYSTEM_PTR)((LONGINT)S1), AclUtils_Length((void*)S1, S1__len), (SYSTEM_PTR)((LONGINT)S2), AclUtils_Length((void*)S2, S2__len)) - 2;
}

/*----------------------------------------------------------------------------*/
SYSTEM_PTR AclUtils_FileOpen (CHAR *fileName, LONGINT fileName__len, INTEGER mode)
{
	SET AccessMode[3];
	SET ShareMode[5];
	INTEGER OpenMode[2];
	AccessMode[0] = 0x80000000;
	AccessMode[1] = 0x40000000;
	AccessMode[2] = 0xc0000000;
	ShareMode[0] = 0x0;
	ShareMode[1] = 0x0;
	ShareMode[2] = 0x01;
	ShareMode[3] = 0x02;
	ShareMode[4] = 0x03;
	OpenMode[0] = 3;
	OpenMode[1] = 5;
	return WinApi_CreateFile((SYSTEM_PTR)((LONGINT)fileName), AccessMode[__X((int)((SET)(mode) & 0x03), 3)], ShareMode[__X(__ASHR((int)((SET)(mode) & 0xf0), 4), 5)], NIL, NIL, OpenMode[__X(__ASHR((int)((SET)(mode) & 0x04), 2), 2)], 0x80, NIL);
}

/*----------------------------------------------------------------------------*/
SYSTEM_PTR AclUtils_FileCreate (CHAR *fileName, LONGINT fileName__len)
{
	return WinApi_CreateFile((SYSTEM_PTR)((LONGINT)fileName), 0xc0000000, 0x0, NIL, NIL, 2, 0x80, NIL);
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_FileRead (SYSTEM_PTR handle, BYTE *buffer, LONGINT buffer__len, INTEGER count)
{
	INTEGER result;
	if (0 == WinApi_ReadFile(handle, (SYSTEM_PTR)((LONGINT)buffer), count, &result, NIL, NIL)) {
		result = -1;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
INTEGER AclUtils_FileWrite (SYSTEM_PTR handle, BYTE *buffer, LONGINT buffer__len, INTEGER Count)
{
	INTEGER result;
	if (0 == WinApi_WriteFile(handle, (SYSTEM_PTR)((LONGINT)buffer), Count, &result, NIL, NIL)) {
		result = -1;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
void AclUtils_FileClose (SYSTEM_PTR handle)
{
	Ignore_Int(WinApi_CloseHandle(handle));
}

