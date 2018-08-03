MODULE AsmTest;
IMPORT Asm;

PROCEDURE Border (color: BYTE);
BEGIN
  Asm.Code("POP  DE    ");
  Asm.Code("POP  HL    ");
  Asm.Code("PUSH HL    ");
  Asm.Code("PUSH DE    ");
  Asm.Code("LD   A,L   ");
  Asm.Code("JP   0x229B");
END Border;

BEGIN (*$MAIN*)
  Border(2);
END AsmTest.