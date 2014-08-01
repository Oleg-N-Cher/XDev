/* ------------------------------- */
/* LASER BASIC for SDCC  >>> v3.17 */
/* Adapted to SDCC by Oleg N. Cher */
/*    (Vedanta software), 2011     */
/*    Thanks to Michailov (HVG)    */
/* ------------------------------- */

#include "SYSTEM.h"
#include "Laser.h"

/* Set video attrib */
#define SETV_A$ 0x5C8D

extern unsigned int SFSTRT; /* Sprite file start address */
extern unsigned int SF_END; /* Sprite file end address */
extern unsigned int SCRL_B; /* Scroll buffer address */

extern unsigned long LB_069;
extern unsigned int LB_075;

export void _InitSprites (void /* Registers HL */);

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
/*================================== Header ==================================*/

unsigned long LB_069;
/*LB_069$:
  NOP
  NOP
  NOP
  NOP*/
/*--------------------------------- Cut here ---------------------------------*/
unsigned int LB_075;
/*LB_075$:
  NOP
  NOP*/
/*--------------------------------- Cut here ---------------------------------*/
unsigned int SFSTRT; /* Sprite file start address */
unsigned int SF_END; /* Sprite file end address */
unsigned int SCRL_B; /* Scroll buffer address */

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
  BYTE sprN;
  struct Sprite *sprNext;
  BYTE sprLen;
  BYTE sprHgt;
};

