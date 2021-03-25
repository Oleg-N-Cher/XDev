MODULE AsmTest;
IMPORT Asm;

PROCEDURE Border (color: INT8);
BEGIN
  Asm.Code("POP  BC    ");
  Asm.Code("POP  DE    ");
  Asm.Code("POP  HL    ");
  Asm.Code("PUSH HL    ");
  Asm.Code("PUSH DE    ");
  Asm.Code("PUSH BC    ");
  Asm.Code("LD   A,L   ");
  Asm.Code("CALL 0x229B");
END Border;

BEGIN (*$MAIN*)
  Border(2);
END AsmTest.
