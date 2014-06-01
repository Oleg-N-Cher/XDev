#include <spr0.h>

void	spr0_out0(const Sprite0* adr, BYTE x, BYTE y)__naked{
__asm
    push  ix
    ld    ix,#4
    add   ix,sp
    ;// adr
    ld    e,0(ix)
    ld    d,1(ix)
    ;// x
    ld    l,2(ix)
    ;// y
    ld    h,3(ix)
    
    push  de
    pop   ix
    
    call  spr0_out0
    pop   ix
    ret
__endasm;
}
