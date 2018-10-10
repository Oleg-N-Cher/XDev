float Math_ArcTan (float x);
float Math_Cos (float x);
float Math_Exp (float x);
float Math_Ln (float x);
float Math_Sin (float x);
float Math_Sqrt (float x);
void Math_UIntToBCD (unsigned int n) __z88dk_fastcall;
unsigned int Math_RndRange (unsigned int min, unsigned int max);
void Math_Randomize (void);

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
float Math_Sin (float x)
{
	return Math_sin(x);
}

/*--------------------------------- Cut here ---------------------------------*/
float Math_Cos (float x)
{
	return Math_cos(x);
}

/*--------------------------------- Cut here ---------------------------------*/
float Math_ArcTan (float x)
{
	return Math_arctan(x);
}

/*--------------------------------- Cut here ---------------------------------*/
float Math_Exp (float x)
{
	return Math_exp(x);
}

/*--------------------------------- Cut here ---------------------------------*/
float Math_Sqrt (float x)
{
	return Math_sqrt(x);
}

/*--------------------------------- Cut here ---------------------------------*/
float Math_Ln (float x)
{
	return Math_ln(x);
}

/*--------------------------------- Cut here ---------------------------------*/
void Math_UIntToBCD (unsigned int n) __z88dk_fastcall { // bin(HL) -> bcd(E,H,L)
// Функция переводит 16-разрядное беззнаковое
// двоичное число в двоично-десятичный формат
// E,H,L = bin2bcd(hl)   ~1330 takts.
    __asm
        LD   BC, #0x1000
        LD   E, C
        LD   D, C
I2BCD$: ADD  HL, HL
        LD   A, E
        ADC  A, A
        DAA
        LD   E, A
        LD   A, D
        ADC  A, A
        DAA
        LD   D, A
        RL   C
        DJNZ I2BCD$     ; ~83   ~1328
        EX   DE, HL
        LD   E, C
__endasm;
} //Math_UIntToBCD

/*--------------------------------- Cut here ---------------------------------*/
/* SEED_RND address */
#define SF_RND$ 0x5C76

static unsigned int __Math_RandBB (void) /* Ripped from Beta Basic */
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
