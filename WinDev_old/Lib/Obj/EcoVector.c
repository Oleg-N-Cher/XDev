/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	struct EcoVector_NodeRec *EcoVector_Node;

typedef
	struct EcoVector_ObjectRec *EcoVector_OBJECT;

typedef
	struct EcoVector_NodeRec {
		EcoVector_OBJECT data;
		EcoVector_Node next;
	} EcoVector_NodeRec;

typedef
	struct EcoVector_ObjectRec {
		char _prvt0[1];
	} EcoVector_ObjectRec;

typedef
	struct EcoVector_VectorRec *EcoVector_VECTOR;

typedef
	struct EcoVector_VectorRec {
		INTEGER len;
		EcoVector_Node head, tail;
	} EcoVector_VectorRec;

export EcoVector_OBJECT EcoVector_VECTOR_At (EcoVector_VECTOR vec, INTEGER pos);
export void EcoVector_VECTOR_Clear (EcoVector_VECTOR vec);
export void EcoVector_VECTOR_Delete (EcoVector_VECTOR vec, INTEGER pos);
export EcoVector_OBJECT EcoVector_VECTOR_Head (EcoVector_VECTOR vec);
export void EcoVector_VECTOR_Insert (EcoVector_VECTOR vec, INTEGER pos, EcoVector_OBJECT e);
export INTEGER EcoVector_VECTOR_Length (EcoVector_VECTOR vec);
export EcoVector_OBJECT EcoVector_VECTOR_PopBack (EcoVector_VECTOR vec);
export void EcoVector_VECTOR_PushBack (EcoVector_VECTOR vec, EcoVector_OBJECT e);
export void EcoVector_VECTOR_Swap (EcoVector_VECTOR vec, INTEGER p1, INTEGER p2);
export EcoVector_OBJECT EcoVector_VECTOR_Tail (EcoVector_VECTOR vec);
#define __EcoVector_VECTOR_At(vec, pos) __SEND(__TYPEOF(vec), EcoVector_VECTOR_At, 0, EcoVector_OBJECT(*)(EcoVector_VECTOR, INTEGER), (vec, pos))
#define __EcoVector_VECTOR_Clear(vec) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Clear, 1, void(*)(EcoVector_VECTOR), (vec))
#define __EcoVector_VECTOR_Delete(vec, pos) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Delete, 2, void(*)(EcoVector_VECTOR, INTEGER), (vec, pos))
#define __EcoVector_VECTOR_Head(vec) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Head, 3, EcoVector_OBJECT(*)(EcoVector_VECTOR), (vec))
#define __EcoVector_VECTOR_Insert(vec, pos, e) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Insert, 4, void(*)(EcoVector_VECTOR, INTEGER, EcoVector_OBJECT), (vec, pos, e))
#define __EcoVector_VECTOR_Length(vec) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Length, 5, INTEGER(*)(EcoVector_VECTOR), (vec))
#define __EcoVector_VECTOR_PopBack(vec) __SEND(__TYPEOF(vec), EcoVector_VECTOR_PopBack, 6, EcoVector_OBJECT(*)(EcoVector_VECTOR), (vec))
#define __EcoVector_VECTOR_PushBack(vec, e) __SEND(__TYPEOF(vec), EcoVector_VECTOR_PushBack, 7, void(*)(EcoVector_VECTOR, EcoVector_OBJECT), (vec, e))
#define __EcoVector_VECTOR_Swap(vec, p1, p2) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Swap, 8, void(*)(EcoVector_VECTOR, INTEGER, INTEGER), (vec, p1, p2))
#define __EcoVector_VECTOR_Tail(vec) __SEND(__TYPEOF(vec), EcoVector_VECTOR_Tail, 9, EcoVector_OBJECT(*)(EcoVector_VECTOR), (vec))



export LONGINT *EcoVector_ObjectRec__typ;
export LONGINT *EcoVector_NodeRec__typ;
export LONGINT *EcoVector_VectorRec__typ;

export EcoVector_VECTOR EcoVector_Vector (void);


/*============================================================================*/

EcoVector_VECTOR EcoVector_Vector (void)
{
	EcoVector_VECTOR vec = NIL;
	__NEW(vec, EcoVector_VectorRec);
	vec->len = 0;
	vec->head = NIL;
	vec->tail = NIL;
	return vec;
}

/*----------------------------------------------------------------------------*/
INTEGER EcoVector_VECTOR_Length (EcoVector_VECTOR vec)
{
	return vec->len;
}

/*----------------------------------------------------------------------------*/
void EcoVector_VECTOR_PushBack (EcoVector_VECTOR vec, EcoVector_OBJECT e)
{
	EcoVector_Node node = NIL;
	__NEW(node, EcoVector_NodeRec);
	node->next = NIL;
	node->data = e;
	if (vec->head == NIL) {
		vec->head = node;
	} else {
		vec->tail->next = node;
	}
	vec->tail = node;
	vec->len += 1;
}

