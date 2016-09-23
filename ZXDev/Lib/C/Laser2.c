/**************************/
/* LASER 2 Graphic Engine */
/*    by Oleg N. Cher     */
/*  zx.oberon2.ru/forum   */
/**************************/

extern unsigned int Laser2_SPRT_ADR;  // Sprite file start address

// Sprite engine:

void Laser2_ATOF_INSCR  (void);
void Laser2_ATOF_OUTSCR (void);
void Laser2_ATON_INSCR  (void);
void Laser2_ATON_OUTSCR (void);
void Laser2_INVM        (unsigned char spn)      __z88dk_fastcall;
void Laser2_SCRN_INSCR  (unsigned char hbyteadr) __z88dk_fastcall;
void Laser2_SCRN_OUTSCR (unsigned char hbyteadr) __z88dk_fastcall;
void Laser2_PTBL_INSCR  (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTBL_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTND_INSCR  (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTND_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTNV_INSCR  (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTNV_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTOR_INSCR  (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTOR_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTXR_INSCR  (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTXR_OUTSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;

// Screen windows processing:

void Laser2_CLSV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_INVV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_MIRV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SL1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SL4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SL8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SR1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SR4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SR8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_WL1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_WL4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_WL8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_WR1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_WR4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_WR8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;

// Attribute windows processing:

void Laser2_AWLV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_AWRV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_MARV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_SETV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;

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

static typedef struct Sprite {
  BYTE sprN;
  struct Sprite *sprNext;
  BYTE sprLen;
  BYTE sprHgt;
};
*/
/*================================== Header ==================================*/

unsigned int _Laser2_SPRT_ADR;  // Sprite file start address

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_ATOF_INSCR (void)
{
  __asm
                  LD    A, #0xC9    ; "RET"
                  LD    (_Laser2_ATOF_IN), A
  __endasm;
} //Laser2_ATOF_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_ATOF_OUTSCR (void)
{
  __asm
                  LD    A, #0xC9    ; "RET"
                  LD    (_Laser2_ATOF_OUT), A
  __endasm;
} //Laser2_ATOF_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_ATON_INSCR (void)
{
  __asm
                  LD    A, #0xED    ; "LD DE,(ADDR) ED5BXXXX"
                  LD    (_Laser2_ATOF_IN), A
  __endasm;
} //Laser2_ATON_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_ATON_OUTSCR (void)
{
  __asm
                  LD    A, #0x11    ; "LD DE, NN 11XXXX"
                  LD    (_Laser2_ATOF_OUT), A
  __endasm;
} //Laser2_ATON_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SCRN_INSCR (unsigned char hbyteadr) __z88dk_fastcall
{
  __asm
                  LD    A, L
                  LD    (_Laser2_SCR_IN+1), A
                  ADD   #0x18
                  LD    (_Laser2_SCRATR_IN+1), A
                  LD    (_Laser2_SCRATR+1), A
  __endasm;
} //Laser2_SCRN_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SCRN_OUTSCR (unsigned char hbyteadr) __z88dk_fastcall
{
  __asm
                  LD    A, L
                  LD    (_Laser2_SCR_OUT+1), A
                  ADD   #0x18
                  LD    (_Laser2_SCRATR_OUT+1), A
                  LD    (_Laser2_SCRATR+1), A
  __endasm;
} //Laser2_SCRN_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0x007E  ; "LD A,(HL)" "NOP"
                  JP    __Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTBL_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTBL_OUTSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0x007E  ; "LD A,(HL)" "NOP"
                  JP    __Laser2_PUT_SPRITE_OUTSCR
  __endasm;
} //Laser2_PTBL_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTND_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0xA61A  ; "LD A,(DE)" "AND (HL)"
                  JP    __Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTND_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTND_OUTSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0xA61A  ; "LD A,(DE)" "AND (HL)"
                  JP    __Laser2_PUT_SPRITE_OUTSCR
  __endasm;
} //Laser2_PTND_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTNV_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0x2F7E  ; "LD A,(HL)" "CPL"
                  JP    __Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTNV_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTNV_OUTSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0x2F7E  ; "LD A,(HL)" "CPL"
                  JP    __Laser2_PUT_SPRITE_OUTSCR
  __endasm;
} //Laser2_PTNV_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTOR_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0xB61A  ; "LD A,(DE)" "OR (HL)"
                  JP    __Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTOR_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTOR_OUTSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0xB61A  ; "LD A,(DE)" "OR (HL)"
                  JP    __Laser2_PUT_SPRITE_OUTSCR
  __endasm;
} //Laser2_PTOR_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTXR_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0xAE1A  ; "LD A,(DE)" "XOR (HL)"
                  JP    __Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTXR_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTXR_OUTSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0xAE1A  ; "LD A,(DE)" "XOR (HL)"
                  JP    __Laser2_PUT_SPRITE_OUTSCR
  __endasm;
} //Laser2_PTXR_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_XYtoScr (void) {
// Процедура расчёта адреса экрана из координат
//  Вход: C = x; B = y
// Выход: HL = адрес видеопамяти
  __asm
  
