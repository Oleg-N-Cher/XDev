#ifndef Asm__h
#define Asm__h

#define Asm_Byte(b) __asm .db b __endasm
#define Asm_Byte1(b) __asm .db b __endasm
#define Asm_Byte2(b1,b2) __asm .db b1,b2 __endasm
#define Asm_Byte3(b1,b2,b3) __asm .db b1,b2,b3 __endasm
#define Asm_Byte4(b1,b2,b3,b4) __asm .db b1,b2,b3,b4 __endasm
#define Asm_Byte5(b1,b2,b3,b4,b5) __asm .db b1,b2,b3,b4,b5 __endasm
#define Asm_Byte6(b1,b2,b3,b4,b5,b6) __asm .db b1,b2,b3,b4,b5,b6 __endasm
#define Asm_Byte7(b1,b2,b3,b4,b5,b6,b7) __asm .db b1,b2,b3,b4,b5,b6,b7 __endasm
#define Asm_Byte8(b1,b2,b3,b4,b5,b6,b7,b8) __asm .db b1,b2,b3,b4,b5,b6,b7,b8 __endasm
#define Asm_Byte9(b1,b2,b3,b4,b5,b6,b7,b8,b9) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9 __endasm
#define Asm_Byte10(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10 __endasm
#define Asm_Byte11(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11 __endasm
#define Asm_Byte12(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12 __endasm
#define Asm_Byte13(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13 __endasm
#define Asm_Byte14(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14 __endasm
#define Asm_Byte15(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15 __endasm
#define Asm_Byte16(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16 __endasm

#define Asm_Char(b) __asm .db b __endasm
#define Asm_Char1(b) __asm .db b __endasm
#define Asm_Char2(b1,b2) __asm .db b1,b2 __endasm
#define Asm_Char3(b1,b2,b3) __asm .db b1,b2,b3 __endasm
#define Asm_Char4(b1,b2,b3,b4) __asm .db b1,b2,b3,b4 __endasm
#define Asm_Char5(b1,b2,b3,b4,b5) __asm .db b1,b2,b3,b4,b5 __endasm
#define Asm_Char6(b1,b2,b3,b4,b5,b6) __asm .db b1,b2,b3,b4,b5,b6 __endasm
#define Asm_Char7(b1,b2,b3,b4,b5,b6,b7) __asm .db b1,b2,b3,b4,b5,b6,b7 __endasm
#define Asm_Char8(b1,b2,b3,b4,b5,b6,b7,b8) __asm .db b1,b2,b3,b4,b5,b6,b7,b8 __endasm
#define Asm_Char9(b1,b2,b3,b4,b5,b6,b7,b8,b9) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9 __endasm
#define Asm_Char10(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10 __endasm
#define Asm_Char11(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11 __endasm
#define Asm_Char12(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12 __endasm
#define Asm_Char13(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13 __endasm
#define Asm_Char14(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14 __endasm
#define Asm_Char15(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15 __endasm
#define Asm_Char16(b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16) __asm .db b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16 __endasm

#define Asm_Word(w) __asm .dw w __endasm
#define Asm_Word1(w) __asm .dw w __endasm
#define Asm_Word2(w1,w2) __asm .dw w1,w2 __endasm
#define Asm_Word3(w1,w2,w3) __asm .dw w1,w2,w3 __endasm
#define Asm_Word4(w1,w2,w3,w4) __asm .dw w1,w2,w3,w4 __endasm
#define Asm_Word5(w1,w2,w3,w4,w5) __asm .dw w1,w2,w3,w4,w5 __endasm
#define Asm_Word6(w1,w2,w3,w4,w5,w6) __asm .dw w1,w2,w3,w4,w5,w6 __endasm
#define Asm_Word7(w1,w2,w3,w4,w5,w6,w7) __asm .dw w1,w2,w3,w4,w5,w6,w7 __endasm
#define Asm_Word8(w1,w2,w3,w4,w5,w6,w7,w8) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8 __endasm
#define Asm_Word9(w1,w2,w3,w4,w5,w6,w7,w8,w9) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9 __endasm
#define Asm_Word10(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10 __endasm
#define Asm_Word11(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11 __endasm
#define Asm_Word12(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12 __endasm
#define Asm_Word13(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13 __endasm
#define Asm_Word14(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14 __endasm
#define Asm_Word15(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15 __endasm
#define Asm_Word16(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16) __asm .dw w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16 __endasm

#define __arg_killer__(a)
#define Asm_String(str, str__len)	__asm .ascii __arg_killer__ str __endasm
#define Asm_StringZ(str, str__len)	__asm .ascii __arg_killer__ str \
  .db 0x00 \
  __endasm
#define Asm_Code(str, str__len)	__asm__(__arg_killer__ str)

#define Asm__init()

#endif
