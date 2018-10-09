#include "SYSTEM.h"

/* runtime system routines */
void SYSTEM_HALT_m1 (unsigned char n) __z88dk_fastcall;
int SYSTEM_STRCMP (CHAR *x, CHAR *y);
void SYSTEM_STRCOPY (CHAR x[], CHAR y[], SHORTINT n);
long SYSTEM_ENTIER (float x);
SHORTINT SYSTEM_ASH (SHORTINT x, BYTE n);
INTEGER SYSTEM_ASHL (INTEGER x, BYTE n);
SYSTEM_PTR SYSTEM_NEWBLK (__U_SHORTINT size);

#define SYSTEM_malloc(size)	(SYSTEM_PTR)malloc(size)
/*================================== Header ==================================*/

void SYSTEM_HALT_m1 (unsigned char n) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  IM   1
  EI
  LD   (HALTCODE$),HL
  RST  8
HALTCODE$:
  .DB  0xFF ; Портит содержимое байта после этого, но он больше не нужен
__endasm;
} //SYSTEM_HALT_m1

/*--------------------------------- Cut here ---------------------------------*/
int SYSTEM_STRCMP (CHAR *x, CHAR *y)
{long i = 0; CHAR ch1, ch2;
	do {ch1 = x[i]; ch2 = y[i]; i++;
		if (!ch1) return -(int)ch2;
	} while (ch1==ch2);
	return (int)ch1 - (int)ch2;
}

/*--------------------------------- Cut here ---------------------------------*/
void SYSTEM_STRCOPY (CHAR x[], CHAR y[], SHORTINT n) { /* sy := sx */
  int i = 0; do { if (n-- == 0) __HALT(-8); y[i] = x[i]; } while (x[i++] != 0);
}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_ENTIER (float x)
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
SHORTINT SYSTEM_ASH (SHORTINT x, BYTE n)
{
	if (n >= 0) return x << n;
	return x >> (-n);
} //SYSTEM_ASH

/*--------------------------------- Cut here ---------------------------------*/
INTEGER SYSTEM_ASHL (INTEGER x, BYTE n)
{
	if (n >= 0) return x << n;
	return x >> (-n);
} //SYSTEM_ASHL

/*--------------------------------- Cut here ---------------------------------*/
float SYSTEM_ABSD (float i)
{
	return __ABS(i);
}

/*--------------------------------- Cut here ---------------------------------*/
SYSTEM_PTR SYSTEM_NEWBLK (__U_SHORTINT size)
{
  SYSTEM_PTR mem = SYSTEM_malloc(size);
//  __ASSERT(mem != NIL, 0xFF);
  return mem;
}

/*--------------------------------- Cut here ---------------------------------*/
/*
#define _DYNARRAY struct {
  SHORTINT len[1]; // Length of allocated memory: LEN()
  CHAR data[1];   // Array data
} */
SYSTEM_PTR SYSTEM_NEWARR (__U_SHORTINT size)
{
  SYSTEM_PTR arrPtr = SYSTEM_NEWBLK(sizeof(INTEGER) + size);
  *((SHORTINT*)arrPtr) = size;
  return arrPtr;
}

