extern unsigned int Math_RndRange (unsigned int min, unsigned int max);
extern void Math_Randomize (void);

/*================================== Header ==================================*/
static unsigned int __Math_RandBB (void) // Ripped from Beta Basic
{
__asm
  LD   D,#0
  LD   BC,(0x5C76) ; SEED_RND
  LD   H,C
  LD   L,#0xFD
  LD   A,B
  OR   A
  SBC  HL,BC
  SBC  A,D
  SBC  HL,BC
  SBC  A,D
  LD   E,A
  SBC  HL,DE
  JR   NC,R1$
  INC  HL
R1$:
  LD  (0x5C76),HL
__endasm;
} //__Math_RandBB

unsigned int Math_RndRange (unsigned int min, unsigned int max)
{
  return __Math_RandBB()%(max-min+1) + min;
} //Math_RndRange

/*--------------------------------- Cut here ---------------------------------*/
void Math_Randomize (void)
{
__asm
  LD   A,R
  ADD  (HL)
  ADC  B
  LD   B,A
  LD   A,(DE)
  ADC  C
  LD   C,A
  CALL #0x1E52
__endasm;
} //Math_Randomize
