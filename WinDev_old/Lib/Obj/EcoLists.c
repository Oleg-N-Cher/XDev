/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	struct EcoLists_Node *EcoLists_NodePtr;

typedef
	void (*EcoLists_DoProc)(EcoLists_NodePtr);

typedef
	struct EcoLists_List {
		EcoLists_NodePtr head, tail;
		SHORTINT remallowed;
	} EcoLists_List;

typedef
	struct EcoLists_Node {
		EcoLists_NodePtr next, prev;
	} EcoLists_Node;



export LONGINT *EcoLists_Node__typ;
export LONGINT *EcoLists_List__typ;

export void EcoLists_AddBefore (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n, EcoLists_NodePtr x);
export void EcoLists_AddBehind (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n, EcoLists_NodePtr x);
export void EcoLists_AddHead (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n);
export void EcoLists_AddMarkBefore (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark, EcoLists_NodePtr x);
export void EcoLists_AddMarkBehind (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark, EcoLists_NodePtr x);
export void EcoLists_AddMarkHead (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark);
export void EcoLists_AddMarkTail (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark);
export void EcoLists_AddTail (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n);
export INTEGER EcoLists_CountElements (EcoLists_List *list, LONGINT *list__typ);
export void EcoLists_DoBackward (EcoLists_List *list, LONGINT *list__typ, EcoLists_DoProc proc);
export void EcoLists_DoForward (EcoLists_List *list, LONGINT *list__typ, EcoLists_DoProc proc);
export BOOLEAN EcoLists_Empty (EcoLists_List *list, LONGINT *list__typ);
export EcoLists_NodePtr EcoLists_GetPred (EcoLists_NodePtr n);
export EcoLists_NodePtr EcoLists_GetSucc (EcoLists_NodePtr n);
export void EcoLists_GoBackward (EcoLists_List list, EcoLists_NodePtr *n, INTEGER num);
export void EcoLists_GoForward (EcoLists_List list, EcoLists_NodePtr *n, INTEGER num);
export EcoLists_NodePtr EcoLists_Head (EcoLists_List *list, LONGINT *list__typ);
export void EcoLists_Init (EcoLists_List *list, LONGINT *list__typ);
export BOOLEAN EcoLists_IsElement (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr e);
export BOOLEAN EcoLists_Next (EcoLists_NodePtr *n);
export void EcoLists_Pred (EcoLists_NodePtr *n);
export BOOLEAN EcoLists_Previous (EcoLists_NodePtr *n);
export EcoLists_NodePtr EcoLists_RemHead (EcoLists_List *list, LONGINT *list__typ);
export EcoLists_NodePtr EcoLists_RemTail (EcoLists_List *list, LONGINT *list__typ);
export void EcoLists_Remove (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n);
export void EcoLists_RemoveMark (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark);
export void EcoLists_SetMark (EcoLists_List *mark, LONGINT *mark__typ, EcoLists_NodePtr h, EcoLists_NodePtr t);
export void EcoLists_Succ (EcoLists_NodePtr *n);
export void EcoLists_Swap (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr a, EcoLists_NodePtr b);
export EcoLists_NodePtr EcoLists_Tail (EcoLists_List *list, LONGINT *list__typ);


/*============================================================================*/

