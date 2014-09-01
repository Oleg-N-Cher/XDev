MODULE GRAPHIC;
IMPORT SYSTEM, Asm;

(*Procedures by K.Lammassaari 1993-94 (ACADEMY)*)

(* sisaltaa proceduurit:

 - Screen(Mode:Byte);
 - Width(ScreenWidth:Byte);
 - Color(ForeGroundColor,BackGroudColor,BorderColor:Byte);
 - SetColor(color:Byte);  (Asettaa Piirtovarin);
 - GraphicPrint(Str:TPString;X,Y:Integer;Color:Byte;LogOp:Byte);
 - Box(StartX,StartY,ENDX,ENDY:Integer;LogOp:Byte);
 - Line(StartX,StartY,ENDX,ENDY:Integer;Page,Color,LogOp:Byte);
 - SetPage(ActivePage,DisplayPage:Byte);

*)
TYPE
  BYTE = SHORTINT;

PROCEDURE Screen* (mode: BYTE);
BEGIN
  Asm.Code("LD   HL, #2                   ");
  Asm.Code("ADD  HL, SP                   ");
  Asm.Code("LD   A, (HL)       ; (mode)   ");
  Asm.Code("LD   IY, (0xFCC0)  ;(EXPTBL-1)");
  Asm.Code("PUSH IX                       ");
  Asm.Code("LD   IX, #0x005F   ; CHGMOD   ");
  Asm.Code("CALL 0x001C        ; CALSLT   ");
  Asm.Code("EI                            ");
  Asm.Code("POP IX                        ");
END Screen;

