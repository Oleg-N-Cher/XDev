#ifndef SYSTEM__h
#define SYSTEM__h

/*

the Ofront runtime system interface and macros library
copyright (c) Josef Templ, 1995, 1996

gcc for Linux version (same as SPARC/Solaris2)
uses double # as concatenation operator

*/

#include "SYSTEM_Cfg.h"
#ifdef _SDLGUI
#  include "GrConfig.h"
  extern void GrApp_Init (void);
#endif

#define export
#define import extern

/* constants */
#define __MAXEXT	16
#define NIL	0L
#define POINTER__typ	(long*)1L	/* not NIL and not a valid type */

/* basic types */
typedef char BOOLEAN;
typedef unsigned char CHAR;
typedef short int SHORTINT;
typedef int INTEGER;
typedef long long LONGINT;
typedef float REAL;
typedef double LONGREAL;
typedef unsigned long SET;
typedef void *SYSTEM_PTR;
typedef signed char BYTE;
#if _WIN64 || __amd64__
  typedef unsigned long long SYSTEM_ADDRESS;
#else
  typedef unsigned int SYSTEM_ADDRESS;
#endif

/* runtime system routines */
void* SYSTEM_MEMCPY (void* to, const void* from, SYSTEM_ADDRESS count);
#ifdef SYSTEM_Cfg_KERNEL32
#  define __MEMCPY SYSTEM_MEMCPY
   __attribute__((dllimport)) void __attribute__((__stdcall__)) ExitProcess (int);
#  define SYSTEM_HALT ExitProcess
#else
#  define __MEMCPY memcpy
#  define SYSTEM_HALT exit
#endif

//extern void *memcpy (void *dest, const void *src, long n);
//extern void *malloc (long size);
//extern void exit (int status);

extern long SYSTEM_DIV();
extern long SYSTEM_MOD();
extern long SYSTEM_ENTIER();
extern long SYSTEM_ASH();
extern long SYSTEM_ABS();
extern long SYSTEM_XCHK();
extern long SYSTEM_RCHK();
extern double SYSTEM_ABSD();
extern int SYSTEM_STRCMP();
extern SYSTEM_PTR SYSTEM_NEWREC();
extern SYSTEM_PTR SYSTEM_NEWBLK();
#ifdef __STDC__
  extern SYSTEM_PTR SYSTEM_NEWARR (LONGINT);
#else
  extern SYSTEM_PTR SYSTEM_NEWARR();
#endif
extern SYSTEM_PTR SYSTEM_REGMOD();
#ifdef SYSTEM_Cfg_IncRef
  extern void SYSTEM_INCREF();
#else
  #define SYSTEM_INCREF(proc) proc
#endif
extern void SYSTEM_REGCMD();
extern void SYSTEM_REGTYP();
extern void SYSTEM_REGFIN();
//extern void SYSTEM_FINALL();
#define SYSTEM_FINALL()
//extern void SYSTEM_INIT();
//extern void SYSTEM_FINI();
#define SYSTEM_FINI()
//extern void SYSTEM_HALT (int n);
extern void SYSTEM_INHERIT();
extern void SYSTEM_ENUMP();
extern void SYSTEM_ENUMR (char *adr, long *typ, long size, long n, void (*P)(void*));

/* module registry */
#ifdef SYSTEM_Cfg_RegisterModules
#  define __DEFMOD	static void *m; if(m!=0)return m
#  define __REGMOD(name, enum)	if(m==0)m=SYSTEM_REGMOD((CHAR*)name,enum); else return m
#  define __ENDMOD	return m
#else
#  define __DEFMOD	static char m; if(m!=0)return
#  define __REGMOD(name, enum)	m=1
#  define __ENDMOD
#endif

#ifdef SYSTEM_Cfg_RegisterMain
#  ifdef _SDLGUI
#    define __INIT(argc, argv) static void *m; SYSTEM_argc=argc; \
       SYSTEM_argv=(SYSTEM_PTR)argv; GrConfig_Init; GrApp_Init()
