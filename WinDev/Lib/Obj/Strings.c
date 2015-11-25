/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *Strings_PtrSTR;




export INTEGER Strings_Find (CHAR *str, LONGINT str__len, CHAR *pattern, LONGINT pattern__len, INTEGER start);
export void Strings_IntToStr (INTEGER n, CHAR *str, LONGINT str__len);
export void Strings_IntToStrForm (INTEGER x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len);
export void Strings_LIntToStr (LONGINT n, CHAR *str, LONGINT str__len);
export void Strings_LIntToStrForm (LONGINT x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len);
export INTEGER Strings_Length (CHAR *str, LONGINT str__len);
export BOOLEAN Strings_Utf8ToWin1251 (CHAR *s, LONGINT s__len, CHAR *res, LONGINT res__len);
export BOOLEAN Strings_Win1251ToUtf8 (CHAR *s, LONGINT s__len, CHAR *res, LONGINT res__len);

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
INTEGER Strings_Find (CHAR *str, LONGINT str__len, CHAR *pattern, LONGINT pattern__len, INTEGER start)
{
	INTEGER j, pos;
	if (start < 0) {
		start = 0;
	}
	if (start == 0 || start <= Strings_Length((void*)str, str__len) - Strings_Length((void*)pattern, pattern__len)) {
		pos = start;
		while (str[__X(pos, str__len)] != 0x00) {
			j = 0;
			while (str[__X(pos + j, str__len)] == pattern[__X(j, pattern__len)] && pattern[__X(j, pattern__len)] != 0x00) {
				j += 1;
			}
			if (pattern[__X(j, pattern__len)] == 0x00) {
				return pos;
			}
			pos += 1;
		}
	}
	return -1;
}

/*----------------------------------------------------------------------------*/
void Strings_IntToStr (INTEGER n, CHAR *str, LONGINT str__len)
{
	Strings_sprintf(str, str__len, n);
}

/*----------------------------------------------------------------------------*/
void Strings_LIntToStr (LONGINT n, CHAR *str, LONGINT str__len)
{
	Strings_sprintfL(str, str__len, n);
}

