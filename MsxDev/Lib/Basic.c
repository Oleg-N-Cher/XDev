void Basic_CLS (void);
void Basic_COLOR (char fore, char back, char border);
void Basic_LINE_BASIC (int x1, int y1, int x2, int y2);
void Basic_LINE_EBIOS (int x1, int y1, int x2, int y2);
void Basic_LOCATE (char x, char y);
void Basic_SCREEN_BIOS (char mode);
void Basic_SCREEN_ISLT (char mode);
char Basic_VPEEK (unsigned int addr);
void Basic_VPOKE (unsigned int addr, char value);
void Basic_WIDTH (char width);
/*============================================================================*/

void Basic_CLS (void) __naked {
__asm
  LD   A, #0x1B
  CALL 0x00A2 ; CHPUT --- displays one character
  LD   A, #0x45
  JP   0x00A2 ; CHPUT --- displays one character
__endasm;
} //Basic_CLS

/*----------------------------------------------------------------------------*/
// Specifies the colours of each part of the screen.
void Basic_COLOR (char fore, char back, char border) __naked {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   DE, #0xF3E9 ; FORCLR, BAKCLR, BDRCLR
  LD   BC, #3
  LDIR
  JP 0x0062 ; CHGCLR --- change color
__endasm;
} //Basic_COLOR

/*----------------------------------------------------------------------------*/
void Basic_LINE_BASIC (int x1, int y1, int x2, int y2) {
//http://www.msx.org/forum/development/msx-development/use-command-graphics-basic-linedrawcirclepaint-code-assembler?page=0
__asm
  POP  IY ; ret addr
  POP  HL
  LD   (0xFCB3), HL ; GXPOS
  POP  HL
  LD   (0xFCB5), HL ; GYPOS
  POP  BC
  POP  DE
  PUSH HL
  PUSH HL
  PUSH HL
  PUSH HL
  PUSH IY ; ret addr
  PUSH IX
  LD   IX, #0x58FC ; bios_line
  CALL 0x0159 ; bios_basic
  POP  IX
__endasm;
} //Basic_LINE_BASIC

/*----------------------------------------------------------------------------*/
void Basic_LINE_EBIOS (int x1, int y1, int x2, int y2) {
__asm
  POP  IY ; ret addr
  POP  HL
  LD   (0xFCB3), HL ; GXPOS
  POP  HL
  LD   (0xFCB5), HL ; GYPOS
  POP  BC
  POP  DE
  PUSH HL
  PUSH HL
  PUSH HL
  PUSH HL
  PUSH IY ; ret addr
  XOR  A
  LD   (0xFB02), A ; LOGOPR
  LD   IY, (0xFAF8-1) ; (EXBRASA-1)
  PUSH IX
  LD   IX, #0x0085 ; DOGRPH
  CALL 0x001C ; CALSLT
  POP  IX
__endasm;
} //Basic_LINE_EBIOS

/*----------------------------------------------------------------------------*/
void Basic_LOCATE (char x, char y) __naked {
__asm
  POP  HL
  POP  DE
  PUSH DE
  PUSH HL
  LD   L, E
  LD   H, D
  JP   0x00C6 ; POSIT --- set cursor pos
__endasm;
} //Basic_LOCATE

/*----------------------------------------------------------------------------*/
void Basic_SCREEN_BIOS (char mode) __naked {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)       ; mode
  JP   0x005F        ; CHGMOD --- go to screen mode
__endasm;
} //Basic_SCREEN_BIOS

/*----------------------------------------------------------------------------*/
void Basic_SCREEN_ISLT (char mode) {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)       ; mode
  LD   IY, (0xFCC0) ; (EXPTBL-1)
  PUSH IX
  LD   IX, #0x005F   ; CHGMOD
  CALL 0x001C        ; CALSLT
  EI
  POP  IX
__endasm;
} //Basic_SCREEN_ISLT

/*----------------------------------------------------------------------------*/
char Basic_VPEEK (unsigned int addr) {
__asm
  POP  DE
  POP  HL
  PUSH HL
  PUSH DE
  CALL 0x004A ; RDVRM --- reads the content of VRAM
  LD   L, A
__endasm;
} //Basic_VPEEK

/*----------------------------------------------------------------------------*/
void Basic_VPOKE (unsigned int addr, char value) __naked {
__asm
  POP  DE
  POP  HL
  POP  BC
  PUSH BC
  PUSH HL
  PUSH DE
  LD   A, C
  JP   0x004D ; WRTVRM --- writes data in VRAM
__endasm;
} //Basic_VPOKE

/*----------------------------------------------------------------------------*/
void Basic_WIDTH_BIOS (char width) __naked {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)
  LD   (0xF3AE), A ; (LINL40)
  JP   0x006C ; INITXT
__endasm;
} //Basic_WIDTH_BIOS

/*----------------------------------------------------------------------------*/
void Basic_WIDTH_ISLT (char width) {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)
  LD   (0xF3AE), A  ; (LINL40)
  LD   IY, (0xFCC0) ; (EXPTBL-1)
  PUSH IX
  LD   IX, #0x006C  ; INITXT
  CALL 0x001C       ; CALSLT
  EI
__endasm;
} //Basic_WIDTH_ISLT

/*----------------------------------------------------------------------------*/
void Basic_ATR_BIOS (char color) __naked {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)      ; (color)
  JP   0x011A       ; SETATR
__endasm;
} //Basic_ATR_BIOS

/*----------------------------------------------------------------------------*/
void Basic_ATR_ISLT (char color) {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)      ; (color)
  LD   IY, (0xFCC0) ; (EXPTBL-1)
  PUSH IX
  LD   IX, #0x011A  ; SETATR
  CALL 0x001C       ; CALSLT
  EI
  POP IX
__endasm;
} //Basic_ATR_ISLT
