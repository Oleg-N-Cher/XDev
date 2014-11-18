#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "ConsoleCfg.h"

#define __hash__ #
#define __id__(x) x
#define __ld_hl__(x) __asm ld hl,__id__(__hash__)x __endasm

#define Console__init()

import void Console_At_ROM (SHORTINT x, SHORTINT y);
import void Console_At_COMPACT (SHORTINT x, SHORTINT y);
import void Console_At_FAST (SHORTINT x, SHORTINT y);
#  ifdef OUTPUT_ROM
#    define Console_At Console_At_ROM
#  endif
#  ifdef OUTPUT_COMPACT
#    define Console_At Console_At_COMPACT
#  endif
#  ifdef OUTPUT_FAST
#    define Console_At Console_At_FAST
#  endif
import INTEGER Console_ReadIntRange_ROM (INTEGER min, INTEGER max);
import INTEGER Console_ReadInt_ROM (void);
import INTEGER Console_ReadIntRange_COMPACT (INTEGER min, INTEGER max);
import INTEGER Console_ReadInt_COMPACT (void);
import INTEGER Console_ReadIntRange_FAST (INTEGER min, INTEGER max);
import INTEGER Console_ReadInt_FAST (void);
#  ifdef OUTPUT_ROM
#    define Console_ReadIntRange Console_ReadIntRange_ROM
#    define Console_ReadInt Console_ReadInt_ROM
#  endif
#  ifdef OUTPUT_COMPACT
#    define Console_ReadIntRange Console_ReadIntRange_COMPACT
#    define Console_ReadInt Console_ReadInt_COMPACT
#  endif
#  ifdef OUTPUT_FAST
#    define Console_ReadIntRange Console_ReadIntRange_FAST
#    define Console_ReadInt Console_ReadInt_FAST
#  endif
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
import void Console_WriteBool_COMPACT (BOOLEAN b);
import void Console_WriteBool_FAST (BOOLEAN b);
import void Console_WriteBool_ROM (BOOLEAN b);
#  ifdef OUTPUT_COMPACT
#    define Console_WriteBool(b) Console_WriteBool_COMPACT(b)
#  endif
#  ifdef OUTPUT_FAST
#    define Console_WriteBool(b) Console_WriteBool_FAST(b)
#  endif
#  ifdef OUTPUT_ROM
#    define Console_WriteBool(b) Console_WriteBool_ROM(b)
#  endif

import void Console_WriteInt_ROM (INTEGER i);
import void Console_WriteInt_COMPACT (INTEGER i);
import void Console_WriteInt_FAST (INTEGER i);
#  ifdef OUTPUT_COMPACT
#    define Console_WriteInt Console_WriteInt_COMPACT
#  endif
#  ifdef OUTPUT_FAST
#    define Console_WriteInt Console_WriteInt_FAST
#  endif
#  ifdef OUTPUT_ROM
#    define Console_WriteInt Console_WriteInt_ROM
#  endif

import void Console_WriteLn_ROM (void);
import void Console_WriteLn_COMPACT (void);
import void Console_WriteLn_FAST (void);
#  ifdef OUTPUT_COMPACT
#    define Console_WriteLn Console_WriteLn_COMPACT
#  endif
#  ifdef OUTPUT_FAST
#    define Console_WriteLn Console_WriteLn_FAST
#  endif
#  ifdef OUTPUT_ROM
#    define Console_WriteLn Console_WriteLn_ROM
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

import void Console_WriteStrLn_C_COMPACT (void/*CHAR *str*/);
import void Console_WriteStrLn_C_FAST (void/*CHAR *str*/);
#  ifdef OUTPUT_COMPACT
#    define Console_WriteStrLn(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_COMPACT(); Console_WriteLn_COMPACT()
#  endif
#  ifdef OUTPUT_FAST
#    define Console_WriteStrLn(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_FAST(); Console_WriteLn_FAST()
#  endif
#  ifdef OUTPUT_ROM
#    define Console_WriteStrLn(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_ROM(); __asm LD A,__id__(__hash__)0x0D \
                                                       RST 16 __endasm
#  endif

import BYTE Console_attrib;
#define Console_SetColors(attr) Console_attrib = attr

#  ifdef OUTPUT_COMPACT
#    define Console_SetFont(fontAddr)	(*(unsigned*) (0x5C36) = ((unsigned)fontAddr - 256))
#  endif
#  ifdef OUTPUT_FAST
#    define Console_SetFont(fontAddr)	(*(unsigned*) (0x5C36) = ((unsigned)fontAddr - 256))
#  endif
#  ifdef OUTPUT_ROM
#    define Console_SetFont(fontAddr)	(*(unsigned*) (0x5C36) = ((unsigned)fontAddr - 256))
#  endif

import void Console_Clear_ROM (SHORTCARD attr);
import void Console_Clear_FAST (SHORTCARD attr);
import void Console_Clear_COMPACT (SHORTCARD attr);
#  ifdef OUTPUT_COMPACT
#    define Console_Clear Console_Clear_COMPACT
#  endif
#  ifdef OUTPUT_FAST
#    define Console_Clear Console_Clear_FAST
#  endif
#  ifdef OUTPUT_ROM
#    define Console_Clear Console_Clear_ROM
#  endif

#endif
