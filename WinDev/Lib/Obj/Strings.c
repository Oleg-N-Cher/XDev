/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *Strings_PtrSTR;




export void Strings_IntToStr (LONGINT n, CHAR *str, LONGINT str__len);
export void Strings_IntToStrForm (LONGINT x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len);
export INTEGER Strings_Length (CHAR *str, LONGINT str__len);

#define Strings__init()	/*-noinit*/
#include <stdio.h>
#define Strings_sprintf(str, str__len, n)	sprintf(str, "%ld", n)
#define Strings_sprintfL(str, str__len, n)	sprintf(str, "%lld", n)

/*============================================================================*/

INTEGER Strings_Length (CHAR *str, LONGINT str__len)
{
	INTEGER len;
	len = 0;
	while (len < (int)str__len && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}

/*----------------------------------------------------------------------------*/
void Strings_IntToStr (LONGINT n, CHAR *str, LONGINT str__len)
{
	Strings_sprintfL(str, str__len, n);
}

/*----------------------------------------------------------------------------*/
void Strings_IntToStrForm (LONGINT x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len)
{
	INTEGER base, i, j, k, si;
	BOOLEAN mSign;
	CHAR a[128];
	CHAR c1, c5, c10;
	CHAR digits[17];
	__MOVE("0123456789ABCDEF", digits, 17);
	__ASSERT(((form == -1 || form == -2) || form == -3) || form >= 2 && form <= 16, 20);
	__ASSERT(minWidth >= 0, 22);
	if (form == -1) {
		base = 16;
	} else if (form == -2) {
		base = 16;
	} else {
		base = form;
	}
	if (form == -3) {
		__ASSERT(x > 0 && x < 3999, 21);
		base = 1000;
		i = 0;
		mSign = 0;
		while (base > 0 && x > 0) {
			if (base == 1) {
				c1 = 'I';
				c5 = 'V';
				c10 = 'X';
			} else if (base == 10) {
				c1 = 'X';
				c5 = 'L';
				c10 = 'C';
			} else if (base == 100) {
				c1 = 'C';
				c5 = 'D';
				c10 = 'M';
			} else {
				c1 = 'M';
			}
			k = (int)__DIV(x, (LONGINT)base);
			x = __MOD(x, (LONGINT)base);
			if (__IN(k, 0x0210)) {
				a[__X(i, 128)] = c1;
				i += 1;
			}
			if (__IN(k, 0x01f0)) {
				a[__X(i, 128)] = c5;
				i += 1;
			}
			if (k == 9) {
				a[__X(i, 128)] = c10;
				i += 1;
			} else if (__IN(k, 0x01ce)) {
				j = (int)__MOD(k, 5);
				do {
					a[__X(i, 128)] = c1;
					i += 1;
					j -= 1;
				} while (!(j == 0));
			}
			base = __DIV(base, 10);
		}
	} else if (form == -2 || form == -1) {
		i = 0;
		mSign = 0;
		if (showBase) {
			minWidth -= 1;
		}
		do {
			a[__X(i, 128)] = digits[__X(__MOD(x, (LONGINT)base), 17)];
			x = __DIV(x, (LONGINT)base);
			i += 1;
		} while (!((x == 0 || x == -1) || i == 128));
		if (x == -1) {
			fillCh = 'F';
		}
	} else {
		if (x < 0) {
			i = 0;
			mSign = 1;
			minWidth -= 1;
			do {
				if (__MOD(x, (LONGINT)base) == 0) {
					a[__X(i, 128)] = digits[0];
					x = __DIV(x, (LONGINT)base);
				} else {
					a[__X(i, 128)] = digits[__X((LONGINT)base - __MOD(x, (LONGINT)base), 17)];
					x = __DIV(x, (LONGINT)base) + 1;
				}
				i += 1;
			} while (!(x == 0 || i == 128));
		} else {
			i = 0;
			mSign = 0;
			do {
				a[__X(i, 128)] = digits[__X(__MOD(x, (LONGINT)base), 17)];
				x = __DIV(x, (LONGINT)base);
				i += 1;
			} while (!(x == 0 || i == 128));
		}
		if (showBase) {
			minWidth -= 1;
			if (base < 10) {
				minWidth -= 1;
			} else {
				minWidth -= 2;
			}
		}
	}
	si = 0;
	if ((mSign && fillCh == '0') && (LONGINT)si < s__len) {
		s[__X(si, s__len)] = '-';
		si += 1;
		mSign = 0;
	}
	while (minWidth > i) {
		if ((LONGINT)si < s__len) {
			s[__X(si, s__len)] = fillCh;
			si += 1;
		}
		minWidth -= 1;
	}
	if (mSign && (LONGINT)si < s__len) {
		s[__X(si, s__len)] = '-';
		si += 1;
	}
	if (form == -3) {
		j = 0;
		while (j < i) {
			if ((LONGINT)si < s__len) {
				s[__X(si, s__len)] = a[__X(j, 128)];
				si += 1;
			}
			j += 1;
		}
	} else {
		do {
			i -= 1;
			if ((LONGINT)si < s__len) {
				s[__X(si, s__len)] = a[__X(i, 128)];
				si += 1;
			}
		} while (!(i == 0));
	}
	if (showBase && form != -3) {
		if (form == -1 && (LONGINT)si < s__len) {
			s[__X(si, s__len)] = 'X';
			si += 1;
		} else if (form == -2 && (LONGINT)si < s__len) {
			s[__X(si, s__len)] = 'H';
			si += 1;
		} else if (form < 10 && (LONGINT)si < s__len - 1) {
			s[__X(si, s__len)] = '%';
			s[__X(si + 1, s__len)] = digits[__X(base, 17)];
			si += 2;
		} else if ((LONGINT)si < s__len - 2) {
			s[__X(si, s__len)] = '%';
			s[__X(si + 1, s__len)] = digits[__X(__DIV(base, 10), 17)];
			s[__X(si + 2, s__len)] = digits[__X((int)__MOD(base, 10), 17)];
			si += 3;
		}
	}
	if ((LONGINT)si < s__len) {
		s[__X(si, s__len)] = 0x00;
	} else {
		__HALT(23);
	}
}

/*----------------------------------------------------------------------------*/

export void *Strings__init(void)
{
	__DEFMOD;
	__REGMOD("Strings", 0);
/* BEGIN */
	__ENDMOD;
}
