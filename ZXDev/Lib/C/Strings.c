unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee;
unsigned char Strings_IntToStr (int n, unsigned char *str, unsigned int len) __z88dk_callee;
unsigned char Strings_UIntToStr (unsigned int n, unsigned char *str, unsigned int len) __z88dk_callee;
unsigned char Strings_StrToInt (unsigned char *str, unsigned int len, int *result) __z88dk_callee;
/*============================================================================*/

unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __naked __z88dk_callee {
    __asm
        POP  HL
        POP  BC             ; len
        EX   (SP), HL       ; str
        LD   E, C
        LD   D, B
        XOR  A
        CPIR
        EX   DE, HL
        RET  NZ
        SBC  HL, BC
        DEC  HL
        RET
    __endasm;
} //Strings_LengthEx

/*----------------------------------------------------------------------------*/
unsigned char Strings_IntToStr (int n, unsigned char *str, unsigned int len) __naked __z88dk_callee
{
    __asm
        POP  DE
        POP  HL             ; n
        EXX
        POP  HL             ; HL(alt) := str
        EXX
        POP  BC             ; len
        PUSH DE

        BIT  7, H
        JP   Z, _Strings_UIntToStr+7
        LD   A, L           ; HL := -HL
        CPL
        LD   L, A
        LD   A, H
        CPL
        LD   H, A
        INC  HL

        EXX
        LD   (HL), #'-'
        INC  HL
        EXX

        DEC  BC             ; is buffer enough?
        LD   A, C
        OR   B
        JP   NZ, _Strings_UIntToStr+7

        LD   L, #0          ; RETURN FALSE
        RET
__endasm;
} //Strings_IntToStr

/*----------------------------------------------------------------------------*/
unsigned char Strings_UIntToStr (unsigned int n, unsigned char *str, unsigned int len) __naked __z88dk_callee
{
    __asm
        POP  DE
        POP  HL             ; n
        EXX
        POP  HL             ; HL(alt) := str
        EXX
        POP  BC             ; len
        PUSH DE

        LD   A, #255        ; Check buffer size
        ADD  A, B
        SBC  A, A
        OR   C
        LD   B, A           ; B := C, OR 255 IF B # 0

        LD   DE, #-10000    // таблица степеней десятки
        LD   C, E           ; flag := 0xF0
        CALL DIGIT$
        LD   DE, #-1000     ;
        CALL DIGIT$
        LD   DE, #-100      ;
        CALL DIGIT$
        LD   E, #-10        ;
        CALL DIGIT$
        LD   A, L
        ADD  #'0'
        CALL NEXTCH$
        EXX
        LD   (HL), #0       ; Final 0X (ASCIIZ)
        LD   L, #1          ; RETURN TRUE
        RET

DIGIT$: LD   A, #'0'-1      // обнулили счётчик
PDW2$:  INC  A              // увеличиваем счётчик
        ADD  HL, DE         // вычитаем текущую степень десятки
        JR   C, PDW2$       // повторяем пока HL >= 0
        SBC  HL, DE         // HL := HL MOD DE; A := HL DIV DE
        DEC  C              // проверяем: может это незначащий нуль?
        JR   Z, PRNT$       // если уже были другие цифры, печатаем
        CP   #'0'           // если это нуль, то он незначащий
        RET  Z              // ничего не печатаем
PRNT$:  LD   C, #1          // дальше все значащие
NEXTCH$:EXX
        LD   (HL), A
        INC  HL
        EXX
        DJNZ RETRN$
        LD   L, #0          ; RETURN FALSE
        POP  AF
RETRN$:
        RET
    __endasm;
} //Strings_UIntToStr

/*----------------------------------------------------------------------------*/
unsigned char Strings_StrToInt (unsigned char *str, unsigned int len, int *result) __naked __z88dk_callee
{
    __asm
        POP  HL
        POP  DE             ; *str
        POP  BC             ; len
        EX   (SP), HL       ; *result
        LD   (SaveRes$+1), HL

        LD   A, (DE)
        OR   A
        JR   Z, NOT_0_9
        CP   #'-'
        SCF                 ; set flag C = negative
        JR   Z, SetSign$
        CP   #'+'
        JR   Z, SetSign$    ; flag C is reset now
        DEC  BC
        DEC  DE
        SUB  A              ; reset flag C = positive
SetSign$:
        EX   AF, AF
        INC  BC
        LD   HL, #0
S2I_LOOP:
        LD   A, B
        OR   C
        JR   NZ, LenEnough
        CALL S2I_DONE       ; get a partial result
        LD   L, #2          ; RETURN err 2 (out of length)
        RET
LenEnough:
        INC  DE             ; next digit
        LD   A, (DE)
        OR   A
        JR   Z, S2I_DONE
        SUB  #'0'
        JR   C, NOT_0_9
        CP   #10
        JR   NC, NOT_0_9
        PUSH BC
        LD   C, L
        LD   B, H
        ADD  HL, HL         ; * 2
        ADD  HL, HL         ; * 4
        ADD  HL, BC         ; * 5
        ADD  HL, HL         ; *10
        LD   B, #0
        LD   C, A
        ADD  HL, BC         ; + digit
        POP  BC
        DEC  BC
        JR   S2I_LOOP
NOT_0_9:
        CALL S2I_DONE       ; get a partial result
        LD   L, #1          ; RETURN err 1 (not a number)
        RET
S2I_DONE:
        EX   AF, AF
        JR   NC,  SaveRes$  ; NZ = positive
        EX   DE, HL
        LD   HL, #0
        AND  A
        SBC  HL, DE         ; HL := -HL
SaveRes$:
        LD   (SaveRes$+1), HL
        LD   L, #0          ; RETURN ok
        RET 
    __endasm;
} //Strings_StrToInt
