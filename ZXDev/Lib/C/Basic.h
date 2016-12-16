#ifndef Basic__h
#define Basic__h

#include "SYSTEM.h"
#include "BasicCfg.h"

#define __hash__ #
#define __id__(x) x
#define __ld_a__(x) if(x==0) {__asm xor a __endasm;}else{__asm ld a,__id__(__hash__)x __endasm;}
#define __ld_c__(x) __asm ld c,__id__(__hash__)x __endasm
#define __ld_bc__(x) __asm ld bc,__id__(__hash__)x __endasm

extern void Basic_Init_IM2 (void);
#if defined (MODE_DI) || defined (MODE_DI_inline)
#  define Basic_Init() __asm DI __endasm
#endif //MODE_DI
#ifdef MODE_IM1
#  define Basic_Init()
#endif //MODE_IM1
#if defined (MODE_IM2) || defined (MODE_IM2_inline)
#  define Basic_Init Basic_Init_IM2
#endif //MODE_IM2

extern void Basic_BORDER_z88dk_fastcall (unsigned char color) __z88dk_fastcall;
#ifndef BORDER_fastcall
  #define Basic_BORDER Basic_BORDER_z88dk_fastcall
#else //BORDER_fastcall
  #define Basic_BORDER(color) __ld_a__(color); __asm \
    call 0x229B \
    __endasm;
#endif

extern void Basic_COLOR_fastcall (void /* Register A */) __preserves_regs(b,c,d,e,h,l,iyl,iyh);
extern void Basic_COLOR_z88dk_fastcall (unsigned char atr) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
#ifndef COLOR_fastcall
  #define Basic_COLOR Basic_COLOR_z88dk_fastcall
#else //COLOR_fastcall
  #define Basic_COLOR(atr) __ld_a__(atr); Basic_COLOR_fastcall()
#endif

extern void Basic_INK    (unsigned char color) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
extern void Basic_PAPER  (unsigned char color) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
extern void Basic_FLASH  (unsigned char mode)  __z88dk_fastcall __preserves_regs(b,c,d,e);
extern void Basic_BRIGHT (unsigned char mode)  __z88dk_fastcall __preserves_regs(b,c,d,e);

extern void Basic_INVERSE_FAST (unsigned char mode) __z88dk_fastcall __preserves_regs(b,c,d,e,h);
extern void Basic_INVERSE_ROM (unsigned char mode) __z88dk_fastcall __preserves_regs(b,c,d,e);
#ifdef ROM_OUTPUT
#  define Basic_INVERSE Basic_INVERSE_ROM
#else
#  define Basic_INVERSE Basic_INVERSE_FAST
#endif

extern void Basic_OVER_FAST (SHORTINT mode);
extern void Basic_OVER_ROM_stdcall (SHORTINT mode);
extern void Basic_OVER_ROM_fastcall (void /* Register C */);
#ifdef ROM_OUTPUT
#  ifndef OVER_fastcall
#    define Basic_OVER Basic_OVER_ROM_stdcall
#  else
#    define Basic_OVER(mode) __ld_c__(mode); Basic_OVER_ROM_fastcall();
#  endif
#else
#  define Basic_OVER Basic_OVER_FAST
#endif

extern void Basic_AT_FAST (SHORTINT y, SHORTINT x);
extern void Basic_AT_ROM_stdcall (SHORTINT y, SHORTINT x);
extern void Basic_AT_ROM_fastcall (void /* post */);
#ifdef ROM_OUTPUT
#  ifndef AT_fastcall
#    define Basic_AT Basic_AT_ROM_stdcall
#  else
#    define Basic_AT(y,x) Basic_AT_ROM_fastcall(); Basic_DATA2(y,x)
#  endif
#else
  #define Basic_AT Basic_AT_FAST
#endif

extern void Basic_CLS_ZX (void);
extern void Basic_CLS_FULLSCREEN (void);
#ifdef CLS_FULLSCREEN
  #define Basic_CLS Basic_CLS_FULLSCREEN
#else
  #define Basic_CLS Basic_CLS_ZX
#endif

extern void Basic_PAINT (unsigned char x, unsigned char y, unsigned char ink);
extern void Basic_PRSTR_C_FAST (CHAR *str);
extern void Basic_PRSTR_C_ROM_stdcall (CHAR *str);
extern void Basic_PRSTR_C_ROM_fastcall (void /* post */);
#ifdef ROM_OUTPUT
#  ifndef PRSTR_fastcall
#    define Basic_PRSTR(str,len) Basic_PRSTR_C_ROM_stdcall(str)
#    define PRSTR Basic_PRSTR_C_ROM_stdcall
#  else
#    define Basic_PRSTR(str,len) Basic_PRSTR_C_ROM_fastcall(); __asm \
       .ascii __arg_killer__ str \
       .db 0x00                  \
     __endasm
#  define PRSTR(str) Basic_PRSTR_C_ROM_fastcall(); __asm \
       .ascii __arg_killer__ str \
       .db 0x00                  \
     __endasm
#  endif
#else
  #define Basic_PRSTR(str,len) Basic_PRSTR_C_FAST(str)
  #define PRSTR Basic_PRSTR_C_FAST
