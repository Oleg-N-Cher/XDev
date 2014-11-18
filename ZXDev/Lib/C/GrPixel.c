#include "SYSTEM.h"
#include "GrPixel.h"

/*interface*/

/*implementation*/

/*================================== Header ==================================*/
export void GrPixel_Line (SHORTCARD x1, SHORTCARD y1, SHORTCARD x2, SHORTCARD y2)
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

