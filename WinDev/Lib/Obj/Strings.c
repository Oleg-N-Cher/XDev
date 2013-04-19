/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *Strings_PtrSTR;




export void Strings_IntToStr (LONGINT n, CHAR *str, LONGINT str__len);
export LONGINT Strings_Length (CHAR *str, LONGINT str__len);

#include <stdio.h>
#define Strings_sprintf(str, str__len, n)	sprintf(str, "%ld", n)
#define Strings_sprintfL(str, str__len, n)	sprintf(str, "%lld", n)

void Strings_IntToStr (LONGINT n, CHAR *str, LONGINT str__len)
{
	Strings_sprintf(str, str__len, n);
}

LONGINT Strings_Length (CHAR *str, LONGINT str__len)
{
	LONGINT len, maxLen;
	maxLen = str__len;
	len = 0;
	while (len < maxLen && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}


export void *Strings__init(void)
{
	__DEFMOD;
	__REGMOD("Strings", 0);
/* BEGIN */
	__ENDMOD;
}
