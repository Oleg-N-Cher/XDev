#ifndef SYSTEM__h
#define SYSTEM__h

/*

the ofront runtime system interface and macro library
based on SYSTEM.h by Sepp Templ
bh 20.12.1999

*/

#pragma warning(disable:4101)	// disable "unreferenced variable" warning

// #include <alloca.h>
#include <malloc.h>
#include <stddef.h>
#include <string.h>

// extern char *memcpy();

#define export
#define import extern

/* basic types */
typedef char _BOOLEAN;
typedef unsigned char SHORTCHAR;
typedef wchar_t _CHAR;
typedef signed char _BYTE;
typedef short int SHORTINT;
typedef int INTEGER;
typedef __int64 LONGINT;
typedef float SHORTREAL;
typedef double REAL;
typedef unsigned int SET;
typedef void ANYREC;
typedef void *ANYPTR;
typedef void *SYSTEM_PTR;

LONGINT SYSTEM_INF;
INTEGER SYSTEM_INFS;

/* constants */
#define __MAXEXT	15
#define NIL	0
#define POINTER__typ	(INTEGER*)1	/* not NIL and not a valid type */
#define __INF	(*(REAL*)&SYSTEM_INF)
#define __INFS	(*(SHORTREAL*)&SYSTEM_INFS)

#define __CALLBACK	WINAPI

typedef struct SYSTEM_MODDESC;


/* runtime system routines */
extern _CHAR* SYSTEM_LSTR(char *x);
extern INTEGER SYSTEM_DIV(INTEGER x, INTEGER y);
extern INTEGER SYSTEM_MOD(INTEGER x, INTEGER y);
extern INTEGER SYSTEM_MIN(INTEGER x, INTEGER y);
extern INTEGER SYSTEM_MAX(INTEGER x, INTEGER y);
extern INTEGER SYSTEM_ENTIER(REAL x);
extern INTEGER SYSTEM_ASH(INTEGER x, INTEGER n);
extern INTEGER SYSTEM_ABS(INTEGER x);
extern INTEGER SYSTEM_XCHK(INTEGER i, INTEGER ub);
extern void *SYSTEM_NEWARR(INTEGER type, INTEGER n);
extern void *SYSTEM_NEWARR1(INTEGER type, INTEGER n0, INTEGER n);
extern void *SYSTEM_NEWARR2(INTEGER type, INTEGER n1, INTEGER n0, INTEGER n);
extern void *SYSTEM_NEWARR3(INTEGER type, INTEGER n2, INTEGER n1, INTEGER n0, INTEGER n);
extern void *SYSTEM_NEWARR4(INTEGER type, INTEGER n3, INTEGER n2, INTEGER n1, INTEGER n0, INTEGER n);
extern void SYSTEM_REGMOD(struct SYSTEM_MODDESC *mod);
extern INTEGER SYSTEM_STRLEN(_CHAR x[]);	/* LEN(lx$) */
extern INTEGER SYSTEM_STRLENS(SHORTCHAR x[]);	/* LEN(sx$) */
extern INTEGER SYSTEM_STRCMPSS(SHORTCHAR x[], SHORTCHAR y[]);	/* sx = sy */
extern INTEGER SYSTEM_STRCMPTS(_CHAR x[], SHORTCHAR y[]);	/* SHORT(lx) = sy */
extern INTEGER SYSTEM_STRCMPTT(_CHAR x[], _CHAR y[]);	/* SHORT(lx) = SHORT(ly) */
extern INTEGER SYSTEM_STRCMPLL(_CHAR x[], _CHAR y[]);	/* lx = ly */
extern INTEGER SYSTEM_STRCMPSL(SHORTCHAR x[], _CHAR y[]);	/* LONG(sx) = ly */
extern INTEGER SYSTEM_STRCMPTL(_CHAR x[], _CHAR y[]);	/* LONG(SHORT(lx)) = ly */
extern void SYSTEM_STRCOPYSS(SHORTCHAR x[], SHORTCHAR y[], INTEGER n);	/* sy := sx */
extern void SYSTEM_STRCOPYTS(_CHAR x[], SHORTCHAR y[], INTEGER n);	/* sy := SHORT(lx) */
extern void SYSTEM_STRCOPYLL(_CHAR x[], _CHAR y[], INTEGER n);	/* ly := lx */
extern void SYSTEM_STRCOPYSL(SHORTCHAR x[], _CHAR y[], INTEGER n);	/* ly := LONG(sx) */
extern void SYSTEM_STRCOPYTL(_CHAR x[], _CHAR y[], INTEGER n);	/* ly := LONG(SHORT(lx)) */
extern void SYSTEM_STRAPNDSS(SHORTCHAR x[], SHORTCHAR y[], INTEGER n);	/* sy := sy + sx */
extern void SYSTEM_STRAPNDTS(_CHAR x[], SHORTCHAR y[], INTEGER n);	/* sy := sy + SHORT(lx) */
extern void SYSTEM_STRAPNDLL(_CHAR x[], _CHAR y[], INTEGER n);	/* ly := ly + lx */
extern void SYSTEM_STRAPNDSL(SHORTCHAR x[], _CHAR y[], INTEGER n);	/* ly := ly + LONG(sx) */
extern void SYSTEM_STRAPNDTL(_CHAR x[], _CHAR y[], INTEGER n);	/* ly := ly + LONG(SHORT(lx)) */
extern LONGINT SYSTEM_DIVL(LONGINT x, LONGINT y);
extern LONGINT SYSTEM_MODL(LONGINT x, LONGINT y);
extern LONGINT SYSTEM_MINL(LONGINT x, LONGINT y);
extern LONGINT SYSTEM_MAXL(LONGINT x, LONGINT y);
extern LONGINT SYSTEM_ASHL(LONGINT x, INTEGER n);
extern LONGINT SYSTEM_ABSL(LONGINT x);
extern SHORTREAL SYSTEM_INT2SR(INTEGER x);
extern REAL SYSTEM_LONG2R(LONGINT x);
extern LONGINT SYSTEM_ENTIERL(REAL x);
extern INTEGER SYSTEM_SR2INT(SHORTREAL x);
extern LONGINT SYSTEM_R2LONG(REAL x);
extern SHORTREAL SYSTEM_ABSF(SHORTREAL x);
extern SHORTREAL SYSTEM_MINF(SHORTREAL x, SHORTREAL y);
extern SHORTREAL SYSTEM_MAXF(SHORTREAL x, SHORTREAL y);
extern REAL SYSTEM_ABSD(REAL x);
extern REAL SYSTEM_MIND(REAL x, REAL y);
extern REAL SYSTEM_MAXD(REAL x, REAL y);

