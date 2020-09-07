#include "SYSTEM.oh"

/* runtime system routines */
extern void SYSTEM_HALT_m1 (BYTE n) __z88dk_fastcall;
extern int SYSTEM_STRCMP (CHAR *x, CHAR *y);
extern void SYSTEM_STRAPND (CHAR *from, CHAR *to) __z88dk_callee;
extern void SYSTEM_STRCOPY (CHAR *to, CHAR *from) __z88dk_callee;
extern SHORTINT SYSTEM_STRLEN (CHAR *str) __z88dk_fastcall;
extern long SYSTEM_ENTIER (float x);
extern SHORTINT SYSTEM_ASH (SHORTINT x, BYTE n);
extern INTEGER SYSTEM_ASHL (INTEGER x, BYTE n);
extern SYSTEM_PTR SYSTEM_NEWBLK (__U_SHORTINT size);

#define SYSTEM_malloc(size)	(SYSTEM_PTR)malloc(size)
/*================================== Header ==================================*/

void SYSTEM_HALT_m1 (BYTE n) __naked __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  IM   1
  EI
  LD   (HALTCODE$),HL
  RST  8
HALTCODE$:
  .DB  0xFF ; Ruins the byte after that, but it is no longer needed
__endasm;
} //SYSTEM_HALT_m1

/*--------------------------------- Cut here ---------------------------------*/
int SYSTEM_XCHK (int i, int ub) { return __X(i, ub, "", 0); }

/*--------------------------------- Cut here ---------------------------------*/
void SYSTEM_STRAPND (CHAR *from, CHAR *to) __naked __z88dk_callee {
    __asm  ; n = 0; while (to[n] != '\0') n++;
           POP  HL
           POP  DE           ; from[]
           EX   (SP), HL     ; to[]
           XOR  A
           LD   C, A
           LD   B, A
           CPIR
           DEC  HL
           ; i = 0; do { to[n++] = from[i]; } while (from[i++] != '\0');
           EX   DE, HL
APND_STR$: CP   (HL)
           LDI
           JR   NZ, APND_STR$
           RET
    __endasm;
} //SYSTEM_STRAPND

/*--------------------------------- Cut here ---------------------------------*/
int SYSTEM_STRCMP (CHAR *x, CHAR *y)
{int i = 0; CHAR ch1, ch2;
	do {ch1 = x[i]; ch2 = y[i]; i++;
		if (!ch1) return -(int)ch2;
	} while (ch1==ch2);
	return (int)ch1 - (int)ch2;
}

/*--------------------------------- Cut here ---------------------------------*/
void SYSTEM_STRCOPY (CHAR *to, CHAR *from) __naked __z88dk_callee {
__asm      ; n = 0; do { to[n] = from[n]; } while (from[n++] != '\0');
           POP  HL
           POP  DE           ; to[]
           EX   (SP), HL     ; from[]
           XOR  A
COPY_STR$: CP   (HL)
           LDI
           JR   NZ, COPY_STR$
           RET
__endasm;
} //SYSTEM_STRCOPY

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT SYSTEM_STRLEN (CHAR *str) __z88dk_fastcall {
    __asm  ; n = 0; while (str[n] != '\0') n++; return n;
           XOR  A
           LD   B, A
           LD   C, A
           CPIR
           LD   HL, #0xFFFF
           SBC  HL, BC
    __endasm;
} //SYSTEM_STRLEN

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
