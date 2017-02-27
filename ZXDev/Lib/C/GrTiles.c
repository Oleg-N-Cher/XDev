void GrTiles_DrawTile8x8 (unsigned char x, unsigned char y, unsigned int tile) __z88dk_callee;
void GrTiles_DrawMonoTile8x8 (
  unsigned char x, unsigned char y, unsigned int tile, unsigned char colors) __z88dk_callee;
/*================================== Header ==================================*/

void GrTiles_DrawTile8x8 (unsigned char x, unsigned char y, unsigned int tile) __z88dk_callee {
__asm
  POP  HL
  POP  DE      ; D = y; E = x
  EX   (SP),HL ; tile address
  LD   A,D     ; Здесь вычисляется адрес
  RRCA         ;  строки, номер которой задан
  RRCA         ;  в регистре A
  RRCA         ; 3 команды RRCA
  AND  #0xE0 
  ADD  A,E     ; Добавляем смещение по x
  LD   E,A 
  LD   A,D 
  AND  #0x18 
  OR   #0x40 
  LD   D,A     ; Счётчик цикла рисования
  LD   B,#7
DRLOOP$:
  LD   A,(HL)  ; Берём байт из фонта
  LD   (DE),A  ;   и кладем в экран
  INC  HL      ; Приращение fnt adr
  INC  D       ; Приращение scr adr
  DJNZ DRLOOP$
  LD   A,(HL)  ; И так 8 раз
  LD   (DE),A
; =========scr adr -> attr adr========
; in: DE - screen adress
; out:DE - attr adress
  LD   A,D     ; 4
  RRCA         ; 4
  RRCA         ; 4
  RRCA         ; 4
  AND  #3      ; 7
  OR   #0x58   ; 7
  LD   D,A     ; 4 = 34t
  INC  HL
  LD   A,(HL)
  LD   (DE),A
__endasm;
} //GrTiles_DrawTile8x8

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_DrawMonoTile8x8 (
    unsigned char x, unsigned char y, unsigned int tile, unsigned char colors) __z88dk_callee {
__asm
  POP  BC
  POP  DE      ; D = y; E = x
; ====================================
  LD   A,D     ; Здесь вычисляется адрес
  RRCA         ;  строки, номер которой задан
  RRCA         ;  в регистре A
  RRCA         ; 3 команды RRCA
  AND  #0xE0
  ADD  A,E     ; Добавляем смещение по x
  LD   E,A
  LD   A,D
  AND  #0x18
  OR   #0x40
  LD   D,A     ; Счётчик цикла рисования
; ====================================
  POP  HL      ; HL = tile address
  DEC  SP
  POP  AF      ; A = colors
  PUSH BC
  LD   C,A     ; C = colors
; ====================================
  LD   B,#7
DRLOOPM$:
  LD   A,(HL)  ; Берём байт из фонта
  LD   (DE),A  ;  и кладем в экран
  INC  HL      ; Приращение fnt adr
  INC  D       ; Приращение scr adr
  DJNZ DRLOOPM$
  LD   A,(HL)  ; И так 8 раз
  LD   (DE),A
; =========scr adr -> attr adr========
; in: DE - screen adress
; out:DE - attr adress
  LD   A,D     ; 4
  RRCA         ; 4
  RRCA         ; 4
  RRCA         ; 4
  AND  #3      ; 7
  OR   #0x58   ; 7
  LD   D,A     ; 4 = 34t
  LD   A,C     ; tile attrib
  LD   (DE),A
__endasm;
} //GrTiles_DrawMonoTile8x8

