MODULE TestTasks; (*$MAIN*)
IMPORT co := Tasks, out := Console, Timer;

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
  i := 0; WHILE str[i] # 0X DO out.WriteCh(str[i]); INC(i); co.Yield END;
END Proc;

BEGIN
  co.Spawn(task1, Proc);
  co.Spawn(task2, Proc);
  co.Spawn(task3, Proc);
  WHILE co.Run() # 0 DO Timer.Delay(100) END;
END TestTasks.
