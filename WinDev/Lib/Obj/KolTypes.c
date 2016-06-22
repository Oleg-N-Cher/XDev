/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "WinApi.h"

typedef
	SYSTEM_PTR (*KolTypes_ANYPTR)[1];

typedef
	CHAR *KolTypes_AnsiString;

typedef
	CHAR *KolTypes_KOLString;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *KolTypes_PKOLChar;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *KolTypes_PKOLString;




export void KolTypes_IntToString (LONGINT x, CHAR *s, LONGINT s__len);
export void KolTypes_StringToInt (CHAR *s, LONGINT s__len, INTEGER *x, INTEGER *res);

#define KolTypes__init()	/*-noinit*/

/*============================================================================*/

void KolTypes_IntToString (LONGINT x, CHAR *s, LONGINT s__len)
{
	INTEGER j, k;
	CHAR ch;
	CHAR a[32];
	if (x != (-2147483647-1)) {
		if (x < 0) {
			s[0] = '-';
			k = 1;
			x = -x;
		} else {
			k = 0;
		}
		j = 0;
		do {
			a[__X(j, 32)] = (CHAR)(__MOD(x, 10) + 48);
			x = __DIV(x, 10);
			j += 1;
		} while (!(x == 0));
	} else {
		__MOVE("8085774586302733229", a, 20);
		s[0] = '-';
		k = 1;
		j = 0;
		while (a[__X(j, 32)] != 0x00) {
			j += 1;
		}
	}
	__ASSERT((LONGINT)(k + j) < s__len, 23);
	do {
		j -= 1;
		ch = a[__X(j, 32)];
		s[__X(k, s__len)] = ch;
		k += 1;
	} while (!(j == 0));
	s[__X(k, s__len)] = 0x00;
}

/*----------------------------------------------------------------------------*/
void KolTypes_StringToInt (CHAR *s, LONGINT s__len, INTEGER *x, INTEGER *res)
{
	INTEGER i, j, k, digits;
	CHAR ch, top;
	BOOLEAN neg;
	INTEGER base;
	*res = 0;
	i = 0;
	ch = s[0];
	while (((ch != 0x00 && ch <= ' ' || ch == 0x8b) || ch == 0x8f) || ch == 0xa0) {
		i += 1;
		ch = s[__X(i, s__len)];
	}
	j = i;
	top = '0';
	while (((ch != 0x00 && ch != 'H') && ch != 'X') && ch != '%') {
		if (ch > top) {
			top = ch;
		}
		j += 1;
		ch = s[__X(j, s__len)];
	}
	if (ch == 'H' || ch == 'X') {
		*x = 0;
		ch = s[__X(i, s__len)];
		if ('0' <= ch && ch <= '9' || 'A' <= ch && ch <= 'F') {
			while (ch == '0') {
				i += 1;
				ch = s[__X(i, s__len)];
			}
			digits = 0;
			while (*res == 0 && ('0' <= ch && ch <= '9' || 'A' <= ch && ch <= 'F')) {
				if (ch < 'A') {
					k = (int)ch - 48;
				} else {
					k = ((int)ch - 65) + 10;
				}
				if (digits < 8) {
					*x = __MASK(*x, -268435456);
					if (*x >= 134217728) {
						*x = *x - 268435456;
					}
					*x = __ASHL(*x, 4) + k;
					i += 1;
					ch = s[__X(i, s__len)];
				} else {
					*res = 1;
				}
				digits += 1;
			}
			if (*res == 0) {
				if (ch != 'H' && ch != 'X' || s[__X(i + 1, s__len)] != 0x00) {
					*res = 2;
				}
			}
		} else {
			*res = 2;
		}
	} else {
		if (ch == '%') {
			j += 1;
			ch = s[__X(j, s__len)];
			base = 0;
			if ('0' <= ch && ch <= '9') {
				k = (int)ch - 48;
				do {
					base = base * 10 + k;
					j += 1;
					ch = s[__X(j, s__len)];
					k = (int)ch - 48;
				} while (!((ch < '0' || ch > '9') || base > __DIV(2147483647 - k, 10)));
				if ('0' <= ch && ch <= '9') {
					base = 0;
				}
			}
		} else {
			base = 10;
		}
		if (base < 2 || base > 16) {
			*res = 2;
		} else if (base <= 10 && (int)top < base + 48 || base > 10 && (int)top < (base - 10) + 65) {
			*x = 0;
			ch = s[__X(i, s__len)];
			neg = 0;
			if (ch == '-') {
				i += 1;
				ch = s[__X(i, s__len)];
				neg = 1;
			} else if (ch == '+') {
				i += 1;
				ch = s[__X(i, s__len)];
			}
			while (ch != 0x00 && ch <= ' ') {
				i += 1;
				ch = s[__X(i, s__len)];
			}
			if ('0' <= ch && ch <= '9' || 'A' <= ch && ch <= 'F') {
				if (ch <= '9') {
					k = (int)ch - 48;
				} else {
					k = ((int)ch - 65) + 10;
				}
				while (('0' <= ch && ch <= '9' || 'A' <= ch && ch <= 'F') && *res == 0) {
					if (*x >= __DIV(((-2147483647-1) + (base - 1)) + k, base)) {
						*x = *x * base - k;
						i += 1;
						ch = s[__X(i, s__len)];
						if (ch <= '9') {
							k = (int)ch - 48;
						} else {
							k = ((int)ch - 65) + 10;
						}
					} else {
						*res = 1;
					}
				}
			} else {
				*res = 2;
			}
			if (*res == 0) {
				if (!neg) {
					if (*x > (-2147483647-1)) {
						*x = -*x;
					} else {
						*res = 1;
					}
				}
				if (ch != 0x00 && ch != '%') {
					*res = 2;
				}
			}
		} else {
			*res = 2;
		}
	}
}

/*----------------------------------------------------------------------------*/

export void *KolTypes__init(void)
{
	__DEFMOD;
	__IMPORT(WinApi__init);
	__REGMOD("KolTypes", 0);
/* BEGIN */
	__ENDMOD;
}
