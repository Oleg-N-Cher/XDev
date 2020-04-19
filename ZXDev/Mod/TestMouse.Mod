MODULE TestMouse; (*$MAIN*)
IMPORT B := Basic, Cursor, Key := Control, Asm;

VAR x, y: BYTE; pressed: SET;

PROCEDURE ProcIM2;
BEGIN
  Asm.Code("PUSH AF        ");
  Asm.Code("PUSH BC        ");
  Asm.Code("PUSH DE        ");
  Asm.Code("PUSH HL        ");
  Cursor.Hide;
  Cursor.Draw(x, y);
  Asm.Code("LD   IY,#0x5C3A");
  Asm.Code("RST  0x38      ");
  Asm.Code("POP  HL        ");
  Asm.Code("POP  DE        ");
  Asm.Code("POP  BC        ");
  Asm.Code("POP  AF        ");
END ProcIM2;

BEGIN
  B.Init; Cursor.Init(Cursor.Std);
  x := 100; y := 100; Cursor.Draw(x, y); B.IM2PROC(ProcIM2);
  LOOP
    pressed := Key.Get();
    IF Key.Left IN pressed THEN DEC(x) END;
    IF Key.Right IN pressed THEN INC(x) END;
    IF Key.Up IN pressed THEN DEC(y) END;
    IF Key.Down IN pressed THEN INC(y) END;
    IF Key.Fire IN pressed THEN EXIT END;
  END;
  B.Quit
END TestMouse.
