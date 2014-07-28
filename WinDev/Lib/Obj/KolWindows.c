/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolTypes.h"
#include "WinApi.h"


static CHAR KolWindows_saveWinVer, KolWindows_saveIs64Bit;


export BOOLEAN KolWindows_Is64Bit (void);
export BOOLEAN KolWindows_IsWinVer (SET ver);
export BYTE KolWindows_WinVer (void);


/*============================================================================*/

BYTE KolWindows_WinVer (void)
{
	CHAR majorVersion, minorVersion;
	INTEGER dwVersion;
	if (KolWindows_saveWinVer == 0xff) {
		dwVersion = WinApi_GetVersion();
		majorVersion = (CHAR)dwVersion;
		minorVersion = (CHAR)__ASHR(dwVersion, 8);
		if (dwVersion >= 0) {
			KolWindows_saveWinVer = 0x04;
			if (majorVersion >= 0x06) {
				if (minorVersion >= 0x02) {
					KolWindows_saveWinVer = 0x0a;
				} else if (minorVersion == 0x01) {
					KolWindows_saveWinVer = 0x09;
				} else {
					KolWindows_saveWinVer = 0x08;
				}
			} else {
				if (majorVersion >= 0x05) {
					if (minorVersion >= 0x01) {
						KolWindows_saveWinVer = 0x06;
						if (minorVersion >= 0x02) {
							KolWindows_saveWinVer = 0x07;
						}
					} else {
						KolWindows_saveWinVer = 0x05;
					}
				}
			}
		} else {
			KolWindows_saveWinVer = 0x01;
			if (majorVersion > 0x04 || majorVersion == 0x04 && minorVersion >= 0x10) {
				KolWindows_saveWinVer = 0x02;
				if (majorVersion == 0x04 && minorVersion >= 'Z') {
					KolWindows_saveWinVer = 0x03;
				}
			} else {
				if (majorVersion <= 0x03) {
					KolWindows_saveWinVer = 0x00;
				}
			}
		}
	}
	return KolWindows_saveWinVer;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolWindows_IsWinVer (SET ver)
{
	return __IN(KolWindows_WinVer(), ver);
}

/*----------------------------------------------------------------------------*/
typedef
	INTEGER (*ISWOW64PROCESS__4)(SYSTEM_PTR, INTEGER*);

BOOLEAN KolWindows_Is64Bit (void)
{
	ISWOW64PROCESS__4 IsWow64Process;
	INTEGER wow64Process;
	if (KolWindows_saveIs64Bit == 0xff) {
		IsWow64Process = (ISWOW64PROCESS__4)WinApi_GetProcAddress(WinApi_GetModuleHandle((SYSTEM_PTR)((LONGINT)"Kernel32")), (SYSTEM_PTR)((LONGINT)"IsWow64Process"));
		KolWindows_saveIs64Bit = (CHAR)((IsWow64Process != NIL && (*IsWow64Process)(WinApi_GetCurrentProcess(), &wow64Process) != 0) && wow64Process != 0);
	}
	return __VAL(BOOLEAN, KolWindows_saveIs64Bit);
}

/*----------------------------------------------------------------------------*/

export void *KolWindows__init(void)
{
	__DEFMOD;
	__IMPORT(KolTypes__init);
	__IMPORT(WinApi__init);
	__REGMOD("KolWindows", 0);
/* BEGIN */
	KolWindows_saveWinVer = 0xff;
	KolWindows_saveIs64Bit = 0xff;
	__ENDMOD;
}
