/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export REAL Math_ArcTan (REAL x);
export REAL Math_Cos (REAL x);
export REAL Math_Exp (REAL x);
export REAL Math_Ln (REAL x);
export REAL Math_Sin (REAL x);
export REAL Math_Sqrt (REAL x);

#define Math_arctan(x)	(atan(x))
#define Math_cos(x)	(cos(x))
#define Math_exp(x)	(exp(x))
#include <math.h>
#define Math_ln(x)	(log(x))
#define Math_sin(x)	(sin(x))
#define Math_sqrt(x)	(sqrt(x))

REAL Math_Sin (REAL x)
{
	return Math_sin(x);
}

REAL Math_Cos (REAL x)
{
	return Math_cos(x);
}

REAL Math_ArcTan (REAL x)
{
	return Math_arctan(x);
}

REAL Math_Exp (REAL x)
{
	return Math_exp(x);
}

REAL Math_Sqrt (REAL x)
{
	return Math_sqrt(x);
}

REAL Math_Ln (REAL x)
{
	return Math_ln(x);
}


export void *Math__init(void)
{
	__DEFMOD;
	__REGMOD("Math", 0);
/* BEGIN */
	__ENDMOD;
}
