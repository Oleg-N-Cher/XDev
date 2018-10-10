unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee;
unsigned char Strings_IntToStr (int n, unsigned char *str, unsigned int len) __z88dk_callee;
unsigned char Strings_UIntToStr (unsigned int n, unsigned char *str, unsigned int len) __z88dk_callee;
unsigned char Strings_StrToInt (unsigned char *str, unsigned int len, unsigned int *result);
/*============================================================================*/

unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee {
    __asm
        POP  HL
        POP  BC         ; len
        EX   (SP), HL   ; str
        LD   E, C
        LD   D, B
        XOR  A
        CPIR
        EX   DE, HL
        RET  NZ
        SBC  HL, BC
        DEC  HL
    __endasm;
} //Strings_LengthEx

/*----------------------------------------------------------------------------*/
unsigned char Strings_IntToStr (int n, unsigned char *str, unsigned int len) __naked __z88dk_callee
{
    __asm
        POP  HL
        POP  DE         ; n
        BIT  7, D
        JP   Z, _Strings_UIntToStr+2

        PUSH HL
        ; DE := -DE
        XOR  A          ;  4
        LD   L, A       ;  4
        LD   H, A       ;  4
        SBC  HL, DE     ; 15 => 31t
        EX   DE, HL
        POP  HL

        POP  BC         ; str
        EX   (SP), HL   ; len

        DEC  HL
        LD   A, L
        OR   H
        RET  Z          ; Buffer too small

        LD   A, #'-'
        LD   (BC), A
        INC  BC
        JP   _Strings_UIntToStr+4
__endasm;
} //Strings_IntToStr

/*----------------------------------------------------------------------------*/
#include "Math.h"
unsigned char Strings_UIntToStr (unsigned int n, unsigned char *str, unsigned int len) __z88dk_callee
{
// decimal2ascii HL=string[6], DE=number -> HL=*0(string)
// функция записывает 16-разрядное беззнаковое число
// в десятичном виде, ведущие нули не записываются.
// по адресу (HL) будет записано 5 цифр числа и
// символ с кодом 0 завершающий строку.
// *HL = itoa(DE) -> HL=указатель на завершающий 0.
    __asm
        POP  HL
        POP  DE         ; n
        POP  BC         ; str
        EX   (SP), HL   ; len

        LD   A, H       ; Check buffer size
        OR   A
        JR   Z, HighZero$
        LD   L, #0xFF   ; Enough
HighZero$:

        PUSH HL
        PUSH BC         ; str
        EX   DE, HL
        CALL _Math_UIntToBCD
        LD   A, E
        EX   DE, HL
        POP  HL         ; str
        POP  BC         ; len (high byte)
        LD   B, C

        OR   A
        JR   NZ, LTOA5$
        LD   A, D
        AND  #0xF0
        JR   NZ, LTOA4$
        LD   A, D
        AND  #0x0F
        JR   NZ, LTOA3$
        LD   A, E
        AND  #0xF0
        JR   NZ, LTOA2$
        LD   A, E
        JR   LTOA1$

LTOA5$: OR   #0x30      ; A, D, E
        LD   (HL), A
        INC  HL
        DJNZ LTOA4$
        LD   L, #0      ; RETURN FALSE
        RET
LTOA4$: LD   (HL), D
        LD   A, #0x33
        RRD
        INC  HL
        DJNZ LTOA3$
        LD   L, #0      ; RETURN FALSE
        RET
LTOA3$: OR   #0x30
        LD   (HL), A
        INC  HL
        DJNZ LTOA2$
        LD   L, #0      ; RETURN FALSE
        RET
LTOA2$: LD   (HL), E
        LD   A, #0x33
        RRD
        INC  HL
        DJNZ LTOA1$
        LD   L, #0      ; RETURN FALSE
        RET
LTOA1$: OR   #0x30
        LD   (HL), A
        DJNZ LTOA0$
        LD   L, #0      ; RETURN FALSE
        RET
LTOA0$: INC  HL
        LD   (HL), #0
        LD   L, #1      ; RETURN TRUE
    __endasm;
} //Strings_UIntToStr

/*----------------------------------------------------------------------------*/
unsigned char Strings_StrToInt (unsigned char *str, unsigned int len, unsigned int *result)
{
	unsigned char pos, ch;
	signed char sign;
	unsigned int prev;
	*result = 0;
	pos = 0;
	sign = 1;
	while (pos < len) {
		ch = str[pos];
		switch (ch) {
			case '-': 
				if (pos == 0) {
					sign = -1;
				} else {
					return 0;
				}
				break;
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
				prev = *result;
				*result = (*result * 10 + ch) - 48;
				if (*result < prev) {
					return 0;
				}
				break;
			case 0x00: 
				*result = *result * sign;
				return pos > 0;
				break;
			default: 
				return 0;
				break;
		}
		pos += 1;
	}
	*result = *result * sign;
	return pos > 0;
} //Strings_StrToInt
