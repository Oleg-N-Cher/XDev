/*  Ofront 1.2 -xtspkae */

#ifndef EcoVector__h
#define EcoVector__h

#include "SYSTEM.h"

typedef
	struct EcoVector_ObjectRec *EcoVector_OBJECT;

typedef
	struct EcoVector_ObjectRec {
		char _prvt0[1];
	} EcoVector_ObjectRec;

typedef
	struct EcoVector_VectorRec *EcoVector_VECTOR;

typedef
	struct EcoVector_VectorRec {
		INTEGER _prvt0;
		char _prvt1[8];
	} EcoVector_VectorRec;

import EcoVector_OBJECT EcoVector_VECTOR_At (EcoVector_VECTOR vec, INTEGER pos);
import void EcoVector_VECTOR_Clear (EcoVector_VECTOR vec);
import void EcoVector_VECTOR_Delete (EcoVector_VECTOR vec, INTEGER pos);
import EcoVector_OBJECT EcoVector_VECTOR_Head (EcoVector_VECTOR vec);
import void EcoVector_VECTOR_Insert (EcoVector_VECTOR vec, INTEGER pos, EcoVector_OBJECT e);
import INTEGER EcoVector_VECTOR_Length (EcoVector_VECTOR vec);
import EcoVector_OBJECT EcoVector_VECTOR_PopBack (EcoVector_VECTOR vec);
import void EcoVector_VECTOR_PushBack (EcoVector_VECTOR vec, EcoVector_OBJECT e);
import void EcoVector_VECTOR_Swap (EcoVector_VECTOR vec, INTEGER p1, INTEGER p2);
import EcoVector_OBJECT EcoVector_VECTOR_Tail (EcoVector_VECTOR vec);
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



import LONGINT *EcoVector_ObjectRec__typ;
import LONGINT *EcoVector_VectorRec__typ;

import EcoVector_VECTOR EcoVector_Vector (void);
import void *EcoVector__init(void);


#endif
