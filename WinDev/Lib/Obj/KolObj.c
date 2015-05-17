/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolTypes.h"

typedef
	struct KolObj_TObj *KolObj_PObj;

typedef
	struct KolObj_TObj {
		INTEGER refCount, tag;
		struct {
			LONGINT len[1];
			CHAR data[1];
		} *name;
		KolObj_PObj ownerObj;
	} KolObj_TObj;

export void KolObj_TObj_Create (KolObj_TObj *obj, LONGINT *obj__typ);
export void KolObj_TObj_Destroy (KolObj_TObj *obj, LONGINT *obj__typ);
export void KolObj_TObj_Free (KolObj_TObj *obj, LONGINT *obj__typ);
static void KolObj_TObj_RefDec (KolObj_TObj *obj, LONGINT *obj__typ);
static void KolObj_TObj_RefInc (KolObj_TObj *obj, LONGINT *obj__typ);
#define __KolObj_TObj_Create(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_Create, 0, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))
#define __KolObj_TObj_Destroy(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_Destroy, 1, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))
#define __KolObj_TObj_Free(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_Free, 2, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))
#define __KolObj_TObj_RefDec(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_RefDec, 3, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))
#define __KolObj_TObj_RefInc(obj, obj__typ) __SEND(obj__typ, KolObj_TObj_RefInc, 4, void(*)(KolObj_TObj*, LONGINT *), (obj, obj__typ))



export LONGINT *KolObj_TObj__typ;



/*============================================================================*/

void KolObj_TObj_Create (KolObj_TObj *obj, LONGINT *obj__typ)
{
	(*obj).refCount = 0;
}

/*----------------------------------------------------------------------------*/
void KolObj_TObj_Destroy (KolObj_TObj *obj, LONGINT *obj__typ)
{
	(*obj).name = NIL;
	(*obj).ownerObj = NIL;
}

/*----------------------------------------------------------------------------*/
static void KolObj_TObj_RefDec (KolObj_TObj *obj, LONGINT *obj__typ)
{
	(*obj).refCount -= 2;
	if ((*obj).refCount < 0) {
		__KolObj_TObj_Destroy(&*obj, obj__typ);
	}
}

static void KolObj_TObj_RefInc (KolObj_TObj *obj, LONGINT *obj__typ)
{
	(*obj).refCount += 2;
}

void KolObj_TObj_Free (KolObj_TObj *obj, LONGINT *obj__typ)
{
	__KolObj_TObj_RefDec(&*obj, obj__typ);
}

/*----------------------------------------------------------------------------*/
__TDESC(KolObj_TObj__desc, 6, 2) = {__TDFLDS("TObj", 16), {8, 12, -24}};

export void *KolObj__init(void)
{
	__DEFMOD;
	__IMPORT(KolTypes__init);
	__REGMOD("KolObj", 0);
	__INITYP(KolObj_TObj, KolObj_TObj, 0);
	__INITBP(KolObj_TObj, KolObj_TObj_Create, 0);
	__INITBP(KolObj_TObj, KolObj_TObj_Destroy, 1);
	__INITBP(KolObj_TObj, KolObj_TObj_Free, 2);
	__INITBP(KolObj_TObj, KolObj_TObj_RefDec, 3);
	__INITBP(KolObj_TObj, KolObj_TObj_RefInc, 4);
/* BEGIN */
	__ENDMOD;
}
