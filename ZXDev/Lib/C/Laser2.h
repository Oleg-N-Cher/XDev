/***************************/
/* LASER 2  Graphic Engine */
/*  Coded by Oleg N. Cher  */
/*   zx.oberon2.ru/forum   */
/***************************/

#ifndef Laser2__h
#define Laser2__h

#include "Laser2Cfg.h"
#include "Basic.h"

extern unsigned int _Laser2_SCRL_BUF;  // Scroll buffer start address
extern unsigned int _Laser2_SPRT_ADR;  // Sprite file start address

// New procedures:

#define Laser2_SCRL(adr) __asm              \
  ld hl,__id__(__hash__)adr                 \
  ld (__id__(__hash__)__Laser2_SCRL_BUF),hl \
  __endasm;
#define Laser2_SCRLv(adr, size) __asm       \
  ld hl,(__id__(__hash__)_##adr)            \
  ld (__id__(__hash__)__Laser2_SCRL_BUF),hl \
  __endasm;
#define Laser2_SCRLa(adr, size) __asm       \
  ld hl,__id__(__hash__)_##adr              \
  ld (__id__(__hash__)__Laser2_SCRL_BUF),hl \
  __endasm;
#define Laser2_SPRT(adr) __asm              \
  ld hl,__id__(__hash__)adr                 \
  ld (__id__(__hash__)__Laser2_SPRT_ADR),hl \
  __endasm;
#define Laser2_SPRTv(adr, size) __asm       \
  ld hl,(__id__(__hash__)_##adr)            \
  ld (__id__(__hash__)__Laser2_SPRT_ADR),hl \
  __endasm;
#define Laser2_SPRTa(adr, size) __asm       \
  ld hl,__id__(__hash__)_##adr              \
  ld (__id__(__hash__)__Laser2_SPRT_ADR),hl \
  __endasm;

// Synonyms for the new procedures:

#define Laser2_InitScroll    Laser2_SCRL
#define Laser2_InitScrollV   Laser2_SCRLv
#define Laser2_InitScrollA   Laser2_SCRLa
#define Laser2_InitSprites   Laser2_SPRT
#define Laser2_InitSpritesV  Laser2_SPRTv
#define Laser2_InitSpritesA  Laser2_SPRTa
#define Laser2_SetScreen     Laser2_SCRN

// Sprite engine (in OUT_OF_SCREEN the coords can be outside the screen):

#ifdef OUT_OF_SCREEN
    extern void Laser2_ATOF_OUTSCR (void) __preserves_regs(b,c,d,e,h,l,iyl,iyh);
    extern void Laser2_ATON_OUTSCR (void) __preserves_regs(b,c,d,e,h,l,iyl,iyh);
    extern void Laser2_GTBL_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTND_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTNV_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTOR_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTXR_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_SCRN_OUTSCR (unsigned char hbyteadr) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
    extern void Laser2_PTBL_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTND_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTNV_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTOR_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTXR_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
#   define Laser2_ATOF       Laser2_ATOF_OUTSCR
#   define Laser2_ATON       Laser2_ATON_OUTSCR
#   define Laser2_GTBL       Laser2_GTBL_OUTSCR
#   define Laser2_GTND       Laser2_GTND_OUTSCR
#   define Laser2_GTNV       Laser2_GTNV_OUTSCR
#   define Laser2_GTOR       Laser2_GTOR_OUTSCR
#   define Laser2_GTXR       Laser2_GTXR_OUTSCR
#   define Laser2_SCRN(adr)  Laser2_SCRN_OUTSCR((unsigned int)(adr)>>8)
#   define Laser2_PTBL       Laser2_PTBL_OUTSCR
#   define Laser2_PTND       Laser2_PTND_OUTSCR
#   define Laser2_PTNV       Laser2_PTNV_OUTSCR
#   define Laser2_PTOR       Laser2_PTOR_OUTSCR
#   define Laser2_PTXR       Laser2_PTXR_OUTSCR
#else // IN_SCREEN
    extern void Laser2_ATOF_INSCR (void) __preserves_regs(b,c,d,e,h,l,iyl,iyh);
    extern void Laser2_ATON_INSCR (void) __preserves_regs(b,c,d,e,h,l,iyl,iyh);
    extern void Laser2_GTBL_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTOR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTND_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTNV_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_GTXR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_SCRN_INSCR (unsigned char hbyteadr) __z88dk_fastcall __preserves_regs(b,c,d,e,h,iyl,iyh);
    extern void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTOR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTND_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTNV_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
    extern void Laser2_PTXR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee __preserves_regs(iyl,iyh);
#   define Laser2_ATOF       Laser2_ATOF_INSCR
#   define Laser2_ATON       Laser2_ATON_INSCR
#   define Laser2_GTBL       Laser2_GTBL_INSCR
#   define Laser2_GTND       Laser2_GTND_INSCR
#   define Laser2_GTNV       Laser2_GTNV_INSCR
#   define Laser2_GTOR       Laser2_GTOR_INSCR
#   define Laser2_GTXR       Laser2_GTXR_INSCR
#   define Laser2_SCRN(adr)  Laser2_SCRN_INSCR((unsigned int)(adr)>>8)
#   define Laser2_PTBL       Laser2_PTBL_INSCR
#   define Laser2_PTND       Laser2_PTND_INSCR
#   define Laser2_PTNV       Laser2_PTNV_INSCR
#   define Laser2_PTOR       Laser2_PTOR_INSCR
#   define Laser2_PTXR       Laser2_PTXR_INSCR
#endif
extern void Laser2_INVM (unsigned char spn) __z88dk_fastcall __preserves_regs(iyl,iyh);

// Screen windows processing (coordinates CANNOT be outside the screen):

extern void Laser2_CLSV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_INVV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_MIRV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SDNV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt, unsigned char npx) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SUPV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt, unsigned char npx) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SL1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SL4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SL8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SR1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SR4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SR8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WL1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WL4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WL8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WR1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WR4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WR8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_WU1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);

// Attribute windows processing (coordinates CANNOT be outside the screen):

extern void Laser2_AWLV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_AWRV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_ATUV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_ATDV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_MARV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser2_SETV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee __preserves_regs(iyl,iyh);


#define Laser2__init()

#endif
