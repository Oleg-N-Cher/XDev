#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"
#include "BasicCfg.h"

#define __hash__ #
#define __id__(x) x
#define __ld_a__(x) if(x==0) {__asm xor a,a __endasm;}else{__asm ld a,__id__(__hash__)x __endasm;}
#define __ld_c__(x) __asm ld c,__id__(__hash__)x __endasm

import void Basic_Init_DI (void);
import void Basic_Init_IM0 (void);
import void Basic_Init_IM2 (void);
#ifdef MODE_DI
#  define Basic_Init Basic_Init_DI
#endif //MODE_DI
#ifdef MODE_IM0
#  define Basic_Init Basic_Init_IM0
#endif //MODE_IM0
#ifdef MODE_IM2
#  define Basic_Init Basic_Init_IM2
#endif //MODE_IM2

import void Basic_BORDER_stdcall (SHORTINT color);
#ifndef BORDER_fastcall
  #define Basic_BORDER Basic_BORDER_stdcall
#else //BORDER_fastcall
  #define Basic_BORDER(color) __ld_a__(color); \
    __asm \
    call 0x229B \
    __endasm;
#endif

import void Basic_INK_stdcall (SHORTINT color);
import void Basic_INK_fastcall (void /* Register C */);
#ifndef INK_fastcall
  #define Basic_INK Basic_INK_stdcall
#else //INK_fastcall
  #define Basic_INK(color) __ld_c__(color); Basic_INK_fastcall()
#endif

import void Basic_PAPER_stdcall (SHORTINT color);
import void Basic_PAPER_fastcall (void /* Register C */);
#ifndef PAPER_fastcall
  #define Basic_PAPER Basic_PAPER_stdcall
#else //PAPER_fastcall
  #define Basic_PAPER(color) __ld_c__(color); Basic_PAPER_fastcall()
#endif

import void Basic_FLASH_stdcall (SHORTINT mode);
import void Basic_FLASH_fastcall (void /* Register C */);
#ifndef FLASH_fastcall
  #define Basic_FLASH Basic_FLASH_stdcall
#else //FLASH_fastcall
  #define Basic_FLASH(mode) __ld_c__(mode); Basic_FLASH_fastcall()
#endif

import void Basic_BRIGHT_stdcall (SHORTINT mode);
import void Basic_BRIGHT_fastcall (void /* Register C */);
#ifndef BRIGHT_fastcall
  #define Basic_BRIGHT Basic_BRIGHT_stdcall
#else //BRIGHT_fastcall
  #define Basic_BRIGHT(mode) __ld_c__(mode); Basic_BRIGHT_fastcall()
#endif

import void Basic_INVERSE_FAST (SHORTINT mode);
import void Basic_INVERSE_ROM (SHORTINT mode);
#ifdef ROM_OUTPUT
  #define Basic_INVERSE Basic_INVERSE_ROM
#else
  #define Basic_INVERSE Basic_INVERSE_FAST
#endif

import void Basic_OVER_FAST (SHORTINT mode);
import void Basic_OVER_ROM (SHORTINT mode);
#ifdef ROM_OUTPUT
  #define Basic_OVER Basic_OVER_ROM
#else
  #define Basic_OVER Basic_OVER_FAST
#endif

import void Basic_AT_FAST (SHORTINT y, SHORTINT x);
import void Basic_AT_ROM (SHORTINT y, SHORTINT x);
#ifdef ROM_OUTPUT
  #define Basic_AT Basic_AT_ROM
#else
  #define Basic_AT Basic_AT_FAST
#endif

import void Basic_CLS_ZX (void);
import void Basic_CLS_FULLSCREEN (void);
#ifdef CLS_FULLSCREEN
  #define Basic_CLS Basic_CLS_FULLSCREEN
#else
  #define Basic_CLS Basic_CLS_ZX
#endif

import void Basic_PRSTR_C_FAST (CHAR *str);
import void Basic_PRSTR_C_ROM (CHAR *str);
#ifdef ROM_OUTPUT
  #define Basic_PRSTR(str,len) Basic_PRSTR_C_ROM(str)
  #define PRSTR Basic_PRSTR_C_ROM
#else
  #define Basic_PRSTR(str,len) Basic_PRSTR_C_FAST(str)
  #define PRSTR Basic_PRSTR_C_FAST
#endif

import void Basic_PRCHAR_FAST (CHAR ch);
import void Basic_PRCHAR_ROM (CHAR ch);
#ifdef ROM_OUTPUT
  #define Basic_PRCHAR Basic_PRCHAR_ROM
#else
  #define Basic_PRCHAR Basic_PRCHAR_FAST
#endif

#define Basic_PRUDG(udg) Basic_PRCHAR_ROM(udg+79)

import void Basic_PRDATA (void);

import void Basic_PRLN (void);

