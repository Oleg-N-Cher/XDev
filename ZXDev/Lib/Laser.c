/* ------------------------------- */
/* LASER BASIC for SDCC  >>> v3.17 */
/* Adapted to SDCC by Oleg N. Cher */
/*    (Vedanta software), 2011     */
/*    Thanks to Michailov (HVG)    */
/* ------------------------------- */

#include "SYSTEM.h"
#include "Rsrc.h"
#include "Laser.h"

/*interface*/

export void Laser_Init (void);
/* Functions for screen windows processing */
export void Laser_INVV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_MIRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_MARV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SETV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_CLSV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_SR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_WCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx);
export void Laser_SCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx);
export void Laser_AWLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_ASLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_AWRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_ASRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_ATUV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
export void Laser_ATDV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);

/* Functions for sprites manipulations */
export void Laser_CLSM (SHORTCARD spN);
export void Laser_INVM (SHORTCARD spN);
export void Laser_PTBL (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_PTOR (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_PTXR (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_PTND (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_WL1M (SHORTCARD spN);
export void Laser_WR1M (SHORTCARD spN);
export void Laser_WL4M (SHORTCARD spN);
export void Laser_WR4M (SHORTCARD spN);
export void Laser_WL8M (SHORTCARD spN);
export void Laser_WR8M (SHORTCARD spN);
export void Laser_SL1M (SHORTCARD spN);
export void Laser_SR1M (SHORTCARD spN);
export void Laser_SL4M (SHORTCARD spN);
export void Laser_SR4M (SHORTCARD spN);
export void Laser_SL8M (SHORTCARD spN);
export void Laser_SR8M (SHORTCARD spN);
export void Laser_WCRM (SHORTCARD spN, SHORTINT npx);
export void Laser_SCRM (SHORTCARD spN, SHORTINT npx);
export void Laser_ATOF (void);
export void Laser_ATON (void);
export void Laser_GTBL (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_GTOR (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_GTXR (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_GTND (SHORTINT col, SHORTINT row, SHORTCARD spN);
export void Laser_PMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_PMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_PMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_PMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_PMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_GMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_GMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_GMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_GMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_GMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
export void Laser_PWBL (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
export void Laser_PWOR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
export void Laser_PWXR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
export void Laser_PWND (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);

/*implementation*/

/*================================== Header ==================================*/

/* Спрайты хранятся в памяти в следующем формате:
Байт 1 - номер спрайта.
Байт 2 - младший байт адреса следующего
спрайта.
Байт 3 - старший байт адреса следующего
спрайта.
Байт 4 - длина спрайта.
Байт 5 - высота спрайта.
8*HGT*LEN - данные о состоянии
пикселей.
HGT*LEN - атрибуты.
  ИТОГО: 9*HGT*LEN+5 байтов.
*/
/* This is C realization of Set sprite relocs ===

static typedef struct Sprite {
  SYSTEM_BYTE sprN;
  struct Sprite *sprNext;
  SYSTEM_BYTE sprLen;
  SYSTEM_BYTE sprHgt;
};

void Laser_Init (SYSTEM_ADDRESS sprAddr, SYSTEM_ADDRESS sprEnd)
{
__asm
  LD   L,4(IX)
  LD   H,5(IX)
  LD   (#SFSTRT$),HL
  LD   L,6(IX)
  LD   H,7(IX)
  LD   (#SF_END$),HL
__endasm;
  {
    struct Sprite *sprPtr; sprPtr = (struct Sprite*)sprAddr;
    while ((sprPtr->sprN) != 0) {
      SYSTEM_ADDRESS sprSize;
      sprSize = (SYSTEM_ADDRESS)(sprPtr->sprHgt) *
                (SYSTEM_ADDRESS)(sprPtr->sprLen) * 9 + 5;
      sprPtr->sprNext = (struct Sprite*)((SYSTEM_ADDRESS)sprPtr + sprSize);
      sprPtr = sprPtr->sprNext;
    }
  }
}
*/
void Laser_Init (void)
{
__asm
  PUSH IX      // IX is a calle-saves register (see SDCC tracker #3567945)
  LD   HL,#scrollBuf
  LD   (#SCRL_B$),HL
  LD   HL,#sprEnd
  LD   (#SF_END$),HL
  LD   HL,#sprAddr
  LD   (#SFSTRT$),HL
/* Set sprite relocs (see Laser Basic sprite format specifications) */
  PUSH HL
  POP  IX      //  struct Sprite *sprPtr; sprPtr = (struct Sprite*)sprAddr;
SET_ADDR$:     // while ((sprPtr->sprN) != 0) {
  LD   A,0(IX)
  OR   A
  JR   Z,SPREXIT$
  LD   E,3(IX)
  LD   D,#0    // SYSTEM_ADDRESS sprSize;
  LD   L,D
  LD   H,D /* LH,DE = sprLen */
  LD   B,4(IX) /* B = sprHgt */
  // sprSize = (SYSTEM_ADDRESS)(sprPtr->sprLen) *
  //           (SYSTEM_ADDRESS)(sprPtr->sprHgt) * 9 + 5;
SPRMULT$:
  ADD  HL,DE
  DJNZ SPRMULT$ /* HL = sprLen * sprHgt */
  LD   E,L
  LD   D,H
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,DE
  LD   DE,#5
  ADD  HL,DE
  PUSH IX
  POP  DE
  ADD  HL,DE
  LD   1(IX),L // sprPtr->sprNext = (struct Sprite*)((SYSTEM_ADDRESS)sprPtr + sprSize);
  LD   2(IX),H
  PUSH HL
  POP  IX      // sprPtr = sprPtr->sprNext;
  JR   SET_ADDR$
    // }
SPREXIT$:  // }
  POP  IX
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
/*-----------------------------------------*/
/* Functions for screen windows processing */
/*-----------------------------------------*/
void Laser_INVV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Inverts the window */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL INVV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_MIRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Mirroring the window */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL MIRV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_MARV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Mirroring the window attributes */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL MARV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SETV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Sets the attributes of the window */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SETV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_CLSV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Clears the attributes of the window */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL CLSV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window left by 1 pixel circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL WL1V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window right by 1 pixel circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL WR1V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window left by 4 pixels circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL WL4V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window right by 4 pixels circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL WR4V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window left by 8 pixels circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL WL8V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window right by 8 pixels circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL WR8V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window left by 1 pixel */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SL1V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window right by 1 pixel */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SR1V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window left by 4 pixels */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SL4V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window right by 4 pixels */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SR4V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window left by 8 pixels */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SL8V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window right by 8 pixels */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL SR8V$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx)
/* Scrolls the window by npx pixels vertically (+Up, -Down) and circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  LD   A,8(IX)
  CALL WCRV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx)
/* Scrolls the window by npx pixels vertically (+Up, -Down) */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  LD   A,8(IX)
  CALL SCRV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_AWLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window attributes left circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL AWLV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ASLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window attributes left */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL ASLV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_AWRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window attributes right circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL AWRV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ASRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window attributes right */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL ASRV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATUV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window attributes up circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL ATUV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATDV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt)
/* Scrolls the window attributes down circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  LD   L,6(IX)
  LD   H,7(IX)
  CALL ATDV$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
/*-------------------------------------*/
/* Functions for sprites manipulations */
/*-------------------------------------*/
void Laser_CLSM (SHORTCARD spN)
/* Clears the sprite */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL CLSM$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_INVM (SHORTCARD spN)
/* Inverts the sprite */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL INVM$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTBL (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL PTBL$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTOR (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL PTOR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTXR (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL PTXR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTND (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL PTND$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL1M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL WL1M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR1M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL WR1M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL4M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL WL4M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR4M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL WR4M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL8M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL WL8M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR8M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL WR8M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL1M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL SL1M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR1M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL SR1M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL4M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL SL4M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR4M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL SR4M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL8M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL SL8M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR8M (SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL SR8M$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WCRM (SHORTCARD spN, SHORTINT npx)
/* Scrolls the sprite by npx pixels vertically (+Up, -Down) and circularly */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   B,5(IX)
  CALL WCRM$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SCRM (SHORTCARD spN, SHORTINT npx)
/* Scrolls the sprite by npx pixels vertically (+Up, -Down) */
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   B,5(IX)
  CALL SCRM$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATOF (void)
{
__asm
  JP   ATOF$
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATON (void)
{
__asm
  JP   ATON$
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTBL (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL GTBL$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTOR (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL GTOR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTXR (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL GTXR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTND (SHORTINT col, SHORTINT row, SHORTCARD spN)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  CALL GTND$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   C,6(IX) /* Dest sprite number */
  LD   B,7(IX) /* Source sprite number */
  CALL PMND$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   C,6(IX) /* Dest sprite number */
  LD   B,7(IX) /* Source sprite number */
  CALL PMOR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   C,6(IX) /* Dest sprite number */
  LD   B,7(IX) /* Source sprite number */
  CALL PMXR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   C,6(IX) /* Dest sprite number */
  LD   B,7(IX) /* Source sprite number */
  CALL PMND$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   C,6(IX) /* Dest sprite number */
  LD   B,7(IX) /* Source sprite number */
  CALL PMAT$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   B,6(IX) /* Dest sprite number */
  LD   C,7(IX) /* Source sprite number */
  CALL GMBL$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   B,6(IX) /* Dest sprite number */
  LD   C,7(IX) /* Source sprite number */
  CALL GMOR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   B,6(IX) /* Dest sprite number */
  LD   C,7(IX) /* Source sprite number */
  CALL GMXR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   B,6(IX) /* Dest sprite number */
  LD   C,7(IX) /* Source sprite number */
  CALL GMND$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   E,4(IX) /* x */
  LD   D,5(IX) /* y */
  LD   B,6(IX) /* Dest sprite number */
  LD   C,7(IX) /* Source sprite number */
  CALL GMAT$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWBL (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* Screen col */
  LD   B,5(IX) /* Screen row */
  LD   A,6(IX) /* Sprite number */
  LD   E,7(IX) /* Sprite col */
  LD   D,8(IX) /* Sprite row */
  LD   L,7(IX) /* Sprite len */
  LD   H,8(IX) /* Sprite hgt */
  CALL PWBL$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWOR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* Screen col */
  LD   B,5(IX) /* Screen row */
  LD   A,6(IX) /* Sprite number */
  LD   E,7(IX) /* Sprite col */
  LD   D,8(IX) /* Sprite row */
  LD   L,7(IX) /* Sprite len */
  LD   H,8(IX) /* Sprite hgt */
  CALL PWOR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWXR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* Screen col */
  LD   B,5(IX) /* Screen row */
  LD   A,6(IX) /* Sprite number */
  LD   E,7(IX) /* Sprite col */
  LD   D,8(IX) /* Sprite row */
  LD   L,7(IX) /* Sprite len */
  LD   H,8(IX) /* Sprite hgt */
  CALL PWXR$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWND (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* Screen col */
  LD   B,5(IX) /* Screen row */
  LD   A,6(IX) /* Sprite number */
  LD   E,7(IX) /* Sprite col */
  LD   D,8(IX) /* Sprite row */
  LD   L,7(IX) /* Sprite len */
  LD   H,8(IX) /* Sprite hgt */
  CALL PWND$
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*    HOME VIDEO GAMES Ent.     */
/*        version 3.17          */
/*            1997              */
/* ---------------------------- */

/* Set video attrib */
#define SETV_A$ 0x5C8D

static void __Asm_Laser__ (void)
{
__asm
/* ---------------------------- */
SCRL_B$: .DW #0x5B00 /* Buffer vor vertical scroll */
SFSTRT$: .DW #0x0000 /* Sprite file start address */
SF_END$: .DW #0x0000 /* Sprite file end address */
//SETV_A$: .DW #0x5C8D /* Set video attrib */
SCR_AC$: .DW #0x4000
SCRA_A$: .DW #0x5800

/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*    HOME VIDEO GAMES Ent.     */
/*        version 3.17          */
/*            1997              */
/*          P A R T  1          */
/* ---------------------------- */
MARV$:
  NOP
LB_001$:
  LD   DE,#LB_052$
  LD   (#LB_050$+1+1),DE
  LD   (#LB_051$+1),DE
  LD   DE,#LB_049$
LB_002$:
  CALL LB_013$
  LD   DE,#LB_052$+2
  LD   (#LB_050$+1+1),DE
  LD   (#LB_051$+1),DE
  RET
AWLV$:
  CALL LB_058$
  RET  NC
  PUSH HL
  PUSH BC
  POP  HL
  POP  BC
  PUSH BC
  CALL LB_105$
  POP  BC
LB_003$:
  LD   A,B
  PUSH BC
  PUSH AF
  PUSH HL
  LD   B,#0x00
LB_004$:
  CALL LB_046$
  POP  HL
LB_005$:
  LD   DE,#0x0020
  OR   A
  ADC  HL,DE
  POP  AF
  POP  BC
  DEC  A
  RET  Z
  JR   LB_003$+1
ATUV$:
  CALL LB_064$
  CALL LB_068$
  CALL LB_058$
  RET  NC
LB_006$:
  CALL LB_007$
  LD   DE,(#SCRL_B$)
  EX   DE,HL
  LD   B,#0x00
  LDIR
  LD   HL,(#SCRL_B$)
  LD   (HL),#0x00
  RET
LB_007$:
  PUSH HL
  PUSH BC
  POP  HL
  POP  BC
  PUSH BC
  CALL LB_105$
  POP  BC
LB_008$:
  CALL LB_012$
  LD   A,B
LB_009$:
  DEC  A
  RET  Z
  PUSH BC
  PUSH HL
  LD   B,#0x00
LB_010$:
  LD   DE,#0x0020
  OR   A
LB_011$:
  ADC  HL,DE
  POP  DE
  PUSH HL
  LDIR
  POP  HL
  POP  BC
  JR   LB_009$
LB_012$:
  PUSH HL
  PUSH BC
  LD   B,#0x00
  LD   DE,(#SCRL_B$)
  LDIR
  POP  BC
  POP  HL
  RET
ATDV$:
  CALL LB_064$
  CALL LB_068$
  CALL LB_058$
  RET  NC
  LD   A,H
  DEC  A
  RET  Z
  ADD  A,B
  LD   B,A
  LD   A,#0x52
  LD   (#LB_011$+1),A
  CALL LB_006$
  LD   A,#0x5A
  LD   (#LB_011$+1),A
  RET
AWRV$:
  LD   DE,#LB_048$
LB_013$:
  LD   (#LB_004$+1),DE
  CALL AWLV$
LB_014$:
  LD   DE,#LB_046$
  LD   (#LB_004$+1),DE
  RET
ASRV$:
  LD   DE,#LB_047$
  LD   (#LB_004$+1),DE
  CALL AWLV$
  LD   DE,#LB_046$
  LD   (#LB_004$+1),DE
  RET
ASLV$:
  LD   DE,#LB_045$
  LD   (#LB_004$+1),DE
  CALL AWLV$
  LD   DE,#LB_046$
  LD   (#LB_004$+1),DE
  RET
WCRV$:
  JP   LB_015$+1
LB_015$:
  NOP
  CALL LB_068$
  LD   (#LB_069$),A
  OR   A
  RET  Z
  CALL LB_021$
  RET  NC
  SLA  B
  SLA  B
  SLA  B
  LD   A,(#LB_069$)
  BIT  7,A
  JR   Z,#LB_016$
  LD   A,H
  ADD  A,B
  LD   B,A
  DEC  B
  LD   A,(#LB_069$)
  NEG
  PUSH HL
  LD   HL,#0x0515
  LD   (#LB_018$),HL
  LD   HL,#LB_027$
  LD   (HL),#0x05
  POP  HL
LB_016$:
  SUB  H
  NEG
  LD   (#LB_015$),A
  PUSH BC
  PUSH HL
  CALL LB_023$
  POP  HL
  POP  BC
  LD   A,(#LB_069$)
  LD   E,C
  LD   D,B
  ADD  A,D
  LD   D,A
  LD   A,(#LB_015$)
LB_017$:
  PUSH BC
  PUSH DE
  PUSH HL
  PUSH AF
  CALL LB_029$
  POP  AF
  POP  HL
  POP  DE
  POP  BC
LB_018$:
  INC  D
  INC  B
  DEC  A
  JR   NZ,#LB_017$
  LD   A,(#LB_069$)
  BIT  7,A
LB_019$:
  JP   Z,#LB_032$
  PUSH HL
  LD   HL,#0x0414
  LD   (#LB_018$),HL
  POP  HL
LB_020$:
  CALL LB_032$
  LD  HL,#LB_027$
  LD  (HL),#0x04
  RET
SCRV$:
  CALL LB_068$
  PUSH HL
  LD   HL,#LB_030$
  LD   (#LB_019$+1),HL
  LD   (#LB_020$+1),HL
  POP  HL
  CALL LB_015$+1
  LD   HL,#LB_032$
  LD   (#LB_019$+1),HL
  LD   (#LB_020$+1),HL
  RET
LB_021$:
  CALL LB_058$
  RET  NC
  LD   A,(#LB_069$)
  SLA  H
  SLA  H
  SLA  H
  BIT  7,A
  JR   Z,#LB_022$
  NEG
LB_022$:
  SUB  H
  RET
  LD   E,B
  LD   D,C
  LD   A,#0x07
  AND  B
  LD   C,A
  LD   A,#0xC0
  AND  B
  RRCA
  RRCA
  RRCA
  OR   C
  SET  6,A
  LD   H,A
  LD   A,#0x38
  AND  B
  RLCA
  RLCA
  ADD  A,D
  LD   L,A
  LD   B,E
  LD   C,D
  RET
LB_023$:
  NOP
  LD   DE,(#SCRL_B$)
  LD   A,(#LB_069$)
  BIT  7,A
  JR   Z,#LB_024$
  NEG
LB_024$:
  LD   H,#0x00
  PUSH BC
  PUSH AF
  PUSH DE
  PUSH HL
  CALL LB_022$+3
  POP  BC
  POP  DE
  PUSH BC
LB_025$:
  NOP
  LDIR
LB_026$:
  NOP
  POP  HL
  POP  AF
  POP  BC
  DEC  A
  JR   Z,#LB_028$
LB_027$:
  INC  B
  JR   LB_024$+2
LB_028$:
  LD   HL,(#SCRL_B$)
  OR   A
  EX   DE,HL
  SBC  HL,DE
  LD   (#LB_069$+2),HL
  RET
LB_029$:
  PUSH HL
  PUSH DE
  CALL LB_022$+3
  POP  BC
  PUSH HL
  CALL LB_022$+3
  POP  DE
  POP  BC
  LD   B,#0x00
  LDIR
  RET
LB_030$:
  PUSH HL
  PUSH BC
  PUSH DE
  LD   HL,(#SCRL_B$)
  LD   BC,(#LB_069$+2)
  LD   D,H
  LD   E,L
  INC  DE
  DEC  BC
  LD   (HL),#0x00
  LD   A,B
  OR   C
  JR   Z,#LB_031$
  LDIR
LB_031$:
  POP  DE
  POP  BC
  POP  HL
LB_032$:
  PUSH HL
  LD   HL,#LB_025$
  LD   (HL),#0xEB
  LD   HL,#LB_026$
  LD   (HL),#0xEB
  POP  HL
  CALL LB_023$
  XOR  A
  LD   (#LB_023$),A
  LD   (#LB_025$),A
  LD   (#LB_026$),A
  RET
LB_033$:
  XOR  A
  LD   B,C
  RR   (HL)
  INC  HL
  DJNZ LB_033$+2
  RET
LB_034$:
  PUSH HL
  CALL LB_033$
  POP  HL
  RET  NC
  SET  7,(HL)
  NEG
  RET
LB_035$:
  LD   B,#0x00
  ADD  HL,BC
  DEC  HL
  XOR  A
  PUSH HL
  LD   B,C
LB_036$:
  RL   (HL)
  DEC  HL
  DJNZ LB_036$
  POP  HL
  RET
LB_037$:
  CALL LB_035$
  RET  NC
  SET  0,(HL)
  RET
SR1V$:
  LD   DE,#LB_033$
  JP   LB_056$
SL1V$:
  LD   DE,#LB_035$
  JP   LB_056$
WR1V$:
  LD   DE,#LB_034$
  JP   LB_056$
WL1V$:
  LD   DE,#LB_037$
  JP   LB_056$
SR4V$:
  PUSH HL
  LD   HL,#0x67ED
  LD   (#LB_033$+2),HL
  POP  HL
LB_038$:
  CALL SR1V$
  LD   HL,#0x1ECB
  LD   (#LB_033$+2),HL
  RET
SL4V$:
  PUSH HL
  LD   HL,#0x6FED
  LD   (#LB_036$),HL
  POP  HL
LB_039$:
  CALL SL1V$
  LD   HL,#0x16CB
  LD   (#LB_036$),HL
  RET
WR4V$:
  PUSH HL
  LD   HL,#0x67ED
  LD   (#LB_033$+2),HL
  POP  HL
  LD   DE,#LB_041$
LB_040$:
  CALL LB_056$
  JR   LB_038$+3
LB_041$:
  PUSH HL
  CALL LB_033$
  SLA  A
  SLA  A
  SLA  A
  SLA  A
  POP  HL
LB_042$:
  OR  (HL)
  LD  (HL),A
  RET
WL4V$:
  PUSH HL
  LD   HL,#0x6FED
  LD   (#LB_036$),HL
  POP  HL
  LD   DE,#LB_044$
LB_043$:
  CALL LB_056$
  JR   LB_039$+3
LB_044$:
  CALL LB_035$
  JR   LB_042$
SL8V$:
  LD   DE,#LB_045$
  JP   LB_056$
LB_045$:
  LD   D,H
  LD   E,L
  INC  HL
  DEC  C
  RET  Z
  LDIR
  DEC  HL
  LD   (HL),#0x00
  RET
WL8V$:
  LD   DE,#LB_046$
  JP   LB_056$
LB_046$:
  LD   A,(HL)
  CALL LB_045$
  LD   (DE),A
  RET
SR8V$:
  LD   DE,#LB_047$
  JP   LB_056$
LB_047$:
  DEC  C
  RET  Z
  ADD  HL,BC
  LD   D,H
  LD   E,L
  LD   A,(HL)
  DEC  HL
  LDDR
  INC  HL
  LD   (HL),#0x00
  RET
WR8V$:
  LD   DE,#LB_048$
  JP   LB_056$
LB_048$:
  CALL LB_047$
  LD   (DE),A
  RET
LB_049$:
  LD   E,L
  LD   D,H
  ADD  HL,BC
  DEC  HL
  EX   DE,HL
  SRL  C
  JR   NC,#LB_050$
  INC  C
LB_050$:
  LD   A,(HL)
  CALL LB_052$+2
  LD   A,(DE)
  PUSH BC
LB_051$:
  CALL LB_052$+2
  POP  AF
  LD   (DE),A
  LD   (HL),B
  DEC  DE
  INC  HL
  DEC  C
  JR   NZ,LB_050$
  RET
LB_052$:
  LD   B,A
  RET
  RLC  A
  RR   B
  RLC  A
  RR   B
  RLC  A
  RR   B
  RLC  A
  RR   B
  RLC  A
  RR   B
  RLC  A
  RR   B
  RLC  A
  RR   B
  RLC  A
  RR   B
  RET
MIRV$:
  LD   DE,#LB_049$
  JP   LB_056$
INVV$:
  LD   DE,#LB_053$
  JP   LB_056$
LB_053$:
  LD   B,C
  LD   A,(HL)
  CPL
  LD   (HL),A
  INC  HL
  DJNZ LB_053$+1
  RET
SETV$:
  CALL LB_064$
  CALL LB_068$
  PUSH HL
  PUSH BC
  POP  HL
  CALL LB_105$
  POP  BC
LB_054$:
  PUSH BC
  PUSH HL
  LD   A,(#SETV_A$)
  CALL LB_055$+1
  POP  HL
  LD   DE,#0x0020
  ADD  HL,DE
  POP  BC
  DJNZ LB_054$
  RET
CLSV$:
  LD   DE,#LB_055$
  JP   LB_056$
LB_055$:
  XOR  A
  LD   B,#0x00
  LD   (HL),A
  DEC  C
  RET  Z
  LD   D,H
  LD   E,L
  INC  DE
  LDIR
  RET
LB_056$:
  LD   (#LB_087$+1),DE
  CALL LB_064$
  CALL LB_068$
  XOR  A
LB_057$:
  CALL LB_086$
  LD  HL,#LB_084$
  LD  (#LB_087$+1),HL
  RET
LB_058$:
  LD   A,H
  ADD  A,B
  CP   #0x19
  RET  NC
  LD   A,L
  ADD  A,C
  CP   #0x21
  RET  NC
  LD   A,B
  CP   #0x18
  RET  NC
  LD   A,C
  CP   #0x20
  RET  NC
  SCF
  RET
LB_059$:
  LD   DE,#0x0000
  BIT  7,C
  JR   Z,#LB_060$
  LD   A,L
  ADD  A,C
  BIT  7,A
  JR   NZ,#LB_063$+2
  OR   A
  JR   Z,#LB_063$+2
  LD   L,A
  LD   A,C
  NEG
  LD   E,A
  LD   C,#0x00
LB_060$:
  BIT  7,B
  JR   Z,#LB_061$
  LD   A,H
  ADD  A,B
  BIT  7,A
  JR   NZ,#LB_063$+2
  OR   A
  JR   Z,#LB_063$+2
  LD   H,A
  LD   A,B
  NEG
  LD   D,A
  LD   B,#0x00
LB_061$:
  LD   A,C
  ADD  A,L
  CP   #0x21
  JR   C,#LB_062$
  LD   A,#0x20
  SUB  C
  JR   C,#LB_063$+2
  OR   A
  JR   Z,#LB_063$+2
  LD   L,A
LB_062$:
  LD   A,B
  ADD  A,H
  CP   #0x19
  JR   C,#LB_063$
  LD   A,#0x18
  SUB  B
  JR   C,#LB_063$+2
  OR   A
  JR   Z,#LB_063$+2
  LD   H,A
LB_063$:
  SCF
  RET
  OR   A
  RET
  PUSH BC
  CALL LB_146$
  POP  BC
LB_064$:
  CALL LB_058$
  JP   NC,#LB_059$
  LD   DE,#0x0000
  SCF
  RET
LB_065$:
  PUSH AF
  PUSH BC
  PUSH BC
  CALL LB_070$
  POP  HL
  JR   C,#LB_067$
LB_066$:
  POP  HL
  POP  HL
  RET
LB_067$:
  LD   E,H
  LD   D,#0x00
  LD   H,#0x00
  CALL LB_107$
  PUSH HL
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  ADD  HL,DE
  LD   DE,#0x0005
  ADD  HL,DE
  EX   DE,HL
  LD   HL,#0x0000
  OR   A
  SBC  HL,DE
  LD   B,H
  LD   C,L
  CALL RLCT$
  POP  BC
  POP  AF
  JP   LB_079$
LB_068$:
  PUSH AF
  LD   A,H
  OR   A
  JP   Z,#LB_066$
  LD   A,L
  OR   A
  JP   Z,#LB_066$
  POP  AF
  RET
LB_069$:
  NOP
  NOP
  NOP
  NOP
LB_070$:
  LD   HL,(#SFSTRT$)
  LD   (#LB_069$),A
LB_071$:
  LD   B,A
  LD   A,(HL)
  CP   #0x00
  JR   NZ,#LB_072$
  SCF
  RET
LB_072$:
  CP   B
  JR   NZ,#LB_073$
  PUSH HL
  INC  HL
  INC  HL
  INC  HL
  LD   C,(HL)
  INC  HL
  LD   B,(HL)
  INC  HL
  EX   DE,HL
  LD   H,B
  LD   L,C
  OR   A
  POP  BC
  RET
LB_073$:
  CALL LB_074$
  EX   DE,HL
  LD   A,(#LB_069$)
  JR   LB_071$
LB_074$:
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
  RET
LB_075$:
  NOP
  NOP
LB_076$:
  LD   HL,(#SFSTRT$)
  LD   A,(HL)
  CP   #0x00
  RET  Z
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
  EX   DE,HL
  PUSH HL
  ADD  HL,BC
  EX   DE,HL
  LD   (HL),D
  DEC  HL
  LD   (HL),E
  POP  HL
  JR   LB_076$+3
RLCT$:
  CALL LB_076$
  LD   HL,(#SF_END$)
  LD   DE,(#SFSTRT$)
  OR   A
  SBC  HL,DE
  INC  HL
  PUSH HL
  BIT  7,B
  JR   NZ,#LB_077$
  LD   HL,(#SF_END$)
  CALL LB_078$
  LD   (#SF_END$),DE
  POP  BC
  LDDR
  INC  DE
  LD   (#SFSTRT$),DE
  RET
LB_077$:
  LD   HL,(#SFSTRT$)
  CALL LB_078$
  LD   (#SFSTRT$),DE
  POP  BC
  LDIR
  DEC  DE
  LD   (#SF_END$),DE
  RET
LB_078$:
  PUSH HL
  ADD  HL,BC
  EX   DE,HL
  POP  HL
  RET
LB_079$:
  LD   D,A
  LD   A,B
  OR   A
  RET  Z
  LD   A,C
  OR   A
  RET  Z
  LD   A,D
  PUSH AF
  PUSH BC
  CALL LB_070$
  CALL NC,#LB_080$
  POP  BC
  POP  AF
  LD   HL,(#SF_END$)
  LD   (HL),A
  INC  HL
  PUSH BC
  PUSH HL
  LD   L,B
  LD   H,#0x00
  LD   D,H
  LD   E,L
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,DE
  LD   D,#0x00
  LD   E,C
  CALL LB_107$
  POP  DE
  ADD  HL,DE
  INC  HL
  INC  HL
  INC  HL
  INC  HL
  EX   DE,HL
  LD   (HL),E
  INC  HL
  LD   (HL),D
  INC  HL
  POP  BC
  LD   (HL),C
  INC  HL
  LD   (HL),B
  LD   (#SF_END$),DE
  XOR  A
  LD   (DE),A
  RET
LB_080$:
  PUSH BC
  LD   H,B
  LD   L,C
  CALL LB_074$
  POP  HL
  EX   DE,HL
  CALL LB_106$
  PUSH HL
  PUSH DE
  EX   DE,HL
  JR   LB_082$
LB_081$:
  CALL LB_074$
  EX   DE,HL
  PUSH HL
  OR   A
  SBC  HL,BC
  EX   DE,HL
  LD   (HL),D
  DEC  HL
  LD   (HL),E
  POP  HL
LB_082$:
  LD   A,(HL)
  OR   A
  JR   NZ,#LB_081$
  LD   HL,(#SF_END$)
  POP  DE
  OR   A
  SBC  HL,BC
  LD   (#SF_END$),HL
  ADD  HL,BC
  SBC  HL,DE
  LD   B,H
  LD   C,L
  LD   A,B
  OR   C
  POP  HL
  EX   DE,HL
  JR   Z,#LB_083$
  LDIR
LB_083$:
  XOR  A
  LD   (DE),A
  RET
LB_084$:
  PUSH AF
  LD   B,C
LB_085$:
  LD   A,(DE)
  OR   (HL)
  LD   (DE),A
  INC  DE
  INC  HL
  DJNZ LB_085$
  POP  AF
  RET
LB_086$:
  LD   (#LB_088$+1),A
  LD   A,#0xCD
  LD   (#LB_096$+1),A
  PUSH HL
LB_087$:
  LD   HL,#LB_084$
  LD   (#LB_096$+2),HL
  POP  HL
LB_088$:
  LD   A,#0x00
  CALL LB_093$
  XOR  A
  LD   (#LB_096$+1),A
  LD   (#LB_096$),A
  PUSH HL
  CALL LB_092$+3
  JP   LB_090$
LB_089$:
  PUSH HL
  LD   HL,#0xB0ED
  LD   (#LB_096$+2),HL
  POP  HL
  SCF
  RET
LB_090$:
  POP  HL
  JR   LB_089$
LB_091$:
  LD   HL,#LB_085$+1
  LD   (HL),#0xAE
LB_092$:
  CALL LB_151$
  LD   HL,#LB_085$+1
  LD   (HL),#0xB6
  RET
LB_093$:
  LD   (#LB_069$),A
  CALL LB_058$
  RET  NC
  LD   A,(#LB_069$)
  LD   (#LB_096$),A
  LD   (#LB_096$+4),A
  LD   (#LB_102$),A
  LD   (#LB_103$),A
  PUSH HL
  PUSH BC
  PUSH HL
  CALL LB_099$
  POP  BC
LB_094$:
  LD   A,#0x08
  PUSH HL
  PUSH BC
  LD   B,#0x00
LB_095$:
  PUSH HL
  PUSH BC
  PUSH AF
LB_096$:
  NOP
  NOP
  LDIR
  NOP
  POP  AF
  POP  BC
  POP  HL
  DEC  A
  JR   Z,#LB_097$
  INC  H
  JR   LB_095$
LB_097$:
  POP  BC
  POP  HL
  DEC  B
  JR   Z,#LB_098$
  LD   A,#0x20
  ADD  A,L
  LD   L,A
  JR   NC,#LB_094$
  LD   A,H
  AND  #0x58
  ADD  A,#0x08
  CP   #0x58
  JR   Z,#LB_098$
  LD   H,A
  JR   LB_094$
LB_098$:
  POP  HL
  POP  BC
  SCF
  RET
LB_099$:
  LD   A,#0x07
  AND  B
  RRCA
  RRCA
  RRCA
  OR   C
  LD   C,A
  LD   A,B
  AND  #0x18
  LD   B,A
  LD   HL,(#SCR_AC$)
  ADD  HL,BC
  RET
LB_100$:
  CALL LB_093$
  RET  NC
  CALL LB_105$
LB_101$:
  PUSH HL
  PUSH BC
  LD   B,#0x00
LB_102$:
  NOP
  LDIR
LB_103$:
  NOP
  POP  BC
  POP  HL
  DEC  B
  RET  Z
  LD   A,L
  ADD  A,#0x20
  JR   NC,#LB_104$
  INC  H
LB_104$:
  LD   L,A
  JR   LB_101$
LB_105$:
  LD   A,L
  LD   L,H
  LD   H,#0x00
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  ADD  A,L
  LD   L,A
  PUSH DE
  LD   DE,(#SCRA_A$)
  ADD  HL,DE
  POP  DE
  RET
LB_106$:
  AND  A
  SBC  HL,DE
  LD   B,H
  LD   C,L
  ADD  HL,DE
  EX   DE,HL
  RET
LB_107$:
  PUSH BC
  LD   B,#0x10
  LD   A,H
  LD   C,L
  LD   HL,#0x0000
LB_108$:
  ADD  HL,HL
  JR   C,#LB_110$
  RL   C
  RLA
  JR   NC,#LB_109$
  ADD  HL,DE
  JR   C,#LB_110$
LB_109$:
  DJNZ LB_108$
LB_110$:
  POP  BC
  RET
/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*          v. 3.17             */
/*      E N D  P A R T  1       */
/* ---------------------------- */



/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*    HOME VIDEO GAMES Ent.     */
/*        version 3.17          */
/*            1997              */
/*          P A R T  2          */
/* ---------------------------- */
LB_111$:
  LD   (#LB_179$),DE
  LD   A,B
  LD   B,C
  PUSH BC
  CALL LB_189$
  LD   BC,(#LB_075$)
  LD   B,#0x00
  LD   (#LB_212$),BC
  LD   BC,(#LB_075$)
  POP  AF
  PUSH BC
  PUSH AF
  LD   DE,(#LB_179$)
  JP   LB_210$
LB_112$:
  SET  4,A
ADJM$:
  CALL LB_063$+4
  LD   IX,(#LB_112$)
  LD   6(IX),D
  LD   7(IX),E
LB_113$:
  LD   2(IX),B
  LD   3(IX),C
  LD   4(IX),L
  LD   5(IX),H
  RET
ADJV$:
  CALL LB_064$
  LD   IX,(#LB_112$)
  JR   LB_113$
ISPR$:
  LD   B,H
  LD   C,L
  JP   LB_065$
SPRT$:
  LD   B,H
  LD   C,L
  JP   LB_079$
WSPR$:
  CALL LB_146$
  RET  C
  JP   LB_080$
DSPR$:
  PUSH HL
  PUSH AF
  CALL LB_146$
  POP  AF
  CALL WSPR$
  LD   DE,(#SF_END$)
  POP  HL
  OR   A
  SBC  HL,DE
  LD   B,H
  LD   C,L
  JP   RLCT$
MOVE$:
  LD   A,E
  PUSH DE
  PUSH HL
  PUSH BC
  CALL PTXR$
  POP  BC
  POP  HL
  LD   A,C
  ADD  A,L
  LD   C,A
  LD   A,B
  ADD  A,H
  LD   B,A
  POP  DE
  LD   A,D
  LD   HL,(#LB_112$)
  INC  HL
  INC  HL
  LD   (HL),B
  INC  HL
  LD   (HL),C
  PUSH DE
  CALL PTXR$
  POP  DE
  LD   HL,(#LB_112$)
  LD   BC,#0x000A
  ADD  HL,BC
  LD   (HL),D
  INC  HL
  LD   (HL),E
  RET
GMAT$:
  PUSH AF
  XOR  A
LB_114$:
  LD   (#LB_213$),A
  LD   (#LB_214$),A
  POP  AF
  JP   LB_111$
PMAT$:
  PUSH AF
  LD   A,#0xEB
  JR   LB_114$
GMBL$:
  CALL LB_202$
  JP   LB_187$
GMND$:
  CALL LB_206$
  JP   LB_187$
GMOR$:
  CALL LB_204$
  JP   LB_187$
GMXR$:
  CALL LB_207$
  JP   LB_187$
PMBL$:
  CALL LB_202$
  JP   LB_164$
PMND$:
  CALL LB_206$
  JP   LB_164$
PMOR$:
  CALL LB_204$
  JP   LB_164$
PMXR$:
  CALL LB_207$
  JP   LB_164$
AWLM$:
  LD   DE,#LB_046$
  JP   LB_143$
AWRM$:
  LD   DE,#LB_048$
  JP   LB_143$
ASLM$:
  LD   DE,#LB_045$
  JP   LB_143$
ASRM$:
  LD   DE,#LB_047$
  JP   LB_143$
ATUM$:
  CALL LB_189$
  LD   DE,(#LB_075$)
LB_115$:
  LD   C,E
  LD   B,D
  LD   A,E
  LD   (#LB_010$+1),A
  CALL LB_008$
  CALL LB_007$+3
  LD   HL,#LB_010$+1
  LD   (HL),#0x20
  RET
ATDM$:
  CALL LB_146$
  PUSH HL
  LD   L,C
  LD   H,B
  CALL LB_074$
  POP  HL
  EX   DE,HL
  LD   A,D
  LD   D,#0x00
  SBC  HL,DE
  LD   D,A
  LD   A,#0x52
  LD   (#LB_011$+1),A
  CALL LB_115$
  LD   A,#0x5A
  LD   (#LB_011$+1),A
  RET
WL1M$:
  LD   DE,#LB_037$
  JP   LB_156$
WR1M$:
  LD   DE,#LB_034$
  JP   LB_156$
SL8M$:
  LD   DE,#LB_045$
  JP   LB_156$
SR8M$:
  LD   DE,#LB_047$
  JP   LB_156$
WL8M$:
  LD   DE,#LB_046$
  JP   LB_156$
WR8M$:
  LD   DE,#LB_048$
  JP   LB_156$
SR4M$:
  LD   HL,#SR1M$
  LD   (#LB_038$+1),HL
  JP   LB_160$
SL4M$:
  LD   HL,#SL1M$
  LD   (#LB_039$+1),HL
  JP   LB_161$
WR4M$:
  LD   HL,#LB_156$
  LD   (#LB_040$+1),HL
  JP   LB_162$
WL4M$:
  LD   HL,#LB_156$
  LD   (#LB_043$+1),HL
  JP   LB_163$
LB_116$:
  NOP
  NOP
  NOP
SPNM$:
  NOP
  LD   A,B
  PUSH BC
  PUSH BC
  CALL LB_146$
  LD   (#LB_118$),HL
  POP  BC
  LD   A,C
  PUSH HL
  PUSH DE
  CALL LB_146$
  LD   A,(#LB_118$)
  CP   H
  JR   NZ,#LB_117$
  LD   A,(#LB_118$+1)
  CP   L
  JR   NZ,#LB_117$
  POP  HL
  POP  BC
  CALL LB_123$
  POP  BC
  JR   LB_118$+2
LB_117$:
  POP  HL
  POP  HL
  POP  HL
  RET
ATON$:
  PUSH HL
  LD   HL,#LB_100$+3
  LD   (HL),#0xD0
  POP  HL
  RET
ATOF$:
  PUSH HL
  LD   HL,#LB_100$+3
  LD   (HL),#0xC9
  POP  HL
  RET
LB_118$:
  NOP
  NOP
  LD   A,B
  PUSH BC
  CALL LB_189$
  POP  BC
  LD   A,C
  PUSH HL
  CALL LB_189$
  POP  DE
  EX   DE,HL
  LD   BC,(#LB_118$)
  PUSH BC
  LD   C,B
  LD   B,#0x00
  CALL LB_122$
  POP  BC
LB_119$:
  PUSH DE
  CALL LB_120$
  POP  DE
  DEC  DE
  DJNZ LB_119$
  RET
LB_120$:
  PUSH BC
  LD   BC,(#LB_118$)
  LD   A,B
  LD   B,C
  LD   C,A
LB_121$:
  LD   A,(HL)
  LD   (DE),A
  CALL LB_122$
  INC  HL
  INC  DE
  DJNZ LB_121$
  POP  BC
  RET
LB_122$:
  EX   DE,HL
  LD   A,B
  LD   B,#0x00
  ADD  HL,BC
  DEC  HL
  LD   B,A
  EX   DE,HL
  RET
LB_123$:
  PUSH BC
  LD   C,B
  LD   B,#0x00
  CALL LB_122$
  POP  BC
  LD   (#LB_118$),BC
LB_124$:
  PUSH DE
  CALL LB_125$
  POP  DE
  DEC  DE
  DJNZ LB_124$
  RET
LB_125$:
  PUSH BC
  LD   B,#0x08
  LD   A,#0x01
LB_126$:
  LD   (#LB_116$+2),A
  PUSH DE
  CALL LB_127$
  POP  DE
  INC  HL
  LD   A,(#LB_116$+2)
  SLA  A
  DJNZ LB_126$
  POP  BC
  RET
LB_127$:
  LD   A,C
  SLA  A
  SLA  A
  SLA  A
  LD   (#LB_116$),A
  DEC  HL
  LD   A,#0x01
LB_128$:
  RRCA
  LD   (#LB_116$+1),A
  JR   NC,#LB_129$
  INC  HL
LB_129$:
  AND  (HL)
  EX   DE,HL
  JR   Z,#LB_130$
  LD   A,(#LB_116$+2)
  OR   (HL)
  LD   (HL),A
LB_130$:
  PUSH BC
  LD   BC,(#LB_118$)
  LD   C,B
  LD   B,#0x00
  ADD  HL,BC
  EX   DE,HL
  POP  BC
  LD   A,(#LB_116$)
  DEC  A
  RET  Z
  LD   (#LB_116$),A
  LD   A,(#LB_116$+1)
  JR   LB_128$
DSPM$:
  PUSH BC
  LD   A,B
  CALL LB_146$
  EX   (SP),HL
  POP  AF
  PUSH AF
  PUSH AF
  PUSH DE
  LD   A,L
  CALL LB_146$
  POP  BC
  POP  AF
  PUSH DE
  PUSH BC
  PUSH AF
  POP  DE
  LD   A,D
  SLA  H
  SUB  H
  JR   NZ,#LB_137$
  LD   A,E
  SLA  L
  SUB  L
  JR   NZ,#LB_137$
  SRL  L
  SRL  H
  EX   (SP),HL
  POP  BC
  PUSH HL
  LD   H,#0x00
  LD   L,B
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  PUSH HL
  LD   A,C
  POP  BC
  POP  HL
  POP  DE
LB_131$:
  PUSH DE
  CALL LB_133$
  POP  DE
  CALL LB_133$
  DEC  BC
  PUSH AF
  LD   A,B
  OR   C
  JR   NZ,#LB_132$
  POP  AF
  JR   LB_138$
LB_132$:
  POP  AF
  JR   LB_131$
LB_133$:
  PUSH AF
  PUSH AF
  CALL LB_134$
  POP  AF
  DEC  A
  JR   NZ,#LB_133$+1
  POP  AF
  RET
LB_134$:
  LD   A,(DE)
  RRC  A
  RRC  A
  RRC  A
  RRC  A
  CALL LB_135$
  INC  HL
  CALL LB_135$
  INC  HL
  INC  DE
  RET
LB_135$:
  CALL LB_136$
  CALL LB_136$
  CALL LB_136$
LB_136$:
  RRCA
  RR   (HL)
  SRA  (HL)
  RET
LB_137$:
  POP  BC
  POP  BC
  POP  BC
  OR   A
  RET
LB_138$:
  POP  BC
  SRL  B
  SRL  C
LB_139$:
  CALL LB_140$
  DJNZ LB_139$
  SCF
  RET
LB_140$:
  PUSH DE
  CALL LB_141$
  POP  DE
LB_141$:
  PUSH BC
  LD   B,C
LB_142$:
  LD   A,(DE)
  LD   (HL),A
  INC  HL
  LD   (HL),A
  INC  HL
  INC  DE
  DJNZ LB_142$
  POP  BC
  RET
MARM$:
  LD   DE,#LB_143$
  LD   (#LB_002$+1),DE
  CALL LB_001$
  LD   DE,#LB_013$
  LD   (#LB_002$+1),DE
  RET
LB_143$:
  CALL LB_177$
  CALL LB_156$
  JP   LB_159$
MIRM$:
  LD   DE,#LB_049$
  JP   LB_156$
CLSM$:
  CALL LB_146$
  RET  C
  PUSH DE
  CALL LB_145$
  XOR  A
  EX   (SP),HL
  POP  BC
LB_144$:
  DEC  BC
  LD   D,H
  LD   E,L
  INC  DE
  LD   (HL),A
  LDIR
  RET
LB_145$:
  PUSH DE
  LD   E,H
  LD   H,#0x00
  LD   D,#0x00
  CALL LB_107$
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  RET
SETM$:
  CALL LB_189$
  PUSH HL
  LD   HL,(#LB_075$)
  LD   E,H
  LD   H,#0x00
  LD   D,#0x00
  CALL LB_107$
  EX   (SP),HL
  POP  BC
  DEC  BC
  LD   A,B
  OR   C
  LD   A,(#SETV_A$)
  LD   (HL),A
  RET  Z
  INC  BC
  JP   LB_144$
INVM$:
  LD   DE,#LB_053$
  JP   LB_156$
LB_146$:
  CALL LB_070$
  RET  NC
  CALL LB_092$+3
  CALL LB_150$
  CALL LB_152$
  CALL LB_155$
  CALL LB_157$
  CALL LB_158$
  CALL LB_165$
  CALL LB_159$
  CALL LB_160$+3
  CALL LB_161$+3
  CALL LB_162$+3
  CALL LB_163$+3
  LD   A,#0x7C
  LD   (#LB_058$),A
  LD   A,#0x80
  LD   (#LB_058$+1),A
  LD   A,#0xE5
  LD   (#LB_173$),A
  RET
LB_147$:
  PUSH BC
  CALL LB_146$
  POP  BC
  RET  C
LB_148$:
  LD   A,#0x00
  JP   LB_100$
LB_149$:
  LD   HL,#LB_148$+1
  LD   (HL),#0xEB
  CALL LB_147$
LB_150$:
  XOR  A
  LD   (#LB_148$+1),A
  RET
LB_151$:
  LD   HL,#LB_086$
  LD   (#LB_100$+1),HL
  CALL LB_149$
LB_152$:
  LD   HL,#LB_093$
  LD   (#LB_100$+1),HL
  RET
LB_153$:
  LD   HL,#LB_085$+1
  LD   (HL),#0xA6
  JP   LB_092$
LB_154$:
  LD   HL,#LB_149$+3+1
  LD   (HL),#0x00
  CALL LB_151$
LB_155$:
  LD   A,#0xEB
  LD   (#LB_149$+3+1),A
  RET
SR1M$:
  LD   DE,#LB_033$
LB_156$:
  LD   (#LB_176$+1),DE
  CALL SL1M$
LB_157$:
  LD   DE,#LB_035$
  LD   (#LB_176$+1),DE
  RET
WCRM$:
  LD   HL,#LB_015$+1
  LD   (#LB_181$+1),HL
  CALL SCRM$
LB_158$:
  LD   HL,#SCRV$
  LD   (#LB_181$+1),HL
  RET
LB_159$:
  PUSH HL
  LD   HL,#LB_146$
  LD   (#SL1M$+1),HL
  LD   HL,#0x20CB
  JP   LB_178$
LB_160$:
  CALL SR4V$
  LD   HL,#SR1V$
  LD   (#LB_038$+1),HL
  RET
LB_161$:
  CALL SL4V$
  LD   HL,#SL1V$
  LD   (#LB_039$+1),HL
  RET
LB_162$:
  CALL WR4V$
  LD   HL,#LB_056$
  LD   (#LB_040$+1),HL
  RET
LB_163$:
  CALL WL4V$
  LD   HL,#LB_056$
  LD   (#LB_043$+1),HL
  RET
LB_164$:
  LD   HL,#LB_174$
  LD   (#LB_188$+1),HL
  CALL LB_187$
LB_165$:
  LD   HL,#LB_166$
  LD   (#LB_188$+1),HL
  RET
LB_166$:
  PUSH BC
  PUSH DE
  CALL LB_146$
  POP  DE
  POP  BC
  LD   A,C
LB_167$:
  PUSH AF
  CALL LB_058$
  JR   NC,#LB_171$
  XOR  A
LB_168$:
  LD   (#LB_183$+1),A
  LD   (#LB_184$),A
  POP  AF
  JR   LB_170$
LB_169$:
  PUSH AF
  CALL LB_058$
  JR   NC,#LB_171$
  LD   A,#0xEB
  JR   LB_168$
LB_170$:
  LD   (#LB_069$+2),HL
  LD   (#LB_179$),DE
  CALL ATOF$
  PUSH BC
  CALL LB_146$
  PUSH DE
  CALL LB_185$
  JR   C,#LB_172$
  POP  BC
LB_171$:
  POP  DE
  RET
LB_172$:
  LD   A,(#LB_179$+1)
  LD   E,A
  LD   D,#0x00
  LD   H,#0x00
  LD   (#LB_179$+2),HL
  CALL LB_107$
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  ADD  HL,DE
  LD   D,#0x00
  LD   A,(#LB_179$)
  LD   E,A
  ADD  HL,DE
  LD   DE,(#LB_069$+2)
  EX   DE,HL
  POP  BC
LB_173$:
  PUSH HL
  LD   HL,#LB_183$
  LD   (#LB_087$+1),HL
  XOR  A
  POP  HL
  JP   LB_057$
LB_174$:
  PUSH BC
  PUSH DE
  CALL LB_146$
  POP  DE
  POP  BC
  LD   A,C
  JP   LB_169$
SL1M$:
  CALL LB_146$
  RET  C
  PUSH DE
  PUSH HL
  POP  BC
  POP  HL
LB_175$:
  SLA  B
  SLA  B
  SLA  B
  LD   A,C
  LD   (#LB_005$+1),A
LB_176$:
  LD   DE,#LB_035$
  LD   (#LB_004$+1),DE
  CALL LB_003$
  LD   A,#0x20
  LD   (#LB_005$+1),A
  JP   LB_014$
LB_177$:
  PUSH HL
  LD   HL,#LB_186$+2
  LD   (SL1M$+1),HL
  LD   HL,#0x0000
LB_178$:
  LD   (#LB_175$),HL
  LD   (#LB_175$+2),HL
  LD   (#LB_175$+4),HL
  POP  HL
  RET
LB_179$:
  NOP
  NOP
  NOP
  NOP
  LD   HL,(#LB_179$+2)
  LD   H,#0x00
  LD   D,#0x00
  LD   E,B
  CALL LB_107$
  LD   DE,(#LB_179$)
  ADD  HL,DE
  RET
SCRM$:
  PUSH BC
  CALL LB_146$
  POP  BC
  LD   (#LB_179$),DE
  LD   (#LB_179$+2),HL
  LD   HL,#LB_179$+4
  LD   (#LB_022$+4),HL
  LD   A,#0xC3
  LD   (#LB_022$+3),A
  LD   A,B
  LD   BC,#0x0000
  LD   HL,(#LB_179$+2)
LB_181$:
  CALL SCRV$
  LD   A,#0x58
  LD   (#LB_022$+3),A
  LD   HL,#0x3E51
  LD   (#LB_022$+4),HL
  RET
LB_182$:
  LD   DE,(#LB_186$)
LB_183$:
  PUSH DE
  NOP
  .DB  #0xED
  .DB  #0xB0
  NOP
LB_184$:
  NOP
  POP  DE
  LD   HL,(#LB_179$+2)
  ADD  HL,DE
  EX   DE,HL
  LD   (#LB_186$),DE
  RET
LB_185$:
  LD   A,(#LB_069$+3)
  LD   C,A
  LD   A,(#LB_179$+1)
  ADD  A,C
  DEC  A
  SUB  H
  RET  NC
  LD   A,(#LB_069$+2)
  LD   C,A
  LD   A,(#LB_179$)
  ADD  A,C
  DEC  A
  SUB  L
  RET
LB_186$:
  .DB  0,0
  CALL LB_189$
  LD   DE,(#LB_075$)
  EX   DE,HL
  RET
LB_187$:
  LD   A,#0xC9
  LD   (#LB_173$),A
  LD   (#LB_058$+1),A
  LD   A,#0x37
  LD   (#LB_058$),A
  LD   A,B
  OR   A
LB_188$:
  CALL LB_166$
  LD   A,#0x7C
  LD   (#LB_058$),A
  LD   A,#0x80
  LD   (#LB_058$+1),A
  LD   A,#0xE5
  LD   (#LB_173$),A
  LD   A,B
  LD   (#LB_186$),DE
  LD   DE,#LB_182$
  JP   LB_156$
LB_189$:
  CALL LB_146$
  LD   (#LB_075$),HL
  PUSH DE
  LD   D,#0x00
  LD   E,H
  LD   H,#0x00
  CALL LB_107$
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  ADD  HL,DE
  RET
GTBL$:
  LD   HL,#LB_147$
  LD   DE,#GWBL$
  JP   LB_196$
GTOR$:
  LD   HL,#LB_154$
  LD   DE,#GWOR$
  JP   LB_196$
GTXR$:
  LD   HL,#LB_200$
  LD   DE,#GWXR$
  JP   LB_196$
GTND$:
  LD   HL,#LB_201$
  LD   DE,#GWND$
  JP   LB_196$
PTBL$:
  LD   HL,#LB_149$
  LD   DE,#PWBL$
  JP   LB_196$
PTOR$:
  LD   HL,#LB_151$
  LD   DE,#PWOR$
  JP   LB_196$
PTXR$:
  LD   HL,#LB_091$
  LD   DE,#PWXR$
  JP   LB_196$
PTND$:
  LD   HL,#LB_153$
  LD   DE,#PWND$
  JP   LB_196$
GWBL$:
  CALL LB_202$
  JP   LB_190$
GWOR$:
  CALL LB_204$
  JP   LB_190$
GWXR$:
  CALL LB_207$
  JP   LB_190$
GWND$:
  CALL LB_206$
  JP   LB_190$
PWBL$:
  CALL LB_202$
  JP   LB_195$
PWOR$:
  CALL LB_204$
  JP   LB_195$
PWXR$:
  CALL LB_207$
  JP   LB_195$
PWND$:
  CALL LB_206$
  JP   LB_195$
LB_190$:
  LD   IX,#LB_167$
  LD   (#LB_192$+1),IX
  LD   IX,#GWAT$
LB_191$:
  LD   (#LB_193$+1),IX
  LD   IX,(#LB_100$+3)
  PUSH IX
  PUSH AF
  PUSH BC
  PUSH DE
  PUSH HL
  PUSH IX
LB_192$:
  CALL LB_167$
  POP  HL
  LD   (#LB_100$+3),HL
  LD   A,L
  CP   #0xD0
  POP  HL
  POP  DE
  POP  BC
  JR   NZ,#LB_194$
  POP  AF
LB_193$:
  CALL GWAT$
  POP  HL
  LD   (#LB_100$+3),HL
  RET
LB_194$:
  POP  AF
  JR   LB_193$+3
LB_195$:
  LD   IX,#LB_169$
  LD   (#LB_192$+1),IX
  LD   IX,#PWAT$
  JR   LB_191$
LB_196$:
  LD   (#LB_197$+1),HL
  LD   (#LB_198$+1),DE
  PUSH BC
  CALL LB_146$
  POP  BC
  LD   D,A
  CALL LB_058$
  LD   A,D
LB_197$:
  JP   C,#LB_147$
  LD   (#LB_199$),A
  CALL LB_059$
  LD   A,(#LB_199$)
  RET  NC
LB_198$:
  JP   GWBL$
LB_199$:
  NOP
  NOP
  NOP
LB_200$:
  LD   HL,#LB_149$+3+1
  LD   (HL),#0x00
  CALL LB_091$
  JP   LB_155$
LB_201$:
  LD   HL,#LB_149$+3+1
  LD   (HL),#0x00
  CALL LB_153$
  JP   LB_155$
LB_202$:
  PUSH AF
  PUSH HL
  XOR  A
  LD   HL,#0xB0ED
LB_203$:
  LD   (#LB_183$+2),A
  LD   (#LB_183$+3),HL
  POP  HL
  POP  AF
  RET
LB_204$:
  PUSH AF
  PUSH HL
  LD   A,#0xB6
LB_205$:
  LD   (#LB_085$+1),A
  LD   A,#0xCD
  LD   HL,#LB_084$
  JR   LB_203$
LB_206$:
  PUSH AF
  PUSH HL
  LD   A,#0xA6
  JR   LB_205$
LB_207$:
  PUSH AF
  PUSH HL
  LD   A,#0xAE
  JR   LB_205$
GWAT$:
  PUSH AF
  XOR  A
LB_208$:
  LD   (#LB_213$),A
  LD   (#LB_214$),A
  POP  AF
  JR   LB_209$
PWAT$:
  PUSH AF
  LD   A,#0xEB
  JR   LB_208$
LB_209$:
  LD   (#LB_179$),DE
  PUSH AF
  CALL LB_058$
  JP   NC,#LB_171$
  POP  AF
  PUSH HL
  PUSH AF
  LD   H,B
  LD   L,C
  LD   BC,#0x0020
  LD   (#LB_212$),BC
  CALL LB_105$
LB_210$:
  EX   (SP),HL
  LD   A,H
  CALL LB_217$
  POP  DE
  EX   DE,HL
  LD   BC,(#LB_075$)
  LD   B,#0x00
  LD   (#LB_212$+2),BC
  POP  BC
  CALL LB_215$
  LD   A,C
  RET  NC
LB_211$:
  CALL LB_212$+4
  DJNZ LB_211$
  RET
LB_212$:
  NOP
  NOP
  NOP
  NOP
  PUSH BC
  PUSH DE
  PUSH HL
  LD   B,#0x00
  LD   C,A
LB_213$:
  NOP
  LDIR
LB_214$:
  NOP
  POP  HL
  LD   BC,(#LB_212$)
  ADD  HL,BC
  EX   (SP),HL
  LD   BC,(#LB_212$+2)
  ADD  HL,BC
  POP  DE
  POP  BC
  EX   DE,HL
  RET
LB_215$:
  PUSH DE
  LD   DE,(#LB_179$)
  PUSH HL
  LD   HL,(#LB_075$)
  LD   A,D
  ADD  A,B
  DEC  A
  SUB  H
  JR   NC,#LB_216$
  LD   A,E
  ADD  A,C
  DEC  A
  SUB  L
  NOP
  NOP
LB_216$:
  POP  HL
  POP  DE
  RET
LB_217$:
  PUSH BC
  PUSH DE
  CALL LB_189$
  LD   B,H
  LD   C,L
  POP  DE
  PUSH DE
  LD   E,D
  LD   D,#0x00
  LD   H,#0x00
  LD   A,(#LB_075$)
  LD   L,A
  CALL LB_107$
  ADD  HL,BC
  POP  DE
  LD   D,#0x00
  ADD  HL,DE
  POP  BC
  RET
/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*          v. 3.17             */
/*      E N D  P A R T  2       */
/* ---------------------------- */
__endasm;
}
