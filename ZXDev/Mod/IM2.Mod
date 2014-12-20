(* This program works when used #define MODE_IM2 in Obj/BasicCfg.h *)
MODULE IM2;
IMPORT B := Basic, Asm;
CONST
  LAST_K = 5C08H; FRAMES_CNTR = 5C78H;

  PROCEDURE ProcIM2;
  BEGIN
    Asm.Code("LD   IY,#0x5C3A");
    Asm.Code("RST  0x38 ");
    Asm.Code("EI");
  END ProcIM2;

BEGIN (*$MAIN*)
  B.Init;
  B.IM2PROC(ProcIM2);
  B.POKE(LAST_K, 0); B.AT(0, 0); B.PRSTR("Press SPACE to exit");
  REPEAT
    B.AT(4, 4); B.PRINT(B.PEEK(LAST_K)); B.PRSTR("   ");
    B.AT(8, 8); B.PRINT(B.PEEK(FRAMES_CNTR)); B.PRSTR("   ");
  UNTIL B.PEEK(LAST_K) = 20H;
  B.Quit;
END IM2.