import void Basic_PLOT (SHORTINT x, SHORTINT y);

import SYSTEM_BYTE Basic_POINT (SHORTINT x, SHORTINT y);

import SYSTEM_BYTE Basic_ATTR (SHORTINT y, SHORTINT x);

import void Basic_DRAW (SHORTINT x, SHORTINT y);

import void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius);

export void Basic_PRINT_FAST (INTEGER i);
export void Basic_PRINT_ROM (INTEGER i);
#ifdef ROM_OUTPUT
  #define Basic_PRINT Basic_PRINT_ROM
#else
  #define Basic_PRINT Basic_PRINT_FAST
#endif

import void Basic_PRWORD_FAST (CARDINAL n);
import void Basic_PRWORD_ROM (CARDINAL n);
#ifdef ROM_OUTPUT
  #define Basic_PRWORD Basic_PRWORD_ROM
#else
  #define Basic_PRWORD Basic_PRWORD_FAST
#endif

import void Basic_SlowCircle (SHORTINT cx, SHORTINT cy, SHORTINT radius);

#define Basic_POKE(addr,val)  (*(unsigned char*) (addr) = (val))
#define Basic_POKEW(addr,val) (*(unsigned*) (addr) = (val))
#define Basic_PEEK(addr)      (*(unsigned char*) (addr))
#define Basic_PEEKW(addr)     (*(unsigned*) (addr))

import SYSTEM_BYTE Basic_PORTIN (SYSTEM_ADDRESS port);

import void Basic_PORTOUT (SYSTEM_ADDRESS port, SYSTEM_BYTE value);

import BOOLEAN Basic_KeyPressed (void);

import void Basic_PAUSE_DI (CARDINAL ticks);
import void Basic_PAUSE_EI (CARDINAL ticks);
#ifdef MODE_DI
#  define Basic_PAUSE Basic_PAUSE_DI
#endif //MODE_DI
#ifdef MODE_IM0
#  define Basic_PAUSE Basic_PAUSE_EI
#endif //MODE_IM0
#ifdef MODE_IM2
#  define Basic_PAUSE Basic_PAUSE_EI
#endif //MODE_IM2


import void Basic_RANDOMIZE (CARDINAL seed);

import SHORTCARD Basic_RND_BYTE (SHORTCARD min, SHORTCARD max);
import CARDINAL Basic_RND_WORD (CARDINAL min, CARDINAL max);
#ifdef RND_SHORTCARD
  #define Basic_RND Basic_RND_BYTE
#else
  #define Basic_RND Basic_RND_WORD
#endif

import SHORTINT Basic_SGN (SHORTINT x);

import void Basic_BEEP_DI (CARDINAL ms, SHORTINT freq);
import void Basic_BEEP_EI (CARDINAL ms, SHORTINT freq);
#ifdef MODE_DI
#  define Basic_BEEP Basic_BEEP_DI
#endif //MODE_DI
#ifdef MODE_IM0
#  define Basic_BEEP Basic_BEEP_EI
#endif //MODE_IM0
#ifdef MODE_IM2
#  define Basic_BEEP Basic_BEEP_EI
#endif //MODE_IM2

#define Basic_FONT(fontAddr) (*(unsigned*) (0x5C36) = (fontAddr - 256))
#define Basic_UDG(udgAddr) (*(unsigned*) (0x5C7B) = udgAddr)

import void Basic_Reset (void);

