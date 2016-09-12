/***********************/
/*    LASER BASIC 2    */
/*   by Oleg N. Cher   */
/* zx.oberon2.ru/forum */
/***********************/

extern unsigned int Laser2_SPRT_ADR;  // Sprite file start address

// Functions for screen windows processing

void Laser2_ATOF_INSCR (void);
void Laser2_ATON_INSCR (void);
void Laser2_SCRN_INSCR (unsigned int adr) __z88dk_callee;
void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTOR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTND_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTXR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;

void Laser2_PTBL_OUTSCR (signed char col, signed char row, unsigned char spn);
void Laser2_PTOR_OUTSCR (signed char col, signed char row, unsigned char spn);
void Laser2_PTND_OUTSCR (signed char col, signed char row, unsigned char spn);
void Laser2_PTXR_OUTSCR (signed char col, signed char row, unsigned char spn);

/* Спрайты хранятся в памяти в следующем формате:
Байт 1 - номер спрайта.
Байт 2 - младший байт размера спрайта (9*HGT*LEN+3).
Байт 3 - старший байт размера спрайта.
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
*/
/*================================== Header ==================================*/

unsigned int Laser2_SPRT_ADR;  // Sprite file start address

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_ATOF_INSCR (void)
{
  __asm
                  LD    A, #0xC9    ; "RET"
                  LD    (Laser2_ATOF_IN), A
  __endasm;
} //Laser2_ATOF_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_ATON_INSCR (void)
{
  __asm
                  LD    A, #0xED    ; "LD DE,(ADDR) ED5BXXXX"
                  LD    (Laser2_ATOF_IN), A
  __endasm;
} //Laser2_ATON_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SCRN_INSCR (unsigned int adr) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   AF
                  LD    (Laser2_SCR_IN+1), A
                  ADD   #0x18
                  LD    (Laser2_SCRATR_IN+1), A
                  JP    (HL)
  __endasm;
} //Laser2_SCRN_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee {
  __asm
                  POP   HL
                  POP   BC        ; C = col; B = row
                  DEC   SP
                  POP   DE        ; D = spn
                  PUSH  HL
                  XOR   A         ; "NOP"
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTBL_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTOR_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee {
  __asm
                  POP   HL
                  POP   BC        ; C = col; B = row
                  DEC   SP
                  POP   DE        ; D = spn
                  PUSH  HL
                  LD    A, #0xB6  ; "OR (HL)"
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTOR_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTXR_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee {
  __asm
                  POP   HL
                  POP   BC        ; C = col; B = row
                  DEC   SP
                  POP   DE        ; D = spn
                  PUSH  HL
                  LD    A, #0xAE  ; "XOR (HL)"
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTXR_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTND_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee {
  __asm
                  POP   HL
                  POP   BC        ; C = col; B = row
                  DEC   SP
                  POP   DE        ; D = spn
                  PUSH  HL
                  LD    A, #0xA6  ; "AND (HL)"
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTND_INSCR

/*--------------------------------- Cut here ---------------------------------*/

/* Спрайты хранятся в памяти в следующем формате:
Байт 1 - номер спрайта.
Байт 2 - младший байт размера спрайта (9*HGT*LEN+3).
Байт 3 - старший байт размера спрайта.
Байт 4 - ширина спрайта в знакоместах.
Байт 5 - высота спрайта в знакоместах.
8*HGT*LEN - данные о состоянии пикселей.
HGT*LEN - атрибуты.
  ИТОГО: 9*HGT*LEN+5 байтов.
*/

void Laser2_PUT_SPRITE_OUTSCR (void) __naked {
//  A: mode; C: col; D: row; E: spn
__asm
             LD    (SPRT_MODE$), A ; Set draw mode
             LD    (SPRT_XY$+1), HL
             LD    HL, (_Laser2_SPRT_ADR)
FIND_BY_N$:  LD    A, (HL)         ; N of a sprite
             OR    A
             RET   Z
             INC   HL
             CP    E               ; spn
             JR    Z, SPRT_FOUND$
             LD    C, (HL)
             INC   HL
             LD    B, (HL)
             ADD   HL, BC          ; + offset to next sprite
             JR    FIND_BY_N$
SPRT_FOUND$: INC   HL
             INC   HL
SPRT_XY$:    LD    DE, #0
             LD    A, #32          ; 32
             SUB   D               ; - col
             CP    (HL)            ; < len
             JR    NC, SAVE_LEN$
             LD    A, (HL)         ; IF 32-col < len THEN len := 32-col
SAVE_LEN$:   LD    (SPRT_LINE8$+1), A
             LD    B, A            ; |len|
             SUB   (HL)
             NEG
             //LD    (SAVE_REST$+1)  ; rest := len - |len|
             INC   HL
             LD    A, #24          ; 24
             SUB   E               ; - row
             CP    (HL)            ; < hgt
             JR    NC, SAVE_HGT$
             LD    A, (HL)         ; IF 32-row < hgh THEN hgt := 32-row
SAVE_HGT$:   LD    (SPRT_HGT_8$+1), A
Laser2_ATON$:
             LD    C, A            ; |hgt|

;Процедура расчёта адреса атрибутов из координат
; (c) Д.Анисимов, г.Киров, 1996.
; http://zxpress.ru/book_articles.php?id=633
;Первый вариант (E = X; D = Y; 12B; 61T):
             LD    A, D            ;  4
             ADD   A, A            ;  4
             ADD   A, A            ;  4
             ADD   A, A            ;  4
             LD    L, A            ;  4
             LD    H, #0x16        ;  7
             ADD   HL, HL          ; 11
             ADD   HL, HL          ; 11
             LD    A, L            ;  4
             OR    E               ;  4
             LD    L, A            ;  4
/*
;Второй вариант (H = X; L = Y; 10B; 74T):
             LD    A, H            ;  4
             ADD   HL, HL          ; 11
             ADD   HL, HL          ; 11
             ADD   HL, HL          ; 11
             LD    H, #0x16        ;  7
             ADD   HL, HL          ; 11
             ADD   HL, HL          ; 11
             ADD   A, L            ;  4
             LD    L, A            ;  4
*/
;На выходе обеих процедур в HL - адрес файла атрибутов.

OUT_ATR_HLINE$:
             PUSH  BC
             PUSH  HL
OUT_ATR_LINE$:
             LD    A, (DE)
             LD    (HL), A
             INC   DE
             INC   L
             DJNZ  OUT_ATR_LINE$
SAVE_REST$:                        ; Correction of the attributes adress
             LD    HL, #0          ; 10
             ADD   HL, DE          ; 11
             LD    E, L            ;  4
             LD    D, H            ;  4  =>  29
             POP   HL
             LD    BC, #32
             ADD   HL, BC
             POP   BC
             DEC   C
             JR    NZ, OUT_ATR_HLINE$


SPRT_HGT_8$: LD    B, #0           ; Height of sprite
SPRT_HLINE$: PUSH  BC              ; Begin of loop on charlines
             LD    C, #8           ; Height of a character field (charline)
             PUSH  HL
SPRT_LINE8$: LD    B, #0           ; Draw 8 lines (one charline)
             PUSH  HL              ; Draw W bytes (one line)
SPRT_LINE$:  LD    A, (DE)

SPRT_MODE$:  NOP                   ; NOP | AND (HL) | OR (HL) | XOR (HL)
             LD    (HL), A
             INC   HL
             INC   DE
             DJNZ  SPRT_LINE$
             POP   HL
             INC   H               ; Next screen line
             DEC   C
             JR    NZ, SPRT_LINE8$
             POP   HL
             LD    A, #0x20        ; Next charline
             ADD   L
             LD    L, A            ; If carry then jump to next third of screen
             JR    NC, CONTIN_1_3$
             LD    A, #0x08        ; Next third of screen
             ADD   A, H
             LD    H, A            ; HL = HL + 0x0800
CONTIN_1_3$: POP   BC
             DJNZ  SPRT_HLINE$     ; End of loop on charlines (the same third)
             RET
__endasm;
} //Laser2_PUT_SPRITE

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PUT_SPRITE_INSCR (void) __naked {
//  A: mode; C: col; B: row; D: spn
__asm
.globl Laser2_ATOF_IN
.globl Laser2_SCR_IN
.globl Laser2_SCRATR_IN

                  LD    (SPRT_MODE_IN$), A ; Set draw mode

; Процедура расчёта адреса экрана из координат
; Вход:  C = x; B = y
; Выход: HL = адрес видеопамяти

                  LD    A, B
                  AND   #7
                  RRCA
                  RRCA
                  RRCA
                  OR    C
                  LD    L, A
                  LD    A, B
                  AND   #24
Laser2_SCR_IN:    OR    #0x40
                  LD    H, A            ; 14 байт, 53 такта

                  LD    (SCR_ADR_IN$+1), HL

                  LD    HL, (_Laser2_SPRT_ADR)
FIND_BY_N_IN$:    LD    A, (HL)         ; N of a sprite
                  OR    A
                  RET   Z
                  INC   HL
                  CP    D               ; spn
                  JR    Z, SPRT_FOUND_IN$
                  LD    C, (HL)
                  INC   HL
                  LD    B, (HL)
                  ADD   HL, BC          ; + offset to next sprite
                  JR    FIND_BY_N_IN$
SPRT_FOUND_IN$:   INC   HL
                  INC   HL
                  LD    C, (HL)         ; length of sprite
                  INC   HL
                  LD    B, (HL)         ; height of sprite
                  LD    (SPRT_HGT_LEN_IN$+1), BC
                  INC   HL
SCR_ADR_IN$:      LD    DE, #0          ; adr of sprite (up left corner)
SPRT_HLINE_IN$:   LD    A, E            ; Begin of loop on charlines
                  LD    (SCR_LOBYTE_IN$+1), A
                  PUSH  BC
                  LD    B, #8           ; Draw 8 bytes (one charline)
SPRT_CHAR_IN$:    LD    A, (HL)
SPRT_MODE_IN$:    NOP                   ; NOP | AND (HL) | OR (HL) | XOR (HL)
                  LD    (DE), A
                  INC   HL
                  INC   D
                  DJNZ  SPRT_CHAR_IN$
                  LD    B, #8           ; Draw 8 bytes (one charline)
                  LD    A, D
                  SUB   A, B
                  LD    D, A
                  INC   E               ; Next screen line
                  DEC   C
                  JR    NZ, SPRT_CHAR_IN$
SCR_LOBYTE_IN$:   LD    A, #0           ; X
                  ADD   #0x20           ; Next charline
                  LD    E, A            ; If carry then jump to next third of screen
                  JR    NC, CONTIN_1_3_IN$
                  LD    A, D            ; Next third of screen
                  ADD   B
                  LD    D, A            ; DE := DE + 0x0800
CONTIN_1_3_IN$:   POP   BC
                  DJNZ  SPRT_HLINE_IN$  ; End of loop on charlines (the same third)
Laser2_ATOF_IN:                         ; "RET" | "LD DE,(SCR_ADR_IN$+1)"
                  LD    DE, (SCR_ADR_IN$+1)
                  LD    A, D            ; Calculate attribute address
                  RRCA
                  RRCA
                  RRCA
                  AND   #3
Laser2_SCRATR_IN: OR    #0x58
                  LD    D, A

SPRT_HGT_LEN_IN$: LD    BC, #0
                  LD    A, #32
                  SUB   A, C              ; 32 - len
                  LD    (SPRT_HGT_DIS_IN$+1), A
DRAW_ATRLINE_IN$: PUSH  BC                ; Begin of loop on charlines
                  LD    B, #0
                  LDIR
                  LD    A, E
SPRT_HGT_DIS_IN$: ADD   #0
                  LD    E, A
                  LD    A, D
                  ADC   B
                  LD    D, A
                  POP   BC
                  DJNZ  DRAW_ATRLINE_IN$
                  RET
__endasm;
} //Laser2_PUT_SPRITE_INSCR
