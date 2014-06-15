/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"




export void Ignore_Bool (BOOLEAN b);
export void Ignore_Char (CHAR ch);
export void Ignore_Int (LONGINT i);
export void Ignore_Ptr (SYSTEM_PTR ptr);
export void Ignore_Real (LONGREAL r);
export void Ignore_Set (SET s);


/*============================================================================*/

void Ignore_Bool (BOOLEAN b)
{
}

/*----------------------------------------------------------------------------*/
void Ignore_Char (CHAR ch)
{
}

/*----------------------------------------------------------------------------*/
void Ignore_Int (LONGINT i)
{
}

/*----------------------------------------------------------------------------*/
void Ignore_Real (LONGREAL r)
{
}

/*----------------------------------------------------------------------------*/
void Ignore_Ptr (SYSTEM_PTR ptr)
{
}

/*----------------------------------------------------------------------------*/
void Ignore_Set (SET s)
{
}

/*----------------------------------------------------------------------------*/

export void *Ignore__init(void)
{
	__DEFMOD;
	__REGMOD("Ignore", 0);
/* BEGIN */
	__ENDMOD;
}
