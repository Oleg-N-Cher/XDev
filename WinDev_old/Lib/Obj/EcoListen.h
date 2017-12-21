/*  Ofront 1.2 -xtspkae */

#ifndef EcoListen__h
#define EcoListen__h

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
	struct EcoListen_ListDesc {
		INTEGER _prvt0;
		char _prvt1[4];
	} EcoListen_ListDesc;

typedef
	EcoListen_ListDesc *EcoListen_Liste;



import LONGINT *EcoListen_ElementDesc__typ;
import LONGINT *EcoListen_ListDesc__typ;

import EcoListen_Liste EcoListen_Append (EcoListen_Liste list, EcoListen_Element e);
import EcoListen_Liste EcoListen_Concat (EcoListen_Element head, EcoListen_Liste tail);
import EcoListen_Element EcoListen_Find (EcoListen_Element e, EcoListen_Liste l, EcoListen_CompareProc equal);
import EcoListen_Element EcoListen_Head (EcoListen_Liste l);
import BOOLEAN EcoListen_IsElement (EcoListen_Element e, EcoListen_Liste l, EcoListen_CompareProc equal);
import EcoListen_Liste EcoListen_Tail (EcoListen_Liste l);
import void *EcoListen__init(void);


#endif
