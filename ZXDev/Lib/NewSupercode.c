#include "SYSTEM.h"

export void NewSupercode__2WIERSZE (SYSTEM_ADDRESS adr);
export void NewSupercode_DZWIEK_1 (void);
export void NewSupercode_DZWIEK_2 (void);
export void NewSupercode_DZWIEK_3 (void);
export void NewSupercode_EKRAN_1 (SHORTCARD x);
export void NewSupercode_EKRAN_2 (SHORTCARD x);
export void NewSupercode_LITERY_ (SHORTCARD x, SHORTCARD y, SHORTCARD xs,
  SHORTCARD ys, SHORTCARD wdth, CHAR *str);
/*================================== Header ==================================*/

void NewSupercode__2WIERSZE (SYSTEM_ADDRESS adr) {
__asm
           POP  DE
           POP  HL
           PUSH HL
           PUSH DE
           PUSH IX
           LD   B, #8
LOC_DAC5$: PUSH BC
           LD   B, #2
LOC_DAC8$: LD   C, B
           PUSH HL
           POP  IX
           LD   A, 0x1F(IX)
           RRCA
           LD   B, #0x20
LOC_DAD2$: RR   (HL)
           INC  HL
           DJNZ LOC_DAD2$
           LD   B, C
           DJNZ LOC_DAC8$
           LD   BC, #0xC0
           ADD  HL, BC
LOC_DADE$: NOP
           DJNZ LOC_DADE$
           POP  BC
           DJNZ LOC_DAC5$
           POP  IX
__endasm;
} //NewSupercode__2WIERSZE

/*--------------------------------- Cut here ---------------------------------*/
void NewSupercode_EKRAN_1 (SHORTCARD x) {
__asm
    LD   HL, #2
    ADD  HL, SP
    LD   L, (HL) // x
    LD   H, #0
    LD   DE, #0x5800
    LD   BC, #0x300
    LDIR
__endasm;
} //NewSupercode_EKRAN_1

/*--------------------------------- Cut here ---------------------------------*/
void NewSupercode_EKRAN_2 (SHORTCARD x) {
__asm
    LD   HL, #2
    ADD  HL, SP
    LD   L, (HL) // x
    LD   H, #0
    LD   BC, #0x1800
    LD   DE, #0x4000
    LDIR
__endasm;
} //NewSupercode_EKRAN_2

