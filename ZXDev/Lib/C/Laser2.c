/***********************/
/*    LASER BASIC 2    */
/*   by Oleg N. Cher   */
/* zx.oberon2.ru/forum */
/***********************/

extern unsigned int Laser2_SPRT_ADR;  // Sprite file start address

// Procedures for sprite manipulations:

void Laser2_ATOF_INSCR (void);
void Laser2_ATON_INSCR (void);
void Laser2_INVM (unsigned char spn) __z88dk_callee;
void Laser2_SCRN_INSCR (unsigned int adr) __z88dk_callee;
void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTOR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTND_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;
void Laser2_PTXR_INSCR (signed char col, signed char row, unsigned char spn) __z88dk_callee;

void Laser2_PTBL_OUTSCR (signed char col, signed char row, unsigned char spn);
void Laser2_PTOR_OUTSCR (signed char col, signed char row, unsigned char spn);
void Laser2_PTND_OUTSCR (signed char col, signed char row, unsigned char spn);
void Laser2_PTXR_OUTSCR (signed char col, signed char row, unsigned char spn);

// Procedures for screen windows processing:

void Laser2_CLSV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;
void Laser2_INVV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __z88dk_callee;


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
void Laser2_PTBL_INSCR (signed char col, signed char row, unsigned char spn) __naked __z88dk_callee
{
  __asm
                  POP   HL
                  POP   BC           ; C = col; B = row
                  DEC   SP
                  POP   DE           ; D = spn
                  PUSH  HL
                  LD    HL, #0x007E  ; "LD A,(HL)" "NOP"
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTBL_INSCR

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
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTOR_INSCR

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
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTXR_INSCR

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
                  JP    _Laser2_PUT_SPRITE_INSCR
  __endasm;
} //Laser2_PTND_INSCR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_XYtoADR (void) {
// Процедура расчёта адреса экрана из координат
//  Вход: C = x; B = y
// Выход: HL = адрес видеопамяти
  __asm
  
.globl Laser2_SCR_IN

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
  __endasm;
} //Laser2_XYtoADR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_FindSprite (void)
// Input:  D = spn
// Output: Z = not found | NZ = found
//         HL = adr
{
  __asm
                  LD    HL, (_Laser2_SPRT_ADR)
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
} //Laser2_FindSprite
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
             CALL  _Laser2_FindSprite
             RET   Z
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
.globl Laser2_SCRATR_IN
                  LD    (SPRT_MODE_IN$), HL ; Set draw mode

                  CALL  _Laser2_XYtoADR
                  LD    (SCR_ADR_IN$+1), HL

                  CALL  _Laser2_FindSprite
                  RET   Z
                  LD    C, (HL)         ; length of sprite
                  INC   HL
                  LD    B, (HL)         ; height of sprite
                  LD    (SPRT_HGT_LEN_IN$+1), BC
                  INC   HL
SCR_ADR_IN$:      LD    DE, #0          ; adr at screen (up left corner)
SPRT_HLINE_IN$:   LD    A, E            ; Begin of loop on charlines
                  LD    (SCR_LOBYTE_IN$+1), A
                  PUSH  BC
                  LD    B, #8           ; Draw 8 bytes (one charline)
SPRT_CHAR_IN$:
SPRT_MODE_IN$:    LD    A, (HL)         ; "LD A, (HL)" | "LD A, (DE)"
                  NOP                   ; "NOP"        | "AND (HL)" | "OR (HL)" | "XOR (HL)"
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

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_INVM (unsigned char spn) __naked __z88dk_callee {
__asm
                  POP   HL
                  DEC   SP
                  POP   DE        ; D = spn
                  PUSH  HL

                  CALL  _Laser2_FindSprite
                  RET   Z
                  LD    A, (HL)         ; length of sprite
                  ADD   A
                  ADD   A               ; This code works only for length <= 32
                  ADD   A
                  LD    E, A            ; 32*8 MOD 256 = 0
                  INC   HL
                  LD    D, (HL)         ; height of sprite
                  INC   HL
                  
NEXT_LINE_IN$:    LD    B, E
NEXT_BYTE_IN$:    LD    A, (HL)
                  CPL
                  LD    (HL), A
                  INC   HL
                  DJNZ  NEXT_BYTE_IN$
                  DEC   D
                  JR    NZ, NEXT_LINE_IN$
                  RET
__endasm;
} //Laser2_INVM

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_CLSV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __naked __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  _Laser2_XYtoADR
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE

