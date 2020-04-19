/*==================== Configuration file of XDev library ====================*/

/*--------------------------------- Console ----------------------------------*/

/* Use ROM output (RST 10H, slow, 32x22) or COMPACT/FAST (fast, 32x24) */

#define Console_OUTPUT_COMPACT
//#define Console_OUTPUT_FAST
//#define Console_OUTPUT_ROM

/*---------------------------------- Input -----------------------------------*/

#define Input_KeyNoRepeat
//#define Input_KeyRepeat
//#define Input_KeyRepeatBuf

//#define Input_KeyRepeatCount 15

/*---------------------------------- Timer -----------------------------------*/

//#define Timer_MODE_DI
//#define Timer_MODE_EI
//#define Timer_DELAY_HALT
#define Timer_DELAY_fastcall

/*---------------------------------- SYSTEM ----------------------------------*/

/* Runtime system routines */
//#define SYSTEM_IncRef

/* Module registry */
//#define SYSTEM_RegisterModules
//#define SYSTEM_RegisterMain
//#define SYSTEM_RegisterCommands

/* Record type descriptors */
//#define SYSTEM_RecTypeDesc
//#define SYSTEM_InitTypes

/* Oberon-2 type bound procedures support */
//#define SYSTEM_TypeBoundProcDynCalls

/* Std procs and operator mappings */
#define SYSTEM_DIV_as_in_C
#define SYSTEM_MOD_as_in_C
#define SYSTEM_NoASSERT

/* Runtime checks */
#define SYSTEM_NoCheck_CASE
#define SYSTEM_NoCheck_RETURN

/* Garbage collector */
#define SYSTEM_NoGC
//#define SYSTEM_Use_HEAP

