/*  Ofront 1.2 SYSTEM config */

#ifndef __SYSTEM_Cfg__h
#define __SYSTEM_Cfg__h

/* depending on kernel32.dll or msvcrt.dll */
#define SYSTEM_Cfg_KERNEL32
//#define SYSTEM_Cfg_MSVCRT

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

/* Garbage collector */
#define SYSTEM_Cfg_NoGC

/* runtime checks */
#define SYSTEM_Cfg_NoCheck_X
#define SYSTEM_Cfg_NoASSERT

#endif
