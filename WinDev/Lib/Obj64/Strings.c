/* Ofront+ 1.0 -s3 -88 */
#include "SYSTEM.h"




export INTEGER Strings_Length (CHAR *str, INTEGER str__len);


/*============================================================================*/

INTEGER Strings_Length (CHAR *str, INTEGER str__len)
{
	INTEGER len;
	len = 0;
	while (len < str__len && str[__X(len, str__len, "Strings", -146)] != 0x00) {
		len += 1;
	}
	return len;
}

/*----------------------------------------------------------------------------*/

export void *Strings__init(void)
{
	__DEFMOD;
	__REGMOD("Strings", 0);
/* BEGIN */
	__ENDMOD;
}
