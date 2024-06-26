#include "SYSTEM.oh"
#include "Input.oh"
#include "Strings.oh"
#include "Timer.oh"

void Console_At_ROM (signed char x, signed char y) __z88dk_callee;
void Console_At_COMPACT (signed char x, signed char y) __z88dk_callee;
void Console_At_FAST (signed char x, signed char y) __z88dk_callee;
SHORTINT Console_ReadIntRange_ROM (SHORTINT min, SHORTINT max);
SHORTINT Console_ReadInt_ROM (void);
SHORTINT Console_ReadIntRange_COMPACT (SHORTINT min, SHORTINT max);
SHORTINT Console_ReadInt_COMPACT (void);
SHORTINT Console_ReadIntRange_FAST (SHORTINT min, SHORTINT max);
SHORTINT Console_ReadInt_FAST (void);
void Console_ReadStr_COMPACT (CHAR *str, SHORTINT str__len, BYTE maxlen);
void Console_ReadStr_FAST (CHAR *str, SHORTINT str__len, BYTE maxlen);
void Console_ReadStr_ROM (CHAR *str, SHORTINT str__len, BYTE maxlen);
void Console_WriteBool_COMPACT (BOOLEAN b);
void Console_WriteBool_FAST (BOOLEAN b);
void Console_WriteBool_ROM (BOOLEAN b);
void Console_WriteCh_COMPACT (unsigned char ch) __z88dk_fastcall;
void Console_WriteCh_FAST (unsigned char ch) __z88dk_fastcall;
void Console_WriteCh_ROM (unsigned char ch) __z88dk_fastcall;
void Console_WriteLong_ROM (long n);
void Console_WriteLong_COMPACT (long n);
void Console_WriteLong_FAST (long n);
void Console_WriteLn_ROM (void);
void Console_WriteLn_COMPACT (void);
void Console_WriteLn_FAST (void);
void Console_WriteReal_ROM (float x);
void Console_WriteReal_COMPACT (float x);
void Console_WriteReal_FAST (float x);
void Console_WriteRealFix_ROM (float x, BYTE n);
void Console_WriteRealFix_COMPACT (float x, BYTE n);
void Console_WriteRealFix_FAST (float x, BYTE n);
void Console_WriteInt_ROM (int n) __z88dk_fastcall;
void Console_WriteInt_COMPACT (int n) __z88dk_fastcall;
void Console_WriteInt_FAST (int n) __z88dk_fastcall;
void Console_WriteStr_C_COMPACT (unsigned char *str) __z88dk_fastcall;
void Console_WriteStr_C_FAST (unsigned char *str) __z88dk_fastcall;
void Console_WriteStr_C_ROM (unsigned char *str) __z88dk_fastcall;
void Console_WriteUShort_COMPACT (unsigned int n) __z88dk_fastcall;
void Console_WriteUShort_FAST (unsigned int n) __z88dk_fastcall;
void Console_WriteUShort_ROM (unsigned int n) __z88dk_fastcall;
void Console_Clear_ROM (unsigned char attr) __z88dk_fastcall;
void Console_Clear_FAST (unsigned char attr) __z88dk_fastcall;
void Console_Clear_COMPACT (unsigned char attr) __z88dk_fastcall;
float Console_Ten (unsigned char n);

void Console_BackPos_ROM (void);
void Console_BackPos_FAST (void);
void Console_BackPos_COMPACT (void);

/* Set video attrib */
#define SETV_A$   0x5C8F
extern BYTE __at(SETV_A$) Console_attrib;
/*================================== Header ==================================*/

/* Set video attrib */
BYTE __at(SETV_A$) Console_attrib;

/*--------------------------------- Cut here ---------------------------------*/
void Console_At_ROM (signed char x, signed char y) __z88dk_callee __naked {
__asm
  LD   IY,#0x5C3A
  LD   A,#22
  RST  16
  POP  HL
  EX   (SP),HL
  LD   A,H // y
  RST  16
  LD   A,L // x
  RST  16
  RET
__endasm;
} //Console_At_ROM

/*--------------------------------- Cut here ---------------------------------*/

void Console_At_COMPACT (signed char x, signed char y) __naked __z88dk_callee {
__asm
  POP  HL
  POP  DE
  PUSH HL
;��������� ������� ������ ��������� �� ���������
; (c) �.��������, �.�����, 1996.
; http://zxpress.ru/book_articles.php?id=633
;������ ������� (E = X; D = Y; 12B; 61T):
  LD   A,D         ; 4
  ADD  A,A         ; 4
  ADD  A,A         ; 4
  ADD  A,A         ; 4
  LD   L,A         ; 4
  LD   H,#0x16     ; 7
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  LD   A,L         ; 4
  OR   E           ; 4
  LD   L,A         ; 4
/*
;������ ������� (H = X; L = Y; 10B; 74T):
  LD   A,H         ; 4
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  LD   H,#0x16     ; 7
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  ADD  A,L         ; 4
  LD   L,A         ; 4
*/
;�� ������ ����� �������� � HL - ����� ����� ���������.
  DEC  HL
  LD   (_ATTR_ADR_C+1),HL
  RET
__endasm;
} //Console_At_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_At_FAST (signed char x, signed char y) __naked __z88dk_callee {
__asm
  POP  HL
  POP  DE
  PUSH HL
