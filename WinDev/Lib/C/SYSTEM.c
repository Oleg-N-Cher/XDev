/*
*	The body prefix file of the Ofront runtime system, Version 1.0
*
*	Copyright (c) Software Templ, 1994, 1995
*
*	Module SYSTEM is subject to change any time without prior notification.
*	Software Templ disclaims all warranties with regard to module SYSTEM,
*	in particular shall Software Templ not be liable for any damage resulting
*	from inappropriate use or modification of module SYSTEM.
*
*	Version 1.1  jt, 24.11.95  fixes for correct pointer arithmetic on Cray computers
*
*/

#include "SYSTEM.h"

/* runtime system routines */
extern void SYSTEM_INIT (int argc, long argvadr);
extern void* SYSTEM_MEMCPY (void* to, const void* from, SYSTEM_ADDRESS count);
extern long SYSTEM_XCHK(long i, long ub);
extern long SYSTEM_RCHK(long i, long ub);
extern long SYSTEM_ASH(long i, long n);
extern long SYSTEM_ABS(long i);
extern double SYSTEM_ABSD(double i);
extern long SYSTEM_MOD (unsigned long x, unsigned long y);
extern long SYSTEM_ENTIER (double x);
extern int SYSTEM_STRCMP (CHAR *x, CHAR *y);
extern void SYSTEM_ENUMR (char *adr, long *typ, long size, long n, void (*P)(void*));
export SYSTEM_PTR SYSTEM_NEWBLK (LONGINT size);

#define SYSTEM_malloc(size)	(SYSTEM_PTR)malloc(size)

/*================================== Header ==================================*/

/* runtime system variables */
LONGINT SYSTEM_argc;
LONGINT SYSTEM_argv;

//void SYSTEM_INIT (int argc, long argvadr)
//{
//  SYSTEM_argc = argc;
//  SYSTEM_argv = *(long*)argvadr;
//  //SYSTEM__init();
//}

/*--------------------------------- Cut here ---------------------------------*/
void* SYSTEM_MEMCPY (void* to, const void* from, SYSTEM_ADDRESS count) {
  char* dest = (char*)from;
  while(count--) *(char*)to++ = *dest++; return from;
} //SYSTEM_MEMCPY

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_XCHK(i, ub) long i, ub; {return __X(i, ub);}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_RCHK(i, ub) long i, ub; {return __R(i, ub);}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_ASH(i, n) long i, n; {return __ASH(i, n);}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_ABS(i) long i; {return __ABS(i);}

