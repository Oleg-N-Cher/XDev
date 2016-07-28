/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Asm.h"




export void Sound_Play (INTEGER fx);
export void Sound_Quit (void);
export void Sound_RunMe50Hz (void);

#define Sound__init()	Sound_Quit()

/*============================================================================*/

void Sound_Play (INTEGER fx)
{
	Asm_Code((CHAR*)"  DI", (LONGINT)5);
	Asm_Code((CHAR*)"  POP DE", (LONGINT)9);
	Asm_Code((CHAR*)"  POP HL", (LONGINT)9);
	Asm_Code((CHAR*)"  PUSH HL", (LONGINT)10);
	Asm_Code((CHAR*)"  PUSH DE", (LONGINT)10);
	Asm_Code((CHAR*)"  LD (PlayPos+1),HL", (LONGINT)20);
	Asm_Code((CHAR*)"  LD A,#1", (LONGINT)10);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", (LONGINT)19);
	Asm_Code((CHAR*)"  EI", (LONGINT)5);
}

/*----------------------------------------------------------------------------*/
void Sound_RunMe50Hz (void)
{
	Asm_Code((CHAR*)".globl PlayPos", (LONGINT)15);
	Asm_Code((CHAR*)".globl RunStat", (LONGINT)15);
	Asm_Code((CHAR*)"RunStat:  LD A,#0", (LONGINT)18);
	Asm_Code((CHAR*)"  AND A", (LONGINT)8);
	Asm_Code((CHAR*)"  RET Z", (LONGINT)8);
	Asm_Code((CHAR*)"  DEC A", (LONGINT)8);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", (LONGINT)19);
	Asm_Code((CHAR*)"  RET NZ", (LONGINT)9);
	Asm_Code((CHAR*)"PlayPos:  LD HL,#0", (LONGINT)19);
	Asm_Code((CHAR*)"  LD A,#8", (LONGINT)10);
	Asm_Code((CHAR*)"  LD BC,#65533", (LONGINT)15);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD A,(HL)", (LONGINT)12);
	Asm_Code((CHAR*)"  AND A", (LONGINT)8);
	Asm_Code((CHAR*)"  JR NZ,R50LABEL1", (LONGINT)18);
	Asm_Code((CHAR*)"  LD B,#0xBF", (LONGINT)13);
	Asm_Code((CHAR*)"  XOR A", (LONGINT)8);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  RET", (LONGINT)6);
	Asm_Code((CHAR*)"R50LABEL1:  LD A,#1", (LONGINT)20);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", (LONGINT)19);
	Asm_Code((CHAR*)"  LD A,(HL)", (LONGINT)12);
	Asm_Code((CHAR*)"  AND #0xF0", (LONGINT)12);
	Asm_Code((CHAR*)"  JR NZ,R50LABEL2", (LONGINT)18);
	Asm_Code((CHAR*)"  LD A,(HL)", (LONGINT)12);
	Asm_Code((CHAR*)"  ADD A,#2", (LONGINT)11);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", (LONGINT)19);
	Asm_Code((CHAR*)"  INC HL", (LONGINT)9);
	Asm_Code((CHAR*)"  LD A,(HL)", (LONGINT)12);
	Asm_Code((CHAR*)"  AND #0xF0", (LONGINT)12);
	Asm_Code((CHAR*)"R50LABEL2:  RRCA", (LONGINT)17);
	Asm_Code((CHAR*)"  RRCA", (LONGINT)7);
	Asm_Code((CHAR*)"  RRCA", (LONGINT)7);
	Asm_Code((CHAR*)"  RRCA", (LONGINT)7);
	Asm_Code((CHAR*)"  LD B,#0xBF", (LONGINT)13);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD A,#1", (LONGINT)10);
	Asm_Code((CHAR*)"  LD B,#0xFF", (LONGINT)13);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD A,(HL)", (LONGINT)12);
	Asm_Code((CHAR*)"  INC HL", (LONGINT)9);
	Asm_Code((CHAR*)"  LD (PlayPos+1),HL", (LONGINT)20);
	Asm_Code((CHAR*)"  AND #15", (LONGINT)10);
	Asm_Code((CHAR*)"  RET Z", (LONGINT)8);
	Asm_Code((CHAR*)"  DEC A", (LONGINT)8);
	Asm_Code((CHAR*)"  LD B,#0xBF", (LONGINT)13);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  XOR A", (LONGINT)8);
	Asm_Code((CHAR*)"  LD B,#0xFF", (LONGINT)13);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD A,(HL)", (LONGINT)12);
	Asm_Code((CHAR*)"  INC HL", (LONGINT)9);
	Asm_Code((CHAR*)"  LD (PlayPos+1),HL", (LONGINT)20);
	Asm_Code((CHAR*)"  LD B,#0xBF", (LONGINT)13);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
}

/*----------------------------------------------------------------------------*/
void Sound_Quit (void)
{
	Asm_Code((CHAR*)"  DI", (LONGINT)5);
	Asm_Code((CHAR*)"  LD BC,#0xFFFD", (LONGINT)16);
	Asm_Code((CHAR*)"  LD A,#7", (LONGINT)10);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD B,#0xBF", (LONGINT)13);
	Asm_Code((CHAR*)"  LD A,#254", (LONGINT)12);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD B,#0xFF", (LONGINT)13);
	Asm_Code((CHAR*)"  LD A,#8", (LONGINT)10);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  LD B,#0xBF", (LONGINT)13);
	Asm_Code((CHAR*)"  XOR A", (LONGINT)8);
	Asm_Code((CHAR*)"  OUT (C),A", (LONGINT)12);
	Asm_Code((CHAR*)"  EI", (LONGINT)5);
}

