/*************************/
/* ZX-BASIC 48k features */
/* Coded by Oleg N. Cher */
/*  zx.oberon2.ru/forum  */
/*************************/

void Basic_Init_IM2 (void);

signed char Basic_ABS (signed char x) __z88dk_fastcall;
signed int Basic_ABSI (signed int x) __z88dk_fastcall;
void Basic_AT_FAST_callee (unsigned char y, unsigned char x) __z88dk_callee;
void Basic_AT_FAST_fastcall (unsigned int yx) __z88dk_fastcall;
void Basic_AT_ROM_callee (unsigned char y, unsigned char x) __z88dk_callee;
void Basic_AT_ROM_fastcall (unsigned int yx) __z88dk_fastcall;
unsigned char Basic_ATTR_callee (unsigned char y, unsigned char x) __z88dk_callee;
unsigned char Basic_ATTR_fastcall (unsigned int yx) __z88dk_fastcall;
void Basic_BEEP_DI (unsigned int ms, signed char freq) __z88dk_callee;
void Basic_BEEP_EI (unsigned int ms, signed char freq) __z88dk_callee;
void Basic_BORDER_fastcall (unsigned char color) __z88dk_fastcall;
void Basic_BRIGHT (unsigned char mode) __z88dk_fastcall;
void Basic_CIRCLE (unsigned char cx, unsigned char cy, unsigned char radius) __z88dk_callee;
void Basic_CIRCLEROM (unsigned char cx, unsigned char cy, unsigned char radius) __z88dk_callee;
void Basic_CIRCLEW_DI (unsigned char cx, unsigned char cy, int radius) __z88dk_callee;
void Basic_CIRCLEW_EI (unsigned char cx, unsigned char cy, int radius) __z88dk_callee;
void Basic_CLS_FULLSCREEN (void);
void Basic_CLS_ZX (void);
void Basic_COLOR (unsigned char atr) __z88dk_fastcall;
void Basic_DRAW_callee (signed char x, signed char y) __z88dk_callee;
void Basic_DRAW_fastcall (unsigned int xy) __z88dk_fastcall;
void Basic_FLASH (unsigned char mode) __z88dk_fastcall;
void Basic_INK (unsigned char color) __z88dk_fastcall;
unsigned char Basic_INKEY (void);
void Basic_INVERSE_FAST (unsigned char mode) __z88dk_fastcall;
void Basic_INVERSE_ROM (unsigned char mode) __z88dk_fastcall;
unsigned char Basic_PRESSED (void);
void Basic_OVER_FAST (unsigned char mode) __z88dk_fastcall;
void Basic_OVER_ROM (unsigned char mode) __z88dk_fastcall;
void Basic_PAINT (unsigned char x, unsigned char y, unsigned char ink) __z88dk_callee;
void Basic_PAPER (unsigned char color) __z88dk_fastcall;
void Basic_PAUSE_DI (unsigned int ticks) __z88dk_fastcall;
void Basic_PAUSE_EI (unsigned int ticks) __z88dk_fastcall;
void Basic_PLOT_callee (unsigned char x, unsigned char y) __z88dk_callee;
void Basic_PLOT_fastcall (unsigned int xy) __z88dk_fastcall;
unsigned char Basic_POINT_callee (unsigned char x, unsigned char y) __z88dk_callee;
unsigned char Basic_POINT_fastcall (unsigned int xy) __z88dk_fastcall;
unsigned char Basic_PORTIN (unsigned int port) __z88dk_fastcall;
void Basic_PORTOUT (unsigned int port, unsigned char value) __z88dk_callee;
void Basic_PRCHAR_FAST (unsigned char ch) __z88dk_fastcall;
void Basic_PRCHAR_ROM (unsigned char ch) __z88dk_fastcall;
void Basic_PRDATA_FAST (void);
void Basic_PRDATA_ROM (void);
void Basic_PRINT_FAST (int n) __z88dk_fastcall;
void Basic_PRINT_ROM (int n) __z88dk_fastcall;
void Basic_PRLN_FAST (void);
void Basic_PRLN_ROM (void);
void Basic_PRSTR_C_FAST (unsigned char *str) __z88dk_fastcall;
void Basic_PRSTR_C_ROM_fastcall (unsigned char *str) __z88dk_fastcall;
void Basic_PRWORD_FAST (unsigned int n) __z88dk_fastcall;
void Basic_PRWORD_ROM (unsigned int n) __z88dk_fastcall;
void Basic_RANDOMIZE (unsigned int seed) __z88dk_fastcall;
unsigned char Basic_RND (unsigned char min, unsigned char max);
unsigned int Basic_RNDW (unsigned int min, unsigned int max);
signed char Basic_SGN (signed char x) __z88dk_fastcall;
signed char Basic_SGNI (signed int x) __z88dk_fastcall;

void Basic_Quit_DI (void);
void Basic_Quit_IM1 (void);
void Basic_Quit_IM2 (void);

extern unsigned int _Basic_RandBB (void);

/* Set video attrib */
#define ATTR_P$ 0x5C8D
/* Video temp attrib */
#define ATTR_T$ 0x5C8F
/* (Font_address - 256) */
#define CHAR_SET$ 0x5C36
/*================================== Header ==================================*/

