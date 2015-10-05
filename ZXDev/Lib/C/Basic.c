#include "SYSTEM.h"

export void Basic_Init_DI (void);
export void Basic_Init_IM0 (void);
export void Basic_Init_IM2 (void);
export void Basic_BORDER_stdcall (SHORTINT color);
export void Basic_COLOR_fastcall (void /* Register A */);
export void Basic_COLOR_stdcall (SHORTINT attr);
export void Basic_INK_stdcall (SHORTINT color);
export void Basic_INK_fastcall (void /* Register C */);
export void Basic_PAPER_stdcall (SHORTINT color);
export void Basic_PAPER_fastcall (void /* Register C */);
export void Basic_FLASH_stdcall (SHORTINT mode);
export void Basic_FLASH_fastcall (void /* Register C */);
export void Basic_BRIGHT_stdcall (SHORTINT mode);
export void Basic_BRIGHT_fastcall (void /* Register C */);
export void Basic_INVERSE_FAST (SHORTINT mode);
export void Basic_INVERSE_ROM_stdcall (SHORTINT mode);
export void Basic_INVERSE_ROM_fastcall (void /* Register C */);
export void Basic_OVER_FAST (SHORTINT mode);
export void Basic_OVER_ROM_stdcall (SHORTINT mode);
export void Basic_OVER_ROM_fastcall (void /* Register C */);
export void Basic_AT_FAST (SHORTINT y, SHORTINT x);
export void Basic_AT_ROM_stdcall (SHORTINT y, SHORTINT x);
export void Basic_AT_ROM_fastcall (void /* post */);
export void Basic_CLS_ZX (void);
export void Basic_CLS_FULLSCREEN (void);
export void Basic_PRSTR_C_FAST (CHAR *str);
export void Basic_PRSTR_C_ROM_stdcall (CHAR *str);
export void Basic_PRSTR_C_ROM_fastcall (void /* post */);
export void Basic_PRCHAR_FAST (CHAR ch);
export void Basic_PRCHAR_ROM (CHAR ch);
export void Basic_PRDATA (void);
export void Basic_PRLN (void);
export void Basic_PLOT (SHORTINT x, SHORTINT y);
export BYTE Basic_POINT (SHORTINT x, SHORTINT y);
export BYTE Basic_ATTR (SHORTINT y, SHORTINT x);
export void Basic_DRAW (SHORTINT x, SHORTINT y);
export void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius);
export void Basic_CIRCLEW_DI (SHORTINT cx, SHORTINT cy, INTEGER radius);
export void Basic_CIRCLEW_EI (SHORTINT cx, SHORTINT cy, INTEGER radius);
export void Basic_CIRCLEROM (SHORTINT cx, SHORTINT cy, SHORTINT radius);
export BYTE Basic_PORTIN (SYSTEM_ADDRESS port);
export void Basic_PORTOUT (SYSTEM_ADDRESS port, BYTE value);
export void Basic_PRINT_FAST (INTEGER i);
export void Basic_PRINT_ROM (INTEGER i);
export void Basic_PRWORD_FAST (CARDINAL n);
export void Basic_PRWORD_ROM (CARDINAL n);
export BOOLEAN Basic_KeyPressed (void);
export void Basic_PAUSE_DI_fastcall (void /* Regs BC */);
export void Basic_PAUSE_DI_stdcall (CARDINAL ticks);
export void Basic_PAUSE_EI_fastcall (void /* Regs BC */);
export void Basic_PAUSE_EI_stdcall (CARDINAL ticks);
export void Basic_RANDOMIZE (CARDINAL seed);
export SHORTCARD Basic_RND (SHORTCARD min, SHORTCARD max);
export CARDINAL Basic_RNDW (CARDINAL min, CARDINAL max);
export SHORTINT Basic_SGN (SHORTINT x);
export void Basic_BEEP_DI (CARDINAL ms, SHORTINT freq);
export void Basic_BEEP_EI (CARDINAL ms, SHORTINT freq);
export CHAR Basic_INKEY (void);
export void Basic_Quit_DI (void);
export void Basic_Quit_IM0 (void);
export void Basic_Quit_IM2 (void);

import CARDINAL _Basic_RandBB (void);

/* Set video attrib */
#define ATTR_P$ 0x5C8D
/* Video temp attrib */
#define ATTR_T$ 0x5C8F
/* (Font_address - 256) */
#define CHAR_SET$ 0x5C36
/*================================== Header ==================================*/

