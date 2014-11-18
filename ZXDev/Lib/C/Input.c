/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"


export SHORTINT Input_Available (void);
export CHAR Input_Read (void);

/*================================== Header ==================================*/
SHORTINT Input_Available (void)
{
__asm
  LD   IY,#0x5C3A
  CALL 0x28E
  LD   L,#0
  INC  E
  JR   Z,RETURN$
  INC  L
RETURN$:
__endasm;
}
/*
  LD   IY,#0x5C3A
  RES  5,1(IY)
  CALL 0x386E
  LD   L,#0
  BIT  5,1(IY)
  JR   NZ,RETURN$
  INC  L
RETURN$:
*/

/*--------------------------------- Cut here ---------------------------------*/
/*
http://zxpress.ru/book_articles.php?id=1395
*/
CHAR Input_Read (void)
{
__asm
  LD   IY,#0x5C3A
  ;EI
  ;RES  5,1(IY)
LOOP$:
  CALL 0x28E
  ;BIT  5,1(IY)
  INC  E
  JR   Z,LOOP$
  LD   L,-50(IY)
  ;DI
__endasm;
}
/*
  LD   IY,#0x5C3A
  EI
  RES  5,1(IY)
LOOP$:
  BIT  5,1(IY)
  JR   Z,LOOP$
  LD   L,-50(IY)
  DI
*/
