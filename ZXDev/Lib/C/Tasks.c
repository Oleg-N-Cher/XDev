#define SAFE

// ERRORS:
//   22 "Statement lost" - Run() called in not "main" task
//   23 "Invalid stream" - Yield called in "main" task
//   25 "Parameter error"
// http://www.worldofspectrum.org/ZXBasicManual/zxmanappb.html

typedef
  struct Tasks_Context {
    int SP, next;
    // char stack [N];
    // int IX, PC, _RETURN;
  } Tasks_Context;

unsigned char Tasks_count; int Tasks_myid; // Both must go together
int Tasks_current;

/*----------------------------------------------------------------------------*/
void _Tasks_RETURN (void) __naked {
  __asm
           LD   HL, #_Tasks_count
           DEC  (HL)                 ; DEC(count)
           INC  HL
           LD   (HL), A              ;
           INC  HL                   ; myid := 0
           LD   (HL), A              ;

// Load Run() context (IX, SP)
LOAD_RUN$: LD   HL, (_Tasks_current) ; ADR(Context.SP)
           JP   __Run_SP

// Remove completed task, update Context.next
// update Context.next
  __endasm;
} //_Tasks_RETURN

/*----------------------------------------------------------------------------*/
void Tasks_Spawn_Ex (Tasks_Context *ctx, unsigned int size, void (*proc)(void))
  /*__z88dk_callee*/ {

// Context = RECORD
//   SP, next: INTEGER;
//   stack: ARRAY N OF BYTE;
//   IX, PC, _RETURN: INTEGER;
// END;

  // Find the last task in list
  if( Tasks_count == 0 ) {
    Tasks_current = (int)ctx; ctx->next = (int)ctx;
  } else { // Tasks_count >= 1
    int found = Tasks_current;
    for(;;) {
      if( found == (int)ctx ) { Tasks_current = found; return; } // Already run
      if (((Tasks_Context*)found)->next == Tasks_current) break;
      found = ((Tasks_Context*)found)->next;
    }
    // Add new task into the list
    ((Tasks_Context*)found)->next = (int)ctx;
    ctx->next = (int)Tasks_current;
  }
  // Create stack for new task
  {
    int *stack = (int*)((int)ctx + size); // Top of stack
    stack--;                              // 2 bytes for RETURN
    *stack = (int)_Tasks_RETURN;          // RETURN entry point
    stack--;                              // 2 bytes for PC
    *stack = (int)proc;                   // task's entry point
    stack--;                              // 2 bytes for IX
    ctx->SP = (int)stack;                 // task's SP
    Tasks_count++;
  }
} //Tasks_Spawn_Ex

/*----------------------------------------------------------------------------*/
void Tasks_Run (void) __naked { // Run() MUST be started in "main" task
  __asm

#ifdef SAFE
           LD   A, (_Tasks_myid+1)   ;
           OR   A                    ;
           JR   NZ, HALT_22$         ; IF myid # 0 THEN HALT(22)
#endif

// Save IX, SP
           PUSH IX
           LD   (__Run_SP+1), SP
           
// Call one atom of the current task (until Yield or RETURN)
           LD   HL, (_Tasks_current) ; ADR(Context.SP)
           LD   (_Tasks_myid), HL
           LD   A, (HL) ; 7
           INC  HL      ; 6
           LD   H, (HL) ; 7
           LD   L, A    ; 4
           LD   SP, HL  ; 6 => 30    ; (Context.SP)
           POP  IX
           RET                       ; CALL current task

#ifdef SAFE
HALT_22$:  RST  8
           .DB  22                   ; "Statement lost"
#endif

  __endasm;
  // "RETURN count" moved to Yield
} //Tasks_Run

/*----------------------------------------------------------------------------*/
void Tasks_Yield (void) __naked { // Yield MUST NOT be started in "main" task
  __asm
.globl __Run_SP

#ifdef SAFE
           LD   HL, #_Tasks_myid+1   ;
           XOR  A                    ;
           CP   (HL)                 ; IF myid IN {0..255} THEN HALT(23)
           JR   Z, HALT_23$          ;
           LD   (HL), A              ; myid := 0
           DEC  HL                   ;
           LD   (HL), A              ;
#else
           LD   HL, #0               ;
           LD   (_Tasks_myid), HL    ; myid := 0
#endif

// Save current context (IX, SP)
           PUSH IX
           LD   HL, (_Tasks_current) ; ADR(Context.SP)
           LD   (Temp_SP$+2), HL
Temp_SP$:  LD   (0), SP

// Load Run() context (IX, SP)
__Run_SP:  LD   SP, #0
           POP  IX

// Go to next task
           INC  HL
           INC  HL                   ; ADR(Context.next)
           LD   A, (HL)
           INC  HL
           LD   H, (HL)
           LD   L, A
           LD   (_Tasks_current), HL ; (Context.next)

// Run() RETURN count
           LD   HL, (_Tasks_count)
           RET

#ifdef SAFE
HALT_23$:  RST  8
           .DB  23                   ; "Invalid stream"
#endif

  __endasm;
} //Tasks_Yield

/*----------------------------------------------------------------------------*/
void Tasks__init (void) {
  __asm
           LD   HL, #_Tasks_count
           XOR  A                    ;
           LD   (HL), A              ; count = 0
           INC  HL
           LD   (HL), A              ;
           INC  HL                   ; myid = 0
           LD   (HL), A              ;
  __endasm;

} //Tasks__init