void EcoLists_Init (EcoLists_List *list, LONGINT *list__typ)
{
	(*list).head = NIL;
	(*list).tail = NIL;
	(*list).remallowed = 0;
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddHead (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n)
{
	n->next = (*list).head;
	n->prev = NIL;
	if (n->next == NIL) {
		(*list).tail = n;
	} else {
		n->next->prev = n;
	}
	(*list).head = n;
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddTail (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n)
{
	n->prev = (*list).tail;
	n->next = NIL;
	if (n->prev == NIL) {
		(*list).head = n;
	} else {
		n->prev->next = n;
	}
	(*list).tail = n;
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddBefore (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n, EcoLists_NodePtr x)
{
	n->prev = x->prev;
	n->next = x;
	x->prev = n;
	if (n->prev == NIL) {
		(*list).head = n;
	} else {
		n->prev->next = n;
	}
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddBehind (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n, EcoLists_NodePtr x)
{
	n->next = x->next;
	n->prev = x;
	x->next = n;
	if (n->next == NIL) {
		(*list).tail = n;
	} else {
		n->next->prev = n;
	}
}

/*----------------------------------------------------------------------------*/
void EcoLists_Remove (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n)
{
	if (n != NIL) {
		if ((*list).remallowed != 0) {
			__HALT(20);
		}
		if (n->next != NIL) {
			n->next->prev = n->prev;
		} else {
			(*list).tail = n->prev;
		}
		if (n->prev != NIL) {
			n->prev->next = n->next;
		} else {
			(*list).head = n->next;
		}
	}
}

/*----------------------------------------------------------------------------*/
EcoLists_NodePtr EcoLists_RemHead (EcoLists_List *list, LONGINT *list__typ)
{
	EcoLists_NodePtr n = NIL;
	n = (*list).head;
	EcoLists_Remove(&*list, list__typ, n);
	return n;
}

/*----------------------------------------------------------------------------*/
EcoLists_NodePtr EcoLists_RemTail (EcoLists_List *list, LONGINT *list__typ)
{
	EcoLists_NodePtr n = NIL;
	n = (*list).tail;
	EcoLists_Remove(&*list, list__typ, n);
	return n;
}

/*----------------------------------------------------------------------------*/
void EcoLists_DoForward (EcoLists_List *list, LONGINT *list__typ, EcoLists_DoProc proc)
{
	EcoLists_NodePtr n = NIL;
	(*list).remallowed += 1;
	n = (*list).head;
	while (n != NIL) {
		(*proc)(n);
		n = n->next;
	}
	(*list).remallowed -= 1;
}

/*----------------------------------------------------------------------------*/
void EcoLists_DoBackward (EcoLists_List *list, LONGINT *list__typ, EcoLists_DoProc proc)
{
	EcoLists_NodePtr n = NIL;
	(*list).remallowed += 1;
	n = (*list).tail;
	while (n != NIL) {
		(*proc)(n);
		n = n->prev;
	}
	(*list).remallowed -= 1;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoLists_Next (EcoLists_NodePtr *n)
{
	*n = (*n)->next;
	return *n != NIL;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoLists_Previous (EcoLists_NodePtr *n)
{
	*n = (*n)->prev;
	return *n != NIL;
}

/*----------------------------------------------------------------------------*/
void EcoLists_Succ (EcoLists_NodePtr *n)
{
	*n = (*n)->next;
}

/*----------------------------------------------------------------------------*/
void EcoLists_Pred (EcoLists_NodePtr *n)
{
	*n = (*n)->prev;
}

/*----------------------------------------------------------------------------*/
EcoLists_NodePtr EcoLists_GetSucc (EcoLists_NodePtr n)
{
	return n->next;
}

/*----------------------------------------------------------------------------*/
EcoLists_NodePtr EcoLists_GetPred (EcoLists_NodePtr n)
{
	return n->prev;
}

/*----------------------------------------------------------------------------*/
EcoLists_NodePtr EcoLists_Head (EcoLists_List *list, LONGINT *list__typ)
{
	return (*list).head;
}

/*----------------------------------------------------------------------------*/
EcoLists_NodePtr EcoLists_Tail (EcoLists_List *list, LONGINT *list__typ)
{
	return (*list).tail;
}

/*----------------------------------------------------------------------------*/
void EcoLists_GoForward (EcoLists_List list, EcoLists_NodePtr *n, INTEGER num)
{
	while (num > 0 && *n != NIL) {
		*n = (*n)->next;
		num -= 1;
	}
	if (*n == NIL) {
		*n = list.tail;
	}
}

/*----------------------------------------------------------------------------*/
void EcoLists_GoBackward (EcoLists_List list, EcoLists_NodePtr *n, INTEGER num)
{
	while (num > 0 && *n != NIL) {
		*n = (*n)->prev;
		num -= 1;
	}
	if (*n == NIL) {
		*n = list.head;
	}
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoLists_Empty (EcoLists_List *list, LONGINT *list__typ)
{
	return (*list).head == NIL;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoLists_IsElement (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr e)
{
	EcoLists_NodePtr n = NIL;
	n = (*list).head;
	while (n != NIL) {
		if (n == e) {
			return 1;
		}
		n = n->next;
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
INTEGER EcoLists_CountElements (EcoLists_List *list, LONGINT *list__typ)
{
	INTEGER i;
	EcoLists_NodePtr n = NIL;
	i = 0;
	n = (*list).head;
	while (n != NIL) {
		n = n->next;
		i += 1;
	}
	return i;
}

/*----------------------------------------------------------------------------*/
void EcoLists_Swap (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr a, EcoLists_NodePtr b)
{
	EcoLists_NodePtr c = NIL;
	c = a->next;
	if (b->next != a) {
		EcoLists_Remove(&*list, list__typ, a);
		EcoLists_AddBehind(&*list, list__typ, a, b);
	}
	if (c != b) {
		EcoLists_Remove(&*list, list__typ, b);
		if (c == NIL) {
			EcoLists_AddTail(&*list, list__typ, b);
		} else {
			EcoLists_AddBefore(&*list, list__typ, b, c);
		}
	}
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddMarkBefore (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark, EcoLists_NodePtr x)
{
	mark.head->prev = x->prev;
	mark.tail->next = x;
	x->prev = mark.tail;
	if (mark.head->prev == NIL) {
		(*list).head = mark.head;
	} else {
		mark.head->prev->next = mark.head;
	}
	mark.remallowed += 1;
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddMarkBehind (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark, EcoLists_NodePtr x)
{
	mark.tail->next = x->next;
	mark.head->prev = x;
	x->next = mark.head;
	if (mark.tail->next == NIL) {
		(*list).tail = mark.tail;
	} else {
		mark.tail->next->prev = mark.tail;
	}
	mark.remallowed += 1;
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddMarkHead (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark)
{
	mark.tail->next = (*list).head;
	mark.head->prev = NIL;
	if (mark.tail->next == NIL) {
		(*list).tail = mark.tail;
	} else {
		mark.tail->next->prev = mark.tail;
	}
	(*list).head = mark.head;
	mark.remallowed += 1;
}

/*----------------------------------------------------------------------------*/
void EcoLists_AddMarkTail (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark)
{
	mark.head->prev = (*list).tail;
	mark.tail->next = NIL;
	if (mark.head->prev == NIL) {
		(*list).head = mark.head;
	} else {
		mark.head->prev->next = mark.head;
	}
	(*list).tail = mark.tail;
	mark.remallowed += 1;
}

/*----------------------------------------------------------------------------*/
void EcoLists_RemoveMark (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark)
{
	if (mark.head != NIL && mark.tail != NIL) {
		if ((*list).remallowed != 0) {
			__HALT(20);
		}
		if (mark.tail->next != NIL) {
			mark.tail->next->prev = mark.head->prev;
		} else {
			(*list).tail = mark.head->prev;
		}
		if (mark.head->prev != NIL) {
			mark.head->prev->next = mark.tail->next;
		} else {
			(*list).head = mark.tail->next;
		}
	}
	mark.remallowed -= 1;
}

/*----------------------------------------------------------------------------*/
void EcoLists_SetMark (EcoLists_List *mark, LONGINT *mark__typ, EcoLists_NodePtr h, EcoLists_NodePtr t)
{
	if (h == NIL && t == NIL) {
		(*mark).head = NIL;
		(*mark).tail = NIL;
	} else {
		if (h != NIL) {
			(*mark).head = h;
		}
		if (t != NIL) {
			(*mark).tail = t;
		}
	}
	if ((*mark).remallowed == 0) {
		(*mark).remallowed = 1;
	}
}

/*----------------------------------------------------------------------------*/
__TDESC(EcoLists_Node__desc, 1, 2) = {__TDFLDS("Node", 8), {0, 4, -24}};
__TDESC(EcoLists_List__desc, 1, 2) = {__TDFLDS("List", 12), {0, 4, -24}};

export void *EcoLists__init(void)
{
	__DEFMOD;
	__REGMOD("EcoLists", 0);
	__INITYP(EcoLists_Node, EcoLists_Node, 0);
	__INITYP(EcoLists_List, EcoLists_List, 0);
/* BEGIN */
	__ENDMOD;
}
