#include "SYSTEM.h"


export SHORTINT Input_Available (void);
export CHAR Input_Read_NoKeyRepeat (void);
export CHAR Input_Read_KeyRepeat (void);

/*================================== Header ==================================*/
SHORTINT Input_Available (void) {
__asm
  LD   IY,#0x5C3A
  CALL 0x28E
  LD   L,#0
  INC  E
  RET  Z
  INC  L
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
CHAR Input_Read_KeyNoRepeat (void) {
__asm // http://zxpress.ru/book_articles.php?id=1395
  LD   IY,#0x5C3A
  RES  5,1(IY)
LOOPnoRpt$:
  CALL 0x2BF
  BIT  5,1(IY)
  JR   Z,LOOPnoRpt$
  LD   L,-50(IY)
__endasm;
} //Input_Read_KeyNoRepeat

/*--------------------------------- Cut here ---------------------------------*/
CHAR Input_Read_KeyRepeat (void) {
__asm
  LD   IY,#0x5C3A
  RES  5,1(IY)
LOOPrpt$:
  BIT  5,1(IY)
  JR   Z,LOOPrpt$
  LD   L,-50(IY)
__endasm;
} //Input_Read_KeyRepeat

/*--------------------------------- Cut here ---------------------------------*/
CHAR Input_Read_KeyRepeatBuf (void) {
__asm
  LD   IY,#0x5C3A
LOOPrptbuf$:
  BIT  5,1(IY)
  JR   Z,LOOPrptbuf$
  RES  5,1(IY)
  LD   L,-50(IY)
__endasm;
} //Input_Read_KeyRepeatBuf

/*--------------------------------- Cut here ---------------------------------*/
void Input_RunMe50Hz (void) {
__asm
  LD   IY,#0x5C3A
  RST  0x38
__endasm;
} //Input_RunMe50Hz