void Basic_Init_DI (void)
{
  __asm
  DI
//  LD   IY,#0x5C3A
  RES  4,1(IY) /* RESET OF 128K FLAG */
  __endasm;
} //Basic_Init_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Init_IM0 (void)
{
  __asm
  RES  4,1(IY) /* RESET OF 128K FLAG */
  __endasm;
} //Basic_Init_IM0

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Init_IM2 (void) __naked {
  __asm
  RES  4,1(IY) /* RESET OF 128K FLAG */

; ************************************************
; * Set IM2 mode (need for correct work with IY) *
; ************************************************
  LD   HL,#IM2PROC$
IMON$:
  LD   A,#24       ; код команды JR
  LD   (#65535),A
  LD   A,#195      ; код команды JP
  LD   (#65524),A
  LD   (#65525),HL ; в HL - адрес обработчика прерываний
  LD   HL,#0xFE00  ; построение таблицы для векторов прерываний
  LD   DE,#0xFE01
  LD   BC,#256     ; размер таблицы минус 1
  LD   (HL),#0xFF  ; адрес перехода #FFFF (65535)
  LD   A,H         ; запоминаем старший байт адреса таблицы
  LDIR             ; заполняем таблицу
  DI               ; запрещаем прерывания на время
                   ; установки второго режима
  LD    I,A        ; задаем в регистре I старший байт адреса
                   ; таблицы для векторов прерываний
  IM    2          ; назначаем второй режим прерываний
  EI               ; разрешаем прерывания
  RET

IM2PROC$:
  PUSH AF
  PUSH BC
  PUSH DE
  PUSH HL
  PUSH IX
  PUSH IY
  __endasm;
}
void Basic__IM2ADR (void) {
  __asm
  CALL IM2RET$
  POP  IY
  POP  IX
  POP  HL
  POP  DE
  POP  BC
  POP  AF
  EI
IM2RET$:
  __endasm;
} //Basic_Init_IM2

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BORDER_stdcall (SHORTINT color) __naked {
__asm
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C
  JP   0x229B // IX-safe
__endasm;
} //Basic_BORDER_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INK_stdcall (SHORTINT color) __naked {
__asm
  POP  HL
  POP  BC
  PUSH BC
  LD   A,(ATTR_P$)
  AND  #0xF8
  OR   C
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
  JP   (HL)
__endasm;
} //Basic_INK_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INK_fastcall (void /* Register C */) {
__asm
  LD   A,(ATTR_P$)
  AND  #0xF8
  OR   C
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
__endasm;
} //Basic_INK_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_COLOR_fastcall (void /* Register A */) {
__asm
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
__endasm;
} //Basic_COLOR_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_COLOR_stdcall (SHORTINT attr) __naked {
__asm
  POP  HL
  POP  BC
  PUSH BC
  LD   A,C
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
  JP   (HL)
__endasm;
} //Basic_COLOR_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAPER_stdcall (SHORTINT color) __naked {
__asm
  POP  HL
  POP  BC
  PUSH BC
  LD   A,(ATTR_P$)
  AND  #0xC7
  SLA  C
  SLA  C
  SLA  C
  OR   C
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
  JP   (HL)