#  else
#    define __INIT(argc, argv) static void *m; //SYSTEM_INIT(argc, (long)&argv)
#  endif
#  define __REGMAIN(name, enum)	m=SYSTEM_REGMOD(name,enum)
#else
#  ifdef _SDLGUI
#    define __INIT(argc, argv) SYSTEM_argc=argc; \
       SYSTEM_argv=(SYSTEM_PTR)argv; GrConfig_Init; GrApp_Init()
#  else
#    define __INIT(argc, argv) SYSTEM_argc=argc; SYSTEM_argv=(SYSTEM_PTR)argv
#  endif
#  define __REGMAIN(name, enum)
#endif

#define __FINI	SYSTEM_FINI(); return 0
#define __IMPORT(name__init)	SYSTEM_INCREF(name__init())
#ifdef SYSTEM_Cfg_RegisterCommands
  #define __REGCMD(name, cmd)	SYSTEM_REGCMD(m, name, cmd)
#else
  #define __REGCMD(name, cmd)
#endif

#ifdef DJGPP
#  define __EXTERN
#else
#  define __EXTERN __attribute__((dllimport))
#endif
#define __CALL_1 __attribute__((__stdcall__))

/* SYSTEM ops */
#define __SYSNEW(p, len)	p=SYSTEM_NEWBLK((long)(len))
#define __VAL(t, x)	(*(t*)&(x))
#define __GET(a, x, t)	x= *(t*)(a)
#define __PUT(a, x, t)	*(t*)(a)=x
#define __LSHL(x, n, t)	((t)((unsigned)(x)<<(n)))
#define __LSHR(x, n, t)	((t)((unsigned)(x)>>(n)))
#define __LSH(x, n, t)	((n)>=0? __LSHL(x, n, t): __LSHR(x, -(n), t))
#define __ROTL(x, n, t)	((t)((unsigned)(x)<<(n)|(unsigned)(x)>>(8*sizeof(t)-(n))))
#define __ROTR(x, n, t)	((t)((unsigned)(x)>>(n)|(unsigned)(x)<<(8*sizeof(t)-(n))))
#define __ROT(x, n, t)	((n)>=0? __ROTL(x, n, t): __ROTR(x, -(n), t))
#define __BIT(x, n)	(*(unsigned long*)(x)>>(n)&1)
#define __MOVE(s, d, n)	__MEMCPY((char*)(d),(char*)(s),n)

/* std procs and operator mappings */
#define __CONSTARR const
#define __CONSTARRLOC const
#define __SHORT(x, y)	((int)((unsigned long)(x)+(y)<(y)+(y)?(x):(__HALT(-8),0)))
#define __SHORTF(x, y)	((int)(__RF((x)+(y),(y)+(y))-(y)))
#define __CHR(x)	((CHAR)__R(x, 256))
#define __CHRF(x)	((CHAR)__RF(x, 256))
#define __DIV(x, y)	((x)>=0?(x)/(y):-(((y)-1-(x))/(y)))
#define __DIVF(x, y)	SYSTEM_DIV((long)(x),(long)(y))
#define __MOD(x, y)	((x)>=0?(x)%(y):__MODF(x,y))
#define __MODF(x, y)	SYSTEM_MOD((long)(x),(long)(y))

#ifdef SYSTEM_Cfg_NoGC
#  define __NEW(p, t)	p=SYSTEM_NEWBLK(sizeof(struct t))
#  define __NEWARR(typ, elemsz, elemalgn, nofdim, nofdyn, va_alist) \
	SYSTEM_NEWARR(elemalgn*va_alist);
#else
#  define __NEW(p, t)	p=SYSTEM_NEWREC((long)t##__typ)
#  define __NEWARR	SYSTEM_NEWARR
#endif

