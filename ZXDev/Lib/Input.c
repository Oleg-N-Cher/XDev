/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export SHORTINT Input_Available (void);
export CHAR Input_Read (void);


SHORTINT Input_Available (void)
{
__asm
  LD   IY,#0x5C3A
  RES  5,1(IY)
  CALL 0x386E
  LD   L,#0
  BIT  5,1(IY)
  JR   NZ,RETURN$
  INC  L
RETURN$:
__endasm;
}

CHAR Input_Read (void)
{
__asm
  LD   IY,#0x5C3A
  EI
  RES  5,1(IY)
LOOP$:
  BIT  5,1(IY)
  JR   Z,LOOP$
  LD   L,-50(IY)
  DI
__endasm;
}

export void *Input__init(void)
{
	__DEFMOD;
	__REGMOD("Input", 0);
/* BEGIN */
	__ENDMOD;
}