.globl _Laser2_SCR_IN

                  LD    A, B
                  AND   #7
                  RRCA
                  RRCA
                  RRCA
                  OR    C
                  LD    L, A
                  LD    A, B
                  AND   #24
_Laser2_SCR_IN:   OR    #0x40
                  LD    H, A            ; 14 байт, 53 такта
  __endasm;
} //_Laser2_XYtoScr

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_XYtoScrAtr (void) {
// Процедура вычисления адреса на экране по координатам
//  Вход: L=x, H=y
// Выход: HL = адрес памяти атрибутов
  __asm
  
.globl _Laser2_SCRATR

                  ; HL = y
                  LD    A, L
                  LD    L, H
                  LD    H, #0
                  ; HL = y*32
                  ADD   HL, HL
                  ADD   HL, HL
                  ADD   HL, HL
                  ADD   HL, HL
                  ADD   HL, HL
                  ; HL = y*32 + x
                  ADD   A, L
                  LD    L, A
                  ;
                  LD    A, H     ; 4t
_Laser2_SCRATR:   ADD   #0x58    ; 7t
                  LD    H, A     ; 4t
  __endasm;
} //_Laser2_XYtoScrAtr

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_FindSprite (void)
// Input:  D = spn
// Output: Z = not found | NZ = found
//         HL = adr
{
  __asm
                  LD    HL, (__Laser2_SPRT_ADR)
FIND_BY_N_IN$:    LD    A, (HL)         ; N of a sprite
                  OR    A
                  RET   Z               ; Return Z
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
                  OR    A               ; Return NZ
  __endasm;
} //_Laser2_FindSprite

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_DE_x8 (void)
// Input:  DE = x
// Output: DE = 8*x
{
  __asm
                  SLA   E
                  RL    D
                  SLA   E
                  RL    D
                  SLA   E
                  RL    D
  __endasm;
} //_Laser2_DE_x8

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_HL_x8 (void)
// Input:  HL = x
// Output: HL = 8*x
{
  __asm
                  SLA   L
                  RL    H
                  SLA   L
                  RL    H
                  SLA   L
                  RL    H
  __endasm;
} //_Laser2_HL_x8

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_PUT_SPRITE_OUTSCR (void) {
//  HL: mode; C: col; B: row; D: spn
__asm
.globl _Laser2_ATOF_OUT
.globl _Laser2_SCRATR_OUT

                  LD    (SPRT_MODE_OUT$), HL ; Set draw mode

                  PUSH  BC
                  CALL  __Laser2_FindSprite
                  POP   DE
                  RET   Z
                  
                  ; col
                  LD    C, (HL)         ; len
                  LD    A, C
                  EX    AF, AF
                  XOR   A
                  LD    (LEFT_SKIP$+1), A
                  LD    A, E
                  OR    A               ; IF col < 0 THEN
                  JP    P, X_POSITIVE_OR_0$
                  NEG
                  LD    (LEFT_SKIP$+1), A
                  LD    A, E
                  ADD   C
                  RET   Z               ;   -col = len
                  RET   M               ;   -col < len
                  LD    C, A            ;   len := len + col
                  LD    E, #0           ;   col := 0
                                        ; END
                  ; len
X_POSITIVE_OR_0$: LD    A, E
                  SUB   #32
                  RET   NC              ; IF col >= 32 THEN RETURN END
                  ADD   C
                  JP    P, COR_RIGHT_SKIP$
                  XOR   A
COR_RIGHT_SKIP$:  LD    (RIGHT_SKIP$+1), A
                  NEG
                  ADD   C
                  LD    C, A            ;

                  ; row
                  INC   HL
                  LD    B, (HL)         ; hgt
                  XOR   A
                  LD    (UP_SKIP$+1), A
                  LD    A, D
                  OR    A               ; IF row < 0 THEN
                  JP    P, Y_POSITIVE_OR_0$
                  NEG
                  LD    (UP_SKIP$+1), A
                  LD    A, D
                  ADD   B
                  RET   Z               ;   -row = hgt
                  RET   M               ;   -row < hgt
                  LD    B, A            ;   hgt := hgt + row
                  LD    D, #0           ;   row := 0
                                        ; END
                  ; hgt
Y_POSITIVE_OR_0$: LD    A, D
                  SUB   #24
                  RET   NC              ; IF row >= 24 THEN RETURN END
                  ADD   B
                  JP    P, COR_DOWN_SKIP$
                  XOR   A
COR_DOWN_SKIP$:   LD    (DOWN_SKIP$+1), A
                  NEG
                  ADD   B
                  LD    B, A
                  PUSH  BC              ; len hgt
                  PUSH  HL

                  LD    C, E
                  LD    B, D
                  CALL  __Laser2_XYtoScr
                  LD    (SCR_ADR_OUT$+1), HL

LEFT_SKIP$:       LD    HL, #0
                  CALL  __Laser2_HL_x8
                  LD    (LEFT_SKIP_x8$+1), HL

RIGHT_SKIP$:      LD    HL, #0
                  CALL  __Laser2_HL_x8
                  LD    (RIGHT_SKIP_x8$+1), HL

                  LD    HL, #0
DOWN_SKIP$:       LD    DE, #0
                  CALL  __Laser2_DE_x8
                  EX    AF, AF
                  PUSH  AF
INC_DN_SKIP_LINE$:ADD   HL, DE
                  DEC   A
                  JR    NZ, INC_DN_SKIP_LINE$
                  LD    (DOWN_SKIP_x8$+1), HL

                  POP   AF
                  LD    (UP_SKIP_MULT$+1), A
                  POP   HL
                  INC   HL
UP_SKIP$:         LD    DE, #0
                  CALL  __Laser2_DE_x8
INC_UP_SKIP_LINE$:ADD   HL, DE
                  DEC   A
                  JR    NZ, INC_UP_SKIP_LINE$

                  POP   BC              ; len hgt
                  PUSH  BC
SCR_ADR_OUT$:     LD    DE, #0          ; adr at screen (up left corner)
SPRT_HLINE_OUT$:  LD    A, E            ; Begin of loop on charlines
                  LD    (SCR_LOBYTE_OUT$+1), A
                  PUSH  DE
LEFT_SKIP_x8$:    LD    DE, #0
                  ADD   HL, DE
                  POP   DE
                  PUSH  BC
                  LD    B, #8           ; Draw 8 bytes (one charline)
SPRT_CHAR_OUT$:
SPRT_MODE_OUT$:   LD    A, (HL)         ; "LD A, (HL) " | "LD A, (DE)"
                  NOP                   ; "NOP" | "CPL" | "AND (HL)" | "OR (HL)" | "XOR (HL)"
                  LD    (DE), A
                  INC   HL
                  INC   D
                  DJNZ  SPRT_CHAR_OUT$
                  LD    B, #8           ; Draw 8 bytes (one charline)
                  LD    A, D
                  SUB   A, B
                  LD    D, A
                  INC   E               ; Next screen line
                  DEC   C
                  JR    NZ, SPRT_CHAR_OUT$
SCR_LOBYTE_OUT$:  LD    A, #0           ; X
                  ADD   #0x20           ; Next charline
                  LD    E, A            ; If carry then jump to next third of screen
                  JR    NC, CONTIN_1_3_OUT$
                  LD    A, D            ; Next third of screen
                  ADD   B
                  LD    D, A            ; DE := DE + 0x0800
CONTIN_1_3_OUT$:
RIGHT_SKIP_x8$:   LD    BC, #0
                  ADD   HL, BC
                  POP   BC
                  DJNZ  SPRT_HLINE_OUT$ ; End of loop on charlines (the same third)
                  POP   BC              ; len hgt
_Laser2_ATOF_OUT:                       ; "RET" | "LD DE, NN"
DOWN_SKIP_x8$:    LD    DE, #0
                  ADD   HL, DE
UP_SKIP_MULT$:    LD    A, #0

COR_UP_SKIP$:     EX    AF, AF
                  LD    A, (UP_SKIP$+1)
                  ADD   L
                  LD    L, A
                  LD    A, H
                  ADC   #0
                  LD    H, A
                  EX    AF, AF
                  DEC   A
                  JR    NZ, COR_UP_SKIP$

                  LD    DE, (SCR_ADR_OUT$+1)
                  LD    A, D            ; Calculate attribute address
                  RRCA
                  RRCA
                  RRCA
                  AND   #3
_Laser2_SCRATR_OUT:
                  OR    #0x58
                  LD    D, A

                  LD    A, #32
                  SUB   A, C              ; 32 - len
                  LD    (SPRT_HGT_DIS_OUT$+1), A
DRAW_ATRLINE_OUT$:PUSH  BC                ; Begin of loop on charlines
                  LD    B, #0
                  
                  LD    A, (LEFT_SKIP$+1)
                  ADD   L
                  LD    L, A
                  LD    A, H
                  ADC   #0
                  LD    H, A

                  LDIR

                  LD    A, (RIGHT_SKIP$+1)
                  ADD   L
                  LD    L, A
                  LD    A, H
                  ADC   B
                  LD    H, A

                  LD    A, E
SPRT_HGT_DIS_OUT$:ADD   #0
                  LD    E, A
                  LD    A, D
                  ADC   B
                  LD    D, A
                  POP   BC
                  DJNZ  DRAW_ATRLINE_OUT$
__endasm;
} //_Laser2_PUT_SPRITE_OUTSCR

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_PUT_SPRITE_INSCR (void) {
//  HL: mode; C: col; B: row; D: spn
__asm
.globl _Laser2_ATOF_IN
.globl _Laser2_SCRATR_IN

                  LD    (SPRT_MODE_IN$), HL ; Set draw mode

                  CALL  __Laser2_XYtoScr
                  LD    (SCR_ADR_IN$+1), HL

                  CALL  __Laser2_FindSprite
                  RET   Z
                  LD    C, (HL)         ; length of sprite
                  INC   HL
                  LD    B, (HL)         ; height of sprite
                  INC   HL
                  PUSH  BC              ; len hgt
SCR_ADR_IN$:      LD    DE, #0          ; adr at screen (up left corner)
SPRT_HLINE_IN$:   LD    A, E            ; Begin of loop on charlines
                  LD    (SCR_LOBYTE_IN$+1), A
                  PUSH  BC
                  LD    B, #8           ; Draw 8 bytes (one charline)
SPRT_CHAR_IN$:
SPRT_MODE_IN$:    LD    A, (HL)         ; "LD A, (HL) " | "LD A, (DE)"
                  NOP                   ; "NOP" | "CPL" | "AND (HL)" | "OR (HL)" | "XOR (HL)"
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
                  POP   BC              ; len hgt
_Laser2_ATOF_IN:                        ; "RET" | "LD DE,(SCR_ADR_IN$+1)"
                  LD    DE, (SCR_ADR_IN$+1)
                  LD    A, D            ; Calculate attribute address
                  RRCA
                  RRCA
                  RRCA
                  AND   #3
_Laser2_SCRATR_IN:OR    #0x58
                  LD    D, A

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
__endasm;
} //_Laser2_PUT_SPRITE_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_CLSV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE

