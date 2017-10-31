MODULE TestTasks; (*$MAIN*)
IMPORT co := Tasks, out := Console;

TYPE
  Message = ARRAY 24 OF CHAR;
CONST
  str = Message("Hello multitask World!");
VAR
  task1, task2, task3: co.Tiny;

PROCEDURE Proc;
VAR
  i: SHORTINT;
BEGIN
  i := 0;
  WHILE str[i] # 0X DO
    IF co.MyId() = co.Id(task1) THEN out.SetColors(out.RedOnBlack   ) END;
    IF co.MyId() = co.Id(task2) THEN out.SetColors(out.YellowOnBlack) END;
    IF co.MyId() = co.Id(task3) THEN out.SetColors(out.GreenOnBlack ) END;
    out.WriteCh(str[i]);
    INC(i);
    co.Yield;
  END;
END Proc;

BEGIN
  co.Spawn(task1, Proc);
  co.Spawn(task2, Proc);
  co.Spawn(task3, Proc);
  WHILE co.Run() # 0 DO END;
END TestTasks.
