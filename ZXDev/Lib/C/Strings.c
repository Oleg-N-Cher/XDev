unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee;
unsigned char Strings_IntToStr (int n, unsigned char *str, unsigned int len) __z88dk_callee;
unsigned char Strings_UIntToStr (unsigned int n, unsigned char *str, unsigned int len) __z88dk_callee;
unsigned char Strings_StrToInt (unsigned char *str, unsigned int len, unsigned int *result);
/*============================================================================*/

unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee {
    __asm
        POP  HL
        POP  BC             ; len
        EX   (SP), HL       ; str
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
unsigned char Strings_IntToStr (int n, unsigned char *str, unsigned int len) __z88dk_callee
{
    __asm
        POP  DE
        POP  HL             ; n
        EXX
        POP  HL             ; HL(alt) := str
        EXX
        POP  BC             ; len
        PUSH DE

        BIT  7, H
        JP   Z, _Strings_UIntToStr+7
        LD   A, L           ; HL := -HL
        CPL
        LD   L, A
        LD   A, H
        CPL
        LD   H, A
        INC  HL

        EXX
        LD   (HL), #'-'
        INC  HL
        EXX

        DEC  BC             ; is buffer enough?
        LD   A, C
        OR   B
        JP   NZ, _Strings_UIntToStr+7

        LD   L, #0          ; RETURN FALSE
__endasm;
} //Strings_IntToStr

/*----------------------------------------------------------------------------*/
unsigned char Strings_UIntToStr (unsigned int n, unsigned char *str, unsigned int len) __z88dk_callee
{
    __asm
        POP  DE
        POP  HL             ; n
        EXX
        POP  HL             ; HL(alt) := str
        EXX
        POP  BC             ; len
        PUSH DE

        LD   A, #255        ; Check buffer size
        ADD  A, B
        SBC  A, A
        OR   C
        LD   B, A           ; B := C, OR 255 IF B # 0

        LD   DE, #-10000    // таблица степеней десятки
        LD   C, E           ; flag := 0xF0
        CALL DIGIT$
        LD   DE, #-1000     ;
        CALL DIGIT$
        LD   DE, #-100      ;
        CALL DIGIT$
        LD   E, #-10        ;
        CALL DIGIT$
        LD   A, L
        ADD  #'0'
        CALL NEXTCH$
        EXX
        LD   (HL), #0       ; Final 0X (ASCIIZ)
        LD   L, #1          ; RETURN TRUE
        RET

DIGIT$: LD   A, #'0'-1      // обнулили счётчик
PDW2$:  INC  A              // увеличиваем счётчик
        ADD  HL, DE         // вычитаем текущую степень десятки
        JR   C, PDW2$       // повторяем пока HL >= 0
        SBC  HL, DE         // HL := HL MOD DE; A := HL DIV DE
        DEC  C              // проверяем: может это незначащий нуль?
        JR   Z, PRNT$       // если уже были другие цифры, печатаем
        CP   #'0'           // если это нуль, то он незначащий
        RET  Z              // ничего не печатаем
PRNT$:  LD   C, #1          // дальше все значащие
NEXTCH$:EXX
        LD   (HL), A
        INC  HL
        EXX
        DJNZ RETRN$
        LD   L, #0          ; RETURN FALSE
        POP  AF
RETRN$:
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
