#include "SYSTEM.h"

/* WinAPI */
#if defined(WIN32) || defined(_WIN32)
  export void Console_At_WinAPI (INTEGER x, INTEGER y);
  export void Console_SetColors_WinAPI (INTEGER colors);
  export void Console_WriteBool_WinAPI (BOOLEAN b);
  export void Console_WriteCh_WinAPI (CHAR ch);
  export void Console_WriteLn_WinAPI (void);
  export void Console_WriteStrLn_WinAPI (CHAR *str);
  export void Console_WriteStr_WinAPI (CHAR *str);
  export void Console__init_WinAPI (void);
  extern SYSTEM_PTR __hConOutput;
#endif

/* StdIO */
export void Console_WriteBool_StdIO (BOOLEAN b);
export void Console_WriteCh_StdIO (CHAR ch);
export void Console_WriteInt_StdIO (LONGINT n);
export void Console_WriteReal_StdIO (REAL r);
export void Console_WriteLn_StdIO (void);
export void Console_WriteStr_StdIO (CHAR *str);
export void Console_WriteStrLn_StdIO (CHAR *str);
export void Console_WriteIntWidth_StdIO (INTEGER x, INTEGER n);
export void Console_WriteHex_StdIO (INTEGER val);

/*================================== Header ==================================*/

/*
#include <stdio.h>
#define Console_writeLInt(n)	printf("%lld", n)
*/
export void Console_WriteInt_StdIO (LONGINT n) {
  printf("%ld", n);
} //Console_WriteInt_StdIO

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteReal_StdIO (REAL r) {
  printf("%f", r);
} //Console_WriteReal_StdIO

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteStr_StdIO (CHAR *str) {
  printf("%s", str);
} //Console_WriteStr_StdIO

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteStrLn_StdIO (CHAR *str) {
  printf("%s\n", str);
} //Console_WriteStrLn_StdIO

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteBool_StdIO (BOOLEAN b) {
  if (b) printf("TRUE"); else printf("FALSE");
} //Console_WriteBool_StdIO

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteCh_StdIO (CHAR ch) {
  printf("%c", ch);
} //Console_WriteCh_StdIO

/*--------------------------------- Cut here ---------------------------------*/
export void Console_WriteLn_StdIO (void) {
  printf("\n");
} //Console_WriteLn_StdIO

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
#include <WinApi.h>
  /* WinAPI */
  void Console_At_WinAPI (INTEGER x, INTEGER y) {
    WinApi_COORD coord; coord.X = x; coord.Y = y;
    WinApi_SetConsoleCursorPosition(WinApi_GetStdHandle(-11), coord);
  } //Console_At_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  void Console_WriteLn_WinAPI (void) {
    INTEGER maxLen; CHAR *cr = "\x0D\x0A";
    WinApi_WriteFile(__hConOutput, cr, 2, &maxLen, NIL, NIL);
  } //Console_WriteLn_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
  void Console_WriteBool_WinAPI (BOOLEAN b) {
    if (b) Console_WriteStr_WinAPI("TRUE"); else Console_WriteStr_WinAPI("FALSE");
  } //Console_WriteBool_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
#include <WinApi.h>
  void Console_WriteCh_WinAPI (CHAR ch) {
    INTEGER maxLen;
    WinApi_WriteFile(__hConOutput, &ch, 1, &maxLen, NIL, NIL);
  } //Console_WriteCh_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
#include <WinApi.h>
  void Console_WriteStr_WinAPI (CHAR *str) {
    INTEGER maxLen;
    WinApi_WriteFile(__hConOutput, str, strlen(str), &maxLen, NIL, NIL);
  } //Console_WriteStr_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
#include <WinApi.h>
  void Console_WriteStrLn_WinAPI (CHAR *str) {
    Console_WriteStr_WinAPI(str); Console_WriteLn_WinAPI();
  } //Console_WriteStrLn_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
#include <WinApi.h>
  void Console_SetColors_WinAPI (INTEGER colors) {
    WinApi_SetConsoleTextAttribute(WinApi_GetStdHandle(-11), colors);
  } //Console_SetColors_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
#if defined(WIN32) || defined(_WIN32)
#include <WinApi.h>
  SYSTEM_PTR __hConOutput;

  void Console__init_WinAPI (void) {
    __hConOutput = WinApi_GetStdHandle(-11);
  } //Console__init_WinAPI
#endif

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteIntWidth_StdIO (INTEGER x, INTEGER n) {
	INTEGER i, x0;
	CHAR a[10];
	if (x < 0) {
		if (x == (-2147483647-1)) {
      printf("-2147483648");
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
		printf(" ");
		n -= 1;
	}
	if (x < 0) {
  printf("-");
	}
	do {
		i -= 1;
		printf("%c", a[__X(i, 10)]);
	} while (!(i == 0));
} //Console_WriteIntWidth_StdIO

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteHex_StdIO (INTEGER val) {
	INTEGER i, y;
	CHAR a[10];
	i = 0;
	do {
		y = __MASK(val, -16);
		if (y < 10) {
			a[__X(i, 10)] = (CHAR)(y + 48);
		} else {
			a[__X(i, 10)] = (CHAR)(y + 55);
		}
		val = __ASHR(val, 4);
		i += 1;
	} while (val != 0);
	do {
		i -= 1;
		printf("%c", a[__X(i, 10)]);
	} while (i != 0);
} //Console_WriteHex_StdIO

