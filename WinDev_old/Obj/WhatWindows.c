/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "Console.h"
#include "KolWindows.h"




static void WhatWindows_ShowBit (void);


/*============================================================================*/

static void WhatWindows_ShowBit (void)
{
	if (KolWindows_Is64Bit()) {
		Console_WriteStrLn((CHAR*)" (64 bit)", (LONGINT)10);
	} else {
		Console_WriteStrLn((CHAR*)" (32 bit)", (LONGINT)10);
	}
}


export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(Console__init);
	__IMPORT(KolWindows__init);
	__REGMAIN("WhatWindows", 0);
/* BEGIN */
	Console_WriteStr((CHAR*)"Runned under Windows ", (LONGINT)22);
	switch (KolWindows_WinVer()) {
		case 1: 
			Console_WriteStr((CHAR*)"95", (LONGINT)3);
			break;
		case 2: 
			Console_WriteStr((CHAR*)"98", (LONGINT)3);
			break;
		case 3: 
			Console_WriteStr((CHAR*)"ME", (LONGINT)3);
			break;
		case 4: 
			Console_WriteStr((CHAR*)"NT", (LONGINT)3);
			break;
		case 5: 
			Console_WriteStr((CHAR*)"2000", (LONGINT)5);
			break;
		case 6: 
			Console_WriteStr((CHAR*)"XP", (LONGINT)3);
			WhatWindows_ShowBit();
			break;
		case 7: 
			Console_WriteStr((CHAR*)"Server 2003", (LONGINT)12);
			WhatWindows_ShowBit();
			break;
		case 8: 
			Console_WriteStr((CHAR*)"Vista", (LONGINT)6);
			WhatWindows_ShowBit();
			break;
		case 9: 
			Console_WriteStr((CHAR*)"7", (LONGINT)2);
			WhatWindows_ShowBit();
			break;
		case 10: 
			Console_WriteStr((CHAR*)"8", (LONGINT)2);
			WhatWindows_ShowBit();
			break;
		default: 
			break;
	}
	__FINI;
}
