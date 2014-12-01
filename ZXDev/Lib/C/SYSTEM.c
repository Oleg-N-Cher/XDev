#include "SYSTEM.h"

/* runtime system routines */
export void SYSTEM_HALT_A (void /* Register A */);
export int SYSTEM_STRCMP (CHAR *x, CHAR *y);
export long SYSTEM_ENTIER (float x);
export SYSTEM_PTR SYSTEM_NEWBLK (CARDINAL size);

extern CHAR *SYSTEM_str_par;

#define SYSTEM_malloc(size)	(SYSTEM_PTR)malloc(size)

/*================================== Header ==================================*/
/* runtime system variables */
CHAR *SYSTEM_str_par;

/*--------------------------------- Cut here ---------------------------------*/
void SYSTEM_HALT_N (void) __naked {
__asm
  LD   HL,#0x2758
  EXX
  LD   IY,#0x5C3A
  IM   0
  EI
  JP   8
__endasm;
} //SYSTEM_HALT_N

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
  SYSTEM_PTR mem = SYSTEM_malloc(size);
//  __ASSERT(mem != NIL, 0xFF);
  return mem;
}

/*--------------------------------- Cut here ---------------------------------*/
/*
#define _DYNARRAY struct {
  LONGINT len[1]; // Length of allocated memory: LEN()
  CHAR data[1];   // Array data
} */
SYSTEM_PTR SYSTEM_NEWARR (CARDINAL size)
{
  SYSTEM_PTR arrPtr = SYSTEM_NEWBLK(sizeof(LONGINT) + size);
  *((LONGINT*)arrPtr) = size;
  return arrPtr;
}

