/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolTypes.h"




export INTEGER KolStrings_DelimiterLast (CHAR *str, LONGINT str__len, CHAR *delimiters, LONGINT delimiters__len);
export INTEGER KolStrings_Length (CHAR *str, LONGINT str__len);
export INTEGER KolStrings_StrRScan (CHAR *str, LONGINT str__len, CHAR ch);
export BOOLEAN KolStrings_SubStr (CHAR *s, LONGINT s__len, INTEGER pos, INTEGER len, CHAR *res, LONGINT res__len);

#define KolStrings__init()	/*-noinit*/

/*============================================================================*/

INTEGER KolStrings_Length (CHAR *str, LONGINT str__len)
{
	INTEGER len, maxLen;
	maxLen = (INTEGER)str__len;
	len = 0;
	while (len < maxLen && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}

/*----------------------------------------------------------------------------*/
INTEGER KolStrings_StrRScan (CHAR *str, LONGINT str__len, CHAR ch)
{
	INTEGER count, index;
	count = KolStrings_Length(str, str__len);
	if (ch == 0x00) {
		return count;
	}
	index = count - 1;
	while (index >= 0) {
		if (ch == str[__X(index, str__len)]) {
			return index;
		}
		index += -1;
	}
	return -1;
}

/*----------------------------------------------------------------------------*/
INTEGER KolStrings_DelimiterLast (CHAR *str, LONGINT str__len, CHAR *delimiters, LONGINT delimiters__len)
{
	INTEGER delimiterN, f, result;
	delimiterN = 0;
	result = KolStrings_Length(str, str__len);
	while (delimiters[__X(delimiterN, delimiters__len)] != 0x00) {
		f = KolStrings_StrRScan(str, str__len, delimiters[__X(delimiterN, delimiters__len)]);
		if (f != -1) {
			if (str[__X(result, str__len)] == 0x00 || f > result) {
				result = f;
			}
		}
		delimiterN += 1;
	}
	return result;
}

/*----------------------------------------------------------------------------*/
BOOLEAN KolStrings_SubStr (CHAR *s, LONGINT s__len, INTEGER pos, INTEGER len, CHAR *res, LONGINT res__len)
{
	INTEGER i, j, max;
	__ASSERT(len >= 0, 20);
	__ASSERT(pos >= 0, 21);
	i = 0;
	j = 0;
	max = (INTEGER)res__len - 1;
	while (i < pos && s[__X(i, s__len)] != 0x00) {
		i += 1;
	}
	while ((j < len && j < max) && s[__X(i, s__len)] != 0x00) {
		res[__X(j, res__len)] = s[__X(i, s__len)];
		j += 1;
		i += 1;
	}
	res[__X(j, res__len)] = 0x00;
	if (s[__X(i, s__len)] == 0x00) {
		len = j - 1;
	}
	return len < max;
}

/*----------------------------------------------------------------------------*/

export void *KolStrings__init(void)
{
	__DEFMOD;
	__IMPORT(KolTypes__init);
	__REGMOD("KolStrings", 0);
/* BEGIN */
	__ENDMOD;
}
