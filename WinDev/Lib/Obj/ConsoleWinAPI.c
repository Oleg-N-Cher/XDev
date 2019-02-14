/* Ofront+ 1.0 -sxt3 -48 */
#include "SYSTEM.h"
#include "Ignore.h"
#include "Strings.h"
#include "WinAPI.h"


static INTEGER ConsoleWinAPI_hConOutput;


static INTEGER ConsoleWinAPI_Exponent (REAL x);
static BOOLEAN ConsoleWinAPI_IsNaN (REAL x);
export void ConsoleWinAPI_SetColors (SHORTINT colors);
static REAL ConsoleWinAPI_Ten (INTEGER n);
export void ConsoleWinAPI_WriteCh (CHAR ch);
export void ConsoleWinAPI_WriteInt (INTEGER n);
export void ConsoleWinAPI_WriteLn (void);
export void ConsoleWinAPI_WriteLong (LONGINT n);
export void ConsoleWinAPI_WriteReal (REAL x);
export void ConsoleWinAPI_WriteRealFix (REAL x, INTEGER n);
export void ConsoleWinAPI_WriteStr (CHAR *str, INTEGER str__len);


/*============================================================================*/

void ConsoleWinAPI_SetColors (SHORTINT colors)
{
	Ignore_Int(WinAPI_SetConsoleTextAttribute(ConsoleWinAPI_hConOutput, colors));
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteCh (CHAR ch)
{
	INTEGER maxLen;
	Ignore_Int(WinAPI_WriteFile(ConsoleWinAPI_hConOutput, (SYSTEM_ADRINT)&ch, 1, &maxLen, NIL));
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteLn (void)
{
	ConsoleWinAPI_WriteCh(0x0d);
	ConsoleWinAPI_WriteCh(0x0a);
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteInt (INTEGER n)
{
	CHAR s[11];
	INTEGER i1, k;
	if (n == (-2147483647-1)) {
		__MOVE("8463847412", s, 11);
		k = 10;
	} else {
		i1 = __ABS(n);
		s[0] = (CHAR)(__MOD(i1, 10) + 48);
		i1 = __DIV(i1, 10);
		k = 1;
		while (i1 > 0) {
			s[k] = (CHAR)(__MOD(i1, 10) + 48);
			i1 = __DIV(i1, 10);
			k += 1;
		}
	}
	if (n < 0) {
		s[k] = '-';
		k += 1;
	}
	while (k > 0) {
		k -= 1;
		ConsoleWinAPI_WriteCh(s[k]);
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteLong (LONGINT n)
{
	CHAR s[20];
	LONGINT i1;
	INTEGER k;
	if (n == (-9223372036854775807LL-1)) {
		__MOVE("8085774586302733229", s, 20);
		k = 19;
	} else {
		i1 = __ABS(n);
		s[0] = (CHAR)(__MOD(i1, 10) + 48);
		i1 = __DIV(i1, 10);
		k = 1;
		while (i1 > 0) {
			s[k] = (CHAR)(__MOD((INTEGER)i1, 10) + 48);
			i1 = __DIV(i1, 10);
			k += 1;
		}
	}
	if (n < 0) {
		s[k] = '-';
		k += 1;
	}
	while (k > 0) {
		k -= 1;
		ConsoleWinAPI_WriteCh(s[k]);
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteStr (CHAR *str, INTEGER str__len)
{
	INTEGER maxLen;
	Ignore_Int(WinAPI_WriteFile(ConsoleWinAPI_hConOutput, (SYSTEM_ADRINT)str, Strings_Length((void*)str, str__len), &maxLen, NIL));
}

/*----------------------------------------------------------------------------*/
static REAL ConsoleWinAPI_Ten (INTEGER n)
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

static BOOLEAN ConsoleWinAPI_IsNaN (REAL x)
{
	return (0x7ff80000 & ~(SET)((INTEGER)__ASHR(__VAL(LONGINT, x), 32, LONGINT))) == 0x0;
}

static INTEGER ConsoleWinAPI_Exponent (REAL x)
{
	INTEGER exp, offset;
	x = __ABS(x);
	exp = (INTEGER)__ASHR(__VAL(LONGINT, x), 52, LONGINT);
	offset = 1023;
	while (exp == 0) {
		x = x + x;
		exp = (INTEGER)__ASHR(__VAL(LONGINT, x), 52, LONGINT);
		offset += 1;
	}
	return exp - offset;
}

void ConsoleWinAPI_WriteReal (REAL x)
{
	LONGINT m;
	INTEGER e, i;
	CHAR d[16];
	e = __MASK((INTEGER)__ASHR(__VAL(LONGINT, x), 52, LONGINT), -2048);
	if (e == 0) {
		ConsoleWinAPI_WriteCh('0');
	} else if (ConsoleWinAPI_IsNaN(x)) {
		ConsoleWinAPI_WriteStr((void*)&"NaN", 4);
	} else {
		if (x < (REAL)0) {
			ConsoleWinAPI_WriteCh('-');
			x = -x;
		}
		e = __ASHR(ConsoleWinAPI_Exponent(x) * 77, 8, INTEGER) - 12;
		if (e >= 0) {
			x = x / (REAL)ConsoleWinAPI_Ten(e);
		} else if (e < -308) {
			x = (x * ConsoleWinAPI_Ten(-e - 12)) * ConsoleWinAPI_Ten(12);
		} else {
			x = ConsoleWinAPI_Ten(-e) * x;
		}
		m = __ENTIERL(x + 0.5);
		i = 0;
		if (m >= 10000000000000LL) {
			e += 1;
			m = __DIV(m, 10);
		}
		do {
			d[i] = (CHAR)(__MOD(m, 10) + 48);
			m = __DIV(m, 10);
			i += 1;
		} while (!(m == 0));
		i -= 1;
		ConsoleWinAPI_WriteCh(d[i]);
		ConsoleWinAPI_WriteCh('.');
		while (i > 0) {
			i -= 1;
			ConsoleWinAPI_WriteCh(d[i]);
		}
		e += 12;
		if (e != 0) {
			ConsoleWinAPI_WriteCh('E');
			if (e > 0) {
				ConsoleWinAPI_WriteCh('+');
			}
			ConsoleWinAPI_WriteInt(e);
		}
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinAPI_WriteRealFix (REAL x, INTEGER n)
{
	LONGINT m;
	if (x == (REAL)0) {
		ConsoleWinAPI_WriteCh('0');
	} else {
		if (n < 1 || n > 16) {
			n = 16;
		}
		if (x < (REAL)0) {
			x = -x;
			ConsoleWinAPI_WriteCh('-');
		}
		m = __ENTIERL(x);
		ConsoleWinAPI_WriteLong(m);
		ConsoleWinAPI_WriteCh('.');
		x = ConsoleWinAPI_Ten(n) * (x - m);
		m = __ENTIERL(x + 0.5);
		while (m != 0 && __MOD(m, 10) == 0) {
			m = __DIV(m, 10);
		}
		ConsoleWinAPI_WriteLong(m);
	}
}

/*----------------------------------------------------------------------------*/

export void *ConsoleWinAPI__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(Strings__init);
	__IMPORT(WinAPI__init);
	__REGMOD("ConsoleWinAPI", 0);
	__REGCMD("WriteLn", ConsoleWinAPI_WriteLn);
/* BEGIN */
	ConsoleWinAPI_hConOutput = WinAPI_GetStdHandle(-11);
	__ENDMOD;
}