CLSV_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    E, L
                  LD    D, H
                  XOR   A
CLSV_PUT_ZERO0$:  LD    B, #8
CLSV_PUT_ZERO$:   LD    (HL), A
                  INC   H
                  DJNZ  CLSV_PUT_ZERO$
                  LD    H, D            ; Restore H
                  INC   L               ; Next screen line
                  DEC   C
                  JR    NZ, CLSV_PUT_ZERO0$
                  LD    A, E            ; Restore L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    NC, CONTIN_1_3_CLSV$
                  LD    A, H            ; Next third of screen
                  ADD   #8
                  LD    H, A            ; DE := DE + 0x0800
CONTIN_1_3_CLSV$: POP   BC
                  DJNZ  CLSV_HLINE$     ; End of loop on charlines (the same third)
                  RET
  __endasm;
} //Laser2_CLSV

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_INVV (unsigned char col, unsigned char row, unsigned char len, unsigned char hgt) __naked __z88dk_callee
{
  __asm
                  POP   DE
                  POP   BC              ; C = col; B = row
                  CALL  _Laser2_XYtoADR
                  POP   BC              ; C = len; B = hgt
                  PUSH  DE

INVV_HLINE$:      PUSH  BC              ; Begin of loop on charlines
                  LD    E, L
                  LD    D, H
INVV_INV_BYTE0$:  LD    B, #8
INVV_INV_BYTE$:   LD    A, (HL)
                  CPL
                  LD    (HL), A
                  INC   H
                  DJNZ  INVV_INV_BYTE$
                  LD    H, D            ; Restore H
                  INC   L               ; Next screen line
                  DEC   C
                  JR    NZ, INVV_INV_BYTE0$
                  LD    A, E            ; Restore L
                  ADD   #0x20           ; Next charline
                  LD    L, A            ; If carry then jump to next third of screen
                  JR    NC, CONTIN_1_3_INVV$
                  LD    A, H            ; Next third of screen
                  ADD   #8
                  LD    H, A            ; DE := DE + 0x0800
CONTIN_1_3_INVV$: POP   BC
                  DJNZ  INVV_HLINE$     ; End of loop on charlines (the same third)
                  RET
  __endasm;
} //Laser2_INVV

