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
#ifdef __STDC__
#  include "stdarg.h"
#else
#  include "varargs.h"
#endif

extern void exit (int status);

/* runtime system routines */
extern void SYSTEM_INIT (int argc, long argvadr);
extern void SYSTEM_HALT (int n);
extern long SYSTEM_MOD (unsigned long x, unsigned long y);
extern int SYSTEM_STRCMP (CHAR *x, CHAR *y);
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
long SYSTEM_MOD (unsigned long x, unsigned long y)
{ unsigned long m;
	if ((long) x >= 0) return (x % y);
	else { m = (-x) % y;
		if (m != 0) return (y - m); else return 0;
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
void SYSTEM_HALT (int n)
{
	exit(n);
}

//void SYSTEM_FINALL (void)
//{
  //exit(0);
//}

//void SYSTEM_FINI (void)
//{
  //SYSTEM_FINALL();
//}

/*--------------------------------- Cut here ---------------------------------*/
SYSTEM_PTR SYSTEM_NEWBLK (LONGINT size)
{
	SYSTEM_PTR new = SYSTEM_malloc(size);
  __ASSERT(new != NIL, 0xFF);
  return new;
}

/*--------------------------------- Cut here ---------------------------------*/
#define Lock
#define Unlock

#ifdef __STDC__
SYSTEM_PTR SYSTEM_NEWARR(long *typ, long elemsz, int elemalgn, int nofdim, int nofdyn, ...)
#else
SYSTEM_PTR SYSTEM_NEWARR(typ, elemsz, elemalgn, nofdim, nofdyn, va_alist)
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