;��������� ������� ������ ��������� �� ���������
; (c) �.��������, �.�����, 1996.
; http://zxpress.ru/book_articles.php?id=633
;������ ������� (E = X; D = Y; 12B; 61T):
  LD   A,D         ; 4
  ADD  A,A         ; 4
  ADD  A,A         ; 4
  ADD  A,A         ; 4
  LD   L,A         ; 4
  LD   H,#0x16     ; 7
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  LD   A,L         ; 4
  OR   E           ; 4
  LD   L,A         ; 4
/*
;������ ������� (H = X; L = Y; 10B; 74T):
  LD   A,H         ; 4
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  LD   H,#0x16     ; 7
  ADD  HL,HL       ;11
  ADD  HL,HL       ;11
  ADD  A,L         ; 4
  LD   L,A         ; 4
*/
;�� ������ ����� �������� � HL - ����� ����� ���������.
  DEC  HL
  LD   (_ATTR_ADR_F+1),HL
;������ ��������� ������ �� ������ ���������
; (c) �.��������, �.�����, 1996.
; http://zxpress.ru/book_articles.php?id=633
;����: HL = ����� ���������
  LD   A,H             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  AND  #0x7F           ; 7
;�����: AL = �������� �����
  LD   (#_SCR_ADR_F+1),A
  RET
__endasm;
} //Console_At_FAST

/*--------------------------------- Cut here ---------------------------------*/

/* (Font_address - 256) */
#define CHAR_SET$ 0x5C36

void Console_WriteCh_COMPACT (unsigned char ch) __z88dk_fastcall
{ // http://www.zxpress.ru/article.php?id=9493
__asm
  LD   A,L
  LD   (_CHAR_CODE_C$+1),A
  LD   HL,#_ATTR_ADR_C+1
  INC  (HL)
  CALL Z, _INC_HBYTE_C
.globl _ATTR_ADR_C
_ATTR_ADR_C:
  LD   DE,#0x5800-1    ;DE = �������� �����
  LD   A,(SETV_A$)     ;��������� ���� �������
  LD   (DE),A
;������ ��������� ������ �� ������ ���������
; (c) �.��������, �.�����, 1996.
; http://zxpress.ru/book_articles.php?id=633
;����: DE = ����� ���������
  LD   A,D             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  AND  #0x7F           ; 7
  LD   D,A             ; 4 = 27T
;�����: DE = �������� �����
; =====������ ������� 8�8 (compact) =====
_CHAR_CODE_C$:         ;in: L - ��� �������
  LD   HL,#0           ;���������� ������ �������
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  LD   BC,(0x5C36)
  ADD  HL,BC
  LD   B,#7
PRLOOP$:
  LD   A,(HL)          ;����� ���� �� �����
  LD   (DE),A          ;� ������ � �����
  INC  HL              ;���������� fnt adr
  INC  D               ;���������� scr adr
  DJNZ PRLOOP$
  LD   A,(HL)          ;� ��� 8 ���
  LD   (DE),A
__endasm;
} //Console_WriteCh_COMPACT

/*--------------------------------- Cut here ---------------------------------*/

/* (Font_address - 256) */
#define CHAR_SET$ 0x5C36

#define DUP_7 \
  LD   A,(HL) ;����� ���� �� ����� \
  LD   (DE),A ;� ������ � �����   \
  INC  HL     ;���������� fnt adr \
  INC  D      ;���������� scr adr

void Console_WriteCh_FAST (unsigned char ch) __z88dk_fastcall
{ // http://www.zxpress.ru/article.php?id=9493
__asm
  LD   A,L
  LD   (_CHAR_CODE_F$+1),A
  LD   HL,#_ATTR_ADR_F+1
  INC  (HL)
  CALL Z, _INC_HBYTE_F
.globl _ATTR_ADR_F
_ATTR_ADR_F:
  LD   DE,#0x5800-1    ;DE = �������� �����
  LD   A,(SETV_A$)     ;��������� ���� �������
  LD   (DE),A
.globl _SCR_ADR_F
_SCR_ADR_F:            ;������� ������ ���������
  LD   D,#0x40-8       ; � �������� �����
; =====������ ������� 8�8 (compact) =====
_CHAR_CODE_F$:         ;in: L - ��� �������
  LD   HL,#0           ;���������� ������ �������
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  LD   BC,(0x5C36)
  ADD  HL,BC
  DUP_7                ;� ��� 8 ���
  DUP_7
  DUP_7
  DUP_7
  DUP_7
  DUP_7
  DUP_7
  LD   A,(HL)
  LD   (DE),A
__endasm;
} //Console_WriteCh_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteCh_ROM (unsigned char ch) __z88dk_fastcall {
__asm
  LD   A,L
  LD   IY,#0x5C3A
  RST  16
__endasm;
} //Console_WriteCh_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_ROM (void) __naked {
__asm
  LD   A,#0x0D
  JP   _Console_WriteCh_ROM+1
