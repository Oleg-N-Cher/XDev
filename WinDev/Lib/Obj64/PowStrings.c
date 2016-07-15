/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *PowStrings_StringT;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *PowStrings_String;




export void PowStrings_Append (CHAR *dest, LONGINT dest__len, CHAR *src, LONGINT src__len);
export void PowStrings_AppendChar (CHAR *dest, LONGINT dest__len, CHAR ch);
export void PowStrings_Copy (CHAR *source, LONGINT source__len, CHAR *dest, LONGINT dest__len, LONGINT pos, LONGINT n);
export void PowStrings_Delete (CHAR *t, LONGINT t__len, LONGINT pos, LONGINT n);
export void PowStrings_HexStr (LONGINT x, CHAR *t, LONGINT t__len);
export void PowStrings_Insert (CHAR *source, LONGINT source__len, CHAR *dest, LONGINT dest__len, LONGINT pos);
export void PowStrings_InsertChar (CHAR x, CHAR *t, LONGINT t__len, LONGINT pos);
export void PowStrings_LeftAlign (CHAR *t, LONGINT t__len, LONGINT n);
export LONGINT PowStrings_Length (CHAR *t, LONGINT t__len);
export LONGINT PowStrings_Pos (CHAR *pattern, LONGINT pattern__len, CHAR *t, LONGINT t__len, LONGINT start);
export LONGINT PowStrings_PosChar (CHAR x, CHAR *t, LONGINT t__len, LONGINT start);
export void PowStrings_RemoveLeadingSpaces (CHAR *t, LONGINT t__len);
export void PowStrings_RemoveTrailingSpaces (CHAR *t, LONGINT t__len);
export void PowStrings_ReverseStringT (CHAR *t, LONGINT t__len, LONGINT n);
export void PowStrings_RightAlign (CHAR *t, LONGINT t__len, LONGINT n);
export void PowStrings_Str (LONGINT x, CHAR *t, LONGINT t__len);
export void PowStrings_UpCase (CHAR *t, LONGINT t__len);
export CHAR PowStrings_UpCaseChar (CHAR x);
export LONGINT PowStrings_Val (CHAR *t, LONGINT t__len);
export INTEGER PowStrings_ValResult (CHAR *t, LONGINT t__len);

#define PowStrings__init()	/*-noinit*/

/*============================================================================*/

LONGINT PowStrings_Length (CHAR *t, LONGINT t__len)
{
	LONGINT i, maxlen;
	maxlen = t__len;
	i = 0;
	while (i < maxlen && t[__X(i, t__len)] != 0x00) {
		i += 1;
	}
	return i;
}

