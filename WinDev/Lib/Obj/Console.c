/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Console_At (INTEGER x, INTEGER y);
export void Console_SetColors (INTEGER n);
export void Console_WriteCh (CHAR ch);
export void Console_WriteHex (INTEGER x);
export void Console_WriteInt (LONGINT n);
export void Console_WriteIntWidth (INTEGER x, INTEGER n);
export void Console_WriteLn (void);
export void Console_WriteStr (CHAR *str, LONGINT str__len);
export void Console_WriteStrLn (CHAR *str, LONGINT str__len);

#include <stdio.h>
#define Console_writeCh(ch)	printf("%c", ch)
#define Console_writeInt(n)	printf("%ld", n)
#define Console_writeLInt(n)	printf("%lld", n)
#define Console_writeLn()	printf("\n")
#define Console_writeStr(str, str__len)	printf("%s", str)
#define Console_writeStrLn(str, str__len)	printf("%s\n", str)

void Console_At (INTEGER x, INTEGER y)
{
}

void Console_WriteInt (LONGINT n)
{
	Console_writeInt(n);
}

void Console_WriteStr (CHAR *str, LONGINT str__len)
{
	Console_writeStr(str, str__len);
}

void Console_WriteStrLn (CHAR *str, LONGINT str__len)
{
	Console_writeStrLn(str, str__len);
}

void Console_WriteCh (CHAR ch)
{
	Console_writeCh(ch);
}

void Console_WriteLn (void)
{
	Console_writeLn();
}

void Console_WriteIntWidth (INTEGER x, INTEGER n)
{
	INTEGER i, x0;
	CHAR a[10];
	if (x < 0) {
		if (x == (-2147483647-1)) {
			Console_writeStr((CHAR*)"-2147483648", (LONGINT)12);
			return;
		}
		n -= 1;
		x0 = -x;
	} else {
		x0 = x;
	}
	i = 0;
	do {
		a[__X(i, 10)] = (CHAR)((int)__MOD(x0, 10) + 48);
		x0 = __DIV(x0, 10);
		i += 1;
	} while (!(x0 == 0));
	while (n > i) {
		Console_writeCh(' ');
		n -= 1;
	}
	if (x < 0) {
		Console_writeCh('-');
	}
	do {
		i -= 1;
		Console_writeCh(a[__X(i, 10)]);
	} while (!(i == 0));
}

void Console_WriteHex (INTEGER x)
{
	INTEGER i, y;
	CHAR a[10];
	i = 0;
	do {
		y = __MASK(x, -16);
		if (y < 10) {
			a[__X(i, 10)] = (CHAR)(y + 48);
		} else {
			a[__X(i, 10)] = (CHAR)(y + 55);
		}
		x = __ASHR(x, 4);
		i += 1;
	} while (!(i == 8));
	do {
		i -= 1;
		Console_writeCh(a[__X(i, 10)]);
	} while (!(i == 0));
}

void Console_SetColors (INTEGER n)
{
}


export void *Console__init(void)
{
	__DEFMOD;
	__REGMOD("Console", 0);
	__REGCMD("WriteLn", Console_WriteLn);
/* BEGIN */
	__ENDMOD;
}
