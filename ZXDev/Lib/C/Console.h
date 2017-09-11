#ifndef Console__h
#define Console__h

#include "SYSTEM.h"
#include "XDevCfg.h"

#define __hash__ #
#define __id__(x) x
#define __ld_hl__(x) __asm ld hl,__id__(__hash__)x __endasm

#ifdef Console_OUTPUT_ROM
#  define Console__init() __asm call 0x1642 __endasm
#else
#  define Console__init()
#endif

extern void Console_At_ROM (signed char x, signed char y);
extern void Console_At_COMPACT (signed char x, signed char y);
extern void Console_At_FAST (signed char x, signed char y);
#  ifdef Console_OUTPUT_ROM
#    define Console_At Console_At_ROM
#  endif
#  ifdef Console_OUTPUT_COMPACT
#    define Console_At Console_At_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_At Console_At_FAST
#  endif
extern INTEGER Console_ReadIntRange_ROM (INTEGER min, INTEGER max);
extern INTEGER Console_ReadInt_ROM (void);
extern INTEGER Console_ReadIntRange_COMPACT (INTEGER min, INTEGER max);
extern INTEGER Console_ReadInt_COMPACT (void);
extern INTEGER Console_ReadIntRange_FAST (INTEGER min, INTEGER max);
extern INTEGER Console_ReadInt_FAST (void);
#  ifdef Console_OUTPUT_ROM
#    define Console_ReadIntRange Console_ReadIntRange_ROM
#    define Console_ReadInt Console_ReadInt_ROM
#  endif
#  ifdef Console_OUTPUT_COMPACT
#    define Console_ReadIntRange Console_ReadIntRange_COMPACT
#    define Console_ReadInt Console_ReadInt_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_ReadIntRange Console_ReadIntRange_FAST
#    define Console_ReadInt Console_ReadInt_FAST
#  endif
extern void Console_WriteCh_COMPACT (unsigned char ch) __z88dk_fastcall;
extern void Console_WriteCh_FAST (unsigned char ch) __z88dk_fastcall;
extern void Console_WriteCh_ROM (unsigned char ch) __z88dk_fastcall;
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteCh(ch) Console_WriteCh_COMPACT(ch)
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteCh(ch) Console_WriteCh_FAST(ch)
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteCh(ch) Console_WriteCh_ROM(ch)
#  endif
extern void Console_WriteBool_COMPACT (BOOLEAN b);
extern void Console_WriteBool_FAST (BOOLEAN b);
extern void Console_WriteBool_ROM (BOOLEAN b);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteBool(b) Console_WriteBool_COMPACT(b)
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteBool(b) Console_WriteBool_FAST(b)
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteBool(b) Console_WriteBool_ROM(b)
#  endif

extern void Console_WriteInt_ROM (int n) __z88dk_fastcall;
extern void Console_WriteInt_COMPACT (int n);
extern void Console_WriteInt_FAST (int n);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteInt Console_WriteInt_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteInt Console_WriteInt_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteInt Console_WriteInt_ROM
#  endif

extern void Console_WriteLn_ROM (void);
extern void Console_WriteLn_COMPACT (void);
extern void Console_WriteLn_FAST (void);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteLn Console_WriteLn_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteLn Console_WriteLn_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteLn Console_WriteLn_ROM
#  endif

extern void Console_WriteStr_C_COMPACT (void/*CHAR *str*/);
extern void Console_WriteStr_C_FAST (void/*CHAR *str*/);
extern void Console_WriteStr_C_ROM (void/*CHAR *str*/);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteStr(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_COMPACT()
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteStr(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_FAST()
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteStr(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_ROM()
#  endif

extern void Console_WriteStrLn_C_COMPACT (void/*CHAR *str*/);
extern void Console_WriteStrLn_C_FAST (void/*CHAR *str*/);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteStrLn(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_COMPACT(); Console_WriteLn_COMPACT()
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteStrLn(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_FAST(); Console_WriteLn_FAST()
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteStrLn(str,len) \
       SYSTEM_str_par = str; Console_WriteStr_C_ROM(); __asm LD A,__id__(__hash__)0x0D \
                                                       RST 16 __endasm
#  endif

extern void Console_WriteUInt_ROM (unsigned int n) __z88dk_fastcall;

extern BYTE Console_attrib;
#define Console_SetColors(attr) Console_attrib = attr

#  ifdef Console_OUTPUT_COMPACT
#    define Console_SetFont(fontAddr)	(*(unsigned*) (0x5C36) = ((unsigned)fontAddr - 256))
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_SetFont(fontAddr)	(*(unsigned*) (0x5C36) = ((unsigned)fontAddr - 256))
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_SetFont(fontAddr)	(*(unsigned*) (0x5C36) = ((unsigned)fontAddr - 256))
#  endif

extern void Console_Clear_ROM (unsigned char attr) __z88dk_fastcall;
extern void Console_Clear_FAST (unsigned char attr) __z88dk_fastcall;
extern void Console_Clear_COMPACT (unsigned char attr) __z88dk_fastcall;
#  ifdef Console_OUTPUT_COMPACT
#    define Console_Clear Console_Clear_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_Clear Console_Clear_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_Clear Console_Clear_ROM
#  endif

#endif
