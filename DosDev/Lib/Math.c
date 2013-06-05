#include "SYSTEM.h"
#include "Math.h"

export REAL Math_ArcTan (REAL x);
export REAL Math_Cos (REAL x);
export REAL Math_Exp (REAL x);
export REAL Math_Ln (REAL x);
export REAL Math_Sin (REAL x);
export REAL Math_Sqrt (REAL x);
export INTEGER Math_RndRange (INTEGER rangeMin, INTEGER rangeMax);

void Math_NextRnd (void);
void Math_PutSeed (LONGINT seed);

#include <math.h>
#include <stdlib.h>

#define Math_rand()	rand()
#define Math_randomize()	randomize()

extern LONGINT Math_z;
/*================================== Header ==================================*/
#define Math_sin(x)	(sin(x))

REAL Math_Sin (REAL x)
{
	return Math_sin(x);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Math_cos(x)	(cos(x))

REAL Math_Cos (REAL x)
{
	return Math_cos(x);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Math_arctan(x)	(atan(x))

REAL Math_ArcTan (REAL x)
{
	return Math_arctan(x);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Math_exp(x)	(exp(x))

REAL Math_Exp (REAL x)
{
	return Math_exp(x);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Math_sqrt(x)	(sqrt(x))

REAL Math_Sqrt (REAL x)
{
	return Math_sqrt(x);
}

/*--------------------------------- Cut here ---------------------------------*/
#define Math_ln(x)	(log(x))

REAL Math_Ln (REAL x)
{
	return Math_ln(x);
}

/*--------------------------------- Cut here ---------------------------------*/
LONGINT Math_z;
/*--------------------------------- Cut here ---------------------------------*/

void Math_PutSeed (LONGINT seed)
{
	seed = (int)__MOD(seed, 2147483647);
	if (seed == 0) {
		Math_z = 1;
	} else {
		Math_z = seed;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void Math_NextRnd (void)
{
	LONGINT lo, hi, test;
	hi = __DIV(Math_z, 127773);
	lo = (int)__MOD(Math_z, 127773);
	test = 16807 * lo - 2836 * hi;
	if (test > 0) {
		Math_z = test;
	} else {
		Math_z = test + 2147483647;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
INTEGER Math_RndRange (INTEGER rangeMin, INTEGER rangeMax)
{
	__ASSERT(rangeMin <= rangeMax, 0);
	Math_NextRnd();
	return (int)__MODF(Math_z + Math_rand(), (rangeMax - rangeMin) + 1) + rangeMin;
}

/*--------------------------------- Cut here ---------------------------------*/
void Math_Randomize (void)
{
  Math_randomize();
	Math_PutSeed(Math_rand());
}

/*--------------------------------- Cut here ---------------------------------*/
export void Math (void)
{
	Math_z = 1;
	Math_Randomize();
}

