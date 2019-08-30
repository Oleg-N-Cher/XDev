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
extern SHORTINT Console_ReadIntRange_ROM (SHORTINT min, SHORTINT max);
extern SHORTINT Console_ReadInt_ROM (void);
extern SHORTINT Console_ReadIntRange_COMPACT (SHORTINT min, SHORTINT max);
extern SHORTINT Console_ReadInt_COMPACT (void);
extern SHORTINT Console_ReadIntRange_FAST (SHORTINT min, SHORTINT max);
extern SHORTINT Console_ReadInt_FAST (void);
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
extern void Console_ReadStr_COMPACT (CHAR *str, SHORTINT str__len, BYTE maxlen);
extern void Console_ReadStr_FAST (CHAR *str, SHORTINT str__len, BYTE maxlen);
extern void Console_ReadStr_ROM (CHAR *str, SHORTINT str__len, BYTE maxlen);
#  ifdef Console_OUTPUT_ROM
#    define Console_ReadStr Console_ReadStr_ROM
#  endif
#  ifdef Console_OUTPUT_COMPACT
#    define Console_ReadStr Console_ReadStr_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_ReadStr Console_ReadStr_FAST
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

extern void Console_WriteLong_ROM (long n);
extern void Console_WriteLong_COMPACT (long n);
extern void Console_WriteLong_FAST (long n);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteLong Console_WriteLong_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteLong Console_WriteLong_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteLong Console_WriteLong_ROM
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

extern void Console_WriteReal_ROM (float x);
extern void Console_WriteReal_COMPACT (float x);
extern void Console_WriteReal_FAST (float x);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteReal Console_WriteReal_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteReal Console_WriteReal_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteReal Console_WriteReal_ROM
#  endif
void Console_WriteRealFix_ROM (float x, BYTE n);
void Console_WriteRealFix_COMPACT (float x, BYTE n);
void Console_WriteRealFix_FAST (float x, BYTE n);
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteRealFix Console_WriteRealFix_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteRealFix Console_WriteRealFix_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteRealFix Console_WriteRealFix_ROM
#  endif

extern void Console_WriteInt_ROM (int n) __z88dk_fastcall;
extern void Console_WriteInt_COMPACT (int n) __z88dk_fastcall;
extern void Console_WriteInt_FAST (int n) __z88dk_fastcall;
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteInt Console_WriteInt_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteInt Console_WriteInt_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteInt Console_WriteInt_ROM
#  endif

extern void Console_WriteStr_C_COMPACT (unsigned char *str) __z88dk_fastcall;
extern void Console_WriteStr_C_FAST (unsigned char *str) __z88dk_fastcall;
extern void Console_WriteStr_C_ROM (unsigned char *str) __z88dk_fastcall;
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteStr(str,len) Console_WriteStr_C_COMPACT(str)
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteStr(str,len) Console_WriteStr_C_FAST(str)
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteStr(str,len) Console_WriteStr_C_ROM(str)
#  endif

extern void Console_WriteStrLn_C_COMPACT (unsigned char *str) __z88dk_fastcall;
extern void Console_WriteStrLn_C_FAST (unsigned char *str) __z88dk_fastcall;
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteStrLn(str,len) \
       Console_WriteStr_C_COMPACT(str); Console_WriteLn_COMPACT()
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteStrLn(str,len) \
       Console_WriteStr_C_FAST(str); Console_WriteLn_FAST()
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteStrLn(str,len) \
       Console_WriteStr_C_ROM(str); __asm LD A,__id__(__hash__)0x0D \
       RST 16 __endasm
#  endif

extern void Console_WriteUShort_COMPACT (unsigned int n) __z88dk_fastcall;
extern void Console_WriteUShort_FAST (unsigned int n) __z88dk_fastcall;
extern void Console_WriteUShort_ROM (unsigned int n) __z88dk_fastcall;
#  ifdef Console_OUTPUT_COMPACT
#    define Console_WriteUShort Console_WriteUShort_COMPACT
#  endif
#  ifdef Console_OUTPUT_FAST
#    define Console_WriteUShort Console_WriteUShort_FAST
#  endif
#  ifdef Console_OUTPUT_ROM
#    define Console_WriteUShort Console_WriteUShort_ROM
#  endif

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
