/*  Ofront 1.2 -xtspkae */

#ifndef Timer__h
#define Timer__h

#include "SYSTEM.h"
#include "TimerCfg.h"

#define __hash__ #
#define __id__(x) x
#define __ld_de__(x) __asm ld de,__id__(__hash__)x __endasm

import void Timer_Delay_HALT_DI_stdcall (INTEGER msec);
import void Timer_Delay_HALT_DI_fastcall (void /*DE*/);
import void Timer_Delay_HALT_EI_stdcall (INTEGER msec);
import void Timer_Delay_HALT_EI_fastcall (void /*DE*/);
import void Timer_Delay_Ex_stdcall (INTEGER msec);
import void Timer_Delay_Ex_fastcall (void /*DE*/);


#ifdef DELAY_HALT
#  ifdef MODE_DI
#    ifndef DELAY_fastcall
#      define Timer_Delay(ms)	Timer_Delay_HALT_DI_stdcall(x/20)
#    else
#      define Timer_Delay(ms) __ld_de__(ms); Timer_Delay_HALT_DI_fastcall()
#    endif
#  else
#    ifndef DELAY_fastcall
#      define Timer_Delay(ms)	Timer_Delay_HALT_EI_stdcall(x/20)
#    else
#      define Timer_Delay(ms) __ld_de__(ms); Timer_Delay_HALT_EI_fastcall()
#    endif
#  endif
#else
#  ifndef DELAY_fastcall
#    define Timer_Delay	Timer_Delay_Ex_stdcall
#  else
#    define Timer_Delay(ms) __ld_de__(ms); Timer_Delay_Ex_fastcall()
#  endif
#endif

#define Timer__init()


#endif
