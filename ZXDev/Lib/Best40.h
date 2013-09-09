#ifndef Best40__h
#define Best40__h

#include "SYSTEM.h"

import SHORTINT Best40_attrib;

import void Best40_ASRL_LF (void);
import void Best40_ASRL_RG (void);
import void Best40_ASRL_UP (void);
import void Best40_ASRL_DN (void);
import void Best40_SSRL_LF (void);
import void Best40_SSRL_RG (void);
import void Best40_SSRL_UP (void);
import void Best40_SSRL_DN (void);
import void Best40_PSRL_LF (void);
import void Best40_PSRL_RG (void);
import void Best40_PSRL_UP (void);
import void Best40_PSRL_DN (void);
import void Best40_SCR_MRG (SYSTEM_ADDRESS scr_addr);
import void Best40_SCR_INV (void);
import void Best40_SINV_UD (SYSTEM_ADDRESS char_addr);
import void Best40_SINV_LR (SYSTEM_ADDRESS char_addr);
import void Best40_SROTATE (SYSTEM_ADDRESS char_addr);
import void Best40_ACHANGE (SHORTINT attr_and, SHORTINT attr_or);
import void Best40_AREPLC (SHORTINT attr_from, SHORTINT attr_to);
import void Best40_PAINT (SHORTINT x, SHORTINT y);
import BOOLEAN Best40_POINT (SHORTINT x, SHORTINT y);
import void Best40_PFIGURE_E (SHORTINT x, SHORTINT y, CHAR *pattern);
#define Best40_PFIGURE(x,y,pattern,len) Best40_PFIGURE_E(x,y,pattern)
import void Best40_PSCALER (
  SHORTINT x1_old, SHORTINT y1_old, SHORTINT x2_old, SHORTINT y2_old,
  SHORTINT xscale, SHORTINT yscale, SHORTINT x_new, SHORTINT y_new);

#define Best40__init()

#endif
