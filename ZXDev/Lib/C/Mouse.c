extern unsigned char Mouse_Detect (void);

/*================================== Header ==================================*/
unsigned char Mouse_Detect (void) __naked {
__asm
        LD   DE, #0x301
        LD   L, E
        LD   BC, #0xFADF
MT_D0:  IN   A, (C)
        CPL
        AND  #7
        JR   Z, MT_D1
        DEC  L
        RET              ; FALSE
MT_D1:  DEC  DE
        LD   A, E
        OR   D
        JR   NZ, MT_D0
        RET              ; TRUE
__endasm;
} //Mouse_Detect

/*--------------------------------- Cut here ---------------------------------*/
