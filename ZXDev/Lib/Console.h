/*  Ofront 1.2 -xtspkae */

#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "ConsoleCfg.h"

#define __hash__ #
#define __id__(x) x
#define __ld_hl__(x) __asm ld hl,__id__(__hash__)x __endasm

#define Console__init()

import void Console_WriteCh_COMPACT (CHAR ch);
import void Console_WriteCh_FAST (CHAR ch);
import void Console_WriteCh_ROM (CHAR ch);
#  ifdef OUTPUT_COMPACT
#    define Console_WriteCh(ch) Console_WriteCh_COMPACT(ch)
#  endif
#  ifdef OUTPUT_FAST
#    define Console_WriteCh(ch) Console_WriteCh_FAST(ch)
#  endif
#  ifdef OUTPUT_ROM
#    define Console_WriteCh(ch) Console_WriteCh_ROM(ch)
#  endif

import void Console_WriteStr_C_COMPACT (void/*CHAR *str*/);
import void Console_WriteStr_C_FAST (void/*CHAR *str*/);
import void Console_WriteStr_C_ROM (void/*CHAR *str*/);
#  ifdef OUTPUT_COMPACT
#    define Console_WriteStr(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_COMPACT()
#  endif
#  ifdef OUTPUT_FAST
#    define Console_WriteStr(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_FAST()
#  endif
#  ifdef OUTPUT_ROM
#    define Console_WriteStr(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_ROM()
#  endif

import SYSTEM_BYTE Console_attrib;
#define Console_SetColors(attr) Console_attrib = attr

#endif
