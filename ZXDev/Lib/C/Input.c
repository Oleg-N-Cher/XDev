#define KeyBufSize 8
extern char Input_keyBuf [KeyBufSize];

signed char Input_Available_NoRepeat (void);
signed char Input_Available_RepeatBuf (void);
unsigned char Input_Read_NoRepeat (void);
unsigned char Input_Read_Repeat (void);
unsigned char Input_Read_RepeatBuf (void);
void Input_RunMe50Hz (void);

/*================================== Header ==================================*/
signed char Input_Available_NoRepeat (void) {
__asm
  LD   IY,#0x5C3A
  CALL 0x28E
  LD   L,#0
  INC  E
  RET  Z
  INC  L
__endasm;
} //Input_Available_NoRepeat

/*--------------------------------- Cut here ---------------------------------*/
signed char Input_Available_RepeatBuf (void) {
__asm
  LD   HL,(_Input_keysAvailable+1)
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Input_Read_NoRepeat (void) {
__asm // http://zxpress.ru/book_articles.php?id=1395
  LD   IY,#0x5C3A
  RES  5,1(IY)
LOOPnoRpt$:
  CALL 0x2BF
  BIT  5,1(IY)
  JR   Z,LOOPnoRpt$
  LD   L,-50(IY)
__endasm;
} //Input_Read_NoRepeat

/*--------------------------------- Cut here ---------------------------------*/
unsigned char Input_Read_Repeat (void) {
__asm
  LD   IY,#0x5C3A
  RES  5,1(IY)
LOOPrpt$:
  BIT  5,1(IY)
  JR   Z,LOOPrpt$
  LD   L,-50(IY)
__endasm;
} //Input_Read_Repeat

/*--------------------------------- Cut here ---------------------------------*/
char Input_keyBuf [KeyBufSize];

/* Закономерно считаем, что более актуальны клавиши, нажатые позднее,
   поэтому при переполнении буфера будем удалять из него нажатые ранее.
   Эта стратегия кажется более удачной, чем игнорирование всех клавиш,
   нажатых после переполнения буфера (как в контроллере клавиатуры IBM PC). */

unsigned char Input_Read_RepeatBuf (void) {
__asm
LOOPrptbuf$:
  LD   HL,#_Input_keysAvailable+1
  LD   A,(HL)
  OR   A
  JR   Z,LOOPrptbuf$
  DEC  (HL)
.globl _Input_keyOut
_Input_keyOut:           ; Read a key:
  LD   HL,#_Input_keyBuf ; key := keyBuf[keyOut];
  LD   C,(HL)
  INC  HL                ; keyOut := (keyOut+1) MOD KeyBufSize;
  LD   A,L
  SUB  #<_Input_keyBuf+KeyBufSize
  JR   NZ,Save_keyOut$
  LD   HL,#_Input_keyBuf
Save_keyOut$:
  LD   (_Input_keyOut+1),HL
  LD   L,C               ; RETURN key
__endasm;
} //Input_Read_RepeatBuf

void Input_RunMe50Hz (void) {
__asm
  LD   IY,#0x5C3A
  RST  0x38
  BIT  5,1(IY)
  RET  Z
  RES  5,1(IY)
_Input_keyIn:
  LD   HL,#_Input_keyBuf ; Add a key:
  LD   A,-50(IY)         ; keyBuf[keyIn] := CHR(keyCode);
  LD   (HL),A
  INC  HL
  LD   A,L
  SUB  #<_Input_keyBuf+KeyBufSize
  JR   NZ,Save_keyIn$
  LD   HL,#_Input_keyBuf
Save_keyIn$:
  LD   (_Input_keyIn+1),HL
.globl _Input_keysAvailable
_Input_keysAvailable:
  LD   A,#0              ; Check overflow:
  CP   #KeyBufSize       ; IF keysAvailable > 8 THEN keysAvailable := 8 END;
  JR   NC,_Input_keyOut
  INC  A
  LD   (_Input_keysAvailable+1),A
__endasm;
} //Input_RunMe50Hz

