#include "SYSTEM.h"
#include "Input.h"
#include "Strings.h"
#include "Timer.h"

void Console_At_ROM (signed char x, signed char y);
void Console_At_COMPACT (signed char x, signed char y);
void Console_At_FAST (signed char x, signed char y);
SHORTINT Console_ReadIntRange_ROM (SHORTINT min, SHORTINT max);
SHORTINT Console_ReadInt_ROM (void);
SHORTINT Console_ReadIntRange_COMPACT (SHORTINT min, SHORTINT max);
SHORTINT Console_ReadInt_COMPACT (void);
SHORTINT Console_ReadIntRange_FAST (SHORTINT min, SHORTINT max);
SHORTINT Console_ReadInt_FAST (void);
void Console_WriteBool_COMPACT (BOOLEAN b);
void Console_WriteBool_FAST (BOOLEAN b);
void Console_WriteBool_ROM (BOOLEAN b);
void Console_WriteCh_COMPACT (unsigned char ch) __z88dk_fastcall;
void Console_WriteCh_FAST (unsigned char ch) __z88dk_fastcall;
void Console_WriteCh_ROM (unsigned char ch) __z88dk_fastcall;
void Console_WriteInt_ROM (int n) __z88dk_fastcall;
void Console_WriteInt_COMPACT (int n) __z88dk_fastcall;
void Console_WriteInt_FAST (int n) __z88dk_fastcall;
void Console_WriteLn_ROM (void);
void Console_WriteLn_COMPACT (void);
void Console_WriteLn_FAST (void);
void Console_WriteStr_C_COMPACT (unsigned char *str) __z88dk_fastcall;
void Console_WriteStr_C_FAST (unsigned char *str) __z88dk_fastcall;
void Console_WriteStr_C_ROM (unsigned char *str) __z88dk_fastcall;
void Console_WriteUInt_COMPACT (unsigned int n) __z88dk_fastcall;
void Console_WriteUInt_FAST (unsigned int n) __z88dk_fastcall;
void Console_WriteUInt_ROM (unsigned int n) __z88dk_fastcall;
void Console_Clear_ROM (unsigned char attr) __z88dk_fastcall;
void Console_Clear_FAST (unsigned char attr) __z88dk_fastcall;
void Console_Clear_COMPACT (unsigned char attr) __z88dk_fastcall;

/* Set video attrib */
#define SETV_A$   0x5C8F
extern BYTE __at(SETV_A$) Console_attrib;
/*================================== Header ==================================*/

/* Set video attrib */
BYTE __at(SETV_A$) Console_attrib;

/*--------------------------------- Cut here ---------------------------------*/
void Console_At_ROM (signed char x, signed char y) __naked {
__asm
#ifdef __SDCC
  PUSH IX
  LD   IX,#0
  ADD  IX,SP
#endif
  LD   IY,#0x5C3A
  LD   A,#22
  RST  16
  LD   A,5(IX) // y
  RST  16
  LD   A,4(IX) // x
  RST  16
#ifdef __SDCC
  POP  IX
#endif
  RET
__endasm;
} //Console_At_ROM

/*--------------------------------- Cut here ---------------------------------*/

void Console_At_COMPACT (signed char x, signed char y) __naked {
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
#else
  LD   E,4(IX)
  LD   D,5(IX)
#endif
;Процедура расчёта адреса атрибутов из координат
; (c) Д.Анисимов, г.Киров, 1996.
; http://zxpress.ru/book_articles.php?id=633
;Первый вариант (E = X; D = Y; 12B; 61T):
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
;Второй вариант (H = X; L = Y; 10B; 74T):
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
;На выходе обеих процедур в HL - адрес файла атрибутов.
  DEC  HL
  LD   (_ATTR_ADR_C+1),HL
  RET
__endasm;
} //Console_At_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_At_FAST (signed char x, signed char y) __naked {
__asm
#ifdef __SDCC
  LD   HL,#2
  ADD  HL,SP
  LD   E,(HL)
  INC  HL
  LD   D,(HL)
#else
  LD   E,4(IX)
  LD   D,5(IX)
#endif
;Процедура расчёта адреса атрибутов из координат
; (c) Д.Анисимов, г.Киров, 1996.
; http://zxpress.ru/book_articles.php?id=633
;Первый вариант (E = X; D = Y; 12B; 61T):
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
;Второй вариант (H = X; L = Y; 10B; 74T):
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
;На выходе обеих процедур в HL - адрес файла атрибутов.
  DEC  HL
  LD   (_ATTR_ADR_F+1),HL
;Расчёт экранного адреса из адреса атрибутов
; (c) Д.Анисимов, г.Киров, 1996.
; http://zxpress.ru/book_articles.php?id=633
;Вход: HL = адрес атрибутов
  LD   A,H             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  AND  #0x7F           ; 7
;Выход: AL = экранный адрес
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
.globl _ATTR_ADR_C
  LD   A,L
  LD   (_CHAR_CODE_C$+1),A
  LD   HL,#_ATTR_ADR_C+1
  INC  (HL)
  CALL Z, _INC_HBYTE_C
