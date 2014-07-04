MODULE AsmTest;
IMPORT Asm;

PROCEDURE Border* (color: SHORTINT);
BEGIN
  Asm.Code("LD   A,4(IX)");
  Asm.Code("CALL 0x229B ");
END Border;

BEGIN (*$MAIN*)
  Border(2);
END AsmTest.