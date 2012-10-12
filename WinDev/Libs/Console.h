#ifndef __Console_h
#define __Console_h

#include "../Mod/ConsoleCfg.h"

#ifdef OUTPUT_STDIO

  #include <stdio.h>

  #define Console_SetColors(colors) /* */
  #define Console_WriteStr(str)     printf("%s", str)

#endif OUTPUT_STDIO

#ifdef OUTPUT_CONIO

  #include <conio.h>

  #define Console_SetColors(colors) /* */
  #define Console_WriteStr(str)     _cputs(str)

#endif OUTPUT_CONIO

#ifdef OUTPUT_WINAPI

  #include <windows.h>

  #define Console_SetColors(colors) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors)
  #define Console_WriteStr Console_WriteStr_WinAPI

#endif OUTPUT_WINAPI


#define WriteStr  Console_WriteStr
#define SetColors Console_SetColors

#endif __Console_h
