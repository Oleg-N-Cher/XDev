MODULE Debug;
IMPORT SYSTEM, Asm, Basic;

VAR a: SHORTINT; bc, de, hl, ix, iy: INTEGER;

PROCEDURE SaveIX* ;
BEGIN
  Asm.Code("LD (_Debug_ix), IX");
END SaveIX;

PROCEDURE CheckIX* ;
BEGIN
  Asm.Code("PUSH IX");
  Asm.Code("POP  DE");
  Asm.Code("LD   HL, (_Debug_ix)");
  Asm.Code("AND  A");
  Asm.Code("SBC  HL, DE");
  Asm.Code("RET  Z");
  Basic.COLOR(Basic.Red); Basic.PRSTR("IX broken"); Basic.PAUSE(0);
END CheckIX;

PROCEDURE SaveRegs* ;
BEGIN
  Asm.Code("LD (_Debug_a) , A ");
  Asm.Code("LD (_Debug_bc), BC");
  Asm.Code("LD (_Debug_de), DE");
  Asm.Code("LD (_Debug_hl), HL");
  Asm.Code("LD (_Debug_ix), IX");
  Asm.Code("LD (_Debug_iy), IY");
END SaveRegs;

PROCEDURE SaveRegsDef* ;
BEGIN
  Asm.Code("LD A , #0x33      ");
  Asm.Code("LD BC, #0x4455    ");
  Asm.Code("LD DE, #0x6677    ");
  Asm.Code("LD HL, #0x8899    ");
  Asm.Code("LD IX, #0xAABB    ");
  Asm.Code("LD IY, #0xCCDD    ");
  Asm.Code("LD (_Debug_a), A  ");
  Asm.Code("LD (_Debug_bc), BC");
  Asm.Code("LD (_Debug_de), DE");
  Asm.Code("LD (_Debug_hl), HL");
  Asm.Code("LD (_Debug_ix), IX");
  Asm.Code("LD (_Debug_iy), IY");
END SaveRegsDef;

PROCEDURE CheckRegs* ;
BEGIN
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");
    Asm.Code("PUSH AF"); Asm.Code("PUSH HL");
    Basic.COLOR(Basic.Green);
    Asm.Code("POP  HL"); Asm.Code("POP  AF");

  (* A *)

  Asm.Code("LD   B, A");
  Asm.Code("LD   A, (_Debug_a)");
  Asm.Code("CP   B");
  Asm.Code("JR   NZ, NoA$");
    Basic.PRSTR("A ");
  Asm.Code("NoA$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  (* BC *)

  Asm.Code("LD   A, (_Debug_bc+1)");
  Asm.Code("CP   B");
  Asm.Code("JR   NZ, NoB$");
    Basic.PRSTR("B ");
  Asm.Code("NoB$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  Asm.Code("LD   A, (_Debug_bc)");
  Asm.Code("CP   C");
  Asm.Code("JR   NZ, NoC$");
    Basic.PRSTR("C ");
  Asm.Code("NoC$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  (* DE *)
  Asm.Code("LD   A, (_Debug_de+1)");
  Asm.Code("CP   D");
  Asm.Code("JR   NZ, NoD$");
    Basic.PRSTR("D ");
  Asm.Code("NoD$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  Asm.Code("LD   A, (_Debug_de)");
  Asm.Code("CP   E");
  Asm.Code("JR   NZ, NoE$");
    Basic.PRSTR("E ");
  Asm.Code("NoE$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  (* HL *)
  Asm.Code("LD   A, (_Debug_hl+1)");
  Asm.Code("CP   H");
  Asm.Code("JR   NZ, NoH$");
    Basic.PRSTR("H ");
  Asm.Code("NoH$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  Asm.Code("LD   A, (_Debug_hl)");
  Asm.Code("CP   L");
  Asm.Code("JR   NZ, NoL$");
    Basic.PRSTR("L ");
  Asm.Code("NoL$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");
  Asm.Code("PUSH AF"); Asm.Code("PUSH BC"); Asm.Code("PUSH DE");
  Asm.Code("PUSH HL"); Asm.Code("PUSH IX"); Asm.Code("PUSH IY");

  (* IY *)

  Asm.Code("PUSH IY             ");
  Asm.Code("POP  DE             ");
  Asm.Code("LD   HL, (_Debug_iy)");
  Asm.Code("AND  A");
  Asm.Code("SBC  HL, DE");
  Asm.Code("JR   NZ, NoIY$");
    Basic.PRSTR("IY ");
  Asm.Code("NoIY$: ");

  Asm.Code("POP  IY"); Asm.Code("POP  IX"); Asm.Code("POP  HL");
  Asm.Code("POP  DE"); Asm.Code("POP  BC"); Asm.Code("POP  AF");

  (* IX *)

  Asm.Code("PUSH IX             ");
  Asm.Code("POP  DE             ");
  Asm.Code("LD   HL, (_Debug_ix)");
  Asm.Code("AND  A");
  Asm.Code("SBC  HL, DE");
  Asm.Code("JR   Z, YesIX$");
    Basic.COLOR(Basic.Red); Basic.PRSTR("IX");
  Asm.Code("YesIX$: ");

  Basic.PRLN;
END CheckRegs;

END Debug.
