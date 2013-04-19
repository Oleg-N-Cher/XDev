/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Mega_INVERT (void);
export void Mega_PLAY (BOOLEAN sound, INTEGER stepLen, INTEGER startFreq, LONGINT stepNum, INTEGER incFreq);


void Mega_INVERT (void)
{
}

void Mega_PLAY (BOOLEAN sound, INTEGER stepLen, INTEGER startFreq, LONGINT stepNum, INTEGER incFreq)
{
}


export void *Mega__init(void)
{
	__DEFMOD;
	__REGMOD("Mega", 0);
	__REGCMD("INVERT", Mega_INVERT);
/* BEGIN */
	__ENDMOD;
}
