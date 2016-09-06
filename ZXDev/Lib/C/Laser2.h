/*********************/
/*   LASER BASIC 2   */
/*  by Oleg N. Cher  */
/*   zx.oberon2.ru   */
/*********************/

#ifndef Laser2__h
#define Laser2__h

#include "Laser2Cfg.h"

#include "Basic.h"

extern unsigned int Laser2_SPRT_ADR;  // Sprite file start address

#define Laser2_InitSprites(adr, size) __asm   \
  ld hl,__id__(__hash__)adr                   \
  ld (__id__(__hash__)_Laser2_SPRT_ADR),hl    \
  __endasm;
  //SFSTRT = adr; SF_END = adr + size; _InitSprites()
#define Laser2_InitSpritesEx(adr, size) __asm \
  ld hl,(__id__(__hash__)_##adr)              \
  ld (__id__(__hash__)_Laser2_SPRT_ADR),hl    \
  __endasm;
#define Laser2_InitSpritesAr(adr, size) __asm \
  ld hl,__id__(__hash__)_##adr                \
  ld (__id__(__hash__)_Laser2_SPRT_ADR),hl    \
  __endasm;
  
// Functions for sprites manipulations

#ifdef OUT_OF_SCREEN
    extern void Laser2_PTBL_OUTSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
    extern void Laser2_PTOR_OUTSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
    extern void Laser2_PTND_OUTSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
    extern void Laser2_PTXR_OUTSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
#   define Laser2_PTBL Laser2_PTBL_OUTSCR
#   define Laser2_PTOR Laser2_PTOR_OUTSCR
#   define Laser2_PTND Laser2_PTND_OUTSCR
#   define Laser2_PTXR Laser2_PTXR_OUTSCR
#else // IN_SCREEN
    extern void Laser2_ATOF_INSCR (void);
    extern void Laser2_ATON_INSCR (void);
    extern void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
    extern void Laser2_PTOR_INSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
    extern void Laser2_PTND_INSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
    extern void Laser2_PTXR_INSCR (signed char col, signed char row, unsigned char spn) __preserves_regs(iyl, iyh);
#   define Laser2_ATOF Laser2_ATOF_INSCR
#   define Laser2_ATON Laser2_ATON_INSCR
#   define Laser2_PTBL Laser2_PTBL_INSCR
#   define Laser2_PTOR Laser2_PTOR_INSCR
#   define Laser2_PTND Laser2_PTND_INSCR
#   define Laser2_PTXR Laser2_PTXR_INSCR
#endif

#define Laser2__init()

#endif
