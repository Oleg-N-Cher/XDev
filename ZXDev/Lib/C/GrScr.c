void GrScr_ScrToAtr (void) __naked {
//  in: DE = screen address
// out: DE - attrib address
  __asm
              LD   A, D    ; 4
              RRCA         ; 4
              RRCA         ; 4
              RRCA         ; 4
              AND  #3      ; 7
              .DB  0xF6    ; 7 ; OR #0x58
.globl _GrScr_atr
_GrScr_atr:   .DB  0x58
              LD   D, A    ; 4 = 34t
              RET
  __endasm;
} //GrScr_ScrToAtr

/*--------------------------------- Cut here ---------------------------------*/
void GrScr_SetScr (unsigned char hiadr) __naked __z88dk_fastcall {
  __asm
              LD   A, L
              LD   (_GrScr_scr), A
              ADD  #18
              LD   (_GrScr_atr), A
              RET
  __endasm;
} //GrScr_SetScr

/*--------------------------------- Cut here ---------------------------------*/
void GrScr_XYtoScr (void) __naked {
//  in: E = x; D = y (character coords)
// out: DE = screen address
  __asm
              LD   A, D
              RRCA
              RRCA
              RRCA
              AND  #0xE0
              ADD  A, E
              LD   E, A
              LD   A, D
              AND  #0x18
              .DB  0xF6    ; OR #0x40
.globl _GrScr_scr
_GrScr_scr:   .DB  0x40
              LD   D, A
              RET
  __endasm;
} //GrScr_XYtoScr