/*----------------------------------------------------------------------------*/
EcoVector_OBJECT EcoVector_VECTOR_PopBack (EcoVector_VECTOR vec)
{
	EcoVector_Node prev = NIL, node = NIL;
	if (vec->tail == NIL) {
		return NIL;
	} else if (vec->head == vec->tail) {
		node = vec->head;
		vec->head = NIL;
		vec->tail = NIL;
		vec->len = 0;
		return node->data;
	} else {
		prev = vec->head;
		while (prev->next != vec->tail) {
			prev = prev->next;
		}
		node = prev->next;
		prev->next = NIL;
		vec->tail = prev;
		vec->len -= 1;
		return node->data;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
EcoVector_OBJECT EcoVector_VECTOR_Head (EcoVector_VECTOR vec)
{
	if (vec->head == NIL) {
		return NIL;
	} else {
		return vec->head->data;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
EcoVector_OBJECT EcoVector_VECTOR_Tail (EcoVector_VECTOR vec)
{
	if (vec->tail == NIL) {
		return NIL;
	} else {
		return vec->tail->data;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
EcoVector_OBJECT EcoVector_VECTOR_At (EcoVector_VECTOR vec, INTEGER pos)
{
	INTEGER i;
	EcoVector_Node node = NIL;
	INTEGER _for__2;
	if (pos < 0 || pos > vec->len - 1) {
		return NIL;
	} else {
		node = vec->head;
		_for__2 = pos - 1;
		i = 0;
		while (i <= _for__2) {
			node = node->next;
			i += 1;
		}
		return node->data;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
void EcoVector_VECTOR_Delete (EcoVector_VECTOR vec, INTEGER pos)
{
	INTEGER i;
	EcoVector_Node node = NIL;
	INTEGER _for__5;
	if (pos < 0 || pos > vec->len - 1) {
	} else if (pos == 0) {
		vec->head = vec->head->next;
		vec->len -= 1;
	} else {
		node = vec->head;
		_for__5 = pos - 1;
		i = 0;
		while (i <= _for__5) {
			node = node->next;
			i += 1;
		}
		node->next = NIL;
		vec->len -= 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoVector_VECTOR_Insert (EcoVector_VECTOR vec, INTEGER pos, EcoVector_OBJECT e)
{
	INTEGER i;
	EcoVector_Node node = NIL, prev = NIL;
	INTEGER _for__8;
	if (pos < 0) {
		pos = 0;
	}
	if (pos > vec->len) {
		pos = vec->len;
	}
	__NEW(node, EcoVector_NodeRec);
	node->data = e;
	if (pos == 0) {
		node->next = vec->head;
		vec->head = node;
	} else if (pos == vec->len - 1) {
		node->next = NIL;
		vec->tail->next = node;
		vec->tail = node;
	} else {
		prev = vec->head;
		_for__8 = pos - 2;
		i = 0;
		while (i <= _for__8) {
			prev = prev->next;
			i += 1;
		}
		node->next = prev->next;
		prev->next = node;
	}
	vec->len += 1;
}

/*----------------------------------------------------------------------------*/
void EcoVector_VECTOR_Clear (EcoVector_VECTOR vec)
{
	vec->head = NIL;
	vec->tail = NIL;
	vec->len = 0;
}

/*----------------------------------------------------------------------------*/
void EcoVector_VECTOR_Swap (EcoVector_VECTOR vec, INTEGER p1, INTEGER p2)
{
	INTEGER i;
	EcoVector_OBJECT o1 = NIL, o2 = NIL;
	if (((p1 < 0 || p1 > vec->len - 1) || p2 < 0) || p2 > vec->len - 1) {
	} else if (p1 == p2) {
	} else {
		if (p1 > p2) {
			i = p1;
			p1 = p2;
			p2 = i;
		}
		o1 = __EcoVector_VECTOR_At(vec, p1);
		o2 = __EcoVector_VECTOR_At(vec, p2);
		__EcoVector_VECTOR_Delete(vec, p2);
		__EcoVector_VECTOR_Delete(vec, p1);
		__EcoVector_VECTOR_Insert(vec, p1, o2);
		__EcoVector_VECTOR_Insert(vec, p2, o1);
	}
}

/*----------------------------------------------------------------------------*/
__TDESC(EcoVector_ObjectRec__desc, 1, 0) = {__TDFLDS("ObjectRec", 1), {-8}};
__TDESC(EcoVector_NodeRec__desc, 1, 2) = {__TDFLDS("NodeRec", 8), {0, 4, -24}};
__TDESC(EcoVector_VectorRec__desc, 11, 2) = {__TDFLDS("VectorRec", 12), {4, 8, -24}};

export void *EcoVector__init(void)
{
	__DEFMOD;
	__REGMOD("EcoVector", 0);
	__INITYP(EcoVector_ObjectRec, EcoVector_ObjectRec, 0);
	__INITYP(EcoVector_NodeRec, EcoVector_NodeRec, 0);
	__INITYP(EcoVector_VectorRec, EcoVector_ObjectRec, 1);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_At, 0);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Clear, 1);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Delete, 2);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Head, 3);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Insert, 4);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Length, 5);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_PopBack, 6);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_PushBack, 7);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Swap, 8);
	__INITBP(EcoVector_VectorRec, EcoVector_VECTOR_Tail, 9);
/* BEGIN */
	__ENDMOD;
}
