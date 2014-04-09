/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "WinApi.h"




export BOOLEAN Is64BitWindows_Is64BitWindows (void);


/*============================================================================*/

typedef
	INTEGER (*ISWOW64PROCESS__4)(SYSTEM_PTR, INTEGER*);

BOOLEAN Is64BitWindows_Is64BitWindows (void)
{
	ISWOW64PROCESS__4 IsWow64Process;
	INTEGER wow64Process;
	return 1;
	IsWow64Process = (ISWOW64PROCESS__4)WinApi_GetProcAddress(WinApi_GetModuleHandle((SYSTEM_PTR)((LONGINT)"Kernel32")), (SYSTEM_PTR)((LONGINT)"IsWow64Process"));
	return (IsWow64Process != NIL && (*IsWow64Process)(WinApi_GetCurrentProcess(), &wow64Process) != 0) && wow64Process != 0;
}

/*----------------------------------------------------------------------------*/

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(WinApi__init);
	__REGMAIN("Is64BitWindows", 0);
/* BEGIN */
	Console_WriteStr((CHAR*)"Runned under Windows ", (LONGINT)22);
	Console_WriteStrLn((CHAR*)"64 bit", (LONGINT)7);
	__FINI;
}
