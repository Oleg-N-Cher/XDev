/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	struct EcoListen_ElementDesc *EcoListen_Element;

typedef
	BOOLEAN (*EcoListen_CompareProc)(EcoListen_Element, EcoListen_Element);

typedef
	struct EcoListen_ElementDesc {
		char _prvt0[1];
	} EcoListen_ElementDesc;

typedef
	struct EcoListen_ListDesc *EcoListen_Liste;

typedef
	struct EcoListen_ListDesc {
		EcoListen_Element e;
		EcoListen_Liste rest;
	} EcoListen_ListDesc;



export LONGINT *EcoListen_ElementDesc__typ;
export LONGINT *EcoListen_ListDesc__typ;

export EcoListen_Liste EcoListen_Append (EcoListen_Liste list, EcoListen_Element e);
export EcoListen_Liste EcoListen_Concat (EcoListen_Element head, EcoListen_Liste tail);
export EcoListen_Element EcoListen_Find (EcoListen_Element e, EcoListen_Liste l, EcoListen_CompareProc equal);
export EcoListen_Element EcoListen_Head (EcoListen_Liste l);
export BOOLEAN EcoListen_IsElement (EcoListen_Element e, EcoListen_Liste l, EcoListen_CompareProc equal);
export EcoListen_Liste EcoListen_Tail (EcoListen_Liste l);


/*============================================================================*/

EcoListen_Liste EcoListen_Concat (EcoListen_Element head, EcoListen_Liste tail)
{
	EcoListen_Liste temp = NIL;
	__NEW(temp, EcoListen_ListDesc);
	temp->e = head;
	temp->rest = tail;
	return temp;
}

/*----------------------------------------------------------------------------*/
EcoListen_Element EcoListen_Head (EcoListen_Liste l)
{
	return l->e;
}

/*----------------------------------------------------------------------------*/
EcoListen_Liste EcoListen_Tail (EcoListen_Liste l)
{
	return l->rest;
}

/*----------------------------------------------------------------------------*/
EcoListen_Liste EcoListen_Append (EcoListen_Liste list, EcoListen_Element e)
{
	if (list == NIL) {
		return EcoListen_Concat(e, NIL);
	} else {
		return EcoListen_Concat(EcoListen_Head(list), EcoListen_Append(EcoListen_Tail(list), e));
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoListen_IsElement (EcoListen_Element e, EcoListen_Liste l, EcoListen_CompareProc equal)
{
	if (l == NIL) {
		return 0;
	} else if ((*equal)(e, EcoListen_Head(l))) {
		return 1;
	} else {
		return EcoListen_IsElement(e, EcoListen_Tail(l), equal);
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
EcoListen_Element EcoListen_Find (EcoListen_Element e, EcoListen_Liste l, EcoListen_CompareProc equal)
{
	if (l == NIL) {
		return NIL;
	} else if ((*equal)(e, EcoListen_Head(l))) {
		return EcoListen_Head(l);
	} else {
		return EcoListen_Find(e, EcoListen_Tail(l), equal);
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
__TDESC(EcoListen_ElementDesc__desc, 1, 0) = {__TDFLDS("ElementDesc", 1), {-8}};
__TDESC(EcoListen_ListDesc__desc, 1, 2) = {__TDFLDS("ListDesc", 8), {0, 4, -24}};

export void *EcoListen__init(void)
{
	__DEFMOD;
	__REGMOD("EcoListen", 0);
	__INITYP(EcoListen_ElementDesc, EcoListen_ElementDesc, 0);
	__INITYP(EcoListen_ListDesc, EcoListen_ListDesc, 0);
/* BEGIN */
	__ENDMOD;
}
