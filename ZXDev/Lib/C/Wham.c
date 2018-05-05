void Wham_InitPlayNote (unsigned int chan1, unsigned int chan2) __z88dk_callee;
void Wham_PlayNote (void);
void Wham_PlayKeyPress (unsigned int chan1, unsigned int chan2) __z88dk_callee;
void Wham_PlayTuneEnd (unsigned int chan1, unsigned int chan2) __z88dk_callee;
void Wham_SetTempo (unsigned char tempo) __z88dk_fastcall;
/*================================== Header ==================================*/

void Wham_InitPlayNote (unsigned int chan1, unsigned int chan2) __naked __z88dk_callee {
  __asm
    LD   A, #0x16+2
    LD   (JR_TUNE_END+1), A
    LD   A, (0x5C48)
    RRA
    RRA
    RRA
    LD   (BYTE_BC62), A
    POP  DE
    POP  HL
    LD   (WORD_BC63), HL
    INC  HL
    LD   (WORD_BC65), HL
    POP  HL
    LD   (WORD_BC67), HL
    INC  HL
    LD   (WORD_BC69), HL
    PUSH DE
    RET
  __endasm;
} //Wham_InitPlayNote

/*--------------------------------- Cut here ---------------------------------*/
void Wham_PlayKeyPress (unsigned int chan1, unsigned int chan2) __naked __z88dk_callee {
  __asm
    POP  BC
    CALL _Wham_InitPlayNote
    PUSH BC
    DI
LOC_BC55$:
    PUSH IX
    CALL SUB_BC8F
    POP  IX
    CALL 0x28E
    INC  E
    JR   Z, LOC_BC55$
    EI
    RET
  __endasm;
} //Wham_PlayKeyPress

/*--------------------------------- Cut here ---------------------------------*/
void Wham_PlayTuneEnd (unsigned int chan1, unsigned int chan2) __naked __z88dk_callee {
  __asm
    POP  BC
    LD   A, #4  ; FINISHED$
    CALL _Wham_InitPlayNote+2
    JP   _Wham_PlayKeyPress+4
  __endasm;
} //Wham_PlayTuneEnd

/*--------------------------------- Cut here ---------------------------------*/
void Wham_PlayNote (void) {
  __asm
    DI
    PUSH IX
    CALL SUB_BC8F
    POP  IX
    EI
  __endasm;
} //Wham_PlayNote

/*--------------------------------- Cut here ---------------------------------*/
void Wham_SetTempo (unsigned char tempo) __z88dk_fastcall {
  __asm
    LD   A,L
    LD   (BYTE_BC6B),A
  __endasm;
} //Wham_SetTempo

