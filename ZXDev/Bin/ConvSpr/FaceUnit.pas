{ KOL MCK } // Do not remove this line!
{$DEFINE KOL_MCK}
unit FaceUnit;

interface

{$IFDEF KOL_MCK}
uses Windows, Messages, KOL {$IF Defined(KOL_MCK)}{$ELSE}, mirror, Classes, Controls, mckCtrls, mckObjs, Graphics {$IFEND (place your units here->)};
{$ELSE}
{$I uses.inc}
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, mirror;
{$ENDIF}

type
  {$IF Defined(KOL_MCK)}
  {$I MCKfakeClasses.inc}
  {$IFDEF KOLCLASSES} {$I TForm1class.inc} {$ELSE OBJECTS} PForm1 = ^TForm1; {$ENDIF CLASSES/OBJECTS}
  {$IFDEF KOLCLASSES}{$I TForm1.inc}{$ELSE} TForm1 = object(TObj) {$ENDIF}
    Form: PControl;
  {$ELSE not_KOL_MCK}
  TForm1 = class(TForm)
  {$IFEND KOL_MCK}
    KOLProject1: TKOLProject;
    KOLForm1: TKOLForm;
    MemoSrc: TKOLMemo;
    MemoDest: TKOLMemo;
    procedure MemoSrcChange(Sender: PObj);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1 {$IFDEF KOL_MCK} : PForm1 {$ELSE} : TForm1 {$ENDIF} ;

{$IFDEF KOL_MCK}
procedure NewForm1( var Result: PForm1; AParent: PControl );
{$ENDIF}

implementation

{$IF Defined(KOL_MCK)}{$ELSE}{$R *.DFM}{$IFEND}

{$IFDEF KOL_MCK}
{$I FaceUnit_1.inc}
{$ENDIF}

FUNCTION ScanNumber (CONST numstr: KOLString): INTEGER;
VAR
  int, hex, n: INTEGER;
BEGIN
  int := 0; hex := 0;

  FOR n := 1 TO LENGTH(numstr) DO                             BEGIN
    CASE numstr[n] OF
      '0'..'9':                                               BEGIN
        int := 10*int + ORD(numstr[n]) - ORD('0');
        hex := 16*hex + ORD(numstr[n]) - ORD('0');             END;
      'A'..'F':                                               BEGIN
        hex := 16*hex + ORD(numstr[n]) - ORD('A') + 10;        END;
      'a'..'f':                                               BEGIN
        hex := 16*hex + ORD(numstr[n]) - ORD('a') + 10;        END;
      'X', 'H':                                               BEGIN
        RESULT := hex; EXIT                                    END;
    END;
  END;
  RESULT := int
END {ScanNumber};

FUNCTION ScanAndRecognize (source: KOLString): KOLString;
VAR
  spn, lobyt, hibyt, len, hgt: KOLString;
  data: ARRAY [0..6912-1] OF KOLString;
  datasize, lenint, hgtint, colint, rowint, charcell, i, n: INTEGER;
BEGIN
  RESULT := '';

  (* spn, lobyt, hibyt, len, hgt *)
  spn := KOL.Parse(source, ',');
  lobyt := KOL.Parse(source, ','); hibyt := KOL.Parse(source, ',');
  len := KOL.Parse(source, ','); hgt := KOL.Parse(source, ','); 

  INSERT(spn,   RESULT, MAXINT); INSERT(',', RESULT, MAXINT);
  INSERT(lobyt, RESULT, MAXINT); INSERT(',', RESULT, MAXINT);
  INSERT(hibyt, RESULT, MAXINT); INSERT(',', RESULT, MAXINT);
  INSERT(len,   RESULT, MAXINT); INSERT(',', RESULT, MAXINT);
  INSERT(hgt,   RESULT, MAXINT); INSERT(','#13#10, RESULT, MAXINT);

  datasize := 0;
  WHILE source <> '' DO                                       BEGIN
    data[datasize] := KOL.Parse(source, ',');
    INC(datasize);
  END;

  lenint := ScanNumber(len); hgtint := ScanNumber(hgt);
  n := 0;

  FOR rowint := 0 TO hgtint - 1 DO                            BEGIN
    FOR colint := 0 TO lenint - 1 DO                          BEGIN
      FOR charcell := 0 TO 7 DO                               BEGIN
        INSERT(data[ charcell*lenint + colint + rowint*lenint*8 ], RESULT, MAXINT);
        INSERT(',', RESULT, MAXINT); INC(n);
      END;
    END;
  END;

  INSERT(#13#10#13#10, RESULT, MAXINT);
  FOR i := n TO datasize - 1 DO                           BEGIN
    INSERT(data[i], RESULT, MAXINT);
    INSERT(',', RESULT, MAXINT);
  END;  

END {ScanAndRecognize};

procedure TForm1.MemoSrcChange(Sender: PObj);
begin
  MemoDest.Text := ScanAndRecognize(MemoSrc.Text);
end;

end.


