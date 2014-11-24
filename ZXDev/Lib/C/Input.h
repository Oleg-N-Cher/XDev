#ifndef Input__h
#define Input__h

#include "XDevCfg.h"


extern unsigned char Input_Available (void);

extern CHAR Input_Read_NoKeyRepeat (void);
extern CHAR Input_Read_KeyRepeat (void);
extern CHAR Input_Read_KeyRepeatBuf (void);
#  ifdef Input_KeyNoRepeat
#    define Input_Read Input_Read_KeyNoRepeat
#  endif
#  ifdef Input_KeyRepeat
#    define Input_Read Input_Read_KeyRepeat
#  endif
#  ifdef Input_KeyRepeatBuf
#    define Input_Read Input_Read_KeyRepeatBuf
#  endif

extern void Input_RunMe50Hz (void);

#  ifdef Input_KeyRepeatCount
#    define Input__init() (*(unsigned char*) (0x5C09) = (Input_KeyRepeatCount))
#else
#    define Input__init()
#  endif


#endif

