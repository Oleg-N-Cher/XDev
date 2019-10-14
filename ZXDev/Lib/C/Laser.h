/*-----------------------------------*/
/* LASER BASIC v3.17 for Ofront/SDCC */
/* Adapted to Ofront by Oleg N. Cher */
/*  VEDAsoft Oberon Club, 2012-2015  */
/* Thanx to Raydac & Michailov (HVG) */
/*-----------------------------------*/

#ifndef Laser__h
#define Laser__h

#include "Basic.h"

extern unsigned int SFSTRT; /* Sprite file start address */
extern unsigned int SF_END; /* Sprite file end address */
extern unsigned int SCRL_B; /* Scroll buffer address */

#define Laser_InitSprites(adr, size) __asm   \
  ld hl,__id__(__hash__)adr + size           \
  ld (__id__(__hash__)_SF_END),hl            \
  ld hl,__id__(__hash__)adr                  \
  ld (__id__(__hash__)_SFSTRT),hl            \
  __endasm;
  //SFSTRT = adr; SF_END = adr + size; _InitSprites()
#define Laser_InitSpritesEx(adr, size) __asm \
  ld hl,(__id__(__hash__)_##adr)             \
  ld (__id__(__hash__)_SFSTRT),hl            \
  push hl                                    \
  ld de,__id__(__hash__)size                 \
  add hl,de                                  \
  ld (__id__(__hash__)_SF_END),hl            \
  pop hl                                     \
  __endasm;
#define Laser_InitSpritesAr(adr, size) __asm \
  ld hl,__id__(__hash__)_##adr + size - 1    \
  ld (__id__(__hash__)_SF_END),hl            \
  ld hl,__id__(__hash__)_##adr               \
  ld (__id__(__hash__)_SFSTRT),hl            \
  __endasm;

#define Laser_InitScroll(scrollBuf) __asm \
  ld hl,__id__(__hash__)scrollBuf \
  ld (__id__(__hash__)_SCRL_B),hl \
  __endasm;

extern void Laser_CalcSpritesOffset (void);
/* Functions for screen windows processing */
extern void Laser_INVV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_MIRV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_MARV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SETV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_CLSV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WL1V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WR1V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WL4V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WR4V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WL8V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WR8V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SL1V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SR1V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SL4V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SR4V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SL8V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_SR8V (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_WCRV (signed char col, signed char row, signed char len, signed char hgt, signed char npx);
extern void Laser_SCRV (signed char col, signed char row, signed char len, signed char hgt, signed char npx);
extern void Laser_AWLV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_ASLV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_AWRV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_ASRV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_ATUV (signed char col, signed char row, signed char len, signed char hgt);
extern void Laser_ATDV (signed char col, signed char row, signed char len, signed char hgt);

/* Functions for sprites manipulations */
extern void Laser_CLSM (unsigned char spN) __z88dk_fastcall __preserves_regs(iyl,iyh);
extern void Laser_INVM (unsigned char spN) __z88dk_fastcall __preserves_regs(iyl,iyh);
extern void Laser_PTBL (signed char col, signed char row, unsigned char spN) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser_PTOR (signed char col, signed char row, unsigned char spN) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser_PTXR (signed char col, signed char row, unsigned char spN) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser_PTND (signed char col, signed char row, unsigned char spN) __z88dk_callee __preserves_regs(iyl,iyh);
extern void Laser_WL1M (unsigned char spN);
extern void Laser_WR1M (unsigned char spN);
extern void Laser_WL4M (unsigned char spN);
extern void Laser_WR4M (unsigned char spN);
extern void Laser_WL8M (unsigned char spN);
extern void Laser_WR8M (unsigned char spN);
extern void Laser_SL1M (unsigned char spN);
extern void Laser_SR1M (unsigned char spN);
extern void Laser_SL4M (unsigned char spN);
extern void Laser_SR4M (unsigned char spN);
extern void Laser_SL8M (unsigned char spN);
extern void Laser_SR8M (unsigned char spN);
extern void Laser_WCRM (unsigned char spN, signed char npx);
extern void Laser_SCRM (unsigned char spN, signed char npx);
extern void Laser_ATOF (void) __preserves_regs(a,b,c,d,e,iyl,iyh);
extern void Laser_ATON (void) __preserves_regs(b,c,d,e,h,l,iyl,iyh);
extern void Laser_GTBL (signed char col, signed char row, unsigned char spN);
extern void Laser_GTOR (signed char col, signed char row, unsigned char spN);
extern void Laser_GTXR (signed char col, signed char row, unsigned char spN);
extern void Laser_GTND (signed char col, signed char row, unsigned char spN);
extern void Laser_PMBL (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_PMOR (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_PMXR (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_PMND (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_PMAT (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_GMBL (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_GMOR (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_GMXR (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_GMND (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_GMAT (signed char col, signed char row, unsigned char spD, unsigned char spS);
extern void Laser_PWBL (signed char col, signed char row, unsigned char spN,
                        signed char spCol, signed char spRow, signed char len, signed char hgt);
extern void Laser_PWOR (signed char col, signed char row, unsigned char spN,
                        signed char spCol, signed char spRow, signed char len, signed char hgt);
extern void Laser_PWXR (signed char col, signed char row, unsigned char spN,
                        signed char spCol, signed char spRow, signed char len, signed char hgt);
extern void Laser_PWND (signed char col, signed char row, unsigned char spN,
                        signed char spCol, signed char spRow, signed char len, signed char hgt);
extern void Laser_SPNM (unsigned char sp1, unsigned char sp2) __z88dk_callee;
#define Laser__init()

/* Functions for screen windows processing */
#define INVV Laser_INVV
#define MIRV Laser_MIRV
#define MARV Laser_MARV
#define SETV Laser_SETV
#define CLSV Laser_CLSV
#define WL1V Laser_WL1V
#define WR1V Laser_WR1V
#define WL4V Laser_WL4V
#define WR4V Laser_WR4V
#define WL8V Laser_WL8V
#define WR8V Laser_WR8V
#define SL1V Laser_SL1V
#define SR1V Laser_SR1V
#define SL4V Laser_SL4V
#define SR4V Laser_SR4V
#define SL8V Laser_SL8V
#define SR8V Laser_SR8V
#define WCRV Laser_WCRV
#define SCRV Laser_SCRV
#define AWLV Laser_AWLV
#define ASLV Laser_ASLV
#define AWRV Laser_AWRV
#define ASRV Laser_ASRV
#define ATUV Laser_ATUV
#define ATDV Laser_ATDV

/* Functions for sprites manipulations */
#define CLSM Laser_CLSM
#define INVM Laser_INVM
#define PTBL Laser_PTBL
#define PTOR Laser_PTOR
#define PTXR Laser_PTXR
#define PTND Laser_PTND
#define WL1M Laser_WL1M
#define WR1M Laser_WR1M
#define WL4M Laser_WL4M
#define WR4M Laser_WR4M
#define WL8M Laser_WL8M
#define WR8M Laser_WR8M
#define SL1M Laser_SL1M
#define SR1M Laser_SR1M
#define SL4M Laser_SL4M
#define SR4M Laser_SR4M
#define SL8M Laser_SL8M
#define SR8M Laser_SR8M
#define WCRM Laser_WCRM
#define SCRM Laser_SCRM
#define ATOF Laser_ATOF
#define ATON Laser_ATON
#define GTBL Laser_GTBL
#define GTOR Laser_GTOR
#define GTXR Laser_GTXR
#define GTND Laser_GTND
#define PMBL Laser_PMBL
#define PMOR Laser_PMOR
#define PMXR Laser_PMXR
#define PMND Laser_PMND
#define PMAT Laser_PMAT
#define GMBL Laser_GMBL
#define GMOR Laser_GMOR
#define GMXR Laser_GMXR
#define GMND Laser_GMND
#define GMAT Laser_GMAT
#define PWBL Laser_PWBL
#define PWOR Laser_PWOR
#define PWXR Laser_PWXR
#define PWND Laser_PWND
#define SPNM Laser_SPNM

#endif
