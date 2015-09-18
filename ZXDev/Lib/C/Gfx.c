void Gfx_Fill (unsigned char x, unsigned char y, unsigned char atr);

/*================================== Header ==================================*/

void Gfx_Fill (unsigned char x, unsigned char y, unsigned char atr) __naked {
  __asm
        POP  HL
        POP  DE            ; y, x
        POP  BC            ; atr
        PUSH BC
        PUSH DE
        PUSH HL
        LD   A, D
        CP   #0xC0
        RET  NC            ; y > 191
        
        LD A,D
        LD D,E
        LD E,A

        LD   L, #0
        LD   A, C          ; atr
        CP   #8
        JR   NC, LOC_7DF2$
        LD   L, #0xF8
        LD   H, C

LOC_7DF2$:
        PUSH    DE
        PUSH    HL
        LD    HL, #0
        ADD    HL, SP
        LD    BC, (0x5C65) ; STK_END
        SBC    HL, BC
        SRL    H
        RR    L
        SRL    H
        RR    L
        LD    B, #0xA

LOC_7E08$:
        DEC  HL
        DJNZ LOC_7E08$
        EX   DE, HL
        POP    HL
        EXX
        LD    HL, #0x4000
        LD    IX, #0x5800
        POP    DE
        LD    C, D
        LD    B, #3

LOC_7E19:                ; CODE XREF: SUB_7DB1+6AJ
        SRL    C
        DJNZ    LOC_7E19
        ADD    HL, BC
        ADD    IX, BC
        LD    C, E
        LD    E, #0xBF

LOC_7E23:                ; CODE XREF: SUB_7DB1+79J
        LD    A, E
        CP    C
        JR    Z, LOC_7E2C
        CALL    SUB_7EB9
        JR    LOC_7E23
; ---------------------------------------------------------------------------

LOC_7E2C:                ; CODE XREF: SUB_7DB1+74J
        LD    A, D
        AND    #7
        INC    A
        LD    B, A
        LD    A, (HL)

LOC_7E32:                ; CODE XREF: SUB_7DB1+82J
        RLA
        DJNZ    LOC_7E32
        PUSH    AF
        CALL    C, SUB_7E4C
        CALL    SUB_7EF3
        POP    AF
        CALL    C, SUB_7E4C
        EXX
        LD    A, B
        LD    SP, (0x5C3D) ; ERR_SP
        AND    A
        JP    Z, 0x1BF4 ; STMT_NEXT
        RST    8
        INC    BC
; END OF FUNCTION SUB_7DB1


; =============== S U B    R O U T    I N E =======================================


SUB_7E4C:                ; CODE XREF: SUB_7DB1+85P SUB_7DB1+8CP
        PUSH    IX
        PUSH    HL
        PUSH    DE
        LD    IX, #0x5800
        LD    HL, #0x4000
        LD    D, #3

LOC_7E59:                ; CODE XREF: SUB_7E4C+3EJ
        LD    E, #0

LOC_7E5B:                ; CODE XREF: SUB_7E4C+37J
        LD    B, #8
        PUSH    HL

LOC_7E5E:                ; CODE XREF: SUB_7E4C+16J
        LD    A, (HL)
        CPL
        LD    (HL), A
        INC    H
        DJNZ    LOC_7E5E
        LD    A, 0(IX)
        LD    C, A
        AND    #7
        LD    H, A
        LD    A, C
        AND    #0x38
        LD    B, #3

LOC_7E70:                ; CODE XREF: SUB_7E4C+27J
        RRCA
        RL    H
        DJNZ    LOC_7E70
        OR    H
        LD    H, A
        LD    A, C
        AND    #0xC0
        OR    H
        LD    0(IX),    A
        POP    HL
        INC    HL
        INC    IX
        DEC    E
        JR    NZ, LOC_7E5B
        LD    A, H
        ADD    A, #7
        LD    H, A
        DEC    D
        JR    NZ, LOC_7E59
        POP    DE
        POP    HL
        POP    IX
        RET
; END OF FUNCTION SUB_7E4C


; =============== S U B    R O U T    I N E =======================================


SUB_7E91:                ; CODE XREF: SUB_7EF3+7P SUB_7EF3+75P    ...
        EXX
        BIT    7, L
        EXX
        RET    Z
        LD    A, 0(IX)
        EXX
        AND    L
        OR    H
        EXX
        LD    0(IX),    A
        RET
; END OF FUNCTION SUB_7E91


; =============== S U B    R O U T    I N E =======================================


SUB_7EA1:                ; CODE XREF: SUB_7EF3+C5P
                    ; SUB_7EF3:LOC_7FE8P
        INC    E
        LD    A, E
        DEC    H
        AND    #7
        RET    NZ
        PUSH    BC
        LD    BC, #0xFFE0
        ADD    IX, BC
        ADD    HL, BC
        INC    H
        POP    BC
        LD    A, E
        AND    #0x3F
        RET    Z
        LD    A, H
        ADD    A, #7
        LD    H, A
        RET
; END OF FUNCTION SUB_7EA1


; =============== S U B    R O U T    I N E =======================================


SUB_7EB9:
        LD    A, E
SUB_7EBA:
        INC    H
        DEC    E
        AND    #7
        RET    NZ
        PUSH    BC
        LD    BC, #0x20
        ADD    IX, BC
        ADD    HL, BC
        DEC    H
        POP    BC
        LD    A, E
        INC    A
        AND    #0x3F
        RET    Z
        LD    A, H
        SUB    #7
        LD    H, A
        RET
; END OF FUNCTION SUB_7EBA


; =============== S U B    R O U T    I N E =======================================


SUB_7ED2:                ; CODE XREF: SUB_7EF3+C8P
                    ; SUB_7EF3:LOC_7FCBP ...
        PUSH    BC
        LD    B, C
        SRL    B
        SRL    B
        SRL    B
        LD    A, L
        AND    #0xE0
        OR    B
        LD    L, A
        PUSH    IX
        EX    (SP), HL
        LD    A, L
        AND    #0xE0
        OR    B
        LD    L, A
        EX    (SP), HL
        POP    IX
        POP    BC
        LD    D, C
        RET
; END OF FUNCTION SUB_7ED2

; ---------------------------------------------------------------------------
; START    OF FUNCTION CHUNK FOR SUB_7EF3

LOC_7EED:                ; CODE XREF: SUB_7EF3+4J
        LD    B, D
        INC    DE
        EXX
        LD    D, #0
        RET
; END OF FUNCTION CHUNK    FOR SUB_7EF3

; =============== S U B    R O U T    I N E =======================================


SUB_7EF3:                ; CODE XREF: SUB_7DB1+88P SUB_7EF3+CCP ...

; FUNCTION CHUNK AT 7EED SIZE 00000006 BYTES

        EXX
        DEC    DE
        BIT    7, D
        JR    NZ, LOC_7EED
        EXX
        CALL    SUB_7E91
        LD    A, (HL)
        AND    A
        JR    Z, LOC_7F52
        LD    C, A
        INC    A
        LD    A, D
        JR    Z, LOC_7F20
        AND    #7
        INC    A
        LD    B, A
        LD    A, C
        LD    C, B

LOC_7F0C:                ; CODE XREF: SUB_7EF3+1AJ
        RLCA
        DJNZ    LOC_7F0C
        JR    NC, LOC_7F3B
        INC    D
        JR    Z, LOC_7F1C
        LD    A, D
        AND    #7
        JR    NZ, LOC_7F1C

LOC_7F19:                ; CODE XREF: SUB_7EF3+34J
        INC    HL
        INC    IX

LOC_7F1C:                ; CODE XREF: SUB_7EF3+1FJ SUB_7EF3+24J ...
        EXX
        INC    DE
        EXX
        RET
; ---------------------------------------------------------------------------

LOC_7F20:                ; CODE XREF: SUB_7EF3+11J
        AND    #0xF8
        ADD    A, #8
        LD    D, A
        JR    Z, LOC_7F1C
        JR    LOC_7F19
; ---------------------------------------------------------------------------

LOC_7F29:                ; CODE XREF: SUB_7EF3+57J
        LD    (HL), A
        LD    A, D
        DEC    A
        AND    #0xF8
        ADD    A, B
        LD    C, A
        DEC    B
        JR    Z, LOC_7F38
        LD    A, (HL)

LOC_7F34:                ; CODE XREF: SUB_7EF3+42J
        RRCA
        DJNZ    LOC_7F34
        LD    (HL), A

LOC_7F38:                ; CODE XREF: SUB_7EF3+3EJ
        LD    A, D
        JR    LOC_7F87
; ---------------------------------------------------------------------------

LOC_7F3B:                ; CODE XREF: SUB_7EF3+1CJ SUB_7EF3+51J
        INC    D
        BIT    3, C
        JR    NZ, LOC_7F47
        RLCA
        JR    C, LOC_7F46
        INC    C
        JR    LOC_7F3B
; ---------------------------------------------------------------------------

LOC_7F46:                ; CODE XREF: SUB_7EF3+4EJ
        RRCA

LOC_7F47:                ; CODE XREF: SUB_7EF3+4BJ
        LD    B, C

LOC_7F48:                ; CODE XREF: SUB_7EF3+59J
        SCF
        RRA
        JR    C, LOC_7F29
        DJNZ    LOC_7F48
        LD    (HL), A
        LD    A, D
        JR    LOC_7F5A
; ---------------------------------------------------------------------------

LOC_7F52:                ; CODE XREF: SUB_7EF3+CJ
        LD    (HL), #0xFF
        LD    A, D
        AND    #0xF8
        ADD    A, #8
        INC    D

LOC_7F5A:                ; CODE XREF: SUB_7EF3+5DJ
        LD    C, A
        PUSH    HL
        PUSH    IX

LOC_7F5E:                ; CODE XREF: SUB_7EF3+7CJ
        LD    A, D
        DEC    A
        AND    #0xF8
        LD    D, A
        JR    Z, LOC_7F81
        DEC    HL
        DEC    IX
        CALL    SUB_7E91
        LD    A, (HL)
        LD    (HL), #0xFF
        AND    A
        JR    Z, LOC_7F5E
        LD    B, #0
        SCF

LOC_7F74:                ; CODE XREF: SUB_7EF3+83J
        INC    B
        RRA
        JR    NC, LOC_7F74
        DEC    B

LOC_7F79:                ; CODE XREF: SUB_7EF3+88J
        SCF
        RLA
        JR    NC, LOC_7F79
        LD    (HL), A
        LD    A, D
        SUB    B
        LD    D, A

LOC_7F81:                ; CODE XREF: SUB_7EF3+70J
        POP    IX
        POP    HL
        LD    A, C
        LD    C, D
        LD    D, A

LOC_7F87:                ; CODE XREF: SUB_7EF3+46J
        AND    #7
        JR    NZ, LOC_7FB1
        LD    A, D
        AND    A

LOC_7F8D:                ; CODE XREF: SUB_7EF3+ACJ
        JR    Z, LOC_7FB1
        INC    HL
        INC    IX
        CALL    SUB_7E91
        LD    A, (HL)
        AND    A
        JR    NZ, LOC_7FA1
        LD    (HL), #0xFF
        LD    A, D
        ADD    A, #8
        LD    D, A
        JR    LOC_7F8D
; ---------------------------------------------------------------------------

LOC_7FA1:                ; CODE XREF: SUB_7EF3+A4J
        LD    B, #0
        SCF

LOC_7FA4:                ; CODE XREF: SUB_7EF3+B3J
        INC    B
        RLA
        JR    NC, LOC_7FA4
        DEC    B

LOC_7FA9:                ; CODE XREF: SUB_7EF3+B8J
        SCF
        RRA
        JR    NC, LOC_7FA9
        LD    (HL), A
        LD    A, D
        ADD    A, B
        LD    D, A

LOC_7FB1:                ; CODE XREF: SUB_7EF3+96J
                    ; SUB_7EF3:LOC_7F8DJ
        LD    B, D
        DEC    B
        LD    A, E
        CP    #0xBF
        JR    NC, LOC_7FD1
        CALL    SUB_7EA1
        CALL    SUB_7ED2

LOC_7FBE:                ; CODE XREF: SUB_7EF3+D6J
        PUSH    BC
        CALL    SUB_7EF3
        POP    BC
        LD    A, D
        SUB    #1
        JR    C, LOC_7FCB
        CP    B
        JR    C, LOC_7FBE

LOC_7FCB:                ; CODE XREF: SUB_7EF3+D3J
        CALL    SUB_7ED2
        CALL    SUB_7EB9

LOC_7FD1:                ; CODE XREF: SUB_7EF3+C3J
        LD    A, E
        AND    A
        JR    Z, LOC_7FEB
        CALL    SUB_7EBA
        CALL    SUB_7ED2

LOC_7FDB:                ; CODE XREF: SUB_7EF3+F3J
        PUSH    BC
        CALL    SUB_7EF3
        POP    BC
        LD    A, D
        SUB    #1
        JR    C, LOC_7FE8
        CP    B
        JR    C, LOC_7FDB

LOC_7FE8:                ; CODE XREF: SUB_7EF3+F0J
        CALL    SUB_7EA1

LOC_7FEB:                ; CODE XREF: SUB_7EF3+E0J
        LD    C, B
        CALL    SUB_7ED2
        EXX
        INC    DE
        EXX
        INC    D
        RET    Z
        INC    D
        RET    Z
        LD    A, D
        AND    #7
        CP    #2
        RET    NC
        INC    HL
        INC    IX
        RET
; END OF FUNCTION SUB_7EF3

  __endasm;
} //Gfx_Fill

