/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"


export BOOLEAN EcoBuffer_nonempty, EcoBuffer_nonfull;
static INTEGER EcoBuffer_in, EcoBuffer_out, EcoBuffer_n;
static INTEGER EcoBuffer_buf[100];


export void EcoBuffer_get (INTEGER *x);
export void EcoBuffer_put (INTEGER x);


/*============================================================================*/

void EcoBuffer_put (INTEGER x)
{
	if (EcoBuffer_n < 100) {
		EcoBuffer_buf[__X(EcoBuffer_in, 100)] = x;
		EcoBuffer_in = (int)__MOD(EcoBuffer_in + 1, 100);
		EcoBuffer_n += 1;
		EcoBuffer_nonfull = EcoBuffer_n < 100;
		EcoBuffer_nonempty = 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoBuffer_get (INTEGER *x)
{
	if (EcoBuffer_n > 0) {
		*x = EcoBuffer_buf[__X(EcoBuffer_out, 100)];
		EcoBuffer_out = (int)__MOD(EcoBuffer_out + 1, 100);
		EcoBuffer_n -= 1;
		EcoBuffer_nonempty = EcoBuffer_n > 0;
		EcoBuffer_nonfull = 1;
	}
}

/*----------------------------------------------------------------------------*/

export void *EcoBuffer__init(void)
{
	__DEFMOD;
	__REGMOD("EcoBuffer", 0);
/* BEGIN */
	EcoBuffer_n = 0;
	EcoBuffer_in = 0;
	EcoBuffer_out = 0;
	EcoBuffer_nonempty = 0;
	EcoBuffer_nonfull = 1;
	__ENDMOD;
}
