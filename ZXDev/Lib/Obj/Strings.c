/* Ofront+ 1.0 -tspkae */
#include "SYSTEM.h"




export BOOLEAN Strings_StrToInt (CHAR *str, SHORTINT str__len, INTEGER *result);


/*============================================================================*/

BOOLEAN Strings_StrToInt (CHAR *str, SHORTINT str__len, INTEGER *result)
{
	SHORTINT pos, sign;
	CHAR ch;
	INTEGER prev;
	*result = 0;
	pos = 0;
	sign = 1;
	while (pos < str__len) {
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
				*result = (*result * 10 + (INTEGER)ch) - 48;
				if (*result < prev) {
					return 0;
				}
				break;
			case 0x00: 
				*result = *result * (INTEGER)sign;
				return pos > 0;
				break;
			default: 
				return 0;
				break;
		}
		pos += 1;
	}
	*result = *result * (INTEGER)sign;
	return pos > 0;
}

/*----------------------------------------------------------------------------*/

export void *Strings__init(void)
{
	__DEFMOD;
	__REGMOD("Strings", 0);
/* BEGIN */
	__ENDMOD;
}