/*--------------------------------- Cut here ---------------------------------*/
void _Wham_Player (void) __naked {
  __asm
.globl BYTE_BC62
.globl WORD_BC63
.globl WORD_BC65
.globl WORD_BC67
.globl WORD_BC69
.globl BYTE_BC6B
; ---------------------------------------------------------------------------
BYTE_BC60$:  .DB 0x18
BYTE_BC61$:  .DB 0x0B
BYTE_BC62:   .DB 3    ; Border color
WORD_BC63:   .DW 0    ; Start address of channel 1
WORD_BC65:   .DW 0    ; + 1
WORD_BC67:   .DW 0    ; Start address of channel 2
WORD_BC69:   .DW 0    ; + 1
BYTE_BC6B:   .DB 0xEE ; Tempo

; =============== S U B R O U T I N E =======================================
SUB_BC6C$:
    LD   E, (HL)
    INC  HL
    LD   D, (HL)
    INC  DE
LOC_BC70$:
    LD   A, (DE)
    CP   #0x40
.globl JR_TUNE_END
JR_TUNE_END:
    JR   Z, LOC_BC87$
    LD   (HL), D
    DEC  HL
    LD   (HL), E
    RET
FINISHED$:
    POP  HL
    POP  HL
    POP  IX
    EI
    RET

; =============== S U B R O U T I N E =======================================
SUB_BC79$:
    LD   A, (HL)
    ADD  A, #0xC
    LD   E, A
    LD   D, #0
    LD   HL, #LOC_BD1C$
    ADD  HL, DE
    LD   H, (HL)
    LD   L, #1
    RET

; ---------------------------------------------------------------------------

LOC_BC87$:
    INC  HL
    LD   E, (HL)
    INC  HL
    LD   D, (HL)
    DEC  HL
    DEC  HL
    JR   LOC_BC70$

; =============== S U B R O U T I N E =======================================
.globl SUB_BC8F

SUB_BC8F:
    LD   HL, #WORD_BC63
    CALL SUB_BC6C$
    LD   (BYTE_BC60$), A
    LD   HL, #WORD_BC67
    CALL SUB_BC6C$
    LD   (BYTE_BC61$), A
    LD   HL, #BYTE_BC60$
    CALL SUB_BC79$
    RL   E
    JP   C, LOC_BD52$
    PUSH HL
    LD   HL, #BYTE_BC61$
    CALL SUB_BC79$
    POP  DE
    LD   A, H
    DEC  A
    JR   NZ, LOC_BCBC$
    LD   A, D
    DEC  A
    JR   Z, LOC_BCFE$
LOC_BCBC$:
    LD   A, (BYTE_BC6B)
    LD   C, A
    LD   B, #0
    LD   A, (BYTE_BC62)
    EX   AF, AF
    LD   A, (BYTE_BC62)
    .DB  0xDD
    LD   H, D   ; LD IXH, D
    LD   D, #0x10
LOC_BCCD$:
    NOP
    NOP
LOC_BCCF$:
    EX   AF, AF
    DEC  E
    OUT  (0xFE),  A
    JR   NZ, LOC_BCEC$
    .DB  0xDD
    LD   E, H    ; LD E, IXH
    XOR  D
    EX   AF, AF
    DEC  L
    JP   NZ, LOC_BCF3$
LOC_BCDD$:
    OUT  (0xFE),  A
    LD   L, H
    XOR  D
    DJNZ LOC_BCCD$
    INC  C
    JP   NZ, LOC_BCCF$
    RET
; ---------------------------------------------------------------------------
    .DB  0x61
    .DB  0x64
    .DB  0x61
    .DB  0x6D
; ---------------------------------------------------------------------------
LOC_BCEC$:
    JR   Z, .
    EX   AF, AF
    DEC  L
    JP   Z, LOC_BCDD$
LOC_BCF3$:
    OUT  (0xFE),  A
    NOP
    NOP
    DJNZ LOC_BCCD$
    INC  C
    JP   NZ, LOC_BCCF$
    RET
; ---------------------------------------------------------------------------
LOC_BCFE$:
    LD   A, (BYTE_BC6B)
    CPL
    LD   C, A
; END OF FUNCTION SUB_BC8F

; =============== S U B R O U T I N E =======================================
SUB_BD03$:
    PUSH BC
    PUSH AF
    LD   B, #0

LOC_BD07$:
    PUSH HL
    LD   HL, #0
    SRA  (HL)
    SRA  (HL)
    SRA  (HL)
    NOP
    POP  HL
    DJNZ LOC_BD07$
    DEC  C
    JP   NZ, LOC_BD07$
    POP  AF
    POP  BC
    RET
; END OF FUNCTION SUB_BD03

; ---------------------------------------------------------------------------
LOC_BD1C$:
    .DB 0xFF
    .DB 0xF0
    .DB 0xE3
    .DB 0xD7
    .DB 0xCB
    .DB 0xC0
    .DB 0xB4
    .DB 0xAB
    .DB 0xA1
    .DB 0x97
    .DB 0x90
    .DB 0x88
    .DB 0x80
    .DB 0x79
    .DB 0x72
    .DB 0x6C
    .DB 0x66
    .DB 0x60
    .DB 0x5B
    .DB 0x56
    .DB 0x51
    .DB 0x4C
    .DB 0x48
    .DB 0x44
    .DB 0x40
    .DB 0x3D
    .DB 0x39
    .DB 0x36
    .DB 0x33
    .DB 0x30
    .DB 0x2D
    .DB 0x2B
    .DB 0x28
    .DB 0x26
    .DB 0x24
    .DB 0x22
    .DB 0x20
    .DB 0x1E
    .DB 0x1C
    .DB 0x1B
    .DB 0x19
    .DB 0x18
    .DB 0x17
    .DB 0x15
    .DB 0x14
    .DB 0x13
    .DB 0x12
    .DB 0x11
    .DB 0x10
    .DB 0x0F
    .DB 0x0E
    .DB 0x0D
    .DB 0x0C
    .DB 1
; ---------------------------------------------------------------------------
; START  OF FUNCTION CHUNK FOR SUB_BC8F

LOC_BD52$:
    PUSH AF
    LD   A, (BYTE_BC61$)
    LD   D, A
    POP  AF
    CALL SUB_BD75$
    CP   #0xFF
    JR   Z, SUB_BD8A$
    CP   #0xC0
    JP   Z, LOC_BDC7$
    LD   B, #4
    LD   C, E
    RLA
    RLA
    RLA
    RLA

LOC_BD6B$:
    RLA
    CALL C, SUB_BD8A$
    CALL NC, SUB_BD03$
    DJNZ LOC_BD6B$
    RET
; END OF FUNCTION CHUNK  FOR SUB_BC8F

; =============== S U B R O U T I N E =======================================


SUB_BD75$:
    PUSH AF
    LD   A, (BYTE_BC6B)
    CPL
    LD   B, A
    LD   C, A
    ADD  A, #1
    SRA  A
    SRA  A
    LD   E, A
    CP   #0
    JR   NZ, LOC_BD88$
    INC  E

LOC_BD88$:
    POP  AF
    RET
; END OF FUNCTION SUB_BD75


; =============== S U B R O U T I N E =======================================
SUB_BD8A$:
    PUSH AF
    PUSH HL
    PUSH BC
    LD   A, (BYTE_BC62)
    LD   B, #0
    LD   HL, #0x3E8
LOC_BD95$:
    RRC  D
    JP   NC, LOC_BDB9$
    INC  HL
    BIT  0, (HL)
    JP   Z, LOC_BDB5$
    SET  4, A
    XOR  #0x83
    XOR  #0x83

LOC_BDA6$:
    OUT  (0xFE),  A

LOC_BDA8$:
    NOP
    DEC  B
    JP   NZ, LOC_BD95$
    DEC  C
    JP   NZ, LOC_BD95$
    POP  BC
    POP  HL
    POP  AF
    RET
; ---------------------------------------------------------------------------

LOC_BDB5$:
    RES  4, A
    JR   LOC_BDA6$
; ---------------------------------------------------------------------------

LOC_BDB9$:
    SCF
    JP   NC, 0
    JP   NC, 0
    JP   NC, 0
    NOP
    NOP
    JR   LOC_BDA8$
; END OF FUNCTION SUB_BD8A

; ---------------------------------------------------------------------------
; START  OF FUNCTION CHUNK FOR SUB_BC8F

LOC_BDC7$:
    LD   E, B
    LD   D, #0
    LD   HL, #LOC_BDFF$
    ADC  HL, DE
    LD   A, (HL)
    LD   B, A
    LD   HL, #3

LOC_BDD4$:
    PUSH BC
    LD   DE, #1
    PUSH HL
    CALL SUB_BDE6$
    POP  HL
    LD   DE, #0xFF
    ADC  HL, DE
    POP  BC
    DJNZ LOC_BDD4$
    RET
; END OF FUNCTION CHUNK  FOR SUB_BC8F

; =============== S U B R O U T I N E =======================================
SUB_BDE6$:
    LD   A, L
    SRL  L
    SRL  L
    CPL
    AND  #3
    LD   C, A
    LD   B, #0
    LD   IX, #0x3D1
    ADD  IX, BC
    LD   A, (BYTE_BC62)
    CALL 0x3D4
    DI
    RET
; END OF FUNCTION SUB_BDE6

; ---------------------------------------------------------------------------
LOC_BDFF$:
    .DB  0x0C
    .DB  0x0C
    .DB  0x0D
    .DB  0x0D
    .DB  0x0E
    .DB  0x0E
    .DB  0x0E
    .DB  0x0F
    .DB  0x0F
    .DB  0x0F
    .DB  0x10
    .DB  0x10
    .DB  0x11
    .DB  0x11
    .DB  0x12
    .DB  0x12
    .DB  0x13
    .DB  0x13
    .DB  0x14
    .DB  0x14
    .DB  0x15
    .DB  0x15
    .DB  0x15
    .DB  0x16
  __endasm;
}