__endasm;
} //Console_WriteLn_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteBool_COMPACT (BOOLEAN b) {
  if(b)
    Console_WriteStr_C_COMPACT("TRUE");
  else
    Console_WriteStr_C_COMPACT("FALSE");
} //Console_WriteBool_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteBool_FAST (BOOLEAN b) {
  if(b)
    Console_WriteStr_C_FAST("TRUE");
  else
    Console_WriteStr_C_FAST("FALSE");
} //Console_WriteBool_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteBool_ROM (BOOLEAN b) {
  if(b)
    Console_WriteStr_C_ROM("TRUE");
  else
    Console_WriteStr_C_ROM("FALSE");
} //Console_WriteBool_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_COMPACT (void) __naked {
__asm
  LD   HL,#_ATTR_ADR_C+1
  LD   A,(HL)
  OR   #0x1F
  CP   (HL)
  LD   (HL),A
  RET  NZ
  ADD  A,#0x20
  LD   (HL),A
  RET  NC
.globl _INC_HBYTE_C
_INC_HBYTE_C:
  INC  HL              ;���������� ��������
  INC  (HL)            ;������ ��������� (� ���������)
  LD   A,(HL)
  CP   #0x5B
  RET  C
  LD   HL,#0x5AE0-1
  LD   (_ATTR_ADR_C+1),HL
  LD   B,#23
  JP   0xE00           ;����� CL_SCROLL
__endasm;
} //Console_WriteLn_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_FAST (void) __naked {
__asm
  LD   HL,#_ATTR_ADR_F+1
  LD   A,(HL)
  OR   #0x1F
  CP   (HL)
  LD   (HL),A
  RET  NZ
  ADD  A,#0x20
  LD   (HL),A
  RET  NC
.globl _INC_HBYTE_F
_INC_HBYTE_F:
  LD   A,(#_SCR_ADR_F+1)
  ADD  A,#8
  LD   (#_SCR_ADR_F+1),A
  INC  HL              ;���������� ��������
  INC  (HL)            ;������ ��������� (� ���������)
  LD   A,(HL)
  CP   #0x5B
  RET  C
  LD   A,#0x50
  LD   (#_SCR_ADR_F+1),A
  LD   HL,#0x5AE0-1
  LD   (_ATTR_ADR_F+1),HL
  LD   B,#23
  JP   0xE00           ;����� CL_SCROLL
__endasm;
} //Console_WriteLn_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_C_COMPACT (unsigned char *str) __z88dk_fastcall __naked {
__asm
WRSTR_C$:
  LD   A,(HL)
  OR   A
  RET  Z
  PUSH HL
  CALL _Console_WriteCh_COMPACT+1
  POP  HL
  INC  HL
  JR   WRSTR_C$
__endasm;
} //Console_WriteStr_C_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_C_FAST (unsigned char *str) __z88dk_fastcall __naked {
__asm
WRSTR_F$:
  LD   A,(HL)
  OR   A
  RET  Z
  PUSH HL
  CALL _Console_WriteCh_FAST+1
  POP  HL
  INC  HL
  JR   WRSTR_F$
__endasm;
} //Console_WriteStr_C_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteStr_C_ROM (unsigned char *str) __z88dk_fastcall __naked {
__asm
  LD   IY,#0x5C3A
WRSTR_R$:
  LD   A,(HL)
  OR   A
  RET  Z
  RST  16
  INC  HL
  JR   WRSTR_R$
__endasm;
} //Console_WriteStr_C_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteUShort_ROM (unsigned int n) __z88dk_fastcall __naked {
__asm
    LD   C,L
    LD   B,H
    CALL 0x2D2B       ; BC-TO-FP
    JP   0x2DE3       ; PRINT-FP
__endasm;
} //Console_WriteUShort_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_ROM (int n) __z88dk_fastcall __naked {
__asm
    BIT   7,H
    JP    Z,_Console_WriteUShort_ROM

    ; HL := -HL
    EX    DE,HL ;  4
    XOR   A     ;  4
    LD    L,A   ;  4
    LD    H,A   ;  4
    SBC   HL,DE ; 15 => 31t

    PUSH  HL
    LD    A,#'-'
    CALL  _Console_WriteCh_ROM+1
    POP   BC
    JP    _Console_WriteUShort_ROM+2
__endasm;
} //Console_WriteInt_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteUShort_COMPACT (unsigned int n) __z88dk_fastcall {
__asm
            LD    C,#0x5        ;���-�� ���������� ����� + 1
            LD    DE,#-10000    ;������� �������� �������
            CALL  LP_DIGIT_C$
            LD    DE,#-1000     ;
            CALL  LP_DIGIT_C$
            LD    DE,#-100      ;
            CALL  LP_DIGIT_C$
            LD    E,#-10        ;
            CALL  LP_DIGIT_C$
            LD    E,D           ;
LP_DIGIT_C$:LD    A,#'0'-1      ;�������� �������
LP_PDW2_C$: INC   A             ;����������� �������
            ADD   HL,DE         ;�������� ������� ������� �������
            JR    C,LP_PDW2_C$  ;��������� ���� HL>=0
            SBC   HL,DE         ;HL=HL mod DE; A=HL div DE
            DEC   C             ;���������: ����� ��� ���������� ����?
            JR    Z,LP_PRNT_C$  ; ���� ��� ���� ������ �����, ��������
            CP    #'0'          ;���� ��� ����, �� �� ����������
            RET   Z             ; ������ �� ��������
