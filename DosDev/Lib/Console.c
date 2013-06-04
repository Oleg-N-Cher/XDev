/*  Ofront 1.2 -xtspkae */
#include "Console.h"
#include "SYSTEM.h"

export void Console_WriteCh_StdIO (CHAR ch);
export void Console_WriteInt_StdIO (LONGINT n);
export void Console_WriteLn_StdIO (void);
export void Console_WriteStr_StdIO (CHAR *str);
export void Console_WriteStrLn_StdIO (CHAR *str);

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