CLSV_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    E, L
                  LD    D, H
                  XOR   A
CLSV_PUT_ZERO0$:  LD    B, #8
CLSV_PUT_ZERO$:   LD    (DE), A
                  INC   D
                  DJNZ  CLSV_PUT_ZERO$
                  LD    D, H            ; Restore D
                  INC   E               ; Next screen line
                  DEC   C
                  JR    NZ, CLSV_PUT_ZERO0$
                  LD    A, L            ; Restore E
                  ADD   #0x20           ; Next charline
                  LD    E, A            ; If carry then jump to next third of screen
                  JR    NC, CONTIN_1_3_CLSV$
                  LD    A, D            ; Next third of screen
                  ADD   #8
                  LD    D, A            ; DE := DE + 0x0800
CONTIN_1_3_CLSV$: POP   BC
                  DJNZ  CLSV_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_CLSV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_INVM (unsigned char spn) __z88dk_fastcall
{
  __asm
                  LD    D, L      ; D = spn

                  CALL  __Laser2_FindSprite
                  RET   Z
                  LD    A, (HL)         ; length of sprite
                  ADD   A
                  ADD   A               ; This code works only for length <= 32
                  ADD   A
                  LD    E, A            ; 32*8 MOD 256 = 0
                  INC   HL
                  LD    D, (HL)         ; height of sprite
                  INC   HL

INVM_NEXT_LINE$:  LD    B, E
INVM_NEXT_BYTE$:  LD    A, (HL)
                  CPL
                  LD    (HL), A
                  INC   HL
                  DJNZ  INVM_NEXT_BYTE$
                  DEC   D
                  JR    NZ, INVM_NEXT_LINE$
__endasm;
} //Laser2_INVM

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_INVV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE

