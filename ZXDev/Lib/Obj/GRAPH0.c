/* Ofront+ 1.0 -sx3 -21 */
#include "SYSTEM.h"
#include "Asm.h"




export void GRAPH0_CLS2 (void);
export void GRAPH0_GCLS (void);
export void GRAPH0_SCRDOT (void);
export void GRAPH0_SCRNAD (void);
export void GRAPH0_SETATTRS (SHORTINT X, SHORTINT Y, BYTE L, BYTE C);

#define GRAPH0__init()	/*noinit*/

/*============================================================================*/

void GRAPH0_CLS2 (void)
{
	Asm_Code((CHAR*)"LD   A, (#0x5C8D) ;ATTR_P   ", 29);
	Asm_Code((CHAR*)"LD   B, #0x18               ", 29);
	Asm_Code((CHAR*)"EXX                         ", 29);
	Asm_Code((CHAR*)"LD   HL, #0x5B00  ;SWAP_PAGE", 29);
	Asm_Code((CHAR*)"JP   _GRAPH0_GCLS+20        ", 29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_GCLS (void)
{
	Asm_Code((CHAR*)"XOR  A                      ", 29);
	Asm_Code((CHAR*)"LD   B, #0xBF               ", 29);
	Asm_Code((CHAR*)"EXX                         ", 29);
	Asm_Code((CHAR*)"LD   HL, #0x5800            ", 29);
	Asm_Code((CHAR*)"CALL _GRAPH0_GCLS+20        ", 29);
	Asm_Code((CHAR*)"LD   HL, #0x4000            ", 29);
	Asm_Code((CHAR*)"LD   B, #0x20               ", 29);
	Asm_Code((CHAR*)"LD   (HL), A                ", 29);
	Asm_Code((CHAR*)"INC  L                      ", 29);
	Asm_Code((CHAR*)"DJNZ .-2                    ", 29);
	Asm_Code((CHAR*)"RET                         ", 29);
	Asm_Code((CHAR*)"EXX                         ", 29);
	Asm_Code((CHAR*)"LD   D, A                   ", 29);
	Asm_Code((CHAR*)"LD   E, A                   ", 29);
	Asm_Code((CHAR*)"LD   HL, #0x0000            ", 29);
	Asm_Code((CHAR*)"ADD  HL, SP                 ", 29);
	Asm_Code((CHAR*)"EXX                         ", 29);
	Asm_Code((CHAR*)"LD   SP, HL                 ", 29);
	Asm_Code((CHAR*)"EXX                         ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"PUSH DE                     ", 29);
	Asm_Code((CHAR*)"DJNZ .-16                   ", 29);
	Asm_Code((CHAR*)"LD   SP, HL                 ", 29);
	Asm_Code((CHAR*)"LD   HL, #0x2758            ", 29);
	Asm_Code((CHAR*)"EXX                         ", 29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_SETATTRS (SHORTINT X, SHORTINT Y, BYTE L, BYTE C)
{
	Asm_Code((CHAR*)"POP  BC                     ", 29);
	Asm_Code((CHAR*)"POP  DE                     ", 29);
	Asm_Code((CHAR*)"POP  HL                     ", 29);
	Asm_Code((CHAR*)"LD   A, E                   ", 29);
	Asm_Code((CHAR*)"AND  A, #0x1F               ", 29);
	Asm_Code((CHAR*)"LD   E, A                   ", 29);
	Asm_Code((CHAR*)"LD   A, L                   ", 29);
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"LD   D, A                   ", 29);
	Asm_Code((CHAR*)"AND  A, #0xE0               ", 29);
	Asm_Code((CHAR*)"OR   E                      ", 29);
	Asm_Code((CHAR*)"LD   L,A                    ", 29);
	Asm_Code((CHAR*)"LD   A,D                    ", 29);
	Asm_Code((CHAR*)"AND  A, #0x03               ", 29);
	Asm_Code((CHAR*)"OR   A, #0x58               ", 29);
	Asm_Code((CHAR*)"LD   H, A                   ", 29);
	Asm_Code((CHAR*)"POP  DE                     ", 29);
	Asm_Code((CHAR*)"PUSH BC                     ", 29);
	Asm_Code((CHAR*)"PUSH BC                     ", 29);
	Asm_Code((CHAR*)"PUSH BC                     ", 29);
	Asm_Code((CHAR*)"PUSH BC                     ", 29);
	Asm_Code((CHAR*)"LD   B, E                   ", 29);
	Asm_Code((CHAR*)"INC  B                      ", 29);
	Asm_Code((CHAR*)"JR   B07E$                  ", 29);
	Asm_Code((CHAR*)"B07C$:", 7);
	Asm_Code((CHAR*)"LD   (HL), D                ", 29);
	Asm_Code((CHAR*)"INC  HL                     ", 29);
	Asm_Code((CHAR*)"B07E$:", 7);
	Asm_Code((CHAR*)"DJNZ B07C$                  ", 29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_SCRDOT (void)
{
	Asm_Code((CHAR*)"LD   A, D                   ", 29);
	Asm_Code((CHAR*)"AND  A, #7                  ", 29);
	Asm_Code((CHAR*)"ADD  A, #0x18               ", 29);
	Asm_Code((CHAR*)"LD   L, A                   ", 29);
	Asm_Code((CHAR*)"LD   H, #0xBD               ", 29);
	Asm_Code((CHAR*)"LD   A, D                   ", 29);
	Asm_Code((CHAR*)"LD   D, (HL)                ", 29);
}

/*----------------------------------------------------------------------------*/
void GRAPH0_SCRNAD (void)
{
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"AND  A, #0x1F               ", 29);
	Asm_Code((CHAR*)"LD   L, A                   ", 29);
	Asm_Code((CHAR*)"LD   A, E                   ", 29);
	Asm_Code((CHAR*)"RLCA                        ", 29);
	Asm_Code((CHAR*)"RLCA                        ", 29);
	Asm_Code((CHAR*)"AND  A, #0xE0               ", 29);
	Asm_Code((CHAR*)"OR   L                      ", 29);
	Asm_Code((CHAR*)"LD   L, A                   ", 29);
	Asm_Code((CHAR*)"LD   A, E                   ", 29);
	Asm_Code((CHAR*)"AND  A, #7                  ", 29);
	Asm_Code((CHAR*)"LD   B, A                   ", 29);
	Asm_Code((CHAR*)"LD   A, E                   ", 29);
	Asm_Code((CHAR*)"RRCA                        ", 29);
	Asm_Code((CHAR*)"SCF                         ", 29);
	Asm_Code((CHAR*)"RRA                         ", 29);
	Asm_Code((CHAR*)"SCF                         ", 29);
	Asm_Code((CHAR*)"RRA                         ", 29);
	Asm_Code((CHAR*)"AND  A, #0x58               ", 29);
	Asm_Code((CHAR*)"OR   B                      ", 29);
	Asm_Code((CHAR*)"LD   H, A                   ", 29);
}

/*----------------------------------------------------------------------------*/

export void *GRAPH0__init (void)
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
