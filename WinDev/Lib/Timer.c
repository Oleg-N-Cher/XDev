/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Input.h"
#include "SdlLib.h"




export void Timer_Delay (INTEGER msec);


void Timer_Delay (INTEGER msec)
{
	if (Input_Available() == 0) {
	}
	SdlLib_Delay(msec);
	if (Input_Available() == 0) {
	}
}

