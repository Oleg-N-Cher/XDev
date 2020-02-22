unsigned char trdosIsDisk (void) {
  __asm 
       LD      HL,(#23635)
       LD      DE,#23755
       XOR     A
       SBC     HL,DE
       LD      L,A
       RET     Z
       INC     L
  __endasm;
}