void Basic_Init_IM2 (void) __naked {
  __asm
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
signed char Basic_ABS (signed char x) __z88dk_fastcall {
__asm
    BIT  7,L
    RET  Z
    XOR  A
    SUB  L
    LD   L,A
__endasm;
} //Basic_ABS

/*--------------------------------- Cut here ---------------------------------*/
signed int Basic_ABSI (signed int x) __z88dk_fastcall {
__asm // by John Metcalf
    BIT  7,H     ;  8
    RET  Z       ; 11/5
    XOR  A       ;  4
    SUB  L       ;  4
    LD   L,A     ;  4
    SBC  A,A     ;  4
    SUB  H       ;  4
    LD   H,A     ;  4 => 37/19
__endasm;

/*
__asm // Code by Titus
    LD   A,H     ;  4
    OR   A       ;  4
    RET  P       ; 11/5
    CPL          ;  4
    LD   H,A     ;  4
    LD   A,L     ;  4
    CPL          ;  4
    LD   L,A     ;  4
    INC  HL      ;  6 => 39/19
__endasm;
*/

/*
__asm
    BIT  7,H     ;  8
    RET  Z       ; 11/5
    EX   DE,HL   ;  4
    XOR  A       ;  4
    LD   L,A     ;  4
    LD   H,A     ;  4
    SBC  HL,DE   ; 15 => 44/19
__endasm;
*/

/*
__asm // Code by NEO SPECTRUMAN
    LD   A,H     ;  4
    CP   #0x80   ;  7
    RET  C       ; 11/5
    CPL          ;  4
    LD   H,A     ;  4
    LD   A,L     ;  4
    CPL          ;  4
    LD   L,A     ;  4
    INC  HL      ;  6 => 42/22
__endasm;
*/

/*
__asm // Code by Titus
    LD   A,#0xFF ;  7
    XOR  H       ;  4
    RET  M       ; 11/5
    LD   H,A     ;  4
    LD   A,L     ;  4
    CPL          ;  4
    LD   L,A     ;  4
    INC  HL      ;  6 => 38/22
__endasm;
*/

} //Basic_ABSI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_ROM_callee (unsigned char y, unsigned char x) __naked __z88dk_callee {
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  CALL 0x1601 // IX-safe
  POP  HL
  POP  DE
  LD   A,#22
  RST  16
  LD   A,E     // y
  RST  16
  LD   A,D     // x
  RST  16
  JP   (HL)
__endasm;
} //Basic_AT_ROM_callee

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_ROM_fastcall (unsigned int yx) __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,#2
  PUSH HL
  CALL 0x1601 // IX-safe
  POP  HL
  LD   A,#22
  RST  16
  LD   A,L     // y
  RST  16
  LD   A,H     // x
  RST  16
__endasm;
} //Basic_AT_ROM_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_FAST_callee (unsigned char y, unsigned char x) __naked __z88dk_callee {
__asm
  POP  HL
  EX   (SP),HL
  LD   A,L     // y
  LD   E,H     // x
  CALL 0xE9E
  LD   A,L
  ADD  E       // + x
  LD   L,A
  LD   (#23684),HL
  RET
__endasm;
} //Basic_AT_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_AT_FAST_fastcall (unsigned int yx) __z88dk_fastcall {
__asm
  LD   A,L     // y
  LD   E,H     // x
  CALL 0xE9E
  LD   A,L
  ADD  E       // + x
  LD   L,A
  LD   (#23684),HL
__endasm;
} //Basic_AT_FAST_fastcall

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_ATTR_callee (unsigned char y, unsigned char x) __naked __z88dk_callee {
__asm
  POP  HL
  POP  BC
  PUSH HL
  CALL 0x2583
  CALL 0x2DD5
  LD   L,A
  RET
__endasm;
} //Basic_ATTR_callee

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_ATTR_fastcall (unsigned int yx) __z88dk_fastcall {
__asm
  LD   C,L
  LD   B,H
  CALL 0x2583
  CALL 0x2DD5
  LD   L,A
__endasm;
} //Basic_ATTR_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BEEP_DI (unsigned int ms, signed char freq) __naked __z88dk_callee {
/* Uses Spectrum ROM calculator */
__asm
  POP  HL
  POP  BC      /* BC = ms */
  DEC  SP
  POP  AF      /* A = freq */
  PUSH HL
  PUSH AF
  CALL 0x2D2B /* IY := 0x5C3A; Put ms into stack */
  LD   BC,#1000
  CALL 0x2D2F /* Put 1000 into stack */
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
  PUSH IX
  CALL 0x3F8
  POP  IX
  DI
  RET
__endasm;
} //Basic_BEEP_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BEEP_EI (unsigned int ms, signed char freq) __naked __z88dk_callee {
/* Uses Spectrum ROM calculator */
__asm
  POP  HL
  POP  BC      /* BC = ms */
  DEC  SP
  POP  AF      /* A = freq */
  PUSH HL
  PUSH AF
  CALL 0x2D2B /* IY := 0x5C3A; Put ms into stack */
  LD   BC,#1000
  CALL 0x2D2F /* Put 1000 into stack */
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
  PUSH IX
  CALL 0x3F8
  POP  IX
  RET
