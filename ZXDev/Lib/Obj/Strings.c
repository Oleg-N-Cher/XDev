/* Ofront+ 1.0 -s3 -21 */
#include "SYSTEM.h"




export BOOLEAN Strings_StrToInt (CHAR *str, SHORTINT str__len, SHORTINT *result);


/*============================================================================*/

BOOLEAN Strings_StrToInt (CHAR *str, SHORTINT str__len, SHORTINT *result)
{
	BYTE pos, sign;
	CHAR ch;
	SHORTINT prev;
	*result = 0;
	pos = 0;
	sign = 1;
	while ((SHORTINT)pos < str__len) {
		ch = str[__X(pos, str__len, "Strings", -260)];
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
				*result = (*result * 10 + (SHORTINT)ch) - 48;
				if (*result < prev) {
					return 0;
				}
				break;
			case 0x00: 
				*result = *result * (SHORTINT)sign;
				return pos > 0;
				break;
			default: 
				return 0;
				break;
		}
		pos += 1;
	}
	*result = *result * (SHORTINT)sign;
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
