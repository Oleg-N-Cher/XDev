/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"


export INTEGER Best40_attrib;


export void Best40_ACHANGE (INTEGER attr_and, INTEGER attr_or);
export void Best40_AREPLC (INTEGER attr_from, INTEGER attr_to);
export void Best40_ASRL_DN (void);
export void Best40_ASRL_LF (void);
export void Best40_ASRL_RG (void);
export void Best40_ASRL_UP (void);
export void Best40_PAINT (INTEGER x, INTEGER y);
export void Best40_PFIGURE (INTEGER x, INTEGER y, CHAR *pattern, LONGINT pattern__len);
export BOOLEAN Best40_POINT (INTEGER x, INTEGER y);
export void Best40_PSCALER (INTEGER x1_old, INTEGER y1_old, INTEGER x2_old, INTEGER y2_old, INTEGER xscale, INTEGER yscale, INTEGER x_new, INTEGER y_new);
export void Best40_PSRL_DN (void);
export void Best40_PSRL_LF (void);
export void Best40_PSRL_RG (void);
export void Best40_PSRL_UP (void);
export void Best40_SCR_INV (void);
export void Best40_SCR_MRG (INTEGER scr_addr);
export void Best40_SINV_LR (INTEGER char_addr);
export void Best40_SINV_UD (INTEGER char_addr);
export void Best40_SROTATE (INTEGER char_addr);
export void Best40_SSRL_DN (void);
export void Best40_SSRL_LF (void);
export void Best40_SSRL_RG (void);
export void Best40_SSRL_UP (void);


/*============================================================================*/

void Best40_ASRL_LF (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_ASRL_RG (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_ASRL_UP (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_ASRL_DN (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SSRL_LF (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SSRL_RG (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SSRL_UP (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SSRL_DN (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_PSRL_LF (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_PSRL_RG (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_PSRL_UP (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_PSRL_DN (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SCR_MRG (INTEGER scr_addr)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SCR_INV (void)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SINV_UD (INTEGER char_addr)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SINV_LR (INTEGER char_addr)
{
}

/*----------------------------------------------------------------------------*/
void Best40_SROTATE (INTEGER char_addr)
{
}

/*----------------------------------------------------------------------------*/
void Best40_ACHANGE (INTEGER attr_and, INTEGER attr_or)
{
}

/*----------------------------------------------------------------------------*/
void Best40_AREPLC (INTEGER attr_from, INTEGER attr_to)
{
}

/*----------------------------------------------------------------------------*/
void Best40_PAINT (INTEGER x, INTEGER y)
{
}

/*----------------------------------------------------------------------------*/
BOOLEAN Best40_POINT (INTEGER x, INTEGER y)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
void Best40_PFIGURE (INTEGER x, INTEGER y, CHAR *pattern, LONGINT pattern__len)
{
	__DUP(pattern, pattern__len, CHAR);
	__DEL(pattern);
}

/*----------------------------------------------------------------------------*/
void Best40_PSCALER (INTEGER x1_old, INTEGER y1_old, INTEGER x2_old, INTEGER y2_old, INTEGER xscale, INTEGER yscale, INTEGER x_new, INTEGER y_new)
{
}

/*----------------------------------------------------------------------------*/

export void *Best40__init(void)
{
	__DEFMOD;
	__REGMOD("Best40", 0);
	__REGCMD("ASRL_DN", Best40_ASRL_DN);
	__REGCMD("ASRL_LF", Best40_ASRL_LF);
	__REGCMD("ASRL_RG", Best40_ASRL_RG);
	__REGCMD("ASRL_UP", Best40_ASRL_UP);
	__REGCMD("PSRL_DN", Best40_PSRL_DN);
	__REGCMD("PSRL_LF", Best40_PSRL_LF);
	__REGCMD("PSRL_RG", Best40_PSRL_RG);
	__REGCMD("PSRL_UP", Best40_PSRL_UP);
	__REGCMD("SCR_INV", Best40_SCR_INV);
	__REGCMD("SSRL_DN", Best40_SSRL_DN);
	__REGCMD("SSRL_LF", Best40_SSRL_LF);
	__REGCMD("SSRL_RG", Best40_SSRL_RG);
	__REGCMD("SSRL_UP", Best40_SSRL_UP);
/* BEGIN */
	__ENDMOD;
}