__endasm;
} //Basic_BEEP_EI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BORDER_fastcall (unsigned char color) __naked __z88dk_fastcall
{
  __asm
    LD   A,L
    JP   0x229B // IX-safe
  __endasm;
} //Basic_BORDER_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_BRIGHT (unsigned char mode) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,#19
  RST  16
  LD   A,L
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_BRIGHT

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CIRCLE (unsigned char cx, unsigned char cy, unsigned char radius) __naked __z88dk_callee {
  __asm // Fixed for OVER 1 & small radius by Reobne
        LD   IY, #0x5C3A
        POP  BC
        POP  HL     ; L = x; H = y
        DEC  SP
        POP  AF     ; A = radius
        PUSH BC
        LD   E, A
        LD   C, A
        LD   B, #0
        CALL DOTCI$
        XOR  A
        SUB  C
        RET  Z
        LD   C, A
        CALL DOTCI$
        LD   B, C
        LD   C, #0
        CALL DOTCI$
        XOR  A
        SUB  B
        LD   B, A
        CALL DOTCI$
        DEC  E
        RET  Z
        JR   DLOOPCI$
LOOPCI$:
        CALL DOTCI$ ; sector 1
        XOR  A
        SUB  B
        LD   B, A
        CALL DOTCI$ ; sector 4
        XOR  A
        SUB  C
        LD   C, A
        CALL DOTCI$ ; sector 5
        XOR  A
        SUB  B
        LD   B, A
        CALL DOTCI$ ; sector 8
HLOOPCI$:
        LD   A, C
        LD   C, B
        LD   B, A
        CALL DOTCI$ ; sector 3
        XOR  A
        SUB  C
        LD   C, A
        CALL DOTCI$ ; sector 6
        XOR  A
        SUB  B
        LD   B, A
        CALL DOTCI$ ; sector 7
        XOR  A
        SUB  C
        LD   C, A
        CALL DOTCI$ ; sector 8
        LD   A, C
        LD   C, B
        LD   B, A
DLOOPCI$:
        INC  C
        LD   A, E
        SUB  C
        LD   E, A
        JR   NC, LOOPCI$
        DEC  B
        LD   A, E
        ADD  A, B
        LD   E, A
        LD   A, C
        CP   B
        JR   C, LOOPCI$
        JR   Z, HLOOPCI$
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
void Basic_CIRCLEROM (unsigned char cx, unsigned char cy, unsigned char radius) __naked __z88dk_callee {
__asm
  POP  HL
  DEC  SP
  EX   (SP),HL
  LD   A,H     /* cx */
  CALL 0x2D28
  POP  HL
  DEC  SP
  EX   (SP),HL
  LD   A,H     /* cy */
  CALL 0x2D28
  POP  HL
  DEC  SP
  EX   (SP),HL
  LD   A,H     /* radius */
  CALL 0x2D28
  CALL 0x232D
  LD   A,(ATTR_P$)
  LD   (ATTR_T$),A
  RET
__endasm;
} //Basic_CIRCLEROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CIRCLEW_DI (unsigned char cx, unsigned char cy, int radius) __naked __z88dk_callee {
  __asm
    LD   IY, #0x5C3A
    POP  DE
    POP  BC
    POP  HL
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
void Basic_CIRCLEW_EI (unsigned char cx, unsigned char cy, int radius) __naked __z88dk_callee {
  __asm
    LD   IY, #0x5C3A
    POP  DE
    POP  BC
    POP  HL
    PUSH DE
    LD   A, H
    OR   L
    RET  Z
    BIT  7, H
    RET  NZ
    DI
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
void Basic_CLS_FULLSCREEN (void) __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,(#0x5C48)
  EX   AF,AF
  LD   A,(ATTR_P$)
  LD   (#0x5C48),A
  CALL 0xD6B       ; IX-safe
  EX   AF,AF
  LD   (#0x5C48),A
  LD   A,(ATTR_P$)
  LD   (ATTR_T$),A
  JP   0x1642      ; CHAN_S
__endasm;
} //Basic_CLS_FULLSCREEN

/*--------------------------------- Cut here ---------------------------------*/
void Basic_CLS_ZX (void) __naked {
__asm
  LD   IY,#0x5C3A
  CALL 0xD6B       ; IX-safe
  LD   A,(ATTR_P$)
  LD   (ATTR_T$),A
  JP   0x1642      ; CHAN_S
__endasm;
} //Basic_CLS_ZX

/*--------------------------------- Cut here ---------------------------------*/
void Basic_COLOR (unsigned char atr) __z88dk_fastcall {
__asm
  LD   A,L
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
__endasm;
} //Basic_COLOR

/*--------------------------------- Cut here ---------------------------------*/
void Basic_DRAW_callee (signed char x, signed char y) __naked __z88dk_callee {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH HL
  LD   HL,(#0x5C7D)
  LD   DE,#0x0101
  LD   A,C
  ADD  L
  JR   NC,PositiveXc$
  XOR  A
  SUB  C
  LD   C,A
  LD   E,#0xFF
PositiveXc$:
  LD   A,B
  ADD  H
  JR   NC,PositiveYc$
  XOR  A
  SUB  B
  LD   B,A
  LD   D,#0xFF
PositiveYc$:
  JP   0x24BA
__endasm;
} //Basic_DRAW_callee

/*--------------------------------- Cut here ---------------------------------*/
void Basic_DRAW_fastcall (unsigned int xy) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   C,L
  LD   B,H
  LD   HL,(#0x5C7D)
  LD   DE,#0x0101
  LD   A,C
  ADD  L
  JR   NC,PositiveXf$
  XOR  A
  SUB  C
  LD   C,A
  LD   E,#0xFF
PositiveXf$:
  LD   A,B
  ADD  H
  JR   NC,PositiveYf$
  XOR  A
  SUB  B
  LD   B,A
  LD   D,#0xFF
PositiveYf$:
  JP   0x24BA
__endasm;
} //Basic_DRAW_callee

/*--------------------------------- Cut here ---------------------------------*/
void Basic_FLASH (unsigned char mode) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,#18
  RST  16 // IX-safe
  LD   A,L
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_FLASH

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INK (unsigned char color) __z88dk_fastcall {
__asm
  LD   A,(ATTR_P$)
  AND  #0xF8
  OR   L
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
__endasm;
} //Basic_INK

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_INKEY (void) {
__asm
    LD   IY,#0x5C3A
    LD   A, (#0x5C07)
    CP   #0xFF
    JR   Z, INKEY_RET_0X$
    CALL 0x28E
    JR   NZ, INKEY_RET_0X$
    CALL 0x31E
    JR   NC, INKEY_RET_0X$
    DEC  D
    LD   E, A
    LD   C, #0
    CALL 0x333
    LD   L, A
    RET
INKEY_RET_0X$:
    LD   L, #0
__endasm;
} //Basic_INKEY

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INVERSE_FAST (unsigned char mode) __z88dk_fastcall {
__asm
.globl _Basic_INV_MODE
  LD   IY,#0x5C3A
  LD   A,L
  OR   A
  JR   Z,SetInvers$ /* If INVERSE 0 then poke NOP */
  LD   A,#0x2F      /*              else poke CPL */
SetInvers$:
  LD   (#_Basic_INV_MODE),A
  LD   A,#20
  RST  16
  LD   A,L
  RST  16
__endasm;
} //Basic_INVERSE_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_INVERSE_ROM (unsigned char mode) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,#20
  RST  16 // IX-safe
  LD   A,L
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_INVERSE_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_OVER_FAST (unsigned char mode) __z88dk_fastcall {
__asm // !!! NEED to be checked to IX-safety
.globl _Basic_OVER_MODE
  LD   IY,#0x5C3A
  LD   A,L
  OR   A
  JR   Z,SetOver$ /* If OVER 0 then poke NOP      */
  LD   A,#0xAE    /*           else poke XOR (HL) */
SetOver$:
  LD   (#_Basic_OVER_MODE),A
  LD   A,#21
  RST  16
  LD   A,L
  RST  16
__endasm;
} //Basic_OVER_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_OVER_ROM (unsigned char mode) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,#21
  RST  16 // IX-safe
  LD   A,L
  RST  16
  JP   0x1CAD
__endasm;
} //Basic_OVER_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAINT (unsigned char x, unsigned char y, unsigned char ink) __naked __z88dk_callee {
  __asm
           POP  BC
           POP  DE           ; E = x; D = y
           DEC  SP
           POP  HL           ; H = ink
           PUSH BC
           LD   A, D
           CP   #0xC0
           RET  NC           ; y > 191

           LD D,E            ; D = x
           LD E,A            ; E = y

           PUSH IX
           LD   L, #0
           LD   A, H         ; ink
           CP   #8
           JR   NC, LOC_7DF2$
           LD   L, #0xF8
LOC_7DF2$: PUSH DE
           PUSH HL
           LD   HL, #0
           ADD  HL, SP
           LD   BC, (0x5C65) ; STK_END
           SBC  HL, BC
           SRL  H
           RR   L
           SRL  H
           RR   L
           LD   B, #0xA
LOC_7E08$: DEC  HL
           DJNZ LOC_7E08$
           EX   DE, HL
           POP  HL
           EXX
           LD   HL, #0x4000
           LD   IX, #0x5800
           POP  DE
           LD   C, D         ; x
           LD   B, #3
LOC_7E19$: SRL  C
           DJNZ LOC_7E19$
           ADD  HL, BC
           ADD  IX, BC
           LD   C, E         ; y
           LD   E, #0xBF
LOC_7E23$: LD   A, E
           CP   C
           JR   Z, LOC_7E2C$
           CALL SUB_7EB9$
           JR   LOC_7E23$
LOC_7E2C$: LD   A, D
           AND  #7
           INC  A
           LD   B, A
           LD   A, (HL)
LOC_7E32$: RLA
           DJNZ LOC_7E32$
           PUSH AF
           CALL C, SUB_7E4C$
           CALL SUB_7EF3$
           POP  AF
           CALL C, SUB_7E4C$
           EXX
           LD   A, B
           AND  A
           POP  IX
           RET  Z
           RST  8
           .DB  3

SUB_7E4C$: PUSH IX
           PUSH HL
           PUSH DE
           LD   IX, #0x5800
           LD   HL, #0x4000
           LD   D, #3
LOC_7E59$: LD   E, #0
LOC_7E5B$: LD   B, #8
           PUSH HL
LOC_7E5E$: LD   A, (HL)
           CPL
           LD   (HL), A
           INC  H
           DJNZ LOC_7E5E$
           LD   A, 0(IX)
           LD   C, A
           AND  #7
           LD   H, A
           LD   A, C
           AND  #0x38
           LD   B, #3
LOC_7E70$: RRCA
           RL   H
           DJNZ LOC_7E70$
           OR   H
           LD   H, A
           LD   A, C
           AND  #0xC0
           OR   H
           LD   0(IX), A
           POP  HL
           INC  HL
           INC  IX
           DEC  E
           JR   NZ, LOC_7E5B$
           LD   A, H
           ADD  A, #7
           LD   H, A
           DEC  D
           JR   NZ, LOC_7E59$
           POP  DE
           POP  HL
           POP  IX
           RET

SUB_7E91$: EXX
           BIT 7, L
           EXX
           RET Z
           LD  A, 0(IX)
           EXX
           AND L
           OR  H
           EXX
           LD  0(IX), A
           RET

SUB_7EA1$: INC  E
           LD   A, E
           DEC  H
           AND  #7
           RET  NZ
           PUSH BC
           LD   BC, #0xFFE0
           ADD  IX, BC
           ADD  HL, BC
           INC  H
           POP  BC
           LD   A, E
           AND  #0x3F
           RET  Z
           LD   A, H
           ADD  A, #7
           LD   H, A
           RET

SUB_7EB9$: LD   A, E
SUB_7EBA$: INC  H
           DEC  E
           AND  #7
           RET  NZ
           PUSH BC
           LD   BC, #0x20
           ADD  IX, BC
           ADD  HL, BC
           DEC  H
           POP  BC
           LD   A, E
           INC  A
           AND  #0x3F
           RET  Z
           LD   A, H
           SUB  #7
           LD   H, A
           RET

SUB_7ED2$: PUSH BC
           LD   B, C
           SRL  B
           SRL  B
           SRL  B
           LD   A, L
           AND  #0xE0
           OR   B
           LD   L, A
           PUSH IX
           EX   (SP), HL
           LD   A, L
           AND  #0xE0
           OR   B
           LD   L, A
           EX   (SP), HL
           POP  IX
           POP  BC
           LD   D, C
           RET

LOC_7EED$: LD   B, D
           INC  DE
           EXX
           LD   D, #0
           RET

SUB_7EF3$: EXX
           DEC  DE
           BIT  7, D
           JR   NZ, LOC_7EED$
           EXX
           CALL SUB_7E91$
           LD   A, (HL)
           AND  A
           JR   Z, LOC_7F52$
           LD   C, A
           INC  A
           LD   A, D
           JR   Z, LOC_7F20$
           AND  #7
           INC  A
           LD   B, A
           LD   A, C
           LD   C, B
LOC_7F0C$: RLCA
           DJNZ LOC_7F0C$
           JR   NC, LOC_7F3B$
           INC  D
           JR   Z, LOC_7F1C$
           LD   A, D
           AND  #7
           JR   NZ, LOC_7F1C$
LOC_7F19$: INC  HL
           INC  IX
LOC_7F1C$: EXX
           INC  DE
           EXX
           RET
LOC_7F20$: AND  #0xF8
           ADD  A, #8
           LD   D, A
           JR   Z, LOC_7F1C$
           JR   LOC_7F19$
LOC_7F29$: LD   (HL), A
           LD   A, D
           DEC  A
           AND  #0xF8
           ADD  A, B
           LD   C, A
           DEC  B
           JR   Z, LOC_7F38$
           LD   A, (HL)
LOC_7F34$: RRCA
           DJNZ LOC_7F34$
           LD   (HL), A
LOC_7F38$: LD   A, D
           JR   LOC_7F87$
LOC_7F3B$: INC  D
           BIT  3, C
           JR   NZ, LOC_7F47$
           RLCA
           JR   C, LOC_7F46$
           INC  C
           JR   LOC_7F3B$
LOC_7F46$: RRCA
LOC_7F47$: LD   B, C
LOC_7F48$: SCF
           RRA
           JR   C, LOC_7F29$
           DJNZ LOC_7F48$
           LD   (HL), A
           LD   A, D
           JR   LOC_7F5A$
LOC_7F52$: LD   (HL), #0xFF
           LD   A, D
           AND  #0xF8
           ADD  A, #8
           INC  D
LOC_7F5A$: LD   C, A
           PUSH HL
           PUSH IX
LOC_7F5E$: LD   A, D
           DEC  A
           AND  #0xF8
           LD   D, A
           JR   Z, LOC_7F81$
           DEC  HL
           DEC  IX
           CALL SUB_7E91$
           LD   A, (HL)
           LD   (HL), #0xFF
           AND  A
           JR   Z, LOC_7F5E$
           LD   B, #0
           SCF
LOC_7F74$: INC  B
           RRA
           JR   NC, LOC_7F74$
           DEC  B
LOC_7F79$: SCF
           RLA
           JR   NC, LOC_7F79$
           LD   (HL), A
           LD   A, D
           SUB  B
           LD   D, A
LOC_7F81$: POP  IX
           POP  HL
           LD   A, C
           LD   C, D
           LD   D, A
LOC_7F87$: AND  #7
           JR   NZ, LOC_7FB1$
           LD   A, D
           AND  A
LOC_7F8D$: JR   Z, LOC_7FB1$
           INC  HL
           INC  IX
           CALL SUB_7E91$
           LD   A, (HL)
           AND  A
           JR   NZ, LOC_7FA1$
           LD   (HL), #0xFF
           LD   A, D
           ADD  A, #8
           LD   D, A
           JR   LOC_7F8D$
LOC_7FA1$: LD   B, #0
           SCF
LOC_7FA4$: INC  B
           RLA
           JR   NC, LOC_7FA4$
           DEC  B
LOC_7FA9$: SCF
           RRA
           JR   NC, LOC_7FA9$
           LD   (HL), A
           LD   A, D
           ADD  A, B
           LD   D, A
LOC_7FB1$: LD   B, D
           DEC  B
           LD   A, E
           CP   #0xBF
           JR   NC, LOC_7FD1$
           CALL SUB_7EA1$
           CALL SUB_7ED2$
LOC_7FBE$: PUSH BC
           CALL SUB_7EF3$
           POP  BC
           LD   A, D
           SUB  #1
           JR   C, LOC_7FCB$
           CP   B
           JR   C, LOC_7FBE$
LOC_7FCB$: CALL SUB_7ED2$
           CALL SUB_7EB9$
LOC_7FD1$: LD   A, E
           AND  A
           JR   Z, LOC_7FEB$
           CALL SUB_7EBA$
           CALL SUB_7ED2$
LOC_7FDB$: PUSH BC
           CALL SUB_7EF3$
           POP  BC
           LD   A, D
           SUB  #1
           JR   C, LOC_7FE8$
           CP   B
           JR   C, LOC_7FDB$
LOC_7FE8$: CALL SUB_7EA1$
LOC_7FEB$: LD   C, B
           CALL SUB_7ED2$
           EXX
           INC  DE
           EXX
           INC  D
           RET  Z
           INC  D
           RET  Z
           LD   A, D
           AND  #7
           CP   #2
           RET  NC
           INC  HL
           INC  IX
           RET
  __endasm;
} //Basic_PAINT

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAPER (unsigned char color) __z88dk_fastcall {
__asm
  LD   A,(ATTR_P$)
  AND  #0xC7
  SLA  L
  SLA  L
  SLA  L
  OR   L
  LD   (ATTR_P$),A
  LD   (ATTR_T$),A
__endasm;
} //Basic_PAPER

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAUSE_DI (unsigned int ticks) __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  EI
  LD   A,L
  OR   H
  JR   NZ,PauseDI$
  LD   C,L
  LD   B,H
  CALL 0x1F3D
  DI
  RET
PauseDI$:
  HALT
  DEC  HL
  LD   A,L
  OR   H
  JR   NZ,PauseDI$
  DI
__endasm;
} //Basic_PAUSE_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PAUSE_EI (unsigned int ticks) __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,L
  OR   H
  LD   C,L
  LD   B,H
  JP   Z,0x1F3D
PauseEI$:
  HALT
  DEC  HL
  LD   A,L
  OR   H
  JR   NZ,PauseEI$
__endasm;
} //Basic_PAUSE_EI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PLOT_callee (unsigned char x, unsigned char y) __naked __z88dk_callee {
__asm
  LD   IY,#0x5C3A
  POP  HL
  POP  BC
  PUSH HL
  JP   0x22E5
__endasm;
} //Basic_PLOT_callee

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PLOT_fastcall (unsigned int xy) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   C,L
  LD   B,H
  JP   0x22E5
__endasm;
} //Basic_PLOT_fastcall

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_POINT_callee (unsigned char x, unsigned char y) __naked __z88dk_callee {
__asm
  POP  HL
  POP  BC
  PUSH HL
  CALL 0x22CE
  CALL 0x2DD5
  LD   L,A
  RET
__endasm;
} //Basic_POINT_callee

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_POINT_fastcall (unsigned int xy) __z88dk_fastcall {
__asm
  LD   C,L
  LD   B,H
  CALL 0x22CE
  CALL 0x2DD5
  LD   L,A
__endasm;
} //Basic_POINT_fastcall

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_PORTIN (unsigned int port) __z88dk_fastcall {
__asm
  LD   C,L
  LD   B,H
  IN   L,(C)
__endasm;
} //Basic_PORTIN

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PORTOUT (unsigned int port, unsigned char value) __naked __z88dk_callee {
__asm
  POP  HL
  POP  BC
  DEC  SP
  POP  AF
  OUT  (C),A
  JP   (HL)
__endasm;
} //Basic_PORTOUT

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRCHAR_FAST (unsigned char ch) __z88dk_fastcall {
__asm
            BIT  7,L
            JR   NZ,PO_GR$
            LD   H,#0
            ADD  HL,HL
            ADD  HL,HL
            ADD  HL,HL
            LD   DE,(#CHAR_SET$)
            ADD  HL,DE
            JR   USER_FONT$
PO_GR_BUF$: .DB  #0,#0,#0,#0,#0,#0,#0,#0
PO_GR$:     LD   B,L
            LD   HL,#PO_GR_BUF$
            PUSH HL
            CALL 0xB3E /* Generate po_gr char to buffer */
            CALL 0xB3E
            POP  HL
USER_FONT$: EX   DE,HL
            LD   HL,(#23684)
            PUSH HL
            LD   B,#8
p_Sy1$:     LD   A,(DE)
_Basic_INV_MODE:
            NOP
_Basic_OVER_MODE:
            NOP
            LD   (HL),A
            INC  DE
            INC  H
            DJNZ p_Sy1$
            POP  HL
            LD   E,L
            LD   A,H
            AND  #0x18
            RRCA
            RRCA
            RRCA
            ADD  A,#0x58
            LD   D,A
            LD   A,(ATTR_P$)
            LD   (DE),A
            INC  L
_Basic_INC_HPOS:
            JR   NZ,p_Sy2$
            LD   A,H
            ADD  A,#8
            LD   H,A
            CP   #0x58
            JR   C,p_Sy2$
            LD   H,#0x40
p_Sy2$:     LD   (#23684),HL
__endasm;
} //Basic_PRCHAR_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRCHAR_ROM (unsigned char ch) __z88dk_fastcall {
__asm
            LD   A,L
            LD   IY,#0x5C3A
//          JP   0x09F4       ; PRINT_OUT
            RST  16
__endasm;
} //Basic_PRCHAR_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRDATA_FAST (void) __naked {
__asm
            POP  HL
PRDATAfast$:LD   A,(HL)
            OR   A
            JR   Z,PRDATA_EXf$
            PUSH HL
            LD   L,A
            CALL _Basic_PRCHAR_FAST
            POP  HL
            INC  HL
            JR   PRDATAfast$
PRDATA_EXf$:JP   (HL)
__endasm;
} //Basic_PRDATA_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRDATA_ROM (void) __naked {
__asm
            LD   IY,#0x5C3A
            POP  HL
PRDATArom$: LD   A,(HL)
            OR   A
            JR   Z,PRDATA_EXr$
            RST  16
            INC  HL
            JR   PRDATArom$
PRDATA_EXr$:JP   (HL)
__endasm;
} //Basic_PRDATA_ROM

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Basic_PRESSED (void) {
__asm
            CALL  #0x28E      ; KEY_SCAN
            INC   DE
            LD    A,E
            OR    D
            LD    L,A         ; FALSE
            RET   Z
            LD    L,#1        ; TRUE
__endasm;
} //Basic_PRESSED

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRINT_FAST (int n) __naked __z88dk_fastcall {
__asm
    BIT   7,H
    JP    Z,_Basic_PRWORD_FAST

    ; HL := -HL
    EX    DE,HL ;  4
    XOR   A     ;  4
    LD    L,A   ;  4
    LD    H,A   ;  4
    SBC   HL,DE ; 15 => 31t

    PUSH  HL
    LD    L,#0x2D
    CALL  _Basic_PRCHAR_FAST
    POP   HL
    JP    _Basic_PRWORD_FAST
__endasm;
} //Basic_PRINT_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRINT_ROM (int n) __naked __z88dk_fastcall {
__asm
    BIT   7,H
    JP    Z,_Basic_PRWORD_ROM
    
    ; HL := -HL
    EX    DE,HL ;  4
    XOR   A     ;  4
    LD    L,A   ;  4
    LD    H,A   ;  4
    SBC   HL,DE ; 15 => 31t

    PUSH  HL
    LD    A,#0x2D
    CALL  _Basic_PRCHAR_ROM+1
    POP   BC
    JP    _Basic_PRWORD_ROM+2
__endasm;
} //Basic_PRINT_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRLN_FAST (void) __naked {
__asm
.globl _Basic_INC_HPOS
            LD   HL,(#23684)
            LD   A,L
            OR   #0x1F
            INC  A
            LD   L,A
            JP   _Basic_INC_HPOS
__endasm;
} //Basic_PRLN_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRLN_ROM (void) __naked {
__asm
            LD    A,#0x0D
            JP    _Basic_PRCHAR_ROM+1
__endasm;
} //Basic_PRLN_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRSTR_C_ROM_fastcall (unsigned char *str) __naked __z88dk_fastcall {
__asm
            LD   IY,#0x5C3A