#define __HALT(x)	SYSTEM_HALT(x)
#ifndef SYSTEM_Cfg_NoASSERT
#  define __ASSERT(cond, x)	if (!(cond)) SYSTEM_HALT(x)
#else
#  define __ASSERT(cond, x)	if (cond) ;
#endif
#define __ENTIER(x)	SYSTEM_ENTIER(x)
#define __ABS(x)	(((x)<0)?-(x):(x))
#define __ABSF(x)	SYSTEM_ABS((long)(x))
#define __ABSFD(x)	SYSTEM_ABSD((double)(x))
#define __CAP(ch)	((CHAR)((ch)&0x5f))
#define __ODD(x)	((x)&1)
#define __IN(x, s)	(((s)>>(x))&1)
#define __SETOF(x)	((SET)1<<(x))
#define __SETRNG(l, h)	((~(SET)0<<(l))&~(SET)0>>(8*sizeof(SET)-1-(h)))
#define __MASK(x, m)	((x)&~(m))
#define __COPY(s, d, n)	{char*_a=(void*)s,*_b=(void*)d;long _i=0,_t=n-1;while(_i<_t&&((_b[_i]=_a[_i])!=0)){_i++;};_b[_i]=0;}
#define __STRCMP SYSTEM_STRCMP
#define __ASH(x, n)	((n)>=0?__ASHL(x,n):__ASHR(x,-(n)))
#define __ASHL(x, n)	((long)(x)<<(n))
#define __ASHR(x, n)	((long)(x)>>(n))
#define __ASHF(x, n)	SYSTEM_ASH((long)(x), (long)(n))
#define __DUP(x, l, t)	x=(void*)__MEMCPY(malloc(l*sizeof(t)),x,l*sizeof(t))
#define __DUPARR(v, t)	v=(void*)__MEMCPY(v##__copy,v,sizeof(t))
#define __DEL(x)	free(x)
#define __IS(tag, typ, level)	(*(tag-(__BASEOFF-level))==(long)typ##__typ)
#define __TYPEOF(p)	(*(((long**)(p))-1))
#define __ISP(p, typ, level)	__IS(__TYPEOF(p),typ,level)

/* runtime checks */
#ifndef SYSTEM_Cfg_NoCheck_X
#  define __X(i, ub)	(((unsigned)(long)(i)<(unsigned long)(ub))?i:(__HALT(-2),0))
#  define __XF(i, ub)	 SYSTEM_XCHK((long)(i), (long)(ub))
#else
#  define __X(i, ub)	(i)
#  define __XF(i, ub)	(i)
#endif
#define __RETCHK	__retchk: __HALT(-3)
#define __CASECHK	__HALT(-4)
#define __GUARDP(p, typ, level)	((typ*)(__ISP(p,typ,level)?p:(__HALT(-5),p)))
#define __GUARDR(r, typ, level)	(*((typ*)(__IS(r##__typ,typ,level)?r:(__HALT(-5),r))))
#define __GUARDA(p, typ, level)	((struct typ*)(__IS(__TYPEOF(p),typ,level)?p:(__HALT(-5),p)))
#define __GUARDEQR(p, dyntyp, typ)	if(dyntyp!=typ##__typ) __HALT(-6);*(p)
#define __GUARDEQP(p, typ)	if(__TYPEOF(p)!=typ##__typ)__HALT(-6);*(p)
#define __WITHCHK	__HALT(-7)
#define __R(i, ub)	(((unsigned)(long)(i)<(unsigned long)(ub))?i:(__HALT(-8),0))
#define __RF(i, ub)	SYSTEM_RCHK((long)(i),(long)(ub))

/* record type descriptors */
#ifdef SYSTEM_Cfg_RecTypeDesc
  #define __TDESC(t__desc, m, n) \
	static struct t__desc {\
		long tproc[m]; \
		long tag, next, level, module; \
		char name[24]; \
		long *base[__MAXEXT]; \
		char *rsrvd; \
		long blksz, ptr[n+1]; \
	} t__desc
  #define __TDFLDS(name, size)	{__EOM}, 1, 0, 0, 0, name, {0}, 0, size
