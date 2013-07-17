/*  Ofront 1.2 -xtspkae */

#if defined(WIN32) || defined(_WIN32)
#  include <windows.h>
#endif

#include "Console.h"
#include "SYSTEM.h"

/* WinAPI */
#if defined(WIN32) || defined(_WIN32)
  export void Console_At_WinAPI (INTEGER x, INTEGER y);
  export void Console_SetColors_WinAPI (INTEGER colors);
  export void Console_WriteLn_WinAPI (void);
  export void Console_WriteStrLn_WinAPI (CHAR *str);
  export void Console_WriteStr_WinAPI (CHAR *str);
#endif

export void Console_WriteHex (INTEGER x);
export void Console_WriteIntWidth (INTEGER x, INTEGER n);

/* StdIO */
export void Console_WriteCh_StdIO (CHAR ch);
export void Console_WriteInt_StdIO (LONGINT n);
export void Console_WriteLn_StdIO (void);
export void Console_WriteStr_StdIO (CHAR *str);
export void Console_WriteStrLn_StdIO (CHAR *str);

/*================================== Header ==================================*/

/*
#include <stdio.h>
#define Console_writeLInt(n)	printf("%lld", n)
*/
export void Console_WriteInt_StdIO (LONGINT n)
{
  printf("%ld", n);
}

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteStr_StdIO (CHAR *str)
{
  printf("%s", str);
}

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteStrLn_StdIO (CHAR *str)
{
  printf("%s\n", str);
}

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteCh_StdIO (CHAR ch)
{
  printf("%c", ch);
}

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteLn_StdIO (void)
{
  printf("\n");
}

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  /* WinAPI */
  void Console_At_WinAPI (INTEGER x, INTEGER y) {
    COORD coord; coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  void Console_WriteLn_WinAPI (void) {
    printf("\n");
  }
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  void Console_WriteStr_WinAPI (CHAR *str) {
    INTEGER maxLen;
    HANDLE hConOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteFile(hConOutput, str, strlen(str), &maxLen, NULL);
  }
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  void Console_WriteStrLn_WinAPI (CHAR *str) {
    INTEGER maxLen;
    HANDLE hConOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteFile(hConOutput, str, strlen(str), &maxLen, NULL);
    str = "\x0D\x0A";
    WriteFile(hConOutput, str, 2, &maxLen, NULL);
  }
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  void Console_SetColors_WinAPI (INTEGER colors) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors);
  }
#endif

/*--------------------------------- Cut here ---------------------------------*/
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

/*--------------------------------- Cut here ---------------------------------*/
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


