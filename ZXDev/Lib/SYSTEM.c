#include "SYSTEM.h"

/* runtime system routines */
export int SYSTEM_STRCMP (CHAR *x, CHAR *y);
export long SYSTEM_ENTIER (float x);
export SYSTEM_PTR SYSTEM_NEWBLK (CARDINAL size);

extern CHAR *SYSTEM_str_par;

#define SYSTEM_malloc(size)	(SYSTEM_PTR)malloc(size)

/*================================== Header ==================================*/
/* runtime system variables */
CHAR *SYSTEM_str_par;

/*--------------------------------- Cut here ---------------------------------*/
export int SYSTEM_STRCMP (CHAR *x, CHAR *y)
{long i = 0; CHAR ch1, ch2;
	do {ch1 = x[i]; ch2 = y[i]; i++;
		if (!ch1) return -(int)ch2;
	} while (ch1==ch2);
	return (int)ch1 - (int)ch2;
}

/*--------------------------------- Cut here ---------------------------------*/
export long SYSTEM_ENTIER (float x)
{
	if (x >= 0)
		return (long)x;
	else {
   	long y;
		y = (long)x;
		if (y <= x) return y; else return y - 1;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
float SYSTEM_ABSD (float i)
{
	return __ABS(i);
}

/*--------------------------------- Cut here ---------------------------------*/
SYSTEM_PTR SYSTEM_NEWBLK (CARDINAL size)
{
  SYSTEM_PTR new = SYSTEM_malloc(size);
  __ASSERT(new != NIL, 0xFF);
  return new;
}
