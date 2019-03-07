/* Ofront+ 1.0 -sxt3 -88 */
#include "SYSTEM.h"




static REAL ConsoleStdIO_Ten (INTEGER n);
export void ConsoleStdIO_WriteCh (CHAR ch);
export void ConsoleStdIO_WriteInt (INTEGER n);
export void ConsoleStdIO_WriteLn (void);
export void ConsoleStdIO_WriteLong (LONGINT n);
export void ConsoleStdIO_WriteReal (REAL x);
export void ConsoleStdIO_WriteRealFix (REAL x, INTEGER n);
export void ConsoleStdIO_WriteStr (CHAR *str, INTEGER str__len);

#include <stdio.h>
#define ConsoleStdIO_printfc(ch)	printf("%c", ch)
#define ConsoleStdIO_printfi(n)	printf("%d", n);
#define ConsoleStdIO_printfli(l)	printf("%lld", l)
#define ConsoleStdIO_printfln()	printf("\n")
#define ConsoleStdIO_printfr(r)	printf("%.7g", r)
#define ConsoleStdIO_printfs(str, str__len)	printf("%s", str)

/*============================================================================*/

void ConsoleStdIO_WriteCh (CHAR ch)
{
	ConsoleStdIO_printfc(ch);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteInt (INTEGER n)
{
	ConsoleStdIO_printfi(n);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteLong (LONGINT n)
{
	ConsoleStdIO_printfli(n);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteLn (void)
{
	ConsoleStdIO_printfln();
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteStr (CHAR *str, INTEGER str__len)
{
	ConsoleStdIO_printfs((void*)str, str__len);
}

/*----------------------------------------------------------------------------*/
static REAL ConsoleStdIO_Ten (INTEGER n)
{
	REAL t, p;
	t = (REAL)1;
	p = (REAL)10;
	while (n > 0) {
		if (__ODD(n)) {
			t = p * t;
		}
		p = p * p;
		n = __ASHR(n, 1, INTEGER);
	}
	return t;
}

void ConsoleStdIO_WriteReal (REAL x)
{
	ConsoleStdIO_printfr(x);
}

/*----------------------------------------------------------------------------*/
void ConsoleStdIO_WriteRealFix (REAL x, INTEGER n)
{
	LONGINT m;
	if (x == (REAL)0) {
		ConsoleStdIO_WriteCh('0');
	} else {
		if (n < 1 || n > 16) {
			n = 16;
		}
		if (x < (REAL)0) {
			x = -x;
			ConsoleStdIO_WriteCh('-');
		}
		m = __ENTIERL(x);
		ConsoleStdIO_WriteLong(m);
		ConsoleStdIO_WriteCh('.');
		x = ConsoleStdIO_Ten(n) * (x - m);
		m = __ENTIERL(x + 0.5);
		while (m != 0 && __MOD(m, 10) == 0) {
			m = __DIV(m, 10);
		}
		ConsoleStdIO_WriteLong(m);
	}
}

/*----------------------------------------------------------------------------*/

export void *ConsoleStdIO__init(void)
{
	__DEFMOD;
	__REGMOD("ConsoleStdIO", 0);
	__REGCMD("WriteLn", ConsoleStdIO_WriteLn);
/* BEGIN */
	__ENDMOD;
}
