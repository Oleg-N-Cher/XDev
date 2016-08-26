#include "SYSTEM.h"

void GrPixel_PutPixel_ROM (unsigned char x, unsigned char y);
void GrPixel_PutPixel_TBL (unsigned char x, unsigned char y);

/*================================== Header ==================================*/

void GrPixel_Line (SHORTCARD x1, SHORTCARD y1, SHORTCARD x2, SHORTCARD y2)
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   HL,#4
  ADD  HL,SP
  LD   B,(HL)  ; 7t
  INC  HL      ; 6t
  LD   C,(HL)
  INC  HL
  LD   D,(HL)
  INC  HL
  LD   E,(HL)
#else
  LD   B,4(IX) ; 19t
  LD   C,5(IX)
  LD   D,6(IX)
  LD   E,7(IX)
#endif
;Draw subroutine
;На входе: BC - координаты нача-
;            ла линии (B=Y, C=X)
;          DE - координаты конца
;            линии (D=Y, E=X)
  LD   (#0x5C7D),DE
DRAW$:    EXX
          LD      BC,#0x1C14
          EXX
          LD      A,B
          CP      D
          JR      NC,NO_EXX$
          LD      B,D
          LD      D,A
          LD      A,C
          LD      C,E
          LD      E,A
NO_EXX$:  LD      A,C
          SUB     E
          JR      NC,X_POSIT$
          NEG
          EXX
          LD      B,#0x1D
          EXX
X_POSIT$: LD      L,A
; смещение по X
          LD      A,B
          SUB     D
; A - смещение по Y
          CP      L
          LD      H,L
          LD      B,L
          .DB   #0xDD  ; LD HX,B
          LD H,B
          .DB  #0xDD  ; LD LX,A
          LD L,A
          JR      C,DONE$
          EXX
          LD      C,B
          LD      B,#0x14
          EXX
          LD      H,A
          LD      B,A
          .DB   #0xDD  ; LD HX,A
          LD      H,A
          LD      A,L
          .DB   #0xDD  ; LD LX,A
          LD      L,A
DONE$:    INC     H
          .DB   #0xDD  ; INC     LX
          INC     L
          EXX
          LD      A,B
          LD      (COMM$),A
          LD      A,C
          LD      (COMM1$),A
          EXX
NEXT$:    PUSH    HL
          PUSH    DE
          PUSH    BC
PLOT$:
;===============================
;'PLOT' - любая процедура уста-
; новки точки; координаты в DE:
; D-Y, E-X. Рекомендую процедуру
; А.Астафьева.
  LD   IY,#0x5C3A
  LD   B,E
  LD   C,D
  LD   A,B
  CP   #0xC0
  JP   NC,#0x24F9 // REPORT_B_3
  CALL #0x22B1
  CALL #0x22EC
;===============================
          POP     BC
          POP     DE
          POP     HL
COMM$:    INC     E           ;*
          .DB   #0xDD  ; LD      A,HX
          LD      A,H
          .DB   #0xDD  ; SUB     LX
          SUB     L
          .DB   #0xDD  ; LD      HX,A
          LD      H,A
          JR      C,CARRY$
COUNT$:   DEC     H
          JR      NZ,NEXT$
          POP     IX
          RET
CARRY$:   ADD     A,B
          .DB   #0xDD  ; LD      HX,A
          LD      H,A
COMM1$:   INC     D           ;*
          JR      COUNT$
__endasm;
} //GrPixel_Line

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutPixel_ROM (unsigned char x, unsigned char y) __naked
{
__asm
          POP  HL
          POP  BC
          PUSH BC
          PUSH HL
          LD   IY, #0x5C3A
PLOT_ROM$:
          LD   (0x5C7D), BC
          LD   A, B
          CP   #0xC0
          JP   NC, 0x24F9 ; REPORT_B_3
          CALL 0x22B1
          JP   0x22EC
__endasm;
} //GrPixel_PutPixel_ROM

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel_PutPixel_TBL (unsigned char x, unsigned char y)
{
__asm
;--------------------------------------------------
; Вывод точки на экран DE(y,x)
;--------------------------------------------------
          POP  HL
          POP  DE
          PUSH DE
          PUSH HL
PLOTTBL$: LD   H, #GrPixel_PLOTTBL ; старший байт
          LD   L, D
          LD   B, (HL)
          INC  H
          LD   A, (HL)
          LD   L, E
          INC  H
          OR   (HL)
          INC  H
          LD   C, A
          LD   A, (BC)
          OR   (HL)
          LD   (BC),A
__endasm;
} //GrPixel_PutPixel_TBL

/*--------------------------------- Cut here ---------------------------------*/
void GrPixel__init (void)
{
__asm
FORMER$:  LD   DE, #0x4000
          LD   BC, #0x8000
          LD   L, E  ; формирование таблички
FLP1$:    LD   H, #GrPixel_PLOTTBL ; старший байт
          LD   (HL), D
          INC  H
          LD   (HL), E
          INC  H
          LD   (HL), C
          INC  H
          LD   (HL), B
          RRC  B
          LD   A, C
          ADC  A, #0
          LD   C, A
FBR1$:    INC  D
          LD   A, D
          AND  #7
          JR   NZ, FNXT$
          LD   A, E
          ADD  A, #32
          LD   E, A
          JR   C, FNXT$
          LD   A, D
          SUB  #8
          LD   D, A
FNXT$:    INC  L
          JR   NZ, FLP1$
          LD   HL, #GrPixel_PLOTTBL + 0xC0
          LD   BC, #0x3F
          LD   E, L
          LD   D, L
          INC  E
          LD   (HL), #0
          LDIR
          DI
__endasm;
} //GrPixel__init
