#include "system.h"

SYSTEM_MODDESC *SYSTEM_modlist;
SYSTEM_DLINK *SYSTEM_dlink;

LONGINT SYSTEM_INF = 0x7FF0000000000000L;
INTEGER SYSTEM_INFS = 0x7F800000;

_CHAR SYSTEM_strBuf[32][256];
INTEGER SYSTEM_actual;

void SYSTEM_REGMOD(SYSTEM_MODDESC *mod)
{
	int i;
	mod->next = SYSTEM_modlist;
	SYSTEM_modlist = mod;
	for (i = 0; i < mod->nofimps; i++) mod->imports[i]->refcnt++;
}

typedef struct {
	INTEGER gc[3], len[1];
} Array;

void *SYSTEM_NEWARR(INTEGER type, INTEGER n)
{
	int ptr = Kernel_NewArr(type, n, 1);
	((Array*)ptr)->len[0] = n;
	return (void*)ptr;
}

void *SYSTEM_NEWARR1(INTEGER type, INTEGER n0, INTEGER n)
{
	int ptr = Kernel_NewArr(type, n * n0, 1);
	((Array*)ptr)->len[0] = n0;
	return (void*)ptr;
}

void *SYSTEM_NEWARR2(INTEGER type, INTEGER n1, INTEGER n0, INTEGER n)
{
	int ptr = Kernel_NewArr(type, n * n0 * n1, 2);
	((Array*)ptr)->len[0] = n1;
	((Array*)ptr)->len[1] = n0;
	return (void*)ptr;
}

void *SYSTEM_NEWARR3(INTEGER type, INTEGER n2, INTEGER n1, INTEGER n0, INTEGER n)
{
	int ptr = Kernel_NewArr(type, n * n0 * n1 * n2, 3);
	((Array*)ptr)->len[0] = n2;
	((Array*)ptr)->len[1] = n1;
	((Array*)ptr)->len[2] = n0;
	return (void*)ptr;
}

void *SYSTEM_NEWARR4(INTEGER type, INTEGER n3, INTEGER n2, INTEGER n1, INTEGER n0, INTEGER n)
{
	int ptr = Kernel_NewArr(type, n * n0 * n1 * n2 * n3, 4);
	((Array*)ptr)->len[0] = n3;
	((Array*)ptr)->len[1] = n2;
	((Array*)ptr)->len[2] = n1;
	((Array*)ptr)->len[3] = n0;
	return (void*)ptr;
}

INTEGER SYSTEM_XCHK(INTEGER i, INTEGER ub)
{
	if ((unsigned)(i)>=(unsigned)(ub)) __HALT(-7);
	return i;
}


_CHAR* SYSTEM_LSTR(char *x)
{
	_CHAR *str = SYSTEM_strBuf[SYSTEM_actual];
	int i = 0;
	SYSTEM_actual = (SYSTEM_actual + 1) & 0x1F;
	do {
		if (i == 256) __HALT(-8);
		str[i] = x[i];
	} while (x[i++] != 0);
	return str;
}

INTEGER SYSTEM_ASH(INTEGER x, INTEGER y)
{
	if (y >= 0) return x << y;
	else return x >> (-y);
}

LONGINT SYSTEM_ASHL(LONGINT x, INTEGER y)
{
	if (y >= 0) return x << y;
	else return x >> (-y);
}

INTEGER SYSTEM_ABS(INTEGER x)
{
	if (x<0) x=-x;
	return x;
}

LONGINT SYSTEM_ABSL(LONGINT x)
{
	if (x<0) x=-x;
	return x;
}

SHORTREAL SYSTEM_ABSF(SHORTREAL x)
{
	if (x<0) x=-x;
	return x;
}

REAL SYSTEM_ABSD(REAL x)
{
	if (x<0) x=-x;
	return x;
}

INTEGER SYSTEM_ENTIER(REAL x)
{
	INTEGER i;
	i = (INTEGER)x;
	if (i > x) i--;
	return i;
}

LONGINT SYSTEM_ENTIERL(REAL x)
{
	LONGINT i;
	i = (LONGINT)x;
	if (i > x) i--;
	return i;
}

