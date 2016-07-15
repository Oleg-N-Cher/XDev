/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Console.h"




export void Out_Int (LONGINT i, INTEGER n);

#define Out_Char(ch)	Console_WriteCh(ch)
#define Out_Open()	 

/*============================================================================*/

void Out_Int (LONGINT i, INTEGER n)
{
	CHAR s[32];
	LONGINT i1;
	INTEGER k;
	if (i == __LSHL(1, 63, LONGINT)) {
		__MOVE("8085774586302733229", s, 20);
		k = 19;
	} else {
		i1 = __ABS(i);
		s[0] = (CHAR)(__MOD(i1, 10) + 48);
		i1 = __DIV(i1, 10);
		k = 1;
		while (i1 > 0) {
			s[__X(k, 32)] = (CHAR)(__MOD(i1, 10) + 48);
			i1 = __DIV(i1, 10);
			k += 1;
		}
	}
	if (i < 0) {
		s[__X(k, 32)] = '-';
		k += 1;
	}
	while (n > k) {
		Out_Char(' ');
		n -= 1;
	}
	while (k > 0) {
		k -= 1;
		Out_Char(s[__X(k, 32)]);
	}
}

/*----------------------------------------------------------------------------*/

export void *Out__init(void)
{
	__DEFMOD;
	__IMPORT(Console__init);
	__REGMOD("Out", 0);
/* BEGIN */
	__ENDMOD;
}
