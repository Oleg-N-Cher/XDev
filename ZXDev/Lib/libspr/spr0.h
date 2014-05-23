#ifndef SPR0_H_DEFINED
#define SPR0_H_DEFINED

typedef unsigned char BYTE;
typedef unsigned int WORD;

typedef struct {
    WORD    sz;
    BYTE    w;
    BYTE    h;
    char    *datap;
}Sprite0;

void    spr0_out0(const Sprite0* adr, BYTE x, BYTE y)__naked;
void    spr0_out0_attr(const Sprite0* adr, BYTE x, BYTE y)__naked;

void    spr0_out0_setopt_nop()__naked;
void    spr0_out0_setopt_and()__naked;
void    spr0_out0_setopt_or()__naked;
void    spr0_out0_setopt_xor()__naked;

#endif /* SPR0_H_DEFINED */