INTEGER SYSTEM_DIV(INTEGER x, INTEGER y)
{
	if (y > 0) {
		if (x < 0) return ~(~x / y);
		else return x / y;
	} else if (y < 0) {
		if (x > 0) return ~((x - 1) / -y);
		else return -x / -y;
	} else {
		__HALT(-5);
	}
}

LONGINT SYSTEM_DIVL(LONGINT x, LONGINT y)
{
	if (y > 0) {
		if (x < 0) return ~(~x / y);
		else return x / y;
	} else if (y < 0) {
		if (x > 0) return ~((x - 1) / -y);
		else return -x / -y;
	} else {
		__HALT(-5);
	}
}

INTEGER SYSTEM_MOD(INTEGER x, INTEGER y)
{
	if (y > 0) {
		if (x < 0) return y + ~(~x % y);
		else return x % y;
	} else if (y < 0) {
		if (x > 0) return y + 1 + ((x - 1) % -y);
		else return -(-x % -y);
	} else {
		__HALT(-5);
	}
}

LONGINT SYSTEM_MODL(LONGINT x, LONGINT y)
{
	if (y > 0) {
		if (x < 0) return y + ~(~x % y);
		else return x % y;
	} else if (y < 0) {
		if (x > 0) return y + 1 + ((x - 1) % -y);
		else return -(-x % -y);
	} else {
		__HALT(-5);
	}
}

INTEGER SYSTEM_MIN(INTEGER x, INTEGER y)
{
	if (x > y) x = y;
	return x;
}

LONGINT SYSTEM_MINL(LONGINT x, LONGINT y)
{
	if (x > y) x = y;
	return x;
}

SHORTREAL SYSTEM_MINF(SHORTREAL x, SHORTREAL y)
{
	if (x > y) x = y;
	return x;
}

REAL SYSTEM_MIND(REAL x, REAL y)
{
	if (x > y) x = y;
	return x;
}

INTEGER SYSTEM_MAX(INTEGER x, INTEGER y)
{
	if (x < y) x = y;
	return x;
}

LONGINT SYSTEM_MAXL(LONGINT x, LONGINT y)
{
	if (x < y) x = y;
	return x;
}

SHORTREAL SYSTEM_MAXF(SHORTREAL x, SHORTREAL y)
{
	if (x < y) x = y;
	return x;
}

REAL SYSTEM_MAXD(REAL x, REAL y)
{
	if (x < y) x = y;
	return x;
}


SHORTREAL SYSTEM_INT2SR(INTEGER x)
{
	return *(SHORTREAL*)&x;
}

REAL SYSTEM_LONG2R(LONGINT x)
{
	return *(REAL*)&x;
}

INTEGER SYSTEM_SR2INT(SHORTREAL x)
{
	return *(INTEGER*)&x;
}

LONGINT SYSTEM_R2LONG(REAL x)
{
	return *(LONGINT*)&x;
}




INTEGER SYSTEM_STRLEN(_CHAR x[])	/* LEN(lx$) */
{
	int i = 0;
	while (x[i] != 0) i++;
	return i;
}

INTEGER SYSTEM_STRLENS(SHORTCHAR x[])	/* LEN(sx$) */
{
	int i = 0;
	while (x[i] != 0) i++;
	return i;
}

INTEGER SYSTEM_STRCMPSS(SHORTCHAR x[], SHORTCHAR y[])	/* sx = sy */
{
	int i = 0;
	while (x[i] == y[i] && y[i] != 0) i++;
	return x[i] - y[i];
}

INTEGER SYSTEM_STRCMPTS(_CHAR x[], SHORTCHAR y[])	/* SHORT(lx) = sy */
{
	int i = 0;
	while ((x[i] & 0xff) == y[i] && y[i] != 0) i++;
	return (x[i] & 0xff) - y[i];
}

INTEGER SYSTEM_STRCMPTT(_CHAR x[], _CHAR y[])	/* SHORT(lx) = SHORT(ly) */
{
	int i = 0;
	while ((x[i] & 0xff) == (y[i] & 0xff) && (y[i] & 0xff) != 0) i++;
	return (x[i] & 0xff) - (y[i] & 0xff);
}

