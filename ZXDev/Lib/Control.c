#include "SYSTEM.h"

export SET Control_Get (void);
/*============================================================================*/

SET Control_Get (void) __naked {
__asm
/* Из журнала Deja Vu #09, Кемерово, 1999
 (C) Rezonance group */

;Кроме стандартных Q, A, O, P, Space, здесь
;опрашивается Sinclair1 и Sinclair2. На выходе
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
        .DB   0,0,0
__endasm;
} //Control_Get()

