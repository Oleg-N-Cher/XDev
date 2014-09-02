/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "AclLib.h"
#include "AclUtils.h"
#include "WinApi.h"

typedef
	struct AclDemo_TWnd1 { /* AclLib_TWinControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		char _prvt1[4];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style;
		char _prvt3[8];
		INTEGER Left, Top, Width, Height;
		char _prvt4[15];
		BOOLEAN Visible;
		char _prvt5[4];
	} AclDemo_TWnd1;


static AclDemo_TWnd1 AclDemo_Wnd1;
static CHAR AclDemo_s1[256], AclDemo_s2[256];
static BOOLEAN AclDemo_trig;

export LONGINT *AclDemo_TWnd1__typ;



/*============================================================================*/

static void EnumPtrs(void (*P)(void*))
{
	__ENUMR(&AclDemo_Wnd1, AclDemo_TWnd1__typ, 856, 1, P);
}

__TDESC(AclDemo_TWnd1__desc, 13, 6) = {__TDFLDS("TWnd1", 856), {0, 4, 788, 792, 836, 844, -56}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(AclLib__init);
	__IMPORT(AclUtils__init);
	__IMPORT(WinApi__init);
	__REGMAIN("AclDemo", EnumPtrs);
	__INITYP(AclDemo_TWnd1, AclLib_TWinControl, 1);
/* BEGIN */
	__MOVE("Sorted ListBox Sample", AclDemo_s1, 22);
	__MOVE("SORTED LISTBOX SAMPLE", AclDemo_s2, 22);
	AclDemo_trig = 0;
	__AclLib_TWinControl_Create((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, NIL);
	AclDemo_Wnd1.Style = 0xc80000;
	__AclLib_TWinControl_SetWidth((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, 350);
	__AclLib_TWinControl_SetHeight((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, 300);
	__AclLib_TWinControl_SetLeft((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, __ASHR(WinApi_GetSystemMetrics(0) - AclDemo_Wnd1.Width, 1));
	__AclLib_TWinControl_SetTop((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, __ASHR(WinApi_GetSystemMetrics(1) - AclDemo_Wnd1.Height, 1));
	__AclLib_TWinControl_SetColor((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, AclUtils_RGB('3', 0x99, 0xff));
	__AclLib_TWinControl_SetCaption((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, (void*)&"Win32 API Programming Sample", (LONGINT)29);
	__FINI;
}