#define Basic_DEFDATA(title, size) if (size <= 127) { __asm ld hl,__id__(__hash__).+8 \
    ld   (_##title),hl \
    jr   2+.+size \
    __endasm; \
  } else { __asm ld hl,__id__(__hash__).+9 \
    ld   (_##title),hl \
    jp   3+.+size \
  __endasm; \
  }
  
#define Basic_DEFDATAREL(title, size) if (size <= 127) { __asm xor a,a \
    inc  a \
    call 0x1FC6 \
    ld   de,__id__(__hash__)9 \
    add  hl,de \
    ld   (_##title),hl \
    jr   2+.+size \
    __endasm; \
  } else { __asm xor a,a \
    inc  a \
    call 0x1FC6 \
    ld   de,__id__(__hash__)12 \
    add  hl,de \
    ld   (_##title),hl \
    ld   de,__id__(__hash__)size \
    add  hl,de \
    jp   (hl) \
  __endasm; \
  }
#define Basic_READ(addr) (*(unsigned char*) (addr++))
#define Basic_DATA(b) __asm .db b __endasm
#define Basic_DATA1(b) __asm .db b __endasm
#define Basic_DATA2(b1,b2) __asm .db b1,b2 __endasm
#define Basic_DATA3(b1,b2,b3) __asm .db b1,b2,b3 __endasm
#define Basic_DATA4(b1,b2,b3,b4) __asm .db b1,b2,b3,b4 __endasm
#define Basic_DATA5(b1,b2,b3,b4,b5) __asm .db b1,b2,b3,b4,b5 __endasm
#define Basic_DATA6(b1,b2,b3,b4,b5,b6) __asm .db b1,b2,b3,b4,b5,b6 __endasm
#define Basic_DATA7(b1,b2,b3,b4,b5,b6,b7) __asm .db b1,b2,b3,b4,b5,b6,b7 __endasm
#define Basic_DATA8(b1,b2,b3,b4,b5,b6,b7,b8) __asm .db b1,b2,b3,b4,b5,b6,b7,b8 __endasm
#define Basic_DATA9(b1,b2,b3,b4,b5,b6,b7,b8,b9) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9 __endasm
#define Basic_DATA10(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10 __endasm
#define Basic_DATA11(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11 __endasm
#define Basic_DATA12(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12 __endasm
#define Basic_DATA13(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13 __endasm
#define Basic_DATA14(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14 __endasm
#define Basic_DATA15(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15 __endasm
#define Basic_DATA16(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16 __endasm
#define Basic_DATACH(b) __asm .db b __endasm
#define Basic_DATACH1(b) __asm .db b __endasm
#define Basic_DATACH2(b1,b2) __asm .db b1,b2 __endasm
#define Basic_DATACH3(b1,b2,b3) __asm .db b1,b2,b3 __endasm
#define Basic_DATACH4(b1,b2,b3,b4) __asm .db b1,b2,b3,b4 __endasm
#define Basic_DATACH5(b1,b2,b3,b4,b5) __asm .db b1,b2,b3,b4,b5 __endasm
#define Basic_DATACH6(b1,b2,b3,b4,b5,b6) __asm .db b1,b2,b3,b4,b5,b6 __endasm
#define Basic_DATACH7(b1,b2,b3,b4,b5,b6,b7) __asm .db b1,b2,b3,b4,b5,b6,b7 __endasm
#define Basic_DATACH8(b1,b2,b3,b4,b5,b6,b7,b8) __asm .db b1,b2,b3,b4,b5,b6,b7,b8 __endasm
#define Basic_DATACH9(b1,b2,b3,b4,b5,b6,b7,b8,b9) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9 __endasm
#define Basic_DATACH10(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10 __endasm
#define Basic_DATACH11(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11 __endasm
#define Basic_DATACH12(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12 __endasm
#define Basic_DATACH13(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13 __endasm
#define Basic_DATACH14(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14 __endasm
#define Basic_DATACH15(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15 __endasm
#define Basic_DATACH16(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16 __endasm

import void Basic_Quit_DI (void);
import void Basic_Quit_IM0 (void);
import void Basic_Quit_IM2 (void);
#ifdef MODE_DI
#  define Basic_Quit Basic_Quit_DI
#endif //MODE_DI
#ifdef MODE_IM0
#  define Basic_Quit Basic_Quit_IM0
#endif //MODE_IM0
#ifdef MODE_IM2
#  define Basic_Quit Basic_Quit_IM2
#endif //MODE_IM2
#define Basic__init()

#define Black 0
#define Blue 1
#define Red 2
#define Magenta 3
#define Green 4
#define Cyan 5
#define Brown 6
#define LightGray 7

#define LightBlue 1
#define LightRed 2
#define LightMagenta 3
#define LightGreen 4
#define LightCyan 5
#define Yellow 6
#define White 7

#define On 1
#define Off 0

#define BORDER Basic_BORDER
#define INK Basic_INK
#define PAPER Basic_PAPER
#define FLASH Basic_FLASH
#define BRIGHT Basic_BRIGHT
#define INVERSE Basic_INVERSE
#define OVER Basic_OVER
#define AT Basic_AT
#define CLS Basic_CLS
#define PRCHAR Basic_PRCHAR
#define PLOT Basic_PLOT
#define POINT Basic_POINT
#define ATTR Basic_ATTR
#define DRAW Basic_DRAW
#define CIRCLE Basic_CIRCLE
#define PRINT Basic_PRINT
#define PRWORD Basic_PRWORD
#define SlowCircle Basic_SlowCircle
#define POKE(addr,val)  (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val) (*(unsigned*) (addr) = (val))
#define PEEK(addr)      (*(unsigned char*) (addr))
#define PEEKW(addr)     (*(unsigned*) (addr))
#define PORTIN Basic_PORTIN
#define PORTOUT Basic_PORTOUT
#define KeyPressed Basic_KeyPressed
#define PAUSE Basic_PAUSE
#define RANDOMIZE Basic_RANDOMIZE
#define RND Basic_RND
#define SGN Basic_SGN
#define BEEP Basic_BEEP
#define FONT Basic_FONT
#define Reset Basic_Reset

#endif
