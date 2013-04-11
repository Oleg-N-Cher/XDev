/*  Ofront 1.2 -xtspkae */
#include <windows.h>
#include "Console.h"
#include "SYSTEM.h"

export void Console_WriteCh_StdIO (CHAR ch);
export void Console_WriteInt_StdIO (LONGINT n);
export void Console_WriteLn_StdIO (void);
export void Console_WriteStr_StdIO (CHAR *str);
export void Console_WriteStrLn_StdIO (CHAR *str);

/* WinAPI */
export void Console_At_WinAPI (INTEGER x, INTEGER y);
export void Console_SetColors_WinAPI (INTEGER colors);
export void Console_WriteLn_WinAPI (void);
export void Console_WriteStr_WinAPI (CHAR *str);
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

/* WinAPI */
void Console_At_WinAPI (INTEGER x, INTEGER y)
{
  COORD coord; coord.X = x; coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_WinAPI (void)
{
  printf("\n");
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_WinAPI (CHAR *str)
{
  INTEGER maxLen;
  HANDLE hConOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  WriteFile(hConOutput, str, strlen(str), &maxLen, NULL);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_SetColors_WinAPI (INTEGER colors)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors);
}

