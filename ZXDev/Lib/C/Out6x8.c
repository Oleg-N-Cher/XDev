extern void Out6x8_At (signed char x, signed char y) __z88dk_callee;
extern void Out6x8_Ch (unsigned char ch) __z88dk_fastcall;
extern void Out6x8_Ln (void);
extern void Out6x8_Str (unsigned char *str) __z88dk_fastcall;
extern void Out6x8_GenFont (unsigned int dest) __z88dk_fastcall;

extern unsigned int Out6x8_font;
/*================================== Header ==================================*/
unsigned int Out6x8_font; // 6x8 font address

/*--------------------------------- Cut here ---------------------------------*/
void Out6x8_At (signed char x, signed char y) __naked __z88dk_callee {
__asm
        POP  HL
        EX   (SP), HL
        LD   A, #43
        SUB  L
        LD   (_POS_X), A
        LD   A, L
        ADD  L
        ADD  L
        INC  A
        LD   L, A
        AND  #3
        LD   C, A
        LD   A, #1
        SUB  C
        SUB  C
        AND  #7
        LD   (_CHPOS+1), A
        SRL  L
        SRL  L           ; (x * 3 + 1) DIV 4
// Процедура расчёта адреса экрана из координат
//   Вход: L = x; H = y
//   Выход: HL = адрес видеопамяти
        LD   A, H
        AND  #7
        RRCA
        RRCA
        RRCA
        OR   L
        LD   L, A
        LD   A, H
        AND  #24
.globl _Out6x8_SCRADR
_Out6x8_SCRADR:
        ADD  #0x40
        LD   H, A       ; 14 байт, 53 такта
        DEC  L
        LD   (_SCR_ADR+1), HL
        RET
__endasm;
} //Out6x8_At

/*--------------------------------- Cut here ---------------------------------*/
void Out6x8_Ch (unsigned char ch) __naked __z88dk_fastcall {
__asm
        LD   A, L
        LD   (CH_CODE$+1), A
        LD   HL, #_POS_X
        DEC  (HL)
        CALL Z, _Out6x8_Ln
.globl _SCR_ADR
_SCR_ADR:
        LD   DE, #0x40FF  ; DE = экранный адрес
        INC  E
// Alone Coder
// Быстрая печать буквы 6x8 (экран в DE):
.globl _CHPOS
_CHPOS: LD   A, #7 ; C=7,5,3 или 1, где 7 соответствует
        ; нулевой координате буквы внутри знакоместа(x mod 8=0)
        LD   B, A
        EX   AF, AF
        LD   A, #2
        RRCA
        DJNZ .-1
        LD   (PRN$+1), A
CH_CODE$:
        LD   HL, #0 // Вычисление адреса символа
        ADD  HL, HL
        ADD  HL, HL
        ADD  HL, HL
        LD   BC, (_Out6x8_font)
        ADD  HL, BC
        LD   B, #8
PRGO$:  PUSH HL
        LD   L, (HL)
PRN$:   LD   H, #1
PR1$:   ADD  HL, HL
        ADD  HL, HL
        JR   NC, PR1$
        LD   A, (DE)
        OR   H
        LD   (DE), A
        INC  E
        LD   A, L
        LD   (DE), A
        DEC  E
        INC  D
        POP  HL
        INC  HL
        DJNZ PRGO$
        EX   AF, AF
        SUB  #6
        AND  #7
        LD   (_CHPOS+1), A
        CP   #3
        RET  Z
        LD   HL, #_SCR_ADR+1
        INC  (HL)
        RET
.globl _POS_X
_POS_X: .DB  43
__endasm;
} //Out6x8_Ch

/*--------------------------------- Cut here ---------------------------------*/
void Out6x8_Ln (void) __naked {
__asm
        LD   A, #42
        LD   (_POS_X), A
        LD   A, #7
        LD   (_CHPOS+1), A
        LD   HL, #_SCR_ADR+1
        LD   A, (HL)
        OR   #0x1F
        LD   (HL), A
        INC  A
        RET  NZ
        INC  HL
        LD   A, (HL)
        ADD  #8
        LD   (HL), A
        CP   #0x58
        RET  NZ
        LD   (HL), #0x50
        DEC  HL
        LD   (HL), #0xDF
        LD   B, #23
        JP   0xE00           ; Вызов CL_SCROLL
__endasm;
} //Out6x8_Ln

/*--------------------------------- Cut here ---------------------------------*/
void Out6x8_Str (unsigned char *str) __z88dk_fastcall __naked {
__asm
        LD   A, (HL)
        OR   A
        RET  Z
        PUSH HL
        LD   L, A
        CALL _Out6x8_Ch
        POP  HL
        INC  HL
        JR   _Out6x8_Str
__endasm;
} //Out6x8_Str

/*--------------------------------- Cut here ---------------------------------*/
void Out6x8_GenFont (unsigned int dest) __z88dk_fastcall __naked {
__asm
        LD   DE, #0x3D00; Адрес шрифта ПЗУ
        LD   BC, #0x300 ; Длина шрифта
NEXT_B$:LD   A, D       ; Все символы разделяются
        CP   #0x3F      ; на две группы:
        JR   Z, NO_IZM$ ;   1) #2F-#5F
        CP   #0x3D      ;   2) #20-#2E,
                        ;      #60-#7F
        JR   NZ, IZM_1$ ; Преобразование символов
        LD   A, E       ; осуществляется по-разному
        CP   #15*8      ; в зависимости от того,
        JR   C, NO_IZM$ ; к какой группе они принадлежат.
IZM_1$: LD   A, (DE)    ; Преобразование символов первой
        PUSH BC         ; группы
        PUSH AF
        AND  #0b00001111
        RLCA
        LD   B, A
        POP  AF
        AND  #0b11110000
        OR   B
        POP  BC
        JR   BYTEOK$
NO_IZM$:LD   A, (DE)    ; Преобразование
BYTEOK$:RLCA            ; второй группы
        AND  #0b11111100
        LD   (HL), A
        INC  DE
        INC  HL
        DEC  BC
        LD   A, C
        OR   B
        JR   NZ, NEXT_B$
        RET
__endasm;
} //Out6x8_GenFont
