/*  Ofront 1.2 -xtspkae */

#ifndef KolFiles__h
#define KolFiles__h

#include "SYSTEM.h"


import SYSTEM_PTR KolFiles_hInstance;


import BOOLEAN KolFiles_ExtractFileName (CHAR *path, LONGINT path__len, CHAR *name, LONGINT name__len);
import BOOLEAN KolFiles_FileClose (SYSTEM_PTR handle);
import SYSTEM_PTR KolFiles_FileCreate (CHAR *fileName, LONGINT fileName__len, SET openFlags);
import void *KolFiles__init(void);

#define KolFiles__init()	/*-noinit*/

#endif
