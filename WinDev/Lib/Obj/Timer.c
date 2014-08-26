/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"
#include "Input.h"
#include "SdlLib.h"




export void Timer_Delay (INTEGER msec);


/*============================================================================*/

void Timer_Delay (INTEGER msec)
{
	if (Input_Available() == 0) {
	}
	SdlLib_Delay(msec);
	if (Input_Available() == 0) {
	}
}

/*----------------------------------------------------------------------------*/

export void *Timer__init(void)
{
	__DEFMOD;
	__IMPORT(Input__init);
	__IMPORT(SdlLib__init);
	__REGMOD("Timer", 0);
/* BEGIN */
	__ENDMOD;
}