/*--------------------------------- Cut here ---------------------------------*/
/*
SETV   LD    DE,#5800    ;адрес начала области атрибутов экрана
       LD    BC,(LEN)    ;C = LEN, B = HGT
       LD    A,(ROW)
       LD    L,A         ;расчет адреса левого верхнего угла окна
       LD    H,0         ; в области атрибутов экрана
       ADD   HL,HL       ;умножаем на 32 (2 в 5-ой степени)
       ADD   HL,HL
       ADD   HL,HL
       ADD   HL,HL
       ADD   HL,HL
       ADD   HL,DE       ;полученное смещение складываем
                         ; с началом области атрибутов
       LD    A,(COL)     ;добавляем горизонтальное смещение окна
       ADD   A,L
       LD    L,A
       LD    A,(ATTR)    ;в аккумуляторе байт атрибутов
SETV1  PUSH  BC
       PUSH  HL
SETV2  LD    (HL),A      ;помещаем в видеобуфер
       INC   HL
       DEC   C           ;до правого края окна
       JR    NZ,SETV2
       POP   HL
       POP   BC
       LD    DE,32       ;переходим к следующей строке
       ADD   HL,DE       ; (длина строки 32 знакоместа)
       DJNZ  SETV1       ;повторяем, пока не дойдем до нижнего
                         ; края окна
       RET
*/
/*--------------------------------- Cut here ---------------------------------*/
/*
MIRV   LD    BC,(LEN)
       LD    A,(ROW)
MIRV1  PUSH  AF
       PUSH  BC
       CALL  3742        ;в HL - адрес экрана
       LD    A,(COL)
       OR    L
       LD    L,A         ;начальный адрес левого края окна
; В DE получаем соответствующий адрес противоположного края окна
       LD    D,H
       LD    A,C
       ADD   A,L
       DEC   A
       LD    E,A
       LD    B,8         ;8 рядов пикселей
MIRV2  PUSH  DE
       PUSH  HL
       PUSH  BC
       SRL   C           ;делим ширину окна на 2
       JR    NC,MIRV3    ;продолжаем, если разделилось без остатка
       INC   C           ;иначе увеличиваем счетчик на 1
MIRV3  LD    A,(HL)      ;получаем байт с левой стороны
       CALL  MIRV0       ;зеркально отображаем его
       PUSH  BC          ;запоминаем его
       LD    A,(DE)      ;берем байт с правой стороны
       CALL  MIRV0       ;отображаем
       POP   AF          ;восстанавливаем предыдущий байт
                         ; в аккумуляторе
       LD    (HL),B      ;записываем «правый» байт
                         ; на левую сторону окна
       LD    (DE),A      ; и наоборот
       INC   HL          ;приближаемся с двух сторон
       DEC   DE          ; к середине окна
       DEC   C
       JR    NZ,MIRV3    ;повторяем, если еще не дошли до середины
       POP   BC
       POP   HL
       POP   DE
       INC   H           ;переходим к следующему ряду пикселей
       INC   D
       DJNZ  MIRV2
       POP   BC
       POP   AF
       INC   A           ;переходим к следующей строке экрана
       DJNZ  MIRV1
       RET
; Подпрограмма зеркального отображения байта в аккумуляторе
MIRV0  RLA
       RR    B           ;отображенный байт получится в B
       RLA
       RR    B
       RLA
       RR    B
       RLA
       RR    B
       RLA
       RR    B
       RLA
       RR    B
       RLA
       RR    B
       RLA
       RR    B
       RET
*/
/*--------------------------------- Cut here ---------------------------------*/
/*
MARV   LD    BC,(LEN)
       LD    A,(ROW)
       LD    L,A
       LD    H,0
       ADD   HL,HL
       ADD   HL,HL
       ADD   HL,HL
       ADD   HL,HL
       ADD   HL,HL
       LD    DE,#5800
       ADD   HL,DE
       LD    A,(COL)
       ADD   A,L
       LD    L,A
       LD    D,H
       LD    A,C
       ADD   A,L
       DEC   A
       LD    E,A
MARV1  PUSH  BC
       PUSH  DE
       PUSH  HL
       SRL   C
       JR    NC,MARV2
       INC   C
MARV2  LD    A,(HL)
       EX    AF,AF'
       LD    A,(DE)
       LD    (HL),A
       EX    AF,AF'
       LD    (DE),A
       INC   HL
       DEC   DE
       DEC   C
       JR    NZ,MARV2
       POP   DE
       POP   HL
       LD    BC,32
       ADD   HL,BC
       EX    DE,HL
       ADD   HL,BC
       POP   BC
       DJNZ  MARV1
       RET
*/
/*--------------------------------- Cut here ---------------------------------*/
/*
Для определенности будем скроллировать 21-ю строку экрана:
       ORG   60000
       LD    A,21        ;21-я строка экрана
SCRLIN CALL  3742        ;получаем ее адрес в HL
; Так как строка должна бежать слева направо, то раньше нужно сдвигать
;  последние байты, поэтому определяем адрес конца строки
       LD    A,L
       OR    31
       LD    L,A
       LD    C,8         ;высота строки 8 пикселей
SCRL1  LD    B,32        ;длина строки 32 байта
       AND   A           ;очистка флага CY
       PUSH  HL          ;сохраняем адрес
SCRL2  RL    (HL)        ;последовательно сдвигаем все байты
       DEC   HL
       DJNZ  SCRL2
       POP   HL          ;восстанавливаем адрес
       INC   H           ;переходим к следующему ряду пикселей
       DEC   C           ;повторяем
       JR    NZ,SCRL1
       RET
*/
