MODULE CalcZX; (* ZX Spectrum's ROM calculator: compact real arithmetic. *)
IMPORT SYSTEM, Asm;

PROCEDURE -AANoRETCHK0 "#undef __RETCHK";
PROCEDURE -AANoRETCHK1 "#define __RETCHK";

(* http://zxpress.ru/article.php?id=6609

#2D22 - STK-DIGIT. Значение аккумулятора=цифра в ASCII ->  стек
(значение цифры);
#2D28 -  STACK-A.  Аккумулятор  ->  стек  (в  форме  "плавающей
запятой");
#2D2B - STACK-BC. BC -> стек (-''-);
#2AB1 - STK-STORE. A,E,D,C,B -> в стек в 5-байтовом  внутреннем
формате; так же засылаются параметры строки (при этом A=0);
#2ABB - то же без проверок  на  корректность  (иногда  полезно,
если система Бейсика искажена преднамеренно).
*)

PROCEDURE -jump_true*  "__asm .db 0x00 __endasm"; (** jump true *)
(*
#01 - exchange
#02 - delete
*)
PROCEDURE -subtract*  "__asm .db 0x03 __endasm"; (** subtract (вычитание; X-Y) *)
PROCEDURE -mult*      "__asm .db 0x04 __endasm"; (** mult (умножение; X*Y) *)
PROCEDURE -div*       "__asm .db 0x05 __endasm"; (** div (деление; Y/X) *)
PROCEDURE -to_power*  "__asm .db 0x06 __endasm"; (** to-power (возведение в степень; X^Y) *)
PROCEDURE -or*        "__asm .db 0x03 __endasm"; (** or *)
(*
#08 - no-&-no
#09 - no-l-eq
#0A - no-gr-eq
#0B - nos-eql
#0C - no-gtr
#0D - no-less
#0E - nos-eql
*)
PROCEDURE -add* "__asm .db 0x0F __endasm"; (** add (сложение; X+Y) *)
(*
#10 - str-&-no
#11 - str-l-eq
#12 - str-gr-eq
#13 - strs-negl
#14 - str-gtr
#15 - str-less
#16 - str-gtr
#17 - strs-add
#18 - val$ (рекурсия; только через fp-calc-2)
#19 - usr-s
#1A - read-in
#1B - neg
#1C - code
#1D - val (рекурсия; только через fp-calc-2)
#1E - len
*)
PROCEDURE -sin*   "__asm .db 0x1F __endasm"; (** #1F - sin *)
PROCEDURE -cos*   "__asm .db 0x20 __endasm"; (** #20 - cos *)
PROCEDURE -tan*   "__asm .db 0x21 __endasm"; (** #21 - tan *)
PROCEDURE -asn*   "__asm .db 0x22 __endasm"; (** #22 - asn *)
PROCEDURE -acs*   "__asm .db 0x23 __endasm"; (** #23 - acs *)
PROCEDURE -atn*   "__asm .db 0x24 __endasm"; (** #24 - atn *)
PROCEDURE -ln*    "__asm .db 0x25 __endasm"; (** #25 - ln *)
PROCEDURE -exp*   "__asm .db 0x26 __endasm"; (** #26 - exp *)
PROCEDURE -int*   "__asm .db 0x27 __endasm"; (** #27 - int *)
PROCEDURE -sqr*   "__asm .db 0x28 __endasm"; (** #28 - sqr *)
PROCEDURE -sgn*   "__asm .db 0x29 __endasm"; (** #29 - sgn *)
PROCEDURE -abs*   "__asm .db 0x2A __endasm"; (** #2A - abs *)
PROCEDURE -peek*  "__asm .db 0x2B __endasm"; (** #2B - peek *)
PROCEDURE -round* "__asm .db 0x2C __endasm"; (** #2C - int(Y+0.5) *)
(*
#2D - user-no
#2E - str$
#2F - chr$
*)
PROCEDURE -not*       "__asm .db 0x30 __endasm"; (** not *)
PROCEDURE -duplicate* "__asm .db 0x31 __endasm"; (** duplicate *)
(*
#33 - jump
#34 - stk-data
#35 - djnz
#36 - less-0
#37 - greater-0

#39 - get-argt
*)
PROCEDURE -trunc* "__asm .db 0x2C __endasm"; (** #3A - trunc *)
(*
#3B - fp-calc-2 (вторичный вызов калькулятора - рекурсия)
#3C - e-to-fp
#3D - restack (Y целое -> Y в плавающей форме)
#86 и далее - series-06
*)
PROCEDURE -_0*       "__asm .db 0xA0 __endasm"; (** 0 (занесение в стек константы) *)
PROCEDURE -_1*       "__asm .db 0xA1 __endasm";
PROCEDURE -_1_div_2* "__asm .db 0xA2 __endasm"; (** 1/2 *)
PROCEDURE -pi_div_2* "__asm .db 0xA3 __endasm"; (** PI/2 *)
(*
#C0 и далее - st-mem-0
#E0 и далее - get-mem-0
*)

PROCEDURE -Begin* "__asm rst 0x28 __endasm"; (** Запуск калькулятора *)

PROCEDURE _PushBYTE* (b: SHORTINT);
BEGIN
  Asm.Code("POP  HL    ");
  Asm.Code("POP  BC    ");
  Asm.Code("PUSH BC    ");
  Asm.Code("PUSH HL    ");
  Asm.Code("LD   A, C  ");
  Asm.Code("JP   0x2D28");
END _PushBYTE;

PROCEDURE -PushByte* (b: INTEGER) "CalcZX__PushBYTE((unsigned char)(b))";

PROCEDURE _PushWORD* (w: INTEGER);
BEGIN
  Asm.Code("POP  HL    ");
  Asm.Code("POP  BC    ");
  Asm.Code("PUSH BC    ");
  Asm.Code("PUSH HL    ");
  Asm.Code("JP   0x2D2B");
END _PushWORD;

PROCEDURE -PushWord* (w: LONGINT) "CalcZX__PushWORD((unsigned int)(w))";

PROCEDURE -PopByteAsSInt* (): SHORTINT "__asm jp 0x2DA2 __endasm";

PROCEDURE PopWordAsInt* (): INTEGER;
BEGIN
  Asm.Code("CALL 0x2DA2");
  Asm.Code("LD   L, C  ");
  Asm.Code("LD   H, B  ");
END PopWordAsInt;

(*
 - FP-TO-BC. Снимает со стека верхнее значение и  помещает
его в пару BC, округляя до ближайшего целого (int(N+0.5));
# - FP-TO-A - то же, но с помещением 1-байтового результата
в аккумулятор
*)

PROCEDURE -Print_PopReal* () "__asm call 0x2DE3 __endasm;"; (** PRINT-FP *)

PROCEDURE -End*   "__asm .db 0x38 __endasm;"; (** #38 - end-calc (завершение работы с калькулятором)*)

(*
#2BF1 -  STK-FETCH.  Снимает  со  стека  последнее  значение  и
помещает его в регистры B,C,D,E,A. Если данное в стеке являлось
параметрами строки символов, то: DE - адрес начала, BC - длина;
#2DA2 - FP-TO-BC. Снимает со стека верхнее значение и  помещает
его в пару BC, округляя до ближайшего целого (int(N+0.5));
#2DD5 - FP-TO-A - то же, но с помещением 1-байтового результата
в аккумулятор;
#2DE3 - PRINT-FP  -  печатает  в  текущий  поток  (связанный  с
экраном, принтером или другим устройством) значение с  верхушки
стека калькулятора в виде, наиболее подходящем для  конкретного
значения (целом или вещественном). Параметры с  верхушки  стека
калькулятора  рассматриваются  как  число;  если  они  окажутся
параметрами строки, то  будут  напечатаны  в  виде  числа  (это
будет ошибка);
#203C - печатает строку, заданную через: DE=адрес начала,
BC=длина. Может использоваться  вне  связи  с  калькулятором  -
просто для печати строк символов.

В группу обслуживающих процедур  нужно  занести  еще  следующие
подпрограммы:

#16B0 - очистка редакторской строки, временной рабочей  области
и стека калькулятора;
#16BF - очистка временной рабочей области и стека калькулятора;
#16C5 - очистка стека калькулятора.
*)
PROCEDURE- _init* "/*noinit*/";
END CalcZX.
