/*  Ofront 1.2 -xtspkae */

#ifndef EcoLists__h
#define EcoLists__h

#include "SYSTEM.h"

typedef
	struct EcoLists_Node *EcoLists_NodePtr;

typedef
	void (*EcoLists_DoProc)(EcoLists_NodePtr);

typedef
	struct EcoLists_List {
		INTEGER _prvt0;
		char _prvt1[6];
	} EcoLists_List;

typedef
	struct EcoLists_Node {
		INTEGER _prvt0;
		char _prvt1[4];
	} EcoLists_Node;



import LONGINT *EcoLists_Node__typ;
import LONGINT *EcoLists_List__typ;

import void EcoLists_AddBefore (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n, EcoLists_NodePtr x);
import void EcoLists_AddBehind (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n, EcoLists_NodePtr x);
import void EcoLists_AddHead (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n);
import void EcoLists_AddMarkBefore (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark, EcoLists_NodePtr x);
import void EcoLists_AddMarkBehind (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark, EcoLists_NodePtr x);
import void EcoLists_AddMarkHead (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark);
import void EcoLists_AddMarkTail (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark);
import void EcoLists_AddTail (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n);
import INTEGER EcoLists_CountElements (EcoLists_List *list, LONGINT *list__typ);
import void EcoLists_DoBackward (EcoLists_List *list, LONGINT *list__typ, EcoLists_DoProc proc);
import void EcoLists_DoForward (EcoLists_List *list, LONGINT *list__typ, EcoLists_DoProc proc);
import BOOLEAN EcoLists_Empty (EcoLists_List *list, LONGINT *list__typ);
import EcoLists_NodePtr EcoLists_GetPred (EcoLists_NodePtr n);
import EcoLists_NodePtr EcoLists_GetSucc (EcoLists_NodePtr n);
import void EcoLists_GoBackward (EcoLists_List list, EcoLists_NodePtr *n, INTEGER num);
import void EcoLists_GoForward (EcoLists_List list, EcoLists_NodePtr *n, INTEGER num);
import EcoLists_NodePtr EcoLists_Head (EcoLists_List *list, LONGINT *list__typ);
import void EcoLists_Init (EcoLists_List *list, LONGINT *list__typ);
import BOOLEAN EcoLists_IsElement (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr e);
import BOOLEAN EcoLists_Next (EcoLists_NodePtr *n);
import void EcoLists_Pred (EcoLists_NodePtr *n);
import BOOLEAN EcoLists_Previous (EcoLists_NodePtr *n);
import EcoLists_NodePtr EcoLists_RemHead (EcoLists_List *list, LONGINT *list__typ);
import EcoLists_NodePtr EcoLists_RemTail (EcoLists_List *list, LONGINT *list__typ);
import void EcoLists_Remove (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr n);
import void EcoLists_RemoveMark (EcoLists_List *list, LONGINT *list__typ, EcoLists_List mark);
import void EcoLists_SetMark (EcoLists_List *mark, LONGINT *mark__typ, EcoLists_NodePtr h, EcoLists_NodePtr t);
import void EcoLists_Succ (EcoLists_NodePtr *n);
import void EcoLists_Swap (EcoLists_List *list, LONGINT *list__typ, EcoLists_NodePtr a, EcoLists_NodePtr b);
import EcoLists_NodePtr EcoLists_Tail (EcoLists_List *list, LONGINT *list__typ);
import void *EcoLists__init(void);


#endif