extern INTEGER Kernel_NewRec();
extern INTEGER Kernel_NewArr();
extern void Kernel_Trap();

/* simple open array types */

typedef struct BOOLEAN_ARRAY {
	INTEGER gc[3], len[1];
	_BOOLEAN data[1];
} BOOLEAN_ARRAY;
typedef struct CHAR_ARRAY {
	INTEGER gc[3], len[1];
	_CHAR data[1];
} CHAR_ARRAY;
typedef struct SHORTCHAR_ARRAY {
	INTEGER gc[3], len[1];
	SHORTCHAR data[1];
} SHORTCHAR_ARRAY;
typedef struct BYTE_ARRAY {
	INTEGER gc[3], len[1];
	_BYTE data[1];
} BYTE_ARRAY;
typedef struct SHORTINT_ARRAY {
	INTEGER gc[3], len[1];
	SHORTINT data[1];
} SHORTINT_ARRAY;
typedef struct INTEGER_ARRAY {
	INTEGER gc[3], len[1];
	INTEGER data[1];
} INTEGER_ARRAY;
typedef struct LONGINT_ARRAY {
	INTEGER gc[3], len[1];
	LONGINT data[1];
} LONGINT_ARRAY;
typedef struct REAL_ARRAY {
	INTEGER gc[3], len[1];
	REAL data[1];
} REAL_ARRAY;
typedef struct SHORTREAL_ARRAY {
	INTEGER gc[3], len[1];
	SHORTREAL data[1];
} SHORTREAL_ARRAY;
typedef struct SET_ARRAY {
	INTEGER gc[3], len[1];
	SET data[1];
} SET_ARRAY;

