MODULE GRAPH0; (* For the ZX Spectrum  (c) Mira Software 1991 *)

(** This module provides the elementary procedures
    used by theother graphics modules.

    CLS2 clears the screen, but not the attributes area, while
    GCLS clears the screen and attributes.
    SETATTRS(X,Y,L,C) sets L character squares to have attribute C
        starting at character position (X,Y).
    SCRDOT and SCRNAD are imported by other graphic modules,
        and are not useable as procedures on their own. *)

IMPORT S := SYSTEM, Asm;

CONST
  width* = 256; height* = 192;

PROCEDURE CLS2* ; (** clears the screen, but not the attributes area. *)
BEGIN
  Asm.Code("LD   A, (#0x5C8D) ;ATTR_P   ");
  Asm.Code("LD   B, #0x18               ");
  Asm.Code("EXX                         ");
  Asm.Code("LD   HL, #0x5B00  ;SWAP_PAGE");
  Asm.Code("JP   _GRAPH0_GCLS+20        ");
END CLS2;

PROCEDURE GCLS* ; (** clears the screen and attributes. *)
BEGIN
  Asm.Code("XOR  A                      ");
  Asm.Code("LD   B, #0xBF               ");
  Asm.Code("EXX                         ");
  Asm.Code("LD   HL, #0x5800            ");
  Asm.Code("CALL _GRAPH0_GCLS+20        ");
  Asm.Code("LD   HL, #0x4000            ");
  Asm.Code("LD   B, #0x20               ");
  Asm.Code("LD   (HL), A                ");
  Asm.Code("INC  L                      ");
  Asm.Code("DJNZ .-2                    ");
  Asm.Code("RET                         ");
(*_GRAPH0_GCLS+20:*)
  Asm.Code("EXX                         ");
  Asm.Code("LD   D, A                   ");
  Asm.Code("LD   E, A                   ");
  Asm.Code("LD   HL, #0x0000            ");
  Asm.Code("ADD  HL, SP                 ");
  Asm.Code("EXX                         ");
  Asm.Code("LD   SP, HL                 ");
  Asm.Code("EXX                         ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("PUSH DE                     ");
  Asm.Code("DJNZ .-16                   ");
  Asm.Code("LD   SP, HL                 ");
(*Safe RETURN to BASIC:*)
  Asm.Code("LD   HL, #0x2758            ");
  Asm.Code("EXX                         ");
END GCLS;

PROCEDURE SETATTRS* (X, Y: S.CARDINAL; L, C: S.SHORTCARD); (** sets L character
  squares to have attribute C starting at character position (X, Y). *)
BEGIN
  Asm.Code("POP  BC                     ");
  Asm.Code("POP  DE                     ");
  Asm.Code("POP  HL                     ");
  Asm.Code("LD   A, E                   ");
  Asm.Code("AND  A, #0x1F               ");
  Asm.Code("LD   E, A                   ");
  Asm.Code("LD   A, L                   ");
  Asm.Code("RRCA                        ");
  Asm.Code("RRCA                        ");
  Asm.Code("RRCA                        ");
  Asm.Code("LD   D, A                   ");
  Asm.Code("AND  A, #0xE0               ");
  Asm.Code("OR   E                      ");
  Asm.Code("LD   L,A                    ");
  Asm.Code("LD   A,D                    ");
  Asm.Code("AND  A, #0x03               ");
  Asm.Code("OR   A, #0x58               ");
  Asm.Code("LD   H, A                   ");
  Asm.Code("POP  DE                     ");
  Asm.Code("PUSH BC                     ");
  Asm.Code("PUSH BC                     ");
  Asm.Code("PUSH BC                     ");
  Asm.Code("PUSH BC                     ");
  Asm.Code("LD   B, E                   ");
  Asm.Code("INC  B                      ");
  Asm.Code("JR   B07E$                  ");
Asm.Code("B07C$:");
  Asm.Code("LD   (HL), D                ");
  Asm.Code("INC  HL                     ");
Asm.Code("B07E$:");
  Asm.Code("DJNZ B07C$                  ");
END SETATTRS;

PROCEDURE SCRDOT* ; (** imported by other graphic modules. *)
BEGIN
  Asm.Code("LD   A, D                   ");
  Asm.Code("AND  A, #7                  ");
  Asm.Code("ADD  A, #0x18               ");
  Asm.Code("LD   L, A                   ");
  Asm.Code("LD   H, #0xBD               ");
  Asm.Code("LD   A, D                   ");
  Asm.Code("LD   D, (HL)                ");
END SCRDOT;

PROCEDURE SCRNAD* ; (** imported by other graphic modules. *)
BEGIN
  Asm.Code("RRCA                        ");
  Asm.Code("RRCA                        ");
  Asm.Code("RRCA                        ");
  Asm.Code("AND  A, #0x1F               ");
  Asm.Code("LD   L, A                   ");
  Asm.Code("LD   A, E                   ");
  Asm.Code("RLCA                        ");
  Asm.Code("RLCA                        ");
  Asm.Code("AND  A, #0xE0               ");
  Asm.Code("OR   L                      ");
  Asm.Code("LD   L, A                   ");
  Asm.Code("LD   A, E                   ");
  Asm.Code("AND  A, #7                  ");
  Asm.Code("LD   B, A                   ");
  Asm.Code("LD   A, E                   ");
  Asm.Code("RRCA                        ");
  Asm.Code("SCF                         ");
  Asm.Code("RRA                         ");
  Asm.Code("SCF                         ");
  Asm.Code("RRA                         ");
  Asm.Code("AND  A, #0x58               ");
  Asm.Code("OR   B                      ");
  Asm.Code("LD   H, A                   ");
END SCRNAD;

PROCEDURE- _init* "/*noinit*/";
END GRAPH0.
