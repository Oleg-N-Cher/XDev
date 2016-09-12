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

FUNCTION ScanAndRecognize (source: KOLString): KOLString;
CONST
  NumbersInLine = 12; Blank = '    ';
VAR
  n: INTEGER;
BEGIN
  RESULT := '';
  n := 0; INSERT(Blank, RESULT, MAXINT);

  WHILE source <> '' DO                                       BEGIN
    INSERT(KOL.Trim(KOL.Parse(source, ',')), RESULT, MAXINT);
    INSERT(',', RESULT, MAXINT);
    INC(n); IF n = NumbersInLine THEN                         BEGIN
      n := 0;
      INSERT(#13#10 + Blank, RESULT, MAXINT);                   END
    ELSE                                                      BEGIN
      INSERT(' ', RESULT, MAXINT);
    END;
  END;

END {ScanAndRecognize};

procedure TForm1.MemoSrcChange(Sender: PObj);
begin
  MemoDest.Text := ScanAndRecognize(MemoSrc.Text);
end;

end.


