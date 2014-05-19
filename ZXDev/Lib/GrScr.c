/*
;----------------------------------------------------------------;
;           Adapted to ZXDev/SDCC by Oleg N. Cher, 2012          ;
;----------------------------------------------------------------;
*/
#include "SYSTEM.h"
#include "GrScr.h"

/*interface*/

//export void GrScr_Clear (void);

/*implementation*/

export void GrPixel_Line (SHORTCARD x1, SHORTCARD y1, SHORTCARD x2, SHORTCARD y2);
{
__asm
#ifdef __SDCC
  PUSH IX
  LD   HL,#2
  ADD  HL,SP
  LD   C,(HL)
  INC  HL
  LD   B,(HL)
  INC  HL
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
#else
  LD   C,4(IX)
  LD   B,5(IX)
  LD   E,6(IX)
  LD   D,7(IX)
#endif
;Draw subroutine
;На входе: BC - координаты нача-
;            ла линии (B=Y, C=X)
;          DE - координаты конца
;            линии (D=Y, E=X)

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
          LD      HX,B
          LD      LX,A
          JR      C,DONE$
          EXX
          LD      C,B
          LD      B,#0x14
          EXX
          LD      H,A
          LD      B,A
          LD      HX,A
          LD      A,L
          LD      LX,A
DONE$:    INC     H
          INC     LX
          EXX
          LD      A,B
          LD      (COMM$),A
          LD      A,C
          LD      (COMM1$),A
          EXX
NEXT      PUSH    HL
          PUSH    DE
          PUSH    BC
          CALL    PLOT$
;'PLOT' - любая процедура уста-
; новки точки; координаты в DE:
; D-Y, E-X. Рекомендую процедуру
; А.Астафьева.
          POP     BC
          POP     DE
          POP     HL
COMM$:    INC     E           ;*
          LD      A,HX
          SUB     LX
          LD      HX,A
          JR      C,CARRY$
COUNT$:   DEC     H
          JR      NZ,NEXT$
          POP     IX
          RET
CARRY$:   ADD     A,B
          LD      HX,A
COMM1$:   INC     D           ;*
          JR      COUNT2$



/*
;--------------------------------------------------------------;
*/
void GrScr_Clear (void)
{
__asm
        XOR   A          // -------------------------------------
        LD    HL,#0x5B00 // (c) ALK/XTM
CLEAR$: DEC   HL         // Born Dead #0B
        LD    (HL),A     // http://zxpress.ru/article.php?id=1306
        OR    (HL)       //
        JR    Z,CLEAR$   // -------------------------------------
__endasm;
}//Clear

/*
------------------------------------------

   Напоследок, моя процедурка рассчета ад-
реса  в аттрибутах по координатам в знако-
местах. Быстрее  без использования  таблиц
не бывает.

На входе:
   d-y
   e-x
На выходе:
   hl-адрес в аттрибутах

        ld a,d
        rrca
        rrca
        rrca
        ld h,a
        and #e0
        or e
        ld l,a
        xor e
        xor h
        or #58
        ld h,a

t=54 такта.
*/

/*
           *   *   *
*/