LP_PRNT_C$: EXX                 ;������ ���������� �����
            CALL  _Console_WriteCh_COMPACT+1 ; Skip "LD A,L"
            EXX
            LD    C,#1          ;��� ���� ������, ������ ��� ��������
__endasm;
} //Console_WriteUShort_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_COMPACT (int n) __z88dk_fastcall __naked {
__asm
    BIT   7,H
    JP    Z,_Console_WriteUShort_COMPACT

    ; HL := -HL
    EX    DE,HL ;  4
    XOR   A     ;  4
    LD    L,A   ;  4
    LD    H,A   ;  4
    SBC   HL,DE ; 15 => 31t

    PUSH  HL
    LD    A,#'-'
    CALL  _Console_WriteCh_COMPACT+1
    POP   HL
    JP    _Console_WriteUShort_COMPACT
__endasm;
} //Console_WriteInt_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteUShort_FAST (unsigned int n) __z88dk_fastcall {
__asm
            LD    DE,#-10000    ;������� �������� �������
            LD    C,E           ;������������� ���� ���� ����������
            CALL  LP_DIGIT_F$
            LD    DE,#-1000     ;
            CALL  LP_DIGIT_F$
            LD    DE,#-100      ;
            CALL  LP_DIGIT_F$
            LD    E,#-10        ;
            CALL  LP_DIGIT_F$
            LD    A,L
            ADD   #'0'
            JP    _Console_WriteCh_FAST+1 ; Skip "LD A,L"
LP_DIGIT_F$:LD    A,#'0'-1      ;�������� �������
LP_PDW2_F$: INC   A             ;����������� �������
            ADD   HL,DE         ;�������� ������� ������� �������
            JR    C,LP_PDW2_F$  ;��������� ���� HL>=0
            SBC   HL,DE         ;HL=HL mod DE; A=HL div DE
            DEC   C             ;���������: ����� ��� ���������� ����?
            JR    Z,LP_PRNT_F$  ; ���� ��� ���� ������ �����, ��������
            CP    #'0'          ;���� ��� ����, �� �� ����������
            RET   Z             ; ������ �� ��������
LP_PRNT_F$: EXX                 ;������ ���������� �����
            CALL  _Console_WriteCh_FAST+1 ; Skip "LD A,L"
            EXX
            LD    C,#1          ;��� ���� ������, ������ ��� ��������
__endasm;
} //Console_WriteUShort_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_FAST (int n) __z88dk_fastcall __naked {
__asm
    BIT   7,H
    JP    Z,_Console_WriteUShort_FAST

    ; HL := -HL
    EX    DE,HL ;  4
    XOR   A     ;  4
    LD    L,A   ;  4
    LD    H,A   ;  4
    SBC   HL,DE ; 15 => 31t

    PUSH  HL
    LD    A,#'-'
    CALL  _Console_WriteCh_FAST+1
    POP   HL
    JP    _Console_WriteUShort_FAST
