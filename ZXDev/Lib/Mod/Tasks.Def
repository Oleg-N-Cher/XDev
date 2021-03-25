MODULE [foreign] Tasks; IMPORT SYSTEM; (** non-portable *)

(**
  ERRORS:
    22 "Statement lost" - Run called in not "main" task
    25 "Parameter error" - the task is already spawned
*)

TYPE
  Context = RECORD [notag]
    SP, next: INT16;
    (* stack: ARRAY N OF INT8; *)
    IX, PC, _RETURN: INT16;
  END;

  Low    * = RECORD (Context) stack: ARRAY  20 OF INT8 END;
  Tiny   * = RECORD (Context) stack: ARRAY  40 OF INT8 END;
  Small  * = RECORD (Context) stack: ARRAY  60 OF INT8 END;
  Medium * = RECORD (Context) stack: ARRAY  80 OF INT8 END;
  Large  * = RECORD (Context) stack: ARRAY 100 OF INT8 END;
  Huge   * = RECORD (Context) stack: ARRAY 120 OF INT8 END;

PROCEDURE- Count* (): INT8;
PROCEDURE- Spawn* (VAR ctx: Context; proc: PROCEDURE);
PROCEDURE- Id* (ctx: Context): INT16;
PROCEDURE- MyId* (): INT16;
PROCEDURE- Run* ;
PROCEDURE- Yield* ;

END Tasks.