#endif

extern void Basic_PRCHAR_FAST (CHAR ch);
extern void Basic_PRCHAR_ROM (CHAR ch);
#ifdef ROM_OUTPUT
  #define Basic_PRCHAR Basic_PRCHAR_ROM
#else
  #define Basic_PRCHAR Basic_PRCHAR_FAST
#endif

#define Basic_PRUDG(udg) Basic_PRCHAR_ROM((CHAR)(udg+79))

extern void Basic_PRDATA (void);

extern void Basic_PRLN (void);

extern void Basic_PLOT (unsigned char x, unsigned char y);

extern BYTE Basic_POINT (SHORTINT x, SHORTINT y);

extern BYTE Basic_ATTR (SHORTINT y, SHORTINT x);

extern void Basic_DRAW_S (signed char x, signed char y);
#define Basic_DRAW(x, y) Basic_DRAW_S((signed char)(x), (signed char)(y))

extern void Basic_CIRCLE (unsigned char cx, unsigned char cy, unsigned char radius);

extern void Basic_CIRCLEW_DI (unsigned char cx, unsigned char cy, INTEGER radius);
extern void Basic_CIRCLEW_EI (unsigned char cx, unsigned char cy, INTEGER radius);
#if defined (MODE_DI) || defined (MODE_DI_inline)
#  define Basic_CIRCLEW Basic_CIRCLEW_DI
#endif //MODE_DI
#if defined (MODE_IM1) || defined (MODE_IM1_inline)
#  define Basic_CIRCLEW Basic_CIRCLE_EIW
#endif //MODE_IM1
#if defined (MODE_IM2) || defined (MODE_IM2_inline)
#  define Basic_CIRCLEW Basic_CIRCLEW_EI
#endif //MODE_IM2

export void Basic_PRINT_FAST (INTEGER i);
export void Basic_PRINT_ROM (INTEGER i);
#ifdef ROM_OUTPUT
  #define Basic_PRINT Basic_PRINT_ROM
#else
  #define Basic_PRINT Basic_PRINT_FAST
#endif

extern void Basic_PRWORD_FAST (CARDINAL n);
extern void Basic_PRWORD_ROM (CARDINAL n);
#ifdef ROM_OUTPUT
  #define Basic_PRWORD Basic_PRWORD_ROM
#else
  #define Basic_PRWORD Basic_PRWORD_FAST
#endif

extern void Basic_CIRCLEROM (unsigned char cx, unsigned char cy, SHORTINT radius);

#define Basic_POKE(addr,val)  (*(unsigned char*) (addr) = (val))
#define Basic_POKEW(addr,val) (*(unsigned*) (addr) = (val))
#define Basic_PEEK(addr)      (*(unsigned char*) (addr))
#define Basic_PEEKW(addr)     (*(unsigned*) (addr))

extern BYTE Basic_PORTIN (SYSTEM_ADDRESS port);

extern void Basic_PORTOUT (SYSTEM_ADDRESS port, BYTE value);

extern BOOLEAN Basic_KeyPressed (void);

extern void Basic_PAUSE_DI_fastcall (void /* Regs BC */);
extern void Basic_PAUSE_DI_stdcall (CARDINAL ticks);
extern void Basic_PAUSE_EI_fastcall (void /* Regs BC */);
extern void Basic_PAUSE_EI_stdcall (CARDINAL ticks);
#if defined (MODE_DI) || defined (MODE_DI_inline)
#  ifdef PAUSE_fastcall
#    define Basic_PAUSE(ticks) __ld_bc__(ticks); Basic_PAUSE_DI_fastcall()
#  else
#    define Basic_PAUSE Basic_PAUSE_DI_stdcall
#  endif
#endif //MODE_DI
#if defined (MODE_IM1) || defined (MODE_IM1_inline)
#  ifdef PAUSE_fastcall
#    define Basic_PAUSE(ticks) __ld_bc__(ticks); Basic_PAUSE_EI_fastcall()
#  else
#    define Basic_PAUSE Basic_PAUSE_EI_stdcall
#  endif
#endif //MODE_IM1
#if defined (MODE_IM2) || defined (MODE_IM2_inline)
#  ifdef PAUSE_fastcall
#    define Basic_PAUSE(ticks) __ld_bc__(ticks); Basic_PAUSE_EI_fastcall()
#  else
#    define Basic_PAUSE Basic_PAUSE_EI_stdcall
#  endif
#endif //MODE_IM2


extern void Basic_RANDOMIZE (CARDINAL seed);

extern SHORTCARD Basic_RND (SHORTCARD min, SHORTCARD max);
extern CARDINAL Basic_RNDW (CARDINAL min, CARDINAL max);
extern SHORTINT Basic_SGN (SHORTINT x);

extern void Basic_BEEP_DI (CARDINAL ms, SHORTINT freq);
extern void Basic_BEEP_EI (CARDINAL ms, SHORTINT freq);
#if defined (MODE_DI) || defined (MODE_DI_inline)
#  define Basic_BEEP Basic_BEEP_DI
#endif //MODE_DI
#if defined (MODE_IM1) || defined (MODE_IM1_inline)
#  define Basic_BEEP Basic_BEEP_EI
#endif //MODE_IM1
#if defined (MODE_IM2) || defined (MODE_IM2_inline)
#  define Basic_BEEP Basic_BEEP_EI
#endif //MODE_IM2

