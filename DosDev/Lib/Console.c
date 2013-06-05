/*  Ofront 1.2 -xtspkae */
#include "Console.h"
#include "SYSTEM.h"
#include <conio.h>

/* StdIO */
export void Console_At_StdIO (INTEGER x, INTEGER y);
export void Console_WriteCh_StdIO (CHAR ch);
export void Console_WriteInt_StdIO (LONGINT n);
export void Console_WriteLn_StdIO (void);
export void Console_WriteStr_StdIO (CHAR *str);
export void Console_WriteStrLn_StdIO (CHAR *str);

/* ConIO */
export void Console_At_ConIO (INTEGER x, INTEGER y);
export void Console_SetColors_ConIO (INTEGER colors);
export void Console_WriteCh_ConIO (CHAR ch);
export void Console_WriteInt_ConIO (LONGINT n);
export void Console_WriteLn_ConIO (void);
export void Console_WriteStr_ConIO (CHAR *str);
export void Console_WriteStrLn_ConIO (CHAR *str);

/* DIRECT */
export void Console_At_DIRECT (INTEGER x, INTEGER y);
export void Console_SetColors_DIRECT (INTEGER colors);
export void Console_WriteLn_DIRECT (void);
export void Console_WriteStrLn_DIRECT (CHAR *str);
export void Console_WriteStr_DIRECT (CHAR *str);
/*================================== Header ==================================*/

/*
#include <stdio.h>
#define Console_writeLInt(n)	printf("%lld", n)
*/

void Console_At_StdIO (INTEGER x, INTEGER y)
{
  gotoxy(x, y);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_SetColors_StdIO (INTEGER colors)
{
  textattr(colors);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_StdIO (LONGINT n)
{
  printf("%ld", n);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_StdIO (CHAR *str)
{
  printf("%s", str);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStrLn_StdIO (CHAR *str)
{
  printf("%s\n", str);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteCh_StdIO (CHAR ch)
{
  printf("%c", ch);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_StdIO (void)
{
  printf("\n");
}

/*--------------------------------- Cut here ---------------------------------*/

/* ConIO */

void Console_At_ConIO (INTEGER x, INTEGER y)
{
  gotoxy(x, y);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_SetColors_ConIO (INTEGER colors)
{
  textattr(colors);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_ConIO (LONGINT n)
{
  cprintf("%ld", n);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_ConIO (CHAR *str)
{
  cprintf("%s", str);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStrLn_ConIO (CHAR *str)
{
  cprintf("%s\n\r", str);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteCh_ConIO (CHAR ch)
{
  cprintf("%c", ch);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_ConIO (void)
{
  cprintf("\n\r");
}

/*--------------------------------- Cut here ---------------------------------*/

/* DIRECT */
void Console_At_DIRECT (INTEGER x, INTEGER y)
{
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_DIRECT (void)
{
  printf("\n");
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_DIRECT (CHAR *str)
{
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStrLn_DIRECT (CHAR *str)
{
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_SetColors_DIRECT (INTEGER colors)
{
}

