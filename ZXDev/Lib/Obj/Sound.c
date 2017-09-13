/* Ofront+ 0.9 -s */
#include "SYSTEM.h"
#include "Asm.h"




export void Sound_Play (INTEGER fx);
export void Sound_Quit (void);
export void Sound_RunMe50Hz (void);

#define Sound__init()	Sound_Quit()

/*============================================================================*/

void Sound_Play (INTEGER fx)
{
	Asm_Code((CHAR*)"  DI", 5);
	Asm_Code((CHAR*)"  POP DE", 9);
	Asm_Code((CHAR*)"  POP HL", 9);
	Asm_Code((CHAR*)"  PUSH HL", 10);
	Asm_Code((CHAR*)"  PUSH DE", 10);
	Asm_Code((CHAR*)"  LD (PlayPos+1),HL", 20);
	Asm_Code((CHAR*)"  LD A,#1", 10);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", 19);
	Asm_Code((CHAR*)"  EI", 5);
}

/*----------------------------------------------------------------------------*/
void Sound_RunMe50Hz (void)
{
	Asm_Code((CHAR*)".globl PlayPos", 15);
	Asm_Code((CHAR*)".globl RunStat", 15);
	Asm_Code((CHAR*)"RunStat:  LD A,#0", 18);
	Asm_Code((CHAR*)"  AND A", 8);
	Asm_Code((CHAR*)"  RET Z", 8);
	Asm_Code((CHAR*)"  DEC A", 8);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", 19);
	Asm_Code((CHAR*)"  RET NZ", 9);
	Asm_Code((CHAR*)"PlayPos:  LD HL,#0", 19);
	Asm_Code((CHAR*)"  LD A,#8", 10);
	Asm_Code((CHAR*)"  LD BC,#65533", 15);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD A,(HL)", 12);
	Asm_Code((CHAR*)"  AND A", 8);
	Asm_Code((CHAR*)"  JR NZ,R50LABEL1", 18);
	Asm_Code((CHAR*)"  LD B,#0xBF", 13);
	Asm_Code((CHAR*)"  XOR A", 8);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  RET", 6);
	Asm_Code((CHAR*)"R50LABEL1:  LD A,#1", 20);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", 19);
	Asm_Code((CHAR*)"  LD A,(HL)", 12);
	Asm_Code((CHAR*)"  AND #0xF0", 12);
	Asm_Code((CHAR*)"  JR NZ,R50LABEL2", 18);
	Asm_Code((CHAR*)"  LD A,(HL)", 12);
	Asm_Code((CHAR*)"  ADD A,#2", 11);
	Asm_Code((CHAR*)"  LD (RunStat+1),A", 19);
	Asm_Code((CHAR*)"  INC HL", 9);
	Asm_Code((CHAR*)"  LD A,(HL)", 12);
	Asm_Code((CHAR*)"  AND #0xF0", 12);
	Asm_Code((CHAR*)"R50LABEL2:  RRCA", 17);
	Asm_Code((CHAR*)"  RRCA", 7);
	Asm_Code((CHAR*)"  RRCA", 7);
	Asm_Code((CHAR*)"  RRCA", 7);
	Asm_Code((CHAR*)"  LD B,#0xBF", 13);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD A,#1", 10);
	Asm_Code((CHAR*)"  LD B,#0xFF", 13);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD A,(HL)", 12);
	Asm_Code((CHAR*)"  INC HL", 9);
	Asm_Code((CHAR*)"  LD (PlayPos+1),HL", 20);
	Asm_Code((CHAR*)"  AND #15", 10);
	Asm_Code((CHAR*)"  RET Z", 8);
	Asm_Code((CHAR*)"  DEC A", 8);
	Asm_Code((CHAR*)"  LD B,#0xBF", 13);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  XOR A", 8);
	Asm_Code((CHAR*)"  LD B,#0xFF", 13);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD A,(HL)", 12);
	Asm_Code((CHAR*)"  INC HL", 9);
	Asm_Code((CHAR*)"  LD (PlayPos+1),HL", 20);
	Asm_Code((CHAR*)"  LD B,#0xBF", 13);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
}

/*----------------------------------------------------------------------------*/
void Sound_Quit (void)
{
	Asm_Code((CHAR*)"  DI", 5);
	Asm_Code((CHAR*)"  LD BC,#0xFFFD", 16);
	Asm_Code((CHAR*)"  LD A,#7", 10);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD B,#0xBF", 13);
	Asm_Code((CHAR*)"  LD A,#254", 12);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD B,#0xFF", 13);
	Asm_Code((CHAR*)"  LD A,#8", 10);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  LD B,#0xBF", 13);
	Asm_Code((CHAR*)"  XOR A", 8);
	Asm_Code((CHAR*)"  OUT (C),A", 12);
	Asm_Code((CHAR*)"  EI", 5);
}

/*----------------------------------------------------------------------------*/

export void *Sound__init(void)
{
	__DEFMOD;
	__IMPORT(Asm__init);
	__REGMOD("Sound", 0);
	__REGCMD("Quit", Sound_Quit);
	__REGCMD("RunMe50Hz", Sound_RunMe50Hz);
/* BEGIN */
	__ENDMOD;
}