PROCEDURE Width* (len: BYTE);
  (* http://www.msx.org/ru/node/45144 *)
BEGIN
  Asm.Code("LD   HL, #2                   ");
  Asm.Code("ADD  HL, SP                   ");
  Asm.Code("LD   A, (HL)      ; (len)     ");
  Asm.Code("LD   (0xF3AE), A  ; (LINL40)  ");
  Asm.Code("LD   IY, (0xFCC0) ; (EXPTBL-1)");
  Asm.Code("PUSH IX                       ");
  Asm.Code("LD   IX, #0x006C  ; INITXT    ");
  Asm.Code("CALL 0x001C       ; CALSLT    ");
  Asm.Code("POP IX                        ");
  Asm.Code("EI                            ");
END Width;

PROCEDURE Color* (ForeGroundColor, BackGroudColor, BorderColor: BYTE);
BEGIN
  Asm.Code("LD   HL, #2                   ");
  Asm.Code("ADD  HL, SP                   ");
  Asm.Code("LD   DE, #0xF3E9  ; (FORCLR)  ");
  Asm.Code("LD   BC, #3       ; (BAKCLR)  ");
  Asm.Code("LDIR              ; (BDRCLR)  ");
  Asm.Code("LD   IY, (0xFCC0) ; (EXPTBL-1)");
  Asm.Code("PUSH IX                       ");
  Asm.Code("LD   IX, #0x0062  ; CHGCLR    ");
  Asm.Code("CALL 0x001C       ; CALSLT    ");
  Asm.Code("POP IX                        ");
  Asm.Code("EI                            ");
END Color;

PROCEDURE SetColor* (color: BYTE);
BEGIN
  Asm.Code("LD   HL, #2                   ");
  Asm.Code("ADD  HL, SP                   ");
  Asm.Code("LD   A, (HL)      ; (color)   ");
  Asm.Code("LD   IY, (0xFCC0) ; (EXPTBL-1)");
  Asm.Code("PUSH IX                       ");
  Asm.Code("LD   IX, #0x011A  ; SETATR    ");
  Asm.Code("CALL 0x001C       ; CALSLT    ");
  Asm.Code("EI                            ");
  Asm.Code("POP IX                        ");
END SetColor;

PROCEDURE Pset* (Destination_x, Destination_y: INTEGER;
  DestinationPage: BYTE; Color, LogicalOperation: BYTE);
BEGIN(*
  _cmd:= $50 + LogicalOperation ;
  _dx := Destination_x ;
  _dy := DestinationPage * 256 + Destination_y ;
  _col:= Color;
  Inline *)

  Asm.Code("DI                            ");
  Asm.Code("LD   A, #0x20                 ");
  Asm.Code("OUT  (0x99), A                ");
  Asm.Code("LD   A, #0x11                 ");
  Asm.Code("OR   #0x80                    ");
  Asm.Code("OUT  (0x99), A                ");
  Asm.Code("LD   B, #0x0F                 ");
  Asm.Code("LD   C, #0x9B                 ");
  Asm.Code("LD   HL, #0xF562              ");
  Asm.Code("OTIR                          ");
Asm.Code("LOC_40E8$:");
  Asm.Code("LD   A, #2                    ");
  Asm.Code("OUT  (0x99), A                ");
  Asm.Code("LD   A, #0x0F                 ");
  Asm.Code("OR   #0x80                    ");
  Asm.Code("OUT  (0x99), A                ");
  Asm.Code("IN   A, (0x99)                ");
  Asm.Code("BIT  0, A                     ");
  Asm.Code("JR   NZ, LOC_40E8$            ");
  Asm.Code("XOR  A                        ");
  Asm.Code("OUT  (0x99), A                ");
  Asm.Code("LD   A, #0x8F                 ");
  Asm.Code("OUT  (0x63), A                ");
  Asm.Code("EI                            ");
END Pset;

(*
Type TPString = String[255];

PROCEDURE GraphicPrint(Str:TPString;X,Y:Integer;Color:Byte;LogOp:Byte);

Var StoreX,StoreY :Integer ;
    ch            :Char;
    i,StoreColor  :Byte;
    GRPACX        :Integer Absolute $FCB7;
    GRPACY        :Integer Absolute $FCB9;
    ATRBYT        :Byte Absolute $F3F2;
    LOGOPER       :Byte Absolute $f570;
BEGIN
     StoreColor := ATRBYT;
     ATRBYT := Color;
     StoreX := GRPACX;
     StoreY := GRPACY;
     GRPACX := x;
     GRPACY := y;
     LOGOPER :=LogOp;
     For i := 1 to Length(Str) Do
        BEGIN
           ch := Str[i];
           Inline (

              $3a/ch/
              $fd/$2a/$c0/$fc    (* LD IY,(EXPTBL - 1 *)
             /$DD/$21/$10/$15    (* LD IX,grpprnt *)
             /$CD/$1c/00         (* CALL CALSLT *)
             /$fb
                   );
         END;
     GRPACX :=StoreX;
     GRPACY :=StoreY;
     ATRBYT :=StoreColor;
     LOGOPER := 0; (*Normal condition*)

END; (*GraphicPrint*)


PROCEDURE Box(StartX,StartY,ENDX,ENDY:Integer;LogOp:Byte);
Var LOGOPER :Byte ABsolute $f570;
BEGIN
     LOGOPER := LogOp;
     Inline (
            $f3/
            $2a/ENDX/            (*LD HL,(STARTX) *)
            $22/$B3/$FC/         (*LD ($FCB3),HL *)
            $2a/ENDY/
            $22/$b5/$fc/
            $ed/$4b/StartX/      (* LD BC,(ENDX)*)
            $ed/$5b/StartY       (* LD DE,(ENDY *)

            /$fd/$2a/$f7/$fa    (* LD IY,(EXbrsa - 1 *)
            /$DD/$21/$c9/$00    (* LD IX,dobox *)
            /$CD/$1c/00         (* CALL CALSLT *)
            /$fb
             );
      LOGOPER := 0;
END; (* Box *)

PROCEDURE Line(x1,y1,x2,y2:Integer;page,color,logop:Byte);

BEGIN

    y1:=256*page+y1;
    y2:=256*page+y2;
    logop := logop + $70; (*line cmd + logical operation*)

    Inline (
       $DD/$21/$D6/$FD/$DD/$36/$00/$FD/$DD/$36/$01/$E1/$DD/$36/$02/$FD/

       $DD/$36/$03/$E9/$F3/$DD/$21/$6F/$F5/$DD/$36/$00/$00/$ED/$5B/  x1 /

       $91/$ED/$53/$66/$F5/$2A/  x2  /$FD/$E5/$E5/$D5/$CD/$D6/$FD/$FD/

       $E5/$E1/$FD/$5E/$1E/$FD/$56/$1F/$19/$EB/$FD/$73/$1E/$FD/$72/$1F/

       $FD/$36/$F9/$18/$FD/$36/$FA/$22/$D1/$E1/$FD/$E1/$CD/$E8/$00/$30/

       $05/$EB/$DD/$CB/$00/$D6/$B7/$ED/$52/$E5/$ED/$5B/  y1  /$ED/$53/

       $68/$F5/$2A/  y2  /$FD/$E5/$E5/$D5/$CD/$D6/$FD/$FD/$E5/$E1/$FD/

       $5E/$1E/$FD/$56/$1F/$19/$EB/$FD/$73/$1E/$FD/$72/$1F/$FD/$36/$F9/

       $18/$FD/$36/$FA/$22/$D1/$E1/$FD/$E1/$CD/$AB/$00/$30/$05/$DD/$CB/

       $00/$DE/$EB/$B7/$ED/$52/$EB/$E1/$FD/$E5/$E5/$D5/$CD/$D6/$FD/$FD/

       $E5/$E1/$FD/$5E/$1E/$FD/$56/$1F/$19/$EB/$FD/$73/$1E/$FD/$72/$1F/

       $FD/$36/$F9/$18/$FD/$36/$FA/$22/$D1/$E1/$FD/$E1/$CD/$78/$00/$38/

       $01/$EB/$ED/$53/$6A/$F5/$22/$6C/$F5/$30/$04/$DD/$CB/$00/$C6/$3A/

         color /$DD/$2B/$DD/$77/$00/$DD/$23/$DD/$23/$3A/  logop  /$00/$DD/

       $77/$00/$F3/$3E/$24/$D3/$99/$D9/$D9/$3E/$11/$F6/$80/$D3/$99/$06/

       $0B/$0E/$9B/$21/$66/$F5/$ED/$B3/$3E/$02/$D3/$99/$D9/$D9/$3E/$0F/

       $F6/$80/$D3/$99/$D9/$D9/$DB/$99/$CB/$47/$20/$EC/$AF/$D3/$99/$D9/

       $D9/$3E/$8F/$D3/$99/$18/$06/$7C/$BA/$C0/$7D/$BB/$C9
            );
END; (*Line*)


PROCEDURE SetPage(ActivePage,DisplayPage:Byte);

CONST SETPAGE = $013D; (*SubRom routine*)

Var   DPPAGE :Byte Absolute  $FAF5;
      ACPAGE :Byte Absolute  $FAF6;

BEGIN
    DpPage := DispLayPage;
    AcPage := ActivePage;

    Inline (
             $f3
            /$fd/$2a/$f7/$fa    (* LD IY,(EXbrsa - 1 *)
            /$DD/$21/$3d/$01    (* LD IX,setpage *)
            /$CD/$1c/00         (* CALL CALSLT *)
            /$fb
             );
END; (* SetPage *)
*)

PROCEDURE- _init* "/*noinit*/";
END GRAPHIC.