/* meta info */

typedef struct SYSTEM_OBJDESC {
	INTEGER fprint, offs, id, struc;
} SYSTEM_OBJDESC;
typedef struct SYSTEM_DIRECTORY {
	INTEGER num;
	struct SYSTEM_OBJDESC obj[1];
} SYSTEM_DIRECTORY;
typedef struct SYSTEM_MODDESC {
	struct SYSTEM_MODDESC *next;
	SET opts;
	INTEGER refcnt;
	SHORTINT compTime[6], loadTime[6];
	void (*body) ();
	void (*term) ();
	INTEGER nofimps, nofptrs, size, dsize, rsize, code, data, refs, procBase, varBase;
	char *names;
	INTEGER *ptrs;
	struct SYSTEM_MODDESC **imports;
	struct SYSTEM_DIRECTORY *exp;
	char name[64];
} SYSTEM_MODDESC;
typedef struct SYSTEM_TYPEDESC {
	INTEGER size;
	struct SYSTEM_MODDESC *mod;
	INTEGER id;
	INTEGER base[16];
	struct SYSTEM_DIRECTORY *fields;
	INTEGER ptroffs[1];
} SYSTEM_TYPEDESC;

/* dynamic link */

typedef struct SYSTEM_DLINK {
	struct SYSTEM_DLINK *next;
	char *name;
} SYSTEM_DLINK;
SYSTEM_DLINK *SYSTEM_dlink;


#define __BEGREG(mod)	if (mod.opts & 0x40000) return; mod.opts |= 0x40000;
#define __ENDREG	
#define __REGMOD(mod)	SYSTEM_REGMOD(&mod);
#define __BEGBODY(mod)	if (mod.opts & 0x10000) return; mod.opts |= 0x10000;
#define __ENDBODY	
#define __BEGCLOSE	
#define __ENDCLOSE	
#define __ENTER(name)	SYSTEM_DLINK __dl = {SYSTEM_dlink, name}; SYSTEM_dlink = &__dl
#define __EXIT				SYSTEM_dlink = __dl.next

/* SYSTEM ops */
#define __VAL(t, x)	(*(t*)&(x))
#define __VALSR(x)	SYSTEM_INT2SR(x)
#define __VALR(x)	SYSTEM_LONG2R(x)
#define __VALI(x)	SYSTEM_SR2INT(x)
#define __VALL(x)	SYSTEM_R2LONG(x)
#define __GET(a, x, t)	x= *(t*)(a)
#define __PUT(a, x, t)	*(t*)(a)=(t)x
#define __LSHL(x, n, t)	((t)((unsigned)(x)<<(n)))
#define __LSHR(x, n, t)	((t)((unsigned)(x)>>(n)))
#define __LSH(x, n, t)	((n)>=0? __LSHL(x, n, t): __LSHR(x, -(n), t))
#define __ROTL(x, n, t)	((t)((unsigned)(x)<<(n)|(unsigned)(x)>>(8*sizeof(t)-(n))))
#define __ROTR(x, n, t)	((t)((unsigned)(x)>>(n)|(unsigned)(x)<<(8*sizeof(t)-(n))))
#define __ROT(x, n, t)	((n)>=0? __ROTL(x, n, t): __ROTR(x, -(n), t))
#define __BIT(x, n)	(*(unsigned*)(x)>>(n)&1)
#define __MOVE(s, d, n)	memcpy((char*)(d),(char*)(s),n)