PRSTR_fast$:LD   A,(HL)
            OR   A
            RET  Z
//          PUSH HL
//          CALL 0x09F4       ; PRINT_OUT
//          POP  HL
            RST  16
            INC  HL
            JR   PRSTR_fast$
__endasm;
} //Basic_PRSTR_C_ROM_fastcall

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRSTR_C_FAST (unsigned char *str) __naked __z88dk_fastcall {
__asm
            LD   A,(HL)
            OR   A
            RET  Z
            PUSH HL
            LD   L,A
            CALL _Basic_PRCHAR_FAST
            POP  HL
            INC  HL
            JR   _Basic_PRSTR_C_FAST
__endasm;
} //Basic_PRSTR_C_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRWORD_FAST (unsigned int n) __z88dk_fastcall {
__asm
            LD    C,#0x5        ;кол-во незначащих нулей + 1
            LD    DE,#-10000    ;таблица степеней десятки
            CALL  LP_DIGIT$
            LD    DE,#-1000     ;
            CALL  LP_DIGIT$
            LD    DE,#-100      ;
            CALL  LP_DIGIT$
            LD    DE,#-10       ;
            CALL  LP_DIGIT$
            LD    DE,#-1        ;
LP_DIGIT$:  LD    A,#'0'-1      ;обнулили счётчик
LP_PDW2$:   INC   A             ;увеличиваем счётчик
            ADD   HL,DE         ;вычитаем текущую степень десятки
            JR    C,LP_PDW2$    ;повторяем пока HL>=0
            SBC   HL,DE         ;HL=HL mod DE; A=HL div DE
            DEC   C             ;проверяем: может это незначащий нуль?
            JR    Z,LP_PRNT$    ; если уже были другие цифры, печатаем
            CP    #'0'          ;если это нуль, то он незначащий
            RET   Z             ; ничего не печатаем