extern CHAR Basic_INKEY (void);

#define Basic_FONT(fontAddr) (*(unsigned*) (0x5C36) = (fontAddr - 256))
#define Basic_UDG(udgAddr) (*(unsigned*) (0x5C7B) = udgAddr)
#define Basic_Reset() __asm RST 0 __endasm

#define Basic_DEFDATA(title, size) if (size <= 127) { __asm ld hl,__id__(__hash__).+8 \
    ld   (_##title),hl \
    jr   2+.+size \
    __endasm; \
  } else { __asm ld hl,__id__(__hash__).+9 \
    ld   (_##title),hl \
    jp   3+.+size \
  __endasm; \
  }
  
#define Basic_DEFDATAREL(title, size) if (size <= 127) { __asm xor a \
    inc  a \
    call 0x1FC6 \
    ld   de,__id__(__hash__)9 \
    add  hl,de \
    ld   (_##title),hl \
    jr   2+.+size \
    __endasm; \
  } else { __asm xor a \
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
#define Basic_DATAW(w) __asm .dw w __endasm
#define Basic_DATAW1(w) __asm .dw w __endasm
#define Basic_DATAW2(w1,w2) __asm .dw w1,w2 __endasm
#define Basic_DATAW3(w1,w2,w3) __asm .dw w1,w2,w3 __endasm
#define Basic_DATAW4(w1,w2,w3,w4) __asm .dw w1,w2,w3,w4 __endasm
#define Basic_DATAW5(w1,w2,w3,w4,w5) __asm .dw w1,w2,w3,w4,w5 __endasm
#define Basic_DATAW6(w1,w2,w3,w4,w5,w6) __asm .dw w1,w2,w3,w4,w5,w6 __endasm
#define Basic_DATAW7(w1,w2,w3,w4,w5,w6,w7) __asm .dw w1,w2,w3,w4,w5,w6,w7 __endasm
#define Basic_DATAW8(w1,w2,w3,w4,w5,w6,w7,w8) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8 __endasm
#define Basic_DATAW9(w1,w2,w3,w4,w5,w6,w7,w8,w9) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9 __endasm
#define Basic_DATAW10(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10 __endasm
#define Basic_DATAW11(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11 __endasm
#define Basic_DATAW12(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12 __endasm
#define Basic_DATAW13(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13 __endasm
#define Basic_DATAW14(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14 __endasm
#define Basic_DATAW15(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15 __endasm
#define Basic_DATAW16(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16 __endasm
#define __arg_killer__(a)
#define Basic_DATASTR(str, str__len)	__asm .ascii __arg_killer__ str __endasm
#define Basic_DATASTRZ(str, str__len)	__asm .ascii __arg_killer__ str \
  .db 0x00 \
  __endasm

extern void Basic_Quit_DI  (void);
extern void Basic_Quit_IM1 (void);
extern void Basic_Quit_IM2 (void);

#ifdef MODE_DI
#  define Basic_Quit Basic_Quit_DI
#endif //MODE_DI
#ifdef MODE_DI_inline
#  define Basic_Quit() __asm         \
     LD   HL, __id__(__hash__)0x2758 \
     EXX                             \
     LD   IY, __id__(__hash__)0x5C3A \
     EI                              \
  __endasm
#endif //MODE_DI_inline

#ifdef MODE_IM1
#  define Basic_Quit Basic_Quit_IM1
#endif //MODE_IM1
#ifdef MODE_IM1_inline
#  define Basic_Quit() __asm         \
     LD   HL, __id__(__hash__)0x2758 \
     EXX                             \
     LD   IY, __id__(__hash__)0x5C3A \
  __endasm
#endif //MODE_IM1_inline

#ifdef MODE_IM2
#  define Basic_Quit Basic_Quit_IM2
#endif //MODE_IM2
#ifdef MODE_IM2_inline
#  define Basic_Quit() __asm        \
     DI                             \
     LD   HL,__id__(__hash__)0x2758 \
     EXX                            \
     LD   IY,__id__(__hash__)0x5C3A \
     IM   1                         \
     EI                             \
   __endasm
#endif //MODE_IM2_inline

extern void Basic__IM2ADR (void);
#define Basic_IM2PROC(adr) __asm DI __endasm; \
  Basic_POKEW((int)Basic__IM2ADR+1, (int)adr); __asm EI __endasm
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
#define PAINT Basic_PAINT
#define PRCHAR Basic_PRCHAR
#define PLOT Basic_PLOT
#define POINT Basic_POINT
#define ATTR Basic_ATTR
#define DRAW Basic_DRAW
#define CIRCLE Basic_CIRCLE
#define CIRCLEW Basic_CIRCLEW
#define CIRCLEROM Basic_CIRCLEROM
#define PRINT Basic_PRINT
#define PRWORD Basic_PRWORD
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
