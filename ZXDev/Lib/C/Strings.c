unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee;
unsigned char Strings_StrToInt (unsigned char *str, unsigned int len, unsigned int *result);
/*============================================================================*/

unsigned int Strings_LengthEx (unsigned int len, unsigned char *str) __z88dk_callee {
  __asm
    POP  HL
    POP  BC
    EX   (SP),HL
    LD   E,C
    LD   D,B
    XOR  A
    CPIR
    EX   DE,HL
    RET  NZ
    SBC  HL,BC
    DEC  HL
__endasm;
} //Strings_LengthEx

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
