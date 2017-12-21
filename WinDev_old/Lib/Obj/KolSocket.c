/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "KolObj.h"
#include "WinApi.h"
#include "WinNet.h"

typedef
	struct KolSocket_TAsyncSocket *KolSocket_PAsyncSocket;

typedef
	struct KolSocket_TAsyncSocket { /* KolObj_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
	} KolSocket_TAsyncSocket;


static INTEGER KolSocket_InstanceCount;

export LONGINT *KolSocket_TAsyncSocket__typ;

static void KolSocket_KillWinsockBug (void);
export KolSocket_PAsyncSocket KolSocket_NewAsyncSocket (void);


/*============================================================================*/

KolSocket_PAsyncSocket KolSocket_NewAsyncSocket (void)
{
	WinNet_WSADATA TempWSAData;
	KolSocket_PAsyncSocket Result = NIL;
	KolSocket_InstanceCount = KolSocket_InstanceCount + 1;
	__NEW(Result, KolSocket_TAsyncSocket);
	__KolObj_TObj_Create((void*)&*Result, __TYPEOF(Result));
	if (KolSocket_InstanceCount == 1) {
		Ignore_Int(WinNet_WSAStartup(257, &TempWSAData, WinNet_WSADATA__typ));
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
static void KolSocket_KillWinsockBug (void)
{
	INTEGER Addr;
	Addr = 0;
	Ignore_Ptr((void*)WinNet_gethostbyname((SYSTEM_PTR)((INTEGER)"")));
	Ignore_Ptr((void*)WinNet_gethostbyaddr((SYSTEM_PTR)((INTEGER)&Addr), 4, 2));
	Ignore_Ptr((void*)WinNet_gethostbyname((SYSTEM_PTR)((INTEGER)"")));
}

__TDESC(KolSocket_TAsyncSocket__desc, 6, 2) = {__TDFLDS("TAsyncSocket", 16), {8, 12, -24}};

export void *KolSocket__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(KolObj__init);
	__IMPORT(WinApi__init);
	__IMPORT(WinNet__init);
	__REGMOD("KolSocket", 0);
	__INITYP(KolSocket_TAsyncSocket, KolObj_TObj, 1);
/* BEGIN */
	KolSocket_InstanceCount = 0;
	__ENDMOD;
}
