/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "WinNet.h"
#include "KolObj.h"
#include "WinApi.h"

typedef
	struct KolXXSocket_TAccept *KolXXSocket_PAccept;

typedef
	struct KolXXSocket_TBaseSocket *KolXXSocket_PBaseSocket;

typedef
	struct KolXXSocket_TClient *KolXXSocket_PClient;

typedef
	struct KolXXSocket_TReceive *KolXXSocket_PReceive;

typedef
	struct KolXXSocket_TServer *KolXXSocket_PServer;

typedef
	struct KolXXSocket_TServerClient *KolXXSocket_PServerClient;

typedef
	struct KolXXSocket_TAccept { /* KolObj_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
	} KolXXSocket_TAccept;

typedef
	struct KolXXSocket_TBaseSocket { /* KolObj_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
		SYSTEM_PTR sock;
		BOOLEAN online;
		KolXXSocket_PReceive receive;
	} KolXXSocket_TBaseSocket;

export void KolXXSocket_TBaseSocket_Destroy (KolXXSocket_TBaseSocket *self, LONGINT *self__typ);
export void KolXXSocket_TBaseSocket_Disconnect (KolXXSocket_TBaseSocket *self, LONGINT *self__typ);
#define __KolXXSocket_TBaseSocket_Disconnect(self, self__typ) __SEND(self__typ, KolXXSocket_TBaseSocket_Disconnect, 5, void(*)(KolXXSocket_TBaseSocket*, LONGINT *), (self, self__typ))

typedef
	struct KolXXSocket_TClient {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
		SYSTEM_PTR sock;
		BOOLEAN online;
		KolXXSocket_PReceive receive;
	} KolXXSocket_TClient;

typedef
	struct KolXXSocket_TReceive { /* KolObj_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
		BOOLEAN terminate;
	} KolXXSocket_TReceive;

typedef
	struct KolXXSocket_TServer { /* KolObj_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
	} KolXXSocket_TServer;

typedef
	struct KolXXSocket_TServerClient {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		char _prvt0[4];
		SYSTEM_PTR sock;
		BOOLEAN online;
		KolXXSocket_PReceive receive;
	} KolXXSocket_TServerClient;



export LONGINT *KolXXSocket_TBaseSocket__typ;
export LONGINT *KolXXSocket_TReceive__typ;
export LONGINT *KolXXSocket_TClient__typ;
export LONGINT *KolXXSocket_TServer__typ;
export LONGINT *KolXXSocket_TAccept__typ;
export LONGINT *KolXXSocket_TServerClient__typ;



/*============================================================================*/

void KolXXSocket_TBaseSocket_Disconnect (KolXXSocket_TBaseSocket *self, LONGINT *self__typ)
{
	INTEGER i;
	if ((*self).receive != NIL) {
		Ignore_Int(WinNet_closesocket((*self).sock));
		(*self).receive->terminate = 1;
		i = 10;
		for (;;) {
			if (!(*self).receive->terminate) {
				break;
			} else {
				WinApi_Sleep(1);
			}
			(*self).receive = NIL;
			i -= 1;
			if (i == 0) {
				break;
			}
		}
	}
	(*self).online = 0;
}

/*----------------------------------------------------------------------------*/
void KolXXSocket_TBaseSocket_Destroy (KolXXSocket_TBaseSocket *self, LONGINT *self__typ)
{
	__KolXXSocket_TBaseSocket_Disconnect(&*self, self__typ);
	KolObj_TObj_Destroy((void*)&*self, self__typ);
}

/*----------------------------------------------------------------------------*/
__TDESC(KolXXSocket_TBaseSocket__desc, 7, 4) = {__TDFLDS("TBaseSocket", 28), {8, 12, 16, 24, -40}};
__TDESC(KolXXSocket_TReceive__desc, 6, 2) = {__TDFLDS("TReceive", 20), {8, 12, -24}};
__TDESC(KolXXSocket_TClient__desc, 7, 4) = {__TDFLDS("TClient", 28), {8, 12, 16, 24, -40}};
__TDESC(KolXXSocket_TServer__desc, 6, 2) = {__TDFLDS("TServer", 16), {8, 12, -24}};
__TDESC(KolXXSocket_TAccept__desc, 6, 2) = {__TDFLDS("TAccept", 16), {8, 12, -24}};
__TDESC(KolXXSocket_TServerClient__desc, 7, 4) = {__TDFLDS("TServerClient", 28), {8, 12, 16, 24, -40}};

export void *KolXXSocket__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(WinNet__init);
	__IMPORT(KolObj__init);
	__IMPORT(WinApi__init);
	__REGMOD("KolXXSocket", 0);
	__INITYP(KolXXSocket_TBaseSocket, KolObj_TObj, 1);
	__INITBP(KolXXSocket_TBaseSocket, KolXXSocket_TBaseSocket_Destroy, 1);
	__INITBP(KolXXSocket_TBaseSocket, KolXXSocket_TBaseSocket_Disconnect, 5);
	__INITYP(KolXXSocket_TReceive, KolObj_TObj, 1);
	__INITYP(KolXXSocket_TClient, KolXXSocket_TBaseSocket, 2);
	__INITYP(KolXXSocket_TServer, KolObj_TObj, 1);
	__INITYP(KolXXSocket_TAccept, KolObj_TObj, 1);
	__INITYP(KolXXSocket_TServerClient, KolXXSocket_TBaseSocket, 2);
/* BEGIN */
	__ENDMOD;
}