/*----------------------------------------------------------------------------*/
LONGINT PowStrings_PosChar (CHAR x, CHAR *t, LONGINT t__len, LONGINT start)
{
	LONGINT maxl;
	if (start < 1) {
		start = 0;
	} else {
		start -= 1;
	}
	maxl = PowStrings_Length(t, t__len);
	while (start < maxl && t[__X(start, t__len)] != x) {
		start += 1;
	}
	if (start < maxl && t[__X(start, t__len)] == x) {
		return start + 1;
	} else {
		return 0;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
LONGINT PowStrings_Pos (CHAR *pattern, LONGINT pattern__len, CHAR *t, LONGINT t__len, LONGINT start)
{
	LONGINT i, j, maxl, patLen;
	if (start < 1) {
		start = 0;
	} else {
		start -= 1;
	}
	maxl = PowStrings_Length(t, t__len);
	patLen = PowStrings_Length(pattern, pattern__len);
	i = start;
	j = 0;
	while (j < patLen && i + j < maxl) {
		if (t[__X(i + j, t__len)] == pattern[__X(j, pattern__len)]) {
			j += 1;
		} else {
			j = 0;
			i += 1;
		}
	}
	if (j == patLen) {
		return i + 1;
	} else {
		return 0;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
void PowStrings_Copy (CHAR *source, LONGINT source__len, CHAR *dest, LONGINT dest__len, LONGINT pos, LONGINT n)
{
	LONGINT i, j, l1, l2;
	if (pos < 1) {
		dest[0] = 0x00;
		return;
	}
	l1 = (PowStrings_Length(source, source__len) - pos) + 1;
	if (l1 < 1) {
		dest[0] = 0x00;
		return;
	}
	l2 = dest__len - 1;
	if (l2 < l1) {
		l1 = l2;
	}
	if (n < l1) {
		l1 = n;
	}
	i = 0;
	j = pos - 1;
	while (i < l1) {
		dest[__X(i, dest__len)] = source[__X(j, source__len)];
		i += 1;
		j += 1;
	}
	dest[__X(i, dest__len)] = 0x00;
}

/*----------------------------------------------------------------------------*/
void PowStrings_Append (CHAR *dest, LONGINT dest__len, CHAR *src, LONGINT src__len)
{
	LONGINT i, j, lSrc, lDest;
	i = PowStrings_Length(dest, dest__len);
	j = 0;
	lDest = dest__len - 1;
	lSrc = src__len;
	while ((i < lDest && j < lSrc) && src[__X(j, src__len)] != 0x00) {
		dest[__X(i, dest__len)] = src[__X(j, src__len)];
		i += 1;
		j += 1;
	}
	dest[__X(i, dest__len)] = 0x00;
}

/*----------------------------------------------------------------------------*/
void PowStrings_AppendChar (CHAR *dest, LONGINT dest__len, CHAR ch)
{
	LONGINT l;
	l = PowStrings_Length(dest, dest__len);
	if (dest__len >= l + 2) {
		dest[__X(l, dest__len)] = ch;
		dest[__X(l + 1, dest__len)] = 0x00;
	}
}

/*----------------------------------------------------------------------------*/
CHAR PowStrings_UpCaseChar (CHAR x)
{
	switch (x) {
		case 'a': case 'b': case 'c': case 'd': case 'e': 
		case 'f': case 'g': case 'h': case 'i': case 'j': 
		case 'k': case 'l': case 'm': case 'n': case 'o': 
		case 'p': case 'q': case 'r': case 's': case 't': 
		case 'u': case 'v': case 'w': case 'x': case 'y': 
		case 'z': 
			x = (CHAR)(((INTEGER)x + 65) - 97);
			break;
		case 0xf6: 
			x = 0xd6;
			break;
		case 0xe4: 
			x = 0xc4;
			break;
		case 0xfc: 
			x = 0xdc;
			break;
		case 0xe1: 
			x = 0xc1;
			break;
		case 0xe9: 
			x = 0xc9;
			break;
		case 0xed: 
			x = 0xcd;
			break;
		case 0xf3: 
			x = 0xd3;
			break;
		case 0xfa: 
			x = 0xda;
			break;
		case 0xe0: 
			x = 0xc0;
			break;
		case 0xe8: 
			x = 0xc8;
			break;
		case 0xec: 
			x = 0xcc;
			break;
		case 0xf2: 
			x = 0xd2;
			break;
		case 0xf9: 
			x = 0xd9;
			break;
		case 0xe2: 
			x = 0xc2;
			break;
		case 0xea: 
			x = 0xca;
			break;
		case 0xee: 
			x = 0xce;
			break;
		case 0xf4: 
			x = 0xd4;
			break;
		case 0xfb: 
			x = 0xdb;
			break;
		default: 
			break;
	}
	return x;
}

/*----------------------------------------------------------------------------*/
void PowStrings_UpCase (CHAR *t, LONGINT t__len)
{
	LONGINT i, l;
	i = 0;
	l = t__len;
	while (i < l && t[__X(i, t__len)] != 0x00) {
		t[__X(i, t__len)] = PowStrings_UpCaseChar(t[__X(i, t__len)]);
		i += 1;
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_Delete (CHAR *t, LONGINT t__len, LONGINT pos, LONGINT n)
{
	LONGINT i, l, _for__5;
	l = PowStrings_Length(t, t__len);
	if ((n < 1 || pos < 1) || pos > l) {
		return;
	}
	if (n > (l - pos) + 1) {
		n = (l - pos) + 1;
	}
	_for__5 = l - n;
	i = pos - 1;
	while (i <= _for__5) {
		t[__X(i, t__len)] = t[__X(i + n, t__len)];
		i += 1;
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_ReverseStringT (CHAR *t, LONGINT t__len, LONGINT n)
{
	LONGINT a, b;
	CHAR x;
	a = 0;
	b = n - 1;
	while (a < b) {
		x = t[__X(a, t__len)];
		t[__X(a, t__len)] = t[__X(b, t__len)];
		t[__X(b, t__len)] = x;
		a += 1;
		b -= 1;
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_RemoveTrailingSpaces (CHAR *t, LONGINT t__len)
{
	LONGINT i;
	i = PowStrings_Length(t, t__len) - 1;
	while (i >= 0 && t[__X(i, t__len)] == ' ') {
		i -= 1;
	}
	t[__X(i + 1, t__len)] = 0x00;
}

/*----------------------------------------------------------------------------*/
void PowStrings_RemoveLeadingSpaces (CHAR *t, LONGINT t__len)
{
	LONGINT i, ml;
	i = 0;
	ml = t__len - 1;
	while (i < ml && t[__X(i, t__len)] == ' ') {
		i += 1;
	}
	if (i > 0) {
		PowStrings_Delete(t, t__len, 1, i);
	}
}

/*----------------------------------------------------------------------------*/
LONGINT PowStrings_Val (CHAR *t, LONGINT t__len)
{
	LONGINT inx, l, v, res;
	BOOLEAN hex, exit, neg;
	CHAR ch;
	__DUP(t, t__len, CHAR);
	PowStrings_RemoveTrailingSpaces(t, t__len);
	PowStrings_RemoveLeadingSpaces(t, t__len);
	l = PowStrings_Length(t, t__len);
	if (l < 1) {
		__DEL(t);
		return (-9223372036854775807-1);
	}
	hex = __CAP(t[__X(l - 1, t__len)]) == 'H';
	if (hex) {
		l -= 1;
		t[__X(l, t__len)] = 0x00;
		if (l < 1) {
			__DEL(t);
			return (-9223372036854775807-1);
		}
	}
	inx = 0;
	neg = 0;
	res = 0;
	if (t[0] == '+') {
		inx += 1;
	} else if (t[0] == '-') {
		inx += 1;
		neg = 1;
	}
	if (t[__X(l - 1, t__len)] == '+') {
		l -= 1;
	} else if (t[__X(l - 1, t__len)] == '-') {
		l -= 1;
		neg = 1;
	}
	exit = 0;
	if (hex) {
		if (neg) {
			while (inx < l && !exit) {
				ch = __CAP(t[__X(inx, t__len)]);
				if (ch >= '0' && ch <= '9') {
					v = (INTEGER)ch - 48;
				} else if (ch >= 'A' && ch <= 'F') {
					v = ((INTEGER)ch - 65) + 10;
				} else {
					v = -1;
				}
				if ((v < 0 || v > 15) || res < -576460752303423487) {
					exit = 1;
				} else {
					res = __ASHL(res, 4, LONGINT) - v;
					inx += 1;
				}
			}
		} else {
			while (inx < l && !exit) {
				ch = __CAP(t[__X(inx, t__len)]);
				if (ch >= '0' && ch <= '9') {
					v = (INTEGER)ch - 48;
				} else if (ch >= 'A' && ch <= 'F') {
					v = ((INTEGER)ch - 65) + 10;
				} else {
					v = -1;
				}
				if ((v < 0 || v > 15) || res > 576460752303423487) {
					exit = 1;
				} else {
					res = __ASHL(res, 4, LONGINT) + v;
					inx += 1;
				}
			}
		}
	} else {
		if (neg) {
			while (inx < l && !exit) {
				v = (INTEGER)t[__X(inx, t__len)] - 48;
				if (((v < 0 || v > 9) || res < -922337203685477580) || res == -922337203685477580 && v > 8) {
					exit = 1;
				} else {
					res = res * 10 - v;
					inx += 1;
				}
			}
		} else {
			while (inx < l && !exit) {
				v = (INTEGER)t[__X(inx, t__len)] - 48;
				if (((v < 0 || v > 9) || res > 922337203685477580) || res == 922337203685477580 && v > 7) {
					exit = 1;
				} else {
					res = res * 10 + v;
					inx += 1;
				}
			}
		}
	}
	if (exit) {
		__DEL(t);
		return (-9223372036854775807-1);
	} else {
		__DEL(t);
		return res;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
INTEGER PowStrings_ValResult (CHAR *t, LONGINT t__len)
{
	LONGINT inx, l, v, res;
	INTEGER h;
	BOOLEAN hex, exit, neg;
	CHAR ch;
	__DUP(t, t__len, CHAR);
	PowStrings_RemoveTrailingSpaces(t, t__len);
	PowStrings_RemoveLeadingSpaces(t, t__len);
	l = PowStrings_Length(t, t__len);
	if (l < 1) {
		__DEL(t);
		return 5;
	}
	hex = __CAP(t[__X(l - 1, t__len)]) == 'H';
	if (hex) {
		l -= 1;
		t[__X(l, t__len)] = 0x00;
		if (l < 1) {
			__DEL(t);
			return 5;
		}
	}
	inx = 0;
	neg = 0;
	res = 0;
	if (t[0] == '+') {
		inx += 1;
	} else if (t[0] == '-') {
		inx += 1;
		neg = 1;
	}
	if (t[__X(l - 1, t__len)] == '+') {
		l -= 1;
	} else if (t[__X(l - 1, t__len)] == '-') {
		l -= 1;
		neg = 1;
	}
	exit = 0;
	if (hex) {
		if (neg) {
			while (inx < l && !exit) {
				ch = __CAP(t[__X(inx, t__len)]);
				if (ch >= '0' && ch <= '9') {
					v = (INTEGER)ch - 48;
				} else if (ch >= 'A' && ch <= 'F') {
					v = ((INTEGER)ch - 65) + 10;
				} else {
					v = -1;
				}
				if (((v < 0 || v > 15) || res < -576460752303423488) || res == -576460752303423488 && v > 0) {
					exit = 1;
				} else {
					res = __ASHL(res, 4, LONGINT) - v;
					inx += 1;
				}
			}
		} else {
			while (inx < l && !exit) {
				ch = __CAP(t[__X(inx, t__len)]);
				if (ch >= '0' && ch <= '9') {
					v = (INTEGER)ch - 48;
				} else if (ch >= 'A' && ch <= 'F') {
					v = ((INTEGER)ch - 65) + 10;
				} else {
					v = -1;
				}
				if ((v < 0 || v > 15) || res > 576460752303423487) {
					exit = 1;
				} else {
					res = __ASHL(res, 4, LONGINT) + v;
					inx += 1;
				}
			}
		}
	} else {
		if (neg) {
			while (inx < l && !exit) {
				v = (INTEGER)t[__X(inx, t__len)] - 48;
				if (((v < 0 || v > 9) || res < -922337203685477580) || res == -922337203685477580 && v > 8) {
					exit = 1;
				} else {
					res = res * 10 - v;
					inx += 1;
				}
			}
		} else {
			while (inx < l && !exit) {
				v = (INTEGER)t[__X(inx, t__len)] - 48;
				if (((v < 0 || v > 9) || res > 922337203685477580) || res == 922337203685477580 && v > 7) {
					exit = 1;
				} else {
					res = res * 10 + v;
					inx += 1;
				}
			}
		}
	}
	if (exit) {
		if ((v < 0 || hex && v > 15) || !hex && v > 9) {
			__DEL(t);
			return 6;
		} else {
			__DEL(t);
			return 4;
		}
	} else {
		h = 3;
		if (res >= (-2147483647-1) && res <= 2147483647) {
			h -= 1;
		}
		if (res >= -32768 && res <= 32767) {
			h -= 1;
		}
		__DEL(t);
		return h;
	}
	__RETCHK;
}

/*----------------------------------------------------------------------------*/
void PowStrings_Str (LONGINT x, CHAR *t, LONGINT t__len)
{
	LONGINT i, maxlen;
	BOOLEAN neg;
	LONGINT _for__26, _for__25;
	maxlen = t__len - 1;
	if (maxlen < 1) {
		t[0] = 0x00;
		return;
	}
	if (x == 0) {
		t[0] = '0';
		t[__X(1, t__len)] = 0x00;
	} else {
		i = 0;
		neg = x < 0;
		if (neg) {
			if (x == (-9223372036854775807-1)) {
				__COPY("-2147483648", t, t__len);
				if (PowStrings_Length(t, t__len) != 11) {
					_for__26 = maxlen - 1;
					i = 0;
					while (i <= _for__26) {
						t[__X(i, t__len)] = '$';
						i += 1;
					}
					t[__X(maxlen, t__len)] = 0x00;
				}
				return;
			} else {
				x = -x;
			}
		}
		while (x != 0 && i < maxlen) {
			t[__X(i, t__len)] = (CHAR)(48 + __MOD(x, 10));
			x = __DIV(x, 10);
			i += 1;
		}
		if (x != 0 || neg && i >= maxlen) {
			_for__25 = maxlen - 1;
			i = 0;
			while (i <= _for__25) {
				t[__X(i, t__len)] = '$';
				i += 1;
			}
			t[__X(maxlen, t__len)] = 0x00;
		} else {
			if (neg) {
				t[__X(i, t__len)] = '-';
				i += 1;
			}
			t[__X(i, t__len)] = 0x00;
			PowStrings_ReverseStringT(t, t__len, i);
		}
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_HexStr (LONGINT x, CHAR *t, LONGINT t__len)
{
	LONGINT i, digit, maxlen;
	BOOLEAN neg;
	LONGINT _for__8, _for__7;
	maxlen = t__len - 1;
	if (maxlen < 2) {
		if (maxlen == 1) {
			t[0] = '$';
			t[__X(1, t__len)] = 0x00;
		} else {
			t[0] = 0x00;
		}
		return;
	}
	if (x == 0) {
		t[0] = '0';
		t[__X(1, t__len)] = 'h';
		t[__X(2, t__len)] = 0x00;
	} else {
		t[0] = 'h';
		i = 1;
		neg = x < 0;
		if (neg) {
			if (x == (-9223372036854775807-1)) {
				__COPY("-80000000h", t, t__len);
				if (PowStrings_Length(t, t__len) != 10) {
					_for__8 = maxlen - 1;
					i = 0;
					while (i <= _for__8) {
						t[__X(i, t__len)] = '$';
						i += 1;
					}
					t[__X(maxlen, t__len)] = 0x00;
				}
				return;
			} else {
				x = -x;
			}
		}
		while (x != 0 && i < maxlen) {
			digit = __MASK(x, -16);
			if (digit < 10) {
				t[__X(i, t__len)] = (CHAR)(48 + digit);
			} else {
				t[__X(i, t__len)] = (CHAR)(55 + digit);
			}
			x = __ASHR(x, 4, LONGINT);
			i += 1;
		}
		if (x != 0 || neg && i >= maxlen) {
			_for__7 = maxlen - 1;
			i = 0;
			while (i <= _for__7) {
				t[__X(i, t__len)] = '$';
				i += 1;
			}
			t[__X(maxlen, t__len)] = 0x00;
		} else {
			if (neg) {
				t[__X(i, t__len)] = '-';
				i += 1;
			}
			t[__X(i, t__len)] = 0x00;
			PowStrings_ReverseStringT(t, t__len, i);
		}
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_InsertChar (CHAR x, CHAR *t, LONGINT t__len, LONGINT pos)
{
	LONGINT i, l, _for__13;
	l = PowStrings_Length(t, t__len);
	if (l + 1 < t__len) {
		if (pos < 1) {
			pos = 1;
		} else if (pos > l + 1) {
			pos = l + 1;
		}
		_for__13 = pos - 1;
		i = l;
		while (i >= _for__13) {
			t[__X(i + 1, t__len)] = t[__X(i, t__len)];
			i += -1;
		}
		t[__X(pos - 1, t__len)] = x;
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_Insert (CHAR *source, LONGINT source__len, CHAR *dest, LONGINT dest__len, LONGINT pos)
{
	LONGINT i, l, dif, _for__11, _for__10;
	dif = PowStrings_Length(source, source__len);
	l = PowStrings_Length(dest, dest__len);
	if ((l + dif) + 1 > dest__len) {
		dif = (dest__len - l) - 1;
	}
	if (pos < 1) {
		pos = 1;
	} else if (pos > l + 1) {
		pos = l + 1;
	}
	_for__11 = pos - 1;
	i = l;
	while (i >= _for__11) {
		dest[__X(i + dif, dest__len)] = dest[__X(i, dest__len)];
		i += -1;
	}
	_for__10 = (pos - 2) + dif;
	i = pos - 1;
	while (i <= _for__10) {
		dest[__X(i, dest__len)] = source[__X((i + 1) - pos, source__len)];
		i += 1;
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_LeftAlign (CHAR *t, LONGINT t__len, LONGINT n)
{
	LONGINT l, i, maxlen, _for__15;
	maxlen = t__len;
	if (n + 1 > maxlen) {
		n = maxlen - 1;
	}
	l = PowStrings_Length(t, t__len);
	if (l <= n - 1) {
		_for__15 = n - 1;
		i = l;
		while (i <= _for__15) {
			t[__X(i, t__len)] = ' ';
			i += 1;
		}
		t[__X(n, t__len)] = 0x00;
	}
}

/*----------------------------------------------------------------------------*/
void PowStrings_RightAlign (CHAR *t, LONGINT t__len, LONGINT n)
{
	LONGINT l, i, maxlen, _for__23;
	maxlen = t__len;
	if (n + 1 > maxlen) {
		n = maxlen - 1;
	}
	l = PowStrings_Length(t, t__len);
	if (l < n) {
		t[__X(n, t__len)] = 0x00;
		n = n - l;
		i = l - 1;
		while (i >= 0) {
			t[__X(i + n, t__len)] = t[__X(i, t__len)];
			i += -1;
		}
		_for__23 = n - 1;
		i = 0;
		while (i <= _for__23) {
			t[__X(i, t__len)] = ' ';
			i += 1;
		}
	}
}

/*----------------------------------------------------------------------------*/

export void *PowStrings__init(void)
{
	__DEFMOD;
	__REGMOD("PowStrings", 0);
/* BEGIN */
	__ENDMOD;
}
