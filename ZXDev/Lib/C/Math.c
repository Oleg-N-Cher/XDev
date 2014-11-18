/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"


export REAL Math_ArcTan (REAL x);
export REAL Math_Cos (REAL x);
export REAL Math_Exp (REAL x);
export REAL Math_Ln (REAL x);
export REAL Math_Sin (REAL x);
export REAL Math_Sqrt (REAL x);
export CARDINAL Math_RndRange (CARDINAL min, CARDINAL max);
export void Math_Randomize (void);

//#include <math.h>
extern float atanf (const float x);
extern float cosf (const float x);
extern float expf (const float x);
extern float logf (const float x);
extern float sinf (const float x);
extern float sqrtf (const float x);

#define Math_arctan(x)	(atanf(x))
#define Math_cos(x)	(cosf(x))
#define Math_exp(x)	(expf(x))
#define Math_ln(x)	(logf(x))
#define Math_sin(x)	(sinf(x))
#define Math_sqrt(x)	(sqrtf(x))

/*================================== Header ==================================*/
REAL Math_Sin (REAL x)
{
	return Math_sin(x);
}

/*--------------------------------- Cut here ---------------------------------*/
REAL Math_Cos (REAL x)
{
	return Math_cos(x);
}

/*--------------------------------- Cut here ---------------------------------*/
REAL Math_ArcTan (REAL x)
{
	return Math_arctan(x);
}

/*--------------------------------- Cut here ---------------------------------*/
REAL Math_Exp (REAL x)
{
	return Math_exp(x);
}

/*--------------------------------- Cut here ---------------------------------*/
REAL Math_Sqrt (REAL x)
{
	return Math_sqrt(x);
}

/*--------------------------------- Cut here ---------------------------------*/
REAL Math_Ln (REAL x)
{
	return Math_ln(x);
}
/*--------------------------------- Cut here ---------------------------------*/
/* SEED_RND address */
#define SF_RND$ 0x5C76

static CARDINAL __Math_RandBB (void) /* Ripped from Beta Basic */
{
__asm
  LD   D,#0
  LD   BC,(#SF_RND$)
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
  LD  (#SF_RND$),HL
__endasm;
} //__Math_RandBB

CARDINAL Math_RndRange (CARDINAL min, CARDINAL max)
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