void Laser_Init (SYSTEM_ADDRESS sprAddr, SYSTEM_ADDRESS sprEnd)
{
__asm
  LD   L,4(IX)
  LD   H,5(IX)
  LD   (#_SFSTRT),HL
  LD   L,6(IX)
  LD   H,7(IX)
  LD   (#_SF_END),HL
  //  В ячейке _SF_END должен быть записан ноль - метка конца спрайт-файла.
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

void _InitSprites (void /* Registers HL */)
{
__asm
  PUSH IX      // IX is a calle-saves register (see SDCC tracker #3567945)
//  LD   HL,#scrollBuf
//  LD   (#_SCRL_B),HL
//  LD   HL,#sprEnd
    //  В ячейке _SF_END должен быть записан ноль - метка конца спрайт-файла.
//  LD   (#_SF_END),HL
//  LD   HL,#sprAddr
//  LD   (#_SFSTRT),HL
/* Set sprite relocs (see Laser Basic sprite format specifications) */
  PUSH HL
  POP  IX
  // LD   IX,(#_SFSTRT) // struct Sprite *sprPtr; sprPtr = (struct Sprite*)sprAddr;
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
} //_InitSprites

/*--------------------------------- Cut here ---------------------------------*/
/*-----------------------------------------*/
/* Functions for screen windows processing */
/*-----------------------------------------*/
void Laser_INVV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Inverts the window */
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
  LD   DE,#__Laser_LB_053
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_INVV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_MIRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Mirroring the window */
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
  LD   DE,#__Laser_LB_049
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_MIRV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_MARV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Mirroring the window attributes */
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
  //  NOP  //?
  CALL __Laser_LB_001
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_MARV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SETV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Sets the attributes of the window */
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
  CALL __Laser_LB_064
  CALL __Laser_LB_068
  PUSH HL
  PUSH BC
  POP  HL
  CALL __Laser_LB_105
  POP  BC
LB_054$:
  PUSH BC
  PUSH HL
  LD   A,(#SETV_A$)
  CALL __Laser_LB_055+1
  POP  HL
  LD   DE,#0x0020
  ADD  HL,DE
  POP  BC
  DJNZ LB_054$
  //RET
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SETV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_CLSV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Clears the attributes of the window */
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
  LD   DE,#__Laser_LB_055
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_CLSV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window left by 1 pixel circularly */
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
  LD   DE,#__Laser_LB_037
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WL1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window right by 1 pixel circularly */
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
  LD   DE,#__Laser_LB_034
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WR1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window left by 4 pixels circularly */
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
  CALL __Laser_LB_WL4V
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WL4V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_WL4V (void) __naked {
__asm
  PUSH HL
  LD   HL,#0x6FED
  LD   (#LB_036),HL
  POP  HL
  LD   DE,#LB_044$
.globl LB_043
LB_043:
  CALL __Laser_LB_056
  JP   LB_039+3 // was: JR
LB_044$:
  CALL __Laser_LB_035
  JP   LB_042 // was: JR
__endasm;
} //_Laser_LB_WL4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window right by 4 pixels circularly */
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
  CALL __Laser_LB_WR4V
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WR4V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_WR4V (void) {
__asm
  PUSH HL
  LD   HL,#0x67ED
  LD   (#__Laser_LB_033+2),HL
  POP  HL
  LD   DE,#LB_041$
.globl LB_040
LB_040:
  CALL __Laser_LB_056
  JP   LB_038+3 //was: JR
LB_041$:
  PUSH HL
  CALL __Laser_LB_033
  SLA  A
  SLA  A
  SLA  A
  SLA  A
  POP  HL
.globl LB_042
LB_042:
  OR  (HL)
  LD  (HL),A
//RET
__endasm;
} //_Laser_LB_WR4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window left by 8 pixels circularly */
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
  LD   DE,#__Laser_LB_046
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WL8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window right by 8 pixels circularly */
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
  LD   DE,#__Laser_LB_048
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WR8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window left by 1 pixel */
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
  CALL __Laser_LB_SL1V
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SL1V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_SL1V (void) __naked {
__asm
  LD   DE,#__Laser_LB_035
  JP   __Laser_LB_056
__endasm;
} //_Laser_LB_SL1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window right by 1 pixel */
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
  CALL __Laser_LB_SR1V
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SR1V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_SR1V (void) __naked {
__asm
  LD   DE,#__Laser_LB_033
  JP   __Laser_LB_056
__endasm;
} //_Laser_LB_SR1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window left by 4 pixels */
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
  CALL __Laser_LB_SL4V
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SL4V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_SL4V (void) {
__asm
  PUSH HL
  LD   HL,#0x6FED
  LD   (#LB_036),HL
  POP  HL
.globl LB_039
LB_039:
  CALL __Laser_LB_SL1V
  LD   HL,#0x16CB
  LD   (#LB_036),HL
//RET
__endasm;
} //_Laser_LB_SL4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window right by 4 pixels */
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
  CALL __Laser_LB_SR4V
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SR4V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_SR4V (void) {
__asm
  PUSH HL
  LD   HL,#0x67ED
  LD   (#__Laser_LB_033+2),HL
  POP  HL
.globl LB_038
LB_038:
  CALL __Laser_LB_SR1V
  LD   HL,#0x1ECB
  LD   (#__Laser_LB_033+2),HL
//RET
__endasm;
} //_Laser_LB_SR4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window left by 8 pixels */
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
  LD   DE,#__Laser_LB_045
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SL8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window right by 8 pixels */
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
  LD   DE,#__Laser_LB_047
  CALL __Laser_LB_056
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SR8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx) {
/* Scrolls the window by npx pixels vertically (+Up, -Down) and circularly */
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
  CALL __Laser_LB_015+1
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WCRV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx) {
/* Scrolls the window by npx pixels vertically (+Up, -Down) */
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
  CALL __Laser_LB_SCRV
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SCRV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_AWLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window attributes left circularly */
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
  CALL __Laser_LB_AWLV
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_AWLV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ASLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window attributes left */
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
  LD   DE,#__Laser_LB_045
  LD   (#LB_004+1),DE
  CALL __Laser_LB_AWLV
  LD   DE,#__Laser_LB_046
  LD   (#LB_004+1),DE
  //RET
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_ASLV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_AWRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window attributes right circularly */
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
  LD   DE,#__Laser_LB_048
  CALL __Laser_LB_013
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_AWRV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ASRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window attributes right */
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
  LD   DE,#__Laser_LB_047
  LD   (#LB_004+1),DE
  CALL __Laser_LB_AWLV
  LD   DE,#__Laser_LB_046
  LD   (#LB_004+1),DE
  //RET
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_ASRV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATUV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window attributes up circularly */
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
  CALL __Laser_LB_064
  CALL __Laser_LB_068
  CALL __Laser_LB_058
  CALL C,__Laser_LB_006
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_ATUV

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATDV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt) {
/* Scrolls the window attributes down circularly */
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
#ifdef __SDCC
  POP  IX
#endif
  CALL __Laser_LB_064
  CALL __Laser_LB_068
  CALL __Laser_LB_058
  RET  NC
  LD   A,H
  DEC  A
  RET  Z
  ADD  A,B
  LD   B,A
  LD   A,#0x52
  LD   (#LB_011+1),A
  CALL __Laser_LB_006
  LD   A,#0x5A
  LD   (#LB_011+1),A
  //RET
__endasm;
} //Laser_ATDV

/*--------------------------------- Cut here ---------------------------------*/
/*-------------------------------------*/
/* Functions for sprites manipulations */
/*-------------------------------------*/
void Laser_CLSM (SHORTCARD spN) {
/* Clears the sprite */
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL __Laser_LB_CLSM
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_INVM (SHORTCARD spN) {
/* Inverts the sprite */
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_053
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_INVM

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTBL (SHORTINT col, SHORTINT row, SHORTCARD spN) __naked {
__asm
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL) /* x */
  INC  HL
  LD   B,(HL) /* y */
  INC  HL
  LD   A,(HL) /* Sprite number */
  LD   HL,#__Laser_LB_149
  LD   DE,#__Laser_LB_PWBL
  JP   __Laser_LB_196
__endasm;
} //Laser_PTBL

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTOR (SHORTINT col, SHORTINT row, SHORTCARD spN) __naked {
__asm
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL) /* x */
  INC  HL
  LD   B,(HL) /* y */
  INC  HL
  LD   A,(HL) /* Sprite number */
  LD   HL,#__Laser_LB_151
  LD   DE,#__Laser_LB_PWOR
  JP   __Laser_LB_196
__endasm;
} //Laser_PTOR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTXR (SHORTINT col, SHORTINT row, SHORTCARD spN) __naked {
__asm
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL) /* x */
  INC  HL
  LD   B,(HL) /* y */
  INC  HL
  LD   A,(HL) /* Sprite number */
  JP   __Laser_LB_PTXR
__endasm;
} //Laser_PTXR

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_PTXR (void) __naked {
__asm
  LD   HL,#__Laser_LB_091
  LD   DE,#__Laser_LB_PWXR
  JP   __Laser_LB_196
__endasm;
} //_Laser_LB_PTXR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PTND (SHORTINT col, SHORTINT row, SHORTCARD spN) __naked {
__asm
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL) /* x */
  INC  HL
  LD   B,(HL) /* y */
  INC  HL
  LD   A,(HL) /* Sprite number */
  LD   HL,#LB_153
  LD   DE,#__Laser_LB_PWND
  JP   __Laser_LB_196
__endasm;
} //Laser_PTND

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_PWND (void) __naked {
__asm
  CALL __Laser_LB_206
  JP   __Laser_LB_195
__endasm;
} //_Laser_LB_PWND

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL1M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_037
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WL1M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR1M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_034
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WR1M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL4M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   HL,#LB_156
  LD   (#LB_043+1),HL
  CALL __Laser_LB_WL4V
  CALL __Laser_LB_163_3
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WL4M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR4M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   HL,#LB_156
  LD   (#LB_040+1),HL
  CALL __Laser_LB_WR4V
  CALL __Laser_LB_162_3
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WR4M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WL8M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_046
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WL8M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WR8M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_048
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_WR8M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL1M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL _LB_SL1M
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void LB_SL1M (void) __naked {
__asm
  CALL __Laser_LB_146
  RET  C
  PUSH DE
  PUSH HL
  POP  BC
  POP  HL
.globl LB_175
LB_175:
  SLA  B
  SLA  B
  SLA  B
  LD   A,C
  LD   (#LB_005+1),A
.globl LB_176
LB_176:
  LD   DE,#__Laser_LB_035
  LD   (#LB_004+1),DE
  CALL LB_003
  LD   A,#0x20
  LD   (#LB_005+1),A
  JP   LB_014
__endasm;
} //LB_SL1M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR1M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  CALL _LB_SR1M
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void LB_SR1M (void) {
__asm
  LD   DE,#__Laser_LB_033
.globl LB_156
LB_156:
  LD   (#LB_176+1),DE
  CALL _LB_SL1M
.globl LB_157
LB_157:
  LD   DE,#__Laser_LB_035
  LD   (#LB_176+1),DE
//RET
__endasm;
} //LB_SR1M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL4M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   HL,#_LB_SL1M
  LD   (#LB_039+1),HL
  CALL __Laser_LB_SL4V
  CALL __Laser_LB_161_3
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SL4M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR4M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   HL,#_LB_SR1M
  LD   (#LB_038+1),HL
  CALL __Laser_LB_SR4V
  CALL __Laser_LB_160_3
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SR4M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SL8M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_045
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SL8M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_SR8M (SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   DE,#__Laser_LB_047
  CALL LB_156
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_SR8M

/*--------------------------------- Cut here ---------------------------------*/
void Laser_WCRM (SHORTCARD spN, SHORTINT npx) {
/* Scrolls the sprite by npx pixels vertically (+Up, -Down) and circularly */
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   B,5(IX)
  LD   HL,#__Laser_LB_015+1
  LD   (#LB_181+1),HL
  CALL __Laser_LB_SCRM
  CALL __Laser_LB_158
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_158 (void) {
__asm
  LD   HL,#__Laser_LB_SCRV
  LD   (#LB_181+1),HL
//RET
__endasm;
} //_Laser_LB_158
  
/*--------------------------------- Cut here ---------------------------------*/
void Laser_SCRM (SHORTCARD spN, SHORTINT npx) {
/* Scrolls the sprite by npx pixels vertically (+Up, -Down) */
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   A,4(IX)
  LD   B,5(IX)
  CALL __Laser_LB_SCRM
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_SCRM (void) {
__asm
  PUSH BC
  CALL __Laser_LB_146
  POP  BC
  LD   (#LB_179),DE
  LD   (#LB_179+2),HL
  LD   HL,#LB_179+4
  LD   (#LB_022+4),HL
  LD   A,#0xC3
  LD   (#LB_022+3),A
  LD   A,B
  LD   BC,#0x0000
  LD   HL,(#LB_179+2)
.globl LB_181
LB_181:
  CALL __Laser_LB_SCRV
  LD   A,#0x58
  LD   (#LB_022+3),A
  LD   HL,#0x3E51
  LD   (#LB_022+4),HL
  //RET
__endasm;
} //_Laser_LB_SCRM

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATOF (void) {
__asm
  PUSH HL
  LD   HL,#__Laser_LB_100+3
  LD   (HL),#0xC9
  POP  HL
  //RET
__endasm;
} //Laser_ATOF

/*--------------------------------- Cut here ---------------------------------*/
void Laser_ATON (void) {
__asm
  PUSH HL
  LD   HL,#__Laser_LB_100+3
  LD   (HL),#0xD0
  POP  HL
  //RET
__endasm;
} //Laser_ATON

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTBL (SHORTINT col, SHORTINT row, SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  LD   HL,#__Laser_LB_147
  LD   DE,#__Laser_GWBL
  CALL __Laser_LB_196
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GTBL

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTOR (SHORTINT col, SHORTINT row, SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  LD   HL,#__Laser_LB_154
  LD   DE,#__Laser_GWOR
  CALL __Laser_LB_196
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GTOR

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_GWOR (void) __naked {
__asm
  CALL __Laser_LB_204
  JP   __Laser_LB_190
__endasm;
} //_Laser_GWOR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTXR (SHORTINT col, SHORTINT row, SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  LD   HL,#__Laser_LB_200
  LD   DE,#__Laser_GWXR
  CALL __Laser_LB_196
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GTXR

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_GWXR (void) __naked {
__asm
  CALL __Laser_LB_207
  JP   __Laser_LB_190
__endasm;
} //_Laser_GWXR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GTND (SHORTINT col, SHORTINT row, SHORTCARD spN) {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX) /* x */
  LD   B,5(IX) /* y */
  LD   A,6(IX) /* Sprite number */
  LD   HL,#__Laser_LB_201
  LD   DE,#__Laser_GWND
  CALL __Laser_LB_196
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GTND

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_GWND (void) __naked {
__asm
  CALL __Laser_LB_206
  JP   __Laser_LB_190
__endasm;
} //_Laser_GWND

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_202
  CALL __Laser_LB_164
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_PMBL

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_204
  CALL __Laser_LB_164
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_PMOR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_207
  CALL __Laser_LB_164
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_PMXR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_206
  CALL __Laser_LB_164
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_PMND

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  PUSH AF
  LD   A,#0xEB
  CALL __Laser_LB_114 // Was: JR
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_202
  CALL __Laser_LB_187
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GMBL

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_GWBL (void) __naked {
__asm
  CALL __Laser_LB_202
  JP   __Laser_LB_190
__endasm;
} //_Laser_GWBL

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_GWAT (void) __naked {
__asm
  PUSH AF
  XOR  A
.globl LB_208
LB_208:
  LD   (#LB_213),A
  LD   (#LB_214),A
  POP  AF
  JP   __Laser_LB_209 // Was: JR
__endasm;
} //_Laser_GWAT

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_204
  CALL __Laser_LB_187
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GMOR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_207
  CALL __Laser_LB_187
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GMXR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  CALL __Laser_LB_206
  CALL __Laser_LB_187
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_GMND

/*--------------------------------- Cut here ---------------------------------*/
void Laser_GMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS) {
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
  PUSH AF
  XOR  A
  CALL __Laser_LB_114
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWBL (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt) {
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
  CALL __Laser_LB_PWBL
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_PWBL (void) __naked {
__asm
  CALL __Laser_LB_202
  JP   __Laser_LB_195
__endasm;
} //_Laser_LB_PWBL

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWOR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt) {
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
  CALL __Laser_LB_PWOR
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_PWOR (void) __naked {
__asm
  CALL __Laser_LB_204
  JP   __Laser_LB_195
__endasm;
} //_Laser_LB_PWOR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWXR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt) {
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
  CALL __Laser_LB_PWXR
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_PWXR (void) __naked {
__asm
  CALL __Laser_LB_207
  JP   __Laser_LB_195
__endasm;
} //_Laser_LB_PWXR

/*--------------------------------- Cut here ---------------------------------*/
void Laser_PWND (SHORTINT col, SHORTINT row, SHORTCARD spN,
                 SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt) {
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
  CALL __Laser_LB_PWND
#ifdef __SDCC
  POP  IX
#endif
__endasm;
} //Laser_PWND

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_AWLV (void) __naked {
__asm
  CALL __Laser_LB_058
  RET  NC
  PUSH HL
  PUSH BC
  POP  HL
  POP  BC
  PUSH BC
  CALL __Laser_LB_105
  POP  BC
.globl LB_003
LB_003:
  LD   A,B
  PUSH BC
  PUSH AF
  PUSH HL
  LD   B,#0x00
.globl LB_004
LB_004:
  CALL __Laser_LB_046
  POP  HL
.globl LB_005
LB_005:
  LD   DE,#0x0020
  OR   A
  ADC  HL,DE
  POP  AF
  POP  BC
  DEC  A
  RET  Z
  JR   LB_003+1
__endasm;
} //_Laser_LB_AWLV

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_013 (void) {
__asm
  LD   (#LB_004+1),DE
  CALL __Laser_LB_AWLV
.globl LB_014
LB_014:
  LD   DE,#__Laser_LB_046
  LD   (#LB_004+1),DE
  //RET
__endasm;
} //_Laser_LB_013

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_021 (void) {
__asm
  CALL __Laser_LB_058
  RET  NC
  LD   A,(#_LB_069)
  SLA  H
  SLA  H
  SLA  H
  BIT  7,A
  JR   Z,#LB_022
  NEG
.globl LB_022
LB_022:
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
//RET
__endasm;
} //_Laser_LB_021
  
/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_033 (void) {
__asm
  XOR  A
  LD   B,C
LB_033_2$:
  RR   (HL)
  INC  HL
  DJNZ LB_033_2$
//RET
__endasm;
} //_Laser_LB_033

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_035 (void) {
__asm
  LD   B,#0x00
  ADD  HL,BC
  DEC  HL
  XOR  A
  PUSH HL
  LD   B,C
.globl LB_036
LB_036:
  RL   (HL)
  DEC  HL
  DJNZ LB_036
  POP  HL
//RET
__endasm;
} //_Laser_LB_035

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_045 (void) {
__asm
  LD   D,H
  LD   E,L
  INC  HL
  DEC  C
  RET  Z
  LDIR
  DEC  HL
  LD   (HL),#0x00
//RET
__endasm;
} //_Laser_LB_045

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_046 (void) {
__asm
  LD   A,(HL)
  CALL __Laser_LB_045
  LD   (DE),A
//RET
__endasm;
} //_Laser_LB_046

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_047 (void) {
__asm
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
//RET
__endasm;
} //_Laser_LB_047

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_056 (void) {
__asm
  LD   (#LB_087+1),DE
  CALL __Laser_LB_064
  CALL __Laser_LB_068
  XOR  A
.globl LB_057
LB_057:
  CALL __Laser_LB_086
  LD  HL,#__Laser_LB_084
  LD  (#LB_087+1),HL
//RET
__endasm;
} //_Laser_LB_056

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_058 (void) {
__asm
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
//RET
__endasm;
} //_Laser_LB_058

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_059 (void) {
__asm
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
//RET
__endasm;
} //_Laser_LB_059

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_064 (void) {
__asm
  CALL __Laser_LB_058
  JP   NC,#__Laser_LB_059
  LD   DE,#0x0000
  SCF
//RET
__endasm;
} //_Laser_LB_064

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_068 (void) {
__asm
  PUSH AF
  LD   A,H
  OR   A
  JR   Z,#LB_066$
  LD   A,L
  OR   A
  JR   Z,#LB_066$
  POP  AF
  RET
LB_066$:
  POP  HL
  POP  HL
//RET
__endasm;
} //_Laser_LB_068

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_070 (void) __naked {
__asm
  LD   HL,(#_SFSTRT)
  LD   (#_LB_069),A
LB_071$:
  LD   B,A
  LD   A,(HL)
  OR   A //CP   #0x00
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
  //CALL __Laser_LB_074
  //inline
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
  //end
  EX   DE,HL
  LD   A,(#_LB_069)
  JR   LB_071$
__endasm;
} //_Laser_LB_070

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_RLCT (void) {
__asm
  //CALL __Laser_LB_076
  // inline
  LD   HL,(#_SFSTRT)
LB_076_3$:
  LD   A,(HL)
  OR   A // Was: CP   #0x00
  JR   Z,LB_076_4$//RET  Z
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
  JR   LB_076_3$
LB_076_4$:
  // end
  LD   HL,(#_SF_END)
  LD   DE,(#_SFSTRT)
  OR   A
  SBC  HL,DE
  INC  HL
  PUSH HL
  BIT  7,B
  JR   NZ,#LB_077$
  LD   HL,(#_SF_END)
  CALL __Laser_LB_078
  LD   (#_SF_END),DE
  POP  BC
  LDDR
  INC  DE
  LD   (#_SFSTRT),DE
  RET
LB_077$:
  LD   HL,(#_SFSTRT)
  CALL __Laser_LB_078
  LD   (#_SFSTRT),DE
  POP  BC
  LDIR
  DEC  DE
  LD   (#_SF_END),DE
//RET
__endasm;
} //_Laser_RLCT

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_078 (void) {
__asm
  PUSH HL
  ADD  HL,BC
  EX   DE,HL
  POP  HL
//RET
__endasm;
} //_Laser_LB_078

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_079 (void) {
__asm
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
  CALL __Laser_LB_070
  CALL NC,#__Laser_LB_080
  POP  BC
  POP  AF
  LD   HL,(#_SF_END)
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
  CALL __Laser_LB_107
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
  LD   (#_SF_END),DE
  XOR  A
  LD   (DE),A
//RET
__endasm;
} //_Laser_LB_079
  
/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_080 (void) {
__asm
  PUSH BC
  LD   H,B
  LD   L,C
  //CALL __Laser_LB_074
  //inline
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
  //end
  POP  HL
  EX   DE,HL
  //CALL LB_106$
  //inline
  AND  A
  SBC  HL,DE
  LD   B,H
  LD   C,L
  ADD  HL,DE
  EX   DE,HL
  //RET
  //end
  PUSH HL
  PUSH DE
  EX   DE,HL
  JR   LB_082$
LB_081$:
  //CALL __Laser_LB_074
  //inline
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
  //end
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
  LD   HL,(#_SF_END)
  POP  DE
  OR   A
  SBC  HL,BC
  LD   (#_SF_END),HL
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
//RET
__endasm;
} //_Laser_LB_080

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_084 (void) {
__asm
  PUSH AF
  LD   B,C
.globl LB_085
LB_085:
  LD   A,(DE)
  OR   (HL)
  LD   (DE),A
  INC  DE
  INC  HL
  DJNZ LB_085
  POP  AF
//RET
__endasm;
} //_Laser_LB_084

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_086 (void) {
__asm
  LD   (#LB_088$+1),A
  LD   A,#0xCD
  LD   (#LB_096+1),A
  PUSH HL
.globl LB_087
LB_087:
  LD   HL,#__Laser_LB_084
  LD   (#LB_096+2),HL
  POP  HL
LB_088$:
  LD   A,#0x00
  CALL __Laser_LB_093
  XOR  A
  LD   (#LB_096+1),A
  LD   (#LB_096),A
  PUSH HL
  CALL LB_092_3
//
  LD   HL,#0xB0ED
  LD   (#LB_096+2),HL
  POP  HL
  SCF
//RET
__endasm;
} //_Laser_LB_089
  

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_091 (void) {
__asm
  LD   HL,#LB_085+1
  LD   (HL),#0xAE
.globl LB_092_3
LB_092_3:
  LD   HL,#LB_085+1
  LD   (HL),#0xB6
//RET
__endasm;
} //_Laser_LB_091

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_093 (void) {
__asm
  LD   (#_LB_069),A
  CALL __Laser_LB_058
  RET  NC
  LD   A,(#_LB_069)
  LD   (#LB_096),A
  LD   (#LB_096+4),A
  LD   (#LB_102),A
  LD   (#LB_103),A
  PUSH HL
  PUSH BC
  PUSH HL
//CALL LB_099$
/* start inline */
//LB_099$:
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
  //LD   HL,(#SCR_AC$)
  LD   HL,#0x4000
  ADD  HL,BC
//RET
/* end inline */
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
.globl LB_096
LB_096:
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
//RET
__endasm;
//SCR_AC$: .DW #0x4000
} //_Laser_LB_093

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_100 (void) __naked {
__asm
  CALL __Laser_LB_093
  RET  NC
  CALL __Laser_LB_105
LB_101$:
  PUSH HL
  PUSH BC
  LD   B,#0x00
.globl LB_102
LB_102:
  NOP
  LDIR
.globl LB_103
LB_103:
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
__endasm;
} //_Laser_LB_100

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_105 (void) {
__asm
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
  //LD   DE,(#SCRA_A$)
  LD   DE,#0x5800
  ADD  HL,DE
  POP  DE
//RET
__endasm;
//SCRA_A$: .DW #0x5800
} //_Laser_LB_105

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_107 (void) {
__asm
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
//RET
__endasm;
} //_Laser_LB_107

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_114 (void) __naked {
__asm
  LD   (#LB_213),A
  LD   (#LB_214),A
  POP  AF
  //JP   LB_111$
LB_111$:
  LD   (#LB_179),DE
  LD   A,B
  LD   B,C
  PUSH BC
  CALL __Laser_LB_189
  LD   BC,(#_LB_075)
  LD   B,#0x00
  LD   (#__Laser_LB_212),BC
  LD   BC,(#_LB_075)
  POP  AF
  PUSH BC
  PUSH AF
  LD   DE,(#LB_179)
  JP   LB_210
__endasm;
} //_Laser_LB_114

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_CLSM (void) {
__asm
  CALL __Laser_LB_146
  RET  C
  PUSH DE
  //CALL LB_145$
  // inline
//LB_145$:
  PUSH DE
  LD   E,H
  LD   H,#0x00
  LD   D,#0x00
  CALL __Laser_LB_107
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  //RET
  // end
  XOR  A
  EX   (SP),HL
  POP  BC
.globl LB_144
LB_144:
  DEC  BC
  LD   D,H
  LD   E,L
  INC  DE
  LD   (HL),A
  LDIR
//RET
__endasm;
} //_Laser_LB_CLSM

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_146 (void) {
// Used by: PTBL
__asm
  CALL __Laser_LB_070
  RET  NC
  CALL LB_092_3
  CALL LB_150
  CALL LB_152
  CALL LB_155
  CALL LB_157
  CALL __Laser_LB_158
  CALL LB_165
  CALL __Laser_LB_159
  CALL __Laser_LB_160_3
  CALL __Laser_LB_161_3
  CALL __Laser_LB_162_3
  CALL __Laser_LB_163_3
  LD   A,#0x7C
  LD   (#__Laser_LB_058),A
  LD   A,#0x80
  LD   (#__Laser_LB_058+1),A
  LD   A,#0xE5
  LD   (#LB_173),A
//RET
__endasm;
} //_Laser_LB_146

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_147 (void) __naked {
__asm
  PUSH BC
  CALL __Laser_LB_146
  POP  BC
  RET  C
.globl LB_148
LB_148:
  LD   A,#0x00
  JP   __Laser_LB_100
__endasm;
} //_Laser_LB_147

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_149 (void) {
__asm
  LD   HL,#LB_148+1
  LD   (HL),#0xEB
  CALL __Laser_LB_147
.globl LB_150
LB_150:
  XOR  A
  LD   (#LB_148+1),A
//RET
__endasm;
} //_Laser_LB_149

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_151 (void) {
__asm
  LD   HL,#__Laser_LB_086
  LD   (#__Laser_LB_100+1),HL
  CALL __Laser_LB_149
.globl LB_152
LB_152:
  LD   HL,#__Laser_LB_093
  LD   (#__Laser_LB_100+1),HL
//RET
__endasm;
} //_Laser_LB_151

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_154 (void) {
__asm
  LD   HL,#__Laser_LB_149+3+1
  LD   (HL),#0x00
  CALL __Laser_LB_151
.globl LB_155
LB_155:
  LD   A,#0xEB
  LD   (#__Laser_LB_149+3+1),A
//RET
__endasm;
} //_Laser_LB_154

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_159 (void) __naked {
__asm
  PUSH HL
  LD   HL,#__Laser_LB_146
  LD   (#_LB_SL1M+1),HL
  LD   HL,#0x20CB
  JP   LB_178
__endasm;
} //_Laser_LB_159

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_160_3 (void) {
__asm
  LD   HL,#__Laser_LB_SR1V
  LD   (#LB_038+1),HL
//RET
__endasm;
} //_Laser_LB_160_3

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_161_3 (void) {
__asm
  LD   HL,#__Laser_LB_SL1V
  LD   (#LB_039+1),HL
//RET
__endasm;
} //_Laser_LB_161_3

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_162_3 (void) {
__asm
  LD   HL,#__Laser_LB_056
  LD   (#LB_040+1),HL
//RET
__endasm;
} //_Laser_LB_162_3

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_163_3 (void) {
__asm
  LD   HL,#__Laser_LB_056
  LD   (#LB_043+1),HL
//RET
__endasm;
} //_Laser_LB_163_3

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_164 (void) {
__asm
  LD   HL,#__Laser_LB_174
  LD   (#LB_188+1),HL
  CALL __Laser_LB_187
.globl LB_165
LB_165:
  LD   HL,#__Laser_LB_166
  LD   (#LB_188+1),HL
//RET
__endasm;
} //_Laser_LB_164

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_166 (void) __naked {
__asm
  PUSH BC
  PUSH DE
  CALL __Laser_LB_146
  POP  DE
  POP  BC
  LD   A,C
.globl LB_167
LB_167:
  PUSH AF
  CALL __Laser_LB_058
  JR   NC,#LB_171$
  XOR  A
LB_168$:
  LD   (#LB_183+1),A
  LD   (#LB_184),A
  POP  AF
  JR   LB_170$
.globl LB_169
LB_169:
  PUSH AF
  CALL __Laser_LB_058
  JR   NC,#LB_171$
  LD   A,#0xEB
  JR   LB_168$
LB_170$:
  LD   (#_LB_069+2),HL
  LD   (#LB_179),DE
  CALL _Laser_ATOF
  PUSH BC
  CALL __Laser_LB_146
  PUSH DE
  CALL __Laser_LB_185
  JR   C,#LB_172$
  POP  BC
LB_171$:
  POP  DE
  RET
LB_172$:
  LD   A,(#LB_179+1)
  LD   E,A
  LD   D,#0x00
  LD   H,#0x00
  LD   (#LB_179+2),HL
  CALL __Laser_LB_107
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  ADD  HL,DE
  LD   D,#0x00
  LD   A,(#LB_179)
  LD   E,A
  ADD  HL,DE
  LD   DE,(#_LB_069+2)
  EX   DE,HL
  POP  BC
.globl LB_173
LB_173:
  PUSH HL
  LD   HL,#LB_183
  LD   (#LB_087+1),HL
  XOR  A
  POP  HL
  JP   LB_057
__endasm;
} //_Laser_LB_166

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_174 (void) __naked {
__asm
  PUSH BC
  PUSH DE
  CALL __Laser_LB_146
  POP  DE
  POP  BC
  LD   A,C
  JP   LB_169
__endasm;
} //_Laser_LB_174

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_177 (void) {
__asm
  PUSH HL
  LD   HL,#__Laser_LB_186+2
  LD   (_LB_SL1M+1),HL
  LD   HL,#0x0000
.globl LB_178
LB_178:
  LD   (#LB_175),HL
  LD   (#LB_175+2),HL
  LD   (#LB_175+4),HL
  POP  HL
  //RET
__endasm;
} //_Laser_LB_177

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_179 (void) __naked {
__asm
.globl LB_179
LB_179:
  NOP
  NOP
  NOP
  NOP
__endasm;
} //_Laser_LB_179

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_182 (void) {
__asm
  LD   DE,(#__Laser_LB_186)
.globl LB_183
LB_183:
  PUSH DE
  NOP
  .DB  #0xED
  .DB  #0xB0
  NOP
.globl LB_184
LB_184:
  NOP
  POP  DE
  LD   HL,(#LB_179+2)
  ADD  HL,DE
  EX   DE,HL
  LD   (#__Laser_LB_186),DE
  //RET
__endasm;
} //_Laser_LB_182

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_185 (void) {
__asm
  LD   A,(#_LB_069+3)
  LD   C,A
  LD   A,(#LB_179+1)
  ADD  A,C
  DEC  A
  SUB  H
  RET  NC
  LD   A,(#_LB_069+2)
  LD   C,A
  LD   A,(#LB_179)
  ADD  A,C
  DEC  A
  SUB  L
//RET
__endasm;
} //_Laser_LB_185

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_186 (void) {
__asm
  .DB  0,0
  CALL __Laser_LB_189
  LD   DE,(#_LB_075)
  EX   DE,HL
//RET
__endasm;
} //_Laser_LB_186

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_187 (void) __naked {
__asm
  LD   A,#0xC9
  LD   (#LB_173),A
  LD   (#__Laser_LB_058+1),A
  LD   A,#0x37
  LD   (#__Laser_LB_058),A
  LD   A,B
  OR   A
.globl LB_188
LB_188:
  CALL __Laser_LB_166
  LD   A,#0x7C
  LD   (#__Laser_LB_058),A
  LD   A,#0x80
  LD   (#__Laser_LB_058+1),A
  LD   A,#0xE5
  LD   (#LB_173),A
  LD   A,B
  LD   (#__Laser_LB_186),DE
  LD   DE,#__Laser_LB_182
  JP   LB_156
__endasm;
} //_Laser_LB_187

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_189 (void) {
__asm
  CALL __Laser_LB_146
  LD   (#_LB_075),HL
  PUSH DE
  LD   D,#0x00
  LD   E,H
  LD   H,#0x00
  CALL __Laser_LB_107
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  POP  DE
  ADD  HL,DE
//RET
__endasm;
} //_Laser_LB_189

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_190 (void) __naked {
__asm
  LD   IX,#LB_167
  LD   (#LB_192+1),IX
  LD   IX,#__Laser_GWAT
.globl LB_191
LB_191:
  LD   (#LB_193$+1),IX
  LD   IX,(#__Laser_LB_100+3)
  PUSH IX
  PUSH AF
  PUSH BC
  PUSH DE
  PUSH HL
  PUSH IX
.globl LB_192
LB_192:
  CALL LB_167
  POP  HL
  LD   (#__Laser_LB_100+3),HL
  LD   A,L
  CP   #0xD0
  POP  HL
  POP  DE
  POP  BC
  JR   NZ,#LB_194$
  POP  AF
LB_193$:
  CALL __Laser_GWAT
  POP  HL
  LD   (#__Laser_LB_100+3),HL
  RET
LB_194$:
  POP  AF
  JR   LB_193$+3
__endasm;
} //_Laser_LB_190

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_195 (void) __naked {
__asm
  LD   IX,#LB_169
  LD   (#LB_192+1),IX
  LD   IX,#PWAT$
  JP   LB_191 // Was: JR
PWAT$:
  PUSH AF
  LD   A,#0xEB
  JP   LB_208 // Was: JR
__endasm;
} //_Laser_LB_195

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_196 (void) __naked {
// Used by: PTBL
__asm
  LD   (#LB_197$+1),HL
  LD   (#LB_198$+1),DE
  PUSH BC
  CALL __Laser_LB_146
  POP  BC
  LD   D,A
  CALL __Laser_LB_058
  LD   A,D
LB_197$:
  JP   C,0 //#__Laser_LB_147
  LD   (#LB_199$+1),A
  CALL __Laser_LB_059
LB_199$:
  LD   A,#0 //(#LB_199$)
  RET  NC
LB_198$:
  JP   0 //__Laser_GWBL
//LB_199$:
  //NOP
  //NOP //?
  //NOP //?
//RET
__endasm;
} //_Laser_LB_196

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_202 (void) {
__asm
  PUSH AF
  PUSH HL
  XOR  A
  LD   HL,#0xB0ED
.globl LB_203
LB_203:
  LD   (#LB_183+2),A
  LD   (#LB_183+3),HL
  POP  HL
  POP  AF
//RET
__endasm;
} //_Laser_LB_202

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_204 (void) __naked {
__asm
  PUSH AF
  PUSH HL
  LD   A,#0xB6
.globl LB_205
LB_205:
  LD   (#LB_085+1),A
  LD   A,#0xCD
  LD   HL,#__Laser_LB_084
  JP   LB_203 // Was: JR
__endasm;
} //_Laser_LB_204

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_209 (void) {
__asm
  LD   (#LB_179),DE
  PUSH AF
  CALL __Laser_LB_058
  JR   NC,#LB_171_EX$
  POP  AF
  PUSH HL
  PUSH AF
  LD   H,B
  LD   L,C
  LD   BC,#0x0020
  LD   (#__Laser_LB_212),BC
  CALL __Laser_LB_105
.globl LB_210
LB_210:
  EX   (SP),HL
  LD   A,H
  // CALL LB_217$
  // inline
LB_217$:
  PUSH BC
  PUSH DE
  CALL __Laser_LB_189
  LD   B,H
  LD   C,L
  POP  DE
  PUSH DE
  LD   E,D
  LD   D,#0x00
  LD   H,#0x00
  LD   A,(#_LB_075)
  LD   L,A
  CALL __Laser_LB_107
  ADD  HL,BC
  POP  DE
  LD   D,#0x00
  ADD  HL,DE
  POP  BC
  //RET
  // end
  
  POP  DE
  EX   DE,HL
  LD   BC,(#_LB_075)
  LD   B,#0x00
  LD   (#__Laser_LB_212+2),BC
  POP  BC
  //CALL __Laser_LB_215
  // inline
  PUSH DE
  LD   DE,(#LB_179)
  PUSH HL
  LD   HL,(#_LB_075)
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
//RET
  // end
  LD   A,C
  RET  NC
LB_211$:
  CALL __Laser_LB_212+4
  DJNZ LB_211$
  RET

LB_171_EX$:
  POP  DE
//RET
__endasm;
} //_Laser_LB_209

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_212 (void) {
__asm
  NOP
  NOP
  NOP
  NOP
  PUSH BC
  PUSH DE
  PUSH HL
  LD   B,#0x00
  LD   C,A
.globl LB_213
LB_213:
  NOP
  LDIR
.globl LB_214
LB_214:
  NOP
  POP  HL
  LD   BC,(#__Laser_LB_212)
  ADD  HL,BC
  EX   (SP),HL
  LD   BC,(#__Laser_LB_212+2)
  ADD  HL,BC
  POP  DE
  POP  BC
  EX   DE,HL
//RET
__endasm;
} //_Laser_LB_212

/*--------------------------------- Cut here ---------------------------------*/

/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*    HOME VIDEO GAMES Ent.     */
/*        version 3.17          */
/*            1997              */
/* ---------------------------- */


/* ---------------------------- */
//.globl SCRL_B
//SCRL_B: .DW #0x5B00 /* Buffer vor vertical scroll */

/*--------------------------------- Cut here ---------------------------------*/

/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*    HOME VIDEO GAMES Ent.     */
/*        version 3.17          */
/*            1997              */
/*          P A R T  1          */
/* ---------------------------- */

void _Laser_LB_001 (void) __naked {
__asm
  LD   DE,#__Laser_LB_052
  LD   (#LB_050+1+1),DE
  LD   (#LB_051+1),DE
  LD   DE,#__Laser_LB_049
.globl LB_002
LB_002:
  CALL __Laser_LB_013
  LD   DE,#__Laser_LB_052+2
  LD   (#LB_050+1+1),DE
  LD   (#LB_051+1),DE
//RET
__endasm;
} //_Laser_LB_001

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_006 (void) {
__asm
  CALL __Laser_LB_007
  LD   DE,(#_SCRL_B)
  EX   DE,HL
  LD   B,#0x00
  LDIR
  LD   HL,(#_SCRL_B)
  LD   (HL),#0x00
//RET
__endasm;
} //_Laser_LB_006
  
/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_007 (void) __naked {
__asm
  PUSH HL
  PUSH BC
  POP  HL
  POP  BC
  PUSH BC
  CALL __Laser_LB_105
  POP  BC
.globl LB_008
LB_008:
  //CALL __Laser_LB_012
  // inline
  PUSH HL
  PUSH BC
  LD   B,#0x00
  LD   DE,(#_SCRL_B)
  LDIR
  POP  BC
  POP  HL
  //end
  LD   A,B
LB_009$:
  DEC  A
  RET  Z
  PUSH BC
  PUSH HL
  LD   B,#0x00
.globl LB_010
LB_010:
  LD   DE,#0x0020
  OR   A
.globl LB_011
LB_011:
  ADC  HL,DE
  POP  DE
  PUSH HL
  LDIR
  POP  HL
  POP  BC
  JR   LB_009$
__endasm;
} //_Laser_LB_007

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_015 (void) __naked {
__asm
  NOP
  CALL __Laser_LB_068
  LD   (#_LB_069),A
  OR   A
  RET  Z
  CALL __Laser_LB_021
  RET  NC
  SLA  B
  SLA  B
  SLA  B
  LD   A,(#_LB_069)
  BIT  7,A
  JR   Z,#LB_016$
  LD   A,H
  ADD  A,B
  LD   B,A
  DEC  B
  LD   A,(#_LB_069)
  NEG
  PUSH HL
  LD   HL,#0x0515
  LD   (#LB_018$),HL
  LD   HL,#LB_027
  LD   (HL),#0x05
  POP  HL
LB_016$:
  SUB  H
  NEG
  LD   (#__Laser_LB_015),A
  PUSH BC
  PUSH HL
  CALL __Laser_LB_023
  POP  HL
  POP  BC
  LD   A,(#_LB_069)
  LD   E,C
  LD   D,B
  ADD  A,D
  LD   D,A
  LD   A,(#__Laser_LB_015)
LB_017$:
  PUSH BC
  PUSH DE
  PUSH HL
  PUSH AF
  //CALL __Laser_LB_029
  //inline
  PUSH HL
  PUSH DE
  CALL LB_022+3
  POP  BC
  PUSH HL
  CALL LB_022+3
  POP  DE
  POP  BC
  LD   B,#0x00
  LDIR
  //RET
  //end
  POP  AF
  POP  HL
  POP  DE
  POP  BC
LB_018$:
  INC  D
  INC  B
  DEC  A
  JR   NZ,#LB_017$
  LD   A,(#_LB_069)
  BIT  7,A
.globl LB_019
LB_019:
  JP   Z,#LB_032
  PUSH HL
  LD   HL,#0x0414
  LD   (#LB_018$),HL
  POP  HL
.globl LB_020
LB_020:
  CALL LB_032
  LD  HL,#LB_027
  LD  (HL),#0x04
  //RET
__endasm;
} //_Laser_LB_015

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_SCRV (void) {
__asm
  CALL __Laser_LB_068
  PUSH HL
  LD   HL,#__Laser_LB_030
  LD   (#LB_019+1),HL
  LD   (#LB_020+1),HL
  POP  HL
  CALL __Laser_LB_015+1
  LD   HL,#LB_032
  LD   (#LB_019+1),HL
  LD   (#LB_020+1),HL
  //RET
__endasm;
} //_Laser_LB_SCRV

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_023 (void) {
__asm
  NOP
  LD   DE,(#_SCRL_B)
  LD   A,(#_LB_069)
  BIT  7,A
  JR   Z,#LB_024$
  NEG
LB_024$:
  LD   H,#0x00
  PUSH BC
  PUSH AF
  PUSH DE
  PUSH HL
  CALL LB_022+3
  POP  BC
  POP  DE
  PUSH BC
.globl LB_025
LB_025:
  NOP
  LDIR
.globl LB_026
LB_026:
  NOP
  POP  HL
  POP  AF
  POP  BC
  DEC  A
  JR   Z,#LB_028$
.globl LB_027
LB_027:
  INC  B
  JR   LB_024$+2
LB_028$:
  LD   HL,(#_SCRL_B)
  OR   A
  EX   DE,HL
  SBC  HL,DE
  LD   (#_LB_069+2),HL
  //RET
__endasm;
} //_Laser_LB_023

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_030 (void) {
__asm
  PUSH HL
  PUSH BC
  PUSH DE
  LD   HL,(#_SCRL_B)
  LD   BC,(#_LB_069+2)
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
.globl LB_032
LB_032:
  PUSH HL
  LD   HL,#LB_025
  LD   (HL),#0xEB
  LD   HL,#LB_026
  LD   (HL),#0xEB
  POP  HL
  CALL __Laser_LB_023
  XOR  A
  LD   (#__Laser_LB_023),A
  LD   (#LB_025),A
  LD   (#LB_026),A
  //RET
__endasm;
} //_Laser_LB_030

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_034 (void) {
__asm
  PUSH HL
  CALL __Laser_LB_033
  POP  HL
  RET  NC
  SET  7,(HL)
  NEG
  //RET
__endasm;
} //_Laser_LB_034

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_037 (void) {
__asm
  CALL __Laser_LB_035
  RET  NC
  SET  0,(HL)
  //RET
__endasm;
} //_Laser_LB_037

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_048 (void) {
__asm
  CALL __Laser_LB_047
  LD   (DE),A
  //RET
__endasm;
} //_Laser_LB_048

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_049 (void) {
__asm
  LD   E,L
  LD   D,H
  ADD  HL,BC
  DEC  HL
  EX   DE,HL
  SRL  C
  JR   NC,#LB_050
  INC  C
.globl LB_050
LB_050:
  LD   A,(HL)
  CALL __Laser_LB_052+2
  LD   A,(DE)
  PUSH BC
.globl LB_051
LB_051:
  CALL __Laser_LB_052+2
  POP  AF
  LD   (DE),A
  LD   (HL),B
  DEC  DE
  INC  HL
  DEC  C
  JR   NZ,LB_050
  //RET
__endasm;
} //_Laser_LB_049

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_052 (void) {
__asm
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
  //RET
__endasm;
} //_Laser_LB_052

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_053 (void) {
__asm
  LD   B,C
  LD   A,(HL)
  CPL
  LD   (HL),A
  INC  HL
  DJNZ __Laser_LB_053+1
  //RET
__endasm;
} //_Laser_LB_053

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_055 (void) {
__asm
  XOR  A
  LD   B,#0x00
  LD   (HL),A
  DEC  C
  RET  Z
  LD   D,H
  LD   E,L
  INC  DE
  LDIR
  //RET
__endasm;
} //_Laser_LB_055

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_065 (void) __naked {
__asm
  PUSH AF
  PUSH BC
  PUSH BC
  CALL __Laser_LB_070
  POP  HL
  JR   C,#LB_067$
//LB_066$:
  POP  HL
  POP  HL
  RET
LB_067$:
  LD   E,H
  LD   D,#0x00
  LD   H,#0x00
  CALL __Laser_LB_107
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
  CALL __Laser_RLCT
  POP  BC
  POP  AF
  JP   __Laser_LB_079
__endasm;
}

/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*          v. 3.17             */
/*      E N D  P A R T  1       */
/* ---------------------------- */

/*--------------------------------- Cut here ---------------------------------*/
void __Asm_Laser_2__ (void) {
/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*    HOME VIDEO GAMES Ent.     */
/*        version 3.17          */
/*            1997              */
/*          P A R T  2          */
/* ---------------------------- */
__asm
LB_112$:
  SET  4,A
ADJM$:
  PUSH BC
  CALL __Laser_LB_146
  POP  BC
  CALL __Laser_LB_064
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
  CALL __Laser_LB_064
  LD   IX,(#LB_112$)
  JR   LB_113$
ISPR$:
  LD   B,H
  LD   C,L
  JP   __Laser_LB_065
SPRT$:
  LD   B,H
  LD   C,L
  JP   __Laser_LB_079
WSPR$:
  CALL __Laser_LB_146
  RET  C
  JP   __Laser_LB_080
DSPR$:
  PUSH HL
  PUSH AF
  CALL __Laser_LB_146
  POP  AF
  CALL WSPR$
  LD   DE,(#_SF_END)
  POP  HL
  OR   A
  SBC  HL,DE
  LD   B,H
  LD   C,L
  JP   __Laser_RLCT
MOVE$:
  LD   A,E
  PUSH DE
  PUSH HL
  PUSH BC
  CALL __Laser_LB_PTXR
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
  CALL __Laser_LB_PTXR
  POP  DE
  LD   HL,(#LB_112$)
  LD   BC,#0x000A
  ADD  HL,BC
  LD   (HL),D
  INC  HL
  LD   (HL),E
  RET

AWLM$:
  LD   DE,#__Laser_LB_046
  JP   LB_143$
AWRM$:
  LD   DE,#__Laser_LB_048
  JP   LB_143$
ASLM$:
  LD   DE,#__Laser_LB_045
  JP   LB_143$
ASRM$:
  LD   DE,#__Laser_LB_047
  JP   LB_143$
ATUM$:
  CALL __Laser_LB_189
  LD   DE,(#_LB_075)
LB_115$:
  LD   C,E
  LD   B,D
  LD   A,E
  LD   (#LB_010+1),A
  CALL LB_008
  CALL __Laser_LB_007+3
  LD   HL,#LB_010+1
  LD   (HL),#0x20
  RET
ATDM$:
  CALL __Laser_LB_146
  PUSH HL
  LD   L,C
  LD   H,B
  //CALL __Laser_LB_074
  //inline
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
  //end
  POP  HL
  EX   DE,HL
  LD   A,D
  LD   D,#0x00
  SBC  HL,DE
  LD   D,A
  LD   A,#0x52
  LD   (#LB_011+1),A
  CALL LB_115$
  LD   A,#0x5A
  LD   (#LB_011+1),A
  RET

LB_116$:
  NOP
  NOP
  NOP
SPNM$:
  NOP
  LD   A,B
  PUSH BC
  PUSH BC
  CALL __Laser_LB_146
  LD   (#LB_118$),HL
  POP  BC
  LD   A,C
  PUSH HL
  PUSH DE
  CALL __Laser_LB_146
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

LB_118$:
  NOP
  NOP
  LD   A,B
  PUSH BC
  CALL __Laser_LB_189
  POP  BC
  LD   A,C
  PUSH HL
  CALL __Laser_LB_189
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
  CALL __Laser_LB_146
  EX   (SP),HL
  POP  AF
  PUSH AF
  PUSH AF
  PUSH DE
  LD   A,L
  CALL __Laser_LB_146
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
  LD   (#LB_002+1),DE
  CALL __Laser_LB_001
  LD   DE,#__Laser_LB_013
  LD   (#LB_002+1),DE
  RET
LB_143$:
  CALL __Laser_LB_177
  CALL LB_156
  JP   __Laser_LB_159
MIRM$:
  LD   DE,#__Laser_LB_049
  JP   LB_156

SETM$:
  CALL __Laser_LB_189
  PUSH HL
  LD   HL,(#_LB_075)
  LD   E,H
  LD   H,#0x00
  LD   D,#0x00
  CALL __Laser_LB_107
  EX   (SP),HL
  POP  BC
  DEC  BC
  LD   A,B
  OR   C
  LD   A,(#SETV_A$)
  LD   (HL),A
  RET  Z
  INC  BC
  JP   LB_144
  
LB_153:
  LD   HL,#LB_085+1
  LD   (HL),#0xA6
  CALL __Laser_LB_151
  JP   LB_092_3

  LD   HL,(#LB_179+2)
  LD   H,#0x00
  LD   D,#0x00
  LD   E,B
  CALL __Laser_LB_107
  LD   DE,(#LB_179)
  ADD  HL,DE
  RET
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_200 (void) __naked {
__asm
  LD   HL,#__Laser_LB_149+3+1
  LD   (HL),#0x00
  CALL __Laser_LB_091
  JP   LB_155
__endasm;
} //_Laser_LB_200

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_201 (void) __naked {
__asm
  LD   HL,#__Laser_LB_149+3+1
  LD   (HL),#0x00
  CALL LB_153
  JP   LB_155
__endasm;
} //_Laser_LB_201

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_206 (void) __naked {
__asm
  PUSH AF
  PUSH HL
  LD   A,#0xA6
  JP   LB_205 // Was: JR
__endasm;
} //_Laser_LB_206

/*--------------------------------- Cut here ---------------------------------*/
void _Laser_LB_207 (void) __naked {
__asm
  PUSH AF
  PUSH HL
  LD   A,#0xAE
  JP   LB_205 // Was: JR
__endasm;
} //_Laser_LB_207

/* ---------------------------- */
/* LASER BASIC for ASSEMBLER ZX */
/*          v. 3.17             */
/*      E N D  P A R T  2       */
/* ---------------------------- */
