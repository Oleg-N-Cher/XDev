void GrTiles_DrawMonoTile8x8 (
  unsigned char x, unsigned char y, unsigned char *tile, unsigned char colors) __z88dk_callee;
void GrTiles_DrawTile8x8 (unsigned char x, unsigned char y, unsigned char *tile) __z88dk_callee;
void GrTiles_GetMonoTile8x8 (unsigned char x, unsigned char y, unsigned char *tile) __z88dk_callee;
void GrTiles_GetTile8x8 (unsigned char x, unsigned char y, unsigned char *tile) __z88dk_callee;
void GrTiles_DrawTile16x16 (unsigned char x, unsigned char y, unsigned char *tile) __z88dk_callee;
void GrTiles_DrawNoAtrTile16x16 (unsigned char x, unsigned char y, unsigned char *tile) __z88dk_callee;
/*================================== Header ==================================*/

void GrTiles_DrawMonoTile8x8 (
    unsigned char x, unsigned char y, unsigned char *tile, unsigned char colors) __naked __z88dk_callee {
__asm
  POP  BC
  POP  DE      ; D = y; E = x
  CALL _GrScr_XYtoScr
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
  CALL _GrScr_ScrToAtr
  LD   A,C     ; tile attrib
  LD   (DE),A
  RET
__endasm;
} //GrTiles_DrawMonoTile8x8

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_DrawTile8x8 (unsigned char x, unsigned char y, unsigned char *tile) __naked __z88dk_callee {
  __asm
              POP  HL
              POP  DE         ; D = y; E = x
              EX   (SP), HL   ; tile address
              CALL _GrScr_XYtoScr
              LD   B, #7
DrTile8x8$:   LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              INC  HL         ; tile++
              INC  D          ; Down(screen)
              DJNZ DrTile8x8$
              LD   A, (HL)    ; И так 8 раз
              LD   (DE), A
              CALL _GrScr_ScrToAtr
              INC  HL
              LD   A, (HL)
              LD   (DE), A
              RET
  __endasm;
} //GrTiles_DrawTile8x8

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_GetMonoTile8x8 (unsigned char x, unsigned char y, unsigned char *tile) __naked __z88dk_callee {
__asm
  POP  HL
  POP  DE      ; D = y; E = x
  EX   (SP),HL ; tile address
  CALL _GrScr_XYtoScr
  LD   B,#7
GTLOOPM$:
  LD   A,(DE)  ; Берём байт из фонта
  LD   (HL),A  ;   и кладем в экран
  INC  HL      ; Приращение fnt adr
  INC  D       ; Приращение scr adr
  DJNZ GTLOOPM$
  LD   A,(DE)  ; И так 8 раз
  LD   (HL),A
  RET
__endasm;
} //GrTiles_GetMonoTile8x8

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_GetTile8x8 (unsigned char x, unsigned char y, unsigned char *tile) __naked __z88dk_callee {
__asm
  POP  AF
  EX   AF, AF
  CALL _GrTiles_GetMonoTile8x8
  CALL _GrScr_ScrToAtr
  INC  HL
  LD   A,(DE)
  LD   (HL),A
  EX   AF, AF
  PUSH AF
  RET
__endasm;
} //GrTiles_GetTile8x8

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_DrawTile16x16 (unsigned char x, unsigned char y, unsigned char *tile) __naked __z88dk_callee {
  __asm
              POP  HL
              POP  DE         ; D = y; E = x
              EX   (SP), HL   ; tile address
              CALL _GrScr_XYtoScr
              PUSH DE         ; screen =>
              CALL DrTil16_Row$
              INC  D          ; Down(screen)
              LD   A, E
              ADD  #0x20-1    ; Next charline
              LD   E, A       ; If carry then jump to next third of screen
              JR   C, DrTile16_13$
              LD   A, D
              SUB  #8         ; HL := HL - 0x0800
              LD   D, A
DrTile16_13$: CALL DrTil16_Row$
              POP  DE         ; <= screen
              CALL _GrScr_ScrToAtr
              LD   A, (HL)    ; O.
              LD   (DE), A    ; ..
              INC  E
              INC  HL
              LD   A, (HL)    ; .O
              LD   (DE), A    ; ..
              LD   A, E
              ADD  #0x20-1
              LD   E, A
              LD   A, D
              ADC  #0
              LD   D, A
              INC  HL
              LD   A, (HL)    ; ..
              LD   (DE), A    ; O.
              INC  E
              INC  HL
              LD   A, (HL)    ; ..
              LD   (DE), A    ; .O
              RET
DrTil16_Row$: LD   B, #7
DrTile16_Lo$: LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              INC  E
              INC  HL         ; tile++
              LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              DEC  E
              INC  D          ; Down(screen)
              INC  HL         ; tile++
              DJNZ DrTile16_Lo$
              LD   A, (HL)
              LD   (DE), A
              INC  E
              INC  HL         ; tile++
              LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              INC  HL         ; tile++
              RET
  __endasm;
} //GrTiles_DrawTile16x16

/*--------------------------------- Cut here ---------------------------------*/
void GrTiles_DrawNoAtrTile16x16 (unsigned char x, unsigned char y, unsigned char *tile) __naked __z88dk_callee {
  __asm
              POP  HL
              POP  DE         ; D = y; E = x
              EX   (SP), HL   ; tile address
              CALL _GrScr_XYtoScr
              CALL DrTil16_rNA$
              INC  D          ; Down(screen)
              LD   A, E
              ADD  #0x20-1    ; Next charline
              LD   E, A       ; If carry then jump to next third of screen
              JR   C, DrTil16_rNA$
              LD   A, D
              SUB  #8         ; HL := HL - 0x0800
              LD   D, A
DrTil16_rNA$: LD   B, #7
DrTile16_NA$: LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              INC  E
              INC  HL         ; tile++
              LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              DEC  E
              INC  D          ; Down(screen)
              INC  HL         ; tile++
              DJNZ DrTile16_NA$
              LD   A, (HL)
              LD   (DE), A
              INC  E
              INC  HL         ; tile++
              LD   A, (HL)    ; [tile]
              LD   (DE), A    ;   => [screen]
              INC  HL         ; tile++
              RET
  __endasm;
} //GrTiles_DrawNoAtrTile16x16