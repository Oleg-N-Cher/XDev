void Console_At (char x, char y);
void Console_Clear (void);
void Console_WriteCh (char ch);

/*============================================================================*/

void Console_At (char x, char y) __naked {
__asm
  POP  HL
  POP  DE
  PUSH DE
  PUSH HL
  LD   L, E
  LD   H, D
  JP   0x00C6 ; POSIT --- set cursor pos
__endasm;
} //Console_At

/*----------------------------------------------------------------------------*/
void Console_Clear (void) __naked {
__asm
  LD   A, #0x1B
  CALL 0x00A2 ; CHPUT --- displays one character
  LD   A, #0x45
  JP   0x00A2 ; CHPUT --- displays one character
__endasm;
}

/*----------------------------------------------------------------------------*/
void Console_WriteCh (char ch) __naked {
__asm
  LD   HL, #2
  ADD  HL, SP
  LD   A, (HL)
  JP   0x00A2 ; CHPUT --- displays one character
__endasm;
} //Console_WriteCh
