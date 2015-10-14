#include "SYSTEM.h"

export SET Control_Get (void);
/*============================================================================*/

SET Control_Get (void) __naked {
__asm
/* Из журнала Deja Vu #09, Кемерово, 1999
 (C) Rezonance group
 Добавлен опрос Kempston-джойстика */

;Кроме стандартных Q, A, O, P, Space, здесь
;опрашиваются Sinclair 1/2 и Kempston. На выходе
;в регистре 'L' в формате кемпстон джойстика
;мы имеем требуемое направление движения.

KEY1A$: LD    HL,#KEY1F$
        LD    C,#0
        LD    A,(HL)
KEY1B$: INC   HL
        IN    A,(#0xFE)
        AND   (HL)
        INC   HL
        JR    NZ,KEY1C$
        LD    A,(HL)
        OR    C
        LD    C,A
KEY1C$: INC   HL
        LD    A,(HL)
        AND   A
        JR    NZ,KEY1B$
        LD    L,C
.globl __KEMPSTON
__KEMPSTON:
        .DB   0xC9  ; RET or IN
        .DB   0x1F
        OR    L
        LD    L,A
        RET
KEY1F$: .DB   0xDF,0x01,0x01 ;P
        .DB   0xEF,0x08,0x01 ;7
        .DB   0xF7,0x02,0x01 ;2
        .DB   0xDF,0x02,0x02 ;O
        .DB   0xEF,0x10,0x02 ;6
        .DB   0xF7,0x01,0x02 ;1
        .DB   0xFD,0x01,0x04 ;A
        .DB   0xEF,0x04,0x04 ;8
        .DB   0xF7,0x04,0x04 ;3
        .DB   0xFB,0x01,0x08 ;Q
        .DB   0xEF,0x02,0x08 ;9
        .DB   0xF7,0x08,0x08 ;4
        .DB   0x7F,0x01,0x10 ;Sp
        .DB   0xEF,0x01,0x10 ;0
        .DB   0xF7,0x10,0x10 ;5
        .DB   0
__endasm;
} //Control_Get()

/*
   Какая  передовая программа сможет обой-
тись  без  кемпстон  мыши. Процедура после
вызова  изменяет  координаты в зависимости
от передвижения мышки.

MOUSE10
      LD     HL,(XYkoor)
      LD     BC,#FBDF
      IN     A,(C)
MOUSE11
      LD     D,0
      LD     (MOUSE11+1),A
      SUB    D
      CALL   NZ,MOUSE30
      LD     B,#FF
      IN     A,(C)
MOUSE12
      LD     D,0
      LD     (MOUSE12+1),A
      SUB    D
      CALL   NZ,MOUSE40
      LD     (XYkoor),HL
      RET
MOUSE30
      JP     M,MOUSE35
      ADD    A,H
      LD     H,A
      RET    NC
      LD     H,#FF
      RET
MOUSE35
      XOR    #FF
      INC    A
      LD     D,A
      LD     A,H
      SUB    D
      LD     H,A
      RET    NC
      LD     H,0
      RET
MOUSE40
      JP     M,MOUSE45
      LD     E,A
      LD     A,L
      SUB    E
      LD     L,A
      RET    NC
      LD     L,#0
      RET
MOUSE45
      XOR    #FF
      INC    A
      ADD    A,L
      LD     L,A
      RET    NC
      LD     L,#FF
      RET

   Теперь  осталось  определить, есть ли у
пользователя  мышь.

AUTOconfig
      LD     L,0
      LD     B,250
A_config03
      LD     A,#FA
      IN     A,(#DF)
      XOR    #FF
      JR     NZ,A_config04
      DJNZ   A_config03
      INC    L
A_config04
      RET

*/

/*----------------------------------------------------------------------------*/

void Control__init (void) {
__asm
; AUTOconfig
      LD     HL,#__KEMPSTON
      LD     (HL),#0xC9   ;RET
      LD     B,#250
A_config01$:
      IN     A,(#0x1F)
      AND    #0x1F
      RET    NZ
      DJNZ   A_config01$
      LD     (HL),#0xDB   ;IN
__endasm;
} //Control__init

