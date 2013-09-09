/*  Ofront 1.2 -xtspkae */

#ifndef Best40__h
#define Best40__h

#include "SYSTEM.h"


import INTEGER Best40_attrib;


import void Best40_ACHANGE (INTEGER attr_and, INTEGER attr_or);
import void Best40_AREPLC (INTEGER attr_from, INTEGER attr_to);
import void Best40_ASRL_DN (void);
import void Best40_ASRL_LF (void);
import void Best40_ASRL_RG (void);
import void Best40_ASRL_UP (void);
import void Best40_PAINT (INTEGER x, INTEGER y);
import void Best40_PFIGURE (INTEGER x, INTEGER y, CHAR *pattern, LONGINT pattern__len);
import BOOLEAN Best40_POINT (INTEGER x, INTEGER y);
import void Best40_PSCALER (INTEGER x1_old, INTEGER y1_old, INTEGER x2_old, INTEGER y2_old, INTEGER xscale, INTEGER yscale, INTEGER x_new, INTEGER y_new);
import void Best40_PSRL_DN (void);
import void Best40_PSRL_LF (void);
import void Best40_PSRL_RG (void);
import void Best40_PSRL_UP (void);
import void Best40_SCR_INV (void);
import void Best40_SCR_MRG (INTEGER scr_addr);
import void Best40_SINV_LR (INTEGER char_addr);
import void Best40_SINV_UD (INTEGER char_addr);
import void Best40_SROTATE (INTEGER char_addr);
import void Best40_SSRL_DN (void);
import void Best40_SSRL_LF (void);
import void Best40_SSRL_RG (void);
import void Best40_SSRL_UP (void);
import void *Best40__init(void);


#endif
