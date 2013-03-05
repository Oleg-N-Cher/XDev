/*---------------------------------*/
/* LASER BASIC for SDCC  >>> v3.17 */
/* Adapted to SDCC by Oleg N. Cher */
/*    (Vedanta software), 2011     */
/*    Thanks to Michailov (HVG)    */
/*---------------------------------*/

#ifndef Laser__h
#define Laser__h

#include "SYSTEM.h"

import void Laser_Init (void);
/* Functions for screen windows processing */
import void Laser_INVV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_MIRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_MARV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SETV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_CLSV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_SR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_WCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx);
import void Laser_SCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx);
import void Laser_AWLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_ASLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_AWRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_ASRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_ATUV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void Laser_ATDV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);

/* Functions for sprites manipulations */
import void Laser_CLSM (SHORTCARD spN);
import void Laser_INVM (SHORTCARD spN);
import void Laser_PTBL (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_PTOR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_PTXR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_PTND (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_WL1M (SHORTCARD spN);
import void Laser_WR1M (SHORTCARD spN);
import void Laser_WL4M (SHORTCARD spN);
import void Laser_WR4M (SHORTCARD spN);
import void Laser_WL8M (SHORTCARD spN);
import void Laser_WR8M (SHORTCARD spN);
import void Laser_SL1M (SHORTCARD spN);
import void Laser_SR1M (SHORTCARD spN);
import void Laser_SL4M (SHORTCARD spN);
import void Laser_SR4M (SHORTCARD spN);
import void Laser_SL8M (SHORTCARD spN);
import void Laser_SR8M (SHORTCARD spN);
import void Laser_WCRM (SHORTCARD spN, SHORTINT npx);
import void Laser_SCRM (SHORTCARD spN, SHORTINT npx);
import void Laser_ATOF (void);
import void Laser_ATON (void);
import void Laser_GTBL (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_GTOR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_GTXR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_GTND (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void Laser_PMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_PMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_PMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_PMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_PMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_GMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_GMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_GMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_GMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_GMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void Laser_PWBL (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
import void Laser_PWOR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
import void Laser_PWXR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
import void Laser_PWND (SHORTINT col, SHORTINT row, SHORTCARD spN,
                        SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
#define Laser__init()

/* Functions for screen windows processing */
#define INVV Laser_INVV
#define MIRV Laser_MIRV
#define MARV Laser_MARV
#define SETV Laser_SETV
#define CLSV Laser_CLSV
#define WL1V Laser_WL1V
#define WR1V Laser_WR1V
#define WL4V Laser_WL4V
#define WR4V Laser_WR4V
#define WL8V Laser_WL8V
#define WR8V Laser_WR8V
#define SL1V Laser_SL1V
#define SR1V Laser_SR1V
#define SL4V Laser_SL4V
#define SR4V Laser_SR4V
#define SL8V Laser_SL8V
#define SR8V Laser_SR8V
#define WCRV Laser_WCRV
#define SCRV Laser_SCRV
#define AWLV Laser_AWLV
#define ASLV Laser_ASLV
#define AWRV Laser_AWRV
#define ASRV Laser_ASRV
#define ATUV Laser_ATUV
#define ATDV Laser_ATDV

/* Functions for sprites manipulations */
#define CLSM Laser_CLSM
#define INVM Laser_INVM
#define PTBL Laser_PTBL
#define PTOR Laser_PTOR
#define PTXR Laser_PTXR
#define PTND Laser_PTND
#define WL1M Laser_WL1M
#define WR1M Laser_WR1M
#define WL4M Laser_WL4M
#define WR4M Laser_WR4M
#define WL8M Laser_WL8M
#define WR8M Laser_WR8M
#define SL1M Laser_SL1M
#define SR1M Laser_SR1M
#define SL4M Laser_SL4M
#define SR4M Laser_SR4M
#define SL8M Laser_SL8M
#define SR8M Laser_SR8M
#define WCRM Laser_WCRM
#define SCRM Laser_SCRM
#define ATOF Laser_ATOF
#define ATON Laser_ATON
#define GTBL Laser_GTBL
#define GTOR Laser_GTOR
#define GTXR Laser_GTXR
#define GTND Laser_GTND
#define PMBL Laser_PMBL
#define PMOR Laser_PMOR
#define PMXR Laser_PMXR
#define PMND Laser_PMND
#define PMAT Laser_PMAT
#define GMBL Laser_GMBL
#define GMOR Laser_GMOR
#define GMXR Laser_GMXR
#define GMND Laser_GMND
#define GMAT Laser_GMAT
#define PWBL Laser_PWBL
#define PWOR Laser_PWOR
#define PWXR Laser_PWXR
#define PWND Laser_PWND

#endif