INVV_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    E, L
                  LD    D, H
INVV_INV_BYTE0$:  LD    B, #8
INVV_INV_BYTE$:   LD    A, (DE)
                  CPL
                  LD    (DE), A
                  INC   D
                  DJNZ  INVV_INV_BYTE$
                  LD    D, H            ; Restore D
                  INC   E               ; Next screen line
                  DEC   C
                  JR    NZ, INVV_INV_BYTE0$
                  LD    A, L            ; Restore E
                  ADD   #0x20           ; Next charline
                  LD    E, A            ; If carry then jump to next third of screen
                  JR    NC, INVV_CONTIN_1_3$
                  LD    A, D            ; Next third of screen
                  ADD   #8
                  LD    D, A            ; DE := DE + 0x0800
INVV_CONTIN_1_3$: POP   BC
                  DJNZ  INVV_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_INVV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SETV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   HL              ; L = col; H = row
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  
                  CALL  __Laser2_XYtoScrAtr

                  LD    A, #32
                  SUB   A, C
                  LD    E, A
                  LD    D, #0           ; DE := 32 - len

                  LD    A, (0x5C8D)     ; (ATTR_P)
SETV_SetAtrRect$: PUSH  BC
SETV_SetAtrLine$: LD    (HL), A
                  INC   HL
                  DEC   C
                  JR    NZ, SETV_SetAtrLine$
                  POP   BC
                  ADD   HL, DE          ; Jump to next attribute line
                  DJNZ  SETV_SetAtrRect$
  __endasm;
} //Laser2_SETV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_AWLV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   HL              ; L = col; H = row
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  DEC   C
                  RET   Z               ; IF len = 1 THEN RETURN
                  CALL  __Laser2_XYtoScrAtr

                  LD    A, #32
                  SUB   C
                  LD    (AWLV_LEN_DIS$+1), A

