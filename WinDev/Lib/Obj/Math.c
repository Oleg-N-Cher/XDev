/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"


static INTEGER Math_z;


export REAL Math_ArcTan (REAL x);
export REAL Math_Cos (REAL x);
export REAL Math_Exp (REAL x);
export REAL Math_Ln (REAL x);
static void Math_NextRnd (void);
static void Math_PutSeed (INTEGER seed);
export void Math_Randomize (void);
export INTEGER Math_RndRange (INTEGER rangeMin, INTEGER rangeMax);
export REAL Math_Sin (REAL x);
export REAL Math_Sqrt (REAL x);

#define Math_arctan(x)	(atan(x))
#define Math_cos(x)	(cos(x))
#define Math_exp(x)	(exp(x))
#define Math_getTickCount()	GetTickCount()
#include <math.h>
#include <windows.h>
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

static void Math_PutSeed (INTEGER seed)
{
	seed = (int)__MOD(seed, 2147483647);
	if (seed == 0) {
		Math_z = 1;
	} else {
		Math_z = seed;
	}
}

static void Math_NextRnd (void)
{
	INTEGER lo, hi, test;
	hi = __DIV(Math_z, 127773);
	lo = (int)__MOD(Math_z, 127773);
	test = 16807 * lo - 2836 * hi;
	if (test > 0) {
		Math_z = test;
	} else {
		Math_z = test + 2147483647;
	}
}

INTEGER Math_RndRange (INTEGER rangeMin, INTEGER rangeMax)
{
	__ASSERT(rangeMin <= rangeMax, 0);
	Math_NextRnd();
	return (int)__MODF(Math_z + Math_getTickCount(), (rangeMax - rangeMin) + 1) + rangeMin;
}

void Math_Randomize (void)
{
	Math_PutSeed(Math_getTickCount());
}


export void *Math__init(void)
{
	__DEFMOD;
	__REGMOD("Math", 0);
	__REGCMD("Randomize", Math_Randomize);
/* BEGIN */
	Math_z = 1;
	Math_Randomize();
	__ENDMOD;
}