/*--------------------------------- Cut here ---------------------------------*/
double SYSTEM_ABSD(i) double i; {return __ABS(i);}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_MOD (unsigned long x, unsigned long y)
{ unsigned long m;
  if ((long) x >= 0) return (x % y);
  else { m = (-x) % y;
    if (m != 0) return (y - m); else return 0;
  }
}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_ENTIER (double x)
{
	long y;
	if (x >= 0)
		return (long)x;
	else {
		y = (long)x;
		if (y <= x) return y; else return y - 1;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
int SYSTEM_STRCMP (CHAR *x, CHAR *y)
{long i = 0; CHAR ch1, ch2;
  do {ch1 = x[i]; ch2 = y[i]; i++;
    if (!ch1) return -(int)ch2;
  } while (ch1==ch2);
  return (int)ch1 - (int)ch2;
}

/*--------------------------------- Cut here ---------------------------------*/
void SYSTEM_ENUMR (char *adr, long *typ, long size, long n, void (*P)(void*))
{
	long *t, off;
	typ++;
	while (n > 0) {
		t = typ;
		off = *t;
		while (off >= 0) {P((void*)*(long*)(adr+off)); t++; off = *t;}
		adr += size; n--;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
SYSTEM_PTR SYSTEM_NEWBLK (LONGINT size)
{
  SYSTEM_PTR mem = SYSTEM_malloc(size);
  __ASSERT(mem != NIL, 0xFF);
  return mem;
}

/*--------------------------------- Cut here ---------------------------------*/
SYSTEM_PTR SYSTEM_NEWREC (LONGINT tag)
{
  /*printf("tag=%d\n", tag);*/ return SYSTEM_NEWBLK(tag);
}

/*--------------------------------- Cut here ---------------------------------*/
/*
#define _DYNARRAY struct {
  LONGINT len[1]; // Length of allocated memory: LEN()
  CHAR data[1];   // Array data
} */
SYSTEM_PTR SYSTEM_NEWARR (LONGINT size)
{
  SYSTEM_PTR arrPtr = SYSTEM_NEWBLK(sizeof(LONGINT) + size);
  *((LONGINT*)arrPtr) = size;
  return arrPtr;
}

/*--------------------------------- Cut here ---------------------------------*/
#ifdef __STDC__
#  include "stdarg.h"
#else
#  include "varargs.h"
#endif

#define Lock
#define Unlock

#ifdef __STDC__
  SYSTEM_PTR SYSTEM_NEWARR2(long *typ, long elemsz, int elemalgn, int nofdim, int nofdyn, ...)
#else
  SYSTEM_PTR SYSTEM_NEWARR2(typ, elemsz, elemalgn, nofdim, nofdyn, va_alist)
    long *typ, elemsz;
    int elemalgn, nofdim, nofdyn;
    va_dcl
#endif
{
  long nofelems, size, dataoff, n, nptr, *x, *p, nofptrs, i, *ptab, off;
  va_list ap;
#ifdef __STDC__
  va_start(ap, nofdyn);
#else
  va_start(ap);
#endif
  nofelems = 1;
  while (nofdim > 0) {
    nofelems = nofelems * va_arg(ap, long); nofdim--;
    if (nofelems <= 0) __HALT(-20);
  }
  va_end(ap);
  dataoff = nofdyn * sizeof(long);
  if (elemalgn > sizeof(long)) {
    n = dataoff % elemalgn;
    if (n != 0) dataoff += elemalgn - n;
  }
  size = dataoff + nofelems * elemsz;
  Lock;
  if (typ == NIL) {
    /* element typ does not contain pointers */
    x = SYSTEM_NEWBLK(size);
  }
  else if (typ == POINTER__typ) {
    /* element type is a pointer */
    x = SYSTEM_NEWBLK(size + nofelems * sizeof(long));
    p = (long*)x[-1];
    p[-nofelems] = *p;	/* build new type desc in situ: 1. copy block size; 2. setup ptr tab; 3. set sentinel; 4. patch tag */
    p -= nofelems - 1; n = 1;	/* n =1 for skipping the size field */
    while (n <= nofelems) {*p = n*sizeof(long); p++; n++;}
    *p = - (nofelems + 1) * sizeof(long);	/* sentinel */
    x[-1] -= nofelems * sizeof(long);
  }
  else {
    /* element type is a record that contains pointers */
    ptab = typ + 1; nofptrs = 0;
    while (ptab[nofptrs] >= 0) {nofptrs++;}	/* number of pointers per element */
    nptr = nofelems * nofptrs;	/* total number of pointers */
    x = SYSTEM_NEWBLK(size + nptr * sizeof(long));
    p = (long*)x[- 1];
    p[-nptr] = *p;	/* build new type desc in situ; 1. copy block size; 2. setup ptr tab; 3. set sentinel; 4. patch tag */
    p -= nptr - 1; n = 0; off = dataoff;
    while (n < nofelems) {i = 0;
      while (i < nofptrs) {*p = off + ptab[i]; p++; i++;}
      off += elemsz; n++;
    }
    *p = - (nptr + 1) * sizeof(long);	/* sentinel */
    x[-1] -= nptr * sizeof(long);
  }
  if (nofdyn != 0) {
    /* setup len vector for index checks */
#ifdef __STDC__
    va_start(ap, nofdyn);
#else
    va_start(ap);
#endif
    p = x;
    while (nofdyn > 0) {*p = va_arg(ap, long); p++, nofdyn--;}
    va_end(ap);
  }
  Unlock;
  return x;
}

/* ----------- end of SYSTEM.co ------------- */
