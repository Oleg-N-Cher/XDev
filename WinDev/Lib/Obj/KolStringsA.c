/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "KolTypesA.h"




export INTEGER KolStringsA_Length (CHAR *str, LONGINT str__len);


/*============================================================================*/

INTEGER KolStringsA_Length (CHAR *str, LONGINT str__len)
{
	INTEGER len, maxLen;
	maxLen = (int)str__len;
	len = 0;
	while (len < maxLen && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}

/*----------------------------------------------------------------------------*/

export void *KolStringsA__init(void)
{
	__DEFMOD;
	__IMPORT(KolTypesA__init);
	__REGMOD("KolStringsA", 0);
/* BEGIN */
	__ENDMOD;
}
