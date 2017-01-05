/* Ofront+ 0.9 -xtspkae */
#include "SYSTEM.h"
#include "Asm.h"
#include "Basic.h"


static SHORTINT Debug_a;
static INTEGER Debug_bc, Debug_de, Debug_hl, Debug_ix, Debug_iy;


export void Debug_CheckIX (void);
export void Debug_CheckRegs (void);
export void Debug_SaveIX (void);
export void Debug_SaveRegs (void);
export void Debug_SaveRegsDef (void);


/*============================================================================*/

void Debug_SaveIX (void)
{
	Asm_Code((CHAR*)"LD (_Debug_ix), IX", 19);
}

/*----------------------------------------------------------------------------*/
void Debug_CheckIX (void)
{
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"LD   HL, (_Debug_ix)", 21);
	Asm_Code((CHAR*)"AND  A", 7);
	Asm_Code((CHAR*)"SBC  HL, DE", 12);
	Asm_Code((CHAR*)"RET  Z", 7);
	Basic_COLOR(2);
	Basic_PRSTR((CHAR*)"IX broken", 10);
	Basic_PAUSE(0);
}

/*----------------------------------------------------------------------------*/
void Debug_SaveRegs (void)
{
	Asm_Code((CHAR*)"LD (_Debug_a) , A ", 19);
	Asm_Code((CHAR*)"LD (_Debug_bc), BC", 19);
	Asm_Code((CHAR*)"LD (_Debug_de), DE", 19);
	Asm_Code((CHAR*)"LD (_Debug_hl), HL", 19);
	Asm_Code((CHAR*)"LD (_Debug_ix), IX", 19);
	Asm_Code((CHAR*)"LD (_Debug_iy), IY", 19);
}

/*----------------------------------------------------------------------------*/
void Debug_SaveRegsDef (void)
{
	Asm_Code((CHAR*)"LD A , #0x33      ", 19);
	Asm_Code((CHAR*)"LD BC, #0x4455    ", 19);
	Asm_Code((CHAR*)"LD DE, #0x6677    ", 19);
	Asm_Code((CHAR*)"LD HL, #0x8899    ", 19);
	Asm_Code((CHAR*)"LD IX, #0xAABB    ", 19);
	Asm_Code((CHAR*)"LD IY, #0xCCDD    ", 19);
	Asm_Code((CHAR*)"LD (_Debug_a), A  ", 19);
	Asm_Code((CHAR*)"LD (_Debug_bc), BC", 19);
	Asm_Code((CHAR*)"LD (_Debug_de), DE", 19);
	Asm_Code((CHAR*)"LD (_Debug_hl), HL", 19);
	Asm_Code((CHAR*)"LD (_Debug_ix), IX", 19);
	Asm_Code((CHAR*)"LD (_Debug_iy), IY", 19);
}

/*----------------------------------------------------------------------------*/
void Debug_CheckRegs (void)
{
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Basic_COLOR(4);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"LD   B, A", 10);
	Asm_Code((CHAR*)"LD   A, (_Debug_a)", 19);
	Asm_Code((CHAR*)"CP   B", 7);
	Asm_Code((CHAR*)"JR   NZ, NoA$", 14);
	Basic_PRSTR((CHAR*)" A", 3);
	Asm_Code((CHAR*)"NoA$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"LD   A, (_Debug_bc+1)", 22);
	Asm_Code((CHAR*)"CP   B", 7);
	Asm_Code((CHAR*)"JR   NZ, NoB$", 14);
	Basic_PRSTR((CHAR*)" B", 3);
	Asm_Code((CHAR*)"NoB$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"LD   A, (_Debug_bc)", 20);
	Asm_Code((CHAR*)"CP   C", 7);
	Asm_Code((CHAR*)"JR   NZ, NoC$", 14);
	Basic_PRSTR((CHAR*)" C", 3);
	Asm_Code((CHAR*)"NoC$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"LD   A, (_Debug_de+1)", 22);
	Asm_Code((CHAR*)"CP   D", 7);
	Asm_Code((CHAR*)"JR   NZ, NoD$", 14);
	Basic_PRSTR((CHAR*)" D", 3);
	Asm_Code((CHAR*)"NoD$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"LD   A, (_Debug_de)", 20);
	Asm_Code((CHAR*)"CP   E", 7);
	Asm_Code((CHAR*)"JR   NZ, NoE$", 14);
	Basic_PRSTR((CHAR*)" E", 3);
	Asm_Code((CHAR*)"NoE$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"LD   A, (_Debug_hl+1)", 22);
	Asm_Code((CHAR*)"CP   H", 7);
	Asm_Code((CHAR*)"JR   NZ, NoH$", 14);
	Basic_PRSTR((CHAR*)" H", 3);
	Asm_Code((CHAR*)"NoH$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"LD   A, (_Debug_hl)", 20);
	Asm_Code((CHAR*)"CP   L", 7);
	Asm_Code((CHAR*)"JR   NZ, NoL$", 14);
	Basic_PRSTR((CHAR*)" L", 3);
	Asm_Code((CHAR*)"NoL$: ", 7);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH AF", 8);
	Asm_Code((CHAR*)"PUSH BC", 8);
	Asm_Code((CHAR*)"PUSH DE", 8);
	Asm_Code((CHAR*)"PUSH HL", 8);
	Asm_Code((CHAR*)"PUSH IX", 8);
	Asm_Code((CHAR*)"PUSH IY", 8);
	Asm_Code((CHAR*)"PUSH IY             ", 21);
	Asm_Code((CHAR*)"POP  DE             ", 21);
	Asm_Code((CHAR*)"LD   HL, (_Debug_iy)", 21);
	Asm_Code((CHAR*)"AND  A", 7);
	Asm_Code((CHAR*)"SBC  HL, DE", 12);
	Asm_Code((CHAR*)"JR   NZ, NoIY$", 15);
	Basic_PRSTR((CHAR*)" IY", 4);
	Asm_Code((CHAR*)"NoIY$: ", 8);
	Asm_Code((CHAR*)"POP  IY", 8);
	Asm_Code((CHAR*)"POP  IX", 8);
	Asm_Code((CHAR*)"POP  HL", 8);
	Asm_Code((CHAR*)"POP  DE", 8);
	Asm_Code((CHAR*)"POP  BC", 8);
	Asm_Code((CHAR*)"POP  AF", 8);
	Asm_Code((CHAR*)"PUSH IX             ", 21);
	Asm_Code((CHAR*)"POP  DE             ", 21);
	Asm_Code((CHAR*)"LD   HL, (_Debug_ix)", 21);
	Asm_Code((CHAR*)"AND  A", 7);
	Asm_Code((CHAR*)"SBC  HL, DE", 12);
	Asm_Code((CHAR*)"JR   Z, YesIX$", 15);
	Basic_COLOR(2);
	Basic_PRSTR((CHAR*)" IX", 4);
	Asm_Code((CHAR*)"YesIX$: ", 9);
	Basic_PRLN();
}

/*----------------------------------------------------------------------------*/

export void *Debug__init(void)
{
	__DEFMOD;
	__IMPORT(Asm__init);
	__IMPORT(Basic__init);
	__REGMOD("Debug", 0);
	__REGCMD("CheckIX", Debug_CheckIX);
	__REGCMD("CheckRegs", Debug_CheckRegs);
	__REGCMD("SaveIX", Debug_SaveIX);
	__REGCMD("SaveRegs", Debug_SaveRegs);
	__REGCMD("SaveRegsDef", Debug_SaveRegsDef);
/* BEGIN */
	__ENDMOD;
}
