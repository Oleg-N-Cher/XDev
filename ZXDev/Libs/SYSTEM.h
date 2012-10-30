#ifndef SYSTEM__h
#define SYSTEM__h

/* constants */
#define NIL	0L

/* basic types */
typedef unsigned char BOOLEAN;
typedef unsigned char CHAR;
typedef signed char SHORTINT;
typedef unsigned char SHORTCARD;
typedef signed int INTEGER;
typedef unsigned int CARDINAL;
typedef signed long LONGINT;
typedef unsigned long LONGCARD;
typedef float REAL;
typedef float LONGREAL;
typedef unsigned char SET;
typedef void *SYSTEM_PTR;
typedef unsigned int SYSTEM_ADDRESS;
typedef unsigned char SYSTEM_BYTE;

/* runtime system routines */
extern void SYSTEM_FINI();
#define SYSTEM_FINALL	exit(0)

/* module registry */
#define __DEFMOD	/* */
#define __REGMOD(name, enum)	/* */
#define __ENDMOD	/* */
#define __INIT(argc, argv)	static void *m; SYSTEM_INIT(argc, (long)&argv);
#define __REGMAIN(name, enum)	/* */
#define __FINI	SYSTEM_FINI(); return 0
#define __REGCMD(name, cmd)	/* */

/* SYSTEM ops */
#define __VAL(t, x)	(*(t*)&(x))
#define __GET(a, x, t)	x= *(t*)(a)
#define __PUT(a, x, t)	*(t*)(a)=x
#define __LSHL(x, n, t)	((t)((unsigned)(x)<<(n)))
#define __LSHR(x, n, t)	((t)((unsigned)(x)>>(n)))
#define __LSH(x, n, t)	((n)>=0? __LSHL(x, n, t): __LSHR(x, -(n), t))

#define __IMPORT(name)	/* */
#define export
#define import	extern
#define interface	/* */
#define implementation	/* */
#define RETURN return

#define __TDESC(t, m, n) \
	static struct t##__desc {\
		char name; \
		char base[1]; \
	} t##__desc
#define __TDFLDS(name, size) 0

#define __INITYP(t, t0, level)	/* */

/* std procs and operator mappings */
#define __ABS(x)	(((x)<0)?-(x):(x))
#define __ASHL(x, n)	((x)<<(n))
#define __ASHR(x, n)	((x)>>(n))
#define __DIV(x, y)	((x)>=0?(x)/(y):-(((y)-1-(x))/(y)))
#define __MOD(x, y)	((x)%(y))
#define __MASK(x, m)	((x)&~(m))
#define __ODD(x)	((x)&1)
#define __X(i, ub)	(i)
#define __IN(x, s)	(((s)>>(x))&1)

#define __ASSERT(cond, x) /* */
#define __CASECHK /* */
#define __COPY(s, d, n)	{char*_a=(void*)s,*_b=(void*)d;long _i=0,_t=n-1;while(_i<_t&&((_b[_i]=_a[_i])!=0)){_i++;};_b[_i]=0;}

/* runtime system variables */
extern LONGINT SYSTEM_argc;
extern LONGINT SYSTEM_argv; 

#endif