/* std procs and operator mappings */
// #define __SHORT(x, y)	((int)((unsigned)(x)+(y)<(y)+(y)?(x):(__HALT(-8),0)))
// #define __SHORTF(x, y)	((int)(__RF((x)+(y),(y)+(y))-(y)))
// #define __CHR(x)	((_CHAR)__R(x, 256))
// #define __CHRF(x)	((_CHAR)__RF(x, 256))
#define __DIV(x, y)	((x)>=0?(x)/(y):~(~(x)/(y)))
#define __DIVF(x, y)	SYSTEM_DIV(x,y)
#define __DIVFL(x, y)	SYSTEM_DIVL(x,y)
#define __MOD(x, y)	((x)>=0?(x)%(y):(y)+~(~(x)%(y)))
#define __MODF(x, y)	SYSTEM_MOD(x,y)
#define __MODFL(x, y)	SYSTEM_MODL(x,y)
#define __MIN(x, y)	((x)<(y)?(x):(y))
#define __MINF(x, y)	SYSTEM_MIN(x,y)
#define __MINFL(x, y)	SYSTEM_MINL(x,y)
#define __MINFF(x, y)	SYSTEM_MINF(x,y)
#define __MINFD(x, y)	SYSTEM_MIND(x,y)
#define __MAX(x, y)	((x)>(y)?(x):(y))
#define __MAXF(x, y)	SYSTEM_MAX(x,y)
#define __MAXFL(x, y)	SYSTEM_MAXL(x,y)
#define __MAXFF(x, y)	SYSTEM_MAXF(x,y)
#define __MAXFD(x, y)	SYSTEM_MAXD(x,y)
#define __NEW(t)	(void*)Kernel_NewRec((INTEGER)t)
#define __NEWARR(t, n)	(void*)SYSTEM_NEWARR(t, n)
#define __NEWARR0(t, n)	(void*)Kernel_NewArr(t, n, 0)
#define __NEWARR1(t, n0, n)	(void*)SYSTEM_NEWARR1(t, n0, n)
#define __NEWARR2(t, n1, n0, n)	(void*)SYSTEM_NEWARR2(t, n1, n0, n)
#define __NEWARR3(t, n2, n1, n0, n)	(void*)SYSTEM_NEWARR3(t, n2, n1, n0, n)
#define __NEWARR4(t, n3, n2, n1, n0, n)	(void*)SYSTEM_NEWARR4(t, n3, n2, n1, n0, n)
#define __HALT(x)	Kernel_Trap(x)
#define __ASSERT(cond, x)	if (!(cond)) __HALT(x)
#define __ENTIER(x)	SYSTEM_ENTIER(x)
#define __ENTIERL(x)	SYSTEM_ENTIERL(x)
#define __ABS(x)	(((x)<0)?-(x):(x))
#define __ABSF(x)	SYSTEM_ABS(x)
#define __ABSFL(x)	SYSTEM_ABSL(x)
#define __ABSFF(x)	SYSTEM_ABSF(x)
#define __ABSFD(x)	SYSTEM_ABSD(x)
#define __CAP(ch)	((_CHAR)((ch)&0x5f))
#define __ODD(x)	((x)&1)
#define __IN(x, s)	(((s)>>(x))&1)
#define __SETOF(x)	((SET)1<<(x))
#define __SETRNG(l, h)	((~(SET)0<<(l))&~(SET)0>>(8*sizeof(SET)-1-(h)))
#define __MASK(x, m)	((x)&~(m))
#define __LSTR(x)	SYSTEM_LSTR(x)