__endasm;
} //Console_WriteInt_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLong_ROM (long n)
{
  CHAR s[10];
  INTEGER i1;
  unsigned char k;
  if (n < 0) {
    Console_WriteCh_ROM('-');
  }
  if (n == (-2147483647-1)) {
    Console_WriteStr_C_ROM((void*)&"2147483648");
  } else {
    i1 = __ABS(n);
    s[0] = (CHAR)(__MOD(i1, 10) + 48);
    i1 = __DIV(i1, 10);
    k = 1;
    while (i1 > 0) {
      s[k] = (CHAR)(__MOD(i1, 10) + 48);
      i1 = __DIV(i1, 10);
      k += 1;
    }
    while (k != 0) {
      k -= 1;
      Console_WriteCh_ROM(s[k]);
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLong_COMPACT (long n)
{
  CHAR s[10];
  INTEGER i1;
  unsigned char k;
  if (n < 0) {
    Console_WriteCh_COMPACT('-');
  }
  if (n == (-2147483647-1)) {
    Console_WriteStr_C_COMPACT((void*)&"2147483648");
  } else {
    i1 = __ABS(n);
    s[0] = (CHAR)(__MOD(i1, 10) + 48);
    i1 = __DIV(i1, 10);
    k = 1;
    while (i1 > 0) {
      s[k] = (CHAR)(__MOD(i1, 10) + 48);
      i1 = __DIV(i1, 10);
      k += 1;
    }
    while (k != 0) {
      k -= 1;
      Console_WriteCh_COMPACT(s[k]);
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLong_FAST (long n)
{
  CHAR s[10];
  INTEGER i1;
  unsigned char k;
  if (n < 0) {
    Console_WriteCh_FAST('-');
  }
  if (n == (-2147483647-1)) {
    Console_WriteStr_C_FAST((void*)&"2147483648");
  } else {
    i1 = __ABS(n);
    s[0] = (CHAR)(__MOD(i1, 10) + 48);
    i1 = __DIV(i1, 10);
    k = 1;
    while (i1 > 0) {
      s[k] = (CHAR)(__MOD(i1, 10) + 48);
      i1 = __DIV(i1, 10);
      k += 1;
    }
    while (k != 0) {
      k -= 1;
      Console_WriteCh_FAST(s[k]);
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_Clear_ROM (unsigned char attr) __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,(_Console_attrib)
  EX   AF,AF
  LD   A,L
  CALL 0x229B
  LD   (0x5C8D),A
  CALL 0xD6B // IX-safe
  CALL 0x1642 ; CHAN_S
  EX   AF,AF
  LD   (_Console_attrib),A
__endasm;
} //Console_Clear_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_Clear_FAST (unsigned char attr) __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,(_Console_attrib)
  EX   AF,AF
  LD   A,L
  CALL 0x229B
  LD   (0x5C8D),A
  CALL 0xD6B // IX-safe
  EX   AF,AF
  LD   (_Console_attrib),A
  LD   A,#0x40-8
  LD   (#_SCR_ADR_F+1),A
  LD   HL,#0x5800-1
  LD   (_ATTR_ADR_F+1),HL
__endasm;
} //Console_Clear_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_Clear_COMPACT (unsigned char attr) __z88dk_fastcall {
__asm
  LD   IY,#0x5C3A
  LD   A,(_Console_attrib)
  EX   AF,AF
  LD   A,L
  CALL 0x229B
  LD   (0x5C8D),A
  CALL 0xD6B // IX-safe
  EX   AF,AF
  LD   (_Console_attrib),A
  LD   HL,#0x5800-1
  LD   (_ATTR_ADR_C+1),HL
__endasm;
} //Console_Clear_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_BackPos_ROM (void) __naked {
__asm
  LD   A,#8
  JP   _Console_WriteCh_ROM+1
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
BYTE i, digits;
CHAR ch;
CHAR data[8];
SHORTINT result;

void Console_ReadInt_Accept_ROM (void)
{
  if (digits < 6) {
    Console_WriteCh_ROM(ch); data[digits] = ch; digits += 1;
  }
}

SHORTINT Console_ReadIntRange_ROM (SHORTINT min, SHORTINT max)
{
  digits = 0;
  for (;;) {
    for (;;) {
      Console_WriteCh_ROM('_');
      Console_BackPos_ROM();
      i = 25;
      while (i >= 1) {
        if (Input_Available() != 0) {
          Console_WriteCh_ROM(' ');
          Console_BackPos_ROM();
          goto exit__0;
        }
        Timer_Delay(10);
        i += -1;
      }
      Console_WriteCh_ROM(' ');
      Console_BackPos_ROM();
      i = 25;
      while (i >= 1) {
        if (Input_Available() != 0) {
          goto exit__0;
        }
        Timer_Delay(10);
        i += -1;
      }
    }
    exit__0:;
    ch = Input_Read();
    switch (ch) {
      case '-':
        if (digits == 0 && min < 0) {
          Console_ReadInt_Accept_ROM();
        }
        break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        Console_ReadInt_Accept_ROM();
        break;
      case 0x0c:
        if (digits > 0) {
          digits -= 1;
          Console_BackPos_ROM();
          Console_WriteCh_ROM(' ');
          Console_BackPos_ROM();
        }
        break;
      case 0x0d:
        if (digits > 0) {
          if (digits < 8) {
            data[digits] = 0x00;
          }
          if ((Strings_StrToInt((void*)data, 8, &result) && result >= min) && result <= max) {
            return result;
          }
        }
        break;
      default:
        break;
    }
    i = 25;
    for (;;) {
      if (Input_Available() == 0 || i == 0) {
        break;
      }
      Timer_Delay(10);
      i -= 1;
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT Console_ReadInt_ROM (void)
{
  return Console_ReadIntRange_ROM(-32768, 32767);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_BackPos_COMPACT (void)
{
__asm
  LD   HL,#_ATTR_ADR_C+1
  DEC  (HL)
__endasm;
}

/*--------------------------------- Cut here ---------------------------------*/
BYTE i, digits;
CHAR ch;
CHAR data[8];
SHORTINT result;

void Console_ReadInt_Accept_COMPACT (void)
{
  if (digits < 6) {
    Console_WriteCh_COMPACT(ch); data[digits] = ch; digits += 1;
  }
}

SHORTINT Console_ReadIntRange_COMPACT (SHORTINT min, SHORTINT max)
{
  digits = 0;
  for (;;) {
    for (;;) {
      Console_WriteCh_COMPACT('_');
      Console_BackPos_COMPACT();
      i = 25;
      while (i >= 1) {
        if (Input_Available() != 0) {
          Console_WriteCh_COMPACT(' ');
          Console_BackPos_COMPACT();
          goto exit__0;
        }
        Timer_Delay(10);
        i += -1;
      }
      Console_WriteCh_COMPACT(' ');
      Console_BackPos_COMPACT();
      i = 25;
      while (i >= 1) {
        if (Input_Available() != 0) {
          goto exit__0;
        }
        Timer_Delay(10);
        i += -1;
      }
    }
    exit__0:;
    ch = Input_Read();
    switch (ch) {
      case '-':
        if (digits == 0 && min < 0) {
          Console_ReadInt_Accept_COMPACT();
        }
        break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        Console_ReadInt_Accept_COMPACT();
        break;
      case 0x0c:
        if (digits > 0) {
          digits -= 1;
          Console_BackPos_COMPACT();
          Console_WriteCh_COMPACT(' ');
          Console_BackPos_COMPACT();
        }
        break;
      case 0x0d:
        if (digits > 0) {
          if (digits < 8) {
            data[digits] = 0x00;
          }
          if ((Strings_StrToInt((void*)data, 8, &result) && result >= min) && result <= max) {
            return result;
          }
        }
        break;
      default:
        break;
    }
    i = 25;
    for (;;) {
      if (Input_Available() == 0 || i == 0) {
        break;
      }
      Timer_Delay(10);
      i -= 1;
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT Console_ReadInt_COMPACT (void)
{
  return Console_ReadIntRange_COMPACT(-32768, 32767);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_BackPos_FAST (void)
{
__asm
  LD   HL,#_SCR_ADR_F+1
  DEC  (HL)
__endasm;
}
/*--------------------------------- Cut here ---------------------------------*/

BYTE i, digits;
CHAR ch;
CHAR data[8];
SHORTINT result;

void Console_ReadInt_Accept_FAST (void)
{
  if (digits < 6) {
    Console_WriteCh_FAST(ch); data[digits] = ch; digits += 1;
  }
}

SHORTINT Console_ReadIntRange_FAST (SHORTINT min, SHORTINT max)
{
  digits = 0;
  for (;;) {
    for (;;) {
      Console_WriteCh_FAST('_');
      Console_BackPos_FAST();
      i = 25;
      while (i >= 1) {
        if (Input_Available() != 0) {
          Console_WriteCh_FAST(' ');
          Console_BackPos_FAST();
          goto exit__0;
        }
        Timer_Delay(10);
        i += -1;
      }
      Console_WriteCh_FAST(' ');
      Console_BackPos_FAST();
      i = 25;
      while (i >= 1) {
        if (Input_Available() != 0) {
          goto exit__0;
        }
        Timer_Delay(10);
        i += -1;
      }
    }
    exit__0:;
    ch = Input_Read();
    switch (ch) {
      case '-':
        if (digits == 0 && min < 0) {
          Console_ReadInt_Accept_FAST();
        }
        break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        Console_ReadInt_Accept_FAST();
        break;
      case 0x0c:
        if (digits > 0) {
          digits -= 1;
          Console_BackPos_FAST();
          Console_WriteCh_FAST(' ');
          Console_BackPos_FAST();
        }
        break;
      case 0x0d:
        if (digits > 0) {
          if (digits < 8) {
            data[digits] = 0x00;
          }
          if ((Strings_StrToInt((void*)data, 8, &result) && result >= min) && result <= max) {
            return result;
          }
        }
        break;
      default:
        break;
    }
    i = 25;
    for (;;) {
      if (Input_Available() == 0 || i == 0) {
        break;
      }
      Timer_Delay(10);
      i -= 1;
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT Console_ReadInt_FAST (void)
{
  return Console_ReadIntRange_FAST(-32768, 32767);
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_ReadStr_COMPACT (CHAR *str, SHORTINT str__len, BYTE maxlen)
{
	BYTE i, chars;
	CHAR ch;
	chars = 0;
	if ((SHORTINT)maxlen >= str__len) {
		maxlen = (BYTE)str__len - 1;
	}
	for (;;) {
		for (;;) {
			Console_WriteCh_COMPACT('_');
			Console_BackPos_COMPACT();
			i = 25;
			do {
				if (Input_Available() != 0) {
					Console_WriteCh_COMPACT(' ');
					Console_BackPos_COMPACT();
					goto exit__1;
				}
				Timer_Delay(10);
			} while (--i);
			Console_WriteCh_COMPACT(' ');
			Console_BackPos_COMPACT();
			i = 25;
			do {
				if (Input_Available() != 0) {
					goto exit__1;
				}
				Timer_Delay(10);
			} while (--i);
		}
		exit__1:;
		ch = Input_Read();
		if ((((ch >= ' ' && ch <= 0x7f)) && chars <= maxlen)) {
			Console_WriteCh_COMPACT(ch);
			str[chars] = ch;
			chars += 1;
		} else if ((ch == 0x0c && chars > 0)) {
			chars -= 1;
			Console_BackPos_COMPACT();
			Console_WriteCh_COMPACT(' ');
			Console_BackPos_COMPACT();
		} else if (ch == 0x0d) {
			str[chars] = 0x00;
			return;
		}
		i = 25;
		for (;;) {
			if (Input_Available() == 0 || i == 0) {
				break;
			}
			Timer_Delay(10);
			i -= 1;
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_ReadStr_FAST (CHAR *str, SHORTINT str__len, BYTE maxlen)
{
	BYTE i, chars;
	CHAR ch;
	chars = 0;
	if ((SHORTINT)maxlen >= str__len) {
		maxlen = (BYTE)str__len - 1;
	}
	for (;;) {
		for (;;) {
			Console_WriteCh_FAST('_');
			Console_BackPos_FAST();
			i = 25;
			do {
				if (Input_Available() != 0) {
					Console_WriteCh_FAST(' ');
					Console_BackPos_FAST();
					goto exit__1;
				}
				Timer_Delay(10);
			} while (--i);
			Console_WriteCh_FAST(' ');
			Console_BackPos_FAST();
			i = 25;
			do {
				if (Input_Available() != 0) {
					goto exit__1;
				}
				Timer_Delay(10);
			} while (--i);
		}
		exit__1:;
		ch = Input_Read();
		if ((((ch >= ' ' && ch <= 0x7f)) && chars <= maxlen)) {
			Console_WriteCh_FAST(ch);
			str[chars] = ch;
			chars += 1;
		} else if ((ch == 0x0c && chars > 0)) {
			chars -= 1;
			Console_BackPos_FAST();
			Console_WriteCh_FAST(' ');
			Console_BackPos_FAST();
		} else if (ch == 0x0d) {
			str[chars] = 0x00;
			return;
		}
		i = 25;
		for (;;) {
			if (Input_Available() == 0 || i == 0) {
				break;
			}
			Timer_Delay(10);
			i -= 1;
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_ReadStr_ROM (CHAR *str, SHORTINT str__len, BYTE maxlen)
{
	BYTE i, chars;
	CHAR ch;
	chars = 0;
	if ((SHORTINT)maxlen >= str__len) {
		maxlen = (BYTE)str__len - 1;
	}
	for (;;) {
		for (;;) {
			Console_WriteCh_ROM('_');
			Console_BackPos_ROM();
			i = 25;
			do {
				if (Input_Available() != 0) {
					Console_WriteCh_ROM(' ');
					Console_BackPos_ROM();
					goto exit__1;
				}
				Timer_Delay(10);
			} while (--i);
			Console_WriteCh_ROM(' ');
			Console_BackPos_ROM();
			i = 25;
			do {
				if (Input_Available() != 0) {
					goto exit__1;
				}
				Timer_Delay(10);
			} while (--i);
		}
		exit__1:;
		ch = Input_Read();
		if ((((ch >= ' ' && ch <= 0x7f)) && chars <= maxlen)) {
			Console_WriteCh_ROM(ch);
			str[chars] = ch;
			chars += 1;
		} else if ((ch == 0x0c && chars > 0)) {
			chars -= 1;
			Console_BackPos_ROM();
			Console_WriteCh_ROM(' ');
			Console_BackPos_ROM();
		} else if (ch == 0x0d) {
			str[chars] = 0x00;
			return;
		}
		i = 25;
		for (;;) {
			if (Input_Available() == 0 || i == 0) {
				break;
			}
			Timer_Delay(10);
			i -= 1;
		}
	}
}

/*--------------------------------- Cut here ---------------------------------*/
float Console_Ten (unsigned char n)
{
  float t, p;
  t = (float)1;
  p = (float)10;
  while (n != 0) {
    if (__ODD(n)) {
      t = p * t;
    }
    p = p * p;
    n = __ASHR(n, 1, BYTE);
  }
  return t;
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteReal_ROM (float x)
{
  BYTE e; unsigned char i;
  INTEGER m;
  CHAR d[7];
  e = (BYTE)__ASHR(__VAL(INTEGER, x), 23, INTEGER);
  if (e == 0) {
    Console_WriteCh_ROM('0');
  } else if (e == -1) {
    Console_WriteStr_C_ROM((void*)&"NaN");
  } else {
    if (x < (float)0) {
      Console_WriteCh_ROM('-');
      x = -x;
    }
    e = (BYTE)(__ASHR((SHORTINT)((unsigned char)e - 127) * 77, 8, SHORTINT) - 6);
    if (e >= 0) {
      x = x / (float)Console_Ten(e);
    } else if (e < -38) {
      x = (x * Console_Ten(-e - 6)) * (float)1000000;
    } else {
      x = Console_Ten(-e) * x;
    }
    m = (INTEGER)__ENTIER(x + 0.5);
    i = 0;
    if (m >= 10000000) {
      e += 1;
      m = __DIV(m, 10);
    }
    do {
      d[i] = (CHAR)(__MOD(m, 10) + 48);
      m = __DIV(m, 10);
      i += 1;
    } while (!(m == 0));
    i -= 1;
    Console_WriteCh_ROM(d[i]);
    Console_WriteCh_ROM('.');
    while (i > 0) {
      i -= 1;
      Console_WriteCh_ROM(d[i]);
    }
    e += 6;
    if (e != 0) {
      Console_WriteCh_ROM('E');
      if (e > 0) {
        Console_WriteCh_ROM('+');
      }
      Console_WriteInt_ROM(e);
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteReal_COMPACT (float x)
{
  BYTE e; unsigned char i;
  INTEGER m;
  CHAR d[7];
  e = (BYTE)__ASHR(__VAL(INTEGER, x), 23, INTEGER);
  if (e == 0) {
    Console_WriteCh_COMPACT('0');
  } else if (e == -1) {
    Console_WriteStr_C_COMPACT((void*)&"NaN");
  } else {
    if (x < (float)0) {
      Console_WriteCh_COMPACT('-');
      x = -x;
    }
    e = (BYTE)(__ASHR((SHORTINT)((unsigned char)e - 127) * 77, 8, SHORTINT) - 6);
    if (e >= 0) {
      x = x / (float)Console_Ten(e);
    } else if (e < -38) {
      x = (x * Console_Ten(-e - 6)) * (float)1000000;
    } else {
      x = Console_Ten(-e) * x;
    }
    m = (INTEGER)__ENTIER(x + 0.5);
    i = 0;
    if (m >= 10000000) {
      e += 1;
      m = __DIV(m, 10);
    }
    do {
      d[i] = (CHAR)(__MOD(m, 10) + 48);
      m = __DIV(m, 10);
      i += 1;
    } while (!(m == 0));
    i -= 1;
    Console_WriteCh_COMPACT(d[i]);
    Console_WriteCh_COMPACT('.');
    while (i > 0) {
      i -= 1;
      Console_WriteCh_COMPACT(d[i]);
    }
    Console_WriteCh_COMPACT('E');
    e += 6;
    if (e != 0) {
      Console_WriteCh_COMPACT('E');
      if (e > 0) {
        Console_WriteCh_COMPACT('+');
      }
      Console_WriteInt_COMPACT(e);
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteReal_FAST (float x)
{
  BYTE e; unsigned char i;
  INTEGER m;
  CHAR d[7];
  e = (BYTE)__ASHR(__VAL(INTEGER, x), 23, INTEGER);
  if (e == 0) {
    Console_WriteCh_FAST('0');
  } else if (e == -1) {
    Console_WriteStr_C_FAST((void*)&"NaN");
  } else {
    if (x < (float)0) {
      Console_WriteCh_FAST('-');
      x = -x;
    }
    e = (BYTE)(__ASHR((SHORTINT)((unsigned char)e - 127) * 77, 8, SHORTINT) - 6);
    if (e >= 0) {
      x = x / (float)Console_Ten(e);
    } else if (e < -38) {
      x = (x * Console_Ten(-e - 6)) * (float)1000000;
    } else {
      x = Console_Ten(-e) * x;
    }
    m = (INTEGER)__ENTIER(x + 0.5);
    i = 0;
    if (m >= 10000000) {
      e += 1;
      m = __DIV(m, 10);
    }
    do {
      d[i] = (CHAR)(__MOD(m, 10) + 48);
      m = __DIV(m, 10);
      i += 1;
    } while (!(m == 0));
    i -= 1;
    Console_WriteCh_FAST(d[i]);
    Console_WriteCh_FAST('.');
    while (i > 0) {
      i -= 1;
      Console_WriteCh_FAST(d[i]);
    }
    Console_WriteCh_FAST('E');
    e += 6;
    if (e != 0) {
      Console_WriteCh_FAST('E');
      if (e > 0) {
        Console_WriteCh_FAST('+');
      }
      Console_WriteInt_FAST(e);
    }
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteRealFix_ROM (float x, BYTE n)
{
  INTEGER m;
  if (x == (float)0) {
    Console_WriteCh_ROM('0');
  } else {
    if ((CHAR)(n - 1) > 0x06) {
      n = 7;
    }
    if (x < (float)0) {
      x = -x;
      Console_WriteCh_ROM('-');
    }
    m = (INTEGER)__ENTIER(x);
    Console_WriteLong_ROM(m);
    Console_WriteCh_ROM('.');
    x = Console_Ten(n) * (x - m);
    m = (INTEGER)__ENTIER(x + 0.5);
    while (m != 0 && __MOD(m, 10) == 0) {
      m = __DIV(m, 10);
    }
    Console_WriteLong_ROM(m);
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteRealFix_COMPACT (float x, BYTE n)
{
  INTEGER m;
  if (x == (float)0) {
    Console_WriteCh_COMPACT('0');
  } else {
    if ((CHAR)(n - 1) > 0x06) {
      n = 7;
    }
    if (x < (float)0) {
      x = -x;
      Console_WriteCh_COMPACT('-');
    }
    m = (INTEGER)__ENTIER(x);
    Console_WriteLong_COMPACT(m);
    Console_WriteCh_COMPACT('.');
    x = Console_Ten(n) * (x - m);
    m = (INTEGER)__ENTIER(x + 0.5);
    while (m != 0 && __MOD(m, 10) == 0) {
      m = __DIV(m, 10);
    }
    Console_WriteLong_COMPACT(m);
  }
}

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteRealFix_FAST (float x, BYTE n)
{
  INTEGER m;
  if (x == (float)0) {
    Console_WriteCh_FAST('0');
  } else {
    if ((CHAR)(n - 1) > 0x06) {
      n = 7;
    }
    if (x < (float)0) {
      x = -x;
      Console_WriteCh_FAST('-');
    }
    m = (INTEGER)__ENTIER(x);
    Console_WriteLong_FAST(m);
    Console_WriteCh_FAST('.');
    x = Console_Ten(n) * (x - m);
    m = (INTEGER)__ENTIER(x + 0.5);
    while (m != 0 && __MOD(m, 10) == 0) {
      m = __DIV(m, 10);
    }
    Console_WriteLong_FAST(m);
  }
}

/*
�� Z80 � ���� ����� ���� ����� �����:

; ���� � � A ����� �� 0 �� 15
ADD A,90h
DAA
ADC A,40h
DAA
; ����� � � A ��� �������� '0'-'9', 'A'-'F'
*/
