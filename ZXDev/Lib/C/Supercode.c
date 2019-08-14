
void Supercode_Attribute_Scr_Left (unsigned char x, unsigned char y,
  unsigned char width, unsigned char height, unsigned char wrap,
  unsigned char atr) __z88dk_callee;
void Supercode_Attribute_Scr_Right (unsigned char x, unsigned char y,
  unsigned char width, unsigned char height, unsigned char wrap,
  unsigned char atr) __z88dk_callee;
  
/*================================== Header ==================================*/

void Supercode_Attribute_Scr_Left (unsigned char x, unsigned char y,
  unsigned char width, unsigned char height, unsigned char wrap,
  unsigned char atr) __naked __z88dk_callee
{
  __asm
           POP   HL
           POP   BC              ; x, y
           POP   DE              ; width, height
           EX    (SP), HL
           LD    A, L            ; wrap
           OR    A
           JR    Z, LOC_FEB4$
           LD    A, #0x1A        ; "LD A,(DE)" | "NOP"
LOC_FEB4$: LD    (LOC_FED8$), A
           LD    A, H            ; atr
           LD    HL, #0x57DF
           PUSH  AF
           PUSH  DE
           LD    DE, #0x20
           INC   B
LOC_FEC5$: ADD   HL, DE
           DJNZ  LOC_FEC5$
           LD    B, C
           INC   B
LOC_FECA$: INC   HL
           DJNZ  LOC_FECA$
           POP   DE
           LD    B, D
           POP   AF
LOC_FED0$: PUSH  BC
           LD    B, #0
           LD    C, E
           DEC   C
           PUSH  DE
           PUSH  HL
           POP   DE
LOC_FED8$: LD    A, (DE)
           PUSH  DE
           INC   HL
           LDIR
           LD    (DE), A
           POP   HL
           LD    DE, #0x20
           ADD   HL, DE
           POP   DE
           POP   BC
           DJNZ LOC_FED0$
           RET
  __endasm;
} //Supercode_Attribute_Scr_Left

/*--------------------------------- Cut here ---------------------------------*/
void Supercode_Attribute_Scr_Right (unsigned char x, unsigned char y,
  unsigned char width, unsigned char height, unsigned char wrap,
  unsigned char atr) __naked __z88dk_callee
{
  __asm
           POP   HL
           POP   BC              ; x, y
           POP   DE              ; width, height
           EX    (SP), HL
           LD    A, L            ; wrap
           OR    A
           JR    Z, LOC_FE77$
           LD    A, #0x1A        ; "LD A,(DE)" | "NOP"
LOC_FE77$: LD    (LOC_FEA2$), A
           LD    A, H            ; atr
           LD    HL, #0x57DF
           DEC   D
           PUSH  AF
           LD    A, B
           ADD   D
           LD    B, A
           LD    A, C
           ADD   E
           LD    C, A
           PUSH  DE
           LD    DE, #0x20
           INC   B
LOC_FE8F$: ADD   HL, DE
           DJNZ  LOC_FE8F$
           LD    B, C
LOC_FE93$: INC   HL
           DJNZ  LOC_FE93$
           POP   DE
           LD    B, D
           INC   B
           POP   AF
LOC_FE9A$: PUSH  BC
           LD    B, #0
           LD    C, E
           DEC   C
           PUSH  DE
           PUSH  HL
           POP   DE
LOC_FEA2$: LD    A, (DE)
           PUSH  DE
           DEC   HL
           LDDR
           LD    (DE), A
           POP   HL
           LD    DE, #0xFFE0
           ADD   HL, DE
           POP   DE
           POP   BC
           DJNZ  LOC_FE9A$
           RET
  __endasm;
} //Supercode_Attribute_Scr_Right