__endasm;
} //Basic_PAPER_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAPER_fastcall (void /* Register C */) {
__asm
  LD   A,(ATTR_P$)
  AND  #0xC7
  SLA  C
  SLA  C
  SLA  C
  OR   C
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
__endasm;
} //Basic_PAPER_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_FLASH_stdcall (SHORTINT mode) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#18
  RST  16 // IX-safe
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_FLASH_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_FLASH_fastcall (void /* Register C */) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#18
  RST  16 // IX-safe
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_FLASH_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BRIGHT_stdcall (SHORTINT mode) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#19
  RST  16
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_BRIGHT_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BRIGHT_fastcall (void /* Register C */) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#19
  RST  16
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_BRIGHT_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INVERSE_FAST (SHORTINT mode) __naked {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  LD   A,C
  OR   A
  JR   Z,SetInvers$ /* If INVERSE 0 then poke NOP */
  LD   A,#0x2F      /*              else poke CPL */
SetInvers$:
  LD   (#_INV_MODE),A
  LD   A,#20
  RST  16
  LD   A,C
  RST  16
  JP   (HL)
__endasm;
} //Basic_INVERSE_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INVERSE_ROM_stdcall (SHORTINT mode) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#20
  RST  16 // IX-safe
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_INVERSE_ROM_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INVERSE_ROM_fastcall (void /* Register C */) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#20
  RST  16 // IX-safe
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_INVERSE_ROM_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_OVER_FAST (SHORTINT mode) __naked {
__asm // !!! NEED to be checked to IX-safety
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  LD   A,C
  OR   A
  JR   Z,SetOver$ /* If OVER 0 then poke NOP      */
  LD   A,#0xAE    /*           else poke XOR (HL) */
SetOver$:
  LD   (#_OVER_MODE),A
  LD   A,#21
  RST  16
  LD   A,C
  RST  16
  JP   (HL)
__endasm;
} //Basic_OVER_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_OVER_ROM_stdcall (SHORTINT mode) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#21
  RST  16 // IX-safe
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_OVER_ROM_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_OVER_ROM_fastcall (void /* Register C */) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#21
  RST  16 // IX-safe
  LD   A,C
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_OVER_ROM_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_ROM_stdcall (SHORTINT y, SHORTINT x) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601 // IX-safe
  LD   A,#22
  RST  16
  POP  HL
  POP  BC
  PUSH BC
  LD   A,C     // y
  RST  16
  LD   A,B     // x
  RST  16
  JP   (HL)
__endasm;
} //Basic_AT_ROM_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_ROM_fastcall (void /* post */) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601 // IX-safe
  LD   A,#22
  RST  16
  POP  HL
  LD   A,(HL)  // y
  RST  16
  INC  HL
  LD   A,(HL)  // x
  RST  16
  INC  HL
  JP   (HL)
__endasm;
} //Basic_AT_ROM_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_FAST (SHORTINT y, SHORTINT x) {
__asm
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C     // y
  CALL 0xE9E
  LD   A,B     // x
  ADD  A,L
  LD   L,A
  LD   (#23684),HL
__endasm;
} //Basic_AT_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CLS_ZX (void)
{
__asm
  LD   IY,#0x5C3A
  CALL 0xD6B // IX-safe
  LD   A,(ATTR_P$)
  LD   (ATTR_T$),A
__endasm;
} //Basic_CLS_ZX

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CLS_FULLSCREEN (void)
{
__asm
  LD   IY,#0x5C3A
  LD   A,(#0x5C48)
  PUSH AF
  LD   A,(ATTR_P$)
  LD   (#0x5C48),A
  CALL 0xD6B // IX-safe
  POP  AF
  LD   (#0x5C48),A
  LD   A,(ATTR_P$)
  LD   (ATTR_T$),A
__endasm;
} //Basic_CLS_FULLSCREEN

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRSTR_C_ROM_stdcall (CHAR *str) __naked {
/*
  INTEGER i;
  i = 0;
  while (str[i] != 0x00) {
    PRCHAR(str[i]);
    i += 1;
  }
*/
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
PRSTRstd$:
  LD   A,(BC)
  OR   A
  RET  Z
  RST  16
  INC  BC
  JR   PRSTRstd$
__endasm;
} //Basic_PRSTR_C_ROM_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRSTR_C_ROM_fastcall (void /* post */) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601
PRSTRfst$:
  POP  HL
  LD   A,(HL)
  INC  HL
  PUSH HL
  OR   A
  RET  Z
  RST  16
  JR   PRSTRfst$
__endasm;
} //Basic_PRSTR_C_ROM_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRSTR_C_FAST (CHAR *str) __naked {
__asm
.globl _INV_MODE
.globl _OVER_MODE
  POP  DE
  POP  HL
  PUSH HL
  PUSH DE
pr_sta$:
  LD   A,(HL)
  OR   A
  RET  Z
  PUSH HL
  LD   L,A
  BIT  7,A
  JR   NZ,PO_GR$
  LD   H,#0
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  LD   DE,(#CHAR_SET$)
  ADD  HL,DE
  JR   USER_FONT$
PO_GR_BUF$:
  .DB  #0,#0,#0,#0,#0,#0,#0,#0
PO_GR$:
  LD   B,A
  LD   HL,#PO_GR_BUF$
  PUSH HL
  CALL 0xB3E /* Generate po_gr char to buffer */
  CALL 0xB3E
  POP  HL
USER_FONT$:
  LD   DE,(#23684)
  EX   DE,HL
  PUSH HL
  LD   B,#8
p_Sy1$:
  LD   A,(DE)
_INV_MODE:
  NOP
_OVER_MODE:
  NOP
  LD   (HL),A
  INC  DE
  INC  H
  DJNZ p_Sy1$
  POP  HL
  PUSH HL
  LD   A,H
  AND  #0x18
  RRCA
  RRCA
  RRCA
  ADD  A,#0x58
  LD   H,A
  LD   A,(ATTR_P$)
  LD   (HL),A
  POP  HL
  INC  L
  JR   NZ,p_Sy2$
  LD   A,H
  ADD  A,#8
  LD   H,A
  CP   #0x58
  JR   C,p_Sy2$
  LD   H,#0x40
p_Sy2$:
  LD   (#23684),HL
  POP  HL
  INC  HL
  JR   pr_sta$
__endasm;
} //Basic_PRSTR_C_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRCHAR_ROM (CHAR ch) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601
  POP  HL
  POP  BC
  PUSH BC
  LD   A,C
  RST  16
  JP   (HL)
__endasm;
} //Basic_PRCHAR_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRCHAR_FAST (CHAR ch)
{
  CHAR str[2];
  str[0] = ch; str[1] = '\x0'; Basic_PRSTR_C_FAST(str);
} //Basic_PRCHAR_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRDATA (void)
{
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601
  POP  HL
PRDATA$:
  LD   A,(HL)
  OR   A
  JR   Z,PRDATA_EX$
  RST  16
  INC  HL
  JR   PRDATA$
PRDATA_EX$:
  JP   (HL)
__endasm;
} //Basic_PRDATA

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRLN (void)
{
  Basic_PRCHAR_ROM('\x0D');
}

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PLOT (SHORTINT x, SHORTINT y) __naked {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  JP   0x22E5
  //LD   (0x5C7D),BC
  //LD   A,#0xBF
  //CALL 0x22AC
  //JP   0x22EC
__endasm;
} //Basic_PLOT

/*--------------------------------- Cut here ---------------------------------*/
BYTE Basic_POINT (SHORTINT x, SHORTINT y) {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  CALL 0x22CE
  CALL 0x2DD5
  LD   L,A
__endasm;
} //Basic_POINT

/*--------------------------------- Cut here ---------------------------------*/
BYTE Basic_ATTR (SHORTINT y, SHORTINT x) {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  CALL 0x2583
  CALL 0x2DD5
  LD   L,A
__endasm;
} //Basic_ATTR

/*--------------------------------- Cut here ---------------------------------*/
void Basic_DRAW (SHORTINT x, SHORTINT y) __naked {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   HL,(#0x5C7D)
  LD   DE,#0x0101
  LD   A,C
  ADD  L
  JR   NC,PositiveX$
  LD   A,C
  NEG
  LD   C,A
  LD   E,#0xFF
PositiveX$:
  LD   A,B
  ADD  H
  JR   NC,PositiveY$
  LD   A,B
  NEG
  LD   B,A
  LD   D,#0xFF
PositiveY$:
  JP   0x24BA
__endasm;
} //Basic_DRAW

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CIRCLE (SHORTINT cx, SHORTINT cy, SHORTINT radius) __naked {
  __asm
        POP  BC
        POP  HL     ; L = x; H = y
        POP  DE     ; E = radius
        PUSH DE
        PUSH HL
        PUSH BC
        LD   C, #0
        LD   B, E
LOOPCI$:
        CALL DOTCI$ ; sector 1
        LD   A, B
        NEG
        LD   B, A
        CALL DOTCI$ ; sector 4
        LD   A, C
        NEG
        LD   C, A
        CALL DOTCI$ ; sector 5
        LD   A, B
        NEG
        LD   B, A
        CALL DOTCI$ ; sector 8
        LD   A, C
        LD   C, B
        LD   B, A
        CALL DOTCI$ ; sector 3
        LD   A, C
        NEG
        LD   C, A
        CALL DOTCI$ ; sector 6
        LD   A, B
        NEG
        LD   B, A
        CALL DOTCI$ ; sector 7
        LD   A, C
        NEG
        LD   C, A
        CALL DOTCI$ ; sector 8
        LD   A, C
        LD   C, B
        LD   B, A
        INC  C
        LD   A, E
        SUB  C
        LD   E, A
        JR   NC, LOOPCI$
        DEC  B
        LD   A, E
        ADD  A, B
        LD   E, A
        LD   A, B
        CP   C
        JR   NC, LOOPCI$
        RET

DOTCI$: PUSH HL
        PUSH DE
        PUSH BC
        LD   A, H
        ADD  A, B
        LD   B, A
        LD   A, L
        ADD  A, C
        LD   C, A
        CALL 0x22E5
        POP  BC
        POP  DE
        POP  HL
        RET
__endasm;
} //Basic_CIRCLE

/*--------------------------------- Cut here ---------------------------------*/
/*
void Basic_CIRCLEW (SHORTINT cx, SHORTINT cy, INTEGER radius) {
  SHORTINT x, y;
  INTEGER rr, xx, yy;
  x = radius; y = 0; rr = x*x; xx = rr-x; yy = 0;
  do {
    Basic_PLOT(cx+x, cy+y); Basic_PLOT(cx-x, cy+y);
    Basic_PLOT(cx+x, cy-y); Basic_PLOT(cx-x, cy-y);
    Basic_PLOT(cx+y, cy+x); Basic_PLOT(cx-y, cy+x);
    Basic_PLOT(cx+y, cy-x); Basic_PLOT(cx-y, cy-x);
    yy += y+y+1; y++;
    if (xx > (rr-yy)) {
      xx += 1-x-x; x--;
      Basic_PLOT(cx+x, cy+y); Basic_PLOT(cx-x, cy+y);
      Basic_PLOT(cx+x, cy-y); Basic_PLOT(cx-x, cy-y);
      Basic_PLOT(cx+y, cy+x); Basic_PLOT(cx-y, cy+x);
      Basic_PLOT(cx+y, cy-x); Basic_PLOT(cx-y, cy-x);
    }
  } while (x >= y);
*/
void Basic_CIRCLEW_DI (SHORTINT cx, SHORTINT cy, INTEGER radius) __naked {
  __asm
    LD   IY, #0x5C3A
    POP  DE
    POP  BC
    POP  HL
    PUSH HL
    PUSH BC
    PUSH DE
    LD   A, H
    OR   L
    RET  Z
    BIT  7, H
    RET  NZ
    PUSH IX
    LD   D, #0
    LD   E, C
    LD   C, B
    LD   B, D
    PUSH DE
    LD   DE, #0
    PUSH DE
    PUSH BC
    PUSH HL
    LD   IX, #0
    ADD  IX, SP
    PUSH HL
    EXX
    POP  HL
    ADD  HL, HL
    EX   DE, HL
    LD   HL, #3
    AND  A
    SBC  HL, DE
    EXX
    JR   ENT0$
CIRCLOOP0$:
    AND  A
    SBC  HL, DE
    JP   M, EXT0$
    POP  DE
    POP  HL
    ADD  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP0$
    POP  BC
    POP  HL
    POP  DE
    ADD  HL, DE
    EX   DE, HL
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP0$
    POP  DE
    POP  HL
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP0$
    POP  BC
    POP  HL
    POP  DE
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP0$
ENT0$:
    POP  DE
    POP  HL
    ADD  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP0$
    POP  BC
    POP  HL
    POP  DE
    ADD  HL, DE
    EX   DE, HL
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP0$
    POP  DE
    POP  HL
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP0$
    POP  BC
    POP  HL
    POP  DE
    LD   (POSITIV0$+1), DE
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP0$
    EXX
    EX   DE, HL
    BIT  7, D
    JR   Z, POSITIV0$
    LD   HL, (POSITIV0$+1)
    ADD  HL, HL
    ADD  HL, HL
    LD   BC, #6
    JR   CALCDONE0$
POSITIV0$:
    LD   HL, #0
    POP  BC
    DEC  BC
    PUSH BC
    AND  A
    SBC  HL, BC
    ADD  HL, HL
    ADD  HL, HL
    LD   BC, #0xA
CALCDONE0$:
    ADD  HL, BC
    ADD  HL, DE
    EXX
    POP  HL
    POP  DE
    POP  DE
    INC  DE
    PUSH DE
    LD   SP, IX
    JP   CIRCLOOP0$
EXT0$:
    LD   HL, #8
    ADD  HL, SP
    LD   SP, HL
    POP  IX
    RET
WRAP0$:
    LD   A, D
    OR   A
    RET  NZ
    LD   A, E
    CP   #0xB0
    RET  NC
    LD   A, H
    OR   A
    RET  NZ
    LD   B, E
    LD   C, L
WRAP01$: // fixed for OVER 1 by Destr
    LD   HL, #0xFFFF
    LD   (WRAP01$+1), BC
    SBC  HL, BC
    JP   NZ, 0x22E5
    RET
  __endasm;
} //Basic_CIRCLEW_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CIRCLEW_EI (SHORTINT cx, SHORTINT cy, INTEGER radius) __naked {
  __asm
    LD   IY, #0x5C3A
    POP  DE
    POP  BC
    POP  HL
    PUSH HL
    PUSH BC
    PUSH DE
    LD   A, H
    OR   L
    RET  Z
    BIT  7, H
    RET  NZ
    PUSH IX
    DI
    LD   D, #0
    LD   E, C
    LD   C, B
    LD   B, D
    PUSH DE
    LD   DE, #0
    PUSH DE
    PUSH BC
    PUSH HL
    LD   IX, #0
    ADD  IX, SP
    PUSH HL
    EXX
    POP  HL
    ADD  HL, HL
    EX   DE, HL
    LD   HL, #3
    AND  A
    SBC  HL, DE
    EXX
    JR   ENT1$
CIRCLOOP1$:
    AND  A
    SBC  HL, DE
    JP   M, EXT1$
    POP  DE
    POP  HL
    ADD  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP1$
    POP  BC
    POP  HL
    POP  DE
    ADD  HL, DE
    EX   DE, HL
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP1$
    POP  DE
    POP  HL
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP1$
    POP  BC
    POP  HL
    POP  DE
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP1$
ENT1$:
    POP  DE
    POP  HL
    ADD  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP1$
    POP  BC
    POP  HL
    POP  DE
    ADD  HL, DE
    EX   DE, HL
    POP  HL
    AND  A
    SBC  HL, BC
    LD   SP, IX
    CALL WRAP1$
    POP  DE
    POP  HL
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  BC
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP1$
    POP  BC
    POP  HL
    POP  DE
    LD   (POSITIV1$+1), DE
    AND  A
    SBC  HL, DE
    EX   DE, HL
    POP  HL
    ADD  HL, BC
    LD   SP, IX
    CALL WRAP1$
    EXX
    EX   DE, HL
    BIT  7, D
    JR   Z, POSITIV1$
    LD   HL, (POSITIV1$+1)
    ADD  HL, HL
    ADD  HL, HL
    LD   BC, #6
    JR   CALCDONE1$
POSITIV1$:
    LD   HL, #0
    POP  BC
    DEC  BC
    PUSH BC
    AND  A
    SBC  HL, BC
    ADD  HL, HL
    ADD  HL, HL
    LD   BC, #0xA
CALCDONE1$:
    ADD  HL, BC
    ADD  HL, DE
    EXX
    POP  HL
    POP  DE
    POP  DE
    INC  DE
    PUSH DE
    LD   SP, IX
    JP   CIRCLOOP1$
EXT1$:
    LD   HL, #8
    ADD  HL, SP
    LD   SP, HL
    POP  IX
    EI
    RET
WRAP1$:
    LD   A, D
    OR   A
    RET  NZ
    LD   A, E
    CP   #0xB0
    RET  NC
    LD   A, H
    OR   A
    RET  NZ
    LD   B, E
    LD   C, L
WRAP11$: // fixed for OVER 1 by Destr
    LD   HL, #0xFFFF
    LD   (WRAP11$+1), BC
    SBC  HL, BC
    JP   NZ, 0x22E5
    RET
  __endasm;
} //Basic_CIRCLEW_EI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CIRCLEROM (SHORTINT cx, SHORTINT cy, SHORTINT radius) __naked {
__asm
  LD   IY,#0x5C3A
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
  LD   A,4(IX) /* cx */
  CALL 0x2D28
  LD   A,5(IX) /* cy */
  CALL 0x2D28
  LD   A,6(IX) /* radius */
  CALL 0x2D28
  CALL 0x232D
  POP  IX
  LD   A,(ATTR_P$)
  LD   (ATTR_T$),A
  RET
__endasm;
} //Basic_CIRCLEROM

/*--------------------------------- Cut here ---------------------------------*/
BYTE Basic_PORTIN (SYSTEM_ADDRESS port) {
__asm
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  IN   L,(C)
__endasm;
} //Basic_PORTIN

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PORTOUT (SYSTEM_ADDRESS port, BYTE value) __naked {
__asm
  POP  HL
  POP  BC
  POP  DE
  LD   A,E
  OUT  (C),A
  PUSH DE
  PUSH BC
  JP   (HL)
__endasm;
} //Basic_PORTOUT

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRINT_FAST (INTEGER i) {
  CHAR b[6], *prt;
  INTEGER j;
  j = 5;
  b[5] = 0x00;
  do {
    if (i < 0) {
      Basic_PRSTR_C_FAST("-");
      if (i == -32768) {
        Basic_PRSTR_C_FAST("32768");
        return;
      }
      i = -i;
    }
    j -= 1;
    b[j] = (CHAR)((int)__MOD(i, 10) + 48);
    i = __DIV(i, 10);
  } while (!(j == 0));
  for(prt = b; prt<b+4; prt++) {if(*prt!='0') break;}
  Basic_PRSTR_C_FAST(prt);
} //Basic_PRINT_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRINT_ROM (INTEGER i) {
  CHAR b[6], *prt;
  INTEGER j;
  j = 5;
  b[5] = 0x00;
  do {
    if (i < 0) {
      Basic_PRSTR_C_ROM_stdcall("-");
      if (i == -32768) {
        Basic_PRSTR_C_ROM_stdcall("32768");
        return;
      }
      i = -i;
    }
    j -= 1;
    b[j] = (CHAR)((int)__MOD(i, 10) + 48);
    i = __DIV(i, 10);
  } while (!(j == 0));
  for(prt = b; prt<b+4; prt++) {if(*prt!='0') break;}
  Basic_PRSTR_C_ROM_stdcall(prt);
} //Basic_PRINT_ROM

/*
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   C,4(IX)
  LD   B,5(IX)
  CALL 0x2D2B // BC-TO-FP
  BIT  7,5(IX)
  JR   Z,Positive$
Negative$:
  LD   BC,#0xFFFF
  RST  0x28  // FP_CALC
  .DB  #0xA1 // 1
  .DB  #0x0F // ADD
  .DB  #0x1B // NEG
  .DB  #0x03 // SUB
  .DB  #38   // end-calc
Positive$:
  LD   A,#2
  CALL 0x1601
  CALL 0x2DE3 // PRINT-FP
#ifdef __SDCC
  POP  IX
#endif
__endasm;
}
*/

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRWORD_FAST (CARDINAL n) {
  CHAR b[6], *prt;
  CARDINAL j;
  j = 5;
  b[5] = 0x00;
  do {
    j -= 1;
    b[j] = (CHAR)((unsigned int)__MOD(n, 10) + 48);
    n = n / 10;
  } while (!(j == 0));
  for(prt = b; prt<b+4; prt++) {if(*prt!='0') break;}
  Basic_PRSTR_C_FAST(prt);
} //Basic_PRWORD_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRWORD_ROM (CARDINAL n) __naked {
__asm
          LD    IY,#0x5C3A
          LD    A,#2
          CALL  #0x1601
          POP   DE
          POP   HL
          PUSH  HL
          PUSH  DE
/* Из журнала Deja Vu #04, Кемерово, 01.04.98
    (c) Колотов Сеpгей, г.Шадpинск, SerzhSoft
Доработано для печати только значащих цифр */
;----------------------------------------;
;Печать десятичного числа в HL (0..65535)
;----------------------------------------;
          PUSH  HL            ;закинули печатаемое число на стек
          LD    HL,#DECTB_W$  ;адрес таблицы степеней десятки
          LD    BC,#0x505     ;макс. возможное количество цифр: 5
          ;установим также рег. C - кол-во незначащих нулей + 1
LP_PDW1$: XOR   A             ;обнулили счётчик и флаг C для SBC
          LD    E,(HL)        ;взяли текущую степень
          INC   HL            ; десятки из таблицы
          LD    D,(HL)        ; и поместили в DE
          INC   HL            ;перешли к след. элементу таблицы
          EX    (SP),HL       ;адрес эл-та <-> печатаемое число
LP_PDW2$: INC   A             ;увеличиваем счётчик
          SBC   HL,DE         ;вычитаем текущую степень десятки
          JR    NC,LP_PDW2$   ;повторяем пока HL>=0
          ADD   HL,DE         ;HL=HL mod DE; A=HL div DE
          DEC   C             ;проверяем: может это незначащий нуль?
          JR    Z,LP_PRNT$    ; если уже были другие цифры, печатаем
          DEC   A             ;если это нуль, то он незначащий
          JR    Z,LP_NOPR$    ; ничего не печатаем
          INC   A             ;это не нуль, увеличим на 1 для печати
LP_PRNT$: ADD   A,#"0"-1      ;перевод A в ASCII-код ("0".."9")
          RST   0x10          ;печать десятичной цифры
          LD    C,#1          ;уже была печать, дальше все значащие
LP_NOPR$: EX    (SP),HL       ;HL=адрес эл-та, число -> на стек
          DJNZ  LP_PDW1$      ;цикл по цифрам
          POP   HL            ;убрали оставшийся ноль со стека
          RET                 ;выход из процедуры
;----------------------------------------;
DECTB_W$: .DW   10000,1000,100,10,1  ;Таблица степеней десятки;
;----------------------------------------;
__endasm;
} //Basic_PRWORD_ROM

