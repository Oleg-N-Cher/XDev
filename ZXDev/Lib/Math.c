/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"


export REAL Math_ArcTan (REAL x);
export REAL Math_Cos (REAL x);
export REAL Math_Exp (REAL x);
export REAL Math_Ln (REAL x);
export REAL Math_Sin (REAL x);
export REAL Math_Sqrt (REAL x);

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

