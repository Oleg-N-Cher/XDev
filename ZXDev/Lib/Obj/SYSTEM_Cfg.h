/*  Ofront 1.2 SYSTEM config */

#ifndef __SYSTEM_Cfg__h
#define __SYSTEM_Cfg__h

/* runtime system routines */
//#define SYSTEM_Cfg_IncRef

/* module registry */
//#define SYSTEM_Cfg_RegisterModules
//#define SYSTEM_Cfg_RegisterMain
//#define SYSTEM_Cfg_RegisterCommands

/* record type descriptors */
//#define SYSTEM_Cfg_RecTypeDesc
//#define SYSTEM_Cfg_InitTypes

/* Oberon-2 type bound procedures support */
//#define SYSTEM_Cfg_TypeBoundProcDynCalls

/* std procs and operator mappings */
#define SYSTEM_Cfg_DIV_as_in_C
#define SYSTEM_Cfg_MOD_as_in_C
#define SYSTEM_Cfg_NoASSERT

/* runtime checks */
#define SYSTEM_Cfg_NoCheck_X
#define SYSTEM_Cfg_NoCheck_CASE

/* Garbage collector */
//#define SYSTEM_Cfg_NoGC
//#define SYSTEM_Cfg_Use_HEAP

#endif
