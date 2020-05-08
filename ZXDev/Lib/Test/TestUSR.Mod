MODULE TestUSR; (*$MAIN*)
IMPORT b := Basic, SYSTEM;

TYPE ProcUSR = PROCEDURE (color: BYTE);

VAR border: ProcUSR;

BEGIN
  b.Init;
  b.POKE(65000, 0E1H); (* POP HL *)
  b.POKE(65001, 0C1H); (* POP BC *)
  b.POKE(65002, 0C5H); (* PUSH BC *)
  b.POKE(65003, 79H);  (* LD A, C *)
  b.POKE(65003, 0D3H); b.POKE(65004, 0FEH); (* OUT (254), A *)
  b.POKE(65005, 0E9H); (* JP (HL)  *)
  border := SYSTEM.VAL(ProcUSR, 65000);
  (* ֲûחמג *)
  border(b.Yellow);
  b.Quit
END TestUSR.