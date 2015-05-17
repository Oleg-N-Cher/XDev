/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolObj.h"

typedef
	CHAR *KolXXSocket_AnsiString;

typedef
	struct KolXXSocket_TAccept *KolXXSocket_PAccept;

typedef
	struct KolXXSocket_TBaseSocket *KolXXSocket_PBaseSocket;

typedef
	struct KolXXSocket_TClient *KolXXSocket_PClient;

typedef
	struct KolXXSocket_TObj *KolXXSocket_PObj;

typedef
	struct KolXXSocket_TReceive *KolXXSocket_PReceive;

typedef
	struct KolXXSocket_TServer *KolXXSocket_PServer;

typedef
	struct KolXXSocket_TServerClient *KolXXSocket_PServerClient;

typedef
	struct KolXXSocket_TObj {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
	} KolXXSocket_TObj;

export void KolXXSocket_TObj_Create (KolXXSocket_TObj *obj, LONGINT *obj__typ);
export void KolXXSocket_TObj_Destroy (KolXXSocket_TObj *obj, LONGINT *obj__typ);
export void KolXXSocket_TObj_Free (KolXXSocket_TObj *obj, LONGINT *obj__typ);
static void KolXXSocket_TObj_RefDec (KolXXSocket_TObj *obj, LONGINT *obj__typ);
static void KolXXSocket_TObj_RefInc (KolXXSocket_TObj *obj, LONGINT *obj__typ);
#define __KolXXSocket_TObj_Create(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_Create, 0, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))
#define __KolXXSocket_TObj_Destroy(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_Destroy, 1, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))
#define __KolXXSocket_TObj_Free(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_Free, 2, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))
#define __KolXXSocket_TObj_RefDec(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_RefDec, 3, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))
#define __KolXXSocket_TObj_RefInc(obj, obj__typ) __SEND(obj__typ, KolXXSocket_TObj_RefInc, 4, void(*)(KolXXSocket_TObj*, LONGINT *), (obj, obj__typ))

typedef
	struct KolXXSocket_TAccept { /* KolXXSocket_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
	} KolXXSocket_TAccept;

typedef
	struct KolXXSocket_TBaseSocket { /* KolXXSocket_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
		BOOLEAN online;
		KolXXSocket_PReceive receive;
	} KolXXSocket_TBaseSocket;

export void KolXXSocket_TBaseSocket_Disconnect (KolXXSocket_TBaseSocket *self, LONGINT *self__typ);
#define __KolXXSocket_TBaseSocket_Disconnect(self, self__typ) __SEND(self__typ, KolXXSocket_TBaseSocket_Disconnect, 5, void(*)(KolXXSocket_TBaseSocket*, LONGINT *), (self, self__typ))

typedef
	struct KolXXSocket_TClient {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
		BOOLEAN online;
		KolXXSocket_PReceive receive;
	} KolXXSocket_TClient;

typedef
	struct KolXXSocket_TReceive { /* KolXXSocket_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
		BOOLEAN terminate;
	} KolXXSocket_TReceive;

typedef
	struct KolXXSocket_TServer { /* KolXXSocket_TObj */
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
	} KolXXSocket_TServer;

typedef
	struct KolXXSocket_TServerClient {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolXXSocket_PObj ownerObj;
		BOOLEAN online;
		KolXXSocket_PReceive receive;
	} KolXXSocket_TServerClient;



export LONGINT *KolXXSocket_TObj__typ;
export LONGINT *KolXXSocket_TBaseSocket__typ;
export LONGINT *KolXXSocket_TReceive__typ;
export LONGINT *KolXXSocket_TClient__typ;
export LONGINT *KolXXSocket_TServer__typ;
export LONGINT *KolXXSocket_TAccept__typ;
export LONGINT *KolXXSocket_TServerClient__typ;

export void KolXXSocket_Free_And_Nil (KolXXSocket_PObj *obj);


/*============================================================================*/

void KolXXSocket_TObj_Destroy (KolXXSocket_TObj *obj, LONGINT *obj__typ)
{
	(*obj).name = NIL;
	(*obj).ownerObj = NIL;
}

