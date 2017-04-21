#ifndef NewSupercode__h
#define NewSupercode__h

#include "SYSTEM.h"

import void NewSupercode__2WIERSZE (SYSTEM_ADR adr);
import void NewSupercode_EKRAN1 (SYSTEM_ADR adr);
import void NewSupercode_EKRAN2 (SYSTEM_ADR adr);
import void NewSupercode_EKRAN3 (SYSTEM_ADR adr);
import void NewSupercode_EKRAN4 (SYSTEM_ADR adr);
import void NewSupercode_SIATKA (SHORTCARD x, SHORTCARD y, SYSTEM_ADR ramtop);
import void NewSupercode_DZWIEK_1 (void);
import void NewSupercode_DZWIEK_2 (void);
import void NewSupercode_DZWIEK_3 (void);
import void NewSupercode_EKRAN_1 (SHORTCARD x);
import void NewSupercode_EKRAN_2 (SHORTCARD x);
import void NewSupercode_LITERY_ (SHORTCARD x, SHORTCARD y, SHORTCARD xs,
  SHORTCARD ys, SHORTCARD wdth, CHAR *str);
#define NewSupercode_LITERY(x, y, xs, ys, wdth, str, str__len) NewSupercode_LITERY_ (x, y, xs, ys, wdth, str)
#define NewSupercode__init()

#endif
