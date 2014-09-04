/*  Ofront 1.2 -xtspkaem */
#include "SYSTEM.h"
#include "AclLib.h"
#include "Ignore.h"
#include "AclUtils.h"
#include "WinApi.h"

typedef
	struct AclDemo_TWnd1 { /* AclLib_TWinControl */
		char _prvt0[788];
		SYSTEM_PTR Brush;
		SHORTINT Cursor;
		char _prvt1[68];
		INTEGER Color, TextColor;
		char _prvt2[4];
		SET Style, ExStyle;
		char _prvt3[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt4[7];
		BOOLEAN Enabled, IsModal;
		char _prvt5[7];
		BOOLEAN Visible;
		char _prvt6[4];
		AclLib_TLabel L1;
		AclLib_TListBox Lb1;
		AclLib_TCheckBox Ch1, Ch2, Ch3, Ch4;
		AclLib_TButton Btn1, Btn2;
		AclLib_TProgressBar Prg1;
	} AclDemo_TWnd1;

static void AclDemo_TWnd1_Btn1Click (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender);
static void AclDemo_TWnd1_Btn2Click (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender);
static void AclDemo_TWnd1_WndCreate (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender);
#define __AclDemo_TWnd1_Btn1Click(w, w__typ, sender) __SEND(w__typ, AclDemo_TWnd1_Btn1Click, 25, void(*)(AclDemo_TWnd1*, LONGINT *, AclLib_TObject), (w, w__typ, sender))
#define __AclDemo_TWnd1_Btn2Click(w, w__typ, sender) __SEND(w__typ, AclDemo_TWnd1_Btn2Click, 26, void(*)(AclDemo_TWnd1*, LONGINT *, AclLib_TObject), (w, w__typ, sender))
#define __AclDemo_TWnd1_WndCreate(w, w__typ, sender) __SEND(w__typ, AclDemo_TWnd1_WndCreate, 27, void(*)(AclDemo_TWnd1*, LONGINT *, AclLib_TObject), (w, w__typ, sender))


static AclDemo_TWnd1 AclDemo_Wnd1;
static CHAR AclDemo_s1[256], AclDemo_s2[256];
static BOOLEAN AclDemo_trig;

export LONGINT *AclDemo_TWnd1__typ;



/*============================================================================*/

static void AclDemo_TWnd1_WndCreate (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender)
{
	(*w).AutoStop = 1;
}

static void AclDemo_TWnd1_Btn1Click (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender)
{
}

static void AclDemo_TWnd1_Btn2Click (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender)
{
}

static void EnumPtrs(void (*P)(void*))
{
	__ENUMR(&AclDemo_Wnd1, AclDemo_TWnd1__typ, 9360, 1, P);
}

__TDESC(AclDemo_TWnd1__desc, 29, 90) = {__TDFLDS("TWnd1", 9360), {0, 4, 788, 792, 800, 804, 864, 908, 916, 936, 940, 1724, 1728, 1736, 1740, 1800, 
	1844, 1852, 1872, 1876, 2660, 2664, 2672, 2676, 2736, 2780, 2788, 2808, 2812, 3596, 3600, 3608, 
	3612, 3672, 3716, 3724, 3744, 3748, 4532, 4536, 4544, 4548, 4608, 4652, 4660, 4680, 4684, 5468, 
	5472, 5480, 5484, 5544, 5588, 5596, 5616, 5620, 6404, 6408, 6416, 6420, 6480, 6524, 6532, 6552, 
	6556, 7340, 7344, 7352, 7356, 7416, 7460, 7468, 7488, 7492, 8276, 8280, 8288, 8292, 8352, 8396, 
	8404, 8424, 8428, 9212, 9216, 9224, 9228, 9288, 9332, 9340, -728}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(AclLib__init);
	__IMPORT(Ignore__init);
	__IMPORT(AclUtils__init);
	__IMPORT(WinApi__init);
	__REGMAIN("AclDemo", EnumPtrs);
	__INITYP(AclDemo_TWnd1, AclLib_TWinControl, 1);
	__INITBP(AclDemo_TWnd1, AclDemo_TWnd1_Btn1Click, 25);
	__INITBP(AclDemo_TWnd1, AclDemo_TWnd1_Btn2Click, 26);
	__INITBP(AclDemo_TWnd1, AclDemo_TWnd1_WndCreate, 27);
/* BEGIN */
	__MOVE("Sorted ListBox Sample", AclDemo_s1, 22);
	__MOVE("SORTED LISTBOX SAMPLE", AclDemo_s2, 22);
	AclDemo_trig = 0;
	__AclLib_TWinControl_Create((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, NIL, NIL);
	AclDemo_Wnd1.Style = 0xc80000;
	__AclLib_TWinControl_SetWidth((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, 350);
	__AclLib_TWinControl_SetHeight((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, 300);
	__AclLib_TWinControl_SetLeft((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, __ASHR(WinApi_GetSystemMetrics(0) - AclDemo_Wnd1.Width, 1));
	__AclLib_TWinControl_SetTop((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, __ASHR(WinApi_GetSystemMetrics(1) - AclDemo_Wnd1.Height, 1));
	__AclLib_TWinControl_SetColor((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, AclUtils_RGB('3', 0x99, 0xff));
	__AclLib_TWinControl_SetCaption((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, (void*)&"Win32 API Programming Sample", (LONGINT)29);
	__AclLib_TWinControl_CreateWnd((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ);
	__AclLib_TWinControl_SetVisible((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ, 1);
	Ignore_Int(__AclLib_TWinControl_ShowModal((void*)&AclDemo_Wnd1, AclDemo_TWnd1__typ));
	__FINI;
}
