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
		char _prvt1[4];
		SHORTINT Cursor;
		char _prvt2[128];
		INTEGER Color, TextColor;
		char _prvt3[4];
		SET Style, ExStyle;
		char _prvt4[4];
		INTEGER Left, Top, Width, Height;
		AclLib_PWinControl Parent;
		BOOLEAN AutoStop;
		char _prvt5[7];
		BOOLEAN Enabled, IsModal;
		char _prvt6[7];
		BOOLEAN Visible;
		char _prvt7[4];
		AclLib_TLabel L1;
		AclLib_TListBox Lb1;
		AclLib_TCheckBox Ch1, Ch2, Ch3, Ch4;
		AclLib_TButton Btn1, Btn2;
		AclLib_TProgressBar Prg1;
	} AclDemo_TWnd1;

static void AclDemo_TWnd1_Btn1Click (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender);
static void AclDemo_TWnd1_Btn2Click (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender);
static void AclDemo_TWnd1_WndCreate (AclDemo_TWnd1 *w, LONGINT *w__typ, AclLib_TObject sender);
#define __AclDemo_TWnd1_Btn1Click(w, w__typ, sender) __SEND(w__typ, AclDemo_TWnd1_Btn1Click, 27, void(*)(AclDemo_TWnd1*, LONGINT *, AclLib_TObject), (w, w__typ, sender))
#define __AclDemo_TWnd1_Btn2Click(w, w__typ, sender) __SEND(w__typ, AclDemo_TWnd1_Btn2Click, 28, void(*)(AclDemo_TWnd1*, LONGINT *, AclLib_TObject), (w, w__typ, sender))
#define __AclDemo_TWnd1_WndCreate(w, w__typ, sender) __SEND(w__typ, AclDemo_TWnd1_WndCreate, 29, void(*)(AclDemo_TWnd1*, LONGINT *, AclLib_TObject), (w, w__typ, sender))


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
	__ENUMR(&AclDemo_Wnd1, AclDemo_TWnd1__typ, 9960, 1, P);
}

__TDESC(AclDemo_TWnd1__desc, 31, 90) = {__TDFLDS("TWnd1", 9960), {0, 4, 788, 792, 800, 804, 924, 968, 976, 996, 1000, 1784, 1788, 1796, 1800, 1920, 
	1964, 1972, 1992, 1996, 2780, 2784, 2792, 2796, 2916, 2960, 2968, 2988, 2992, 3776, 3780, 3788, 
	3792, 3912, 3956, 3964, 3984, 3988, 4772, 4776, 4784, 4788, 4908, 4952, 4960, 4980, 4984, 5768, 
	5772, 5780, 5784, 5904, 5948, 5956, 5976, 5980, 6764, 6768, 6776, 6780, 6900, 6944, 6952, 6972, 
	6976, 7760, 7764, 7772, 7776, 7896, 7940, 7948, 7968, 7972, 8756, 8760, 8768, 8772, 8892, 8936, 
	8944, 8964, 8968, 9752, 9756, 9764, 9768, 9888, 9932, 9940, -728}};

export main(int argc, char **argv)
{
	__INIT(argc, argv);
	__IMPORT(AclLib__init);
	__IMPORT(Ignore__init);
	__IMPORT(AclUtils__init);
	__IMPORT(WinApi__init);
	__REGMAIN("AclDemo", EnumPtrs);
	__INITYP(AclDemo_TWnd1, AclLib_TWinControl, 1);
	__INITBP(AclDemo_TWnd1, AclDemo_TWnd1_Btn1Click, 27);
	__INITBP(AclDemo_TWnd1, AclDemo_TWnd1_Btn2Click, 28);
	__INITBP(AclDemo_TWnd1, AclDemo_TWnd1_WndCreate, 29);
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