#else
  #define __TDESC(t__desc, m, n) \
	static struct t__desc {\
		long tproc[m]; \
		long ptr[n+1]; \
	} t__desc
  #define __TDFLDS(name, size)	{}
#endif

#define __BASEOFF	(__MAXEXT+1)
#define __TPROC0OFF	(__BASEOFF+24/sizeof(long)+5)
#define __EOM	1
#define __ENUMP(adr, n, P)	SYSTEM_ENUMP(adr, (long)(n), P)
#define __ENUMR(adr, typ, size, n, P)	SYSTEM_ENUMR(adr, typ, (long)(size), (long)(n), P)

#ifdef SYSTEM_Cfg_InitTypes
  #define __INITYP(t, t0, level) \
	t##__typ= &t##__desc.blksz; \
	__MEMCPY(t##__desc.base, t0##__typ - __BASEOFF, level*sizeof(long)); \
	t##__desc.base[level]=t##__typ; \
	t##__desc.module=(long)m; \
	if(t##__desc.blksz!=sizeof(struct t)) __HALT(-15); \
	t##__desc.blksz=(t##__desc.blksz+5*sizeof(long)-1)/(4*sizeof(long))*(4*sizeof(long)); \
	SYSTEM_REGTYP(m, (long)&t##__desc.next); \
	SYSTEM_INHERIT(t##__typ, t0##__typ)
#else
  #define __INITYP(t, t0, level)
#endif

/* Oberon-2 type bound procedures support */
#ifdef SYSTEM_Cfg_TypeBoundProcDynCalls
  #define __INITBP(t, proc, num)	*(t##__typ-(__TPROC0OFF+num))=(long)proc
  #define __SEND(typ, procname, num, funtyp, parlist)	((funtyp)(*(typ-(__TPROC0OFF+num))))parlist
#else
  #define __INITBP(t, proc, num)
  #define __SEND(typ, procname, num, funtyp, parlist) procname parlist
#endif

/* runtime system variables */
extern INTEGER SYSTEM_argc;
extern SYSTEM_PTR SYSTEM_argv;
//extern void (*SYSTEM_Halt)();
extern LONGINT SYSTEM_halt;
//extern LONGINT SYSTEM_assert;
extern SYSTEM_PTR SYSTEM_modules;
extern LONGINT SYSTEM_heapsize;
extern LONGINT SYSTEM_allocated;
extern LONGINT SYSTEM_lock;
extern SHORTINT SYSTEM_gclock;
extern BOOLEAN SYSTEM_interrupted;

/* ANSI prototypes; not used so far
int SYSTEM_STRCMP(CHAR *x, CHAR *y);
void SYSTEM_INIT(int argc, long argvadr);
void SYSTEM_FINI(void);
long SYSTEM_XCHK(long i, long ub);
long SYSTEM_RCHK(long i, long ub);
long SYSTEM_ASH(long i, long n);
long SYSTEM_ABS(long i);
double SYSTEM_ABSD(double i);
void SYSTEM_INHERIT(long *t, long *t0);
void SYSTEM_ENUMP(long *adr, long n, void (*P)(void*));
void SYSTEM_ENUMR(char *adr, long *typ, long size, long n, void (*P)(void*));
long SYSTEM_DIV(unsigned long x, unsigned long y);
long SYSTEM_MOD(unsigned long x, unsigned long y);
long SYSTEM_ENTIER(double x);
void SYSTEM_HALT(int n);
*/

#if defined _SDLGUI || defined _WINGUI || defined DJGPP
#  if defined WIN64 || defined _WIN64
#    define __stdcall
#  else
#    define __stdcall __attribute__((__stdcall__))
#  endif
#  define main(argc, argv) int __stdcall WinMain( \
     void* __hInstance, void* __hPrevInstance, char* __lpCmdLine, int __nCmdShow)
#  define argc SYSTEM_argc
#  define argv SYSTEM_argv
#endif

#endif
