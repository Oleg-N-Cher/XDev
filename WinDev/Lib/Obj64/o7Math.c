/* Ofront+ 1.0 -sxtw7 -88 */
#include "SYSTEM.oh"




export SHORTREAL o7Math_Cos (SHORTREAL x);
export SHORTREAL o7Math_Exp (SHORTREAL x);
export SHORTREAL o7Math_Ln (SHORTREAL x);
export SHORTREAL o7Math_Sin (SHORTREAL x);
export SHORTREAL o7Math_Sqrt (SHORTREAL x);


/*============================================================================*/

SHORTREAL o7Math_Sqrt (SHORTREAL x)
{
  SHORTREAL s;
  INTEGER e;
  __ASSERT(x >= (SHORTREAL)0, 0, (CHAR*)"o7Math", -318);
  if (x > (SHORTREAL)0) {
    __UNPK(&x, &e);
    s = 0.5901620388031006 * (x + 0.7071068286895752);
    s = s + x / s;
    s = 0.25 * s + x / s;
    s = 0.5 * (s + x / s);
    if (__ODD(e)) {
      s = 1.414213538169861 * s;
    }
    __PACK(&s, __ASHR(e, 1, INTEGER));
  } else {
    s = (SHORTREAL)0;
  }
  return s;
}

/*----------------------------------------------------------------------------*/
SHORTREAL o7Math_Exp (SHORTREAL x)
{
  INTEGER n;
  SHORTREAL p, y, yy;
  y = 1.442695140838623 * x;
  n = (INTEGER)__ENTIER(y + 0.5);
  y = y - (SHORTREAL)n;
  yy = y * y;
  p = ((0.02309432066977024 * yy + 20.20170021057129) * yy + 1513.864135742188) * y;
  p = p / (SHORTREAL)(((yy + 233.1782379150391) * yy + 4368.0888671875) - p) + 0.5;
  __PACK(&p, n + 1);
  return p;
}

/*----------------------------------------------------------------------------*/
SHORTREAL o7Math_Ln (SHORTREAL x)
{
  INTEGER e;
  SHORTREAL xx, y;
  __ASSERT(x > (SHORTREAL)0, 0, (CHAR*)"o7Math", -1226);
  __UNPK(&x, &e);
  if (x < 0.7071068286895752) {
    x = x * (SHORTREAL)2;
    e = e - 1;
  }
  x = (x - (SHORTREAL)1) / (SHORTREAL)(x + (SHORTREAL)1);
  xx = x;
  y = 0.6931471824645996 * (SHORTREAL)e + (x * ((-18.32787132263184 * xx + 93.46389770507812) * xx + -90.17469024658203)) / (SHORTREAL)(((xx + -20.73348808288574) * xx + 67.61065673828125) * xx + -45.08734512329102);
  return y;
}

/*----------------------------------------------------------------------------*/
SHORTREAL o7Math_Sin (SHORTREAL x)
{
  INTEGER n;
  SHORTREAL y, yy, f;
  y = 0.6366197466850281 * x;
  if (y >= (SHORTREAL)0) {
    n = (INTEGER)__ENTIER(y + 0.5);
  } else {
    n = (INTEGER)__ENTIER(y - 0.5);
  }
  y = (y - (SHORTREAL)n) * (SHORTREAL)2;
  yy = y * y;
  if (__ODD(n)) {
    f = (((((1.136381266864106e-10 * yy + -2.460945758286925e-8) * yy + 3.590859023461235e-6) * yy + -3.259918885305524e-4) * yy + 0.01585434377193451) * yy + -0.3084251284599304) * yy + (SHORTREAL)1;
  } else {
    f = ((((((6.877100451607721e-12 * yy + -1.75714931494042e-9) * yy + 3.133616246486781e-7) * yy + -3.657620254671201e-5) * yy + 0.002490394515916705) * yy + -0.08074551075696945) * yy + 0.7853981852531433) * y;
  }
  if (__ODD(__ASHR(n, 1, INTEGER))) {
    f = -f;
  }
  return f;
}

/*----------------------------------------------------------------------------*/
SHORTREAL o7Math_Cos (SHORTREAL x)
{
  INTEGER n;
  SHORTREAL y, yy, f;
  y = 0.6366197466850281 * x;
  if (y >= (SHORTREAL)0) {
    n = (INTEGER)__ENTIER(y + 0.5);
  } else {
    n = (INTEGER)__ENTIER(y - 0.5);
  }
  y = (y - (SHORTREAL)n) * (SHORTREAL)2;
  yy = y * y;
  if (!__ODD(n)) {
    f = (((((1.136381266864106e-10 * yy + -2.460945758286925e-8) * yy + 3.590859023461235e-6) * yy + -3.259918885305524e-4) * yy + 0.01585434377193451) * yy + -0.3084251284599304) * yy + (SHORTREAL)1;
  } else {
    f = ((((((6.877100451607721e-12 * yy + -1.75714931494042e-9) * yy + 3.133616246486781e-7) * yy + -3.657620254671201e-5) * yy + 0.002490394515916705) * yy + -0.08074551075696945) * yy + 0.7853981852531433) * y;
  }
  if (__ODD(__ASHR(n + 1, 1, INTEGER))) {
    f = -f;
  }
  return f;
}

/*----------------------------------------------------------------------------*/
