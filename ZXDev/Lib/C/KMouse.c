/*
  Short mouse driver (optimized for size - source for Prometheus / AS + manual)
  https://velesoft.speccy.cz/k-mouse_driver.htm
*/

unsigned char KMouse_Read (void) __naked
{
    __asm
;RUSSIAN KEMPSTON MOUSE DRIVER

XMAX     =  255
XMIN     =  0

YMAX     =  191
YMIN     =  0

;XECUTE MOUSE
;TAKE COORDINATES FROM CURPOS=
;=COORD
         LD   HL, (COORD)
;L=X-axis
;H=Y-axis
         LD   BC, #0xFBDF
         LD   DE, (OLDCO)
         IN   A, (C)
         LD   (OLDCO), A
         SUB  E
         JR   Z, NM_X
         JP   P, MX_PL
         ADD  A, L
         JR   C, ZER_X
         XOR  A
ZER_X:   LD   L, A
         JR   NM_X
MX_PL:   ADD  A, L
         JR   C, BEX_Z
         CP   #XMAX
         JR   C, BEX_B
BEX_Z:   LD   A, #XMAX
BEX_B:   LD   L, A
NM_X:    LD   B, #0xFF
         IN   A, (C)
         LD   (OLDCO + 1), A
         SUB  D
         JR   Z, NM_Y
         NEG
         JP   P, MY_PL
         ADD  A, H
         JR   C, ZER_Y
         XOR  A
ZER_Y:   LD   H, A
         JR   NM_Y
MY_PL:   ADD  A, H
         JR   C, BEY_Z
         CP   #YMAX
         JR   C, BEY_B
BEY_Z:   LD   A, #YMAX
BEY_B:   LD   H, A
NM_Y:    LD   A, H
         CP   #0xFF
         JR   C, BIGY
         LD   H, #0xFF
BIGY:    CP   #YMIN
         JR   NC, SMALY
         LD   H, #YMIN
SMALY:   LD   A, L
         CP   #0xFF
         JR   C, DIRY
         LD   L, #0xFF
DIRY:    CP   #XMIN
         JR   NC, DIMENS
         LD   L, #XMIN
DIMENS:  LD   (COORD), HL
         LD   BC, #0xFADF
         IN   A, (C)
         CPL
         AND  #7
         LD   (CONTRB), A
         LD   L, A
         RET
    __endasm;
} //KMouse_Read

void KMouse_SetXY (unsigned char x, unsigned char y) __naked __z88dk_callee
{
    __asm
         POP  HL
         EX   (SP), HL
;------------------------------
;INPUT: L=new X-axis
;       H=new Y-axis
         LD   BC, #0xFBDF
         IN   A, (C)
         LD   (OLDCO), A
         LD   B, #0xFF
         IN   A, (C)
         LD   (OLDCO + 1), A
         LD   (COORD), HL
         RET
;------------------------------
;new cursor position
.globl   _KMouse_X
_KMouse_X:
COORD:   .DB  0
.globl   _KMouse_Y
_KMouse_Y:
         .DB  0
;buttons status
CONTRB:  .DB  0

;working (previous position)
OLDCO:   .DB  0, 0
;------------------------------
    __endasm;
} //KMouse_SetXY

/*--------------------------------- Cut here ---------------------------------*/
unsigned char KMouse_Detect (void) __naked {
__asm
         LD   DE, #0x301
         LD   L, E
         LD   BC, #0xFADF
MT_D0:   IN   A, (C)
         CPL
         AND  #7
         JR   Z, MT_D1
         DEC  L
         RET              ; FALSE
MT_D1:   DEC  DE
         LD   A, E
         OR   D
         JR   NZ, MT_D0
         RET              ; TRUE
__endasm;
} //KMouse_Detect
