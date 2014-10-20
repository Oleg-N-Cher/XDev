/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "WinApi.h"

typedef
	CHAR *Debug_PtrSTR;


static SYSTEM_PTR Debug_hConOut;


export void Debug_Bool (CHAR *msg, LONGINT msg__len, BOOLEAN b);
export void Debug_Int (CHAR *msg, LONGINT msg__len, LONGINT i);
export void Debug_IntBox (LONGINT i);
static void Debug_IntToStr (LONGINT n, CHAR *str, LONGINT str__len);
export void Debug_Ptr (CHAR *msg, LONGINT msg__len, SYSTEM_PTR ptr);
export void Debug_Str (CHAR *msg, LONGINT msg__len);
static void Debug_WriteCh (CHAR ch);
export void Debug_WriteInt (LONGINT x);
export void Debug_WriteLn (void);
export void Debug_WriteStr (CHAR *str, LONGINT str__len);

#define Debug_sprintf(str, str__len, n)	sprintf(str, "%ld", n)
#define Debug_sprintfL(str, str__len, n)	sprintf(str, "%lld", n)

/*============================================================================*/

static void Debug_WriteCh (CHAR ch)
{
	INTEGER bytesWritten;
	Ignore_Int(WinApi_WriteFile(Debug_hConOut, (SYSTEM_PTR)((LONGINT)&ch), 1, &bytesWritten, NIL, NIL));
}

void Debug_WriteStr (CHAR *str, LONGINT str__len)
{
	INTEGER strLen, maxLen;
	strLen = 0;
	maxLen = (int)str__len;
	while (strLen < maxLen && str[__X(strLen, str__len)] != 0x00) {
		Debug_WriteCh(str[__X(strLen, str__len)]);
		strLen += 1;
	}
}

/*----------------------------------------------------------------------------*/
void Debug_WriteInt (LONGINT x)
{
	LONGINT n;
	CHAR buf[20];
	if (x < 0) {
		if (x == (-2147483647-1)) {
			Debug_WriteStr((void*)&"-9223372036854775808", (LONGINT)21);
			return;
		}
		Debug_WriteCh('-');
		x = -x;
	}
	n = 0;
	do {
		buf[__X(n, 20)] = (CHAR)(__MOD(x, 10) + 48);
		x = __DIV(x, 10);
		n += 1;
	} while (!(x == 0));
	do {
		n -= 1;
		Debug_WriteCh(buf[__X(n, 20)]);
	} while (!(n == 0));
}

/*----------------------------------------------------------------------------*/
void Debug_WriteLn (void)
{
	Debug_WriteCh(0x0d);
	Debug_WriteCh(0x0a);
}

/*----------------------------------------------------------------------------*/
void Debug_Int (CHAR *msg, LONGINT msg__len, LONGINT i)
{
	Debug_WriteStr((void*)msg, msg__len);
	Debug_WriteInt(i);
	Debug_WriteLn();
}

/*----------------------------------------------------------------------------*/
void Debug_Ptr (CHAR *msg, LONGINT msg__len, SYSTEM_PTR ptr)
{
	Debug_WriteStr((void*)msg, msg__len);
	Debug_WriteInt((LONGINT)ptr);
	Debug_WriteLn();
}

/*----------------------------------------------------------------------------*/
void Debug_Bool (CHAR *msg, LONGINT msg__len, BOOLEAN b)
{
	Debug_WriteStr((void*)msg, msg__len);
	if (b) {
		Debug_WriteStr((void*)&"TRUE", (LONGINT)5);
	} else {
		Debug_WriteStr((void*)&"FALSE", (LONGINT)6);
	}
	Debug_WriteLn();
}

/*----------------------------------------------------------------------------*/
void Debug_Str (CHAR *msg, LONGINT msg__len)
{
	Debug_WriteStr((void*)msg, msg__len);
	Debug_WriteLn();
}

/*----------------------------------------------------------------------------*/
static void Debug_IntToStr (LONGINT n, CHAR *str, LONGINT str__len)
{
	Debug_sprintfL(str, str__len, n);
}

void Debug_IntBox (LONGINT i)
{
	CHAR str[21];
	Debug_IntToStr(i, (void*)str, 21);
	Ignore_Int(WinApi_MessageBox(NIL, (SYSTEM_PTR)((LONGINT)str), NIL, 0x0));
}

/*----------------------------------------------------------------------------*/
static void EnumPtrs(void (*P)(void*))
{
	P(Debug_hConOut);
}


export void *Debug__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(WinApi__init);
	__REGMOD("Debug", EnumPtrs);
	__REGCMD("WriteLn", Debug_WriteLn);
/* BEGIN */
	if (0 == WinApi_AllocConsole()) {
	}
	Debug_hConOut = WinApi_GetStdHandle(-11);
	__ENDMOD;
}
