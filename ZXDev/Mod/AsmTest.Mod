MODULE AsmTest;
IMPORT _ := Asm;
 
BEGIN (*$MAIN*)
  _.Byte2( 3EH,   1); (* LD   A, #1 *)
  _.Byte2(0D3H,0FEH); (* OUT  (#0xFE), A *)
END AsmTest.