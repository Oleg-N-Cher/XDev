MODULE MoveBalls; (*$MAIN*)
IMPORT b := Basic, g := Best40, t := Tasks, SYSTEM;

TYPE
  SprBall  = ARRAY 8 OF SHORTCHAR;

CONST
  Ball = SprBall(3CX, 7EX, 0FFX, 0FFX, 0FFX, 0FFX, 7EX, 3CX);

VAR
  task1, task2, task3, task4, task5, task6, task7, task8: t.Small;

PROCEDURE MoveBall;
VAR
  x, y: SHORTINT; sx, sy: BYTE;
BEGIN
  x := b.RND(20, 240); y := b.RND(20, 160);
  sx := SHORT( b.RND(0, 1) ); IF sx = 0 THEN sx := -1 END;
  sy := SHORT( b.RND(0, 1) ); IF sy = 0 THEN sy := -1 END;
  g.PUTSPR(x, y, 1, 8, SYSTEM.ADR(Ball), g.XORSPR);
  LOOP
    g.PUTSPR(x, y, 1, 8, SYSTEM.ADR(Ball), g.XORSPR);
    IF (x < 1) OR (x > 247) THEN sx := -sx END;
    INC(x, sx);
    IF (y < 8) OR (y > 190) THEN sy := -sy END;
    INC(y, sy);
    g.PUTSPR(x, y, 1, 8, SYSTEM.ADR(Ball), g.XORSPR);
    t.Yield;
  END;
END MoveBall;

BEGIN
  b.Init;
  b.COLOR(b.Yellow); b.BORDER(b.Black); b.CLS;
  t.Spawn(task1, MoveBall); t.Spawn(task2, MoveBall);
  t.Spawn(task3, MoveBall); t.Spawn(task4, MoveBall);
  t.Spawn(task5, MoveBall); t.Spawn(task6, MoveBall);
  t.Spawn(task7, MoveBall); t.Spawn(task8, MoveBall);
  LOOP t.Run END
END MoveBalls.
