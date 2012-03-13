/*---------------------------------*/
/* LASER BASIC for SDCC  >>> v3.17 */
/* Adapted to SDCC by Oleg N. Cher */
/*    (Vedanta software), 2011     */
/*    Thanks to Michailov (HVG)    */
/*---------------------------------*/

#ifndef Laser__h
#define Laser__h

#include "SYSTEM.h"
interface

import void Laser_Init (void);
/* Functions for screen windows processing */
import void INVV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void MIRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void MARV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SETV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void CLSV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SL1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SR1V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SL4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SR4V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SL8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void SR8V (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void WCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx);
import void SCRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt, SHORTINT npx);
import void AWLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void ASLV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void AWRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void ASRV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void ATUV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);
import void ATDV (SHORTINT col, SHORTINT row, SHORTINT len, SHORTINT hgt);

/* Functions for sprites manipulations */
import void CLSM (SHORTCARD spN);
import void INVM (SHORTCARD spN);
import void PTBL (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void PTOR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void PTXR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void PTND (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void WL1M (SHORTCARD spN);
import void WR1M (SHORTCARD spN);
import void WL4M (SHORTCARD spN);
import void WR4M (SHORTCARD spN);
import void WL8M (SHORTCARD spN);
import void WR8M (SHORTCARD spN);
import void SL1M (SHORTCARD spN);
import void SR1M (SHORTCARD spN);
import void SL4M (SHORTCARD spN);
import void SR4M (SHORTCARD spN);
import void SL8M (SHORTCARD spN);
import void SR8M (SHORTCARD spN);
import void WCRM (SHORTCARD spN, SHORTINT npx);
import void SCRM (SHORTCARD spN, SHORTINT npx);
import void ATOF (void);
import void ATON (void);
import void GTBL (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void GTOR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void GTXR (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void GTND (SHORTINT col, SHORTINT row, SHORTCARD spN);
import void PMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void PMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void PMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void PMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void PMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void GMBL (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void GMOR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void GMXR (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void GMND (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void GMAT (SHORTINT col, SHORTINT row, SHORTCARD spD, SHORTCARD spS);
import void PWBL (SHORTINT col, SHORTINT row, SHORTCARD spN,
                  SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
import void PWOR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                  SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
import void PWXR (SHORTINT col, SHORTINT row, SHORTCARD spN,
                  SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);
import void PWND (SHORTINT col, SHORTINT row, SHORTCARD spN,
                  SHORTINT spCol, SHORTINT spRow, SHORTINT len, SHORTINT hgt);

/* Functions for screen windows processing */
#define Laser_INVV INVV
#define Laser_MIRV MIRV
#define Laser_MARV MARV
#define Laser_SETV SETV
#define Laser_CLSV CLSV
#define Laser_WL1V WL1V
#define Laser_WR1V WR1V
#define Laser_WL4V WL4V
#define Laser_WR4V WR4V
#define Laser_WL8V WL8V
#define Laser_WR8V WR8V
#define Laser_SL1V SL1V
#define Laser_SR1V SR1V
#define Laser_SL4V SL4V
#define Laser_SR4V SR4V
#define Laser_SL8V SL8V
#define Laser_SR8V SR8V
#define Laser_WCRV WCRV
#define Laser_SCRV SCRV
#define Laser_AWLV AWLV
#define Laser_ASLV ASLV
#define Laser_AWRV AWRV
#define Laser_ASRV ASRV
#define Laser_ATUV ATUV
#define Laser_ATDV ATDV

/* Functions for sprites manipulations */
#define Laser_CLSM CLSM
#define Laser_INVM INVM
#define Laser_PTBL PTBL
#define Laser_PTOR PTOR
#define Laser_PTXR PTXR
#define Laser_PTND PTND
#define Laser_WL1M WL1M
#define Laser_WR1M WR1M
#define Laser_WL4M WL4M
#define Laser_WR4M WR4M
#define Laser_WL8M WL8M
#define Laser_WR8M WR8M
#define Laser_SL1M SL1M
#define Laser_SR1M SR1M
#define Laser_SL4M SL4M
#define Laser_SR4M SR4M
#define Laser_SL8M SL8M
#define Laser_SR8M SR8M
#define Laser_WCRM WCRM
#define Laser_SCRM SCRM
#define Laser_ATOF ATOF
#define Laser_ATON ATON
#define Laser_GTBL GTBL
#define Laser_GTOR GTOR
#define Laser_GTXR GTXR
#define Laser_GTND GTND
#define Laser_PMBL PMBL
#define Laser_PMOR PMOR
#define Laser_PMXR PMXR
#define Laser_PMND PMND
#define Laser_PMAT PMAT
#define Laser_GMBL GMBL
#define Laser_GMOR GMOR
#define Laser_GMXR GMXR
#define Laser_GMND GMND
#define Laser_GMAT GMAT
#define Laser_PWBL PWBL
#define Laser_PWOR PWOR
#define Laser_PWXR PWXR
#define Laser_PWND PWND

#endif

