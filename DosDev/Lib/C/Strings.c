#include "SYSTEM.oh"
#include "Strings.oh"

typedef
	CHAR *Strings_PtrSTR;

export void Strings_IntToStr (INTEGER n, CHAR *str, SHORTINT str__len);
export SHORTINT Strings_Length (CHAR *str, SHORTINT str__len);

#include <stdio.h>
#define Strings_sprintf(str, str__len, n)	sprintf(str, "%ld", n)
#define Strings_sprintfL(str, str__len, n)	sprintf(str, "%lld", n)

/*================================== Header ==================================*/
void Strings_IntToStr (INTEGER n, CHAR *str, SHORTINT str__len)
{
	Strings_sprintf(str, str__len, n);
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT Strings_Length (CHAR *str, SHORTINT str__len)
{
	INTEGER len;
	len = 0;
	while (len < str__len && str[len] != 0x00) {
		len += 1;
	}
	return len;
}