INTEGER SYSTEM_STRCMPLL(_CHAR x[], _CHAR y[])	/* lx = ly */
{
	int i = 0;
	while (x[i] == y[i] && y[i] != 0) i++;
	return x[i] - y[i];
}

INTEGER SYSTEM_STRCMPSL(SHORTCHAR x[], _CHAR y[])	/* LONG(sx) = ly */
{
	int i = 0;
	while (x[i] == y[i] && y[i] != 0) i++;
	return x[i] - y[i];
}

INTEGER SYSTEM_STRCMPTL(_CHAR x[], _CHAR y[])	/* LONG(SHORT(lx)) = ly */
{
	int i = 0;
	while ((x[i] & 0xff) == y[i] && y[i] != 0) i++;
	return (x[i] & 0xff) - y[i];
}

void SYSTEM_STRCOPYSS(SHORTCHAR x[], SHORTCHAR y[], INTEGER n)	/* sy := sx */
{
	int i = 0;
	do {
		if (n-- == 0) __HALT(-8);
		y[i] = x[i];
	} while (x[i++] != 0);
}

void SYSTEM_STRCOPYTS(_CHAR x[], SHORTCHAR y[], INTEGER n)	/* sy := SHORT(lx) */
{
	int i = 0;
	do {
		if (n-- == 0) __HALT(-8);
		y[i] = (SHORTCHAR)x[i];
	} while ((x[i++] & 0xff) != 0);
}

void SYSTEM_STRCOPYLL(_CHAR x[], _CHAR y[], INTEGER n)	/* ly := lx */
{
	int i = 0;
	do {
		if (n-- == 0) __HALT(-8);
		y[i] = x[i];
	} while (x[i++] != 0);
}

void SYSTEM_STRCOPYSL(SHORTCHAR x[], _CHAR y[], INTEGER n)	/* ly := LONG(sx) */
{
	int i = 0;
	do {
		if (n-- == 0) __HALT(-8);
		y[i] = x[i];
	} while (x[i++] != 0);
}

void SYSTEM_STRCOPYTL(_CHAR x[], _CHAR y[], INTEGER n)	/* ly := LONG(SHORT(lx)) */
{
	int i = 0;
	do {
		if (n-- == 0) __HALT(-8);
		y[i] = (x[i] & 0xff);
	} while ((x[i++] & 0xff) != 0);
}

void SYSTEM_STRAPNDSS(SHORTCHAR x[], SHORTCHAR y[], INTEGER n)	/* sy := sy + sx */
{
	int i = 0, j = 0;
	while (y[j] != 0) j++;
	do {
		if (n-- == 0) __HALT(-8);
		y[j++] = x[i];
	} while (x[i++] != 0);
}

void SYSTEM_STRAPNDTS(_CHAR x[], SHORTCHAR y[], INTEGER n)	/* sy := sy + SHORT(lx) */
{
	int i = 0, j = 0;
	while (y[j] != 0) j++;
	do {
		if (n-- == 0) __HALT(-8);
		y[j++] = (SHORTCHAR)x[i];
	} while ((x[i++] & 0xff) != 0);
}

void SYSTEM_STRAPNDLL(_CHAR x[], _CHAR y[], INTEGER n)	/* ly := ly + lx */
{
	int i = 0, j = 0;
	while (y[j] != 0) j++;
	do {
		if (n-- == 0) __HALT(-8);
		y[j++] = x[i];
	} while (x[i++] != 0);
}

void SYSTEM_STRAPNDSL(SHORTCHAR x[], _CHAR y[], INTEGER n)	/* ly := ly + LONG(sx) */
{
	int i = 0, j = 0;
	while (y[j] != 0) j++;
	do {
		if (n-- == 0) __HALT(-8);
		y[j++] = x[i];
	} while (x[i++] != 0);
}

void SYSTEM_STRAPNDTL(_CHAR x[], _CHAR y[], INTEGER n)	/* ly := ly + LONG(SHORT(lx)) */
{
	int i = 0, j = 0;
	while (y[j] != 0) j++;
	do {
		if (n-- == 0) __HALT(-8);
		y[j++] = (x[i] & 0xff);
	} while ((x[i++] & 0xff) != 0);
}