LP_PRNT$:   PUSH  HL
            LD    L,A           ;печать десятичной цифры
            CALL  _Basic_PRCHAR_FAST+4 ; Skip checking UDG graphic
            POP   HL
            LD    C,#1          ;уже была печать, дальше все значащие
__endasm;
} //Basic_PRWORD_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Basic_PRWORD_ROM (unsigned int n) __naked __z88dk_fastcall {
__asm
            LD   C,L
            LD   B,H
            CALL 0x2D2B       ; BC-TO-FP
            JP   0x2DE3       ; PRINT-FP
__endasm;

/*
__asm
          LD    IY,#0x5C3A
// Из журнала Deja Vu #04, Кемерово, 01.04.98
//  (c) Колотов Сеpгей, г.Шадpинск, SerzhSoft
// Доработано для печати только значащих цифр
// Оптимизировано заменой SBC на ADD (с) blackmirror
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
          ADD   HL,DE         ;вычитаем текущую степень десятки
          JR    C,LP_PDW2$    ;повторяем пока HL>=0
          SBC   HL,DE         ;HL=HL mod DE; A=HL div DE
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
DECTB_W$: .DW   -10000,-1000,-100,-10,-1  ;Таблица степеней десятки;
;----------------------------------------;
__endasm;

*/
} //Basic_PRWORD_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Basic_RANDOMIZE (unsigned int seed) __naked __z88dk_fastcall {
__asm
    LD   C,L
    LD   B,H
    JP   0x1E52
