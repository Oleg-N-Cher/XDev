/* Ofront+ 0.9 -s */

#ifndef Sound__h
#define Sound__h

#include "SYSTEM.h"




import void Sound_Play (INTEGER fx);
import void Sound_Quit (void);
import void Sound_RunMe50Hz (void);
import void *Sound__init(void);

#define Sound__init()	Sound_Quit()

#endif
