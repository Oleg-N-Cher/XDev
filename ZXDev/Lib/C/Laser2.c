/*********************/
/*   LASER BASIC 2   */
/*  by Oleg N. Cher  */
/*   zx.oberon2.ru   */
/*********************/

extern unsigned int Laser2_SPRT_ADR;  // Sprite file start address

// Functions for screen windows processing

void Laser2_PTBL (signed char col, signed char row, unsigned char spn);
void Laser2_PTOR (signed char col, signed char row, unsigned char spn);
void Laser2_PTND (signed char col, signed char row, unsigned char spn);
void Laser2_PTXR (signed char col, signed char row, unsigned char spn);

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
void Laser2_PTBL (signed char col, signed char row, unsigned char spn) __naked {
__asm
             POP   BC
             POP   HL        ; col, row
             POP   DE        ; spn
             PUSH  DE
             PUSH  HL
             PUSH  BC
             XOR   A         ; NOP
             JP    Laser2_PUT_SPRITE
__endasm;
} //Laser2_PTBL

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTOR (signed char col, signed char row, unsigned char spn) __naked {
__asm
             POP   BC
             POP   HL        ; col, row
             POP   DE        ; spn
             PUSH  DE
             PUSH  HL
             PUSH  BC
             LD    A, #0xB6  ; OR (HL)
             JP    Laser2_PUT_SPRITE
__endasm;
} //Laser2_PTOR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTXR (signed char col, signed char row, unsigned char spn) __naked {
__asm
             POP   BC
             POP   HL        ; col, row
             POP   DE        ; spn
             PUSH  DE
             PUSH  HL
             PUSH  BC
             LD    A, #0xAE  ; XOR (HL)
             JP    Laser2_PUT_SPRITE
__endasm;
} //Laser2_PTXR

/*--------------------------------- Cut here ---------------------------------*/
void Laser2_PTND (signed char col, signed char row, unsigned char spn) __naked {
__asm
             POP   BC
             POP   HL        ; col, row
             POP   DE        ; spn
             PUSH  DE
             PUSH  HL
             PUSH  BC
             LD    A, #0xA6  ; AND (HL)
             JP    Laser2_PUT_SPRITE
__endasm;
} //Laser2_PTND

/*--------------------------------- Cut here ---------------------------------*/

/* Спрайты хранятся в памяти в следующем формате:
Байт 1 - номер спрайта.
Байт 2 - младший байт размера спрайта (9*HGT*LEN+3).
Байт 3 - старший байт размера спрайта
Байт 4 - длина спрайта.
Байт 5 - высота спрайта.
8*HGT*LEN - данные о состоянии
пикселей.
HGT*LEN - атрибуты.
  ИТОГО: 9*HGT*LEN+5 байтов.
*/

void Laser2_PUT_SPRITE (void) __naked {
//  A: mode; L: col; H: row; D: spn
__asm
             LD    (SPRT_MODE$), A ; Set draw mode
             LD    (SPRT_XY$+1), HL
             LD    HL, (_Laser2_SPRT_ADR)
FIND_BY_N$:  LD    A, (HL)         ; N of a sprite
             OR    A
             RET   Z
             INC   HL
             CP    D               ; spn
             JR    Z, SPRT_FOUND$
             LD    C, (HL)
             INC   HL
             LD    B, (HL)
             ADD   HL, BC
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
             LD    (SAVE_REST$+1)  ; rest := len - |len|
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

/* http://zxpress.ru/book_articles.php?id=639

  (С) Жерихов Руслан
                г. Новочебоксарск, 1996

   Операции со спрайтами.

1. Эта программа выводит на экран спрайт произвольной конфигурации, например
вот такой:

    Ъ----ї  Ъ-ї
    А--ї А--Щ і
       А------Щ

   Формат спрайта: заголовок - 1 байт - количество знакомест в спрайте;
данные спрайта - 1 байт Y координата, 2 байт X координата (координаты
относительные от левого верхнего угла спрайта). Далее 8 байт шаблон
знакоместа.
   Входные параметры: HL - адрес начала спрайта; DE - абсолютные X,Y
координаты левого верхнего угла спрайта; A - метод вывода спрайта ( с
уничтожением фона SP_PUT и с различными наложениями SP_OR, SP_XOR, SP_AND).
Если часть спрайта или весь спрайт выходит за пределы экрана, то он просто
не печатается.

SP_PUT    EQU  #00
SP_OR     EQU  #B6
SP_XOR    EQU  #AE
SP_AND    EQU  #A6
PTBL      LD   (SPRT_MODE),A
          LD   A,(HL)
          INC  HL
PTBL_1    PUSH AF
          PUSH DE
          LD   A,(HL)
          ADD  A,E
          CP   #18
          JR   NC,PTBL_4
          LD   E,A
          INC  HL
          LD   A,(HL)
          ADD  A,D
          CP   32
          JR   NC,PTBL_5
          LD   D,A
          INC  HL
          PUSH HL
          LD   A,E
          AND  #18
          ADD  A,#40
          LD   H,A
          LD   A,E
          AND  7
          RRCA
          RRCA
          RRCA
          ADD  A,D
          LD   L,A
          POP  DE
          LD   B,8
PTLB_2    LD   A,(DE)
MODE      NOP
          LD   (HL),A
          INC  H
          INC  DE
          DJNZ PTBL_2
          EX   DE,HL
PTBL_3    POP  DE
          POP  AF
          DEC  A
          JR   NZ,PTBL_1
          RET
PTBL_4    INC  HL
PTBL_5    LD   DE,9
          ADD  HL,DE
          JR   PTBL_3

   Скажу сразу - идею я подсмотрел в книге фирмы "Питер" <Как написать игру на
ассемблере>. */

__endasm;
} //Laser2_PUT_SPRITE