#define __STRLEN(x)	SYSTEM_STRLEN(x)	/* LEN(lx$) */
#define __STRLENS(x)	SYSTEM_STRLENS(x)	/* LEN(sx$) */
#define __STRCMPSS(x, y)	SYSTEM_STRCMPSS(x, y)	/* sx = sy */
#define __STRCMPTS(x, y)	SYSTEM_STRCMPTS(x, y)	/* SHORT(lx) = sy */
#define __STRCMPTT(x, y)	SYSTEM_STRCMPTT(x, y)	/* SHORT(lx) = SHORT(ly) */
#define __STRCMPLL(x, y)	SYSTEM_STRCMPLL(x, y)	/* lx = ly */
#define __STRCMPSL(x, y)	SYSTEM_STRCMPSL(x, y)	/* LONG(sx) = ly */
#define __STRCMPTL(x, y)	SYSTEM_STRCMPTL(x, y)	/* LONG(SHORT(lx)) = ly */
#define __STRCOPYSS(x, y, n)	SYSTEM_STRCOPYSS(x, y, n)	/* sy := sx */
#define __STRCOPYTS(x, y, n)	SYSTEM_STRCOPYTS(x, y, n)	/* sy := SHORT(lx) */
#define __STRCOPYLL(x, y, n)	SYSTEM_STRCOPYLL(x, y, n)	/* ly := lx */
#define __STRCOPYSL(x, y, n)	SYSTEM_STRCOPYSL(x, y, n)	/* ly := LONG(sx) */
#define __STRCOPYTL(x, y, n)	SYSTEM_STRCOPYTL(x, y, n)	/* ly := LONG(SHORT(lx)) */
#define __STRAPNDSS(x, y, n)	SYSTEM_STRAPNDSS(x, y, n)	/* sy := sy + sx */
#define __STRAPNDTS(x, y, n)	SYSTEM_STRAPNDTS(x, y, n)	/* sy := sy + SHORT(lx) */
#define __STRAPNDLL(x, y, n)	SYSTEM_STRAPNDLL(x, y, n)	/* ly := ly + lx */
#define __STRAPNDSL(x, y, n)	SYSTEM_STRAPNDSL(x, y, n)	/* ly := ly + LONG(sx) */
#define __STRAPNDTL(x, y, n)	SYSTEM_STRAPNDTL(x, y, n)	/* ly := ly + LONG(SHORT(lx)) */

#define __ASH(x, n, t)	((n)>=0?__ASHL(x,n,t):__ASHR(x,-(n),t))
#define __ASHL(x, n, t)	((t)(x)<<(n))
#define __ASHR(x, n, t) ((t)(x)>>(n))
#define __ASHF(x, n, t)	SYSTEM_ASH(x, n)
#define __ASHFL(x, n, t)	SYSTEM_ASHL(x, n)
#define __DUP(x, l)	x=(void*)memcpy(alloca(l*sizeof(*x)),x,l*sizeof(*x))
#define __DUPARR(v)	v=(void*)memcpy(v##__copy,v,sizeof(v##__copy))
#define __DEL(x)	/* DUP with alloca frees storage automatically */
#define __IS(tag, typ, level)	((tag->base[level])==(INTEGER)typ)
#define __TYPEOF(p)	(*(((SYSTEM_TYPEDESC**)(p))-1))
#define __ISP(p, typ, level)	__IS(__TYPEOF(p),typ,level)

/* runtime checks */
#define __X(i, ub)	(((unsigned)(i)<(unsigned)(ub))?i:(__HALT(-7),0))
#define __XF(i, ub)	 SYSTEM_XCHK((INTEGER)(i), (INTEGER)(ub))
// #define __RETCHK	__retchk: __HALT(-3)
#define __RETCHK	__HALT(-3)
#define __CASECHK	__HALT(-2)
#define __GUARDP(p, typ, level)	((typ*)(__ISP(p,typ,level)?p:(__HALT(-4),p)))
#define __GUARDR(r, typ, level)	(*((typ*)(__IS(r##__typ,typ,level)?r:(__HALT(-4),r))))
#define __GUARDA(p, typ, level)	((struct typ*)(__IS(__TYPEOF(p),typ,level)?p:(__HALT(-4),p)))
#define __WITHCHK	__HALT(-1)

/* Oberon-2 type bound procedures support */
#define __SEND(typ, num, funtyp, parlist)	((funtyp)(*((INTEGER*)typ-(num+1))))parlist

/* runtime system variables */
extern SYSTEM_MODDESC *SYSTEM_modlist;
extern LONGINT SYSTEM_argc;
extern LONGINT SYSTEM_argv;
extern void (*SYSTEM_Halt)();
extern LONGINT SYSTEM_halt;
extern LONGINT SYSTEM_assert;
extern SYSTEM_PTR SYSTEM_modules;
extern LONGINT SYSTEM_heapsize;
extern LONGINT SYSTEM_allocated;
extern LONGINT SYSTEM_lock;
extern SHORTINT SYSTEM_gclock;
extern _BOOLEAN SYSTEM_interrupted;

#endif