_ATTR_ADR_C:
  LD   DE,#0x5800-1    ;DE = экранный адрес
  LD   A,(SETV_A$)     ;Установим цвет символа
  LD   (DE),A
;Расчёт экранного адреса из адреса атрибутов
; (c) Д.Анисимов, г.Киров, 1996.
; http://zxpress.ru/book_articles.php?id=633
;Вход: DE = адрес атрибутов
  LD   A,D             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  ADD  A,A             ; 4
  AND  #0x7F           ; 7
  LD   D,A             ; 4 = 27T
;Выход: DE = экранный адрес
; =====печать символа 8х8 (compact) =====
_CHAR_CODE_C$:         ;in: L - код символа
  LD   HL,#0           ;Вычисление адреса символа
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  LD   BC,(0x5C36)
  ADD  HL,BC
  LD   B,#7
PRLOOP$:
  LD   A,(HL)          ;берем байт из фонта
  LD   (DE),A          ;и кладем в экран
  INC  HL              ;приращение fnt adr
  INC  D               ;приращение scr adr
  DJNZ PRLOOP$
  LD   A,(HL)          ;и так 8 раз
  LD   (DE),A
__endasm;
} //Console_WriteCh_COMPACT

/*--------------------------------- Cut here ---------------------------------*/

/* (Font_address - 256) */
#define CHAR_SET$ 0x5C36

#define DUP_7 \
  LD   A,(HL) ;берем байт из фонта \
  LD   (DE),A ;и кладем в экран   \
  INC  HL     ;приращение fnt adr \
  INC  D      ;приращение scr adr

void Console_WriteCh_FAST (unsigned char ch) __z88dk_fastcall
{ // http://www.zxpress.ru/article.php?id=9493
__asm
.globl _ATTR_ADR_F
.globl _SCR_ADR_F
  LD   A,L
  LD   (_CHAR_CODE_F$+1),A
  LD   HL,#_ATTR_ADR_F+1
  INC  (HL)
  CALL Z, _INC_HBYTE_F
_ATTR_ADR_F:
  LD   DE,#0x5800-1    ;DE = экранный адрес
  LD   A,(SETV_A$)     ;Установим цвет символа
  LD   (DE),A
_SCR_ADR_F:            ;Перевод адреса атрибутов
  LD   D,#0x40-8       ; в экранный адрес
; =====печать символа 8х8 (compact) =====
_CHAR_CODE_F$:         ;in: L - код символа
  LD   HL,#0           ;Вычисление адреса символа
  ADD  HL,HL
  ADD  HL,HL
  ADD  HL,HL
  LD   BC,(0x5C36)
  ADD  HL,BC
  DUP_7                ;и так 8 раз
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
.globl _INC_HBYTE_C
  LD   HL,#_ATTR_ADR_C+1
  LD   A,(HL)
  OR   #0x1F
  CP   (HL)
  LD   (HL),A
  RET  NZ
  ADD  A,#0x20
  LD   (HL),A
  RET  NC
_INC_HBYTE_C:
  INC  HL              ;приращение старшего
  INC  (HL)            ;адреса атрибутов (и скроллинг)
  LD   A,(HL)
  CP   #0x5B
  RET  C
  LD   HL,#0x5AE0-1
  LD   (_ATTR_ADR_C+1),HL
  LD   B,#23
  JP   0xE00           ;вызов CL_SCROLL
__endasm;
} //Console_WriteLn_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteLn_FAST (void) __naked {
__asm
.globl _INC_HBYTE_F
  LD   HL,#_ATTR_ADR_F+1
  LD   A,(HL)
  OR   #0x1F
  CP   (HL)
  LD   (HL),A
  RET  NZ
  ADD  A,#0x20
  LD   (HL),A
  RET  NC