/*----------------------------------------------------------------------------*/
void Strings_IntToStrForm (INTEGER x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len)
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
			k = (int)__DIV(x, base);
			x = (int)__MOD(x, base);
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
			a[__X(i, 128)] = digits[__X((int)__MOD(x, base), 17)];
			x = __DIV(x, base);
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
				if ((int)__MOD(x, base) == 0) {
					a[__X(i, 128)] = digits[0];
					x = __DIV(x, base);
				} else {
					a[__X(i, 128)] = digits[__X(base - (int)__MOD(x, base), 17)];
					x = __DIV(x, base) + 1;
				}
				i += 1;
			} while (!(x == 0 || i == 128));
		} else {
			i = 0;
			mSign = 0;
			do {
				a[__X(i, 128)] = digits[__X((int)__MOD(x, base), 17)];
				x = __DIV(x, base);
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
void Strings_LIntToStrForm (LONGINT x, INTEGER form, INTEGER minWidth, CHAR fillCh, BOOLEAN showBase, CHAR *s, LONGINT s__len)
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
BOOLEAN Strings_Win1251ToUtf8 (CHAR *s, LONGINT s__len, CHAR *res, LONGINT res__len)
{
	INTEGER i, j, n, len;
	CHAR ch;
	CHAR utf8[3];
	INTEGER _for__9;
	i = 0;
	j = 0;
	while ((LONGINT)i < s__len && s[__X(i, s__len)] != 0x00) {
		len = 1;
		ch = s[__X(i, s__len)];
		if (ch >= 0x01 && ch <= 0x7f) {
			utf8[0] = s[__X(i, s__len)];
			len -= 1;
		} else if (ch >= 0xc0 && ch <= 0xef) {
			utf8[0] = 0xd0;
			utf8[1] = (CHAR)((int)ch - 48);
		} else if (ch >= 0xf0 && ch <= 0xff) {
			utf8[0] = 0xd1;
			utf8[1] = (CHAR)((int)ch - 112);
		} else {
			switch (ch) {
				case 0x80: 
					utf8[0] = 0xd0;
					utf8[1] = 0x82;
					break;
				case 0x81: 
					utf8[0] = 0xd0;
					utf8[1] = 0x83;
					break;
				case 0x82: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x9a;
					len += 1;
					break;
				case 0x83: 
					utf8[0] = 0xd1;
					utf8[1] = 0x93;
					break;
				case 0x84: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x9e;
					len += 1;
					break;
				case 0x85: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xa6;
					len += 1;
					break;
				case 0x86: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xa0;
					len += 1;
					break;
				case 0x87: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xa1;
					len += 1;
					break;
				case 0x88: 
					utf8[0] = 0xe2;
					utf8[1] = 0x82;
					utf8[2] = 0xac;
					len += 1;
					break;
				case 0x89: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xb0;
					len += 1;
					break;
				case 0x8a: 
					utf8[0] = 0xd0;
					utf8[1] = 0x89;
					break;
				case 0x8b: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xb9;
					len += 1;
					break;
				case 0x8c: 
					utf8[0] = 0xd0;
					utf8[1] = 0x8a;
					break;
				case 0x8d: 
					utf8[0] = 0xd0;
					utf8[1] = 0x8c;
					break;
				case 0x8e: 
					utf8[0] = 0xd0;
					utf8[1] = 0x8b;
					break;
				case 0x8f: 
					utf8[0] = 0xd0;
					utf8[1] = 0x8f;
					break;
				case 0x90: 
					utf8[0] = 0xd1;
					utf8[1] = 0x92;
					break;
				case 0x91: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x98;
					len += 1;
					break;
				case 0x92: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x99;
					len += 1;
					break;
				case 0x93: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x9c;
					len += 1;
					break;
				case 0x94: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x9d;
					len += 1;
					break;
				case 0x95: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xa2;
					len += 1;
					break;
				case 0x96: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x93;
					len += 1;
					break;
				case 0x97: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0x94;
					len += 1;
					break;
				case 0x98: 
					utf8[0] = 0xc2;
					utf8[1] = 0x98;
					break;
				case 0x99: 
					utf8[0] = 0xe2;
					utf8[1] = 0x84;
					utf8[2] = 0xa2;
					len += 1;
					break;
				case 0x9a: 
					utf8[0] = 0xd1;
					utf8[1] = 0x99;
					break;
				case 0x9b: 
					utf8[0] = 0xe2;
					utf8[1] = 0x80;
					utf8[2] = 0xba;
					len += 1;
					break;
				case 0x9c: 
					utf8[0] = 0xd1;
					utf8[1] = 0x9a;
					break;
				case 0x9d: 
					utf8[0] = 0xd1;
					utf8[1] = 0x9c;
					break;
				case 0x9e: 
					utf8[0] = 0xd1;
					utf8[1] = 0x9b;
					break;
				case 0x9f: 
					utf8[0] = 0xd1;
					utf8[1] = 0x9f;
					break;
				case 0xa0: 
					utf8[0] = 0xc2;
					utf8[1] = 0xa0;
					break;
				case 0xa1: 
					utf8[0] = 0xd0;
					utf8[1] = 0x8e;
					break;
				case 0xa2: 
					utf8[0] = 0xd1;
					utf8[1] = 0x9e;
					break;
				case 0xa3: 
					utf8[0] = 0xd0;
					utf8[1] = 0x88;
					break;
				case 0xa4: 
					utf8[0] = 0xc2;
					utf8[1] = 0xa4;
					break;
				case 0xa5: 
					utf8[0] = 0xd2;
					utf8[1] = 0x90;
					break;
				case 0xa6: 
					utf8[0] = 0xc2;
					utf8[1] = 0xa6;
					break;
				case 0xa7: 
					utf8[0] = 0xc2;
					utf8[1] = 0xa7;
					break;
				case 0xa8: 
					utf8[0] = 0xd0;
					utf8[1] = 0x81;
					break;
				case 0xa9: 
					utf8[0] = 0xc2;
					utf8[1] = 0xa9;
					break;
				case 0xaa: 
					utf8[0] = 0xd0;
					utf8[1] = 0x84;
					break;
				case 0xab: 
					utf8[0] = 0xc2;
					utf8[1] = 0xab;
					break;
				case 0xac: 
					utf8[0] = 0xc2;
					utf8[1] = 0xac;
					break;
				case 0xad: 
					utf8[0] = 0xc2;
					utf8[1] = 0xad;
					break;
				case 0xae: 
					utf8[0] = 0xc2;
					utf8[1] = 0xae;
					break;
				case 0xaf: 
					utf8[0] = 0xd0;
					utf8[1] = 0x87;
					break;
				case 0xb0: 
					utf8[0] = 0xc2;
					utf8[1] = 0xb0;
					break;
				case 0xb1: 
					utf8[0] = 0xc2;
					utf8[1] = 0xb1;
					break;
				case 0xb2: 
					utf8[0] = 0xd0;
					utf8[1] = 0x86;
					break;
				case 0xb3: 
					utf8[0] = 0xd1;
					utf8[1] = 0x96;
					break;
				case 0xb4: 
					utf8[0] = 0xd2;
					utf8[1] = 0x91;
					break;
				case 0xb5: 
					utf8[0] = 0xc2;
					utf8[1] = 0xb5;
					break;
				case 0xb6: 
					utf8[0] = 0xc2;
					utf8[1] = 0xb6;
					break;
				case 0xb7: 
					utf8[0] = 0xc2;
					utf8[1] = 0xb7;
					break;
				case 0xb8: 
					utf8[0] = 0xd1;
					utf8[1] = 0x91;
					break;
				case 0xb9: 
					utf8[0] = 0xe2;
					utf8[1] = 0x84;
					utf8[2] = 0x96;
					len += 1;
					break;
				case 0xba: 
					utf8[0] = 0xd1;
					utf8[1] = 0x94;
					break;
				case 0xbb: 
					utf8[0] = 0xc2;
					utf8[1] = 0xbb;
					break;
				case 0xbc: 
					utf8[0] = 0xd1;
					utf8[1] = 0x98;
					break;
				case 0xbd: 
					utf8[0] = 0xd0;
					utf8[1] = 0x85;
					break;
				case 0xbe: 
					utf8[0] = 0xd1;
					utf8[1] = 0x95;
					break;
				case 0xbf: 
					utf8[0] = 0xd1;
					utf8[1] = 0x97;
					break;
				default: 
					break;
			}
		}
		if ((LONGINT)((j + len) + 1) >= res__len) {
			res[__X(j, res__len)] = 0x00;
			return 0;
		}
		_for__9 = len;
		n = 0;
		while (n <= _for__9) {
			res[__X(j, res__len)] = utf8[__X(n, 3)];
			j += 1;
			n += 1;
		}
		i += 1;
	}
	res[__X(j, res__len)] = 0x00;
	return 1;
}

/*----------------------------------------------------------------------------*/
BOOLEAN Strings_Utf8ToWin1251 (CHAR *s, LONGINT s__len, CHAR *res, LONGINT res__len)
{
	INTEGER i, j;
	CHAR ch;
	i = 0;
	j = 0;
	while ((LONGINT)i < s__len && s[__X(i, s__len)] != 0x00) {
		if ((LONGINT)(j + 1) >= res__len) {
			res[__X(j, res__len)] = 0x00;
			return 0;
		}
		ch = s[__X(i, s__len)];
		if (ch >= 0x01 && ch <= 0x7f) {
			res[__X(j, res__len)] = ch;
		} else {
			switch (ch) {
				case 0xc2: 
					i += 1;
					res[__X(j, res__len)] = s[__X(i, s__len)];
					break;
				case 0xd0: 
					i += 1;
					ch = s[__X(i, s__len)];
					if (ch >= 0x90 && ch <= 0xbf) {
						res[__X(j, res__len)] = (CHAR)((int)ch + 48);
					} else {
						switch (ch) {
							case 0x81: 
								res[__X(j, res__len)] = 0xa8;
								break;
							case 0x82: 
								res[__X(j, res__len)] = 0x80;
								break;
							case 0x83: 
								res[__X(j, res__len)] = 0x81;
								break;
							case 0x84: 
								res[__X(j, res__len)] = 0xaa;
								break;
							case 0x85: 
								res[__X(j, res__len)] = 0xbd;
								break;
							case 0x86: 
								res[__X(j, res__len)] = 0xb2;
								break;
							case 0x87: 
								res[__X(j, res__len)] = 0xaf;
								break;
							case 0x88: 
								res[__X(j, res__len)] = 0xa3;
								break;
							case 0x89: 
								res[__X(j, res__len)] = 0x8a;
								break;
							case 0x8a: 
								res[__X(j, res__len)] = 0x8c;
								break;
							case 0x8b: 
								res[__X(j, res__len)] = 0x8e;
								break;
							case 0x8c: 
								res[__X(j, res__len)] = 0x8d;
								break;
							case 0x8e: 
								res[__X(j, res__len)] = 0xa1;
								break;
							case 0x8f: 
								res[__X(j, res__len)] = 0x8f;
								break;
							default: 
								res[__X(j, res__len)] = 0x00;
								return 0;
								break;
						}
					}
					break;
				case 0xd1: 
					i += 1;
					ch = s[__X(i, s__len)];
					if (ch >= 0x80 && ch <= 0x8f) {
						res[__X(j, res__len)] = (CHAR)((int)ch + 112);
					} else {
						switch (ch) {
							case 0x91: 
								res[__X(j, res__len)] = 0xb8;
								break;
							case 0x92: 
								res[__X(j, res__len)] = 0x90;
								break;
							case 0x93: 
								res[__X(j, res__len)] = 0x83;
								break;
							case 0x94: 
								res[__X(j, res__len)] = 0xba;
								break;
							case 0x95: 
								res[__X(j, res__len)] = 0xbe;
								break;
							case 0x96: 
								res[__X(j, res__len)] = 0xb3;
								break;
							case 0x97: 
								res[__X(j, res__len)] = 0xbf;
								break;
							case 0x98: 
								res[__X(j, res__len)] = 0xbc;
								break;
							case 0x99: 
								res[__X(j, res__len)] = 0x9a;
								break;
							case 0x9a: 
								res[__X(j, res__len)] = 0x9c;
								break;
							case 0x9b: 
								res[__X(j, res__len)] = 0x9e;
								break;
							case 0x9c: 
								res[__X(j, res__len)] = 0x9d;
								break;
							case 0x9e: 
								res[__X(j, res__len)] = 0xa2;
								break;
							case 0x9f: 
								res[__X(j, res__len)] = 0x9f;
								break;
							default: 
								res[__X(j, res__len)] = 0x00;
								return 0;
								break;
						}
					}
					break;
				case 0xd2: 
					i += 1;
					switch (s[__X(i, s__len)]) {
						case 0x90: 
							res[__X(j, res__len)] = 0xa5;
							break;
						case 0x91: 
							res[__X(j, res__len)] = 0xb4;
							break;
						default: 
							res[__X(j, res__len)] = 0x00;
							return 0;
							break;
					}
					break;
				case 0xe2: 
					i += 1;
					switch (s[__X(i, s__len)]) {
						case 0x80: 
							i += 1;
							switch (s[__X(i, s__len)]) {
								case 0x93: 
									res[__X(j, res__len)] = 0x96;
									break;
								case 0x94: 
									res[__X(j, res__len)] = 0x97;
									break;
								case 0x98: 
									res[__X(j, res__len)] = 0x91;
									break;
								case 0x99: 
									res[__X(j, res__len)] = 0x92;
									break;
								case 0x9a: 
									res[__X(j, res__len)] = 0x82;
									break;
								case 0x9c: 
									res[__X(j, res__len)] = 0x93;
									break;
								case 0x9d: 
									res[__X(j, res__len)] = 0x94;
									break;
								case 0x9e: 
									res[__X(j, res__len)] = 0x84;
									break;
								case 0xa0: 
									res[__X(j, res__len)] = 0x86;
									break;
								case 0xa1: 
									res[__X(j, res__len)] = 0x87;
									break;
								case 0xa2: 
									res[__X(j, res__len)] = 0x95;
									break;
								case 0xa6: 
									res[__X(j, res__len)] = 0x85;
									break;
								case 0xb0: 
									res[__X(j, res__len)] = 0x89;
									break;
								case 0xb9: 
									res[__X(j, res__len)] = 0x8b;
									break;
								case 0xba: 
									res[__X(j, res__len)] = 0x9b;
									break;
								default: 
									res[__X(j, res__len)] = 0x00;
									return 0;
									break;
							}
							break;
						case 0x82: 
							i += 1;
							res[__X(j, res__len)] = 0x88;
							break;
						case 0x84: 
							i += 1;
							switch (s[__X(i, s__len)]) {
								case 0x96: 
									res[__X(j, res__len)] = 0xb9;
									break;
								case 0xa2: 
									res[__X(j, res__len)] = 0x99;
									break;
								default: 
									res[__X(j, res__len)] = 0x00;
									return 0;
									break;
							}
							break;
						default: 
							res[__X(j, res__len)] = 0x00;
							return 0;
							break;
					}
					break;
				case 0x00: 
					res[__X(j, res__len)] = 0x00;
					return 1;
					break;
				default: 
					res[__X(j, res__len)] = 0x00;
					return 0;
					break;
			}
		}
		i += 1;
		j += 1;
	}
	res[__X(j, res__len)] = 0x00;
	return 1;
}

/*----------------------------------------------------------------------------*/

export void *Strings__init(void)
{
	__DEFMOD;
	__REGMOD("Strings", 0);
/* BEGIN */
	__ENDMOD;
}