/*--------------------------------- Cut here ---------------------------------*/
BOOLEAN Basic_KeyPressed (void) { // Check to IX-safety
__asm
    CALL  #0x28E /* Scan keys */
    LD    L,#0   /* FALSE */
    INC   DE
    LD    A,E
    OR    D
    RET   Z
    INC   L      /* TRUE */
__endasm;
} //Basic_KeyPressed

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAUSE_DI_fastcall (void /* Regs BC */) {
__asm
  LD   IY,#0x5C3A
  EI
  LD   A,C
  OR   B
  JR   NZ,PauseDiF$
  CALL 0x1F3D
  JR   EndPauseDiF$
PauseDiF$:
  HALT
  DEC  BC
  LD   A,C
  OR   B
  JR   NZ,PauseDiF$
EndPauseDiF$:
  DI
__endasm;
} //Basic_PAUSE_DI_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAUSE_DI_stdcall (CARDINAL ticks) {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  EI
  LD   A,C
  OR   B
  JR   NZ,PauseDiS$
  CALL 0x1F3D
  JR   EndPauseDiS$
PauseDiS$:
  HALT
  DEC  BC
  LD   A,C
  OR   B
  JR   NZ,PauseDiS$
EndPauseDiS$:
  DI
__endasm;
} //Basic_PAUSE_DI_stdcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAUSE_EI_fastcall (void /* Regs BC */) {
__asm
  LD   IY,#0x5C3A
  LD   A,C
  OR   B
  JP   Z,0x1F3D