/*--------------------------------- Cut here ---------------------------------*/
void NewSupercode_LITERY_ (SHORTCARD x, SHORTCARD y, SHORTCARD xs,
    SHORTCARD ys, SHORTCARD wdth, CHAR *str) __naked {
__asm
    PUSH IX
    LD   IX, #4
    ADD  IX, SP
    LD   L, 5(IX)
    LD   H, 6(IX) // str
LOC_E69C$:
    LD   A, (HL)
    OR   A
    JP   Z,LOC_E7AE$
    INC  HL
    PUSH HL
    LD   L, A
    LD   H, #0
    ADD  HL, HL
    ADD  HL, HL
    ADD  HL, HL
    LD   DE, (#0x5C36) // SHAR_SET
    ADD  HL, DE
    LD   A, #8
    LD   (#VAR_5B04$+1), A // _ptr
    LD   A, 1(IX) // y
    LD   (#VAR_5B09$+1), A // _swY
LOC_E6B9$: // lst
    LD   A, 0(IX) // x
    LD   (#VAR_5B08$+1), A // _swX
    LD   A, #9
    LD   (#VAR_5B05$+1), A // _rpt
    LD   A, (HL)
    INC  HL
    LD   (#VAR_5B02$+1), HL // symb
LOC_E6C9$: // lot
    RLCA
    LD   (#VAR_5B06$+1), A // cod
VAR_5B05$:
    LD   A, #0 // (_rpt)
    DEC  A
    JR   NZ, LOC_E705$
VAR_5B04$:
    LD   A, #0  // (_ptr)
    DEC  A
    JR   NZ, LOC_E6F1$
    LD   A, 4(IX) // wdth
    LD   B, A
    LD   A, 2(IX) // len
    LD   C, A
    LD   A, 0(IX) // x
LOC_E6E4$:
    ADD  A, C
    DEC  B
    JR   NZ, LOC_E6E4$
    LD   0(IX), A // x
    POP  HL
    JR   LOC_E69C$
LOC_E6F1$:
    LD   (#VAR_5B04$+1), A // _ptr
    LD   A, 3(IX) // high
VAR_5B09$:
    ADD  A, #0 // (_swY)
    LD   (#VAR_5B09$+1), A // _swY
VAR_5B02$:
    LD   HL, #0 // (symb)
    JR   LOC_E6B9$
LOC_E705$:
    LD   (#VAR_5B05$+1), A // _rpt
    LD   A, 2(IX) // len
    LD   B, A
LOC_E70C$:
    LD   A, (#VAR_5B09$+1) // _swY
    LD   (#VAR_5B07$+1), A // _bit
    LD   A, 3(IX) // high
    LD   C, A
LOC_E716$:
    PUSH BC
    CALL SUB_E73D$ // letter
    POP  BC
    LD   A, (#VAR_5B07$+1) // _bit
    INC  A
    LD   (#VAR_5B07$+1), A // _bit
    DEC  C
    JR   NZ, LOC_E716$
    LD   A, (#VAR_5B08$+1) // _swX
    INC  A
    LD   (#VAR_5B08$+1), A // _swX
    DJNZ LOC_E70C$
VAR_5B06$:
    LD   A, #0 // (cod)
    JR   LOC_E6C9$ // lot
LOC_E735$: // form
    .DB 0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1
SUB_E73D$: // letter
    LD   A, (#0x5C8E) // MASK_P
    XOR  #0xFF
    LD   B, A
    LD   A, (#0x5C8D) // ATTR_P
    AND  B
    LD   B, A
VAR_5B08$:
    LD   A, #0 // (_swX)
    AND  #0xF8
    LD   L, A
VAR_5B07$:
    LD   A, #0 // (_bit)
    CP   #0xC0
    RET  NC
    RRA
    RRA
    RRA
    AND  #0x1F
    LD   H, A
    RR   H
    RR   L
    RR   H
    RR   L
    RR   H
    RR   L
    LD   A, #0x58
    OR   H
    LD   H, A
    LD   A, (#0x5C8E) // MASK_P
    AND  (HL)
    OR   B
    LD   (HL), A
    LD   A, (#VAR_5B07$+1) // _bit
    LD   B, A
    AND  #7
    OR   #0x40
    LD   H, A
    LD   A, B
    RRA
    RRA
    RRA
    AND  #0x18
    OR   H
    LD   H, A
    LD   A, B
    RLA
    RLA
    AND  #0xE0
    LD   L, A
    LD   A, (#VAR_5B08$+1) // _swX
    LD   B, A
    RRA
    RRA
    RRA
    AND  #0x1F
    OR   L
    LD   L, A
    EX   DE, HL
    LD   HL, #LOC_E735$ // form
    LD   A, B
    AND  #7
    LD   C, A
    LD   B, #0
    ADD  HL, BC
    LD   B, (HL)
    LD   A, (DE)
    LD   HL, #VAR_5B06$+1 // cod
    BIT  0, (HL)
    JR   Z, LOC_E7A9$
    OR   B
    LD  (DE), A
    RET
LOC_E7A9$:
    CPL
    OR  B
    CPL
    LD  (DE), A
    RET
LOC_E7AE$:
    POP  IX
    RET
__endasm;
} //NewSupercode_LITERY_

/*--------------------------------- Cut here ---------------------------------*/
void NewSupercode_DZWIEK_1 (void) {
__asm
    LD   A, (#0x5C48)
    RRA
    RRA
    RRA
    LD   B, #0xF0
    LD   C, #0xFE
LOC_E7B9$:
    DEC  H
    JR   NZ, LOC_E7C2$
    XOR  #0x10
    OUT  (C), A
    LD   H, #0xEE
LOC_E7C2$:
    DEC  L
    JR   NZ, LOC_E7B9$
    XOR  #0x10
    OUT  (C), A
    LD   L, #0xFE
    DJNZ LOC_E7B9$
__endasm;
} //NewSupercode_DZWIEK_1

/*--------------------------------- Cut here ---------------------------------*/
void NewSupercode_DZWIEK_2 (void) {
__asm
    PUSH IX
    LD   BC, #0xFA04
    LD   HL, #0x200
    LD   DE, #2
LOC_E7D7$:
    PUSH HL
    PUSH DE
    PUSH BC
    CALL 0x3B5
    POP  BC
    POP  DE
    POP  HL
    LD   A, L
    SUB  C
    LD   L, A
    DJNZ LOC_E7D7$
    POP  IX
__endasm;
} //NewSupercode_DZWIEK_2

/*--------------------------------- Cut here ---------------------------------*/
void NewSupercode_DZWIEK_3 (void) {
__asm
    LD   A, (#0x5C48)
    SRL  A
    SRL  A
    LD   L, A
    LD   E, #0
    LD   D, #0x80
LOC_E7F2$:
    PUSH DE
LOC_E7F3$:
    LD   B, E
    DJNZ .
    LD   A, (BC)
    AND  #0xF8
    OR   L
    OUT  (#0x9A), A
    INC  C
    DEC  D
    JR   NZ, LOC_E7F3$
    POP  DE
    INC  E
    DEC  D
    JR   NZ, LOC_E7F2$
__endasm;
} //NewSupercode_DZWIEK_3