_INC_HBYTE_F:
  LD   A,(#_SCR_ADR_F+1)
  ADD  A,#8
  LD   (#_SCR_ADR_F+1),A
  INC  HL              ;приращение старшего
  INC  (HL)            ;адреса атрибутов (и скроллинг)
  LD   A,(HL)
  CP   #0x5B
  RET  C
  LD   A,#0x50
  LD   (#_SCR_ADR_F+1),A
  LD   HL,#0x5AE0-1
  LD   (_ATTR_ADR_F+1),HL
  LD   B,#23
  JP   0xE00           ;вызов CL_SCROLL
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
void Console_WriteUInt_ROM (unsigned int n) __z88dk_fastcall __naked {
__asm
    LD   C,L
    LD   B,H
    CALL 0x2D2B       ; BC-TO-FP
    JP   0x2DE3       ; PRINT-FP
__endasm;
} //Console_WriteUInt_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_ROM (int n) __z88dk_fastcall __naked {
__asm
    BIT   7,H
    JP    Z,_Console_WriteUInt_ROM

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
    JP    _Console_WriteUInt_ROM+2
__endasm;
} //Console_WriteInt_ROM

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteUInt_COMPACT (unsigned int n) __z88dk_fastcall {
__asm
            LD    C,#0x5        ;кол-во незначащих нулей + 1
            LD    DE,#-10000    ;таблица степеней десятки
            CALL  LP_DIGIT_C$
            LD    DE,#-1000     ;
            CALL  LP_DIGIT_C$
            LD    DE,#-100      ;
            CALL  LP_DIGIT_C$
            LD    E,#-10        ;
            CALL  LP_DIGIT_C$
            LD    E,D           ;
LP_DIGIT_C$:LD    A,#"0"-1      ;обнулили счётчик
LP_PDW2_C$: INC   A             ;увеличиваем счётчик
            ADD   HL,DE         ;вычитаем текущую степень десятки
            JR    C,LP_PDW2_C$  ;повторяем пока HL>=0
            SBC   HL,DE         ;HL=HL mod DE; A=HL div DE
            DEC   C             ;проверяем: может это незначащий нуль?
            JR    Z,LP_PRNT_C$  ; если уже были другие цифры, печатаем
            CP    #"0"          ;если это нуль, то он незначащий
            RET   Z             ; ничего не печатаем
LP_PRNT_C$: PUSH  HL
            PUSH  DE            ;печать десятичной цифры
            CALL  _Console_WriteCh_COMPACT+1 ; Skip "LD A,L"
            POP   DE
            POP   HL
            LD    C,#1          ;уже была печать, дальше все значащие
__endasm;
} //Console_WriteUInt_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_COMPACT (int n) __z88dk_fastcall __naked {
__asm
    BIT   7,H
    JP    Z,_Console_WriteUInt_COMPACT

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
    JP    _Console_WriteUInt_COMPACT
__endasm;
} //Console_WriteInt_COMPACT

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteUInt_FAST (unsigned int n) __z88dk_fastcall {
__asm
            LD    C,#0x5        ;кол-во незначащих нулей + 1
            LD    DE,#-10000    ;таблица степеней десятки
            CALL  LP_DIGIT_F$
            LD    DE,#-1000     ;
            CALL  LP_DIGIT_F$
            LD    DE,#-100      ;
            CALL  LP_DIGIT_F$
            LD    DE,#-10       ;
            CALL  LP_DIGIT_F$
            LD    DE,#-1        ;
LP_DIGIT_F$:LD    A,#"0"-1      ;обнулили счётчик
LP_PDW2_F$: INC   A             ;увеличиваем счётчик
            ADD   HL,DE         ;вычитаем текущую степень десятки
            JR    C,LP_PDW2_F$  ;повторяем пока HL>=0
            SBC   HL,DE         ;HL=HL mod DE; A=HL div DE
            DEC   C             ;проверяем: может это незначащий нуль?
            JR    Z,LP_PRNT_F$  ; если уже были другие цифры, печатаем
            CP    #"0"          ;если это нуль, то он незначащий
            RET   Z             ; ничего не печатаем
LP_PRNT_F$: PUSH  HL            ;печать десятичной цифры
            CALL  _Console_WriteCh_FAST+1 ; Skip "LD A,L"
            POP   HL
            LD    C,#1          ;уже была печать, дальше все значащие
__endasm;
} //Console_WriteUInt_FAST

/*--------------------------------- Cut here ---------------------------------*/
void Console_WriteInt_FAST (int n) __z88dk_fastcall __naked {
__asm
    BIT   7,H
    JP    Z,_Console_WriteUInt_FAST

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
    JP    _Console_WriteUInt_FAST
__endasm;
} //Console_WriteInt_FAST

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

/*----------------------------------------------------------------------------*/
void Console_BackPos_ROM (void) __naked {
__asm
  LD   A,#8
  JP   _Console_WriteCh_ROM+1
__endasm;
}

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

/*----------------------------------------------------------------------------*/
SHORTINT Console_ReadInt_ROM (void)
{
	return Console_ReadIntRange_ROM(-32768, 32767);
}

/*----------------------------------------------------------------------------*/
void Console_BackPos_COMPACT (void)
{
__asm
  LD   HL,#_ATTR_ADR_C+1
  DEC  (HL)
__endasm;
}

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

/*----------------------------------------------------------------------------*/
SHORTINT Console_ReadInt_COMPACT (void)
{
	return Console_ReadIntRange_COMPACT(-32768, 32767);
}

/*----------------------------------------------------------------------------*/
void Console_BackPos_FAST (void)
{
__asm
  LD   HL,#_SCR_ADR_F+1
  DEC  (HL)
__endasm;
}

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

/*----------------------------------------------------------------------------*/
SHORTINT Console_ReadInt_FAST (void)
{
	return Console_ReadIntRange_FAST(-32768, 32767);
}

/*
На Z80 в свое время была такая магия:

; вход — в A число от 0 до 15
ADD A,90h
DAA
ADC A,40h
DAA
; выход — в A код символов '0'-'9', 'A'-'F'
*/