PauseEiF$:
  HALT
  DEC  BC
  LD   A,C
  OR   B
  JR   NZ,PauseEiF$
__endasm;
} //Basic_PAUSE_EI_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAUSE_EI_stdcall (CARDINAL ticks) {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  LD   A,C
  OR   B
  JP   Z,0x1F3D
PauseEiS$:
  HALT
  DEC  BC
  LD   A,C
  OR   B
  JR   NZ,PauseEiS$
__endasm;
} //Basic_PAUSE_EI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_RANDOMIZE (CARDINAL seed) __naked {
__asm
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  JP   0x1E52
__endasm;
} //Basic_RANDOMIZE

/*--------------------------------- Cut here ---------------------------------*/
/* SEED_RND address */
#define SF_RND$ 0x5C76

CARDINAL _Basic_RandBB (void) /* Ripped from Beta Basic */
{
__asm
  LD   D,#0
  LD   BC,(#SF_RND$)
  LD   H,C
  LD   L,#0xFD
  LD   A,B
  OR   A
  SBC  HL,BC
  SBC  A,D
  SBC  HL,BC
  SBC  A,D
  LD   E,A
  SBC  HL,DE
  JR   NC,R1$
  INC  HL
R1$:
  LD  (#SF_RND$),HL
__endasm;
} //__Basic_RandBB

/*--------------------------------- Cut here ---------------------------------*/
SHORTCARD Basic_RND (SHORTCARD min, SHORTCARD max) {
  return _Basic_RandBB()%(max-min+1) + min;
} //Basic_RND

/*--------------------------------- Cut here ---------------------------------*/
CARDINAL Basic_RNDW (CARDINAL min, CARDINAL max) {
  return _Basic_RandBB()%(max-min+1) + min;
} //Basic_RNDW

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT Basic_SGN (SHORTINT x) {
  if(x <0) return -1;
  if(x==0) return 0;
  return 1;
} //Basic_SGN

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BEEP_DI (CARDINAL ms, SHORTINT freq) __naked {
/* Uses Spectrum ROM calculator */
__asm
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
  LD   C,4(IX)
  LD   B,5(IX) /* BC = ms */
  LD   A,6(IX) /* A = freq */
  LD   IY,#0x5C3A
  PUSH AF
  CALL 0x2D2B /* Put ms into stack */
  LD   BC,#1000
  CALL 0x2D2B /* Put 1000 into stack */
  RST  40
  .DB  5,56   /* Divide */
  POP  AF
  AND  A
  JP   M,BeperDi$ /* If freq < 0 then goto BeperDi$ */
  CALL 0x2D28 /* Put positive freq into stack */
  JR   DoBeepDi$
BeperDi$:
  NEG         /* Make absolute value */
  CALL 0x2D28 /* and put it into stack */
  RST  40
  .DB  27,56  /* Do it negative */
DoBeepDi$:
  CALL 0x3F8
  DI
  POP  IX
  RET
__endasm;
} //Basic_BEEP_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BEEP_EI (CARDINAL ms, SHORTINT freq) __naked {
/* Uses Spectrum ROM calculator */
__asm
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
  LD   C,4(IX)
  LD   B,5(IX) /* BC = ms */
  LD   A,6(IX) /* A = freq */
  LD   IY,#0x5C3A
  PUSH AF
  CALL 0x2D2B /* Put ms into stack */
  LD   BC,#1000
  CALL 0x2D2B /* Put 1000 into stack */
  RST  40
  .DB  5,56   /* Divide */
  POP  AF
  AND  A
  JP   M,BeperEi$ /* If freq < 0 then goto BEPER1$ */
  CALL 0x2D28 /* Put positive freq into stack */
  JR   DoBeepEi$
BeperEi$:
  NEG         /* Make absolute value */
  CALL 0x2D28 /* and put it into stack */
  RST  40
  .DB  27,56  /* Do it negative */
DoBeepEi$:
  CALL 0x3F8
  POP  IX
  RET
__endasm;
} //Basic_BEEP_EI

/*--------------------------------- Cut here ---------------------------------*/
CHAR Basic_INKEY (void) {
__asm
    LD   A, (#0x5C07)
    CP   #0xFF
    JR   Z, INKEY_RET_0X$
    CALL 0x28E
    LD   C, #0
    JR   NZ, INKEY_RET_0X$
    CALL 0x31E
    JR   NC, INKEY_RET_0X$
    DEC  D
    LD   E, A
    CALL 0x333
    LD   L, A
    RET
INKEY_RET_0X$:
    LD   L, #0
__endasm;
} //Basic_INKEY

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Quit_DI (void)
{
__asm
  LD   HL,#0x2758
  EXX
  LD   IY,#0x5C3A
  EI
__endasm;
} //Basic_Quit_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Quit_IM0 (void)
{
__asm
  LD   HL,#0x2758
  EXX
  LD   IY,#0x5C3A
__endasm;
} //Basic_Quit_IM0

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Quit_IM2 (void)
{
__asm
  DI
  LD   HL,#0x2758
  EXX
  LD   IY,#0x5C3A
  IM   0
  EI
__endasm;
} //Basic_Quit_IM2