__endasm;
} //Basic_RANDOMIZE

/*--------------------------------- Cut here ---------------------------------*/
/* SEED_RND address */
#define SF_RND$ 0x5C76

unsigned int _Basic_RandBB (void) /* Ripped from Beta Basic */
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
unsigned char Basic_RND (unsigned char min, unsigned char max) {
  return _Basic_RandBB()%(max-min+1) + min;
} //Basic_RND

/*--------------------------------- Cut here ---------------------------------*/
unsigned int Basic_RNDW (unsigned int min, unsigned int max) {
  return _Basic_RandBB()%(max-min+1) + min;
} //Basic_RNDW

/*--------------------------------- Cut here ---------------------------------*/
signed char Basic_SGN (signed char x) __z88dk_fastcall {
__asm // Code by char & SaNchez
    RLC  L
    RET  Z
    SBC  A
    OR   #1
    LD   L,A
__endasm;
} //Basic_SGN

/*--------------------------------- Cut here ---------------------------------*/
signed char Basic_SGNI (signed int x) __z88dk_fastcall {
__asm // Code by char & SaNchez
    LD   A,L
    OR   H
    RET  Z
    RLC  H
    SBC  A
    OR   #1
    LD   L,A
__endasm;
} //Basic_SGNI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Quit_DI (void) {
__asm
  LD   IY,#0x5C3A
  LD   HL,#0x2758
  EXX
  EI
__endasm;
} //Basic_Quit_DI

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Quit_IM1 (void) {
__asm
  LD   HL,#0x2758
  EXX
__endasm;
} //Basic_Quit_IM1

/*--------------------------------- Cut here ---------------------------------*/
void Basic_Quit_IM2 (void) {
__asm
  LD   IY,#0x5C3A
  LD   HL,#0x2758
  EXX
  LD   A,#0x3F
  DI
  LD   I,A
  IM   1
  EI
__endasm;
} //Basic_Quit_IM2
