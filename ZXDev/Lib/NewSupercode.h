/*  Ofront 1.2 -xtspkae */

#ifndef NewSupercode__h
#define NewSupercode__h

#include "SYSTEM.h"


import void NewSupercode_DZWIEK_1 (void);
import void NewSupercode_DZWIEK_2 (void);
import void NewSupercode_DZWIEK_3 (void);
import void NewSupercode_EKRAN_1 (SHORTCARD x);
import void NewSupercode_EKRAN_2 (SHORTCARD x);
import void NewSupercode_LITERY_ (SHORTCARD x, SHORTCARD y, SHORTCARD xs,
  SHORTCARD ys, SHORTCARD wdth, CHAR *str);
#define NewSupercode__init()

#define NewSupercode_LITERY(x, y, xs, ys, wdth, str, str__len) NewSupercode_LITERY_ (x, y, xs, ys, wdth, str)


#endif
