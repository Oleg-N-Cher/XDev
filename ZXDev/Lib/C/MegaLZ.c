void MegaLZ_Depack (unsigned int src, unsigned int dst) __z88dk_callee;
/*================================== Header ==================================*/

/* http://www.boriel.com/wiki/en/index.php/ZX_BASIC:MegaLZ.bas

This routine takes a block of data compressed with the MegaLZ
compression algorithm at SOURCE location and decompresses it
to DESTINATIOn location. */

void MegaLZ_Depack (unsigned int src, unsigned int dst) __naked __z88dk_callee {
  __asm
        POP  BC         ; RET address
        POP  HL         ; HL=src
        POP  DE         ; DE=dst
        PUSH BC         ; restore RET address
/*
    Z80 depacker FOR megalz V4 packed files   (C) fyrex^mhm

    DESCRIPTION:

    Depacker is fully relocatable, NOT self-modifying,
    it's length is 110 bytes starting from DEC40.
    Register usage: AF,AF',BC,DE,HL. Must be CALL'ed, return is done by RET.
    Provide extra stack location FOR store 2 bytes (1 word). Depacker does NOT
    disable OR enable interrupts, AS well AS could be interrupted AT any time
    (no f*cking wicked stack usage :).

    USAGE:

    - put depacker anywhere you want,
    - put starting address of packed block in HL,
    - put location where you want data TO be depacked in DE,
      (much like LDIR command, but without BC)
    - make CALL TO depacker (DEC40).
    - enjoy! ;)

    PRECAUTIONS:

    Be very careful IF packed AND depacked blocks coincide somewhere in memory.
    Here are some advices:

    1. put packed block TO the highest addresses possible.
        Best IF last BYTE of packed block has address #FFFF.

    2. Leave some gap between ends of packed AND depacked block.
        FOR example, last BYTE of depacked block AT #FF00,
        last BYTE of packed block AT #FFFF.

    3. Place nonpackable data TO the END of block.

    4. Always check whether depacking occurs OK AND neither corrupts depacked data
        nor hangs computer.
*/
    ;MLZ_DEPACK:

            LD      A,#0x80
            EX      AF,AF
    MS$:    LDI
    M0$:    LD      BC,#0x2FF
    M1$:    EX      AF,AF
    M1X$:   ADD     A,A
            JR      NZ,M2$
            LD      A,(HL)
            INC     HL
            RLA
    M2$:    RL      C
            JR      NC,M1X$
            EX      AF,AF
            DJNZ    X2$
            LD      A,#2
            SRA     C
            JR      C,N1$
            INC     A
            INC     C
            JR      Z,N2$
            LD      BC,#0x33F
            JR      M1$

    X2$:    DJNZ    X3$
            SRL     C
            JR      C,MS$
            INC     B
            JR      M1$
    X6$:
            ADD     A,C
    N2$:
            LD      BC,#0x4FF
            JR      M1$
    N1$:
            INC     C
            JR      NZ,M4$
            EX      AF,AF
            INC     B
    N5$:    RR      C
            RET     C
            RL      B
            ADD     A,A
            JR      NZ,N6$
            LD      A,(HL)
            INC     HL
            RLA
    N6$:    JR      NC,N5$
            EX      AF,AF
            ADD     A,B
            LD      B,#6
            JR      M1$
    X3$:
            DJNZ    X4$
            LD      A,#1
            JR      M3$
    X4$:    DJNZ    X5$
            INC     C
            JR      NZ,M4$
            LD      BC,#0x51F
            JR      M1$
    X5$:
            DJNZ    X6$
            LD      B,C
    M4$:    LD      C,(HL)
            INC     HL
    M3$:    DEC     B
            PUSH    HL
            LD      L,C
            LD      H,B
            ADD     HL,DE
            LD      C,A
            LD      B,#0
            LDIR
            POP     HL
            JR      M0$
  __endasm;
} //MegaLZ_Depack
