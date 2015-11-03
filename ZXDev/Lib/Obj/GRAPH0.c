/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Asm.h"




export void GRAPH0_CLS2 (void);
export void GRAPH0_GCLS (void);
export void GRAPH0_SCRDOT (void);
export void GRAPH0_SCRNAD (void);
export void GRAPH0_SETATTRS (INTEGER X, INTEGER Y, SHORTINT L, SHORTINT C);

#define GRAPH0__init()	/*noinit*/

/*============================================================================*/

void GRAPH0_CLS2 (void)
{
	Asm_Code((CHAR*)"LD   A, (#0x5C8D) ;ATTR_P   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   B, #0x18               ", (LONGINT)29);
	Asm_Code((CHAR*)"EXX                         ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   HL, #0x5B00  ;SWAP_PAGE", (LONGINT)29);
	Asm_Code((CHAR*)"JP   _GRAPH0_GCLS+20        ", (LONGINT)29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_GCLS (void)
{
	Asm_Code((CHAR*)"XOR  A                      ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   B, #0xBF               ", (LONGINT)29);
	Asm_Code((CHAR*)"EXX                         ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   HL, #0x5800            ", (LONGINT)29);
	Asm_Code((CHAR*)"CALL _GRAPH0_GCLS+20        ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   HL, #0x4000            ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   B, #0x20               ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   (HL), A                ", (LONGINT)29);
	Asm_Code((CHAR*)"INC  L                      ", (LONGINT)29);
	Asm_Code((CHAR*)"DJNZ .-2                    ", (LONGINT)29);
	Asm_Code((CHAR*)"RET                         ", (LONGINT)29);
	Asm_Code((CHAR*)"EXX                         ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   D, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   E, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   HL, #0x0000            ", (LONGINT)29);
	Asm_Code((CHAR*)"ADD  HL, SP                 ", (LONGINT)29);
	Asm_Code((CHAR*)"EXX                         ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   SP, HL                 ", (LONGINT)29);
	Asm_Code((CHAR*)"EXX                         ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"DJNZ .-16                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   SP, HL                 ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   HL, #0x2758            ", (LONGINT)29);
	Asm_Code((CHAR*)"EXX                         ", (LONGINT)29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_SETATTRS (INTEGER X, INTEGER Y, SHORTINT L, SHORTINT C)
{
	Asm_Code((CHAR*)"POP  BC                     ", (LONGINT)29);
	Asm_Code((CHAR*)"POP  DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"POP  HL                     ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A, E                   ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #0x1F               ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   E, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A, L                   ", (LONGINT)29);
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   D, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #0xE0               ", (LONGINT)29);
	Asm_Code((CHAR*)"OR   E                      ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   L,A                    ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A,D                    ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #0x03               ", (LONGINT)29);
	Asm_Code((CHAR*)"OR   A, #0x58               ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   H, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"POP  DE                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH BC                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH BC                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH BC                     ", (LONGINT)29);
	Asm_Code((CHAR*)"PUSH BC                     ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   B, E                   ", (LONGINT)29);
	Asm_Code((CHAR*)"INC  B                      ", (LONGINT)29);
	Asm_Code((CHAR*)"JR   B07E$                  ", (LONGINT)29);
	Asm_Code((CHAR*)"B07C$:", (LONGINT)7);
	Asm_Code((CHAR*)"LD   (HL), D                ", (LONGINT)29);
	Asm_Code((CHAR*)"INC  HL                     ", (LONGINT)29);
	Asm_Code((CHAR*)"B07E$:", (LONGINT)7);
	Asm_Code((CHAR*)"DJNZ B07C$                  ", (LONGINT)29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_SCRDOT (void)
{
	Asm_Code((CHAR*)"LD   A, D                   ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #7                  ", (LONGINT)29);
	Asm_Code((CHAR*)"ADD  A, #0x18               ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   L, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   H, #0xBD               ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A, D                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   D, (HL)                ", (LONGINT)29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_SCRNAD (void)
{
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #0x1F               ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   L, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A, E                   ", (LONGINT)29);
	Asm_Code((CHAR*)"RLCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"RLCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #0xE0               ", (LONGINT)29);
	Asm_Code((CHAR*)"OR   L                      ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   L, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A, E                   ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #7                  ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   B, A                   ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   A, E                   ", (LONGINT)29);
	Asm_Code((CHAR*)"RRCA                        ", (LONGINT)29);
	Asm_Code((CHAR*)"SCF                         ", (LONGINT)29);
	Asm_Code((CHAR*)"RRA                         ", (LONGINT)29);
	Asm_Code((CHAR*)"SCF                         ", (LONGINT)29);
	Asm_Code((CHAR*)"RRA                         ", (LONGINT)29);
	Asm_Code((CHAR*)"AND  A, #0x58               ", (LONGINT)29);
	Asm_Code((CHAR*)"OR   B                      ", (LONGINT)29);
	Asm_Code((CHAR*)"LD   H, A                   ", (LONGINT)29);
}

/*----------------------------------------------------------------------------*/

export void *GRAPH0__init(void)
{
	__DEFMOD;
	__IMPORT(Asm__init);
	__REGMOD("GRAPH0", 0);
	__REGCMD("CLS2", GRAPH0_CLS2);
	__REGCMD("GCLS", GRAPH0_GCLS);
	__REGCMD("SCRDOT", GRAPH0_SCRDOT);
	__REGCMD("SCRNAD", GRAPH0_SCRNAD);
/* BEGIN */
	__ENDMOD;
}