AWLV_ROLL_ATRLN$: PUSH  BC              ; Begin of loop on charlines
                  LD    E, L
                  LD    D, H
                  INC   L
                  LD    B, #0
                  LD    A, (DE)
                  LDIR
                  LD    (DE), A
                  LD    A, E
AWLV_LEN_DIS$:    ADD   #0
                  LD    L, A
                  LD    A, D
                  ADC   B
                  LD    H, A
                  POP   BC
                  DJNZ  AWLV_ROLL_ATRLN$
  __endasm;
} //Laser2_AWLV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_AWRV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   HL              ; L = col; H = row
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  DEC   C
                  RET   Z               ; IF len = 1 THEN RETURN

                  CALL  __Laser2_XYtoScrAtr
                  LD    A, L
                  ADD   C               ; adr := adr + len
                  LD    L, A
                  
                  LD    A, #32
                  ADD   C
                  LD    (AWRV_LEN_DIS$+1), A

AWRV_ROLL_ATRLN$: PUSH  BC              ; Begin of loop on charlines
                  LD    E, L
                  LD    D, H
                  DEC   L
                  LD    B, #0
                  LD    A, (DE)
                  LDDR
                  LD    (DE), A
                  LD    A, E
AWRV_LEN_DIS$:    ADD   #0
                  LD    L, A
                  LD    A, D
                  ADC   B
                  LD    H, A
                  POP   BC
                  DJNZ  AWRV_ROLL_ATRLN$
  __endasm;
} //Laser2_AWRV

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_SLXV (void)
{
  __asm
                  LD    (SLXV_ROLL_LINE$), HL
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  LD    A, C
                  DEC   A
                  ADD   L
                  LD    L, A
SLXV_HLINE$:      PUSH  BC
                  LD    D, #8
                  LD    E, L
SLXV_ROLL_LINE8$: LD    B, C
                  XOR   A               ; Flag C is off
SLXV_ROLL_LINE$:  RL    (HL)            ; SL1V: "RL (HL)" | SL4V: "RLD"
                  DEC   L
                  DJNZ  SLXV_ROLL_LINE$
                  LD    L, E
                  INC   H
                  DEC   D
                  JR    NZ, SLXV_ROLL_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, SLXV_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
SLXV_CONT_1_3$:   POP   BC
                  DJNZ  SLXV_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //_Laser2_SLXV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SL1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __naked __z88dk_callee
{
  __asm
                  LD    HL, #0x16CB     ; "RL (HL)"
                  JP    __Laser2_SLXV
  __endasm;
} //Laser2_SL1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SL4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __naked __z88dk_callee
{
  __asm
                  LD    HL, #0x6FED     ; "RLD"
                  JP    __Laser2_SLXV
  __endasm;
} //Laser2_SL4V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_SX8V (void) // C = 0; B = hgt; HL = screen adr
{
  __asm
                  LD    D, #8           ; Begin of loop on charlines
SX8V_CHAR$:       LD    (HL), C         ; [HL] := 0
                  INC   H
                  DEC   D
                  JR    NZ, SX8V_CHAR$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, SX8V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
SX8V_CONT_1_3$:   DJNZ  SX8V_CHAR$
  __endasm;
} //_Laser2_SX8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SL8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  DEC   C
                  JP    Z,__Laser2_SX8V ; IF len = 1 THEN Clear rect of len = 1

SL8V_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    B, #8
                  XOR   A
SL8V_LINE8$:      LD    (SL8V_SCRADR$+1), HL
                  LD    E, L
                  LD    D, H
                  INC   L
                  PUSH  BC
                  LD    B, A
                  LDIR
                  LD    (DE), A
SL8V_SCRADR$:     LD    HL, #0
                  INC   H
                  POP   BC
                  DJNZ  SL8V_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, SL8V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
SL8V_CONT_1_3$:   POP   BC
                  DJNZ  SL8V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_SL8V

/*--------------------------------- Cut here ---------------------------------*/
void _Laser2_SRXV (void)
{
  __asm
                  LD    (SRXV_ROLL_LINE$), HL
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
SRXV_HLINE$:      PUSH  BC
                  LD    D, #8
                  LD    E, L
SRXV_ROLL_LINE8$: LD    B, C
                  XOR   A               ; Flag C is off
SRXV_ROLL_LINE$:  RR    (HL)
                  INC   L
                  DJNZ  SRXV_ROLL_LINE$
                  LD    L, E
                  INC   H
                  DEC   D
                  JR    NZ, SRXV_ROLL_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, SRXV_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
SRXV_CONT_1_3$:   POP   BC
                  DJNZ  SRXV_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //_Laser2_SRXV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SR1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __naked __z88dk_callee
{
  __asm
                  LD    HL, #0x1ECB     ; "RL (HL)"
                  JP    __Laser2_SRXV
  __endasm;
} //Laser2_SR1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SR4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __naked __z88dk_callee
{
  __asm
                  LD    HL, #0x67ED     ; "RRD"
                  JP    __Laser2_SRXV
  __endasm;
} //Laser2_SR4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_SR8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  DEC   C
                  JP    Z,__Laser2_SX8V ; IF len = 1 THEN Clear rect of len = 1
                  LD    A, L
                  ADD   C
                  LD    L, A

SR8V_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    B, #8
                  XOR   A
SR8V_LINE8$:      LD    (SR8V_SCRADR$+1), HL
                  LD    E, L
                  LD    D, H
                  DEC   L
                  PUSH  BC
                  LD    B, A
                  LDDR
                  LD    (DE), A
SR8V_SCRADR$:     LD    HL, #0
                  INC   H
                  POP   BC
                  DJNZ  SR8V_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, SR8V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
SR8V_CONT_1_3$:   POP   BC
                  DJNZ  SR8V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_SR8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_WL1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  LD    A, C
                  DEC   A
                  ADD   L
                  LD    L, A
WL1V_HLINE$:      PUSH  BC
                  LD    D, #8
                  LD    E, L
WL1V_ROLL_LINE8$: LD    B, C
                  LD    A, (HL)
WL1V_ROLL_LINE$:  RL    (HL)
                  DEC   L
                  DJNZ  WL1V_ROLL_LINE$
                  LD    L, E
                  RLA
                  LD    (HL), A
                  INC   H
                  DEC   D
                  JR    NZ, WL1V_ROLL_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, WL1V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
WL1V_CONT_1_3$:   POP   BC
                  DJNZ  WL1V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_WL1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_WL4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  LD    A, C
                  DEC   A
                  ADD   L
                  LD    L, A
WL4V_HLINE$:      PUSH  BC
                  LD    D, #8
                  LD    E, L
WL4V_ROLL_LINE8$: LD    B, C
                  LD    A, (HL)
                  EX    AF, AF
WL4V_ROLL_LINE$:  RLD
                  DEC   L
                  DJNZ  WL4V_ROLL_LINE$
                  LD    L, E
                  EX    AF, AF
                  LD    (HL), A
                  EX    AF, AF
                  RLD
                  INC   H
                  DEC   D
                  JR    NZ, WL4V_ROLL_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, WL4V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
WL4V_CONT_1_3$:   POP   BC
                  DJNZ  WL4V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_WL4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_WL8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  DEC   C
                  RET   Z               ; IF len = 1 THEN RETURN

WL8V_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    B, #8
WL8V_LINE8$:      LD    (WL8V_SCRADR$+1), HL
                  LD    E, L
                  LD    D, H
                  INC   L
                  PUSH  BC
                  LD    B, #0
                  LD    A, (DE)
                  LDIR
                  LD    (DE), A
WL8V_SCRADR$:     LD    HL, #0
                  INC   H
                  POP   BC
                  DJNZ  WL8V_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, WL8V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
WL8V_CONT_1_3$:   POP   BC
                  DJNZ  WL8V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_WL8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_WR1V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
WR1V_HLINE$:      PUSH  BC
                  LD    D, #8
                  LD    E, L
WR1V_ROLL_LINE8$: LD    B, C
                  LD    A, (HL)
WR1V_ROLL_LINE$:  RR    (HL)
                  INC   L
                  DJNZ  WR1V_ROLL_LINE$
                  LD    L, E
                  RRA
                  LD    (HL), A
                  INC   H
                  DEC   D
                  JR    NZ, WR1V_ROLL_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, WR1V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
WR1V_CONT_1_3$:   POP   BC
                  DJNZ  WR1V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_WR1V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_WR4V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
WR4V_HLINE$:      PUSH  BC
                  LD    D, #8
                  LD    E, L
WR4V_ROLL_LINE8$: LD    B, C
                  LD    A, (HL)
                  EX    AF, AF
WR4V_ROLL_LINE$:  RRD
                  INC   L
                  DJNZ  WR4V_ROLL_LINE$
                  LD    L, E
                  EX    AF, AF
                  LD    (HL), A
                  EX    AF, AF
                  RRD
                  INC   H
                  DEC   D
                  JR    NZ, WR4V_ROLL_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, WR4V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
WR4V_CONT_1_3$:   POP   BC
                  DJNZ  WR4V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_WR4V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_WR8V (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  DEC   C
                  RET   Z               ; IF len = 1 THEN RETURN
                  LD    A, L
                  ADD   C
                  LD    L, A

WR8V_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    B, #8
WR8V_LINE8$:      LD    (WR8V_SCRADR$+1), HL
                  LD    E, L
                  LD    D, H
                  DEC   L
                  PUSH  BC
                  LD    B, #0
                  LD    A, (DE)
                  LDDR
                  LD    (DE), A
WR8V_SCRADR$:     LD    HL, #0
                  INC   H
                  POP   BC
                  DJNZ  WR8V_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, WR8V_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
WR8V_CONT_1_3$:   POP   BC
                  DJNZ  WR8V_HLINE$     ; End of loop on charlines (the same third)
  __endasm;
} //Laser2_WR8V

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_MIRV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  __Laser2_XYtoScr
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  LD    A, C
                  LD    (MIRV_LEN$+1), A
                  INC   A
                  SRL   A
                  LD    (MIRV_LEN_DIV_2$+1), A
MIRV_RECT$:       PUSH  BC              ; Begin of loop on charlines
                  LD    A, #8
MIRV_LINE8$:      EX    AF, AF
                  LD    (MIRV_SCR_ADR$+1), HL
                  LD    A, L
MIRV_LEN$:        ADD   #0
                  LD    E, A
                  LD    D, H
MIRV_LEN_DIV_2$:  LD    B, #0

MIRV_COL_MIRROR$: DEC   E
                  LD    A, (DE)
                  LD    C, (HL)

                  ; ------------------
                  ; 2 bytes mirroring
                  ; ------------------
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  RR    C
                  RLA
                  ; ------------------
                  
                  LD    (DE), A
                  LD    (HL), C
                  INC   L
                  DJNZ  MIRV_COL_MIRROR$
MIRV_SCR_ADR$:    LD    HL, #0
                  INC   H
                  EX    AF, AF
                  DEC   A
                  JR    NZ, MIRV_LINE8$
                  LD    A, L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    C, MIRV_CONT_1_3$
                  LD    A, H
                  SUB   #8              ; HL := HL - 0x0800
                  LD    H, A
MIRV_CONT_1_3$:   POP   BC
                  DJNZ  MIRV_RECT$
  __endasm;
} //Laser2_MIRV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_MARV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee
{
  __asm
                  POP   DE
                  POP   HL              ; L = col; H = row
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE
                  LD    A, C
                  DEC   C
                  RET   Z               ; IF len = 1 THEN RETURN
                  SRL   A
                  LD    (MARV_LEN_DIV_2$+1), A
                  CALL  __Laser2_XYtoScrAtr

MARV_MIRR_RECT$:  PUSH  BC              ; Begin of loop on charlines
                  PUSH  HL
                  LD    A, L
                  ADD   C
                  LD    E, A
                  LD    D, H

MARV_LEN_DIV_2$:  LD    B, #0
MARV_MIRR_LINE$:  LD    A, (DE)
                  LD    C, (HL)
                  LD    (HL), A
                  LD    A, C
                  LD    (DE), A
                  INC   L
                  DEC   E
                  DJNZ  MARV_MIRR_LINE$
                  POP   HL
                  LD    A, L
                  ADD   #32
                  LD    L, A
                  LD    A, H
                  ADC   B
                  LD    H, A
                  POP   BC
                  DJNZ  MARV_MIRR_RECT$
  __endasm;
} //Laser2_MARV

