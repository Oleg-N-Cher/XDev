/*  Ofront 1.2 -xtspkae */

#ifndef EcoBuffer__h
#define EcoBuffer__h

#include "SYSTEM.h"


import BOOLEAN EcoBuffer_nonempty, EcoBuffer_nonfull;


import void EcoBuffer_get (INTEGER *x);
import void EcoBuffer_put (INTEGER x);
import void *EcoBuffer__init(void);


#endif
