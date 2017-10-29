#include "SYSTEM.h"

typedef
  struct Tasks_Context {
    int SP, next;
    // char stack [N];
    // int IX, PC, _RETURN;
  } Tasks_Context;

unsigned char Tasks_count;
int Tasks_myid, Tasks_current;

/*----------------------------------------------------------------------------*/
void _Tasks_RETURN (void) __naked {
  __asm
           LD   HL, #_Tasks_count
           DEC  (HL)
           ;JR   Z, LOAD_RUN$
           
// Load Run() context (IX, SP)
LOAD_RUN$: LD   HL, (_Tasks_current) ; ADR(Context.sp)
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
unsigned char Tasks_Run (void) {
  __asm
// Prevent the threat of re-entry
           ;LD   HL, (_Tasks_current)
           ;LD   L, A
           ;OR   H
           ;JR   Z, EXIT_RUN$ ; current = 0: "main" task

// Save IX, SP
           PUSH IX
           LD   (__Run_SP+1), SP
           
// Call one atom of the current task (until Yield or RETURN)
           LD   HL, (_Tasks_current) ; ADR(Context.SP)
           LD   A, (HL)
           INC  HL
           LD   H, (HL)
           LD   L, A
           LD   SP, HL               ; (Context.SP)
           POP  IX
           ;RET                      ; CALL current task
  __endasm;
  // RETURN count moved to Yield
} //Tasks_Run

/*----------------------------------------------------------------------------*/
void Tasks_Yield (void) {
  __asm
.globl __Run_SP
// Save current context (IX, SP)
           PUSH IX
           LD   HL, (_Tasks_current) ; ADR(Context.sp)
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
           LD  HL, (_Tasks_count)
  __endasm;
} //Tasks_Yield

/*----------------------------------------------------------------------------*/
void Tasks__init (void) {
  Tasks_count = 0; Tasks_myid = 0;
}
