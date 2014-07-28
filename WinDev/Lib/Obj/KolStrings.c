/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolTypes.h"




export INTEGER KolStrings_Length (CHAR *str, LONGINT str__len);

#define KolStrings__init()	/*-noinit*/

/*============================================================================*/

INTEGER KolStrings_Length (CHAR *str, LONGINT str__len)
{
	INTEGER len, maxLen;
	maxLen = (int)str__len;
	len = 0;
	while (len < maxLen && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}

