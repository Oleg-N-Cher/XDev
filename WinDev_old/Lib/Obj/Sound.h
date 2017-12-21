/*  Ofront 1.2 -xtspkae */

#ifndef Sound__h
#define Sound__h

#include "SYSTEM.h"
#include "SdlMixer.h"


import BOOLEAN Sound_initOk;


import void Sound_Free (SdlMixer_PMix_Chunk *sound);
import void Sound_Load (SdlMixer_PMix_Chunk *sound, CHAR *fileName, LONGINT fileName__len);
import void Sound_Play (SdlMixer_PMix_Chunk sound);
import void Sound_Quit (void);
import void *Sound__init(void);


#endif
