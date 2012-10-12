#include "Console.h"
#include <string.h>
#include <windows.h>

/*================================== Header ==================================*/

/*
void Console_WriteCh (const char ch)
{
  printf("%c", ch);
}

void Console_WriteStr (const char *str)
{
  printf("%s", str);
}

void Console_WriteInt (const signed int num)
{
  printf("%u", num);
}

void Console_WriteCard (const unsigned int num)
{
  printf("%u", num);
}
*/

void Console_WriteStr_WinAPI (char *str)
{
  int maxLen;
  HANDLE hConOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  WriteFile(hConOutput, str, strlen(str), &maxLen, NULL);
}

/*--------------------------------- Cut here ---------------------------------*/
void Beeper (void)
{
  Beep(100, 100);
}


