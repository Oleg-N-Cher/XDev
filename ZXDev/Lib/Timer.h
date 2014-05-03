/*  Ofront 1.2 -xtspkae */

#ifndef Timer__h
#define Timer__h

#include "SYSTEM.h"
#include "TimerCfg.h"


import void Timer_Delay_HALT_DI (INTEGER msec);
import void Timer_Delay_HALT_EI (INTEGER msec);
import void Timer_Delay_Ex (INTEGER msec);

#ifdef DELAY_HALT
#  ifdef MODE_DI
#    define Timer_Delay(x)	Timer_Delay_HALT_DI(x/20)
#  else
#    define Timer_Delay(x)	Timer_Delay_HALT_EI(x/20)
#  endif
#else
#  define Timer_Delay	Timer_Delay_Ex
#endif

#define Timer__init()


#endif
