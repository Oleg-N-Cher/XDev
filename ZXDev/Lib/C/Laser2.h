/*********************/
/*   LASER BASIC 2   */
/*  by Oleg N. Cher  */
/*   zx.oberon2.ru   */
/*********************/

#ifndef Laser2__h
#define Laser2__h


#include "Basic.h"

extern unsigned int Laser2_SPRT_ADR;  // Sprite file start address

#define Laser_InitSprites(adr, size) __asm   \
  ld hl,__id__(__hash__)adr                  \
  ld (__id__(__hash__)_Laser2_SPRT_ADR),hl   \
  __endasm;
  //SFSTRT = adr; SF_END = adr + size; _InitSprites()
#define Laser_InitSpritesEx(adr, size) __asm \
  ld hl,(__id__(__hash__)_##adr)             \
  ld (__id__(__hash__)_Laser2_SPRT_ADR),hl   \
  __endasm;

// Functions for sprites manipulations

extern void Laser2_PTBL (signed char col, signed char row, unsigned char spn) __preserves_regs(b, c, iyl, iyh);
extern void Laser2_PTOR (signed char col, signed char row, unsigned char spn) __preserves_regs(b, c, iyl, iyh);
extern void Laser2_PTND (signed char col, signed char row, unsigned char spn) __preserves_regs(b, c, iyl, iyh);
extern void Laser2_PTXR (signed char col, signed char row, unsigned char spn) __preserves_regs(b, c, iyl, iyh);

#endif
