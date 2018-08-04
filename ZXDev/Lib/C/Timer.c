void Timer_Delay_HALT_DI_stdcall (int msec);
void Timer_Delay_HALT_DI_fastcall (void /*DE*/);
void Timer_Delay_HALT_EI_stdcall (int msec);
void Timer_Delay_HALT_EI_fastcall (void /*DE*/);
void Timer_Delay_Ex_stdcall (int msec);
void Timer_Delay_Ex_fastcall (void /*DE*/);

/*================================== Header ==================================*/

void Timer_Delay_Ex_stdcall (int msec)
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
void Timer_Delay_Ex_fastcall (void /*DE*/)
{
  __asm
DelayLoopF$:
  LD   B,#205
LoopF$:
  NOP
  DJNZ LoopF$
  LD   A,E
  OR   D
  DEC  DE
  JR   NZ,DelayLoopF$
  __endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Timer_Delay_HALT_DI_stdcall (int msec)
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
void Timer_Delay_HALT_DI_fastcall (void /*DE*/)
{
  __asm
  LD   IY,#0x5C3A
  EI
DelayLoopHaltDiF$:
  HALT
  DEC  DE
  LD   A,E
  OR   D
  JR   NZ,DelayLoopHaltDiF$
  DI
  __endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
void Timer_Delay_HALT_EI_stdcall (int msec)
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

/*--------------------------------- Cut here ---------------------------------*/
void Timer_Delay_HALT_EI_fastcall (void /*DE*/)
{
  __asm
  LD   IY,#0x5C3A
  EI
DelayLoopHaltEiF$:
  HALT
  DEC  DE
  LD   A,E
  OR   D
  JR   NZ,DelayLoopHaltEiF$
  __endasm;
}