/*----------------------------------------------------------------------------*/
static void KolXXSocket_TObj_RefDec (KolXXSocket_TObj *obj, LONGINT *obj__typ)
{
	(*obj).refCount -= 2;
	if ((*obj).refCount < 0) {
		__KolXXSocket_TObj_Destroy(&*obj, obj__typ);
	}
}

static void KolXXSocket_TObj_RefInc (KolXXSocket_TObj *obj, LONGINT *obj__typ)
{
	(*obj).refCount += 2;
}

void KolXXSocket_TObj_Free (KolXXSocket_TObj *obj, LONGINT *obj__typ)
{
	__KolXXSocket_TObj_RefDec(&*obj, obj__typ);
}

/*----------------------------------------------------------------------------*/
void KolXXSocket_Free_And_Nil (KolXXSocket_PObj *obj)
{
	KolXXSocket_PObj obj1 = NIL;
	*obj = NIL;
}

/*----------------------------------------------------------------------------*/
void KolXXSocket_TObj_Create (KolXXSocket_TObj *obj, LONGINT *obj__typ)
{
	(*obj).refCount = 0;
}

/*----------------------------------------------------------------------------*/
void KolXXSocket_TBaseSocket_Disconnect (KolXXSocket_TBaseSocket *self, LONGINT *self__typ)
{
	INTEGER i;
	if ((*self).receive != NIL) {
		(*self).receive->terminate = 1;
		i = 10;
		for (;;) {
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
__TDESC(KolXXSocket_TObj__desc, 6, 2) = {__TDFLDS("TObj", 16), {8, 12, -24}};
__TDESC(KolXXSocket_TBaseSocket__desc, 7, 3) = {__TDFLDS("TBaseSocket", 24), {8, 12, 20, -32}};
__TDESC(KolXXSocket_TReceive__desc, 6, 2) = {__TDFLDS("TReceive", 20), {8, 12, -24}};
__TDESC(KolXXSocket_TClient__desc, 7, 3) = {__TDFLDS("TClient", 24), {8, 12, 20, -32}};
__TDESC(KolXXSocket_TServer__desc, 6, 2) = {__TDFLDS("TServer", 16), {8, 12, -24}};
__TDESC(KolXXSocket_TAccept__desc, 6, 2) = {__TDFLDS("TAccept", 16), {8, 12, -24}};
__TDESC(KolXXSocket_TServerClient__desc, 7, 3) = {__TDFLDS("TServerClient", 24), {8, 12, 20, -32}};

export void *KolXXSocket__init(void)
{
	__DEFMOD;
	__IMPORT(KolObj__init);
	__REGMOD("KolXXSocket", 0);
	__INITYP(KolXXSocket_TObj, KolXXSocket_TObj, 0);
	__INITBP(KolXXSocket_TObj, KolXXSocket_TObj_Create, 0);
	__INITBP(KolXXSocket_TObj, KolXXSocket_TObj_Destroy, 1);
	__INITBP(KolXXSocket_TObj, KolXXSocket_TObj_Free, 2);
	__INITBP(KolXXSocket_TObj, KolXXSocket_TObj_RefDec, 3);
	__INITBP(KolXXSocket_TObj, KolXXSocket_TObj_RefInc, 4);
	__INITYP(KolXXSocket_TBaseSocket, KolXXSocket_TObj, 1);
	__INITBP(KolXXSocket_TBaseSocket, KolXXSocket_TBaseSocket_Disconnect, 5);
	__INITYP(KolXXSocket_TReceive, KolXXSocket_TObj, 1);
	__INITYP(KolXXSocket_TClient, KolXXSocket_TBaseSocket, 2);
	__INITYP(KolXXSocket_TServer, KolXXSocket_TObj, 1);
	__INITYP(KolXXSocket_TAccept, KolXXSocket_TObj, 1);
	__INITYP(KolXXSocket_TServerClient, KolXXSocket_TBaseSocket, 2);
/* BEGIN */
	__ENDMOD;
}
