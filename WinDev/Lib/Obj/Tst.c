/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Ignore.h"
#include "WinApi.h"

typedef
	CHAR *Tst_PtrSTR;


static SYSTEM_PTR Tst_hConOut;


export void Tst_Bool (CHAR *msg, LONGINT msg__len, BOOLEAN b);
export void Tst_Int (CHAR *msg, LONGINT msg__len, LONGINT i);
export void Tst_IntBox (LONGINT i);
static void Tst_IntToStr (LONGINT n, CHAR *str, LONGINT str__len);
export void Tst_Ptr (CHAR *msg, LONGINT msg__len, SYSTEM_PTR ptr);
export void Tst_Str (CHAR *msg, LONGINT msg__len);
static void Tst_WriteCh (CHAR ch);
export void Tst_WriteInt (LONGINT x);
export void Tst_WriteLn (void);
export void Tst_WriteStr (CHAR *str, LONGINT str__len);

#define Tst_sprintf(str, str__len, n)	sprintf(str, "%ld", n)
#define Tst_sprintfL(str, str__len, n)	sprintf(str, "%lld", n)

/*============================================================================*/

static void Tst_WriteCh (CHAR ch)
{
	INTEGER bytesWritten;
	Ignore_Int(WinApi_WriteFile(Tst_hConOut, (SYSTEM_PTR)((INTEGER)&ch), 1, &bytesWritten, NIL, NIL));
}

void Tst_WriteStr (CHAR *str, LONGINT str__len)
{
	INTEGER strLen, maxLen;
	strLen = 0;
	maxLen = (int)str__len;
	while (strLen < maxLen && str[__X(strLen, str__len)] != 0x00) {
		Tst_WriteCh(str[__X(strLen, str__len)]);
		strLen += 1;
	}
}

/*----------------------------------------------------------------------------*/
void Tst_WriteInt (LONGINT x)
{
	LONGINT n;
	CHAR buf[20];
	if (x < 0) {
		if (x == (-2147483647-1)) {
			Tst_WriteStr((void*)&"-9223372036854775808", (LONGINT)21);
			return;
		}
		Tst_WriteCh('-');
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
		Tst_WriteCh(buf[__X(n, 20)]);
	} while (!(n == 0));
}

/*----------------------------------------------------------------------------*/
void Tst_WriteLn (void)
{
	Tst_WriteCh(0x0d);
	Tst_WriteCh(0x0a);
}

/*----------------------------------------------------------------------------*/
void Tst_Int (CHAR *msg, LONGINT msg__len, LONGINT i)
{
	Tst_WriteStr((void*)msg, msg__len);
	Tst_WriteInt(i);
	Tst_WriteLn();
}

/*----------------------------------------------------------------------------*/
void Tst_Ptr (CHAR *msg, LONGINT msg__len, SYSTEM_PTR ptr)
{
	Tst_WriteStr((void*)msg, msg__len);
	Tst_WriteInt(__VAL(INTEGER, ptr));
	Tst_WriteLn();
}

/*----------------------------------------------------------------------------*/
void Tst_Bool (CHAR *msg, LONGINT msg__len, BOOLEAN b)
{
	Tst_WriteStr((void*)msg, msg__len);
	if (b) {
		Tst_WriteStr((void*)&"TRUE", (LONGINT)5);
	} else {
		Tst_WriteStr((void*)&"FALSE", (LONGINT)6);
	}
	Tst_WriteLn();
}

/*----------------------------------------------------------------------------*/
void Tst_Str (CHAR *msg, LONGINT msg__len)
{
	Tst_WriteStr((void*)msg, msg__len);
	Tst_WriteLn();
}

/*----------------------------------------------------------------------------*/
static void Tst_IntToStr (LONGINT n, CHAR *str, LONGINT str__len)
{
	Tst_sprintfL(str, str__len, n);
}

void Tst_IntBox (LONGINT i)
{
	CHAR str[21];
	Tst_IntToStr(i, (void*)str, 21);
	Ignore_Int(WinApi_MessageBox(NIL, (SYSTEM_PTR)((INTEGER)str), NIL, 0x0));
}

/*----------------------------------------------------------------------------*/
static void EnumPtrs(void (*P)(void*))
{
	P(Tst_hConOut);
}


export void *Tst__init(void)
{
	__DEFMOD;
	__IMPORT(Ignore__init);
	__IMPORT(WinApi__init);
	__REGMOD("Tst", EnumPtrs);
	__REGCMD("WriteLn", Tst_WriteLn);
/* BEGIN */
	if (0 == WinApi_AllocConsole()) {
	}
	Tst_hConOut = WinApi_GetStdHandle(-11);
	__ENDMOD;
}
