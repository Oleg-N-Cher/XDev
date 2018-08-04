/* -------------------- */
/* YS MegaBasic v4.0    */
/* (c) 1984 Mike Leaman */
/* MEGA BASIC for ZXDev */
/*   by Oleg N. Cher    */
/*    VEDAsoft, 2013    */
/* -------------------- */

void MegaBasic_INVERT (void);
void MegaBasic_PLAY (unsigned char soundType,
  unsigned char stepLen, unsigned char startFreq, unsigned int stepNum, unsigned char incFreq);

/*================================== Header ==================================*/

/* "INVERT" - инвертирование экрана: тон становится фоном, а фон - тоном. */
void MegaBasic_INVERT (void)
{
__asm
  LD   HL, #0x4000
  LD   BC, #0x1800
INV_LOOP$:
  LD   A, (HL)
  XOR  #0xFF
  LD   (HL), A
  DEC  BC
  INC  HL
  LD   A, B
  OR   C
  JR   NZ, INV_LOOP$
__endasm;
} //MegaBasic_INVERT

/*--------------------------------- Cut here ---------------------------------*/
/* PLAY_N,L,S,D,F[,D,F...]

где N - выбор звука (0 - чистый тон, 1 - белый шум), L - длина
каждого шага, S - начальная частота, D - количество шагов, F -
приращение частоты после каждого шага. Переменные D и F при
необходимости могут быть повторены нужное количество раз. */

void MegaBasic_PLAY (unsigned char soundType,
  unsigned char stepLen, unsigned char startFreq, unsigned int stepNum, unsigned char incFreq)
{
  // n = [#C2FA]; l = [#C2FB]; s = [#C2FC]
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   A,(HL)  ; (soundType)
  LD   (#Arg_SoundType$+1),A
  INC  HL
  LD   D,(HL)  ; (stepLen)
  INC  HL
  LD   E,(HL)  ; E := (startFreq)
  INC  HL
  LD   C,(HL)  ;
  INC  HL      ; BC := (stepNum)
  LD   B,(HL)  ;
  INC  HL
  LD   H,(HL)  ; H := (incFreq)
  LD   L,D     ; L := (stepLen)
#else
  LD   L,5(IX) ; L := (stepLen)
  LD   E,6(IX) ; E := (startFreq)
  LD   C,7(IX) ;
  LD   B,8(IX) ; BC := (stepNum)
  LD   H,9(IX) ; H := (incFreq)
#endif
  DI
MAIN_LOOP$:
    LD   A,B
    OR   C
    JR   Z,EXITPLAY$ ; IF (stepNum) # 0 THEN
    LD   A,E
    ADD  A,H   ; INC(startFreq, incFreq)
    LD   E,A
#   ifdef __SDCC
Arg_SoundType$:
      LD   A,#0  ; (soundType)
#   else
      LD   A,4(IX) ; (soundType)
#   endif
    AND  A
    JR   Z,PURE_TONE$
    PUSH BC
    LD   B,L   ; (stepLen)
INT_LOOP1$:
      PUSH HL
L_5C79$:
      LD   HL,#0 ; (#5C79)
      PUSH DE
      EX   DE,HL
      LD   H,E
      LD   L,#0xA
      OR   A
      SBC  HL,DE
      ADD  HL,HL
      ADD  HL,HL
      ADD  HL,DE
      INC  HL
      POP  DE
      LD   A,H
      LD   (#L_5C79$+1),HL
      POP  HL
      CALL DO_SOUND$
      PUSH BC
      LD   B,E ; FOR B := E TO 1 BY -1 DO END
DELAY_1$:
      DJNZ DELAY_1$
      POP  BC
    DJNZ INT_LOOP1$
END_MAIN_LOOP$:
    POP  BC
    DEC  BC
    JR   MAIN_LOOP$
; -----------------
PURE_TONE$:
    PUSH BC
    LD   A,L   ; (stepLen)
INT_LOOP2$:
    LD   A,#0xFF
    CALL DO_SOUND$
    PUSH BC
    LD   B,E
DELAY_2$:
    DJNZ DELAY_2$
    XOR  A
    CALL DO_SOUND$
    LD   B,E
DELAY_3$:
    DJNZ DELAY_3$
    POP  BC
    DJNZ INT_LOOP2$
    JR   END_MAIN_LOOP$
DO_SOUND$:
  AND  #0xF8
  LD   (#C2FC$+1),A
  LD   A,(#0x5C48)
  SRL  A
  SRL  A
  SRL  A
  AND  #7
  PUSH BC
C2FC$:
  LD   BC,#0
  OR   C
  POP  BC
  OUT  (#0xFE),A
  RET
EXITPLAY$:
  EI
__endasm;
} //BasicMega_PLAY
