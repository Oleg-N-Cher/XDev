{ KOL MCK } // Do not remove this line!
program ConvSpr;

uses
KOL,
  FaceUnit in 'FaceUnit.pas' {Form1};

//{$R *.res}

begin // PROGRAM START HERE -- Please do not remove this comment

{$IF Defined(KOL_MCK)} {$I ConvSpr_0.inc} {$ELSE}

  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;

{$IFEND}

end.
