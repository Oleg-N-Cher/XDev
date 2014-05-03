/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

export void Timer_Delay_HALT_DI (INTEGER msec);
export void Timer_Delay_HALT_EI (INTEGER msec);
export void Timer_Delay_Ex (INTEGER msec);

/*================================== Header ==================================*/

void Timer_Delay_Ex (INTEGER msec)
{
  __asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
#else
  LD   E,4(IX)
  LD   D,5(IX)
#endif
DelayLoop$:
  LD   B,#205
Loop$:
  NOP
  DJNZ Loop$
  LD   A,E
  OR   D
  DEC  DE
  JR   NZ,DelayLoop$
  __endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Timer_Delay_HALT_DI (INTEGER msec)
{
  __asm
  LD   IY,#0x5C3A
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
#else
  LD   E,4(IX)
  LD   D,5(IX)
#endif
  EI
DelayLoopHaltDi$:
  HALT
  DEC  DE
  LD   A,E
  OR   D
  JR   NZ,DelayLoopHaltDi$
  DI
  __endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Timer_Delay_HALT_EI (INTEGER msec)
{
  __asm
  LD   IY,#0x5C3A
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
#else
  LD   E,4(IX)
  LD   D,5(IX)
#endif
  EI
DelayLoopHaltEi$:
  HALT
  DEC  DE
  LD   A,E
  OR   D
  JR   NZ,DelayLoopHaltEi$
  __endasm;
}
