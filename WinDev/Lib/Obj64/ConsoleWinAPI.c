/* Ofront+ 1.0 -sxt3 -88 */
#include "SYSTEM.oh"
#include "WinApi.oh"
#include "Strings.oh"
#include "Ignore.oh"


static LONGINT ConsoleWinApi_hConOutput;


static INTEGER ConsoleWinApi_Exponent (REAL x);
static BOOLEAN ConsoleWinApi_IsNaN (REAL x);
export void ConsoleWinApi_SetColors (SHORTINT colors);
static REAL ConsoleWinApi_Ten (INTEGER n);
export void ConsoleWinApi_WriteCh (CHAR ch);
export void ConsoleWinApi_WriteInt (INTEGER n);
export void ConsoleWinApi_WriteLn (void);
export void ConsoleWinApi_WriteLong (LONGINT n);
export void ConsoleWinApi_WriteReal (REAL x);
export void ConsoleWinApi_WriteRealFix (REAL x, INTEGER n);
export void ConsoleWinApi_WriteStr (CHAR *str, INTEGER str__len);


/*============================================================================*/

void ConsoleWinApi_SetColors (SHORTINT colors)
{
	Ignore_Int(SetConsoleTextAttribute(ConsoleWinApi_hConOutput, colors));
}

/*----------------------------------------------------------------------------*/
void ConsoleWinApi_WriteCh (CHAR ch)
{
	INTEGER maxLen;
	Ignore_Int(WriteFile(ConsoleWinApi_hConOutput, (SYSTEM_ADRINT)&ch, 1, &maxLen, NIL));
}

/*----------------------------------------------------------------------------*/
void ConsoleWinApi_WriteLn (void)
{
	ConsoleWinApi_WriteCh(0x0d);
	ConsoleWinApi_WriteCh(0x0a);
}

/*----------------------------------------------------------------------------*/
void ConsoleWinApi_WriteInt (INTEGER n)
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
		ConsoleWinApi_WriteCh(s[k]);
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinApi_WriteLong (LONGINT n)
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
		ConsoleWinApi_WriteCh(s[k]);
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinApi_WriteStr (CHAR *str, INTEGER str__len)
{
	INTEGER maxLen;
	Ignore_Int(WriteFile(ConsoleWinApi_hConOutput, (SYSTEM_ADRINT)str, Strings_Length((void*)str, str__len), &maxLen, NIL));
}

/*----------------------------------------------------------------------------*/
static REAL ConsoleWinApi_Ten (INTEGER n)
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

static BOOLEAN ConsoleWinApi_IsNaN (REAL x)
{
	return (0x7ff80000 & ~(SET)((INTEGER)__ASHR(__VAL(LONGINT, x), 32, LONGINT))) == 0x0;
}

static INTEGER ConsoleWinApi_Exponent (REAL x)
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

void ConsoleWinApi_WriteReal (REAL x)
{
	LONGINT m;
	INTEGER e, i;
	CHAR d[16];
	e = __MASK((INTEGER)__ASHR(__VAL(LONGINT, x), 52, LONGINT), -2048);
	if (e == 0) {
		ConsoleWinApi_WriteCh('0');
	} else if (ConsoleWinApi_IsNaN(x)) {
		ConsoleWinApi_WriteStr((CHAR*)"NaN", 4);
	} else {
		if (x < (REAL)0) {
			ConsoleWinApi_WriteCh('-');
			x = -x;
		}
		e = __ASHR(ConsoleWinApi_Exponent(x) * 77, 8, INTEGER) - 12;
		if (e >= 0) {
			x = x / (REAL)ConsoleWinApi_Ten(e);
		} else if (e < -308) {
			x = (x * ConsoleWinApi_Ten(-e - 12)) * (REAL)1000000000000LL;
		} else {
			x = ConsoleWinApi_Ten(-e) * x;
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
		ConsoleWinApi_WriteCh(d[i]);
		ConsoleWinApi_WriteCh('.');
		while (i > 0) {
			i -= 1;
			ConsoleWinApi_WriteCh(d[i]);
		}
		e += 12;
		if (e != 0) {
			ConsoleWinApi_WriteCh('E');
			if (e > 0) {
				ConsoleWinApi_WriteCh('+');
			}
			ConsoleWinApi_WriteInt(e);
		}
	}
}

/*----------------------------------------------------------------------------*/
void ConsoleWinApi_WriteRealFix (REAL x, INTEGER n)
{
	LONGINT m;
	if (x == (REAL)0) {
		ConsoleWinApi_WriteCh('0');
	} else {
		if (n < 1 || n > 16) {
			n = 16;
		}
		if (x < (REAL)0) {
			x = -x;
			ConsoleWinApi_WriteCh('-');
		}
		m = __ENTIERL(x);
		ConsoleWinApi_WriteLong(m);
		ConsoleWinApi_WriteCh('.');
		x = ConsoleWinApi_Ten(n) * (x - (REAL)m);
		m = __ENTIERL(x + 0.5);
		while (m != 0 && __MOD(m, 10) == 0) {
			m = __DIV(m, 10);
		}
		ConsoleWinApi_WriteLong(m);
	}
}

/*----------------------------------------------------------------------------*/

export void *ConsoleWinApi__init (void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(Strings__init);
	__IMPORT(WinApi__init);
	__REGMOD("ConsoleWinApi", 0);
	__REGCMD("WriteLn", ConsoleWinApi_WriteLn);
/* BEGIN */
	ConsoleWinApi_hConOutput = GetStdHandle(-11);
	__ENDMOD;
}
